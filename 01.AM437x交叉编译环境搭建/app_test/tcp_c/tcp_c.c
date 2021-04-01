#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <time.h>          //使用当前时钟做种子

#define MAXLINE 4096

#define PORT 6666

int main(int argc, char**argv)
{
    int sock_fd;
    char recv_buff[MAXLINE], send_buff[MAXLINE];
    struct sockaddr_in server_addr;
	
	struct sockaddr_in loc_addr;
	socklen_t loc_addrlen = sizeof(loc_addr);
	
	unsigned long count = 0;
	int i = 0;
	int send_len = 0, recv_len = 0;
	
	srand((unsigned)time( NULL ) );          //初始化随机数

    if(argc !=2)
    {
        printf("usage: ./client <ipaddress>\n");
        return 0;
    }
	
    //创建socket
    if( (sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf(" create socket error: %s (errno :%d)\n",strerror(errno),errno);
        return 0;
    }

	// 设置server结构体 
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    //IP地址从“点分十进制”转换到“二进制整肃”
    if( inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <=0 ) {
        printf("inet_pton error for %s\n", argv[1]);
        return 0;
    }
	
    //连接
    if( connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf(" connect socket error: %s(errno :%d)\n", strerror(errno), errno);
        return 0;
    }
	
	// 获取socket绑定的本地address信息
	if( getsockname(sock_fd, (struct sockaddr *)&loc_addr, &loc_addrlen) == 0) {
		printf("local %s:%d\n", 
			inet_ntoa(loc_addr.sin_addr), ntohs(loc_addr.sin_port));
	}
	else {
		printf(" getsockname error: %s(errno :%d)\n", strerror(errno), errno);
        return 0;
	}
    
    printf("send msg to server:\n\n");
    while(1)
	{
		count++;
		send_len = rand() % 100 + 10;
		send_buff[0] = (count >> 24) & 0xFF;
		send_buff[1] = (count >> 16) & 0xFF;
		send_buff[2] = (count >>  8) & 0xFF;
		send_buff[3] = (count >>  0) & 0xFF;
		for(i = 4; i < send_len; i++) {
			send_buff[i] = rand() % 255;
		}
		
		//send发送
		if ( send(sock_fd, send_buff, send_len, 0) < 0) {
		    printf("send msg error: %s(errno :%d)\n",strerror(errno),errno);
		    return 0;
		}
		
		// 接收数据
		recv_len = recv(sock_fd, recv_buff, MAXLINE, 0);
		
		printf("\b\r\033[k");
		if((send_len == recv_len) && 
			(memcmp(send_buff, recv_buff, send_len) == 0)) {
			printf("correct %ld\r\n", count);
		}
		else {
			printf("error %ld\r\n\r\n", count);		// 出错时多回车换行一次，覆盖上一行显示时不会覆盖错误信息
		}
	}
    close(sock_fd);
    return 0;
}

