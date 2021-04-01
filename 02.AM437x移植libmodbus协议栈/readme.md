AM437x移植LibModbus协议栈



## 1. 配置交叉编译环境
## 2. 下载

https://libmodbus.org/download/ 

稳定版：v3.0.8



## 3. 安装

### a) 拷贝文件

将压缩包拷贝至配置好交叉编译环境的Ubuntu系统中，/opt/libmodbus/目录

### b) 解压

 ```shell
tar -zxvf libmodbus-3.0.8.tar.gz 
 ```

### c) 创建安装目录

```shell
mkdir install-3.0.8
```

### d) 进入解压后的目录

```shell
cd libmodbus-3.0.8
```

### e) 配置编译选项

 --host=[交叉编译工具链前缀] ,例如 arm-none-linux-gnueabi 、arm-linux-gnueabihf

 --prefix=[安装路径]

```shell
root@ubuntu:/opt/libmodbus/libmodbus-3.0.8# ./configure --build=i386 --host=arm-linux-gnueabihf --enable-static --prefix=/opt/libmodbus/install-3.0.8/
checking for a BSD-compatible install... /usr/bin/install -c
checking whether build environment is sane... yes
checking for arm-linux-gnueabihf-strip... arm-linux-gnueabihf-strip
checking for a thread-safe mkdir -p... /bin/mkdir -p
checking for gawk... no
checking for mawk... mawk
checking whether make sets $(MAKE)... yes
checking whether make supports nested variables... yes
checking whether make supports nested variables... (cached) yes
checking build system type... i386-pc-none
checking host system type... arm-unknown-linux-gnueabihf
checking for arm-linux-gnueabihf-gcc... arm-linux-gnueabihf-gcc
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
checking for suffix of executables... 
checking whether we are cross compiling... yes
checking for suffix of object files... o
checking whether we are using the GNU C compiler... yes
checking whether arm-linux-gnueabihf-gcc accepts -g... yes
checking for arm-linux-gnueabihf-gcc option to accept ISO C89... none needed
checking whether arm-linux-gnueabihf-gcc understands -c and -o together... yes
checking whether make supports the include directive... yes (GNU style)
checking dependency style of arm-linux-gnueabihf-gcc... gcc3
checking for arm-linux-gnueabihf-g++... arm-linux-gnueabihf-g++
checking whether we are using the GNU C++ compiler... yes
checking whether arm-linux-gnueabihf-g++ accepts -g... yes
checking dependency style of arm-linux-gnueabihf-g++... gcc3
checking whether make sets $(MAKE)... (cached) yes
checking how to print strings... printf
checking for a sed that does not truncate output... /bin/sed
checking for grep that handles long lines and -e... /bin/grep
checking for egrep... /bin/grep -E
checking for fgrep... /bin/grep -F
checking for ld used by arm-linux-gnueabihf-gcc... /opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/arm-linux-gnueabihf/bin/ld
checking if the linker (/opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/arm-linux-gnueabihf/bin/ld) is GNU ld... yes
checking for BSD- or MS-compatible name lister (nm)... /opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/bin/arm-linux-gnueabihf-nm -B
checking the name lister (/opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/bin/arm-linux-gnueabihf-nm -B) interface... BSD nm
checking whether ln -s works... yes
checking the maximum length of command line arguments... 1572864
checking how to convert i386-pc-none file names to arm-unknown-linux-gnueabihf format... func_convert_file_noop
checking how to convert i386-pc-none file names to toolchain format... func_convert_file_noop
checking for /opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/arm-linux-gnueabihf/bin/ld option to reload object files... -r
checking for arm-linux-gnueabihf-objdump... arm-linux-gnueabihf-objdump
checking how to recognize dependent libraries... pass_all
checking for arm-linux-gnueabihf-dlltool... no
checking for dlltool... no
checking how to associate runtime and link libraries... printf %s\n
checking for arm-linux-gnueabihf-ar... arm-linux-gnueabihf-ar
checking for archiver @FILE support... @
checking for arm-linux-gnueabihf-strip... (cached) arm-linux-gnueabihf-strip
checking for arm-linux-gnueabihf-ranlib... arm-linux-gnueabihf-ranlib
checking command to parse /opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/bin/arm-linux-gnueabihf-nm -B output from arm-linux-gnueabihf-gcc object... ok
checking for sysroot... no
checking for a working dd... /bin/dd
checking how to truncate binary pipes... /bin/dd bs=4096 count=1
checking for arm-linux-gnueabihf-mt... no
checking for mt... mt
configure: WARNING: using cross tools not prefixed with host triplet
checking if mt is a manifest tool... no
checking how to run the C preprocessor... arm-linux-gnueabihf-gcc -E
checking for ANSI C header files... yes
checking for sys/types.h... yes
checking for sys/stat.h... yes
checking for stdlib.h... yes
checking for string.h... yes
checking for memory.h... yes
checking for strings.h... yes
checking for inttypes.h... yes
checking for stdint.h... yes
checking for unistd.h... yes
checking for dlfcn.h... yes
checking for objdir... .libs
checking if arm-linux-gnueabihf-gcc supports -fno-rtti -fno-exceptions... no
checking for arm-linux-gnueabihf-gcc option to produce PIC... -fPIC -DPIC
checking if arm-linux-gnueabihf-gcc PIC flag -fPIC -DPIC works... yes
checking if arm-linux-gnueabihf-gcc static flag -static works... yes
checking if arm-linux-gnueabihf-gcc supports -c -o file.o... yes
checking if arm-linux-gnueabihf-gcc supports -c -o file.o... (cached) yes
checking whether the arm-linux-gnueabihf-gcc linker (/opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/arm-linux-gnueabihf/bin/ld) supports shared libraries... yes
checking whether -lc should be explicitly linked in... no
checking dynamic linker characteristics... GNU/Linux ld.so
checking how to hardcode library paths into programs... immediate
checking whether stripping libraries is possible... yes
checking if libtool supports shared libraries... yes
checking whether to build shared libraries... yes
checking whether to build static libraries... yes
checking how to run the C++ preprocessor... arm-linux-gnueabihf-g++ -E
checking for ld used by arm-linux-gnueabihf-g++... /opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/arm-linux-gnueabihf/bin/ld
checking if the linker (/opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/arm-linux-gnueabihf/bin/ld) is GNU ld... yes
checking whether the arm-linux-gnueabihf-g++ linker (/opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/arm-linux-gnueabihf/bin/ld) supports shared libraries... yes
checking for arm-linux-gnueabihf-g++ option to produce PIC... -fPIC -DPIC
checking if arm-linux-gnueabihf-g++ PIC flag -fPIC -DPIC works... yes
checking if arm-linux-gnueabihf-g++ static flag -static works... yes
checking if arm-linux-gnueabihf-g++ supports -c -o file.o... yes
checking if arm-linux-gnueabihf-g++ supports -c -o file.o... (cached) yes
checking whether the arm-linux-gnueabihf-g++ linker (/opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/arm-linux-gnueabihf/bin/ld) supports shared libraries... yes
checking dynamic linker characteristics... (cached) GNU/Linux ld.so
checking how to hardcode library paths into programs... immediate
checking termios.h usability... yes
checking termios.h presence... yes
checking for termios.h... yes
checking sys/time.h usability... yes
checking sys/time.h presence... yes
checking for sys/time.h... yes
checking time.h usability... yes
checking time.h presence... yes
checking for time.h... yes
checking for unistd.h... (cached) yes
checking errno.h usability... yes
checking errno.h presence... yes
checking for errno.h... yes
checking limits.h usability... yes
checking limits.h presence... yes
checking for limits.h... yes
checking fcntl.h usability... yes
checking fcntl.h presence... yes
checking for fcntl.h... yes
checking for sys/types.h... (cached) yes
checking sys/socket.h usability... yes
checking sys/socket.h presence... yes
checking for sys/socket.h... yes
checking sys/ioctl.h usability... yes
checking sys/ioctl.h presence... yes
checking for sys/ioctl.h... yes
checking netinet/in.h usability... yes
checking netinet/in.h presence... yes
checking for netinet/in.h... yes
checking netinet/tcp.h usability... yes
checking netinet/tcp.h presence... yes
checking for netinet/tcp.h... yes
checking arpa/inet.h usability... yes
checking arpa/inet.h presence... yes
checking for arpa/inet.h... yes
checking netdb.h usability... yes
checking netdb.h presence... yes
checking for netdb.h... yes
checking linux/serial.h usability... yes
checking linux/serial.h presence... yes
checking for linux/serial.h... yes
checking for asciidoc... no
checking for xmlto... no
checking whether to build documentation... no
checking whether to install manpages... yes
checking for ANSI C header files... (cached) yes
checking for an ANSI C-conforming const... yes
checking for size_t... yes
checking whether time.h and sys/time.h may both be included... yes
checking whether __CYGWIN__ is declared... no
checking for pid_t... yes
checking vfork.h usability... no
checking vfork.h presence... no
checking for vfork.h... no
checking for fork... yes
checking for vfork... yes
checking for working fork... cross
configure: WARNING: result yes guessed because of cross compilation
checking for working vfork... (cached) yes
checking for gettimeofday... yes
checking for inet_ntoa... yes
checking for memset... yes
checking for select... yes
checking for socket... yes
checking for strerror... yes
checking for strlcpy... no
checking for getaddrinfo... yes
checking winsock2.h usability... no
checking winsock2.h presence... no
checking for winsock2.h... no
checking whether TIOCSRS485 is declared... yes
checking that generated files are newer than configure... done
configure: creating ./config.status
config.status: creating Makefile
config.status: creating src/Makefile
config.status: creating src/modbus-version.h
config.status: creating doc/Makefile
config.status: creating tests/Makefile
config.status: creating libmodbus.pc
config.status: creating libmodbus.spec
config.status: creating config.h
config.status: creating tests/unit-test.h
config.status: tests/unit-test.h is unchanged
config.status: executing depfiles commands
config.status: executing libtool commands
root@ubuntu:/opt/libmodbus/libmodbus-3.0.8# 
```

