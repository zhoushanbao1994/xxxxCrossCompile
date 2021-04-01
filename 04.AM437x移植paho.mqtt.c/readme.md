AM4379移植paho.mqtt.c

paho.mqtt.c MQTT客户端

## 1. 配置交叉编译环境



## 2. **移植OpenSSL**

编译paho.mqtt.c，它依赖OpenSSL库。所以需先移植OpenSSL库。

### a) 下载源码

源码下载地址：https://www.openssl.org/source/，当前稳定版[openssl-1.1.1k.tar.gz](https://www.openssl.org/source/openssl-1.1.1k.tar.gz)

### b) 交叉编译

#### 配置

```shell
./config no-asm shared --prefix=$PWD/install --cross-compile-prefix=arm-linux-gnueabihf-
```

- no-asm：Do not use assembler code
- shared：编译连接成动态库
- –prefix=$PWD/install：指定编译后安装路径
- –cross-compile-prefix=arm-linux-gnueabihf-：指定交叉编译工具链

#### 修改Makefile

找到Makefile中的所有-m64的地方，然后删除

```shell
CNF_CPPFLAGS=-DNDEBUG
#CNF_CFLAGS=-pthread -m64
CNF_CFLAGS=-pthread
#CNF_CXXFLAGS=-std=c++11 -pthread -m64
CNF_CXXFLAGS=-std=c++11 -pthread
CNF_LDFLAGS=
CNF_EX_LIBS=-ldl -pthread
```

#### 执行make && make install

```shell
make
make install
```

然后在install目录下会生成相应的库及头文件。

#### 复制文件

```shell
# 进入install/lib/文件夹，将里面内容全部复制到交叉编译的系统库路径中
cp -pR * /opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/lib

# 进入install/include/文件夹，将openssl文件夹整个文件夹复制到交叉编译的系统包含路径中
cp -r openssl/ /opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/include
```





## 3. 移植paho.mqtt.c

### a) 下载源码

下载链接：https://github.com/eclipse/paho.mqtt.c/releases。选择[Version 1.3.8](https://github.com/eclipse/paho.mqtt.c/archive/refs/tags/v1.3.8.tar.gz)版本。

### b) 交叉编译

#### 修改Makefile的prefix定义：

```shell
ifndef prefix
	prefix = /usr/local
endif
# 改为
ifndef prefix
    prefix = ./install/
endif
```

#### 修改Makefile的交叉编译工具链

```shell
CC ?= gcc
# 改为
CC := arm-linux-gnueabihf-gcc
```

#### 修改Makefile的INSTALL_DATA

```shell
INSTALL_DATA =  $(INSTALL) -m 644
# 改为
INSTALL_DATA =  $(INSTALL)
```

#### ~~Makefile增加openssl库及头文件的路径~~

~~CCFLAGS_SO += -I /opt/openssl/openssl-1.1.1k/install/include~~
~~LDFLAGS_C  += -L /opt/openssl/openssl-1.1.1k/install/lib~~
~~LDFLAGS_CS += -L /opt/openssl/openssl-1.1.1k/install/lib~~
~~LDFLAGS_A  += -L /opt/openssl/openssl-1.1.1k/install/lib~~
~~LDFLAGS_AS += -L /opt/openssl/openssl-1.1.1k/install/lib~~
~~FLAGS_EXE  += -L /opt/openssl/openssl-1.1.1k/install/lib~~
~~FLAGS_EXES += -L /opt/openssl/openssl-1.1.1k/install/lib~~

~~路径根据实际路径设置。增加此语句在174行左右。~~

直接将库拷贝至系统路径下，不需要在增加路径。

#### Makefile更改install目标的定义

