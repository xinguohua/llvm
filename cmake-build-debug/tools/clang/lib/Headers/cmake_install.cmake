# Install script for directory: /home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers

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

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang-headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/include" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/adxintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/altivec.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/ammintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/arm_acle.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/armintr.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/arm64intr.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx2intrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512bwintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512bitalgintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vlbitalgintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512cdintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vpopcntdqintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512dqintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512erintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512fintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512ifmaintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512ifmavlintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512pfintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vbmiintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vbmivlintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vbmi2intrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vlvbmi2intrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vlbwintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vlcdintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vldqintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vlintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vpopcntdqvlintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vnniintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avx512vlvnniintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/avxintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/bmi2intrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/bmiintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/__clang_cuda_builtin_vars.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/__clang_cuda_cmath.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/__clang_cuda_complex_builtins.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/__clang_cuda_intrinsics.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/__clang_cuda_math_forward_declares.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/__clang_cuda_runtime_wrapper.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/cetintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/clzerointrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/cpuid.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/clflushoptintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/clwbintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/emmintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/f16cintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/float.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/fma4intrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/fmaintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/fxsrintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/gfniintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/htmintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/htmxlintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/ia32intrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/immintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/intrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/inttypes.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/iso646.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/limits.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/lwpintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/lzcntintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/mm3dnow.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/mmintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/mm_malloc.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/module.modulemap"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/msa.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/mwaitxintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/nmmintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/opencl-c.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/pkuintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/pmmintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/popcntintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/prfchwintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/rdseedintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/rtmintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/s390intrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/shaintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/smmintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/stdalign.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/stdarg.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/stdatomic.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/stdbool.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/stddef.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/__stddef_max_align_t.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/stdint.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/stdnoreturn.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/tbmintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/tgmath.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/tmmintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/unwind.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/vadefs.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/vaesintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/varargs.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/vecintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/vpclmulqdqintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/wmmintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/__wmmintrin_aes.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/__wmmintrin_pclmul.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/x86intrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/xmmintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/xopintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/xsavecintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/xsaveintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/xsaveoptintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/xsavesintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/xtestintrin.h"
    "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/tools/clang/lib/Headers/arm_neon.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "clang-headers" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/clang/6.0.0/include/cuda_wrappers" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/cuda_wrappers/algorithm"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/cuda_wrappers/complex"
    "/home/nsas2020/fuzz/llvm-6.0.0/tools/clang/lib/Headers/cuda_wrappers/new"
    )
endif()