### f) 编译

```shell
rroot@ubuntu:/opt/libmodbus/libmodbus-3.0.8# make
make  all-recursive
make[1]: Entering directory '/opt/libmodbus/libmodbus-3.0.8'
Making all in src
make[2]: Entering directory '/opt/libmodbus/libmodbus-3.0.8/src'
  CC       modbus.lo
  CC       modbus-data.lo
  CC       modbus-rtu.lo
  CC       modbus-tcp.lo
  CCLD     libmodbus.la
make[2]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8/src'
Making all in doc
make[2]: Entering directory '/opt/libmodbus/libmodbus-3.0.8/doc'
make[2]: Nothing to be done for 'all'.
make[2]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8/doc'
Making all in tests
make[2]: Entering directory '/opt/libmodbus/libmodbus-3.0.8/tests'
make  all-am
make[3]: Entering directory '/opt/libmodbus/libmodbus-3.0.8/tests'
  CC       bandwidth-server-one.o
  CCLD     bandwidth-server-one
  CC       bandwidth-server-many-up.o
  CCLD     bandwidth-server-many-up
  CC       bandwidth-client.o
  CCLD     bandwidth-client
  CC       random-test-server.o
  CCLD     random-test-server
  CC       random-test-client.o
  CCLD     random-test-client
  CC       unit-test-server.o
  CCLD     unit-test-server
  CC       unit-test-client.o
  CCLD     unit-test-client
  CC       version.o
  CCLD     version
make[3]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8/tests'
make[2]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8/tests'
make[2]: Entering directory '/opt/libmodbus/libmodbus-3.0.8'
make[2]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8'
make[1]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8'
root@ubuntu:/opt/libmodbus/libmodbus-3.0.8# 
```

