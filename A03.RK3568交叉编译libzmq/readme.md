## 1. 获取ZMQ

libzmq的github链接[https://github.com/zeromq/libzmq](https://github.com/zeromq/libzmq)，下载最新的releases版[V4.3.5](https://github.com/zeromq/libzmq/releases/download/v4.3.5/zeromq-4.3.5.tar.gz)



## 2. 解压并进入

```shell
tar zxvf zeromq-4.3.5.tar.gz
cd zeromq-4.3.5
```



## 3. 创建指定交叉编译工具链的文件“toolchain.cmake”

```cmake
# 交叉编译工具链配置文件

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# 设置RK3568工具链的路径
set(ARM_TOOLCHAIN_PREFIX "/opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu")
## 设置T113工具链的路径
#set(ARM_TOOLCHAIN_PREFIX "/opt/t113/gcc-linaro-5.3.1-2016.05-x86_64_arm-linux-gnueabi/bin/arm-linux-gnueabi")

set(CMAKE_C_COMPILER "${ARM_TOOLCHAIN_PREFIX}-gcc")
set(CMAKE_CXX_COMPILER "${ARM_TOOLCHAIN_PREFIX}-g++")
```



## 4. 创建编译目录并进入及创建安装目录

```shell
mkdir build
cd build
mkdir install
```



## 5. 生成Makefile

```shell
cmake ../ -DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake -DCMAKE_INSTALL_PREFIX=./install

# ../ 是指定CMakelist.txt的路径
# -DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake 是指定交叉编译工具链文件的路径
# -DCMAKE_INSTALL_PREFIX=./install 是指定安装目录
```



## 6. 编译、安装

```shell
make
make install
```



## 7. 安装目录下最终的文件结构

编译后库文件版本号为5.2.5(libzmq.so.5.2.5)

```shell
~libzmq/zeromq-4.3.5/build# tree ./install
./install
├── bin
│   ├── inproc_lat
│   ├── inproc_thr
│   ├── local_lat
│   ├── local_thr
│   ├── proxy_thr
│   ├── remote_lat
│   └── remote_thr
├── include
│   ├── zmq.h
│   └── zmq_utils.h
├── lib
│   ├── cmake
│   │   └── ZeroMQ
│   │       ├── ZeroMQConfig.cmake
│   │       ├── ZeroMQConfigVersion.cmake
│   │       ├── ZeroMQTargets-release.cmake
│   │       └── ZeroMQTargets.cmake
│   ├── libzmq.a
│   ├── libzmq.so -> libzmq.so.5
│   ├── libzmq.so.5 -> libzmq.so.5.2.5
│   ├── libzmq.so.5.2.5
│   └── pkgconfig
│       └── libzmq.pc
└── share
    └── zmq
        ├── AUTHORS.txt
        ├── LICENSE.txt
        └── NEWS.txt

8 directories, 21 files
```

