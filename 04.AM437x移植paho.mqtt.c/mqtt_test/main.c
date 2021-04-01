#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/MQTTClient.h"
#if !defined(WIN32)
#include <unistd.h>
#else
#include <windows.h>
#endif

#define NUM_THREADS     2
#define ADDRESS         "tcp://192.168.10.253:1883"  //更改此处地址
#define CLIENTID        "aaabbbccc_pub"         //更改此处客户端ID
#define SUB_CLIENTID    "aaabbbccc_sub"         //更改此处客户端ID
#define TOPIC           "topic01"               //更改发送的话题
#define PAYLOAD         "Hello Man, Can you see me ?!" //
#define QOS             1
#define TIMEOUT         10000L
#define USERNAME        ""
#define PASSWORD        ""
#define DISCONNECT      "out"

int CONNECT = 1;
volatile MQTTClient_deliveryToken deliveredtoken;


// 订阅客户端的回调
void delivered(void *context, MQTTClient_deliveryToken dt)
{
    printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

// 订阅客户端的回调
int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    int i;
    char* payloadptr;

    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: ");

    payloadptr = message->payload;
    if(strcmp(payloadptr, DISCONNECT) == 0){
        printf(" \n out!!");
        CONNECT = 0;
    }
    
    for(i=0; i<message->payloadlen; i++)
    {
        putchar(*payloadptr++);
    }
    printf("\n");
    
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

// 订阅客户端的回调
void connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

// 订阅客户端
void *subClient(void *threadid)
{
    long tid;
    tid = (long)threadid;
    printf("Hello World! It's me, thread #%ld!\n", tid);
    
    // 声明客户端
    MQTTClient client;
    // 设置连接MQTT服务器的选项
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;
    int ch;

    // 通过函数给其赋值
    MQTTClient_create(&client, ADDRESS, SUB_CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    conn_opts.username = USERNAME;
    conn_opts.password = PASSWORD;
    
    // 设置回调函数；
    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);

    // 使用客户端和连接选项连接服务器；
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
    printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n"
           "Press Q<Enter> to quit\n\n", TOPIC, CLIENTID, QOS);
           
    // 订阅话题；
    MQTTClient_subscribe(client, TOPIC, QOS);

    // 一直等待，直到输入'Q' 或'q'退出
    do 
    {
        ch = getchar();
    } while(ch!='Q' && ch != 'q');

    // 取消订阅；
    MQTTClient_unsubscribe(client, TOPIC);
    // 断开客户端连接
    MQTTClient_disconnect(client, 10000);
    // 释放客户端使用的所有内存
    MQTTClient_destroy(&client);
   
   pthread_exit(NULL);
}

// 推送客户端
void *pubClient(void *threadid)
{
    long tid;
    tid = (long)threadid;
    int count = 0;
    printf("Hello World! It's me, thread #%ld!\n", tid);
    
    //声明一个MQTTClient
    MQTTClient client;
    //初始化MQTT Client选项
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    
    //#define MQTTClient_message_initializer { {'M', 'Q', 'T', 'M'}, 0, 0, NULL, 0, 0, 0, 0 }
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    //声明消息token
    MQTTClient_deliveryToken token;
    int rc;
    //使用参数创建一个client，并将其赋值给之前声明的client
    MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    conn_opts.username = USERNAME;
    conn_opts.password = PASSWORD;
    //使用MQTTClient_connect将client连接到服务器，使用指定的连接选项。成功则返回MQTTCLIENT_SUCCESS
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
    // 设置发送消息的属性；
    pubmsg.payload = PAYLOAD;
    pubmsg.payloadlen = strlen(PAYLOAD);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    
    // 循环发送消息；
    while(CONNECT){
        MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
        printf("Waiting for up to %d seconds for publication of %s\n"
                "on topic %s for client with ClientID: %s\n",
                (int)(TIMEOUT/1000), PAYLOAD, TOPIC, CLIENTID);
        rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
        printf("Message with delivery token %d delivered\n", token);
        usleep(3000000L);
    }
    
    // 断开客户端连接；
    MQTTClient_disconnect(client, 10000);
    // 释放客户端使用的所有内存；
    MQTTClient_destroy(&client);
}
int main(int argc, char* argv[])
{
    pthread_t threads[NUM_THREADS];
    long t;
    //创建了两个线程，分别用来处理订阅客户端和发布客户端。
    pthread_create(&threads[0], NULL, subClient, (void *)0);
    pthread_create(&threads[1], NULL, pubClient, (void *)1);
    pthread_exit(NULL);
}