### g) 安装

```shell
root@ubuntu:/opt/libmodbus/libmodbus-3.0.8# make install
Making install in src
make[1]: Entering directory '/opt/libmodbus/libmodbus-3.0.8/src'
make[2]: Entering directory '/opt/libmodbus/libmodbus-3.0.8/src'
 /bin/mkdir -p '/opt/libmodbus/install-3.0.8/lib'
 /bin/bash ../libtool   --mode=install /usr/bin/install -c   libmodbus.la '/opt/libmodbus/install-3.0.8/lib'
libtool: install: /usr/bin/install -c .libs/libmodbus.so.5.0.5 /opt/libmodbus/install-3.0.8/lib/libmodbus.so.5.0.5
libtool: install: (cd /opt/libmodbus/install-3.0.8/lib && { ln -s -f libmodbus.so.5.0.5 libmodbus.so.5 || { rm -f libmodbus.so.5 && ln -s libmodbus.so.5.0.5 libmodbus.so.5; }; })
libtool: install: (cd /opt/libmodbus/install-3.0.8/lib && { ln -s -f libmodbus.so.5.0.5 libmodbus.so || { rm -f libmodbus.so && ln -s libmodbus.so.5.0.5 libmodbus.so; }; })
libtool: install: /usr/bin/install -c .libs/libmodbus.lai /opt/libmodbus/install-3.0.8/lib/libmodbus.la
libtool: install: /usr/bin/install -c .libs/libmodbus.a /opt/libmodbus/install-3.0.8/lib/libmodbus.a
libtool: install: chmod 644 /opt/libmodbus/install-3.0.8/lib/libmodbus.a
libtool: install: arm-linux-gnueabihf-ranlib /opt/libmodbus/install-3.0.8/lib/libmodbus.a
libtool: finish: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/bin:/opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/bin:/sbin" ldconfig -n /opt/libmodbus/install-3.0.8/lib
----------------------------------------------------------------------
Libraries have been installed in:
   /opt/libmodbus/install-3.0.8/lib

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the '-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the 'LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the 'LD_RUN_PATH' environment variable
     during linking
   - use the '-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to '/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------
 /bin/mkdir -p '/opt/libmodbus/install-3.0.8/include/modbus'
 /usr/bin/install -c -m 644 modbus.h modbus-version.h modbus-rtu.h modbus-tcp.h '/opt/libmodbus/install-3.0.8/include/modbus'
make[2]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8/src'
make[1]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8/src'
Making install in doc
make[1]: Entering directory '/opt/libmodbus/libmodbus-3.0.8/doc'
make[2]: Entering directory '/opt/libmodbus/libmodbus-3.0.8/doc'
make[2]: Nothing to be done for 'install-exec-am'.
 /bin/mkdir -p '/opt/libmodbus/install-3.0.8/share/man/man3'
 /usr/bin/install -c -m 644 modbus_close.3 modbus_connect.3 modbus_flush.3 modbus_free.3 modbus_get_byte_from_bits.3 modbus_get_byte_timeout.3 modbus_get_float.3 modbus_get_header_length.3 modbus_get_response_timeout.3 modbus_get_socket.3 modbus_mapping_free.3 modbus_mapping_new.3 modbus_new_rtu.3 modbus_new_tcp_pi.3 modbus_new_tcp.3 modbus_read_bits.3 modbus_read_input_bits.3 modbus_read_input_registers.3 modbus_read_registers.3 modbus_receive_confirmation.3 modbus_receive_from.3 modbus_receive.3 modbus_reply_exception.3 modbus_reply.3 modbus_report_slave_id.3 modbus_rtu_get_serial_mode.3 modbus_rtu_set_serial_mode.3 modbus_send_raw_request.3 modbus_set_bits_from_bytes.3 modbus_set_bits_from_byte.3 modbus_set_byte_timeout.3 modbus_set_debug.3 modbus_set_error_recovery.3 modbus_set_float.3 modbus_set_response_timeout.3 modbus_set_slave.3 modbus_set_socket.3 modbus_strerror.3 modbus_tcp_listen.3 modbus_write_and_read_registers.3 '/opt/libmodbus/install-3.0.8/share/man/man3'
 /usr/bin/install -c -m 644 modbus_write_bits.3 modbus_write_bit.3 modbus_write_registers.3 modbus_write_register.3 '/opt/libmodbus/install-3.0.8/share/man/man3'
 /bin/mkdir -p '/opt/libmodbus/install-3.0.8/share/man/man7'
 /usr/bin/install -c -m 644 libmodbus.7 '/opt/libmodbus/install-3.0.8/share/man/man7'
make[2]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8/doc'
make[1]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8/doc'
Making install in tests
make[1]: Entering directory '/opt/libmodbus/libmodbus-3.0.8/tests'
make[2]: Entering directory '/opt/libmodbus/libmodbus-3.0.8/tests'
make[2]: Nothing to be done for 'install-exec-am'.
make[2]: Nothing to be done for 'install-data-am'.
make[2]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8/tests'
make[1]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8/tests'
make[1]: Entering directory '/opt/libmodbus/libmodbus-3.0.8'
make[2]: Entering directory '/opt/libmodbus/libmodbus-3.0.8'
make[2]: Nothing to be done for 'install-exec-am'.
 /bin/mkdir -p '/opt/libmodbus/install-3.0.8/lib/pkgconfig'
 /usr/bin/install -c -m 644 libmodbus.pc '/opt/libmodbus/install-3.0.8/lib/pkgconfig'
make[2]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8'
make[1]: Leaving directory '/opt/libmodbus/libmodbus-3.0.8'
root@ubuntu:/opt/libmodbus/libmodbus-3.0.8# 
```

