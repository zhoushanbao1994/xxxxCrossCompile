# lib60870（IEC104）交叉编译



## 一、 编译环境



## 二、 下载

Git地址：https://github.com/mz-automation/lib60870

当前最新版本V2.3.6：https://github.com/mz-automation/lib60870/archive/refs/tags/v2.3.6.tar.gz



## 三、 编译

### 1. 解压

```shell
tar zxvf lib60870-2.3.6.tar.gz
cd lib60870-2.3.6/lib60870-C/
```



### 2. 创建编译工具链文件

创建"toolchain_rk3568.cmake"文件

```shell 
# toolchain-arm.cmake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# 指定交叉编译器路径
set(CMAKE_C_COMPILER /opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER /opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++)
```



创建"toolchain_t113.cmake"文件

```shell 
# toolchain-arm.cmake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# 指定交叉编译器路径
set(CMAKE_C_COMPILER /opt/t113/gcc-linaro-5.3.1-2016.05-x86_64_arm-linux-gnueabi/bin/arm-linux-gnueabi-gcc)
set(CMAKE_CXX_COMPILER /opt/t113/gcc-linaro-5.3.1-2016.05-x86_64_arm-linux-gnueabi/bin/arm-linux-gnueabi-g++)
```





### 3. 创建编译文件夹并进入及创建安装目录

```shell
mkdir build_rk3568
cd build_rk3568
mkdir install
```



### 4. 执行cmake

```shell
cmake ../ -DCMAKE_TOOLCHAIN_FILE=../toolchain_rk3568.cmake -DCMAKE_INSTALL_PREFIX=./install

# ../ 是指定CMakelist.txt的路径
# -DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake 是指定交叉编译工具链文件的路径
# -DCMAKE_INSTALL_PREFIX=./install 是指定安装目录
```



### 5. 编译、安装

```shell
make
make install
```



### 6. 安装目录下最终文件结构

```shell
~lib60870/lib60870-2.3.6/lib60870-C/build_rk3568# tree ./install
./install
├── include
│   └── lib60870
│       ├── cs101_file_service.h
│       ├── cs101_information_objects.h
│       ├── cs101_master.h
│       ├── cs101_slave.h
│       ├── cs104_connection.h
│       ├── cs104_slave.h
│       ├── hal_base.h
│       ├── hal_serial.h
│       ├── hal_socket.h
│       ├── hal_thread.h
│       ├── hal_time.h
│       ├── iec60870_common.h
│       ├── iec60870_master.h
│       ├── iec60870_slave.h
│       ├── link_layer_parameters.h
│       ├── linked_list.h
│       ├── tls_ciphers.h
│       └── tls_config.h
├── lib
│   ├── liblib60870.a
│   ├── liblib60870.so -> liblib60870.so.2.3.5
│   └── liblib60870.so.2.3.5
└── share
    └── pkgconfig
        └── lib60870.pc

5 directories, 22 files
```

