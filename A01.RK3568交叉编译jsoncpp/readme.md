## RK3568交叉编译jsoncpp

### 一、下载文件

https://github.com/open-source-parsers/jsoncpp

https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.9.5.tar.gz

压缩包文件名为“jsoncpp-1.9.5.tar.gz”

### 二、准备文件夹

1. 创建“jsoncpp”文件夹（此文件夹为最外层文件夹）

2. 将“jsoncpp-1.9.5.tar.gz”拷贝至“jsoncpp”，并解压

   ```shell
   tar zxvf jsoncpp-1.9.5.tar.gz
   ```

3. 修改 CMakeLists.txt，将 JSONCPP_WITH_TESTS 配置成 OFF，不去编译测试工程

   ```shell
   # 注：如果不修改，最后会报错，测试工程“jsoncpp_test”与本机不匹配导致的报错（jsoncpp_test是交叉编译生成的，不能再本机运行）
   option(JSONCPP_WITH_TESTS "Compile and (for jsoncpp_check) run JsonCpp test executables" ON)
   option(JSONCPP_WITH_TESTS "Compile and (for jsoncpp_check) run JsonCpp test executables" OFF)
   ```

4. 在“jsoncpp”下，创建文件“toolchain.cmake”，文件内容如下

   ```cmake
   # 设置 CMAKE_SYSTEM_NAME 为 Linux，指的是编译代码的系统是 Linux，必须配置
   SET(CMAKE_SYSTEM_NAME Linux)
   # 设置 CMAKE_SYSTEM_PROCESSOR 为 arm，指的是运行的系统是在 arm 上面
   SET(CMAKE_SYSTEM_PROCESSOR arm)
   
   # 定义 TOOLCHAIN_PATH ，供后续使用
   SET(TOOLCHAIN_PATH /opt/rk3568/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu)
   #SET(TOOLCHAIN_PATH /opt/rk3568/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu)
   #SET(CMAKE_SYSROOT ${TOOLCHAIN_PATH}/aarch64-none-linux-gnu)
   # 指定C交叉编译器,必须配置
   SET(CMAKE_C_COMPILER   ${TOOLCHAIN_PATH}/bin/aarch64-none-linux-gnu-gcc)
   # 指定C++交叉编译器
   SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}/bin/aarch64-none-linux-gnu-g++)
   
   # search for programs in the build host directories
   SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
   
   # for libraries and headers in the target directories
   SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
   SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
   SET(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
   ```
   
   ```cmake
   # 设置 CMAKE_SYSTEM_NAME 为 Linux，指的是编译代码的系统是 Linux，必须配置
   SET(CMAKE_SYSTEM_NAME Linux)
   # 设置 CMAKE_SYSTEM_PROCESSOR 为 arm，指的是运行的系统是在 arm 上面
   SET(CMAKE_SYSTEM_PROCESSOR arm)
   
   # 定义 TOOLCHAIN_PATH ，供后续使用
   SET(TOOLCHAIN_PATH /opt/t113/gcc-linaro-5.3.1-2016.05-x86_64_arm-linux-gnueabi)
   #SET(CMAKE_SYSROOT ${TOOLCHAIN_PATH}/arm-linux-gnueabi)
   # 指定C交叉编译器,必须配置
   SET(CMAKE_C_COMPILER   ${TOOLCHAIN_PATH}/bin/arm-linux-gnueabi-gcc)
   # 指定C++交叉编译器
   SET(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}/bin/arm-linux-gnueabi-g++)
   
   # search for programs in the build host directories
   SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
   
   # for libraries and headers in the target directories
   SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
   SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
   SET(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
   ```
   
5. 在“jsoncpp”下，创建文件夹“build”“install”

6. 此时目录结构

   ```shell
   root@xxxx:~/jsoncpp# ls -la
   total 236
   drwxr-xr-x  2 root root   4096 Jan 23 18:45 build
   drwxr-xr-x  2 root root   4096 Jan 23 18:45 install
   drwxrwxr-x 12 root root   4096 Nov  4  2021 jsoncpp-1.9.5
   -rwxrwxrwx  1 root root 216055 Jan 23 17:34 jsoncpp-1.9.5.tar.gz
   -rw-r--r--  1 root root    925 Jan 23 18:23 toolchain.cmake
   ```

## 三、编译

