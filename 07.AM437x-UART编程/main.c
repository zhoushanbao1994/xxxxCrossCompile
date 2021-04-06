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
    int fd = open( Dev, O_RDWR );
    if (-1 == fd) {
        perror("Can't Open Serial Port");
        return -1;
    } else
        return fd;
}


void thread1(void)// 线程1
{
    int  fd;
    int i=0,j=0;
    int nread;          /* Read the counts of data */
    char buff[512];     /* Recvice data buffer */

    char write_buff[512];

    int totol_read = 0;

    int speed = 115200;
    struct termios saveterm,nt;

    fd = OpenDev("/dev/ttyO5");

    if (fd > 0) {
        set_speed(fd, speed);
    } else {
        fprintf(stderr, "Error opening: %s\n", strerror(errno));
        pthread_exit(0);
    }

    if (set_Parity(fd,8,1,'N')== FALSE) {
        fprintf(stderr, "Set Parity Error\n");
        close(fd);
        pthread_exit(0);
    }

    tcgetattr(fd,&saveterm);
    nt=saveterm;
    nt.c_lflag &= ~(ICANON | ECHO | ECHOE);

    //set hardware flow control
    //nt.c_cflag |= CRTSCTS;

    tcsetattr(fd,TCSANOW,&nt);

    printf("RECV  total\n");

    while (1)
    {
        totol_read = 0;
        memset(write_buff, 0, sizeof(write_buff));

        while(totol_read < 26) {
            nread = read(fd, buff, sizeof(buff));
            if (nread > 0) {
                memcpy(write_buff + totol_read, buff, nread);
                totol_read += nread;
                write_buff[totol_read] = '\0';
                //printf("RECV %d total\n", nread);
                //printf("RECV: %s\n",  buff);
            }
            else {
                printf("RECV %d total\n", nread);
            }
        }

        write(fd, write_buff, strlen(write_buff));
    }

    close(fd);
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
