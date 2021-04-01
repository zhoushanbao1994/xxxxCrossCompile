## AM437x交叉编译工具安装说明：

### 文件说明：

- ccu_brd文件夹：ARM板的几个测试例子
- arm-gcc文件夹：交叉编译开发环境

### 准备

一台Linux PC或者虚拟机Linux系统(系统必须是64位，建议Ubuntu16.04_x64)

### 开始

#### 1. 新建目录

在Linux的/opt目录下新建am437x目录;

#### 2. 拷贝文件至Linux系统中

- 将arm-gcc目录下ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06-Linux-x86-Install.bin文件拷贝到新建的am437x目录下
- 将arm-gcc目录下setting.sh文件拷贝到新建的am437x目录下
- 将app_test目录全部拷贝至到新建的am437x目录下

#### 3. 安装

在目录/opt/am437x下运行命令：

```shell
# 安装交叉编译器
./ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06-Linux-x86-Install.bin
# 设置环境变量
source setting.sh 
```

#### 4. 编译测试

进入测试程序路径
```shell
cd  /opt/am437x/app_test/ccu_brd
```

执行命令

make  clean
make

出现“arm-linux-gnueabihf-gcc .....” 即可认为交叉编译环境搭建完成

```shell
root@ubuntu:/opt/am437x/app_test/ccu_brd# make clean
rm -f  ccu_brd_test *.all *.o
root@ubuntu:/opt/am437x/app_test_new/ccu_brd# make
arm-linux-gnueabihf-gcc -c -o ai-adc.o ai-adc.c
arm-linux-gnueabihf-gcc -c -o ao-dac.o ao-dac.c
arm-linux-gnueabihf-gcc -c -o gpio.o gpio.c
arm-linux-gnueabihf-gcc -c -o led.o led.c
arm-linux-gnueabihf-gcc -c -o main.o main.c
arm-linux-gnueabihf-gcc -c -o uart.o uart.c
arm-linux-gnueabihf-gcc -o ccu_brd_test ai-adc.o ao-dac.o gpio.o led.o main.o uart.o -lpthread
root@ubuntu:/opt/am437x/app_test/ccu_brd# 
```