1. 进入“build”文件夹内，执行cmke

   ```shell
   cd build
   cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake -DCMAKE_INSTALL_PREFIX=../install ../jsoncpp-1.9.5
   -- The CXX compiler identification is GNU 10.3.1
   -- Check for working CXX compiler: /opt/rk3568/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++
   -- Check for working CXX compiler: /opt/rk3568/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++ -- works
   -- Detecting CXX compiler ABI info
   -- Detecting CXX compiler ABI info - done
   -- Detecting CXX compile features
   -- Detecting CXX compile features - done
   -- JsonCpp Version: 1.9.5
   -- Looking for C++ include clocale
   -- Looking for C++ include clocale - found
   -- Looking for localeconv
   -- Looking for localeconv - found
   -- Looking for C++ include sys/types.h
   -- Looking for C++ include sys/types.h - found
   -- Looking for C++ include stdint.h
   -- Looking for C++ include stdint.h - found
   -- Looking for C++ include stddef.h
   -- Looking for C++ include stddef.h - found
   -- Check size of lconv
   -- Check size of lconv - done
   -- Performing Test HAVE_DECIMAL_POINT
   -- Performing Test HAVE_DECIMAL_POINT - Success
   -- Found Python3: /usr/bin/python3.8 (found version "3.8.10") found components: Interpreter
   -- Configuring done
   -- Generating done
   -- Build files have been written to: /opt/rk3568/jsoncpp/build
   ```

2. 执行make

   ```shell
   root@xxxx:~/jsoncpp/build# make
   Scanning dependencies of target jsoncpp_object
   [  9%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_object.dir/json_reader.cpp.o
   [ 18%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_object.dir/json_value.cpp.o
   [ 27%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_object.dir/json_writer.cpp.o
   [ 27%] Built target jsoncpp_object
   Scanning dependencies of target jsoncpp_static
   [ 36%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_static.dir/json_reader.cpp.o
   [ 45%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_static.dir/json_value.cpp.o
   [ 54%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_static.dir/json_writer.cpp.o
   [ 63%] Linking CXX static library ../../lib/libjsoncpp.a
   [ 63%] Built target jsoncpp_static
   Scanning dependencies of target jsoncpp_lib
   [ 72%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_reader.cpp.o
   [ 81%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_value.cpp.o
   [ 90%] Building CXX object src/lib_json/CMakeFiles/jsoncpp_lib.dir/json_writer.cpp.o
   [100%] Linking CXX shared library ../../lib/libjsoncpp.so
   [100%] Built target jsoncpp_lib
   ```

3. 执行make install

   ```shell
   root@xxxx:~/jsoncpp/build# make install
   [ 27%] Built target jsoncpp_object
   [ 63%] Built target jsoncpp_static
   [100%] Built target jsoncpp_lib
   Install the project...
   -- Install configuration: "Release"
   -- Installing: /opt/rk3568/jsoncpp/install/lib/pkgconfig/jsoncpp.pc
   -- Installing: /opt/rk3568/jsoncpp/install/lib/cmake/jsoncpp/jsoncpp-targets.cmake
   -- Installing: /opt/rk3568/jsoncpp/install/lib/cmake/jsoncpp/jsoncpp-targets-release.cmake
   -- Installing: /opt/rk3568/jsoncpp/install/lib/cmake/jsoncpp/jsoncppConfigVersion.cmake
   -- Installing: /opt/rk3568/jsoncpp/install/lib/cmake/jsoncpp/jsoncppConfig.cmake
   -- Installing: /opt/rk3568/jsoncpp/install/lib/cmake/jsoncpp/jsoncpp-namespaced-targets.cmake
   -- Installing: /opt/rk3568/jsoncpp/install/lib/libjsoncpp.so.1.9.5
   -- Installing: /opt/rk3568/jsoncpp/install/lib/libjsoncpp.so.25
   -- Installing: /opt/rk3568/jsoncpp/install/lib/libjsoncpp.so
   -- Installing: /opt/rk3568/jsoncpp/install/lib/libjsoncpp.a
   -- Installing: /opt/rk3568/jsoncpp/install/lib/objects-Release/jsoncpp_object/json_reader.cpp.o
   -- Installing: /opt/rk3568/jsoncpp/install/lib/objects-Release/jsoncpp_object/json_value.cpp.o
   -- Installing: /opt/rk3568/jsoncpp/install/lib/objects-Release/jsoncpp_object/json_writer.cpp.o
   -- Installing: /opt/rk3568/jsoncpp/install/include/json/allocator.h
   -- Installing: /opt/rk3568/jsoncpp/install/include/json/assertions.h
   -- Installing: /opt/rk3568/jsoncpp/install/include/json/config.h
   -- Installing: /opt/rk3568/jsoncpp/install/include/json/forwards.h
   -- Installing: /opt/rk3568/jsoncpp/install/include/json/json.h
   -- Installing: /opt/rk3568/jsoncpp/install/include/json/json_features.h
   -- Installing: /opt/rk3568/jsoncpp/install/include/json/reader.h
   -- Installing: /opt/rk3568/jsoncpp/install/include/json/value.h
   -- Installing: /opt/rk3568/jsoncpp/install/include/json/version.h
   -- Installing: /opt/rk3568/jsoncpp/install/include/json/writer.h
   ```
   
4. 此时“/jsoncpp/install/”就是对应的库文件、头文件