### h) 生成动态链接库

在install生成三个目录：include lib share

```shell
root@ubuntu:/opt/libmodbus/install-3.0.8# ll
total 20
drwxr-xr-x 5 root root 4096 Nov 10 22:24 ./
drwxr-xr-x 4 root root 4096 Nov 10 22:22 ../
drwxr-xr-x 3 root root 4096 Nov 10 22:24 include/
drwxr-xr-x 3 root root 4096 Nov 10 22:24 lib/
drwxr-xr-x 3 root root 4096 Nov 10 22:24 share/
```

lib文件夹中的libmodbus.so、libmodbus.so.5、libmodbus.so.5.0.5就是动态链接库

```shell
root@ubuntu:/opt/libmodbus/install-3.0.8/lib# ls -la
total 232
drwxr-xr-x 3 root root   4096 Nov 10 23:13 .
drwxr-xr-x 5 root root   4096 Nov 10 23:13 ..
-rw-r--r-- 1 root root 119440 Nov 10 23:13 libmodbus.a
-rwxr-xr-x 1 root root    957 Nov 10 23:13 libmodbus.la
lrwxrwxrwx 1 root root     18 Nov 10 23:13 libmodbus.so -> libmodbus.so.5.0.5
lrwxrwxrwx 1 root root     18 Nov 10 23:13 libmodbus.so.5 -> libmodbus.so.5.0.5
-rwxr-xr-x 1 root root  96936 Nov 10 23:13 libmodbus.so.5.0.5
drwxr-xr-x 2 root root   4096 Nov 10 23:13 pkgconfig
root@ubuntu:/opt/libmodbus/install-3.0.8/lib# 
```

