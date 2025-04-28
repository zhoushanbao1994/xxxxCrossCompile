## 1. 配置交叉编译环境



## 2. 编译openssl

### a) 下载源码

地址：[https://github.com/openssl/openssl/releases](https://github.com/openssl/openssl/releases)，选择版本： [1.1.1w]( https://github.com/openssl/openssl/archive/refs/tags/OpenSSL_1_1_1w.tar.gz)

```shell
# 下载
wget https://github.com/openssl/openssl/archive/refs/tags/OpenSSL_1_1_1w.tar.gz

# 解压
tar zxvf OpenSSL_1_1_1w.tar.gz

# 进入文件夹
cd openssl-OpenSSL_1_1_1w/
```



### b) 交叉编译

#### 配置(Configure方式)

Configure方式

```shell
./Configure linux-aarch64 no-asm shared --prefix=$PWD/_install --cross-compile-prefix=aarch64-none-linux-gnu-
```

（可选）修改Makefile，添加交叉编译器路径

```shell
# 找到
C=$(CROSS_COMPILE)gcc
CXX=$(CROSS_COMPILE)g++
# 改为
C=/opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/$(CROSS_COMPILE)gcc
CXX=/opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/$(CROSS_COMPILE)g++
```

```shell
# 找到
AR=$(CROSS_COMPILE)ar
ARFLAGS= r
RANLIB=$(CROSS_COMPILE)ranlib
RC=$(CROSS_COMPILE)windres
# 改为
AR=/opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/$(CROSS_COMPILE)ar
ARFLAGS= r
RANLIB=/opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/$(CROSS_COMPILE)ranlib
RC=/opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/$(CROSS_COMPILE)windres
```



#### ~~配置(config方式) 交叉编译不适用，会自动检测平台~~

~~config方式~~

```shell
./config no-asm shared --prefix=$PWD/install --cross-compile-prefix=aarch64-none-linux-gnu-
```

- ~~no-asm：Do not use assembler code~~
- ~~shared：编译连接成动态库~~
- ~~–prefix=$PWD/install：指定编译后安装路径~~
- ~~–cross-compile-prefix=aarch64-none-linux-gnu-：指定交叉编译工具链~~

~~修改Makefile~~

1. ~~修改平台~~

```shell
# 找到
PLATFORM=linux-x86_64
# 改为
PLATFORM=linux-aarch64
```

2. ~~删除“-m64”~~

```shell
# 找到
CNF_CFLAGS=-pthread -m64
CNF_CXXFLAGS=-std=c++11 -pthread -m64
# 改为
CNF_CFLAGS=-pthread #-m64
CNF_CXXFLAGS=-std=c++11 -pthread #-m64
```

2. ~~参照Configure方式，添加交叉编译器路径~~



#### 编译

```shell
make clean
make
make install
```





## 2. 编译paho.mqtt.c

### a) 下载源码

地址：[https://github.com/eclipse-paho/paho.mqtt.c/releases](https://github.com/eclipse-paho/paho.mqtt.c/releases)，当前最新版本：[1.3.14](https://github.com/eclipse-paho/paho.mqtt.c/archive/refs/tags/v1.3.14.tar.gz)

```shell
# 下载
wget https://github.com/eclipse-paho/paho.mqtt.c/archive/refs/tags/v1.3.14.tar.gz

# 解压
tar zxvf v1.3.14.tar.gz

# 进入文件夹
cd paho.mqtt.c-1.3.14/
```



### b) 交叉编译

```shell
make CC=/opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc CFLAGS:="-I /opt/rk3568/openssl/openssl-OpenSSL_1_1_1w/_install/include" LDFLAGS:="-L /opt/rk3568/openssl/openssl-OpenSSL_1_1_1w/_install/lib"
```



