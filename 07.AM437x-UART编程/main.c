#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <string.h>

#define FALSE 1
#define TRUE 0

// 波特率
int speed_arr[] = {
    B4000000,
    B2000000,
    B1000000,
    B921600, 
    B460800, 
    B230400, 
    B115200, 
    B57600, 
    B38400, 
    B19200,
    B9600, 
    B4800, 
    B2400, 
    B1200, 
    B300,
};
int name_arr[] = {
    4000000,
    2000000,
    1000000,
    921600, 
    460800, 
    230400, 
    115200, 
    57600, 
    38400,  
    19200,
    9600,  
    4800,  
    2400,  
    1200,  
    300,
};

// 设置波特率
void set_speed(int fd, int speed)
{
    int   i;
    int   status;
    struct termios   Opt;
    tcgetattr(fd, &Opt);

    for ( i= 0;  i < sizeof(speed_arr) / sizeof(int);  i++) {
        if  (speed == name_arr[i])  {
            tcflush(fd, TCIOFLUSH);
            cfsetispeed(&Opt, speed_arr[i]);
            cfsetospeed(&Opt, speed_arr[i]);
            status = tcsetattr(fd, TCSANOW, &Opt);
            if  (status != 0)
                perror("tcsetattr fd1");
                return;
        }
        tcflush(fd,TCIOFLUSH);
     }

    if (i == 12){
        printf("\tSorry, please set the correct baud rate!\n\n");
        //print_usage(stderr, 1);
    }
}
/*
    *@brief   设置串口数据位，停止位和效验位
    *@param  fd     类型  int  打开的串口文件句柄*
    *@param  databits 类型  int 数据位   取值 为 7 或者8*
    *@param  stopbits 类型  int 停止位   取值为 1 或者2*
    *@param  parity  类型  int  效验类型 取值为N,E,O,,S
*/
int set_Parity(int fd,int databits,int stopbits,int parity)
{
    struct termios options;
    if  ( tcgetattr( fd,&options)  !=  0) {
        perror("SetupSerial 1");
        return(FALSE);
    }
    options.c_cflag &= ~CSIZE ;
    /*设置数据位数*/
    switch (databits) {
    case 7:
        options.c_cflag |= CS7;
    break;
    case 8:
        options.c_cflag |= CS8;
    break;
    default:
        fprintf(stderr,"Unsupported data size\n");
        return (FALSE);
    }

    // 设置校验位
    switch (parity) {
    case 'n':
    case 'N':
        options.c_cflag &= ~PARENB;             /* Clear parity enable */
        options.c_iflag &= ~INPCK;              /* Enable parity checking */
    break;
    case 'o':
    case 'O':
        options.c_cflag |= (PARODD | PARENB);   /* 设置为奇效验*/
        options.c_iflag |= INPCK;               /* Disnable parity checking */
    break;
    case 'e':
    case 'E':
        options.c_cflag |= PARENB;              /* Enable parity */
        options.c_cflag &= ~PARODD;             /* 转换为偶效验*/
        options.c_iflag |= INPCK;               /* Disnable parity checking */
    break;
    case 'S':
    case 's':  /*as no parity*/
        options.c_cflag &= ~PARENB;
        options.c_cflag &= ~CSTOPB;
    break;
    default:
        fprintf(stderr,"Unsupported parity\n");
        return (FALSE);
    }

    /* 设置停止位*/
    switch (stopbits) {
    case 1:
        options.c_cflag &= ~CSTOPB;
    break;
    case 2:
        options.c_cflag |= CSTOPB;
    break;
    default:
        fprintf(stderr,"Unsupported stop bits\n");
        return (FALSE);
    }

    /* Set input parity option */
    if (parity != 'n')
        options.c_iflag |= INPCK;
    options.c_cc[VTIME] = 150; // 15 seconds
        options.c_cc[VMIN] = 0;

    options.c_lflag &= ~(ECHO | ICANON);

    // set hardware flow control
    //options.c_cflag |= CRTSCTS;

    tcflush(fd,TCIFLUSH); /* Update the options and do it NOW */
    if (tcsetattr(fd,TCSANOW,&options) != 0) {
        perror("SetupSerial 3");
        return (FALSE);
    }
    return (TRUE);
}