```shell
install: build
	mkdir -p $(DESTDIR)$(PREFIX)${includedir}
	mkdir -p $(DESTDIR)$(PREFIX)${libdir}
	mkdir -p $(DESTDIR)$(PREFIX)${bindir}
	mkdir -p $(DESTDIR)${man1dir}
	mkdir -p $(DESTDIR)${man3dir}
	cp -f ${MQTTLIB_C_TARGET} $(DESTDIR)${libdir}
	cp -f ${MQTTLIB_CS_TARGET} $(DESTDIR)${libdir}
	cp -f ${MQTTLIB_A_TARGET} $(DESTDIR)${libdir}
	cp -f ${MQTTLIB_AS_TARGET} $(DESTDIR)${libdir}
	cp -f ${MQTTVERSION_TARGET} $(DESTDIR)${bindir}
	cp -f ${PAHO_C_PUB_TARGET} $(DESTDIR)${bindir}
	cp -f ${PAHO_C_SUB_TARGET} $(DESTDIR)${bindir}
	cp -f ${PAHO_CS_PUB_TARGET} $(DESTDIR)${bindir}
	cp -f ${PAHO_CS_SUB_TARGET} $(DESTDIR)${bindir}
	ln -sf lib$(MQTTLIB_C).so.${MAJOR_VERSION} $(DESTDIR)${libdir}/lib$(MQTTLIB_C).so
	ln -sf lib$(MQTTLIB_CS).so.${MAJOR_VERSION} $(DESTDIR)${libdir}/lib$(MQTTLIB_CS).so
	ln -sf lib$(MQTTLIB_A).so.${MAJOR_VERSION} $(DESTDIR)${libdir}/lib$(MQTTLIB_A).so
	ln -sf lib$(MQTTLIB_AS).so.${MAJOR_VERSION} $(DESTDIR)${libdir}/lib$(MQTTLIB_AS).so
	ln -sf lib$(MQTTLIB_C).so.${VERSION} $(DESTDIR)${libdir}/lib$(MQTTLIB_C).so.${MAJOR_VERSION}
	ln -sf lib$(MQTTLIB_CS).so.${VERSION} $(DESTDIR)${libdir}/lib$(MQTTLIB_CS).so.${MAJOR_VERSION}
	ln -sf lib$(MQTTLIB_A).so.${VERSION} $(DESTDIR)${libdir}/lib$(MQTTLIB_A).so.${MAJOR_VERSION}
	ln -sf lib$(MQTTLIB_AS).so.${VERSION} $(DESTDIR)${libdir}/lib$(MQTTLIB_AS).so.${MAJOR_VERSION}
	cp -f ${srcdir}/MQTTAsync.h $(DESTDIR)${includedir}
	cp -f ${srcdir}/MQTTClient.h $(DESTDIR)${includedir}
	cp -f ${srcdir}/MQTTClientPersistence.h $(DESTDIR)${includedir}
	cp -f ${srcdir}/MQTTExportDeclarations.h $(DESTDIR)${includedir}
	cp -f ${srcdir}/MQTTProperties.h $(DESTDIR)${includedir}
	cp -f ${srcdir}/MQTTReasonCodes.h $(DESTDIR)${includedir}
	cp -f ${srcdir}/MQTTSubscribeOpts.h $(DESTDIR)${includedir}   
	- cp -f doc/man/man1/paho_c_pub.1 $(DESTDIR)${man1dir}
	- cp -f doc/man/man1/paho_c_sub.1 $(DESTDIR)${man1dir}
	- cp -f doc/man/man1/paho_cs_pub.1 $(DESTDIR)${man1dir}
	- cp -f doc/man/man1/paho_cs_sub.1 $(DESTDIR)${man1dir}
	#- cp -f ${blddir}/doc/MQTTClient/man/man3/MQTTClient.h.3 $(DESTDIR)${man3dir}
	#- cp -f ${blddir}/doc/MQTTAsync/man/man3/MQTTAsync.h.3 $(DESTDIR)${man3dir}
	@echo ""
	@echo "make install finish", `date`
	@echo ""
```



#### Makefile更改uninstall目标的定义

```shell
uninstall:
	rm -rf $(blddir_work)
	@echo ""
	@echo "make uninstall finish", `date`
	@echo ""
```

即把paho.mqtt.c的库及其头文件安装在build/install目录下。

#### 编译

```shell
make
make install
```

#### 复制文件

```shell
# 进入install/lib/文件夹，将里面内容全部复制到交叉编译的系统库路径中
cp -pR * /opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/lib
```



## 4. 创建测试例子

### a) 拷贝头文件

将mqtt编译输出install文件夹下的include/文件夹拷贝至测试例子目录

### b) main.c

```c
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
```

### c) Makefile

```makefile
TARGET = $(notdir $(CURDIR))

CC=$(CROSS_COMPILE)gcc

objs := $(patsubst %c, %o, $(shell ls *.c))

$(TARGET)_test:$(objs)
	$(CC) -o $@ $^ -lpthread -lpaho-mqtt3c -lpaho-mqtt3a
%.o:%.c
	$(CC) -c -o $@ $<
clean:
	rm -f  $(TARGET)_test *.all *.o
```



### d) 编译

```shell
make
```

生成“test_test”可执行文件



## 5. 复制到板子上

### a)  复制openssl库

进入openssl生成的install/lib/文件夹，将里面内容全部复制到板子/usr/lib/路径下

```shell
cp -pR * /usr/lib/
```

### b)  复制paho.mqtt.c库

进入paho.mqtt.c生成的install/lib/文件夹，将里面内容全部复制到板子/usr/lib/路径下

```shell
cp -pR * /usr/lib/
```

### c) 复制可执行文件

将“test_test”可执行文件传输至板子上，运行“test_test”







## 参考文章

http://velep.com/archives/1430.html