确认文件为ARM

```shell
root@ubuntu:/opt/libmodbus/install-3.0.8/lib# file libmodbus*
libmodbus.a:        current ar archive
libmodbus.la:       libtool library file, ASCII text
libmodbus.so:       symbolic link to libmodbus.so.5.0.5
libmodbus.so.5:     symbolic link to libmodbus.so.5.0.5
libmodbus.so.5.0.5: ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, BuildID[sha1]=1a71df072440df182130c6dcf4b661d32b5f703e, not stripped
root@ubuntu:/opt/libmodbus/install-3.0.8/lib# 
```



## 4. 移植到ARM开发板

### a) 复制文件到ARM开发板

将libmodbus.so、libmodbus.so.5、libmodbus.so.5.0.5复制到ARM开发板中的/usr/lib目录下



## 5. 创建测试程序

### a) 创建文件夹，用于存放测试工程

### b) 复制库头我呢见

 将/opt/libmodbus/install-3.0.8/include/modbus中的四个头文件modbus.h、modbus-rtu.h、modbus-tcp.h、modbus-version.h复制到刚创建的文件夹。  

```shell
root@ubuntu:/opt/libmodbus/install-3.0.8/include/modbus# ls
modbus.h  modbus-rtu.h  modbus-tcp.h  modbus-version.h
root@ubuntu:/opt/libmodbus/install-3.0.8/include/modbus# cp modbus.h modbus-rtu.h modbus-tcp.h modbus-version.h /opt/am437x/app_test_new/modbus_test/
```

