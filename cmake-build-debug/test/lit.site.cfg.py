## Autogenerated from /home/nsas2020/fuzz/llvm-6.0.0/test/lit.site.cfg.py.in
## Do not edit!

import sys

config.host_triple = "x86_64-unknown-linux-gnu"
config.target_triple = "x86_64-unknown-linux-gnu"
config.llvm_src_root = "/home/nsas2020/fuzz/llvm-6.0.0"
config.llvm_obj_root = "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug"
config.llvm_tools_dir = "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/./bin"
config.llvm_lib_dir = "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/./lib"
config.llvm_shlib_dir = "/home/nsas2020/fuzz/llvm-6.0.0/cmake-build-debug/./lib"
config.llvm_shlib_ext = ".so"
config.llvm_exe_ext = ""
config.lit_tools_dir = ""
config.python_executable = "/usr/bin/python2.7"
config.gold_executable = "/usr/bin/ld.gold"
config.ld64_executable = ""
config.llvm_tool_lto_build = 1
config.ocamlfind_executable = "OCAMLFIND-NOTFOUND"
config.have_ocamlopt = 0
config.have_ocaml_ounit = 0
config.ocaml_flags = ""
config.include_go_tests = 1
config.go_executable = "/usr/bin/go"
config.enable_shared = 1
config.enable_assertions = 1
config.enable_abi_breaking_checks = "1"
config.targets_to_build = " AArch64 AMDGPU ARM BPF Hexagon Lanai Mips MSP430 NVPTX PowerPC Sparc SystemZ X86 XCore"
config.native_target = "X86"
config.llvm_bindings = " go".split(' ')
config.host_os = "Linux"
config.host_cc = "/usr/bin/cc "
config.host_cxx = "/usr/bin/c++ "
config.host_ldflags = " -Wl,-allow-shlib-undefined"
config.llvm_use_intel_jitevents = 0
config.llvm_use_sanitizer = ""
config.have_zlib = 1
config.have_libxar = 0
config.have_dia_sdk = 0
config.enable_ffi = 0
config.build_shared_libs = 0
config.link_llvm_dylib = 0
config.llvm_libxml2_enabled = "1"
config.llvm_host_triple = 'x86_64-unknown-linux-gnu'
config.host_arch = "x86_64"
config.have_opt_viewer_modules = 0

# Support substitution of the tools_dir with user parameters. This is
# used when we can't determine the tool dir at configuration time.
try:
    config.llvm_tools_dir = config.llvm_tools_dir % lit_config.params
    config.llvm_shlib_dir = config.llvm_shlib_dir % lit_config.params
except KeyError:
    e = sys.exc_info()[1]
    key, = e.args
    lit_config.fatal("unable to find %r parameter, use '--param=%s=VALUE'" % (key,key))

import lit.llvm
lit.llvm.initialize(lit_config, config)


# Let the main config do the real work.
lit_config.load_config(config, "/home/nsas2020/fuzz/llvm-6.0.0/test/lit.cfg.py")