int OpenDev(char *Dev)
{
    int fd = open( Dev, O_RDWR | O_NOCTTY | O_NONBLOCK );
    if (-1 == fd) {
        perror("Can't Open Serial Port");
        return -1;
    } else
        return fd;
}


void thread1(void)// 线程1
{
    time_t timep;
    struct tm *p;
    
    int     uart_fd;
    int     nread;          /* Read the counts of data */
    char    recv_buff[512]; /* Recvice data buffer */

    //int     speed = 921600;     // 串口波特率
    int     speed = 1000000;     // 串口波特率
    struct  termios saveterm,nt;

    fd_set  recv_fds;       /* 定义接收fds  一个存放文件描述符(file descriptor)，即文件句柄的聚合，实际上是一long类型的数组 */
    int     fd_result;
    struct  timeval tv;     /* 超时时间 */

    /******** 打开串口，若打开成功配置波特率 ********/
    uart_fd = OpenDev("/dev/ttyS1");
    if (uart_fd > 0) {
        set_speed(uart_fd, speed);
    } else {
        fprintf(stderr, "Error opening: %s\n", strerror(errno));
        pthread_exit(0);
    }

    /******** 配置数据位、校验位、停止位 ********/
    if (set_Parity(uart_fd, 8, 1, 'N')== FALSE) {
        fprintf(stderr, "Set Parity Error\n");
        close(uart_fd);
        pthread_exit(0);
    }

    ///******** 调整终端接口 ********/
    tcgetattr(uart_fd, &saveterm);
    nt = saveterm;
    nt.c_cflag |= CLOCAL | CREAD;
    nt.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    nt.c_oflag &= ~OPOST;
    nt.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    //set hardware flow control
    //nt.c_cflag |= CRTSCTS;
    tcsetattr(uart_fd, TCSANOW, &nt);




    printf("RECV  total\n");

    while (1)
    {
        /******** 注意每次都要重新设置 ********/
        FD_ZERO(&recv_fds);
        FD_SET(uart_fd, &recv_fds);     /* 把句柄加入读监视集合里去 */

        /******** select超时时间设置(select会把tv清零，每次需要给tv赋值) ********/
        tv.tv_sec   = 10;           //设定超时时间 
        tv.tv_usec  = 0;            //10000us = 10ms

        /****************************** select ****************************************/
        fd_result = select(uart_fd + 1, &recv_fds, NULL, NULL, &tv);  /* 注意是fd加1 */
        /******** select函数出错 ********/
        if(fd_result < 0) {
            printf("Timer: %04d-%02d-%02d %02d:%02d:%02d ---- ", 
                    (1900+p->tm_year), (1+p->tm_mon), p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
            printf("select err \r\n");
            usleep(10000);
            continue;
        }
        /******** select函数超时结束 ********/
        else if(fd_result == 0) {
            /* 在设定的tv时间内，socket的状态没有发生变化 */
            //printf("Timer: %04d-%02d-%02d %02d:%02d:%02d ---- ", 
            //        (1900+p->tm_year), (1+p->tm_mon), p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
            //printf("select time out  --- tv.tv_sec = %d, tv.tv_usec = %d\r\n", tv.tv_sec, tv.tv_usec);
            usleep(10000);
            continue;
        }
        /******** select函数触发 ********/
        else {
            /* 先判断一下句柄是否可读 */
            if(FD_ISSET(uart_fd, &recv_fds)) {
                nread = read(uart_fd, recv_buff, 0xff);   /*  读取串口数据  */
                /*** 数据解析 */
                // 获取当前时间并打印
                time(&timep);
                p = gmtime(&timep);
                printf("Timer: %04d-%02d-%02d %02d:%02d:%02d ---- ", 
                    (1900+p->tm_year), (1+p->tm_mon), p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
                for(int i = 0; i < nread; i++)
                    printf("%02x ", recv_buff[i]);
                printf("\r\n");
                write(uart_fd, recv_buff, nread);
            }
        }
    }

    close(uart_fd);
    pthread_exit(0);
}

int main(void)
{
     pthread_t id1,id2,id3;
     int i,ret;

     ret=pthread_create(&id1,NULL,(void *)thread1,NULL);//创建线程1
     if(ret!=0)
     {
          printf("create pthread error !\n");
          exit(1);
     }

     pthread_join(id1,NULL);// 等待线程结束
     exit(0);
}
