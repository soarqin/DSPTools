#ifndef _C4CORE_SINGLE_HEADER_AMALGAMATED_HPP_
#define _C4CORE_SINGLE_HEADER_AMALGAMATED_HPP_

//
// c4core - C++ utilities
//
// https://github.com/biojppm/c4core
//
// DO NOT EDIT. This file is generated automatically.
// This is an amalgamated single-header version of the library.
//
// INSTRUCTIONS:
//   - Include at will in any header of your project
//   - In one (and only one) of your project source files,
//     #define C4CORE_SINGLE_HDR_DEFINE_NOW and then include this header.
//     This will enable the function and class definitions in
//     the header file.
//   - To compile into a shared library, just define the
//     preprocessor symbol C4CORE_SHARED . This will take
//     care of symbol export/import.
//



//********************************************************************************
//--------------------------------------------------------------------------------
// LICENSE.txt
// https://github.com/biojppm/c4core/LICENSE.txt
//--------------------------------------------------------------------------------
//********************************************************************************

// Copyright (c) 2018, Joao Paulo Magalhaes <dev@jpmag.me>
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

// shared library: export when defining
#if defined(C4CORE_SHARED) && defined(C4CORE_SINGLE_HDR_DEFINE_NOW) && !defined(C4CORE_EXPORTS)
#define C4CORE_EXPORTS
#endif




//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/export.hpp
// https://github.com/biojppm/c4core/src/c4/export.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef C4_EXPORT_HPP_
#define C4_EXPORT_HPP_

#ifdef _WIN32
    #ifdef C4CORE_SHARED
        #ifdef C4CORE_EXPORTS
            #define C4CORE_EXPORT __declspec(dllexport)
        #else
            #define C4CORE_EXPORT __declspec(dllimport)
        #endif
    #else
        #define C4CORE_EXPORT
    #endif
#else
    #define C4CORE_EXPORT
#endif

#endif /* C4CORE_EXPORT_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/export.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/preprocessor.hpp
// https://github.com/biojppm/c4core/src/c4/preprocessor.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_PREPROCESSOR_HPP_
#define _C4_PREPROCESSOR_HPP_

/** @file preprocessor.hpp Contains basic macros and preprocessor utilities.
 * @ingroup basic_headers */

#ifdef __clang__
    /* NOTE: using , ## __VA_ARGS__ to deal with zero-args calls to
     * variadic macros is not portable, but works in clang, gcc, msvc, icc.
     * clang requires switching off compiler warnings for pedantic mode.
     * @see http://stackoverflow.com/questions/32047685/variadic-macro-without-arguments */
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments" // warning: token pasting of ',' and __VA_ARGS__ is a GNU extension
#elif defined(__GNUC__)
    /* GCC also issues a warning for zero-args calls to variadic macros.
     * This warning is switched on with -pedantic and apparently there is no
     * easy way to turn it off as with clang. But marking this as a system
     * header works.
     * @see https://gcc.gnu.org/onlinedocs/cpp/System-Headers.html
     * @see http://stackoverflow.com/questions/35587137/ */
#   pragma GCC system_header
#endif

#define C4_WIDEN(str) L"" str

#define C4_COUNTOF(arr) (sizeof(arr)/sizeof((arr)[0]))

#define C4_EXPAND(arg) arg

/** useful in some macro calls with template arguments */
#define C4_COMMA ,
/** useful in some macro calls with template arguments
 * @see C4_COMMA */
#define C4_COMMA_X C4_COMMA

/** expand and quote */
#define C4_XQUOTE(arg) _C4_XQUOTE(arg)
#define _C4_XQUOTE(arg) C4_QUOTE(arg)
#define C4_QUOTE(arg) #arg

/** expand and concatenate */
#define C4_XCAT(arg1, arg2) _C4_XCAT(arg1, arg2)
#define _C4_XCAT(arg1, arg2) C4_CAT(arg1, arg2)
#define C4_CAT(arg1, arg2) arg1##arg2

#define C4_VERSION_CAT(major, minor, patch) ((major)*10000 + (minor)*100 + (patch))

/** A preprocessor foreach. Spectacular trick taken from:
 * http://stackoverflow.com/a/1872506/5875572
 * The first argument is for a macro receiving a single argument,
 * which will be called with every subsequent argument. There is
 * currently a limit of 32 arguments, and at least 1 must be provided.
 *
Example:
@code{.cpp}
struct Example {
    int a;
    int b;
    int c;
};
// define a one-arg macro to be called
#define PRN_STRUCT_OFFSETS(field) PRN_STRUCT_OFFSETS_(Example, field)
#define PRN_STRUCT_OFFSETS_(structure, field) printf(C4_XQUOTE(structure) ":" C4_XQUOTE(field)" - offset=%zu\n", offsetof(structure, field));

// now call the macro for a, b and c
C4_FOR_EACH(PRN_STRUCT_OFFSETS, a, b, c);
@endcode */
#define C4_FOR_EACH(what, ...) C4_FOR_EACH_SEP(what, ;, __VA_ARGS__)

/** same as C4_FOR_EACH(), but use a custom separator between statements.
 * If a comma is needed as the separator, use the C4_COMMA macro.
 * @see C4_FOR_EACH
 * @see C4_COMMA
 */
#define C4_FOR_EACH_SEP(what, sep, ...) _C4_FOR_EACH_(_C4_FOR_EACH_NARG(__VA_ARGS__), what, sep, __VA_ARGS__)

/// @cond dev

#define _C4_FOR_EACH_01(what, sep, x) what(x) sep
#define _C4_FOR_EACH_02(what, sep, x, ...) what(x) sep _C4_FOR_EACH_01(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_03(what, sep, x, ...) what(x) sep _C4_FOR_EACH_02(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_04(what, sep, x, ...) what(x) sep _C4_FOR_EACH_03(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_05(what, sep, x, ...) what(x) sep _C4_FOR_EACH_04(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_06(what, sep, x, ...) what(x) sep _C4_FOR_EACH_05(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_07(what, sep, x, ...) what(x) sep _C4_FOR_EACH_06(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_08(what, sep, x, ...) what(x) sep _C4_FOR_EACH_07(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_09(what, sep, x, ...) what(x) sep _C4_FOR_EACH_08(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_10(what, sep, x, ...) what(x) sep _C4_FOR_EACH_09(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_11(what, sep, x, ...) what(x) sep _C4_FOR_EACH_10(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_12(what, sep, x, ...) what(x) sep _C4_FOR_EACH_11(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_13(what, sep, x, ...) what(x) sep _C4_FOR_EACH_12(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_14(what, sep, x, ...) what(x) sep _C4_FOR_EACH_13(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_15(what, sep, x, ...) what(x) sep _C4_FOR_EACH_14(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_16(what, sep, x, ...) what(x) sep _C4_FOR_EACH_15(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_17(what, sep, x, ...) what(x) sep _C4_FOR_EACH_16(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_18(what, sep, x, ...) what(x) sep _C4_FOR_EACH_17(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_19(what, sep, x, ...) what(x) sep _C4_FOR_EACH_18(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_20(what, sep, x, ...) what(x) sep _C4_FOR_EACH_19(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_21(what, sep, x, ...) what(x) sep _C4_FOR_EACH_20(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_22(what, sep, x, ...) what(x) sep _C4_FOR_EACH_21(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_23(what, sep, x, ...) what(x) sep _C4_FOR_EACH_22(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_24(what, sep, x, ...) what(x) sep _C4_FOR_EACH_23(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_25(what, sep, x, ...) what(x) sep _C4_FOR_EACH_24(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_26(what, sep, x, ...) what(x) sep _C4_FOR_EACH_25(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_27(what, sep, x, ...) what(x) sep _C4_FOR_EACH_26(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_28(what, sep, x, ...) what(x) sep _C4_FOR_EACH_27(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_29(what, sep, x, ...) what(x) sep _C4_FOR_EACH_28(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_30(what, sep, x, ...) what(x) sep _C4_FOR_EACH_29(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_31(what, sep, x, ...) what(x) sep _C4_FOR_EACH_30(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_32(what, sep, x, ...) what(x) sep _C4_FOR_EACH_31(what, sep, __VA_ARGS__)
#define _C4_FOR_EACH_NARG(...) _C4_FOR_EACH_NARG_(__VA_ARGS__, _C4_FOR_EACH_RSEQ_N())
#define _C4_FOR_EACH_NARG_(...) _C4_FOR_EACH_ARG_N(__VA_ARGS__)
#define _C4_FOR_EACH_ARG_N(_01, _02, _03, _04, _05, _06, _07, _08, _09, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, N, ...) N
#define _C4_FOR_EACH_RSEQ_N() 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 09, 08, 07, 06, 05, 04, 03, 02, 01
#define _C4_FOR_EACH_(N, what, sep, ...) C4_XCAT(_C4_FOR_EACH_, N)(what, sep, __VA_ARGS__)

/// @endcond

#ifdef __clang__
#   pragma clang diagnostic pop
#endif

#endif /* _C4_PREPROCESSOR_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/preprocessor.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/platform.hpp
// https://github.com/biojppm/c4core/src/c4/platform.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_PLATFORM_HPP_
#define _C4_PLATFORM_HPP_

/** @file platform.hpp Provides platform information macros
 * @ingroup basic_headers */

// see also https://sourceforge.net/p/predef/wiki/OperatingSystems/

#if defined(_WIN64)
#   define C4_WIN
#   define C4_WIN64
#elif defined(_WIN32)
#   define C4_WIN
#   define C4_WIN32
#elif defined(__ANDROID__)
#   define C4_ANDROID
#elif defined(__APPLE__)
#   include "TargetConditionals.h"
#   if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#       define C4_IOS
#   elif TARGET_OS_MAC || TARGET_OS_OSX
#       define C4_MACOS
#   else
#       error "Unknown Apple platform"
#   endif
#elif defined(__linux__) || defined(__linux)
#   define C4_UNIX
#   define C4_LINUX
#elif defined(__unix__) || defined(__unix)
#   define C4_UNIX
#elif defined(__arm__) || defined(__aarch64__)
#   define C4_ARM
#elif defined(__xtensa__) || defined(__XTENSA__)
#   define C4_XTENSA
#elif defined(SWIG)
#   define C4_SWIG
#else
#   error "unknown platform"
#endif

#if defined(__posix) || defined(C4_UNIX) || defined(C4_LINUX)
#   define C4_POSIX
#endif


#endif /* _C4_PLATFORM_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/platform.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/cpu.hpp
// https://github.com/biojppm/c4core/src/c4/cpu.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_CPU_HPP_
#define _C4_CPU_HPP_

/** @file cpu.hpp Provides processor information macros
 * @ingroup basic_headers */

// see also https://sourceforge.net/p/predef/wiki/Architectures/
// see also https://sourceforge.net/p/predef/wiki/Endianness/
// see also https://github.com/googlesamples/android-ndk/blob/android-mk/hello-jni/jni/hello-jni.c
// see http://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qprocessordetection.h

#ifdef __ORDER_LITTLE_ENDIAN__
#   define _C4EL __ORDER_LITTLE_ENDIAN__
#else
#   define _C4EL 1234
#endif

#ifdef __ORDER_BIG_ENDIAN__
#   define _C4EB __ORDER_BIG_ENDIAN__
#else
#   define _C4EB 4321
#endif

// mixed byte order (eg, PowerPC or ia64)
#define _C4EM 1111

#if defined(__x86_64) || defined(__x86_64__) || defined(__amd64) || defined(_M_X64)
#    define C4_CPU_X86_64
#    define C4_WORDSIZE 8
#    define C4_BYTE_ORDER _C4EL

#elif defined(__i386) || defined(__i386__) || defined(_M_IX86)
#    define C4_CPU_X86
#    define C4_WORDSIZE 4
#    define C4_BYTE_ORDER _C4EL

#elif defined(__arm__) || defined(_M_ARM) \
    || defined(__TARGET_ARCH_ARM) || defined(__aarch64__) || defined(_M_ARM64)
#   if defined(__aarch64__) || defined(_M_ARM64)
#       define C4_CPU_ARM64
#       define C4_CPU_ARMV8
#       define C4_WORDSIZE 8
#   else
#       define C4_CPU_ARM
#       define C4_WORDSIZE 4
#       if defined(__ARM_ARCH_8__) || defined(__ARM_ARCH_8A__)  \
        || (defined(__ARCH_ARM) && __ARCH_ARM >= 8) \
        || (defined(__TARGET_ARCH_ARM) && __TARGET_ARCH_ARM >= 8)
#           define C4_CPU_ARMV8
#       elif defined(__ARM_ARCH_7__) || defined(_ARM_ARCH_7)    \
        || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) \
        || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__) \
        || defined(__ARM_ARCH_7EM__) \
        || (defined(__TARGET_ARCH_ARM) && __TARGET_ARCH_ARM >= 7) \
        || (defined(_M_ARM) && _M_ARM >= 7)
#           define C4_CPU_ARMV7
#       elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) \
        || defined(__ARM_ARCH_6T2__) || defined(__ARM_ARCH_6Z__) \
        || defined(__ARM_ARCH_6K__)  || defined(__ARM_ARCH_6ZK__) \
        || defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_6KZ__) \
        || (defined(__TARGET_ARCH_ARM) && __TARGET_ARCH_ARM >= 6)
#           define C4_CPU_ARMV6
#       elif defined(__ARM_ARCH_5TEJ__) \
        || defined(__ARM_ARCH_5TE__) \
        || (defined(__TARGET_ARCH_ARM) && __TARGET_ARCH_ARM >= 5)
#           define C4_CPU_ARMV5
#       elif defined(__ARM_ARCH_4T__) \
        || (defined(__TARGET_ARCH_ARM) && __TARGET_ARCH_ARM >= 4)
#           define C4_CPU_ARMV4
#       else
#           error "unknown CPU architecture: ARM"
#       endif
#   endif
#   if defined(__ARMEL__) || defined(__LITTLE_ENDIAN__) || defined(__AARCH64EL__) \
       || (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)) \
       || defined(_MSC_VER) // winarm64 does not provide any of the above macros,
                            // but advises little-endianess:
                            // https://docs.microsoft.com/en-us/cpp/build/overview-of-arm-abi-conventions?view=msvc-170
                            // So if it is visual studio compiling, we'll assume little endian.
#       define C4_BYTE_ORDER _C4EL
#   elif defined(__ARMEB__) || defined(__BIG_ENDIAN__) || defined(__AARCH64EB__) \
       || (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__))
#       define C4_BYTE_ORDER _C4EB
#   elif defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_PDP_ENDIAN__)
#       define C4_BYTE_ORDER _C4EM
#   else
#       error "unknown endianness"
#   endif

#elif defined(__ia64) || defined(__ia64__) || defined(_M_IA64)
#   define C4_CPU_IA64
#   define C4_WORDSIZE 8
#   define C4_BYTE_ORDER _C4EM
   // itanium is bi-endian - check byte order below

#elif defined(__ppc__) || defined(__ppc) || defined(__powerpc__)       \
    || defined(_ARCH_COM) || defined(_ARCH_PWR) || defined(_ARCH_PPC)  \
    || defined(_M_MPPC) || defined(_M_PPC)
#   if defined(__ppc64__) || defined(__powerpc64__) || defined(__64BIT__)
#       define C4_CPU_PPC64
#       define C4_WORDSIZE 8
#   else
#       define C4_CPU_PPC
#       define C4_WORDSIZE 4
#   endif
#   define C4_BYTE_ORDER _C4EM
   // ppc is bi-endian - check byte order below

#elif defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH_)
#   define C4_CPU_S390_X
#   define C4_WORDSIZE 8
#   define C4_BYTE_ORDER _C4EB

#elif defined(__xtensa__) || defined(__XTENSA__)
#   define C4_CPU_XTENSA
#   define C4_WORDSIZE 4
// not sure about this...
#   if defined(__XTENSA_EL__) || defined(__xtensa_el__)
#       define C4_BYTE_ORDER _C4EL
#   else
#       define C4_BYTE_ORDER _C4EB
#   endif

#elif defined(__riscv)
#   if __riscv_xlen == 64
#       define C4_CPU_RISCV64
#       define C4_WORDSIZE 8
#   else
#       define C4_CPU_RISCV32
#       define C4_WORDSIZE 4
#   endif
#   define C4_BYTE_ORDER _C4EL

#elif defined(__EMSCRIPTEN__)
#   define C4_BYTE_ORDER _C4EL
#   define C4_WORDSIZE 4

#elif defined(__loongarch__)
#   if defined(__loongarch64)
#       define C4_CPU_LOONGARCH64
#       define C4_WORDSIZE 8
#   else
#       define C4_CPU_LOONGARCH
#       define C4_WORDSIZE 4
#   endif
#   define C4_BYTE_ORDER _C4EL

#elif defined(SWIG)
#   error "please define CPU architecture macros when compiling with swig"

#else
#   error "unknown CPU architecture"
#endif

#define C4_LITTLE_ENDIAN (C4_BYTE_ORDER == _C4EL)
#define C4_BIG_ENDIAN (C4_BYTE_ORDER == _C4EB)
#define C4_MIXED_ENDIAN (C4_BYTE_ORDER == _C4EM)

#endif /* _C4_CPU_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/cpu.hpp)

// (amalgamate) these includes are needed to work around
// conditional includes in the gcc4.8 shim
#include <cstdint>
#include <type_traits>
#include <cstring>




//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/gcc-4.8.hpp
// https://github.com/biojppm/c4core/src/c4/gcc-4.8.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_GCC_4_8_HPP_
#define _C4_GCC_4_8_HPP_

#if __GNUC__ == 4 && __GNUC_MINOR__ >= 8
/* STL polyfills for old GNU compilers */

_Pragma("GCC diagnostic ignored \"-Wshadow\"")
_Pragma("GCC diagnostic ignored \"-Wmissing-field-initializers\"")

#if __cplusplus
//included above:
//#include <cstdint>
//included above:
//#include <type_traits>

namespace std {

template<typename _Tp>
struct is_trivially_copyable : public integral_constant<bool,
    is_destructible<_Tp>::value && __has_trivial_destructor(_Tp) &&
    (__has_trivial_constructor(_Tp) || __has_trivial_copy(_Tp) || __has_trivial_assign(_Tp))>
{ };

template<typename _Tp>
using is_trivially_copy_constructible = has_trivial_copy_constructor<_Tp>;

template<typename _Tp>
using is_trivially_default_constructible = has_trivial_default_constructor<_Tp>;

template<typename _Tp>
using is_trivially_copy_assignable = has_trivial_copy_assign<_Tp>;

/* not supported */
template<typename _Tp>
struct is_trivially_move_constructible : false_type
{ };

/* not supported */
template<typename _Tp>
struct is_trivially_move_assignable : false_type
{ };

inline void *align(size_t __align, size_t __size, void*& __ptr, size_t& __space) noexcept
{
    if (__space < __size)
        return nullptr;
    const auto __intptr = reinterpret_cast<uintptr_t>(__ptr);
    const auto __aligned = (__intptr - 1u + __align) & -__align;
    const auto __diff = __aligned - __intptr;
    if (__diff > (__space - __size))
        return nullptr;
    else
    {
        __space -= __diff;
        return __ptr = reinterpret_cast<void*>(__aligned);
    }
}

#if __GNUC__ == 4 && __GNUC_MINOR__ == 8
typedef long double max_align_t ;
#endif

}
#else // __cplusplus

//included above:
//#include <string.h>
// see https://sourceware.org/bugzilla/show_bug.cgi?id=25399 (ubuntu gcc-4.8)
#define memset(s, c, count) __builtin_memset(s, c, count)

#endif // __cplusplus

#endif // __GNUC__ == 4 && __GNUC_MINOR__ >= 8

#endif // _C4_GCC_4_8_HPP_


// (end https://github.com/biojppm/c4core/src/c4/gcc-4.8.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/compiler.hpp
// https://github.com/biojppm/c4core/src/c4/compiler.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_COMPILER_HPP_
#define _C4_COMPILER_HPP_

/** @file compiler.hpp Provides compiler information macros
 * @ingroup basic_headers */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/platform.hpp
//#include "c4/platform.hpp"
#if !defined(C4_PLATFORM_HPP_) && !defined(_C4_PLATFORM_HPP_)
#error "amalgamate: file c4/platform.hpp must have been included at this point"
#endif /* C4_PLATFORM_HPP_ */


// Compilers:
//      C4_MSVC
//             Visual Studio 2022: MSVC++ 17, 1930
//             Visual Studio 2019: MSVC++ 16, 1920
//             Visual Studio 2017: MSVC++ 15
//             Visual Studio 2015: MSVC++ 14
//             Visual Studio 2013: MSVC++ 13
//             Visual Studio 2013: MSVC++ 12
//             Visual Studio 2012: MSVC++ 11
//             Visual Studio 2010: MSVC++ 10
//             Visual Studio 2008: MSVC++ 09
//             Visual Studio 2005: MSVC++ 08
//      C4_CLANG
//      C4_GCC
//      C4_ICC (intel compiler)
/** @see http://sourceforge.net/p/predef/wiki/Compilers/ for a list of compiler identifier macros */
/** @see https://msdn.microsoft.com/en-us/library/b0084kay.aspx for VS2013 predefined macros */

#if defined(_MSC_VER) && !defined(__clang__)
#   define C4_MSVC
#   define C4_MSVC_VERSION_2022 17
#   define C4_MSVC_VERSION_2019 16
#   define C4_MSVC_VERSION_2017 15
#   define C4_MSVC_VERSION_2015 14
#   define C4_MSVC_VERSION_2013 12
#   define C4_MSVC_VERSION_2012 11
#   if _MSC_VER >= 1930
#       define C4_MSVC_VERSION C4_MSVC_VERSION_2022  // visual studio 2022
#       define C4_MSVC_2022
#   elif _MSC_VER >= 1920
#       define C4_MSVC_VERSION C4_MSVC_VERSION_2019  // visual studio 2019
#       define C4_MSVC_2019
#   elif _MSC_VER >= 1910
#       define C4_MSVC_VERSION C4_MSVC_VERSION_2017  // visual studio 2017
#       define C4_MSVC_2017
#   elif _MSC_VER == 1900
#       define C4_MSVC_VERSION C4_MSVC_VERSION_2015  // visual studio 2015
#       define C4_MSVC_2015
#   elif _MSC_VER == 1800
#       error "MSVC version not supported"
#       define C4_MSVC_VERSION C4_MSVC_VERSION_2013  // visual studio 2013
#       define C4_MSVC_2013
#   elif _MSC_VER == 1700
#       error "MSVC version not supported"
#       define C4_MSVC_VERSION C4_MSVC_VERSION_2012  // visual studio 2012
#       define C4_MSVC_2012
#   elif _MSC_VER == 1600
#       error "MSVC version not supported"
#       define C4_MSVC_VERSION 10  // visual studio 2010
#       define C4_MSVC_2010
#   elif _MSC_VER == 1500
#       error "MSVC version not supported"
#       define C4_MSVC_VERSION 09  // visual studio 2008
#       define C4_MSVC_2008
#   elif _MSC_VER == 1400
#       error "MSVC version not supported"
#       define C4_MSVC_VERSION 08  // visual studio 2005
#       define C4_MSVC_2005
#   else
#       error "MSVC version not supported"
#   endif // _MSC_VER
#else
#   define C4_MSVC_VERSION 0   // visual studio not present
#   define C4_GCC_LIKE
#   ifdef __INTEL_COMPILER // check ICC before checking GCC, as ICC defines __GNUC__ too
#       define C4_ICC
#       define C4_ICC_VERSION __INTEL_COMPILER
#   elif defined(__APPLE_CC__)
#       define C4_XCODE
#       if defined(__clang__)
#           define C4_CLANG
#           ifndef __apple_build_version__
#               define C4_CLANG_VERSION C4_VERSION_ENCODED(__clang_major__, __clang_minor__, __clang_patchlevel__)
#           else
#               define C4_CLANG_VERSION __apple_build_version__
#           endif
#       else
#           define C4_XCODE_VERSION __APPLE_CC__
#       endif
#   elif defined(__clang__)
#       define C4_CLANG
#       ifndef __apple_build_version__
#           define C4_CLANG_VERSION C4_VERSION_ENCODED(__clang_major__, __clang_minor__, __clang_patchlevel__)
#       else
#           define C4_CLANG_VERSION __apple_build_version__
#       endif
#   elif defined(__GNUC__)
#       ifdef __MINGW32__
#           define C4_MINGW
#       endif
#       define C4_GCC
#       if defined(__GNUC_PATCHLEVEL__)
#           define C4_GCC_VERSION C4_VERSION_ENCODED(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#       else
#           define C4_GCC_VERSION C4_VERSION_ENCODED(__GNUC__, __GNUC_MINOR__, 0)
#       endif
#       if __GNUC__ < 5
#           if __GNUC__ == 4 && __GNUC_MINOR__ >= 8
// provided by cmake sub-project
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/gcc-4.8.hpp
//#               include "c4/gcc-4.8.hpp"
#if !defined(C4_GCC_4_8_HPP_) && !defined(_C4_GCC_4_8_HPP_)
#error "amalgamate: file c4/gcc-4.8.hpp must have been included at this point"
#endif /* C4_GCC_4_8_HPP_ */

#           else
// we do not support GCC < 4.8:
//  * misses std::is_trivially_copyable
//  * misses std::align
//  * -Wshadow has false positives when a local function parameter has the same name as a method
#               error "GCC < 4.8 is not supported"
#           endif
#       endif
#   endif
#endif // defined(C4_WIN) && defined(_MSC_VER)

#endif /* _C4_COMPILER_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/compiler.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/language.hpp
// https://github.com/biojppm/c4core/src/c4/language.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_LANGUAGE_HPP_
#define _C4_LANGUAGE_HPP_

/** @file language.hpp Provides language standard information macros and
 * compiler agnostic utility macros: namespace facilities, function attributes,
 * variable attributes, etc.
 * @ingroup basic_headers */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/preprocessor.hpp
//#include "c4/preprocessor.hpp"
#if !defined(C4_PREPROCESSOR_HPP_) && !defined(_C4_PREPROCESSOR_HPP_)
#error "amalgamate: file c4/preprocessor.hpp must have been included at this point"
#endif /* C4_PREPROCESSOR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/compiler.hpp
//#include "c4/compiler.hpp"
#if !defined(C4_COMPILER_HPP_) && !defined(_C4_COMPILER_HPP_)
#error "amalgamate: file c4/compiler.hpp must have been included at this point"
#endif /* C4_COMPILER_HPP_ */


/* Detect C++ standard.
 * @see http://stackoverflow.com/a/7132549/5875572 */
#ifndef C4_CPP
#   if defined(_MSC_VER) && !defined(__clang__)
#       if _MSC_VER >= 1910  // >VS2015: VS2017, VS2019, VS2022
#           if (!defined(_MSVC_LANG))
#               error _MSVC not defined
#           endif
#           if _MSVC_LANG >= 201705L
#               define C4_CPP 20
#               define C4_CPP20
#           elif _MSVC_LANG == 201703L
#               define C4_CPP 17
#               define C4_CPP17
#           elif _MSVC_LANG >= 201402L
#               define C4_CPP 14
#               define C4_CPP14
#           elif _MSVC_LANG >= 201103L
#               define C4_CPP 11
#               define C4_CPP11
#           else
#               error C++ lesser than C++11 not supported
#           endif
#       else
#           if _MSC_VER == 1900
#               define C4_CPP 14  // VS2015 is c++14 https://devblogs.microsoft.com/cppblog/c111417-features-in-vs-2015-rtm/
#               define C4_CPP14
#           elif _MSC_VER == 1800 // VS2013
#               define C4_CPP 11
#               define C4_CPP11
#           else
#               error C++ lesser than C++11 not supported
#           endif
#       endif
#   elif defined(__INTEL_COMPILER) // https://software.intel.com/en-us/node/524490
#       ifdef __INTEL_CXX20_MODE__ // not sure about this
#           define C4_CPP 20
#           define C4_CPP20
#       elif defined __INTEL_CXX17_MODE__ // not sure about this
#           define C4_CPP 17
#           define C4_CPP17
#       elif defined __INTEL_CXX14_MODE__ // not sure about this
#           define C4_CPP 14
#           define C4_CPP14
#       elif defined __INTEL_CXX11_MODE__
#           define C4_CPP 11
#           define C4_CPP11
#       else
#           error C++ lesser than C++11 not supported
#       endif
#   else
#       ifndef __cplusplus
#           error __cplusplus is not defined?
#       endif
#       if __cplusplus == 1
#           error cannot handle __cplusplus==1
#       elif __cplusplus >= 201709L
#           define C4_CPP 20
#           define C4_CPP20
#       elif __cplusplus >= 201703L
#           define C4_CPP 17
#           define C4_CPP17
#       elif __cplusplus >= 201402L
#           define C4_CPP 14
#           define C4_CPP14
#       elif __cplusplus >= 201103L
#           define C4_CPP 11
#           define C4_CPP11
#       elif __cplusplus >= 199711L
#           error C++ lesser than C++11 not supported
#       endif
#   endif
#else
#   ifdef C4_CPP == 20
#       define C4_CPP20
#   elif C4_CPP == 17
#       define C4_CPP17
#   elif C4_CPP == 14
#       define C4_CPP14
#   elif C4_CPP == 11
#       define C4_CPP11
#   elif C4_CPP == 98
#       define C4_CPP98
#       error C++ lesser than C++11 not supported
#   else
#       error C4_CPP must be one of 20, 17, 14, 11, 98
#   endif
#endif

#ifdef C4_CPP20
#   define C4_CPP17
#   define C4_CPP14
#   define C4_CPP11
#elif defined(C4_CPP17)
#   define C4_CPP14
#   define C4_CPP11
#elif defined(C4_CPP14)
#   define C4_CPP11
#endif

/** lifted from this answer: http://stackoverflow.com/a/20170989/5875572 */
#if defined(_MSC_VER) && !defined(__clang__)
#  if _MSC_VER < 1900
#    define C4_CONSTEXPR11
#    define C4_CONSTEXPR14
#  elif _MSC_VER < 2000
#    define C4_CONSTEXPR11 constexpr
#    define C4_CONSTEXPR14
#  else
#    define C4_CONSTEXPR11 constexpr
#    define C4_CONSTEXPR14 constexpr
#  endif
#else
#  if __cplusplus < 201103
#    define C4_CONSTEXPR11
#    define C4_CONSTEXPR14
#  elif __cplusplus == 201103
#    define C4_CONSTEXPR11 constexpr
#    define C4_CONSTEXPR14
#  else
#    define C4_CONSTEXPR11 constexpr
#    define C4_CONSTEXPR14 constexpr
#  endif
#endif  // _MSC_VER


#if C4_CPP < 17
#define C4_IF_CONSTEXPR
#define C4_INLINE_CONSTEXPR constexpr
#else
#define C4_IF_CONSTEXPR constexpr
#define C4_INLINE_CONSTEXPR inline constexpr
#endif

#if defined(_MSC_VER) && !defined(__clang__)
#  if (defined(_CPPUNWIND) && (_CPPUNWIND == 1))
#    define C4_EXCEPTIONS
#  endif
#else
#  if defined(__EXCEPTIONS) || defined(__cpp_exceptions)
#    define C4_EXCEPTIONS
#  endif
#endif

#ifdef C4_EXCEPTIONS
#  define C4_IF_EXCEPTIONS_(exc_code, setjmp_code) exc_code
#  define C4_IF_EXCEPTIONS(exc_code, setjmp_code) do { exc_code } while(0)
#else
#  define C4_IF_EXCEPTIONS_(exc_code, setjmp_code) setjmp_code
#  define C4_IF_EXCEPTIONS(exc_code, setjmp_code) do { setjmp_code } while(0)
#endif

#if defined(_MSC_VER) && !defined(__clang__)
#  if defined(_CPPRTTI)
#    define C4_RTTI
#  endif
#else
#  if defined(__GXX_RTTI)
#    define C4_RTTI
#  endif
#endif

#ifdef C4_RTTI
#  define C4_IF_RTTI_(code_rtti, code_no_rtti) code_rtti
#  define C4_IF_RTTI(code_rtti, code_no_rtti) do { code_rtti } while(0)
#else
#  define C4_IF_RTTI_(code_rtti, code_no_rtti) code_no_rtti
#  define C4_IF_RTTI(code_rtti, code_no_rtti) do { code_no_rtti } while(0)
#endif


//------------------------------------------------------------

#define _C4_BEGIN_NAMESPACE(ns) namespace ns {
#define _C4_END_NAMESPACE(ns)   }

// MSVC cant handle the C4_FOR_EACH macro... need to fix this
//#define C4_BEGIN_NAMESPACE(...) C4_FOR_EACH_SEP(_C4_BEGIN_NAMESPACE, , __VA_ARGS__)
//#define C4_END_NAMESPACE(...) C4_FOR_EACH_SEP(_C4_END_NAMESPACE, , __VA_ARGS__)
#define C4_BEGIN_NAMESPACE(ns) namespace ns {
#define C4_END_NAMESPACE(ns) }

#define C4_BEGIN_HIDDEN_NAMESPACE namespace /*hidden*/ {
#define C4_END_HIDDEN_NAMESPACE } /* namespace hidden */

//------------------------------------------------------------

#ifndef C4_API
#   if defined(_MSC_VER) && !defined(__clang__)
#       if defined(C4_EXPORT)
#           define C4_API __declspec(dllexport)
#       elif defined(C4_IMPORT)
#           define C4_API __declspec(dllimport)
#       else
#           define C4_API
#       endif
#   else
#       define C4_API
#   endif
#endif

#if defined(_MSC_VER) && !defined(__clang__)
#   define C4_RESTRICT __restrict
#   define C4_RESTRICT_FN __declspec(restrict)
#   define C4_NO_INLINE __declspec(noinline)
#   define C4_ALWAYS_INLINE inline __forceinline
/** these are not available in VS AFAIK */
#   define C4_CONST
#   define C4_PURE
#   define C4_FLATTEN
#   define C4_HOT         /** @todo */
#   define C4_COLD        /** @todo */
#   define C4_ASSUME(...) __assume(__VA_ARGS__)
#   define C4_EXPECT(x, y) x /** @todo */
#   define C4_LIKELY(x)   x
#   define C4_UNLIKELY(x) x
#   define C4_UNREACHABLE() _c4_msvc_unreachable()
#   define C4_ATTR_FORMAT(...) /** */
#   define C4_NORETURN [[noreturn]]
#   if _MSC_VER >= 1700 // VS2012
#       define C4_NODISCARD _Check_return_
#   else
#       define C4_NODISCARD
#   endif
[[noreturn]] __forceinline void _c4_msvc_unreachable() { __assume(false); } ///< https://stackoverflow.com/questions/60802864/emulating-gccs-builtin-unreachable-in-visual-studio
#   define C4_UNREACHABLE_AFTER_ERR() /* */
#else
    ///< @todo assuming gcc-like compiler. check it is actually so.
/** for function attributes in GCC,
 * @see https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html#Common-Function-Attributes */
/** for __builtin functions in GCC,
 * @see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html */
#   define C4_RESTRICT __restrict__
#   define C4_RESTRICT_FN __attribute__((restrict))
#   define C4_NO_INLINE __attribute__((noinline))
#   define C4_ALWAYS_INLINE inline __attribute__((always_inline))
#   define C4_CONST __attribute__((const))
#   define C4_PURE __attribute__((pure))
/** force inlining of every callee function */
#   define C4_FLATTEN __atribute__((flatten))
/** mark a function as hot, ie as having a visible impact in CPU time
 * thus making it more likely to inline, etc
 * @see http://stackoverflow.com/questions/15028990/semantics-of-gcc-hot-attribute */
#   define C4_HOT __attribute__((hot))
/** mark a function as cold, ie as NOT having a visible impact in CPU time
 * @see http://stackoverflow.com/questions/15028990/semantics-of-gcc-hot-attribute */
#   define C4_COLD __attribute__((cold))
#   define C4_EXPECT(x, y) __builtin_expect(x, y) ///< @see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
#   define C4_LIKELY(x)   __builtin_expect(x, 1)
#   define C4_UNLIKELY(x) __builtin_expect(x, 0)
#   define C4_UNREACHABLE() __builtin_unreachable()
#   define C4_ATTR_FORMAT(...) //__attribute__((format (__VA_ARGS__))) ///< @see https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html#Common-Function-Attributes
#   define C4_NORETURN __attribute__((noreturn))
#   define C4_NODISCARD __attribute__((warn_unused_result))
#   define C4_UNREACHABLE_AFTER_ERR() C4_UNREACHABLE()
// C4_ASSUME
// see https://stackoverflow.com/questions/63493968/reproducing-clangs-builtin-assume-for-gcc
// preferred option: C++ standard attribute
#   ifdef __has_cpp_attribute
#       if __has_cpp_attribute(assume) >= 202207L
#           define C4_ASSUME(...) [[assume(__VA_ARGS__)]]
#       endif
#   endif
// first fallback: compiler intrinsics/attributes for assumptions
#   ifndef C4_ASSUME
#       if defined(__clang__)
#           define C4_ASSUME(...) __builtin_assume(__VA_ARGS__)
#       elif defined(__GNUC__)
#       if __GNUC__ >= 13
#           define C4_ASSUME(...) __attribute__((__assume__(__VA_ARGS__)))
#       endif
#       endif
#   endif
// second fallback: possibly evaluating uses of unreachable()
// Set this to 1 if you want to allow assumptions to possibly evaluate.
#   ifndef C4_ASSUME_ALLOW_EVAL
#       define C4_ASSUME_ALLOW_EVAL 0
#   endif
#   if !defined(C4_ASSUME) && (C4_ASSUME_ALLOW_EVAL)
#       define C4_ASSUME(...) do { if (!bool(__VA_ARGS__)) C4_UNREACHABLE(); ) while(0)
#   endif
// last fallback: define macro as doing nothing
#   ifndef C4_ASSUME
#       define C4_ASSUME(...)
#   endif
#endif


#if C4_CPP >= 14
#   define C4_DEPRECATED(msg) [[deprecated(msg)]]
#else
#   if defined(_MSC_VER)
#       define C4_DEPRECATED(msg) __declspec(deprecated(msg))
#   else // defined(__GNUC__) || defined(__clang__)
#       define C4_DEPRECATED(msg) __attribute__((deprecated(msg)))
#   endif
#endif


#ifdef _MSC_VER
#   define C4_FUNC __FUNCTION__
#   define C4_PRETTY_FUNC __FUNCSIG__
#else /// @todo assuming gcc-like compiler. check it is actually so.
#   define C4_FUNC __FUNCTION__
#   define C4_PRETTY_FUNC __PRETTY_FUNCTION__
#endif

/** prevent compiler warnings about a specific var being unused */
#define C4_UNUSED(var) (void)var

#if C4_CPP >= 17
#define C4_STATIC_ASSERT(cond) static_assert(cond)
#else
#define C4_STATIC_ASSERT(cond) static_assert((cond), #cond)
#endif
#define C4_STATIC_ASSERT_MSG(cond, msg) static_assert((cond), #cond ": " msg)

/** @def C4_DONT_OPTIMIZE idea lifted from GoogleBenchmark.
 * @see https://github.com/google/benchmark/blob/master/include/benchmark/benchmark_api.h */
namespace c4 {
namespace detail {
#ifdef __GNUC__
#   define C4_DONT_OPTIMIZE(var) c4::detail::dont_optimize(var)
template< class T >
C4_ALWAYS_INLINE void dont_optimize(T const& value) { asm volatile("" : : "g"(value) : "memory"); }
#else
#   define C4_DONT_OPTIMIZE(var) c4::detail::use_char_pointer(reinterpret_cast< const char* >(&var))
void use_char_pointer(char const volatile*);
#endif
} // namespace detail
} // namespace c4

/** @def C4_KEEP_EMPTY_LOOP prevent an empty loop from being optimized out.
 * @see http://stackoverflow.com/a/7084193/5875572 */
#if defined(_MSC_VER) && !defined(__clang__)
#   define C4_KEEP_EMPTY_LOOP { char c; C4_DONT_OPTIMIZE(c); }
#else
#   define C4_KEEP_EMPTY_LOOP { asm(""); }
#endif

/** @def C4_VA_LIST_REUSE_MUST_COPY
 * @todo <jpmag> I strongly suspect that this is actually only in UNIX platforms. revisit this. */
#ifdef __GNUC__
#   define C4_VA_LIST_REUSE_MUST_COPY
#endif

#endif /* _C4_LANGUAGE_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/language.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/types.hpp
// https://github.com/biojppm/c4core/src/c4/types.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_TYPES_HPP_
#define _C4_TYPES_HPP_

//included above:
//#include <stdint.h>
#include <stddef.h>
//included above:
//#include <type_traits>

#if __cplusplus >= 201103L
#include <utility>  // for integer_sequence and friends
#endif

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/preprocessor.hpp
//#include "c4/preprocessor.hpp"
#if !defined(C4_PREPROCESSOR_HPP_) && !defined(_C4_PREPROCESSOR_HPP_)
#error "amalgamate: file c4/preprocessor.hpp must have been included at this point"
#endif /* C4_PREPROCESSOR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/language.hpp
//#include "c4/language.hpp"
#if !defined(C4_LANGUAGE_HPP_) && !defined(_C4_LANGUAGE_HPP_)
#error "amalgamate: file c4/language.hpp must have been included at this point"
#endif /* C4_LANGUAGE_HPP_ */


/** @file types.hpp basic types, and utility macros and traits for types.
 * @ingroup basic_headers */

/** @defgroup types Type utilities */

namespace c4 {

/** @defgroup intrinsic_types Intrinsic types
 * @ingroup types
 * @{ */

using cbyte = const char; /**< a constant byte */
using  byte =       char; /**< a mutable byte */

using  i8 =   int8_t;
using i16 =  int16_t;
using i32 =  int32_t;
using i64 =  int64_t;
using  u8 =  uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

using f32 =  float;
using f64 = double;

using ssize_t = typename std::make_signed<size_t>::type;

/** @} */

//--------------------------------------------------

/** @defgroup utility_types Utility types
 * @ingroup types
 * @{ */

// some tag types

#if !defined(__clang__) && defined(__GNUC__)
#pragma GCC diagnostic push
#if __GNUC__ >= 6
#pragma GCC diagnostic ignored "-Wunused-const-variable"
#endif
#endif

/** a tag type for initializing the containers with variadic arguments a la
 * initializer_list, minus the initializer_list overload problems.
 */
struct aggregate_t {};
/** @see aggregate_t */
constexpr const aggregate_t aggregate{};

/** a tag type for specifying the initial capacity of allocatable contiguous storage */
struct with_capacity_t {};
/** @see with_capacity_t */
constexpr const with_capacity_t with_capacity{};

/** a tag type for disambiguating template parameter packs in variadic template overloads */
struct varargs_t {};
/** @see with_capacity_t */
constexpr const varargs_t varargs{};

#if !defined(__clang__) && defined(__GNUC__)
#pragma GCC diagnostic pop
#endif


//--------------------------------------------------

/** whether a value should be used in place of a const-reference in argument passing. */
template<class T>
struct cref_uses_val
{
    enum { value = (
    std::is_scalar<T>::value
    ||
    (
#if C4_CPP >= 20
        (std::is_trivially_copyable<T>::value && std::is_standard_layout<T>::value)
#else
        std::is_pod<T>::value
#endif
        &&
        sizeof(T) <= sizeof(size_t))) };
};
/** utility macro to override the default behaviour for c4::fastcref<T>
 @see fastcref */
#define C4_CREF_USES_VAL(T) \
template<>                  \
struct cref_uses_val<T>     \
{                           \
    enum { value = true };  \
};

/** Whether to use pass-by-value or pass-by-const-reference in a function argument
 * or return type. */
template<class T>
using fastcref = typename std::conditional<c4::cref_uses_val<T>::value, T, T const&>::type;

//--------------------------------------------------

/** Just what its name says. Useful sometimes as a default empty policy class. */
struct EmptyStruct
{
    template<class... T> EmptyStruct(T && ...){}
};

/** Just what its name says. Useful sometimes as a default policy class to
 * be inherited from. */
struct EmptyStructVirtual
{
    virtual ~EmptyStructVirtual() = default;
    template<class... T> EmptyStructVirtual(T && ...){}
};


/** */
template<class T>
struct inheritfrom : public T {};

//--------------------------------------------------
// Utilities to make a class obey size restrictions (eg, min size or size multiple of).
// DirectX usually makes this restriction with uniform buffers.
// This is also useful for padding to prevent false-sharing.

/** how many bytes must be added to size such that the result is at least minsize? */
C4_ALWAYS_INLINE constexpr size_t min_remainder(size_t size, size_t minsize) noexcept
{
    return size < minsize ? minsize-size : 0;
}

/** how many bytes must be added to size such that the result is a multiple of multipleof?  */
C4_ALWAYS_INLINE constexpr size_t mult_remainder(size_t size, size_t multipleof) noexcept
{
    return (((size % multipleof) != 0) ? (multipleof-(size % multipleof)) : 0);
}

/* force the following class to be tightly packed. */
#pragma pack(push, 1)
/** pad a class with more bytes at the end.
 * @see http://stackoverflow.com/questions/21092415/force-c-structure-to-pack-tightly */
template<class T, size_t BytesToPadAtEnd>
struct Padded : public T
{
    using T::T;
    using T::operator=;
    Padded(T const& val) : T(val) {}
    Padded(T && val) : T(val) {}
    char ___c4padspace___[BytesToPadAtEnd];
};
#pragma pack(pop)
/** When the padding argument is 0, we cannot declare the char[] array. */
template<class T>
struct Padded<T, 0> : public T
{
    using T::T;
    using T::operator=;
    Padded(T const& val) : T(val) {}
    Padded(T && val) : T(val) {}
};

/** make T have a size which is at least Min bytes */
template<class T, size_t Min>
using MinSized = Padded<T, min_remainder(sizeof(T), Min)>;

/** make T have a size which is a multiple of Mult bytes */
template<class T, size_t Mult>
using MultSized = Padded<T, mult_remainder(sizeof(T), Mult)>;

/** make T have a size which is simultaneously:
 *  -bigger or equal than Min
 *  -a multiple of Mult */
template<class T, size_t Min, size_t Mult>
using MinMultSized = MultSized<MinSized<T, Min>, Mult>;

/** make T be suitable for use as a uniform buffer. (at least with DirectX). */
template<class T>
using UbufSized = MinMultSized<T, 64, 16>;


//-----------------------------------------------------------------------------

#define C4_NO_COPY_CTOR(ty) ty(ty const&) = delete
#define C4_NO_MOVE_CTOR(ty) ty(ty     &&) = delete
#define C4_NO_COPY_ASSIGN(ty) ty& operator=(ty const&) = delete
#define C4_NO_MOVE_ASSIGN(ty) ty& operator=(ty     &&) = delete
#define C4_DEFAULT_COPY_CTOR(ty) ty(ty const&) noexcept = default
#define C4_DEFAULT_MOVE_CTOR(ty) ty(ty     &&) noexcept = default
#define C4_DEFAULT_COPY_ASSIGN(ty) ty& operator=(ty const&) noexcept = default
#define C4_DEFAULT_MOVE_ASSIGN(ty) ty& operator=(ty     &&) noexcept = default

#define C4_NO_COPY_OR_MOVE_CTOR(ty) \
    C4_NO_COPY_CTOR(ty); \
    C4_NO_MOVE_CTOR(ty)

#define C4_NO_COPY_OR_MOVE_ASSIGN(ty) \
    C4_NO_COPY_ASSIGN(ty); \
    C4_NO_MOVE_ASSIGN(ty)

#define C4_NO_COPY_OR_MOVE(ty) \
    C4_NO_COPY_OR_MOVE_CTOR(ty); \
    C4_NO_COPY_OR_MOVE_ASSIGN(ty)

#define C4_DEFAULT_COPY_AND_MOVE_CTOR(ty) \
    C4_DEFAULT_COPY_CTOR(ty); \
    C4_DEFAULT_MOVE_CTOR(ty)

#define C4_DEFAULT_COPY_AND_MOVE_ASSIGN(ty) \
    C4_DEFAULT_COPY_ASSIGN(ty); \
    C4_DEFAULT_MOVE_ASSIGN(ty)

#define C4_DEFAULT_COPY_AND_MOVE(ty) \
    C4_DEFAULT_COPY_AND_MOVE_CTOR(ty); \
    C4_DEFAULT_COPY_AND_MOVE_ASSIGN(ty)

/** @see https://en.cppreference.com/w/cpp/named_req/TriviallyCopyable */
#define C4_MUST_BE_TRIVIAL_COPY(ty) \
    static_assert(std::is_trivially_copyable<ty>::value, #ty " must be trivially copyable")

/** @} */


//-----------------------------------------------------------------------------

/** @defgroup traits_types Type traits utilities
 * @ingroup types
 * @{ */

// http://stackoverflow.com/questions/10821380/is-t-an-instance-of-a-template-in-c
template<template<typename...> class X, typename    T> struct is_instance_of_tpl             : std::false_type {};
template<template<typename...> class X, typename... Y> struct is_instance_of_tpl<X, X<Y...>> : std::true_type {};

//-----------------------------------------------------------------------------

/** SFINAE. use this macro to enable a template function overload
based on a compile-time condition.
@code
// define an overload for a non-pod type
template<class T, C4_REQUIRE_T(std::is_pod<T>::value)>
void foo() { std::cout << "pod type\n"; }

// define an overload for a non-pod type
template<class T, C4_REQUIRE_T(!std::is_pod<T>::value)>
void foo() { std::cout << "nonpod type\n"; }

struct non_pod
{
    non_pod() : name("asdfkjhasdkjh") {}
    const char *name;
};

int main()
{
    foo<float>(); // prints "pod type"
    foo<non_pod>(); // prints "nonpod type"
}
@endcode */
#define C4_REQUIRE_T(cond) typename std::enable_if<cond, bool>::type* = nullptr

/** enable_if for a return type
 * @see C4_REQUIRE_T */
#define C4_REQUIRE_R(cond, type_) typename std::enable_if<cond, type_>::type

//-----------------------------------------------------------------------------
/** define a traits class reporting whether a type provides a member typedef */
#define C4_DEFINE_HAS_TYPEDEF(member_typedef)               \
template<typename T>                                        \
struct has_##stype                                          \
{                                                           \
private:                                                    \
                                                            \
    typedef char                      yes;                  \
    typedef struct { char array[2]; } no;                   \
                                                            \
    template<typename C>                                    \
    static yes _test(typename C::member_typedef*);          \
                                                            \
    template<typename C>                                    \
    static no  _test(...);                                  \
                                                            \
public:                                                     \
                                                            \
    enum { value = (sizeof(_test<T>(0)) == sizeof(yes)) };  \
                                                            \
}


/** @} */


//-----------------------------------------------------------------------------


/** @defgroup type_declarations Type declaration utilities
 * @ingroup types
 * @{ */

#define _c4_DEFINE_ARRAY_TYPES_WITHOUT_ITERATOR(T, I)           \
                                                                \
    using size_type = I;                                        \
    using ssize_type = typename std::make_signed<I>::type;      \
    using difference_type = typename std::make_signed<I>::type; \
                                                                \
    using value_type = T;                                       \
    using pointer = T*;                                         \
    using const_pointer = T const*;                             \
    using reference = T&;                                       \
    using const_reference = T const&

#define _c4_DEFINE_TUPLE_ARRAY_TYPES_WITHOUT_ITERATOR(interior_types, I) \
                                                                        \
    using size_type = I;                                                \
    using ssize_type = typename std::make_signed<I>::type;              \
    using difference_type = typename std::make_signed<I>::type;         \
                                                                        \
    template<I n> using value_type = typename std::tuple_element< n, std::tuple<interior_types...>>::type; \
    template<I n> using pointer = value_type<n>*;                       \
    template<I n> using const_pointer = value_type<n> const*;           \
    template<I n> using reference = value_type<n>&;                     \
    template<I n> using const_reference = value_type<n> const&


#define _c4_DEFINE_ARRAY_TYPES(T, I)                                \
                                                                    \
    _c4_DEFINE_ARRAY_TYPES_WITHOUT_ITERATOR(T, I);                  \
                                                                    \
    using iterator = T*;                                            \
    using const_iterator = T const*;                                \
    using reverse_iterator = std::reverse_iterator<T*>;             \
    using const_reverse_iterator = std::reverse_iterator<T const*>


#define _c4_DEFINE_TUPLE_ARRAY_TYPES(interior_types, I)                 \
                                                                        \
    _c4_DEFINE_TUPLE_ARRAY_TYPES_WITHOUT_ITERATOR(interior_types, I);   \
                                                                        \
    template<I n> using iterator = value_type<n>*;                      \
    template<I n> using const_iterator = value_type<n> const*;          \
    template<I n> using reverse_iterator = std::reverse_iterator< value_type<n>*>; \
    template<I n> using const_reverse_iterator = std::reverse_iterator< value_type<n> const*>



/** @} */


//-----------------------------------------------------------------------------


/** @defgroup compatility_utilities Backport implementation of some Modern C++ utilities
 * @ingroup types
 * @{ */

//-----------------------------------------------------------------------------
// index_sequence and friends are available only for C++14 and later.
// A C++11 implementation is provided here.
// This implementation was copied over from clang.
// see http://llvm.org/viewvc/llvm-project/libcxx/trunk/include/utility?revision=211563&view=markup#l687

#if __cplusplus > 201103L

using std::integer_sequence;
using std::index_sequence;
using std::make_integer_sequence;
using std::make_index_sequence;
using std::index_sequence_for;

#else

/** C++11 implementation of integer sequence
 * @see https://en.cppreference.com/w/cpp/utility/integer_sequence
 * @see taken from clang: http://llvm.org/viewvc/llvm-project/libcxx/trunk/include/utility?revision=211563&view=markup#l687 */
template<class _Tp, _Tp... _Ip>
struct integer_sequence
{
    static_assert(std::is_integral<_Tp>::value,
                  "std::integer_sequence can only be instantiated with an integral type" );
    using value_type = _Tp;
    static constexpr size_t size() noexcept { return sizeof...(_Ip); }
};

/** C++11 implementation of index sequence
 * @see https://en.cppreference.com/w/cpp/utility/integer_sequence
 * @see taken from clang: http://llvm.org/viewvc/llvm-project/libcxx/trunk/include/utility?revision=211563&view=markup#l687 */
template<size_t... _Ip>
using index_sequence = integer_sequence<size_t, _Ip...>;

/** @cond DONT_DOCUMENT_THIS */
namespace __detail {

template<typename _Tp, size_t ..._Extra>
struct __repeat;

template<typename _Tp, _Tp ..._Np, size_t ..._Extra>
struct __repeat<integer_sequence<_Tp, _Np...>, _Extra...>
{
    using type = integer_sequence<_Tp,
                            _Np...,
                            sizeof...(_Np) + _Np...,
                            2 * sizeof...(_Np) + _Np...,
                            3 * sizeof...(_Np) + _Np...,
                            4 * sizeof...(_Np) + _Np...,
                            5 * sizeof...(_Np) + _Np...,
                            6 * sizeof...(_Np) + _Np...,
                            7 * sizeof...(_Np) + _Np...,
                            _Extra...>;
};

template<size_t _Np> struct __parity;
template<size_t _Np> struct __make : __parity<_Np % 8>::template __pmake<_Np> {};

template<> struct __make<0> { using type = integer_sequence<size_t>; };
template<> struct __make<1> { using type = integer_sequence<size_t, 0>; };
template<> struct __make<2> { using type = integer_sequence<size_t, 0, 1>; };
template<> struct __make<3> { using type = integer_sequence<size_t, 0, 1, 2>; };
template<> struct __make<4> { using type = integer_sequence<size_t, 0, 1, 2, 3>; };
template<> struct __make<5> { using type = integer_sequence<size_t, 0, 1, 2, 3, 4>; };
template<> struct __make<6> { using type = integer_sequence<size_t, 0, 1, 2, 3, 4, 5>; };
template<> struct __make<7> { using type = integer_sequence<size_t, 0, 1, 2, 3, 4, 5, 6>; };

template<> struct __parity<0> { template<size_t _Np> struct __pmake : __repeat<typename __make<_Np / 8>::type> {}; };
template<> struct __parity<1> { template<size_t _Np> struct __pmake : __repeat<typename __make<_Np / 8>::type, _Np - 1> {}; };
template<> struct __parity<2> { template<size_t _Np> struct __pmake : __repeat<typename __make<_Np / 8>::type, _Np - 2, _Np - 1> {}; };
template<> struct __parity<3> { template<size_t _Np> struct __pmake : __repeat<typename __make<_Np / 8>::type, _Np - 3, _Np - 2, _Np - 1> {}; };
template<> struct __parity<4> { template<size_t _Np> struct __pmake : __repeat<typename __make<_Np / 8>::type, _Np - 4, _Np - 3, _Np - 2, _Np - 1> {}; };
template<> struct __parity<5> { template<size_t _Np> struct __pmake : __repeat<typename __make<_Np / 8>::type, _Np - 5, _Np - 4, _Np - 3, _Np - 2, _Np - 1> {}; };
template<> struct __parity<6> { template<size_t _Np> struct __pmake : __repeat<typename __make<_Np / 8>::type, _Np - 6, _Np - 5, _Np - 4, _Np - 3, _Np - 2, _Np - 1> {}; };
template<> struct __parity<7> { template<size_t _Np> struct __pmake : __repeat<typename __make<_Np / 8>::type, _Np - 7, _Np - 6, _Np - 5, _Np - 4, _Np - 3, _Np - 2, _Np - 1> {}; };

template<typename _Tp, typename _Up>
struct __convert
{
    template<typename> struct __result;
    template<_Tp ..._Np> struct __result<integer_sequence<_Tp, _Np...>>
    {
        using type = integer_sequence<_Up, _Np...>;
    };
};

template<typename _Tp>
struct __convert<_Tp, _Tp>
{
    template<typename _Up> struct __result
    {
         using type = _Up;
    };
};

template<typename _Tp, _Tp _Np>
using __make_integer_sequence_unchecked = typename __detail::__convert<size_t, _Tp>::template __result<typename __detail::__make<_Np>::type>::type;

template<class _Tp, _Tp _Ep>
struct __make_integer_sequence
{
    static_assert(std::is_integral<_Tp>::value,
                  "std::make_integer_sequence can only be instantiated with an integral type" );
    static_assert(0 <= _Ep, "std::make_integer_sequence input shall not be negative");
    typedef __make_integer_sequence_unchecked<_Tp, _Ep> type;
};

} // namespace __detail
/** @endcond */


/** C++11 implementation of index sequence
 * @see https://en.cppreference.com/w/cpp/utility/integer_sequence
 * @see taken from clang: http://llvm.org/viewvc/llvm-project/libcxx/trunk/include/utility?revision=211563&view=markup#l687 */
template<class _Tp, _Tp _Np>
using make_integer_sequence = typename __detail::__make_integer_sequence<_Tp, _Np>::type;

/** C++11 implementation of index sequence
 * @see https://en.cppreference.com/w/cpp/utility/integer_sequence
 * @see taken from clang: http://llvm.org/viewvc/llvm-project/libcxx/trunk/include/utility?revision=211563&view=markup#l687 */
template<size_t _Np>
using make_index_sequence = make_integer_sequence<size_t, _Np>;

/** C++11 implementation of index sequence
 * @see https://en.cppreference.com/w/cpp/utility/integer_sequence
 * @see taken from clang: http://llvm.org/viewvc/llvm-project/libcxx/trunk/include/utility?revision=211563&view=markup#l687 */
template<class... _Tp>
using index_sequence_for = make_index_sequence<sizeof...(_Tp)>;
#endif

/** @} */


} // namespace c4

#endif /* _C4_TYPES_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/types.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/config.hpp
// https://github.com/biojppm/c4core/src/c4/config.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_CONFIG_HPP_
#define _C4_CONFIG_HPP_

/** @defgroup basic_headers Basic headers
 * @brief Headers providing basic macros, platform+cpu+compiler information,
 * C++ facilities and basic typedefs. */

/** @file config.hpp Contains configuration defines and includes the basic_headers.
 * @ingroup basic_headers */

//#define C4_DEBUG

#define C4_ERROR_SHOWS_FILELINE
//#define C4_ERROR_SHOWS_FUNC
//#define C4_ERROR_THROWS_EXCEPTION
//#define C4_NO_ALLOC_DEFAULTS
//#define C4_REDEFINE_CPPNEW

#ifndef C4_SIZE_TYPE
#   define C4_SIZE_TYPE size_t
#endif

#ifndef C4_STR_SIZE_TYPE
#   define C4_STR_SIZE_TYPE C4_SIZE_TYPE
#endif

#ifndef C4_TIME_TYPE
#   define C4_TIME_TYPE double
#endif

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/export.hpp
//#include "c4/export.hpp"
#if !defined(C4_EXPORT_HPP_) && !defined(_C4_EXPORT_HPP_)
#error "amalgamate: file c4/export.hpp must have been included at this point"
#endif /* C4_EXPORT_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/preprocessor.hpp
//#include "c4/preprocessor.hpp"
#if !defined(C4_PREPROCESSOR_HPP_) && !defined(_C4_PREPROCESSOR_HPP_)
#error "amalgamate: file c4/preprocessor.hpp must have been included at this point"
#endif /* C4_PREPROCESSOR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/platform.hpp
//#include "c4/platform.hpp"
#if !defined(C4_PLATFORM_HPP_) && !defined(_C4_PLATFORM_HPP_)
#error "amalgamate: file c4/platform.hpp must have been included at this point"
#endif /* C4_PLATFORM_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/cpu.hpp
//#include "c4/cpu.hpp"
#if !defined(C4_CPU_HPP_) && !defined(_C4_CPU_HPP_)
#error "amalgamate: file c4/cpu.hpp must have been included at this point"
#endif /* C4_CPU_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/compiler.hpp
//#include "c4/compiler.hpp"
#if !defined(C4_COMPILER_HPP_) && !defined(_C4_COMPILER_HPP_)
#error "amalgamate: file c4/compiler.hpp must have been included at this point"
#endif /* C4_COMPILER_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/language.hpp
//#include "c4/language.hpp"
#if !defined(C4_LANGUAGE_HPP_) && !defined(_C4_LANGUAGE_HPP_)
#error "amalgamate: file c4/language.hpp must have been included at this point"
#endif /* C4_LANGUAGE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/types.hpp
//#include "c4/types.hpp"
#if !defined(C4_TYPES_HPP_) && !defined(_C4_TYPES_HPP_)
#error "amalgamate: file c4/types.hpp must have been included at this point"
#endif /* C4_TYPES_HPP_ */


#endif // _C4_CONFIG_HPP_


// (end https://github.com/biojppm/c4core/src/c4/config.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/ext/debugbreak/debugbreak.h
// https://github.com/biojppm/c4core/src/c4/ext/debugbreak/debugbreak.h
//--------------------------------------------------------------------------------
//********************************************************************************

/* Copyright (c) 2011-2021, Scott Tsai
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef DEBUG_BREAK_H
#define DEBUG_BREAK_H

#ifdef _MSC_VER

#define debug_break __debugbreak

#else

#ifdef __cplusplus
extern "C" {
#endif

#define DEBUG_BREAK_USE_TRAP_INSTRUCTION 1
#define DEBUG_BREAK_USE_BULTIN_TRAP      2
#define DEBUG_BREAK_USE_SIGTRAP          3

#if defined(__i386__) || defined(__x86_64__)
	#define DEBUG_BREAK_IMPL DEBUG_BREAK_USE_TRAP_INSTRUCTION
__inline__ static void trap_instruction(void)
{
	__asm__ volatile("int $0x03");
}
#elif defined(__thumb__)
	#define DEBUG_BREAK_IMPL DEBUG_BREAK_USE_TRAP_INSTRUCTION
/* FIXME: handle __THUMB_INTERWORK__ */
__attribute__((always_inline))
__inline__ static void trap_instruction(void)
{
	/* See 'arm-linux-tdep.c' in GDB source.
	 * Both instruction sequences below work. */
#if 1
	/* 'eabi_linux_thumb_le_breakpoint' */
	__asm__ volatile(".inst 0xde01");
#else
	/* 'eabi_linux_thumb2_le_breakpoint' */
	__asm__ volatile(".inst.w 0xf7f0a000");
#endif

	/* Known problem:
	 * After a breakpoint hit, can't 'stepi', 'step', or 'continue' in GDB.
	 * 'step' would keep getting stuck on the same instruction.
	 *
	 * Workaround: use the new GDB commands 'debugbreak-step' and
	 * 'debugbreak-continue' that become available
	 * after you source the script from GDB:
	 *
	 * $ gdb -x debugbreak-gdb.py <... USUAL ARGUMENTS ...>
	 *
	 * 'debugbreak-step' would jump over the breakpoint instruction with
	 * roughly equivalent of:
	 * (gdb) set $instruction_len = 2
	 * (gdb) tbreak *($pc + $instruction_len)
	 * (gdb) jump   *($pc + $instruction_len)
	 */
}
#elif defined(__arm__) && !defined(__thumb__)
	#define DEBUG_BREAK_IMPL DEBUG_BREAK_USE_TRAP_INSTRUCTION
__attribute__((always_inline))
__inline__ static void trap_instruction(void)
{
	/* See 'arm-linux-tdep.c' in GDB source,
	 * 'eabi_linux_arm_le_breakpoint' */
	__asm__ volatile(".inst 0xe7f001f0");
	/* Known problem:
	 * Same problem and workaround as Thumb mode */
}
#elif defined(__aarch64__) && defined(__APPLE__)
	#define DEBUG_BREAK_IMPL DEBUG_BREAK_USE_BULTIN_DEBUGTRAP
#elif defined(__aarch64__)
	#define DEBUG_BREAK_IMPL DEBUG_BREAK_USE_TRAP_INSTRUCTION
__attribute__((always_inline))
__inline__ static void trap_instruction(void)
{
	/* See 'aarch64-tdep.c' in GDB source,
	 * 'aarch64_default_breakpoint' */
	__asm__ volatile(".inst 0xd4200000");
}
#elif defined(__powerpc__)
	/* PPC 32 or 64-bit, big or little endian */
	#define DEBUG_BREAK_IMPL DEBUG_BREAK_USE_TRAP_INSTRUCTION
__attribute__((always_inline))
__inline__ static void trap_instruction(void)
{
	/* See 'rs6000-tdep.c' in GDB source,
	 * 'rs6000_breakpoint' */
	__asm__ volatile(".4byte 0x7d821008");

	/* Known problem:
	 * After a breakpoint hit, can't 'stepi', 'step', or 'continue' in GDB.
	 * 'step' stuck on the same instruction ("twge r2,r2").
	 *
	 * The workaround is the same as ARM Thumb mode: use debugbreak-gdb.py
	 * or manually jump over the instruction. */
}
#elif defined(__riscv)
	/* RISC-V 32 or 64-bit, whether the "C" extension
	 * for compressed, 16-bit instructions are supported or not */
	#define DEBUG_BREAK_IMPL DEBUG_BREAK_USE_TRAP_INSTRUCTION
__attribute__((always_inline))
__inline__ static void trap_instruction(void)
{
	/* See 'riscv-tdep.c' in GDB source,
	 * 'riscv_sw_breakpoint_from_kind' */
	__asm__ volatile(".4byte 0x00100073");
}
#else
	#define DEBUG_BREAK_IMPL DEBUG_BREAK_USE_SIGTRAP
#endif


#ifndef DEBUG_BREAK_IMPL
#error "debugbreak.h is not supported on this target"
#elif DEBUG_BREAK_IMPL == DEBUG_BREAK_USE_TRAP_INSTRUCTION
__attribute__((always_inline))
__inline__ static void debug_break(void)
{
	trap_instruction();
}
#elif DEBUG_BREAK_IMPL == DEBUG_BREAK_USE_BULTIN_DEBUGTRAP
__attribute__((always_inline))
__inline__ static void debug_break(void)
{
	__builtin_debugtrap();
}
#elif DEBUG_BREAK_IMPL == DEBUG_BREAK_USE_BULTIN_TRAP
__attribute__((always_inline))
__inline__ static void debug_break(void)
{
	__builtin_trap();
}
#elif DEBUG_BREAK_IMPL == DEBUG_BREAK_USE_SIGTRAP
#include <signal.h>
__attribute__((always_inline))
__inline__ static void debug_break(void)
{
	raise(SIGTRAP);
}
#else
#error "invalid DEBUG_BREAK_IMPL value"
#endif

#ifdef __cplusplus
}
#endif

#endif /* ifdef _MSC_VER */

#endif /* ifndef DEBUG_BREAK_H */


// (end https://github.com/biojppm/c4core/src/c4/ext/debugbreak/debugbreak.h)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/error.hpp
// https://github.com/biojppm/c4core/src/c4/error.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_ERROR_HPP_
#define _C4_ERROR_HPP_

/** @file error.hpp Facilities for error reporting and runtime assertions. */

/** @defgroup error_checking Error checking */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/config.hpp
//#include "c4/config.hpp"
#if !defined(C4_CONFIG_HPP_) && !defined(_C4_CONFIG_HPP_)
#error "amalgamate: file c4/config.hpp must have been included at this point"
#endif /* C4_CONFIG_HPP_ */


#ifdef _DOXYGEN_
    /** if this is defined and exceptions are enabled, then calls to C4_ERROR()
     * will throw an exception
     * @ingroup error_checking */
#   define C4_EXCEPTIONS_ENABLED
    /** if this is defined and exceptions are enabled, then calls to C4_ERROR()
     *  will throw an exception
     * @see C4_EXCEPTIONS_ENABLED
     * @ingroup error_checking */
#   define C4_ERROR_THROWS_EXCEPTION
    /** evaluates to noexcept when C4_ERROR might be called and
     * exceptions are disabled. Otherwise, defaults to nothing.
     * @ingroup error_checking */
#   define C4_NOEXCEPT
#endif // _DOXYGEN_

#if defined(C4_EXCEPTIONS_ENABLED) && defined(C4_ERROR_THROWS_EXCEPTION)
#   define C4_NOEXCEPT
#else
#   define C4_NOEXCEPT noexcept
#endif


namespace c4 {
namespace detail {
struct fail_type__ {};
} // detail
} // c4
#define C4_STATIC_ERROR(dummy_type, errmsg)                             \
    static_assert(std::is_same<dummy_type, c4::detail::fail_type__>::value, errmsg)


//-----------------------------------------------------------------------------

#define C4_ASSERT_SAME_TYPE(ty1, ty2)                       \
    C4_STATIC_ASSERT(std::is_same<ty1 C4_COMMA_X ty2>::value)

#define C4_ASSERT_DIFF_TYPE(ty1, ty2)                       \
    C4_STATIC_ASSERT( ! std::is_same<ty1 C4_COMMA_X ty2>::value)


//-----------------------------------------------------------------------------

#ifdef _DOXYGEN_
/** utility macro that triggers a breakpoint when
 * the debugger is attached and NDEBUG is not defined.
 * @ingroup error_checking */
#   define C4_DEBUG_BREAK()
#endif // _DOXYGEN_


#if defined(NDEBUG) || defined(C4_NO_DEBUG_BREAK)
#   define C4_DEBUG_BREAK()
#else
#   ifdef __clang__
#       pragma clang diagnostic push
#       if !defined(__APPLE_CC__)
#           if __clang_major__ >= 10
#               pragma clang diagnostic ignored "-Wgnu-inline-cpp-without-extern" // debugbreak/debugbreak.h:50:16: error: 'gnu_inline' attribute without 'extern' in C++ treated as externally available, this changed in Clang 10 [-Werror,-Wgnu-inline-cpp-without-extern]
#           endif
#       else
#           if __clang_major__ >= 13
#               pragma clang diagnostic ignored "-Wgnu-inline-cpp-without-extern" // debugbreak/debugbreak.h:50:16: error: 'gnu_inline' attribute without 'extern' in C++ treated as externally available, this changed in Clang 10 [-Werror,-Wgnu-inline-cpp-without-extern]
#           endif
#       endif
#   elif defined(__GNUC__)
#   endif
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/ext/debugbreak/debugbreak.h
//#   include <c4/ext/debugbreak/debugbreak.h>
#if !defined(DEBUG_BREAK_H) && !defined(_DEBUG_BREAK_H)
#error "amalgamate: file c4/ext/debugbreak/debugbreak.h must have been included at this point"
#endif /* DEBUG_BREAK_H */

#   define C4_DEBUG_BREAK() if(c4::is_debugger_attached()) { ::debug_break(); }
#   ifdef __clang__
#       pragma clang diagnostic pop
#   elif defined(__GNUC__)
#   endif
#endif

namespace c4 {
C4CORE_EXPORT bool is_debugger_attached();
} // namespace c4


//-----------------------------------------------------------------------------

#ifdef __clang__
    /* NOTE: using , ## __VA_ARGS__ to deal with zero-args calls to
     * variadic macros is not portable, but works in clang, gcc, msvc, icc.
     * clang requires switching off compiler warnings for pedantic mode.
     * @see http://stackoverflow.com/questions/32047685/variadic-macro-without-arguments */
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments" // warning: token pasting of ',' and __VA_ARGS__ is a GNU extension
#elif defined(__GNUC__)
    /* GCC also issues a warning for zero-args calls to variadic macros.
     * This warning is switched on with -pedantic and apparently there is no
     * easy way to turn it off as with clang. But marking this as a system
     * header works.
     * @see https://gcc.gnu.org/onlinedocs/cpp/System-Headers.html
     * @see http://stackoverflow.com/questions/35587137/ */
#   pragma GCC system_header
#endif


//-----------------------------------------------------------------------------

namespace c4 {

typedef enum : uint32_t {
    /** when an error happens and the debugger is attached, call C4_DEBUG_BREAK().
     * Without effect otherwise. */
    ON_ERROR_DEBUGBREAK = 0x01 << 0,
    /** when an error happens log a message. */
    ON_ERROR_LOG = 0x01 << 1,
    /** when an error happens invoke a callback if it was set with
     * set_error_callback(). */
    ON_ERROR_CALLBACK = 0x01 << 2,
    /** when an error happens call std::terminate(). */
    ON_ERROR_ABORT = 0x01 << 3,
    /** when an error happens and exceptions are enabled throw an exception.
     * Without effect otherwise. */
    ON_ERROR_THROW = 0x01 << 4,
    /** the default flags. */
    ON_ERROR_DEFAULTS = ON_ERROR_DEBUGBREAK|ON_ERROR_LOG|ON_ERROR_CALLBACK|ON_ERROR_ABORT
} ErrorFlags_e;
using error_flags = uint32_t;
C4CORE_EXPORT void set_error_flags(error_flags f);
C4CORE_EXPORT error_flags get_error_flags();


using error_callback_type = void (*)(const char* msg, size_t msg_size);
C4CORE_EXPORT void set_error_callback(error_callback_type cb);
C4CORE_EXPORT error_callback_type get_error_callback();


//-----------------------------------------------------------------------------
/** RAII class controling the error settings inside a scope. */
struct ScopedErrorSettings
{
    error_flags m_flags;
    error_callback_type m_callback;

    explicit ScopedErrorSettings(error_callback_type cb)
    :   m_flags(get_error_flags()),
        m_callback(get_error_callback())
    {
        set_error_callback(cb);
    }
    explicit ScopedErrorSettings(error_flags flags)
    :   m_flags(get_error_flags()),
        m_callback(get_error_callback())
    {
        set_error_flags(flags);
    }
    explicit ScopedErrorSettings(error_flags flags, error_callback_type cb)
    :   m_flags(get_error_flags()),
        m_callback(get_error_callback())
    {
        set_error_flags(flags);
        set_error_callback(cb);
    }
    ~ScopedErrorSettings()
    {
        set_error_flags(m_flags);
        set_error_callback(m_callback);
    }
};


//-----------------------------------------------------------------------------

/** source location */
struct srcloc;

// watchout: for VS the [[noreturn]] needs to come before other annotations like C4CORE_EXPORT
[[noreturn]] C4CORE_EXPORT void handle_error(srcloc s, const char *fmt, ...);
C4CORE_EXPORT void handle_warning(srcloc s, const char *fmt, ...);


#   define C4_ERROR(msg, ...)                               \
    do {                                                    \
        if(c4::get_error_flags() & c4::ON_ERROR_DEBUGBREAK) \
        {                                                   \
            C4_DEBUG_BREAK()                                \
        }                                                   \
        c4::handle_error(C4_SRCLOC(), msg, ## __VA_ARGS__); \
    } while(0)


#   define C4_WARNING(msg, ...)                             \
    c4::handle_warning(C4_SRCLOC(), msg, ## __VA_ARGS__)


#if defined(C4_ERROR_SHOWS_FILELINE) && defined(C4_ERROR_SHOWS_FUNC)

struct srcloc
{
    const char *file = "";
    const char *func = "";
    int line = 0;
};
#define C4_SRCLOC() c4::srcloc{__FILE__, C4_PRETTY_FUNC, __LINE__}

#elif defined(C4_ERROR_SHOWS_FILELINE)

struct srcloc
{
    const char *file;
    int line;
};
#define C4_SRCLOC() c4::srcloc{__FILE__, __LINE__}

#elif ! defined(C4_ERROR_SHOWS_FUNC)

struct srcloc
{
};
#define C4_SRCLOC() c4::srcloc()

#else
#   error not implemented
#endif


//-----------------------------------------------------------------------------
// assertions

// Doxygen needs this so that only one definition counts
#ifdef _DOXYGEN_
    /** Explicitly enables assertions, independently of NDEBUG status.
     * This is meant to allow enabling assertions even when NDEBUG is defined.
     * Defaults to undefined.
     * @ingroup error_checking */
#   define C4_USE_ASSERT
    /** assert that a condition is true; this is turned off when NDEBUG
     * is defined and C4_USE_ASSERT is not true.
     * @ingroup error_checking  */
#   define C4_ASSERT
    /** same as C4_ASSERT(), additionally prints a printf-formatted message
     * @ingroup error_checking */
#   define C4_ASSERT_MSG
    /** evaluates to C4_NOEXCEPT when C4_XASSERT is disabled; otherwise, defaults
     * to noexcept
     * @ingroup error_checking */
#   define C4_NOEXCEPT_A
#endif // _DOXYGEN_

#ifndef C4_USE_ASSERT
#   ifdef NDEBUG
#       define C4_USE_ASSERT 0
#   else
#       define C4_USE_ASSERT 1
#   endif
#endif

#if C4_USE_ASSERT
#   define C4_ASSERT(cond) C4_CHECK(cond)
#   define C4_ASSERT_MSG(cond, /*fmt, */...) C4_CHECK_MSG(cond, ## __VA_ARGS__)
#   define C4_ASSERT_IF(predicate, cond) if(predicate) { C4_ASSERT(cond); }
#   define C4_NOEXCEPT_A C4_NOEXCEPT
#else
#   define C4_ASSERT(cond)
#   define C4_ASSERT_MSG(cond, /*fmt, */...)
#   define C4_ASSERT_IF(predicate, cond)
#   define C4_NOEXCEPT_A noexcept
#endif


//-----------------------------------------------------------------------------
// extreme assertions

// Doxygen needs this so that only one definition counts
#ifdef _DOXYGEN_
    /** Explicitly enables extreme assertions; this is meant to allow enabling
     * assertions even when NDEBUG is defined. Defaults to undefined.
     * @ingroup error_checking */
#   define C4_USE_XASSERT
    /** extreme assertion: can be switched off independently of
     * the regular assertion; use for example for bounds checking in hot code.
     * Turned on only when C4_USE_XASSERT is defined
     * @ingroup error_checking */
#   define C4_XASSERT
    /** same as C4_XASSERT(), and additionally prints a printf-formatted message
     * @ingroup error_checking */
#   define C4_XASSERT_MSG
    /** evaluates to C4_NOEXCEPT when C4_XASSERT is disabled; otherwise, defaults to noexcept
     * @ingroup error_checking */
#   define C4_NOEXCEPT_X
#endif // _DOXYGEN_

#ifndef C4_USE_XASSERT
#   define C4_USE_XASSERT C4_USE_ASSERT
#endif

#if C4_USE_XASSERT
#   define C4_XASSERT(cond) C4_CHECK(cond)
#   define C4_XASSERT_MSG(cond, /*fmt, */...) C4_CHECK_MSG(cond, ## __VA_ARGS__)
#   define C4_XASSERT_IF(predicate, cond) if(predicate) { C4_XASSERT(cond); }
#   define C4_NOEXCEPT_X C4_NOEXCEPT
#else
#   define C4_XASSERT(cond)
#   define C4_XASSERT_MSG(cond, /*fmt, */...)
#   define C4_XASSERT_IF(predicate, cond)
#   define C4_NOEXCEPT_X noexcept
#endif


//-----------------------------------------------------------------------------
// checks: never switched-off

/** Check that a condition is true, or raise an error when not
 * true. Unlike C4_ASSERT(), this check is not disabled in non-debug
 * builds.
 * @see C4_ASSERT
 * @ingroup error_checking
 *
 * @todo add constexpr-compatible compile-time assert:
 * https://akrzemi1.wordpress.com/2017/05/18/asserts-in-constexpr-functions/
 */
#define C4_CHECK(cond)                              \
    do {                                            \
        if(C4_UNLIKELY(!(cond)))                    \
        {                                           \
            C4_ERROR("check failed: %s", #cond);    \
        }                                           \
    } while(0)


/** like C4_CHECK(), and additionally log a printf-style message.
 * @see C4_CHECK
 * @ingroup error_checking */
#define C4_CHECK_MSG(cond, fmt, ...)                                    \
    do {                                                                \
        if(C4_UNLIKELY(!(cond)))                                        \
        {                                                               \
            C4_ERROR("check failed: " #cond "\n" fmt, ## __VA_ARGS__);  \
        }                                                               \
    } while(0)


//-----------------------------------------------------------------------------
// Common error conditions

#define C4_NOT_IMPLEMENTED() C4_ERROR("NOT IMPLEMENTED")
#define C4_NOT_IMPLEMENTED_MSG(/*msg, */...) C4_ERROR("NOT IMPLEMENTED: " __VA_ARGS__)
#define C4_NOT_IMPLEMENTED_IF(condition) do { if(C4_UNLIKELY(condition)) { C4_ERROR("NOT IMPLEMENTED"); } } while(0)
#define C4_NOT_IMPLEMENTED_IF_MSG(condition, /*msg, */...) do { if(C4_UNLIKELY(condition)) { C4_ERROR("NOT IMPLEMENTED: " __VA_ARGS__); } } while(0)

#define C4_NEVER_REACH() do { C4_ERROR("never reach this point"); C4_UNREACHABLE(); } while(0)
#define C4_NEVER_REACH_MSG(/*msg, */...) do { C4_ERROR("never reach this point: " __VA_ARGS__); C4_UNREACHABLE(); } while(0)



//-----------------------------------------------------------------------------
// helpers for warning suppression
// idea adapted from https://github.com/onqtam/doctest/

// TODO: add C4_MESSAGE() https://stackoverflow.com/questions/18252351/custom-preprocessor-macro-for-a-conditional-pragma-message-xxx?rq=1


#ifdef C4_MSVC
#define C4_SUPPRESS_WARNING_MSVC_PUSH __pragma(warning(push))
#define C4_SUPPRESS_WARNING_MSVC(w)  __pragma(warning(disable : w))
#define C4_SUPPRESS_WARNING_MSVC_POP __pragma(warning(pop))
#else // C4_MSVC
#define C4_SUPPRESS_WARNING_MSVC_PUSH
#define C4_SUPPRESS_WARNING_MSVC(w)
#define C4_SUPPRESS_WARNING_MSVC_POP
#endif // C4_MSVC


#ifdef C4_CLANG
#define C4_PRAGMA_TO_STR(x) _Pragma(#x)
#define C4_SUPPRESS_WARNING_CLANG_PUSH _Pragma("clang diagnostic push")
#define C4_SUPPRESS_WARNING_CLANG(w) C4_PRAGMA_TO_STR(clang diagnostic ignored w)
#define C4_SUPPRESS_WARNING_CLANG_POP _Pragma("clang diagnostic pop")
#else // C4_CLANG
#define C4_SUPPRESS_WARNING_CLANG_PUSH
#define C4_SUPPRESS_WARNING_CLANG(w)
#define C4_SUPPRESS_WARNING_CLANG_POP
#endif // C4_CLANG


#ifdef C4_GCC
#define C4_PRAGMA_TO_STR(x) _Pragma(#x)
#define C4_SUPPRESS_WARNING_GCC_PUSH _Pragma("GCC diagnostic push")
#define C4_SUPPRESS_WARNING_GCC(w) C4_PRAGMA_TO_STR(GCC diagnostic ignored w)
#define C4_SUPPRESS_WARNING_GCC_POP _Pragma("GCC diagnostic pop")
#else // C4_GCC
#define C4_SUPPRESS_WARNING_GCC_PUSH
#define C4_SUPPRESS_WARNING_GCC(w)
#define C4_SUPPRESS_WARNING_GCC_POP
#endif // C4_GCC


#define C4_SUPPRESS_WARNING_MSVC_WITH_PUSH(w)   \
    C4_SUPPRESS_WARNING_MSVC_PUSH               \
    C4_SUPPRESS_WARNING_MSVC(w)

#define C4_SUPPRESS_WARNING_CLANG_WITH_PUSH(w)  \
    C4_SUPPRESS_WARNING_CLANG_PUSH              \
    C4_SUPPRESS_WARNING_CLANG(w)

#define C4_SUPPRESS_WARNING_GCC_WITH_PUSH(w)    \
    C4_SUPPRESS_WARNING_GCC_PUSH                \
    C4_SUPPRESS_WARNING_GCC(w)


#define C4_SUPPRESS_WARNING_GCC_CLANG_PUSH \
    C4_SUPPRESS_WARNING_GCC_PUSH     \
    C4_SUPPRESS_WARNING_CLANG_PUSH

#define C4_SUPPRESS_WARNING_GCC_CLANG(w) \
    C4_SUPPRESS_WARNING_GCC(w)     \
    C4_SUPPRESS_WARNING_CLANG(w)

#define C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH(w) \
    C4_SUPPRESS_WARNING_GCC_WITH_PUSH(w)     \
    C4_SUPPRESS_WARNING_CLANG_WITH_PUSH(w)

#define C4_SUPPRESS_WARNING_GCC_CLANG_POP \
    C4_SUPPRESS_WARNING_GCC_POP     \
    C4_SUPPRESS_WARNING_CLANG_POP

} // namespace c4

#ifdef __clang__
#   pragma clang diagnostic pop
#endif

#endif /* _C4_ERROR_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/error.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/memory_util.hpp
// https://github.com/biojppm/c4core/src/c4/memory_util.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_MEMORY_UTIL_HPP_
#define _C4_MEMORY_UTIL_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/config.hpp
//#include "c4/config.hpp"
#if !defined(C4_CONFIG_HPP_) && !defined(_C4_CONFIG_HPP_)
#error "amalgamate: file c4/config.hpp must have been included at this point"
#endif /* C4_CONFIG_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/compiler.hpp
//#include "c4/compiler.hpp"
#if !defined(C4_COMPILER_HPP_) && !defined(_C4_COMPILER_HPP_)
#error "amalgamate: file c4/compiler.hpp must have been included at this point"
#endif /* C4_COMPILER_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/cpu.hpp
//#include "c4/cpu.hpp"
#if !defined(C4_CPU_HPP_) && !defined(_C4_CPU_HPP_)
#error "amalgamate: file c4/cpu.hpp must have been included at this point"
#endif /* C4_CPU_HPP_ */

#ifdef C4_MSVC
#include <intrin.h>
#endif
//included above:
//#include <string.h>

#if (defined(__GNUC__) && __GNUC__ >= 10) || defined(__has_builtin)
#define _C4_USE_LSB_INTRINSIC(which) __has_builtin(which)
#define _C4_USE_MSB_INTRINSIC(which) __has_builtin(which)
#elif defined(C4_MSVC)
#define _C4_USE_LSB_INTRINSIC(which) true
#define _C4_USE_MSB_INTRINSIC(which) true
#else
// let's try our luck
#define _C4_USE_LSB_INTRINSIC(which) true
#define _C4_USE_MSB_INTRINSIC(which) true
#endif


/** @file memory_util.hpp Some memory utilities. */

namespace c4 {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")

/** set the given memory to zero */
C4_ALWAYS_INLINE void mem_zero(void* mem, size_t num_bytes)
{
    memset(mem, 0, num_bytes);
}
/** set the given memory to zero */
template<class T>
C4_ALWAYS_INLINE void mem_zero(T* mem, size_t num_elms)
{
    memset(mem, 0, sizeof(T) * num_elms);
}
/** set the given memory to zero */
template<class T>
C4_ALWAYS_INLINE void mem_zero(T* mem)
{
    memset(mem, 0, sizeof(T));
}

C4_ALWAYS_INLINE C4_CONST bool mem_overlaps(void const* a, void const* b, size_t sza, size_t szb)
{
    // thanks @timwynants
    return (((const char*)b + szb) > a && b < ((const char*)a+sza));
}

void mem_repeat(void* dest, void const* pattern, size_t pattern_size, size_t num_times);


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<class T>
C4_ALWAYS_INLINE C4_CONST bool is_aligned(T *ptr, uintptr_t alignment=alignof(T))
{
    return (uintptr_t(ptr) & (alignment - uintptr_t(1))) == uintptr_t(0);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// least significant bit

/** @name msb Compute the least significant bit
 * @note the input value must be nonzero
 * @note the input type must be unsigned
 */
/** @{ */

// https://graphics.stanford.edu/~seander/bithacks.html#ZerosOnRightLinear
#define _c4_lsb_fallback                                                \
    unsigned c = 0;                                                     \
    v = (v ^ (v - 1)) >> 1; /* Set v's trailing 0s to 1s and zero rest */ \
    for(; v; ++c)                                                       \
        v >>= 1;                                                        \
    return (unsigned) c

// u8
template<class I>
C4_CONSTEXPR14
auto lsb(I v) noexcept
    -> typename std::enable_if<sizeof(I) == 1u, unsigned>::type
{
    C4_STATIC_ASSERT(std::is_unsigned<I>::value);
    C4_ASSERT(v != 0);
    #if _C4_USE_LSB_INTRINSIC(__builtin_ctz)
        // upcast to use the intrinsic, it's cheaper.
        #ifdef C4_MSVC
            #if !defined(C4_CPU_ARM64) && !defined(C4_CPU_ARM)
                unsigned long bit;
                _BitScanForward(&bit, (unsigned long)v);
                return bit;
            #else
                _c4_lsb_fallback;
            #endif
        #else
            return (unsigned)__builtin_ctz((unsigned)v);
        #endif
    #else
        _c4_lsb_fallback;
    #endif
}

// u16
template<class I>
C4_CONSTEXPR14
auto lsb(I v) noexcept
    -> typename std::enable_if<sizeof(I) == 2u, unsigned>::type
{
    C4_STATIC_ASSERT(std::is_unsigned<I>::value);
    C4_ASSERT(v != 0);
    #if _C4_USE_LSB_INTRINSIC(__builtin_ctz)
        // upcast to use the intrinsic, it's cheaper.
        // Then remember that the upcast makes it to 31bits
        #ifdef C4_MSVC
            #if !defined(C4_CPU_ARM64) && !defined(C4_CPU_ARM)
                unsigned long bit;
                _BitScanForward(&bit, (unsigned long)v);
                return bit;
            #else
                _c4_lsb_fallback;
            #endif
        #else
            return (unsigned)__builtin_ctz((unsigned)v);
        #endif
    #else
        _c4_lsb_fallback;
    #endif
}

// u32
template<class I>
C4_CONSTEXPR14
auto lsb(I v) noexcept
    -> typename std::enable_if<sizeof(I) == 4u, unsigned>::type
{
    C4_STATIC_ASSERT(std::is_unsigned<I>::value);
    C4_ASSERT(v != 0);
    #if _C4_USE_LSB_INTRINSIC(__builtin_ctz)
        #ifdef C4_MSVC
            #if !defined(C4_CPU_ARM64) && !defined(C4_CPU_ARM)
                unsigned long bit;
                _BitScanForward(&bit, v);
                return bit;
            #else
                _c4_lsb_fallback;
            #endif
        #else
            return (unsigned)__builtin_ctz((unsigned)v);
        #endif
    #else
        _c4_lsb_fallback;
    #endif
}

// u64 in 64bits
template<class I>
C4_CONSTEXPR14
auto lsb(I v) noexcept
    -> typename std::enable_if<sizeof(I) == 8u && sizeof(unsigned long) == 8u, unsigned>::type
{
    C4_STATIC_ASSERT(std::is_unsigned<I>::value);
    C4_ASSERT(v != 0);
    #if _C4_USE_LSB_INTRINSIC(__builtin_ctzl)
        #if defined(C4_MSVC)
            #if !defined(C4_CPU_ARM64) && !defined(C4_CPU_ARM)
                unsigned long bit;
                _BitScanForward64(&bit, v);
                return bit;
            #else
                _c4_lsb_fallback;
            #endif
        #else
            return (unsigned)__builtin_ctzl((unsigned long)v);
        #endif
    #else
        _c4_lsb_fallback;
    #endif
}

// u64 in 32bits
template<class I>
C4_CONSTEXPR14
auto lsb(I v) noexcept
    -> typename std::enable_if<sizeof(I) == 8u && sizeof(unsigned long long) == 8u && sizeof(unsigned long) != sizeof(unsigned long long), unsigned>::type
{
    C4_STATIC_ASSERT(std::is_unsigned<I>::value);
    C4_ASSERT(v != 0);
    #if _C4_USE_LSB_INTRINSIC(__builtin_ctzll)
        #if defined(C4_MSVC)
            #if !defined(C4_CPU_X86) && !defined(C4_CPU_ARM64) && !defined(C4_CPU_ARM)
                unsigned long bit;
                _BitScanForward64(&bit, v);
                return bit;
            #else
                _c4_lsb_fallback;
            #endif
        #else
            return (unsigned)__builtin_ctzll((unsigned long long)v);
        #endif
    #else
        _c4_lsb_fallback;
    #endif
}

#undef _c4_lsb_fallback

/** @} */


namespace detail {
template<class I, I val, unsigned num_bits, bool finished> struct _lsb11;
template<class I, I val, unsigned num_bits>
struct _lsb11<I, val, num_bits, false>
{
    enum : unsigned { num = _lsb11<I, (val>>1), num_bits+I(1), (((val>>1)&I(1))!=I(0))>::num };
};
template<class I, I val, unsigned num_bits>
struct _lsb11<I, val, num_bits, true>
{
    enum : unsigned { num = num_bits };
};
} // namespace detail


/** TMP version of lsb(); this needs to be implemented with template
 * meta-programming because C++11 cannot use a constexpr function with
 * local variables
 * @see lsb */
template<class I, I number>
struct lsb11
{
    static_assert(number != 0, "lsb: number must be nonzero");
    enum : unsigned { value = detail::_lsb11<I, number, 0, ((number&I(1))!=I(0))>::num};
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// most significant bit


/** @name msb Compute the most significant bit
 * @note the input value must be nonzero
 * @note the input type must be unsigned
 */
/** @{ */


#define _c4_msb8_fallback                       \
    unsigned n = 0;                             \
    if(v & I(0xf0)) v >>= 4, n |= I(4);         \
    if(v & I(0x0c)) v >>= 2, n |= I(2);         \
    if(v & I(0x02)) v >>= 1, n |= I(1);         \
    return n

#define _c4_msb16_fallback                      \
    unsigned n = 0;                             \
    if(v & I(0xff00)) v >>= 8, n |= I(8);       \
    if(v & I(0x00f0)) v >>= 4, n |= I(4);       \
    if(v & I(0x000c)) v >>= 2, n |= I(2);       \
    if(v & I(0x0002)) v >>= 1, n |= I(1);       \
    return n

#define _c4_msb32_fallback                      \
    unsigned n = 0;                             \
    if(v & I(0xffff0000)) v >>= 16, n |= 16;    \
    if(v & I(0x0000ff00)) v >>= 8, n |= 8;      \
    if(v & I(0x000000f0)) v >>= 4, n |= 4;      \
    if(v & I(0x0000000c)) v >>= 2, n |= 2;      \
    if(v & I(0x00000002)) v >>= 1, n |= 1;      \
    return n

#define _c4_msb64_fallback                              \
    unsigned n = 0;                                     \
    if(v & I(0xffffffff00000000)) v >>= 32, n |= I(32); \
    if(v & I(0x00000000ffff0000)) v >>= 16, n |= I(16); \
    if(v & I(0x000000000000ff00)) v >>= 8, n |= I(8);   \
    if(v & I(0x00000000000000f0)) v >>= 4, n |= I(4);   \
    if(v & I(0x000000000000000c)) v >>= 2, n |= I(2);   \
    if(v & I(0x0000000000000002)) v >>= 1, n |= I(1);   \
    return n


// u8
template<class I>
C4_CONSTEXPR14
auto msb(I v) noexcept
    -> typename std::enable_if<sizeof(I) == 1u, unsigned>::type
{
    C4_STATIC_ASSERT(std::is_unsigned<I>::value);
    C4_ASSERT(v != 0);
    #if _C4_USE_MSB_INTRINSIC(__builtin_clz)
        // upcast to use the intrinsic, it's cheaper.
        // Then remember that the upcast makes it to 31bits
        #ifdef C4_MSVC
            #if !defined(C4_CPU_ARM64) && !defined(C4_CPU_ARM)
                unsigned long bit;
                _BitScanReverse(&bit, (unsigned long)v);
                return bit;
            #else
                _c4_msb8_fallback;
            #endif
        #else
            return 31u - (unsigned)__builtin_clz((unsigned)v);
        #endif
    #else
        _c4_msb8_fallback;
    #endif
}

// u16
template<class I>
C4_CONSTEXPR14
auto msb(I v) noexcept
    -> typename std::enable_if<sizeof(I) == 2u, unsigned>::type
{
    C4_STATIC_ASSERT(std::is_unsigned<I>::value);
    C4_ASSERT(v != 0);
    #if _C4_USE_MSB_INTRINSIC(__builtin_clz)
        // upcast to use the intrinsic, it's cheaper.
        // Then remember that the upcast makes it to 31bits
        #ifdef C4_MSVC
            #if !defined(C4_CPU_ARM64) && !defined(C4_CPU_ARM)
                unsigned long bit;
                _BitScanReverse(&bit, (unsigned long)v);
                return bit;
            #else
                _c4_msb16_fallback;
            #endif
        #else
            return 31u - (unsigned)__builtin_clz((unsigned)v);
        #endif
    #else
        _c4_msb16_fallback;
    #endif
}

// u32
template<class I>
C4_CONSTEXPR14
auto msb(I v) noexcept
    -> typename std::enable_if<sizeof(I) == 4u, unsigned>::type
{
    C4_STATIC_ASSERT(std::is_unsigned<I>::value);
    C4_ASSERT(v != 0);
    #if _C4_USE_MSB_INTRINSIC(__builtin_clz)
        #ifdef C4_MSVC
            #if !defined(C4_CPU_ARM64) && !defined(C4_CPU_ARM)
                unsigned long bit;
                _BitScanReverse(&bit, v);
                return bit;
            #else
                _c4_msb32_fallback;
            #endif
        #else
            return 31u - (unsigned)__builtin_clz((unsigned)v);
        #endif
    #else
        _c4_msb32_fallback;
    #endif
}

// u64 in 64bits
template<class I>
C4_CONSTEXPR14
auto msb(I v) noexcept
    -> typename std::enable_if<sizeof(I) == 8u && sizeof(unsigned long) == 8u, unsigned>::type
{
    C4_STATIC_ASSERT(std::is_unsigned<I>::value);
    C4_ASSERT(v != 0);
    #if _C4_USE_MSB_INTRINSIC(__builtin_clzl)
        #ifdef C4_MSVC
            #if !defined(C4_CPU_ARM64) && !defined(C4_CPU_ARM)
                unsigned long bit;
                _BitScanReverse64(&bit, v);
                return bit;
            #else
                _c4_msb64_fallback;
            #endif
        #else
            return 63u - (unsigned)__builtin_clzl((unsigned long)v);
        #endif
    #else
        _c4_msb64_fallback;
    #endif
}

// u64 in 32bits
template<class I>
C4_CONSTEXPR14
auto msb(I v) noexcept
    -> typename std::enable_if<sizeof(I) == 8u && sizeof(unsigned long long) == 8u && sizeof(unsigned long) != sizeof(unsigned long long), unsigned>::type
{
    C4_STATIC_ASSERT(std::is_unsigned<I>::value);
    C4_ASSERT(v != 0);
    #if _C4_USE_MSB_INTRINSIC(__builtin_clzll)
        #ifdef C4_MSVC
            #if !defined(C4_CPU_X86) && !defined(C4_CPU_ARM64) && !defined(C4_CPU_ARM)
                unsigned long bit;
                _BitScanReverse64(&bit, v);
                return bit;
            #else
                _c4_msb64_fallback;
            #endif
        #else
            return 63u - (unsigned)__builtin_clzll((unsigned long long)v);
        #endif
    #else
        _c4_msb64_fallback;
    #endif
}

#undef _c4_msb8_fallback
#undef _c4_msb16_fallback
#undef _c4_msb32_fallback
#undef _c4_msb64_fallback

/** @} */


namespace detail {
template<class I, I val, I num_bits, bool finished> struct _msb11;
template<class I, I val, I num_bits>
struct _msb11< I, val, num_bits, false>
{
    enum : unsigned { num = _msb11<I, (val>>1), num_bits+I(1), ((val>>1)==I(0))>::num };
};
template<class I, I val, I num_bits>
struct _msb11<I, val, num_bits, true>
{
    static_assert(val == 0, "bad implementation");
    enum : unsigned { num = (unsigned)(num_bits-1) };
};
} // namespace detail


/** TMP version of msb(); this needs to be implemented with template
 * meta-programming because C++11 cannot use a constexpr function with
 * local variables
 * @see msb */
template<class I, I number>
struct msb11
{
    enum : unsigned { value = detail::_msb11<I, number, 0, (number==I(0))>::num };
};



#undef _C4_USE_LSB_INTRINSIC
#undef _C4_USE_MSB_INTRINSIC

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

// there is an implicit conversion below; it happens when E or B are
// narrower than int, and thus any operation will upcast the result to
// int, and then downcast to assign
C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wconversion")

/** integer power; this function is constexpr-14 because of the local
 * variables */
template<class B, class E>
C4_CONSTEXPR14 C4_CONST auto ipow(B base, E exponent) noexcept -> typename std::enable_if<std::is_signed<E>::value, B>::type
{
    C4_STATIC_ASSERT(std::is_integral<E>::value);
    B r = B(1);
    if(exponent >= 0)
    {
        for(E e = 0; e < exponent; ++e)
            r *= base;
    }
    else
    {
        exponent *= E(-1);
        for(E e = 0; e < exponent; ++e)
            r /= base;
    }
    return r;
}

/** integer power; this function is constexpr-14 because of the local
 * variables */
template<class B, B base, class E>
C4_CONSTEXPR14 C4_CONST auto ipow(E exponent) noexcept -> typename std::enable_if<std::is_signed<E>::value, B>::type
{
    C4_STATIC_ASSERT(std::is_integral<E>::value);
    B r = B(1);
    if(exponent >= 0)
    {
        for(E e = 0; e < exponent; ++e)
            r *= base;
    }
    else
    {
        exponent *= E(-1);
        for(E e = 0; e < exponent; ++e)
            r /= base;
    }
    return r;
}

/** integer power; this function is constexpr-14 because of the local
 * variables */
template<class B, class Base, Base base, class E>
C4_CONSTEXPR14 C4_CONST auto ipow(E exponent) noexcept -> typename std::enable_if<std::is_signed<E>::value, B>::type
{
    C4_STATIC_ASSERT(std::is_integral<E>::value);
    B r = B(1);
    B bbase = B(base);
    if(exponent >= 0)
    {
        for(E e = 0; e < exponent; ++e)
            r *= bbase;
    }
    else
    {
        exponent *= E(-1);
        for(E e = 0; e < exponent; ++e)
            r /= bbase;
    }
    return r;
}

/** integer power; this function is constexpr-14 because of the local
 * variables */
template<class B, class E>
C4_CONSTEXPR14 C4_CONST auto ipow(B base, E exponent) noexcept -> typename std::enable_if<!std::is_signed<E>::value, B>::type
{
    C4_STATIC_ASSERT(std::is_integral<E>::value);
    B r = B(1);
    for(E e = 0; e < exponent; ++e)
        r *= base;
    return r;
}

/** integer power; this function is constexpr-14 because of the local
 * variables */
template<class B, B base, class E>
C4_CONSTEXPR14 C4_CONST auto ipow(E exponent) noexcept -> typename std::enable_if<!std::is_signed<E>::value, B>::type
{
    C4_STATIC_ASSERT(std::is_integral<E>::value);
    B r = B(1);
    for(E e = 0; e < exponent; ++e)
        r *= base;
    return r;
}
/** integer power; this function is constexpr-14 because of the local
 * variables */
template<class B, class Base, Base base, class E>
C4_CONSTEXPR14 C4_CONST auto ipow(E exponent) noexcept -> typename std::enable_if<!std::is_signed<E>::value, B>::type
{
    C4_STATIC_ASSERT(std::is_integral<E>::value);
    B r = B(1);
    B bbase = B(base);
    for(E e = 0; e < exponent; ++e)
        r *= bbase;
    return r;
}

C4_SUPPRESS_WARNING_GCC_CLANG_POP


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** return a mask with all bits set [first_bit,last_bit[; this function
 * is constexpr-14 because of the local variables */
template<class I>
C4_CONSTEXPR14 I contiguous_mask(I first_bit, I last_bit)
{
    I r = 0;
    for(I i = first_bit; i < last_bit; ++i)
    {
        r |= (I(1) << i);
    }
    return r;
}


namespace detail {

template<class I, I val, I first, I last, bool finished>
struct _ctgmsk11;

template<class I, I val, I first, I last>
struct _ctgmsk11< I, val, first, last, true>
{
    enum : I { value = _ctgmsk11<I, val|(I(1)<<first), first+I(1), last, (first+1!=last)>::value };
};

template<class I, I val, I first, I last>
struct _ctgmsk11< I, val, first, last, false>
{
    enum : I { value = val };
};

} // namespace detail


/** TMP version of contiguous_mask(); this needs to be implemented with template
 * meta-programming because C++11 cannot use a constexpr function with
 * local variables
 * @see contiguous_mask */
template<class I, I first_bit, I last_bit>
struct contiguous_mask11
{
    enum : I { value = detail::_ctgmsk11<I, I(0), first_bit, last_bit, (first_bit!=last_bit)>::value };
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** use Empty Base Class Optimization to reduce the size of a pair of
 * potentially empty types*/

namespace detail {
typedef enum {
    tpc_same,
    tpc_same_empty,
    tpc_both_empty,
    tpc_first_empty,
    tpc_second_empty,
    tpc_general
} TightPairCase_e;

template<class First, class Second>
constexpr TightPairCase_e tpc_which_case()
{
    return std::is_same<First, Second>::value ?
               std::is_empty<First>::value ?
                   tpc_same_empty
                   :
                   tpc_same
               :
               std::is_empty<First>::value && std::is_empty<Second>::value ?
                   tpc_both_empty
                   :
                   std::is_empty<First>::value ?
                       tpc_first_empty
                       :
                       std::is_empty<Second>::value ?
                           tpc_second_empty
                           :
                           tpc_general
           ;
}

template<class First, class Second, TightPairCase_e Case>
struct tight_pair
{
private:

    First m_first;
    Second m_second;

public:

    using first_type = First;
    using second_type = Second;

    tight_pair() : m_first(), m_second() {}
    tight_pair(First const& f, Second const& s) : m_first(f), m_second(s) {}

    C4_ALWAYS_INLINE C4_CONSTEXPR14 First       & first ()       { return m_first; }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 First  const& first () const { return m_first; }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second      & second()       { return m_second; }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second const& second() const { return m_second; }
};

template<class First, class Second>
struct tight_pair<First, Second, tpc_same_empty> : public First
{
    static_assert(std::is_same<First, Second>::value, "bad implementation");

    using first_type = First;
    using second_type = Second;

    tight_pair() : First() {}
    tight_pair(First const& f, Second const& /*s*/) : First(f) {}

    C4_ALWAYS_INLINE C4_CONSTEXPR14 First      & first ()       { return static_cast<First      &>(*this); }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 First const& first () const { return static_cast<First const&>(*this); }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second      & second()       { return reinterpret_cast<Second      &>(*this); }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second const& second() const { return reinterpret_cast<Second const&>(*this); }
};

template<class First, class Second>
struct tight_pair<First, Second, tpc_both_empty> : public First, public Second
{
    using first_type = First;
    using second_type = Second;

    tight_pair() : First(), Second() {}
    tight_pair(First const& f, Second const& s) : First(f), Second(s) {}

    C4_ALWAYS_INLINE C4_CONSTEXPR14 First      & first ()       { return static_cast<First      &>(*this); }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 First const& first () const { return static_cast<First const&>(*this); }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second      & second()       { return static_cast<Second      &>(*this); }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second const& second() const { return static_cast<Second const&>(*this); }
};

template<class First, class Second>
struct tight_pair<First, Second, tpc_same> : public First
{
    Second m_second;

    using first_type = First;
    using second_type = Second;

    tight_pair() : First() {}
    tight_pair(First const& f, Second const& s) : First(f), m_second(s) {}

    C4_ALWAYS_INLINE C4_CONSTEXPR14 First      & first ()       { return static_cast<First      &>(*this); }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 First const& first () const { return static_cast<First const&>(*this); }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second      & second()       { return m_second; }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second const& second() const { return m_second; }
};

template<class First, class Second>
struct tight_pair<First, Second, tpc_first_empty> : public First
{
    Second m_second;

    using first_type = First;
    using second_type = Second;

    tight_pair() : First(), m_second() {}
    tight_pair(First const& f, Second const& s) : First(f), m_second(s) {}

    C4_ALWAYS_INLINE C4_CONSTEXPR14 First      & first ()       { return static_cast<First      &>(*this); }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 First const& first () const { return static_cast<First const&>(*this); }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second      & second()       { return m_second; }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second const& second() const { return m_second; }
};

template<class First, class Second>
struct tight_pair<First, Second, tpc_second_empty> : public Second
{
    First m_first;

    using first_type = First;
    using second_type = Second;

    tight_pair() : Second(), m_first() {}
    tight_pair(First const& f, Second const& s) : Second(s), m_first(f) {}

    C4_ALWAYS_INLINE C4_CONSTEXPR14 First      & first ()       { return m_first; }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 First const& first () const { return m_first; }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second      & second()       { return static_cast<Second      &>(*this); }
    C4_ALWAYS_INLINE C4_CONSTEXPR14 Second const& second() const { return static_cast<Second const&>(*this); }
};

} // namespace detail

template<class First, class Second>
using tight_pair = detail::tight_pair<First, Second, detail::tpc_which_case<First,Second>()>;

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace c4

#endif /* _C4_MEMORY_UTIL_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/memory_util.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/memory_resource.hpp
// https://github.com/biojppm/c4core/src/c4/memory_resource.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_MEMORY_RESOURCE_HPP_
#define _C4_MEMORY_RESOURCE_HPP_

/** @file memory_resource.hpp Provides facilities to allocate typeless
 *  memory, via the memory resource model consecrated with C++17. */

/** @defgroup memory memory utilities */

/** @defgroup raw_memory_alloc Raw memory allocation
 * @ingroup memory
 */

/** @defgroup memory_resources Memory resources
 * @ingroup memory
 */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/config.hpp
//#include "c4/config.hpp"
#if !defined(C4_CONFIG_HPP_) && !defined(_C4_CONFIG_HPP_)
#error "amalgamate: file c4/config.hpp must have been included at this point"
#endif /* C4_CONFIG_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */


namespace c4 {

// need these forward decls here
struct MemoryResource;
struct MemoryResourceMalloc;
struct MemoryResourceStack;
MemoryResourceMalloc* get_memory_resource_malloc();
MemoryResourceStack* get_memory_resource_stack();
namespace detail { MemoryResource*& get_memory_resource(); }


// c-style allocation ---------------------------------------------------------

// this API provides aligned allocation functions.
// These functions forward the call to a user-modifiable function.


// aligned allocation.

/** Aligned allocation. Merely calls the current get_aalloc() function.
 * @see get_aalloc()
 * @ingroup raw_memory_alloc */
void* aalloc(size_t sz, size_t alignment);

/** Aligned free. Merely calls the current get_afree() function.
 * @see get_afree()
 * @ingroup raw_memory_alloc */
void afree(void* ptr);

/** Aligned reallocation. Merely calls the current get_arealloc() function.
 * @see get_arealloc()
 * @ingroup raw_memory_alloc */
void* arealloc(void* ptr, size_t oldsz, size_t newsz, size_t alignment);


// allocation setup facilities.

/** Function pointer type for aligned allocation
 * @see set_aalloc()
 * @ingroup raw_memory_alloc */
using aalloc_pfn = void* (*)(size_t size, size_t alignment);

/** Function pointer type for aligned deallocation
 * @see set_afree()
 * @ingroup raw_memory_alloc */
using afree_pfn = void  (*)(void *ptr);

/** Function pointer type for aligned reallocation
 * @see set_arealloc()
 * @ingroup raw_memory_alloc */
using arealloc_pfn = void* (*)(void *ptr, size_t oldsz, size_t newsz, size_t alignment);


// allocation function pointer setters/getters

/** Set the global aligned allocation function.
 * @see aalloc()
 * @see get_aalloc()
 * @ingroup raw_memory_alloc */
void set_aalloc(aalloc_pfn fn);

/** Set the global aligned deallocation function.
 * @see afree()
 * @see get_afree()
 * @ingroup raw_memory_alloc */
void set_afree(afree_pfn fn);

/** Set the global aligned reallocation function.
 * @see arealloc()
 * @see get_arealloc()
 * @ingroup raw_memory_alloc */
void set_arealloc(arealloc_pfn fn);


/** Get the global aligned reallocation function.
 * @see arealloc()
 * @ingroup raw_memory_alloc */
aalloc_pfn get_aalloc();

/** Get the global aligned deallocation function.
 * @see afree()
 * @ingroup raw_memory_alloc */
afree_pfn get_afree();

/** Get the global aligned reallocation function.
 * @see arealloc()
 * @ingroup raw_memory_alloc */
arealloc_pfn get_arealloc();


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// c++-style allocation -------------------------------------------------------

/** C++17-style memory_resource base class. See http://en.cppreference.com/w/cpp/experimental/memory_resource
 * @ingroup memory_resources */
struct MemoryResource
{
    const char *name = nullptr;
    virtual ~MemoryResource() {}

    void* allocate(size_t sz, size_t alignment=alignof(max_align_t), void *hint=nullptr)
    {
        void *mem = this->do_allocate(sz, alignment, hint);
        C4_CHECK_MSG(mem != nullptr, "could not allocate %lu bytes", sz);
        return mem;
    }

    void* reallocate(void* ptr, size_t oldsz, size_t newsz, size_t alignment=alignof(max_align_t))
    {
        void *mem = this->do_reallocate(ptr, oldsz, newsz, alignment);
        C4_CHECK_MSG(mem != nullptr, "could not reallocate from %lu to %lu bytes", oldsz, newsz);
        return mem;
    }

    void deallocate(void* ptr, size_t sz, size_t alignment=alignof(max_align_t))
    {
        this->do_deallocate(ptr, sz, alignment);
    }

protected:

    virtual void* do_allocate(size_t sz, size_t alignment, void* hint) = 0;
    virtual void* do_reallocate(void* ptr, size_t oldsz, size_t newsz, size_t alignment) = 0;
    virtual void  do_deallocate(void* ptr, size_t sz, size_t alignment) = 0;

};

/** get the current global memory resource. To avoid static initialization
 * order problems, this is implemented using a function call to ensure
 * that it is available when first used.
 * @ingroup memory_resources */
C4_ALWAYS_INLINE MemoryResource* get_memory_resource()
{
    return detail::get_memory_resource();
}

/** set the global memory resource
 * @ingroup memory_resources */
C4_ALWAYS_INLINE void set_memory_resource(MemoryResource* mr)
{
    C4_ASSERT(mr != nullptr);
    detail::get_memory_resource() = mr;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** A c4::aalloc-based memory resource. Thread-safe if the implementation
 * called by c4::aalloc() is safe.
 * @ingroup memory_resources */
struct MemoryResourceMalloc : public MemoryResource
{

    MemoryResourceMalloc() { name = "malloc"; }
    virtual ~MemoryResourceMalloc() override {}

protected:

    virtual void* do_allocate(size_t sz, size_t alignment, void *hint) override
    {
        C4_UNUSED(hint);
        return c4::aalloc(sz, alignment);
    }

    virtual void  do_deallocate(void* ptr, size_t sz, size_t alignment) override
    {
        C4_UNUSED(sz);
        C4_UNUSED(alignment);
        c4::afree(ptr);
    }

    virtual void* do_reallocate(void* ptr, size_t oldsz, size_t newsz, size_t alignment) override
    {
        return c4::arealloc(ptr, oldsz, newsz, alignment);
    }

};

/** returns a malloc-based memory resource
 * @ingroup memory_resources */
C4_ALWAYS_INLINE MemoryResourceMalloc* get_memory_resource_malloc()
{
    /** @todo use a nifty counter:
     * https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Nifty_Counter */
    static MemoryResourceMalloc mr;
    return &mr;
}

namespace detail {
C4_ALWAYS_INLINE MemoryResource* & get_memory_resource()
{
    /** @todo use a nifty counter:
     * https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Nifty_Counter */
    thread_local static MemoryResource* mr = get_memory_resource_malloc();
    return mr;
}
} // namespace detail


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

namespace detail {

/** Allows a memory resource to obtain its memory from another memory resource.
 * @ingroup memory_resources */
struct DerivedMemoryResource : public MemoryResource
{
public:

    DerivedMemoryResource(MemoryResource *mr_=nullptr) : m_local(mr_ ? mr_ : get_memory_resource()) {}

private:

    MemoryResource *m_local;

protected:

    virtual void* do_allocate(size_t sz, size_t alignment, void* hint) override
    {
        return m_local->allocate(sz, alignment, hint);
    }

    virtual void* do_reallocate(void* ptr, size_t oldsz, size_t newsz, size_t alignment) override
    {
        return m_local->reallocate(ptr, oldsz, newsz, alignment);
    }

    virtual void do_deallocate(void* ptr, size_t sz, size_t alignment) override
    {
        return m_local->deallocate(ptr, sz, alignment);
    }
};

/** Provides common facilities for memory resource consisting of a single memory block
 * @ingroup memory_resources */
struct _MemoryResourceSingleChunk : public DerivedMemoryResource
{

    C4_NO_COPY_OR_MOVE(_MemoryResourceSingleChunk);

    using impl_type = DerivedMemoryResource;

public:

    _MemoryResourceSingleChunk(MemoryResource *impl=nullptr) : DerivedMemoryResource(impl) { name = "linear_malloc"; }

    /** initialize with owned memory, allocated from the given (or the global) memory resource */
    _MemoryResourceSingleChunk(size_t sz, MemoryResource *impl=nullptr) : _MemoryResourceSingleChunk(impl) { acquire(sz); }
    /** initialize with borrowed memory */
    _MemoryResourceSingleChunk(void *mem, size_t sz) : _MemoryResourceSingleChunk() { acquire(mem, sz); }

    virtual ~_MemoryResourceSingleChunk() override { release(); }

public:

    void const* mem() const { return m_mem; }

    size_t capacity() const { return m_size; }
    size_t size() const { return m_pos; }
    size_t slack() const { C4_ASSERT(m_size >= m_pos); return m_size - m_pos; }

public:

    char  *m_mem{nullptr};
    size_t m_size{0};
    size_t m_pos{0};
    bool   m_owner;

public:

    /** set the internal pointer to the beginning of the linear buffer */
    void clear() { m_pos = 0; }

    /** initialize with owned memory, allocated from the global memory resource */
    void acquire(size_t sz);
    /** initialize with borrowed memory */
    void acquire(void *mem, size_t sz);
    /** release the memory */
    void release();

};

} // namespace detail


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** provides a linear memory resource. Allocates incrementally from a linear
 * buffer, without ever deallocating. Deallocations are a no-op, and the
 * memory is freed only when the resource is release()d. The memory used by
 * this object can be either owned or borrowed. When borrowed, no calls to
 * malloc/free take place.
 *
 * @ingroup memory_resources */
struct MemoryResourceLinear : public detail::_MemoryResourceSingleChunk
{

    C4_NO_COPY_OR_MOVE(MemoryResourceLinear);

public:

    using detail::_MemoryResourceSingleChunk::_MemoryResourceSingleChunk;

protected:

    virtual void* do_allocate(size_t sz, size_t alignment, void *hint) override;
    virtual void  do_deallocate(void* ptr, size_t sz, size_t alignment) override;
    virtual void* do_reallocate(void* ptr, size_t oldsz, size_t newsz, size_t alignment) override;
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** provides a stack-type malloc-based memory resource.
 * @ingroup memory_resources */
struct MemoryResourceStack : public detail::_MemoryResourceSingleChunk
{

    C4_NO_COPY_OR_MOVE(MemoryResourceStack);

public:

    using detail::_MemoryResourceSingleChunk::_MemoryResourceSingleChunk;

protected:

    virtual void* do_allocate(size_t sz, size_t alignment, void *hint) override;
    virtual void  do_deallocate(void* ptr, size_t sz, size_t alignment) override;
    virtual void* do_reallocate(void* ptr, size_t oldsz, size_t newsz, size_t alignment) override;
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** provides a linear array-based memory resource.
 * @see MemoryResourceLinear
 * @ingroup memory_resources */
template<size_t N>
struct MemoryResourceLinearArr : public MemoryResourceLinear
{
    #ifdef _MSC_VER
    #pragma warning(push)
    #pragma warning(disable: 4324) // structure was padded due to alignment specifier
    #endif
    alignas(alignof(max_align_t)) char m_arr[N];
    #ifdef _MSC_VER
    #pragma warning(pop)
    #endif
    MemoryResourceLinearArr() : MemoryResourceLinear(m_arr, N) { name = "linear_arr"; }
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
struct AllocationCounts
{
    struct Item
    {
        ssize_t allocs;
        ssize_t size;

        void add(size_t sz)
        {
            ++allocs;
            size += static_cast<ssize_t>(sz);
        }
        void rem(size_t sz)
        {
            --allocs;
            size -= static_cast<ssize_t>(sz);
        }
        Item max(Item const& that) const
        {
            Item r(*this);
            r.allocs = r.allocs > that.allocs ? r.allocs : that.allocs;
            r.size = r.size > that.size ? r.size : that.size;
            return r;
        }
    };

    Item curr  = {0, 0};
    Item total = {0, 0};
    Item max   = {0, 0};

    void clear_counts()
    {
        curr  = {0, 0};
        total = {0, 0};
        max   = {0, 0};
    }

    void update(AllocationCounts const& that)
    {
        curr.allocs += that.curr.allocs;
        curr.size += that.curr.size;
        total.allocs += that.total.allocs;
        total.size += that.total.size;
        max.allocs += that.max.allocs;
        max.size += that.max.size;
    }

    void add_counts(void* ptr, size_t sz)
    {
        if(ptr == nullptr) return;
        curr.add(sz);
        total.add(sz);
        max = max.max(curr);
    }

    void rem_counts(void *ptr, size_t sz)
    {
        if(ptr == nullptr) return;
        curr.rem(sz);
    }

    AllocationCounts operator- (AllocationCounts const& that) const
    {
        AllocationCounts r(*this);
        r.curr.allocs -= that.curr.allocs;
        r.curr.size -= that.curr.size;
        r.total.allocs -= that.total.allocs;
        r.total.size -= that.total.size;
        r.max.allocs -= that.max.allocs;
        r.max.size -= that.max.size;
        return r;
    }

    AllocationCounts operator+ (AllocationCounts const& that) const
    {
        AllocationCounts r(*this);
        r.curr.allocs += that.curr.allocs;
        r.curr.size += that.curr.size;
        r.total.allocs += that.total.allocs;
        r.total.size += that.total.size;
        r.max.allocs += that.max.allocs;
        r.max.size += that.max.size;
        return r;
    }
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** a MemoryResource which latches onto another MemoryResource
 * and counts allocations and sizes.
 * @ingroup memory_resources */
class MemoryResourceCounts : public MemoryResource
{
public:

    MemoryResourceCounts() : m_resource(get_memory_resource())
    {
        C4_ASSERT(m_resource != this);
        name = "MemoryResourceCounts";
    }
    MemoryResourceCounts(MemoryResource *res) : m_resource(res)
    {
        C4_ASSERT(m_resource != this);
        name = "MemoryResourceCounts";
    }

    MemoryResource *resource() { return m_resource; }
    AllocationCounts const& counts() const { return m_counts; }

protected:

    MemoryResource *m_resource;
    AllocationCounts m_counts;

protected:

    virtual void* do_allocate(size_t sz, size_t alignment, void * /*hint*/) override
    {
        void *ptr = m_resource->allocate(sz, alignment);
        m_counts.add_counts(ptr, sz);
        return ptr;
    }

    virtual void  do_deallocate(void* ptr, size_t sz, size_t alignment) override
    {
        m_counts.rem_counts(ptr, sz);
        m_resource->deallocate(ptr, sz, alignment);
    }

    virtual void* do_reallocate(void* ptr, size_t oldsz, size_t newsz, size_t alignment) override
    {
        m_counts.rem_counts(ptr, oldsz);
        void* nptr = m_resource->reallocate(ptr, oldsz, newsz, alignment);
        m_counts.add_counts(nptr, newsz);
        return nptr;
    }

};

//-----------------------------------------------------------------------------
/** RAII class which binds a memory resource with a scope duration.
 * @ingroup memory_resources */
struct ScopedMemoryResource
{
    MemoryResource *m_original;

    ScopedMemoryResource(MemoryResource *r)
    :
        m_original(get_memory_resource())
    {
        set_memory_resource(r);
    }

    ~ScopedMemoryResource()
    {
        set_memory_resource(m_original);
    }
};

//-----------------------------------------------------------------------------
/** RAII class which counts allocations and frees inside a scope. Can
 * optionally set also the memory resource to be used.
 * @ingroup memory_resources */
struct ScopedMemoryResourceCounts
{
    MemoryResourceCounts mr;

    ScopedMemoryResourceCounts() : mr()
    {
        set_memory_resource(&mr);
    }
    ScopedMemoryResourceCounts(MemoryResource *m) : mr(m)
    {
        set_memory_resource(&mr);
    }
    ~ScopedMemoryResourceCounts()
    {
        set_memory_resource(mr.resource());
    }
};

} // namespace c4

#endif /* _C4_MEMORY_RESOURCE_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/memory_resource.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/ctor_dtor.hpp
// https://github.com/biojppm/c4core/src/c4/ctor_dtor.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_CTOR_DTOR_HPP_
#define _C4_CTOR_DTOR_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/preprocessor.hpp
//#include "c4/preprocessor.hpp"
#if !defined(C4_PREPROCESSOR_HPP_) && !defined(_C4_PREPROCESSOR_HPP_)
#error "amalgamate: file c4/preprocessor.hpp must have been included at this point"
#endif /* C4_PREPROCESSOR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/language.hpp
//#include "c4/language.hpp"
#if !defined(C4_LANGUAGE_HPP_) && !defined(_C4_LANGUAGE_HPP_)
#error "amalgamate: file c4/language.hpp must have been included at this point"
#endif /* C4_LANGUAGE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/memory_util.hpp
//#include "c4/memory_util.hpp"
#if !defined(C4_MEMORY_UTIL_HPP_) && !defined(_C4_MEMORY_UTIL_HPP_)
#error "amalgamate: file c4/memory_util.hpp must have been included at this point"
#endif /* C4_MEMORY_UTIL_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */


//included above:
//#include <type_traits>
//included above:
//#include <utility> // std::forward

/** @file ctor_dtor.hpp object construction and destruction facilities.
 * Some of these are not yet available in C++11. */

namespace c4 {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")

/** default-construct an object, trivial version */
template <class U> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_default_constructible<U>::value, void>::type
construct(U *ptr) noexcept
{
    memset(ptr, 0, sizeof(U));
}
/** default-construct an object, non-trivial version */
template<class U> C4_ALWAYS_INLINE typename std ::enable_if< ! std::is_trivially_default_constructible<U>::value, void>::type
construct(U* ptr) noexcept
{
    new ((void*)ptr) U();
}

/** default-construct n objects, trivial version */
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_default_constructible<U>::value, void>::type
construct_n(U* ptr, I n) noexcept
{
    memset(ptr, 0, n * sizeof(U));
}
/** default-construct n objects, non-trivial version */
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_default_constructible<U>::value, void>::type
construct_n(U* ptr, I n) noexcept
{
    for(I i = 0; i < n; ++i)
    {
        new ((void*)(ptr + i)) U();
    }
}

#ifdef __clang__
#   pragma clang diagnostic push
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   if __GNUC__ >= 6
#       pragma GCC diagnostic ignored "-Wnull-dereference"
#   endif
#endif

template<class U, class ...Args>
inline void construct(U* ptr, Args&&... args)
{
    new ((void*)ptr) U(std::forward<Args>(args)...);
}
template<class U, class I, class ...Args>
inline void construct_n(U* ptr, I n, Args&&... args)
{
    for(I i = 0; i < n; ++i)
    {
        new ((void*)(ptr + i)) U(args...);
    }
}

#ifdef __clang__
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif


//-----------------------------------------------------------------------------
// copy-construct

template<class U> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_copy_constructible<U>::value, void>::type
copy_construct(U* dst, U const* src) noexcept
{
    C4_ASSERT(dst != src);
    memcpy(dst, src, sizeof(U));
}
template<class U> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_copy_constructible<U>::value, void>::type
copy_construct(U* dst, U const* src)
{
    C4_ASSERT(dst != src);
    new ((void*)dst) U(*src);
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_copy_constructible<U>::value, void>::type
copy_construct_n(U* dst, U const* src, I n) noexcept
{
    C4_ASSERT(dst != src);
    memcpy(dst, src, n * sizeof(U));
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_copy_constructible<U>::value, void>::type
copy_construct_n(U* dst, U const* src, I n)
{
    C4_ASSERT(dst != src);
    for(I i = 0; i < n; ++i)
    {
        new ((void*)(dst + i)) U(*(src + i));
    }
}

template<class U> C4_ALWAYS_INLINE typename std::enable_if<std::is_scalar<U>::value, void>::type
copy_construct(U* dst, U src) noexcept // pass by value for scalar types
{
    *dst = src;
}
template<class U> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_scalar<U>::value, void>::type
copy_construct(U* dst, U const& src) // pass by reference for non-scalar types
{
    C4_ASSERT(dst != &src);
    new ((void*)dst) U(src);
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_scalar<U>::value, void>::type
copy_construct_n(U* dst, U src, I n) noexcept // pass by value for scalar types
{
    for(I i = 0; i < n; ++i)
    {
        dst[i] = src;
    }
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_scalar<U>::value, void>::type
copy_construct_n(U* dst, U const& src, I n) // pass by reference for non-scalar types
{
    C4_ASSERT(dst != &src);
    for(I i = 0; i < n; ++i)
    {
        new ((void*)(dst + i)) U(src);
    }
}

template<class U, size_t N>
C4_ALWAYS_INLINE void copy_construct(U (&dst)[N], U const (&src)[N]) noexcept
{
    copy_construct_n(dst, src, N);
}

//-----------------------------------------------------------------------------
// copy-assign

template<class U> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_copy_assignable<U>::value, void>::type
copy_assign(U* dst, U const* src) noexcept
{
    C4_ASSERT(dst != src);
    memcpy(dst, src, sizeof(U));
}
template<class U> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_copy_assignable<U>::value, void>::type
copy_assign(U* dst, U const* src) noexcept
{
    C4_ASSERT(dst != src);
    *dst = *src;
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_copy_assignable<U>::value, void>::type
copy_assign_n(U* dst, U const* src, I n) noexcept
{
    C4_ASSERT(dst != src);
    memcpy(dst, src, n * sizeof(U));
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_copy_assignable<U>::value, void>::type
copy_assign_n(U* dst, U const* src, I n) noexcept
{
    C4_ASSERT(dst != src);
    for(I i = 0; i < n; ++i)
    {
        dst[i] = src[i];
    }
}

template<class U> C4_ALWAYS_INLINE typename std::enable_if<std::is_scalar<U>::value, void>::type
copy_assign(U* dst, U src) noexcept // pass by value for scalar types
{
    *dst = src;
}
template<class U> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_scalar<U>::value, void>::type
copy_assign(U* dst, U const& src) noexcept // pass by reference for non-scalar types
{
    C4_ASSERT(dst != &src);
    *dst = src;
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_scalar<U>::value, void>::type
copy_assign_n(U* dst, U src, I n) noexcept // pass by value for scalar types
{
    for(I i = 0; i < n; ++i)
    {
        dst[i] = src;
    }
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_scalar<U>::value, void>::type
copy_assign_n(U* dst, U const& src, I n) noexcept // pass by reference for non-scalar types
{
    C4_ASSERT(dst != &src);
    for(I i = 0; i < n; ++i)
    {
        dst[i] = src;
    }
}

template<class U, size_t N>
C4_ALWAYS_INLINE void copy_assign(U (&dst)[N], U const (&src)[N]) noexcept
{
    copy_assign_n(dst, src, N);
}

//-----------------------------------------------------------------------------
// move-construct

template<class U> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_move_constructible<U>::value, void>::type
move_construct(U* dst, U* src) noexcept
{
    C4_ASSERT(dst != src);
    memcpy(dst, src, sizeof(U));
}
template<class U> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_move_constructible<U>::value, void>::type
move_construct(U* dst, U* src) noexcept
{
    C4_ASSERT(dst != src);
    new ((void*)dst) U(std::move(*src));
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_move_constructible<U>::value, void>::type
move_construct_n(U* dst, U* src, I n) noexcept
{
    C4_ASSERT(dst != src);
    memcpy(dst, src, n * sizeof(U));
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_move_constructible<U>::value, void>::type
move_construct_n(U* dst, U* src, I n) noexcept
{
    C4_ASSERT(dst != src);
    for(I i = 0; i < n; ++i)
    {
        new ((void*)(dst + i)) U(std::move(src[i]));
    }
}

//-----------------------------------------------------------------------------
// move-assign

template<class U> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_move_assignable<U>::value, void>::type
move_assign(U* dst, U* src) noexcept
{
    C4_ASSERT(dst != src);
    memcpy(dst, src, sizeof(U));
}
template<class U> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_move_assignable<U>::value, void>::type
move_assign(U* dst, U* src) noexcept
{
    C4_ASSERT(dst != src);
    *dst = std::move(*src);
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_move_assignable<U>::value, void>::type
move_assign_n(U* dst, U* src, I n) noexcept
{
    C4_ASSERT(dst != src);
    memcpy(dst, src, n * sizeof(U));
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_move_assignable<U>::value, void>::type
move_assign_n(U* dst, U* src, I n) noexcept
{
    C4_ASSERT(dst != src);
    for(I i = 0; i < n; ++i)
    {
        *(dst + i) = std::move(*(src + i));
    }
}

//-----------------------------------------------------------------------------
// destroy

template<class U> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_destructible<U>::value, void>::type
destroy(U* ptr) noexcept
{
    C4_UNUSED(ptr); // nothing to do
}
template<class U> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_destructible<U>::value, void>::type
destroy(U* ptr) noexcept
{
    ptr->~U();
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_destructible<U>::value, void>::type
destroy_n(U* ptr, I n) noexcept
{
    C4_UNUSED(ptr);
    C4_UNUSED(n); // nothing to do
}
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_destructible<U>::value, void>::type
destroy_n(U* ptr, I n) noexcept
{
    for(I i = 0; i <n; ++i)
    {
        ptr[i].~U();
    }
}

//-----------------------------------------------------------------------------

/** makes room at the beginning of buf, which has a current size of n */
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_move_constructible<U>::value, void>::type
make_room(U *buf, I bufsz, I room) C4_NOEXCEPT_A
{
    C4_ASSERT(bufsz >= 0 && room >= 0);
    if(room >= bufsz)
    {
        memcpy (buf + room, buf, bufsz * sizeof(U));
    }
    else
    {
        memmove(buf + room, buf, bufsz * sizeof(U));
    }
}
/** makes room at the beginning of buf, which has a current size of bufsz */
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_move_constructible<U>::value, void>::type
make_room(U *buf, I bufsz, I room) C4_NOEXCEPT_A
{
    C4_ASSERT(bufsz >= 0 && room >= 0);
    if(room >= bufsz)
    {
        for(I i = 0; i < bufsz; ++i)
        {
            new ((void*)(buf + (i + room))) U(std::move(buf[i]));
        }
    }
    else
    {
        for(I i = 0; i < bufsz; ++i)
        {
            I w = bufsz-1 - i; // do a backwards loop
            new ((void*)(buf + (w + room))) U(std::move(buf[w]));
        }
    }
}

/** make room to the right of pos */
template<class U, class I>
C4_ALWAYS_INLINE void make_room(U *buf, I bufsz, I currsz, I pos, I room)
{
    C4_ASSERT(pos >= 0 && pos <= currsz);
    C4_ASSERT(currsz <= bufsz);
    C4_ASSERT(room + currsz <= bufsz);
    C4_UNUSED(bufsz);
    make_room(buf + pos, currsz - pos, room);
}


/** make room to the right of pos, copying to the beginning of a different buffer */
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_move_constructible<U>::value, void>::type
make_room(U *dst, U const* src, I srcsz, I room, I pos) C4_NOEXCEPT_A
{
    C4_ASSERT(srcsz >= 0 && room >= 0 && pos >= 0);
    C4_ASSERT(pos < srcsz || (pos == 0 && srcsz == 0));
    memcpy(dst             , src      , pos           * sizeof(U));
    memcpy(dst + room + pos, src + pos, (srcsz - pos) * sizeof(U));
}
/** make room to the right of pos, copying to the beginning of a different buffer */
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_move_constructible<U>::value, void>::type
make_room(U *dst, U const* src, I srcsz, I room, I pos)
{
    C4_ASSERT(srcsz >= 0 && room >= 0 && pos >= 0);
    C4_ASSERT(pos < srcsz || (pos == 0 && srcsz == 0));
    for(I i = 0; i < pos; ++i)
    {
        new ((void*)(dst + i)) U(std::move(src[i]));
    }
    src += pos;
    dst += room + pos;
    for(I i = 0, e = srcsz - pos; i < e; ++i)
    {
        new ((void*)(dst + i)) U(std::move(src[i]));
    }
}

template<class U, class I>
C4_ALWAYS_INLINE void make_room
(
    U      * dst, I dstsz,
    U const* src, I srcsz,
    I room, I pos
)
{
    C4_ASSERT(pos >= 0 && pos < srcsz || (srcsz == 0 && pos == 0));
    C4_ASSERT(pos >= 0 && pos < dstsz || (dstsz == 0 && pos == 0));
    C4_ASSERT(srcsz+room <= dstsz);
    C4_UNUSED(dstsz);
    make_room(dst, src, srcsz, room, pos);
}


//-----------------------------------------------------------------------------
/** destroy room at the beginning of buf, which has a current size of n */
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_scalar<U>::value || (std::is_standard_layout<U>::value && std::is_trivial<U>::value), void>::type
destroy_room(U *buf, I n, I room) C4_NOEXCEPT_A
{
    C4_ASSERT(n >= 0 && room >= 0);
    C4_ASSERT(room <= n);
    if(room < n)
    {
        memmove(buf, buf + room, (n - room) * sizeof(U));
    }
    else
    {
        // nothing to do - no need to destroy scalar types
    }
}
/** destroy room at the beginning of buf, which has a current size of n */
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! (std::is_scalar<U>::value || (std::is_standard_layout<U>::value && std::is_trivial<U>::value)), void>::type
destroy_room(U *buf, I n, I room)
{
    C4_ASSERT(n >= 0 && room >= 0);
    C4_ASSERT(room <= n);
    if(room < n)
    {
        for(I i = 0, e = n - room; i < e; ++i)
        {
            buf[i] = std::move(buf[i + room]);
        }
    }
    else
    {
        for(I i = 0; i < n; ++i)
        {
            buf[i].~U();
        }
    }
}

/** destroy room to the right of pos, copying to a different buffer */
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if<std::is_trivially_move_constructible<U>::value, void>::type
destroy_room(U *dst, U const* src, I n, I room, I pos) C4_NOEXCEPT_A
{
    C4_ASSERT(n >= 0 && room >= 0 && pos >= 0);
    C4_ASSERT(pos <n);
    C4_ASSERT(pos + room <= n);
    memcpy(dst, src, pos * sizeof(U));
    memcpy(dst + pos, src + room + pos, (n - pos - room) * sizeof(U));
}
/** destroy room to the right of pos, copying to a different buffer */
template<class U, class I> C4_ALWAYS_INLINE typename std::enable_if< ! std::is_trivially_move_constructible<U>::value, void>::type
destroy_room(U *dst, U const* src, I n, I room, I pos)
{
    C4_ASSERT(n >= 0 && room >= 0 && pos >= 0);
    C4_ASSERT(pos < n);
    C4_ASSERT(pos + room <= n);
    for(I i = 0; i < pos; ++i)
    {
        new ((void*)(dst + i)) U(std::move(src[i]));
    }
    src += room + pos;
    dst += pos;
    for(I i = 0, e = n - pos - room; i < e; ++i)
    {
        new ((void*)(dst + i)) U(std::move(src[i]));
    }
}

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace c4

#endif /* _C4_CTOR_DTOR_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/ctor_dtor.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/allocator.hpp
// https://github.com/biojppm/c4core/src/c4/allocator.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_ALLOCATOR_HPP_
#define _C4_ALLOCATOR_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/memory_resource.hpp
//#include "c4/memory_resource.hpp"
#if !defined(C4_MEMORY_RESOURCE_HPP_) && !defined(_C4_MEMORY_RESOURCE_HPP_)
#error "amalgamate: file c4/memory_resource.hpp must have been included at this point"
#endif /* C4_MEMORY_RESOURCE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/ctor_dtor.hpp
//#include "c4/ctor_dtor.hpp"
#if !defined(C4_CTOR_DTOR_HPP_) && !defined(_C4_CTOR_DTOR_HPP_)
#error "amalgamate: file c4/ctor_dtor.hpp must have been included at this point"
#endif /* C4_CTOR_DTOR_HPP_ */


#include <memory> // std::allocator_traits
//included above:
//#include <type_traits>

/** @file allocator.hpp Contains classes to make typeful allocations (note
 * that memory resources are typeless) */

/** @defgroup mem_res_providers Memory resource providers
 * @brief Policy classes which provide a memory resource for
 * use in an allocator.
 * @ingroup memory
 */

/** @defgroup allocators Allocators
 * @brief Lightweight classes that act as handles to specific memory
 * resources and provide typeful memory.
 * @ingroup memory
 */

namespace c4 {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")

namespace detail {
template<class T> inline size_t size_for      (size_t num_objs) noexcept { return num_objs * sizeof(T); }
template<       > inline size_t size_for<void>(size_t num_objs) noexcept { return num_objs;             }
} // namespace detail


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** provides a per-allocator memory resource
 * @ingroup mem_res_providers */
class MemRes
{
public:

    MemRes() : m_resource(get_memory_resource()) {}
    MemRes(MemoryResource* r) noexcept : m_resource(r ? r : get_memory_resource()) {}

    inline MemoryResource* resource() const { return m_resource; }

private:

    MemoryResource* m_resource;

};


/** the allocators using this will default to the global memory resource
 * @ingroup mem_res_providers */
class MemResGlobal
{
public:

    MemResGlobal() {}
    MemResGlobal(MemoryResource* r) noexcept { C4_UNUSED(r); C4_ASSERT(r == get_memory_resource()); }

    inline MemoryResource* resource() const { return get_memory_resource(); }
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

namespace detail {
template<class MemRes>
struct _AllocatorUtil;

template<class T, class ...Args>
struct has_no_alloc
    : public std::integral_constant<bool,
                                    !(std::uses_allocator<T, MemoryResource*>::value)
                                    && std::is_constructible<T, Args...>::value> {};

// std::uses_allocator_v<U, MemoryResource> && std::is_constructible<U, std::allocator_arg_t, MemoryResource*, Args...>
// ie can construct(std::allocator_arg_t, MemoryResource*, Args...)
template<class T, class ...Args>
struct has_alloc_arg
    : public std::integral_constant<bool,
                                    std::uses_allocator<T, MemoryResource*>::value
                                    && std::is_constructible<T, std::allocator_arg_t, MemoryResource*, Args...>::value> {};
// std::uses_allocator<U> && std::is_constructible<U, Args..., MemoryResource*>
// ie, can construct(Args..., MemoryResource*)
template<class T, class ...Args>
struct has_alloc
    : public std::integral_constant<bool,
                                    std::uses_allocator<T, MemoryResource*>::value
                                    && std::is_constructible<T, Args..., MemoryResource*>::value> {};

} // namespace detail


template<class MemRes>
struct detail::_AllocatorUtil : public MemRes
{
    using MemRes::MemRes;

    /** for construct:
     * @see http://en.cppreference.com/w/cpp/experimental/polymorphic_allocator/construct */

    // 1. types with no allocators
    template <class U, class... Args>
    C4_ALWAYS_INLINE typename std::enable_if<detail::has_no_alloc<U, Args...>::value, void>::type
    construct(U *ptr, Args &&...args)
    {
        c4::construct(ptr, std::forward<Args>(args)...);
    }
    template<class U, class I, class... Args>
    C4_ALWAYS_INLINE typename std::enable_if<detail::has_no_alloc<U, Args...>::value, void>::type
    construct_n(U* ptr, I n, Args&&... args)
    {
        c4::construct_n(ptr, n, std::forward<Args>(args)...);
    }

    // 2. types using allocators (ie, containers)

    // 2.1. can construct(std::allocator_arg_t, MemoryResource*, Args...)
    template<class U, class... Args>
    C4_ALWAYS_INLINE typename std::enable_if<detail::has_alloc_arg<U, Args...>::value, void>::type
    construct(U* ptr, Args&&... args)
    {
        c4::construct(ptr, std::allocator_arg, this->resource(), std::forward<Args>(args)...);
    }
    template<class U, class I, class... Args>
    C4_ALWAYS_INLINE typename std::enable_if<detail::has_alloc_arg<U, Args...>::value, void>::type
    construct_n(U* ptr, I n, Args&&... args)
    {
        c4::construct_n(ptr, n, std::allocator_arg, this->resource(), std::forward<Args>(args)...);
    }

    // 2.2. can construct(Args..., MemoryResource*)
    template<class U, class... Args>
    C4_ALWAYS_INLINE typename std::enable_if<detail::has_alloc<U, Args...>::value, void>::type
    construct(U* ptr, Args&&... args)
    {
        c4::construct(ptr, std::forward<Args>(args)..., this->resource());
    }
    template<class U, class I, class... Args>
    C4_ALWAYS_INLINE typename std::enable_if<detail::has_alloc<U, Args...>::value, void>::type
    construct_n(U* ptr, I n, Args&&... args)
    {
        c4::construct_n(ptr, n, std::forward<Args>(args)..., this->resource());
    }

    template<class U>
    static C4_ALWAYS_INLINE void destroy(U* ptr)
    {
        c4::destroy(ptr);
    }
    template<class U, class I>
    static C4_ALWAYS_INLINE void destroy_n(U* ptr, I n)
    {
        c4::destroy_n(ptr, n);
    }
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** An allocator is simply a proxy to a memory resource.
 * @param T
 * @param MemResProvider
 * @ingroup allocators */
template<class T, class MemResProvider=MemResGlobal>
class Allocator : public detail::_AllocatorUtil<MemResProvider>
{
public:

    using impl_type = detail::_AllocatorUtil<MemResProvider>;

    using value_type = T;
    using pointer = T*;
    using const_pointer = T const*;
    using reference = T&;
    using const_reference = T const&;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using propagate_on_container_move_assigment = std::true_type;

public:

    template<class U, class MRProv>
    bool operator== (Allocator<U, MRProv> const& that) const
    {
        return this->resource() == that.resource();
    }
    template<class U, class MRProv>
    bool operator!= (Allocator<U, MRProv> const& that) const
    {
        return this->resource() != that.resource();
    }

public:

    template<class U, class MRProv> friend class Allocator;
    template<class U>
    struct rebind
    {
        using other = Allocator<U, MemResProvider>;
    };
    template<class U>
    typename rebind<U>::other rebound()
    {
        return typename rebind<U>::other(*this);
    }

public:

    using impl_type::impl_type;
    Allocator() : impl_type() {} // VS demands this

    template<class U> Allocator(Allocator<U, MemResProvider> const& that) : impl_type(that.resource()) {}

    Allocator(Allocator const&) = default;
    Allocator(Allocator     &&) = default;

    Allocator& operator= (Allocator const&) = default; // WTF? why? @see http://en.cppreference.com/w/cpp/memory/polymorphic_allocator
    Allocator& operator= (Allocator     &&) = default;

    /** returns a default-constructed polymorphic allocator object
     * @see http://en.cppreference.com/w/cpp/memory/polymorphic_allocator/select_on_container_copy_construction      */
    Allocator select_on_container_copy_construct() const { return Allocator(*this); }

    T* allocate(size_t num_objs, size_t alignment=alignof(T))
    {
        C4_ASSERT(this->resource() != nullptr);
        C4_ASSERT(alignment >= alignof(T));
        void* vmem = this->resource()->allocate(detail::size_for<T>(num_objs), alignment);
        T* mem = static_cast<T*>(vmem);
        return mem;
    }

    void deallocate(T * ptr, size_t num_objs, size_t alignment=alignof(T))
    {
        C4_ASSERT(this->resource() != nullptr);
        C4_ASSERT(alignment>= alignof(T));
        this->resource()->deallocate(ptr, detail::size_for<T>(num_objs), alignment);
    }

    T* reallocate(T* ptr, size_t oldnum, size_t newnum, size_t alignment=alignof(T))
    {
        C4_ASSERT(this->resource() != nullptr);
        C4_ASSERT(alignment >= alignof(T));
        void* vmem = this->resource()->reallocate(ptr, detail::size_for<T>(oldnum), detail::size_for<T>(newnum), alignment);
        T* mem = static_cast<T*>(vmem);
        return mem;
    }

};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @ingroup allocators */
template<class T, size_t N=16, size_t Alignment=alignof(T), class MemResProvider=MemResGlobal>
class SmallAllocator : public detail::_AllocatorUtil<MemResProvider>
{
    static_assert(Alignment >= alignof(T), "invalid alignment");

    using impl_type = detail::_AllocatorUtil<MemResProvider>;

    alignas(Alignment) char m_arr[N * sizeof(T)];
    size_t m_num{0};

public:

    using value_type = T;
    using pointer = T*;
    using const_pointer = T const*;
    using reference = T&;
    using const_reference = T const&;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    using propagate_on_container_move_assigment = std::true_type;

    template<class U>
    bool operator== (SmallAllocator<U,N,Alignment,MemResProvider> const&) const
    {
        return false;
    }
    template<class U>
    bool operator!= (SmallAllocator<U,N,Alignment,MemResProvider> const&) const
    {
        return true;
    }

public:

    template<class U, size_t, size_t, class> friend class SmallAllocator;
    template<class U>
    struct rebind
    {
        using other = SmallAllocator<U, N, alignof(U), MemResProvider>;
    };
    template<class U>
    typename rebind<U>::other rebound()
    {
        return typename rebind<U>::other(*this);
    }

public:

    using impl_type::impl_type;
    SmallAllocator() : impl_type() {} // VS demands this

    template<class U, size_t N2, size_t A2, class MP2>
    SmallAllocator(SmallAllocator<U,N2,A2,MP2> const& that) : impl_type(that.resource())
    {
        C4_ASSERT(that.m_num == 0);
    }

    SmallAllocator(SmallAllocator const&) = default;
    SmallAllocator(SmallAllocator     &&) = default;

    SmallAllocator& operator= (SmallAllocator const&) = default; // WTF? why? @see http://en.cppreference.com/w/cpp/memory/polymorphic_allocator
    SmallAllocator& operator= (SmallAllocator     &&) = default;

    /** returns a default-constructed polymorphic allocator object
     * @see http://en.cppreference.com/w/cpp/memory/polymorphic_allocator/select_on_container_copy_construction      */
    SmallAllocator select_on_container_copy_construct() const { return SmallAllocator(*this); }

    T* allocate(size_t num_objs, size_t alignment=Alignment)
    {
        C4_ASSERT(this->resource() != nullptr);
        C4_ASSERT(alignment >= alignof(T));
        void *vmem;
        if(m_num + num_objs <= N)
        {
            vmem = (m_arr + m_num * sizeof(T));
        }
        else
        {
            vmem = this->resource()->allocate(num_objs * sizeof(T), alignment);
        }
        m_num += num_objs;
        T *mem = static_cast<T*>(vmem);
        return mem;
    }

    void deallocate(T * ptr, size_t num_objs, size_t alignment=Alignment)
    {
        C4_ASSERT(m_num >= num_objs);
        m_num -= num_objs;
        if((char*)ptr >= m_arr && (char*)ptr < m_arr + (N * sizeof(T)))
        {
            return;
        }
        C4_ASSERT(this->resource() != nullptr);
        C4_ASSERT(alignment >= alignof(T));
        this->resource()->deallocate(ptr, num_objs * sizeof(T), alignment);
    }

    T* reallocate(T * ptr, size_t oldnum, size_t newnum, size_t alignment=Alignment)
    {
        C4_ASSERT(this->resource() != nullptr);
        C4_ASSERT(alignment >= alignof(T));
        if(oldnum <= N && newnum <= N)
        {
            return m_arr;
        }
        else if(oldnum <= N && newnum > N)
        {
            return allocate(newnum, alignment);
        }
        else if(oldnum > N && newnum <= N)
        {
            deallocate(ptr, oldnum, alignment);
            return m_arr;
        }
        void* vmem = this->resource()->reallocate(ptr, oldnum * sizeof(T), newnum * sizeof(T), alignment);
        T* mem = static_cast<T*>(vmem);
        return mem;
    }

};

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** An allocator making use of the global memory resource.
 * @ingroup allocators */
template<class T> using allocator = Allocator<T, MemResGlobal>;
/** An allocator with a per-instance memory resource
 * @ingroup allocators */
template<class T> using allocator_mr = Allocator<T, MemRes>;

/** @ingroup allocators */
template<class T, size_t N=16, size_t Alignment=alignof(T)> using small_allocator = SmallAllocator<T, N, Alignment, MemResGlobal>;
/** @ingroup allocators */
template<class T, size_t N=16, size_t Alignment=alignof(T)> using small_allocator_mr = SmallAllocator<T, N, Alignment, MemRes>;

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace c4

#endif /* _C4_ALLOCATOR_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/allocator.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/char_traits.hpp
// https://github.com/biojppm/c4core/src/c4/char_traits.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_CHAR_TRAITS_HPP_
#define _C4_CHAR_TRAITS_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/config.hpp
//#include "c4/config.hpp"
#if !defined(C4_CONFIG_HPP_) && !defined(_C4_CONFIG_HPP_)
#error "amalgamate: file c4/config.hpp must have been included at this point"
#endif /* C4_CONFIG_HPP_ */


#include <string> // needed because of std::char_traits
#include <cctype>
#include <cwctype>

namespace c4 {

C4_ALWAYS_INLINE bool isspace(char c) { return std::isspace(c) != 0; }
C4_ALWAYS_INLINE bool isspace(wchar_t c) { return std::iswspace(static_cast<wint_t>(c)) != 0; }

//-----------------------------------------------------------------------------
template<typename C>
struct char_traits;

template<>
struct char_traits<char> : public std::char_traits<char>
{
    constexpr static const char whitespace_chars[] = " \f\n\r\t\v";
    constexpr static const size_t num_whitespace_chars = sizeof(whitespace_chars) - 1;
};

template<>
struct char_traits<wchar_t> : public std::char_traits<wchar_t>
{
    constexpr static const wchar_t whitespace_chars[] = L" \f\n\r\t\v";
    constexpr static const size_t num_whitespace_chars = sizeof(whitespace_chars) - 1;
};


//-----------------------------------------------------------------------------
namespace detail {
template<typename C>
struct needed_chars;
template<>
struct needed_chars<char>
{
    template<class SizeType>
    C4_ALWAYS_INLINE constexpr static SizeType for_bytes(SizeType num_bytes)
    {
        return num_bytes;
    }
};
template<>
struct needed_chars<wchar_t>
{
    template<class SizeType>
    C4_ALWAYS_INLINE constexpr static SizeType for_bytes(SizeType num_bytes)
    {
        // wchar_t is not necessarily 2 bytes.
        return (num_bytes / static_cast<SizeType>(sizeof(wchar_t))) + ((num_bytes & static_cast<SizeType>(SizeType(sizeof(wchar_t)) - SizeType(1))) != 0);
    }
};
} // namespace detail

/** get the number of C characters needed to store a number of bytes */
template<typename C, typename SizeType>
C4_ALWAYS_INLINE constexpr SizeType num_needed_chars(SizeType num_bytes)
{
    return detail::needed_chars<C>::for_bytes(num_bytes);
}


//-----------------------------------------------------------------------------

/** get the given text string as either char or wchar_t according to the given type */
#define C4_TXTTY(txt, type) \
    /* is there a smarter way to do this? */\
    c4::detail::literal_as<type>::get(txt, C4_WIDEN(txt))

namespace detail {
template<typename C>
struct literal_as;

template<>
struct literal_as<char>
{
    C4_ALWAYS_INLINE static constexpr const char* get(const char* str, const wchar_t *)
    {
        return str;
    }
};
template<>
struct literal_as<wchar_t>
{
    C4_ALWAYS_INLINE static constexpr const wchar_t* get(const char*, const wchar_t *wstr)
    {
        return wstr;
    }
};
} // namespace detail

} // namespace c4

#endif /* _C4_CHAR_TRAITS_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/char_traits.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/hash.hpp
// https://github.com/biojppm/c4core/src/c4/hash.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_HASH_HPP_
#define _C4_HASH_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/config.hpp
//#include "c4/config.hpp"
#if !defined(C4_CONFIG_HPP_) && !defined(_C4_CONFIG_HPP_)
#error "amalgamate: file c4/config.hpp must have been included at this point"
#endif /* C4_CONFIG_HPP_ */

#include <climits>

/** @file hash.hpp */

/** @defgroup hash Hash utils
 * @see http://aras-p.info/blog/2016/08/02/Hash-Functions-all-the-way-down/ */

namespace c4 {

namespace detail {

/** @internal
 * @ingroup hash
 * @see this was taken a great answer in stackoverflow:
 * https://stackoverflow.com/a/34597785/5875572
 * @see http://aras-p.info/blog/2016/08/02/Hash-Functions-all-the-way-down/ */
template<typename ResultT, ResultT OffsetBasis, ResultT Prime>
class basic_fnv1a final
{

  static_assert(std::is_unsigned<ResultT>::value, "need unsigned integer");

public:

    using result_type = ResultT;

private:

    result_type state_ {};

public:

    C4_CONSTEXPR14 basic_fnv1a() noexcept : state_ {OffsetBasis} {}

    C4_CONSTEXPR14 void update(const void *const data, const size_t size) noexcept
    {
        auto cdata = static_cast<const unsigned char *>(data);
        auto acc = this->state_;
        for(size_t i = 0; i < size; ++i)
        {
            const auto next = size_t(cdata[i]);
            acc = (acc ^ next) * Prime;
        }
        this->state_ = acc;
    }

    C4_CONSTEXPR14 result_type digest() const noexcept
    {
        return this->state_;
    }

};

using fnv1a_32 = basic_fnv1a<uint32_t, UINT32_C(          2166136261), UINT32_C(     16777619)>;
using fnv1a_64 = basic_fnv1a<uint64_t, UINT64_C(14695981039346656037), UINT64_C(1099511628211)>;

template<size_t Bits> struct fnv1a;
template<> struct fnv1a<32> { using type = fnv1a_32; };
template<> struct fnv1a<64> { using type = fnv1a_64; };

} // namespace detail


/** @ingroup hash */
template<size_t Bits>
using fnv1a_t = typename detail::fnv1a<Bits>::type;


/** @ingroup hash */
C4_CONSTEXPR14 inline size_t hash_bytes(const void *const data, const size_t size) noexcept
{
    fnv1a_t<CHAR_BIT * sizeof(size_t)> fn{};
    fn.update(data, size);
    return fn.digest();
}

/**
 * @overload hash_bytes
 * @ingroup hash */
template<size_t N>
C4_CONSTEXPR14 inline size_t hash_bytes(const char (&str)[N]) noexcept
{
    fnv1a_t<CHAR_BIT * sizeof(size_t)> fn{};
    fn.update(str, N);
    return fn.digest();
}

} // namespace c4


#endif // _C4_HASH_HPP_


// (end https://github.com/biojppm/c4core/src/c4/hash.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/szconv.hpp
// https://github.com/biojppm/c4core/src/c4/szconv.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_SZCONV_HPP_
#define _C4_SZCONV_HPP_

/** @file szconv.hpp utilities to deal safely with narrowing conversions */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/config.hpp
//#include "c4/config.hpp"
#if !defined(C4_CONFIG_HPP_) && !defined(_C4_CONFIG_HPP_)
#error "amalgamate: file c4/config.hpp must have been included at this point"
#endif /* C4_CONFIG_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */


#include <limits>

namespace c4 {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")

/** @todo this would be so much easier with calls to numeric_limits::max()... */
template<class SizeOut, class SizeIn>
struct is_narrower_size : std::conditional
<
   (std::is_signed<SizeOut>::value == std::is_signed<SizeIn>::value)
   ?
   (sizeof(SizeOut) < sizeof(SizeIn))
   :
   (
       (sizeof(SizeOut) < sizeof(SizeIn))
       ||
       (
           (sizeof(SizeOut) == sizeof(SizeIn))
           &&
           (std::is_signed<SizeOut>::value && std::is_unsigned<SizeIn>::value)
       )
   ),
   std::true_type,
   std::false_type
>::type
{
    static_assert(std::is_integral<SizeIn >::value, "must be integral type");
    static_assert(std::is_integral<SizeOut>::value, "must be integral type");
};


/** when SizeOut is wider than SizeIn, assignment can occur without reservations */
template<class SizeOut, class SizeIn>
C4_ALWAYS_INLINE
typename std::enable_if< ! is_narrower_size<SizeOut, SizeIn>::value, SizeOut>::type
szconv(SizeIn sz) noexcept
{
    return static_cast<SizeOut>(sz);
}

/** when SizeOut is narrower than SizeIn, narrowing will occur, so we check
 * for overflow. Note that this check is done only if C4_XASSERT is enabled.
 * @see C4_XASSERT */
template<class SizeOut, class SizeIn>
C4_ALWAYS_INLINE
typename std::enable_if<is_narrower_size<SizeOut, SizeIn>::value, SizeOut>::type
szconv(SizeIn sz)
{
    C4_XASSERT(sz >= 0);
    C4_XASSERT_MSG((SizeIn)sz <= (SizeIn)std::numeric_limits<SizeOut>::max(), "size conversion overflow: in=%zu", (size_t)sz);
    SizeOut szo = static_cast<SizeOut>(sz);
    return szo;
}

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace c4

#endif /* _C4_SZCONV_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/szconv.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/blob.hpp
// https://github.com/biojppm/c4core/src/c4/blob.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_BLOB_HPP_
#define _C4_BLOB_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/types.hpp
//#include "c4/types.hpp"
#if !defined(C4_TYPES_HPP_) && !defined(_C4_TYPES_HPP_)
#error "amalgamate: file c4/types.hpp must have been included at this point"
#endif /* C4_TYPES_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */


/** @file blob.hpp Mutable and immutable binary data blobs.
*/

namespace c4 {

template<class T>
struct blob_;

namespace detail {
template<class T> struct is_blob_type : std::integral_constant<bool, false> {};
template<class T> struct is_blob_type<blob_<T>> : std::integral_constant<bool, true> {};
template<class T> struct is_blob_value_type : std::integral_constant<bool, (std::is_fundamental<T>::value || std::is_trivially_copyable<T>::value)> {};
} // namespace

template<class T>
struct blob_
{
    static_assert(std::is_same<T, byte>::value || std::is_same<T, cbyte>::value, "must be either byte or cbyte");
    static_assert(sizeof(T) == 1u, "must be either byte or cbyte");

public:

    T *    buf;
    size_t len;

public:

    C4_ALWAYS_INLINE blob_() noexcept = default;
    C4_ALWAYS_INLINE blob_(blob_ const& that) noexcept = default;
    C4_ALWAYS_INLINE blob_(blob_     && that) noexcept = default;
    C4_ALWAYS_INLINE blob_& operator=(blob_     && that) noexcept = default;
    C4_ALWAYS_INLINE blob_& operator=(blob_ const& that) noexcept = default;

    template<class U, class=typename std::enable_if<std::is_const<T>::value && std::is_same<typename std::add_const<U>::type, T>::value, U>::type> C4_ALWAYS_INLINE blob_(blob_<U> const& that) noexcept : buf(that.buf), len(that.len) {}
    template<class U, class=typename std::enable_if<std::is_const<T>::value && std::is_same<typename std::add_const<U>::type, T>::value, U>::type> C4_ALWAYS_INLINE blob_(blob_<U>     && that) noexcept : buf(that.buf), len(that.len) {}
    template<class U, class=typename std::enable_if<std::is_const<T>::value && std::is_same<typename std::add_const<U>::type, T>::value, U>::type> C4_ALWAYS_INLINE blob_& operator=(blob_<U>     && that) noexcept { buf = that.buf; len = that.len; }
    template<class U, class=typename std::enable_if<std::is_const<T>::value && std::is_same<typename std::add_const<U>::type, T>::value, U>::type> C4_ALWAYS_INLINE blob_& operator=(blob_<U> const& that) noexcept { buf = that.buf; len = that.len; }

    C4_ALWAYS_INLINE blob_(void       *ptr, size_t n) noexcept : buf(reinterpret_cast<T*>(ptr)), len(n) {}
    C4_ALWAYS_INLINE blob_(void const *ptr, size_t n) noexcept : buf(reinterpret_cast<T*>(ptr)), len(n) {}

    #define _C4_REQUIRE_BLOBTYPE(ty) class=typename std::enable_if<((!detail::is_blob_type<ty>::value) && (detail::is_blob_value_type<ty>::value)), T>::type
    template<class U, _C4_REQUIRE_BLOBTYPE(U)> C4_ALWAYS_INLINE blob_(U &var) noexcept : buf(reinterpret_cast<T*>(&var)), len(sizeof(U)) {}
    template<class U, _C4_REQUIRE_BLOBTYPE(U)> C4_ALWAYS_INLINE blob_(U *ptr, size_t n) noexcept : buf(reinterpret_cast<T*>(ptr)), len(sizeof(U) * n) { C4_ASSERT(is_aligned(ptr)); }
    template<class U, _C4_REQUIRE_BLOBTYPE(U)> C4_ALWAYS_INLINE blob_& operator= (U &var) noexcept { buf = reinterpret_cast<T*>(&var); len = sizeof(U); return *this; }
    template<class U, size_t N, _C4_REQUIRE_BLOBTYPE(U)> C4_ALWAYS_INLINE blob_(U (&arr)[N]) noexcept : buf(reinterpret_cast<T*>(arr)), len(sizeof(U) * N) {}
    template<class U, size_t N, _C4_REQUIRE_BLOBTYPE(U)> C4_ALWAYS_INLINE blob_& operator= (U (&arr)[N]) noexcept { buf = reinterpret_cast<T*>(arr); len = sizeof(U) * N; return *this; }
    #undef _C4_REQUIRE_BLOBTYPE
};

/** an immutable binary blob */
using cblob = blob_<cbyte>;
/** a mutable binary blob */
using  blob = blob_< byte>;

C4_MUST_BE_TRIVIAL_COPY(blob);
C4_MUST_BE_TRIVIAL_COPY(cblob);

} // namespace c4

#endif // _C4_BLOB_HPP_


// (end https://github.com/biojppm/c4core/src/c4/blob.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/substr_fwd.hpp
// https://github.com/biojppm/c4core/src/c4/substr_fwd.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_SUBSTR_FWD_HPP_
#define _C4_SUBSTR_FWD_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/export.hpp
//#include "c4/export.hpp"
#if !defined(C4_EXPORT_HPP_) && !defined(_C4_EXPORT_HPP_)
#error "amalgamate: file c4/export.hpp must have been included at this point"
#endif /* C4_EXPORT_HPP_ */


namespace c4 {

#ifndef DOXYGEN
template<class C> struct basic_substring;
using csubstr = C4CORE_EXPORT basic_substring<const char>;
using substr = C4CORE_EXPORT basic_substring<char>;
#endif // !DOXYGEN

} // namespace c4

#endif /* _C4_SUBSTR_FWD_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/substr_fwd.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/substr.hpp
// https://github.com/biojppm/c4core/src/c4/substr.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_SUBSTR_HPP_
#define _C4_SUBSTR_HPP_

/** @file substr.hpp read+write string views */

//included above:
//#include <string.h>
//included above:
//#include <ctype.h>
//included above:
//#include <type_traits>

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/config.hpp
//#include "c4/config.hpp"
#if !defined(C4_CONFIG_HPP_) && !defined(_C4_CONFIG_HPP_)
#error "amalgamate: file c4/config.hpp must have been included at this point"
#endif /* C4_CONFIG_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/substr_fwd.hpp
//#include "c4/substr_fwd.hpp"
#if !defined(C4_SUBSTR_FWD_HPP_) && !defined(_C4_SUBSTR_FWD_HPP_)
#error "amalgamate: file c4/substr_fwd.hpp must have been included at this point"
#endif /* C4_SUBSTR_FWD_HPP_ */


#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wtype-limits" // disable warnings on size_t>=0, used heavily in assertions below. These assertions are a preparation step for providing the index type as a template parameter.
#   pragma GCC diagnostic ignored "-Wuseless-cast"
#   pragma GCC diagnostic ignored "-Wold-style-cast"
#endif


namespace c4 {

/** @defgroup doc_substr Substring: read/write string views
 * @{ */

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @cond dev */
namespace detail {
template<typename C>
static inline void _do_reverse(C *C4_RESTRICT first, C *C4_RESTRICT last)
{
    while(last > first)
    {
        C tmp = *last;
        *last-- = *first;
        *first++ = tmp;
    }
}
} // namespace detail
/** @endcond */

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @cond dev */
// utility macros to deuglify SFINAE code; undefined after the class.
// https://stackoverflow.com/questions/43051882/how-to-disable-a-class-member-funrtion-for-certain-template-types
#define C4_REQUIRE_RW(ret_type) \
    template <typename U=C> \
    typename std::enable_if< ! std::is_const<U>::value, ret_type>::type
/** @endcond */


/** a non-owning string-view, consisting of a character pointer
 * and a length.
 *
 * @note The pointer is explicitly restricted.
 *
 * @see a [quickstart
 * sample](https://rapidyaml.readthedocs.io/latest/doxygen/group__doc__quickstart.html#ga43e253da0692c13967019446809c1113)
 * in rapidyaml's documentation.
 *
 * @see @ref substr and @ref to_substr()
 * @see @ref csubstr and @ref to_csubstr()
 */
template<class C>
struct C4CORE_EXPORT basic_substring
{
public:

    /** a restricted pointer to the first character of the substring */
    C * C4_RESTRICT str;
    /** the length of the substring */
    size_t          len;

public:

    /** @name Types */
    /** @{ */

    using  CC  = typename std::add_const<C>::type;     //!< CC=const char
    using NCC_ = typename std::remove_const<C>::type; //!< NCC_=non const char

    using ro_substr = basic_substring<CC>;
    using rw_substr = basic_substring<NCC_>;

    using char_type = C;
    using size_type = size_t;

    using iterator = C*;
    using const_iterator = CC*;

    enum : size_t { npos = (size_t)-1, NONE = (size_t)-1 };

    /// convert automatically to substring of const C
    template<class U=C>
    C4_ALWAYS_INLINE operator typename std::enable_if<!std::is_const<U>::value, ro_substr const&>::type () const noexcept
    {
        return *(ro_substr const*)this; // don't call the str+len ctor because it does a check
    }

    /** @} */

public:

    /** @name Default construction and assignment */
    /** @{ */

    C4_ALWAYS_INLINE constexpr basic_substring() noexcept : str(), len() {}

    C4_ALWAYS_INLINE basic_substring(basic_substring const&) noexcept = default;
    C4_ALWAYS_INLINE basic_substring(basic_substring     &&) noexcept = default;
    C4_ALWAYS_INLINE basic_substring(std::nullptr_t) noexcept : str(nullptr), len(0) {}

    C4_ALWAYS_INLINE basic_substring& operator= (basic_substring const&) noexcept = default;
    C4_ALWAYS_INLINE basic_substring& operator= (basic_substring     &&) noexcept = default;
    C4_ALWAYS_INLINE basic_substring& operator= (std::nullptr_t) noexcept { str = nullptr; len = 0; return *this; }

    C4_ALWAYS_INLINE void clear() noexcept { str = nullptr; len = 0; }

    /** @} */

public:

    /** @name Construction and assignment from characters with the same type */
    /** @{ */

    /** Construct from an array.
     * @warning the input string need not be zero terminated, but the
     * length is taken as if the string was zero terminated */
    template<size_t N>
    C4_ALWAYS_INLINE constexpr basic_substring(C (&s_)[N]) noexcept : str(s_), len(N-1) {}
    /** Construct from a pointer and length.
     * @warning the input string need not be zero terminated. */
    C4_ALWAYS_INLINE basic_substring(C *s_, size_t len_) noexcept : str(s_), len(len_) { C4_ASSERT(str || !len_); }
    /** Construct from two pointers.
     * @warning the end pointer MUST BE larger than or equal to the begin pointer
     * @warning the input string need not be zero terminated */
    C4_ALWAYS_INLINE basic_substring(C *beg_, C *end_) noexcept : str(beg_), len(static_cast<size_t>(end_ - beg_)) { C4_ASSERT(end_ >= beg_); }
    /** Construct from a C-string (zero-terminated string)
     * @warning the input string MUST BE zero terminated.
     * @warning will call strlen()
     * @note this overload uses SFINAE to prevent it from overriding the array ctor
     * @see For a more detailed explanation on why the plain overloads cannot
     * coexist, see http://cplusplus.bordoon.com/specializeForCharacterArrays.html */
    template<class U, typename std::enable_if<std::is_same<U, C*>::value || std::is_same<U, NCC_*>::value, int>::type=0>
    C4_ALWAYS_INLINE basic_substring(U s_) noexcept : str(s_), len(s_ ? strlen(s_) : 0) {}

    /** Assign from an array.
     * @warning the input string need not be zero terminated, but the
     * length is taken as if the string was zero terminated */
    template<size_t N>
    C4_ALWAYS_INLINE void assign(C (&s_)[N]) noexcept { str = (s_); len = (N-1); }
    /** Assign from a pointer and length.
     * @warning the input string need not be zero terminated. */
    C4_ALWAYS_INLINE void assign(C *s_, size_t len_) noexcept { str = s_; len = len_; C4_ASSERT(str || !len_); }
    /** Assign from two pointers.
     * @warning the end pointer MUST BE larger than or equal to the begin pointer
     * @warning the input string need not be zero terminated. */
    C4_ALWAYS_INLINE void assign(C *beg_, C *end_) noexcept { C4_ASSERT(end_ >= beg_); str = (beg_); len = static_cast<size_t>(end_ - beg_); }
    /** Assign from a C-string (zero-terminated string)
     * @warning the input string must be zero terminated.
     * @warning will call strlen()
     * @note this overload uses SFINAE to prevent it from overriding the array ctor
     * @see For a more detailed explanation on why the plain overloads cannot
     * coexist, see http://cplusplus.bordoon.com/specializeForCharacterArrays.html */
    template<class U, typename std::enable_if<std::is_same<U, C*>::value || std::is_same<U, NCC_*>::value, int>::type=0>
    C4_ALWAYS_INLINE void assign(U s_) noexcept { str = (s_); len = (s_ ? strlen(s_) : 0); }

    /** Assign from an array.
     * @warning the input string need not be zero terminated. */
    template<size_t N>
    C4_ALWAYS_INLINE basic_substring& operator= (C (&s_)[N]) noexcept { str = (s_); len = (N-1); return *this; }
    /** Assign from a C-string (zero-terminated string)
     * @warning the input string MUST BE zero terminated.
     * @warning will call strlen()
     * @note this overload uses SFINAE to prevent it from overriding the array ctor
     * @see For a more detailed explanation on why the plain overloads cannot
     * coexist, see http://cplusplus.bordoon.com/specializeForCharacterArrays.html */
    template<class U, typename std::enable_if<std::is_same<U, C*>::value || std::is_same<U, NCC_*>::value, int>::type=0>
    C4_ALWAYS_INLINE basic_substring& operator= (U s_) noexcept { str = s_; len = s_ ? strlen(s_) : 0; return *this; }

    /** @} */

public:

    /** @name Standard accessor methods */
    /** @{ */

    C4_ALWAYS_INLINE C4_PURE bool   has_str()   const noexcept { return ! empty() && str[0] != C(0); }
    C4_ALWAYS_INLINE C4_PURE bool   empty()     const noexcept { return (len == 0 || str == nullptr); }
    C4_ALWAYS_INLINE C4_PURE bool   not_empty() const noexcept { return (len != 0 && str != nullptr); }
    C4_ALWAYS_INLINE C4_PURE size_t size()      const noexcept { return len; }

    C4_ALWAYS_INLINE C4_PURE iterator begin() noexcept { return str; }
    C4_ALWAYS_INLINE C4_PURE iterator end  () noexcept { return str + len; }

    C4_ALWAYS_INLINE C4_PURE const_iterator begin() const noexcept { return str; }
    C4_ALWAYS_INLINE C4_PURE const_iterator end  () const noexcept { return str + len; }

    C4_ALWAYS_INLINE C4_PURE C      * data()       noexcept { return str; }
    C4_ALWAYS_INLINE C4_PURE C const* data() const noexcept { return str; }

    C4_ALWAYS_INLINE C4_PURE C      & operator[] (size_t i)       noexcept { C4_ASSERT(i >= 0 && i < len); return str[i]; }
    C4_ALWAYS_INLINE C4_PURE C const& operator[] (size_t i) const noexcept { C4_ASSERT(i >= 0 && i < len); return str[i]; }

    C4_ALWAYS_INLINE C4_PURE C      & front()       noexcept { C4_ASSERT(len > 0 && str != nullptr); return *str; }
    C4_ALWAYS_INLINE C4_PURE C const& front() const noexcept { C4_ASSERT(len > 0 && str != nullptr); return *str; }

    C4_ALWAYS_INLINE C4_PURE C      & back()       noexcept { C4_ASSERT(len > 0 && str != nullptr); return *(str + len - 1); }
    C4_ALWAYS_INLINE C4_PURE C const& back() const noexcept { C4_ASSERT(len > 0 && str != nullptr); return *(str + len - 1); }

    /** @} */

public:

    /** @name Comparison methods */
    /** @{ */

    C4_PURE int compare(C const c) const noexcept
    {
        C4_XASSERT((str != nullptr) || len == 0);
        if(C4_LIKELY(str != nullptr && len > 0))
            return (*str != c) ? *str - c : (static_cast<int>(len) - 1);
        else
            return -1;
    }

    C4_PURE int compare(const char *C4_RESTRICT that, size_t sz) const noexcept
    {
        C4_XASSERT(that || sz  == 0);
        C4_XASSERT(str  || len == 0);
        if(C4_LIKELY(str && that))
        {
            {
                const size_t min = len < sz ? len : sz;
                for(size_t i = 0; i < min; ++i)
                    if(str[i] != that[i])
                        return str[i] < that[i] ? -1 : 1;
            }
            if(len < sz)
                return -1;
            else if(len == sz)
                return 0;
            else
                return 1;
        }
        else if(len == sz)
        {
            C4_XASSERT(len == 0 && sz == 0);
            return 0;
        }
        return len < sz ? -1 : 1;
    }

    C4_ALWAYS_INLINE C4_PURE int compare(ro_substr const that) const noexcept { return this->compare(that.str, that.len); }

    C4_ALWAYS_INLINE C4_PURE bool operator== (std::nullptr_t) const noexcept { return str == nullptr; }
    C4_ALWAYS_INLINE C4_PURE bool operator!= (std::nullptr_t) const noexcept { return str != nullptr; }

    C4_ALWAYS_INLINE C4_PURE bool operator== (C const c) const noexcept { return this->compare(c) == 0; }
    C4_ALWAYS_INLINE C4_PURE bool operator!= (C const c) const noexcept { return this->compare(c) != 0; }
    C4_ALWAYS_INLINE C4_PURE bool operator<  (C const c) const noexcept { return this->compare(c) <  0; }
    C4_ALWAYS_INLINE C4_PURE bool operator>  (C const c) const noexcept { return this->compare(c) >  0; }
    C4_ALWAYS_INLINE C4_PURE bool operator<= (C const c) const noexcept { return this->compare(c) <= 0; }
    C4_ALWAYS_INLINE C4_PURE bool operator>= (C const c) const noexcept { return this->compare(c) >= 0; }

    template<class U> C4_ALWAYS_INLINE C4_PURE bool operator== (basic_substring<U> const that) const noexcept { return this->compare(that) == 0; }
    template<class U> C4_ALWAYS_INLINE C4_PURE bool operator!= (basic_substring<U> const that) const noexcept { return this->compare(that) != 0; }
    template<class U> C4_ALWAYS_INLINE C4_PURE bool operator<  (basic_substring<U> const that) const noexcept { return this->compare(that) <  0; }
    template<class U> C4_ALWAYS_INLINE C4_PURE bool operator>  (basic_substring<U> const that) const noexcept { return this->compare(that) >  0; }
    template<class U> C4_ALWAYS_INLINE C4_PURE bool operator<= (basic_substring<U> const that) const noexcept { return this->compare(that) <= 0; }
    template<class U> C4_ALWAYS_INLINE C4_PURE bool operator>= (basic_substring<U> const that) const noexcept { return this->compare(that) >= 0; }

    template<size_t N> C4_ALWAYS_INLINE C4_PURE bool operator== (const char (&that)[N]) const noexcept { return this->compare(that, N-1) == 0; }
    template<size_t N> C4_ALWAYS_INLINE C4_PURE bool operator!= (const char (&that)[N]) const noexcept { return this->compare(that, N-1) != 0; }
    template<size_t N> C4_ALWAYS_INLINE C4_PURE bool operator<  (const char (&that)[N]) const noexcept { return this->compare(that, N-1) <  0; }
    template<size_t N> C4_ALWAYS_INLINE C4_PURE bool operator>  (const char (&that)[N]) const noexcept { return this->compare(that, N-1) >  0; }
    template<size_t N> C4_ALWAYS_INLINE C4_PURE bool operator<= (const char (&that)[N]) const noexcept { return this->compare(that, N-1) <= 0; }
    template<size_t N> C4_ALWAYS_INLINE C4_PURE bool operator>= (const char (&that)[N]) const noexcept { return this->compare(that, N-1) >= 0; }

    /** @} */

public:

    /** @name Sub-selection methods */
    /** @{ */

    /** true if *this is a substring of that (ie, from the same buffer) */
    C4_ALWAYS_INLINE C4_PURE bool is_sub(ro_substr const that) const noexcept
    {
        return that.is_super(*this);
    }

    /** true if that is a substring of *this (ie, from the same buffer) */
    C4_ALWAYS_INLINE C4_PURE bool is_super(ro_substr const that) const noexcept
    {
        if(C4_LIKELY(len > 0))
            return that.str >= str && that.str+that.len <= str+len;
        else
            return that.len == 0 && that.str == str && str != nullptr;
    }

    /** true if there is overlap of at least one element between that and *this */
    C4_ALWAYS_INLINE C4_PURE bool overlaps(ro_substr const that) const noexcept
    {
        // thanks @timwynants
        return that.str+that.len > str && that.str < str+len;
    }

public:

    /** return [first,len[ */
    C4_ALWAYS_INLINE C4_PURE basic_substring sub(size_t first) const noexcept
    {
        C4_ASSERT(first >= 0 && first <= len);
        return basic_substring(str + first, len - first);
    }

    /** return [first,first+num[. If num==npos, return [first,len[ */
    C4_ALWAYS_INLINE C4_PURE basic_substring sub(size_t first, size_t num) const noexcept
    {
        C4_ASSERT(first >= 0 && first <= len);
        C4_ASSERT((num >= 0 && num <= len) || (num == npos));
        size_t rnum = num != npos ? num : len - first;
        C4_ASSERT((first >= 0 && first + rnum <= len) || (num == 0));
        return basic_substring(str + first, rnum);
    }

    /** return [first,last[. If last==npos, return [first,len[ */
    C4_ALWAYS_INLINE C4_PURE basic_substring range(size_t first, size_t last=npos) const noexcept
    {
        C4_ASSERT(first >= 0 && first <= len);
        last = last != npos ? last : len;
        C4_ASSERT(first <= last);
        C4_ASSERT(last  >= 0 && last  <= len);
        return basic_substring(str + first, last - first);
    }

    /** return the first @p num elements: [0,num[*/
    C4_ALWAYS_INLINE C4_PURE basic_substring first(size_t num) const noexcept
    {
        C4_ASSERT(num <= len || num == npos);
        return basic_substring(str, num != npos ? num : len);
    }

    /** return the last @p num elements: [len-num,len[*/
    C4_ALWAYS_INLINE C4_PURE basic_substring last(size_t num) const noexcept
    {
        C4_ASSERT(num <= len || num == npos);
        return num != npos ?
            basic_substring(str + len - num, num) :
            *this;
    }

    /** offset from the ends: return [left,len-right[ ; ie, trim a
        number of characters from the left and right. This is
        equivalent to python's negative list indices. */
    C4_ALWAYS_INLINE C4_PURE basic_substring offs(size_t left, size_t right) const noexcept
    {
        C4_ASSERT(left  >= 0 && left  <= len);
        C4_ASSERT(right >= 0 && right <= len);
        C4_ASSERT(left  <= len - right + 1);
        return basic_substring(str + left, len - right - left);
    }

    /** return [0, pos[ . Same as .first(pos), but provided for compatibility with .right_of() */
    C4_ALWAYS_INLINE C4_PURE basic_substring left_of(size_t pos) const noexcept
    {
        C4_ASSERT(pos <= len || pos == npos);
        return (pos != npos) ?
            basic_substring(str, pos) :
            *this;
    }

    /** return [0, pos+include_pos[ . Same as .first(pos+1), but provided for compatibility with .right_of() */
    C4_ALWAYS_INLINE C4_PURE basic_substring left_of(size_t pos, bool include_pos) const noexcept
    {
        C4_ASSERT(pos <= len || pos == npos);
        return (pos != npos) ?
            basic_substring(str, pos+include_pos) :
            *this;
    }

    /** return [pos+1, len[ */
    C4_ALWAYS_INLINE C4_PURE basic_substring right_of(size_t pos) const noexcept
    {
        C4_ASSERT(pos <= len || pos == npos);
        return (pos != npos) ?
            basic_substring(str + (pos + 1), len - (pos + 1)) :
            basic_substring(str + len, size_t(0));
    }

    /** return [pos+!include_pos, len[ */
    C4_ALWAYS_INLINE C4_PURE basic_substring right_of(size_t pos, bool include_pos) const noexcept
    {
        C4_ASSERT(pos <= len || pos == npos);
        return (pos != npos) ?
            basic_substring(str + (pos + !include_pos), len - (pos + !include_pos)) :
            basic_substring(str + len, size_t(0));
    }

public:

    /** given @p subs a substring of the current string, get the
     * portion of the current string to the left of it */
    C4_ALWAYS_INLINE C4_PURE basic_substring left_of(ro_substr const subs) const noexcept
    {
        C4_ASSERT(is_super(subs) || subs.empty());
        auto ssb = subs.begin();
        auto b = begin();
        auto e = end();
        if(ssb >= b && ssb <= e)
            return sub(0, static_cast<size_t>(ssb - b));
        else
            return sub(0, 0);
    }

    /** given @p subs a substring of the current string, get the
     * portion of the current string to the right of it */
    C4_ALWAYS_INLINE C4_PURE basic_substring right_of(ro_substr const subs) const noexcept
    {
        C4_ASSERT(is_super(subs) || subs.empty());
        auto sse = subs.end();
        auto b = begin();
        auto e = end();
        if(sse >= b && sse <= e)
            return sub(static_cast<size_t>(sse - b), static_cast<size_t>(e - sse));
        else
            return sub(0, 0);
    }

    /** @} */

public:

    /** @name Removing characters (trim()) / patterns (strip()) from the tips of the string */
    /** @{ */

    /** trim left */
    basic_substring triml(const C c) const
    {
        if( ! empty())
        {
            size_t pos = first_not_of(c);
            if(pos != npos)
                return sub(pos);
        }
        return sub(0, 0);
    }
    /** trim left ANY of the characters.
     * @see stripl() to remove a pattern from the left */
    basic_substring triml(ro_substr chars) const
    {
        if( ! empty())
        {
            size_t pos = first_not_of(chars);
            if(pos != npos)
                return sub(pos);
        }
        return sub(0, 0);
    }

    /** trim the character c from the right */
    basic_substring trimr(const C c) const
    {
        if( ! empty())
        {
            size_t pos = last_not_of(c, npos);
            if(pos != npos)
                return sub(0, pos+1);
        }
        return sub(0, 0);
    }
    /** trim right ANY of the characters
     * @see stripr() to remove a pattern from the right  */
    basic_substring trimr(ro_substr chars) const
    {
        if( ! empty())
        {
            size_t pos = last_not_of(chars, npos);
            if(pos != npos)
                return sub(0, pos+1);
        }
        return sub(0, 0);
    }

    /** trim the character c left and right */
    basic_substring trim(const C c) const
    {
        return triml(c).trimr(c);
    }
    /** trim left and right ANY of the characters
     * @see strip() to remove a pattern from the left and right */
    basic_substring trim(ro_substr const chars) const
    {
        return triml(chars).trimr(chars);
    }

    /** remove a pattern from the left
     * @see triml() to remove characters*/
    basic_substring stripl(ro_substr pattern) const
    {
        if( ! begins_with(pattern))
            return *this;
        return sub(pattern.len < len ? pattern.len : len);
    }

    /** remove a pattern from the right
     * @see trimr() to remove characters*/
    basic_substring stripr(ro_substr pattern) const
    {
        if( ! ends_with(pattern))
            return *this;
        return left_of(len - (pattern.len < len ? pattern.len : len));
    }

    /** @} */

public:

    /** @name Lookup methods */
    /** @{ */

    inline size_t find(const C c, size_t start_pos=0) const
    {
        return first_of(c, start_pos);
    }
    inline size_t find(ro_substr pattern, size_t start_pos=0) const
    {
        C4_ASSERT(start_pos == npos || (start_pos >= 0 && start_pos <= len));
        if(len < pattern.len) return npos;
        for(size_t i = start_pos, e = len - pattern.len + 1; i < e; ++i)
        {
            bool gotit = true;
            for(size_t j = 0; j < pattern.len; ++j)
            {
                C4_ASSERT(i + j < len);
                if(str[i + j] != pattern.str[j])
                {
                    gotit = false;
                    break;
                }
            }
            if(gotit)
            {
                return i;
            }
        }
        return npos;
    }

public:

    /** count the number of occurrences of c */
    inline size_t count(const C c, size_t pos=0) const
    {
        C4_ASSERT(pos >= 0 && pos <= len);
        size_t num = 0;
        pos = find(c, pos);
        while(pos != npos)
        {
            ++num;
            pos = find(c, pos + 1);
        }
        return num;
    }

    /** count the number of occurrences of s */
    inline size_t count(ro_substr c, size_t pos=0) const
    {
        C4_ASSERT(pos >= 0 && pos <= len);
        size_t num = 0;
        pos = find(c, pos);
        while(pos != npos)
        {
            ++num;
            pos = find(c, pos + c.len);
        }
        return num;
    }

    /** get the substr consisting of the first occurrence of @p c after @p pos, or an empty substr if none occurs */
    inline basic_substring select(const C c, size_t pos=0) const
    {
        pos = find(c, pos);
        return pos != npos ? sub(pos, 1) : basic_substring();
    }

    /** get the substr consisting of the first occurrence of @p pattern after @p pos, or an empty substr if none occurs */
    inline basic_substring select(ro_substr pattern, size_t pos=0) const
    {
        pos = find(pattern, pos);
        return pos != npos ? sub(pos, pattern.len) : basic_substring();
    }

public:

    struct first_of_any_result
    {
        size_t which;
        size_t pos;
        inline operator bool() const { return which != NONE && pos != npos; }
    };

    first_of_any_result first_of_any(ro_substr s0, ro_substr s1) const
    {
        ro_substr s[2] = {s0, s1};
        return first_of_any_iter(&s[0], &s[0] + 2);
    }

    first_of_any_result first_of_any(ro_substr s0, ro_substr s1, ro_substr s2) const
    {
        ro_substr s[3] = {s0, s1, s2};
        return first_of_any_iter(&s[0], &s[0] + 3);
    }

    first_of_any_result first_of_any(ro_substr s0, ro_substr s1, ro_substr s2, ro_substr s3) const
    {
        ro_substr s[4] = {s0, s1, s2, s3};
        return first_of_any_iter(&s[0], &s[0] + 4);
    }

    first_of_any_result first_of_any(ro_substr s0, ro_substr s1, ro_substr s2, ro_substr s3, ro_substr s4) const
    {
        ro_substr s[5] = {s0, s1, s2, s3, s4};
        return first_of_any_iter(&s[0], &s[0] + 5);
    }

    template<class It>
    first_of_any_result first_of_any_iter(It first_span, It last_span) const
    {
        for(size_t i = 0; i < len; ++i)
        {
            size_t curr = 0;
            for(It it = first_span; it != last_span; ++curr, ++it)
            {
                auto const& chars = *it;
                if((i + chars.len) > len) continue;
                bool gotit = true;
                for(size_t j = 0; j < chars.len; ++j)
                {
                    C4_ASSERT(i + j < len);
                    if(str[i + j] != chars[j])
                    {
                        gotit = false;
                        break;
                    }
                }
                if(gotit)
                {
                    return {curr, i};
                }
            }
        }
        return {NONE, npos};
    }

public:

    /** true if the first character of the string is @p c */
    bool begins_with(const C c) const
    {
        return len > 0 ? str[0] == c : false;
    }

    /** true if the first @p num characters of the string are @p c */
    bool begins_with(const C c, size_t num) const
    {
        if(len < num)
        {
            return false;
        }
        for(size_t i = 0; i < num; ++i)
        {
            if(str[i] != c)
            {
                return false;
            }
        }
        return true;
    }

    /** true if the string begins with the given @p pattern */
    bool begins_with(ro_substr pattern) const
    {
        if(len < pattern.len)
        {
            return false;
        }
        for(size_t i = 0; i < pattern.len; ++i)
        {
            if(str[i] != pattern[i])
            {
                return false;
            }
        }
        return true;
    }

    /** true if the first character of the string is any of the given @p chars */
    bool begins_with_any(ro_substr chars) const
    {
        if(len == 0)
        {
            return false;
        }
        for(size_t i = 0; i < chars.len; ++i)
        {
            if(str[0] == chars.str[i])
            {
                return true;
            }
        }
        return false;
    }

    /** true if the last character of the string is @p c */
    bool ends_with(const C c) const
    {
        return len > 0 ? str[len-1] == c : false;
    }

    /** true if the last @p num characters of the string are @p c */
    bool ends_with(const C c, size_t num) const
    {
        if(len < num)
        {
            return false;
        }
        for(size_t i = len - num; i < len; ++i)
        {
            if(str[i] != c)
            {
                return false;
            }
        }
        return true;
    }

    /** true if the string ends with the given @p pattern */
    bool ends_with(ro_substr pattern) const
    {
        if(len < pattern.len)
        {
            return false;
        }
        for(size_t i = 0, s = len-pattern.len; i < pattern.len; ++i)
        {
            if(str[s+i] != pattern[i])
            {
                return false;
            }
        }
        return true;
    }

    /** true if the last character of the string is any of the given @p chars */
    bool ends_with_any(ro_substr chars) const
    {
        if(len == 0)
        {
            return false;
        }
        for(size_t i = 0; i < chars.len; ++i)
        {
            if(str[len - 1] == chars[i])
            {
                return true;
            }
        }
        return false;
    }

public:

    /** @return the first position where c is found in the string, or npos if none is found */
    size_t first_of(const C c, size_t start=0) const
    {
        C4_ASSERT(start == npos || (start >= 0 && start <= len));
        for(size_t i = start; i < len; ++i)
        {
            if(str[i] == c)
                return i;
        }
        return npos;
    }

    /** @return the last position where c is found in the string, or npos if none is found */
    size_t last_of(const C c, size_t start=npos) const
    {
        C4_ASSERT(start == npos || (start >= 0 && start <= len));
        if(start == npos)
            start = len;
        for(size_t i = start-1; i != size_t(-1); --i)
        {
            if(str[i] == c)
                return i;
        }
        return npos;
    }

    /** @return the first position where ANY of the chars is found in the string, or npos if none is found */
    size_t first_of(ro_substr chars, size_t start=0) const
    {
        C4_ASSERT(start == npos || (start >= 0 && start <= len));
        for(size_t i = start; i < len; ++i)
        {
            for(size_t j = 0; j < chars.len; ++j)
            {
                if(str[i] == chars[j])
                    return i;
            }
        }
        return npos;
    }

    /** @return the last position where ANY of the chars is found in the string, or npos if none is found */
    size_t last_of(ro_substr chars, size_t start=npos) const
    {
        C4_ASSERT(start == npos || (start >= 0 && start <= len));
        if(start == npos)
            start = len;
        for(size_t i = start-1; i != size_t(-1); --i)
        {
            for(size_t j = 0; j < chars.len; ++j)
            {
                if(str[i] == chars[j])
                    return i;
            }
        }
        return npos;
    }

public:

    size_t first_not_of(const C c) const
    {
        for(size_t i = 0; i < len; ++i)
        {
            if(str[i] != c)
                return i;
        }
        return npos;
    }

    size_t first_not_of(const C c, size_t start) const
    {
        C4_ASSERT((start >= 0 && start <= len) || (start == len && len == 0));
        for(size_t i = start; i < len; ++i)
        {
            if(str[i] != c)
                return i;
        }
        return npos;
    }

    size_t last_not_of(const C c) const
    {
        for(size_t i = len-1; i != size_t(-1); --i)
        {
            if(str[i] != c)
                return i;
        }
        return npos;
    }

    size_t last_not_of(const C c, size_t start) const
    {
        C4_ASSERT(start == npos || (start >= 0 && start <= len));
        if(start == npos)
            start = len;
        for(size_t i = start-1; i != size_t(-1); --i)
        {
            if(str[i] != c)
                return i;
        }
        return npos;
    }

    size_t first_not_of(ro_substr chars) const
    {
        for(size_t i = 0; i < len; ++i)
        {
            bool gotit = true;
            for(size_t j = 0; j < chars.len; ++j)
            {
                if(str[i] == chars.str[j])
                {
                    gotit = false;
                    break;
                }
            }
            if(gotit)
            {
                return i;
            }
        }
        return npos;
    }

    size_t first_not_of(ro_substr chars, size_t start) const
    {
        C4_ASSERT((start >= 0 && start <= len) || (start == len && len == 0));
        for(size_t i = start; i < len; ++i)
        {
            bool gotit = true;
            for(size_t j = 0; j < chars.len; ++j)
            {
                if(str[i] == chars.str[j])
                {
                    gotit = false;
                    break;
                }
            }
            if(gotit)
            {
                return i;
            }
        }
        return npos;
    }

    size_t last_not_of(ro_substr chars) const
    {
        for(size_t i = len-1; i != size_t(-1); --i)
        {
            bool gotit = true;
            for(size_t j = 0; j < chars.len; ++j)
            {
                if(str[i] == chars.str[j])
                {
                    gotit = false;
                    break;
                }
            }
            if(gotit)
            {
                return i;
            }
        }
        return npos;
    }

    size_t last_not_of(ro_substr chars, size_t start) const
    {
        C4_ASSERT(start == npos || (start >= 0 && start <= len));
        if(start == npos)
            start = len;
        for(size_t i = start-1; i != size_t(-1); --i)
        {
            bool gotit = true;
            for(size_t j = 0; j < chars.len; ++j)
            {
                if(str[i] == chars.str[j])
                {
                    gotit = false;
                    break;
                }
            }
            if(gotit)
            {
                return i;
            }
        }
        return npos;
    }

    /** @} */

public:

    /** @name Range lookup methods */
    /** @{ */

    /** get the range delimited by an open-close pair of characters.
     * @note There must be no nested pairs.
     * @note No checks for escapes are performed. */
    basic_substring pair_range(CC open, CC close) const
    {
        size_t b = find(open);
        if(b == npos)
            return basic_substring();
        size_t e = find(close, b+1);
        if(e == npos)
            return basic_substring();
        basic_substring ret = range(b, e+1);
        C4_ASSERT(ret.sub(1).find(open) == npos);
        return ret;
    }

    /** get the range delimited by a single open-close character (eg, quotes).
     * @note The open-close character can be escaped. */
    basic_substring pair_range_esc(CC open_close, CC escape=CC('\\'))
    {
        size_t b = find(open_close);
        if(b == npos) return basic_substring();
        for(size_t i = b+1; i < len; ++i)
        {
            CC c = str[i];
            if(c == open_close)
            {
                if(str[i-1] != escape)
                {
                    return range(b, i+1);
                }
            }
        }
        return basic_substring();
    }

    /** get the range delimited by an open-close pair of characters,
     * with possibly nested occurrences. No checks for escapes are
     * performed. */
    basic_substring pair_range_nested(CC open, CC close) const
    {
        size_t b = find(open);
        if(b == npos) return basic_substring();
        size_t e, curr = b+1, count = 0;
        const char both[] = {open, close, '\0'};
        while((e = first_of(both, curr)) != npos)
        {
            if(str[e] == open)
            {
                ++count;
                curr = e+1;
            }
            else if(str[e] == close)
            {
                if(count == 0) return range(b, e+1);
                --count;
                curr = e+1;
            }
        }
        return basic_substring();
    }

    basic_substring unquoted() const
    {
        constexpr const C dq('"'), sq('\'');
        if(len >= 2 && (str[len - 2] != C('\\')) &&
           ((begins_with(sq) && ends_with(sq))
            ||
            (begins_with(dq) && ends_with(dq))))
        {
            return range(1, len -1);
        }
        return *this;
    }

    /** @} */

public:

    /** @name Number-matching query methods */
    /** @{ */

    /** @return true if the substring contents are a floating-point or integer number.
     * @note any leading or trailing whitespace will return false. */
    bool is_number() const
    {
        if(empty() || (first_non_empty_span().empty()))
            return false;
        if(first_uint_span() == *this)
            return true;
        if(first_int_span() == *this)
            return true;
        if(first_real_span() == *this)
            return true;
        return false;
    }

    /** @return true if the substring contents are a real number.
     * @note any leading or trailing whitespace will return false. */
    bool is_real() const
    {
        if(empty() || (first_non_empty_span().empty()))
            return false;
        if(first_real_span() == *this)
            return true;
        return false;
    }

    /** @return true if the substring contents are an integer number.
     * @note any leading or trailing whitespace will return false. */
    bool is_integer() const
    {
        if(empty() || (first_non_empty_span().empty()))
            return false;
        if(first_uint_span() == *this)
            return true;
        if(first_int_span() == *this)
            return true;
        return false;
    }

    /** @return true if the substring contents are an unsigned integer number.
     * @note any leading or trailing whitespace will return false. */
    bool is_unsigned_integer() const
    {
        if(empty() || (first_non_empty_span().empty()))
            return false;
        if(first_uint_span() == *this)
            return true;
        return false;
    }

    /** get the first span consisting exclusively of non-empty characters */
    basic_substring first_non_empty_span() const
    {
        constexpr const ro_substr empty_chars(" \n\r\t");
        size_t pos = first_not_of(empty_chars);
        if(pos == npos)
            return first(0);
        auto ret = sub(pos);
        pos = ret.first_of(empty_chars);
        return ret.first(pos);
    }

    /** get the first span which can be interpreted as an unsigned integer */
    basic_substring first_uint_span() const
    {
        basic_substring ne = first_non_empty_span();
        if(ne.empty())
            return ne;
        if(ne.str[0] == '-')
            return first(0);
        size_t skip_start = size_t(ne.str[0] == '+');
        return ne._first_integral_span(skip_start);
    }

    /** get the first span which can be interpreted as a signed integer */
    basic_substring first_int_span() const
    {
        basic_substring ne = first_non_empty_span();
        if(ne.empty())
            return ne;
        size_t skip_start = size_t(ne.str[0] == '+' || ne.str[0] == '-');
        return ne._first_integral_span(skip_start);
    }

    basic_substring _first_integral_span(size_t skip_start) const
    {
        C4_ASSERT(!empty());
        if(skip_start == len)
            return first(0);
        C4_ASSERT(skip_start < len);
        if(len >= skip_start + 3)
        {
            if(str[skip_start] != '0')
            {
                for(size_t i = skip_start; i < len; ++i)
                {
                    char c = str[i];
                    if(c < '0' || c > '9')
                        return i > skip_start && _is_delim_char(c) ? first(i) : first(0);
                }
            }
            else
            {
                char next = str[skip_start + 1];
                if(next == 'x' || next == 'X')
                {
                    skip_start += 2;
                    for(size_t i = skip_start; i < len; ++i)
                    {
                        const char c = str[i];
                        if( ! _is_hex_char(c))
                            return i > skip_start && _is_delim_char(c) ? first(i) : first(0);
                    }
                    return *this;
                }
                else if(next == 'b' || next == 'B')
                {
                    skip_start += 2;
                    for(size_t i = skip_start; i < len; ++i)
                    {
                        const char c = str[i];
                        if(c != '0' && c != '1')
                            return i > skip_start && _is_delim_char(c) ? first(i) : first(0);
                    }
                    return *this;
                }
                else if(next == 'o' || next == 'O')
                {
                    skip_start += 2;
                    for(size_t i = skip_start; i < len; ++i)
                    {
                        const char c = str[i];
                        if(c < '0' || c > '7')
                            return i > skip_start && _is_delim_char(c) ? first(i) : first(0);
                    }
                    return *this;
                }
            }
        }
        // must be a decimal, or it is not a an number
        for(size_t i = skip_start; i < len; ++i)
        {
            const char c = str[i];
            if(c < '0' || c > '9')
                return i > skip_start && _is_delim_char(c) ? first(i) : first(0);
        }
        return *this;
    }

    /** get the first span which can be interpreted as a real (floating-point) number */
    basic_substring first_real_span() const
    {
        basic_substring ne = first_non_empty_span();
        if(ne.empty())
            return ne;
        const size_t skip_start = (ne.str[0] == '+' || ne.str[0] == '-');
        C4_ASSERT(skip_start == 0 || skip_start == 1);
        // if we have at least three digits after the leading sign, it
        // can be decimal, or hex, or bin or oct. Ex:
        // non-decimal: 0x0, 0b0, 0o0
        // decimal: 1.0, 10., 1e1, 100, inf, nan, infinity
        if(ne.len >= skip_start+3)
        {
            // if it does not have leading 0, it must be decimal, or it is not a real
            if(ne.str[skip_start] != '0')
            {
                if(ne.str[skip_start] == 'i') // is it infinity or inf?
                {
                    basic_substring word = ne._word_follows(skip_start + 1, "nfinity");
                    if(word.len)
                        return word;
                    return ne._word_follows(skip_start + 1, "nf");
                }
                else if(ne.str[skip_start] == 'n') // is it nan?
                {
                    return ne._word_follows(skip_start + 1, "an");
                }
                else // must be a decimal, or it is not a real
                {
                    return ne._first_real_span_dec(skip_start);
                }
            }
            else // starts with 0. is it 0x, 0b or 0o?
            {
                const char next = ne.str[skip_start + 1];
                // hexadecimal
                if(next == 'x' || next == 'X')
                    return ne._first_real_span_hex(skip_start + 2);
                // binary
                else if(next == 'b' || next == 'B')
                    return ne._first_real_span_bin(skip_start + 2);
                // octal
                else if(next == 'o' || next == 'O')
                    return ne._first_real_span_oct(skip_start + 2);
                // none of the above. may still be a decimal.
                else
                    return ne._first_real_span_dec(skip_start); // do not skip the 0.
            }
        }
        // less than 3 chars after the leading sign. It is either a
        // decimal or it is not a real. (cannot be any of 0x0, etc).
        return ne._first_real_span_dec(skip_start);
    }

    /** true if the character is a delimiter character *at the end* */
    static constexpr C4_ALWAYS_INLINE C4_CONST bool _is_delim_char(char c) noexcept
    {
        return c == ' ' || c == '\n'
            || c == ']' || c == ')'  || c == '}'
            || c == ',' || c == ';' || c == '\r' || c == '\t' || c == '\0';
    }

    /** true if the character is in [0-9a-fA-F] */
    static constexpr C4_ALWAYS_INLINE C4_CONST bool _is_hex_char(char c) noexcept
    {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
    }

    C4_NO_INLINE C4_PURE basic_substring _word_follows(size_t pos, csubstr word) const noexcept
    {
        size_t posend = pos + word.len;
        if(len >= posend && sub(pos, word.len) == word)
            if(len == posend || _is_delim_char(str[posend]))
                return first(posend);
        return first(0);
    }

    // this function is declared inside the class to avoid a VS error with __declspec(dllimport)
    C4_NO_INLINE C4_PURE basic_substring _first_real_span_dec(size_t pos) const noexcept
    {
        bool intchars = false;
        bool fracchars = false;
        bool powchars;
        // integral part
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(c >= '0' && c <= '9')
            {
                intchars = true;
            }
            else if(c == '.')
            {
                ++pos;
                goto fractional_part_dec;
            }
            else if(c == 'e' || c == 'E')
            {
                ++pos;
                goto power_part_dec;
            }
            else if(_is_delim_char(c))
            {
                return intchars ? first(pos) : first(0);
            }
            else
            {
                return first(0);
            }
        }
        // no . or p were found; this is either an integral number
        // or not a number at all
        return intchars ?
            *this :
            first(0);
    fractional_part_dec:
        C4_ASSERT(pos > 0);
        C4_ASSERT(str[pos - 1] == '.');
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(c >= '0' && c <= '9')
            {
                fracchars = true;
            }
            else if(c == 'e' || c == 'E')
            {
                ++pos;
                goto power_part_dec;
            }
            else if(_is_delim_char(c))
            {
                return intchars || fracchars ? first(pos) : first(0);
            }
            else
            {
                return first(0);
            }
        }
        return intchars || fracchars ?
            *this :
            first(0);
    power_part_dec:
        C4_ASSERT(pos > 0);
        C4_ASSERT(str[pos - 1] == 'e' || str[pos - 1] == 'E');
        // either digits, or +, or - are expected here, followed by more digits.
        if((len == pos) || ((!intchars) && (!fracchars)))
            return first(0);
        if(str[pos] == '-' || str[pos] == '+')
            ++pos; // skip the sign
        powchars = false;
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(c >= '0' && c <= '9')
                powchars = true;
            else if(powchars && _is_delim_char(c))
                return first(pos);
            else
                return first(0);
        }
        return powchars ? *this : first(0);
    }

    // this function is declared inside the class to avoid a VS error with __declspec(dllimport)
    C4_NO_INLINE C4_PURE basic_substring _first_real_span_hex(size_t pos) const noexcept
    {
        bool intchars = false;
        bool fracchars = false;
        bool powchars;
        // integral part
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(_is_hex_char(c))
            {
                intchars = true;
            }
            else if(c == '.')
            {
                ++pos;
                goto fractional_part_hex;
            }
            else if(c == 'p' || c == 'P')
            {
                ++pos;
                goto power_part_hex;
            }
            else if(_is_delim_char(c))
            {
                return intchars ? first(pos) : first(0);
            }
            else
            {
                return first(0);
            }
        }
        // no . or p were found; this is either an integral number
        // or not a number at all
        return intchars ?
            *this :
            first(0);
    fractional_part_hex:
        C4_ASSERT(pos > 0);
        C4_ASSERT(str[pos - 1] == '.');
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(_is_hex_char(c))
            {
                fracchars = true;
            }
            else if(c == 'p' || c == 'P')
            {
                ++pos;
                goto power_part_hex;
            }
            else if(_is_delim_char(c))
            {
                return intchars || fracchars ? first(pos) : first(0);
            }
            else
            {
                return first(0);
            }
        }
        return intchars || fracchars ?
            *this :
            first(0);
    power_part_hex:
        C4_ASSERT(pos > 0);
        C4_ASSERT(str[pos - 1] == 'p' || str[pos - 1] == 'P');
        // either a + or a - is expected here, followed by more chars.
        // also, using (pos+1) in this check will cause an early
        // return when no more chars follow the sign.
        if(len <= (pos+1) || (str[pos] != '+' && str[pos] != '-') || ((!intchars) && (!fracchars)))
            return first(0);
        ++pos; // this was the sign.
        // ... so the (pos+1) ensures that we enter the loop and
        // hence that there exist chars in the power part
        powchars = false;
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(c >= '0' && c <= '9')
                powchars = true;
            else if(powchars && _is_delim_char(c))
                return first(pos);
            else
                return first(0);
        }
        return *this;
    }

    // this function is declared inside the class to avoid a VS error with __declspec(dllimport)
    C4_NO_INLINE C4_PURE basic_substring _first_real_span_bin(size_t pos) const noexcept
    {
        bool intchars = false;
        bool fracchars = false;
        bool powchars;
        // integral part
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(c == '0' || c == '1')
            {
                intchars = true;
            }
            else if(c == '.')
            {
                ++pos;
                goto fractional_part_bin;
            }
            else if(c == 'p' || c == 'P')
            {
                ++pos;
                goto power_part_bin;
            }
            else if(_is_delim_char(c))
            {
                return intchars ? first(pos) : first(0);
            }
            else
            {
                return first(0);
            }
        }
        // no . or p were found; this is either an integral number
        // or not a number at all
        return intchars ?
            *this :
            first(0);
    fractional_part_bin:
        C4_ASSERT(pos > 0);
        C4_ASSERT(str[pos - 1] == '.');
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(c == '0' || c == '1')
            {
                fracchars = true;
            }
            else if(c == 'p' || c == 'P')
            {
                ++pos;
                goto power_part_bin;
            }
            else if(_is_delim_char(c))
            {
                return intchars || fracchars ? first(pos) : first(0);
            }
            else
            {
                return first(0);
            }
        }
        return intchars || fracchars ?
            *this :
            first(0);
    power_part_bin:
        C4_ASSERT(pos > 0);
        C4_ASSERT(str[pos - 1] == 'p' || str[pos - 1] == 'P');
        // either a + or a - is expected here, followed by more chars.
        // also, using (pos+1) in this check will cause an early
        // return when no more chars follow the sign.
        if(len <= (pos+1) || (str[pos] != '+' && str[pos] != '-') || ((!intchars) && (!fracchars)))
            return first(0);
        ++pos; // this was the sign.
        // ... so the (pos+1) ensures that we enter the loop and
        // hence that there exist chars in the power part
        powchars = false;
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(c >= '0' && c <= '9')
                powchars = true;
            else if(powchars && _is_delim_char(c))
                return first(pos);
            else
                return first(0);
        }
        return *this;
    }

    // this function is declared inside the class to avoid a VS error with __declspec(dllimport)
    C4_NO_INLINE C4_PURE basic_substring _first_real_span_oct(size_t pos) const noexcept
    {
        bool intchars = false;
        bool fracchars = false;
        bool powchars;
        // integral part
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(c >= '0' && c <= '7')
            {
                intchars = true;
            }
            else if(c == '.')
            {
                ++pos;
                goto fractional_part_oct;
            }
            else if(c == 'p' || c == 'P')
            {
                ++pos;
                goto power_part_oct;
            }
            else if(_is_delim_char(c))
            {
                return intchars ? first(pos) : first(0);
            }
            else
            {
                return first(0);
            }
        }
        // no . or p were found; this is either an integral number
        // or not a number at all
        return intchars ?
            *this :
            first(0);
    fractional_part_oct:
        C4_ASSERT(pos > 0);
        C4_ASSERT(str[pos - 1] == '.');
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(c >= '0' && c <= '7')
            {
                fracchars = true;
            }
            else if(c == 'p' || c == 'P')
            {
                ++pos;
                goto power_part_oct;
            }
            else if(_is_delim_char(c))
            {
                return intchars || fracchars ? first(pos) : first(0);
            }
            else
            {
                return first(0);
            }
        }
        return intchars || fracchars ?
            *this :
            first(0);
    power_part_oct:
        C4_ASSERT(pos > 0);
        C4_ASSERT(str[pos - 1] == 'p' || str[pos - 1] == 'P');
        // either a + or a - is expected here, followed by more chars.
        // also, using (pos+1) in this check will cause an early
        // return when no more chars follow the sign.
        if(len <= (pos+1) || (str[pos] != '+' && str[pos] != '-') || ((!intchars) && (!fracchars)))
            return first(0);
        ++pos; // this was the sign.
        // ... so the (pos+1) ensures that we enter the loop and
        // hence that there exist chars in the power part
        powchars = false;
        for( ; pos < len; ++pos)
        {
            const char c = str[pos];
            if(c >= '0' && c <= '9')
                powchars = true;
            else if(powchars && _is_delim_char(c))
                return first(pos);
            else
                return first(0);
        }
        return *this;
    }

    /** @} */

public:

    /** @name Splitting methods */
    /** @{ */

    /** returns true if the string has not been exhausted yet, meaning
     * it's ok to call next_split() again. When no instance of sep
     * exists in the string, returns the full string. When the input
     * is an empty string, the output string is the empty string. */
    bool next_split(C sep, size_t *C4_RESTRICT start_pos, basic_substring *C4_RESTRICT out) const
    {
        if(C4_LIKELY(*start_pos < len))
        {
            for(size_t i = *start_pos; i < len; i++)
            {
                if(str[i] == sep)
                {
                    out->assign(str + *start_pos, i - *start_pos);
                    *start_pos = i+1;
                    return true;
                }
            }
            out->assign(str + *start_pos, len - *start_pos);
            *start_pos = len + 1;
            return true;
        }
        else
        {
            bool valid = len > 0 && (*start_pos == len);
            if(valid && str && str[len-1] == sep)
            {
                out->assign(str + len, size_t(0)); // the cast is needed to prevent overload ambiguity
            }
            else
            {
                out->assign(str + len + 1, size_t(0)); // the cast is needed to prevent overload ambiguity
            }
            *start_pos = len + 1;
            return valid;
        }
    }

private:

    struct split_proxy_impl
    {
        struct split_iterator_impl
        {
            split_proxy_impl const* m_proxy;
            basic_substring m_str;
            size_t m_pos;
            NCC_ m_sep;

            split_iterator_impl(split_proxy_impl const* proxy, size_t pos, C sep)
                : m_proxy(proxy), m_pos(pos), m_sep(sep)
            {
                _tick();
            }

            void _tick()
            {
                m_proxy->m_str.next_split(m_sep, &m_pos, &m_str);
            }

            split_iterator_impl& operator++ () { _tick(); return *this; }
            split_iterator_impl  operator++ (int) { split_iterator_impl it = *this; _tick(); return it; }

            basic_substring& operator*  () { return  m_str; }
            basic_substring* operator-> () { return &m_str; }

            bool operator!= (split_iterator_impl const& that) const
            {
                return !(this->operator==(that));
            }
            bool operator== (split_iterator_impl const& that) const
            {
                C4_XASSERT((m_sep == that.m_sep) && "cannot compare split iterators with different separators");
                if(m_str.size() != that.m_str.size())
                    return false;
                if(m_str.data() != that.m_str.data())
                    return false;
                return m_pos == that.m_pos;
            }
        };

        basic_substring m_str;
        size_t m_start_pos;
        C m_sep;

        split_proxy_impl(basic_substring str_, size_t start_pos, C sep)
            : m_str(str_), m_start_pos(start_pos), m_sep(sep)
        {
        }

        split_iterator_impl begin() const
        {
            auto it = split_iterator_impl(this, m_start_pos, m_sep);
            return it;
        }
        split_iterator_impl end() const
        {
            size_t pos = m_str.size() + 1;
            auto it = split_iterator_impl(this, pos, m_sep);
            return it;
        }
    };

public:

    using split_proxy = split_proxy_impl;

    /** a view into the splits */
    split_proxy split(C sep, size_t start_pos=0) const
    {
        C4_XASSERT((start_pos >= 0 && start_pos < len) || empty());
        auto ss = sub(0, len);
        auto it = split_proxy(ss, start_pos, sep);
        return it;
    }

public:

    /** pop right: return the first split from the right. Use
     * gpop_left() to get the reciprocal part.
     */
    basic_substring pop_right(C sep=C('/'), bool skip_empty=false) const
    {
        if(C4_LIKELY(len > 1))
        {
            auto pos = last_of(sep);
            if(pos != npos)
            {
                if(pos + 1 < len) // does not end with sep
                {
                    return sub(pos + 1); // return from sep to end
                }
                else // the string ends with sep
                {
                    if( ! skip_empty)
                    {
                        return sub(pos + 1, 0);
                    }
                    auto ppos = last_not_of(sep); // skip repeated seps
                    if(ppos == npos) // the string is all made of seps
                    {
                        return sub(0, 0);
                    }
                    // find the previous sep
                    auto pos0 = last_of(sep, ppos);
                    if(pos0 == npos) // only the last sep exists
                    {
                        return sub(0); // return the full string (because skip_empty is true)
                    }
                    ++pos0;
                    return sub(pos0);
                }
            }
            else // no sep was found, return the full string
            {
                return *this;
            }
        }
        else if(len == 1)
        {
            if(begins_with(sep))
            {
                return sub(0, 0);
            }
            return *this;
        }
        else // an empty string
        {
            return basic_substring();
        }
    }

    /** return the first split from the left. Use gpop_right() to get
     * the reciprocal part. */
    basic_substring pop_left(C sep = C('/'), bool skip_empty=false) const
    {
        if(C4_LIKELY(len > 1))
        {
            auto pos = first_of(sep);
            if(pos != npos)
            {
                if(pos > 0)  // does not start with sep
                {
                    return sub(0, pos); //  return everything up to it
                }
                else  // the string starts with sep
                {
                    if( ! skip_empty)
                    {
                        return sub(0, 0);
                    }
                    auto ppos = first_not_of(sep); // skip repeated seps
                    if(ppos == npos) // the string is all made of seps
                    {
                        return sub(0, 0);
                    }
                    // find the next sep
                    auto pos0 = first_of(sep, ppos);
                    if(pos0 == npos) // only the first sep exists
                    {
                        return sub(0); // return the full string (because skip_empty is true)
                    }
                    C4_XASSERT(pos0 > 0);
                    // return everything up to the second sep
                    return sub(0, pos0);
                }
            }
            else // no sep was found, return the full string
            {
                return sub(0);
            }
        }
        else if(len == 1)
        {
            if(begins_with(sep))
            {
                return sub(0, 0);
            }
            return sub(0);
        }
        else // an empty string
        {
            return basic_substring();
        }
    }

public:

    /** greedy pop left. eg, csubstr("a/b/c").gpop_left('/')="c" */
    basic_substring gpop_left(C sep = C('/'), bool skip_empty=false) const
    {
        auto ss = pop_right(sep, skip_empty);
        ss = left_of(ss);
        if(ss.find(sep) != npos)
        {
            if(ss.ends_with(sep))
            {
                if(skip_empty)
                {
                    ss = ss.trimr(sep);
                }
                else
                {
                    ss = ss.sub(0, ss.len-1); // safe to subtract because ends_with(sep) is true
                }
            }
        }
        return ss;
    }

    /** greedy pop right. eg, csubstr("a/b/c").gpop_right('/')="a" */
    basic_substring gpop_right(C sep = C('/'), bool skip_empty=false) const
    {
        auto ss = pop_left(sep, skip_empty);
        ss = right_of(ss);
        if(ss.find(sep) != npos)
        {
            if(ss.begins_with(sep))
            {
                if(skip_empty)
                {
                    ss = ss.triml(sep);
                }
                else
                {
                    ss = ss.sub(1);
                }
            }
        }
        return ss;
    }

    /** @} */

public:

    /** @name Path-like manipulation methods */
    /** @{ */

    basic_substring basename(C sep=C('/')) const
    {
        auto ss = pop_right(sep, /*skip_empty*/true);
        ss = ss.trimr(sep);
        return ss;
    }

    basic_substring dirname(C sep=C('/')) const
    {
        auto ss = basename(sep);
        ss = ss.empty() ? *this : left_of(ss);
        return ss;
    }

    C4_ALWAYS_INLINE basic_substring name_wo_extshort() const
    {
        return gpop_left('.');
    }

    C4_ALWAYS_INLINE basic_substring name_wo_extlong() const
    {
        return pop_left('.');
    }

    C4_ALWAYS_INLINE basic_substring extshort() const
    {
        return pop_right('.');
    }

    C4_ALWAYS_INLINE basic_substring extlong() const
    {
        return gpop_right('.');
    }

    /** @} */

public:

    /** @name Content-modification methods (only for non-const C) */
    /** @{ */

    /** convert the string to upper-case
     * @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(void) toupper()
    {
        for(size_t i = 0; i < len; ++i)
        {
            str[i] = static_cast<C>(::toupper(str[i]));
        }
    }

    /** convert the string to lower-case
     * @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(void) tolower()
    {
        for(size_t i = 0; i < len; ++i)
        {
            str[i] = static_cast<C>(::tolower(str[i]));
        }
    }

public:

    /** fill the entire contents with the given @p val
     * @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(void) fill(C val)
    {
        for(size_t i = 0; i < len; ++i)
        {
            str[i] = val;
        }
    }

public:

    /** set the current substring to a copy of the given csubstr
     * @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(void) copy_from(ro_substr that, size_t ifirst=0, size_t num=npos)
    {
        C4_ASSERT(ifirst >= 0 && ifirst <= len);
        num = num != npos ? num : len - ifirst;
        num = num < that.len ? num : that.len;
        C4_ASSERT(ifirst + num >= 0 && ifirst + num <= len);
        // calling memcpy with null strings is undefined behavior
        // and will wreak havoc in calling code's branches.
        // see https://github.com/biojppm/rapidyaml/pull/264#issuecomment-1262133637
        if(num)
            memcpy(str + sizeof(C) * ifirst, that.str, sizeof(C) * num);
    }

public:

    /** reverse in place
     * @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(void) reverse()
    {
        if(len == 0) return;
        detail::_do_reverse(str, str + len - 1);
    }

    /** revert a subpart in place
     * @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(void) reverse_sub(size_t ifirst, size_t num)
    {
        C4_ASSERT(ifirst >= 0 && ifirst <= len);
        C4_ASSERT(ifirst + num >= 0 && ifirst + num <= len);
        if(num == 0) return;
        detail::_do_reverse(str + ifirst, str + ifirst + num - 1);
    }

    /** revert a range in place
     * @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(void) reverse_range(size_t ifirst, size_t ilast)
    {
        C4_ASSERT(ifirst >= 0 && ifirst <= len);
        C4_ASSERT(ilast  >= 0 && ilast  <= len);
        if(ifirst == ilast) return;
        detail::_do_reverse(str + ifirst, str + ilast - 1);
    }

public:

    /** erase part of the string. eg, with char s[] = "0123456789",
     * substr(s).erase(3, 2) = "01256789", and s is now "01245678989"
     * @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(basic_substring) erase(size_t pos, size_t num)
    {
        C4_ASSERT(pos >= 0 && pos+num <= len);
        size_t num_to_move = len - pos - num;
        memmove(str + pos, str + pos + num, sizeof(C) * num_to_move);
        return basic_substring{str, len - num};
    }

    /** @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(basic_substring) erase_range(size_t first, size_t last)
    {
        C4_ASSERT(first <= last);
        return erase(first, static_cast<size_t>(last-first));
    }

    /** erase a part of the string.
     * @note @p sub must be a substring of this string
     * @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(basic_substring) erase(ro_substr sub)
    {
        C4_ASSERT(is_super(sub));
        C4_ASSERT(sub.str >= str);
        return erase(static_cast<size_t>(sub.str - str), sub.len);
    }

public:

    /** replace every occurrence of character @p value with the character @p repl
     * @return the number of characters that were replaced
     * @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(size_t) replace(C value, C repl, size_t pos=0)
    {
        C4_ASSERT((pos >= 0 && pos <= len) || pos == npos);
        size_t did_it = 0;
        while((pos = find(value, pos)) != npos)
        {
            str[pos++] = repl;
            ++did_it;
        }
        return did_it;
    }

    /** replace every occurrence of each character in @p value with
     * the character @p repl.
     * @return the number of characters that were replaced
     * @note this method requires that the string memory is writeable and is SFINAEd out for const C */
    C4_REQUIRE_RW(size_t) replace(ro_substr chars, C repl, size_t pos=0)
    {
        C4_ASSERT((pos >= 0 && pos <= len) || pos == npos);
        size_t did_it = 0;
        while((pos = first_of(chars, pos)) != npos)
        {
            str[pos++] = repl;
            ++did_it;
        }
        return did_it;
    }

    /** replace @p pattern with @p repl, and write the result into
     * @p dst. pattern and repl don't need equal sizes.
     *
     * @return the required size for dst. No overflow occurs if
     * dst.len is smaller than the required size; this can be used to
     * determine the required size for an existing container. */
    size_t replace_all(rw_substr dst, ro_substr pattern, ro_substr repl, size_t pos=0) const
    {
        C4_ASSERT( ! pattern.empty()); //!< @todo relax this precondition
        C4_ASSERT( ! this  ->overlaps(dst)); //!< @todo relax this precondition
        C4_ASSERT( ! pattern.overlaps(dst));
        C4_ASSERT( ! repl   .overlaps(dst));
        C4_ASSERT((pos >= 0 && pos <= len) || pos == npos);
        C4_SUPPRESS_WARNING_GCC_PUSH
        C4_SUPPRESS_WARNING_GCC("-Warray-bounds")  // gcc11 has a false positive here
        #if (!defined(__clang__)) && (defined(__GNUC__) && (__GNUC__ >= 7))
        C4_SUPPRESS_WARNING_GCC("-Wstringop-overflow")  // gcc11 has a false positive here
        #endif
        #define _c4append(first, last)                                  \
            {                                                           \
                C4_ASSERT((last) >= (first));                           \
                size_t num = static_cast<size_t>((last) - (first));     \
                if(num > 0 && sz + num <= dst.len)                      \
                {                                                       \
                    memcpy(dst.str + sz, first, num * sizeof(C));       \
                }                                                       \
                sz += num;                                              \
            }
        size_t sz = 0;
        size_t b = pos;
        _c4append(str, str + pos);
        do {
            size_t e = find(pattern, b);
            if(e == npos)
            {
                _c4append(str + b, str + len);
                break;
            }
            _c4append(str + b, str + e);
            _c4append(repl.begin(), repl.end());
            b = e + pattern.size();
        } while(b < len && b != npos);
        return sz;
        #undef _c4append
        C4_SUPPRESS_WARNING_GCC_POP
    }

    /** @} */

}; // template class basic_substring


#undef C4_REQUIRE_RW


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


/** @defgroup doc_substr_adapters substr adapters
 *
 * to_substr() and to_csubstr() is used in generic code like
 * format(), and allow adding construction of substrings from new
 * types like containers.
 * @{ */


/** neutral version for use in generic code */
C4_ALWAYS_INLINE substr to_substr(substr s) noexcept { return s; }
/** neutral version for use in generic code */
C4_ALWAYS_INLINE csubstr to_csubstr(substr s) noexcept { return s; }
/** neutral version for use in generic code */
C4_ALWAYS_INLINE csubstr to_csubstr(csubstr s) noexcept { return s; }


template<size_t N>
C4_ALWAYS_INLINE substr
to_substr(char (&s)[N]) noexcept { substr ss(s, N-1); return ss; }
template<size_t N>
C4_ALWAYS_INLINE csubstr
to_csubstr(const char (&s)[N]) noexcept { csubstr ss(s, N-1); return ss; }


/** @note this overload uses SFINAE to prevent it from overriding the array overload
 * @see For a more detailed explanation on why the plain overloads cannot
 * coexist, see http://cplusplus.bordoon.com/specializeForCharacterArrays.html */
template<class U>
C4_ALWAYS_INLINE typename std::enable_if<std::is_same<U, char*>::value, substr>::type
to_substr(U s) noexcept { substr ss(s); return ss; }
/** @note this overload uses SFINAE to prevent it from overriding the array overload
 * @see For a more detailed explanation on why the plain overloads cannot
 * coexist, see http://cplusplus.bordoon.com/specializeForCharacterArrays.html */
template<class U>
C4_ALWAYS_INLINE typename std::enable_if<std::is_same<U, const char*>::value || std::is_same<U, char*>::value, csubstr>::type
to_csubstr(U s) noexcept { csubstr ss(s); return ss; }


/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @defgroup doc_substr_cmp substr comparison operators
 * @{ */

template<typename C, size_t N> inline bool operator== (const char (&s)[N], basic_substring<C> const that) noexcept { return that.compare(s, N-1) == 0; }
template<typename C, size_t N> inline bool operator!= (const char (&s)[N], basic_substring<C> const that) noexcept { return that.compare(s, N-1) != 0; }
template<typename C, size_t N> inline bool operator<  (const char (&s)[N], basic_substring<C> const that) noexcept { return that.compare(s, N-1) >  0; }
template<typename C, size_t N> inline bool operator>  (const char (&s)[N], basic_substring<C> const that) noexcept { return that.compare(s, N-1) <  0; }
template<typename C, size_t N> inline bool operator<= (const char (&s)[N], basic_substring<C> const that) noexcept { return that.compare(s, N-1) >= 0; }
template<typename C, size_t N> inline bool operator>= (const char (&s)[N], basic_substring<C> const that) noexcept { return that.compare(s, N-1) <= 0; }

template<typename C> inline bool operator== (const char c, basic_substring<C> const that) noexcept { return that.compare(c) == 0; }
template<typename C> inline bool operator!= (const char c, basic_substring<C> const that) noexcept { return that.compare(c) != 0; }
template<typename C> inline bool operator<  (const char c, basic_substring<C> const that) noexcept { return that.compare(c) >  0; }
template<typename C> inline bool operator>  (const char c, basic_substring<C> const that) noexcept { return that.compare(c) <  0; }
template<typename C> inline bool operator<= (const char c, basic_substring<C> const that) noexcept { return that.compare(c) >= 0; }
template<typename C> inline bool operator>= (const char c, basic_substring<C> const that) noexcept { return that.compare(c) <= 0; }

/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/* C4_SUBSTR_NO_OSTREAM_LSHIFT doctest does not deal well with
 * template operator<<
 * @see https://github.com/onqtam/doctest/pull/431 */
#ifndef C4_SUBSTR_NO_OSTREAM_LSHIFT
#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wsign-conversion"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wsign-conversion"
#endif

/** output the string to a stream */
template<class OStream, class C>
inline OStream& operator<< (OStream& os, basic_substring<C> s)
{
    os.write(s.str, s.len);
    return os;
}

// this causes ambiguity
///** this is used by google test */
//template<class OStream, class C>
//inline void PrintTo(basic_substring<C> s, OStream* os)
//{
//    os->write(s.str, s.len);
//}

#ifdef __clang__
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif
#endif // !C4_SUBSTR_NO_OSTREAM_LSHIFT

/** @} */

} // namespace c4


#ifdef __clang__
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif

#endif /* _C4_SUBSTR_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/substr.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/ext/fast_float.hpp
// https://github.com/biojppm/c4core/src/c4/ext/fast_float.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_EXT_FAST_FLOAT_HPP_
#define _C4_EXT_FAST_FLOAT_HPP_

#if defined(_MSC_VER) && !defined(__clang__)
#   pragma warning(push)
#   pragma warning(disable: 4365) // '=': conversion from 'const _Ty' to 'fast_float::limb', signed/unsigned mismatch
#   pragma warning(disable: 4996) // snprintf/scanf: this function or variable may be unsafe
#elif defined(__clang__) || defined(__APPLE_CC__) || defined(_LIBCPP_VERSION)
#   pragma clang diagnostic push
#   if (defined(__clang_major__) && (__clang_major__ >= 9)) || defined(__APPLE_CC__)
#       pragma clang diagnostic ignored "-Wfortify-source"
#   endif
#   pragma clang diagnostic ignored "-Wshift-count-overflow"
#   pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wnarrowing"
#   pragma GCC diagnostic ignored "-Wconversion"
#   pragma GCC diagnostic ignored "-Wuseless-cast"
#   pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

// fast_float by Daniel Lemire
// fast_float by João Paulo Magalhaes
//
//
// with contributions from Eugene Golushkov
// with contributions from Maksim Kita
// with contributions from Marcin Wojdyr
// with contributions from Neal Richardson
// with contributions from Tim Paine
// with contributions from Fabio Pellacini
// with contributions from Lénárd Szolnoki
// with contributions from Jan Pharago
// with contributions from Maya Warrier
// with contributions from Taha Khokhar
//
//
// MIT License Notice
//
//    MIT License
//    
//    Copyright (c) 2021 The fast_float authors
//    
//    Permission is hereby granted, free of charge, to any
//    person obtaining a copy of this software and associated
//    documentation files (the "Software"), to deal in the
//    Software without restriction, including without
//    limitation the rights to use, copy, modify, merge,
//    publish, distribute, sublicense, and/or sell copies of
//    the Software, and to permit persons to whom the Software
//    is furnished to do so, subject to the following
//    conditions:
//    
//    The above copyright notice and this permission notice
//    shall be included in all copies or substantial portions
//    of the Software.
//    
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF
//    ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
//    TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
//    PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
//    SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
//    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
//    IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//    DEALINGS IN THE SOFTWARE.
//

#ifndef FASTFLOAT_CONSTEXPR_FEATURE_DETECT_H
#define FASTFLOAT_CONSTEXPR_FEATURE_DETECT_H

#ifdef __has_include
#if __has_include(<version>)
#include <version>
#endif
#endif

// Testing for https://wg21.link/N3652, adopted in C++14
#if __cpp_constexpr >= 201304
#define FASTFLOAT_CONSTEXPR14 constexpr
#else
#define FASTFLOAT_CONSTEXPR14
#endif

#if defined(__cpp_lib_bit_cast) && __cpp_lib_bit_cast >= 201806L
#define FASTFLOAT_HAS_BIT_CAST 1
#else
#define FASTFLOAT_HAS_BIT_CAST 0
#endif

#if defined(__cpp_lib_is_constant_evaluated) && __cpp_lib_is_constant_evaluated >= 201811L
#define FASTFLOAT_HAS_IS_CONSTANT_EVALUATED 1
#else
#define FASTFLOAT_HAS_IS_CONSTANT_EVALUATED 0
#endif

// Testing for relevant C++20 constexpr library features
#if FASTFLOAT_HAS_IS_CONSTANT_EVALUATED \
    && FASTFLOAT_HAS_BIT_CAST \
    && __cpp_lib_constexpr_algorithms >= 201806L /*For std::copy and std::fill*/
#define FASTFLOAT_CONSTEXPR20 constexpr
#define FASTFLOAT_IS_CONSTEXPR 1
#else
#define FASTFLOAT_CONSTEXPR20
#define FASTFLOAT_IS_CONSTEXPR 0
#endif

#endif // FASTFLOAT_CONSTEXPR_FEATURE_DETECT_H

#ifndef FASTFLOAT_FLOAT_COMMON_H
#define FASTFLOAT_FLOAT_COMMON_H

#include <cfloat>
//included above:
//#include <cstdint>
#include <cassert>
//included above:
//#include <cstring>
//included above:
//#include <type_traits>
#include <system_error>
#ifdef __has_include
  #if __has_include(<stdfloat>) && (__cplusplus > 202002L || _MSVC_LANG > 202002L)
    #include <stdfloat>
  #endif
#endif

namespace fast_float {

#define FASTFLOAT_JSONFMT (1 << 5)
#define FASTFLOAT_FORTRANFMT (1 << 6)

enum chars_format {
  scientific = 1 << 0,
  fixed = 1 << 2,
  hex = 1 << 3,
  no_infnan = 1 << 4,
  // RFC 8259: https://datatracker.ietf.org/doc/html/rfc8259#section-6
  json = FASTFLOAT_JSONFMT | fixed | scientific | no_infnan,
  // Extension of RFC 8259 where, e.g., "inf" and "nan" are allowed.
  json_or_infnan = FASTFLOAT_JSONFMT | fixed | scientific,
  fortran = FASTFLOAT_FORTRANFMT | fixed | scientific,
  general = fixed | scientific
};

template <typename UC>
struct from_chars_result_t {
  UC const* ptr;
  std::errc ec;
};
using from_chars_result = from_chars_result_t<char>;

template <typename UC>
struct parse_options_t {
  constexpr explicit parse_options_t(chars_format fmt = chars_format::general,
    UC dot = UC('.'))
    : format(fmt), decimal_point(dot) {}

  /** Which number formats are accepted */
  chars_format format;
  /** The character used as decimal point */
  UC decimal_point;
};
using parse_options = parse_options_t<char>;

}

#if FASTFLOAT_HAS_BIT_CAST
#include <bit>
#endif

#if (defined(__x86_64) || defined(__x86_64__) || defined(_M_X64)   \
       || defined(__amd64) || defined(__aarch64__) || defined(_M_ARM64) \
       || defined(__MINGW64__)                                          \
       || defined(__s390x__)                                            \
       || (defined(__ppc64__) || defined(__PPC64__) || defined(__ppc64le__) || defined(__PPC64LE__)) \
       || defined(__loongarch64) )
#define FASTFLOAT_64BIT 1
#elif (defined(__i386) || defined(__i386__) || defined(_M_IX86)   \
     || defined(__arm__) || defined(_M_ARM) || defined(__ppc__)   \
     || defined(__MINGW32__) || defined(__EMSCRIPTEN__))
#define FASTFLOAT_32BIT 1
#else
  // Need to check incrementally, since SIZE_MAX is a size_t, avoid overflow.
  // We can never tell the register width, but the SIZE_MAX is a good approximation.
  // UINTPTR_MAX and INTPTR_MAX are optional, so avoid them for max portability.
  #if SIZE_MAX == 0xffff
    #error Unknown platform (16-bit, unsupported)
  #elif SIZE_MAX == 0xffffffff
    #define FASTFLOAT_32BIT 1
  #elif SIZE_MAX == 0xffffffffffffffff
    #define FASTFLOAT_64BIT 1
  #else
    #error Unknown platform (not 32-bit, not 64-bit?)
  #endif
#endif

#if ((defined(_WIN32) || defined(_WIN64)) && !defined(__clang__))
//included above:
//#include <intrin.h>
#endif

#if defined(_MSC_VER) && !defined(__clang__)
#define FASTFLOAT_VISUAL_STUDIO 1
#endif

#if defined __BYTE_ORDER__ && defined __ORDER_BIG_ENDIAN__
#define FASTFLOAT_IS_BIG_ENDIAN (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#elif defined _WIN32
#define FASTFLOAT_IS_BIG_ENDIAN 0
#else
#if defined(__APPLE__) || defined(__FreeBSD__)
#include <machine/endian.h>
#elif defined(sun) || defined(__sun)
#include <sys/byteorder.h>
#elif defined(__MVS__)
#include <sys/endian.h>
#else
#ifdef __has_include
#if __has_include(<endian.h>)
#include <endian.h>
#endif //__has_include(<endian.h>)
#endif //__has_include
#endif
#
#ifndef __BYTE_ORDER__
// safe choice
#define FASTFLOAT_IS_BIG_ENDIAN 0
#endif
#
#ifndef __ORDER_LITTLE_ENDIAN__
// safe choice
#define FASTFLOAT_IS_BIG_ENDIAN 0
#endif
#
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define FASTFLOAT_IS_BIG_ENDIAN 0
#else
#define FASTFLOAT_IS_BIG_ENDIAN 1
#endif
#endif

#if defined(__SSE2__) || \
  (defined(FASTFLOAT_VISUAL_STUDIO) && \
    (defined(_M_AMD64) || defined(_M_X64) || (defined(_M_IX86_FP) && _M_IX86_FP == 2)))
#define FASTFLOAT_SSE2 1
#endif

#if defined(__aarch64__) || defined(_M_ARM64)
#define FASTFLOAT_NEON 1
#endif

#if defined(FASTFLOAT_SSE2) || defined(FASTFLOAT_NEON)
#define FASTFLOAT_HAS_SIMD 1
#endif

#if defined(__GNUC__)
// disable -Wcast-align=strict (GCC only)
#define FASTFLOAT_SIMD_DISABLE_WARNINGS \
  _Pragma("GCC diagnostic push") \
  _Pragma("GCC diagnostic ignored \"-Wcast-align\"")
#else
#define FASTFLOAT_SIMD_DISABLE_WARNINGS
#endif

#if defined(__GNUC__)
#define FASTFLOAT_SIMD_RESTORE_WARNINGS \
  _Pragma("GCC diagnostic pop")
#else
#define FASTFLOAT_SIMD_RESTORE_WARNINGS
#endif



#ifdef FASTFLOAT_VISUAL_STUDIO
#define fastfloat_really_inline __forceinline
#else
#define fastfloat_really_inline inline __attribute__((always_inline))
#endif

#ifndef FASTFLOAT_ASSERT
#define FASTFLOAT_ASSERT(x)  { ((void)(x)); }
#endif

#ifndef FASTFLOAT_DEBUG_ASSERT
#define FASTFLOAT_DEBUG_ASSERT(x) { ((void)(x)); }
#endif

// rust style `try!()` macro, or `?` operator
#define FASTFLOAT_TRY(x) { if (!(x)) return false; }

#define FASTFLOAT_ENABLE_IF(...) typename std::enable_if<(__VA_ARGS__), int>::type


namespace fast_float {

fastfloat_really_inline constexpr bool cpp20_and_in_constexpr() {
#if FASTFLOAT_HAS_IS_CONSTANT_EVALUATED
  return std::is_constant_evaluated();
#else
  return false;
#endif
}

template <typename T>
fastfloat_really_inline constexpr bool is_supported_float_type() {
  return std::is_same<T, float>::value || std::is_same<T, double>::value
#if __STDCPP_FLOAT32_T__
    || std::is_same<T, std::float32_t>::value
#endif
#if __STDCPP_FLOAT64_T__
    || std::is_same<T, std::float64_t>::value
#endif
  ;
}

template <typename UC>
fastfloat_really_inline constexpr bool is_supported_char_type() {
  return
    std::is_same<UC, char>::value ||
    std::is_same<UC, wchar_t>::value ||
    std::is_same<UC, char16_t>::value ||
    std::is_same<UC, char32_t>::value;
}

// Compares two ASCII strings in a case insensitive manner.
template <typename UC>
inline FASTFLOAT_CONSTEXPR14 bool
fastfloat_strncasecmp(UC const * input1, UC const * input2, size_t length) {
  char running_diff{0};
  for (size_t i = 0; i < length; ++i) {
    running_diff |= (char(input1[i]) ^ char(input2[i]));
  }
  return (running_diff == 0) || (running_diff == 32);
}

#ifndef FLT_EVAL_METHOD
#error "FLT_EVAL_METHOD should be defined, please include cfloat."
#endif

// a pointer and a length to a contiguous block of memory
template <typename T>
struct span {
  const T* ptr;
  size_t length;
  constexpr span(const T* _ptr, size_t _length) : ptr(_ptr), length(_length) {}
  constexpr span() : ptr(nullptr), length(0) {}

  constexpr size_t len() const noexcept {
    return length;
  }

  FASTFLOAT_CONSTEXPR14 const T& operator[](size_t index) const noexcept {
    FASTFLOAT_DEBUG_ASSERT(index < length);
    return ptr[index];
  }
};

struct value128 {
  uint64_t low;
  uint64_t high;
  constexpr value128(uint64_t _low, uint64_t _high) : low(_low), high(_high) {}
  constexpr value128() : low(0), high(0) {}
};

/* Helper C++14 constexpr generic implementation of leading_zeroes */
fastfloat_really_inline FASTFLOAT_CONSTEXPR14
int leading_zeroes_generic(uint64_t input_num, int last_bit = 0) {
    if(input_num & uint64_t(0xffffffff00000000)) { input_num >>= 32; last_bit |= 32; }
    if(input_num & uint64_t(        0xffff0000)) { input_num >>= 16; last_bit |= 16; }
    if(input_num & uint64_t(            0xff00)) { input_num >>=  8; last_bit |=  8; }
    if(input_num & uint64_t(              0xf0)) { input_num >>=  4; last_bit |=  4; }
    if(input_num & uint64_t(               0xc)) { input_num >>=  2; last_bit |=  2; }
    if(input_num & uint64_t(               0x2)) { /* input_num >>=  1; */ last_bit |=  1; }
    return 63 - last_bit;
}

/* result might be undefined when input_num is zero */
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
int leading_zeroes(uint64_t input_num) {
  assert(input_num > 0);
  if (cpp20_and_in_constexpr()) {
    return leading_zeroes_generic(input_num);
  }
#ifdef FASTFLOAT_VISUAL_STUDIO
  #if defined(_M_X64) || defined(_M_ARM64)
  unsigned long leading_zero = 0;
  // Search the mask data from most significant bit (MSB)
  // to least significant bit (LSB) for a set bit (1).
  _BitScanReverse64(&leading_zero, input_num);
  return (int)(63 - leading_zero);
  #else
  return leading_zeroes_generic(input_num);
  #endif
#else
  return __builtin_clzll(input_num);
#endif
}

// slow emulation routine for 32-bit
fastfloat_really_inline constexpr uint64_t emulu(uint32_t x, uint32_t y) {
    return x * (uint64_t)y;
}

fastfloat_really_inline FASTFLOAT_CONSTEXPR14
uint64_t umul128_generic(uint64_t ab, uint64_t cd, uint64_t *hi) {
  uint64_t ad = emulu((uint32_t)(ab >> 32), (uint32_t)cd);
  uint64_t bd = emulu((uint32_t)ab, (uint32_t)cd);
  uint64_t adbc = ad + emulu((uint32_t)ab, (uint32_t)(cd >> 32));
  uint64_t adbc_carry = (uint64_t)(adbc < ad);
  uint64_t lo = bd + (adbc << 32);
  *hi = emulu((uint32_t)(ab >> 32), (uint32_t)(cd >> 32)) + (adbc >> 32) +
        (adbc_carry << 32) + (uint64_t)(lo < bd);
  return lo;
}

#ifdef FASTFLOAT_32BIT

// slow emulation routine for 32-bit
#if !defined(__MINGW64__)
fastfloat_really_inline FASTFLOAT_CONSTEXPR14
uint64_t _umul128(uint64_t ab, uint64_t cd, uint64_t *hi) {
  return umul128_generic(ab, cd, hi);
}
#endif // !__MINGW64__

#endif // FASTFLOAT_32BIT


// compute 64-bit a*b
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
value128 full_multiplication(uint64_t a, uint64_t b) {
  if (cpp20_and_in_constexpr()) {
    value128 answer;
    answer.low = umul128_generic(a, b, &answer.high);
    return answer;
  }
  value128 answer;
#if defined(_M_ARM64) && !defined(__MINGW32__)
  // ARM64 has native support for 64-bit multiplications, no need to emulate
  // But MinGW on ARM64 doesn't have native support for 64-bit multiplications
  answer.high = __umulh(a, b);
  answer.low = a * b;
#elif defined(FASTFLOAT_32BIT) || (defined(_WIN64) && !defined(__clang__))
  answer.low = _umul128(a, b, &answer.high); // _umul128 not available on ARM64
#elif defined(FASTFLOAT_64BIT) && defined(__SIZEOF_INT128__)
  __uint128_t r = ((__uint128_t)a) * b;
  answer.low = uint64_t(r);
  answer.high = uint64_t(r >> 64);
#else
  answer.low = umul128_generic(a, b, &answer.high);
#endif
  return answer;
}

struct adjusted_mantissa {
  uint64_t mantissa{0};
  int32_t power2{0}; // a negative value indicates an invalid result
  adjusted_mantissa() = default;
  constexpr bool operator==(const adjusted_mantissa &o) const {
    return mantissa == o.mantissa && power2 == o.power2;
  }
  constexpr bool operator!=(const adjusted_mantissa &o) const {
    return mantissa != o.mantissa || power2 != o.power2;
  }
};

// Bias so we can get the real exponent with an invalid adjusted_mantissa.
constexpr static int32_t invalid_am_bias = -0x8000;

// used for binary_format_lookup_tables<T>::max_mantissa
constexpr uint64_t constant_55555 = 5 * 5 * 5 * 5 * 5;

template <typename T, typename U = void>
struct binary_format_lookup_tables;

template <typename T> struct binary_format : binary_format_lookup_tables<T> {
  using equiv_uint = typename std::conditional<sizeof(T) == 4, uint32_t, uint64_t>::type;

  static inline constexpr int mantissa_explicit_bits();
  static inline constexpr int minimum_exponent();
  static inline constexpr int infinite_power();
  static inline constexpr int sign_index();
  static inline constexpr int min_exponent_fast_path(); // used when fegetround() == FE_TONEAREST
  static inline constexpr int max_exponent_fast_path();
  static inline constexpr int max_exponent_round_to_even();
  static inline constexpr int min_exponent_round_to_even();
  static inline constexpr uint64_t max_mantissa_fast_path(int64_t power);
  static inline constexpr uint64_t max_mantissa_fast_path(); // used when fegetround() == FE_TONEAREST
  static inline constexpr int largest_power_of_ten();
  static inline constexpr int smallest_power_of_ten();
  static inline constexpr T exact_power_of_ten(int64_t power);
  static inline constexpr size_t max_digits();
  static inline constexpr equiv_uint exponent_mask();
  static inline constexpr equiv_uint mantissa_mask();
  static inline constexpr equiv_uint hidden_bit_mask();
};

template <typename U>
struct binary_format_lookup_tables<double, U> {
  static constexpr double powers_of_ten[] = {
      1e0,  1e1,  1e2,  1e3,  1e4,  1e5,  1e6,  1e7,  1e8,  1e9,  1e10, 1e11,
      1e12, 1e13, 1e14, 1e15, 1e16, 1e17, 1e18, 1e19, 1e20, 1e21, 1e22};

  // Largest integer value v so that (5**index * v) <= 1<<53.
  // 0x10000000000000 == 1 << 53
  static constexpr uint64_t max_mantissa[] = {
      0x10000000000000,
      0x10000000000000 / 5,
      0x10000000000000 / (5 * 5),
      0x10000000000000 / (5 * 5 * 5),
      0x10000000000000 / (5 * 5 * 5 * 5),
      0x10000000000000 / (constant_55555),
      0x10000000000000 / (constant_55555 * 5),
      0x10000000000000 / (constant_55555 * 5 * 5),
      0x10000000000000 / (constant_55555 * 5 * 5 * 5),
      0x10000000000000 / (constant_55555 * 5 * 5 * 5 * 5),
      0x10000000000000 / (constant_55555 * constant_55555),
      0x10000000000000 / (constant_55555 * constant_55555 * 5),
      0x10000000000000 / (constant_55555 * constant_55555 * 5 * 5),
      0x10000000000000 / (constant_55555 * constant_55555 * 5 * 5 * 5),
      0x10000000000000 / (constant_55555 * constant_55555 * constant_55555),
      0x10000000000000 / (constant_55555 * constant_55555 * constant_55555 * 5),
      0x10000000000000 / (constant_55555 * constant_55555 * constant_55555 * 5 * 5),
      0x10000000000000 / (constant_55555 * constant_55555 * constant_55555 * 5 * 5 * 5),
      0x10000000000000 / (constant_55555 * constant_55555 * constant_55555 * 5 * 5 * 5 * 5),
      0x10000000000000 / (constant_55555 * constant_55555 * constant_55555 * constant_55555),
      0x10000000000000 / (constant_55555 * constant_55555 * constant_55555 * constant_55555 * 5),
      0x10000000000000 / (constant_55555 * constant_55555 * constant_55555 * constant_55555 * 5 * 5),
      0x10000000000000 / (constant_55555 * constant_55555 * constant_55555 * constant_55555 * 5 * 5 * 5),
      0x10000000000000 / (constant_55555 * constant_55555 * constant_55555 * constant_55555 * 5 * 5 * 5 * 5)};
};

template <typename U>
constexpr double binary_format_lookup_tables<double, U>::powers_of_ten[];

template <typename U>
constexpr uint64_t binary_format_lookup_tables<double, U>::max_mantissa[];

template <typename U>
struct binary_format_lookup_tables<float, U> {
  static constexpr float powers_of_ten[] = {1e0f, 1e1f, 1e2f, 1e3f, 1e4f, 1e5f,
                                     1e6f, 1e7f, 1e8f, 1e9f, 1e10f};

  // Largest integer value v so that (5**index * v) <= 1<<24.
  // 0x1000000 == 1<<24
  static constexpr uint64_t max_mantissa[] = {
        0x1000000,
        0x1000000 / 5,
        0x1000000 / (5 * 5),
        0x1000000 / (5 * 5 * 5),
        0x1000000 / (5 * 5 * 5 * 5),
        0x1000000 / (constant_55555),
        0x1000000 / (constant_55555 * 5),
        0x1000000 / (constant_55555 * 5 * 5),
        0x1000000 / (constant_55555 * 5 * 5 * 5),
        0x1000000 / (constant_55555 * 5 * 5 * 5 * 5),
        0x1000000 / (constant_55555 * constant_55555),
        0x1000000 / (constant_55555 * constant_55555 * 5)};
};

template <typename U>
constexpr float binary_format_lookup_tables<float, U>::powers_of_ten[];

template <typename U>
constexpr uint64_t binary_format_lookup_tables<float, U>::max_mantissa[];

template <> inline constexpr int binary_format<double>::min_exponent_fast_path() {
#if (FLT_EVAL_METHOD != 1) && (FLT_EVAL_METHOD != 0)
  return 0;
#else
  return -22;
#endif
}

template <> inline constexpr int binary_format<float>::min_exponent_fast_path() {
#if (FLT_EVAL_METHOD != 1) && (FLT_EVAL_METHOD != 0)
  return 0;
#else
  return -10;
#endif
}

template <> inline constexpr int binary_format<double>::mantissa_explicit_bits() {
  return 52;
}
template <> inline constexpr int binary_format<float>::mantissa_explicit_bits() {
  return 23;
}

template <> inline constexpr int binary_format<double>::max_exponent_round_to_even() {
  return 23;
}

template <> inline constexpr int binary_format<float>::max_exponent_round_to_even() {
  return 10;
}

template <> inline constexpr int binary_format<double>::min_exponent_round_to_even() {
  return -4;
}

template <> inline constexpr int binary_format<float>::min_exponent_round_to_even() {
  return -17;
}

template <> inline constexpr int binary_format<double>::minimum_exponent() {
  return -1023;
}
template <> inline constexpr int binary_format<float>::minimum_exponent() {
  return -127;
}

template <> inline constexpr int binary_format<double>::infinite_power() {
  return 0x7FF;
}
template <> inline constexpr int binary_format<float>::infinite_power() {
  return 0xFF;
}

template <> inline constexpr int binary_format<double>::sign_index() { return 63; }
template <> inline constexpr int binary_format<float>::sign_index() { return 31; }

template <> inline constexpr int binary_format<double>::max_exponent_fast_path() {
  return 22;
}
template <> inline constexpr int binary_format<float>::max_exponent_fast_path() {
  return 10;
}

template <> inline constexpr uint64_t binary_format<double>::max_mantissa_fast_path() {
  return uint64_t(2) << mantissa_explicit_bits();
}
template <> inline constexpr uint64_t binary_format<double>::max_mantissa_fast_path(int64_t power) {
  // caller is responsible to ensure that
  // power >= 0 && power <= 22
  //
  // Work around clang bug https://godbolt.org/z/zedh7rrhc
  return (void)max_mantissa[0], max_mantissa[power];
}
template <> inline constexpr uint64_t binary_format<float>::max_mantissa_fast_path() {
  return uint64_t(2) << mantissa_explicit_bits();
}
template <> inline constexpr uint64_t binary_format<float>::max_mantissa_fast_path(int64_t power) {
  // caller is responsible to ensure that
  // power >= 0 && power <= 10
  //
  // Work around clang bug https://godbolt.org/z/zedh7rrhc
  return (void)max_mantissa[0], max_mantissa[power];
}

template <>
inline constexpr double binary_format<double>::exact_power_of_ten(int64_t power) {
  // Work around clang bug https://godbolt.org/z/zedh7rrhc
  return (void)powers_of_ten[0], powers_of_ten[power];
}
template <>
inline constexpr float binary_format<float>::exact_power_of_ten(int64_t power) {
  // Work around clang bug https://godbolt.org/z/zedh7rrhc
  return (void)powers_of_ten[0], powers_of_ten[power];
}


template <>
inline constexpr int binary_format<double>::largest_power_of_ten() {
  return 308;
}
template <>
inline constexpr int binary_format<float>::largest_power_of_ten() {
  return 38;
}

template <>
inline constexpr int binary_format<double>::smallest_power_of_ten() {
  return -342;
}
template <>
inline constexpr int binary_format<float>::smallest_power_of_ten() {
  return -64;
}

template <> inline constexpr size_t binary_format<double>::max_digits() {
  return 769;
}
template <> inline constexpr size_t binary_format<float>::max_digits() {
  return 114;
}

template <> inline constexpr binary_format<float>::equiv_uint
    binary_format<float>::exponent_mask() {
  return 0x7F800000;
}
template <> inline constexpr binary_format<double>::equiv_uint
    binary_format<double>::exponent_mask() {
  return 0x7FF0000000000000;
}

template <> inline constexpr binary_format<float>::equiv_uint
    binary_format<float>::mantissa_mask() {
  return 0x007FFFFF;
}
template <> inline constexpr binary_format<double>::equiv_uint
    binary_format<double>::mantissa_mask() {
  return 0x000FFFFFFFFFFFFF;
}

template <> inline constexpr binary_format<float>::equiv_uint
    binary_format<float>::hidden_bit_mask() {
  return 0x00800000;
}
template <> inline constexpr binary_format<double>::equiv_uint
    binary_format<double>::hidden_bit_mask() {
  return 0x0010000000000000;
}

template<typename T>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
void to_float(bool negative, adjusted_mantissa am, T &value) {
  using fastfloat_uint = typename binary_format<T>::equiv_uint;
  fastfloat_uint word = (fastfloat_uint)am.mantissa;
  word |= fastfloat_uint(am.power2) << binary_format<T>::mantissa_explicit_bits();
  word |= fastfloat_uint(negative) << binary_format<T>::sign_index();
#if FASTFLOAT_HAS_BIT_CAST
  value = std::bit_cast<T>(word);
#else
  ::memcpy(&value, &word, sizeof(T));
#endif
}

#ifdef FASTFLOAT_SKIP_WHITE_SPACE // disabled by default
template <typename = void>
struct space_lut {
  static constexpr bool value[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};

template <typename T>
constexpr bool space_lut<T>::value[];

inline constexpr bool is_space(uint8_t c) { return space_lut<>::value[c]; }
#endif

template<typename UC>
static constexpr uint64_t int_cmp_zeros()
{
    static_assert((sizeof(UC) == 1) || (sizeof(UC) == 2) || (sizeof(UC) == 4), "Unsupported character size");
    return (sizeof(UC) == 1) ? 0x3030303030303030 : (sizeof(UC) == 2) ? (uint64_t(UC('0')) << 48 | uint64_t(UC('0')) << 32 | uint64_t(UC('0')) << 16 | UC('0')) : (uint64_t(UC('0')) << 32 | UC('0'));
}
template<typename UC>
static constexpr int int_cmp_len()
{
    return sizeof(uint64_t) / sizeof(UC);
}
template<typename UC>
static constexpr UC const * str_const_nan()
{
    return nullptr;
}
template<>
constexpr char const * str_const_nan<char>()
{
    return "nan";
}
template<>
constexpr wchar_t const * str_const_nan<wchar_t>()
{
    return L"nan";
}
template<>
constexpr char16_t const * str_const_nan<char16_t>()
{
    return u"nan";
}
template<>
constexpr char32_t const * str_const_nan<char32_t>()
{
    return U"nan";
}
template<typename UC>
static constexpr UC const * str_const_inf()
{
    return nullptr;
}
template<>
constexpr char const * str_const_inf<char>()
{
    return "infinity";
}
template<>
constexpr wchar_t const * str_const_inf<wchar_t>()
{
    return L"infinity";
}
template<>
constexpr char16_t const * str_const_inf<char16_t>()
{
    return u"infinity";
}
template<>
constexpr char32_t const * str_const_inf<char32_t>()
{
    return U"infinity";
}


template <typename = void>
struct int_luts {
  static constexpr uint8_t chdigit[] = {
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 255, 255, 255, 255, 255, 255,
    255, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
    25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 255, 255, 255, 255, 255,
    255, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
    25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
    255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255
  };

  static constexpr size_t maxdigits_u64[] = {
    64, 41, 32, 28, 25, 23, 22, 21,
    20, 19, 18, 18, 17, 17, 16, 16,
    16, 16, 15, 15, 15, 15, 14, 14,
    14, 14, 14, 14, 14, 13, 13, 13,
    13, 13, 13
  };

  static constexpr uint64_t min_safe_u64[] = {
    9223372036854775808ull, 12157665459056928801ull, 4611686018427387904, 7450580596923828125, 4738381338321616896,
    3909821048582988049, 9223372036854775808ull, 12157665459056928801ull, 10000000000000000000ull, 5559917313492231481,
    2218611106740436992, 8650415919381337933, 2177953337809371136, 6568408355712890625, 1152921504606846976, 
    2862423051509815793, 6746640616477458432, 15181127029874798299ull, 1638400000000000000, 3243919932521508681,
    6221821273427820544, 11592836324538749809ull, 876488338465357824, 1490116119384765625, 2481152873203736576,
    4052555153018976267, 6502111422497947648, 10260628712958602189ull, 15943230000000000000ull, 787662783788549761,
    1152921504606846976, 1667889514952984961, 2386420683693101056, 3379220508056640625, 4738381338321616896
  };
};

template <typename T>
constexpr uint8_t int_luts<T>::chdigit[];

template <typename T>
constexpr size_t int_luts<T>::maxdigits_u64[];

template <typename T>
constexpr uint64_t int_luts<T>::min_safe_u64[];

template <typename UC>
fastfloat_really_inline
constexpr uint8_t ch_to_digit(UC c) { return int_luts<>::chdigit[static_cast<unsigned char>(c)]; }

fastfloat_really_inline
constexpr size_t max_digits_u64(int base) { return int_luts<>::maxdigits_u64[base - 2]; }

// If a u64 is exactly max_digits_u64() in length, this is
// the value below which it has definitely overflowed. 
fastfloat_really_inline
constexpr uint64_t min_safe_u64(int base) { return int_luts<>::min_safe_u64[base - 2]; }

} // namespace fast_float

#endif


#ifndef FASTFLOAT_FAST_FLOAT_H
#define FASTFLOAT_FAST_FLOAT_H


namespace fast_float {
/**
 * This function parses the character sequence [first,last) for a number. It parses floating-point numbers expecting
 * a locale-indepent format equivalent to what is used by std::strtod in the default ("C") locale.
 * The resulting floating-point value is the closest floating-point values (using either float or double),
 * using the "round to even" convention for values that would otherwise fall right in-between two values.
 * That is, we provide exact parsing according to the IEEE standard.
 *
 * Given a successful parse, the pointer (`ptr`) in the returned value is set to point right after the
 * parsed number, and the `value` referenced is set to the parsed value. In case of error, the returned
 * `ec` contains a representative error, otherwise the default (`std::errc()`) value is stored.
 *
 * The implementation does not throw and does not allocate memory (e.g., with `new` or `malloc`).
 *
 * Like the C++17 standard, the `fast_float::from_chars` functions take an optional last argument of
 * the type `fast_float::chars_format`. It is a bitset value: we check whether
 * `fmt & fast_float::chars_format::fixed` and `fmt & fast_float::chars_format::scientific` are set
 * to determine whether we allow the fixed point and scientific notation respectively.
 * The default is  `fast_float::chars_format::general` which allows both `fixed` and `scientific`.
 */
template<typename T, typename UC = char, typename = FASTFLOAT_ENABLE_IF(is_supported_float_type<T>())>
FASTFLOAT_CONSTEXPR20
from_chars_result_t<UC> from_chars(UC const * first, UC const * last,
                             T &value, chars_format fmt = chars_format::general)  noexcept;

/**
 * Like from_chars, but accepts an `options` argument to govern number parsing.
 */
template<typename T, typename UC = char>
FASTFLOAT_CONSTEXPR20
from_chars_result_t<UC> from_chars_advanced(UC const * first, UC const * last,
                                      T &value, parse_options_t<UC> options)  noexcept;
/**
* from_chars for integer types.
*/
template <typename T, typename UC = char, typename = FASTFLOAT_ENABLE_IF(!is_supported_float_type<T>())>
FASTFLOAT_CONSTEXPR20
from_chars_result_t<UC> from_chars(UC const * first, UC const * last, T& value, int base = 10) noexcept;

} // namespace fast_float
#endif // FASTFLOAT_FAST_FLOAT_H

#ifndef FASTFLOAT_ASCII_NUMBER_H
#define FASTFLOAT_ASCII_NUMBER_H

//included above:
//#include <cctype>
//included above:
//#include <cstdint>
//included above:
//#include <cstring>
#include <iterator>
//included above:
//#include <limits>
//included above:
//#include <type_traits>


#ifdef FASTFLOAT_SSE2
#include <emmintrin.h>
#endif

#ifdef FASTFLOAT_NEON
#include <arm_neon.h>
#endif

namespace fast_float {

template <typename UC>
fastfloat_really_inline constexpr bool has_simd_opt() {
#ifdef FASTFLOAT_HAS_SIMD
  return std::is_same<UC, char16_t>::value;
#else
  return false;
#endif
}

// Next function can be micro-optimized, but compilers are entirely
// able to optimize it well.
template <typename UC>
fastfloat_really_inline constexpr bool is_integer(UC c) noexcept {
  return !(c > UC('9') || c < UC('0'));
}

fastfloat_really_inline constexpr uint64_t byteswap(uint64_t val) {
  return (val & 0xFF00000000000000) >> 56
    | (val & 0x00FF000000000000) >> 40
    | (val & 0x0000FF0000000000) >> 24
    | (val & 0x000000FF00000000) >> 8
    | (val & 0x00000000FF000000) << 8
    | (val & 0x0000000000FF0000) << 24
    | (val & 0x000000000000FF00) << 40
    | (val & 0x00000000000000FF) << 56;
}

// Read 8 UC into a u64. Truncates UC if not char.
template <typename UC>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
uint64_t read8_to_u64(const UC *chars) {
  if (cpp20_and_in_constexpr() || !std::is_same<UC, char>::value) {
    uint64_t val = 0;
    for(int i = 0; i < 8; ++i) {
      val |= uint64_t(uint8_t(*chars)) << (i*8);
      ++chars;
    }
    return val;
  }
  uint64_t val;
  ::memcpy(&val, chars, sizeof(uint64_t));
#if FASTFLOAT_IS_BIG_ENDIAN == 1
  // Need to read as-if the number was in little-endian order.
  val = byteswap(val);
#endif
  return val;
}

#ifdef FASTFLOAT_SSE2

fastfloat_really_inline
uint64_t simd_read8_to_u64(const __m128i data) {
FASTFLOAT_SIMD_DISABLE_WARNINGS
  const __m128i packed = _mm_packus_epi16(data, data);
#ifdef FASTFLOAT_64BIT
  return uint64_t(_mm_cvtsi128_si64(packed));
#else
  uint64_t value;
  // Visual Studio + older versions of GCC don't support _mm_storeu_si64
  _mm_storel_epi64(reinterpret_cast<__m128i*>(&value), packed);
  return value;
#endif
FASTFLOAT_SIMD_RESTORE_WARNINGS
}

fastfloat_really_inline
uint64_t simd_read8_to_u64(const char16_t* chars) {
FASTFLOAT_SIMD_DISABLE_WARNINGS
  return simd_read8_to_u64(_mm_loadu_si128(reinterpret_cast<const __m128i*>(chars)));
FASTFLOAT_SIMD_RESTORE_WARNINGS
}

#elif defined(FASTFLOAT_NEON)


fastfloat_really_inline
uint64_t simd_read8_to_u64(const uint16x8_t data) {
FASTFLOAT_SIMD_DISABLE_WARNINGS
  uint8x8_t utf8_packed = vmovn_u16(data);
  return vget_lane_u64(vreinterpret_u64_u8(utf8_packed), 0);
FASTFLOAT_SIMD_RESTORE_WARNINGS
}

fastfloat_really_inline
uint64_t simd_read8_to_u64(const char16_t* chars) {
FASTFLOAT_SIMD_DISABLE_WARNINGS
  return simd_read8_to_u64(vld1q_u16(reinterpret_cast<const uint16_t*>(chars)));
FASTFLOAT_SIMD_RESTORE_WARNINGS
}

#endif // FASTFLOAT_SSE2

// MSVC SFINAE is broken pre-VS2017
#if defined(_MSC_VER) && _MSC_VER <= 1900
template <typename UC>
#else
template <typename UC, FASTFLOAT_ENABLE_IF(!has_simd_opt<UC>()) = 0>
#endif
// dummy for compile
uint64_t simd_read8_to_u64(UC const*) {
  return 0;
}

// credit  @aqrit
fastfloat_really_inline FASTFLOAT_CONSTEXPR14
uint32_t parse_eight_digits_unrolled(uint64_t val) {
  const uint64_t mask = 0x000000FF000000FF;
  const uint64_t mul1 = 0x000F424000000064; // 100 + (1000000ULL << 32)
  const uint64_t mul2 = 0x0000271000000001; // 1 + (10000ULL << 32)
  val -= 0x3030303030303030;
  val = (val * 10) + (val >> 8); // val = (val * 2561) >> 8;
  val = (((val & mask) * mul1) + (((val >> 16) & mask) * mul2)) >> 32;
  return uint32_t(val);
}


// Call this if chars are definitely 8 digits.
template <typename UC>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
uint32_t parse_eight_digits_unrolled(UC const * chars)  noexcept {
  if (cpp20_and_in_constexpr() || !has_simd_opt<UC>()) {
    return parse_eight_digits_unrolled(read8_to_u64(chars)); // truncation okay
  }
  return parse_eight_digits_unrolled(simd_read8_to_u64(chars));
}


// credit @aqrit
fastfloat_really_inline constexpr bool is_made_of_eight_digits_fast(uint64_t val)  noexcept {
  return !((((val + 0x4646464646464646) | (val - 0x3030303030303030)) &
     0x8080808080808080));
}


#ifdef FASTFLOAT_HAS_SIMD

// Call this if chars might not be 8 digits.
// Using this style (instead of is_made_of_eight_digits_fast() then parse_eight_digits_unrolled())
// ensures we don't load SIMD registers twice.
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
bool simd_parse_if_eight_digits_unrolled(const char16_t* chars, uint64_t& i) noexcept {
  if (cpp20_and_in_constexpr()) {
    return false;
  }   
#ifdef FASTFLOAT_SSE2
FASTFLOAT_SIMD_DISABLE_WARNINGS
  const __m128i data = _mm_loadu_si128(reinterpret_cast<const __m128i*>(chars));

  // (x - '0') <= 9
  // http://0x80.pl/articles/simd-parsing-int-sequences.html
  const __m128i t0 = _mm_add_epi16(data, _mm_set1_epi16(32720));
  const __m128i t1 = _mm_cmpgt_epi16(t0, _mm_set1_epi16(-32759));

  if (_mm_movemask_epi8(t1) == 0) {
    i = i * 100000000 + parse_eight_digits_unrolled(simd_read8_to_u64(data));
    return true;
  }
  else return false;
FASTFLOAT_SIMD_RESTORE_WARNINGS
#elif defined(FASTFLOAT_NEON)
FASTFLOAT_SIMD_DISABLE_WARNINGS
  const uint16x8_t data = vld1q_u16(reinterpret_cast<const uint16_t*>(chars));
  
  // (x - '0') <= 9
  // http://0x80.pl/articles/simd-parsing-int-sequences.html
  const uint16x8_t t0 = vsubq_u16(data, vmovq_n_u16('0'));
  const uint16x8_t mask = vcltq_u16(t0, vmovq_n_u16('9' - '0' + 1));

  if (vminvq_u16(mask) == 0xFFFF) {
    i = i * 100000000 + parse_eight_digits_unrolled(simd_read8_to_u64(data));
    return true;
  }
  else return false;
FASTFLOAT_SIMD_RESTORE_WARNINGS
#else
  (void)chars; (void)i;
  return false;
#endif // FASTFLOAT_SSE2
}

#endif // FASTFLOAT_HAS_SIMD

// MSVC SFINAE is broken pre-VS2017
#if defined(_MSC_VER) && _MSC_VER <= 1900
template <typename UC>
#else
template <typename UC, FASTFLOAT_ENABLE_IF(!has_simd_opt<UC>()) = 0>
#endif
// dummy for compile
bool simd_parse_if_eight_digits_unrolled(UC const*, uint64_t&) {
  return 0;
}


template <typename UC, FASTFLOAT_ENABLE_IF(!std::is_same<UC, char>::value) = 0>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
void loop_parse_if_eight_digits(const UC*& p, const UC* const pend, uint64_t& i) {
  if (!has_simd_opt<UC>()) {
    return;
  }
  while ((std::distance(p, pend) >= 8) && simd_parse_if_eight_digits_unrolled(p, i)) { // in rare cases, this will overflow, but that's ok
    p += 8;
  }
}

fastfloat_really_inline FASTFLOAT_CONSTEXPR20
void loop_parse_if_eight_digits(const char*& p, const char* const pend, uint64_t& i) {
  // optimizes better than parse_if_eight_digits_unrolled() for UC = char.
  while ((std::distance(p, pend) >= 8) && is_made_of_eight_digits_fast(read8_to_u64(p))) {
    i = i * 100000000 + parse_eight_digits_unrolled(read8_to_u64(p)); // in rare cases, this will overflow, but that's ok
    p += 8;
  }
}

template <typename UC>
struct parsed_number_string_t {
  int64_t exponent{0};
  uint64_t mantissa{0};
  UC const * lastmatch{nullptr};
  bool negative{false};
  bool valid{false};
  bool too_many_digits{false};
  // contains the range of the significant digits
  span<const UC> integer{};  // non-nullable
  span<const UC> fraction{}; // nullable
};

using byte_span = span<const char>;
using parsed_number_string = parsed_number_string_t<char>;

// Assuming that you use no more than 19 digits, this will
// parse an ASCII string.
template <typename UC>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
parsed_number_string_t<UC> parse_number_string(UC const *p, UC const * pend, parse_options_t<UC> options) noexcept {
  chars_format const fmt = options.format;
  UC const decimal_point = options.decimal_point;

  parsed_number_string_t<UC> answer;
  answer.valid = false;
  answer.too_many_digits = false;
  answer.negative = (*p == UC('-'));
#ifdef FASTFLOAT_ALLOWS_LEADING_PLUS // disabled by default
  if ((*p == UC('-')) || (!(fmt & FASTFLOAT_JSONFMT) && *p == UC('+'))) {
#else
  if (*p == UC('-')) { // C++17 20.19.3.(7.1) explicitly forbids '+' sign here
#endif
    ++p;
    if (p == pend) {
      return answer;
    }
    if (fmt & FASTFLOAT_JSONFMT) {
      if (!is_integer(*p)) { // a sign must be followed by an integer
        return answer;
      }    
    } else {
      if (!is_integer(*p) && (*p != decimal_point)) { // a sign must be followed by an integer or the dot
        return answer;
      }
    }
  }
  UC const * const start_digits = p;

  uint64_t i = 0; // an unsigned int avoids signed overflows (which are bad)

  while ((p != pend) && is_integer(*p)) {
    // a multiplication by 10 is cheaper than an arbitrary integer
    // multiplication
    i = 10 * i +
        uint64_t(*p - UC('0')); // might overflow, we will handle the overflow later
    ++p;
  }
  UC const * const end_of_integer_part = p;
  int64_t digit_count = int64_t(end_of_integer_part - start_digits);
  answer.integer = span<const UC>(start_digits, size_t(digit_count));
  if (fmt & FASTFLOAT_JSONFMT) {
    // at least 1 digit in integer part, without leading zeros
    if (digit_count == 0 || (start_digits[0] == UC('0') && digit_count > 1)) {
      return answer;
    }
  }

  int64_t exponent = 0;
  const bool has_decimal_point = (p != pend) && (*p == decimal_point);
  if (has_decimal_point) {
    ++p;
    UC const * before = p;
    // can occur at most twice without overflowing, but let it occur more, since
    // for integers with many digits, digit parsing is the primary bottleneck.
    loop_parse_if_eight_digits(p, pend, i);

    while ((p != pend) && is_integer(*p)) {
      uint8_t digit = uint8_t(*p - UC('0'));
      ++p;
      i = i * 10 + digit; // in rare cases, this will overflow, but that's ok
    }
    exponent = before - p;
    answer.fraction = span<const UC>(before, size_t(p - before));
    digit_count -= exponent;
  }
  if (fmt & FASTFLOAT_JSONFMT) {
    // at least 1 digit in fractional part
    if (has_decimal_point && exponent == 0) {
      return answer;
    }
  } 
  else if (digit_count == 0) { // we must have encountered at least one integer!
    return answer;
  }
  int64_t exp_number = 0;            // explicit exponential part
  if ( ((fmt & chars_format::scientific) &&
        (p != pend) &&
        ((UC('e') == *p) || (UC('E') == *p)))
       ||
       ((fmt & FASTFLOAT_FORTRANFMT) &&
        (p != pend) &&
        ((UC('+') == *p) || (UC('-') == *p) || (UC('d') == *p) || (UC('D') == *p)))) {
    UC const * location_of_e = p;
    if ((UC('e') == *p) || (UC('E') == *p) || (UC('d') == *p) || (UC('D') == *p)) {
      ++p;
    }
    bool neg_exp = false;
    if ((p != pend) && (UC('-') == *p)) {
      neg_exp = true;
      ++p;
    } else if ((p != pend) && (UC('+') == *p)) { // '+' on exponent is allowed by C++17 20.19.3.(7.1)
      ++p;
    }
    if ((p == pend) || !is_integer(*p)) {
      if(!(fmt & chars_format::fixed)) {
        // We are in error.
        return answer;
      }
      // Otherwise, we will be ignoring the 'e'.
      p = location_of_e;
    } else {
      while ((p != pend) && is_integer(*p)) {
        uint8_t digit = uint8_t(*p - UC('0'));
        if (exp_number < 0x10000000) {
          exp_number = 10 * exp_number + digit;
        }
        ++p;
      }
      if(neg_exp) { exp_number = - exp_number; }
      exponent += exp_number;
    }
  } else {
    // If it scientific and not fixed, we have to bail out.
    if((fmt & chars_format::scientific) && !(fmt & chars_format::fixed)) { return answer; }
  }
  answer.lastmatch = p;
  answer.valid = true;

  // If we frequently had to deal with long strings of digits,
  // we could extend our code by using a 128-bit integer instead
  // of a 64-bit integer. However, this is uncommon.
  //
  // We can deal with up to 19 digits.
  if (digit_count > 19) { // this is uncommon
    // It is possible that the integer had an overflow.
    // We have to handle the case where we have 0.0000somenumber.
    // We need to be mindful of the case where we only have zeroes...
    // E.g., 0.000000000...000.
    UC const * start = start_digits;
    while ((start != pend) && (*start == UC('0') || *start == decimal_point)) {
      if(*start == UC('0')) { digit_count --; }
      start++;
    }

    if (digit_count > 19) {
      answer.too_many_digits = true;
      // Let us start again, this time, avoiding overflows.
      // We don't need to check if is_integer, since we use the
      // pre-tokenized spans from above.
      i = 0;
      p = answer.integer.ptr;
      UC const* int_end = p + answer.integer.len();
      const uint64_t minimal_nineteen_digit_integer{ 1000000000000000000 };
      while ((i < minimal_nineteen_digit_integer) && (p != int_end)) {
        i = i * 10 + uint64_t(*p - UC('0'));
        ++p;
      }
      if (i >= minimal_nineteen_digit_integer) { // We have a big integers
        exponent = end_of_integer_part - p + exp_number;
      }
      else { // We have a value with a fractional component.
        p = answer.fraction.ptr;
        UC const* frac_end = p + answer.fraction.len();
        while ((i < minimal_nineteen_digit_integer) && (p != frac_end)) {
          i = i * 10 + uint64_t(*p - UC('0'));
          ++p;
        }
        exponent = answer.fraction.ptr - p + exp_number;
      }
      // We have now corrected both exponent and i, to a truncated value
    }
  }
  answer.exponent = exponent;
  answer.mantissa = i;
  return answer;
}

template <typename T, typename UC>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
from_chars_result_t<UC> parse_int_string(UC const* p, UC const* pend, T& value, int base) {
  from_chars_result_t<UC> answer;
  
  UC const* const first = p;

  bool negative = (*p == UC('-'));
  if (!std::is_signed<T>::value && negative) {
    answer.ec = std::errc::invalid_argument;
    answer.ptr = first;
    return answer;
  }
#ifdef FASTFLOAT_ALLOWS_LEADING_PLUS // disabled by default
  if ((*p == UC('-')) || (*p == UC('+'))) {
#else
  if (*p == UC('-')) {
#endif
    ++p;
  }

  UC const* const start_num = p;

  while (p!= pend && *p == UC('0')) {
    ++p; 
  }

  const bool has_leading_zeros = p > start_num;

  UC const* const start_digits = p;

  uint64_t i = 0;
  if (base == 10) {
    loop_parse_if_eight_digits(p, pend, i); // use SIMD if possible
  }
  while (p != pend) {
    uint8_t digit = ch_to_digit(*p);
    if (digit >= base) {
      break;
    }
    i = uint64_t(base) * i + digit; // might overflow, check this later
    p++; 
  }
  
  size_t digit_count = size_t(p - start_digits);

  if (digit_count == 0) {
    if (has_leading_zeros) {
      value = 0;
      answer.ec = std::errc();
      answer.ptr = p;
    }
    else {
      answer.ec = std::errc::invalid_argument;
      answer.ptr = first;
    }
    return answer; 
  }

  answer.ptr = p;

  // check u64 overflow
  size_t max_digits = max_digits_u64(base);
  if (digit_count > max_digits) {
    answer.ec = std::errc::result_out_of_range;
    return answer;
  }
  // this check can be eliminated for all other types, but they will all require a max_digits(base) equivalent
  if (digit_count == max_digits && i < min_safe_u64(base)) {
    answer.ec = std::errc::result_out_of_range;
    return answer;
  }

  // check other types overflow
  if (!std::is_same<T, uint64_t>::value) {
    if (i > uint64_t(std::numeric_limits<T>::max()) + uint64_t(negative)) {
      answer.ec = std::errc::result_out_of_range;
      return answer;
    }
  }

  if (negative) {
#ifdef FASTFLOAT_VISUAL_STUDIO
#pragma warning(push)
#pragma warning(disable: 4146) 
#endif
    // this weird workaround is required because:
    // - converting unsigned to signed when its value is greater than signed max is UB pre-C++23.
    // - reinterpret_casting (~i + 1) would work, but it is not constexpr
    // this is always optimized into a neg instruction (note: T is an integer type)
    value = T(-std::numeric_limits<T>::max() - T(i - uint64_t(std::numeric_limits<T>::max())));
#ifdef FASTFLOAT_VISUAL_STUDIO
#pragma warning(pop)
#endif
  }
  else { value = T(i); }

  answer.ec = std::errc();
  return answer;
}

} // namespace fast_float

#endif

#ifndef FASTFLOAT_FAST_TABLE_H
#define FASTFLOAT_FAST_TABLE_H

//included above:
//#include <cstdint>

namespace fast_float {

/**
 * When mapping numbers from decimal to binary,
 * we go from w * 10^q to m * 2^p but we have
 * 10^q = 5^q * 2^q, so effectively
 * we are trying to match
 * w * 2^q * 5^q to m * 2^p. Thus the powers of two
 * are not a concern since they can be represented
 * exactly using the binary notation, only the powers of five
 * affect the binary significand.
 */

/**
 * The smallest non-zero float (binary64) is 2^-1074.
 * We take as input numbers of the form w x 10^q where w < 2^64.
 * We have that w * 10^-343  <  2^(64-344) 5^-343 < 2^-1076.
 * However, we have that
 * (2^64-1) * 10^-342 =  (2^64-1) * 2^-342 * 5^-342 > 2^-1074.
 * Thus it is possible for a number of the form w * 10^-342 where
 * w is a 64-bit value to be a non-zero floating-point number.
 *********
 * Any number of form w * 10^309 where w>= 1 is going to be
 * infinite in binary64 so we never need to worry about powers
 * of 5 greater than 308.
 */
template <class unused = void>
struct powers_template {

constexpr static int smallest_power_of_five = binary_format<double>::smallest_power_of_ten();
constexpr static int largest_power_of_five = binary_format<double>::largest_power_of_ten();
constexpr static int number_of_entries = 2 * (largest_power_of_five - smallest_power_of_five + 1);
// Powers of five from 5^-342 all the way to 5^308 rounded toward one.
constexpr static uint64_t power_of_five_128[number_of_entries] = {
    0xeef453d6923bd65a,0x113faa2906a13b3f,
    0x9558b4661b6565f8,0x4ac7ca59a424c507,
    0xbaaee17fa23ebf76,0x5d79bcf00d2df649,
    0xe95a99df8ace6f53,0xf4d82c2c107973dc,
    0x91d8a02bb6c10594,0x79071b9b8a4be869,
    0xb64ec836a47146f9,0x9748e2826cdee284,
    0xe3e27a444d8d98b7,0xfd1b1b2308169b25,
    0x8e6d8c6ab0787f72,0xfe30f0f5e50e20f7,
    0xb208ef855c969f4f,0xbdbd2d335e51a935,
    0xde8b2b66b3bc4723,0xad2c788035e61382,
    0x8b16fb203055ac76,0x4c3bcb5021afcc31,
    0xaddcb9e83c6b1793,0xdf4abe242a1bbf3d,
    0xd953e8624b85dd78,0xd71d6dad34a2af0d,
    0x87d4713d6f33aa6b,0x8672648c40e5ad68,
    0xa9c98d8ccb009506,0x680efdaf511f18c2,
    0xd43bf0effdc0ba48,0x212bd1b2566def2,
    0x84a57695fe98746d,0x14bb630f7604b57,
    0xa5ced43b7e3e9188,0x419ea3bd35385e2d,
    0xcf42894a5dce35ea,0x52064cac828675b9,
    0x818995ce7aa0e1b2,0x7343efebd1940993,
    0xa1ebfb4219491a1f,0x1014ebe6c5f90bf8,
    0xca66fa129f9b60a6,0xd41a26e077774ef6,
    0xfd00b897478238d0,0x8920b098955522b4,
    0x9e20735e8cb16382,0x55b46e5f5d5535b0,
    0xc5a890362fddbc62,0xeb2189f734aa831d,
    0xf712b443bbd52b7b,0xa5e9ec7501d523e4,
    0x9a6bb0aa55653b2d,0x47b233c92125366e,
    0xc1069cd4eabe89f8,0x999ec0bb696e840a,
    0xf148440a256e2c76,0xc00670ea43ca250d,
    0x96cd2a865764dbca,0x380406926a5e5728,
    0xbc807527ed3e12bc,0xc605083704f5ecf2,
    0xeba09271e88d976b,0xf7864a44c633682e,
    0x93445b8731587ea3,0x7ab3ee6afbe0211d,
    0xb8157268fdae9e4c,0x5960ea05bad82964,
    0xe61acf033d1a45df,0x6fb92487298e33bd,
    0x8fd0c16206306bab,0xa5d3b6d479f8e056,
    0xb3c4f1ba87bc8696,0x8f48a4899877186c,
    0xe0b62e2929aba83c,0x331acdabfe94de87,
    0x8c71dcd9ba0b4925,0x9ff0c08b7f1d0b14,
    0xaf8e5410288e1b6f,0x7ecf0ae5ee44dd9,
    0xdb71e91432b1a24a,0xc9e82cd9f69d6150,
    0x892731ac9faf056e,0xbe311c083a225cd2,
    0xab70fe17c79ac6ca,0x6dbd630a48aaf406,
    0xd64d3d9db981787d,0x92cbbccdad5b108,
    0x85f0468293f0eb4e,0x25bbf56008c58ea5,
    0xa76c582338ed2621,0xaf2af2b80af6f24e,
    0xd1476e2c07286faa,0x1af5af660db4aee1,
    0x82cca4db847945ca,0x50d98d9fc890ed4d,
    0xa37fce126597973c,0xe50ff107bab528a0,
    0xcc5fc196fefd7d0c,0x1e53ed49a96272c8,
    0xff77b1fcbebcdc4f,0x25e8e89c13bb0f7a,
    0x9faacf3df73609b1,0x77b191618c54e9ac,
    0xc795830d75038c1d,0xd59df5b9ef6a2417,
    0xf97ae3d0d2446f25,0x4b0573286b44ad1d,
    0x9becce62836ac577,0x4ee367f9430aec32,
    0xc2e801fb244576d5,0x229c41f793cda73f,
    0xf3a20279ed56d48a,0x6b43527578c1110f,
    0x9845418c345644d6,0x830a13896b78aaa9,
    0xbe5691ef416bd60c,0x23cc986bc656d553,
    0xedec366b11c6cb8f,0x2cbfbe86b7ec8aa8,
    0x94b3a202eb1c3f39,0x7bf7d71432f3d6a9,
    0xb9e08a83a5e34f07,0xdaf5ccd93fb0cc53,
    0xe858ad248f5c22c9,0xd1b3400f8f9cff68,
    0x91376c36d99995be,0x23100809b9c21fa1,
    0xb58547448ffffb2d,0xabd40a0c2832a78a,
    0xe2e69915b3fff9f9,0x16c90c8f323f516c,
    0x8dd01fad907ffc3b,0xae3da7d97f6792e3,
    0xb1442798f49ffb4a,0x99cd11cfdf41779c,
    0xdd95317f31c7fa1d,0x40405643d711d583,
    0x8a7d3eef7f1cfc52,0x482835ea666b2572,
    0xad1c8eab5ee43b66,0xda3243650005eecf,
    0xd863b256369d4a40,0x90bed43e40076a82,
    0x873e4f75e2224e68,0x5a7744a6e804a291,
    0xa90de3535aaae202,0x711515d0a205cb36,
    0xd3515c2831559a83,0xd5a5b44ca873e03,
    0x8412d9991ed58091,0xe858790afe9486c2,
    0xa5178fff668ae0b6,0x626e974dbe39a872,
    0xce5d73ff402d98e3,0xfb0a3d212dc8128f,
    0x80fa687f881c7f8e,0x7ce66634bc9d0b99,
    0xa139029f6a239f72,0x1c1fffc1ebc44e80,
    0xc987434744ac874e,0xa327ffb266b56220,
    0xfbe9141915d7a922,0x4bf1ff9f0062baa8,
    0x9d71ac8fada6c9b5,0x6f773fc3603db4a9,
    0xc4ce17b399107c22,0xcb550fb4384d21d3,
    0xf6019da07f549b2b,0x7e2a53a146606a48,
    0x99c102844f94e0fb,0x2eda7444cbfc426d,
    0xc0314325637a1939,0xfa911155fefb5308,
    0xf03d93eebc589f88,0x793555ab7eba27ca,
    0x96267c7535b763b5,0x4bc1558b2f3458de,
    0xbbb01b9283253ca2,0x9eb1aaedfb016f16,
    0xea9c227723ee8bcb,0x465e15a979c1cadc,
    0x92a1958a7675175f,0xbfacd89ec191ec9,
    0xb749faed14125d36,0xcef980ec671f667b,
    0xe51c79a85916f484,0x82b7e12780e7401a,
    0x8f31cc0937ae58d2,0xd1b2ecb8b0908810,
    0xb2fe3f0b8599ef07,0x861fa7e6dcb4aa15,
    0xdfbdcece67006ac9,0x67a791e093e1d49a,
    0x8bd6a141006042bd,0xe0c8bb2c5c6d24e0,
    0xaecc49914078536d,0x58fae9f773886e18,
    0xda7f5bf590966848,0xaf39a475506a899e,
    0x888f99797a5e012d,0x6d8406c952429603,
    0xaab37fd7d8f58178,0xc8e5087ba6d33b83,
    0xd5605fcdcf32e1d6,0xfb1e4a9a90880a64,
    0x855c3be0a17fcd26,0x5cf2eea09a55067f,
    0xa6b34ad8c9dfc06f,0xf42faa48c0ea481e,
    0xd0601d8efc57b08b,0xf13b94daf124da26,
    0x823c12795db6ce57,0x76c53d08d6b70858,
    0xa2cb1717b52481ed,0x54768c4b0c64ca6e,
    0xcb7ddcdda26da268,0xa9942f5dcf7dfd09,
    0xfe5d54150b090b02,0xd3f93b35435d7c4c,
    0x9efa548d26e5a6e1,0xc47bc5014a1a6daf,
    0xc6b8e9b0709f109a,0x359ab6419ca1091b,
    0xf867241c8cc6d4c0,0xc30163d203c94b62,
    0x9b407691d7fc44f8,0x79e0de63425dcf1d,
    0xc21094364dfb5636,0x985915fc12f542e4,
    0xf294b943e17a2bc4,0x3e6f5b7b17b2939d,
    0x979cf3ca6cec5b5a,0xa705992ceecf9c42,
    0xbd8430bd08277231,0x50c6ff782a838353,
    0xece53cec4a314ebd,0xa4f8bf5635246428,
    0x940f4613ae5ed136,0x871b7795e136be99,
    0xb913179899f68584,0x28e2557b59846e3f,
    0xe757dd7ec07426e5,0x331aeada2fe589cf,
    0x9096ea6f3848984f,0x3ff0d2c85def7621,
    0xb4bca50b065abe63,0xfed077a756b53a9,
    0xe1ebce4dc7f16dfb,0xd3e8495912c62894,
    0x8d3360f09cf6e4bd,0x64712dd7abbbd95c,
    0xb080392cc4349dec,0xbd8d794d96aacfb3,
    0xdca04777f541c567,0xecf0d7a0fc5583a0,
    0x89e42caaf9491b60,0xf41686c49db57244,
    0xac5d37d5b79b6239,0x311c2875c522ced5,
    0xd77485cb25823ac7,0x7d633293366b828b,
    0x86a8d39ef77164bc,0xae5dff9c02033197,
    0xa8530886b54dbdeb,0xd9f57f830283fdfc,
    0xd267caa862a12d66,0xd072df63c324fd7b,
    0x8380dea93da4bc60,0x4247cb9e59f71e6d,
    0xa46116538d0deb78,0x52d9be85f074e608,
    0xcd795be870516656,0x67902e276c921f8b,
    0x806bd9714632dff6,0xba1cd8a3db53b6,
    0xa086cfcd97bf97f3,0x80e8a40eccd228a4,
    0xc8a883c0fdaf7df0,0x6122cd128006b2cd,
    0xfad2a4b13d1b5d6c,0x796b805720085f81,
    0x9cc3a6eec6311a63,0xcbe3303674053bb0,
    0xc3f490aa77bd60fc,0xbedbfc4411068a9c,
    0xf4f1b4d515acb93b,0xee92fb5515482d44,
    0x991711052d8bf3c5,0x751bdd152d4d1c4a,
    0xbf5cd54678eef0b6,0xd262d45a78a0635d,
    0xef340a98172aace4,0x86fb897116c87c34,
    0x9580869f0e7aac0e,0xd45d35e6ae3d4da0,
    0xbae0a846d2195712,0x8974836059cca109,
    0xe998d258869facd7,0x2bd1a438703fc94b,
    0x91ff83775423cc06,0x7b6306a34627ddcf,
    0xb67f6455292cbf08,0x1a3bc84c17b1d542,
    0xe41f3d6a7377eeca,0x20caba5f1d9e4a93,
    0x8e938662882af53e,0x547eb47b7282ee9c,
    0xb23867fb2a35b28d,0xe99e619a4f23aa43,
    0xdec681f9f4c31f31,0x6405fa00e2ec94d4,
    0x8b3c113c38f9f37e,0xde83bc408dd3dd04,
    0xae0b158b4738705e,0x9624ab50b148d445,
    0xd98ddaee19068c76,0x3badd624dd9b0957,
    0x87f8a8d4cfa417c9,0xe54ca5d70a80e5d6,
    0xa9f6d30a038d1dbc,0x5e9fcf4ccd211f4c,
    0xd47487cc8470652b,0x7647c3200069671f,
    0x84c8d4dfd2c63f3b,0x29ecd9f40041e073,
    0xa5fb0a17c777cf09,0xf468107100525890,
    0xcf79cc9db955c2cc,0x7182148d4066eeb4,
    0x81ac1fe293d599bf,0xc6f14cd848405530,
    0xa21727db38cb002f,0xb8ada00e5a506a7c,
    0xca9cf1d206fdc03b,0xa6d90811f0e4851c,
    0xfd442e4688bd304a,0x908f4a166d1da663,
    0x9e4a9cec15763e2e,0x9a598e4e043287fe,
    0xc5dd44271ad3cdba,0x40eff1e1853f29fd,
    0xf7549530e188c128,0xd12bee59e68ef47c,
    0x9a94dd3e8cf578b9,0x82bb74f8301958ce,
    0xc13a148e3032d6e7,0xe36a52363c1faf01,
    0xf18899b1bc3f8ca1,0xdc44e6c3cb279ac1,
    0x96f5600f15a7b7e5,0x29ab103a5ef8c0b9,
    0xbcb2b812db11a5de,0x7415d448f6b6f0e7,
    0xebdf661791d60f56,0x111b495b3464ad21,
    0x936b9fcebb25c995,0xcab10dd900beec34,
    0xb84687c269ef3bfb,0x3d5d514f40eea742,
    0xe65829b3046b0afa,0xcb4a5a3112a5112,
    0x8ff71a0fe2c2e6dc,0x47f0e785eaba72ab,
    0xb3f4e093db73a093,0x59ed216765690f56,
    0xe0f218b8d25088b8,0x306869c13ec3532c,
    0x8c974f7383725573,0x1e414218c73a13fb,
    0xafbd2350644eeacf,0xe5d1929ef90898fa,
    0xdbac6c247d62a583,0xdf45f746b74abf39,
    0x894bc396ce5da772,0x6b8bba8c328eb783,
    0xab9eb47c81f5114f,0x66ea92f3f326564,
    0xd686619ba27255a2,0xc80a537b0efefebd,
    0x8613fd0145877585,0xbd06742ce95f5f36,
    0xa798fc4196e952e7,0x2c48113823b73704,
    0xd17f3b51fca3a7a0,0xf75a15862ca504c5,
    0x82ef85133de648c4,0x9a984d73dbe722fb,
    0xa3ab66580d5fdaf5,0xc13e60d0d2e0ebba,
    0xcc963fee10b7d1b3,0x318df905079926a8,
    0xffbbcfe994e5c61f,0xfdf17746497f7052,
    0x9fd561f1fd0f9bd3,0xfeb6ea8bedefa633,
    0xc7caba6e7c5382c8,0xfe64a52ee96b8fc0,
    0xf9bd690a1b68637b,0x3dfdce7aa3c673b0,
    0x9c1661a651213e2d,0x6bea10ca65c084e,
    0xc31bfa0fe5698db8,0x486e494fcff30a62,
    0xf3e2f893dec3f126,0x5a89dba3c3efccfa,
    0x986ddb5c6b3a76b7,0xf89629465a75e01c,
    0xbe89523386091465,0xf6bbb397f1135823,
    0xee2ba6c0678b597f,0x746aa07ded582e2c,
    0x94db483840b717ef,0xa8c2a44eb4571cdc,
    0xba121a4650e4ddeb,0x92f34d62616ce413,
    0xe896a0d7e51e1566,0x77b020baf9c81d17,
    0x915e2486ef32cd60,0xace1474dc1d122e,
    0xb5b5ada8aaff80b8,0xd819992132456ba,
    0xe3231912d5bf60e6,0x10e1fff697ed6c69,
    0x8df5efabc5979c8f,0xca8d3ffa1ef463c1,
    0xb1736b96b6fd83b3,0xbd308ff8a6b17cb2,
    0xddd0467c64bce4a0,0xac7cb3f6d05ddbde,
    0x8aa22c0dbef60ee4,0x6bcdf07a423aa96b,
    0xad4ab7112eb3929d,0x86c16c98d2c953c6,
    0xd89d64d57a607744,0xe871c7bf077ba8b7,
    0x87625f056c7c4a8b,0x11471cd764ad4972,
    0xa93af6c6c79b5d2d,0xd598e40d3dd89bcf,
    0xd389b47879823479,0x4aff1d108d4ec2c3,
    0x843610cb4bf160cb,0xcedf722a585139ba,
    0xa54394fe1eedb8fe,0xc2974eb4ee658828,
    0xce947a3da6a9273e,0x733d226229feea32,
    0x811ccc668829b887,0x806357d5a3f525f,
    0xa163ff802a3426a8,0xca07c2dcb0cf26f7,
    0xc9bcff6034c13052,0xfc89b393dd02f0b5,
    0xfc2c3f3841f17c67,0xbbac2078d443ace2,
    0x9d9ba7832936edc0,0xd54b944b84aa4c0d,
    0xc5029163f384a931,0xa9e795e65d4df11,
    0xf64335bcf065d37d,0x4d4617b5ff4a16d5,
    0x99ea0196163fa42e,0x504bced1bf8e4e45,
    0xc06481fb9bcf8d39,0xe45ec2862f71e1d6,
    0xf07da27a82c37088,0x5d767327bb4e5a4c,
    0x964e858c91ba2655,0x3a6a07f8d510f86f,
    0xbbe226efb628afea,0x890489f70a55368b,
    0xeadab0aba3b2dbe5,0x2b45ac74ccea842e,
    0x92c8ae6b464fc96f,0x3b0b8bc90012929d,
    0xb77ada0617e3bbcb,0x9ce6ebb40173744,
    0xe55990879ddcaabd,0xcc420a6a101d0515,
    0x8f57fa54c2a9eab6,0x9fa946824a12232d,
    0xb32df8e9f3546564,0x47939822dc96abf9,
    0xdff9772470297ebd,0x59787e2b93bc56f7,
    0x8bfbea76c619ef36,0x57eb4edb3c55b65a,
    0xaefae51477a06b03,0xede622920b6b23f1,
    0xdab99e59958885c4,0xe95fab368e45eced,
    0x88b402f7fd75539b,0x11dbcb0218ebb414,
    0xaae103b5fcd2a881,0xd652bdc29f26a119,
    0xd59944a37c0752a2,0x4be76d3346f0495f,
    0x857fcae62d8493a5,0x6f70a4400c562ddb,
    0xa6dfbd9fb8e5b88e,0xcb4ccd500f6bb952,
    0xd097ad07a71f26b2,0x7e2000a41346a7a7,
    0x825ecc24c873782f,0x8ed400668c0c28c8,
    0xa2f67f2dfa90563b,0x728900802f0f32fa,
    0xcbb41ef979346bca,0x4f2b40a03ad2ffb9,
    0xfea126b7d78186bc,0xe2f610c84987bfa8,
    0x9f24b832e6b0f436,0xdd9ca7d2df4d7c9,
    0xc6ede63fa05d3143,0x91503d1c79720dbb,
    0xf8a95fcf88747d94,0x75a44c6397ce912a,
    0x9b69dbe1b548ce7c,0xc986afbe3ee11aba,
    0xc24452da229b021b,0xfbe85badce996168,
    0xf2d56790ab41c2a2,0xfae27299423fb9c3,
    0x97c560ba6b0919a5,0xdccd879fc967d41a,
    0xbdb6b8e905cb600f,0x5400e987bbc1c920,
    0xed246723473e3813,0x290123e9aab23b68,
    0x9436c0760c86e30b,0xf9a0b6720aaf6521,
    0xb94470938fa89bce,0xf808e40e8d5b3e69,
    0xe7958cb87392c2c2,0xb60b1d1230b20e04,
    0x90bd77f3483bb9b9,0xb1c6f22b5e6f48c2,
    0xb4ecd5f01a4aa828,0x1e38aeb6360b1af3,
    0xe2280b6c20dd5232,0x25c6da63c38de1b0,
    0x8d590723948a535f,0x579c487e5a38ad0e,
    0xb0af48ec79ace837,0x2d835a9df0c6d851,
    0xdcdb1b2798182244,0xf8e431456cf88e65,
    0x8a08f0f8bf0f156b,0x1b8e9ecb641b58ff,
    0xac8b2d36eed2dac5,0xe272467e3d222f3f,
    0xd7adf884aa879177,0x5b0ed81dcc6abb0f,
    0x86ccbb52ea94baea,0x98e947129fc2b4e9,
    0xa87fea27a539e9a5,0x3f2398d747b36224,
    0xd29fe4b18e88640e,0x8eec7f0d19a03aad,
    0x83a3eeeef9153e89,0x1953cf68300424ac,
    0xa48ceaaab75a8e2b,0x5fa8c3423c052dd7,
    0xcdb02555653131b6,0x3792f412cb06794d,
    0x808e17555f3ebf11,0xe2bbd88bbee40bd0,
    0xa0b19d2ab70e6ed6,0x5b6aceaeae9d0ec4,
    0xc8de047564d20a8b,0xf245825a5a445275,
    0xfb158592be068d2e,0xeed6e2f0f0d56712,
    0x9ced737bb6c4183d,0x55464dd69685606b,
    0xc428d05aa4751e4c,0xaa97e14c3c26b886,
    0xf53304714d9265df,0xd53dd99f4b3066a8,
    0x993fe2c6d07b7fab,0xe546a8038efe4029,
    0xbf8fdb78849a5f96,0xde98520472bdd033,
    0xef73d256a5c0f77c,0x963e66858f6d4440,
    0x95a8637627989aad,0xdde7001379a44aa8,
    0xbb127c53b17ec159,0x5560c018580d5d52,
    0xe9d71b689dde71af,0xaab8f01e6e10b4a6,
    0x9226712162ab070d,0xcab3961304ca70e8,
    0xb6b00d69bb55c8d1,0x3d607b97c5fd0d22,
    0xe45c10c42a2b3b05,0x8cb89a7db77c506a,
    0x8eb98a7a9a5b04e3,0x77f3608e92adb242,
    0xb267ed1940f1c61c,0x55f038b237591ed3,
    0xdf01e85f912e37a3,0x6b6c46dec52f6688,
    0x8b61313bbabce2c6,0x2323ac4b3b3da015,
    0xae397d8aa96c1b77,0xabec975e0a0d081a,
    0xd9c7dced53c72255,0x96e7bd358c904a21,
    0x881cea14545c7575,0x7e50d64177da2e54,
    0xaa242499697392d2,0xdde50bd1d5d0b9e9,
    0xd4ad2dbfc3d07787,0x955e4ec64b44e864,
    0x84ec3c97da624ab4,0xbd5af13bef0b113e,
    0xa6274bbdd0fadd61,0xecb1ad8aeacdd58e,
    0xcfb11ead453994ba,0x67de18eda5814af2,
    0x81ceb32c4b43fcf4,0x80eacf948770ced7,
    0xa2425ff75e14fc31,0xa1258379a94d028d,
    0xcad2f7f5359a3b3e,0x96ee45813a04330,
    0xfd87b5f28300ca0d,0x8bca9d6e188853fc,
    0x9e74d1b791e07e48,0x775ea264cf55347e,
    0xc612062576589dda,0x95364afe032a819e,
    0xf79687aed3eec551,0x3a83ddbd83f52205,
    0x9abe14cd44753b52,0xc4926a9672793543,
    0xc16d9a0095928a27,0x75b7053c0f178294,
    0xf1c90080baf72cb1,0x5324c68b12dd6339,
    0x971da05074da7bee,0xd3f6fc16ebca5e04,
    0xbce5086492111aea,0x88f4bb1ca6bcf585,
    0xec1e4a7db69561a5,0x2b31e9e3d06c32e6,
    0x9392ee8e921d5d07,0x3aff322e62439fd0,
    0xb877aa3236a4b449,0x9befeb9fad487c3,
    0xe69594bec44de15b,0x4c2ebe687989a9b4,
    0x901d7cf73ab0acd9,0xf9d37014bf60a11,
    0xb424dc35095cd80f,0x538484c19ef38c95,
    0xe12e13424bb40e13,0x2865a5f206b06fba,
    0x8cbccc096f5088cb,0xf93f87b7442e45d4,
    0xafebff0bcb24aafe,0xf78f69a51539d749,
    0xdbe6fecebdedd5be,0xb573440e5a884d1c,
    0x89705f4136b4a597,0x31680a88f8953031,
    0xabcc77118461cefc,0xfdc20d2b36ba7c3e,
    0xd6bf94d5e57a42bc,0x3d32907604691b4d,
    0x8637bd05af6c69b5,0xa63f9a49c2c1b110,
    0xa7c5ac471b478423,0xfcf80dc33721d54,
    0xd1b71758e219652b,0xd3c36113404ea4a9,
    0x83126e978d4fdf3b,0x645a1cac083126ea,
    0xa3d70a3d70a3d70a,0x3d70a3d70a3d70a4,
    0xcccccccccccccccc,0xcccccccccccccccd,
    0x8000000000000000,0x0,
    0xa000000000000000,0x0,
    0xc800000000000000,0x0,
    0xfa00000000000000,0x0,
    0x9c40000000000000,0x0,
    0xc350000000000000,0x0,
    0xf424000000000000,0x0,
    0x9896800000000000,0x0,
    0xbebc200000000000,0x0,
    0xee6b280000000000,0x0,
    0x9502f90000000000,0x0,
    0xba43b74000000000,0x0,
    0xe8d4a51000000000,0x0,
    0x9184e72a00000000,0x0,
    0xb5e620f480000000,0x0,
    0xe35fa931a0000000,0x0,
    0x8e1bc9bf04000000,0x0,
    0xb1a2bc2ec5000000,0x0,
    0xde0b6b3a76400000,0x0,
    0x8ac7230489e80000,0x0,
    0xad78ebc5ac620000,0x0,
    0xd8d726b7177a8000,0x0,
    0x878678326eac9000,0x0,
    0xa968163f0a57b400,0x0,
    0xd3c21bcecceda100,0x0,
    0x84595161401484a0,0x0,
    0xa56fa5b99019a5c8,0x0,
    0xcecb8f27f4200f3a,0x0,
    0x813f3978f8940984,0x4000000000000000,
    0xa18f07d736b90be5,0x5000000000000000,
    0xc9f2c9cd04674ede,0xa400000000000000,
    0xfc6f7c4045812296,0x4d00000000000000,
    0x9dc5ada82b70b59d,0xf020000000000000,
    0xc5371912364ce305,0x6c28000000000000,
    0xf684df56c3e01bc6,0xc732000000000000,
    0x9a130b963a6c115c,0x3c7f400000000000,
    0xc097ce7bc90715b3,0x4b9f100000000000,
    0xf0bdc21abb48db20,0x1e86d40000000000,
    0x96769950b50d88f4,0x1314448000000000,
    0xbc143fa4e250eb31,0x17d955a000000000,
    0xeb194f8e1ae525fd,0x5dcfab0800000000,
    0x92efd1b8d0cf37be,0x5aa1cae500000000,
    0xb7abc627050305ad,0xf14a3d9e40000000,
    0xe596b7b0c643c719,0x6d9ccd05d0000000,
    0x8f7e32ce7bea5c6f,0xe4820023a2000000,
    0xb35dbf821ae4f38b,0xdda2802c8a800000,
    0xe0352f62a19e306e,0xd50b2037ad200000,
    0x8c213d9da502de45,0x4526f422cc340000,
    0xaf298d050e4395d6,0x9670b12b7f410000,
    0xdaf3f04651d47b4c,0x3c0cdd765f114000,
    0x88d8762bf324cd0f,0xa5880a69fb6ac800,
    0xab0e93b6efee0053,0x8eea0d047a457a00,
    0xd5d238a4abe98068,0x72a4904598d6d880,
    0x85a36366eb71f041,0x47a6da2b7f864750,
    0xa70c3c40a64e6c51,0x999090b65f67d924,
    0xd0cf4b50cfe20765,0xfff4b4e3f741cf6d,
    0x82818f1281ed449f,0xbff8f10e7a8921a4,
    0xa321f2d7226895c7,0xaff72d52192b6a0d,
    0xcbea6f8ceb02bb39,0x9bf4f8a69f764490,
    0xfee50b7025c36a08,0x2f236d04753d5b4,
    0x9f4f2726179a2245,0x1d762422c946590,
    0xc722f0ef9d80aad6,0x424d3ad2b7b97ef5,
    0xf8ebad2b84e0d58b,0xd2e0898765a7deb2,
    0x9b934c3b330c8577,0x63cc55f49f88eb2f,
    0xc2781f49ffcfa6d5,0x3cbf6b71c76b25fb,
    0xf316271c7fc3908a,0x8bef464e3945ef7a,
    0x97edd871cfda3a56,0x97758bf0e3cbb5ac,
    0xbde94e8e43d0c8ec,0x3d52eeed1cbea317,
    0xed63a231d4c4fb27,0x4ca7aaa863ee4bdd,
    0x945e455f24fb1cf8,0x8fe8caa93e74ef6a,
    0xb975d6b6ee39e436,0xb3e2fd538e122b44,
    0xe7d34c64a9c85d44,0x60dbbca87196b616,
    0x90e40fbeea1d3a4a,0xbc8955e946fe31cd,
    0xb51d13aea4a488dd,0x6babab6398bdbe41,
    0xe264589a4dcdab14,0xc696963c7eed2dd1,
    0x8d7eb76070a08aec,0xfc1e1de5cf543ca2,
    0xb0de65388cc8ada8,0x3b25a55f43294bcb,
    0xdd15fe86affad912,0x49ef0eb713f39ebe,
    0x8a2dbf142dfcc7ab,0x6e3569326c784337,
    0xacb92ed9397bf996,0x49c2c37f07965404,
    0xd7e77a8f87daf7fb,0xdc33745ec97be906,
    0x86f0ac99b4e8dafd,0x69a028bb3ded71a3,
    0xa8acd7c0222311bc,0xc40832ea0d68ce0c,
    0xd2d80db02aabd62b,0xf50a3fa490c30190,
    0x83c7088e1aab65db,0x792667c6da79e0fa,
    0xa4b8cab1a1563f52,0x577001b891185938,
    0xcde6fd5e09abcf26,0xed4c0226b55e6f86,
    0x80b05e5ac60b6178,0x544f8158315b05b4,
    0xa0dc75f1778e39d6,0x696361ae3db1c721,
    0xc913936dd571c84c,0x3bc3a19cd1e38e9,
    0xfb5878494ace3a5f,0x4ab48a04065c723,
    0x9d174b2dcec0e47b,0x62eb0d64283f9c76,
    0xc45d1df942711d9a,0x3ba5d0bd324f8394,
    0xf5746577930d6500,0xca8f44ec7ee36479,
    0x9968bf6abbe85f20,0x7e998b13cf4e1ecb,
    0xbfc2ef456ae276e8,0x9e3fedd8c321a67e,
    0xefb3ab16c59b14a2,0xc5cfe94ef3ea101e,
    0x95d04aee3b80ece5,0xbba1f1d158724a12,
    0xbb445da9ca61281f,0x2a8a6e45ae8edc97,
    0xea1575143cf97226,0xf52d09d71a3293bd,
    0x924d692ca61be758,0x593c2626705f9c56,
    0xb6e0c377cfa2e12e,0x6f8b2fb00c77836c,
    0xe498f455c38b997a,0xb6dfb9c0f956447,
    0x8edf98b59a373fec,0x4724bd4189bd5eac,
    0xb2977ee300c50fe7,0x58edec91ec2cb657,
    0xdf3d5e9bc0f653e1,0x2f2967b66737e3ed,
    0x8b865b215899f46c,0xbd79e0d20082ee74,
    0xae67f1e9aec07187,0xecd8590680a3aa11,
    0xda01ee641a708de9,0xe80e6f4820cc9495,
    0x884134fe908658b2,0x3109058d147fdcdd,
    0xaa51823e34a7eede,0xbd4b46f0599fd415,
    0xd4e5e2cdc1d1ea96,0x6c9e18ac7007c91a,
    0x850fadc09923329e,0x3e2cf6bc604ddb0,
    0xa6539930bf6bff45,0x84db8346b786151c,
    0xcfe87f7cef46ff16,0xe612641865679a63,
    0x81f14fae158c5f6e,0x4fcb7e8f3f60c07e,
    0xa26da3999aef7749,0xe3be5e330f38f09d,
    0xcb090c8001ab551c,0x5cadf5bfd3072cc5,
    0xfdcb4fa002162a63,0x73d9732fc7c8f7f6,
    0x9e9f11c4014dda7e,0x2867e7fddcdd9afa,
    0xc646d63501a1511d,0xb281e1fd541501b8,
    0xf7d88bc24209a565,0x1f225a7ca91a4226,
    0x9ae757596946075f,0x3375788de9b06958,
    0xc1a12d2fc3978937,0x52d6b1641c83ae,
    0xf209787bb47d6b84,0xc0678c5dbd23a49a,
    0x9745eb4d50ce6332,0xf840b7ba963646e0,
    0xbd176620a501fbff,0xb650e5a93bc3d898,
    0xec5d3fa8ce427aff,0xa3e51f138ab4cebe,
    0x93ba47c980e98cdf,0xc66f336c36b10137,
    0xb8a8d9bbe123f017,0xb80b0047445d4184,
    0xe6d3102ad96cec1d,0xa60dc059157491e5,
    0x9043ea1ac7e41392,0x87c89837ad68db2f,
    0xb454e4a179dd1877,0x29babe4598c311fb,
    0xe16a1dc9d8545e94,0xf4296dd6fef3d67a,
    0x8ce2529e2734bb1d,0x1899e4a65f58660c,
    0xb01ae745b101e9e4,0x5ec05dcff72e7f8f,
    0xdc21a1171d42645d,0x76707543f4fa1f73,
    0x899504ae72497eba,0x6a06494a791c53a8,
    0xabfa45da0edbde69,0x487db9d17636892,
    0xd6f8d7509292d603,0x45a9d2845d3c42b6,
    0x865b86925b9bc5c2,0xb8a2392ba45a9b2,
    0xa7f26836f282b732,0x8e6cac7768d7141e,
    0xd1ef0244af2364ff,0x3207d795430cd926,
    0x8335616aed761f1f,0x7f44e6bd49e807b8,
    0xa402b9c5a8d3a6e7,0x5f16206c9c6209a6,
    0xcd036837130890a1,0x36dba887c37a8c0f,
    0x802221226be55a64,0xc2494954da2c9789,
    0xa02aa96b06deb0fd,0xf2db9baa10b7bd6c,
    0xc83553c5c8965d3d,0x6f92829494e5acc7,
    0xfa42a8b73abbf48c,0xcb772339ba1f17f9,
    0x9c69a97284b578d7,0xff2a760414536efb,
    0xc38413cf25e2d70d,0xfef5138519684aba,
    0xf46518c2ef5b8cd1,0x7eb258665fc25d69,
    0x98bf2f79d5993802,0xef2f773ffbd97a61,
    0xbeeefb584aff8603,0xaafb550ffacfd8fa,
    0xeeaaba2e5dbf6784,0x95ba2a53f983cf38,
    0x952ab45cfa97a0b2,0xdd945a747bf26183,
    0xba756174393d88df,0x94f971119aeef9e4,
    0xe912b9d1478ceb17,0x7a37cd5601aab85d,
    0x91abb422ccb812ee,0xac62e055c10ab33a,
    0xb616a12b7fe617aa,0x577b986b314d6009,
    0xe39c49765fdf9d94,0xed5a7e85fda0b80b,
    0x8e41ade9fbebc27d,0x14588f13be847307,
    0xb1d219647ae6b31c,0x596eb2d8ae258fc8,
    0xde469fbd99a05fe3,0x6fca5f8ed9aef3bb,
    0x8aec23d680043bee,0x25de7bb9480d5854,
    0xada72ccc20054ae9,0xaf561aa79a10ae6a,
    0xd910f7ff28069da4,0x1b2ba1518094da04,
    0x87aa9aff79042286,0x90fb44d2f05d0842,
    0xa99541bf57452b28,0x353a1607ac744a53,
    0xd3fa922f2d1675f2,0x42889b8997915ce8,
    0x847c9b5d7c2e09b7,0x69956135febada11,
    0xa59bc234db398c25,0x43fab9837e699095,
    0xcf02b2c21207ef2e,0x94f967e45e03f4bb,
    0x8161afb94b44f57d,0x1d1be0eebac278f5,
    0xa1ba1ba79e1632dc,0x6462d92a69731732,
    0xca28a291859bbf93,0x7d7b8f7503cfdcfe,
    0xfcb2cb35e702af78,0x5cda735244c3d43e,
    0x9defbf01b061adab,0x3a0888136afa64a7,
    0xc56baec21c7a1916,0x88aaa1845b8fdd0,
    0xf6c69a72a3989f5b,0x8aad549e57273d45,
    0x9a3c2087a63f6399,0x36ac54e2f678864b,
    0xc0cb28a98fcf3c7f,0x84576a1bb416a7dd,
    0xf0fdf2d3f3c30b9f,0x656d44a2a11c51d5,
    0x969eb7c47859e743,0x9f644ae5a4b1b325,
    0xbc4665b596706114,0x873d5d9f0dde1fee,
    0xeb57ff22fc0c7959,0xa90cb506d155a7ea,
    0x9316ff75dd87cbd8,0x9a7f12442d588f2,
    0xb7dcbf5354e9bece,0xc11ed6d538aeb2f,
    0xe5d3ef282a242e81,0x8f1668c8a86da5fa,
    0x8fa475791a569d10,0xf96e017d694487bc,
    0xb38d92d760ec4455,0x37c981dcc395a9ac,
    0xe070f78d3927556a,0x85bbe253f47b1417,
    0x8c469ab843b89562,0x93956d7478ccec8e,
    0xaf58416654a6babb,0x387ac8d1970027b2,
    0xdb2e51bfe9d0696a,0x6997b05fcc0319e,
    0x88fcf317f22241e2,0x441fece3bdf81f03,
    0xab3c2fddeeaad25a,0xd527e81cad7626c3,
    0xd60b3bd56a5586f1,0x8a71e223d8d3b074,
    0x85c7056562757456,0xf6872d5667844e49,
    0xa738c6bebb12d16c,0xb428f8ac016561db,
    0xd106f86e69d785c7,0xe13336d701beba52,
    0x82a45b450226b39c,0xecc0024661173473,
    0xa34d721642b06084,0x27f002d7f95d0190,
    0xcc20ce9bd35c78a5,0x31ec038df7b441f4,
    0xff290242c83396ce,0x7e67047175a15271,
    0x9f79a169bd203e41,0xf0062c6e984d386,
    0xc75809c42c684dd1,0x52c07b78a3e60868,
    0xf92e0c3537826145,0xa7709a56ccdf8a82,
    0x9bbcc7a142b17ccb,0x88a66076400bb691,
    0xc2abf989935ddbfe,0x6acff893d00ea435,
    0xf356f7ebf83552fe,0x583f6b8c4124d43,
    0x98165af37b2153de,0xc3727a337a8b704a,
    0xbe1bf1b059e9a8d6,0x744f18c0592e4c5c,
    0xeda2ee1c7064130c,0x1162def06f79df73,
    0x9485d4d1c63e8be7,0x8addcb5645ac2ba8,
    0xb9a74a0637ce2ee1,0x6d953e2bd7173692,
    0xe8111c87c5c1ba99,0xc8fa8db6ccdd0437,
    0x910ab1d4db9914a0,0x1d9c9892400a22a2,
    0xb54d5e4a127f59c8,0x2503beb6d00cab4b,
    0xe2a0b5dc971f303a,0x2e44ae64840fd61d,
    0x8da471a9de737e24,0x5ceaecfed289e5d2,
    0xb10d8e1456105dad,0x7425a83e872c5f47,
    0xdd50f1996b947518,0xd12f124e28f77719,
    0x8a5296ffe33cc92f,0x82bd6b70d99aaa6f,
    0xace73cbfdc0bfb7b,0x636cc64d1001550b,
    0xd8210befd30efa5a,0x3c47f7e05401aa4e,
    0x8714a775e3e95c78,0x65acfaec34810a71,
    0xa8d9d1535ce3b396,0x7f1839a741a14d0d,
    0xd31045a8341ca07c,0x1ede48111209a050,
    0x83ea2b892091e44d,0x934aed0aab460432,
    0xa4e4b66b68b65d60,0xf81da84d5617853f,
    0xce1de40642e3f4b9,0x36251260ab9d668e,
    0x80d2ae83e9ce78f3,0xc1d72b7c6b426019,
    0xa1075a24e4421730,0xb24cf65b8612f81f,
    0xc94930ae1d529cfc,0xdee033f26797b627,
    0xfb9b7cd9a4a7443c,0x169840ef017da3b1,
    0x9d412e0806e88aa5,0x8e1f289560ee864e,
    0xc491798a08a2ad4e,0xf1a6f2bab92a27e2,
    0xf5b5d7ec8acb58a2,0xae10af696774b1db,
    0x9991a6f3d6bf1765,0xacca6da1e0a8ef29,
    0xbff610b0cc6edd3f,0x17fd090a58d32af3,
    0xeff394dcff8a948e,0xddfc4b4cef07f5b0,
    0x95f83d0a1fb69cd9,0x4abdaf101564f98e,
    0xbb764c4ca7a4440f,0x9d6d1ad41abe37f1,
    0xea53df5fd18d5513,0x84c86189216dc5ed,
    0x92746b9be2f8552c,0x32fd3cf5b4e49bb4,
    0xb7118682dbb66a77,0x3fbc8c33221dc2a1,
    0xe4d5e82392a40515,0xfabaf3feaa5334a,
    0x8f05b1163ba6832d,0x29cb4d87f2a7400e,
    0xb2c71d5bca9023f8,0x743e20e9ef511012,
    0xdf78e4b2bd342cf6,0x914da9246b255416,
    0x8bab8eefb6409c1a,0x1ad089b6c2f7548e,
    0xae9672aba3d0c320,0xa184ac2473b529b1,
    0xda3c0f568cc4f3e8,0xc9e5d72d90a2741e,
    0x8865899617fb1871,0x7e2fa67c7a658892,
    0xaa7eebfb9df9de8d,0xddbb901b98feeab7,
    0xd51ea6fa85785631,0x552a74227f3ea565,
    0x8533285c936b35de,0xd53a88958f87275f,
    0xa67ff273b8460356,0x8a892abaf368f137,
    0xd01fef10a657842c,0x2d2b7569b0432d85,
    0x8213f56a67f6b29b,0x9c3b29620e29fc73,
    0xa298f2c501f45f42,0x8349f3ba91b47b8f,
    0xcb3f2f7642717713,0x241c70a936219a73,
    0xfe0efb53d30dd4d7,0xed238cd383aa0110,
    0x9ec95d1463e8a506,0xf4363804324a40aa,
    0xc67bb4597ce2ce48,0xb143c6053edcd0d5,
    0xf81aa16fdc1b81da,0xdd94b7868e94050a,
    0x9b10a4e5e9913128,0xca7cf2b4191c8326,
    0xc1d4ce1f63f57d72,0xfd1c2f611f63a3f0,
    0xf24a01a73cf2dccf,0xbc633b39673c8cec,
    0x976e41088617ca01,0xd5be0503e085d813,
    0xbd49d14aa79dbc82,0x4b2d8644d8a74e18,
    0xec9c459d51852ba2,0xddf8e7d60ed1219e,
    0x93e1ab8252f33b45,0xcabb90e5c942b503,
    0xb8da1662e7b00a17,0x3d6a751f3b936243,
    0xe7109bfba19c0c9d,0xcc512670a783ad4,
    0x906a617d450187e2,0x27fb2b80668b24c5,
    0xb484f9dc9641e9da,0xb1f9f660802dedf6,
    0xe1a63853bbd26451,0x5e7873f8a0396973,
    0x8d07e33455637eb2,0xdb0b487b6423e1e8,
    0xb049dc016abc5e5f,0x91ce1a9a3d2cda62,
    0xdc5c5301c56b75f7,0x7641a140cc7810fb,
    0x89b9b3e11b6329ba,0xa9e904c87fcb0a9d,
    0xac2820d9623bf429,0x546345fa9fbdcd44,
    0xd732290fbacaf133,0xa97c177947ad4095,
    0x867f59a9d4bed6c0,0x49ed8eabcccc485d,
    0xa81f301449ee8c70,0x5c68f256bfff5a74,
    0xd226fc195c6a2f8c,0x73832eec6fff3111,
    0x83585d8fd9c25db7,0xc831fd53c5ff7eab,
    0xa42e74f3d032f525,0xba3e7ca8b77f5e55,
    0xcd3a1230c43fb26f,0x28ce1bd2e55f35eb,
    0x80444b5e7aa7cf85,0x7980d163cf5b81b3,
    0xa0555e361951c366,0xd7e105bcc332621f,
    0xc86ab5c39fa63440,0x8dd9472bf3fefaa7,
    0xfa856334878fc150,0xb14f98f6f0feb951,
    0x9c935e00d4b9d8d2,0x6ed1bf9a569f33d3,
    0xc3b8358109e84f07,0xa862f80ec4700c8,
    0xf4a642e14c6262c8,0xcd27bb612758c0fa,
    0x98e7e9cccfbd7dbd,0x8038d51cb897789c,
    0xbf21e44003acdd2c,0xe0470a63e6bd56c3,
    0xeeea5d5004981478,0x1858ccfce06cac74,
    0x95527a5202df0ccb,0xf37801e0c43ebc8,
    0xbaa718e68396cffd,0xd30560258f54e6ba,
    0xe950df20247c83fd,0x47c6b82ef32a2069,
    0x91d28b7416cdd27e,0x4cdc331d57fa5441,
    0xb6472e511c81471d,0xe0133fe4adf8e952,
    0xe3d8f9e563a198e5,0x58180fddd97723a6,
    0x8e679c2f5e44ff8f,0x570f09eaa7ea7648,};
};

template <class unused>
constexpr uint64_t powers_template<unused>::power_of_five_128[number_of_entries];

using powers = powers_template<>;

} // namespace fast_float

#endif

#ifndef FASTFLOAT_DECIMAL_TO_BINARY_H
#define FASTFLOAT_DECIMAL_TO_BINARY_H

//included above:
//#include <cfloat>
#include <cinttypes>
#include <cmath>
//included above:
//#include <cstdint>
#include <cstdlib>
//included above:
//#include <cstring>

namespace fast_float {

// This will compute or rather approximate w * 5**q and return a pair of 64-bit words approximating
// the result, with the "high" part corresponding to the most significant bits and the
// low part corresponding to the least significant bits.
//
template <int bit_precision>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
value128 compute_product_approximation(int64_t q, uint64_t w) {
  const int index = 2 * int(q - powers::smallest_power_of_five);
  // For small values of q, e.g., q in [0,27], the answer is always exact because
  // The line value128 firstproduct = full_multiplication(w, power_of_five_128[index]);
  // gives the exact answer.
  value128 firstproduct = full_multiplication(w, powers::power_of_five_128[index]);
  static_assert((bit_precision >= 0) && (bit_precision <= 64), " precision should  be in (0,64]");
  constexpr uint64_t precision_mask = (bit_precision < 64) ?
               (uint64_t(0xFFFFFFFFFFFFFFFF) >> bit_precision)
               : uint64_t(0xFFFFFFFFFFFFFFFF);
  if((firstproduct.high & precision_mask) == precision_mask) { // could further guard with  (lower + w < lower)
    // regarding the second product, we only need secondproduct.high, but our expectation is that the compiler will optimize this extra work away if needed.
    value128 secondproduct = full_multiplication(w, powers::power_of_five_128[index + 1]);
    firstproduct.low += secondproduct.high;
    if(secondproduct.high > firstproduct.low) {
      firstproduct.high++;
    }
  }
  return firstproduct;
}

namespace detail {
/**
 * For q in (0,350), we have that
 *  f = (((152170 + 65536) * q ) >> 16);
 * is equal to
 *   floor(p) + q
 * where
 *   p = log(5**q)/log(2) = q * log(5)/log(2)
 *
 * For negative values of q in (-400,0), we have that
 *  f = (((152170 + 65536) * q ) >> 16);
 * is equal to
 *   -ceil(p) + q
 * where
 *   p = log(5**-q)/log(2) = -q * log(5)/log(2)
 */
  constexpr fastfloat_really_inline int32_t power(int32_t q)  noexcept  {
    return (((152170 + 65536) * q) >> 16) + 63;
  }
} // namespace detail

// create an adjusted mantissa, biased by the invalid power2
// for significant digits already multiplied by 10 ** q.
template <typename binary>
fastfloat_really_inline FASTFLOAT_CONSTEXPR14
adjusted_mantissa compute_error_scaled(int64_t q, uint64_t w, int lz) noexcept  {
  int hilz = int(w >> 63) ^ 1;
  adjusted_mantissa answer;
  answer.mantissa = w << hilz;
  int bias = binary::mantissa_explicit_bits() - binary::minimum_exponent();
  answer.power2 = int32_t(detail::power(int32_t(q)) + bias - hilz - lz - 62 + invalid_am_bias);
  return answer;
}

// w * 10 ** q, without rounding the representation up.
// the power2 in the exponent will be adjusted by invalid_am_bias.
template <typename binary>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
adjusted_mantissa compute_error(int64_t q, uint64_t w)  noexcept  {
  int lz = leading_zeroes(w);
  w <<= lz;
  value128 product = compute_product_approximation<binary::mantissa_explicit_bits() + 3>(q, w);
  return compute_error_scaled<binary>(q, product.high, lz);
}

// w * 10 ** q
// The returned value should be a valid ieee64 number that simply need to be packed.
// However, in some very rare cases, the computation will fail. In such cases, we
// return an adjusted_mantissa with a negative power of 2: the caller should recompute
// in such cases.
template <typename binary>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
adjusted_mantissa compute_float(int64_t q, uint64_t w)  noexcept  {
  adjusted_mantissa answer;
  if ((w == 0) || (q < binary::smallest_power_of_ten())) {
    answer.power2 = 0;
    answer.mantissa = 0;
    // result should be zero
    return answer;
  }
  if (q > binary::largest_power_of_ten()) {
    // we want to get infinity:
    answer.power2 = binary::infinite_power();
    answer.mantissa = 0;
    return answer;
  }
  // At this point in time q is in [powers::smallest_power_of_five, powers::largest_power_of_five].

  // We want the most significant bit of i to be 1. Shift if needed.
  int lz = leading_zeroes(w);
  w <<= lz;

  // The required precision is binary::mantissa_explicit_bits() + 3 because
  // 1. We need the implicit bit
  // 2. We need an extra bit for rounding purposes
  // 3. We might lose a bit due to the "upperbit" routine (result too small, requiring a shift)

  value128 product = compute_product_approximation<binary::mantissa_explicit_bits() + 3>(q, w);
  // The computed 'product' is always sufficient.
  // Mathematical proof:
  // Noble Mushtak and Daniel Lemire, Fast Number Parsing Without Fallback (to appear)
  // See script/mushtak_lemire.py

  // The "compute_product_approximation" function can be slightly slower than a branchless approach:
  // value128 product = compute_product(q, w);
  // but in practice, we can win big with the compute_product_approximation if its additional branch
  // is easily predicted. Which is best is data specific.
  int upperbit = int(product.high >> 63);
  int shift = upperbit + 64 - binary::mantissa_explicit_bits() - 3;

  answer.mantissa = product.high >> shift;

  answer.power2 = int32_t(detail::power(int32_t(q)) + upperbit - lz - binary::minimum_exponent());
  if (answer.power2 <= 0) { // we have a subnormal?
    // Here have that answer.power2 <= 0 so -answer.power2 >= 0
    if(-answer.power2 + 1 >= 64) { // if we have more than 64 bits below the minimum exponent, you have a zero for sure.
      answer.power2 = 0;
      answer.mantissa = 0;
      // result should be zero
      return answer;
    }
    // next line is safe because -answer.power2 + 1 < 64
    answer.mantissa >>= -answer.power2 + 1;
    // Thankfully, we can't have both "round-to-even" and subnormals because
    // "round-to-even" only occurs for powers close to 0.
    answer.mantissa += (answer.mantissa & 1); // round up
    answer.mantissa >>= 1;
    // There is a weird scenario where we don't have a subnormal but just.
    // Suppose we start with 2.2250738585072013e-308, we end up
    // with 0x3fffffffffffff x 2^-1023-53 which is technically subnormal
    // whereas 0x40000000000000 x 2^-1023-53  is normal. Now, we need to round
    // up 0x3fffffffffffff x 2^-1023-53  and once we do, we are no longer
    // subnormal, but we can only know this after rounding.
    // So we only declare a subnormal if we are smaller than the threshold.
    answer.power2 = (answer.mantissa < (uint64_t(1) << binary::mantissa_explicit_bits())) ? 0 : 1;
    return answer;
  }

  // usually, we round *up*, but if we fall right in between and and we have an
  // even basis, we need to round down
  // We are only concerned with the cases where 5**q fits in single 64-bit word.
  if ((product.low <= 1) &&  (q >= binary::min_exponent_round_to_even()) && (q <= binary::max_exponent_round_to_even()) &&
      ((answer.mantissa & 3) == 1) ) { // we may fall between two floats!
    // To be in-between two floats we need that in doing
    //   answer.mantissa = product.high >> (upperbit + 64 - binary::mantissa_explicit_bits() - 3);
    // ... we dropped out only zeroes. But if this happened, then we can go back!!!
    if((answer.mantissa  << shift) ==  product.high) {
      answer.mantissa &= ~uint64_t(1);          // flip it so that we do not round up
    }
  }

  answer.mantissa += (answer.mantissa & 1); // round up
  answer.mantissa >>= 1;
  if (answer.mantissa >= (uint64_t(2) << binary::mantissa_explicit_bits())) {
    answer.mantissa = (uint64_t(1) << binary::mantissa_explicit_bits());
    answer.power2++; // undo previous addition
  }

  answer.mantissa &= ~(uint64_t(1) << binary::mantissa_explicit_bits());
  if (answer.power2 >= binary::infinite_power()) { // infinity
    answer.power2 = binary::infinite_power();
    answer.mantissa = 0;
  }
  return answer;
}

} // namespace fast_float

#endif

#ifndef FASTFLOAT_BIGINT_H
#define FASTFLOAT_BIGINT_H

#include <algorithm>
//included above:
//#include <cstdint>
//included above:
//#include <climits>
//included above:
//#include <cstring>


namespace fast_float {

// the limb width: we want efficient multiplication of double the bits in
// limb, or for 64-bit limbs, at least 64-bit multiplication where we can
// extract the high and low parts efficiently. this is every 64-bit
// architecture except for sparc, which emulates 128-bit multiplication.
// we might have platforms where `CHAR_BIT` is not 8, so let's avoid
// doing `8 * sizeof(limb)`.
#if defined(FASTFLOAT_64BIT) && !defined(__sparc)
#define FASTFLOAT_64BIT_LIMB 1
typedef uint64_t limb;
constexpr size_t limb_bits = 64;
#else
#define FASTFLOAT_32BIT_LIMB
typedef uint32_t limb;
constexpr size_t limb_bits = 32;
#endif

typedef span<limb> limb_span;

// number of bits in a bigint. this needs to be at least the number
// of bits required to store the largest bigint, which is
// `log2(10**(digits + max_exp))`, or `log2(10**(767 + 342))`, or
// ~3600 bits, so we round to 4000.
constexpr size_t bigint_bits = 4000;
constexpr size_t bigint_limbs = bigint_bits / limb_bits;

// vector-like type that is allocated on the stack. the entire
// buffer is pre-allocated, and only the length changes.
template <uint16_t size>
struct stackvec {
  limb data[size];
  // we never need more than 150 limbs
  uint16_t length{0};

  stackvec() = default;
  stackvec(const stackvec &) = delete;
  stackvec &operator=(const stackvec &) = delete;
  stackvec(stackvec &&) = delete;
  stackvec &operator=(stackvec &&other) = delete;

  // create stack vector from existing limb span.
  FASTFLOAT_CONSTEXPR20 stackvec(limb_span s) {
    FASTFLOAT_ASSERT(try_extend(s));
  }

  FASTFLOAT_CONSTEXPR14 limb& operator[](size_t index) noexcept {
    FASTFLOAT_DEBUG_ASSERT(index < length);
    return data[index];
  }
  FASTFLOAT_CONSTEXPR14 const limb& operator[](size_t index) const noexcept {
    FASTFLOAT_DEBUG_ASSERT(index < length);
    return data[index];
  }
  // index from the end of the container
  FASTFLOAT_CONSTEXPR14 const limb& rindex(size_t index) const noexcept {
    FASTFLOAT_DEBUG_ASSERT(index < length);
    size_t rindex = length - index - 1;
    return data[rindex];
  }

  // set the length, without bounds checking.
  FASTFLOAT_CONSTEXPR14 void set_len(size_t len) noexcept {
    length = uint16_t(len);
  }
  constexpr size_t len() const noexcept {
    return length;
  }
  constexpr bool is_empty() const noexcept {
    return length == 0;
  }
  constexpr size_t capacity() const noexcept {
    return size;
  }
  // append item to vector, without bounds checking
  FASTFLOAT_CONSTEXPR14 void push_unchecked(limb value) noexcept {
    data[length] = value;
    length++;
  }
  // append item to vector, returning if item was added
  FASTFLOAT_CONSTEXPR14 bool try_push(limb value) noexcept {
    if (len() < capacity()) {
      push_unchecked(value);
      return true;
    } else {
      return false;
    }
  }
  // add items to the vector, from a span, without bounds checking
  FASTFLOAT_CONSTEXPR20 void extend_unchecked(limb_span s) noexcept {
    limb* ptr = data + length;
    std::copy_n(s.ptr, s.len(), ptr);
    set_len(len() + s.len());
  }
  // try to add items to the vector, returning if items were added
  FASTFLOAT_CONSTEXPR20 bool try_extend(limb_span s) noexcept {
    if (len() + s.len() <= capacity()) {
      extend_unchecked(s);
      return true;
    } else {
      return false;
    }
  }
  // resize the vector, without bounds checking
  // if the new size is longer than the vector, assign value to each
  // appended item.
  FASTFLOAT_CONSTEXPR20
  void resize_unchecked(size_t new_len, limb value) noexcept {
    if (new_len > len()) {
      size_t count = new_len - len();
      limb* first = data + len();
      limb* last = first + count;
      ::std::fill(first, last, value);
      set_len(new_len);
    } else {
      set_len(new_len);
    }
  }
  // try to resize the vector, returning if the vector was resized.
  FASTFLOAT_CONSTEXPR20 bool try_resize(size_t new_len, limb value) noexcept {
    if (new_len > capacity()) {
      return false;
    } else {
      resize_unchecked(new_len, value);
      return true;
    }
  }
  // check if any limbs are non-zero after the given index.
  // this needs to be done in reverse order, since the index
  // is relative to the most significant limbs.
  FASTFLOAT_CONSTEXPR14 bool nonzero(size_t index) const noexcept {
    while (index < len()) {
      if (rindex(index) != 0) {
        return true;
      }
      index++;
    }
    return false;
  }
  // normalize the big integer, so most-significant zero limbs are removed.
  FASTFLOAT_CONSTEXPR14 void normalize() noexcept {
    while (len() > 0 && rindex(0) == 0) {
      length--;
    }
  }
};

fastfloat_really_inline FASTFLOAT_CONSTEXPR14
uint64_t empty_hi64(bool& truncated) noexcept {
  truncated = false;
  return 0;
}

fastfloat_really_inline FASTFLOAT_CONSTEXPR20
uint64_t uint64_hi64(uint64_t r0, bool& truncated) noexcept {
  truncated = false;
  int shl = leading_zeroes(r0);
  return r0 << shl;
}

fastfloat_really_inline FASTFLOAT_CONSTEXPR20
uint64_t uint64_hi64(uint64_t r0, uint64_t r1, bool& truncated) noexcept {
  int shl = leading_zeroes(r0);
  if (shl == 0) {
    truncated = r1 != 0;
    return r0;
  } else {
    int shr = 64 - shl;
    truncated = (r1 << shl) != 0;
    return (r0 << shl) | (r1 >> shr);
  }
}

fastfloat_really_inline FASTFLOAT_CONSTEXPR20
uint64_t uint32_hi64(uint32_t r0, bool& truncated) noexcept {
  return uint64_hi64(r0, truncated);
}

fastfloat_really_inline FASTFLOAT_CONSTEXPR20
uint64_t uint32_hi64(uint32_t r0, uint32_t r1, bool& truncated) noexcept {
  uint64_t x0 = r0;
  uint64_t x1 = r1;
  return uint64_hi64((x0 << 32) | x1, truncated);
}

fastfloat_really_inline FASTFLOAT_CONSTEXPR20
uint64_t uint32_hi64(uint32_t r0, uint32_t r1, uint32_t r2, bool& truncated) noexcept {
  uint64_t x0 = r0;
  uint64_t x1 = r1;
  uint64_t x2 = r2;
  return uint64_hi64(x0, (x1 << 32) | x2, truncated);
}

// add two small integers, checking for overflow.
// we want an efficient operation. for msvc, where
// we don't have built-in intrinsics, this is still
// pretty fast.
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
limb scalar_add(limb x, limb y, bool& overflow) noexcept {
  limb z;
// gcc and clang
#if defined(__has_builtin)
  #if __has_builtin(__builtin_add_overflow)
    if (!cpp20_and_in_constexpr()) {
      overflow = __builtin_add_overflow(x, y, &z);
      return z;
    }
  #endif
#endif

  // generic, this still optimizes correctly on MSVC.
  z = x + y;
  overflow = z < x;
  return z;
}

// multiply two small integers, getting both the high and low bits.
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
limb scalar_mul(limb x, limb y, limb& carry) noexcept {
#ifdef FASTFLOAT_64BIT_LIMB
  #if defined(__SIZEOF_INT128__)
  // GCC and clang both define it as an extension.
  __uint128_t z = __uint128_t(x) * __uint128_t(y) + __uint128_t(carry);
  carry = limb(z >> limb_bits);
  return limb(z);
  #else
  // fallback, no native 128-bit integer multiplication with carry.
  // on msvc, this optimizes identically, somehow.
  value128 z = full_multiplication(x, y);
  bool overflow;
  z.low = scalar_add(z.low, carry, overflow);
  z.high += uint64_t(overflow);  // cannot overflow
  carry = z.high;
  return z.low;
  #endif
#else
  uint64_t z = uint64_t(x) * uint64_t(y) + uint64_t(carry);
  carry = limb(z >> limb_bits);
  return limb(z);
#endif
}

// add scalar value to bigint starting from offset.
// used in grade school multiplication
template <uint16_t size>
inline FASTFLOAT_CONSTEXPR20
bool small_add_from(stackvec<size>& vec, limb y, size_t start) noexcept {
  size_t index = start;
  limb carry = y;
  bool overflow;
  while (carry != 0 && index < vec.len()) {
    vec[index] = scalar_add(vec[index], carry, overflow);
    carry = limb(overflow);
    index += 1;
  }
  if (carry != 0) {
    FASTFLOAT_TRY(vec.try_push(carry));
  }
  return true;
}

// add scalar value to bigint.
template <uint16_t size>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
bool small_add(stackvec<size>& vec, limb y) noexcept {
  return small_add_from(vec, y, 0);
}

// multiply bigint by scalar value.
template <uint16_t size>
inline FASTFLOAT_CONSTEXPR20
bool small_mul(stackvec<size>& vec, limb y) noexcept {
  limb carry = 0;
  for (size_t index = 0; index < vec.len(); index++) {
    vec[index] = scalar_mul(vec[index], y, carry);
  }
  if (carry != 0) {
    FASTFLOAT_TRY(vec.try_push(carry));
  }
  return true;
}

// add bigint to bigint starting from index.
// used in grade school multiplication
template <uint16_t size>
FASTFLOAT_CONSTEXPR20
bool large_add_from(stackvec<size>& x, limb_span y, size_t start) noexcept {
  // the effective x buffer is from `xstart..x.len()`, so exit early
  // if we can't get that current range.
  if (x.len() < start || y.len() > x.len() - start) {
      FASTFLOAT_TRY(x.try_resize(y.len() + start, 0));
  }

  bool carry = false;
  for (size_t index = 0; index < y.len(); index++) {
    limb xi = x[index + start];
    limb yi = y[index];
    bool c1 = false;
    bool c2 = false;
    xi = scalar_add(xi, yi, c1);
    if (carry) {
      xi = scalar_add(xi, 1, c2);
    }
    x[index + start] = xi;
    carry = c1 | c2;
  }

  // handle overflow
  if (carry) {
    FASTFLOAT_TRY(small_add_from(x, 1, y.len() + start));
  }
  return true;
}

// add bigint to bigint.
template <uint16_t size>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
bool large_add_from(stackvec<size>& x, limb_span y) noexcept {
  return large_add_from(x, y, 0);
}

// grade-school multiplication algorithm
template <uint16_t size>
FASTFLOAT_CONSTEXPR20
bool long_mul(stackvec<size>& x, limb_span y) noexcept {
  limb_span xs = limb_span(x.data, x.len());
  stackvec<size> z(xs);
  limb_span zs = limb_span(z.data, z.len());

  if (y.len() != 0) {
    limb y0 = y[0];
    FASTFLOAT_TRY(small_mul(x, y0));
    for (size_t index = 1; index < y.len(); index++) {
      limb yi = y[index];
      stackvec<size> zi;
      if (yi != 0) {
        // re-use the same buffer throughout
        zi.set_len(0);
        FASTFLOAT_TRY(zi.try_extend(zs));
        FASTFLOAT_TRY(small_mul(zi, yi));
        limb_span zis = limb_span(zi.data, zi.len());
        FASTFLOAT_TRY(large_add_from(x, zis, index));
      }
    }
  }

  x.normalize();
  return true;
}

// grade-school multiplication algorithm
template <uint16_t size>
FASTFLOAT_CONSTEXPR20
bool large_mul(stackvec<size>& x, limb_span y) noexcept {
  if (y.len() == 1) {
    FASTFLOAT_TRY(small_mul(x, y[0]));
  } else {
    FASTFLOAT_TRY(long_mul(x, y));
  }
  return true;
}

template <typename = void>
struct pow5_tables {
  static constexpr uint32_t large_step = 135;
  static constexpr uint64_t small_power_of_5[] = {
    1UL, 5UL, 25UL, 125UL, 625UL, 3125UL, 15625UL, 78125UL, 390625UL,
    1953125UL, 9765625UL, 48828125UL, 244140625UL, 1220703125UL,
    6103515625UL, 30517578125UL, 152587890625UL, 762939453125UL,
    3814697265625UL, 19073486328125UL, 95367431640625UL, 476837158203125UL,
    2384185791015625UL, 11920928955078125UL, 59604644775390625UL,
    298023223876953125UL, 1490116119384765625UL, 7450580596923828125UL,
  };
#ifdef FASTFLOAT_64BIT_LIMB
  constexpr static limb large_power_of_5[] = {
    1414648277510068013UL, 9180637584431281687UL, 4539964771860779200UL,
    10482974169319127550UL, 198276706040285095UL};
#else
  constexpr static limb large_power_of_5[] = {
    4279965485U, 329373468U, 4020270615U, 2137533757U, 4287402176U,
    1057042919U, 1071430142U, 2440757623U, 381945767U, 46164893U};
#endif
};

template <typename T>
constexpr uint32_t pow5_tables<T>::large_step;

template <typename T>
constexpr uint64_t pow5_tables<T>::small_power_of_5[];

template <typename T>
constexpr limb pow5_tables<T>::large_power_of_5[];

// big integer type. implements a small subset of big integer
// arithmetic, using simple algorithms since asymptotically
// faster algorithms are slower for a small number of limbs.
// all operations assume the big-integer is normalized.
struct bigint : pow5_tables<> {
  // storage of the limbs, in little-endian order.
  stackvec<bigint_limbs> vec;

  FASTFLOAT_CONSTEXPR20 bigint(): vec() {}
  bigint(const bigint &) = delete;
  bigint &operator=(const bigint &) = delete;
  bigint(bigint &&) = delete;
  bigint &operator=(bigint &&other) = delete;

  FASTFLOAT_CONSTEXPR20 bigint(uint64_t value): vec() {
#ifdef FASTFLOAT_64BIT_LIMB
    vec.push_unchecked(value);
#else
    vec.push_unchecked(uint32_t(value));
    vec.push_unchecked(uint32_t(value >> 32));
#endif
    vec.normalize();
  }

  // get the high 64 bits from the vector, and if bits were truncated.
  // this is to get the significant digits for the float.
  FASTFLOAT_CONSTEXPR20 uint64_t hi64(bool& truncated) const noexcept {
#ifdef FASTFLOAT_64BIT_LIMB
    if (vec.len() == 0) {
      return empty_hi64(truncated);
    } else if (vec.len() == 1) {
      return uint64_hi64(vec.rindex(0), truncated);
    } else {
      uint64_t result = uint64_hi64(vec.rindex(0), vec.rindex(1), truncated);
      truncated |= vec.nonzero(2);
      return result;
    }
#else
    if (vec.len() == 0) {
      return empty_hi64(truncated);
    } else if (vec.len() == 1) {
      return uint32_hi64(vec.rindex(0), truncated);
    } else if (vec.len() == 2) {
      return uint32_hi64(vec.rindex(0), vec.rindex(1), truncated);
    } else {
      uint64_t result = uint32_hi64(vec.rindex(0), vec.rindex(1), vec.rindex(2), truncated);
      truncated |= vec.nonzero(3);
      return result;
    }
#endif
  }

  // compare two big integers, returning the large value.
  // assumes both are normalized. if the return value is
  // negative, other is larger, if the return value is
  // positive, this is larger, otherwise they are equal.
  // the limbs are stored in little-endian order, so we
  // must compare the limbs in ever order.
  FASTFLOAT_CONSTEXPR20 int compare(const bigint& other) const noexcept {
    if (vec.len() > other.vec.len()) {
      return 1;
    } else if (vec.len() < other.vec.len()) {
      return -1;
    } else {
      for (size_t index = vec.len(); index > 0; index--) {
        limb xi = vec[index - 1];
        limb yi = other.vec[index - 1];
        if (xi > yi) {
          return 1;
        } else if (xi < yi) {
          return -1;
        }
      }
      return 0;
    }
  }

  // shift left each limb n bits, carrying over to the new limb
  // returns true if we were able to shift all the digits.
  FASTFLOAT_CONSTEXPR20 bool shl_bits(size_t n) noexcept {
    // Internally, for each item, we shift left by n, and add the previous
    // right shifted limb-bits.
    // For example, we transform (for u8) shifted left 2, to:
    //      b10100100 b01000010
    //      b10 b10010001 b00001000
    FASTFLOAT_DEBUG_ASSERT(n != 0);
    FASTFLOAT_DEBUG_ASSERT(n < sizeof(limb) * 8);

    size_t shl = n;
    size_t shr = limb_bits - shl;
    limb prev = 0;
    for (size_t index = 0; index < vec.len(); index++) {
      limb xi = vec[index];
      vec[index] = (xi << shl) | (prev >> shr);
      prev = xi;
    }

    limb carry = prev >> shr;
    if (carry != 0) {
      return vec.try_push(carry);
    }
    return true;
  }

  // move the limbs left by `n` limbs.
  FASTFLOAT_CONSTEXPR20 bool shl_limbs(size_t n) noexcept {
    FASTFLOAT_DEBUG_ASSERT(n != 0);
    if (n + vec.len() > vec.capacity()) {
      return false;
    } else if (!vec.is_empty()) {
      // move limbs
      limb* dst = vec.data + n;
      const limb* src = vec.data;
      std::copy_backward(src, src + vec.len(), dst + vec.len());
      // fill in empty limbs
      limb* first = vec.data;
      limb* last = first + n;
      ::std::fill(first, last, 0);
      vec.set_len(n + vec.len());
      return true;
    } else {
      return true;
    }
  }

  // move the limbs left by `n` bits.
  FASTFLOAT_CONSTEXPR20 bool shl(size_t n) noexcept {
    size_t rem = n % limb_bits;
    size_t div = n / limb_bits;
    if (rem != 0) {
      FASTFLOAT_TRY(shl_bits(rem));
    }
    if (div != 0) {
      FASTFLOAT_TRY(shl_limbs(div));
    }
    return true;
  }

  // get the number of leading zeros in the bigint.
  FASTFLOAT_CONSTEXPR20 int ctlz() const noexcept {
    if (vec.is_empty()) {
      return 0;
    } else {
#ifdef FASTFLOAT_64BIT_LIMB
      return leading_zeroes(vec.rindex(0));
#else
      // no use defining a specialized leading_zeroes for a 32-bit type.
      uint64_t r0 = vec.rindex(0);
      return leading_zeroes(r0 << 32);
#endif
    }
  }

  // get the number of bits in the bigint.
  FASTFLOAT_CONSTEXPR20 int bit_length() const noexcept {
    int lz = ctlz();
    return int(limb_bits * vec.len()) - lz;
  }

  FASTFLOAT_CONSTEXPR20 bool mul(limb y) noexcept {
    return small_mul(vec, y);
  }

  FASTFLOAT_CONSTEXPR20 bool add(limb y) noexcept {
    return small_add(vec, y);
  }

  // multiply as if by 2 raised to a power.
  FASTFLOAT_CONSTEXPR20 bool pow2(uint32_t exp) noexcept {
    return shl(exp);
  }

  // multiply as if by 5 raised to a power.
  FASTFLOAT_CONSTEXPR20 bool pow5(uint32_t exp) noexcept {
    // multiply by a power of 5
    size_t large_length = sizeof(large_power_of_5) / sizeof(limb);
    limb_span large = limb_span(large_power_of_5, large_length);
    while (exp >= large_step) {
      FASTFLOAT_TRY(large_mul(vec, large));
      exp -= large_step;
    }
#ifdef FASTFLOAT_64BIT_LIMB
    uint32_t small_step = 27;
    limb max_native = 7450580596923828125UL;
#else
    uint32_t small_step = 13;
    limb max_native = 1220703125U;
#endif
    while (exp >= small_step) {
      FASTFLOAT_TRY(small_mul(vec, max_native));
      exp -= small_step;
    }
    if (exp != 0) {
      // Work around clang bug https://godbolt.org/z/zedh7rrhc
      // This is similar to https://github.com/llvm/llvm-project/issues/47746,
      // except the workaround described there don't work here
      FASTFLOAT_TRY(
        small_mul(vec, limb(((void)small_power_of_5[0], small_power_of_5[exp])))
      );
    }

    return true;
  }

  // multiply as if by 10 raised to a power.
  FASTFLOAT_CONSTEXPR20 bool pow10(uint32_t exp) noexcept {
    FASTFLOAT_TRY(pow5(exp));
    return pow2(exp);
  }
};

} // namespace fast_float

#endif

#ifndef FASTFLOAT_DIGIT_COMPARISON_H
#define FASTFLOAT_DIGIT_COMPARISON_H

//included above:
//#include <algorithm>
//included above:
//#include <cstdint>
//included above:
//#include <cstring>
//included above:
//#include <iterator>


namespace fast_float {

// 1e0 to 1e19
constexpr static uint64_t powers_of_ten_uint64[] = {
    1UL, 10UL, 100UL, 1000UL, 10000UL, 100000UL, 1000000UL, 10000000UL, 100000000UL,
    1000000000UL, 10000000000UL, 100000000000UL, 1000000000000UL, 10000000000000UL,
    100000000000000UL, 1000000000000000UL, 10000000000000000UL, 100000000000000000UL,
    1000000000000000000UL, 10000000000000000000UL};

// calculate the exponent, in scientific notation, of the number.
// this algorithm is not even close to optimized, but it has no practical
// effect on performance: in order to have a faster algorithm, we'd need
// to slow down performance for faster algorithms, and this is still fast.
template <typename UC>
fastfloat_really_inline FASTFLOAT_CONSTEXPR14
int32_t scientific_exponent(parsed_number_string_t<UC> & num) noexcept {
  uint64_t mantissa = num.mantissa;
  int32_t exponent = int32_t(num.exponent);
  while (mantissa >= 10000) {
    mantissa /= 10000;
    exponent += 4;
  }
  while (mantissa >= 100) {
    mantissa /= 100;
    exponent += 2;
  }
  while (mantissa >= 10) {
    mantissa /= 10;
    exponent += 1;
  }
  return exponent;
}

// this converts a native floating-point number to an extended-precision float.
template <typename T>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
adjusted_mantissa to_extended(T value) noexcept {
  using equiv_uint = typename binary_format<T>::equiv_uint;
  constexpr equiv_uint exponent_mask = binary_format<T>::exponent_mask();
  constexpr equiv_uint mantissa_mask = binary_format<T>::mantissa_mask();
  constexpr equiv_uint hidden_bit_mask = binary_format<T>::hidden_bit_mask();

  adjusted_mantissa am;
  int32_t bias = binary_format<T>::mantissa_explicit_bits() - binary_format<T>::minimum_exponent();
  equiv_uint bits;
#if FASTFLOAT_HAS_BIT_CAST
  bits = std::bit_cast<equiv_uint>(value);
#else
  ::memcpy(&bits, &value, sizeof(T));
#endif
  if ((bits & exponent_mask) == 0) {
    // denormal
    am.power2 = 1 - bias;
    am.mantissa = bits & mantissa_mask;
  } else {
    // normal
    am.power2 = int32_t((bits & exponent_mask) >> binary_format<T>::mantissa_explicit_bits());
    am.power2 -= bias;
    am.mantissa = (bits & mantissa_mask) | hidden_bit_mask;
  }

  return am;
}

// get the extended precision value of the halfway point between b and b+u.
// we are given a native float that represents b, so we need to adjust it
// halfway between b and b+u.
template <typename T>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
adjusted_mantissa to_extended_halfway(T value) noexcept {
  adjusted_mantissa am = to_extended(value);
  am.mantissa <<= 1;
  am.mantissa += 1;
  am.power2 -= 1;
  return am;
}

// round an extended-precision float to the nearest machine float.
template <typename T, typename callback>
fastfloat_really_inline FASTFLOAT_CONSTEXPR14
void round(adjusted_mantissa& am, callback cb) noexcept {
  int32_t mantissa_shift = 64 - binary_format<T>::mantissa_explicit_bits() - 1;
  if (-am.power2 >= mantissa_shift) {
    // have a denormal float
    int32_t shift = -am.power2 + 1;
    cb(am, std::min<int32_t>(shift, 64));
    // check for round-up: if rounding-nearest carried us to the hidden bit.
    am.power2 = (am.mantissa < (uint64_t(1) << binary_format<T>::mantissa_explicit_bits())) ? 0 : 1;
    return;
  }

  // have a normal float, use the default shift.
  cb(am, mantissa_shift);

  // check for carry
  if (am.mantissa >= (uint64_t(2) << binary_format<T>::mantissa_explicit_bits())) {
    am.mantissa = (uint64_t(1) << binary_format<T>::mantissa_explicit_bits());
    am.power2++;
  }

  // check for infinite: we could have carried to an infinite power
  am.mantissa &= ~(uint64_t(1) << binary_format<T>::mantissa_explicit_bits());
  if (am.power2 >= binary_format<T>::infinite_power()) {
    am.power2 = binary_format<T>::infinite_power();
    am.mantissa = 0;
  }
}

template <typename callback>
fastfloat_really_inline FASTFLOAT_CONSTEXPR14
void round_nearest_tie_even(adjusted_mantissa& am, int32_t shift, callback cb) noexcept {
  const uint64_t mask
  = (shift == 64)
    ? UINT64_MAX
    : (uint64_t(1) << shift) - 1;
  const uint64_t halfway
  = (shift == 0)
    ? 0
    : uint64_t(1) << (shift - 1);
  uint64_t truncated_bits = am.mantissa & mask;
  bool is_above = truncated_bits > halfway;
  bool is_halfway = truncated_bits == halfway;

  // shift digits into position
  if (shift == 64) {
    am.mantissa = 0;
  } else {
    am.mantissa >>= shift;
  }
  am.power2 += shift;

  bool is_odd = (am.mantissa & 1) == 1;
  am.mantissa += uint64_t(cb(is_odd, is_halfway, is_above));
}

fastfloat_really_inline FASTFLOAT_CONSTEXPR14
void round_down(adjusted_mantissa& am, int32_t shift) noexcept {
  if (shift == 64) {
    am.mantissa = 0;
  } else {
    am.mantissa >>= shift;
  }
  am.power2 += shift;
}
template <typename UC>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
void skip_zeros(UC const * & first, UC const * last) noexcept {
  uint64_t val;
  while (!cpp20_and_in_constexpr() && std::distance(first, last) >= int_cmp_len<UC>()) {
    ::memcpy(&val, first, sizeof(uint64_t));
    if (val != int_cmp_zeros<UC>()) {
      break;
    }
    first += int_cmp_len<UC>();
  }
  while (first != last) {
    if (*first != UC('0')) {
      break;
    }
    first++;
  }
}

// determine if any non-zero digits were truncated.
// all characters must be valid digits.
template <typename UC>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
bool is_truncated(UC const * first, UC const * last) noexcept {
  // do 8-bit optimizations, can just compare to 8 literal 0s.
  uint64_t val;
  while (!cpp20_and_in_constexpr() && std::distance(first, last) >= int_cmp_len<UC>()) {
    ::memcpy(&val, first, sizeof(uint64_t));
    if (val != int_cmp_zeros<UC>()) {
      return true;
    }
    first += int_cmp_len<UC>();
  }
  while (first != last) {
    if (*first != UC('0')) {
      return true;
    }
    ++first;
  }
  return false;
}
template <typename UC>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
bool is_truncated(span<const UC> s) noexcept {
  return is_truncated(s.ptr, s.ptr + s.len());
}


template <typename UC>
fastfloat_really_inline FASTFLOAT_CONSTEXPR20
void parse_eight_digits(const UC*& p, limb& value, size_t& counter, size_t& count) noexcept {
  value = value * 100000000 + parse_eight_digits_unrolled(p);
  p += 8;
  counter += 8;
  count += 8;
}

template <typename UC>
fastfloat_really_inline FASTFLOAT_CONSTEXPR14
void parse_one_digit(UC const *& p, limb& value, size_t& counter, size_t& count) noexcept {
  value = value * 10 + limb(*p - UC('0'));
  p++;
  counter++;
  count++;
}

fastfloat_really_inline FASTFLOAT_CONSTEXPR20
void add_native(bigint& big, limb power, limb value) noexcept {
  big.mul(power);
  big.add(value);
}

fastfloat_really_inline FASTFLOAT_CONSTEXPR20
void round_up_bigint(bigint& big, size_t& count) noexcept {
  // need to round-up the digits, but need to avoid rounding
  // ....9999 to ...10000, which could cause a false halfway point.
  add_native(big, 10, 1);
  count++;
}

// parse the significant digits into a big integer
template <typename UC>
inline FASTFLOAT_CONSTEXPR20
void parse_mantissa(bigint& result, parsed_number_string_t<UC>& num, size_t max_digits, size_t& digits) noexcept {
  // try to minimize the number of big integer and scalar multiplication.
  // therefore, try to parse 8 digits at a time, and multiply by the largest
  // scalar value (9 or 19 digits) for each step.
  size_t counter = 0;
  digits = 0;
  limb value = 0;
#ifdef FASTFLOAT_64BIT_LIMB
  size_t step = 19;
#else
  size_t step = 9;
#endif

  // process all integer digits.
  UC const * p = num.integer.ptr;
  UC const * pend = p + num.integer.len();
  skip_zeros(p, pend);
  // process all digits, in increments of step per loop
  while (p != pend) {
    while ((std::distance(p, pend) >= 8) && (step - counter >= 8) && (max_digits - digits >= 8)) {
      parse_eight_digits(p, value, counter, digits);
    }
    while (counter < step && p != pend && digits < max_digits) {
      parse_one_digit(p, value, counter, digits);
    }
    if (digits == max_digits) {
      // add the temporary value, then check if we've truncated any digits
      add_native(result, limb(powers_of_ten_uint64[counter]), value);
      bool truncated = is_truncated(p, pend);
      if (num.fraction.ptr != nullptr) {
        truncated |= is_truncated(num.fraction);
      }
      if (truncated) {
        round_up_bigint(result, digits);
      }
      return;
    } else {
      add_native(result, limb(powers_of_ten_uint64[counter]), value);
      counter = 0;
      value = 0;
    }
  }

  // add our fraction digits, if they're available.
  if (num.fraction.ptr != nullptr) {
    p = num.fraction.ptr;
    pend = p + num.fraction.len();
    if (digits == 0) {
      skip_zeros(p, pend);
    }
    // process all digits, in increments of step per loop
    while (p != pend) {
      while ((std::distance(p, pend) >= 8) && (step - counter >= 8) && (max_digits - digits >= 8)) {
        parse_eight_digits(p, value, counter, digits);
      }
      while (counter < step && p != pend && digits < max_digits) {
        parse_one_digit(p, value, counter, digits);
      }
      if (digits == max_digits) {
        // add the temporary value, then check if we've truncated any digits
        add_native(result, limb(powers_of_ten_uint64[counter]), value);
        bool truncated = is_truncated(p, pend);
        if (truncated) {
          round_up_bigint(result, digits);
        }
        return;
      } else {
        add_native(result, limb(powers_of_ten_uint64[counter]), value);
        counter = 0;
        value = 0;
      }
    }
  }

  if (counter != 0) {
    add_native(result, limb(powers_of_ten_uint64[counter]), value);
  }
}

template <typename T>
inline FASTFLOAT_CONSTEXPR20
adjusted_mantissa positive_digit_comp(bigint& bigmant, int32_t exponent) noexcept {
  FASTFLOAT_ASSERT(bigmant.pow10(uint32_t(exponent)));
  adjusted_mantissa answer;
  bool truncated;
  answer.mantissa = bigmant.hi64(truncated);
  int bias = binary_format<T>::mantissa_explicit_bits() - binary_format<T>::minimum_exponent();
  answer.power2 = bigmant.bit_length() - 64 + bias;

  round<T>(answer, [truncated](adjusted_mantissa& a, int32_t shift) {
    round_nearest_tie_even(a, shift, [truncated](bool is_odd, bool is_halfway, bool is_above) -> bool {
      return is_above || (is_halfway && truncated) || (is_odd && is_halfway);
    });
  });

  return answer;
}

// the scaling here is quite simple: we have, for the real digits `m * 10^e`,
// and for the theoretical digits `n * 2^f`. Since `e` is always negative,
// to scale them identically, we do `n * 2^f * 5^-f`, so we now have `m * 2^e`.
// we then need to scale by `2^(f- e)`, and then the two significant digits
// are of the same magnitude.
template <typename T>
inline FASTFLOAT_CONSTEXPR20
adjusted_mantissa negative_digit_comp(bigint& bigmant, adjusted_mantissa am, int32_t exponent) noexcept {
  bigint& real_digits = bigmant;
  int32_t real_exp = exponent;

  // get the value of `b`, rounded down, and get a bigint representation of b+h
  adjusted_mantissa am_b = am;
  // gcc7 buf: use a lambda to remove the noexcept qualifier bug with -Wnoexcept-type.
  round<T>(am_b, [](adjusted_mantissa&a, int32_t shift) { round_down(a, shift); });
  T b;
  to_float(false, am_b, b);
  adjusted_mantissa theor = to_extended_halfway(b);
  bigint theor_digits(theor.mantissa);
  int32_t theor_exp = theor.power2;

  // scale real digits and theor digits to be same power.
  int32_t pow2_exp = theor_exp - real_exp;
  uint32_t pow5_exp = uint32_t(-real_exp);
  if (pow5_exp != 0) {
    FASTFLOAT_ASSERT(theor_digits.pow5(pow5_exp));
  }
  if (pow2_exp > 0) {
    FASTFLOAT_ASSERT(theor_digits.pow2(uint32_t(pow2_exp)));
  } else if (pow2_exp < 0) {
    FASTFLOAT_ASSERT(real_digits.pow2(uint32_t(-pow2_exp)));
  }

  // compare digits, and use it to director rounding
  int ord = real_digits.compare(theor_digits);
  adjusted_mantissa answer = am;
  round<T>(answer, [ord](adjusted_mantissa& a, int32_t shift) {
    round_nearest_tie_even(a, shift, [ord](bool is_odd, bool _, bool __) -> bool {
      (void)_;  // not needed, since we've done our comparison
      (void)__; // not needed, since we've done our comparison
      if (ord > 0) {
        return true;
      } else if (ord < 0) {
        return false;
      } else {
        return is_odd;
      }
    });
  });

  return answer;
}

// parse the significant digits as a big integer to unambiguously round the
// the significant digits. here, we are trying to determine how to round
// an extended float representation close to `b+h`, halfway between `b`
// (the float rounded-down) and `b+u`, the next positive float. this
// algorithm is always correct, and uses one of two approaches. when
// the exponent is positive relative to the significant digits (such as
// 1234), we create a big-integer representation, get the high 64-bits,
// determine if any lower bits are truncated, and use that to direct
// rounding. in case of a negative exponent relative to the significant
// digits (such as 1.2345), we create a theoretical representation of
// `b` as a big-integer type, scaled to the same binary exponent as
// the actual digits. we then compare the big integer representations
// of both, and use that to direct rounding.
template <typename T, typename UC>
inline FASTFLOAT_CONSTEXPR20
adjusted_mantissa digit_comp(parsed_number_string_t<UC>& num, adjusted_mantissa am) noexcept {
  // remove the invalid exponent bias
  am.power2 -= invalid_am_bias;

  int32_t sci_exp = scientific_exponent(num);
  size_t max_digits = binary_format<T>::max_digits();
  size_t digits = 0;
  bigint bigmant;
  parse_mantissa(bigmant, num, max_digits, digits);
  // can't underflow, since digits is at most max_digits.
  int32_t exponent = sci_exp + 1 - int32_t(digits);
  if (exponent >= 0) {
    return positive_digit_comp<T>(bigmant, exponent);
  } else {
    return negative_digit_comp<T>(bigmant, am, exponent);
  }
}

} // namespace fast_float

#endif

#ifndef FASTFLOAT_PARSE_NUMBER_H
#define FASTFLOAT_PARSE_NUMBER_H


//included above:
//#include <cmath>
//included above:
//#include <cstring>
//included above:
//#include <limits>
//included above:
//#include <system_error>
namespace fast_float {


namespace detail {
/**
 * Special case +inf, -inf, nan, infinity, -infinity.
 * The case comparisons could be made much faster given that we know that the
 * strings a null-free and fixed.
 **/
template <typename T, typename UC>
from_chars_result_t<UC> FASTFLOAT_CONSTEXPR14
parse_infnan(UC const * first, UC const * last, T &value)  noexcept  {
  from_chars_result_t<UC> answer{};
  answer.ptr = first;
  answer.ec = std::errc(); // be optimistic
  bool minusSign = false;
  if (*first == UC('-')) { // assume first < last, so dereference without checks; C++17 20.19.3.(7.1) explicitly forbids '+' here
      minusSign = true;
      ++first;
  }
#ifdef FASTFLOAT_ALLOWS_LEADING_PLUS // disabled by default
  if (*first == UC('+')) {
      ++first;
  }
#endif
  if (last - first >= 3) {
    if (fastfloat_strncasecmp(first, str_const_nan<UC>(), 3)) {
      answer.ptr = (first += 3);
      value = minusSign ? -std::numeric_limits<T>::quiet_NaN() : std::numeric_limits<T>::quiet_NaN();
      // Check for possible nan(n-char-seq-opt), C++17 20.19.3.7, C11 7.20.1.3.3. At least MSVC produces nan(ind) and nan(snan).
      if(first != last && *first == UC('(')) {
        for(UC const * ptr = first + 1; ptr != last; ++ptr) {
          if (*ptr == UC(')')) {
            answer.ptr = ptr + 1; // valid nan(n-char-seq-opt)
            break;
          }
          else if(!((UC('a') <= *ptr && *ptr <= UC('z')) || (UC('A') <= *ptr && *ptr <= UC('Z')) || (UC('0') <= *ptr && *ptr <= UC('9')) || *ptr == UC('_')))
            break; // forbidden char, not nan(n-char-seq-opt)
        }
      }
      return answer;
    }
    if (fastfloat_strncasecmp(first, str_const_inf<UC>(), 3)) {
      if ((last - first >= 8) && fastfloat_strncasecmp(first + 3, str_const_inf<UC>() + 3, 5)) {
        answer.ptr = first + 8;
      } else {
        answer.ptr = first + 3;
      }
      value = minusSign ? -std::numeric_limits<T>::infinity() : std::numeric_limits<T>::infinity();
      return answer;
    }
  }
  answer.ec = std::errc::invalid_argument;
  return answer;
}

/**
 * Returns true if the floating-pointing rounding mode is to 'nearest'.
 * It is the default on most system. This function is meant to be inexpensive.
 * Credit : @mwalcott3
 */
fastfloat_really_inline bool rounds_to_nearest() noexcept {
  // https://lemire.me/blog/2020/06/26/gcc-not-nearest/
#if (FLT_EVAL_METHOD != 1) && (FLT_EVAL_METHOD != 0)
  return false;
#endif
  // See
  // A fast function to check your floating-point rounding mode
  // https://lemire.me/blog/2022/11/16/a-fast-function-to-check-your-floating-point-rounding-mode/
  //
  // This function is meant to be equivalent to :
  // prior: #include <cfenv>
  //  return fegetround() == FE_TONEAREST;
  // However, it is expected to be much faster than the fegetround()
  // function call.
  //
  // The volatile keywoard prevents the compiler from computing the function
  // at compile-time.
  // There might be other ways to prevent compile-time optimizations (e.g., asm).
  // The value does not need to be std::numeric_limits<float>::min(), any small
  // value so that 1 + x should round to 1 would do (after accounting for excess
  // precision, as in 387 instructions).
  static volatile float fmin = std::numeric_limits<float>::min();
  float fmini = fmin; // we copy it so that it gets loaded at most once.
  //
  // Explanation:
  // Only when fegetround() == FE_TONEAREST do we have that
  // fmin + 1.0f == 1.0f - fmin.
  //
  // FE_UPWARD:
  //  fmin + 1.0f > 1
  //  1.0f - fmin == 1
  //
  // FE_DOWNWARD or  FE_TOWARDZERO:
  //  fmin + 1.0f == 1
  //  1.0f - fmin < 1
  //
  // Note: This may fail to be accurate if fast-math has been
  // enabled, as rounding conventions may not apply.
  #ifdef FASTFLOAT_VISUAL_STUDIO
  #   pragma warning(push)
  //  todo: is there a VS warning?
  //  see https://stackoverflow.com/questions/46079446/is-there-a-warning-for-floating-point-equality-checking-in-visual-studio-2013
  #elif defined(__clang__)
  #   pragma clang diagnostic push
  #   pragma clang diagnostic ignored "-Wfloat-equal"
  #elif defined(__GNUC__)
  #   pragma GCC diagnostic push
  #   pragma GCC diagnostic ignored "-Wfloat-equal"
  #endif
  return (fmini + 1.0f == 1.0f - fmini);
  #ifdef FASTFLOAT_VISUAL_STUDIO
  #   pragma warning(pop)
  #elif defined(__clang__)
  #   pragma clang diagnostic pop
  #elif defined(__GNUC__)
  #   pragma GCC diagnostic pop
  #endif
}

} // namespace detail

template <typename T>
struct from_chars_caller
{
  template <typename UC>
  FASTFLOAT_CONSTEXPR20
  static from_chars_result_t<UC> call(UC const * first, UC const * last,
                                      T &value, parse_options_t<UC> options)  noexcept {
    return from_chars_advanced(first, last, value, options);
  }
};

#if __STDCPP_FLOAT32_T__ == 1
template <>
struct from_chars_caller<std::float32_t>
{
  template <typename UC>
  FASTFLOAT_CONSTEXPR20
  static from_chars_result_t<UC> call(UC const * first, UC const * last,
                                      std::float32_t &value, parse_options_t<UC> options) noexcept{
    // if std::float32_t is defined, and we are in C++23 mode; macro set for float32; 
    // set value to float due to equivalence between float and float32_t
    float val;
    auto ret = from_chars_advanced(first, last, val, options);
    value = val;
    return ret;
  }
};
#endif

#if __STDCPP_FLOAT64_T__ == 1
template <>
struct from_chars_caller<std::float64_t>
{
  template <typename UC>
  FASTFLOAT_CONSTEXPR20
  static from_chars_result_t<UC> call(UC const * first, UC const * last,
                                      std::float64_t &value, parse_options_t<UC> options) noexcept{
    // if std::float64_t is defined, and we are in C++23 mode; macro set for float64;
    // set value as double due to equivalence between double and float64_t
    double val;
    auto ret = from_chars_advanced(first, last, val, options);
    value = val;
    return ret;
  }
};
#endif


template<typename T, typename UC, typename>
FASTFLOAT_CONSTEXPR20
from_chars_result_t<UC> from_chars(UC const * first, UC const * last,
                             T &value, chars_format fmt /*= chars_format::general*/)  noexcept  {
  return from_chars_caller<T>::call(first, last, value, parse_options_t<UC>(fmt));
}

/**
 * This function overload takes parsed_number_string_t structure that is created and populated
 * either by from_chars_advanced function taking chars range and parsing options
 * or other parsing custom function implemented by user.
 */
template<typename T, typename UC>
FASTFLOAT_CONSTEXPR20
from_chars_result_t<UC> from_chars_advanced(parsed_number_string_t<UC>& pns,
                                      T &value)  noexcept  {

  static_assert (is_supported_float_type<T>(), "only some floating-point types are supported");
  static_assert (is_supported_char_type<UC>(), "only char, wchar_t, char16_t and char32_t are supported");

  from_chars_result_t<UC> answer;

  answer.ec = std::errc(); // be optimistic
  answer.ptr = pns.lastmatch;
  // The implementation of the Clinger's fast path is convoluted because
  // we want round-to-nearest in all cases, irrespective of the rounding mode
  // selected on the thread.
  // We proceed optimistically, assuming that detail::rounds_to_nearest() returns
  // true.
  if (binary_format<T>::min_exponent_fast_path() <= pns.exponent && pns.exponent <= binary_format<T>::max_exponent_fast_path() && !pns.too_many_digits) {
    // Unfortunately, the conventional Clinger's fast path is only possible
    // when the system rounds to the nearest float.
    //
    // We expect the next branch to almost always be selected.
    // We could check it first (before the previous branch), but
    // there might be performance advantages at having the check
    // be last.
    if(!cpp20_and_in_constexpr() && detail::rounds_to_nearest())  {
      // We have that fegetround() == FE_TONEAREST.
      // Next is Clinger's fast path.
      if (pns.mantissa <=binary_format<T>::max_mantissa_fast_path()) {
        value = T(pns.mantissa);
        if (pns.exponent < 0) { value = value / binary_format<T>::exact_power_of_ten(-pns.exponent); }
        else { value = value * binary_format<T>::exact_power_of_ten(pns.exponent); }
        if (pns.negative) { value = -value; }
        return answer;
      }
    } else {
      // We do not have that fegetround() == FE_TONEAREST.
      // Next is a modified Clinger's fast path, inspired by Jakub Jelínek's proposal
      if (pns.exponent >= 0 && pns.mantissa <=binary_format<T>::max_mantissa_fast_path(pns.exponent)) {
#if defined(__clang__) || defined(FASTFLOAT_32BIT)
        // Clang may map 0 to -0.0 when fegetround() == FE_DOWNWARD
        if(pns.mantissa == 0) {
          value = pns.negative ? T(-0.) : T(0.);
          return answer;
        }
#endif
        value = T(pns.mantissa) * binary_format<T>::exact_power_of_ten(pns.exponent);
        if (pns.negative) { value = -value; }
        return answer;
      }
    }
  }
  adjusted_mantissa am = compute_float<binary_format<T>>(pns.exponent, pns.mantissa);
  if(pns.too_many_digits && am.power2 >= 0) {
    if(am != compute_float<binary_format<T>>(pns.exponent, pns.mantissa + 1)) {
      am = compute_error<binary_format<T>>(pns.exponent, pns.mantissa);
    }
  }
  // If we called compute_float<binary_format<T>>(pns.exponent, pns.mantissa) and we have an invalid power (am.power2 < 0),
  // then we need to go the long way around again. This is very uncommon.
  if(am.power2 < 0) { am = digit_comp<T>(pns, am); }
  to_float(pns.negative, am, value);
  // Test for over/underflow.
  if ((pns.mantissa != 0 && am.mantissa == 0 && am.power2 == 0) || am.power2 == binary_format<T>::infinite_power()) {
    answer.ec = std::errc::result_out_of_range;
  }
  return answer;
}

template<typename T, typename UC>
FASTFLOAT_CONSTEXPR20
from_chars_result_t<UC> from_chars_advanced(UC const * first, UC const * last,
                                      T &value, parse_options_t<UC> options)  noexcept  {

  static_assert (is_supported_float_type<T>(), "only some floating-point types are supported");
  static_assert (is_supported_char_type<UC>(), "only char, wchar_t, char16_t and char32_t are supported");

  from_chars_result_t<UC> answer;
#ifdef FASTFLOAT_SKIP_WHITE_SPACE  // disabled by default
  while ((first != last) && fast_float::is_space(uint8_t(*first))) {
    first++;
  }
#endif
  if (first == last) {
    answer.ec = std::errc::invalid_argument;
    answer.ptr = first;
    return answer;
  }
  parsed_number_string_t<UC> pns = parse_number_string<UC>(first, last, options);
  if (!pns.valid) {
    if (options.format & chars_format::no_infnan) {
      answer.ec = std::errc::invalid_argument;
      answer.ptr = first;
      return answer;
    } else {
      return detail::parse_infnan(first, last, value);
    }
  }

  // call overload that takes parsed_number_string_t directly.
  return from_chars_advanced(pns, value);
}


template <typename T, typename UC, typename>
FASTFLOAT_CONSTEXPR20
from_chars_result_t<UC> from_chars(UC const* first, UC const* last, T& value, int base) noexcept {
  static_assert (is_supported_char_type<UC>(), "only char, wchar_t, char16_t and char32_t are supported");

  from_chars_result_t<UC> answer;
#ifdef FASTFLOAT_SKIP_WHITE_SPACE  // disabled by default
  while ((first != last) && fast_float::is_space(uint8_t(*first))) {
    first++;
  }
#endif
  if (first == last || base < 2 || base > 36) {
    answer.ec = std::errc::invalid_argument;
    answer.ptr = first;
    return answer;
  }
  return parse_int_string(first, last, value, base);
}

} // namespace fast_float

#endif

#ifdef _MSC_VER
#   pragma warning(pop)
#elif defined(__clang__) || defined(__APPLE_CC__)
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif

#endif // _C4_EXT_FAST_FLOAT_HPP_


// (end https://github.com/biojppm/c4core/src/c4/ext/fast_float.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/std/vector_fwd.hpp
// https://github.com/biojppm/c4core/src/c4/std/vector_fwd.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_STD_VECTOR_FWD_HPP_
#define _C4_STD_VECTOR_FWD_HPP_

/** @file vector_fwd.hpp */

//included above:
//#include <cstddef>

// forward declarations for std::vector
#if defined(__GLIBCXX__) || defined(__GLIBCPP__) || defined(_MSC_VER)
#if defined(_MSC_VER)
__pragma(warning(push))
__pragma(warning(disable : 4643))
#endif
namespace std {
template<typename> class allocator;
#ifdef _GLIBCXX_DEBUG
inline namespace __debug {
template<typename T, typename Alloc> class vector;
}
#else
template<typename T, typename Alloc> class vector;
#endif
} // namespace std
#if defined(_MSC_VER)
__pragma(warning(pop))
#endif
#elif defined(_LIBCPP_ABI_NAMESPACE)
namespace std {
inline namespace _LIBCPP_ABI_NAMESPACE {
template<typename> class allocator;
template<typename T, typename Alloc> class vector;
} // namespace _LIBCPP_ABI_NAMESPACE
} // namespace std
#else
#error "unknown standard library"
#endif

#ifndef C4CORE_SINGLE_HEADER
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/substr_fwd.hpp
//#include "c4/substr_fwd.hpp"
#if !defined(C4_SUBSTR_FWD_HPP_) && !defined(_C4_SUBSTR_FWD_HPP_)
#error "amalgamate: file c4/substr_fwd.hpp must have been included at this point"
#endif /* C4_SUBSTR_FWD_HPP_ */

#endif

namespace c4 {

template<class Alloc> c4::substr to_substr(std::vector<char, Alloc> &vec);
template<class Alloc> c4::csubstr to_csubstr(std::vector<char, Alloc> const& vec);

template<class Alloc> bool operator!= (c4::csubstr ss, std::vector<char, Alloc> const& s);
template<class Alloc> bool operator== (c4::csubstr ss, std::vector<char, Alloc> const& s);
template<class Alloc> bool operator>= (c4::csubstr ss, std::vector<char, Alloc> const& s);
template<class Alloc> bool operator>  (c4::csubstr ss, std::vector<char, Alloc> const& s);
template<class Alloc> bool operator<= (c4::csubstr ss, std::vector<char, Alloc> const& s);
template<class Alloc> bool operator<  (c4::csubstr ss, std::vector<char, Alloc> const& s);

template<class Alloc> bool operator!= (std::vector<char, Alloc> const& s, c4::csubstr ss);
template<class Alloc> bool operator== (std::vector<char, Alloc> const& s, c4::csubstr ss);
template<class Alloc> bool operator>= (std::vector<char, Alloc> const& s, c4::csubstr ss);
template<class Alloc> bool operator>  (std::vector<char, Alloc> const& s, c4::csubstr ss);
template<class Alloc> bool operator<= (std::vector<char, Alloc> const& s, c4::csubstr ss);
template<class Alloc> bool operator<  (std::vector<char, Alloc> const& s, c4::csubstr ss);

template<class Alloc> size_t to_chars(c4::substr buf, std::vector<char, Alloc> const& s);
template<class Alloc> bool from_chars(c4::csubstr buf, std::vector<char, Alloc> * s);

} // namespace c4

#endif // _C4_STD_VECTOR_FWD_HPP_


// (end https://github.com/biojppm/c4core/src/c4/std/vector_fwd.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/std/string_fwd.hpp
// https://github.com/biojppm/c4core/src/c4/std/string_fwd.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_STD_STRING_FWD_HPP_
#define _C4_STD_STRING_FWD_HPP_

/** @file string_fwd.hpp */

#ifndef DOXYGEN

#ifndef C4CORE_SINGLE_HEADER
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/substr_fwd.hpp
//#include "c4/substr_fwd.hpp"
#if !defined(C4_SUBSTR_FWD_HPP_) && !defined(_C4_SUBSTR_FWD_HPP_)
#error "amalgamate: file c4/substr_fwd.hpp must have been included at this point"
#endif /* C4_SUBSTR_FWD_HPP_ */

#endif

//included above:
//#include <cstddef>

// forward declarations for std::string
#if defined(__GLIBCXX__) || defined(__GLIBCPP__)
#include <bits/stringfwd.h>  // use the fwd header in glibcxx
#elif defined(_LIBCPP_VERSION) || defined(__APPLE_CC__)
#include <iosfwd>  // use the fwd header in stdlibc++
#elif defined(_MSC_VER)
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */

//! @todo is there a fwd header in msvc?
namespace std {
C4_SUPPRESS_WARNING_MSVC_WITH_PUSH(4643) // Forward declaring 'char_traits' in namespace std is not permitted by the C++ Standard.
template<typename> struct char_traits;
template<typename> class allocator;
template<typename _CharT, typename _Traits, typename _Alloc> class basic_string;
using string = basic_string<char, char_traits<char>, allocator<char>>;
C4_SUPPRESS_WARNING_MSVC_POP
} /* namespace std */
#else
#error "unknown standard library"
#endif

namespace c4 {

c4::substr to_substr(std::string &s) noexcept;
c4::csubstr to_csubstr(std::string const& s) noexcept;

bool operator== (c4::csubstr ss, std::string const& s);
bool operator!= (c4::csubstr ss, std::string const& s);
bool operator>= (c4::csubstr ss, std::string const& s);
bool operator>  (c4::csubstr ss, std::string const& s);
bool operator<= (c4::csubstr ss, std::string const& s);
bool operator<  (c4::csubstr ss, std::string const& s);

bool operator== (std::string const& s, c4::csubstr ss);
bool operator!= (std::string const& s, c4::csubstr ss);
bool operator>= (std::string const& s, c4::csubstr ss);
bool operator>  (std::string const& s, c4::csubstr ss);
bool operator<= (std::string const& s, c4::csubstr ss);
bool operator<  (std::string const& s, c4::csubstr ss);

size_t to_chars(c4::substr buf, std::string const& s);
bool from_chars(c4::csubstr buf, std::string * s);

} // namespace c4

#endif // DOXYGEN
#endif // _C4_STD_STRING_FWD_HPP_


// (end https://github.com/biojppm/c4core/src/c4/std/string_fwd.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/std/std_fwd.hpp
// https://github.com/biojppm/c4core/src/c4/std/std_fwd.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_STD_STD_FWD_HPP_
#define _C4_STD_STD_FWD_HPP_

/** @file std_fwd.hpp includes all c4-std interop fwd files */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/std/vector_fwd.hpp
//#include "c4/std/vector_fwd.hpp"
#if !defined(C4_STD_VECTOR_FWD_HPP_) && !defined(_C4_STD_VECTOR_FWD_HPP_)
#error "amalgamate: file c4/std/vector_fwd.hpp must have been included at this point"
#endif /* C4_STD_VECTOR_FWD_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/std/string_fwd.hpp
//#include "c4/std/string_fwd.hpp"
#if !defined(C4_STD_STRING_FWD_HPP_) && !defined(_C4_STD_STRING_FWD_HPP_)
#error "amalgamate: file c4/std/string_fwd.hpp must have been included at this point"
#endif /* C4_STD_STRING_FWD_HPP_ */

//#include "c4/std/tuple_fwd.hpp"

#endif // _C4_STD_STD_FWD_HPP_


// (end https://github.com/biojppm/c4core/src/c4/std/std_fwd.hpp)

// (amalgamate) this include is needed to work around
// conditional includes in charconv.hpp
#if (defined(_MSVC_LANG) && (_MSVC_LANG >= 201703L)) || (__cplusplus >= 201703L)
#include <charconv>
#endif




//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/charconv.hpp
// https://github.com/biojppm/c4core/src/c4/charconv.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_CHARCONV_HPP_
#define _C4_CHARCONV_HPP_

/** @file charconv.hpp Lightweight generic type-safe wrappers for
 * converting individual values to/from strings.
 */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/language.hpp
//#include "c4/language.hpp"
#if !defined(C4_LANGUAGE_HPP_) && !defined(_C4_LANGUAGE_HPP_)
#error "amalgamate: file c4/language.hpp must have been included at this point"
#endif /* C4_LANGUAGE_HPP_ */

//included above:
//#include <inttypes.h>
//included above:
//#include <type_traits>
//included above:
//#include <climits>
//included above:
//#include <limits>
//included above:
//#include <utility>

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/config.hpp
//#include "c4/config.hpp"
#if !defined(C4_CONFIG_HPP_) && !defined(_C4_CONFIG_HPP_)
#error "amalgamate: file c4/config.hpp must have been included at this point"
#endif /* C4_CONFIG_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/substr.hpp
//#include "c4/substr.hpp"
#if !defined(C4_SUBSTR_HPP_) && !defined(_C4_SUBSTR_HPP_)
#error "amalgamate: file c4/substr.hpp must have been included at this point"
#endif /* C4_SUBSTR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/std/std_fwd.hpp
//#include "c4/std/std_fwd.hpp"
#if !defined(C4_STD_STD_FWD_HPP_) && !defined(_C4_STD_STD_FWD_HPP_)
#error "amalgamate: file c4/std/std_fwd.hpp must have been included at this point"
#endif /* C4_STD_STD_FWD_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/memory_util.hpp
//#include "c4/memory_util.hpp"
#if !defined(C4_MEMORY_UTIL_HPP_) && !defined(_C4_MEMORY_UTIL_HPP_)
#error "amalgamate: file c4/memory_util.hpp must have been included at this point"
#endif /* C4_MEMORY_UTIL_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/szconv.hpp
//#include "c4/szconv.hpp"
#if !defined(C4_SZCONV_HPP_) && !defined(_C4_SZCONV_HPP_)
#error "amalgamate: file c4/szconv.hpp must have been included at this point"
#endif /* C4_SZCONV_HPP_ */


#ifndef C4CORE_NO_FAST_FLOAT
#   if (C4_CPP >= 17)
#       if defined(_MSC_VER)
#           if (C4_MSVC_VERSION >= C4_MSVC_VERSION_2019) // VS2017 and lower do not have these macros
//included above:
//#               include <charconv>
#               define C4CORE_HAVE_STD_TOCHARS 1
#               define C4CORE_HAVE_STD_FROMCHARS 0 // prefer fast_float with MSVC
#               define C4CORE_HAVE_FAST_FLOAT 1
#           else
#               define C4CORE_HAVE_STD_TOCHARS 0
#               define C4CORE_HAVE_STD_FROMCHARS 0
#               define C4CORE_HAVE_FAST_FLOAT 1
#           endif
#       else
#           if __has_include(<charconv>)
//included above:
//#               include <charconv>
#               if defined(__cpp_lib_to_chars)
#                   define C4CORE_HAVE_STD_TOCHARS 1
#                   define C4CORE_HAVE_STD_FROMCHARS 0 // glibc uses fast_float internally
#                   define C4CORE_HAVE_FAST_FLOAT 1
#               else
#                   define C4CORE_HAVE_STD_TOCHARS 0
#                   define C4CORE_HAVE_STD_FROMCHARS 0
#                   define C4CORE_HAVE_FAST_FLOAT 1
#               endif
#           else
#               define C4CORE_HAVE_STD_TOCHARS 0
#               define C4CORE_HAVE_STD_FROMCHARS 0
#               define C4CORE_HAVE_FAST_FLOAT 1
#           endif
#       endif
#   else
#       define C4CORE_HAVE_STD_TOCHARS 0
#       define C4CORE_HAVE_STD_FROMCHARS 0
#       define C4CORE_HAVE_FAST_FLOAT 1
#   endif
#   if C4CORE_HAVE_FAST_FLOAT
        C4_SUPPRESS_WARNING_GCC_WITH_PUSH("-Wsign-conversion")
        C4_SUPPRESS_WARNING_GCC("-Warray-bounds")
#       if defined(__GNUC__) && __GNUC__ >= 5
            C4_SUPPRESS_WARNING_GCC("-Wshift-count-overflow")
#       endif
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/ext/fast_float.hpp
//#       include "c4/ext/fast_float.hpp"
#if !defined(C4_EXT_FAST_FLOAT_HPP_) && !defined(_C4_EXT_FAST_FLOAT_HPP_)
#error "amalgamate: file c4/ext/fast_float.hpp must have been included at this point"
#endif /* C4_EXT_FAST_FLOAT_HPP_ */

        C4_SUPPRESS_WARNING_GCC_POP
#   endif
#elif (C4_CPP >= 17)
#   define C4CORE_HAVE_FAST_FLOAT 0
#   if defined(_MSC_VER)
#       if (C4_MSVC_VERSION >= C4_MSVC_VERSION_2019) // VS2017 and lower do not have these macros
//included above:
//#           include <charconv>
#           define C4CORE_HAVE_STD_TOCHARS 1
#           define C4CORE_HAVE_STD_FROMCHARS 1
#       else
#           define C4CORE_HAVE_STD_TOCHARS 0
#           define C4CORE_HAVE_STD_FROMCHARS 0
#       endif
#   else
#       if __has_include(<charconv>)
//included above:
//#           include <charconv>
#           if defined(__cpp_lib_to_chars)
#               define C4CORE_HAVE_STD_TOCHARS 1
#               define C4CORE_HAVE_STD_FROMCHARS 1 // glibc uses fast_float internally
#           else
#               define C4CORE_HAVE_STD_TOCHARS 0
#               define C4CORE_HAVE_STD_FROMCHARS 0
#           endif
#       else
#           define C4CORE_HAVE_STD_TOCHARS 0
#           define C4CORE_HAVE_STD_FROMCHARS 0
#       endif
#   endif
#else
#   define C4CORE_HAVE_STD_TOCHARS 0
#   define C4CORE_HAVE_STD_FROMCHARS 0
#   define C4CORE_HAVE_FAST_FLOAT 0
#endif


#if !C4CORE_HAVE_STD_FROMCHARS
#include <cstdio>
#endif


#if defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable: 4996) // snprintf/scanf: this function or variable may be unsafe
#   if C4_MSVC_VERSION != C4_MSVC_VERSION_2017
#       pragma warning(disable: 4800) //'int': forcing value to bool 'true' or 'false' (performance warning)
#   endif
#endif

#if defined(__clang__)
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wtautological-constant-out-of-range-compare"
#   pragma clang diagnostic ignored "-Wformat-nonliteral"
#   pragma clang diagnostic ignored "-Wdouble-promotion" // implicit conversion increases floating-point precision
#   pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wformat-nonliteral"
#   pragma GCC diagnostic ignored "-Wdouble-promotion" // implicit conversion increases floating-point precision
#   pragma GCC diagnostic ignored "-Wuseless-cast"
#   pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

#if defined(__clang__)
#define C4_NO_UBSAN_IOVRFLW __attribute__((no_sanitize("signed-integer-overflow")))
#elif defined(__GNUC__)
#if __GNUC__ > 7
#define C4_NO_UBSAN_IOVRFLW __attribute__((no_sanitize("signed-integer-overflow")))
#else
#define C4_NO_UBSAN_IOVRFLW
#endif
#else
#define C4_NO_UBSAN_IOVRFLW
#endif


namespace c4 {

/** @defgroup doc_charconv Charconv utilities
 *
 * Lightweight, very fast generic type-safe wrappers for converting
 * individual values to/from strings. These are the main generic
 * functions:
 *   - @ref doc_to_chars and its alias @ref doc_xtoa: implemented by calling @ref itoa()/@ref utoa()/@ref ftoa()/@ref dtoa() (or generically @ref xtoa())
 *   - @ref doc_from_chars and its alias @ref doc_atox: implemented by calling @ref atoi()/@ref atou()/@ref atof()/@ref atod() (or generically @ref atox())
 *   - @ref to_chars_sub()
 *   - @ref from_chars_first()
 *   - @ref xtoa()/@ref atox() are implemented in terms @ref write_dec()/@ref read_dec() et al (see @ref doc_write/@ref doc_read())
 *
 * And also some modest brag is in order: these functions are really
 * fast: faster even than C++17 `std::to_chars()` and
 * `std::to_chars()`, and many dozens of times faster than the
 * iostream abominations.
 *
 * For example, here are some benchmark comparisons for @ref
 * doc_from_chars (link leads to the main project README, where these
 * results are shown more systematically).
 *
 * <table>
 * <caption id="atox-i64-results">atox,int64_t</caption>
 * <tr><th>g++12, linux <th>Visual Studio 2019
 * <tr><td> \image html linux-x86_64-gxx12.1-Release-c4core-bm-charconv-atox-mega_bytes_per_second-i64.png <td> \image html windows-x86_64-vs2019-Release-c4core-bm-charconv-atox-mega_bytes_per_second-i64.png
 * </table>
 *
 * <table>
 * <caption id="xtoa-i64-results">xtoa,int64_t</caption>
 * <tr><th>g++12, linux <th>Visual Studio 2019
 * <tr><td> \image html linux-x86_64-gxx12.1-Release-c4core-bm-charconv-xtoa-mega_bytes_per_second-i64.png <td> \image html windows-x86_64-vs2019-Release-c4core-bm-charconv-xtoa-mega_bytes_per_second-i64.png
 * </table>
 *
 * To parse floating point, c4core uses
 * [fastfloat](https://github.com/fastfloat/fast_float), which is
 * extremely fast, by an even larger factor:
 *
 * <table>
 * <caption id="atox-float-results">atox,float</caption>
 * <tr><th>g++12, linux <th>Visual Studio 2019
 * <tr><td> \image html linux-x86_64-gxx12.1-Release-c4core-bm-charconv-atof-mega_bytes_per_second-float.png <td> \image html windows-x86_64-vs2019-Release-c4core-bm-charconv-atof-mega_bytes_per_second-float.png
 * </table>
 *
 * @{
 */

#if C4CORE_HAVE_STD_TOCHARS
/** @warning Use only the symbol. Do not rely on the type or naked value of this enum. */
typedef enum : std::underlying_type<std::chars_format>::type {
    /** print the real number in floating point format (like %f) */
    FTOA_FLOAT = static_cast<std::underlying_type<std::chars_format>::type>(std::chars_format::fixed),
    /** print the real number in scientific format (like %e) */
    FTOA_SCIENT = static_cast<std::underlying_type<std::chars_format>::type>(std::chars_format::scientific),
    /** print the real number in flexible format (like %g) */
    FTOA_FLEX = static_cast<std::underlying_type<std::chars_format>::type>(std::chars_format::general),
    /** print the real number in hexadecimal format (like %a) */
    FTOA_HEXA = static_cast<std::underlying_type<std::chars_format>::type>(std::chars_format::hex),
} RealFormat_e;
#else
/** @warning Use only the symbol. Do not rely on the type or naked value of this enum. */
typedef enum : char {
    /** print the real number in floating point format (like %f) */
    FTOA_FLOAT = 'f',
    /** print the real number in scientific format (like %e) */
    FTOA_SCIENT = 'e',
    /** print the real number in flexible format (like %g) */
    FTOA_FLEX = 'g',
    /** print the real number in hexadecimal format (like %a) */
    FTOA_HEXA = 'a',
} RealFormat_e;
#endif

/** @cond dev */
/** in some platforms, int,unsigned int
 *  are not any of int8_t...int64_t and
 *  long,unsigned long are not any of uint8_t...uint64_t */
template<class T>
struct is_fixed_length
{
    enum : bool {
        /** true if T is one of the fixed length signed types */
        value_i = (std::is_integral<T>::value
                   && (std::is_same<T, int8_t>::value
                       || std::is_same<T, int16_t>::value
                       || std::is_same<T, int32_t>::value
                       || std::is_same<T, int64_t>::value)),
        /** true if T is one of the fixed length unsigned types */
        value_u = (std::is_integral<T>::value
                   && (std::is_same<T, uint8_t>::value
                       || std::is_same<T, uint16_t>::value
                       || std::is_same<T, uint32_t>::value
                       || std::is_same<T, uint64_t>::value)),
        /** true if T is one of the fixed length signed or unsigned types */
        value = value_i || value_u
    };
};
/** @endcond */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

#ifdef _MSC_VER
#   pragma warning(push)
#elif defined(__clang__)
#   pragma clang diagnostic push
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wconversion"
#   if __GNUC__ >= 6
#       pragma GCC diagnostic ignored "-Wnull-dereference"
#   endif
#endif

/** @cond dev */
namespace detail {

/* python command to get the values below:
def dec(v):
    return str(v)
for bits in (8, 16, 32, 64):
    imin, imax, umax = (-(1 << (bits - 1))), (1 << (bits - 1)) - 1, (1 << bits) - 1
    for vname, v in (("imin", imin), ("imax", imax), ("umax", umax)):
        for f in (bin, oct, dec, hex):
            print(f"{bits}b: {vname}={v} {f.__name__}: len={len(f(v)):2d}: {v} {f(v)}")
*/

// do not use the type as the template argument because in some
// platforms long!=int32 and long!=int64. Just use the numbytes
// which is more generic and spares lengthy SFINAE code.
template<size_t num_bytes, bool is_signed> struct charconv_digits_;
template<class T> using charconv_digits = charconv_digits_<sizeof(T), std::is_signed<T>::value>;

template<> struct charconv_digits_<1u, true> // int8_t
{
    enum : size_t {
        maxdigits_bin       = 1 + 2 + 8, // -128==-0b10000000
        maxdigits_oct       = 1 + 2 + 3, // -128==-0o200
        maxdigits_dec       = 1     + 3, // -128
        maxdigits_hex       = 1 + 2 + 2, // -128==-0x80
        maxdigits_bin_nopfx =         8, // -128==-0b10000000
        maxdigits_oct_nopfx =         3, // -128==-0o200
        maxdigits_dec_nopfx =         3, // -128
        maxdigits_hex_nopfx =         2, // -128==-0x80
    };
    // min values without sign!
    static constexpr csubstr min_value_dec() noexcept { return csubstr("128"); }
    static constexpr csubstr min_value_hex() noexcept { return csubstr("80"); }
    static constexpr csubstr min_value_oct() noexcept { return csubstr("200"); }
    static constexpr csubstr min_value_bin() noexcept { return csubstr("10000000"); }
    static constexpr csubstr max_value_dec() noexcept { return csubstr("127"); }
    static constexpr bool    is_oct_overflow(csubstr str) noexcept { return !((str.len < 3) || (str.len == 3 && str[0] <= '1')); }
};
template<> struct charconv_digits_<1u, false> // uint8_t
{
    enum : size_t {
        maxdigits_bin       = 2 + 8, // 255 0b11111111
        maxdigits_oct       = 2 + 3, // 255 0o377
        maxdigits_dec       =     3, // 255
        maxdigits_hex       = 2 + 2, // 255 0xff
        maxdigits_bin_nopfx =     8, // 255 0b11111111
        maxdigits_oct_nopfx =     3, // 255 0o377
        maxdigits_dec_nopfx =     3, // 255
        maxdigits_hex_nopfx =     2, // 255 0xff
    };
    static constexpr csubstr max_value_dec() noexcept { return csubstr("255"); }
    static constexpr bool    is_oct_overflow(csubstr str) noexcept { return !((str.len < 3) || (str.len == 3 && str[0] <= '3')); }
};
template<> struct charconv_digits_<2u, true> // int16_t
{
    enum : size_t {
        maxdigits_bin       = 1 + 2 + 16, // -32768 -0b1000000000000000
        maxdigits_oct       = 1 + 2 +  6, // -32768 -0o100000
        maxdigits_dec       = 1     +  5, // -32768 -32768
        maxdigits_hex       = 1 + 2 +  4, // -32768 -0x8000
        maxdigits_bin_nopfx =         16, // -32768 -0b1000000000000000
        maxdigits_oct_nopfx =          6, // -32768 -0o100000
        maxdigits_dec_nopfx =          5, // -32768 -32768
        maxdigits_hex_nopfx =          4, // -32768 -0x8000
    };
    // min values without sign!
    static constexpr csubstr min_value_dec() noexcept { return csubstr("32768"); }
    static constexpr csubstr min_value_hex() noexcept { return csubstr("8000"); }
    static constexpr csubstr min_value_oct() noexcept { return csubstr("100000"); }
    static constexpr csubstr min_value_bin() noexcept { return csubstr("1000000000000000"); }
    static constexpr csubstr max_value_dec() noexcept { return csubstr("32767"); }
    static constexpr bool    is_oct_overflow(csubstr str) noexcept { return !((str.len < 6)); }
};
template<> struct charconv_digits_<2u, false> // uint16_t
{
    enum : size_t {
        maxdigits_bin       = 2 + 16, // 65535 0b1111111111111111
        maxdigits_oct       = 2 +  6, // 65535 0o177777
        maxdigits_dec       =      6, // 65535 65535
        maxdigits_hex       = 2 +  4, // 65535 0xffff
        maxdigits_bin_nopfx =     16, // 65535 0b1111111111111111
        maxdigits_oct_nopfx =      6, // 65535 0o177777
        maxdigits_dec_nopfx =      6, // 65535 65535
        maxdigits_hex_nopfx =      4, // 65535 0xffff
    };
    static constexpr csubstr max_value_dec() noexcept { return csubstr("65535"); }
    static constexpr bool    is_oct_overflow(csubstr str) noexcept { return !((str.len < 6) || (str.len == 6 && str[0] <= '1')); }
};
template<> struct charconv_digits_<4u, true> // int32_t
{
    enum : size_t {
        maxdigits_bin       = 1 + 2 + 32, // len=35: -2147483648 -0b10000000000000000000000000000000
        maxdigits_oct       = 1 + 2 + 11, // len=14: -2147483648 -0o20000000000
        maxdigits_dec       = 1     + 10, // len=11: -2147483648 -2147483648
        maxdigits_hex       = 1 + 2 +  8, // len=11: -2147483648 -0x80000000
        maxdigits_bin_nopfx =         32, // len=35: -2147483648 -0b10000000000000000000000000000000
        maxdigits_oct_nopfx =         11, // len=14: -2147483648 -0o20000000000
        maxdigits_dec_nopfx =         10, // len=11: -2147483648 -2147483648
        maxdigits_hex_nopfx =          8, // len=11: -2147483648 -0x80000000
    };
    // min values without sign!
    static constexpr csubstr min_value_dec() noexcept { return csubstr("2147483648"); }
    static constexpr csubstr min_value_hex() noexcept { return csubstr("80000000"); }
    static constexpr csubstr min_value_oct() noexcept { return csubstr("20000000000"); }
    static constexpr csubstr min_value_bin() noexcept { return csubstr("10000000000000000000000000000000"); }
    static constexpr csubstr max_value_dec() noexcept { return csubstr("2147483647"); }
    static constexpr bool    is_oct_overflow(csubstr str) noexcept { return !((str.len < 11) || (str.len == 11 && str[0] <= '1')); }
};
template<> struct charconv_digits_<4u, false> // uint32_t
{
    enum : size_t {
        maxdigits_bin       = 2 + 32, // len=34: 4294967295 0b11111111111111111111111111111111
        maxdigits_oct       = 2 + 11, // len=13: 4294967295 0o37777777777
        maxdigits_dec       =     10, // len=10: 4294967295 4294967295
        maxdigits_hex       = 2 +  8, // len=10: 4294967295 0xffffffff
        maxdigits_bin_nopfx =     32, // len=34: 4294967295 0b11111111111111111111111111111111
        maxdigits_oct_nopfx =     11, // len=13: 4294967295 0o37777777777
        maxdigits_dec_nopfx =     10, // len=10: 4294967295 4294967295
        maxdigits_hex_nopfx =      8, // len=10: 4294967295 0xffffffff
    };
    static constexpr csubstr max_value_dec() noexcept { return csubstr("4294967295"); }
    static constexpr bool is_oct_overflow(csubstr str) noexcept { return !((str.len < 11) || (str.len == 11 && str[0] <= '3')); }
};
template<> struct charconv_digits_<8u, true> // int32_t
{
    enum : size_t {
        maxdigits_bin       = 1 + 2 + 64, // len=67: -9223372036854775808 -0b1000000000000000000000000000000000000000000000000000000000000000
        maxdigits_oct       = 1 + 2 + 22, // len=25: -9223372036854775808 -0o1000000000000000000000
        maxdigits_dec       = 1     + 19, // len=20: -9223372036854775808 -9223372036854775808
        maxdigits_hex       = 1 + 2 + 16, // len=19: -9223372036854775808 -0x8000000000000000
        maxdigits_bin_nopfx =         64, // len=67: -9223372036854775808 -0b1000000000000000000000000000000000000000000000000000000000000000
        maxdigits_oct_nopfx =         22, // len=25: -9223372036854775808 -0o1000000000000000000000
        maxdigits_dec_nopfx =         19, // len=20: -9223372036854775808 -9223372036854775808
        maxdigits_hex_nopfx =         16, // len=19: -9223372036854775808 -0x8000000000000000
    };
    static constexpr csubstr min_value_dec() noexcept { return csubstr("9223372036854775808"); }
    static constexpr csubstr min_value_hex() noexcept { return csubstr("8000000000000000"); }
    static constexpr csubstr min_value_oct() noexcept { return csubstr("1000000000000000000000"); }
    static constexpr csubstr min_value_bin() noexcept { return csubstr("1000000000000000000000000000000000000000000000000000000000000000"); }
    static constexpr csubstr max_value_dec() noexcept { return csubstr("9223372036854775807"); }
    static constexpr bool    is_oct_overflow(csubstr str) noexcept { return !((str.len < 22)); }
};
template<> struct charconv_digits_<8u, false>
{
    enum : size_t {
        maxdigits_bin       = 2 + 64, // len=66: 18446744073709551615 0b1111111111111111111111111111111111111111111111111111111111111111
        maxdigits_oct       = 2 + 22, // len=24: 18446744073709551615 0o1777777777777777777777
        maxdigits_dec       =     20, // len=20: 18446744073709551615 18446744073709551615
        maxdigits_hex       = 2 + 16, // len=18: 18446744073709551615 0xffffffffffffffff
        maxdigits_bin_nopfx =     64, // len=66: 18446744073709551615 0b1111111111111111111111111111111111111111111111111111111111111111
        maxdigits_oct_nopfx =     22, // len=24: 18446744073709551615 0o1777777777777777777777
        maxdigits_dec_nopfx =     20, // len=20: 18446744073709551615 18446744073709551615
        maxdigits_hex_nopfx =     16, // len=18: 18446744073709551615 0xffffffffffffffff
    };
    static constexpr csubstr max_value_dec() noexcept { return csubstr("18446744073709551615"); }
    static constexpr bool    is_oct_overflow(csubstr str) noexcept { return !((str.len < 22) || (str.len == 22 && str[0] <= '1')); }
};
} // namespace detail

// Helper macros, undefined below
#define _c4append(c) { if(C4_LIKELY(pos < buf.len)) { buf.str[pos++] = static_cast<char>(c); } else { ++pos; } }
#define _c4appendhex(i) { if(C4_LIKELY(pos < buf.len)) { buf.str[pos++] = hexchars[i]; } else { ++pos; } }

/** @endcond */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


/** @defgroup doc_digits Get number of digits
 *
 * @note At first sight this code may look heavily branchy and
 * therefore inefficient. However, measurements revealed this to be
 * the fastest among the alternatives.
 *
 * @see https://github.com/biojppm/c4core/pull/77
 *
 * @{
 */

/** decimal digits for 8 bit integers */
template<class T>
C4_CONSTEXPR14 C4_ALWAYS_INLINE
auto digits_dec(T v) noexcept
    -> typename std::enable_if<sizeof(T) == 1u, unsigned>::type
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    return ((v >= 100) ? 3u : ((v >= 10) ? 2u : 1u));
}

/** decimal digits for 16 bit integers */
template<class T>
C4_CONSTEXPR14 C4_ALWAYS_INLINE
auto digits_dec(T v) noexcept
    -> typename std::enable_if<sizeof(T) == 2u, unsigned>::type
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    return ((v >= 10000) ? 5u : (v >= 1000) ? 4u : (v >= 100) ? 3u : (v >= 10) ? 2u : 1u);
}

/** decimal digits for 32 bit integers */
template<class T>
C4_CONSTEXPR14 C4_ALWAYS_INLINE
auto digits_dec(T v) noexcept
    -> typename std::enable_if<sizeof(T) == 4u, unsigned>::type
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    return ((v >= 1000000000) ? 10u : (v >= 100000000) ? 9u : (v >= 10000000) ? 8u :
            (v >= 1000000) ? 7u : (v >= 100000) ? 6u : (v >= 10000) ? 5u :
            (v >= 1000) ? 4u : (v >= 100) ? 3u : (v >= 10) ? 2u : 1u);
}

/** decimal digits for 64 bit integers */
template<class T>
C4_CONSTEXPR14 C4_ALWAYS_INLINE
auto digits_dec(T v) noexcept
    -> typename std::enable_if<sizeof(T) == 8u, unsigned>::type
{
    // thanks @fargies!!!
    // https://github.com/biojppm/c4core/pull/77#issuecomment-1063753568
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    if(v >= 1000000000) // 10
    {
        if(v >= 100000000000000) // 15 [15-20] range
        {
            if(v >= 100000000000000000) // 18 (15 + (20 - 15) / 2)
            {
                if((typename std::make_unsigned<T>::type)v >= 10000000000000000000u) // 20
                    return 20u;
                else
                    return (v >= 1000000000000000000) ? 19u : 18u;
            }
            else if(v >= 10000000000000000) // 17
                return 17u;
            else
                return(v >= 1000000000000000) ? 16u : 15u;
        }
        else if(v >= 1000000000000) // 13
            return (v >= 10000000000000) ? 14u : 13u;
        else if(v >= 100000000000) // 12
            return 12;
        else
            return(v >= 10000000000) ? 11u : 10u;
    }
    else if(v >= 10000) // 5 [5-9] range
    {
        if(v >= 10000000) // 8
            return (v >= 100000000) ? 9u : 8u;
        else if(v >= 1000000) // 7
            return 7;
        else
            return (v >= 100000) ? 6u : 5u;
    }
    else if(v >= 100)
        return (v >= 1000) ? 4u : 3u;
    else
        return (v >= 10) ? 2u : 1u;
}


/** return the number of digits required to encode an hexadecimal number. */
template<class T>
C4_CONSTEXPR14 C4_ALWAYS_INLINE unsigned digits_hex(T v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    return v ? 1u + (msb((typename std::make_unsigned<T>::type)v) >> 2u) : 1u;
}

/** return the number of digits required to encode a binary number. */
template<class T>
C4_CONSTEXPR14 C4_ALWAYS_INLINE unsigned digits_bin(T v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    return v ? 1u + msb((typename std::make_unsigned<T>::type)v) : 1u;
}

/** return the number of digits required to encode an octal number. */
template<class T>
C4_CONSTEXPR14 C4_ALWAYS_INLINE unsigned digits_oct(T v_) noexcept
{
    // TODO: is there a better way?
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v_ >= 0);
    using U = typename
        std::conditional<sizeof(T) <= sizeof(unsigned),
                         unsigned,
                         typename std::make_unsigned<T>::type>::type;
    U v = (U) v_;  // safe because we require v_ >= 0
    unsigned __n = 1;
    const unsigned __b2 = 64u;
    const unsigned __b3 = __b2 * 8u;
    const unsigned long __b4 = __b3 * 8u;
    while(true)
	{
        if(v < 8u)
            return __n;
        if(v < __b2)
            return __n + 1;
        if(v < __b3)
            return __n + 2;
        if(v < __b4)
            return __n + 3;
        v /= (U) __b4;
        __n += 4;
	}
}

/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @cond dev */
namespace detail {
C4_INLINE_CONSTEXPR const char hexchars[] = "0123456789abcdef";
C4_INLINE_CONSTEXPR const char digits0099[] =
    "0001020304050607080910111213141516171819"
    "2021222324252627282930313233343536373839"
    "4041424344454647484950515253545556575859"
    "6061626364656667686970717273747576777879"
    "8081828384858687888990919293949596979899";
} // namespace detail
/** @endcond */

C4_SUPPRESS_WARNING_GCC_PUSH
C4_SUPPRESS_WARNING_GCC("-Warray-bounds")  // gcc has false positives here
#if (defined(__GNUC__) && (__GNUC__ >= 7))
C4_SUPPRESS_WARNING_GCC("-Wstringop-overflow")  // gcc has false positives here
#endif

/** @defgroup doc_write_unchecked Write with known number of digits
 *
 * Writes a value without checking the buffer length with regards to
 * the required number of digits to encode the value. It is the
 * responsibility of the caller to ensure that the provided number of
 * digits is enough to write the given value. Notwithstanding the
 * name, assertions are liberally performed, so this code is safe.
 *
 * @{ */

template<class T>
C4_HOT C4_ALWAYS_INLINE
void write_dec_unchecked(substr buf, T v, unsigned digits_v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    C4_ASSERT(buf.len >= digits_v);
    C4_XASSERT(digits_v == digits_dec(v));
    // in bm_xtoa: checkoncelog_singlediv_write2
    while(v >= T(100))
    {
        T quo = v;
        quo /= T(100);
        const auto num = (v - quo * T(100)) << 1u;
        v = quo;
        buf.str[--digits_v] = detail::digits0099[num + 1];
        buf.str[--digits_v] = detail::digits0099[num];
    }
    if(v >= T(10))
    {
        C4_ASSERT(digits_v == 2);
        const auto num = v << 1u;
        buf.str[1] = detail::digits0099[num + 1];
        buf.str[0] = detail::digits0099[num];
    }
    else
    {
        C4_ASSERT(digits_v == 1);
        buf.str[0] = (char)('0' + v);
    }
}


template<class T>
C4_HOT C4_ALWAYS_INLINE
void write_hex_unchecked(substr buf, T v, unsigned digits_v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    C4_ASSERT(buf.len >= digits_v);
    C4_XASSERT(digits_v == digits_hex(v));
    do {
        buf.str[--digits_v] = detail::hexchars[v & T(15)];
        v >>= 4;
    } while(v);
    C4_ASSERT(digits_v == 0);
}


template<class T>
C4_HOT C4_ALWAYS_INLINE
void write_oct_unchecked(substr buf, T v, unsigned digits_v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    C4_ASSERT(buf.len >= digits_v);
    C4_XASSERT(digits_v == digits_oct(v));
    do {
        buf.str[--digits_v] = (char)('0' + (v & T(7)));
        v >>= 3;
    } while(v);
    C4_ASSERT(digits_v == 0);
}


template<class T>
C4_HOT C4_ALWAYS_INLINE
void write_bin_unchecked(substr buf, T v, unsigned digits_v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    C4_ASSERT(buf.len >= digits_v);
    C4_XASSERT(digits_v == digits_bin(v));
    do {
        buf.str[--digits_v] = (char)('0' + (v & T(1)));
        v >>= 1;
    } while(v);
    C4_ASSERT(digits_v == 0);
}

/** @} */ // write_unchecked


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @defgroup doc_write Write a value
 *
 * Writes a value without checking the buffer length
 * decimal number -- but asserting.
 *
 * @{ */

/** write an integer to a string in decimal format. This is the
 * lowest level (and the fastest) function to do this task.
 * @note does not accept negative numbers
 * @note the resulting string is NOT zero-terminated.
 * @note it is ok to call this with an empty or too-small buffer;
 * no writes will occur, and the required size will be returned
 * @return the number of characters required for the buffer. */
template<class T>
C4_ALWAYS_INLINE size_t write_dec(substr buf, T v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    unsigned digits = digits_dec(v);
    if(C4_LIKELY(buf.len >= digits))
        write_dec_unchecked(buf, v, digits);
    return digits;
}

/** write an integer to a string in hexadecimal format. This is the
 * lowest level (and the fastest) function to do this task.
 * @note does not accept negative numbers
 * @note does not prefix with 0x
 * @note the resulting string is NOT zero-terminated.
 * @note it is ok to call this with an empty or too-small buffer;
 * no writes will occur, and the required size will be returned
 * @return the number of characters required for the buffer. */
template<class T>
C4_ALWAYS_INLINE size_t write_hex(substr buf, T v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    unsigned digits = digits_hex(v);
    if(C4_LIKELY(buf.len >= digits))
        write_hex_unchecked(buf, v, digits);
    return digits;
}

/** write an integer to a string in octal format. This is the
 * lowest level (and the fastest) function to do this task.
 * @note does not accept negative numbers
 * @note does not prefix with 0o
 * @note the resulting string is NOT zero-terminated.
 * @note it is ok to call this with an empty or too-small buffer;
 * no writes will occur, and the required size will be returned
 * @return the number of characters required for the buffer. */
template<class T>
C4_ALWAYS_INLINE size_t write_oct(substr buf, T v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    unsigned digits = digits_oct(v);
    if(C4_LIKELY(buf.len >= digits))
        write_oct_unchecked(buf, v, digits);
    return digits;
}

/** write an integer to a string in binary format. This is the
 * lowest level (and the fastest) function to do this task.
 * @note does not accept negative numbers
 * @note does not prefix with 0b
 * @note the resulting string is NOT zero-terminated.
 * @note it is ok to call this with an empty or too-small buffer;
 * no writes will occur, and the required size will be returned
 * @return the number of characters required for the buffer. */
template<class T>
C4_ALWAYS_INLINE size_t write_bin(substr buf, T v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_ASSERT(v >= 0);
    unsigned digits = digits_bin(v);
    C4_ASSERT(digits > 0);
    if(C4_LIKELY(buf.len >= digits))
        write_bin_unchecked(buf, v, digits);
    return digits;
}


/** @cond dev */
namespace detail {
template<class U> using NumberWriter = size_t (*)(substr, U);
template<class T, NumberWriter<T> writer>
size_t write_num_digits(substr buf, T v, size_t num_digits) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    size_t ret = writer(buf, v);
    if(ret >= num_digits)
        return ret;
    else if(ret >= buf.len || num_digits > buf.len)
        return num_digits;
    C4_ASSERT(num_digits >= ret);
    size_t delta = static_cast<size_t>(num_digits - ret);
    memmove(buf.str + delta, buf.str, ret);
    memset(buf.str, '0', delta);
    return num_digits;
}
} // namespace detail
/** @endcond */


/** same as c4::write_dec(), but pad with zeroes on the left
 * such that the resulting string is @p num_digits wide.
 * If the given number is requires more than num_digits, then the number prevails. */
template<class T>
C4_ALWAYS_INLINE size_t write_dec(substr buf, T val, size_t num_digits) noexcept
{
    return detail::write_num_digits<T, &write_dec<T>>(buf, val, num_digits);
}

/** same as c4::write_hex(), but pad with zeroes on the left
 * such that the resulting string is @p num_digits wide.
 * If the given number is requires more than num_digits, then the number prevails. */
template<class T>
C4_ALWAYS_INLINE size_t write_hex(substr buf, T val, size_t num_digits) noexcept
{
    return detail::write_num_digits<T, &write_hex<T>>(buf, val, num_digits);
}

/** same as c4::write_bin(), but pad with zeroes on the left
 * such that the resulting string is @p num_digits wide.
 * If the given number is requires more than num_digits, then the number prevails. */
template<class T>
C4_ALWAYS_INLINE size_t write_bin(substr buf, T val, size_t num_digits) noexcept
{
    return detail::write_num_digits<T, &write_bin<T>>(buf, val, num_digits);
}

/** same as c4::write_oct(), but pad with zeroes on the left
 * such that the resulting string is @p num_digits wide.
 * If the given number is requires more than num_digits, then the number prevails. */
template<class T>
C4_ALWAYS_INLINE size_t write_oct(substr buf, T val, size_t num_digits) noexcept
{
    return detail::write_num_digits<T, &write_oct<T>>(buf, val, num_digits);
}

/** @} */ // write

C4_SUPPRESS_WARNING_GCC_POP


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


C4_SUPPRESS_WARNING_MSVC_PUSH
C4_SUPPRESS_WARNING_MSVC(4365) // '=': conversion from 'int' to 'I', signed/unsigned mismatch

/** @defgroup doc_read Read a value
 *
 * @{ */

/** read a decimal integer from a string. This is the
 * lowest level (and the fastest) function to do this task.
 * @note does not accept negative numbers
 * @note The string must be trimmed. Whitespace is not accepted.
 * @note the string must not be empty
 * @note there is no check for overflow; the value wraps around
 * in a way similar to the standard C/C++ overflow behavior.
 * For example, `read_dec<int8_t>("128", &val)` returns true
 * and val will be set to 0 because 127 is the max i8 value.
 * @see overflows<T>() to find out if a number string overflows a type range
 * @return true if the conversion was successful (no overflow check) */
template<class I>
C4_NO_UBSAN_IOVRFLW
C4_ALWAYS_INLINE bool read_dec(csubstr s, I *C4_RESTRICT v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<I>::value);
    C4_ASSERT(!s.empty());
    *v = 0;
    for(char c : s)
    {
        if(C4_UNLIKELY(c < '0' || c > '9'))
            return false;
        *v = (*v) * I(10) + (I(c) - I('0'));
    }
    return true;
}

/** read an hexadecimal integer from a string. This is the
 * lowest level (and the fastest) function to do this task.
 * @note does not accept negative numbers
 * @note does not accept leading 0x or 0X
 * @note the string must not be empty
 * @note the string must be trimmed. Whitespace is not accepted.
 * @note there is no check for overflow; the value wraps around
 * in a way similar to the standard C/C++ overflow behavior.
 * For example, `read_hex<int8_t>("80", &val)` returns true
 * and val will be set to 0 because 7f is the max i8 value.
 * @see overflows<T>() to find out if a number string overflows a type range
 * @return true if the conversion was successful (no overflow check) */
template<class I>
C4_NO_UBSAN_IOVRFLW
C4_ALWAYS_INLINE bool read_hex(csubstr s, I *C4_RESTRICT v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<I>::value);
    C4_ASSERT(!s.empty());
    *v = 0;
    for(char c : s)
    {
        I cv;
        if(c >= '0' && c <= '9')
            cv = I(c) - I('0');
        else if(c >= 'a' && c <= 'f')
            cv = I(10) + (I(c) - I('a'));
        else if(c >= 'A' && c <= 'F')
            cv = I(10) + (I(c) - I('A'));
        else
            return false;
        *v = (*v) * I(16) + cv;
    }
    return true;
}

/** read a binary integer from a string. This is the
 * lowest level (and the fastest) function to do this task.
 * @note does not accept negative numbers
 * @note does not accept leading 0b or 0B
 * @note the string must not be empty
 * @note the string must be trimmed. Whitespace is not accepted.
 * @note there is no check for overflow; the value wraps around
 * in a way similar to the standard C/C++ overflow behavior.
 * For example, `read_bin<int8_t>("10000000", &val)` returns true
 * and val will be set to 0 because 1111111 is the max i8 value.
 * @see overflows<T>() to find out if a number string overflows a type range
 * @return true if the conversion was successful (no overflow check) */
template<class I>
C4_NO_UBSAN_IOVRFLW
C4_ALWAYS_INLINE bool read_bin(csubstr s, I *C4_RESTRICT v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<I>::value);
    C4_ASSERT(!s.empty());
    *v = 0;
    for(char c : s)
    {
        *v <<= 1;
        if(c == '1')
            *v |= 1;
        else if(c != '0')
            return false;
    }
    return true;
}

/** read an octal integer from a string. This is the
 * lowest level (and the fastest) function to do this task.
 * @note does not accept negative numbers
 * @note does not accept leading 0o or 0O
 * @note the string must not be empty
 * @note the string must be trimmed. Whitespace is not accepted.
 * @note there is no check for overflow; the value wraps around
 * in a way similar to the standard C/C++ overflow behavior.
 * For example, `read_oct<int8_t>("200", &val)` returns true
 * and val will be set to 0 because 177 is the max i8 value.
 * @see overflows<T>() to find out if a number string overflows a type range
 * @return true if the conversion was successful (no overflow check) */
template<class I>
C4_NO_UBSAN_IOVRFLW
C4_ALWAYS_INLINE bool read_oct(csubstr s, I *C4_RESTRICT v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<I>::value);
    C4_ASSERT(!s.empty());
    *v = 0;
    for(char c : s)
    {
        if(C4_UNLIKELY(c < '0' || c > '7'))
            return false;
        *v = (*v) * I(8) + (I(c) - I('0'));
    }
    return true;
}

/** @} */

C4_SUPPRESS_WARNING_MSVC_POP


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

C4_SUPPRESS_WARNING_GCC_WITH_PUSH("-Wswitch-default")

/** @cond dev */
namespace detail {
inline size_t _itoa2buf(substr buf, size_t pos, csubstr val) noexcept
{
    C4_ASSERT(pos + val.len <= buf.len);
    memcpy(buf.str + pos, val.str, val.len);
    return pos + val.len;
}
inline size_t _itoa2bufwithdigits(substr buf, size_t pos, size_t num_digits, csubstr val) noexcept
{
    num_digits = num_digits > val.len ? num_digits - val.len : 0;
    C4_ASSERT(num_digits + val.len <= buf.len);
    for(size_t i = 0; i < num_digits; ++i)
        _c4append('0');
    return detail::_itoa2buf(buf, pos, val);
}
template<class I>
C4_NO_INLINE size_t _itoadec2buf(substr buf) noexcept
{
    using digits_type = detail::charconv_digits<I>;
    if(C4_UNLIKELY(buf.len < digits_type::maxdigits_dec))
        return digits_type::maxdigits_dec;
    buf.str[0] = '-';
    return detail::_itoa2buf(buf, 1, digits_type::min_value_dec());
}
template<class I>
C4_NO_INLINE size_t _itoa2buf(substr buf, I radix) noexcept
{
    using digits_type = detail::charconv_digits<I>;
    size_t pos = 0;
    if(C4_LIKELY(buf.len > 0))
        buf.str[pos++] = '-';
    switch(radix)
    {
    case I(10):
        if(C4_UNLIKELY(buf.len < digits_type::maxdigits_dec))
            return digits_type::maxdigits_dec;
        pos =_itoa2buf(buf, pos, digits_type::min_value_dec());
        break;
    case I(16):
        if(C4_UNLIKELY(buf.len < digits_type::maxdigits_hex))
            return digits_type::maxdigits_hex;
        buf.str[pos++] = '0';
        buf.str[pos++] = 'x';
        pos = _itoa2buf(buf, pos, digits_type::min_value_hex());
        break;
    case I( 2):
        if(C4_UNLIKELY(buf.len < digits_type::maxdigits_bin))
            return digits_type::maxdigits_bin;
        buf.str[pos++] = '0';
        buf.str[pos++] = 'b';
        pos = _itoa2buf(buf, pos, digits_type::min_value_bin());
        break;
    case I( 8):
        if(C4_UNLIKELY(buf.len < digits_type::maxdigits_oct))
            return digits_type::maxdigits_oct;
        buf.str[pos++] = '0';
        buf.str[pos++] = 'o';
        pos = _itoa2buf(buf, pos, digits_type::min_value_oct());
        break;
    }
    return pos;
}
template<class I>
C4_NO_INLINE size_t _itoa2buf(substr buf, I radix, size_t num_digits) noexcept
{
    using digits_type = detail::charconv_digits<I>;
    size_t pos = 0;
    size_t needed_digits = 0;
    if(C4_LIKELY(buf.len > 0))
        buf.str[pos++] = '-';
    switch(radix)
    {
    case I(10):
        // add 1 to account for -
        needed_digits = num_digits+1 > digits_type::maxdigits_dec ? num_digits+1 : digits_type::maxdigits_dec;
        if(C4_UNLIKELY(buf.len < needed_digits))
            return needed_digits;
        pos = _itoa2bufwithdigits(buf, pos, num_digits, digits_type::min_value_dec());
        break;
    case I(16):
        // add 3 to account for -0x
        needed_digits = num_digits+3 > digits_type::maxdigits_hex ? num_digits+3 : digits_type::maxdigits_hex;
        if(C4_UNLIKELY(buf.len < needed_digits))
            return needed_digits;
        buf.str[pos++] = '0';
        buf.str[pos++] = 'x';
        pos = _itoa2bufwithdigits(buf, pos, num_digits, digits_type::min_value_hex());
        break;
    case I(2):
        // add 3 to account for -0b
        needed_digits = num_digits+3 > digits_type::maxdigits_bin ? num_digits+3 : digits_type::maxdigits_bin;
        if(C4_UNLIKELY(buf.len < needed_digits))
            return needed_digits;
        C4_ASSERT(buf.len >= digits_type::maxdigits_bin);
        buf.str[pos++] = '0';
        buf.str[pos++] = 'b';
        pos = _itoa2bufwithdigits(buf, pos, num_digits, digits_type::min_value_bin());
        break;
    case I(8):
        // add 3 to account for -0o
        needed_digits = num_digits+3 > digits_type::maxdigits_oct ? num_digits+3 : digits_type::maxdigits_oct;
        if(C4_UNLIKELY(buf.len < needed_digits))
            return needed_digits;
        C4_ASSERT(buf.len >= digits_type::maxdigits_oct);
        buf.str[pos++] = '0';
        buf.str[pos++] = 'o';
        pos = _itoa2bufwithdigits(buf, pos, num_digits, digits_type::min_value_oct());
        break;
    }
    return pos;
}
} // namespace detail
/** @endcond */


/** @defgroup doc_itoa itoa: signed to chars
 *
 * @{ */

/** convert an integral signed decimal to a string.
 * @note the resulting string is NOT zero-terminated.
 * @note it is ok to call this with an empty or too-small buffer;
 * no writes will occur, and the needed size will be returned
 * @return the number of characters required for the buffer. */
template<class T>
C4_ALWAYS_INLINE size_t itoa(substr buf, T v) noexcept
{
    C4_STATIC_ASSERT(std::is_signed<T>::value);
    if(v >= T(0))
    {
        // write_dec() checks the buffer size, so no need to check here
        return write_dec(buf, v);
    }
    // when T is the min value (eg i8: -128), negating it
    // will overflow, so treat the min as a special case
    else if(C4_LIKELY(v != std::numeric_limits<T>::min()))
    {
        v = -v;
        unsigned digits = digits_dec(v);
        if(C4_LIKELY(buf.len >= digits + 1u))
        {
            buf.str[0] = '-';
            write_dec_unchecked(buf.sub(1), v, digits);
        }
        return digits + 1u;
    }
    return detail::_itoadec2buf<T>(buf);
}

/** convert an integral signed integer to a string, using a specific
 * radix. The radix must be 2, 8, 10 or 16.
 *
 * @note the resulting string is NOT zero-terminated.
 * @note it is ok to call this with an empty or too-small buffer;
 * no writes will occur, and the needed size will be returned
 * @return the number of characters required for the buffer. */
template<class T>
C4_ALWAYS_INLINE size_t itoa(substr buf, T v, T radix) noexcept
{
    C4_STATIC_ASSERT(std::is_signed<T>::value);
    C4_ASSERT(radix == 2 || radix == 8 || radix == 10 || radix == 16);
    C4_SUPPRESS_WARNING_GCC_PUSH
    #if (defined(__GNUC__) && (__GNUC__ >= 7))
        C4_SUPPRESS_WARNING_GCC("-Wstringop-overflow")  // gcc has a false positive here
    #endif
    // when T is the min value (eg i8: -128), negating it
    // will overflow, so treat the min as a special case
    if(C4_LIKELY(v != std::numeric_limits<T>::min()))
    {
        unsigned pos = 0;
        if(v < 0)
        {
            v = -v;
            if(C4_LIKELY(buf.len > 0))
                buf.str[pos] = '-';
            ++pos;
        }
        unsigned digits = 0;
        switch(radix)
        {
        case T(10):
            digits = digits_dec(v);
            if(C4_LIKELY(buf.len >= pos + digits))
                write_dec_unchecked(buf.sub(pos), v, digits);
            break;
        case T(16):
            digits = digits_hex(v);
            if(C4_LIKELY(buf.len >= pos + 2u + digits))
            {
                buf.str[pos + 0] = '0';
                buf.str[pos + 1] = 'x';
                write_hex_unchecked(buf.sub(pos + 2), v, digits);
            }
            digits += 2u;
            break;
        case T(2):
            digits = digits_bin(v);
            if(C4_LIKELY(buf.len >= pos + 2u + digits))
            {
                buf.str[pos + 0] = '0';
                buf.str[pos + 1] = 'b';
                write_bin_unchecked(buf.sub(pos + 2), v, digits);
            }
            digits += 2u;
            break;
        case T(8):
            digits = digits_oct(v);
            if(C4_LIKELY(buf.len >= pos + 2u + digits))
            {
                buf.str[pos + 0] = '0';
                buf.str[pos + 1] = 'o';
                write_oct_unchecked(buf.sub(pos + 2), v, digits);
            }
            digits += 2u;
            break;
        }
        return pos + digits;
    }
    C4_SUPPRESS_WARNING_GCC_POP
    // when T is the min value (eg i8: -128), negating it
    // will overflow
    return detail::_itoa2buf<T>(buf, radix);
}


/** same as c4::itoa(), but pad with zeroes on the left such that the
 * resulting string is @p num_digits wide, not accounting for radix
 * prefix (0x,0o,0b). The @p radix must be 2, 8, 10 or 16.
 *
 * @note the resulting string is NOT zero-terminated.
 * @note it is ok to call this with an empty or too-small buffer;
 * no writes will occur, and the needed size will be returned
 * @return the number of characters required for the buffer. */
template<class T>
C4_ALWAYS_INLINE size_t itoa(substr buf, T v, T radix, size_t num_digits) noexcept
{
    C4_STATIC_ASSERT(std::is_signed<T>::value);
    C4_ASSERT(radix == 2 || radix == 8 || radix == 10 || radix == 16);
    C4_SUPPRESS_WARNING_GCC_PUSH
    #if (defined(__GNUC__) && (__GNUC__ >= 7))
        C4_SUPPRESS_WARNING_GCC("-Wstringop-overflow")  // gcc has a false positive here
    #endif
    // when T is the min value (eg i8: -128), negating it
    // will overflow, so treat the min as a special case
    if(C4_LIKELY(v != std::numeric_limits<T>::min()))
    {
        unsigned pos = 0;
        if(v < 0)
        {
            v = -v;
            if(C4_LIKELY(buf.len > 0))
                buf.str[pos] = '-';
            ++pos;
        }
        unsigned total_digits = 0;
        switch(radix)
        {
        case T(10):
            total_digits = digits_dec(v);
            total_digits = pos + (unsigned)(num_digits > total_digits ? num_digits : total_digits);
            if(C4_LIKELY(buf.len >= total_digits))
                write_dec(buf.sub(pos), v, num_digits);
            break;
        case T(16):
            total_digits = digits_hex(v);
            total_digits = pos + 2u + (unsigned)(num_digits > total_digits ? num_digits : total_digits);
            if(C4_LIKELY(buf.len >= total_digits))
            {
                buf.str[pos + 0] = '0';
                buf.str[pos + 1] = 'x';
                write_hex(buf.sub(pos + 2), v, num_digits);
            }
            break;
        case T(2):
            total_digits = digits_bin(v);
            total_digits = pos + 2u + (unsigned)(num_digits > total_digits ? num_digits : total_digits);
            if(C4_LIKELY(buf.len >= total_digits))
            {
                buf.str[pos + 0] = '0';
                buf.str[pos + 1] = 'b';
                write_bin(buf.sub(pos + 2), v, num_digits);
            }
            break;
        case T(8):
            total_digits = digits_oct(v);
            total_digits = pos + 2u + (unsigned)(num_digits > total_digits ? num_digits : total_digits);
            if(C4_LIKELY(buf.len >= total_digits))
            {
                buf.str[pos + 0] = '0';
                buf.str[pos + 1] = 'o';
                write_oct(buf.sub(pos + 2), v, num_digits);
            }
            break;
        }
        return total_digits;
    }
    C4_SUPPRESS_WARNING_GCC_POP
    // when T is the min value (eg i8: -128), negating it
    // will overflow
    return detail::_itoa2buf<T>(buf, radix, num_digits);
}

/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @defgroup doc_utoa utoa: unsigned to chars
 *
 * @{ */

/** convert an integral unsigned decimal to a string.
 *
 * @note the resulting string is NOT zero-terminated.
 * @note it is ok to call this with an empty or too-small buffer;
 * no writes will occur, and the needed size will be returned
 * @return the number of characters required for the buffer. */
template<class T>
C4_ALWAYS_INLINE size_t utoa(substr buf, T v) noexcept
{
    C4_STATIC_ASSERT(std::is_unsigned<T>::value);
    // write_dec() does the buffer length check, so no need to check here
    return write_dec(buf, v);
}

/** convert an integral unsigned integer to a string, using a specific
 * radix. The radix must be 2, 8, 10 or 16.
 *
 * @note the resulting string is NOT zero-terminated.
 * @note it is ok to call this with an empty or too-small buffer;
 * no writes will occur, and the needed size will be returned
 * @return the number of characters required for the buffer. */
template<class T>
C4_ALWAYS_INLINE size_t utoa(substr buf, T v, T radix) noexcept
{
    C4_STATIC_ASSERT(std::is_unsigned<T>::value);
    C4_ASSERT(radix == 10 || radix == 16 || radix == 2 || radix == 8);
    unsigned digits = 0;
    switch(radix)
    {
    case T(10):
        digits = digits_dec(v);
        if(C4_LIKELY(buf.len >= digits))
            write_dec_unchecked(buf, v, digits);
        break;
    case T(16):
        digits = digits_hex(v);
        if(C4_LIKELY(buf.len >= digits+2u))
        {
            buf.str[0] = '0';
            buf.str[1] = 'x';
            write_hex_unchecked(buf.sub(2), v, digits);
        }
        digits += 2u;
        break;
    case T(2):
        digits = digits_bin(v);
        if(C4_LIKELY(buf.len >= digits+2u))
        {
            buf.str[0] = '0';
            buf.str[1] = 'b';
            write_bin_unchecked(buf.sub(2), v, digits);
        }
        digits += 2u;
        break;
    case T(8):
        digits = digits_oct(v);
        if(C4_LIKELY(buf.len >= digits+2u))
        {
            buf.str[0] = '0';
            buf.str[1] = 'o';
            write_oct_unchecked(buf.sub(2), v, digits);
        }
        digits += 2u;
        break;
    }
    return digits;
}

/** same as c4::utoa(), but pad with zeroes on the left such that the
 * resulting string is @p num_digits wide. The @p radix must be 2,
 * 8, 10 or 16.
 *
 * @note the resulting string is NOT zero-terminated.
 * @note it is ok to call this with an empty or too-small buffer;
 * no writes will occur, and the needed size will be returned
 * @return the number of characters required for the buffer. */
template<class T>
C4_ALWAYS_INLINE size_t utoa(substr buf, T v, T radix, size_t num_digits) noexcept
{
    C4_STATIC_ASSERT(std::is_unsigned<T>::value);
    C4_ASSERT(radix == 10 || radix == 16 || radix == 2 || radix == 8);
    unsigned total_digits = 0;
    switch(radix)
    {
    case T(10):
        total_digits = digits_dec(v);
        total_digits = (unsigned)(num_digits > total_digits ? num_digits : total_digits);
        if(C4_LIKELY(buf.len >= total_digits))
            write_dec(buf, v, num_digits);
        break;
    case T(16):
        total_digits = digits_hex(v);
        total_digits = 2u + (unsigned)(num_digits > total_digits ? num_digits : total_digits);
        if(C4_LIKELY(buf.len >= total_digits))
        {
            buf.str[0] = '0';
            buf.str[1] = 'x';
            write_hex(buf.sub(2), v, num_digits);
        }
        break;
    case T(2):
        total_digits = digits_bin(v);
        total_digits = 2u + (unsigned)(num_digits > total_digits ? num_digits : total_digits);
        if(C4_LIKELY(buf.len >= total_digits))
        {
            buf.str[0] = '0';
            buf.str[1] = 'b';
            write_bin(buf.sub(2), v, num_digits);
        }
        break;
    case T(8):
        total_digits = digits_oct(v);
        total_digits = 2u + (unsigned)(num_digits > total_digits ? num_digits : total_digits);
        if(C4_LIKELY(buf.len >= total_digits))
        {
            buf.str[0] = '0';
            buf.str[1] = 'o';
            write_oct(buf.sub(2), v, num_digits);
        }
        break;
    }
    return total_digits;
}
C4_SUPPRESS_WARNING_GCC_POP

/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @defgroup doc_atoi atoi: chars to signed
 *
 * @{ */

/** Convert a trimmed string to a signed integral value. The input
 * string can be formatted as decimal, binary (prefix 0b or 0B), octal
 * (prefix 0o or 0O) or hexadecimal (prefix 0x or 0X). Strings with
 * leading zeroes are considered as decimal and not octal (unlike the
 * C/C++ convention). Every character in the input string is read for
 * the conversion; the input string must not contain any leading or
 * trailing whitespace.
 *
 * @return true if the conversion was successful.
 *
 * @note a positive sign is not accepted. ie, the string must not
 * start with '+'
 *
 * @note overflow is not detected: the return status is true even if
 * the conversion would return a value outside of the type's range, in
 * which case the result will wrap around the type's range.  This is
 * similar to native behavior. See @ref doc_overflows and @ref
 * doc_overflow_checked for overflow checking utilities.
 *
 * @see atoi_first() if the string is not trimmed to the value to read. */
template<class T>
C4_NO_UBSAN_IOVRFLW
C4_ALWAYS_INLINE bool atoi(csubstr str, T * C4_RESTRICT v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    C4_STATIC_ASSERT(std::is_signed<T>::value);

    if(C4_UNLIKELY(str.len == 0))
        return false;

    C4_ASSERT(str.str[0] != '+');

    T sign = 1;
    size_t start = 0;
    if(str.str[0] == '-')
    {
        if(C4_UNLIKELY(str.len == ++start))
            return false;
        sign = -1;
    }

    bool parsed_ok = true;
    if(str.str[start] != '0') // this should be the common case, so put it first
    {
        parsed_ok = read_dec(str.sub(start), v);
    }
    else if(str.len > start + 1)
    {
        // starts with 0: is it 0x, 0o, 0b?
        const char pfx = str.str[start + 1];
        if(pfx == 'x' || pfx == 'X')
            parsed_ok = str.len > start + 2 && read_hex(str.sub(start + 2), v);
        else if(pfx == 'b' || pfx == 'B')
            parsed_ok = str.len > start + 2 && read_bin(str.sub(start + 2), v);
        else if(pfx == 'o' || pfx == 'O')
            parsed_ok = str.len > start + 2 && read_oct(str.sub(start + 2), v);
        else
            parsed_ok = read_dec(str.sub(start + 1), v);
    }
    else
    {
        parsed_ok = read_dec(str.sub(start), v);
    }
    if(C4_LIKELY(parsed_ok))
        *v *= sign;
    return parsed_ok;
}


/** Select the next range of characters in the string that can be parsed
 * as a signed integral value, and convert it using atoi(). Leading
 * whitespace (space, newline, tabs) is skipped.
 * @return the number of characters read for conversion, or csubstr::npos if the conversion failed
 * @see atoi() if the string is already trimmed to the value to read.
 * @see csubstr::first_int_span() */
template<class T>
C4_ALWAYS_INLINE size_t atoi_first(csubstr str, T * C4_RESTRICT v)
{
    csubstr trimmed = str.first_int_span();
    if(trimmed.len == 0)
        return csubstr::npos;
    if(atoi(trimmed, v))
        return static_cast<size_t>(trimmed.end() - str.begin());
    return csubstr::npos;
}

/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @defgroup doc_atou atou: chars to unsigned
 *
 * @{ */

/** Convert a trimmed string to an unsigned integral value. The string can be
 * formatted as decimal, binary (prefix 0b or 0B), octal (prefix 0o or 0O)
 * or hexadecimal (prefix 0x or 0X). Every character in the input string is read
 * for the conversion; it must not contain any leading or trailing whitespace.
 *
 * @return true if the conversion was successful.
 *
 * @note overflow is not detected: the return status is true even if
 * the conversion would return a value outside of the type's range, in
 * which case the result will wrap around the type's range. See @ref
 * doc_overflows and @ref doc_overflow_checked for overflow checking
 * utilities.
 *
 * @note If the string has a minus character, the return status
 * will be false.
 *
 * @see atou_first() if the string is not trimmed to the value to read. */
template<class T>
bool atou(csubstr str, T * C4_RESTRICT v) noexcept
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);

    if(C4_UNLIKELY(str.len == 0 || str.front() == '-'))
        return false;

    bool parsed_ok = true;
    if(str.str[0] != '0')
    {
        parsed_ok = read_dec(str, v);
    }
    else
    {
        if(str.len > 1)
        {
            const char pfx = str.str[1];
            if(pfx == 'x' || pfx == 'X')
                parsed_ok = str.len > 2 && read_hex(str.sub(2), v);
            else if(pfx == 'b' || pfx == 'B')
                parsed_ok = str.len > 2 && read_bin(str.sub(2), v);
            else if(pfx == 'o' || pfx == 'O')
                parsed_ok = str.len > 2 && read_oct(str.sub(2), v);
            else
                parsed_ok = read_dec(str, v);
        }
        else
        {
            *v = 0; // we know the first character is 0
        }
    }
    return parsed_ok;
}


/** Select the next range of characters in the string that can be parsed
 * as an unsigned integral value, and convert it using atou(). Leading
 * whitespace (space, newline, tabs) is skipped.
 * @return the number of characters read for conversion, or csubstr::npos if the conversion faileds
 * @see atou() if the string is already trimmed to the value to read.
 * @see csubstr::first_uint_span() */
template<class T>
C4_ALWAYS_INLINE size_t atou_first(csubstr str, T *v)
{
    csubstr trimmed = str.first_uint_span();
    if(trimmed.len == 0)
        return csubstr::npos;
    if(atou(trimmed, v))
        return static_cast<size_t>(trimmed.end() - str.begin());
    return csubstr::npos;
}


/** @} */

#ifdef _MSC_VER
#   pragma warning(pop)
#elif defined(__clang__)
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @cond dev */
namespace detail {
inline bool check_overflow(csubstr str, csubstr limit) noexcept
{
    if(str.len == limit.len)
    {
        for(size_t i = 0; i < limit.len; ++i)
        {
            if(str[i] < limit[i])
                return false;
            else if(str[i] > limit[i])
                return true;
        }
        return false;
    }
    else
        return str.len > limit.len;
}
} // namespace detail
/** @endcond */


/** @defgroup doc_overflows overflows: does a number string overflow a type
 *
 * @{ */

/** Test if the following string would overflow when converted to
 * associated integral types; this function is dispatched with SFINAE
 * to handle differently signed and unsigned types.
 * @return true if number will overflow, false if it fits (or doesn't parse)
 * @see doc_overflow_checked for format specifiers to enforce no-overflow reads
 */
template<class T>
auto overflows(csubstr str) noexcept
    -> typename std::enable_if<std::is_unsigned<T>::value, bool>::type
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);

    if(C4_UNLIKELY(str.len == 0))
    {
        return false;
    }
    else if(str.str[0] == '0')
    {
        if (str.len == 1)
            return false;
        switch (str.str[1])
        {
            case 'x':
            case 'X':
            {
                size_t fno = str.first_not_of('0', 2);
                if (fno == csubstr::npos)
                    return false;
                return !(str.len <= fno + (sizeof(T) * 2));
            }
            case 'b':
            case 'B':
            {
                size_t fno = str.first_not_of('0', 2);
                if (fno == csubstr::npos)
                    return false;
                return !(str.len <= fno +(sizeof(T) * 8));
            }
            case 'o':
            case 'O':
            {
                size_t fno = str.first_not_of('0', 2);
                if(fno == csubstr::npos)
                    return false;
                return detail::charconv_digits<T>::is_oct_overflow(str.sub(fno));
            }
            default:
            {
                size_t fno = str.first_not_of('0', 1);
                if(fno == csubstr::npos)
                    return false;
                return detail::check_overflow(str.sub(fno), detail::charconv_digits<T>::max_value_dec());
            }
        }
    }
    else if(C4_UNLIKELY(str[0] == '-'))
    {
        return true;
    }
    else
    {
        return detail::check_overflow(str, detail::charconv_digits<T>::max_value_dec());
    }
}


/** Test if the following string would overflow when converted to
 * associated integral types; this function is dispatched with SFINAE
 * to handle differently signed and unsigned types.
 *
 * @return true if number will overflow, false if it fits (or doesn't parse)
 * @see doc_overflow_checked for format specifiers to enforce no-overflow reads
 */
template<class T>
auto overflows(csubstr str)
    -> typename std::enable_if<std::is_signed<T>::value, bool>::type
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    if(C4_UNLIKELY(str.len == 0))
        return false;
    if(str.str[0] == '-')
    {
        if(str.str[1] == '0')
        {
            if(str.len == 2)
                return false;
            switch(str.str[2])
            {
                case 'x':
                case 'X':
                {
                    size_t fno = str.first_not_of('0', 3);
                    if (fno == csubstr::npos)
                        return false;
                    return detail::check_overflow(str.sub(fno), detail::charconv_digits<T>::min_value_hex());
                }
                case 'b':
                case 'B':
                {
                    size_t fno = str.first_not_of('0', 3);
                    if (fno == csubstr::npos)
                        return false;
                    return detail::check_overflow(str.sub(fno), detail::charconv_digits<T>::min_value_bin());
                }
                case 'o':
                case 'O':
                {
                    size_t fno = str.first_not_of('0', 3);
                    if(fno == csubstr::npos)
                        return false;
                    return detail::check_overflow(str.sub(fno), detail::charconv_digits<T>::min_value_oct());
                }
                default:
                {
                    size_t fno = str.first_not_of('0', 2);
                    if(fno == csubstr::npos)
                        return false;
                    return detail::check_overflow(str.sub(fno), detail::charconv_digits<T>::min_value_dec());
                }
            }
        }
        else
            return detail::check_overflow(str.sub(1), detail::charconv_digits<T>::min_value_dec());
    }
    else if(str.str[0] == '0')
    {
        if (str.len == 1)
            return false;
        switch(str.str[1])
        {
            case 'x':
            case 'X':
            {
                size_t fno = str.first_not_of('0', 2);
                if (fno == csubstr::npos)
                    return false;
                const size_t len = str.len - fno;
                return !((len < sizeof (T) * 2) || (len == sizeof(T) * 2 && str[fno] <= '7'));
            }
            case 'b':
            case 'B':
            {
                size_t fno = str.first_not_of('0', 2);
                if (fno == csubstr::npos)
                    return false;
                return !(str.len <= fno + (sizeof(T) * 8 - 1));
            }
            case 'o':
            case 'O':
            {
                size_t fno = str.first_not_of('0', 2);
                if(fno == csubstr::npos)
                    return false;
                return detail::charconv_digits<T>::is_oct_overflow(str.sub(fno));
            }
            default:
            {
                size_t fno = str.first_not_of('0', 1);
                if(fno == csubstr::npos)
                    return false;
                return detail::check_overflow(str.sub(fno), detail::charconv_digits<T>::max_value_dec());
            }
        }
    }
    else
        return detail::check_overflow(str, detail::charconv_digits<T>::max_value_dec());
}

/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @cond dev */
namespace detail {


#if (!C4CORE_HAVE_STD_FROMCHARS)
/** @see http://www.exploringbinary.com/ for many good examples on float-str conversion */
template<size_t N>
void get_real_format_str(char (& C4_RESTRICT fmt)[N], int precision, RealFormat_e formatting, const char* length_modifier="")
{
    int iret;
    if(precision == -1)
        iret = snprintf(fmt, sizeof(fmt), "%%%s%c", length_modifier, formatting);
    else if(precision == 0)
        iret = snprintf(fmt, sizeof(fmt), "%%.%s%c", length_modifier, formatting);
    else
        iret = snprintf(fmt, sizeof(fmt), "%%.%d%s%c", precision, length_modifier, formatting);
    C4_ASSERT(iret >= 2 && size_t(iret) < sizeof(fmt));
    C4_UNUSED(iret);
}


/** @todo we're depending on snprintf()/sscanf() for converting to/from
 * floating point numbers. Apparently, this increases the binary size
 * by a considerable amount. There are some lightweight printf
 * implementations:
 *
 * @see http://www.sparetimelabs.com/tinyprintf/tinyprintf.php (BSD)
 * @see https://github.com/weiss/c99-snprintf
 * @see https://github.com/nothings/stb/blob/master/stb_sprintf.h
 * @see http://www.exploringbinary.com/
 * @see https://blog.benoitblanchon.fr/lightweight-float-to-string/
 * @see http://www.ryanjuckett.com/programming/printing-floating-point-numbers/
 */
template<class T>
size_t print_one(substr str, const char* full_fmt, T v)
{
#ifdef _MSC_VER
    /** use _snprintf() to prevent early termination of the output
     * for writing the null character at the last position
     * @see https://msdn.microsoft.com/en-us/library/2ts7cx93.aspx */
    int iret = _snprintf(str.str, str.len, full_fmt, v);
    if(iret < 0)
    {
        /* when buf.len is not enough, VS returns a negative value.
         * so call it again with a negative value for getting an
         * actual length of the string */
        iret = snprintf(nullptr, 0, full_fmt, v);
        C4_ASSERT(iret > 0);
    }
    size_t ret = (size_t) iret;
    return ret;
#else
    int iret = snprintf(str.str, str.len, full_fmt, v);
    C4_ASSERT(iret >= 0);
    size_t ret = (size_t) iret;
    if(ret >= str.len)
        ++ret; /* snprintf() reserves the last character to write \0 */
    return ret;
#endif
}
#endif // (!C4CORE_HAVE_STD_FROMCHARS)


#if (!C4CORE_HAVE_STD_FROMCHARS) && (!C4CORE_HAVE_FAST_FLOAT)
/** scans a string using the given type format, while at the same time
 * allowing non-null-terminated strings AND guaranteeing that the given
 * string length is strictly respected, so that no buffer overflows
 * might occur. */
template<typename T>
inline size_t scan_one(csubstr str, const char *type_fmt, T *v)
{
    /* snscanf() is absolutely needed here as we must be sure that
     * str.len is strictly respected, because substr is
     * generally not null-terminated.
     *
     * Alas, there is no snscanf().
     *
     * So we fake it by using a dynamic format with an explicit
     * field size set to the length of the given span.
     * This trick is taken from:
     * https://stackoverflow.com/a/18368910/5875572 */

    /* this is the actual format we'll use for scanning */
    char fmt[16];

    /* write the length into it. Eg "%12f".
     * Also, get the number of characters read from the string.
     * So the final format ends up as "%12f%n"*/
    int iret = std::snprintf(fmt, sizeof(fmt), "%%" "%zu" "%s" "%%n", str.len, type_fmt);
    /* no nasty surprises, please! */
    C4_ASSERT(iret >= 0 && size_t(iret) < C4_COUNTOF(fmt));

    /* now we scan with confidence that the span length is respected */
    int num_chars;
    iret = std::sscanf(str.str, fmt, v, &num_chars);
    /* scanf returns the number of successful conversions */
    if(iret != 1) return csubstr::npos;
    C4_ASSERT(num_chars >= 0);
    return (size_t)(num_chars);
}
#endif // (!C4CORE_HAVE_STD_FROMCHARS) && (!C4CORE_HAVE_FAST_FLOAT)


#if C4CORE_HAVE_STD_TOCHARS
template<class T>
C4_ALWAYS_INLINE size_t rtoa(substr buf, T v, int precision=-1, RealFormat_e formatting=FTOA_FLEX) noexcept
{
    std::to_chars_result result;
    size_t pos = 0;
    if(formatting == FTOA_HEXA)
    {
        if(buf.len > size_t(2))
        {
            buf.str[0] = '0';
            buf.str[1] = 'x';
        }
        pos += size_t(2);
    }
    if(precision == -1)
        result = std::to_chars(buf.str + pos, buf.str + buf.len, v, (std::chars_format)formatting);
    else
        result = std::to_chars(buf.str + pos, buf.str + buf.len, v, (std::chars_format)formatting, precision);
    if(result.ec == std::errc())
    {
        // all good, no errors.
        C4_ASSERT(result.ptr >= buf.str);
        ptrdiff_t delta = result.ptr - buf.str;
        return static_cast<size_t>(delta);
    }
    C4_ASSERT(result.ec == std::errc::value_too_large);
    // This is unfortunate.
    //
    // When the result can't fit in the given buffer,
    // std::to_chars() returns the end pointer it was originally
    // given, which is useless because here we would like to know
    // _exactly_ how many characters the buffer must have to fit
    // the result.
    //
    // So we take the pessimistic view, and assume as many digits
    // as could ever be required:
    size_t ret = static_cast<size_t>(std::numeric_limits<T>::max_digits10);
    return ret > buf.len ? ret : buf.len + 1;
}
#endif // C4CORE_HAVE_STD_TOCHARS


#if C4CORE_HAVE_FAST_FLOAT
template<class T>
C4_ALWAYS_INLINE bool scan_rhex(csubstr s, T *C4_RESTRICT val) noexcept
{
    C4_ASSERT(s.len > 0);
    C4_ASSERT(s.str[0] != '-');
    C4_ASSERT(s.str[0] != '+');
    C4_ASSERT(!s.begins_with("0x"));
    C4_ASSERT(!s.begins_with("0X"));
    size_t pos = 0;
    // integer part
    for( ; pos < s.len; ++pos)
    {
        const char c = s.str[pos];
        if(c >= '0' && c <= '9')
            *val = *val * T(16) + T(c - '0');
        else if(c >= 'a' && c <= 'f')
            *val = *val * T(16) + T(c - 'a');
        else if(c >= 'A' && c <= 'F')
            *val = *val * T(16) + T(c - 'A');
        else if(c == '.')
        {
            ++pos;
            break; // follow on to mantissa
        }
        else if(c == 'p' || c == 'P')
        {
            ++pos;
            goto power; // no mantissa given, jump to power
        }
        else
        {
            return false;
        }
    }
    // mantissa
    {
        // 0.0625 == 1/16 == value of first digit after the comma
        for(T digit = T(0.0625); pos < s.len; ++pos, digit /= T(16))
        {
            const char c = s.str[pos];
            if(c >= '0' && c <= '9')
                *val += digit * T(c - '0');
            else if(c >= 'a' && c <= 'f')
                *val += digit * T(c - 'a');
            else if(c >= 'A' && c <= 'F')
                *val += digit * T(c - 'A');
            else if(c == 'p' || c == 'P')
            {
                ++pos;
                goto power; // mantissa finished, jump to power
            }
            else
            {
                return false;
            }
        }
    }
    return true;
power:
    if(C4_LIKELY(pos < s.len))
    {
        if(s.str[pos] == '+') // atoi() cannot handle a leading '+'
            ++pos;
        if(C4_LIKELY(pos < s.len))
        {
            int16_t powval = {};
            if(C4_LIKELY(atoi(s.sub(pos), &powval)))
            {
                *val *= ipow<T, int16_t, 16>(powval);
                return true;
            }
        }
    }
    return false;
}
#endif

} // namespace detail
/** @endcond */


#undef _c4appendhex
#undef _c4append


/** @defgroup doc_ftoa ftoa: float32 to chars
 *
 * @{ */

/** Convert a single-precision real number to string.  The string will
 * in general be NOT null-terminated.  For FTOA_FLEX, \p precision is
 * the number of significand digits. Otherwise \p precision is the
 * number of decimals. It is safe to call this function with an empty
 * or too-small buffer.
 *
 * @return the size of the buffer needed to write the number
 */
C4_ALWAYS_INLINE size_t ftoa(substr str, float v, int precision=-1, RealFormat_e formatting=FTOA_FLEX) noexcept
{
#if C4CORE_HAVE_STD_TOCHARS
    return detail::rtoa(str, v, precision, formatting);
#else
    char fmt[16];
    detail::get_real_format_str(fmt, precision, formatting, /*length_modifier*/"");
    return detail::print_one(str, fmt, v);
#endif
}

/** @} */


/** @defgroup doc_dtoa dtoa: float64 to chars
 *
 * @{ */

/** Convert a double-precision real number to string.  The string will
 * in general be NOT null-terminated.  For FTOA_FLEX, \p precision is
 * the number of significand digits. Otherwise \p precision is the
 * number of decimals. It is safe to call this function with an empty
 * or too-small buffer.
 *
 * @return the size of the buffer needed to write the number
 */
C4_ALWAYS_INLINE size_t dtoa(substr str, double v, int precision=-1, RealFormat_e formatting=FTOA_FLEX) noexcept
{
#if C4CORE_HAVE_STD_TOCHARS
    return detail::rtoa(str, v, precision, formatting);
#else
    char fmt[16];
    detail::get_real_format_str(fmt, precision, formatting, /*length_modifier*/"l");
    return detail::print_one(str, fmt, v);
#endif
}

/** @} */


/** @defgroup doc_atof atof: chars to float32
 *
 * @{ */

/** Convert a string to a single precision real number.
 * The input string must be trimmed to the value, ie
 * no leading or trailing whitespace can be present.
 * @return true iff the conversion succeeded
 * @see atof_first() if the string is not trimmed
 */
C4_ALWAYS_INLINE bool atof(csubstr str, float * C4_RESTRICT v) noexcept
{
    C4_ASSERT(str.len > 0);
    C4_ASSERT(str.triml(" \r\t\n").len == str.len);
#if C4CORE_HAVE_FAST_FLOAT
    // fastfloat cannot parse hexadecimal floats
    bool isneg = (str.str[0] == '-');
    csubstr rem = str.sub(isneg || str.str[0] == '+');
    if(!(rem.len >= 2 && (rem.str[0] == '0' && (rem.str[1] == 'x' || rem.str[1] == 'X'))))
    {
        fast_float::from_chars_result result;
        result = fast_float::from_chars(str.str, str.str + str.len, *v);
        return result.ec == std::errc();
    }
    else if(detail::scan_rhex(rem.sub(2), v))
    {
        *v *= isneg ? -1.f : 1.f;
        return true;
    }
    return false;
#elif C4CORE_HAVE_STD_FROMCHARS
    std::from_chars_result result;
    result = std::from_chars(str.str, str.str + str.len, *v);
    return result.ec == std::errc();
#else
    csubstr rem = str.sub(str.str[0] == '-' || str.str[0] == '+');
    if(!(rem.len >= 2 && (rem.str[0] == '0' && (rem.str[1] == 'x' || rem.str[1] == 'X'))))
        return detail::scan_one(str, "f", v) != csubstr::npos;
    else
        return detail::scan_one(str, "a", v) != csubstr::npos;
#endif
}


/** Convert a string to a single precision real number.
 * Leading whitespace is skipped until valid characters are found.
 * @return the number of characters read from the string, or npos if
 * conversion was not successful or if the string was empty */
inline size_t atof_first(csubstr str, float * C4_RESTRICT v) noexcept
{
    csubstr trimmed = str.first_real_span();
    if(trimmed.len == 0)
        return csubstr::npos;
    if(atof(trimmed, v))
        return static_cast<size_t>(trimmed.end() - str.begin());
    return csubstr::npos;
}

/** @} */


/** @defgroup doc_atod atod: chars to float64
 *
 * @{ */

/** Convert a string to a double precision real number.
 * The input string must be trimmed to the value, ie
 * no leading or trailing whitespace can be present.
 * @return true iff the conversion succeeded
 * @see atod_first() if the string is not trimmed
 */
C4_ALWAYS_INLINE bool atod(csubstr str, double * C4_RESTRICT v) noexcept
{
    C4_ASSERT(str.len > 0);
    C4_ASSERT(str.triml(" \r\t\n").len == str.len);
#if C4CORE_HAVE_FAST_FLOAT
    // fastfloat cannot parse hexadecimal floats
    bool isneg = (str.str[0] == '-');
    csubstr rem = str.sub(isneg || str.str[0] == '+');
    if(!(rem.len >= 2 && (rem.str[0] == '0' && (rem.str[1] == 'x' || rem.str[1] == 'X'))))
    {
        fast_float::from_chars_result result;
        result = fast_float::from_chars(str.str, str.str + str.len, *v);
        return result.ec == std::errc();
    }
    else if(detail::scan_rhex(rem.sub(2), v))
    {
        *v *= isneg ? -1. : 1.;
        return true;
    }
    return false;
#elif C4CORE_HAVE_STD_FROMCHARS
    std::from_chars_result result;
    result = std::from_chars(str.str, str.str + str.len, *v);
    return result.ec == std::errc();
#else
    csubstr rem = str.sub(str.str[0] == '-' || str.str[0] == '+');
    if(!(rem.len >= 2 && (rem.str[0] == '0' && (rem.str[1] == 'x' || rem.str[1] == 'X'))))
        return detail::scan_one(str, "lf", v) != csubstr::npos;
    else
        return detail::scan_one(str, "la", v) != csubstr::npos;
#endif
}


/** Convert a string to a double precision real number.
 * Leading whitespace is skipped until valid characters are found.
 * @return the number of characters read from the string, or npos if
 * conversion was not successful or if the string was empty */
inline size_t atod_first(csubstr str, double * C4_RESTRICT v) noexcept
{
    csubstr trimmed = str.first_real_span();
    if(trimmed.len == 0)
        return csubstr::npos;
    if(atod(trimmed, v))
        return static_cast<size_t>(trimmed.end() - str.begin());
    return csubstr::npos;
}

/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// generic versions

/** @cond dev */
// on some platforms, (unsigned) int and (unsigned) long
// are not any of the fixed length types above
#define _C4_IF_NOT_FIXED_LENGTH_I(T, ty) C4_ALWAYS_INLINE typename std::enable_if<std::  is_signed<T>::value && !is_fixed_length<T>::value_i, ty>
#define _C4_IF_NOT_FIXED_LENGTH_U(T, ty) C4_ALWAYS_INLINE typename std::enable_if<std::is_unsigned<T>::value && !is_fixed_length<T>::value_u, ty>
/** @endcond*/


/** @defgroup doc_xtoa xtoa: generic value to chars
 *
 * Dispatches to the most appropriate and efficient conversion
 * function
 *
 * @{ */
C4_ALWAYS_INLINE size_t xtoa(substr s,  uint8_t v) noexcept { return write_dec(s, v); }
C4_ALWAYS_INLINE size_t xtoa(substr s, uint16_t v) noexcept { return write_dec(s, v); }
C4_ALWAYS_INLINE size_t xtoa(substr s, uint32_t v) noexcept { return write_dec(s, v); }
C4_ALWAYS_INLINE size_t xtoa(substr s, uint64_t v) noexcept { return write_dec(s, v); }
C4_ALWAYS_INLINE size_t xtoa(substr s,   int8_t v) noexcept { return itoa(s, v); }
C4_ALWAYS_INLINE size_t xtoa(substr s,  int16_t v) noexcept { return itoa(s, v); }
C4_ALWAYS_INLINE size_t xtoa(substr s,  int32_t v) noexcept { return itoa(s, v); }
C4_ALWAYS_INLINE size_t xtoa(substr s,  int64_t v) noexcept { return itoa(s, v); }
C4_ALWAYS_INLINE size_t xtoa(substr s,    float v) noexcept { return ftoa(s, v); }
C4_ALWAYS_INLINE size_t xtoa(substr s,   double v) noexcept { return dtoa(s, v); }

C4_ALWAYS_INLINE size_t xtoa(substr s,  uint8_t v,  uint8_t radix) noexcept { return utoa(s, v, radix); }
C4_ALWAYS_INLINE size_t xtoa(substr s, uint16_t v, uint16_t radix) noexcept { return utoa(s, v, radix); }
C4_ALWAYS_INLINE size_t xtoa(substr s, uint32_t v, uint32_t radix) noexcept { return utoa(s, v, radix); }
C4_ALWAYS_INLINE size_t xtoa(substr s, uint64_t v, uint64_t radix) noexcept { return utoa(s, v, radix); }
C4_ALWAYS_INLINE size_t xtoa(substr s,   int8_t v,   int8_t radix) noexcept { return itoa(s, v, radix); }
C4_ALWAYS_INLINE size_t xtoa(substr s,  int16_t v,  int16_t radix) noexcept { return itoa(s, v, radix); }
C4_ALWAYS_INLINE size_t xtoa(substr s,  int32_t v,  int32_t radix) noexcept { return itoa(s, v, radix); }
C4_ALWAYS_INLINE size_t xtoa(substr s,  int64_t v,  int64_t radix) noexcept { return itoa(s, v, radix); }

C4_ALWAYS_INLINE size_t xtoa(substr s,  uint8_t v,  uint8_t radix, size_t num_digits) noexcept { return utoa(s, v, radix, num_digits); }
C4_ALWAYS_INLINE size_t xtoa(substr s, uint16_t v, uint16_t radix, size_t num_digits) noexcept { return utoa(s, v, radix, num_digits); }
C4_ALWAYS_INLINE size_t xtoa(substr s, uint32_t v, uint32_t radix, size_t num_digits) noexcept { return utoa(s, v, radix, num_digits); }
C4_ALWAYS_INLINE size_t xtoa(substr s, uint64_t v, uint64_t radix, size_t num_digits) noexcept { return utoa(s, v, radix, num_digits); }
C4_ALWAYS_INLINE size_t xtoa(substr s,   int8_t v,   int8_t radix, size_t num_digits) noexcept { return itoa(s, v, radix, num_digits); }
C4_ALWAYS_INLINE size_t xtoa(substr s,  int16_t v,  int16_t radix, size_t num_digits) noexcept { return itoa(s, v, radix, num_digits); }
C4_ALWAYS_INLINE size_t xtoa(substr s,  int32_t v,  int32_t radix, size_t num_digits) noexcept { return itoa(s, v, radix, num_digits); }
C4_ALWAYS_INLINE size_t xtoa(substr s,  int64_t v,  int64_t radix, size_t num_digits) noexcept { return itoa(s, v, radix, num_digits); }

C4_ALWAYS_INLINE size_t xtoa(substr s,  float v, int precision, RealFormat_e formatting=FTOA_FLEX) noexcept { return ftoa(s, v, precision, formatting); }
C4_ALWAYS_INLINE size_t xtoa(substr s, double v, int precision, RealFormat_e formatting=FTOA_FLEX) noexcept { return dtoa(s, v, precision, formatting); }

template <class T> _C4_IF_NOT_FIXED_LENGTH_I(T, size_t)::type xtoa(substr buf, T v) noexcept { return itoa(buf, v); }
template <class T> _C4_IF_NOT_FIXED_LENGTH_U(T, size_t)::type xtoa(substr buf, T v) noexcept { return write_dec(buf, v); }
template <class T>
C4_ALWAYS_INLINE size_t xtoa(substr s, T *v) noexcept { return itoa(s, (intptr_t)v, (intptr_t)16); }

/** @} */

/** @defgroup doc_atox atox: generic chars to value
 *
 * Dispatches to the most appropriate and efficient conversion
 * function
 *
 * @{ */

C4_ALWAYS_INLINE bool atox(csubstr s,  uint8_t *C4_RESTRICT v) noexcept { return atou(s, v); }
C4_ALWAYS_INLINE bool atox(csubstr s, uint16_t *C4_RESTRICT v) noexcept { return atou(s, v); }
C4_ALWAYS_INLINE bool atox(csubstr s, uint32_t *C4_RESTRICT v) noexcept { return atou(s, v); }
C4_ALWAYS_INLINE bool atox(csubstr s, uint64_t *C4_RESTRICT v) noexcept { return atou(s, v); }
C4_ALWAYS_INLINE bool atox(csubstr s,   int8_t *C4_RESTRICT v) noexcept { return atoi(s, v); }
C4_ALWAYS_INLINE bool atox(csubstr s,  int16_t *C4_RESTRICT v) noexcept { return atoi(s, v); }
C4_ALWAYS_INLINE bool atox(csubstr s,  int32_t *C4_RESTRICT v) noexcept { return atoi(s, v); }
C4_ALWAYS_INLINE bool atox(csubstr s,  int64_t *C4_RESTRICT v) noexcept { return atoi(s, v); }
C4_ALWAYS_INLINE bool atox(csubstr s,    float *C4_RESTRICT v) noexcept { return atof(s, v); }
C4_ALWAYS_INLINE bool atox(csubstr s,   double *C4_RESTRICT v) noexcept { return atod(s, v); }

template <class T> _C4_IF_NOT_FIXED_LENGTH_I(T, bool  )::type atox(csubstr buf, T *C4_RESTRICT v) noexcept { return atoi(buf, v); }
template <class T> _C4_IF_NOT_FIXED_LENGTH_U(T, bool  )::type atox(csubstr buf, T *C4_RESTRICT v) noexcept { return atou(buf, v); }
template <class T>
C4_ALWAYS_INLINE bool atox(csubstr s, T **v) noexcept { intptr_t tmp; bool ret = atox(s, &tmp); if(ret) { *v = (T*)tmp; } return ret; }

/** @} */


/** @defgroup doc_to_chars to_chars: generalized chars to value
 *
 * Convert the given value, writing into the string.  The resulting
 * string will NOT be null-terminated.  Return the number of
 * characters needed.  This function is safe to call when the string
 * is too small - no writes will occur beyond the string's last
 * character.
 *
 * Dispatches to the most appropriate and efficient conversion
 * function.
 *
 * @see write_dec, doc_utoa, doc_itoa, doc_ftoa, doc_dtoa
 *
 * @warning When serializing floating point values (float or double),
 * be aware that because it uses defaults, to_chars() may cause a
 * truncation of the precision. To enforce a particular precision, use
 * for example @ref c4::fmt::real, or call directly @ref c4::ftoa or
 * @ref c4::dtoa.
 *
 * @{ */

C4_ALWAYS_INLINE size_t to_chars(substr buf,  uint8_t v) noexcept { return write_dec(buf, v); }
C4_ALWAYS_INLINE size_t to_chars(substr buf, uint16_t v) noexcept { return write_dec(buf, v); }
C4_ALWAYS_INLINE size_t to_chars(substr buf, uint32_t v) noexcept { return write_dec(buf, v); }
C4_ALWAYS_INLINE size_t to_chars(substr buf, uint64_t v) noexcept { return write_dec(buf, v); }
C4_ALWAYS_INLINE size_t to_chars(substr buf,   int8_t v) noexcept { return itoa(buf, v); }
C4_ALWAYS_INLINE size_t to_chars(substr buf,  int16_t v) noexcept { return itoa(buf, v); }
C4_ALWAYS_INLINE size_t to_chars(substr buf,  int32_t v) noexcept { return itoa(buf, v); }
C4_ALWAYS_INLINE size_t to_chars(substr buf,  int64_t v) noexcept { return itoa(buf, v); }
C4_ALWAYS_INLINE size_t to_chars(substr buf,    float v) noexcept { return ftoa(buf, v); }
C4_ALWAYS_INLINE size_t to_chars(substr buf,   double v) noexcept { return dtoa(buf, v); }

template <class T> _C4_IF_NOT_FIXED_LENGTH_I(T, size_t)::type to_chars(substr buf, T v) noexcept { return itoa(buf, v); }
template <class T> _C4_IF_NOT_FIXED_LENGTH_U(T, size_t)::type to_chars(substr buf, T v) noexcept { return write_dec(buf, v); }
template <class T>
C4_ALWAYS_INLINE size_t to_chars(substr s, T *v) noexcept { return itoa(s, (intptr_t)v, (intptr_t)16); }

/** @} */


/** @defgroup doc_from_chars from_chars: generalized chars to value
 *
 * Read a value from the string, which must be trimmed to the value
 * (ie, no leading/trailing whitespace).  return true if the
 * conversion succeeded.  There is no check for overflow; the value
 * wraps around in a way similar to the standard C/C++ overflow
 * behavior. For example, from_chars<int8_t>("128", &val) returns true
 * and val will be set tot 0. See @ref doc_overflows and @ref
 * doc_overflow_checked for facilities enforcing no-overflow.
 *
 * Dispatches to the most appropriate and efficient conversion
 * function
 *
 * @see doc_from_chars_first, atou, atoi, atof, atod
 * @{ */

C4_ALWAYS_INLINE bool from_chars(csubstr buf,  uint8_t *C4_RESTRICT v) noexcept { return atou(buf, v); }
C4_ALWAYS_INLINE bool from_chars(csubstr buf, uint16_t *C4_RESTRICT v) noexcept { return atou(buf, v); }
C4_ALWAYS_INLINE bool from_chars(csubstr buf, uint32_t *C4_RESTRICT v) noexcept { return atou(buf, v); }
C4_ALWAYS_INLINE bool from_chars(csubstr buf, uint64_t *C4_RESTRICT v) noexcept { return atou(buf, v); }
C4_ALWAYS_INLINE bool from_chars(csubstr buf,   int8_t *C4_RESTRICT v) noexcept { return atoi(buf, v); }
C4_ALWAYS_INLINE bool from_chars(csubstr buf,  int16_t *C4_RESTRICT v) noexcept { return atoi(buf, v); }
C4_ALWAYS_INLINE bool from_chars(csubstr buf,  int32_t *C4_RESTRICT v) noexcept { return atoi(buf, v); }
C4_ALWAYS_INLINE bool from_chars(csubstr buf,  int64_t *C4_RESTRICT v) noexcept { return atoi(buf, v); }
C4_ALWAYS_INLINE bool from_chars(csubstr buf,    float *C4_RESTRICT v) noexcept { return atof(buf, v); }
C4_ALWAYS_INLINE bool from_chars(csubstr buf,   double *C4_RESTRICT v) noexcept { return atod(buf, v); }

template <class T> _C4_IF_NOT_FIXED_LENGTH_I(T, bool  )::type from_chars(csubstr buf, T *C4_RESTRICT v) noexcept { return atoi(buf, v); }
template <class T> _C4_IF_NOT_FIXED_LENGTH_U(T, bool  )::type from_chars(csubstr buf, T *C4_RESTRICT v) noexcept { return atou(buf, v); }
template <class T>
C4_ALWAYS_INLINE bool from_chars(csubstr buf, T **v) noexcept { intptr_t tmp; bool ret = from_chars(buf, &tmp); if(ret) { *v = (T*)tmp; } return ret; }

/** @defgroup doc_from_chars_first from_chars_first: generalized chars to value
 *
 * Read the first valid sequence of characters from the string,
 * skipping leading whitespace, and convert it using @ref doc_from_chars .
 * Return the number of characters read for converting.
 *
 * Dispatches to the most appropriate and efficient conversion
 * function.
 *
 * @see atou_first, atoi_first, atof_first, atod_first
 * @{ */

C4_ALWAYS_INLINE size_t from_chars_first(csubstr buf,  uint8_t *C4_RESTRICT v) noexcept { return atou_first(buf, v); }
C4_ALWAYS_INLINE size_t from_chars_first(csubstr buf, uint16_t *C4_RESTRICT v) noexcept { return atou_first(buf, v); }
C4_ALWAYS_INLINE size_t from_chars_first(csubstr buf, uint32_t *C4_RESTRICT v) noexcept { return atou_first(buf, v); }
C4_ALWAYS_INLINE size_t from_chars_first(csubstr buf, uint64_t *C4_RESTRICT v) noexcept { return atou_first(buf, v); }
C4_ALWAYS_INLINE size_t from_chars_first(csubstr buf,   int8_t *C4_RESTRICT v) noexcept { return atoi_first(buf, v); }
C4_ALWAYS_INLINE size_t from_chars_first(csubstr buf,  int16_t *C4_RESTRICT v) noexcept { return atoi_first(buf, v); }
C4_ALWAYS_INLINE size_t from_chars_first(csubstr buf,  int32_t *C4_RESTRICT v) noexcept { return atoi_first(buf, v); }
C4_ALWAYS_INLINE size_t from_chars_first(csubstr buf,  int64_t *C4_RESTRICT v) noexcept { return atoi_first(buf, v); }
C4_ALWAYS_INLINE size_t from_chars_first(csubstr buf,    float *C4_RESTRICT v) noexcept { return atof_first(buf, v); }
C4_ALWAYS_INLINE size_t from_chars_first(csubstr buf,   double *C4_RESTRICT v) noexcept { return atod_first(buf, v); }

template <class T> _C4_IF_NOT_FIXED_LENGTH_I(T, size_t)::type from_chars_first(csubstr buf, T *C4_RESTRICT v) noexcept { return atoi_first(buf, v); }
template <class T> _C4_IF_NOT_FIXED_LENGTH_U(T, size_t)::type from_chars_first(csubstr buf, T *C4_RESTRICT v) noexcept { return atou_first(buf, v); }
template <class T>
C4_ALWAYS_INLINE size_t from_chars_first(csubstr buf, T **v) noexcept { intptr_t tmp; bool ret = from_chars_first(buf, &tmp); if(ret) { *v = (T*)tmp; } return ret; }

/** @} */

/** @} */

#undef _C4_IF_NOT_FIXED_LENGTH_I
#undef _C4_IF_NOT_FIXED_LENGTH_U


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** call to_chars() and return a substr consisting of the
 * written portion of the input buffer. Ie, same as to_chars(),
 * but return a substr instead of a size_t.
 * Convert the given value to a string using to_chars(), and
 * return the resulting string, up to and including the last
 * written character.
 * @ingroup doc_to_chars
 * @see to_chars() */
template<class T>
C4_ALWAYS_INLINE substr to_chars_sub(substr buf, T const& C4_RESTRICT v) noexcept
{
    size_t sz = to_chars(buf, v);
    return buf.left_of(sz <= buf.len ? sz : buf.len);
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// bool implementation

/** @ingroup doc_to_chars */
C4_ALWAYS_INLINE size_t to_chars(substr buf, bool v) noexcept
{
    int val = v;
    return to_chars(buf, val);
}

/** @ingroup doc_from_chars */
inline bool from_chars(csubstr buf, bool * C4_RESTRICT v) noexcept
{
    if(buf == '0')
    {
        *v = false; return true;
    }
    else if(buf == '1')
    {
        *v = true; return true;
    }
    else if(buf == "false")
    {
        *v = false; return true;
    }
    else if(buf == "true")
    {
        *v = true; return true;
    }
    else if(buf == "False")
    {
        *v = false; return true;
    }
    else if(buf == "True")
    {
        *v = true; return true;
    }
    else if(buf == "FALSE")
    {
        *v = false; return true;
    }
    else if(buf == "TRUE")
    {
        *v = true; return true;
    }
    // fallback to c-style int bools
    int val = 0;
    bool ret = from_chars(buf, &val);
    if(C4_LIKELY(ret))
    {
        *v = (val != 0);
    }
    return ret;
}

/** @ingroup doc_from_chars_first */
inline size_t from_chars_first(csubstr buf, bool * C4_RESTRICT v) noexcept
{
    csubstr trimmed = buf.first_non_empty_span();
    if(trimmed.len == 0 || !from_chars(buf, v))
        return csubstr::npos;
    return trimmed.len;
}


//-----------------------------------------------------------------------------
// single-char implementation

/** @ingroup doc_to_chars */
inline size_t to_chars(substr buf, char v) noexcept
{
    if(buf.len > 0)
    {
        C4_XASSERT(buf.str);
        buf.str[0] = v;
    }
    return 1;
}

/** extract a single character from a substring
 * @note to extract a string instead and not just a single character, use the csubstr overload
 * @ingroup doc_from_chars
 * */
inline bool from_chars(csubstr buf, char * C4_RESTRICT v) noexcept
{
    if(buf.len != 1)
        return false;
    C4_XASSERT(buf.str);
    *v = buf.str[0];
    return true;
}

/** @ingroup doc_from_chars_first */
inline size_t from_chars_first(csubstr buf, char * C4_RESTRICT v) noexcept
{
    if(buf.len < 1)
        return csubstr::npos;
    *v = buf.str[0];
    return 1;
}


//-----------------------------------------------------------------------------
// csubstr implementation

/** @ingroup doc_to_chars */
inline size_t to_chars(substr buf, csubstr v) noexcept
{
    C4_ASSERT(!buf.overlaps(v));
    size_t len = buf.len < v.len ? buf.len : v.len;
    // calling memcpy with null strings is undefined behavior
    // and will wreak havoc in calling code's branches.
    // see https://github.com/biojppm/rapidyaml/pull/264#issuecomment-1262133637
    if(len)
    {
        C4_ASSERT(buf.str != nullptr);
        C4_ASSERT(v.str != nullptr);
        memcpy(buf.str, v.str, len);
    }
    return v.len;
}

/** @ingroup doc_from_chars */
inline bool from_chars(csubstr buf, csubstr *C4_RESTRICT v) noexcept
{
    *v = buf;
    return true;
}

/** @ingroup doc_from_chars_first */
inline size_t from_chars_first(substr buf, csubstr * C4_RESTRICT v) noexcept
{
    csubstr trimmed = buf.first_non_empty_span();
    if(trimmed.len == 0)
        return csubstr::npos;
    *v = trimmed;
    return static_cast<size_t>(trimmed.end() - buf.begin());
}


//-----------------------------------------------------------------------------
// substr

/** @ingroup doc_to_chars */
inline size_t to_chars(substr buf, substr v) noexcept
{
    C4_ASSERT(!buf.overlaps(v));
    size_t len = buf.len < v.len ? buf.len : v.len;
    // calling memcpy with null strings is undefined behavior
    // and will wreak havoc in calling code's branches.
    // see https://github.com/biojppm/rapidyaml/pull/264#issuecomment-1262133637
    if(len)
    {
        C4_ASSERT(buf.str != nullptr);
        C4_ASSERT(v.str != nullptr);
        memcpy(buf.str, v.str, len);
    }
    return v.len;
}

/** @ingroup doc_from_chars */
inline bool from_chars(csubstr buf, substr * C4_RESTRICT v) noexcept
{
    C4_ASSERT(!buf.overlaps(*v));
    // is the destination buffer wide enough?
    if(v->len >= buf.len)
    {
        // calling memcpy with null strings is undefined behavior
        // and will wreak havoc in calling code's branches.
        // see https://github.com/biojppm/rapidyaml/pull/264#issuecomment-1262133637
        if(buf.len)
        {
            C4_ASSERT(buf.str != nullptr);
            C4_ASSERT(v->str != nullptr);
            memcpy(v->str, buf.str, buf.len);
        }
        v->len = buf.len;
        return true;
    }
    return false;
}

/** @ingroup doc_from_chars_first */
inline size_t from_chars_first(csubstr buf, substr * C4_RESTRICT v) noexcept
{
    csubstr trimmed = buf.first_non_empty_span();
    C4_ASSERT(!trimmed.overlaps(*v));
    if(C4_UNLIKELY(trimmed.len == 0))
        return csubstr::npos;
    size_t len = trimmed.len > v->len ? v->len : trimmed.len;
    // calling memcpy with null strings is undefined behavior
    // and will wreak havoc in calling code's branches.
    // see https://github.com/biojppm/rapidyaml/pull/264#issuecomment-1262133637
    if(len)
    {
        C4_ASSERT(buf.str != nullptr);
        C4_ASSERT(v->str != nullptr);
        memcpy(v->str, trimmed.str, len);
    }
    if(C4_UNLIKELY(trimmed.len > v->len))
        return csubstr::npos;
    return static_cast<size_t>(trimmed.end() - buf.begin());
}


//-----------------------------------------------------------------------------

/** @ingroup doc_to_chars */
template<size_t N>
inline size_t to_chars(substr buf, const char (& C4_RESTRICT v)[N]) noexcept
{
    csubstr sp(v);
    return to_chars(buf, sp);
}

/** @ingroup doc_to_chars */
inline size_t to_chars(substr buf, const char * C4_RESTRICT v) noexcept
{
    return to_chars(buf, to_csubstr(v));
}

/** @} */

} // namespace c4

#ifdef _MSC_VER
#   pragma warning(pop)
#endif

#if defined(__clang__)
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif

#endif /* _C4_CHARCONV_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/charconv.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/utf.hpp
// https://github.com/biojppm/c4core/src/c4/utf.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef C4_UTF_HPP_
#define C4_UTF_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/language.hpp
//#include "c4/language.hpp"
#if !defined(C4_LANGUAGE_HPP_) && !defined(_C4_LANGUAGE_HPP_)
#error "amalgamate: file c4/language.hpp must have been included at this point"
#endif /* C4_LANGUAGE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/substr_fwd.hpp
//#include "c4/substr_fwd.hpp"
#if !defined(C4_SUBSTR_FWD_HPP_) && !defined(_C4_SUBSTR_FWD_HPP_)
#error "amalgamate: file c4/substr_fwd.hpp must have been included at this point"
#endif /* C4_SUBSTR_FWD_HPP_ */

//included above:
//#include <stddef.h>
//included above:
//#include <stdint.h>

namespace c4 {

substr decode_code_point(substr out, csubstr code_point);
size_t decode_code_point(uint8_t *C4_RESTRICT buf, size_t buflen, const uint32_t code);

} // namespace c4

#endif // C4_UTF_HPP_


// (end https://github.com/biojppm/c4core/src/c4/utf.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/format.hpp
// https://github.com/biojppm/c4core/src/c4/format.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_FORMAT_HPP_
#define _C4_FORMAT_HPP_

/** @file format.hpp provides type-safe facilities for formatting arguments
 * to string buffers */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/charconv.hpp
//#include "c4/charconv.hpp"
#if !defined(C4_CHARCONV_HPP_) && !defined(_C4_CHARCONV_HPP_)
#error "amalgamate: file c4/charconv.hpp must have been included at this point"
#endif /* C4_CHARCONV_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/blob.hpp
//#include "c4/blob.hpp"
#if !defined(C4_BLOB_HPP_) && !defined(_C4_BLOB_HPP_)
#error "amalgamate: file c4/blob.hpp must have been included at this point"
#endif /* C4_BLOB_HPP_ */



#ifdef _MSC_VER
#   pragma warning(push)
#   if C4_MSVC_VERSION != C4_MSVC_VERSION_2017
#       pragma warning(disable: 4800) // forcing value to bool 'true' or 'false' (performance warning)
#   endif
#   pragma warning(disable: 4996) // snprintf/scanf: this function or variable may be unsafe
#elif defined(__clang__)
#   pragma clang diagnostic push
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wuseless-cast"
#endif

/** @defgroup doc_format_utils Format utilities
 *
 * @brief Provides generic and type-safe formatting/scanning utilities
 * built on top of @ref doc_to_chars() and @ref doc_from_chars,
 * forwarding the arguments to these functions, which in turn use the
 * @ref doc_charconv utilities. Like @ref doc_charconv, the formatting
 * facilities are very efficient and many times faster than printf().
 *
 * @see [a formatting sample in rapidyaml's docs](https://rapidyaml.readthedocs.io/latest/doxygen/group__doc__quickstart.html#gac2425b515eb552589708cfff70c52b14)
 * */

/** @defgroup doc_format_specifiers Format specifiers
 *
 * @brief Format specifiers are tag types and functions that are used
 * together with @ref doc_to_chars and @ref doc_from_chars
 *
 * @see [a formatting sample in rapidyaml's docs](https://rapidyaml.readthedocs.io/latest/doxygen/group__doc__quickstart.html#gac2425b515eb552589708cfff70c52b14)
 * @ingroup doc_format_utils */

namespace c4 {

/** @addtogroup doc_format_utils
 * @{ */

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// formatting truthy types as booleans

namespace fmt {

/** @addtogroup doc_format_specifiers
 * @{ */

/** @defgroup doc_boolean_specifiers boolean specifiers
 * @{ */

/** write a variable as an alphabetic boolean, ie as either true or false
 * @param strict_read */
template<class T>
struct boolalpha_
{
    boolalpha_(T val_, bool strict_read_=false) : val(val_ ? true : false), strict_read(strict_read_) {}
    bool val;
    bool strict_read;
};

template<class T>
boolalpha_<T> boolalpha(T const& val, bool strict_read=false)
{
    return boolalpha_<T>(val, strict_read);
}

/** @} */

/** @} */

} // namespace fmt

/** write a variable as an alphabetic boolean, ie as either true or
 * false
 * @ingroup doc_to_chars */
template<class T>
inline size_t to_chars(substr buf, fmt::boolalpha_<T> fmt)
{
    return to_chars(buf, fmt.val ? "true" : "false");
}



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// formatting integral types

namespace fmt {

/** @addtogroup doc_format_specifiers
 * @{ */

/** @defgroup doc_integer_specifiers Integer specifiers
 * @{ */

/** format an integral type with a custom radix */
template<typename T>
struct integral_
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    T val;
    T radix;
    C4_ALWAYS_INLINE integral_(T val_, T radix_) : val(val_), radix(radix_) {}
};

/** format an integral type with a custom radix, and pad with zeroes on the left */
template<typename T>
struct integral_padded_
{
    C4_STATIC_ASSERT(std::is_integral<T>::value);
    T val;
    T radix;
    size_t num_digits;
    C4_ALWAYS_INLINE integral_padded_(T val_, T radix_, size_t nd) : val(val_), radix(radix_), num_digits(nd) {}
};


/** format an integral type with a custom radix */
template<class T>
C4_ALWAYS_INLINE integral_<T> integral(T val, T radix=10)
{
    return integral_<T>(val, radix);
}
/** format an integral type with a custom radix */
template<class T>
C4_ALWAYS_INLINE integral_<intptr_t> integral(T const* val, T radix=10)
{
    return integral_<intptr_t>(reinterpret_cast<intptr_t>(val), static_cast<intptr_t>(radix));
}
/** format an integral type with a custom radix */
template<class T>
C4_ALWAYS_INLINE integral_<intptr_t> integral(std::nullptr_t, T radix=10)
{
    return integral_<intptr_t>(intptr_t(0), static_cast<intptr_t>(radix));
}


/** format the pointer as an hexadecimal value */
template<class T>
inline integral_<intptr_t> hex(T * v)
{
    return integral_<intptr_t>(reinterpret_cast<intptr_t>(v), intptr_t(16));
}
/** format the pointer as an hexadecimal value */
template<class T>
inline integral_<intptr_t> hex(T const* v)
{
    return integral_<intptr_t>(reinterpret_cast<intptr_t>(v), intptr_t(16));
}
/** format null as an hexadecimal value
 * @overload hex */
inline integral_<intptr_t> hex(std::nullptr_t)
{
    return integral_<intptr_t>(0, intptr_t(16));
}
/** format the integral_ argument as an hexadecimal value
 * @overload hex */
template<class T>
inline integral_<T> hex(T v)
{
    return integral_<T>(v, T(16));
}

/** format the pointer as an octal value */
template<class T>
inline integral_<intptr_t> oct(T const* v)
{
    return integral_<intptr_t>(reinterpret_cast<intptr_t>(v), intptr_t(8));
}
/** format the pointer as an octal value */
template<class T>
inline integral_<intptr_t> oct(T * v)
{
    return integral_<intptr_t>(reinterpret_cast<intptr_t>(v), intptr_t(8));
}
/** format null as an octal value */
inline integral_<intptr_t> oct(std::nullptr_t)
{
    return integral_<intptr_t>(intptr_t(0), intptr_t(8));
}
/** format the integral_ argument as an octal value */
template<class T>
inline integral_<T> oct(T v)
{
    return integral_<T>(v, T(8));
}

/** format the pointer as a binary 0-1 value
 * @see c4::raw() if you want to use a binary memcpy instead of 0-1 formatting */
template<class T>
inline integral_<intptr_t> bin(T const* v)
{
    return integral_<intptr_t>(reinterpret_cast<intptr_t>(v), intptr_t(2));
}
/** format the pointer as a binary 0-1 value
 * @see c4::raw() if you want to use a binary memcpy instead of 0-1 formatting */
template<class T>
inline integral_<intptr_t> bin(T * v)
{
    return integral_<intptr_t>(reinterpret_cast<intptr_t>(v), intptr_t(2));
}
/** format null as a binary 0-1 value
 * @see c4::raw() if you want to use a binary memcpy instead of 0-1 formatting */
inline integral_<intptr_t> bin(std::nullptr_t)
{
    return integral_<intptr_t>(intptr_t(0), intptr_t(2));
}
/** format the integral_ argument as a binary 0-1 value
 * @see c4::raw() if you want to use a raw memcpy-based binary dump instead of 0-1 formatting */
template<class T>
inline integral_<T> bin(T v)
{
    return integral_<T>(v, T(2));
}

/** @} */ // integer_specifiers


/** @defgroup doc_zpad Pad the number with zeroes on the left
 * @{ */

/** pad the argument with zeroes on the left, with decimal radix */
template<class T>
C4_ALWAYS_INLINE integral_padded_<T> zpad(T val, size_t num_digits)
{
    return integral_padded_<T>(val, T(10), num_digits);
}
/** pad the argument with zeroes on the left */
template<class T>
C4_ALWAYS_INLINE integral_padded_<T> zpad(integral_<T> val, size_t num_digits)
{
    return integral_padded_<T>(val.val, val.radix, num_digits);
}
/** pad the argument with zeroes on the left */
C4_ALWAYS_INLINE integral_padded_<intptr_t> zpad(std::nullptr_t, size_t num_digits)
{
    return integral_padded_<intptr_t>(0, 16, num_digits);
}
/** pad the argument with zeroes on the left */
template<class T>
C4_ALWAYS_INLINE integral_padded_<intptr_t> zpad(T const* val, size_t num_digits)
{
    return integral_padded_<intptr_t>(reinterpret_cast<intptr_t>(val), 16, num_digits);
}
template<class T>
C4_ALWAYS_INLINE integral_padded_<intptr_t> zpad(T * val, size_t num_digits)
{
    return integral_padded_<intptr_t>(reinterpret_cast<intptr_t>(val), 16, num_digits);
}

/** @} */ // zpad


/** @defgroup doc_overflow_checked Check read for overflow
 * @{ */

template<class T>
struct overflow_checked_
{
    static_assert(std::is_integral<T>::value, "range checking only for integral types");
    C4_ALWAYS_INLINE overflow_checked_(T &val_) : val(&val_) {}
    T *val;
};
template<class T>
C4_ALWAYS_INLINE overflow_checked_<T> overflow_checked(T &val)
{
   return overflow_checked_<T>(val);
}

/** @} */ // overflow_checked

/** @} */ // format_specifiers


} // namespace fmt

/** format an integer signed type
 * @ingroup doc_to_chars */
template<typename T>
C4_ALWAYS_INLINE
typename std::enable_if<std::is_signed<T>::value, size_t>::type
to_chars(substr buf, fmt::integral_<T> fmt)
{
    return itoa(buf, fmt.val, fmt.radix);
}
/** format an integer signed type, pad with zeroes
 * @ingroup doc_to_chars */
template<typename T>
C4_ALWAYS_INLINE
typename std::enable_if<std::is_signed<T>::value, size_t>::type
to_chars(substr buf, fmt::integral_padded_<T> fmt)
{
    return itoa(buf, fmt.val, fmt.radix, fmt.num_digits);
}

/** format an integer unsigned type
 * @ingroup doc_to_chars */
template<typename T>
C4_ALWAYS_INLINE
typename std::enable_if<std::is_unsigned<T>::value, size_t>::type
to_chars(substr buf, fmt::integral_<T> fmt)
{
    return utoa(buf, fmt.val, fmt.radix);
}
/** format an integer unsigned type, pad with zeroes
 * @ingroup doc_to_chars */
template<typename T>
C4_ALWAYS_INLINE
typename std::enable_if<std::is_unsigned<T>::value, size_t>::type
to_chars(substr buf, fmt::integral_padded_<T> fmt)
{
    return utoa(buf, fmt.val, fmt.radix, fmt.num_digits);
}

/** read an integer type, detecting overflow (returns false on overflow)
 * @ingroup doc_from_chars */
template<class T>
C4_ALWAYS_INLINE bool from_chars(csubstr s, fmt::overflow_checked_<T> wrapper)
{
    if(C4_LIKELY(!overflows<T>(s)))
        return atox(s, wrapper.val);
    return false;
}
/** read an integer type, detecting overflow (returns false on overflow)
 * @ingroup doc_from_chars */
template<class T>
C4_ALWAYS_INLINE bool from_chars(csubstr s, fmt::overflow_checked_<T> *wrapper)
{
    if(C4_LIKELY(!overflows<T>(s)))
        return atox(s, wrapper->val);
    return false;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// formatting real types

namespace fmt {

/** @addtogroup doc_format_specifiers
 * @{ */

/** @defgroup doc_real_specifiers Real specifiers
 * @{ */

template<class T>
struct real_
{
    T val;
    int precision;
    RealFormat_e fmt;
    real_(T v, int prec=-1, RealFormat_e f=FTOA_FLOAT) : val(v), precision(prec), fmt(f)  {}
};

template<class T>
real_<T> real(T val, int precision, RealFormat_e fmt=FTOA_FLOAT)
{
    return real_<T>(val, precision, fmt);
}

/** @} */ // real_specifiers

/** @} */ // format_specifiers

} // namespace fmt

/** @ingroup doc_to_chars */
inline size_t to_chars(substr buf, fmt::real_< float> fmt) { return ftoa(buf, fmt.val, fmt.precision, fmt.fmt); }
/** @ingroup doc_to_chars */
inline size_t to_chars(substr buf, fmt::real_<double> fmt) { return dtoa(buf, fmt.val, fmt.precision, fmt.fmt); }


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// writing raw binary data

namespace fmt {

/** @addtogroup doc_format_specifiers
 * @{ */

/** @defgroup doc_raw_binary_specifiers Raw binary data
 * @{ */

/** @see blob_ */
template<class T>
struct raw_wrapper_ : public blob_<T>
{
    size_t alignment;

    C4_ALWAYS_INLINE raw_wrapper_(blob_<T> data, size_t alignment_) noexcept
        :
        blob_<T>(data),
        alignment(alignment_)
    {
        C4_ASSERT_MSG(alignment > 0 && (alignment & (alignment - 1)) == 0, "alignment must be a power of two");
    }
};

using const_raw_wrapper = raw_wrapper_<cbyte>;
using raw_wrapper = raw_wrapper_<byte>;

/** mark a variable to be written in raw binary format, using memcpy
 * @see blob_ */
inline const_raw_wrapper craw(cblob data, size_t alignment=alignof(max_align_t))
{
    return const_raw_wrapper(data, alignment);
}
/** mark a variable to be written in raw binary format, using memcpy
 * @see blob_ */
inline const_raw_wrapper raw(cblob data, size_t alignment=alignof(max_align_t))
{
    return const_raw_wrapper(data, alignment);
}
/** mark a variable to be written in raw binary format, using memcpy
 * @see blob_ */
template<class T>
inline const_raw_wrapper craw(T const& C4_RESTRICT data, size_t alignment=alignof(T))
{
    return const_raw_wrapper(cblob(data), alignment);
}
/** mark a variable to be written in raw binary format, using memcpy
 * @see blob_ */
template<class T>
inline const_raw_wrapper raw(T const& C4_RESTRICT data, size_t alignment=alignof(T))
{
    return const_raw_wrapper(cblob(data), alignment);
}

/** mark a variable to be read in raw binary format, using memcpy */
inline raw_wrapper raw(blob data, size_t alignment=alignof(max_align_t))
{
    return raw_wrapper(data, alignment);
}
/** mark a variable to be read in raw binary format, using memcpy */
template<class T>
inline raw_wrapper raw(T & C4_RESTRICT data, size_t alignment=alignof(T))
{
    return raw_wrapper(blob(data), alignment);
}

/** @} */ // raw_binary_specifiers

/** @} */ // format_specifiers

} // namespace fmt


/** write a variable in raw binary format, using memcpy
 * @ingroup doc_to_chars */
C4CORE_EXPORT size_t to_chars(substr buf, fmt::const_raw_wrapper r);

/** read a variable in raw binary format, using memcpy
 * @ingroup doc_from_chars */
C4CORE_EXPORT bool from_chars(csubstr buf, fmt::raw_wrapper *r);
/** read a variable in raw binary format, using memcpy
 * @ingroup doc_from_chars */
inline bool from_chars(csubstr buf, fmt::raw_wrapper r)
{
    return from_chars(buf, &r);
}

/** read a variable in raw binary format, using memcpy
 * @ingroup doc_from_chars_first */
inline size_t from_chars_first(csubstr buf, fmt::raw_wrapper *r)
{
    return from_chars(buf, r);
}
/** read a variable in raw binary format, using memcpy
 * @ingroup doc_from_chars_first */
inline size_t from_chars_first(csubstr buf, fmt::raw_wrapper r)
{
    return from_chars(buf, &r);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// formatting aligned to left/right

namespace fmt {

/** @addtogroup doc_format_specifiers
 * @{ */

/** @defgroup doc_alignment_specifiers Alignment specifiers
 * @{ */

template<class T>
struct left_
{
    T val;
    size_t width;
    char pad;
    left_(T v, size_t w, char p) : val(v), width(w), pad(p) {}
};

template<class T>
struct right_
{
    T val;
    size_t width;
    char pad;
    right_(T v, size_t w, char p) : val(v), width(w), pad(p) {}
};

/** mark an argument to be aligned left */
template<class T>
left_<T> left(T val, size_t width, char padchar=' ')
{
    return left_<T>(val, width, padchar);
}

/** mark an argument to be aligned right */
template<class T>
right_<T> right(T val, size_t width, char padchar=' ')
{
    return right_<T>(val, width, padchar);
}

/** @} */ // alignment_specifiers

/** @} */ // format_specifiers

} // namespace fmt


/** @ingroup doc_to_chars */
template<class T>
size_t to_chars(substr buf, fmt::left_<T> const& C4_RESTRICT align)
{
    size_t ret = to_chars(buf, align.val);
    if(ret >= buf.len || ret >= align.width)
        return ret > align.width ? ret : align.width;
    buf.first(align.width).sub(ret).fill(align.pad);
    to_chars(buf, align.val);
    return align.width;
}

/** @ingroup doc_to_chars */
template<class T>
size_t to_chars(substr buf, fmt::right_<T> const& C4_RESTRICT align)
{
    size_t ret = to_chars(buf, align.val);
    if(ret >= buf.len || ret >= align.width)
        return ret > align.width ? ret : align.width;
    size_t rem = static_cast<size_t>(align.width - ret);
    buf.first(rem).fill(align.pad);
    to_chars(buf.sub(rem), align.val);
    return align.width;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @defgroup doc_cat cat: concatenate arguments to string
 * @{ */

/** @cond dev */
// terminates the variadic recursion
inline size_t cat(substr /*buf*/)
{
    return 0;
}
/** @endcond */


/** serialize the arguments, concatenating them to the given fixed-size buffer.
 * The buffer size is strictly respected: no writes will occur beyond its end.
 * @return the number of characters needed to write all the arguments into the buffer.
 * @see c4::catrs() if instead of a fixed-size buffer, a resizeable container is desired
 * @see c4::uncat() for the inverse function
 * @see c4::catsep() if a separator between each argument is to be used
 * @see c4::format() if a format string is desired */
template<class Arg, class... Args>
size_t cat(substr buf, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    size_t num = to_chars(buf, a);
    buf  = buf.len >= num ? buf.sub(num) : substr{};
    num += cat(buf, more...);
    return num;
}

/** like c4::cat() but return a substr instead of a size */
template<class... Args>
substr cat_sub(substr buf, Args && ...args)
{
    size_t sz = cat(buf, std::forward<Args>(args)...);
    C4_CHECK(sz <= buf.len);
    return {buf.str, sz <= buf.len ? sz : buf.len};
}

/** @} */


//-----------------------------------------------------------------------------


/** @defgroup doc_uncat uncat: read concatenated arguments from string
 * @{ */

/** @cond dev */
// terminates the variadic recursion
inline size_t uncat(csubstr /*buf*/)
{
    return 0;
}
/** @endcond */


/** deserialize the arguments from the given buffer.
 *
 * @return the number of characters read from the buffer, or csubstr::npos
 *   if a conversion was not successful.
 * @see c4::cat(). c4::uncat() is the inverse of c4::cat(). */
template<class Arg, class... Args>
size_t uncat(csubstr buf, Arg & C4_RESTRICT a, Args & C4_RESTRICT ...more)
{
    size_t out = from_chars_first(buf, &a);
    if(C4_UNLIKELY(out == csubstr::npos))
        return csubstr::npos;
    buf  = buf.len >= out ? buf.sub(out) : substr{};
    size_t num = uncat(buf, more...);
    if(C4_UNLIKELY(num == csubstr::npos))
        return csubstr::npos;
    return out + num;
}

/** @} */



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


/** @defgroup doc_catsep catsep: cat arguments to string with separator
 * @{ */

/** @cond dev */
namespace detail {
template<class Sep>
C4_ALWAYS_INLINE size_t catsep_more(substr /*buf*/, Sep const& C4_RESTRICT /*sep*/)
{
    return 0;
}

template<class Sep, class Arg, class... Args>
size_t catsep_more(substr buf, Sep const& C4_RESTRICT sep, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    size_t ret = to_chars(buf, sep);
    size_t num = ret;
    buf  = buf.len >= ret ? buf.sub(ret) : substr{};
    ret  = to_chars(buf, a);
    num += ret;
    buf  = buf.len >= ret ? buf.sub(ret) : substr{};
    ret  = catsep_more(buf, sep, more...);
    num += ret;
    return num;
}


template<class Sep>
inline size_t uncatsep_more(csubstr /*buf*/, Sep & /*sep*/)
{
    return 0;
}

template<class Sep, class Arg, class... Args>
size_t uncatsep_more(csubstr buf, Sep & C4_RESTRICT sep, Arg & C4_RESTRICT a, Args & C4_RESTRICT ...more)
{
    size_t ret = from_chars_first(buf, &sep);
    size_t num = ret;
    if(C4_UNLIKELY(ret == csubstr::npos))
        return csubstr::npos;
    buf  = buf.len >= ret ? buf.sub(ret) : substr{};
    ret  = from_chars_first(buf, &a);
    if(C4_UNLIKELY(ret == csubstr::npos))
        return csubstr::npos;
    num += ret;
    buf  = buf.len >= ret ? buf.sub(ret) : substr{};
    ret  = uncatsep_more(buf, sep, more...);
    if(C4_UNLIKELY(ret == csubstr::npos))
        return csubstr::npos;
    num += ret;
    return num;
}

} // namespace detail

template<class Sep>
size_t catsep(substr /*buf*/, Sep const& C4_RESTRICT /*sep*/)
{
    return 0;
}
/** @endcond */


/** serialize the arguments, concatenating them to the given fixed-size
 * buffer, using a separator between each argument.
 * The buffer size is strictly respected: no writes will occur beyond its end.
 * @return the number of characters needed to write all the arguments into the buffer.
 * @see c4::catseprs() if instead of a fixed-size buffer, a resizeable container is desired
 * @see c4::uncatsep() for the inverse function (ie, reading instead of writing)
 * @see c4::cat() if no separator is needed
 * @see c4::format() if a format string is desired */
template<class Sep, class Arg, class... Args>
size_t catsep(substr buf, Sep const& C4_RESTRICT sep, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    size_t num = to_chars(buf, a);
    buf  = buf.len >= num ? buf.sub(num) : substr{};
    num += detail::catsep_more(buf, sep, more...);
    return num;
}

/** like c4::catsep() but return a substr instead of a size
 * @see c4::catsep(). c4::uncatsep() is the inverse of c4::catsep(). */
template<class... Args>
substr catsep_sub(substr buf, Args && ...args)
{
    size_t sz = catsep(buf, std::forward<Args>(args)...);
    C4_CHECK(sz <= buf.len);
    return {buf.str, sz <= buf.len ? sz : buf.len};
}

/** @} */



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @defgroup doc_uncatsep uncatsep: deserialize the separated arguments from a string
 * @{ */

/** deserialize the arguments from the given buffer.
 *
 * @return the number of characters read from the buffer, or csubstr::npos
 *   if a conversion was not successful.
 * @see c4::cat(). c4::uncat() is the inverse of c4::cat(). */

/** deserialize the arguments from the given buffer, using a separator.
 *
 * @return the number of characters read from the buffer, or csubstr::npos
 *   if a conversion was not successful
 * @see c4::catsep(). c4::uncatsep() is the inverse of c4::catsep(). */
template<class Sep, class Arg, class... Args>
size_t uncatsep(csubstr buf, Sep & C4_RESTRICT sep, Arg & C4_RESTRICT a, Args & C4_RESTRICT ...more)
{
    size_t ret = from_chars_first(buf, &a), num = ret;
    if(C4_UNLIKELY(ret == csubstr::npos))
        return csubstr::npos;
    buf  = buf.len >= ret ? buf.sub(ret) : substr{};
    ret  = detail::uncatsep_more(buf, sep, more...);
    if(C4_UNLIKELY(ret == csubstr::npos))
        return csubstr::npos;
    num += ret;
    return num;
}

/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @defgroup doc_format format: formatted string interpolation
 * @{ */

/// @cond dev
// terminates the variadic recursion
inline size_t format(substr buf, csubstr fmt)
{
    return to_chars(buf, fmt);
}
/// @endcond


/** using a format string, serialize the arguments into the given
 * fixed-size buffer.
 * The buffer size is strictly respected: no writes will occur beyond its end.
 * In the format string, each argument is marked with a compact
 * curly-bracket pair: {}. Arguments beyond the last curly bracket pair
 * are silently ignored. For example:
 * @code{.cpp}
 * c4::format(buf, "the {} drank {} {}", "partier", 5, "beers"); // the partier drank 5 beers
 * c4::format(buf, "the {} drank {} {}", "programmer", 6, "coffees"); // the programmer drank 6 coffees
 * @endcode
 * @return the number of characters needed to write into the buffer.
 * @see c4::formatrs() if instead of a fixed-size buffer, a resizeable container is desired
 * @see c4::unformat() for the inverse function
 * @see c4::cat() if no format or separator is needed
 * @see c4::catsep() if no format is needed, but a separator must be used */
template<class Arg, class... Args>
size_t format(substr buf, csubstr fmt, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    size_t pos = fmt.find("{}"); // @todo use _find_fmt()
    if(C4_UNLIKELY(pos == csubstr::npos))
        return to_chars(buf, fmt);
    size_t num = to_chars(buf, fmt.sub(0, pos));
    size_t out = num;
    buf  = buf.len >= num ? buf.sub(num) : substr{};
    num  = to_chars(buf, a);
    out += num;
    buf  = buf.len >= num ? buf.sub(num) : substr{};
    num  = format(buf, fmt.sub(pos + 2), more...);
    out += num;
    return out;
}

/** like c4::format() but return a substr instead of a size
 * @see c4::format()
 * @see c4::catsep(). uncatsep() is the inverse of catsep(). */
template<class... Args>
substr format_sub(substr buf, csubstr fmt, Args const& C4_RESTRICT ...args)
{
    size_t sz = c4::format(buf, fmt, args...);
    C4_CHECK(sz <= buf.len);
    return {buf.str, sz <= buf.len ? sz : buf.len};
}

/** @} */


//-----------------------------------------------------------------------------

/** @defgroup doc_unformat unformat: formatted read from string
 * @{ */

/// @cond dev
// terminates the variadic recursion
inline size_t unformat(csubstr /*buf*/, csubstr fmt)
{
    return fmt.len;
}
/// @endcond


/** using a format string, deserialize the arguments from the given
 * buffer.
 * @return the number of characters read from the buffer, or npos if a conversion failed.
 * @see c4::format(). c4::unformat() is the inverse function to format(). */
template<class Arg, class... Args>
size_t unformat(csubstr buf, csubstr fmt, Arg & C4_RESTRICT a, Args & C4_RESTRICT ...more)
{
    const size_t pos = fmt.find("{}");
    if(C4_UNLIKELY(pos == csubstr::npos))
        return unformat(buf, fmt);
    size_t num = pos;
    size_t out = num;
    buf  = buf.len >= num ? buf.sub(num) : substr{};
    num  = from_chars_first(buf, &a);
    if(C4_UNLIKELY(num == csubstr::npos))
        return csubstr::npos;
    out += num;
    buf  = buf.len >= num ? buf.sub(num) : substr{};
    num  = unformat(buf, fmt.sub(pos + 2), more...);
    if(C4_UNLIKELY(num == csubstr::npos))
        return csubstr::npos;
    out += num;
    return out;
}

/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** cat+resize: like c4::cat(), but receives a container, and resizes
 * it as needed to contain the result. The container is
 * overwritten. To append to it, use the append overload.
 * @see c4::cat()
 * @ingroup doc_cat */
template<class CharOwningContainer, class... Args>
inline void catrs(CharOwningContainer * C4_RESTRICT cont, Args const& C4_RESTRICT ...args)
{
retry:
    substr buf = to_substr(*cont);
    size_t ret = cat(buf, args...);
    cont->resize(ret);
    if(ret > buf.len)
        goto retry;
}

/** cat+resize: like c4::cat(), but creates and returns a new
 * container sized as needed to contain the result.
 * @see c4::cat()
 * @ingroup doc_cat */
template<class CharOwningContainer, class... Args>
inline CharOwningContainer catrs(Args const& C4_RESTRICT ...args)
{
    CharOwningContainer cont;
    catrs(&cont, args...);
    return cont;
}

/** cat+resize+append: like c4::cat(), but receives a container, and
 * appends to it instead of overwriting it. The container is resized
 * as needed to contain the result.
 *
 * @return the region newly appended to the original container
 * @see c4::cat()
 * @see c4::catrs()
 * @ingroup doc_cat */
template<class CharOwningContainer, class... Args>
inline csubstr catrs_append(CharOwningContainer * C4_RESTRICT cont, Args const& C4_RESTRICT ...args)
{
    const size_t pos = cont->size();
retry:
    substr buf = to_substr(*cont).sub(pos);
    size_t ret = cat(buf, args...);
    cont->resize(pos + ret);
    if(ret > buf.len)
        goto retry;
    return to_csubstr(*cont).range(pos, cont->size());
}


//-----------------------------------------------------------------------------

/** catsep+resize: like c4::catsep(), but receives a container, and
 * resizes it as needed to contain the result.  The container is
 * overwritten. To append to the container use the append overload.
 *
 * @see c4::catsep()
 * @ingroup doc_catsep */
template<class CharOwningContainer, class Sep, class... Args>
inline void catseprs(CharOwningContainer * C4_RESTRICT cont, Sep const& C4_RESTRICT sep, Args const& C4_RESTRICT ...args)
{
retry:
    substr buf = to_substr(*cont);
    size_t ret = catsep(buf, sep, args...);
    cont->resize(ret);
    if(ret > buf.len)
        goto retry;
}

/** catsep+resize: like c4::catsep(), but create a new container with
 * the result.
 *
 * @return the requested container
 * @ingroup doc_catsep */
template<class CharOwningContainer, class Sep, class... Args>
inline CharOwningContainer catseprs(Sep const& C4_RESTRICT sep, Args const& C4_RESTRICT ...args)
{
    CharOwningContainer cont;
    catseprs(&cont, sep, args...);
    return cont;
}


/** catsep+resize+append: like catsep(), but receives a container, and
 * appends the arguments, resizing the container as needed to contain
 * the result. The buffer is appended to.
 *
 * @return a csubstr of the appended part
 * @ingroup formatting_functions
 * @ingroup doc_catsep */
template<class CharOwningContainer, class Sep, class... Args>
inline csubstr catseprs_append(CharOwningContainer * C4_RESTRICT cont, Sep const& C4_RESTRICT sep, Args const& C4_RESTRICT ...args)
{
    const size_t pos = cont->size();
retry:
    substr buf = to_substr(*cont).sub(pos);
    size_t ret = catsep(buf, sep, args...);
    cont->resize(pos + ret);
    if(ret > buf.len)
        goto retry;
    return to_csubstr(*cont).range(pos, cont->size());
}


//-----------------------------------------------------------------------------

/** format+resize: like c4::format(), but receives a container, and
 * resizes it as needed to contain the result.  The container is
 * overwritten. To append to the container use the append overload.
 *
 * @see c4::format()
 * @ingroup doc_format */
template<class CharOwningContainer, class... Args>
inline void formatrs(CharOwningContainer * C4_RESTRICT cont, csubstr fmt, Args const& C4_RESTRICT ...args)
{
retry:
    substr buf = to_substr(*cont);
    size_t ret = format(buf, fmt, args...);
    cont->resize(ret);
    if(ret > buf.len)
        goto retry;
}

/** format+resize: like c4::format(), but create a new container with
 * the result.
 *
 * @return the requested container
 * @ingroup doc_format */
template<class CharOwningContainer, class... Args>
inline CharOwningContainer formatrs(csubstr fmt, Args const& C4_RESTRICT ...args)
{
    CharOwningContainer cont;
    formatrs(&cont, fmt, args...);
    return cont;
}

/** format+resize+append: like format(), but receives a container, and appends the
 * arguments, resizing the container as needed to contain the
 * result. The buffer is appended to.
 * @return the region newly appended to the original container
 * @ingroup formatting_functions
 * @ingroup doc_format */
template<class CharOwningContainer, class... Args>
inline csubstr formatrs_append(CharOwningContainer * C4_RESTRICT cont, csubstr fmt, Args const& C4_RESTRICT ...args)
{
    const size_t pos = cont->size();
retry:
    substr buf = to_substr(*cont).sub(pos);
    size_t ret = format(buf, fmt, args...);
    cont->resize(pos + ret);
    if(ret > buf.len)
        goto retry;
    return to_csubstr(*cont).range(pos, cont->size());
}

/** @} */

} // namespace c4

#ifdef _MSC_VER
#   pragma warning(pop)
#elif defined(__clang__)
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif

#endif /* _C4_FORMAT_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/format.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/dump.hpp
// https://github.com/biojppm/c4core/src/c4/dump.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef C4_DUMP_HPP_
#define C4_DUMP_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/substr.hpp
//#include <c4/substr.hpp>
#if !defined(C4_SUBSTR_HPP_) && !defined(_C4_SUBSTR_HPP_)
#error "amalgamate: file c4/substr.hpp must have been included at this point"
#endif /* C4_SUBSTR_HPP_ */


namespace c4 {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** type of the function to dump characters */
using DumperPfn = void (*)(csubstr buf);


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<DumperPfn dumpfn, class Arg>
inline size_t dump(substr buf, Arg const& a)
{
    size_t sz = to_chars(buf, a); // need to serialize to the buffer
    if(C4_LIKELY(sz <= buf.len))
        dumpfn(buf.first(sz));
    return sz;
}

template<class DumperFn, class Arg>
inline size_t dump(DumperFn &&dumpfn, substr buf, Arg const& a)
{
    size_t sz = to_chars(buf, a); // need to serialize to the buffer
    if(C4_LIKELY(sz <= buf.len))
        dumpfn(buf.first(sz));
    return sz;
}

template<DumperPfn dumpfn>
inline size_t dump(substr buf, csubstr a)
{
    if(buf.len)
        dumpfn(a); // dump directly, no need to serialize to the buffer
    return 0; // no space was used in the buffer
}

template<class DumperFn>
inline size_t dump(DumperFn &&dumpfn, substr buf, csubstr a)
{
    if(buf.len)
        dumpfn(a); // dump directly, no need to serialize to the buffer
    return 0; // no space was used in the buffer
}

template<DumperPfn dumpfn, size_t N>
inline size_t dump(substr buf, const char (&a)[N])
{
    if(buf.len)
        dumpfn(csubstr(a)); // dump directly, no need to serialize to the buffer
    return 0; // no space was used in the buffer
}

template<class DumperFn, size_t N>
inline size_t dump(DumperFn &&dumpfn, substr buf, const char (&a)[N])
{
    if(buf.len)
        dumpfn(csubstr(a)); // dump directly, no need to serialize to the buffer
    return 0; // no space was used in the buffer
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** */
struct DumpResults
{
    enum : size_t { noarg = (size_t)-1 };
    size_t bufsize = 0;
    size_t lastok = noarg;
    bool success_until(size_t expected) const { return lastok == noarg ? false : lastok >= expected; }
    bool write_arg(size_t arg) const { return lastok == noarg || arg > lastok; }
    size_t argfail() const { return lastok + 1; }
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/// @cond dev
// terminates the variadic recursion
template<class DumperFn>
size_t cat_dump(DumperFn &&, substr)
{
    return 0;
}

// terminates the variadic recursion
template<DumperPfn dumpfn>
size_t cat_dump(substr)
{
    return 0;
}
/// @endcond

/** take the function pointer as a function argument */
template<class DumperFn, class Arg, class... Args>
size_t cat_dump(DumperFn &&dumpfn, substr buf, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    size_t size_for_a = dump(dumpfn, buf, a);
    if(C4_UNLIKELY(size_for_a > buf.len))
        buf = buf.first(0); // ensure no more calls
    size_t size_for_more = cat_dump(dumpfn, buf, more...);
    return size_for_more > size_for_a ? size_for_more : size_for_a;
}

/** take the function pointer as a template argument */
template<DumperPfn dumpfn,class Arg, class... Args>
size_t cat_dump(substr buf, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    size_t size_for_a = dump<dumpfn>(buf, a);
    if(C4_LIKELY(size_for_a > buf.len))
        buf = buf.first(0); // ensure no more calls
    size_t size_for_more = cat_dump<dumpfn>(buf, more...);
    return size_for_more > size_for_a ? size_for_more : size_for_a;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/// @cond dev
namespace detail {

// terminates the variadic recursion
template<DumperPfn dumpfn, class Arg>
DumpResults cat_dump_resume(size_t currarg, DumpResults results, substr buf, Arg const& C4_RESTRICT a)
{
    if(C4_LIKELY(results.write_arg(currarg)))
    {
        size_t sz = dump<dumpfn>(buf, a);  // yield to the specialized function
        if(currarg == results.lastok + 1 && sz <= buf.len)
            results.lastok = currarg;
        results.bufsize = sz > results.bufsize ? sz : results.bufsize;
    }
    return results;
}

// terminates the variadic recursion
template<class DumperFn, class Arg>
DumpResults cat_dump_resume(size_t currarg, DumperFn &&dumpfn, DumpResults results, substr buf, Arg const& C4_RESTRICT a)
{
    if(C4_LIKELY(results.write_arg(currarg)))
    {
        size_t sz = dump(dumpfn, buf, a);  // yield to the specialized function
        if(currarg == results.lastok + 1 && sz <= buf.len)
            results.lastok = currarg;
        results.bufsize = sz > results.bufsize ? sz : results.bufsize;
    }
    return results;
}

template<DumperPfn dumpfn, class Arg, class... Args>
DumpResults cat_dump_resume(size_t currarg, DumpResults results, substr buf, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    results = detail::cat_dump_resume<dumpfn>(currarg, results, buf, a);
    return detail::cat_dump_resume<dumpfn>(currarg + 1u, results, buf, more...);
}

template<class DumperFn, class Arg, class... Args>
DumpResults cat_dump_resume(size_t currarg, DumperFn &&dumpfn, DumpResults results, substr buf, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    results = detail::cat_dump_resume(currarg, dumpfn, results, buf, a);
    return detail::cat_dump_resume(currarg + 1u, dumpfn, results, buf, more...);
}
} // namespace detail
/// @endcond


template<DumperPfn dumpfn, class Arg, class... Args>
C4_ALWAYS_INLINE DumpResults cat_dump_resume(DumpResults results, substr buf, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    if(results.bufsize > buf.len)
        return results;
    return detail::cat_dump_resume<dumpfn>(0u, results, buf, a, more...);
}

template<class DumperFn, class Arg, class... Args>
C4_ALWAYS_INLINE DumpResults cat_dump_resume(DumperFn &&dumpfn, DumpResults results, substr buf, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    if(results.bufsize > buf.len)
        return results;
    return detail::cat_dump_resume(0u, dumpfn, results, buf, a, more...);
}

template<DumperPfn dumpfn, class Arg, class... Args>
C4_ALWAYS_INLINE DumpResults cat_dump_resume(substr buf, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    return detail::cat_dump_resume<dumpfn>(0u, DumpResults{}, buf, a, more...);
}

template<class DumperFn, class Arg, class... Args>
C4_ALWAYS_INLINE DumpResults cat_dump_resume(DumperFn &&dumpfn, substr buf, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    return detail::cat_dump_resume(0u, dumpfn, DumpResults{}, buf, a, more...);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/// @cond dev
// terminate the recursion
template<class DumperFn, class Sep>
size_t catsep_dump(DumperFn &&, substr, Sep const& C4_RESTRICT)
{
    return 0;
}

// terminate the recursion
template<DumperPfn dumpfn, class Sep>
size_t catsep_dump(substr, Sep const& C4_RESTRICT)
{
    return 0;
}
/// @endcond

/** take the function pointer as a function argument */
template<class DumperFn, class Sep, class Arg, class... Args>
size_t catsep_dump(DumperFn &&dumpfn, substr buf, Sep const& C4_RESTRICT sep, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    size_t sz = dump(dumpfn, buf, a);
    if(C4_UNLIKELY(sz > buf.len))
        buf = buf.first(0); // ensure no more calls
    if C4_IF_CONSTEXPR (sizeof...(more) > 0)
    {
        size_t szsep = dump(dumpfn, buf, sep);
        if(C4_UNLIKELY(szsep > buf.len))
            buf = buf.first(0); // ensure no more calls
        sz = sz > szsep ? sz : szsep;
    }
    size_t size_for_more = catsep_dump(dumpfn, buf, sep, more...);
    return size_for_more > sz ? size_for_more : sz;
}

/** take the function pointer as a template argument */
template<DumperPfn dumpfn, class Sep, class Arg, class... Args>
size_t catsep_dump(substr buf, Sep const& C4_RESTRICT sep, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    size_t sz = dump<dumpfn>(buf, a);
    if(C4_UNLIKELY(sz > buf.len))
        buf = buf.first(0); // ensure no more calls
    if C4_IF_CONSTEXPR (sizeof...(more) > 0)
    {
        size_t szsep = dump<dumpfn>(buf, sep);
        if(C4_UNLIKELY(szsep > buf.len))
            buf = buf.first(0); // ensure no more calls
        sz = sz > szsep ? sz : szsep;
    }
    size_t size_for_more = catsep_dump<dumpfn>(buf, sep, more...);
    return size_for_more > sz ? size_for_more : sz;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/// @cond dev
namespace detail {
template<DumperPfn dumpfn, class Arg>
void catsep_dump_resume_(size_t currarg, DumpResults *C4_RESTRICT results, substr *C4_RESTRICT buf, Arg const& C4_RESTRICT a)
{
    if(C4_LIKELY(results->write_arg(currarg)))
    {
        size_t sz = dump<dumpfn>(*buf, a);
        results->bufsize = sz > results->bufsize ? sz : results->bufsize;
        if(C4_LIKELY(sz <= buf->len))
            results->lastok = currarg;
        else
            buf->len = 0;
    }
}

template<class DumperFn, class Arg>
void catsep_dump_resume_(size_t currarg, DumperFn &&dumpfn, DumpResults *C4_RESTRICT results, substr *C4_RESTRICT buf, Arg const& C4_RESTRICT a)
{
    if(C4_LIKELY(results->write_arg(currarg)))
    {
        size_t sz = dump(dumpfn, *buf, a);
        results->bufsize = sz > results->bufsize ? sz : results->bufsize;
        if(C4_LIKELY(sz <= buf->len))
            results->lastok = currarg;
        else
            buf->len = 0;
    }
}

template<DumperPfn dumpfn, class Sep, class Arg>
C4_ALWAYS_INLINE void catsep_dump_resume(size_t currarg, DumpResults *C4_RESTRICT results, substr *C4_RESTRICT buf, Sep const& C4_RESTRICT, Arg const& C4_RESTRICT a)
{
    detail::catsep_dump_resume_<dumpfn>(currarg, results, buf, a);
}

template<class DumperFn, class Sep, class Arg>
C4_ALWAYS_INLINE void catsep_dump_resume(size_t currarg, DumperFn &&dumpfn, DumpResults *C4_RESTRICT results, substr *C4_RESTRICT buf, Sep const& C4_RESTRICT, Arg const& C4_RESTRICT a)
{
    detail::catsep_dump_resume_(currarg, dumpfn, results, buf, a);
}

template<DumperPfn dumpfn, class Sep, class Arg, class... Args>
C4_ALWAYS_INLINE void catsep_dump_resume(size_t currarg, DumpResults *C4_RESTRICT results, substr *C4_RESTRICT buf, Sep const& C4_RESTRICT sep, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    detail::catsep_dump_resume_<dumpfn>(currarg     , results, buf, a);
    detail::catsep_dump_resume_<dumpfn>(currarg + 1u, results, buf, sep);
    detail::catsep_dump_resume <dumpfn>(currarg + 2u, results, buf, sep, more...);
}

template<class DumperFn, class Sep, class Arg, class... Args>
C4_ALWAYS_INLINE void catsep_dump_resume(size_t currarg, DumperFn &&dumpfn, DumpResults *C4_RESTRICT results, substr *C4_RESTRICT buf, Sep const& C4_RESTRICT sep, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    detail::catsep_dump_resume_(currarg     , dumpfn, results, buf, a);
    detail::catsep_dump_resume_(currarg + 1u, dumpfn, results, buf, sep);
    detail::catsep_dump_resume (currarg + 2u, dumpfn, results, buf, sep, more...);
}
} // namespace detail
/// @endcond


template<DumperPfn dumpfn, class Sep, class... Args>
C4_ALWAYS_INLINE DumpResults catsep_dump_resume(DumpResults results, substr buf, Sep const& C4_RESTRICT sep, Args const& C4_RESTRICT ...more)
{
    detail::catsep_dump_resume<dumpfn>(0u, &results, &buf, sep, more...);
    return results;
}

template<class DumperFn, class Sep, class... Args>
C4_ALWAYS_INLINE DumpResults catsep_dump_resume(DumperFn &&dumpfn, DumpResults results, substr buf, Sep const& C4_RESTRICT sep, Args const& C4_RESTRICT ...more)
{
    detail::catsep_dump_resume(0u, dumpfn, &results, &buf, sep, more...);
    return results;
}

template<DumperPfn dumpfn, class Sep, class... Args>
C4_ALWAYS_INLINE DumpResults catsep_dump_resume(substr buf, Sep const& C4_RESTRICT sep, Args const& C4_RESTRICT ...more)
{
    DumpResults results;
    detail::catsep_dump_resume<dumpfn>(0u, &results, &buf, sep, more...);
    return results;
}

template<class DumperFn, class Sep, class... Args>
C4_ALWAYS_INLINE DumpResults catsep_dump_resume(DumperFn &&dumpfn, substr buf, Sep const& C4_RESTRICT sep, Args const& C4_RESTRICT ...more)
{
    DumpResults results;
    detail::catsep_dump_resume(0u, dumpfn, &results, &buf, sep, more...);
    return results;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/// @cond dev

/** take the function pointer as a function argument */
template<class DumperFn>
C4_ALWAYS_INLINE size_t format_dump(DumperFn &&dumpfn, substr buf, csubstr fmt)
{
    // we can dump without using buf
    // but we'll only dump if the buffer is ok
    if(C4_LIKELY(buf.len > 0 && fmt.len))
        dumpfn(fmt);
    return 0u;
}

/** take the function pointer as a template argument */
template<DumperPfn dumpfn>
C4_ALWAYS_INLINE size_t format_dump(substr buf, csubstr fmt)
{
    // we can dump without using buf
    // but we'll only dump if the buffer is ok
    if(C4_LIKELY(buf.len > 0 && fmt.len > 0))
        dumpfn(fmt);
    return 0u;
}

/// @endcond


/** take the function pointer as a function argument */
template<class DumperFn, class Arg, class... Args>
C4_NO_INLINE size_t format_dump(DumperFn &&dumpfn, substr buf, csubstr fmt, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    // we can dump without using buf
    // but we'll only dump if the buffer is ok
    size_t pos = fmt.find("{}"); // @todo use _find_fmt()
    if(C4_UNLIKELY(pos == csubstr::npos))
    {
        if(C4_LIKELY(buf.len > 0 && fmt.len > 0))
            dumpfn(fmt);
        return 0u;
    }
    if(C4_LIKELY(buf.len > 0 && pos > 0))
        dumpfn(fmt.first(pos)); // we can dump without using buf
    fmt = fmt.sub(pos + 2); // skip {} do this before assigning to pos again
    pos = dump(dumpfn, buf, a);
    if(C4_UNLIKELY(pos > buf.len))
        buf.len = 0; // ensure no more calls to dump
    size_t size_for_more = format_dump(dumpfn, buf, fmt, more...);
    return size_for_more > pos ? size_for_more : pos;
}

/** take the function pointer as a template argument */
template<DumperPfn dumpfn, class Arg, class... Args>
C4_NO_INLINE size_t format_dump(substr buf, csubstr fmt, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    // we can dump without using buf
    // but we'll only dump if the buffer is ok
    size_t pos = fmt.find("{}"); // @todo use _find_fmt()
    if(C4_UNLIKELY(pos == csubstr::npos))
    {
        if(C4_LIKELY(buf.len > 0 && fmt.len > 0))
            dumpfn(fmt);
        return 0u;
    }
    if(C4_LIKELY(buf.len > 0 && pos > 0))
        dumpfn(fmt.first(pos)); // we can dump without using buf
    fmt = fmt.sub(pos + 2); // skip {} do this before assigning to pos again
    pos = dump<dumpfn>(buf, a);
    if(C4_UNLIKELY(pos > buf.len))
        buf.len = 0; // ensure no more calls to dump
    size_t size_for_more = format_dump<dumpfn>(buf, fmt, more...);
    return size_for_more > pos ? size_for_more : pos;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/// @cond dev
namespace detail {

template<DumperPfn dumpfn>
DumpResults format_dump_resume(size_t currarg, DumpResults results, substr buf, csubstr fmt)
{
    // we can dump without using buf
    // but we'll only dump if the buffer is ok
    if(C4_LIKELY(buf.len > 0))
    {
        dumpfn(fmt);
        results.lastok = currarg;
    }
    return results;
}

template<class DumperFn>
DumpResults format_dump_resume(size_t currarg, DumperFn &&dumpfn, DumpResults results, substr buf, csubstr fmt)
{
    // we can dump without using buf
    // but we'll only dump if the buffer is ok
    if(C4_LIKELY(buf.len > 0))
    {
        dumpfn(fmt);
        results.lastok = currarg;
    }
    return results;
}

template<DumperPfn dumpfn, class Arg, class... Args>
DumpResults format_dump_resume(size_t currarg, DumpResults results, substr buf, csubstr fmt, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    // we need to process the format even if we're not
    // going to print the first arguments because we're resuming
    size_t pos = fmt.find("{}"); // @todo use _find_fmt()
    // we can dump without using buf
    // but we'll only dump if the buffer is ok
    if(C4_LIKELY(results.write_arg(currarg)))
    {
        if(C4_UNLIKELY(pos == csubstr::npos))
        {
            if(C4_LIKELY(buf.len > 0))
            {
                results.lastok = currarg;
                dumpfn(fmt);
            }
            return results;
        }
        if(C4_LIKELY(buf.len > 0))
        {
            results.lastok = currarg;
            dumpfn(fmt.first(pos));
        }
    }
    fmt = fmt.sub(pos + 2);
    if(C4_LIKELY(results.write_arg(currarg + 1)))
    {
        pos = dump<dumpfn>(buf, a);
        results.bufsize = pos > results.bufsize ? pos : results.bufsize;
        if(C4_LIKELY(pos <= buf.len))
            results.lastok = currarg + 1;
        else
            buf.len = 0;
    }
    return detail::format_dump_resume<dumpfn>(currarg + 2u, results, buf, fmt, more...);
}
/// @endcond


template<class DumperFn, class Arg, class... Args>
DumpResults format_dump_resume(size_t currarg, DumperFn &&dumpfn, DumpResults results, substr buf, csubstr fmt, Arg const& C4_RESTRICT a, Args const& C4_RESTRICT ...more)
{
    // we need to process the format even if we're not
    // going to print the first arguments because we're resuming
    size_t pos = fmt.find("{}"); // @todo use _find_fmt()
    // we can dump without using buf
    // but we'll only dump if the buffer is ok
    if(C4_LIKELY(results.write_arg(currarg)))
    {
        if(C4_UNLIKELY(pos == csubstr::npos))
        {
            if(C4_LIKELY(buf.len > 0))
            {
                results.lastok = currarg;
                dumpfn(fmt);
            }
            return results;
        }
        if(C4_LIKELY(buf.len > 0))
        {
            results.lastok = currarg;
            dumpfn(fmt.first(pos));
        }
    }
    fmt = fmt.sub(pos + 2);
    if(C4_LIKELY(results.write_arg(currarg + 1)))
    {
        pos = dump(dumpfn, buf, a);
        results.bufsize = pos > results.bufsize ? pos : results.bufsize;
        if(C4_LIKELY(pos <= buf.len))
            results.lastok = currarg + 1;
        else
            buf.len = 0;
    }
    return detail::format_dump_resume(currarg + 2u, dumpfn, results, buf, fmt, more...);
}
} // namespace detail


template<DumperPfn dumpfn, class... Args>
C4_ALWAYS_INLINE DumpResults format_dump_resume(DumpResults results, substr buf, csubstr fmt, Args const& C4_RESTRICT ...more)
{
    return detail::format_dump_resume<dumpfn>(0u, results, buf, fmt, more...);
}

template<class DumperFn, class... Args>
C4_ALWAYS_INLINE DumpResults format_dump_resume(DumperFn &&dumpfn, DumpResults results, substr buf, csubstr fmt, Args const& C4_RESTRICT ...more)
{
    return detail::format_dump_resume(0u, dumpfn, results, buf, fmt, more...);
}


template<DumperPfn dumpfn, class... Args>
C4_ALWAYS_INLINE DumpResults format_dump_resume(substr buf, csubstr fmt, Args const& C4_RESTRICT ...more)
{
    return detail::format_dump_resume<dumpfn>(0u, DumpResults{}, buf, fmt, more...);
}

template<class DumperFn, class... Args>
C4_ALWAYS_INLINE DumpResults format_dump_resume(DumperFn &&dumpfn, substr buf, csubstr fmt, Args const& C4_RESTRICT ...more)
{
    return detail::format_dump_resume(0u, dumpfn, DumpResults{}, buf, fmt, more...);
}

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace c4


#endif /* C4_DUMP_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/dump.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/enum.hpp
// https://github.com/biojppm/c4core/src/c4/enum.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_ENUM_HPP_
#define _C4_ENUM_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */

//included above:
//#include <string.h>

/** @file enum.hpp utilities for enums: convert to/from string
 */


namespace c4 {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")

//! taken from http://stackoverflow.com/questions/15586163/c11-type-trait-to-differentiate-between-enum-class-and-regular-enum
template<typename Enum>
using is_scoped_enum = std::integral_constant<bool, std::is_enum<Enum>::value && !std::is_convertible<Enum, int>::value>;


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

typedef enum {
    EOFFS_NONE = 0,  ///< no offset
    EOFFS_CLS = 1,   ///< get the enum offset for the class name. @see eoffs_cls()
    EOFFS_PFX = 2,   ///< get the enum offset for the enum prefix. @see eoffs_pfx()
    _EOFFS_LAST      ///< reserved
} EnumOffsetType;


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** A simple (proxy) container for the value-name pairs of an enum type.
 * Uses linear search for finds; this could be improved for time-critical
 * code. */
template<class Enum>
class EnumSymbols
{
public:

    struct Sym
    {
        Enum value;
        const char *name;

        bool cmp(const char *s) const;
        bool cmp(const char *s, size_t len) const;

        const char *name_offs(EnumOffsetType t) const;
    };

    using const_iterator = Sym const*;

public:

    template<size_t N>
    EnumSymbols(Sym const (&p)[N]) : m_symbols(p), m_num(N) {}

    size_t size() const { return m_num; }
    bool empty() const { return m_num == 0; }

    Sym const* get(Enum v) const { auto p = find(v); C4_CHECK_MSG(p != nullptr, "could not find symbol=%zd", (std::ptrdiff_t)v); return p; }
    Sym const* get(const char *s) const { auto p = find(s); C4_CHECK_MSG(p != nullptr, "could not find symbol \"%s\"", s); return p; }
    Sym const* get(const char *s, size_t len) const { auto p = find(s, len); C4_CHECK_MSG(p != nullptr, "could not find symbol \"%.*s\"", len, s); return p; }

    Sym const* find(Enum v) const;
    Sym const* find(const char *s) const;
    Sym const* find(const char *s, size_t len) const;

    Sym const& operator[] (size_t i) const { C4_CHECK(i < m_num); return m_symbols[i]; }

    Sym const* begin() const { return m_symbols; }
    Sym const* end  () const { return m_symbols + m_num; }

private:

    Sym const* m_symbols;
    size_t const m_num;

};

//-----------------------------------------------------------------------------
/** return an EnumSymbols object for the enum type T
 *
 * @warning SPECIALIZE! This needs to be specialized for each enum
 * type. Failure to provide a specialization will cause a linker
 * error. */
template<class Enum>
EnumSymbols<Enum> const esyms();


/** return the offset for an enum symbol class. For example,
 * eoffs_cls<MyEnumClass>() would be 13=strlen("MyEnumClass::").
 *
 * With this function you can announce that the full prefix (including
 * an eventual enclosing class or C++11 enum class) is of a certain
 * length.
 *
 * @warning Needs to be specialized for each enum class type that
 * wants to use this. When no specialization is given, will return
 * 0. */
template<class Enum>
size_t eoffs_cls()
{
    return 0;
}


/** return the offset for an enum symbol prefix. This includes
 * eoffs_cls().  With this function you can announce that the full
 * prefix (including an eventual enclosing class or C++11 enum class
 * plus the string prefix) is of a certain length.
 *
 * @warning Needs to be specialized for each enum class type that
 * wants to use this. When no specialization is given, will return
 * 0. */
template<class Enum>
size_t eoffs_pfx()
{
    return 0;
}


template<class Enum>
size_t eoffs(EnumOffsetType which)
{
    switch(which)
    {
    case EOFFS_NONE:
        return 0;
    case EOFFS_CLS:
        return eoffs_cls<Enum>();
    case EOFFS_PFX:
    {
        size_t pfx = eoffs_pfx<Enum>();
        return pfx > 0 ? pfx : eoffs_cls<Enum>();
    }
    default:
        C4_ERROR("unknown offset type %d", (int)which);
    }
}


//-----------------------------------------------------------------------------
/** get the enum value corresponding to a c-string */

#ifdef __clang__
#   pragma clang diagnostic push
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   if __GNUC__ >= 6
#       pragma GCC diagnostic ignored "-Wnull-dereference"
#   endif
#endif

template<class Enum>
Enum str2e(const char* str)
{
    auto pairs = esyms<Enum>();
    auto *p = pairs.get(str);
    C4_CHECK_MSG(p != nullptr, "no valid enum pair name for '%s'", str);
    return p->value;
}

/** get the c-string corresponding to an enum value */
template<class Enum>
const char* e2str(Enum e)
{
    auto es = esyms<Enum>();
    auto *p = es.get(e);
    C4_CHECK_MSG(p != nullptr, "no valid enum pair name");
    return p->name;
}

/** like e2str(), but add an offset. */
template<class Enum>
const char* e2stroffs(Enum e, EnumOffsetType ot=EOFFS_PFX)
{
    const char *s = e2str<Enum>(e) + eoffs<Enum>(ot);
    return s;
}

#ifdef __clang__
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif

//-----------------------------------------------------------------------------
/** Find a symbol by value. Returns nullptr when none is found */
template<class Enum>
typename EnumSymbols<Enum>::Sym const* EnumSymbols<Enum>::find(Enum v) const
{
    for(Sym const* p = this->m_symbols, *e = p+this->m_num; p < e; ++p)
        if(p->value == v)
            return p;
    return nullptr;
}

/** Find a symbol by name. Returns nullptr when none is found */
template<class Enum>
typename EnumSymbols<Enum>::Sym const* EnumSymbols<Enum>::find(const char *s) const
{
    for(Sym const* p = this->m_symbols, *e = p+this->m_num; p < e; ++p)
        if(p->cmp(s))
            return p;
    return nullptr;
}

/** Find a symbol by name. Returns nullptr when none is found */
template<class Enum>
typename EnumSymbols<Enum>::Sym const* EnumSymbols<Enum>::find(const char *s, size_t len) const
{
    for(Sym const* p = this->m_symbols, *e = p+this->m_num; p < e; ++p)
        if(p->cmp(s, len))
            return p;
    return nullptr;
}

//-----------------------------------------------------------------------------
template<class Enum>
bool EnumSymbols<Enum>::Sym::cmp(const char *s) const
{
    if(strcmp(name, s) == 0)
        return true;

    for(int i = 1; i < _EOFFS_LAST; ++i)
    {
        auto o = eoffs<Enum>((EnumOffsetType)i);
        if(o > 0)
            if(strcmp(name + o, s) == 0)
                return true;
    }

    return false;
}

template<class Enum>
bool EnumSymbols<Enum>::Sym::cmp(const char *s, size_t len) const
{
    if(strncmp(name, s, len) == 0)
        return true;

    size_t nlen = 0;
    for(int i = 1; i <_EOFFS_LAST; ++i)
    {
        auto o = eoffs<Enum>((EnumOffsetType)i);
        if(o > 0)
        {
            if(!nlen)
            {
                nlen = strlen(name);
            }
            C4_ASSERT(o < nlen);
            size_t rem = nlen - o;
            auto m = len > rem ? len : rem;
            if(len >= m && strncmp(name + o, s, m) == 0)
                return true;
        }
    }

    return false;
}

//-----------------------------------------------------------------------------
template<class Enum>
const char* EnumSymbols<Enum>::Sym::name_offs(EnumOffsetType t) const
{
    C4_ASSERT(eoffs<Enum>(t) < strlen(name));
    return name + eoffs<Enum>(t);
}

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace c4

#endif // _C4_ENUM_HPP_


// (end https://github.com/biojppm/c4core/src/c4/enum.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/bitmask.hpp
// https://github.com/biojppm/c4core/src/c4/bitmask.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_BITMASK_HPP_
#define _C4_BITMASK_HPP_

/** @file bitmask.hpp bitmask utilities */

//included above:
//#include <cstring>
//included above:
//#include <type_traits>

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/enum.hpp
//#include "c4/enum.hpp"
#if !defined(C4_ENUM_HPP_) && !defined(_C4_ENUM_HPP_)
#error "amalgamate: file c4/enum.hpp must have been included at this point"
#endif /* C4_ENUM_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/format.hpp
//#include "c4/format.hpp"
#if !defined(C4_FORMAT_HPP_) && !defined(_C4_FORMAT_HPP_)
#error "amalgamate: file c4/format.hpp must have been included at this point"
#endif /* C4_FORMAT_HPP_ */


#if defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable : 4996) // 'strncpy', fopen, etc: This function or variable may be unsafe
#endif

#if defined(__clang__)
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wold-style-cast"
#   if __GNUC__ >= 8
#       pragma GCC diagnostic ignored "-Wstringop-truncation"
#       pragma GCC diagnostic ignored "-Wstringop-overflow"
#   endif
#endif

namespace c4 {

//-----------------------------------------------------------------------------
/** write a bitmask to a stream, formatted as a string */

template<class Enum, class Stream>
Stream& bm2stream(Stream &s, typename std::underlying_type<Enum>::type bits, EnumOffsetType offst=EOFFS_PFX)
{
    using I = typename std::underlying_type<Enum>::type;
    bool written = false;

    auto const& pairs = esyms<Enum>();

    // write non null value
    if(bits)
    {
        // do reverse iteration to give preference to composite enum symbols,
        // which are likely to appear at the end of the enum sequence
        for(size_t i = pairs.size() - 1; i != size_t(-1); --i)
        {
            auto p = pairs[i];
            I b(static_cast<I>(p.value));
            if(b && (bits & b) == b)
            {
                if(written) s << '|'; // append bit-or character
                written = true;
                s << p.name_offs(offst); // append bit string
                bits &= ~b;
            }
        }
        return s;
    }
    else
    {
        // write a null value
        for(size_t i = pairs.size() - 1; i != size_t(-1); --i)
        {
            auto p = pairs[i];
            I b(static_cast<I>(p.value));
            if(b == 0)
            {
                s << p.name_offs(offst);
                written = true;
                break;
            }
        }
    }
    if(!written)
    {
        s << '0';
    }
    return s;
}

template<class Enum, class Stream>
typename std::enable_if<is_scoped_enum<Enum>::value, Stream&>::type
bm2stream(Stream &s, Enum value, EnumOffsetType offst=EOFFS_PFX)
{
    using I = typename std::underlying_type<Enum>::type;
    return bm2stream<Enum>(s, static_cast<I>(value), offst);
}


//-----------------------------------------------------------------------------

// some utility macros, undefed below

/// @cond dev

/* Execute `code` if the `num` of characters is available in the str
 * buffer. This macro simplifies the code for bm2str().
 * @todo improve performance by writing from the end and moving only once. */
#define _c4prependchars(code, num)                                      \
    if(str && (pos + num <= sz))                                        \
    {                                                                   \
        /* move the current string to the right */                      \
        memmove(str + num, str, pos);                                   \
        /* now write in the beginning of the string */                  \
        code;                                                           \
    }                                                                   \
    else if(str && sz)                                                  \
    {                                                                   \
        C4_ERROR("cannot write to string pos=%d num=%d sz=%d",          \
                 (int)pos, (int)num, (int)sz);                          \
    }                                                                   \
    pos += num

/* Execute `code` if the `num` of characters is available in the str
 * buffer. This macro simplifies the code for bm2str(). */
#define _c4appendchars(code, num)                                       \
    if(str && (pos + num <= sz))                                        \
    {                                                                   \
        code;                                                           \
    }                                                                   \
    else if(str && sz)                                                  \
    {                                                                   \
        C4_ERROR("cannot write to string pos=%d num=%d sz=%d",          \
                 (int)pos, (int)num, (int)sz);                          \
    }                                                                   \
    pos += num

/// @endcond


/** convert a bitmask to string.
 * return the number of characters written. To find the needed size,
 * call first with str=nullptr and sz=0 */
template<class Enum>
size_t bm2str
(
    typename std::underlying_type<Enum>::type bits,
    char *str=nullptr,
    size_t sz=0,
    EnumOffsetType offst=EOFFS_PFX
)
{
    using I = typename std::underlying_type<Enum>::type;
    C4_ASSERT((str == nullptr) == (sz == 0));

    auto syms = esyms<Enum>();
    size_t pos = 0;
    typename EnumSymbols<Enum>::Sym const* C4_RESTRICT zero = nullptr;

    // do reverse iteration to give preference to composite enum symbols,
    // which are likely to appear later in the enum sequence
    for(size_t i = syms.size()-1; i != size_t(-1); --i)
    {
        auto const &C4_RESTRICT p = syms[i]; // do not copy, we are assigning to `zero`
        I b = static_cast<I>(p.value);
        if(b == 0)
        {
            zero = &p; // save this symbol for later
        }
        else if((bits & b) == b)
        {
            bits &= ~b;
            // append bit-or character
            if(pos > 0)
            {
                _c4prependchars(*str = '|', 1);
            }
            // append bit string
            const char *pname = p.name_offs(offst);
            size_t len = strlen(pname);
            _c4prependchars(strncpy(str, pname, len), len);
        }
    }

    C4_CHECK_MSG(bits == 0, "could not find all bits");
    if(pos == 0) // make sure at least something is written
    {
        if(zero) // if we have a zero symbol, use that
        {
            const char *pname = zero->name_offs(offst);
            size_t len = strlen(pname);
            _c4prependchars(strncpy(str, pname, len), len);
        }
        else // otherwise just write an integer zero
        {
            _c4prependchars(*str = '0', 1);
        }
    }
    _c4appendchars(str[pos] = '\0', 1);

    return pos;
}


// cleanup!
#undef _c4appendchars
#undef _c4prependchars


/** scoped enums do not convert automatically to their underlying type,
 * so this SFINAE overload will accept scoped enum symbols and cast them
 * to the underlying type */
template<class Enum>
typename std::enable_if<is_scoped_enum<Enum>::value, size_t>::type
bm2str
(
    Enum bits,
    char *str=nullptr,
    size_t sz=0,
    EnumOffsetType offst=EOFFS_PFX
)
{
    using I = typename std::underlying_type<Enum>::type;
    return bm2str<Enum>(static_cast<I>(bits), str, sz, offst);
}


//-----------------------------------------------------------------------------

namespace detail {

#ifdef __clang__
#   pragma clang diagnostic push
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   if __GNUC__ >= 6
#       pragma GCC diagnostic ignored "-Wnull-dereference"
#   endif
#endif

template<class Enum>
typename std::underlying_type<Enum>::type str2bm_read_one(const char *str, size_t sz, bool alnum)
{
    using I = typename std::underlying_type<Enum>::type;
    auto pairs = esyms<Enum>();
    if(alnum)
    {
        auto *p = pairs.find(str, sz);
        C4_CHECK_MSG(p != nullptr, "no valid enum pair name for '%.*s'", (int)sz, str);
        return static_cast<I>(p->value);
    }
    I tmp{0};
    size_t len = uncat(csubstr(str, sz), tmp);
    C4_CHECK_MSG(len != csubstr::npos, "could not read string as an integral type: '%.*s'", (int)sz, str);
    return tmp;
}

#ifdef __clang__
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif
} // namespace detail

/** convert a string to a bitmask */
template<class Enum>
typename std::underlying_type<Enum>::type str2bm(const char *str, size_t sz)
{
    using I = typename std::underlying_type<Enum>::type;

    I val = 0;
    bool started = false;
    bool alnum = false, num = false;
    const char *f = nullptr, *pc = str;
    for( ; pc < str+sz; ++pc)
    {
        const char c = *pc;
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
        {
            C4_CHECK(( ! num) || ((pc - f) == 1 && (c == 'x' || c == 'X'))); // accept hexadecimal numbers
            if( ! started)
            {
                f = pc;
                alnum = started = true;
            }
        }
        else if(c >= '0' && c <= '9')
        {
            C4_CHECK( ! alnum);
            if(!started)
            {
                f = pc;
                num = started = true;
            }
        }
        else if(c == ':' || c == ' ')
        {
            // skip this char
        }
        else if(c == '|' || c == '\0')
        {
            C4_ASSERT(num != alnum);
            C4_ASSERT(pc >= f);
            val |= detail::str2bm_read_one<Enum>(f, static_cast<size_t>(pc-f), alnum);
            started = num = alnum = false;
            if(c == '\0')
            {
                return val;
            }
        }
        else
        {
            C4_ERROR("bad character '%c' in bitmask string", c);
        }
    }

    if(f)
    {
        C4_ASSERT(num != alnum);
        C4_ASSERT(pc >= f);
        val |= detail::str2bm_read_one<Enum>(f, static_cast<size_t>(pc-f), alnum);
    }

    return val;
}

/** convert a string to a bitmask */
template<class Enum>
typename std::underlying_type<Enum>::type str2bm(const char *str)
{
    return str2bm<Enum>(str, strlen(str));
}

} // namespace c4

#ifdef _MSC_VER
#   pragma warning(pop)
#endif

#if defined(__clang__)
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif

#endif // _C4_BITMASK_HPP_


// (end https://github.com/biojppm/c4core/src/c4/bitmask.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/span.hpp
// https://github.com/biojppm/c4core/src/c4/span.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_SPAN_HPP_
#define _C4_SPAN_HPP_

/** @file span.hpp Provides span classes. */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/config.hpp
//#include "c4/config.hpp"
#if !defined(C4_CONFIG_HPP_) && !defined(_C4_CONFIG_HPP_)
#error "amalgamate: file c4/config.hpp must have been included at this point"
#endif /* C4_CONFIG_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/szconv.hpp
//#include "c4/szconv.hpp"
#if !defined(C4_SZCONV_HPP_) && !defined(_C4_SZCONV_HPP_)
#error "amalgamate: file c4/szconv.hpp must have been included at this point"
#endif /* C4_SZCONV_HPP_ */


//included above:
//#include <algorithm>

namespace c4 {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** a crtp base for implementing span classes
 *
 * A span is a non-owning range of elements contiguously stored in memory.
 * Unlike STL's array_view, the span allows write-access to its members.
 *
 * To obtain subspans from a span, the following const member functions
 * are available:
 *  - subspan(first, num)
 *  - range(first, last)
 *  - first(num)
 *  - last(num)
 *
 * A span can also be resized via the following non-const member functions:
 *  - resize(sz)
 *  - ltrim(num)
 *  - rtrim(num)
 *
 * @see span
 * @see cspan
 * @see spanrs
 * @see cspanrs
 * @see spanrsl
 * @see cspanrsl
 */
template<class T, class I, class SpanImpl>
class span_crtp
{
// some utility defines, undefined at the end of this class
#define _c4this  ((SpanImpl      *)this)
#define _c4cthis ((SpanImpl const*)this)
#define _c4ptr   ((SpanImpl      *)this)->m_ptr
#define _c4cptr  ((SpanImpl const*)this)->m_ptr
#define _c4sz    ((SpanImpl      *)this)->m_size
#define _c4csz   ((SpanImpl const*)this)->m_size

public:

    _c4_DEFINE_ARRAY_TYPES(T, I);

public:

    C4_ALWAYS_INLINE constexpr I value_size() const noexcept { return sizeof(T); }
    C4_ALWAYS_INLINE constexpr I elm_size  () const noexcept { return sizeof(T); }
    C4_ALWAYS_INLINE constexpr I type_size () const noexcept { return sizeof(T); }
    C4_ALWAYS_INLINE           I byte_size () const noexcept { return _c4csz*sizeof(T); }

    C4_ALWAYS_INLINE bool empty()    const noexcept { return _c4csz == 0; }
    C4_ALWAYS_INLINE I    size()     const noexcept { return _c4csz; }
    //C4_ALWAYS_INLINE I    capacity() const noexcept { return _c4sz; } // this must be defined by impl classes

    C4_ALWAYS_INLINE void clear() noexcept { _c4sz = 0; }

    C4_ALWAYS_INLINE T      * data()       noexcept { return _c4ptr; }
    C4_ALWAYS_INLINE T const* data() const noexcept { return _c4cptr; }

    C4_ALWAYS_INLINE       iterator  begin()       noexcept { return _c4ptr; }
    C4_ALWAYS_INLINE const_iterator  begin() const noexcept { return _c4cptr; }
    C4_ALWAYS_INLINE const_iterator cbegin() const noexcept { return _c4cptr; }

    C4_ALWAYS_INLINE       iterator  end()       noexcept { return _c4ptr  + _c4sz; }
    C4_ALWAYS_INLINE const_iterator  end() const noexcept { return _c4cptr + _c4csz; }
    C4_ALWAYS_INLINE const_iterator cend() const noexcept { return _c4cptr + _c4csz; }

    C4_ALWAYS_INLINE       reverse_iterator  rbegin()       noexcept { return reverse_iterator(_c4ptr + _c4sz); }
    C4_ALWAYS_INLINE const_reverse_iterator  rbegin() const noexcept { return reverse_iterator(_c4cptr + _c4csz); }
    C4_ALWAYS_INLINE const_reverse_iterator crbegin() const noexcept { return reverse_iterator(_c4cptr + _c4csz); }

    C4_ALWAYS_INLINE       reverse_iterator  rend()       noexcept { return const_reverse_iterator(_c4ptr); }
    C4_ALWAYS_INLINE const_reverse_iterator  rend() const noexcept { return const_reverse_iterator(_c4cptr); }
    C4_ALWAYS_INLINE const_reverse_iterator crend() const noexcept { return const_reverse_iterator(_c4cptr); }

    C4_ALWAYS_INLINE T      & front()       C4_NOEXCEPT_X { C4_XASSERT(!empty()); return _c4ptr [0]; }
    C4_ALWAYS_INLINE T const& front() const C4_NOEXCEPT_X { C4_XASSERT(!empty()); return _c4cptr[0]; }

    C4_ALWAYS_INLINE T      & back()       C4_NOEXCEPT_X { C4_XASSERT(!empty()); return _c4ptr [_c4sz  - 1]; }
    C4_ALWAYS_INLINE T const& back() const C4_NOEXCEPT_X { C4_XASSERT(!empty()); return _c4cptr[_c4csz - 1]; }

    C4_ALWAYS_INLINE T      & operator[] (I i)       C4_NOEXCEPT_X { C4_XASSERT(i >= 0 && i < _c4sz ); return _c4ptr [i]; }
    C4_ALWAYS_INLINE T const& operator[] (I i) const C4_NOEXCEPT_X { C4_XASSERT(i >= 0 && i < _c4csz); return _c4cptr[i]; }

    C4_ALWAYS_INLINE SpanImpl subspan(I first, I num) const C4_NOEXCEPT_X
    {
        C4_XASSERT((first >= 0 && first < _c4csz) || (first == _c4csz && num == 0));
        C4_XASSERT((first + num >= 0) && (first + num <= _c4csz));
        return _c4cthis->_select(_c4cptr + first, num);
    }
    C4_ALWAYS_INLINE SpanImpl subspan(I first) const C4_NOEXCEPT_X ///< goes up until the end of the span
    {
        C4_XASSERT(first >= 0 && first <= _c4csz);
        return _c4cthis->_select(_c4cptr + first, _c4csz - first);
    }

    C4_ALWAYS_INLINE SpanImpl range(I first, I last) const C4_NOEXCEPT_X ///< last element is NOT included
    {
        C4_XASSERT(((first >= 0) && (first < _c4csz)) || (first == _c4csz && first == last));
        C4_XASSERT((last >= 0) && (last <= _c4csz));
        C4_XASSERT(last >= first);
        return _c4cthis->_select(_c4cptr + first, last - first);
    }
    C4_ALWAYS_INLINE SpanImpl range(I first) const C4_NOEXCEPT_X ///< goes up until the end of the span
    {
        C4_XASSERT(((first >= 0) && (first <= _c4csz)));
        return _c4cthis->_select(_c4cptr + first, _c4csz - first);
    }

    C4_ALWAYS_INLINE SpanImpl first(I num) const C4_NOEXCEPT_X ///< get the first num elements, starting at 0
    {
        C4_XASSERT((num >= 0) && (num <= _c4csz));
        return _c4cthis->_select(_c4cptr, num);
    }
    C4_ALWAYS_INLINE SpanImpl last(I num) const C4_NOEXCEPT_X ///< get the last num elements, starting at size()-num
    {
        C4_XASSERT((num >= 0) && (num <= _c4csz));
        return _c4cthis->_select(_c4cptr + _c4csz - num, num);
    }

    bool is_subspan(span_crtp const& ss) const noexcept
    {
        if(_c4cptr == nullptr) return false;
        auto *b = begin(), *e = end();
        auto *ssb = ss.begin(), *sse = ss.end();
        if(ssb >= b && sse <= e)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /** COMPLement Left: return the complement to the left of the beginning of the given subspan.
     * If ss does not begin inside this, returns an empty substring. */
    SpanImpl compll(span_crtp const& ss) const C4_NOEXCEPT_X
    {
        auto ssb = ss.begin();
        auto b = begin();
        auto e = end();
        if(ssb >= b && ssb <= e)
        {
            return subspan(0, static_cast<size_t>(ssb - b));
        }
        else
        {
            return subspan(0, 0);
        }
    }

    /** COMPLement Right: return the complement to the right of the end of the given subspan.
     * If ss does not end inside this, returns an empty substring. */
    SpanImpl complr(span_crtp const& ss) const C4_NOEXCEPT_X
    {
        auto sse = ss.end();
        auto b = begin();
        auto e = end();
        if(sse >= b && sse <= e)
        {
            return subspan(static_cast<size_t>(sse - b), static_cast<size_t>(e - sse));
        }
        else
        {
            return subspan(0, 0);
        }
    }

    C4_ALWAYS_INLINE bool same_span(span_crtp const& that) const noexcept
    {
        return size() == that.size() && data() == that.data();
    }
    template<class I2, class Impl2>
    C4_ALWAYS_INLINE bool same_span(span_crtp<T, I2, Impl2> const& that) const C4_NOEXCEPT_X
    {
        I tsz = szconv<I>(that.size()); // x-asserts that the size does not overflow
        return size() == tsz && data() == that.data();
    }

#undef _c4this
#undef _c4cthis
#undef _c4ptr
#undef _c4cptr
#undef _c4sz
#undef _c4csz
};

//-----------------------------------------------------------------------------
template<class T, class Il, class Ir, class _Impll, class _Implr>
inline constexpr bool operator==
(
    span_crtp<T, Il, _Impll> const& l,
    span_crtp<T, Ir, _Implr> const& r
)
{
#if C4_CPP >= 14
    return std::equal(l.begin(), l.end(), r.begin(), r.end());
#else
    return l.same_span(r) || std::equal(l.begin(), l.end(), r.begin());
#endif
}

template<class T, class Il, class Ir, class _Impll, class _Implr>
inline constexpr bool operator!=
(
    span_crtp<T, Il, _Impll> const& l,
    span_crtp<T, Ir, _Implr> const& r
)
{
    return ! (l == r);
}

//-----------------------------------------------------------------------------
template<class T, class Il, class Ir, class _Impll, class _Implr>
inline constexpr bool operator<
(
    span_crtp<T, Il, _Impll> const& l,
    span_crtp<T, Ir, _Implr> const& r
)
{
    return std::lexicographical_compare(l.begin(), l.end(), r.begin(), r.end());
}

template<class T, class Il, class Ir, class _Impll, class _Implr>
inline constexpr bool operator<=
(
    span_crtp<T, Il, _Impll> const& l,
    span_crtp<T, Ir, _Implr> const& r
)
{
    return ! (l > r);
}

//-----------------------------------------------------------------------------
template<class T, class Il, class Ir, class _Impll, class _Implr>
inline constexpr bool operator>
(
    span_crtp<T, Il, _Impll> const& l,
    span_crtp<T, Ir, _Implr> const& r
)
{
    return r < l;
}

//-----------------------------------------------------------------------------
template<class T, class Il, class Ir, class _Impll, class _Implr>
inline constexpr bool operator>=
(
    span_crtp<T, Il, _Impll> const& l,
    span_crtp<T, Ir, _Implr> const& r
)
{
    return ! (l < r);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** A non-owning span of elements contiguously stored in memory. */
template<class T, class I=C4_SIZE_TYPE>
class span : public span_crtp<T, I, span<T, I>>
{
    friend class span_crtp<T, I, span<T, I>>;

    T * C4_RESTRICT m_ptr;
    I   m_size;

    C4_ALWAYS_INLINE span _select(T *p, I sz) const { return span(p, sz); }

public:

    _c4_DEFINE_ARRAY_TYPES(T, I);
    using NCT = typename std::remove_const<T>::type; //!< NCT=non const type
    using CT = typename std::add_const<T>::type; //!< CT=const type
    using const_type = span<CT, I>;

    /// convert automatically to span of const T
    operator span<CT, I> () const { span<CT, I> s(m_ptr, m_size); return s; }

public:

    C4_ALWAYS_INLINE C4_CONSTEXPR14 span() noexcept : m_ptr{nullptr}, m_size{0} {}

    span(span const&) = default;
    span(span     &&) = default;

    span& operator= (span const&) = default;
    span& operator= (span     &&) = default;

public:

    /** @name Construction and assignment from same type */
    /** @{ */

    template<size_t N> C4_ALWAYS_INLINE C4_CONSTEXPR14      span  (T (&arr)[N]) noexcept : m_ptr{arr}, m_size{N} {}
    template<size_t N> C4_ALWAYS_INLINE C4_CONSTEXPR14 void assign(T (&arr)[N]) noexcept { m_ptr = arr; m_size = N; }

    C4_ALWAYS_INLINE C4_CONSTEXPR14        span(T *p, I sz) noexcept : m_ptr{p}, m_size{sz} {}
    C4_ALWAYS_INLINE C4_CONSTEXPR14 void   assign(T *p, I sz) noexcept { m_ptr = p; m_size = sz; }

    C4_ALWAYS_INLINE C4_CONSTEXPR14      span  (c4::aggregate_t, std::initializer_list<T> il) noexcept : m_ptr{&*il.begin()}, m_size{il.size()} {}
    C4_ALWAYS_INLINE C4_CONSTEXPR14 void assign(c4::aggregate_t, std::initializer_list<T> il) noexcept { m_ptr = &*il.begin(); m_size = il.size(); }

    /** @} */

public:

    C4_ALWAYS_INLINE I capacity() const noexcept { return m_size; }

    C4_ALWAYS_INLINE void resize(I sz) C4_NOEXCEPT_A { C4_ASSERT(sz <= m_size); m_size = sz; }
    C4_ALWAYS_INLINE void rtrim (I n ) C4_NOEXCEPT_A { C4_ASSERT(n >= 0 && n < m_size); m_size -= n; }
    C4_ALWAYS_INLINE void ltrim (I n ) C4_NOEXCEPT_A { C4_ASSERT(n >= 0 && n < m_size); m_size -= n; m_ptr += n; }

};
template<class T, class I=C4_SIZE_TYPE> using cspan = span<const T, I>;


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** A non-owning span resizeable up to a capacity. Subselection or resizing
 * will keep the original provided it starts at begin(). If subselection or
 * resizing change the pointer, then the original capacity information will
 * be lost.
 *
 * Thus, resizing via resize() and ltrim() and subselecting via first()
 * or any of subspan() or range() when starting from the beginning will keep
 * the original capacity. OTOH, using last(), or any of subspan() or range()
 * with an offset from the start will remove from capacity (shifting the
 * pointer) by the corresponding offset. If this is undesired, then consider
 * using spanrsl.
 *
 * @see spanrs for a span resizeable on the right
 * @see spanrsl for a span resizeable on the right and left
 */

template<class T, class I=C4_SIZE_TYPE>
class spanrs : public span_crtp<T, I, spanrs<T, I>>
{
    friend class span_crtp<T, I, spanrs<T, I>>;

    T * C4_RESTRICT m_ptr;
    I   m_size;
    I   m_capacity;

    C4_ALWAYS_INLINE spanrs _select(T *p, I sz) const noexcept
    {
        C4_ASSERT(p >= m_ptr);
        size_t delta = static_cast<size_t>(p - m_ptr);
        C4_ASSERT(m_capacity >= delta);
        return spanrs(p, sz, static_cast<size_t>(m_capacity - delta));
    }

public:

    _c4_DEFINE_ARRAY_TYPES(T, I);
    using NCT = typename std::remove_const<T>::type; //!< NCT=non const type
    using CT = typename std::add_const<T>::type; //!< CT=const type
    using const_type = spanrs<CT, I>;

    /// convert automatically to span of T
    C4_ALWAYS_INLINE operator span<T, I > () const noexcept { return span<T, I>(m_ptr, m_size); }
    /// convert automatically to span of const T
    //C4_ALWAYS_INLINE operator span<CT, I> () const noexcept { span<CT, I> s(m_ptr, m_size); return s; }
    /// convert automatically to spanrs of const T
    C4_ALWAYS_INLINE operator spanrs<CT, I> () const noexcept { spanrs<CT, I> s(m_ptr, m_size, m_capacity); return s; }

public:

    C4_ALWAYS_INLINE spanrs() noexcept : m_ptr{nullptr}, m_size{0}, m_capacity{0} {}

    spanrs(spanrs const&) = default;
    spanrs(spanrs     &&) = default;

    spanrs& operator= (spanrs const&) = default;
    spanrs& operator= (spanrs     &&) = default;

public:

    /** @name Construction and assignment from same type */
    /** @{ */

    C4_ALWAYS_INLINE      spanrs(T *p, I sz) noexcept : m_ptr{p}, m_size{sz}, m_capacity{sz} {}
    /** @warning will reset the capacity to sz */
    C4_ALWAYS_INLINE void assign(T *p, I sz) noexcept { m_ptr = p; m_size = sz; m_capacity = sz; }

    C4_ALWAYS_INLINE      spanrs(T *p, I sz, I cap) noexcept : m_ptr{p}, m_size{sz}, m_capacity{cap} {}
    C4_ALWAYS_INLINE void assign(T *p, I sz, I cap) noexcept { m_ptr = p; m_size = sz; m_capacity = cap; }

    template<size_t N> C4_ALWAYS_INLINE      spanrs(T (&arr)[N]) noexcept : m_ptr{arr}, m_size{N}, m_capacity{N} {}
    template<size_t N> C4_ALWAYS_INLINE void assign(T (&arr)[N]) noexcept { m_ptr = arr; m_size = N; m_capacity = N; }

    C4_ALWAYS_INLINE      spanrs(c4::aggregate_t, std::initializer_list<T> il) noexcept : m_ptr{il.begin()}, m_size{il.size()}, m_capacity{il.size()} {}
    C4_ALWAYS_INLINE void assign(c4::aggregate_t, std::initializer_list<T> il) noexcept { m_ptr = il.begin(); m_size = il.size(); m_capacity = il.size(); }

    /** @} */

public:

    C4_ALWAYS_INLINE I capacity() const noexcept { return m_capacity; }

    C4_ALWAYS_INLINE void resize(I sz) C4_NOEXCEPT_A { C4_ASSERT(sz <= m_capacity); m_size = sz; }
    C4_ALWAYS_INLINE void rtrim (I n ) C4_NOEXCEPT_A { C4_ASSERT(n >= 0 && n < m_size); m_size -= n; }
    C4_ALWAYS_INLINE void ltrim (I n ) C4_NOEXCEPT_A { C4_ASSERT(n >= 0 && n < m_size); m_size -= n; m_ptr += n; m_capacity -= n; }

};
template<class T, class I=C4_SIZE_TYPE> using cspanrs = spanrs<const T, I>;


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** A non-owning span which always retains the capacity of the original
 * range it was taken from (though it may loose its original size).
 * The resizing methods resize(), ltrim(), rtrim() as well
 * as the subselection methods subspan(), range(), first() and last() can be
 * used at will without loosing the original capacity; the full capacity span
 * can always be recovered by calling original().
 */
template<class T, class I=C4_SIZE_TYPE>
class spanrsl : public span_crtp<T, I, spanrsl<T, I>>
{
    friend class span_crtp<T, I, spanrsl<T, I>>;

    T *C4_RESTRICT m_ptr;      ///< the current ptr. the original ptr is (m_ptr - m_offset).
    I   m_size;     ///< the current size. the original size is unrecoverable.
    I   m_capacity; ///< the current capacity. the original capacity is (m_capacity + m_offset).
    I   m_offset;   ///< the offset of the current m_ptr to the start of the original memory block.

    C4_ALWAYS_INLINE spanrsl _select(T *p, I sz) const noexcept
    {
        C4_ASSERT(p >= m_ptr);
        I delta = static_cast<I>(p - m_ptr);
        C4_ASSERT(m_capacity >= delta);
        return spanrsl(p, sz, static_cast<I>(m_capacity - delta), m_offset + delta);
    }

public:

    _c4_DEFINE_ARRAY_TYPES(T, I);
    using NCT = typename std::remove_const<T>::type; //!< NCT=non const type
    using CT = typename std::add_const<T>::type; //!< CT=const type
    using const_type = spanrsl<CT, I>;

    C4_ALWAYS_INLINE operator span<T, I> () const noexcept { return span<T, I>(m_ptr, m_size); }
    C4_ALWAYS_INLINE operator spanrs<T, I> () const noexcept { return spanrs<T, I>(m_ptr, m_size, m_capacity); }
    C4_ALWAYS_INLINE operator spanrsl<CT, I> () const noexcept { return spanrsl<CT, I>(m_ptr, m_size, m_capacity, m_offset); }

public:

    C4_ALWAYS_INLINE spanrsl() noexcept : m_ptr{nullptr}, m_size{0}, m_capacity{0}, m_offset{0} {}

    spanrsl(spanrsl const&) = default;
    spanrsl(spanrsl     &&) = default;

    spanrsl& operator= (spanrsl const&) = default;
    spanrsl& operator= (spanrsl     &&) = default;

public:

    C4_ALWAYS_INLINE     spanrsl(T *p, I sz) noexcept : m_ptr{p}, m_size{sz}, m_capacity{sz}, m_offset{0} {}
    C4_ALWAYS_INLINE void assign(T *p, I sz) noexcept { m_ptr = p; m_size = sz; m_capacity = sz; m_offset = 0; }

    C4_ALWAYS_INLINE     spanrsl(T *p, I sz, I cap) noexcept : m_ptr{p}, m_size{sz}, m_capacity{cap}, m_offset{0} {}
    C4_ALWAYS_INLINE void assign(T *p, I sz, I cap) noexcept { m_ptr = p; m_size = sz; m_capacity = cap; m_offset = 0; }

    C4_ALWAYS_INLINE     spanrsl(T *p, I sz, I cap, I offs) noexcept : m_ptr{p}, m_size{sz}, m_capacity{cap}, m_offset{offs} {}
    C4_ALWAYS_INLINE void assign(T *p, I sz, I cap, I offs) noexcept { m_ptr = p; m_size = sz; m_capacity = cap; m_offset = offs; }

    template<size_t N> C4_ALWAYS_INLINE     spanrsl(T (&arr)[N]) noexcept : m_ptr{arr}, m_size{N}, m_capacity{N}, m_offset{0} {}
    template<size_t N> C4_ALWAYS_INLINE void assign(T (&arr)[N]) noexcept { m_ptr = arr; m_size = N; m_capacity = N; m_offset = 0; }

    C4_ALWAYS_INLINE      spanrsl(c4::aggregate_t, std::initializer_list<T> il) noexcept : m_ptr{il.begin()}, m_size{il.size()}, m_capacity{il.size()}, m_offset{0} {}
    C4_ALWAYS_INLINE void assign (c4::aggregate_t, std::initializer_list<T> il) noexcept { m_ptr = il.begin(); m_size = il.size(); m_capacity = il.size(); m_offset = 0; }

public:

    C4_ALWAYS_INLINE I offset() const noexcept { return m_offset; }
    C4_ALWAYS_INLINE I capacity() const noexcept { return m_capacity; }

    C4_ALWAYS_INLINE void resize(I sz) C4_NOEXCEPT_A { C4_ASSERT(sz <= m_capacity); m_size = sz; }
    C4_ALWAYS_INLINE void rtrim (I n ) C4_NOEXCEPT_A { C4_ASSERT(n >= 0 && n < m_size); m_size -= n; }
    C4_ALWAYS_INLINE void ltrim (I n ) C4_NOEXCEPT_A { C4_ASSERT(n >= 0 && n < m_size); m_size -= n; m_ptr += n; m_offset += n; m_capacity -= n; }

    /** recover the original span as an spanrsl */
    C4_ALWAYS_INLINE spanrsl original() const
    {
        return spanrsl(m_ptr - m_offset, m_capacity + m_offset, m_capacity + m_offset, 0);
    }
    /** recover the original span as a different span type. Example: spanrs<...> orig = s.original<spanrs>(); */
    template<template<class, class> class OtherSpanType>
    C4_ALWAYS_INLINE OtherSpanType<T, I> original()
    {
        return OtherSpanType<T, I>(m_ptr - m_offset, m_capacity + m_offset);
    }
};
template<class T, class I=C4_SIZE_TYPE> using cspanrsl = spanrsl<const T, I>;

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace c4


#endif /* _C4_SPAN_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/span.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/type_name.hpp
// https://github.com/biojppm/c4core/src/c4/type_name.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_TYPENAME_HPP_
#define _C4_TYPENAME_HPP_

/** @file type_name.hpp compile-time type name */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/span.hpp
//#include "c4/span.hpp"
#if !defined(C4_SPAN_HPP_) && !defined(_C4_SPAN_HPP_)
#error "amalgamate: file c4/span.hpp must have been included at this point"
#endif /* C4_SPAN_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/compiler.hpp
//#include "c4/compiler.hpp"
#if !defined(C4_COMPILER_HPP_) && !defined(_C4_COMPILER_HPP_)
#error "amalgamate: file c4/compiler.hpp must have been included at this point"
#endif /* C4_COMPILER_HPP_ */


/// @cond dev
struct _c4t
{
    const char *str;
    size_t sz;
    template<size_t N>
    constexpr _c4t(const char (&s)[N]) : str(s), sz(N-1) {} // take off the \0
};
// this is a more abbreviated way of getting the type name
// (if we used span in the return type, the name would involve
// templates and would create longer type name strings,
// as well as larger differences between compilers)
template<class T>
C4_CONSTEXPR14 C4_ALWAYS_INLINE
_c4t _c4tn()
{
    auto p = _c4t(C4_PRETTY_FUNC);
    return p;
}
/// @endcond


namespace c4 {

/** compile-time type name
 * @see http://stackoverflow.com/a/20170989/5875572 */
template<class T>
C4_CONSTEXPR14 cspan<char> type_name()
{
    const _c4t p = _c4tn<T>();

#if (0) // enable this to debug and find the offsets
    for(size_t index = 0; index < p.sz; ++index)
        printf(" %2c", p.str[index]);
    printf("\n");
    for(size_t index = 0; index < p.sz; ++index)
        printf(" %2zu", index);
    printf("\n");
#endif

#if defined(_MSC_VER)
#   if defined(__clang__) // Visual Studio has the clang toolset
#   if (_MSC_VER >= 1930) // do not use this: defined(C4_MSVC_2022)
    // ..............................xxx.
    // _c4t __cdecl _c4tn(void) [T = int]
    enum : size_t { tstart = 30, tend = 1};
#   else
    // example:
    // ..........................xxx.
    // _c4t __cdecl _c4tn() [T = int]
    enum : size_t { tstart = 26, tend = 1};
#   endif
#   elif defined(C4_MSVC_2015) || defined(C4_MSVC_2017) || defined(C4_MSVC_2019) || defined(C4_MSVC_2022)
    // Note: subtract 7 at the end because the function terminates with ">(void)" in VS2015+
    cspan<char>::size_type tstart = 26, tend = 7;

    const char *C4_RESTRICT s = p.str + tstart; // look at the start

    // we're not using strcmp() or memcmp() to spare the #include

    // does it start with 'class '?
    if(p.sz > 6 && s[0] == 'c' && s[1] == 'l' && s[2] == 'a' && s[3] == 's' && s[4] == 's' && s[5] == ' ')
    {
        tstart += 6;
    }
    // does it start with 'struct '?
    else if(p.sz > 7 && s[0] == 's' && s[1] == 't' && s[2] == 'r' && s[3] == 'u' && s[4] == 'c' && s[5] == 't' && s[6] == ' ')
    {
        tstart += 7;
    }

#   else
    C4_NOT_IMPLEMENTED();
#   endif

#elif defined(__ICC)
    // example:
    // ........................xxx.
    // "_c4t _c4tn() [with T = int]"
    enum : size_t { tstart = 23, tend = 1};

#elif defined(__clang__)
    // example:
    // ...................xxx.
    // "_c4t _c4tn() [T = int]"
    enum : size_t { tstart = 18, tend = 1};

#elif defined(__GNUC__)
    #if __GNUC__ >= 7 && C4_CPP >= 14
        // example:
        // ..................................xxx.
        // "constexpr _c4t _c4tn() [with T = int]"
        enum : size_t { tstart = 33, tend = 1 };
    #else
        // example:
        // ........................xxx.
        // "_c4t _c4tn() [with T = int]"
        enum : size_t { tstart = 23, tend = 1 };
    #endif
#else
    C4_NOT_IMPLEMENTED();
#endif

    cspan<char> o(p.str + tstart, p.sz - tstart - tend);

    return o;
}

/** compile-time type name
 * @overload */
template<class T>
C4_CONSTEXPR14 C4_ALWAYS_INLINE cspan<char> type_name(T const&)
{
    return type_name<T>();
}

} // namespace c4

#endif //_C4_TYPENAME_HPP_


// (end https://github.com/biojppm/c4core/src/c4/type_name.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/base64.hpp
// https://github.com/biojppm/c4core/src/c4/base64.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_BASE64_HPP_
#define _C4_BASE64_HPP_

/** @file base64.hpp encoding/decoding for base64.
 * @see https://en.wikipedia.org/wiki/Base64
 * @see https://www.base64encode.org/
 * */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/charconv.hpp
//#include "c4/charconv.hpp"
#if !defined(C4_CHARCONV_HPP_) && !defined(_C4_CHARCONV_HPP_)
#error "amalgamate: file c4/charconv.hpp must have been included at this point"
#endif /* C4_CHARCONV_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/blob.hpp
//#include "c4/blob.hpp"
#if !defined(C4_BLOB_HPP_) && !defined(_C4_BLOB_HPP_)
#error "amalgamate: file c4/blob.hpp must have been included at this point"
#endif /* C4_BLOB_HPP_ */


namespace c4 {

/** @defgroup doc_base64 Base64 encoding/decoding
 * @see https://en.wikipedia.org/wiki/Base64
 * @see https://www.base64encode.org/
 * @{ */

/** check that the given buffer is a valid base64 encoding
 * @see https://en.wikipedia.org/wiki/Base64 */
C4CORE_EXPORT bool base64_valid(csubstr encoded);


/** base64-encode binary data.
 * @param encoded [out] output buffer for encoded data
 * @param data [in] the input buffer with the binary data
 *
 * @return the number of bytes needed to return the output (ie the
 * required size for @p encoded). No writes occur beyond the end of
 * the output buffer, so it is safe to do a speculative call where the
 * encoded buffer is empty, or maybe too small. The caller should
 * ensure that the returned size is smaller than the size of the
 * encoded buffer.
 *
 * @note the result depends on endianness. If transfer between
 * little/big endian systems is desired, the caller should normalize
 * @p data before encoding.
 *
 * @see https://en.wikipedia.org/wiki/Base64 */
C4CORE_EXPORT size_t base64_encode(substr encoded, cblob data);


/** decode the base64 encoding in the given buffer
 * @param encoded [in] the encoded base64
 * @param data [out] the output buffer
 *
 * @return the number of bytes needed to return the output (ie the
 * required size for @p data). No writes occur beyond the end of the
 * output buffer, so it is safe to do a speculative call where the
 * data buffer is empty, or maybe too small. The caller should ensure
 * that the returned size is smaller than the size of the data buffer.
 *
 * @note the result depends on endianness. If transfer between
 * little/big endian systems is desired, the caller should normalize
 * @p data after decoding.
 *
 * @see https://en.wikipedia.org/wiki/Base64 */
C4CORE_EXPORT size_t base64_decode(csubstr encoded, blob data);

/** @} */ // base64

namespace fmt {

/** @addtogroup doc_format_specifiers
 * @{ */

/** @defgroup doc_base64_fmt Base64
 * @{ */

template<typename CharOrConstChar>
struct base64_wrapper_
{
    blob_<CharOrConstChar> data;
    base64_wrapper_() : data() {}
    base64_wrapper_(blob_<CharOrConstChar> blob) : data(blob) {}
};
/** a tag type to mark a payload as base64-encoded */
using const_base64_wrapper = base64_wrapper_<cbyte>;
/** a tag type to mark a payload to be encoded as base64 */
using base64_wrapper = base64_wrapper_<byte>;


/** mark a variable to be written in base64 format */
template<class ...Args>
C4_ALWAYS_INLINE const_base64_wrapper cbase64(Args const& C4_RESTRICT ...args)
{
    return const_base64_wrapper(cblob(args...));
}
/** mark a csubstr to be written in base64 format */
C4_ALWAYS_INLINE const_base64_wrapper cbase64(csubstr s)
{
    return const_base64_wrapper(cblob(s.str, s.len));
}
/** mark a variable to be written in base64 format */
template<class ...Args>
C4_ALWAYS_INLINE const_base64_wrapper base64(Args const& C4_RESTRICT ...args)
{
    return const_base64_wrapper(cblob(args...));
}
/** mark a csubstr to be written in base64 format */
C4_ALWAYS_INLINE const_base64_wrapper base64(csubstr s)
{
    return const_base64_wrapper(cblob(s.str, s.len));
}

/** mark a variable to be read in base64 format */
template<class ...Args>
C4_ALWAYS_INLINE base64_wrapper base64(Args &... args)
{
    return base64_wrapper(blob(args...));
}
/** mark a variable to be read in base64 format */
C4_ALWAYS_INLINE base64_wrapper base64(substr s)
{
    return base64_wrapper(blob(s.str, s.len));
}

/** @} */ // base64_fmt

/** @} */ // format_specifiers

} // namespace fmt


/** write a variable in base64 format
 * @ingroup doc_to_chars */
inline size_t to_chars(substr buf, fmt::const_base64_wrapper b)
{
    return base64_encode(buf, b.data);
}

/** read a variable in base64 format
 * @ingroup doc_from_chars */
inline size_t from_chars(csubstr buf, fmt::base64_wrapper *b)
{
    return base64_decode(buf, b->data);
}

} // namespace c4

#endif /* _C4_BASE64_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/base64.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/std/string.hpp
// https://github.com/biojppm/c4core/src/c4/std/string.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_STD_STRING_HPP_
#define _C4_STD_STRING_HPP_

/** @file string.hpp */

#ifndef C4CORE_SINGLE_HEADER
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/substr.hpp
//#include "c4/substr.hpp"
#if !defined(C4_SUBSTR_HPP_) && !defined(_C4_SUBSTR_HPP_)
#error "amalgamate: file c4/substr.hpp must have been included at this point"
#endif /* C4_SUBSTR_HPP_ */

#endif

//included above:
//#include <string>

namespace c4 {

//-----------------------------------------------------------------------------

/** get a writeable view to an existing std::string.
 * When the string is empty, the returned view will be pointing
 * at the character with value '\0', but the size will be zero.
 * @see https://en.cppreference.com/w/cpp/string/basic_string/operator_at
 */
C4_ALWAYS_INLINE c4::substr to_substr(std::string &s) noexcept
{
    #if C4_CPP < 11
    #error this function will have undefined behavior
    #endif
    // since c++11 it is legal to call s[s.size()].
    return c4::substr(&s[0], s.size());
}

/** get a readonly view to an existing std::string.
 * When the string is empty, the returned view will be pointing
 * at the character with value '\0', but the size will be zero.
 * @see https://en.cppreference.com/w/cpp/string/basic_string/operator_at
 */
C4_ALWAYS_INLINE c4::csubstr to_csubstr(std::string const& s) noexcept
{
    #if C4_CPP < 11
    #error this function will have undefined behavior
    #endif
    // since c++11 it is legal to call s[s.size()].
    return c4::csubstr(&s[0], s.size());
}

//-----------------------------------------------------------------------------

C4_ALWAYS_INLINE bool operator== (c4::csubstr ss, std::string const& s) { return ss.compare(to_csubstr(s)) == 0; }
C4_ALWAYS_INLINE bool operator!= (c4::csubstr ss, std::string const& s) { return ss.compare(to_csubstr(s)) != 0; }
C4_ALWAYS_INLINE bool operator>= (c4::csubstr ss, std::string const& s) { return ss.compare(to_csubstr(s)) >= 0; }
C4_ALWAYS_INLINE bool operator>  (c4::csubstr ss, std::string const& s) { return ss.compare(to_csubstr(s)) >  0; }
C4_ALWAYS_INLINE bool operator<= (c4::csubstr ss, std::string const& s) { return ss.compare(to_csubstr(s)) <= 0; }
C4_ALWAYS_INLINE bool operator<  (c4::csubstr ss, std::string const& s) { return ss.compare(to_csubstr(s)) <  0; }

C4_ALWAYS_INLINE bool operator== (std::string const& s, c4::csubstr ss) { return ss.compare(to_csubstr(s)) == 0; }
C4_ALWAYS_INLINE bool operator!= (std::string const& s, c4::csubstr ss) { return ss.compare(to_csubstr(s)) != 0; }
C4_ALWAYS_INLINE bool operator>= (std::string const& s, c4::csubstr ss) { return ss.compare(to_csubstr(s)) <= 0; }
C4_ALWAYS_INLINE bool operator>  (std::string const& s, c4::csubstr ss) { return ss.compare(to_csubstr(s)) <  0; }
C4_ALWAYS_INLINE bool operator<= (std::string const& s, c4::csubstr ss) { return ss.compare(to_csubstr(s)) >= 0; }
C4_ALWAYS_INLINE bool operator<  (std::string const& s, c4::csubstr ss) { return ss.compare(to_csubstr(s)) >  0; }

//-----------------------------------------------------------------------------

/** copy an std::string to a writeable string view */
inline size_t to_chars(c4::substr buf, std::string const& s)
{
    C4_ASSERT(!buf.overlaps(to_csubstr(s)));
    size_t len = buf.len < s.size() ? buf.len : s.size();
    // calling memcpy with null strings is undefined behavior
    // and will wreak havoc in calling code's branches.
    // see https://github.com/biojppm/rapidyaml/pull/264#issuecomment-1262133637
    if(len)
    {
        C4_ASSERT(s.data() != nullptr);
        C4_ASSERT(buf.str != nullptr);
        memcpy(buf.str, s.data(), len);
    }
    return s.size(); // return the number of needed chars
}

/** copy a string view to an existing std::string */
inline bool from_chars(c4::csubstr buf, std::string * s)
{
    s->resize(buf.len);
    C4_ASSERT(!buf.overlaps(to_csubstr(*s)));
    // calling memcpy with null strings is undefined behavior
    // and will wreak havoc in calling code's branches.
    // see https://github.com/biojppm/rapidyaml/pull/264#issuecomment-1262133637
    if(buf.len)
    {
        C4_ASSERT(buf.str != nullptr);
        memcpy(&(*s)[0], buf.str, buf.len);
    }
    return true;
}

} // namespace c4

#endif // _C4_STD_STRING_HPP_


// (end https://github.com/biojppm/c4core/src/c4/std/string.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/std/string_view.hpp
// https://github.com/biojppm/c4core/src/c4/std/string_view.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_STD_STRING_VIEW_HPP_
#define _C4_STD_STRING_VIEW_HPP_

/** @file string_view.hpp */

#ifndef C4CORE_SINGLE_HEADER
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/language.hpp
//#include "c4/language.hpp"
#if !defined(C4_LANGUAGE_HPP_) && !defined(_C4_LANGUAGE_HPP_)
#error "amalgamate: file c4/language.hpp must have been included at this point"
#endif /* C4_LANGUAGE_HPP_ */

#endif

#if (C4_CPP >= 17 && defined(__cpp_lib_string_view)) || defined(__DOXYGEN__)

#ifndef C4CORE_SINGLE_HEADER
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/substr.hpp
//#include "c4/substr.hpp"
#if !defined(C4_SUBSTR_HPP_) && !defined(_C4_SUBSTR_HPP_)
#error "amalgamate: file c4/substr.hpp must have been included at this point"
#endif /* C4_SUBSTR_HPP_ */

#endif

#include <string_view>


namespace c4 {

//-----------------------------------------------------------------------------

/** create a csubstr from an existing std::string_view. */
C4_ALWAYS_INLINE c4::csubstr to_csubstr(std::string_view s) noexcept
{
    return c4::csubstr(s.data(), s.size());
}


//-----------------------------------------------------------------------------

C4_ALWAYS_INLINE bool operator== (c4::csubstr ss, std::string_view s) { return ss.compare(s.data(), s.size()) == 0; }
C4_ALWAYS_INLINE bool operator!= (c4::csubstr ss, std::string_view s) { return ss.compare(s.data(), s.size()) != 0; }
C4_ALWAYS_INLINE bool operator>= (c4::csubstr ss, std::string_view s) { return ss.compare(s.data(), s.size()) >= 0; }
C4_ALWAYS_INLINE bool operator>  (c4::csubstr ss, std::string_view s) { return ss.compare(s.data(), s.size()) >  0; }
C4_ALWAYS_INLINE bool operator<= (c4::csubstr ss, std::string_view s) { return ss.compare(s.data(), s.size()) <= 0; }
C4_ALWAYS_INLINE bool operator<  (c4::csubstr ss, std::string_view s) { return ss.compare(s.data(), s.size()) <  0; }

C4_ALWAYS_INLINE bool operator== (std::string_view s, c4::csubstr ss) { return ss.compare(s.data(), s.size()) == 0; }
C4_ALWAYS_INLINE bool operator!= (std::string_view s, c4::csubstr ss) { return ss.compare(s.data(), s.size()) != 0; }
C4_ALWAYS_INLINE bool operator<= (std::string_view s, c4::csubstr ss) { return ss.compare(s.data(), s.size()) >= 0; }
C4_ALWAYS_INLINE bool operator<  (std::string_view s, c4::csubstr ss) { return ss.compare(s.data(), s.size()) >  0; }
C4_ALWAYS_INLINE bool operator>= (std::string_view s, c4::csubstr ss) { return ss.compare(s.data(), s.size()) <= 0; }
C4_ALWAYS_INLINE bool operator>  (std::string_view s, c4::csubstr ss) { return ss.compare(s.data(), s.size()) <  0; }


//-----------------------------------------------------------------------------

/** copy an std::string_view to a writeable substr */
inline size_t to_chars(c4::substr buf, std::string_view s)
{
    C4_ASSERT(!buf.overlaps(to_csubstr(s)));
    size_t sz = s.size();
    size_t len = buf.len < sz ? buf.len : sz;
    // calling memcpy with null strings is undefined behavior
    // and will wreak havoc in calling code's branches.
    // see https://github.com/biojppm/rapidyaml/pull/264#issuecomment-1262133637
    if(len)
    {
        C4_ASSERT(s.data() != nullptr);
        C4_ASSERT(buf.str != nullptr);
        memcpy(buf.str, s.data(), len);
    }
    return sz; // return the number of needed chars
}

} // namespace c4

#endif // C4_STRING_VIEW_AVAILABLE

#endif // _C4_STD_STRING_VIEW_HPP_


// (end https://github.com/biojppm/c4core/src/c4/std/string_view.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/std/vector.hpp
// https://github.com/biojppm/c4core/src/c4/std/vector.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_STD_VECTOR_HPP_
#define _C4_STD_VECTOR_HPP_

/** @file vector.hpp provides conversion and comparison facilities
 * from/between std::vector<char> to c4::substr and c4::csubstr.
 * @todo add to_span() and friends
 */

#ifndef C4CORE_SINGLE_HEADER
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/substr.hpp
//#include "c4/substr.hpp"
#if !defined(C4_SUBSTR_HPP_) && !defined(_C4_SUBSTR_HPP_)
#error "amalgamate: file c4/substr.hpp must have been included at this point"
#endif /* C4_SUBSTR_HPP_ */

#endif

#include <vector>

namespace c4 {

//-----------------------------------------------------------------------------

/** get a substr (writeable string view) of an existing std::vector<char> */
template<class Alloc>
c4::substr to_substr(std::vector<char, Alloc> &vec)
{
    char *data = vec.empty() ? nullptr : vec.data(); // data() may or may not return a null pointer.
    return c4::substr(data, vec.size());
}

/** get a csubstr (read-only string) view of an existing std::vector<char> */
template<class Alloc>
c4::csubstr to_csubstr(std::vector<char, Alloc> const& vec)
{
    const char *data = vec.empty() ? nullptr : vec.data(); // data() may or may not return a null pointer.
    return c4::csubstr(data, vec.size());
}

//-----------------------------------------------------------------------------
// comparisons between substrings and std::vector<char>

template<class Alloc> C4_ALWAYS_INLINE bool operator!= (c4::csubstr ss, std::vector<char, Alloc> const& s) { return ss != to_csubstr(s); }
template<class Alloc> C4_ALWAYS_INLINE bool operator== (c4::csubstr ss, std::vector<char, Alloc> const& s) { return ss == to_csubstr(s); }
template<class Alloc> C4_ALWAYS_INLINE bool operator>= (c4::csubstr ss, std::vector<char, Alloc> const& s) { return ss >= to_csubstr(s); }
template<class Alloc> C4_ALWAYS_INLINE bool operator>  (c4::csubstr ss, std::vector<char, Alloc> const& s) { return ss >  to_csubstr(s); }
template<class Alloc> C4_ALWAYS_INLINE bool operator<= (c4::csubstr ss, std::vector<char, Alloc> const& s) { return ss <= to_csubstr(s); }
template<class Alloc> C4_ALWAYS_INLINE bool operator<  (c4::csubstr ss, std::vector<char, Alloc> const& s) { return ss <  to_csubstr(s); }

template<class Alloc> C4_ALWAYS_INLINE bool operator!= (std::vector<char, Alloc> const& s, c4::csubstr ss) { return ss != to_csubstr(s); }
template<class Alloc> C4_ALWAYS_INLINE bool operator== (std::vector<char, Alloc> const& s, c4::csubstr ss) { return ss == to_csubstr(s); }
template<class Alloc> C4_ALWAYS_INLINE bool operator>= (std::vector<char, Alloc> const& s, c4::csubstr ss) { return ss <= to_csubstr(s); }
template<class Alloc> C4_ALWAYS_INLINE bool operator>  (std::vector<char, Alloc> const& s, c4::csubstr ss) { return ss <  to_csubstr(s); }
template<class Alloc> C4_ALWAYS_INLINE bool operator<= (std::vector<char, Alloc> const& s, c4::csubstr ss) { return ss >= to_csubstr(s); }
template<class Alloc> C4_ALWAYS_INLINE bool operator<  (std::vector<char, Alloc> const& s, c4::csubstr ss) { return ss >  to_csubstr(s); }

//-----------------------------------------------------------------------------

/** copy a std::vector<char> to a writeable string view */
template<class Alloc>
inline size_t to_chars(c4::substr buf, std::vector<char, Alloc> const& s)
{
    C4_ASSERT(!buf.overlaps(to_csubstr(s)));
    size_t len = buf.len < s.size() ? buf.len : s.size();
    // calling memcpy with null strings is undefined behavior
    // and will wreak havoc in calling code's branches.
    // see https://github.com/biojppm/rapidyaml/pull/264#issuecomment-1262133637
    if(len > 0)
    {
        memcpy(buf.str, s.data(), len);
    }
    return s.size(); // return the number of needed chars
}

/** copy a string view to an existing std::vector<char> */
template<class Alloc>
inline bool from_chars(c4::csubstr buf, std::vector<char, Alloc> * s)
{
    s->resize(buf.len);
    C4_ASSERT(!buf.overlaps(to_csubstr(*s)));
    // calling memcpy with null strings is undefined behavior
    // and will wreak havoc in calling code's branches.
    // see https://github.com/biojppm/rapidyaml/pull/264#issuecomment-1262133637
    if(buf.len > 0)
    {
        memcpy(&(*s)[0], buf.str, buf.len);
    }
    return true;
}

} // namespace c4

#endif // _C4_STD_VECTOR_HPP_


// (end https://github.com/biojppm/c4core/src/c4/std/vector.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/std/tuple.hpp
// https://github.com/biojppm/c4core/src/c4/std/tuple.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_STD_TUPLE_HPP_
#define _C4_STD_TUPLE_HPP_

/** @file tuple.hpp */

#ifndef C4CORE_SINGLE_HEADER
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/format.hpp
//#include "c4/format.hpp"
#if !defined(C4_FORMAT_HPP_) && !defined(_C4_FORMAT_HPP_)
#error "amalgamate: file c4/format.hpp must have been included at this point"
#endif /* C4_FORMAT_HPP_ */

#endif

#include <tuple>

/** this is a work in progress */
#undef C4_TUPLE_TO_CHARS

namespace c4 {

#ifdef C4_TUPLE_TO_CHARS
namespace detail {

template< size_t Curr, class... Types >
struct tuple_helper
{
    static size_t do_cat(substr buf, std::tuple< Types... > const& tp)
    {
        size_t num = to_chars(buf, std::get<Curr>(tp));
        buf = buf.len >= num ? buf.sub(num) : substr{};
        num += tuple_helper< Curr+1, Types... >::do_cat(buf, tp);
        return num;
    }

    static size_t do_uncat(csubstr buf, std::tuple< Types... > & tp)
    {
        size_t num = from_str_trim(buf, &std::get<Curr>(tp));
        if(num == csubstr::npos) return csubstr::npos;
        buf = buf.len >= num ? buf.sub(num) : substr{};
        num += tuple_helper< Curr+1, Types... >::do_uncat(buf, tp);
        return num;
    }

    template< class Sep >
    static size_t do_catsep_more(substr buf, Sep const& sep, std::tuple< Types... > const& tp)
    {
        size_t ret = to_chars(buf, sep), num = ret;
        buf  = buf.len >= ret ? buf.sub(ret) : substr{};
        ret  = to_chars(buf, std::get<Curr>(tp));
        num += ret;
        buf  = buf.len >= ret ? buf.sub(ret) : substr{};
        ret  = tuple_helper< Curr+1, Types... >::do_catsep_more(buf, sep, tp);
        num += ret;
        return num;
    }

    template< class Sep >
    static size_t do_uncatsep_more(csubstr buf, Sep & sep, std::tuple< Types... > & tp)
    {
        size_t ret = from_str_trim(buf, &sep), num = ret;
        if(ret == csubstr::npos) return csubstr::npos;
        buf  = buf.len >= ret ? buf.sub(ret) : substr{};
        ret  = from_str_trim(buf, &std::get<Curr>(tp));
        if(ret == csubstr::npos) return csubstr::npos;
        num += ret;
        buf  = buf.len >= ret ? buf.sub(ret) : substr{};
        ret  = tuple_helper< Curr+1, Types... >::do_uncatsep_more(buf, sep, tp);
        if(ret == csubstr::npos) return csubstr::npos;
        num += ret;
        return num;
    }

    static size_t do_format(substr buf, csubstr fmt, std::tuple< Types... > const& tp)
    {
        auto pos = fmt.find("{}");
        if(pos != csubstr::npos)
        {
            size_t num = to_chars(buf, fmt.sub(0, pos));
            size_t out = num;
            buf  = buf.len >= num ? buf.sub(num) : substr{};
            num  = to_chars(buf, std::get<Curr>(tp));
            out += num;
            buf  = buf.len >= num ? buf.sub(num) : substr{};
            num  = tuple_helper< Curr+1, Types... >::do_format(buf, fmt.sub(pos + 2), tp);
            out += num;
            return out;
        }
        else
        {
            return format(buf, fmt);
        }
    }

    static size_t do_unformat(csubstr buf, csubstr fmt, std::tuple< Types... > & tp)
    {
        auto pos = fmt.find("{}");
        if(pos != csubstr::npos)
        {
            size_t num = pos;
            size_t out = num;
            buf  = buf.len >= num ? buf.sub(num) : substr{};
            num  = from_str_trim(buf, &std::get<Curr>(tp));
            out += num;
            buf  = buf.len >= num ? buf.sub(num) : substr{};
            num  = tuple_helper< Curr+1, Types... >::do_unformat(buf, fmt.sub(pos + 2), tp);
            out += num;
            return out;
        }
        else
        {
            return tuple_helper< sizeof...(Types), Types... >::do_unformat(buf, fmt, tp);
        }
    }

};

/** @todo VS compilation fails for this class */
template< class... Types >
struct tuple_helper< sizeof...(Types), Types... >
{
    static size_t do_cat(substr /*buf*/, std::tuple<Types...> const& /*tp*/) { return 0; }
    static size_t do_uncat(csubstr /*buf*/, std::tuple<Types...> & /*tp*/) { return 0; }

    template< class Sep > static size_t do_catsep_more(substr /*buf*/, Sep const& /*sep*/, std::tuple<Types...> const& /*tp*/) { return 0; }
    template< class Sep > static size_t do_uncatsep_more(csubstr /*buf*/, Sep & /*sep*/, std::tuple<Types...> & /*tp*/) { return 0; }

    static size_t do_format(substr buf, csubstr fmt, std::tuple<Types...> const& /*tp*/)
    {
        return to_chars(buf, fmt);
    }

    static size_t do_unformat(csubstr buf, csubstr fmt, std::tuple<Types...> const& /*tp*/)
    {
        return 0;
    }
};

} // namespace detail

template< class... Types >
inline size_t cat(substr buf, std::tuple< Types... > const& tp)
{
    return detail::tuple_helper< 0, Types... >::do_cat(buf, tp);
}

template< class... Types >
inline size_t uncat(csubstr buf, std::tuple< Types... > & tp)
{
    return detail::tuple_helper< 0, Types... >::do_uncat(buf, tp);
}

template< class Sep, class... Types >
inline size_t catsep(substr buf, Sep const& sep, std::tuple< Types... > const& tp)
{
    size_t num = to_chars(buf, std::cref(std::get<0>(tp)));
    buf  = buf.len >= num ? buf.sub(num) : substr{};
    num += detail::tuple_helper< 1, Types... >::do_catsep_more(buf, sep, tp);
    return num;
}

template< class Sep, class... Types >
inline size_t uncatsep(csubstr buf, Sep & sep, std::tuple< Types... > & tp)
{
    size_t ret = from_str_trim(buf, &std::get<0>(tp)), num = ret;
    if(ret == csubstr::npos) return csubstr::npos;
    buf  = buf.len >= ret ? buf.sub(ret) : substr{};
    ret  = detail::tuple_helper< 1, Types... >::do_uncatsep_more(buf, sep, tp);
    if(ret == csubstr::npos) return csubstr::npos;
    num += ret;
    return num;
}

template< class... Types >
inline size_t format(substr buf, csubstr fmt, std::tuple< Types... > const& tp)
{
    return detail::tuple_helper< 0, Types... >::do_format(buf, fmt, tp);
}

template< class... Types >
inline size_t unformat(csubstr buf, csubstr fmt, std::tuple< Types... > & tp)
{
    return detail::tuple_helper< 0, Types... >::do_unformat(buf, fmt, tp);
}
#endif // C4_TUPLE_TO_CHARS

} // namespace c4

#endif /* _C4_STD_TUPLE_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/std/tuple.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/ext/rng/rng.hpp
// https://github.com/biojppm/c4core/src/c4/ext/rng/rng.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

/* Copyright (c) 2018 Arvid Gerstmann.
 *
 * https://arvid.io/2018/07/02/better-cxx-prng/
 *
 * This code is licensed under MIT license. */
#ifndef AG_RANDOM_H
#define AG_RANDOM_H

//included above:
//#include <stdint.h>
#include <random>


#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

namespace c4 {
namespace rng {

class splitmix
{
public:
    using result_type = uint32_t;
    static constexpr result_type (min)() { return 0; }
    static constexpr result_type (max)() { return UINT32_MAX; }
    friend bool operator==(splitmix const &, splitmix const &);
    friend bool operator!=(splitmix const &, splitmix const &);

    splitmix() : m_seed(1) {}
    explicit splitmix(uint64_t s) : m_seed(s) {}
    explicit splitmix(std::random_device &rd)
    {
        seed(rd);
    }

    void seed(uint64_t s) { m_seed = s; }
    void seed(std::random_device &rd)
    {
        m_seed = uint64_t(rd()) << 31 | uint64_t(rd());
    }

    result_type operator()()
    {
        uint64_t z = (m_seed += UINT64_C(0x9E3779B97F4A7C15));
        z = (z ^ (z >> 30)) * UINT64_C(0xBF58476D1CE4E5B9);
        z = (z ^ (z >> 27)) * UINT64_C(0x94D049BB133111EB);
        return result_type((z ^ (z >> 31)) >> 31);
    }

    void discard(unsigned long long n)
    {
        for (unsigned long long i = 0; i < n; ++i)
            operator()();
    }

private:
    uint64_t m_seed;
};

inline bool operator==(splitmix const &lhs, splitmix const &rhs)
{
    return lhs.m_seed == rhs.m_seed;
}
inline bool operator!=(splitmix const &lhs, splitmix const &rhs)
{
    return lhs.m_seed != rhs.m_seed;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

class xorshift
{
public:
    using result_type = uint32_t;
    static constexpr result_type (min)() { return 0; }
    static constexpr result_type (max)() { return UINT32_MAX; }
    friend bool operator==(xorshift const &, xorshift const &);
    friend bool operator!=(xorshift const &, xorshift const &);

    xorshift() : m_seed(0xc1f651c67c62c6e0ull) {}
    explicit xorshift(std::random_device &rd)
    {
        seed(rd);
    }

    void seed(uint64_t s) { m_seed = s; }
    void seed(std::random_device &rd)
    {
        m_seed = uint64_t(rd()) << 31 | uint64_t(rd());
    }

    result_type operator()()
    {
        uint64_t result = m_seed * 0xd989bcacc137dcd5ull;
        m_seed ^= m_seed >> 11;
        m_seed ^= m_seed << 31;
        m_seed ^= m_seed >> 18;
        return uint32_t(result >> 32ull);
    }

    void discard(unsigned long long n)
    {
        for (unsigned long long i = 0; i < n; ++i)
            operator()();
    }

private:
    uint64_t m_seed;
};

inline bool operator==(xorshift const &lhs, xorshift const &rhs)
{
    return lhs.m_seed == rhs.m_seed;
}
inline bool operator!=(xorshift const &lhs, xorshift const &rhs)
{
    return lhs.m_seed != rhs.m_seed;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

class pcg
{
public:
    using result_type = uint32_t;
    static constexpr result_type (min)() { return 0; }
    static constexpr result_type (max)() { return UINT32_MAX; }
    friend bool operator==(pcg const &, pcg const &);
    friend bool operator!=(pcg const &, pcg const &);

    pcg()
        : m_state(0x853c49e6748fea9bULL)
        , m_inc(0xda3e39cb94b95bdbULL)
    {}
    explicit pcg(uint64_t s) { m_state = s; m_inc = m_state << 1; }
    explicit pcg(std::random_device &rd)
    {
        seed(rd);
    }

    void seed(uint64_t s) { m_state = s; }
    void seed(std::random_device &rd)
    {
        uint64_t s0 = uint64_t(rd()) << 31 | uint64_t(rd());
        uint64_t s1 = uint64_t(rd()) << 31 | uint64_t(rd());

        m_state = 0;
        m_inc = (s1 << 1) | 1;
        (void)operator()();
        m_state += s0;
        (void)operator()();
    }

    result_type operator()()
    {
        uint64_t oldstate = m_state;
        m_state = oldstate * 6364136223846793005ULL + m_inc;
        uint32_t xorshifted = uint32_t(((oldstate >> 18u) ^ oldstate) >> 27u);
        //int rot = oldstate >> 59u; // the original. error?
        int64_t rot = (int64_t)oldstate >> 59u; // error?
        return (xorshifted >> rot) | (xorshifted << ((uint64_t)(-rot) & 31));
    }

    void discard(unsigned long long n)
    {
        for (unsigned long long i = 0; i < n; ++i)
            operator()();
    }

private:
    uint64_t m_state;
    uint64_t m_inc;
};

inline bool operator==(pcg const &lhs, pcg const &rhs)
{
    return lhs.m_state == rhs.m_state
        && lhs.m_inc == rhs.m_inc;
}
inline bool operator!=(pcg const &lhs, pcg const &rhs)
{
    return lhs.m_state != rhs.m_state
        || lhs.m_inc != rhs.m_inc;
}

} // namespace rng
} // namespace c4

#ifdef __clang__
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif

#endif /* AG_RANDOM_H */


// (end https://github.com/biojppm/c4core/src/c4/ext/rng/rng.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/ext/sg14/inplace_function.h
// https://github.com/biojppm/c4core/src/c4/ext/sg14/inplace_function.h
//--------------------------------------------------------------------------------
//********************************************************************************

/*
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef _C4_EXT_SG14_INPLACE_FUNCTION_H_
#define _C4_EXT_SG14_INPLACE_FUNCTION_H_

//included above:
//#include <type_traits>
//included above:
//#include <utility>
#include <functional>
//included above:
//#include <cstdlib>

namespace stdext {

namespace inplace_function_detail {

static constexpr size_t InplaceFunctionDefaultCapacity = 32;

#if defined(__GLIBCXX__)  // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=61458
template<size_t Cap>
union aligned_storage_helper {
    struct double1 { double a; };
    struct double4 { double a[4]; };
    template<class T> using maybe = typename std::conditional<(Cap >= sizeof(T)), T, char>::type;
    char real_data[Cap];
    maybe<int> a;
    maybe<long> b;
    maybe<long long> c;
    maybe<void*> d;
    maybe<void(*)()> e;
    maybe<double1> f;
    maybe<double4> g;
    maybe<long double> h;
};

template<size_t Cap, size_t Align = std::alignment_of<aligned_storage_helper<Cap>>::value>
struct aligned_storage {
    using type = typename std::aligned_storage<Cap, Align>::type;
};
#else
using std::aligned_storage;
#endif

template<typename T> struct wrapper
{
    using type = T;
};

template<typename R, typename... Args> struct vtable
{
    using storage_ptr_t = void*;

    using invoke_ptr_t = R(*)(storage_ptr_t, Args&&...);
    using process_ptr_t = void(*)(storage_ptr_t, storage_ptr_t);
    using destructor_ptr_t = void(*)(storage_ptr_t);

    const invoke_ptr_t invoke_ptr;
    const process_ptr_t copy_ptr;
    const process_ptr_t move_ptr;
    const destructor_ptr_t destructor_ptr;

    explicit constexpr vtable() noexcept :
        invoke_ptr{ [](storage_ptr_t, Args&&...) -> R
            {
                #if (defined(_MSC_VER) && (defined(_CPPUNWIND) && (__CPPUNWIND == 1)))  \
                    ||                                                  \
                    (defined(__EXCEPTIONS) || defined(__cpp_exceptions))
                throw std::bad_function_call();
                #else
                std::abort();
                #endif
            }
        },
        copy_ptr{ [](storage_ptr_t, storage_ptr_t) noexcept -> void {} },
        move_ptr{ [](storage_ptr_t, storage_ptr_t) noexcept -> void {} },
        destructor_ptr{ [](storage_ptr_t) noexcept -> void {} }
    {}

    template<typename C> explicit constexpr vtable(wrapper<C>) noexcept :
        invoke_ptr{ [](storage_ptr_t storage_ptr, Args&&... args)
            noexcept(noexcept(std::declval<C>()(args...))) -> R
            { return (*static_cast<C*>(storage_ptr))(
                std::forward<Args>(args)...
            ); }
        },
        copy_ptr{ [](storage_ptr_t dst_ptr, storage_ptr_t src_ptr)
            noexcept(std::is_nothrow_copy_constructible<C>::value) -> void
            { new (dst_ptr) C{ (*static_cast<C*>(src_ptr)) }; }
        },
        move_ptr{ [](storage_ptr_t dst_ptr, storage_ptr_t src_ptr)
            noexcept(std::is_nothrow_move_constructible<C>::value) -> void
            { new (dst_ptr) C{ std::move(*static_cast<C*>(src_ptr)) }; }
        },
        destructor_ptr{ [](storage_ptr_t storage_ptr)
            noexcept -> void
            { static_cast<C*>(storage_ptr)->~C(); }
        }
    {}

    vtable(const vtable&) = delete;
    vtable(vtable&&) = delete;

    vtable& operator= (const vtable&) = delete;
    vtable& operator= (vtable&&) = delete;

    ~vtable() = default;
};

template<size_t DstCap, size_t DstAlign, size_t SrcCap, size_t SrcAlign>
struct is_valid_inplace_dst : std::true_type
{
    static_assert(DstCap >= SrcCap,
        "Can't squeeze larger inplace_function into a smaller one"
    );

    static_assert(DstAlign % SrcAlign == 0,
        "Incompatible inplace_function alignments"
    );
};

} // namespace inplace_function_detail

template<
    typename Signature,
    size_t Capacity = inplace_function_detail::InplaceFunctionDefaultCapacity,
    size_t Alignment = std::alignment_of<typename inplace_function_detail::aligned_storage<Capacity>::type>::value
>
class inplace_function; // unspecified

template<
    typename R,
    typename... Args,
    size_t Capacity,
    size_t Alignment
>
class inplace_function<R(Args...), Capacity, Alignment>
{
    static const constexpr inplace_function_detail::vtable<R, Args...> empty_vtable{};
public:
    using capacity = std::integral_constant<size_t, Capacity>;
    using alignment = std::integral_constant<size_t, Alignment>;

    using storage_t = typename inplace_function_detail::aligned_storage<Capacity, Alignment>::type;
    using vtable_t = inplace_function_detail::vtable<R, Args...>;
    using vtable_ptr_t = const vtable_t*;

    template <typename, size_t, size_t>	friend class inplace_function;

    inplace_function() noexcept :
        vtable_ptr_{std::addressof(empty_vtable)}
    {}

    template<
        typename T,
        typename C = typename std::decay<T>::type,
        typename = typename std::enable_if<
            !(std::is_same<C, inplace_function>::value
            || std::is_convertible<C, inplace_function>::value)
        >::type
    >
    inplace_function(T&& closure)
    {
#if __cplusplus >= 201703L
        static_assert(std::is_invocable_r<R, C, Args...>::value,
            "inplace_function cannot be constructed from non-callable type"
        );
#endif
        static_assert(std::is_copy_constructible<C>::value,
            "inplace_function cannot be constructed from non-copyable type"
        );

        static_assert(sizeof(C) <= Capacity,
            "inplace_function cannot be constructed from object with this (large) size"
        );

        static_assert(Alignment % std::alignment_of<C>::value == 0,
            "inplace_function cannot be constructed from object with this (large) alignment"
        );

        static const vtable_t vt{inplace_function_detail::wrapper<C>{}};
        vtable_ptr_ = std::addressof(vt);

        new (std::addressof(storage_)) C{std::forward<T>(closure)};
    }

    inplace_function(std::nullptr_t) noexcept :
        vtable_ptr_{std::addressof(empty_vtable)}
    {}

    inplace_function(const inplace_function& other) :
        vtable_ptr_{other.vtable_ptr_}
    {
        vtable_ptr_->copy_ptr(
            std::addressof(storage_),
            std::addressof(other.storage_)
        );
    }

    inplace_function(inplace_function&& other) :
        vtable_ptr_{other.vtable_ptr_}
    {
        vtable_ptr_->move_ptr(
            std::addressof(storage_),
            std::addressof(other.storage_)
        );
    }

    inplace_function& operator= (std::nullptr_t) noexcept
    {
        vtable_ptr_->destructor_ptr(std::addressof(storage_));
        vtable_ptr_ = std::addressof(empty_vtable);
        return *this;
    }

    inplace_function& operator= (const inplace_function& other)
    {
        if(this != std::addressof(other))
        {
            vtable_ptr_->destructor_ptr(std::addressof(storage_));

            vtable_ptr_ = other.vtable_ptr_;
            vtable_ptr_->copy_ptr(
                std::addressof(storage_),
                std::addressof(other.storage_)
            );
        }
        return *this;
    }

    inplace_function& operator= (inplace_function&& other)
    {
        if(this != std::addressof(other))
        {
            vtable_ptr_->destructor_ptr(std::addressof(storage_));

            vtable_ptr_ = other.vtable_ptr_;
            vtable_ptr_->move_ptr(
                std::addressof(storage_),
                std::addressof(other.storage_)
            );
        }
        return *this;
    }

    ~inplace_function()
    {
        vtable_ptr_->destructor_ptr(std::addressof(storage_));
    }

    R operator() (Args... args) const
    {
        return vtable_ptr_->invoke_ptr(
            std::addressof(storage_),
            std::forward<Args>(args)...
        );
    }

    constexpr bool operator== (std::nullptr_t) const noexcept
    {
        return !operator bool();
    }

    constexpr bool operator!= (std::nullptr_t) const noexcept
    {
        return operator bool();
    }

    explicit constexpr operator bool() const noexcept
    {
        return vtable_ptr_ != std::addressof(empty_vtable);
    }

    template<size_t Cap, size_t Align>
    operator inplace_function<R(Args...), Cap, Align>() const&
    {
        static_assert(inplace_function_detail::is_valid_inplace_dst<
            Cap, Align, Capacity, Alignment
        >::value, "conversion not allowed");

        return {vtable_ptr_, vtable_ptr_->copy_ptr, std::addressof(storage_)};
    }

    template<size_t Cap, size_t Align>
    operator inplace_function<R(Args...), Cap, Align>() &&
    {
        static_assert(inplace_function_detail::is_valid_inplace_dst<
            Cap, Align, Capacity, Alignment
        >::value, "conversion not allowed");

        return {vtable_ptr_, vtable_ptr_->move_ptr, std::addressof(storage_)};
    }

    void swap(inplace_function& other)
    {
        if (this == std::addressof(other)) return;

        storage_t tmp;
        vtable_ptr_->move_ptr(
            std::addressof(tmp),
            std::addressof(storage_)
        );
        vtable_ptr_->destructor_ptr(std::addressof(storage_));

        other.vtable_ptr_->move_ptr(
            std::addressof(storage_),
            std::addressof(other.storage_)
        );
        other.vtable_ptr_->destructor_ptr(std::addressof(other.storage_));

        vtable_ptr_->move_ptr(
            std::addressof(other.storage_),
            std::addressof(tmp)
        );
        vtable_ptr_->destructor_ptr(std::addressof(tmp));

        std::swap(vtable_ptr_, other.vtable_ptr_);
    }

private:
    vtable_ptr_t vtable_ptr_;
    mutable storage_t storage_;

    inplace_function(
        vtable_ptr_t vtable_ptr,
        typename vtable_t::process_ptr_t process_ptr,
        typename vtable_t::storage_ptr_t storage_ptr
    ) : vtable_ptr_{vtable_ptr}
    {
        process_ptr(std::addressof(storage_), storage_ptr);
    }
};

} // namespace stdext

#endif /* _C4_EXT_SG14_INPLACE_FUNCTION_H_ */


// (end https://github.com/biojppm/c4core/src/c4/ext/sg14/inplace_function.h)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/language.cpp
// https://github.com/biojppm/c4core/src/c4/language.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef C4CORE_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/language.hpp
//#include "c4/language.hpp"
#if !defined(C4_LANGUAGE_HPP_) && !defined(_C4_LANGUAGE_HPP_)
#error "amalgamate: file c4/language.hpp must have been included at this point"
#endif /* C4_LANGUAGE_HPP_ */


namespace c4 {
namespace detail {

#ifndef __GNUC__
void use_char_pointer(char const volatile* v)
{
    C4_UNUSED(v);
}
#else
void foo() {} // to avoid empty file warning from the linker
#endif

} // namespace detail
} // namespace c4

#endif /* C4CORE_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/c4core/src/c4/language.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/format.cpp
// https://github.com/biojppm/c4core/src/c4/format.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef C4CORE_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/format.hpp
//#include "c4/format.hpp"
#if !defined(C4_FORMAT_HPP_) && !defined(_C4_FORMAT_HPP_)
#error "amalgamate: file c4/format.hpp must have been included at this point"
#endif /* C4_FORMAT_HPP_ */


//included above:
//#include <memory> // for std::align

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wformat-nonliteral"
#   pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wformat-nonliteral"
#   pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

namespace c4 {


size_t to_chars(substr buf, fmt::const_raw_wrapper r)
{
    void * vptr = buf.str;
    size_t space = buf.len;
    auto ptr = (decltype(buf.str)) std::align(r.alignment, r.len, vptr, space);
    if(ptr == nullptr)
    {
        // if it was not possible to align, return a conservative estimate
        // of the required space
        return r.alignment + r.len;
    }
    C4_CHECK(ptr >= buf.begin() && ptr <= buf.end());
    size_t sz = static_cast<size_t>(ptr - buf.str) + r.len;
    if(sz <= buf.len)
    {
        memcpy(ptr, r.buf, r.len);
    }
    return sz;
}


bool from_chars(csubstr buf, fmt::raw_wrapper *r)
{
    C4_SUPPRESS_WARNING_GCC_WITH_PUSH("-Wcast-qual")
    void * vptr = (void*)buf.str;
    C4_SUPPRESS_WARNING_GCC_POP
    size_t space = buf.len;
    auto ptr = (decltype(buf.str)) std::align(r->alignment, r->len, vptr, space);
    C4_CHECK(ptr != nullptr);
    C4_CHECK(ptr >= buf.begin() && ptr <= buf.end());
    C4_SUPPRESS_WARNING_GCC_PUSH
    #if defined(__GNUC__) && __GNUC__ > 9
    C4_SUPPRESS_WARNING_GCC("-Wanalyzer-null-argument")
    #endif
    memcpy(r->buf, ptr, r->len);
    C4_SUPPRESS_WARNING_GCC_POP
    return true;
}


} // namespace c4

#ifdef __clang__
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif

#endif /* C4CORE_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/c4core/src/c4/format.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/memory_util.cpp
// https://github.com/biojppm/c4core/src/c4/memory_util.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef C4CORE_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/memory_util.hpp
//#include "c4/memory_util.hpp"
#if !defined(C4_MEMORY_UTIL_HPP_) && !defined(_C4_MEMORY_UTIL_HPP_)
#error "amalgamate: file c4/memory_util.hpp must have been included at this point"
#endif /* C4_MEMORY_UTIL_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */


namespace c4 {


/** Fills 'dest' with the first 'pattern_size' bytes at 'pattern', 'num_times'. */
void mem_repeat(void* dest, void const* pattern, size_t pattern_size, size_t num_times)
{
    if(C4_UNLIKELY(num_times == 0))
        return;
    C4_ASSERT( ! mem_overlaps(dest, pattern, num_times*pattern_size, pattern_size));
    char *begin = static_cast<char*>(dest);
    char *end   = begin + num_times * pattern_size;
    // copy the pattern once
    ::memcpy(begin, pattern, pattern_size);
    // now copy from dest to itself, doubling up every time
    size_t n = pattern_size;
    while(begin + 2*n < end)
    {
        ::memcpy(begin + n, begin, n);
        n <<= 1; // double n
    }
    // copy the missing part
    if(begin + n < end)
    {
        ::memcpy(begin + n, begin, static_cast<size_t>(end - (begin + n)));
    }
}


} // namespace c4

#endif /* C4CORE_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/c4core/src/c4/memory_util.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/char_traits.cpp
// https://github.com/biojppm/c4core/src/c4/char_traits.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef C4CORE_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/char_traits.hpp
//#include "c4/char_traits.hpp"
#if !defined(C4_CHAR_TRAITS_HPP_) && !defined(_C4_CHAR_TRAITS_HPP_)
#error "amalgamate: file c4/char_traits.hpp must have been included at this point"
#endif /* C4_CHAR_TRAITS_HPP_ */


namespace c4 {

constexpr const char char_traits< char >::whitespace_chars[];
constexpr const size_t char_traits< char >::num_whitespace_chars;
constexpr const wchar_t char_traits< wchar_t >::whitespace_chars[];
constexpr const size_t char_traits< wchar_t >::num_whitespace_chars;

} // namespace c4

#endif /* C4CORE_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/c4core/src/c4/char_traits.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/memory_resource.cpp
// https://github.com/biojppm/c4core/src/c4/memory_resource.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef C4CORE_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/memory_resource.hpp
//#include "c4/memory_resource.hpp"
#if !defined(C4_MEMORY_RESOURCE_HPP_) && !defined(_C4_MEMORY_RESOURCE_HPP_)
#error "amalgamate: file c4/memory_resource.hpp must have been included at this point"
#endif /* C4_MEMORY_RESOURCE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/memory_util.hpp
//#include "c4/memory_util.hpp"
#if !defined(C4_MEMORY_UTIL_HPP_) && !defined(_C4_MEMORY_UTIL_HPP_)
#error "amalgamate: file c4/memory_util.hpp must have been included at this point"
#endif /* C4_MEMORY_UTIL_HPP_ */


//included above:
//#include <stdlib.h>
//included above:
//#include <string.h>
#if defined(C4_POSIX) || defined(C4_IOS) || defined(C4_MACOS) || defined(C4_ARM)
#   include <errno.h>
#endif
#if defined(C4_ARM)
#   include <malloc.h>
#endif

//included above:
//#include <memory>

namespace c4 {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")

namespace detail {


#ifdef C4_NO_ALLOC_DEFAULTS
aalloc_pfn s_aalloc = nullptr;
free_pfn s_afree = nullptr;
arealloc_pfn s_arealloc = nullptr;
#else


void afree_impl(void *ptr)
{
#if defined(C4_WIN) || defined(C4_XBOX)
    ::_aligned_free(ptr);
#else
    ::free(ptr);
#endif
}


void* aalloc_impl(size_t size, size_t alignment)
{
    // alignment must be nonzero and a power of 2
    C4_CHECK(alignment > 0 && (alignment & (alignment - 1u)) == 0);
    // NOTE: alignment needs to be sized in multiples of sizeof(void*)
    if(C4_UNLIKELY(alignment < sizeof(void*)))
        alignment = sizeof(void*);
    static_assert((sizeof(void*) & (sizeof(void*)-1u)) == 0, "sizeof(void*) must be a power of 2");
    C4_CHECK(((alignment & (sizeof(void*) - 1u))) == 0u);
    void *mem;
#if defined(C4_WIN) || defined(C4_XBOX)
    mem = ::_aligned_malloc(size, alignment);
    C4_CHECK(mem != nullptr || size == 0);
#elif defined(C4_POSIX) || defined(C4_IOS) || defined(C4_MACOS)
    int ret = ::posix_memalign(&mem, alignment, size);
    if(C4_UNLIKELY(ret))
    {
        C4_ASSERT(ret != EINVAL); // this was already handled above
        if(ret == ENOMEM)
        {
            C4_ERROR("There was insufficient memory to fulfill the "
                     "allocation request of %zu bytes (alignment=%lu)", size, size);
        }
        return nullptr;
    }
#elif defined(C4_ARM) || defined(C4_ANDROID)
    // https://stackoverflow.com/questions/53614538/undefined-reference-to-posix-memalign-in-arm-gcc
    // https://electronics.stackexchange.com/questions/467382/e2-studio-undefined-reference-to-posix-memalign/467753
    mem = memalign(alignment, size);
    C4_CHECK(mem != nullptr || size == 0);
#else
    (void)size;
    (void)alignment;
    mem = nullptr;
    C4_NOT_IMPLEMENTED_MSG("need to implement an aligned allocation for this platform");
#endif
    C4_ASSERT_MSG((uintptr_t(mem) & (alignment-1)) == 0, "address %p is not aligned to %zu boundary", mem, alignment);
    return mem;
}


void* arealloc_impl(void* ptr, size_t oldsz, size_t newsz, size_t alignment)
{
    /** @todo make this more efficient
     * @see https://stackoverflow.com/questions/9078259/does-realloc-keep-the-memory-alignment-of-posix-memalign
     * @see look for qReallocAligned() in http://code.qt.io/cgit/qt/qtbase.git/tree/src/corelib/global/qmalloc.cpp
     */
    void *tmp = aalloc(newsz, alignment);
    size_t min = newsz < oldsz ? newsz : oldsz;
    if(mem_overlaps(ptr, tmp, oldsz, newsz))
    {
        ::memmove(tmp, ptr, min);
    }
    else
    {
        ::memcpy(tmp, ptr, min);
    }
    afree(ptr);
    return tmp;
}

aalloc_pfn s_aalloc = aalloc_impl;
afree_pfn s_afree = afree_impl;
arealloc_pfn s_arealloc = arealloc_impl;

#endif // C4_NO_ALLOC_DEFAULTS

} // namespace detail


aalloc_pfn get_aalloc()
{
    return detail::s_aalloc;
}
void set_aalloc(aalloc_pfn fn)
{
    detail::s_aalloc = fn;
}

afree_pfn get_afree()
{
    return detail::s_afree;
}
void set_afree(afree_pfn fn)
{
    detail::s_afree = fn;
}

arealloc_pfn get_arealloc()
{
    return detail::s_arealloc;
}
void set_arealloc(arealloc_pfn fn)
{
    detail::s_arealloc = fn;
}


void* aalloc(size_t sz, size_t alignment)
{
    C4_ASSERT_MSG(c4::get_aalloc() != nullptr, "did you forget to call set_aalloc()?");
    auto fn = c4::get_aalloc();
    void* ptr = fn(sz, alignment);
    return ptr;
}

void afree(void* ptr)
{
    C4_ASSERT_MSG(c4::get_afree() != nullptr, "did you forget to call set_afree()?");
    auto fn = c4::get_afree();
    fn(ptr);
}

void* arealloc(void *ptr, size_t oldsz, size_t newsz, size_t alignment)
{
    C4_ASSERT_MSG(c4::get_arealloc() != nullptr, "did you forget to call set_arealloc()?");
    auto fn = c4::get_arealloc();
    void* nptr = fn(ptr, oldsz, newsz, alignment);
    return nptr;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void detail::_MemoryResourceSingleChunk::release()
{
    if(m_mem && m_owner)
    {
        impl_type::deallocate(m_mem, m_size);
    }
    m_mem = nullptr;
    m_size = 0;
    m_owner = false;
    m_pos = 0;
}

void detail::_MemoryResourceSingleChunk::acquire(size_t sz)
{
    clear();
    m_owner = true;
    m_mem = (char*) impl_type::allocate(sz, alignof(max_align_t));
    m_size = sz;
    m_pos = 0;
}

void detail::_MemoryResourceSingleChunk::acquire(void *mem, size_t sz)
{
    clear();
    m_owner = false;
    m_mem = (char*) mem;
    m_size = sz;
    m_pos = 0;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void* MemoryResourceLinear::do_allocate(size_t sz, size_t alignment, void *hint)
{
    C4_UNUSED(hint);
    if(sz == 0) return nullptr;
    // make sure there's enough room to allocate
    if(m_pos + sz > m_size)
    {
        C4_ERROR("out of memory");
    }
    void *mem = m_mem + m_pos;
    size_t space = m_size - m_pos;
    if(std::align(alignment, sz, mem, space))
    {
        C4_ASSERT(m_pos <= m_size);
        C4_ASSERT(m_size - m_pos >= space);
        m_pos += (m_size - m_pos) - space;
        m_pos += sz;
        C4_ASSERT(m_pos <= m_size);
    }
    else
    {
        C4_ERROR("could not align memory");
    }
    return mem;
}

void MemoryResourceLinear::do_deallocate(void* ptr, size_t sz, size_t alignment)
{
    C4_UNUSED(ptr);
    C4_UNUSED(sz);
    C4_UNUSED(alignment);
    // nothing to do!!
}

void* MemoryResourceLinear::do_reallocate(void* ptr, size_t oldsz, size_t newsz, size_t alignment)
{
    if(newsz == oldsz) return ptr;
    // is ptr the most recently allocated (MRA) block?
    char *cptr = (char*)ptr;
    bool same_pos = (m_mem + m_pos == cptr + oldsz);
    // no need to get more memory when shrinking
    if(newsz < oldsz)
    {
        // if this is the MRA, we can safely shrink the position
        if(same_pos)
        {
            m_pos -= oldsz - newsz;
        }
        return ptr;
    }
    // we're growing the block, and it fits in size
    else if(same_pos && cptr + newsz <= m_mem + m_size)
    {
        // if this is the MRA, we can safely shrink the position
        m_pos += newsz - oldsz;
        return ptr;
    }
    // we're growing the block or it doesn't fit -
    // delegate any of these situations to do_deallocate()
    return do_allocate(newsz, alignment, ptr);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @todo add a free list allocator. A good candidate because of its
 * small size is TLSF.
 *
 * @see https://github.com/mattconte/tlsf
 *
 * Comparisons:
 *
 * @see https://www.researchgate.net/publication/262375150_A_Comparative_Study_on_Memory_Allocators_in_Multicore_and_Multithreaded_Applications_-_SBESC_2011_-_Presentation_Slides
 * @see http://webkit.sed.hu/blog/20100324/war-allocators-tlsf-action
 * @see https://github.com/emeryberger/Malloc-Implementations/tree/master/allocators
 *
 * */

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace c4


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

#ifdef C4_REDEFINE_CPPNEW
#include <new>
void* operator new(size_t size)
{
    auto *mr = ::c4::get_memory_resource();
    return mr->allocate(size);
}
void operator delete(void *p) noexcept
{
    C4_NEVER_REACH();
}
void operator delete(void *p, size_t size)
{
    auto *mr = ::c4::get_memory_resource();
    mr->deallocate(p, size);
}
void* operator new[](size_t size)
{
    return operator new(size);
}
void operator delete[](void *p) noexcept
{
    operator delete(p);
}
void operator delete[](void *p, size_t size)
{
    operator delete(p, size);
}
void* operator new(size_t size, std::nothrow_t)
{
    return operator new(size);
}
void operator delete(void *p, std::nothrow_t)
{
    operator delete(p);
}
void operator delete(void *p, size_t size, std::nothrow_t)
{
    operator delete(p, size);
}
void* operator new[](size_t size, std::nothrow_t)
{
    return operator new(size);
}
void operator delete[](void *p, std::nothrow_t)
{
    operator delete(p);
}
void operator delete[](void *p, size_t, std::nothrow_t)
{
    operator delete(p, size);
}
#endif // C4_REDEFINE_CPPNEW

#endif /* C4CORE_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/c4core/src/c4/memory_resource.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/utf.cpp
// https://github.com/biojppm/c4core/src/c4/utf.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef C4CORE_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/utf.hpp
//#include "c4/utf.hpp"
#if !defined(C4_UTF_HPP_) && !defined(_C4_UTF_HPP_)
#error "amalgamate: file c4/utf.hpp must have been included at this point"
#endif /* C4_UTF_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/charconv.hpp
//#include "c4/charconv.hpp"
#if !defined(C4_CHARCONV_HPP_) && !defined(_C4_CHARCONV_HPP_)
#error "amalgamate: file c4/charconv.hpp must have been included at this point"
#endif /* C4_CHARCONV_HPP_ */


namespace c4 {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")

size_t decode_code_point(uint8_t *C4_RESTRICT buf, size_t buflen, const uint32_t code)
{
    C4_UNUSED(buflen);
    C4_ASSERT(buflen >= 4);
    if (code <= UINT32_C(0x7f))
    {
        buf[0] = (uint8_t)code;
        return 1u;
    }
    else if(code <= UINT32_C(0x7ff))
    {
        buf[0] = (uint8_t)(UINT32_C(0xc0) | (code >> 6));             /* 110xxxxx */
        buf[1] = (uint8_t)(UINT32_C(0x80) | (code & UINT32_C(0x3f))); /* 10xxxxxx */
        return 2u;
    }
    else if(code <= UINT32_C(0xffff))
    {
        buf[0] = (uint8_t)(UINT32_C(0xe0) | ((code >> 12)));                  /* 1110xxxx */
        buf[1] = (uint8_t)(UINT32_C(0x80) | ((code >>  6) & UINT32_C(0x3f))); /* 10xxxxxx */
        buf[2] = (uint8_t)(UINT32_C(0x80) | ((code      ) & UINT32_C(0x3f))); /* 10xxxxxx */
        return 3u;
    }
    else if(code <= UINT32_C(0x10ffff))
    {
        buf[0] = (uint8_t)(UINT32_C(0xf0) | ((code >> 18)));                  /* 11110xxx */
        buf[1] = (uint8_t)(UINT32_C(0x80) | ((code >> 12) & UINT32_C(0x3f))); /* 10xxxxxx */
        buf[2] = (uint8_t)(UINT32_C(0x80) | ((code >>  6) & UINT32_C(0x3f))); /* 10xxxxxx */
        buf[3] = (uint8_t)(UINT32_C(0x80) | ((code      ) & UINT32_C(0x3f))); /* 10xxxxxx */
        return 4u;
    }
    return 0;
}

substr decode_code_point(substr out, csubstr code_point)
{
    C4_ASSERT(out.len >= 4);
    C4_ASSERT(!code_point.begins_with("U+"));
    C4_ASSERT(!code_point.begins_with("\\x"));
    C4_ASSERT(!code_point.begins_with("\\u"));
    C4_ASSERT(!code_point.begins_with("\\U"));
    C4_ASSERT(!code_point.begins_with('0'));
    C4_ASSERT(code_point.len <= 8);
    C4_ASSERT(code_point.len > 0);
    uint32_t code_point_val;
    C4_CHECK(read_hex(code_point, &code_point_val));
    size_t ret = decode_code_point((uint8_t*)out.str, out.len, code_point_val);
    C4_ASSERT(ret <= 4);
    return out.first(ret);
}

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace c4

#endif /* C4CORE_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/c4core/src/c4/utf.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/base64.cpp
// https://github.com/biojppm/c4core/src/c4/base64.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef C4CORE_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/base64.hpp
//#include "c4/base64.hpp"
#if !defined(C4_BASE64_HPP_) && !defined(_C4_BASE64_HPP_)
#error "amalgamate: file c4/base64.hpp must have been included at this point"
#endif /* C4_BASE64_HPP_ */


#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wchar-subscripts" // array subscript is of type 'char'
#   pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wchar-subscripts"
#   pragma GCC diagnostic ignored "-Wtype-limits"
#   pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

namespace c4 {

namespace detail {

constexpr static const char base64_sextet_to_char_[64] = {
    /* 0/ 65*/ 'A', /* 1/ 66*/ 'B', /* 2/ 67*/ 'C', /* 3/ 68*/ 'D',
    /* 4/ 69*/ 'E', /* 5/ 70*/ 'F', /* 6/ 71*/ 'G', /* 7/ 72*/ 'H',
    /* 8/ 73*/ 'I', /* 9/ 74*/ 'J', /*10/ 75*/ 'K', /*11/ 74*/ 'L',
    /*12/ 77*/ 'M', /*13/ 78*/ 'N', /*14/ 79*/ 'O', /*15/ 78*/ 'P',
    /*16/ 81*/ 'Q', /*17/ 82*/ 'R', /*18/ 83*/ 'S', /*19/ 82*/ 'T',
    /*20/ 85*/ 'U', /*21/ 86*/ 'V', /*22/ 87*/ 'W', /*23/ 88*/ 'X',
    /*24/ 89*/ 'Y', /*25/ 90*/ 'Z', /*26/ 97*/ 'a', /*27/ 98*/ 'b',
    /*28/ 99*/ 'c', /*29/100*/ 'd', /*30/101*/ 'e', /*31/102*/ 'f',
    /*32/103*/ 'g', /*33/104*/ 'h', /*34/105*/ 'i', /*35/106*/ 'j',
    /*36/107*/ 'k', /*37/108*/ 'l', /*38/109*/ 'm', /*39/110*/ 'n',
    /*40/111*/ 'o', /*41/112*/ 'p', /*42/113*/ 'q', /*43/114*/ 'r',
    /*44/115*/ 's', /*45/116*/ 't', /*46/117*/ 'u', /*47/118*/ 'v',
    /*48/119*/ 'w', /*49/120*/ 'x', /*50/121*/ 'y', /*51/122*/ 'z',
    /*52/ 48*/ '0', /*53/ 49*/ '1', /*54/ 50*/ '2', /*55/ 51*/ '3',
    /*56/ 52*/ '4', /*57/ 53*/ '5', /*58/ 54*/ '6', /*59/ 55*/ '7',
    /*60/ 56*/ '8', /*61/ 57*/ '9', /*62/ 43*/ '+', /*63/ 47*/ '/',
};

// https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
constexpr static const char base64_char_to_sextet_[128] = {
    #define __ char(-1) // undefined below
    /*  0 NUL*/ __, /*  1 SOH*/ __, /*  2 STX*/ __, /*  3 ETX*/ __,
    /*  4 EOT*/ __, /*  5 ENQ*/ __, /*  6 ACK*/ __, /*  7 BEL*/ __,
    /*  8 BS */ __, /*  9 TAB*/ __, /* 10 LF */ __, /* 11 VT */ __,
    /* 12 FF */ __, /* 13 CR */ __, /* 14 SO */ __, /* 15 SI */ __,
    /* 16 DLE*/ __, /* 17 DC1*/ __, /* 18 DC2*/ __, /* 19 DC3*/ __,
    /* 20 DC4*/ __, /* 21 NAK*/ __, /* 22 SYN*/ __, /* 23 ETB*/ __,
    /* 24 CAN*/ __, /* 25 EM */ __, /* 26 SUB*/ __, /* 27 ESC*/ __,
    /* 28 FS */ __, /* 29 GS */ __, /* 30 RS */ __, /* 31 US */ __,
    /* 32 SPC*/ __, /* 33 !  */ __, /* 34 "  */ __, /* 35 #  */ __,
    /* 36 $  */ __, /* 37 %  */ __, /* 38 &  */ __, /* 39 '  */ __,
    /* 40 (  */ __, /* 41 )  */ __, /* 42 *  */ __, /* 43 +  */ 62,
    /* 44 ,  */ __, /* 45 -  */ __, /* 46 .  */ __, /* 47 /  */ 63,
    /* 48 0  */ 52, /* 49 1  */ 53, /* 50 2  */ 54, /* 51 3  */ 55,
    /* 52 4  */ 56, /* 53 5  */ 57, /* 54 6  */ 58, /* 55 7  */ 59,
    /* 56 8  */ 60, /* 57 9  */ 61, /* 58 :  */ __, /* 59 ;  */ __,
    /* 60 <  */ __, /* 61 =  */ __, /* 62 >  */ __, /* 63 ?  */ __,
    /* 64 @  */ __, /* 65 A  */  0, /* 66 B  */  1, /* 67 C  */  2,
    /* 68 D  */  3, /* 69 E  */  4, /* 70 F  */  5, /* 71 G  */  6,
    /* 72 H  */  7, /* 73 I  */  8, /* 74 J  */  9, /* 75 K  */ 10,
    /* 76 L  */ 11, /* 77 M  */ 12, /* 78 N  */ 13, /* 79 O  */ 14,
    /* 80 P  */ 15, /* 81 Q  */ 16, /* 82 R  */ 17, /* 83 S  */ 18,
    /* 84 T  */ 19, /* 85 U  */ 20, /* 86 V  */ 21, /* 87 W  */ 22,
    /* 88 X  */ 23, /* 89 Y  */ 24, /* 90 Z  */ 25, /* 91 [  */ __,
    /* 92 \  */ __, /* 93 ]  */ __, /* 94 ^  */ __, /* 95 _  */ __,
    /* 96 `  */ __, /* 97 a  */ 26, /* 98 b  */ 27, /* 99 c  */ 28,
    /*100 d  */ 29, /*101 e  */ 30, /*102 f  */ 31, /*103 g  */ 32,
    /*104 h  */ 33, /*105 i  */ 34, /*106 j  */ 35, /*107 k  */ 36,
    /*108 l  */ 37, /*109 m  */ 38, /*110 n  */ 39, /*111 o  */ 40,
    /*112 p  */ 41, /*113 q  */ 42, /*114 r  */ 43, /*115 s  */ 44,
    /*116 t  */ 45, /*117 u  */ 46, /*118 v  */ 47, /*119 w  */ 48,
    /*120 x  */ 49, /*121 y  */ 50, /*122 z  */ 51, /*123 {  */ __,
    /*124 |  */ __, /*125 }  */ __, /*126 ~  */ __, /*127 DEL*/ __,
    #undef __
};

#ifndef NDEBUG
void base64_test_tables()
{
    for(size_t i = 0; i < C4_COUNTOF(detail::base64_sextet_to_char_); ++i)
    {
        char s2c = base64_sextet_to_char_[i];
        char c2s = base64_char_to_sextet_[(int)s2c];
        C4_CHECK((size_t)c2s == i);
    }
    for(size_t i = 0; i < C4_COUNTOF(detail::base64_char_to_sextet_); ++i)
    {
        char c2s = base64_char_to_sextet_[i];
        if(c2s == char(-1))
            continue;
        char s2c = base64_sextet_to_char_[(int)c2s];
        C4_CHECK((size_t)s2c == i);
    }
}
#endif
} // namespace detail


bool base64_valid(csubstr encoded)
{
    if(encoded.len & 3u) // (encoded.len % 4u)
        return false;
    for(const char c : encoded)
    {
        if(c < 0/* || c >= 128*/)
            return false;
        if(c == '=')
            continue;
        if(detail::base64_char_to_sextet_[c] == char(-1))
            return false;
    }
    return true;
}


size_t base64_encode(substr buf, cblob data)
{
    #define c4append_(c) { if(pos < buf.len) { buf.str[pos] = (c); } ++pos; }
    #define c4append_idx_(char_idx) \
    {\
         C4_XASSERT((char_idx) < sizeof(detail::base64_sextet_to_char_));\
         c4append_(detail::base64_sextet_to_char_[(char_idx)]);\
    }
    size_t rem, pos = 0;
    constexpr const uint32_t sextet_mask = uint32_t(1 << 6) - 1;
    const unsigned char *C4_RESTRICT d = (const unsigned char *) data.buf; // cast to unsigned to avoid wrapping high-bits
    for(rem = data.len; rem >= 3; rem -= 3, d += 3)
    {
        const uint32_t val = ((uint32_t(d[0]) << 16) | (uint32_t(d[1]) << 8) | (uint32_t(d[2])));
        c4append_idx_((val >> 18) & sextet_mask);
        c4append_idx_((val >> 12) & sextet_mask);
        c4append_idx_((val >>  6) & sextet_mask);
        c4append_idx_((val      ) & sextet_mask);
    }
    C4_ASSERT(rem < 3);
    if(rem == 2)
    {
        const uint32_t val = ((uint32_t(d[0]) << 16) | (uint32_t(d[1]) << 8));
        c4append_idx_((val >> 18) & sextet_mask);
        c4append_idx_((val >> 12) & sextet_mask);
        c4append_idx_((val >>  6) & sextet_mask);
        c4append_('=');
    }
    else if(rem == 1)
    {
        const uint32_t val = ((uint32_t(d[0]) << 16));
        c4append_idx_((val >> 18) & sextet_mask);
        c4append_idx_((val >> 12) & sextet_mask);
        c4append_('=');
        c4append_('=');
    }
    return pos;

    #undef c4append_
    #undef c4append_idx_
}


size_t base64_decode(csubstr encoded, blob data)
{
    #define c4append_(c) { if(wpos < data.len) { data.buf[wpos] = static_cast<c4::byte>(c); } ++wpos; }
    #define c4appendval_(c, shift)\
    {\
        C4_XASSERT(c >= 0);\
        C4_XASSERT(size_t(c) < sizeof(detail::base64_char_to_sextet_));\
        val |= static_cast<uint32_t>(detail::base64_char_to_sextet_[(c)]) << ((shift) * 6);\
    }
    C4_ASSERT(base64_valid(encoded));
    C4_CHECK((encoded.len & 3u) == 0);
    size_t wpos = 0;  // the write position
    const char *C4_RESTRICT d = encoded.str;
    constexpr const uint32_t full_byte = 0xff;
    // process every quartet of input 6 bits --> triplet of output bytes
    for(size_t rpos = 0; rpos < encoded.len; rpos += 4, d += 4)
    {
        if(d[2] == '=' || d[3] == '=') // skip the last quartet if it is padded
        {
            C4_ASSERT(d + 4 == encoded.str + encoded.len);
            break;
        }
        uint32_t val = 0;
        c4appendval_(d[3], 0);
        c4appendval_(d[2], 1);
        c4appendval_(d[1], 2);
        c4appendval_(d[0], 3);
        c4append_((val >> (2 * 8)) & full_byte);
        c4append_((val >> (1 * 8)) & full_byte);
        c4append_((val           ) & full_byte);
    }
    // deal with the last quartet when it is padded
    if(d == encoded.str + encoded.len)
        return wpos;
    if(d[2] == '=') // 2 padding chars
    {
        C4_ASSERT(d + 4 == encoded.str + encoded.len);
        C4_ASSERT(d[3] == '=');
        uint32_t val = 0;
        c4appendval_(d[1], 2);
        c4appendval_(d[0], 3);
        c4append_((val >> (2 * 8)) & full_byte);
    }
    else if(d[3] == '=') // 1 padding char
    {
        C4_ASSERT(d + 4 == encoded.str + encoded.len);
        uint32_t val = 0;
        c4appendval_(d[2], 1);
        c4appendval_(d[1], 2);
        c4appendval_(d[0], 3);
        c4append_((val >> (2 * 8)) & full_byte);
        c4append_((val >> (1 * 8)) & full_byte);
    }
    return wpos;
    #undef c4append_
    #undef c4appendval_
}

} // namespace c4

#ifdef __clang__
#    pragma clang diagnostic pop
#elif defined(__GNUC__)
#    pragma GCC diagnostic pop
#endif

#endif /* C4CORE_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/c4core/src/c4/base64.cpp)

#define C4_WINDOWS_POP_HPP_



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/windows_push.hpp
// https://github.com/biojppm/c4core/src/c4/windows_push.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_WINDOWS_PUSH_HPP_
#define _C4_WINDOWS_PUSH_HPP_

/** @file windows_push.hpp sets up macros to include windows header files
 * without pulling in all of <windows.h>
 *
 * @see #include windows_pop.hpp to undefine these macros
 *
 * @see https://aras-p.info/blog/2018/01/12/Minimizing-windows.h/ */


#if defined(_WIN64) || defined(_WIN32)

#if defined(_M_AMD64)
#   ifndef _AMD64_
#       define _c4_AMD64_
#       define _AMD64_
#   endif
#elif defined(_M_IX86)
#   ifndef _X86_
#       define _c4_X86_
#       define _X86_
#   endif
#elif defined(_M_ARM64)
#   ifndef _ARM64_
#       define _c4_ARM64_
#       define _ARM64_
#   endif
#elif defined(_M_ARM)
#   ifndef _ARM_
#       define _c4_ARM_
#       define _ARM_
#   endif
#endif

#ifndef NOMINMAX
#    define _c4_NOMINMAX
#    define NOMINMAX
#endif

#ifndef NOGDI
#    define _c4_NOGDI
#    define NOGDI
#endif

#ifndef VC_EXTRALEAN
#    define _c4_VC_EXTRALEAN
#    define VC_EXTRALEAN
#endif

#ifndef WIN32_LEAN_AND_MEAN
#    define _c4_WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#endif

/*  If defined, the following flags inhibit definition
 *     of the indicated items.
 *
 *  NOGDICAPMASKS     - CC_*, LC_*, PC_*, CP_*, TC_*, RC_
 *  NOVIRTUALKEYCODES - VK_*
 *  NOWINMESSAGES     - WM_*, EM_*, LB_*, CB_*
 *  NOWINSTYLES       - WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
 *  NOSYSMETRICS      - SM_*
 *  NOMENUS           - MF_*
 *  NOICONS           - IDI_*
 *  NOKEYSTATES       - MK_*
 *  NOSYSCOMMANDS     - SC_*
 *  NORASTEROPS       - Binary and Tertiary raster ops
 *  NOSHOWWINDOW      - SW_*
 *  OEMRESOURCE       - OEM Resource values
 *  NOATOM            - Atom Manager routines
 *  NOCLIPBOARD       - Clipboard routines
 *  NOCOLOR           - Screen colors
 *  NOCTLMGR          - Control and Dialog routines
 *  NODRAWTEXT        - DrawText() and DT_*
 *  NOGDI             - All GDI defines and routines
 *  NOKERNEL          - All KERNEL defines and routines
 *  NOUSER            - All USER defines and routines
 *  NONLS             - All NLS defines and routines
 *  NOMB              - MB_* and MessageBox()
 *  NOMEMMGR          - GMEM_*, LMEM_*, GHND, LHND, associated routines
 *  NOMETAFILE        - typedef METAFILEPICT
 *  NOMINMAX          - Macros min(a,b) and max(a,b)
 *  NOMSG             - typedef MSG and associated routines
 *  NOOPENFILE        - OpenFile(), OemToAnsi, AnsiToOem, and OF_*
 *  NOSCROLL          - SB_* and scrolling routines
 *  NOSERVICE         - All Service Controller routines, SERVICE_ equates, etc.
 *  NOSOUND           - Sound driver routines
 *  NOTEXTMETRIC      - typedef TEXTMETRIC and associated routines
 *  NOWH              - SetWindowsHook and WH_*
 *  NOWINOFFSETS      - GWL_*, GCL_*, associated routines
 *  NOCOMM            - COMM driver routines
 *  NOKANJI           - Kanji support stuff.
 *  NOHELP            - Help engine interface.
 *  NOPROFILER        - Profiler interface.
 *  NODEFERWINDOWPOS  - DeferWindowPos routines
 *  NOMCX             - Modem Configuration Extensions
 */

#endif /* defined(_WIN64) || defined(_WIN32) */

#endif /* _C4_WINDOWS_PUSH_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/windows_push.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/windows.hpp
// https://github.com/biojppm/c4core/src/c4/windows.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_WINDOWS_HPP_
#define _C4_WINDOWS_HPP_

#if defined(_WIN64) || defined(_WIN32)
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/windows_push.hpp
//#include "c4/windows_push.hpp"
#if !defined(C4_WINDOWS_PUSH_HPP_) && !defined(_C4_WINDOWS_PUSH_HPP_)
#error "amalgamate: file c4/windows_push.hpp must have been included at this point"
#endif /* C4_WINDOWS_PUSH_HPP_ */

#include <windows.h>
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/windows_pop.hpp
//#include "c4/windows_pop.hpp"
#if !defined(C4_WINDOWS_POP_HPP_) && !defined(_C4_WINDOWS_POP_HPP_)
#error "amalgamate: file c4/windows_pop.hpp must have been included at this point"
#endif /* C4_WINDOWS_POP_HPP_ */

#endif

#endif /* _C4_WINDOWS_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/windows.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/windows_pop.hpp
// https://github.com/biojppm/c4core/src/c4/windows_pop.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_WINDOWS_POP_HPP_
#define _C4_WINDOWS_POP_HPP_

#if defined(_WIN64) || defined(_WIN32)

#ifdef _c4_AMD64_
#    undef _c4_AMD64_
#    undef _AMD64_
#endif
#ifdef _c4_X86_
#    undef _c4_X86_
#    undef _X86_
#endif
#ifdef _c4_ARM_
#    undef _c4_ARM_
#    undef _ARM_
#endif

#ifdef _c4_NOMINMAX
#    undef _c4_NOMINMAX
#    undef NOMINMAX
#endif

#ifdef NOGDI
#    undef _c4_NOGDI
#    undef NOGDI
#endif

#ifdef VC_EXTRALEAN
#    undef _c4_VC_EXTRALEAN
#    undef VC_EXTRALEAN
#endif

#ifdef WIN32_LEAN_AND_MEAN
#    undef _c4_WIN32_LEAN_AND_MEAN
#    undef WIN32_LEAN_AND_MEAN
#endif

#endif /* defined(_WIN64) || defined(_WIN32) */

#endif /* _C4_WINDOWS_POP_HPP_ */


// (end https://github.com/biojppm/c4core/src/c4/windows_pop.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/error.cpp
// https://github.com/biojppm/c4core/src/c4/error.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef C4CORE_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */


//included above:
//#include <stdlib.h>
//included above:
//#include <stdio.h>
#include <stdarg.h>

#define C4_LOGF_ERR(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)
#define C4_LOGF_WARN(...) fprintf(stderr, __VA_ARGS__); fflush(stderr)
#define C4_LOGP(msg, ...) printf(msg)

#if defined(C4_XBOX) || (defined(C4_WIN) && defined(C4_MSVC))
// amalgamate: removed include of
// https://github.com/biojppm/c4core/src/c4/windows.hpp
//#   include "c4/windows.hpp"
#if !defined(C4_WINDOWS_HPP_) && !defined(_C4_WINDOWS_HPP_)
#error "amalgamate: file c4/windows.hpp must have been included at this point"
#endif /* C4_WINDOWS_HPP_ */

#elif defined(C4_PS4)
#   include <libdbg.h>
#elif defined(C4_UNIX) || defined(C4_LINUX)
#   include <sys/stat.h>
//included above:
//#   include <cstring>
#   include <fcntl.h>
#elif defined(C4_MACOS) || defined(C4_IOS)
//included above:
//#   include <assert.h>
#   include <stdbool.h>
#   include <sys/types.h>
#   include <sys/sysctl.h>
#endif
// the amalgamation tool is dumb and was omitting this include under MACOS.
// So do it only once:
#if defined(C4_UNIX) || defined(C4_LINUX) || defined(C4_MACOS) || defined(C4_IOS)
#   include <unistd.h>
#endif

#if defined(C4_EXCEPTIONS_ENABLED) && defined(C4_ERROR_THROWS_EXCEPTION)
#   include <exception>
#endif

#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wformat-nonliteral"
#   pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wformat-nonliteral"
#   pragma GCC diagnostic ignored "-Wold-style-cast"
#endif


//-----------------------------------------------------------------------------
namespace c4 {

static error_flags         s_error_flags = ON_ERROR_DEFAULTS;
static error_callback_type s_error_callback = nullptr;


//-----------------------------------------------------------------------------

error_flags get_error_flags()
{
    return s_error_flags;
}
void set_error_flags(error_flags flags)
{
    s_error_flags = flags;
}

error_callback_type get_error_callback()
{
    return s_error_callback;
}
/** Set the function which is called when an error occurs. */
void set_error_callback(error_callback_type cb)
{
    s_error_callback = cb;
}


//-----------------------------------------------------------------------------

void handle_error(srcloc where, const char *fmt, ...)
{
    char buf[1024];
    size_t msglen = 0;
    if(s_error_flags & (ON_ERROR_LOG|ON_ERROR_CALLBACK))
    {
        va_list args;
        va_start(args, fmt);
        int ilen = vsnprintf(buf, sizeof(buf), fmt, args); // ss.vprintf(fmt, args);
        va_end(args);
        msglen = ilen >= 0 && ilen < (int)sizeof(buf) ? static_cast<size_t>(ilen) : sizeof(buf)-1;
    }

    if(s_error_flags & ON_ERROR_LOG)
    {
        C4_LOGF_ERR("\n");
#if defined(C4_ERROR_SHOWS_FILELINE) && defined(C4_ERROR_SHOWS_FUNC)
        C4_LOGF_ERR("%s:%d: ERROR: %s\n", where.file, where.line, buf);
        C4_LOGF_ERR("%s:%d: ERROR here: %s\n", where.file, where.line, where.func);
#elif defined(C4_ERROR_SHOWS_FILELINE)
        C4_LOGF_ERR("%s:%d: ERROR: %s\n", where.file, where.line, buf);
#elif ! defined(C4_ERROR_SHOWS_FUNC)
        C4_LOGF_ERR("ERROR: %s\n", buf);
#endif
    }

    if(s_error_flags & ON_ERROR_CALLBACK)
    {
        if(s_error_callback)
        {
            s_error_callback(buf, msglen);
        }
    }

    if(s_error_flags & ON_ERROR_THROW)
    {
#if defined(C4_EXCEPTIONS_ENABLED) && defined(C4_ERROR_THROWS_EXCEPTION)
        throw std::runtime_error(buf);
#endif
    }

    if(s_error_flags & ON_ERROR_ABORT)
    {
        abort();
    }

    abort(); // abort anyway, in case nothing was set
    C4_UNREACHABLE_AFTER_ERR();
}

//-----------------------------------------------------------------------------

void handle_warning(srcloc where, const char *fmt, ...)
{
    va_list args;
    char buf[1024];
    va_start(args, fmt);
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    C4_LOGF_WARN("\n");
#if defined(C4_ERROR_SHOWS_FILELINE) && defined(C4_ERROR_SHOWS_FUNC)
    C4_LOGF_WARN("%s:%d: WARNING: %s\n", where.file, where.line, buf);
    C4_LOGF_WARN("%s:%d: WARNING: here: %s\n", where.file, where.line, where.func);
#elif defined(C4_ERROR_SHOWS_FILELINE)
    C4_LOGF_WARN("%s:%d: WARNING: %s\n", where.file, where.line, buf);
#elif ! defined(C4_ERROR_SHOWS_FUNC)
    C4_LOGF_WARN("WARNING: %s\n", buf);
#endif
}

//-----------------------------------------------------------------------------
bool is_debugger_attached()
{
#if defined(C4_UNIX) || defined(C4_LINUX)
    static bool first_call = true;
    static bool first_call_result = false;
    if(first_call)
    {
        first_call = false;
        C4_SUPPRESS_WARNING_GCC_PUSH
        #if defined(__GNUC__) && __GNUC__ > 9
        C4_SUPPRESS_WARNING_GCC("-Wanalyzer-fd-leak")
        #endif
        //! @see http://stackoverflow.com/questions/3596781/how-to-detect-if-the-current-process-is-being-run-by-gdb
        //! (this answer: http://stackoverflow.com/a/24969863/3968589 )
        char buf[1024] = "";
        int status_fd = open("/proc/self/status", O_RDONLY);
        if (status_fd == -1)
        {
            return 0;
        }
        else
        {
            ssize_t num_read = ::read(status_fd, buf, sizeof(buf));
            if (num_read > 0)
            {
                static const char TracerPid[] = "TracerPid:";
                char *tracer_pid;
                if(num_read < 1024)
                {
                    buf[num_read] = 0;
                }
                tracer_pid = strstr(buf, TracerPid);
                if (tracer_pid)
                {
                    first_call_result = !!::atoi(tracer_pid + sizeof(TracerPid) - 1);
                }
            }
            close(status_fd);
        }
        C4_SUPPRESS_WARNING_GCC_POP
    }
    return first_call_result;
#elif defined(C4_PS4)
    return (sceDbgIsDebuggerAttached() != 0);
#elif defined(C4_XBOX) || (defined(C4_WIN) && defined(C4_MSVC))
    return IsDebuggerPresent() != 0;
#elif defined(C4_MACOS) || defined(C4_IOS)
    // https://stackoverflow.com/questions/2200277/detecting-debugger-on-mac-os-x
    // Returns true if the current process is being debugged (either
    // running under the debugger or has a debugger attached post facto).
    int                 junk;
    int                 mib[4];
    struct kinfo_proc   info;
    size_t              size;

    // Initialize the flags so that, if sysctl fails for some bizarre
    // reason, we get a predictable result.

    info.kp_proc.p_flag = 0;

    // Initialize mib, which tells sysctl the info we want, in this case
    // we're looking for information about a specific process ID.

    mib[0] = CTL_KERN;
    mib[1] = KERN_PROC;
    mib[2] = KERN_PROC_PID;
    mib[3] = getpid();

    // Call sysctl.

    size = sizeof(info);
    junk = sysctl(mib, sizeof(mib) / sizeof(*mib), &info, &size, NULL, 0);
    assert(junk == 0);
    (void)junk;

    // We're being debugged if the P_TRACED flag is set.
    return ((info.kp_proc.p_flag & P_TRACED) != 0);
#else
    return false;
#endif
} // is_debugger_attached()

} // namespace c4


#ifdef __clang__
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif

#endif /* C4CORE_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/c4core/src/c4/error.cpp)

#endif /* _C4CORE_SINGLE_HEADER_AMALGAMATED_HPP_ */

