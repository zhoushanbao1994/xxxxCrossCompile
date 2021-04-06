#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<linux/types.h>


#define I2C_RDWR  0x0707

struct i2c_rdwr_ioctl_data {
struct i2c_msg  *msgs;  /* pointers to i2c_msgs */
unsigned int nmsgs;  /* number of i2c_msgs */
};
struct i2c_msg {
unsigned short addr;  /* slave address  */
unsigned short flags;
unsigned short len;  /* msg length  */
unsigned char *buf;  /* pointer to msg data  */
};
int main()
{
int fd;
//1.打开通用设备文件
fd = open("/dev/hi_i2c",O_RDWR);
struct i2c_rdwr_ioctl_data data;
data.msgs = (struct i2c_msg *)malloc(2*sizeof(struct i2c_msg));
//2.构造写入到从设备的消息
data.nmsgs = 1;   //消息的数目
data.msgs[0].len = 2;
data.msgs[0].addr = 0x20;
data.msgs[0].flags = 0;  //flags说明读还是写
data.msgs[0].buf = (unsigned char *)malloc(2);
data.msgs[0].buf[0] = 0x01;     //填入从设备寄存器地址
data.msgs[0].buf[1] = 0x20;     //向寄存器写入的值
//3.使用ioctl写入数据
ioctl(fd,I2C_RDWR,(unsigned long)&data);
//4.构造读出从设备数据的消息
data.nmsgs = 2;
data.msgs[0].len = 1;
data.msgs[0].addr = 0x20; //从设备地址
data.msgs[0].flags = 0;  //flags说明读还是写
//data.msgs[0].buf = (unsigned char *)malloc(2);
data.msgs[0].buf[0] = 0x01;     //填入从设备寄存器地址 
data.msgs[1].len = 1;
data.msgs[1].addr = 0x20; //从设备地址
data.msgs[1].flags = 1;  //flags说明读还是写
data.msgs[1].buf = (unsigned char *)malloc(2);
data.msgs[1].buf[0] = 0;     //填入从设备寄存器地址 
//5.使用ioctl读数据
ioctl(fd,I2C_RDWR,(unsigned long)&data);
printf("buf[0]=%x\n",data.msgs[1].buf[0]);
//6.关闭设备
close(fd);
}
————————————————
版权声明：本文为CSDN博主「w335191658」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/w335191658/article/details/52516759/