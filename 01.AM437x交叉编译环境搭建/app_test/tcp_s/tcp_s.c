//使用pthread线程库
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include<pthread.h>

#define PORT 6666            //服务器端口
#define BACKLOG 5            //listen队列等待的连接数
#define MAXDATASIZE  1024    //缓冲区大小
 
void process_cli(int connectfd, struct sockaddr_in client);    //客户端请求处理函数
void* start_routine(void* arg);        //线程函数

//客户端结构体
typedef struct  _ARG  {
    int connfd;
    struct sockaddr_in client; 
}ARG;                    		  

// 错误信息输出
void sys_err(const char * ptr_err)
{
    perror(ptr_err);
    exit(EXIT_FAILURE);
}

//处理客户端链接的接收工作*
void accept_conn(int listenfd)
{
	 int connect_fd;       		   //socket描述符
     pthread_t  connectthread;	   //线程体变量
     ARG *arg;                      //客户端结构体变量
	 struct sockaddr_in client;     //客户端地址信息结构体
     int sin_size = sizeof(struct sockaddr_in);
	 
	struct sockaddr_in loc_addr;
	socklen_t loc_addrlen = sizeof(loc_addr);
	 
	 while(1) {
        //调用accept，返回与服务器连接的客户端描述符
        if ((connect_fd = accept(listenfd,(struct sockaddr *)&client,(socklen_t *)&sin_size))==-1) {                    
            sys_err("accept() error\n");
        }
		
		// 获取socket绑定的本地address信息
		if( getsockname(listenfd, (struct sockaddr *)&loc_addr, &loc_addrlen) == 0) {
			printf("local %s:%d\n", 
				inet_ntoa(loc_addr.sin_addr), ntohs(loc_addr.sin_port));
		}
        
		// 参数传递
        //arg = new  ARG;
		arg = (ARG *)malloc(sizeof(ARG));
        arg->connfd = connect_fd;
        memcpy(&arg->client, &client, sizeof(client));
        
		//创建线程，以客户端连接为参数，start_routine为线程执行函数
        if (pthread_create(&connectthread, NULL, start_routine, (void*)arg)) {        
            sys_err("Pthread_create() error");
        }
    }
}
 
void tcp_server(uint16_t port)
{
	int listen_fd;				   //socket描述符
    struct sockaddr_in server;     //服务器地址信息结构体
   
	
    //调用socket，创建监听客户端的socket
    if ((listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) { 
        sys_err("Creating socket failed.");
    }
	
    //设置socket属性，端口可以重用
    int opt = SO_REUSEADDR;        
    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));    
	
    //初始化服务器地址结构体
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;   // sin_family指代协议族，在socket编程中只能是AF_INET
    server.sin_port = htons(port);	//存储端口号（使用网络字节顺序）
    server.sin_addr.s_addr = htonl(INADDR_ANY);	// 按照网络字节顺序存储IP地址
	
    //调用bind，绑定地址和端口
    if (bind(listen_fd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1) {   
        sys_err("Bind error.");
    }   
	
    //调用listen，开始监听 (BACKLOG最大数量)
    if(listen(listen_fd, BACKLOG) == -1){      
        sys_err("listen() error\n");
    }
    
	//处理客户端链接的接收工作
    accept_conn(listen_fd);

	//关闭监听socket
    close(listen_fd);        
}
int main()
{
    
	uint16_t port  = PORT;
	tcp_server(port);
    
}
 
void process_cli(int connectfd, struct sockaddr_in client)
{
    int num, i;
    char recvbuf[MAXDATASIZE], sendbuf[MAXDATASIZE], cli_name[MAXDATASIZE];
    
    printf("You got a connection from %s:%d.\n", 
		inet_ntoa(client.sin_addr), ntohs(client.sin_port));
	//MSG_WAITALL 
	
#if 0
    while ((num = recv(connectfd, recvbuf, MAXDATASIZE,0)) > 0) {
 		recvbuf[num] = '\0';
        printf("From %s:%d  --- Received size( %d ) message: %s\n", 
			inet_ntoa(client.sin_addr), ntohs(client.sin_port), num, recvbuf);	
	}
#else
    while ((num = recv(connectfd, recvbuf, MAXDATASIZE,0)) > 0) {
		// 清空发送缓冲区
		memset(sendbuf, 0, MAXDATASIZE);
		// 将接收缓冲区的数据复制到发送缓冲区
		memcpy(sendbuf, recvbuf, num);
		
		// 将发送缓冲区的数据发送
		send(connectfd, sendbuf, num, 0);
		
#if 0
 		recvbuf[num] = '\0';
        printf("From %s:%d  --- Received size( %d ) message: %s\n", 
			inet_ntoa(client.sin_addr), ntohs(client.sin_port), num, recvbuf);
#elif 0
		printf("%s:%d -- %d -- ", 
			inet_ntoa(client.sin_addr), ntohs(client.sin_port), num);
		for(i = 0; i < num; i++) {
			printf("%02X ", 0xFF & recvbuf[i]);
		}
		printf("\r\n");
#endif			
	}
#endif
   
    /* 
 	num = recv(connectfd, cli_name, MAXDATASIZE,0);
    if (num == 0) {
        close(connectfd);
        
        return;
    }
    cli_name[num - 1] = '\0';
    printf("Client's content is: %s\n",cli_name);
    while (num = recv(connectfd, recvbuf, MAXDATASIZE,0)) {
        recvbuf[num] = '\0';
        printf("Received client( %s ) message: %s",cli_name, recvbuf);
        for (int i = 0; i < num - 1; i++) {
            sendbuf[i] = recvbuf[num - i -2];
        }
        sendbuf[num - 1] = '\0';
        send(connectfd,sendbuf,strlen(sendbuf),0);
    }
	*/
	printf("%s:%d Client disconnected.\n", 
		inet_ntoa(client.sin_addr), ntohs(client.sin_port));
    close(connectfd); 
}

// 线程
void* start_routine(void* arg)
{
	ARG *info = (ARG *)arg;
    process_cli(info->connfd, info->client);
	
	//删除对应的堆内存
	//delete info;
	free(info);
	
    pthread_exit(NULL);
} 
