AM4379移植SQLite3数据库



## 1. 配置交叉编译环境

## 2. 下载

网址：[https://www.sqlite.org/download.html](https://www.sqlite.org/download.html)，点击 "sqlite-autoconf-xxx.tar.gz" 下载源码包。

当前版本[sqlite-autoconf-3350200.tar.gz](https://www.sqlite.org/2021/sqlite-autoconf-3350200.tar.gz) 

## 3. 安装
### a) 拷贝文件
将压缩包拷贝至配置好交叉编译环境的Ubuntu系统中，/opt/sqlite3/目录  

### b) 解压

```shell
tar -zxvf sqlite-autoconf-3350200.tar.gz
```

### c) 创建库输出目录

```shell
mkdir arm_build    //用于arm版本的安装目录
```

### d) 配置并生成MakeFile
```shell
# 进入工程目录
cd sqlite-autoconf-3350200
# 指定编译参数
./configure CC=arm-linux-gnueabihf-gcc --prefix=/opt/sqlite3/arm_build --host=arm-linux-gnueabihf --build=i386
```

- CC=xxx               指定交叉编译工具链。
- --prefix=PREFIX 指定安装目录。
- --build=BUILD     指定软件包安装的系统平台.如果没有指定,默认值将是'--host'选项的值.
- --host=HOST      指定软件运行的系统平台.如果没有指定,将会运行`config.guess'来检测.

指定编译参数时打印如下

```shell
root@ubuntu:/opt/sqlite3/sqlite-autoconf-3350200# ./configure CC=arm-linux-gnueabihf-gcc --prefix=/opt/sqlite3/arm_build --host=arm-linux-gnueabihf --build=i386
checking for a BSD-compatible install... /usr/bin/install -c
checking whether build environment is sane... yes
checking for arm-linux-gnueabihf-strip... arm-linux-gnueabihf-strip
checking for a thread-safe mkdir -p... /bin/mkdir -p
checking for gawk... no
checking for mawk... mawk
checking whether make sets $(MAKE)... yes
checking whether make supports nested variables... yes
checking for style of include used by make... GNU
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
checking dependency style of arm-linux-gnueabihf-gcc... gcc3
checking for special C compiler options needed for large files... no
checking for _FILE_OFFSET_BITS value needed for large files... 64
checking for arm-linux-gnueabihf-gcc... (cached) arm-linux-gnueabihf-gcc
checking whether we are using the GNU C compiler... (cached) yes
checking whether arm-linux-gnueabihf-gcc accepts -g... (cached) yes
checking for arm-linux-gnueabihf-gcc option to accept ISO C89... (cached) none needed
checking whether arm-linux-gnueabihf-gcc understands -c and -o together... (cached) yes
checking dependency style of arm-linux-gnueabihf-gcc... (cached) gcc3
checking build system type... i386-pc-none
checking host system type... arm-unknown-linux-gnueabihf
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
checking for fdatasync... yes
checking for usleep... yes
checking for fullfsync... no
checking for localtime_r... yes
checking for gmtime_r... yes
checking whether strerror_r is declared... yes
checking for strerror_r... yes
checking whether strerror_r returns char *... no
checking editline/readline.h usability... no
checking editline/readline.h presence... no
checking for editline/readline.h... no
checking readline/readline.h usability... yes
checking readline/readline.h presence... yes
checking for readline/readline.h... yes
checking for library containing tgetent... -ltermcap
checking for library containing readline... -lreadline
checking for library containing pthread_create... -lpthread
checking for library containing pthread_mutexattr_init... none required
checking for library containing dlopen... -ldl
checking for whether to support dynamic extensions... yes
checking SQL math functions... enabled
checking for library containing ceil... -lm
checking FTS4 extension... enabled
checking FTS3 extension... disabled
checking FTS5 extension... enabled
checking for library containing log... none required
checking JSON functions... enabled
checking RTREE extension... enabled
checking Session extension... disabled
checking Build type... release
checking for posix_fallocate... yes
checking zlib.h usability... yes
checking zlib.h presence... yes
checking for zlib.h... yes
checking for library containing deflate... -lz
checking for library containing system... none required
checking that generated files are newer than configure... done
configure: creating ./config.status
config.status: creating Makefile
config.status: creating sqlite3.pc
config.status: executing depfiles commands
config.status: executing libtool commands
root@ubuntu:/opt/sqlite3/sqlite-autoconf-3350200# 
```

### e) 编译安装

```shell
root@ubuntu:/opt/sqlite3/sqlite-autoconf-3350200# make
/bin/bash ./libtool  --tag=CC   --mode=compile arm-linux-gnueabihf-gcc -DPACKAGE_NAME=\"sqlite\" -DPACKAGE_TARNAME=\"sqlite\" -DPACKAGE_VERSION=\"3.35.2\" -DPACKAGE_STRING=\"sqlite\ 3.35.2\" -DPACKAGE_BUGREPORT=\"http://www.sqlite.org\" -DPACKAGE_URL=\"\" -DPACKAGE=\"sqlite\" -DVERSION=\"3.35.2\" -D_FILE_OFFSET_BITS=64 -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_DLFCN_H=1 -DLT_OBJDIR=\".libs/\" -DHAVE_FDATASYNC=1 -DHAVE_USLEEP=1 -DHAVE_LOCALTIME_R=1 -DHAVE_GMTIME_R=1 -DHAVE_DECL_STRERROR_R=1 -DHAVE_STRERROR_R=1 -DHAVE_READLINE_READLINE_H=1 -DHAVE_READLINE=1 -DHAVE_POSIX_FALLOCATE=1 -DHAVE_ZLIB_H=1 -I.    -D_REENTRANT=1 -DSQLITE_THREADSAFE=1 -DSQLITE_ENABLE_MATH_FUNCTIONS -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_JSON1 -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_GEOPOLY -DSQLITE_HAVE_ZLIB  -g -O2 -MT sqlite3.lo -MD -MP -MF .deps/sqlite3.Tpo -c -o sqlite3.lo sqlite3.c
libtool: compile:  arm-linux-gnueabihf-gcc -DPACKAGE_NAME=\"sqlite\" -DPACKAGE_TARNAME=\"sqlite\" -DPACKAGE_VERSION=\"3.35.2\" "-DPACKAGE_STRING=\"sqlite 3.35.2\"" -DPACKAGE_BUGREPORT=\"http://www.sqlite.org\" -DPACKAGE_URL=\"\" -DPACKAGE=\"sqlite\" -DVERSION=\"3.35.2\" -D_FILE_OFFSET_BITS=64 -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_DLFCN_H=1 -DLT_OBJDIR=\".libs/\" -DHAVE_FDATASYNC=1 -DHAVE_USLEEP=1 -DHAVE_LOCALTIME_R=1 -DHAVE_GMTIME_R=1 -DHAVE_DECL_STRERROR_R=1 -DHAVE_STRERROR_R=1 -DHAVE_READLINE_READLINE_H=1 -DHAVE_READLINE=1 -DHAVE_POSIX_FALLOCATE=1 -DHAVE_ZLIB_H=1 -I. -D_REENTRANT=1 -DSQLITE_THREADSAFE=1 -DSQLITE_ENABLE_MATH_FUNCTIONS -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_JSON1 -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_GEOPOLY -DSQLITE_HAVE_ZLIB -g -O2 -MT sqlite3.lo -MD -MP -MF .deps/sqlite3.Tpo -c sqlite3.c  -fPIC -DPIC -o .libs/sqlite3.o
libtool: compile:  arm-linux-gnueabihf-gcc -DPACKAGE_NAME=\"sqlite\" -DPACKAGE_TARNAME=\"sqlite\" -DPACKAGE_VERSION=\"3.35.2\" "-DPACKAGE_STRING=\"sqlite 3.35.2\"" -DPACKAGE_BUGREPORT=\"http://www.sqlite.org\" -DPACKAGE_URL=\"\" -DPACKAGE=\"sqlite\" -DVERSION=\"3.35.2\" -D_FILE_OFFSET_BITS=64 -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_DLFCN_H=1 -DLT_OBJDIR=\".libs/\" -DHAVE_FDATASYNC=1 -DHAVE_USLEEP=1 -DHAVE_LOCALTIME_R=1 -DHAVE_GMTIME_R=1 -DHAVE_DECL_STRERROR_R=1 -DHAVE_STRERROR_R=1 -DHAVE_READLINE_READLINE_H=1 -DHAVE_READLINE=1 -DHAVE_POSIX_FALLOCATE=1 -DHAVE_ZLIB_H=1 -I. -D_REENTRANT=1 -DSQLITE_THREADSAFE=1 -DSQLITE_ENABLE_MATH_FUNCTIONS -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_JSON1 -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_GEOPOLY -DSQLITE_HAVE_ZLIB -g -O2 -MT sqlite3.lo -MD -MP -MF .deps/sqlite3.Tpo -c sqlite3.c -o sqlite3.o >/dev/null 2>&1
mv -f .deps/sqlite3.Tpo .deps/sqlite3.Plo
/bin/bash ./libtool  --tag=CC   --mode=link arm-linux-gnueabihf-gcc -D_REENTRANT=1 -DSQLITE_THREADSAFE=1 -DSQLITE_ENABLE_MATH_FUNCTIONS -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_JSON1 -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_GEOPOLY -DSQLITE_HAVE_ZLIB  -g -O2 -no-undefined -version-info 8:6:8  -o libsqlite3.la -rpath /opt/sqlite3/arm_build/lib sqlite3.lo  -lz -lm -ldl -lpthread 
libtool: link: arm-linux-gnueabihf-gcc -shared  -fPIC -DPIC  .libs/sqlite3.o   -lz -lm -ldl -lpthread  -g -O2   -Wl,-soname -Wl,libsqlite3.so.0 -o .libs/libsqlite3.so.0.8.6
libtool: link: (cd ".libs" && rm -f "libsqlite3.so.0" && ln -s "libsqlite3.so.0.8.6" "libsqlite3.so.0")
libtool: link: (cd ".libs" && rm -f "libsqlite3.so" && ln -s "libsqlite3.so.0.8.6" "libsqlite3.so")
libtool: link: arm-linux-gnueabihf-ar cru .libs/libsqlite3.a  sqlite3.o
libtool: link: arm-linux-gnueabihf-ranlib .libs/libsqlite3.a
libtool: link: ( cd ".libs" && rm -f "libsqlite3.la" && ln -s "../libsqlite3.la" "libsqlite3.la" )
arm-linux-gnueabihf-gcc -DPACKAGE_NAME=\"sqlite\" -DPACKAGE_TARNAME=\"sqlite\" -DPACKAGE_VERSION=\"3.35.2\" -DPACKAGE_STRING=\"sqlite\ 3.35.2\" -DPACKAGE_BUGREPORT=\"http://www.sqlite.org\" -DPACKAGE_URL=\"\" -DPACKAGE=\"sqlite\" -DVERSION=\"3.35.2\" -D_FILE_OFFSET_BITS=64 -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_DLFCN_H=1 -DLT_OBJDIR=\".libs/\" -DHAVE_FDATASYNC=1 -DHAVE_USLEEP=1 -DHAVE_LOCALTIME_R=1 -DHAVE_GMTIME_R=1 -DHAVE_DECL_STRERROR_R=1 -DHAVE_STRERROR_R=1 -DHAVE_READLINE_READLINE_H=1 -DHAVE_READLINE=1 -DHAVE_POSIX_FALLOCATE=1 -DHAVE_ZLIB_H=1 -I.    -D_REENTRANT=1 -DSQLITE_THREADSAFE=1 -DSQLITE_ENABLE_MATH_FUNCTIONS -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_JSON1 -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_GEOPOLY -DSQLITE_HAVE_ZLIB  -DSQLITE_ENABLE_EXPLAIN_COMMENTS -DSQLITE_ENABLE_DBPAGE_VTAB -DSQLITE_ENABLE_STMTVTAB -DSQLITE_ENABLE_DBSTAT_VTAB  -g -O2 -MT sqlite3-shell.o -MD -MP -MF .deps/sqlite3-shell.Tpo -c -o sqlite3-shell.o `test -f 'shell.c' || echo './'`shell.c
mv -f .deps/sqlite3-shell.Tpo .deps/sqlite3-shell.Po
arm-linux-gnueabihf-gcc -DPACKAGE_NAME=\"sqlite\" -DPACKAGE_TARNAME=\"sqlite\" -DPACKAGE_VERSION=\"3.35.2\" -DPACKAGE_STRING=\"sqlite\ 3.35.2\" -DPACKAGE_BUGREPORT=\"http://www.sqlite.org\" -DPACKAGE_URL=\"\" -DPACKAGE=\"sqlite\" -DVERSION=\"3.35.2\" -D_FILE_OFFSET_BITS=64 -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_DLFCN_H=1 -DLT_OBJDIR=\".libs/\" -DHAVE_FDATASYNC=1 -DHAVE_USLEEP=1 -DHAVE_LOCALTIME_R=1 -DHAVE_GMTIME_R=1 -DHAVE_DECL_STRERROR_R=1 -DHAVE_STRERROR_R=1 -DHAVE_READLINE_READLINE_H=1 -DHAVE_READLINE=1 -DHAVE_POSIX_FALLOCATE=1 -DHAVE_ZLIB_H=1 -I.    -D_REENTRANT=1 -DSQLITE_THREADSAFE=1 -DSQLITE_ENABLE_MATH_FUNCTIONS -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_JSON1 -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_GEOPOLY -DSQLITE_HAVE_ZLIB  -DSQLITE_ENABLE_EXPLAIN_COMMENTS -DSQLITE_ENABLE_DBPAGE_VTAB -DSQLITE_ENABLE_STMTVTAB -DSQLITE_ENABLE_DBSTAT_VTAB  -g -O2 -MT sqlite3-sqlite3.o -MD -MP -MF .deps/sqlite3-sqlite3.Tpo -c -o sqlite3-sqlite3.o `test -f 'sqlite3.c' || echo './'`sqlite3.c
mv -f .deps/sqlite3-sqlite3.Tpo .deps/sqlite3-sqlite3.Po
/bin/bash ./libtool  --tag=CC   --mode=link arm-linux-gnueabihf-gcc -D_REENTRANT=1 -DSQLITE_THREADSAFE=1 -DSQLITE_ENABLE_MATH_FUNCTIONS -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_JSON1 -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_GEOPOLY -DSQLITE_HAVE_ZLIB  -DSQLITE_ENABLE_EXPLAIN_COMMENTS -DSQLITE_ENABLE_DBPAGE_VTAB -DSQLITE_ENABLE_STMTVTAB -DSQLITE_ENABLE_DBSTAT_VTAB  -g -O2   -o sqlite3 sqlite3-shell.o sqlite3-sqlite3.o -lreadline -ltermcap  -lz -lm -ldl -lpthread 
libtool: link: arm-linux-gnueabihf-gcc -D_REENTRANT=1 -DSQLITE_THREADSAFE=1 -DSQLITE_ENABLE_MATH_FUNCTIONS -DSQLITE_ENABLE_FTS4 -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_JSON1 -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_GEOPOLY -DSQLITE_HAVE_ZLIB -DSQLITE_ENABLE_EXPLAIN_COMMENTS -DSQLITE_ENABLE_DBPAGE_VTAB -DSQLITE_ENABLE_STMTVTAB -DSQLITE_ENABLE_DBSTAT_VTAB -g -O2 -o sqlite3 sqlite3-shell.o sqlite3-sqlite3.o  -lreadline -ltermcap -lz -lm -ldl -lpthread
root@ubuntu:/opt/sqlite3/sqlite-autoconf-3350200# 
```

```shell
root@ubuntu:/opt/sqlite3/sqlite-autoconf-3350200# make install
make[1]: Entering directory '/opt/sqlite3/sqlite-autoconf-3350200'
 /bin/mkdir -p '/opt/sqlite3/arm_build/lib'
 /bin/bash ./libtool   --mode=install /usr/bin/install -c   libsqlite3.la '/opt/sqlite3/arm_build/lib'
libtool: install: /usr/bin/install -c .libs/libsqlite3.so.0.8.6 /opt/sqlite3/arm_build/lib/libsqlite3.so.0.8.6
libtool: install: (cd /opt/sqlite3/arm_build/lib && { ln -s -f libsqlite3.so.0.8.6 libsqlite3.so.0 || { rm -f libsqlite3.so.0 && ln -s libsqlite3.so.0.8.6 libsqlite3.so.0; }; })
libtool: install: (cd /opt/sqlite3/arm_build/lib && { ln -s -f libsqlite3.so.0.8.6 libsqlite3.so || { rm -f libsqlite3.so && ln -s libsqlite3.so.0.8.6 libsqlite3.so; }; })
libtool: install: /usr/bin/install -c .libs/libsqlite3.lai /opt/sqlite3/arm_build/lib/libsqlite3.la
libtool: install: /usr/bin/install -c .libs/libsqlite3.a /opt/sqlite3/arm_build/lib/libsqlite3.a
libtool: install: chmod 644 /opt/sqlite3/arm_build/lib/libsqlite3.a
libtool: install: arm-linux-gnueabihf-ranlib /opt/sqlite3/arm_build/lib/libsqlite3.a
libtool: finish: PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/x86_64-arago-linux/usr/bin:/sbin" ldconfig -n /opt/sqlite3/arm_build/lib
----------------------------------------------------------------------
Libraries have been installed in:
   /opt/sqlite3/arm_build/lib

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
 /bin/mkdir -p '/opt/sqlite3/arm_build/bin'
  /bin/bash ./libtool   --mode=install /usr/bin/install -c sqlite3 '/opt/sqlite3/arm_build/bin'
libtool: install: /usr/bin/install -c sqlite3 /opt/sqlite3/arm_build/bin/sqlite3
 /bin/mkdir -p '/opt/sqlite3/arm_build/include'
 /usr/bin/install -c -m 644 sqlite3.h sqlite3ext.h '/opt/sqlite3/arm_build/include'
 /bin/mkdir -p '/opt/sqlite3/arm_build/share/man/man1'
 /usr/bin/install -c -m 644 sqlite3.1 '/opt/sqlite3/arm_build/share/man/man1'
 /bin/mkdir -p '/opt/sqlite3/arm_build/lib/pkgconfig'
 /usr/bin/install -c -m 644 sqlite3.pc '/opt/sqlite3/arm_build/lib/pkgconfig'
make[1]: Leaving directory '/opt/sqlite3/sqlite-autoconf-3350200'
root@ubuntu:/opt/sqlite3/sqlite-autoconf-3350200# 
```

### f) 编译结果

```shell
# 进入编译结果目录
root@ubuntu:/opt/sqlite3# cd arm_build/
root@ubuntu:/opt/sqlite3/arm_build# ls
bin  include  lib  share
root@ubuntu:/opt/sqlite3/arm_build# cd lib/
root@ubuntu:/opt/sqlite3/arm_build/lib# ls
libsqlite3.a  libsqlite3.la  libsqlite3.so  libsqlite3.so.0  libsqlite3.so.0.8.6  pkgconfig
# 查看文件信息
root@ubuntu:/opt/sqlite3/arm_build/lib# file libsqlite3.so.0.8.6 
libsqlite3.so.0.8.6: ELF 32-bit LSB shared object, ARM, EABI5 version 1 (SYSV), dynamically linked, BuildID[sha1]=f1a5fac12eb229ae4506b4ed2d6376f7bce73553, not stripped
root@ubuntu:/opt/sqlite3/arm_build/lib# 
```

## 4. 移植到ARM开发板

### a) 压缩打包

将编译生成的lib文件夹、bin文件夹，压缩打包

```shell
root@ubuntu:/opt/sqlite3/arm_build# tar -zcvf lib_sqlite3_am4379.tar.gz lib/
lib/
lib/libsqlite3.so
lib/libsqlite3.so.0
lib/libsqlite3.la
lib/libsqlite3.so.0.8.6
lib/pkgconfig/
lib/pkgconfig/sqlite3.pc
lib/libsqlite3.a
root@ubuntu:/opt/sqlite3/arm_build# tar -zcvf bin_sqlite3_am4379.tar.gz bin
bin/
bin/sqlite3
root@ubuntu:/opt/sqlite3/arm_build#
```



### b) 传输文件

通过Tftp工具将两个文件传输至ARM开发板中的临时目录

```shell
[root@nudt sqlite3]# tftp -g -r bin_sqlite3_am4379.tar.gz 192.168.10.250
bin_sqlite3_am4379.t 100% |****************************************************|  2177k  0:00:00 ETA
[root@nudt sqlite3]# tftp -g -r lib_sqlite3_am4379.tar.gz 192.168.10.250
lib_sqlite3_am4379.t 100% |****************************************************|  4280k  0:00:00 ETA
[root@nudt sqlite3]# ls
bin_sqlite3_am4379.tar.gz  lib_sqlite3_am4379.tar.gz
```

### c) 解压

```shell
[root@nudt sqlite3]# tar -zxvf bin_sqlite3_am4379.tar.gz
bin/
bin/sqlite3
[root@nudt sqlite3]# tar -zxvf lib_sqlite3_am4379.tar.gz 
lib/
lib/libsqlite3.so
lib/libsqlite3.so.0
lib/libsqlite3.la
lib/libsqlite3.so.0.8.6
lib/pkgconfig/
lib/pkgconfig/sqlite3.pc
lib/libsqlite3.a
[root@nudt sqlite3]# ls
bin                        lib
bin_sqlite3_am4379.tar.gz  lib_sqlite3_am4379.tar.gz
[root@nudt sqlite3]# 
```



### d) 复制库文件到指定路径

/lib/目录下的 libsqlite3.so libsqlite3.so.0 libsqlite3.so.0.8.6三个文件，复制到ARM开发板中的**/usr/lib**目录下  

```shell
[root@nudt sqlite3]# cd lib/
[root@nudt lib]# ls
libsqlite3.a         libsqlite3.so        libsqlite3.so.0.8.6
libsqlite3.la        libsqlite3.so.0      pkgconfig
[root@nudt lib]# cp libsqlite3.so /usr/lib/
[root@nudt lib]# cp libsqlite3.so.0 /usr/lib/
[root@nudt lib]# cp libsqlite3.so.0.8.6 /usr/lib/
```



### b) 可执行文件

/bin/目录下的 sqlite3文件为可执行程序，拷贝至板子上使用。



## 附录拷贝readline、ncuses库

进入交缠编译器的路径“/opt/am437x/ti-processor-sdk-linux-rt-am437x-evm-03.01.00.06/linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/usr/lib”，将“libncurses.so       libreadline.so      libreadline.so.5    libreadline.so.5.2”文件拷贝至开发板“/usr/lib”路径



# RK3568编译说明

1. 配置环境变量

   ```shell
   export PATH=$PATH:/opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/
   
   aarch64-none-linux-gnu-gcc -v
   Using built-in specs.
   COLLECT_GCC=aarch64-none-linux-gnu-gcc
   COLLECT_LTO_WRAPPER=/opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/../libexec/gcc/aarch64-none-linux-gnu/9.2.1/lto-wrapper
   Target: aarch64-none-linux-gnu
   Configured with: ........
   gcc version 9.2.1 20191025 (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
   ```

2. 下载最新版本[sqlite-autoconf-3460100.tar.gz](https://www.sqlite.org/2024/sqlite-autoconf-3460100.tar.gz)；创建安装目录 mkdir install；解压后进入文件夹 tar -zxvf sqlite-autoconf-3460100.tar.gz

3. 指定编译参数，生成makefile

   ```shell
   # 指定编译参数
   ./configure CC=aarch64-none-linux-gnu-gcc --prefix=/opt/rk3568/sqlite/install/ --host=aarch64-none-linux-gnu --build=i386
   ```

4. 编译&安装

   ```shell
   make
   make install
   ```

   
