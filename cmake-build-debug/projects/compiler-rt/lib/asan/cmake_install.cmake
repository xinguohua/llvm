# Install script for directory: /home/nsas2020/fuzz/llvm-6.0.0/projects/compiler-rt/lib/asan

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang_rt.asan-i386" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux" TYPE STATIC_LIBRARY FILES "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/lib/clang/6.0.0/lib/linux/libclang_rt.asan-i386.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang_rt.asan-x86_64" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux" TYPE STATIC_LIBRARY FILES "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/lib/clang/6.0.0/lib/linux/libclang_rt.asan-x86_64.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang_rt.asan_cxx-i386" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux" TYPE STATIC_LIBRARY FILES "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/lib/clang/6.0.0/lib/linux/libclang_rt.asan_cxx-i386.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang_rt.asan_cxx-x86_64" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux" TYPE STATIC_LIBRARY FILES "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/lib/clang/6.0.0/lib/linux/libclang_rt.asan_cxx-x86_64.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang_rt.asan-preinit-i386" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux" TYPE STATIC_LIBRARY FILES "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/lib/clang/6.0.0/lib/linux/libclang_rt.asan-preinit-i386.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang_rt.asan-preinit-x86_64" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux" TYPE STATIC_LIBRARY FILES "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/lib/clang/6.0.0/lib/linux/libclang_rt.asan-preinit-x86_64.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang_rt.asan-dynamic-i386" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-i386.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-i386.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-i386.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux" TYPE SHARED_LIBRARY FILES "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/lib/clang/6.0.0/lib/linux/libclang_rt.asan-i386.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-i386.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-i386.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-i386.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang_rt.asan-dynamic-i386" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang_rt.asan-dynamic-x86_64" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-x86_64.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-x86_64.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-x86_64.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux" TYPE SHARED_LIBRARY FILES "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/lib/clang/6.0.0/lib/linux/libclang_rt.asan-x86_64.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-x86_64.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-x86_64.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux/libclang_rt.asan-x86_64.so")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang_rt.asan-dynamic-x86_64" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux" TYPE FILE FILES "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/lib/clang/6.0.0/lib/linux/libclang_rt.asan_cxx-x86_64.a.syms")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/lib/linux" TYPE FILE FILES "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/lib/clang/6.0.0/lib/linux/libclang_rt.asan-x86_64.a.syms")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "asan" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0" TYPE FILE FILES "/home/nsas2020/fuzz/llvm-6.0.0/projects/compiler-rt/lib/asan/asan_blacklist.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/projects/compiler-rt/lib/asan/scripts/cmake_install.cmake")
  include("/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/projects/compiler-rt/lib/asan/tests/cmake_install.cmake")

endif()

