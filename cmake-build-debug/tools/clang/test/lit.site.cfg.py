## Autogenerated from /home/nsas2020/ufo/llvm-6.0.0/tools/clang/test/lit.site.cfg.py.in
## Do not edit!

import sys

config.llvm_src_root = "/home/nsas2020/ufo/llvm-6.0.0"
config.llvm_obj_root = "/home/nsas2020/ufo/llvm-6.0.0/cmake-build-debug"
config.llvm_tools_dir = "/home/nsas2020/ufo/llvm-6.0.0/cmake-build-debug/./bin"
config.llvm_libs_dir = "/home/nsas2020/ufo/llvm-6.0.0/cmake-build-debug/./lib"
config.llvm_shlib_dir = "/home/nsas2020/ufo/llvm-6.0.0/cmake-build-debug/./lib"
config.llvm_plugin_ext = ".so"
config.lit_tools_dir = ""
config.clang_obj_root = "/home/nsas2020/ufo/llvm-6.0.0/cmake-build-debug/tools/clang"
config.clang_src_dir = "/home/nsas2020/ufo/llvm-6.0.0/tools/clang"
config.clang_tools_dir = "/home/nsas2020/ufo/llvm-6.0.0/cmake-build-debug/./bin"
config.host_triple = "x86_64-unknown-linux-gnu"
config.target_triple = "x86_64-unknown-linux-gnu"
config.host_cxx = "/usr/bin/c++"
config.llvm_use_sanitizer = ""
config.have_zlib = 1
config.clang_arcmt = 1
config.clang_default_cxx_stdlib = ""
config.clang_staticanalyzer = 1
config.clang_staticanalyzer_z3 = ""
config.clang_examples = 0
config.enable_shared = 1
config.enable_backtrace = 1
config.host_arch = "x86_64"
config.enable_abi_breaking_checks = "1"
config.python_executable = "/usr/bin/python2.7"

# Support substitution of the tools and libs dirs with user parameters. This is
# used when we can't determine the tool dir at configuration time.
try:
    config.clang_tools_dir = config.clang_tools_dir % lit_config.params
    config.llvm_tools_dir = config.llvm_tools_dir % lit_config.params
    config.llvm_shlib_dir = config.llvm_shlib_dir % lit_config.params
    config.llvm_libs_dir = config.llvm_libs_dir % lit_config.params
except KeyError:
    e = sys.exc_info()[1]
    key, = e.args
    lit_config.fatal("unable to find %r parameter, use '--param=%s=VALUE'" % (key,key))

import lit.llvm
lit.llvm.initialize(lit_config, config)


# Let the main config do the real work.
lit_config.load_config(config, "/home/nsas2020/ufo/llvm-6.0.0/tools/clang/test/lit.cfg.py")