### c) 创建测试C文件

```c
/*************************
**
** modbus-rtu-test.c
** 移植libmodbus库到ARM开发板，并测试成功
**
**************************/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include "modbus.h"  //modbus动态库文件

int main(int argc, char *argv[])
{
    uint16_t tab_reg[64] = {0}; //定义存放数据的数组
    modbus_t *ctx = NULL;

    int rc;
    int i;
    
    //以串口的方式创建libmobus实例,并设置参数
    ctx = modbus_new_rtu("/dev/ttyO3", 115200, 'N', 8, 1);
    if (ctx == NULL)                //使用UART1,对应的设备描述符为ttyS1
    {
        fprintf(stderr, "Unable to allocate libmodbus contex\n");
        return -1;
    }

    modbus_set_debug(ctx, 1);      //设置1可看到调试信息
    modbus_set_slave(ctx, 1);      //设置slave ID

    if (modbus_connect(ctx) == -1) //等待连接设备
    {
        fprintf(stderr, "Connection failed:%s\n", modbus_strerror(errno));
        return -1;
    }
    
    // 设置超时时间
    struct timeval t;
    t.tv_sec = 3;
    t.tv_usec = 0000000;//1000ms
    modbus_set_response_timeout(ctx,&t);

    while (1)
    {
        printf("\n----------------\n");
        rc = modbus_read_registers(ctx, 0, 10, tab_reg);
        if (rc == -1)                   //读取保持寄存器的值，可读取多个连续输入保持寄存器
        {
            fprintf(stderr,"%s\n", modbus_strerror(errno));
            //return -1;
        }
        else {
            for (i=0; i<10; i++)
            {
                printf("reg[%d] = %d(0x%x)\n", i, tab_reg[i], tab_reg[i]);
            }
        }
        usleep(3000000);
    }
    modbus_close(ctx);  //关闭modbus连接
    modbus_free(ctx);   //释放modbus资源，使用完libmodbus需要释放掉

    return 0;
}
```

### d) 编译


```shell
arm-linux-gnueabihf-gcc test.c -o test -L /opt/libmodbus/install-3.0.8/lib/ -lmodbus
```

- -L /opt/libmodbus/install-3.0.8/lib/
- 由于没有将生成的库文件拷贝至交叉编译器的默认环境中，所以需要增加“-L /opt/libmodbus/install-3.0.8/lib/”
- 也可已将生成的所有库文件拷贝至“/opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/lib”

### e) 复制可执行文件到开发板

将可执行程序文件test复制到ARM开发板的文件夹下。



## 6. 测试

PC端使用“Modbus Salve”，与板子对测，正常





## 参考

 https://www.twblogs.net/a/5c8b8c79bd9eee35cd6ac859/zh-cn 

 https://blog.csdn.net/u010168781/article/details/73924748 

 https://blog.csdn.net/zgkxzx/article/details/78231171 

 https://zhuanlan.zhihu.com/p/27480603 





## 关于CCU板子的其他说明

1. 网口

   Net1：IP192.168.10.100

   Net2：IP192.168.20.100

   IP地址修改：修改开机启动脚本“/mnt/mmcblk0p2/autoStartRcs.sh”

2. Telnet

   用户：root，密码：root

3. 开机启动

```shell
/mnt/mmcblk0p2/autoStartRcs.sh
```
4. 传输文件

   传输文件使用tftp，在Win主机上运行tftp32工具-server模式，在开发板上运行

   ```shell
   #下载单个文件到开发板（IP为window IP）
   tftp -g -r filename IP     
   
   #上传单个文件到pc端（IP为window IP）
   tftp -p -l filename IP
   ```

   
