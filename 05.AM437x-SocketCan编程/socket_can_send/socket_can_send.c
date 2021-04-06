/* 1.报文发送程序 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

int main()
{
    int s, nbytes;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame[2] = {{0}};
    
    //创建套接字
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    strcpy(ifr.ifr_name, "can0" );
    ioctl(s, SIOCGIFINDEX, &ifr); //指定 can0 设备
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;
    bind(s, (struct sockaddr *)&addr, sizeof(addr));//将套接字与 can0 绑定
    //禁用过滤规则，本进程不接收报文，只负责发送
    setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, NULL, 0);
    //生成两个报文
    frame[0].can_id  = 0x11;    // CAN ID
    frame[0].can_dlc = 8;       // 长度
    frame[0].data[0] = 0x01;    // 数据
    frame[0].data[1] = 0x02;
    frame[0].data[2] = 0x03;
    frame[0].data[3] = 0x04;
    frame[0].data[4] = 0x05;
    frame[0].data[5] = 0x06;
    frame[0].data[6] = 0x07;
    frame[0].data[7] = 0x08;
    frame[1].can_id  = 0x22;    // CAN ID
    frame[1].can_dlc = 8;       // 长度
    frame[1].data[0] = 0x11;    // 数据
    frame[1].data[1] = 0x22;
    frame[1].data[2] = 0x33;
    frame[1].data[3] = 0x44;
    frame[1].data[4] = 0x55;
    frame[1].data[5] = 0x66;
    frame[1].data[6] = 0x77;
    frame[1].data[7] = 0x88;
    while(1)
    {
        nbytes = write(s, &frame[0], sizeof(frame[0])); //发送 frame[0]
        if(nbytes != sizeof(frame[0])) {
            printf("Send Error frame[0]\n!");
            break; //发送错误，退出
        }
        sleep(1);
        nbytes = write(s, &frame[1], sizeof(frame[1])); //发送 frame[1]
        if(nbytes != sizeof(frame[1])) {
            printf("Send Error frame[1]\n!");
            break;
        }
        sleep(1);
    }
    close(s);
    
    return 0;
}
