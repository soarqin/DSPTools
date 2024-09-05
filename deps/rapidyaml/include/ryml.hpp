#ifndef _RYML_SINGLE_HEADER_AMALGAMATED_HPP_
#define _RYML_SINGLE_HEADER_AMALGAMATED_HPP_

//
// Rapid YAML - a library to parse and emit YAML, and do it fast.
//
// https://github.com/biojppm/rapidyaml
//
// DO NOT EDIT. This file is generated automatically.
// This is an amalgamated single-header version of the library.
//
// INSTRUCTIONS:
//
//   - Include at will in any header of your project. Because the
//     amalgamated header file is large, to speed up compilation of
//     your project, protect the include with its include guard
//     `_RYML_SINGLE_HEADER_AMALGAMATED_HPP_`, ie like this:
//     ```
//     #ifndef _RYML_SINGLE_HEADER_AMALGAMATED_HPP_
//     #include <ryml_all.hpp>
//     #endif
//     ```
//
//   - In one (and only one) of your project source files, #define
//     RYML_SINGLE_HDR_DEFINE_NOW and then include this header. This will enable
//     the function and class definitions in the header file.
//
//   - To compile into a shared library, define the preprocessor symbol
//     RYML_SHARED before including the header. This will take care of
//     symbol export/import.
//
//



//********************************************************************************
//--------------------------------------------------------------------------------
// LICENSE.txt
// https://github.com/biojppm/rapidyaml/LICENSE.txt
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
#if defined(RYML_SHARED) && defined(RYML_SINGLE_HDR_DEFINE_NOW) && !defined(RYML_EXPORTS)
#define RYML_EXPORTS
#endif




//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/export.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/export.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef C4_YML_EXPORT_HPP_
#define C4_YML_EXPORT_HPP_

#ifdef _WIN32
    #ifdef RYML_SHARED
        #ifdef RYML_EXPORTS
            #define RYML_EXPORT __declspec(dllexport)
        #else
            #define RYML_EXPORT __declspec(dllimport)
        #endif
    #else
        #define RYML_EXPORT
    #endif
#else
    #define RYML_EXPORT
#endif

#endif /* C4_YML_EXPORT_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/export.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/fwd.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/fwd.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_FWD_HPP_
#define _C4_YML_FWD_HPP_

/** @file fwd.hpp forward declarations */

namespace c4 {
namespace yml {

struct NodeScalar;
struct NodeInit;
struct NodeData;
struct NodeType;
class NodeRef;
class ConstNodeRef;
class Tree;
struct ReferenceResolver;
template<class EventHandler> class ParseEngine;
struct EventHandlerTree;
using Parser = ParseEngine<EventHandlerTree>;

} // namespace c4
} // namespace yml

#endif /* _C4_YML_FWD_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/fwd.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/version.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/version.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_VERSION_HPP_
#define _C4_YML_VERSION_HPP_

/** @file version.hpp */

#define RYML_VERSION "0.7.2"
#define RYML_VERSION_MAJOR 0
#define RYML_VERSION_MINOR 7
#define RYML_VERSION_PATCH 2

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/substr.hpp
//#include <c4/substr.hpp>
#if !defined(C4_SUBSTR_HPP_) && !defined(_C4_SUBSTR_HPP_)
#error "amalgamate: file c4/substr.hpp must have been included at this point"
#endif /* C4_SUBSTR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/export.hpp
//#include <c4/yml/export.hpp>
#if !defined(C4_YML_EXPORT_HPP_) && !defined(_C4_YML_EXPORT_HPP_)
#error "amalgamate: file c4/yml/export.hpp must have been included at this point"
#endif /* C4_YML_EXPORT_HPP_ */


namespace c4 {
namespace yml {

RYML_EXPORT csubstr version();
RYML_EXPORT int version_major();
RYML_EXPORT int version_minor();
RYML_EXPORT int version_patch();

} // namespace yml
} // namespace c4

#endif /* _C4_YML_VERSION_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/version.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/common.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/common.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_COMMON_HPP_
#define _C4_YML_COMMON_HPP_

/** @file common.hpp Common utilities and infrastructure used by ryml. */

#include <cstddef>
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/substr.hpp
//#include <c4/substr.hpp>
#if !defined(C4_SUBSTR_HPP_) && !defined(_C4_SUBSTR_HPP_)
#error "amalgamate: file c4/substr.hpp must have been included at this point"
#endif /* C4_SUBSTR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/dump.hpp
//#include <c4/dump.hpp>
#if !defined(C4_DUMP_HPP_) && !defined(_C4_DUMP_HPP_)
#error "amalgamate: file c4/dump.hpp must have been included at this point"
#endif /* C4_DUMP_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/export.hpp
//#include <c4/yml/export.hpp>
#if !defined(C4_YML_EXPORT_HPP_) && !defined(_C4_YML_EXPORT_HPP_)
#error "amalgamate: file c4/yml/export.hpp must have been included at this point"
#endif /* C4_YML_EXPORT_HPP_ */


#if defined(C4_MSVC) || defined(C4_MINGW)
#include <malloc.h>
#else
#include <alloca.h>
#endif



//-----------------------------------------------------------------------------

#ifndef RYML_ERRMSG_SIZE
/// size for the error message buffer
#define RYML_ERRMSG_SIZE (1024)
#endif

#ifndef RYML_LOGBUF_SIZE
/// size for the buffer used to format individual values to string
/// while preparing an error message. This is only used for formatting
/// individual values in the message; final messages will be larger
/// than this value (see @ref RYML_ERRMSG_SIZE). This is also used for
/// the detailed debug log messages when RYML_DBG is defined.
#define RYML_LOGBUF_SIZE (256)
#endif

#ifndef RYML_LOGBUF_SIZE_MAX
/// size for the fallback larger log buffer. When @ref
/// RYML_LOGBUF_SIZE is not large enough to convert a value to string,
/// then temporary stack memory is allocated up to
/// RYML_LOGBUF_SIZE_MAX. This limit is in place to prevent a stack
/// overflow. If the printed value requires more than
/// RYML_LOGBUF_SIZE_MAX, the value is silently skipped.
#define RYML_LOGBUF_SIZE_MAX (1024)
#endif

#ifndef RYML_LOCATIONS_SMALL_THRESHOLD
/// threshold at which a location search will revert from linear to
/// binary search.
#define RYML_LOCATIONS_SMALL_THRESHOLD (30)
#endif


//-----------------------------------------------------------------------------
// Specify groups to have a predefined topic order in doxygen:

/** @defgroup doc_quickstart Quickstart
 *
 * Example code for every feature.
 */

/** @defgroup doc_parse Parse utilities
 * @see sample::sample_parse_in_place
 * @see sample::sample_parse_in_arena
 * @see sample::sample_parse_file
 * @see sample::sample_parse_reuse_tree
 * @see sample::sample_parse_reuse_parser
 * @see sample::sample_parse_reuse_tree_and_parser
 * @see sample::sample_location_tracking
 */

/** @defgroup doc_emit Emit utilities
 *
 * Utilities to emit YAML and JSON, either to a memory buffer or to a
 * file or ostream-like class.
 *
 * @see sample::sample_emit_to_container
 * @see sample::sample_emit_to_stream
 * @see sample::sample_emit_to_file
 * @see sample::sample_emit_nested_node
 * @see sample::sample_emit_style
 */

/** @defgroup doc_node_type Node types
 */

/** @defgroup doc_tree Tree utilities
 * @see sample::sample_quick_overview
 * @see sample::sample_iterate_trees
 * @see sample::sample_create_trees
 * @see sample::sample_tree_arena
 *
 * @see sample::sample_static_trees
 * @see sample::sample_location_tracking
 *
 * @see sample::sample_docs
 * @see sample::sample_anchors_and_aliases
 * @see sample::sample_tags
 */

/** @defgroup doc_node_classes Node classes
 *
 * High-level node classes.
 *
 * @see sample::sample_quick_overview
 * @see sample::sample_iterate_trees
 * @see sample::sample_create_trees
 * @see sample::sample_tree_arena
 */

/** @defgroup doc_callbacks Callbacks for errors and allocation
 *
 * Functions called by ryml to allocate/free memory and to report
 * errors.
 *
 * @see sample::sample_error_handler
 * @see sample::sample_global_allocator
 * @see sample::sample_per_tree_allocator
 */

/** @defgroup doc_serialization Serialization/deserialization
 *
 * Contains information on how to serialize and deserialize
 * fundamental types, user scalar types, user container types and
 * interop with std scalar/container types.
 *
 */

/** @defgroup doc_ref_utils Anchor/Reference utilities
 *
 * @see sample::sample_anchors_and_aliases
 * */

/** @defgroup doc_tag_utils Tag utilities
 * @see sample::sample_tags
 */

/** @defgroup doc_preprocessors Preprocessors
 *
 * Functions for preprocessing YAML prior to parsing.
 */


//-----------------------------------------------------------------------------

// document macros for doxygen
#ifdef __DOXYGEN__ // defined in Doxyfile::PREDEFINED

/** define this macro with a boolean value to enable/disable
 * assertions to check preconditions and assumptions throughout the
 * codebase; this causes a slowdown of the code, and larger code
 * size. By default, this macro is defined unless NDEBUG is defined
 * (see C4_USE_ASSERT); as a result, by default this macro is truthy
 * only in debug builds. */
#   define RYML_USE_ASSERT

/** (Undefined by default) Define this macro to disable ryml's default
 * implementation of the callback functions; see @ref c4::yml::Callbacks  */
#   define RYML_NO_DEFAULT_CALLBACKS

/** (Undefined by default) When this macro is defined (and
 * @ref RYML_NO_DEFAULT_CALLBACKS is not defined), the default error
 * handler will throw C++ exceptions of type `std::runtime_error`. */
#   define RYML_DEFAULT_CALLBACK_USES_EXCEPTIONS

/** Conditionally expands to `noexcept` when @ref RYML_USE_ASSERT is 0 and
 * is empty otherwise. The user is unable to override this macro. */
#   define RYML_NOEXCEPT

#endif


//-----------------------------------------------------------------------------


/** @cond dev*/
#ifndef RYML_USE_ASSERT
#   define RYML_USE_ASSERT C4_USE_ASSERT
#endif

#if RYML_USE_ASSERT
#   define RYML_ASSERT(cond) RYML_CHECK(cond)
#   define RYML_ASSERT_MSG(cond, msg) RYML_CHECK_MSG(cond, msg)
#   define _RYML_CB_ASSERT(cb, cond) _RYML_CB_CHECK((cb), (cond))
#   define _RYML_CB_ASSERT_(cb, cond, loc) _RYML_CB_CHECK((cb), (cond), (loc))
#   define RYML_NOEXCEPT
#else
#   define RYML_ASSERT(cond)
#   define RYML_ASSERT_MSG(cond, msg)
#   define _RYML_CB_ASSERT(cb, cond)
#   define _RYML_CB_ASSERT_(cb, cond, loc)
#   define RYML_NOEXCEPT noexcept
#endif

#define RYML_DEPRECATED(msg) C4_DEPRECATED(msg)

#define RYML_CHECK(cond)                                                \
    do {                                                                \
        if(C4_UNLIKELY(!(cond)))                                        \
        {                                                               \
            RYML_DEBUG_BREAK();                                         \
            c4::yml::error("check failed: " #cond, c4::yml::Location(__FILE__, __LINE__, 0)); \
            C4_UNREACHABLE_AFTER_ERR();                                 \
        }                                                               \
    } while(0)

#define RYML_CHECK_MSG(cond, msg)                                       \
    do                                                                  \
    {                                                                   \
        if(C4_UNLIKELY(!(cond)))                                        \
        {                                                               \
            RYML_DEBUG_BREAK();                                         \
            c4::yml::error(msg ": check failed: " #cond, c4::yml::Location(__FILE__, __LINE__, 0)); \
            C4_UNREACHABLE_AFTER_ERR();                                 \
        }                                                               \
    } while(0)

#if defined(RYML_DBG) && !defined(NDEBUG) && !defined(C4_NO_DEBUG_BREAK)
#   define RYML_DEBUG_BREAK()                               \
    do {                                                    \
        if(c4::get_error_flags() & c4::ON_ERROR_DEBUGBREAK) \
        {                                                   \
            C4_DEBUG_BREAK();                               \
        }                                                   \
    } while(0)
#else
#   define RYML_DEBUG_BREAK()
#endif

/** @endcond */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

namespace c4 {
namespace yml {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")


#ifndef RYML_ID_TYPE
/** The type of a node id in the YAML tree. In the future, the default
 * will likely change to int32_t, which was observed to be faster.
 * @see id_type */
#define RYML_ID_TYPE size_t
#endif


/** The type of a node id in the YAML tree; to override the default
 * type, define the macro @ref RYML_ID_TYPE to a suitable integer
 * type. */
using id_type = RYML_ID_TYPE;
static_assert(std::is_integral<id_type>::value, "id_type must be an integer type");


C4_SUPPRESS_WARNING_GCC_WITH_PUSH("-Wuseless-cast")
enum : id_type {
    /** an index to none */
    NONE = id_type(-1),
};
C4_SUPPRESS_WARNING_GCC_CLANG_POP


enum : size_t {
    /** a null string position */
    npos = size_t(-1)
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//! holds a position into a source buffer
struct RYML_EXPORT LineCol
{
    //! number of bytes from the beginning of the source buffer
    size_t offset;
    //! line
    size_t line;
    //! column
    size_t col;

    LineCol() = default;
    //! construct from line and column
    LineCol(size_t l, size_t c) : offset(0), line(l), col(c) {}
    //! construct from offset, line and column
    LineCol(size_t o, size_t l, size_t c) : offset(o), line(l), col(c) {}
};
static_assert(std::is_trivial<LineCol>::value, "LineCol not trivial");
static_assert(std::is_standard_layout<LineCol>::value, "Location not trivial");


//! a source file position
struct RYML_EXPORT Location
{
    //! number of bytes from the beginning of the source buffer
    size_t offset;
    //! line
    size_t line;
    //! column
    size_t col;
    //! file name
    csubstr name;

    operator bool () const { return !name.empty() || line != 0 || offset != 0 || col != 0; }
    operator LineCol const& () const { return reinterpret_cast<LineCol const&>(*this); }

    Location() = default;
    Location(                         size_t l, size_t c) : offset( ), line(l), col(c), name( ) {}
    Location(               size_t b, size_t l, size_t c) : offset(b), line(l), col(c), name( ) {}
    Location(    csubstr n,           size_t l, size_t c) : offset( ), line(l), col(c), name(n) {}
    Location(    csubstr n, size_t b, size_t l, size_t c) : offset(b), line(l), col(c), name(n) {}
    Location(const char *n,           size_t l, size_t c) : offset( ), line(l), col(c), name(to_csubstr(n)) {}
    Location(const char *n, size_t b, size_t l, size_t c) : offset(b), line(l), col(c), name(to_csubstr(n)) {}
};
static_assert(std::is_standard_layout<Location>::value, "Location not trivial");


//-----------------------------------------------------------------------------

/** @addtogroup doc_callbacks
 *
 * @{ */

struct Callbacks;


/** set the global callbacks for the library; after a call to this
 * function, these callbacks will be used by newly created objects
 * (unless they are copying older objects with different
 * callbacks). If @ref RYML_NO_DEFAULT_CALLBACKS is defined, it is
 * mandatory to call this function prior to using any other library
 * facility.
 *
 * @warning This function is NOT thread-safe.
 *
 * @warning the error callback must never return: see @ref pfn_error
 * for more details */
RYML_EXPORT void set_callbacks(Callbacks const& c);

/** get the global callbacks
 * @warning This function is not thread-safe. */
RYML_EXPORT Callbacks const& get_callbacks();

/** set the global callbacks back to their defaults ()
 * @warning This function is not thread-safe. */
RYML_EXPORT void reset_callbacks();


/** the type of the function used to report errors
 *
 * @warning When given by the user, this function MUST interrupt
 * execution, typically by either throwing an exception, or using
 * `std::longjmp()` ([see
 * documentation](https://en.cppreference.com/w/cpp/utility/program/setjmp))
 * or by calling `std::abort()`. If the function returned, the parser
 * would enter into an infinite loop, or the program may crash. */
using pfn_error = void (*) (const char* msg, size_t msg_len, Location location, void *user_data);


/** the type of the function used to allocate memory; ryml will only
 * allocate memory through this callback. */
using pfn_allocate = void* (*)(size_t len, void* hint, void *user_data);


/** the type of the function used to free memory; ryml will only free
 * memory through this callback. */
using pfn_free = void (*)(void* mem, size_t size, void *user_data);


/** a c-style callbacks class. Can be used globally by the library
 * and/or locally by @ref Tree and @ref Parser objects. */
struct RYML_EXPORT Callbacks
{
    void *       m_user_data;
    pfn_allocate m_allocate;
    pfn_free     m_free;
    pfn_error    m_error;

    /** Construct an object with the default callbacks. If
     * @ref RYML_NO_DEFAULT_CALLBACKS is defined, the object will have null
     * members.*/
    Callbacks();

    /** Construct an object with the given callbacks.
     *
     * @param user_data Data to be forwarded in every call to a callback.
     *
     * @param alloc A pointer to an allocate function. Unless
     *        @ref RYML_NO_DEFAULT_CALLBACKS is defined, when this
     *        parameter is null, will fall back to ryml's default
     *        alloc implementation.
     *
     * @param free A pointer to a free function. Unless
     *        @ref RYML_NO_DEFAULT_CALLBACKS is defined, when this
     *        parameter is null, will fall back to ryml's default free
     *        implementation.
     *
     * @param error A pointer to an error function, which must never
     *        return (see @ref pfn_error). Unless
     *        @ref RYML_NO_DEFAULT_CALLBACKS is defined, when this
     *        parameter is null, will fall back to ryml's default
     *        error implementation.
     */
    Callbacks(void *user_data, pfn_allocate alloc, pfn_free free, pfn_error error);

    bool operator!= (Callbacks const& that) const { return !operator==(that); }
    bool operator== (Callbacks const& that) const
    {
        return (m_user_data == that.m_user_data &&
                m_allocate == that.m_allocate &&
                m_free == that.m_free &&
                m_error == that.m_error);
    }
};


/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/// @cond dev

// BEWARE! MSVC requires that [[noreturn]] appears before RYML_EXPORT
[[noreturn]] RYML_EXPORT void error(Callbacks const& cb, const char *msg, size_t msg_len, Location loc);
[[noreturn]] RYML_EXPORT void error(const char *msg, size_t msg_len, Location loc);

[[noreturn]] inline void error(const char *msg, size_t msg_len)
{
    error(msg, msg_len, Location{});
}
template<size_t N>
[[noreturn]] inline void error(const char (&msg)[N], Location loc)
{
    error(msg, N-1, loc);
}
template<size_t N>
[[noreturn]] inline void error(const char (&msg)[N])
{
    error(msg, N-1, Location{});
}

#define _RYML_CB_ERR(cb, msg_literal)                                   \
    _RYML_CB_ERR_(cb, msg_literal, c4::yml::Location(__FILE__, 0, __LINE__, 0))
#define _RYML_CB_CHECK(cb, cond)                                        \
    _RYML_CB_CHECK_(cb, cond, c4::yml::Location(__FILE__, 0, __LINE__, 0))
#define _RYML_CB_ERR_(cb, msg_literal, loc)                             \
do                                                                      \
{                                                                       \
    const char msg[] = msg_literal;                                     \
    RYML_DEBUG_BREAK();                                                 \
    c4::yml::error((cb), msg, sizeof(msg)-1, loc);                      \
    C4_UNREACHABLE_AFTER_ERR();                                         \
} while(0)
#define _RYML_CB_CHECK_(cb, cond, loc)                                  \
    do                                                                  \
    {                                                                   \
        if(C4_UNLIKELY(!(cond)))                                        \
        {                                                               \
            const char msg[] = "check failed: " #cond;                  \
            RYML_DEBUG_BREAK();                                         \
            c4::yml::error((cb), msg, sizeof(msg)-1, loc);              \
            C4_UNREACHABLE_AFTER_ERR();                                 \
        }                                                               \
    } while(0)
#define _RYML_CB_ALLOC_HINT(cb, T, num, hint) (T*) (cb).m_allocate((num) * sizeof(T), (hint), (cb).m_user_data)
#define _RYML_CB_ALLOC(cb, T, num) _RYML_CB_ALLOC_HINT((cb), T, (num), nullptr)
#define _RYML_CB_FREE(cb, buf, T, num)                              \
    do {                                                            \
        (cb).m_free((buf), (num) * sizeof(T), (cb).m_user_data);    \
        (buf) = nullptr;                                            \
    } while(0)



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

typedef enum {
    BLOCK_LITERAL, //!< keep newlines (|)
    BLOCK_FOLD     //!< replace newline with single space (>)
} BlockStyle_e;

typedef enum {
    CHOMP_CLIP,    //!< single newline at end (default)
    CHOMP_STRIP,   //!< no newline at end     (-)
    CHOMP_KEEP     //!< all newlines from end (+)
} BlockChomp_e;


/** Abstracts the fact that a scalar filter result may not fit in the
 * intended memory. */
struct FilterResult
{
    C4_ALWAYS_INLINE bool valid() const noexcept { return str.str != nullptr; }
    C4_ALWAYS_INLINE size_t required_len() const noexcept { return str.len; }
    C4_ALWAYS_INLINE csubstr get() { RYML_ASSERT(valid()); return str; }
    csubstr str;
};
/** Abstracts the fact that a scalar filter result may not fit in the
 * intended memory. */
struct FilterResultExtending
{
    C4_ALWAYS_INLINE bool valid() const noexcept { return str.str != nullptr; }
    C4_ALWAYS_INLINE size_t required_len() const noexcept { return reqlen; }
    C4_ALWAYS_INLINE csubstr get() { RYML_ASSERT(valid()); return str; }
    csubstr str;
    size_t reqlen;
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


namespace detail {
// is there a better way to do this?
template<int8_t signedval, uint8_t unsignedval>
struct _charconstant_t
    : public std::conditional<std::is_signed<char>::value,
                              std::integral_constant<int8_t, signedval>,
                              std::integral_constant<uint8_t, unsignedval>>::type
{};
#define _RYML_CHCONST(signedval, unsignedval) ::c4::yml::detail::_charconstant_t<INT8_C(signedval), UINT8_C(unsignedval)>::value
} // namespace detail


namespace detail {
struct _SubstrWriter
{
    substr buf;
    size_t pos;
    _SubstrWriter(substr buf_, size_t pos_=0) : buf(buf_), pos(pos_) { C4_ASSERT(buf.str); }
    void append(csubstr s)
    {
        C4_ASSERT(!s.overlaps(buf));
        C4_ASSERT(s.str || !s.len);
        if(s.len && pos + s.len <= buf.len)
        {
            C4_ASSERT(s.str);
            memcpy(buf.str + pos, s.str, s.len);
        }
        pos += s.len;
    }
    void append(char c)
    {
        C4_ASSERT(buf.str);
        if(pos < buf.len)
            buf.str[pos] = c;
        ++pos;
    }
    void append_n(char c, size_t numtimes)
    {
        C4_ASSERT(buf.str);
        if(numtimes && pos + numtimes < buf.len)
            memset(buf.str + pos, c, numtimes);
        pos += numtimes;
    }
    size_t slack() const { return pos <= buf.len ? buf.len - pos : 0; }
    size_t excess() const { return pos > buf.len ? pos - buf.len : 0; }
    //! get the part written so far
    csubstr curr() const { return pos <= buf.len ? buf.first(pos) : buf; }
    //! get the part that is still free to write to (the remainder)
    substr rem() { return pos < buf.len ? buf.sub(pos) : buf.last(0); }

    size_t advance(size_t more) { pos += more; return pos; }
};
} // namespace detail


namespace detail {
// dumpfn is a function abstracting prints to terminal (or to string).
template<class DumpFn, class ...Args>
C4_NO_INLINE void _dump(DumpFn &&dumpfn, csubstr fmt, Args&& ...args)
{
    DumpResults results;
    // try writing everything:
    {
        // buffer for converting individual arguments. it is defined
        // in a child scope to free it in case the buffer is too small
        // for any of the arguments.
        char writebuf[RYML_LOGBUF_SIZE];
        results = format_dump_resume(std::forward<DumpFn>(dumpfn), writebuf, fmt, std::forward<Args>(args)...);
    }
    // if any of the arguments failed to fit the buffer, allocate a
    // larger buffer (up to a limit) and resume writing.
    //
    // results.bufsize is set to the size of the largest element
    // serialized. Eg int(1) will require 1 byte.
    if(C4_UNLIKELY(results.bufsize > RYML_LOGBUF_SIZE))
    {
        const size_t bufsize = results.bufsize <= RYML_LOGBUF_SIZE_MAX ? results.bufsize : RYML_LOGBUF_SIZE_MAX;
        #ifdef C4_MSVC
        substr largerbuf = {static_cast<char*>(_alloca(bufsize)), bufsize};
        #else
        substr largerbuf = {static_cast<char*>(alloca(bufsize)), bufsize};
        #endif
        results = format_dump_resume(std::forward<DumpFn>(dumpfn), results, largerbuf, fmt, std::forward<Args>(args)...);
    }
}
template<class ...Args>
C4_NORETURN C4_NO_INLINE void _report_err(Callbacks const& C4_RESTRICT callbacks, csubstr fmt, Args const& C4_RESTRICT ...args)
{
    char errmsg[RYML_ERRMSG_SIZE] = {0};
    detail::_SubstrWriter writer(errmsg);
    auto dumpfn = [&writer](csubstr s){ writer.append(s); };
    _dump(dumpfn, fmt, args...);
    writer.append('\n');
    const size_t len = writer.pos < RYML_ERRMSG_SIZE ? writer.pos : RYML_ERRMSG_SIZE;
    callbacks.m_error(errmsg, len, {}, callbacks.m_user_data);
    C4_UNREACHABLE_AFTER_ERR();
}
} // namespace detail


inline csubstr _c4prc(const char &C4_RESTRICT c) // pass by reference!
{
    switch(c)
    {
    case '\n': return csubstr("\\n");
    case '\t': return csubstr("\\t");
    case '\0': return csubstr("\\0");
    case '\r': return csubstr("\\r");
    case '\f': return csubstr("\\f");
    case '\b': return csubstr("\\b");
    case '\v': return csubstr("\\v");
    case '\a': return csubstr("\\a");
    default: return csubstr(&c, 1);
    }
}

/// @endcond

C4_SUPPRESS_WARNING_GCC_POP

} // namespace yml
} // namespace c4

#endif /* _C4_YML_COMMON_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/common.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/node_type.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/node_type.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef C4_YML_NODE_TYPE_HPP_
#define C4_YML_NODE_TYPE_HPP_

#ifndef _C4_YML_COMMON_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/common.hpp
//#include "c4/yml/common.hpp"
#if !defined(C4_YML_COMMON_HPP_) && !defined(_C4_YML_COMMON_HPP_)
#error "amalgamate: file c4/yml/common.hpp must have been included at this point"
#endif /* C4_YML_COMMON_HPP_ */

#endif

C4_SUPPRESS_WARNING_MSVC_PUSH
C4_SUPPRESS_WARNING_GCC_CLANG_PUSH
C4_SUPPRESS_WARNING_GCC_CLANG("-Wold-style-cast")

namespace c4 {
namespace yml {

/** @addtogroup doc_node_type
 *
 * @{
 */

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


/** the integral type necessary to cover all the bits for NodeType_e */
using type_bits = uint32_t;


/** a bit mask for marking node types and styles */
typedef enum : type_bits {
    #define __(v) (type_bits(1) << v) // a convenience define, undefined below
    NOTYPE  = 0,         ///< no node type or style is set
    KEY     = __(0),     ///< is member of a map, must have non-empty key
    VAL     = __(1),     ///< a scalar: has a scalar (ie string) value, possibly empty. must be a leaf node, and cannot be MAP or SEQ
    MAP     = __(2),     ///< a map: a parent of KEYVAL/KEYSEQ/KEYMAP nodes
    SEQ     = __(3),     ///< a seq: a parent of VAL/SEQ/MAP nodes
    DOC     = __(4),     ///< a document
    STREAM  = __(5)|SEQ, ///< a stream: a seq of docs
    KEYREF  = __(6),     ///< a *reference: the key references an &anchor
    VALREF  = __(7),     ///< a *reference: the val references an &anchor
    KEYANCH = __(8),     ///< the key has an &anchor
    VALANCH = __(9),     ///< the val has an &anchor
    KEYTAG  = __(10),    ///< the key has a tag
    VALTAG  = __(11),    ///< the val has a tag
    _TYMASK = __(12)-1,  ///< all the bits up to here
    //
    // unfiltered flags:
    //
    KEY_UNFILT  = __(12), ///< the key scalar was left unfiltered; the parser was set not to filter. @see ParserOptions
    VAL_UNFILT  = __(13), ///< the val scalar was left unfiltered; the parser was set not to filter. @see ParserOptions
    //
    // style flags:
    //
    FLOW_SL     = __(14), ///< mark container with single-line flow style (seqs as '[val1,val2], maps as '{key: val,key2: val2}')
    FLOW_ML     = __(15), ///< (NOT IMPLEMENTED, work in progress) mark container with multi-line flow style (seqs as '[\n  val1,\n  val2\n], maps as '{\n  key: val,\n  key2: val2\n}')
    BLOCK       = __(16), ///< mark container with block style (seqs as '- val\n', maps as 'key: val')
    KEY_LITERAL = __(17), ///< mark key scalar as multiline, block literal |
    VAL_LITERAL = __(18), ///< mark val scalar as multiline, block literal |
    KEY_FOLDED  = __(19), ///< mark key scalar as multiline, block folded >
    VAL_FOLDED  = __(20), ///< mark val scalar as multiline, block folded >
    KEY_SQUO    = __(21), ///< mark key scalar as single quoted '
    VAL_SQUO    = __(22), ///< mark val scalar as single quoted '
    KEY_DQUO    = __(23), ///< mark key scalar as double quoted "
    VAL_DQUO    = __(24), ///< mark val scalar as double quoted "
    KEY_PLAIN   = __(25), ///< mark key scalar as plain scalar (unquoted, even when multiline)
    VAL_PLAIN   = __(26), ///< mark val scalar as plain scalar (unquoted, even when multiline)
    //
    // type combination masks:
    //
    KEYVAL  = KEY|VAL,
    KEYSEQ  = KEY|SEQ,
    KEYMAP  = KEY|MAP,
    DOCMAP  = DOC|MAP,
    DOCSEQ  = DOC|SEQ,
    DOCVAL  = DOC|VAL,
    //
    // style combination masks:
    //
    SCALAR_LITERAL = KEY_LITERAL|VAL_LITERAL,
    SCALAR_FOLDED  = KEY_FOLDED|VAL_FOLDED,
    SCALAR_SQUO    = KEY_SQUO|VAL_SQUO,
    SCALAR_DQUO    = KEY_DQUO|VAL_DQUO,
    SCALAR_PLAIN   = KEY_PLAIN|VAL_PLAIN,
    KEYQUO         = KEY_SQUO|KEY_DQUO|KEY_FOLDED|KEY_LITERAL, ///< key style is one of ', ", > or |
    VALQUO         = VAL_SQUO|VAL_DQUO|VAL_FOLDED|VAL_LITERAL, ///< val style is one of ', ", > or |
    KEY_STYLE      = KEY_LITERAL|KEY_FOLDED|KEY_SQUO|KEY_DQUO|KEY_PLAIN, ///< mask of all the scalar styles for key (not container styles!)
    VAL_STYLE      = VAL_LITERAL|VAL_FOLDED|VAL_SQUO|VAL_DQUO|VAL_PLAIN, ///< mask of all the scalar styles for val (not container styles!)
    SCALAR_STYLE   = KEY_STYLE|VAL_STYLE,
    CONTAINER_STYLE_FLOW  = FLOW_SL|FLOW_ML,
    CONTAINER_STYLE_BLOCK = BLOCK,
    CONTAINER_STYLE       = FLOW_SL|FLOW_ML|BLOCK,
    STYLE          = SCALAR_STYLE | CONTAINER_STYLE,
    //
    // mixed masks
    _KEYMASK = KEY | KEYQUO | KEYANCH | KEYREF | KEYTAG,
    _VALMASK = VAL | VALQUO | VALANCH | VALREF | VALTAG,
    #undef __
} NodeType_e;

constexpr C4_ALWAYS_INLINE C4_CONST NodeType_e operator|  (NodeType_e lhs, NodeType_e rhs) noexcept { return (NodeType_e)(((type_bits)lhs) | ((type_bits)rhs)); }
constexpr C4_ALWAYS_INLINE C4_CONST NodeType_e operator&  (NodeType_e lhs, NodeType_e rhs) noexcept { return (NodeType_e)(((type_bits)lhs) & ((type_bits)rhs)); }
constexpr C4_ALWAYS_INLINE C4_CONST NodeType_e operator>> (NodeType_e bits, uint32_t n) noexcept { return (NodeType_e)(((type_bits)bits) >> n); }
constexpr C4_ALWAYS_INLINE C4_CONST NodeType_e operator<< (NodeType_e bits, uint32_t n) noexcept { return (NodeType_e)(((type_bits)bits) << n); }
constexpr C4_ALWAYS_INLINE C4_CONST NodeType_e operator~  (NodeType_e bits) noexcept { return (NodeType_e)(~(type_bits)bits); }
C4_ALWAYS_INLINE NodeType_e& operator&= (NodeType_e &subject, NodeType_e bits) noexcept { subject = (NodeType_e)((type_bits)subject & (type_bits)bits); return subject; }
C4_ALWAYS_INLINE NodeType_e& operator|= (NodeType_e &subject, NodeType_e bits) noexcept { subject = (NodeType_e)((type_bits)subject | (type_bits)bits); return subject; }


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** wraps a NodeType_e element with some syntactic sugar and predicates */
struct RYML_EXPORT NodeType
{
public:

    NodeType_e type;

public:

    C4_ALWAYS_INLINE NodeType() noexcept : type(NOTYPE) {}
    C4_ALWAYS_INLINE NodeType(NodeType_e t) noexcept : type(t) {}
    C4_ALWAYS_INLINE NodeType(type_bits t) noexcept : type((NodeType_e)t) {}

    C4_ALWAYS_INLINE bool has_any(NodeType_e t) const noexcept { return (type & t) != 0u; }
    C4_ALWAYS_INLINE bool has_all(NodeType_e t) const noexcept { return (type & t) == t; }
    C4_ALWAYS_INLINE bool has_none(NodeType_e t) const noexcept { return (type & t) == 0; }

    C4_ALWAYS_INLINE void set(NodeType_e t) noexcept { type = t; }
    C4_ALWAYS_INLINE void add(NodeType_e t) noexcept { type = (type|t); }
    C4_ALWAYS_INLINE void rem(NodeType_e t) noexcept { type = (type & ~t); }
    C4_ALWAYS_INLINE void addrem(NodeType_e bits_to_add, NodeType_e bits_to_remove) noexcept { type |= bits_to_add; type &= ~bits_to_remove; }

    C4_ALWAYS_INLINE void clear() noexcept { type = NOTYPE; }

public:

    C4_ALWAYS_INLINE operator NodeType_e      & C4_RESTRICT ()       noexcept { return type; }
    C4_ALWAYS_INLINE operator NodeType_e const& C4_RESTRICT () const noexcept { return type; }

public:

    /** @name node type queries
     * @{ */

    /** return a preset string based on the node type */
    C4_ALWAYS_INLINE const char *type_str() const noexcept { return type_str(type); }
    /** return a preset string based on the node type */
    static const char* type_str(NodeType_e t) noexcept;

    /** fill a string with the node type flags. If the string is small, returns {null, len} */
    C4_ALWAYS_INLINE csubstr type_str(substr buf) const noexcept { return type_str(buf, type); }
    /** fill a string with the node type flags. If the string is small, returns {null, len}  */
    static csubstr type_str(substr buf, NodeType_e t) noexcept;

public:

    /** @name node type queries
     * @{ */

    C4_ALWAYS_INLINE bool is_notype()         const noexcept { return type == NOTYPE; }
    C4_ALWAYS_INLINE bool is_stream()         const noexcept { return ((type & STREAM) == STREAM) != 0; }
    C4_ALWAYS_INLINE bool is_doc()            const noexcept { return (type & DOC) != 0; }
    C4_ALWAYS_INLINE bool is_container()      const noexcept { return (type & (MAP|SEQ|STREAM)) != 0; }
    C4_ALWAYS_INLINE bool is_map()            const noexcept { return (type & MAP) != 0; }
    C4_ALWAYS_INLINE bool is_seq()            const noexcept { return (type & SEQ) != 0; }
    C4_ALWAYS_INLINE bool has_key()           const noexcept { return (type & KEY) != 0; }
    C4_ALWAYS_INLINE bool has_val()           const noexcept { return (type & VAL) != 0; }
    C4_ALWAYS_INLINE bool is_val()            const noexcept { return (type & KEYVAL) == VAL; }
    C4_ALWAYS_INLINE bool is_keyval()         const noexcept { return (type & KEYVAL) == KEYVAL; }
    C4_ALWAYS_INLINE bool has_key_tag()       const noexcept { return (type & KEYTAG) != 0; }
    C4_ALWAYS_INLINE bool has_val_tag()       const noexcept { return (type & VALTAG) != 0; }
    C4_ALWAYS_INLINE bool has_key_anchor()    const noexcept { return (type & KEYANCH) != 0; }
    C4_ALWAYS_INLINE bool has_val_anchor()    const noexcept { return (type & VALANCH) != 0; }
    C4_ALWAYS_INLINE bool has_anchor()        const noexcept { return (type & (KEYANCH|VALANCH)) != 0; }
    C4_ALWAYS_INLINE bool is_key_ref()        const noexcept { return (type & KEYREF) != 0; }
    C4_ALWAYS_INLINE bool is_val_ref()        const noexcept { return (type & VALREF) != 0; }
    C4_ALWAYS_INLINE bool is_ref()            const noexcept { return (type & (KEYREF|VALREF)) != 0; }

    C4_ALWAYS_INLINE bool is_key_unfiltered() const noexcept { return (type & (KEY_UNFILT)) != 0; }
    C4_ALWAYS_INLINE bool is_val_unfiltered() const noexcept { return (type & (VAL_UNFILT)) != 0; }

    RYML_DEPRECATED("use has_key_anchor()")    bool is_key_anchor() const noexcept { return has_key_anchor(); }
    RYML_DEPRECATED("use has_val_anchor()")    bool is_val_anchor() const noexcept { return has_val_anchor(); }
    RYML_DEPRECATED("use has_anchor()")        bool is_anchor() const noexcept { return has_anchor(); }
    RYML_DEPRECATED("use has_anchor() || is_ref()") bool is_anchor_or_ref() const noexcept { return has_anchor() || is_ref(); }
    /** @} */

public:

    /** @name container+scalar style queries
     * @{ */

    C4_ALWAYS_INLINE bool is_container_styled() const noexcept { return (type & (CONTAINER_STYLE)) != 0; }
    C4_ALWAYS_INLINE bool is_block() const noexcept { return (type & (BLOCK)) != 0; }
    C4_ALWAYS_INLINE bool is_flow_sl() const noexcept { return (type & (FLOW_SL)) != 0; }
    C4_ALWAYS_INLINE bool is_flow_ml() const noexcept { return (type & (FLOW_ML)) != 0; }
    C4_ALWAYS_INLINE bool is_flow() const noexcept { return (type & (FLOW_ML|FLOW_SL)) != 0; }

    C4_ALWAYS_INLINE bool is_key_styled() const noexcept { return (type & (KEY_STYLE)) != 0; }
    C4_ALWAYS_INLINE bool is_val_styled() const noexcept { return (type & (VAL_STYLE)) != 0; }
    C4_ALWAYS_INLINE bool is_key_literal() const noexcept { return (type & (KEY_LITERAL)) != 0; }
    C4_ALWAYS_INLINE bool is_val_literal() const noexcept { return (type & (VAL_LITERAL)) != 0; }
    C4_ALWAYS_INLINE bool is_key_folded() const noexcept { return (type & (KEY_FOLDED)) != 0; }
    C4_ALWAYS_INLINE bool is_val_folded() const noexcept { return (type & (VAL_FOLDED)) != 0; }
    C4_ALWAYS_INLINE bool is_key_squo() const noexcept { return (type & (KEY_SQUO)) != 0; }
    C4_ALWAYS_INLINE bool is_val_squo() const noexcept { return (type & (VAL_SQUO)) != 0; }
    C4_ALWAYS_INLINE bool is_key_dquo() const noexcept { return (type & (KEY_DQUO)) != 0; }
    C4_ALWAYS_INLINE bool is_val_dquo() const noexcept { return (type & (VAL_DQUO)) != 0; }
    C4_ALWAYS_INLINE bool is_key_plain() const noexcept { return (type & (KEY_PLAIN)) != 0; }
    C4_ALWAYS_INLINE bool is_val_plain() const noexcept { return (type & (VAL_PLAIN)) != 0; }
    C4_ALWAYS_INLINE bool is_key_quoted() const noexcept { return (type & KEYQUO) != 0; }
    C4_ALWAYS_INLINE bool is_val_quoted() const noexcept { return (type & VALQUO) != 0; }
    C4_ALWAYS_INLINE bool is_quoted() const noexcept { return (type & (KEYQUO|VALQUO)) != 0; }

    C4_ALWAYS_INLINE void set_container_style(NodeType_e style) noexcept { type = ((style & CONTAINER_STYLE) | (type & ~CONTAINER_STYLE)); }
    C4_ALWAYS_INLINE void set_key_style(NodeType_e style) noexcept { type = ((style & KEY_STYLE) | (type & ~KEY_STYLE)); }
    C4_ALWAYS_INLINE void set_val_style(NodeType_e style) noexcept { type = ((style & VAL_STYLE) | (type & ~VAL_STYLE)); }

    /** @} */

};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @name scalar style helpers
 * @{ */

/** choose a YAML emitting style based on the scalar's contents */
RYML_EXPORT NodeType_e scalar_style_choose(csubstr scalar) noexcept;

/** choose a json style based on the scalar's contents */
RYML_EXPORT NodeType_e scalar_style_json_choose(csubstr scalar) noexcept;

/** query whether a scalar can be encoded using single quotes.
 * It may not be possible, notably when there is leading
 * whitespace after a newline. */
RYML_EXPORT bool scalar_style_query_squo(csubstr s) noexcept;

/** query whether a scalar can be encoded using plain style (no
 * quotes, not a literal/folded block scalar). */
RYML_EXPORT bool scalar_style_query_plain(csubstr s) noexcept;

/** YAML-sense query of nullity. returns true if the scalar points
 * to `nullptr` or is otherwise equal to one of the strings
 * `"~"`,`"null"`,`"Null"`,`"NULL"` */
RYML_EXPORT inline C4_NO_INLINE bool scalar_is_null(csubstr s) noexcept
{
    return s.str == nullptr ||
        s == "~" ||
        s == "null" ||
        s == "Null" ||
        s == "NULL";
}

/** @} */


/** @} */

} // namespace yml
} // namespace c4

C4_SUPPRESS_WARNING_MSVC_POP
C4_SUPPRESS_WARNING_GCC_CLANG_POP

#endif /* C4_YML_NODE_TYPE_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/node_type.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/tag.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/tag.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_TAG_HPP_
#define _C4_YML_TAG_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/common.hpp
//#include <c4/yml/common.hpp>
#if !defined(C4_YML_COMMON_HPP_) && !defined(_C4_YML_COMMON_HPP_)
#error "amalgamate: file c4/yml/common.hpp must have been included at this point"
#endif /* C4_YML_COMMON_HPP_ */


namespace c4 {
namespace yml {

class Tree;

/** @addtogroup doc_tag_utils
 *
 * @{
 */


#ifndef RYML_MAX_TAG_DIRECTIVES
/** the maximum number of tag directives in a Tree */
#define RYML_MAX_TAG_DIRECTIVES 4
#endif

/** the integral type necessary to cover all the bits marking node tags */
using tag_bits = uint16_t;

/** a bit mask for marking tags for types */
typedef enum : tag_bits {
    TAG_NONE      =  0,
    // container types
    TAG_MAP       =  1, /**< !!map   Unordered set of key: value pairs without duplicates. @see https://yaml.org/type/map.html */
    TAG_OMAP      =  2, /**< !!omap  Ordered sequence of key: value pairs without duplicates. @see https://yaml.org/type/omap.html */
    TAG_PAIRS     =  3, /**< !!pairs Ordered sequence of key: value pairs allowing duplicates. @see https://yaml.org/type/pairs.html */
    TAG_SET       =  4, /**< !!set   Unordered set of non-equal values. @see https://yaml.org/type/set.html */
    TAG_SEQ       =  5, /**< !!seq   Sequence of arbitrary values. @see https://yaml.org/type/seq.html */
    // scalar types
    TAG_BINARY    =  6, /**< !!binary A sequence of zero or more octets (8 bit values). @see https://yaml.org/type/binary.html */
    TAG_BOOL      =  7, /**< !!bool   Mathematical Booleans. @see https://yaml.org/type/bool.html */
    TAG_FLOAT     =  8, /**< !!float  Floating-point approximation to real numbers. https://yaml.org/type/float.html */
    TAG_INT       =  9, /**< !!float  Mathematical integers. https://yaml.org/type/int.html */
    TAG_MERGE     = 10, /**< !!merge  Specify one or more mapping to be merged with the current one. https://yaml.org/type/merge.html */
    TAG_NULL      = 11, /**< !!null   Devoid of value. https://yaml.org/type/null.html */
    TAG_STR       = 12, /**< !!str    A sequence of zero or more Unicode characters. https://yaml.org/type/str.html */
    TAG_TIMESTAMP = 13, /**< !!timestamp A point in time https://yaml.org/type/timestamp.html */
    TAG_VALUE     = 14, /**< !!value  Specify the default value of a mapping https://yaml.org/type/value.html */
    TAG_YAML      = 15, /**< !!yaml   Specify the default value of a mapping https://yaml.org/type/yaml.html */
} YamlTag_e;

RYML_EXPORT YamlTag_e to_tag(csubstr tag);
RYML_EXPORT csubstr from_tag(YamlTag_e tag);
RYML_EXPORT csubstr from_tag_long(YamlTag_e tag);
RYML_EXPORT csubstr normalize_tag(csubstr tag);
RYML_EXPORT csubstr normalize_tag_long(csubstr tag);
RYML_EXPORT csubstr normalize_tag_long(csubstr tag, substr output);

RYML_EXPORT bool is_custom_tag(csubstr tag);


struct RYML_EXPORT TagDirective
{
    /** Eg `!e!` in `%TAG !e! tag:example.com,2000:app/` */
    csubstr handle;
    /** Eg `tag:example.com,2000:app/` in `%TAG !e! tag:example.com,2000:app/` */
    csubstr prefix;
    /** The next node to which this tag directive applies */
    id_type next_node_id;

    bool create_from_str(csubstr directive_); ///< leaves next_node_id unfilled
    bool create_from_str(csubstr directive_, Tree *tree);
    size_t transform(csubstr tag, substr output, Callbacks const& callbacks) const;
};

struct RYML_EXPORT TagDirectiveRange
{
    TagDirective const* C4_RESTRICT b;
    TagDirective const* C4_RESTRICT e;
    C4_ALWAYS_INLINE TagDirective const* begin() const noexcept { return b; }
    C4_ALWAYS_INLINE TagDirective const* end() const noexcept { return e; }
};

/** @} */

} // namespace yml
} // namespace c4

#endif /* _C4_YML_TAG_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/tag.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/tree.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/tree.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_TREE_HPP_
#define _C4_YML_TREE_HPP_

/** @file tree.hpp */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/types.hpp
//#include "c4/types.hpp"
#if !defined(C4_TYPES_HPP_) && !defined(_C4_TYPES_HPP_)
#error "amalgamate: file c4/types.hpp must have been included at this point"
#endif /* C4_TYPES_HPP_ */

#ifndef _C4_YML_FWD_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/fwd.hpp
//#include "c4/yml/fwd.hpp"
#if !defined(C4_YML_FWD_HPP_) && !defined(_C4_YML_FWD_HPP_)
#error "amalgamate: file c4/yml/fwd.hpp must have been included at this point"
#endif /* C4_YML_FWD_HPP_ */

#endif
#ifndef _C4_YML_COMMON_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/common.hpp
//#include "c4/yml/common.hpp"
#if !defined(C4_YML_COMMON_HPP_) && !defined(_C4_YML_COMMON_HPP_)
#error "amalgamate: file c4/yml/common.hpp must have been included at this point"
#endif /* C4_YML_COMMON_HPP_ */

#endif
#ifndef C4_YML_NODE_TYPE_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/node_type.hpp
//#include "c4/yml/node_type.hpp"
#if !defined(C4_YML_NODE_TYPE_HPP_) && !defined(_C4_YML_NODE_TYPE_HPP_)
#error "amalgamate: file c4/yml/node_type.hpp must have been included at this point"
#endif /* C4_YML_NODE_TYPE_HPP_ */

#endif
#ifndef _C4_YML_TAG_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/tag.hpp
//#include "c4/yml/tag.hpp"
#if !defined(C4_YML_TAG_HPP_) && !defined(_C4_YML_TAG_HPP_)
#error "amalgamate: file c4/yml/tag.hpp must have been included at this point"
#endif /* C4_YML_TAG_HPP_ */

#endif
#ifndef _C4_CHARCONV_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/charconv.hpp
//#include <c4/charconv.hpp>
#if !defined(C4_CHARCONV_HPP_) && !defined(_C4_CHARCONV_HPP_)
#error "amalgamate: file c4/charconv.hpp must have been included at this point"
#endif /* C4_CHARCONV_HPP_ */

#endif

#include <cmath>
#include <limits>


C4_SUPPRESS_WARNING_MSVC_PUSH
C4_SUPPRESS_WARNING_MSVC(4251) // needs to have dll-interface to be used by clients of struct
C4_SUPPRESS_WARNING_MSVC(4296) // expression is always 'boolean_value'
C4_SUPPRESS_WARNING_GCC_CLANG_PUSH
C4_SUPPRESS_WARNING_GCC_CLANG("-Wold-style-cast")
C4_SUPPRESS_WARNING_GCC("-Wuseless-cast")
C4_SUPPRESS_WARNING_GCC("-Wtype-limits")


namespace c4 {
namespace yml {

/** encode a floating point value to a string. */
template<class T>
size_t to_chars_float(substr buf, T val)
{
    C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wfloat-equal");
    static_assert(std::is_floating_point<T>::value, "must be floating point");
    if(C4_UNLIKELY(std::isnan(val)))
        return to_chars(buf, csubstr(".nan"));
    else if(C4_UNLIKELY(val == std::numeric_limits<T>::infinity()))
        return to_chars(buf, csubstr(".inf"));
    else if(C4_UNLIKELY(val == -std::numeric_limits<T>::infinity()))
        return to_chars(buf, csubstr("-.inf"));
    return to_chars(buf, val);
    C4_SUPPRESS_WARNING_GCC_CLANG_POP
}


/** decode a floating point from string. Accepts special values: .nan,
 * .inf, -.inf */
template<class T>
bool from_chars_float(csubstr buf, T *C4_RESTRICT val)
{
    static_assert(std::is_floating_point<T>::value, "must be floating point");
    if(C4_LIKELY(from_chars(buf, val)))
    {
        return true;
    }
    else if(C4_UNLIKELY(buf.begins_with('+')))
    {
        return from_chars(buf.sub(1), val);
    }
    else if(C4_UNLIKELY(buf == ".nan" || buf == ".NaN" || buf == ".NAN"))
    {
        *val = std::numeric_limits<T>::quiet_NaN();
        return true;
    }
    else if(C4_UNLIKELY(buf == ".inf" || buf == ".Inf" || buf == ".INF"))
    {
        *val = std::numeric_limits<T>::infinity();
        return true;
    }
    else if(C4_UNLIKELY(buf == "-.inf" || buf == "-.Inf" || buf == "-.INF"))
    {
        *val = -std::numeric_limits<T>::infinity();
        return true;
    }
    else
    {
        return false;
    }
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


/** @addtogroup doc_tree
 *
 * @{
 */

/** a node scalar is a csubstr, which may be tagged and anchored. */
struct NodeScalar
{
    csubstr tag;
    csubstr scalar;
    csubstr anchor;

public:

    /// initialize as an empty scalar
    inline NodeScalar() noexcept : tag(), scalar(), anchor() {}

    /// initialize as an untagged scalar
    template<size_t N>
    inline NodeScalar(const char (&s)[N]) noexcept : tag(), scalar(s), anchor() {}
    inline NodeScalar(csubstr      s    ) noexcept : tag(), scalar(s), anchor() {}

    /// initialize as a tagged scalar
    template<size_t N, size_t M>
    inline NodeScalar(const char (&t)[N], const char (&s)[N]) noexcept : tag(t), scalar(s), anchor() {}
    inline NodeScalar(csubstr      t    , csubstr      s    ) noexcept : tag(t), scalar(s), anchor() {}

public:

    ~NodeScalar() noexcept = default;
    NodeScalar(NodeScalar &&) noexcept = default;
    NodeScalar(NodeScalar const&) noexcept = default;
    NodeScalar& operator= (NodeScalar &&) noexcept = default;
    NodeScalar& operator= (NodeScalar const&) noexcept = default;

public:

    bool empty() const noexcept { return tag.empty() && scalar.empty() && anchor.empty(); }

    void clear() noexcept { tag.clear(); scalar.clear(); anchor.clear(); }

    void set_ref_maybe_replacing_scalar(csubstr ref, bool has_scalar) RYML_NOEXCEPT
    {
        csubstr trimmed = ref.begins_with('*') ? ref.sub(1) : ref;
        anchor = trimmed;
        if((!has_scalar) || !scalar.ends_with(trimmed))
            scalar = ref;
    }
};
C4_MUST_BE_TRIVIAL_COPY(NodeScalar);


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** convenience class to initialize nodes */
struct NodeInit
{

    NodeType   type;
    NodeScalar key;
    NodeScalar val;

public:

    /// initialize as an empty node
    NodeInit() : type(NOTYPE), key(), val() {}
    /// initialize as a typed node
    NodeInit(NodeType_e t) : type(t), key(), val() {}
    /// initialize as a sequence member
    NodeInit(NodeScalar const& v) : type(VAL), key(), val(v) { _add_flags(); }
    /// initialize as a sequence member with explicit type
    NodeInit(NodeScalar const& v, NodeType_e t) : type(t|VAL), key(), val(v) { _add_flags(); }
    /// initialize as a mapping member
    NodeInit(              NodeScalar const& k, NodeScalar const& v) : type(KEYVAL), key(k), val(v) { _add_flags(); }
    /// initialize as a mapping member with explicit type
    NodeInit(NodeType_e t, NodeScalar const& k, NodeScalar const& v) : type(t), key(k), val(v) { _add_flags(); }
    /// initialize as a mapping member with explicit type (eg for SEQ or MAP)
    NodeInit(NodeType_e t, NodeScalar const& k                     ) : type(t), key(k), val( ) { _add_flags(KEY); }

public:

    void clear()
    {
        type.clear();
        key.clear();
        val.clear();
    }

    void _add_flags(type_bits more_flags=0)
    {
        type = (type|more_flags);
        if( ! key.tag.empty())
            type = (type|KEYTAG);
        if( ! val.tag.empty())
            type = (type|VALTAG);
        if( ! key.anchor.empty())
            type = (type|KEYANCH);
        if( ! val.anchor.empty())
            type = (type|VALANCH);
    }

    bool _check() const
    {
        // key cannot be empty
        RYML_ASSERT(key.scalar.empty() == ((type & KEY) == 0));
        // key tag cannot be empty
        RYML_ASSERT(key.tag.empty() == ((type & KEYTAG) == 0));
        // val may be empty even though VAL is set. But when VAL is not set, val must be empty
        RYML_ASSERT(((type & VAL) != 0) || val.scalar.empty());
        // val tag cannot be empty
        RYML_ASSERT(val.tag.empty() == ((type & VALTAG) == 0));
        return true;
    }
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** contains the data for each YAML node. */
struct NodeData
{
    NodeType   m_type;

    NodeScalar m_key;
    NodeScalar m_val;

    id_type    m_parent;
    id_type    m_first_child;
    id_type    m_last_child;
    id_type    m_next_sibling;
    id_type    m_prev_sibling;
};
C4_MUST_BE_TRIVIAL_COPY(NodeData);


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

class RYML_EXPORT Tree
{
public:

    /** @name construction and assignment */
    /** @{ */

    Tree() : Tree(get_callbacks()) {}
    Tree(Callbacks const& cb);
    Tree(id_type node_capacity, size_t arena_capacity=0) : Tree(node_capacity, arena_capacity, get_callbacks()) {}
    Tree(id_type node_capacity, size_t arena_capacity, Callbacks const& cb);

    ~Tree();

    Tree(Tree const& that);
    Tree(Tree     && that) noexcept;

    Tree& operator= (Tree const& that);
    Tree& operator= (Tree     && that) RYML_NOEXCEPT;

    /** @} */

public:

    /** @name memory and sizing */
    /** @{ */

    void reserve(id_type node_capacity);

    /** clear the tree and zero every node
     * @note does NOT clear the arena
     * @see clear_arena() */
    void clear();
    inline void clear_arena() { m_arena_pos = 0; }

    inline bool   empty() const { return m_size == 0; }

    inline id_type size() const { return m_size; }
    inline id_type capacity() const { return m_cap; }
    inline id_type slack() const { RYML_ASSERT(m_cap >= m_size); return m_cap - m_size; }

    Callbacks const& callbacks() const { return m_callbacks; }
    void callbacks(Callbacks const& cb) { m_callbacks = cb; }

    /** @} */

public:

    /** @name node getters */
    /** @{ */

    //! get the index of a node belonging to this tree.
    //! @p n can be nullptr, in which case NONE is returned
    id_type id(NodeData const* n) const
    {
        if( ! n)
            return NONE;
        _RYML_CB_ASSERT(m_callbacks, n >= m_buf && n < m_buf + m_cap);
        return static_cast<id_type>(n - m_buf);
    }

    //! get a pointer to a node's NodeData.
    //! i can be NONE, in which case a nullptr is returned
    inline NodeData *get(id_type node)
    {
        if(node == NONE)
            return nullptr;
        _RYML_CB_ASSERT(m_callbacks, node >= 0 && node < m_cap);
        return m_buf + node;
    }
    //! get a pointer to a node's NodeData.
    //! i can be NONE, in which case a nullptr is returned.
    inline NodeData const *get(id_type node) const
    {
        if(node == NONE)
            return nullptr;
        _RYML_CB_ASSERT(m_callbacks, node >= 0 && node < m_cap);
        return m_buf + node;
    }

    //! An if-less form of get() that demands a valid node index.
    //! This function is implementation only; use at your own risk.
    inline NodeData       * _p(id_type node)       { _RYML_CB_ASSERT(m_callbacks, node != NONE && node >= 0 && node < m_cap); return m_buf + node; }
    //! An if-less form of get() that demands a valid node index.
    //! This function is implementation only; use at your own risk.
    inline NodeData const * _p(id_type node) const { _RYML_CB_ASSERT(m_callbacks, node != NONE && node >= 0 && node < m_cap); return m_buf + node; }

    //! Get the id of the root node
    id_type root_id()       { if(m_cap == 0) { reserve(16); } _RYML_CB_ASSERT(m_callbacks, m_cap > 0 && m_size > 0); return 0; }
    //! Get the id of the root node
    id_type root_id() const {                                 _RYML_CB_ASSERT(m_callbacks, m_cap > 0 && m_size > 0); return 0; }

    //! Get a NodeRef of a node by id
    NodeRef      ref(id_type node);
    //! Get a NodeRef of a node by id
    ConstNodeRef ref(id_type node) const;
    //! Get a NodeRef of a node by id
    ConstNodeRef cref(id_type node) const;

    //! Get the root as a NodeRef
    NodeRef      rootref();
    //! Get the root as a ConstNodeRef
    ConstNodeRef rootref() const;
    //! Get the root as a ConstNodeRef
    ConstNodeRef crootref() const;

    //! get the i-th document of the stream
    //! @note @p i is NOT the node id, but the doc position within the stream
    NodeRef      docref(id_type i);
    //! get the i-th document of the stream
    //! @note @p i is NOT the node id, but the doc position within the stream
    ConstNodeRef docref(id_type i) const;
    //! get the i-th document of the stream
    //! @note @p i is NOT the node id, but the doc position within the stream
    ConstNodeRef cdocref(id_type i) const;

    //! find a root child by name, return it as a NodeRef
    //! @note requires the root to be a map.
    NodeRef      operator[] (csubstr key);
    //! find a root child by name, return it as a NodeRef
    //! @note requires the root to be a map.
    ConstNodeRef operator[] (csubstr key) const;

    //! find a root child by index: return the root node's @p i-th child as a NodeRef
    //! @note @p i is NOT the node id, but the child's position
    NodeRef      operator[] (id_type i);
    //! find a root child by index: return the root node's @p i-th child as a NodeRef
    //! @note @p i is NOT the node id, but the child's position
    ConstNodeRef operator[] (id_type i) const;

    /** @} */

public:

    /** @name node property getters */
    /** @{ */

    NodeType type(id_type node) const { return _p(node)->m_type; }
    const char* type_str(id_type node) const { return NodeType::type_str(_p(node)->m_type); }

    csubstr    const& key       (id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_key(node)); return _p(node)->m_key.scalar; }
    csubstr    const& key_tag   (id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_key_tag(node)); return _p(node)->m_key.tag; }
    csubstr    const& key_ref   (id_type node) const { _RYML_CB_ASSERT(m_callbacks, is_key_ref(node)); return _p(node)->m_key.anchor; }
    csubstr    const& key_anchor(id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_key_anchor(node)); return _p(node)->m_key.anchor; }
    NodeScalar const& keysc     (id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_key(node)); return _p(node)->m_key; }

    csubstr    const& val       (id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_val(node)); return _p(node)->m_val.scalar; }
    csubstr    const& val_tag   (id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_val_tag(node)); return _p(node)->m_val.tag; }
    csubstr    const& val_ref   (id_type node) const { _RYML_CB_ASSERT(m_callbacks, is_val_ref(node)); return _p(node)->m_val.anchor; }
    csubstr    const& val_anchor(id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_val_anchor(node)); return _p(node)->m_val.anchor; }
    NodeScalar const& valsc     (id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_val(node)); return _p(node)->m_val; }

    /** @} */

public:

    /** @name node type predicates */
    /** @{ */

    C4_ALWAYS_INLINE bool type_has_any(id_type node, NodeType_e bits) const { return _p(node)->m_type.has_any(bits); }
    C4_ALWAYS_INLINE bool type_has_all(id_type node, NodeType_e bits) const { return _p(node)->m_type.has_all(bits); }
    C4_ALWAYS_INLINE bool type_has_none(id_type node, NodeType_e bits) const { return _p(node)->m_type.has_none(bits); }

    C4_ALWAYS_INLINE bool is_stream(id_type node) const { return _p(node)->m_type.is_stream(); }
    C4_ALWAYS_INLINE bool is_doc(id_type node) const { return _p(node)->m_type.is_doc(); }
    C4_ALWAYS_INLINE bool is_container(id_type node) const { return _p(node)->m_type.is_container(); }
    C4_ALWAYS_INLINE bool is_map(id_type node) const { return _p(node)->m_type.is_map(); }
    C4_ALWAYS_INLINE bool is_seq(id_type node) const { return _p(node)->m_type.is_seq(); }
    C4_ALWAYS_INLINE bool has_key(id_type node) const { return _p(node)->m_type.has_key(); }
    C4_ALWAYS_INLINE bool has_val(id_type node) const { return _p(node)->m_type.has_val(); }
    C4_ALWAYS_INLINE bool is_val(id_type node) const { return _p(node)->m_type.is_val(); }
    C4_ALWAYS_INLINE bool is_keyval(id_type node) const { return _p(node)->m_type.is_keyval(); }
    C4_ALWAYS_INLINE bool has_key_tag(id_type node) const { return _p(node)->m_type.has_key_tag(); }
    C4_ALWAYS_INLINE bool has_val_tag(id_type node) const { return _p(node)->m_type.has_val_tag(); }
    C4_ALWAYS_INLINE bool has_key_anchor(id_type node) const { return _p(node)->m_type.has_key_anchor(); }
    C4_ALWAYS_INLINE bool has_val_anchor(id_type node) const { return _p(node)->m_type.has_val_anchor(); }
    C4_ALWAYS_INLINE bool has_anchor(id_type node) const { return _p(node)->m_type.has_anchor(); }
    C4_ALWAYS_INLINE bool is_key_ref(id_type node) const { return _p(node)->m_type.is_key_ref(); }
    C4_ALWAYS_INLINE bool is_val_ref(id_type node) const { return _p(node)->m_type.is_val_ref(); }
    C4_ALWAYS_INLINE bool is_ref(id_type node) const { return _p(node)->m_type.is_ref(); }

    C4_ALWAYS_INLINE bool parent_is_seq(id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_parent(node)); return is_seq(_p(node)->m_parent); }
    C4_ALWAYS_INLINE bool parent_is_map(id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_parent(node)); return is_map(_p(node)->m_parent); }

    /** true when the node has an anchor named a */
    C4_ALWAYS_INLINE bool has_anchor(id_type node, csubstr a) const { return _p(node)->m_key.anchor == a || _p(node)->m_val.anchor == a; }

    /** true if the node key does not have any KEYQUO flags, and its scalar verifies scalar_is_null().
     * @warning the node must verify .has_key() (asserted) (ie must be a member of a map)
     * @see https://github.com/biojppm/rapidyaml/issues/413 */
    C4_ALWAYS_INLINE bool key_is_null(id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_key(node)); NodeData const* C4_RESTRICT n = _p(node); return !n->m_type.is_key_quoted() && scalar_is_null(n->m_key.scalar); }
    /** true if the node key does not have any VALQUO flags, and its scalar verifies scalar_is_null().
     * @warning the node must verify .has_val() (asserted) (ie must be a scalar / must not be a container)
     * @see https://github.com/biojppm/rapidyaml/issues/413 */
    C4_ALWAYS_INLINE bool val_is_null(id_type node) const { _RYML_CB_ASSERT(m_callbacks, has_val(node)); NodeData const* C4_RESTRICT n = _p(node); return !n->m_type.is_val_quoted() && scalar_is_null(n->m_val.scalar); }

    /// true if the key was a scalar requiring filtering and was left
    /// unfiltered during the parsing (see ParserOptions)
    C4_ALWAYS_INLINE bool is_key_unfiltered(id_type node) const { return _p(node)->m_type.is_key_unfiltered(); }
    /// true if the val was a scalar requiring filtering and was left
    /// unfiltered during the parsing (see ParserOptions)
    C4_ALWAYS_INLINE bool is_val_unfiltered(id_type node) const { return _p(node)->m_type.is_val_unfiltered(); }

    RYML_DEPRECATED("use has_key_anchor()")    bool is_key_anchor(id_type node) const { return _p(node)->m_type.has_key_anchor(); }
    RYML_DEPRECATED("use has_val_anchor()")    bool is_val_anchor(id_type node) const { return _p(node)->m_type.has_val_anchor(); }
    RYML_DEPRECATED("use has_anchor()")        bool is_anchor(id_type node) const { return _p(node)->m_type.has_anchor(); }
    RYML_DEPRECATED("use has_anchor_or_ref()") bool is_anchor_or_ref(id_type node) const { return _p(node)->m_type.has_anchor() || _p(node)->m_type.is_ref(); }

    /** @} */

public:

    /** @name hierarchy predicates */
    /** @{ */

    bool is_root(id_type node) const { _RYML_CB_ASSERT(m_callbacks, _p(node)->m_parent != NONE || node == 0); return _p(node)->m_parent == NONE; }

    bool has_parent(id_type node) const { return _p(node)->m_parent != NONE; }

    /** true when key and val are empty, and has no children */
    bool empty(id_type node) const { return ! has_children(node) && _p(node)->m_key.empty() && (( ! (_p(node)->m_type & VAL)) || _p(node)->m_val.empty()); }

    /** true if @p node has a child with id @p ch */
    bool has_child(id_type node, id_type ch) const { return _p(ch)->m_parent == node; }
    /** true if @p node has a child with key @p key */
    bool has_child(id_type node, csubstr key) const { return find_child(node, key) != NONE; }
    /** true if @p node has any children key */
    bool has_children(id_type node) const { return _p(node)->m_first_child != NONE; }

    /** true if @p node has a sibling with id @p sib */
    bool has_sibling(id_type node, id_type sib) const { return _p(node)->m_parent == _p(sib)->m_parent; }
    /** true if one of the node's siblings has the given key */
    bool has_sibling(id_type node, csubstr key) const { return find_sibling(node, key) != NONE; }
    /** true if node is not a single child */
    bool has_other_siblings(id_type node) const
    {
        NodeData const *n = _p(node);
        if(C4_LIKELY(n->m_parent != NONE))
        {
            n = _p(n->m_parent);
            return n->m_first_child != n->m_last_child;
        }
        return false;
    }

    RYML_DEPRECATED("use has_other_siblings()") bool has_siblings(id_type /*node*/) const { return true; }

    /** @} */

public:

    /** @name hierarchy getters */
    /** @{ */

    id_type parent(id_type node) const { return _p(node)->m_parent; }

    id_type prev_sibling(id_type node) const { return _p(node)->m_prev_sibling; }
    id_type next_sibling(id_type node) const { return _p(node)->m_next_sibling; }

    /** O(#num_children) */
    id_type num_children(id_type node) const;
    id_type child_pos(id_type node, id_type ch) const;
    id_type first_child(id_type node) const { return _p(node)->m_first_child; }
    id_type last_child(id_type node) const { return _p(node)->m_last_child; }
    id_type child(id_type node, id_type pos) const;
    id_type find_child(id_type node, csubstr const& key) const;

    /** O(#num_siblings) */
    /** counts with this */
    id_type num_siblings(id_type node) const { return is_root(node) ? 1 : num_children(_p(node)->m_parent); }
    /** does not count with this */
    id_type num_other_siblings(id_type node) const { id_type ns = num_siblings(node); _RYML_CB_ASSERT(m_callbacks, ns > 0); return ns-1; }
    id_type sibling_pos(id_type node, id_type sib) const { _RYML_CB_ASSERT(m_callbacks,  ! is_root(node) || node == root_id()); return child_pos(_p(node)->m_parent, sib); }
    id_type first_sibling(id_type node) const { return is_root(node) ? node : _p(_p(node)->m_parent)->m_first_child; }
    id_type last_sibling(id_type node) const { return is_root(node) ? node : _p(_p(node)->m_parent)->m_last_child; }
    id_type sibling(id_type node, id_type pos) const { return child(_p(node)->m_parent, pos); }
    id_type find_sibling(id_type node, csubstr const& key) const { return find_child(_p(node)->m_parent, key); }

    id_type doc(id_type i) const { id_type rid = root_id(); _RYML_CB_ASSERT(m_callbacks, is_stream(rid)); return child(rid, i); } //!< gets the @p i document node index. requires that the root node is a stream.

    id_type depth_asc(id_type node) const; /**< O(log(num_tree_nodes)) get the ascending depth of the node: number of levels between root and node */
    id_type depth_desc(id_type node) const; /**< O(num_tree_nodes) get the descending depth of the node: number of levels between node and deepest child */

    /** @} */

public:

    /** @name node style predicates and modifiers. see the corresponding predicate in NodeType */
    /** @{ */

    C4_ALWAYS_INLINE bool is_container_styled(id_type node) const { return _p(node)->m_type.is_container_styled(); }
    C4_ALWAYS_INLINE bool is_block(id_type node) const { return _p(node)->m_type.is_block(); }
    C4_ALWAYS_INLINE bool is_flow_sl(id_type node) const { return _p(node)->m_type.is_flow_sl(); }
    C4_ALWAYS_INLINE bool is_flow_ml(id_type node) const { return _p(node)->m_type.is_flow_ml(); }
    C4_ALWAYS_INLINE bool is_flow(id_type node) const { return _p(node)->m_type.is_flow(); }

    C4_ALWAYS_INLINE bool is_key_styled(id_type node) const { return _p(node)->m_type.is_key_styled(); }
    C4_ALWAYS_INLINE bool is_val_styled(id_type node) const { return _p(node)->m_type.is_val_styled(); }
    C4_ALWAYS_INLINE bool is_key_literal(id_type node) const { return _p(node)->m_type.is_key_literal(); }
    C4_ALWAYS_INLINE bool is_val_literal(id_type node) const { return _p(node)->m_type.is_val_literal(); }
    C4_ALWAYS_INLINE bool is_key_folded(id_type node) const { return _p(node)->m_type.is_key_folded(); }
    C4_ALWAYS_INLINE bool is_val_folded(id_type node) const { return _p(node)->m_type.is_val_folded(); }
    C4_ALWAYS_INLINE bool is_key_squo(id_type node) const { return _p(node)->m_type.is_key_squo(); }
    C4_ALWAYS_INLINE bool is_val_squo(id_type node) const { return _p(node)->m_type.is_val_squo(); }
    C4_ALWAYS_INLINE bool is_key_dquo(id_type node) const { return _p(node)->m_type.is_key_dquo(); }
    C4_ALWAYS_INLINE bool is_val_dquo(id_type node) const { return _p(node)->m_type.is_val_dquo(); }
    C4_ALWAYS_INLINE bool is_key_plain(id_type node) const { return _p(node)->m_type.is_key_plain(); }
    C4_ALWAYS_INLINE bool is_val_plain(id_type node) const { return _p(node)->m_type.is_val_plain(); }
    C4_ALWAYS_INLINE bool is_key_quoted(id_type node) const { return _p(node)->m_type.is_key_quoted(); }
    C4_ALWAYS_INLINE bool is_val_quoted(id_type node) const { return _p(node)->m_type.is_val_quoted(); }
    C4_ALWAYS_INLINE bool is_quoted(id_type node) const { return _p(node)->m_type.is_quoted(); }

    C4_ALWAYS_INLINE void set_container_style(id_type node, NodeType_e style) { _RYML_CB_ASSERT(m_callbacks, is_container(node)); _p(node)->m_type.set_container_style(style); }
    C4_ALWAYS_INLINE void set_key_style(id_type node, NodeType_e style) { _RYML_CB_ASSERT(m_callbacks, has_key(node)); _p(node)->m_type.set_key_style(style); }
    C4_ALWAYS_INLINE void set_val_style(id_type node, NodeType_e style) { _RYML_CB_ASSERT(m_callbacks, has_val(node)); _p(node)->m_type.set_val_style(style); }

    /** @} */

public:

    /** @name node type modifiers */
    /** @{ */

    void to_keyval(id_type node, csubstr key, csubstr val, type_bits more_flags=0);
    void to_map(id_type node, csubstr key, type_bits more_flags=0);
    void to_seq(id_type node, csubstr key, type_bits more_flags=0);
    void to_val(id_type node, csubstr val, type_bits more_flags=0);
    void to_map(id_type node, type_bits more_flags=0);
    void to_seq(id_type node, type_bits more_flags=0);
    void to_doc(id_type node, type_bits more_flags=0);
    void to_stream(id_type node, type_bits more_flags=0);

    void set_key(id_type node, csubstr key) { _RYML_CB_ASSERT(m_callbacks, has_key(node)); _p(node)->m_key.scalar = key; }
    void set_val(id_type node, csubstr val) { _RYML_CB_ASSERT(m_callbacks, has_val(node)); _p(node)->m_val.scalar = val; }

    void set_key_tag(id_type node, csubstr tag) { _RYML_CB_ASSERT(m_callbacks, has_key(node)); _p(node)->m_key.tag = tag; _add_flags(node, KEYTAG); }
    void set_val_tag(id_type node, csubstr tag) { _RYML_CB_ASSERT(m_callbacks, has_val(node) || is_container(node)); _p(node)->m_val.tag = tag; _add_flags(node, VALTAG); }

    void set_key_anchor(id_type node, csubstr anchor) { _RYML_CB_ASSERT(m_callbacks,  ! is_key_ref(node)); _p(node)->m_key.anchor = anchor.triml('&'); _add_flags(node, KEYANCH); }
    void set_val_anchor(id_type node, csubstr anchor) { _RYML_CB_ASSERT(m_callbacks,  ! is_val_ref(node)); _p(node)->m_val.anchor = anchor.triml('&'); _add_flags(node, VALANCH); }
    void set_key_ref   (id_type node, csubstr ref   ) { _RYML_CB_ASSERT(m_callbacks,  ! has_key_anchor(node)); NodeData* C4_RESTRICT n = _p(node); n->m_key.set_ref_maybe_replacing_scalar(ref, n->m_type.has_key()); _add_flags(node, KEY|KEYREF); }
    void set_val_ref   (id_type node, csubstr ref   ) { _RYML_CB_ASSERT(m_callbacks,  ! has_val_anchor(node)); NodeData* C4_RESTRICT n = _p(node); n->m_val.set_ref_maybe_replacing_scalar(ref, n->m_type.has_val()); _add_flags(node, VAL|VALREF); }

    void rem_key_anchor(id_type node) { _p(node)->m_key.anchor.clear(); _rem_flags(node, KEYANCH); }
    void rem_val_anchor(id_type node) { _p(node)->m_val.anchor.clear(); _rem_flags(node, VALANCH); }
    void rem_key_ref   (id_type node) { _p(node)->m_key.anchor.clear(); _rem_flags(node, KEYREF); }
    void rem_val_ref   (id_type node) { _p(node)->m_val.anchor.clear(); _rem_flags(node, VALREF); }
    void rem_anchor_ref(id_type node) { _p(node)->m_key.anchor.clear(); _p(node)->m_val.anchor.clear(); _rem_flags(node, KEYANCH|VALANCH|KEYREF|VALREF); }

    /** @} */

public:

    /** @name tree modifiers */
    /** @{ */

    /** reorder the tree in memory so that all the nodes are stored
     * in a linear sequence when visited in depth-first order.
     * This will invalidate existing ids, since the node id is its
     * position in the tree's node array. */
    void reorder();

    /** Resolve references (aliases <- anchors) in the tree.
     *
     * Dereferencing is opt-in; after parsing, Tree::resolve() has to
     * be called explicitly for obtaining resolved references in the
     * tree. This method will @ref ReferenceResolver::resolve()
     * to resolve all references and substitute the anchored values in
     * place of the reference.
     *
     * This method first does a full traversal of the tree to gather all
     * anchors and references in a separate collection, then it goes through
     * that collection to locate the names, which it does by obeying the YAML
     * standard diktat that "an alias node refers to the most recent node in
     * the serialization having the specified anchor"
     *
     * So, depending on the number of anchor/alias nodes, this is a
     * potentially expensive operation, with a best-case linear complexity
     * (from the initial traversal). This potential cost is the reason for
     * requiring an explicit call.
     *
     * @see ReferenceResolver::resolve()
     */
    void resolve(ReferenceResolver *C4_RESTRICT rr);

    /** Resolve references using a throw-away resolver. */
    void resolve();

    /** @} */

public:

    /** @name tag directives */
    /** @{ */

    void resolve_tags();
    void normalize_tags();
    void normalize_tags_long();

    id_type num_tag_directives() const;
    bool add_tag_directive(csubstr directive);
    id_type add_tag_directive(TagDirective const& td);
    void clear_tag_directives();

    /** resolve the given tag, appearing at node_id. Write the result into output.
     * @return the number of characters required for the resolved tag */
    size_t resolve_tag(substr output, csubstr tag, id_type node_id) const;
    csubstr resolve_tag_sub(substr output, csubstr tag, id_type node_id) const
    {
        size_t needed = resolve_tag(output, tag, node_id);
        return needed <= output.len ? output.first(needed) : output;
    }

    TagDirective const* begin_tag_directives() const { return m_tag_directives; }
    TagDirective const* end_tag_directives() const { return m_tag_directives + num_tag_directives(); }
    c4::yml::TagDirectiveRange tag_directives() const { return c4::yml::TagDirectiveRange{begin_tag_directives(), end_tag_directives()}; }

    RYML_DEPRECATED("use c4::yml::tag_directive_const_iterator") typedef TagDirective const* tag_directive_const_iterator;
    RYML_DEPRECATED("use c4::yml::TagDirectiveRange") typedef c4::yml::TagDirectiveRange TagDirectiveProxy;

    /** @} */

public:

    /** @name modifying hierarchy */
    /** @{ */

    /** create and insert a new child of @p parent. insert after the (to-be)
     * sibling @p after, which must be a child of @p parent. To insert as the
     * first child, set after to NONE */
    C4_ALWAYS_INLINE id_type insert_child(id_type parent, id_type after)
    {
        _RYML_CB_ASSERT(m_callbacks, parent != NONE);
        _RYML_CB_ASSERT(m_callbacks, is_container(parent) || is_root(parent));
        _RYML_CB_ASSERT(m_callbacks, after == NONE || (_p(after)->m_parent == parent));
        id_type child = _claim();
        _set_hierarchy(child, parent, after);
        return child;
    }
    /** create and insert a node as the first child of @p parent */
    C4_ALWAYS_INLINE id_type prepend_child(id_type parent) { return insert_child(parent, NONE); }
    /** create and insert a node as the last child of @p parent */
    C4_ALWAYS_INLINE id_type append_child(id_type parent) { return insert_child(parent, _p(parent)->m_last_child); }
    C4_ALWAYS_INLINE id_type _append_child__unprotected(id_type parent)
    {
        id_type child = _claim();
        _set_hierarchy(child, parent, _p(parent)->m_last_child);
        return child;
    }

public:

    #if defined(__clang__)
    #   pragma clang diagnostic push
    #   pragma clang diagnostic ignored "-Wnull-dereference"
    #elif defined(__GNUC__)
    #   pragma GCC diagnostic push
    #   if __GNUC__ >= 6
    #       pragma GCC diagnostic ignored "-Wnull-dereference"
    #   endif
    #endif

    //! create and insert a new sibling of n. insert after "after"
    C4_ALWAYS_INLINE id_type insert_sibling(id_type node, id_type after)
    {
        return insert_child(_p(node)->m_parent, after);
    }
    /** create and insert a node as the first node of @p parent */
    C4_ALWAYS_INLINE id_type prepend_sibling(id_type node) { return prepend_child(_p(node)->m_parent); }
    C4_ALWAYS_INLINE id_type  append_sibling(id_type node) { return append_child(_p(node)->m_parent); }

public:

    /** remove an entire branch at once: ie remove the children and the node itself */
    inline void remove(id_type node)
    {
        remove_children(node);
        _release(node);
    }

    /** remove all the node's children, but keep the node itself */
    void remove_children(id_type node);

    /** change the @p type of the node to one of MAP, SEQ or VAL.  @p
     * type must have one and only one of MAP,SEQ,VAL; @p type may
     * possibly have KEY, but if it does, then the @p node must also
     * have KEY. Changing to the same type is a no-op. Otherwise,
     * changing to a different type will initialize the node with an
     * empty value of the desired type: changing to VAL will
     * initialize with a null scalar (~), changing to MAP will
     * initialize with an empty map ({}), and changing to SEQ will
     * initialize with an empty seq ([]). */
    bool change_type(id_type node, NodeType type);

    bool change_type(id_type node, type_bits type)
    {
        return change_type(node, (NodeType)type);
    }

    #if defined(__clang__)
    #   pragma clang diagnostic pop
    #elif defined(__GNUC__)
    #   pragma GCC diagnostic pop
    #endif

public:

    /** change the node's position in the parent */
    void move(id_type node, id_type after);

    /** change the node's parent and position */
    void move(id_type node, id_type new_parent, id_type after);

    /** change the node's parent and position to a different tree
     * @return the index of the new node in the destination tree */
    id_type move(Tree * src, id_type node, id_type new_parent, id_type after);

    /** ensure the first node is a stream. Eg, change this tree
     *
     *  DOCMAP
     *    MAP
     *      KEYVAL
     *      KEYVAL
     *    SEQ
     *      VAL
     *
     * to
     *
     *  STREAM
     *    DOCMAP
     *      MAP
     *        KEYVAL
     *        KEYVAL
     *      SEQ
     *        VAL
     *
     * If the root is already a stream, this is a no-op.
     */
    void set_root_as_stream();

public:

    /** recursively duplicate a node from this tree into a new parent,
     * placing it after one of its children
     * @return the index of the copy */
    id_type duplicate(id_type node, id_type new_parent, id_type after);
    /** recursively duplicate a node from a different tree into a new parent,
     * placing it after one of its children
     * @return the index of the copy */
    id_type duplicate(Tree const* src, id_type node, id_type new_parent, id_type after);

    /** recursively duplicate the node's children (but not the node)
     * @return the index of the last duplicated child */
    id_type duplicate_children(id_type node, id_type parent, id_type after);
    /** recursively duplicate the node's children (but not the node), where
     * the node is from a different tree
     * @return the index of the last duplicated child */
    id_type duplicate_children(Tree const* src, id_type node, id_type parent, id_type after);

    void duplicate_contents(id_type node, id_type where);
    void duplicate_contents(Tree const* src, id_type node, id_type where);

    /** duplicate the node's children (but not the node) in a new parent, but
     * omit repetitions where a duplicated node has the same key (in maps) or
     * value (in seqs). If one of the duplicated children has the same key
     * (in maps) or value (in seqs) as one of the parent's children, the one
     * that is placed closest to the end will prevail. */
    id_type duplicate_children_no_rep(id_type node, id_type parent, id_type after);
    id_type duplicate_children_no_rep(Tree const* src, id_type node, id_type parent, id_type after);

public:

    void merge_with(Tree const* src, id_type src_node=NONE, id_type dst_root=NONE);

    /** @} */

public:

    /** @name internal string arena */
    /** @{ */

    /** get the current size of the tree's internal arena */
    RYML_DEPRECATED("use arena_size() instead") size_t arena_pos() const { return m_arena_pos; }
    /** get the current size of the tree's internal arena */
    inline size_t arena_size() const { return m_arena_pos; }
    /** get the current capacity of the tree's internal arena */
    inline size_t arena_capacity() const { return m_arena.len; }
    /** get the current slack of the tree's internal arena */
    inline size_t arena_slack() const { _RYML_CB_ASSERT(m_callbacks, m_arena.len >= m_arena_pos); return m_arena.len - m_arena_pos; }

    /** get the current arena */
    csubstr arena() const { return m_arena.first(m_arena_pos); }
    /** get the current arena */
    substr arena() { return m_arena.first(m_arena_pos); }

    /** return true if the given substring is part of the tree's string arena */
    bool in_arena(csubstr s) const
    {
        return m_arena.is_super(s);
    }

    /** serialize the given floating-point variable to the tree's
     * arena, growing it as needed to accomodate the serialization.
     *
     * @note Growing the arena may cause relocation of the entire
     * existing arena, and thus change the contents of individual
     * nodes, and thus cost O(numnodes)+O(arenasize). To avoid this
     * cost, ensure that the arena is reserved to an appropriate size
     * using .reserve_arena()
     *
     * @see alloc_arena() */
    template<class T>
    typename std::enable_if<std::is_floating_point<T>::value, csubstr>::type
    to_arena(T const& C4_RESTRICT a)
    {
        substr rem(m_arena.sub(m_arena_pos));
        size_t num = to_chars_float(rem, a);
        if(num > rem.len)
        {
            rem = _grow_arena(num);
            num = to_chars_float(rem, a);
            _RYML_CB_ASSERT(m_callbacks, num <= rem.len);
        }
        rem = _request_span(num);
        return rem;
    }

    /** serialize the given non-floating-point variable to the tree's
     * arena, growing it as needed to accomodate the serialization.
     *
     * @note Growing the arena may cause relocation of the entire
     * existing arena, and thus change the contents of individual
     * nodes, and thus cost O(numnodes)+O(arenasize). To avoid this
     * cost, ensure that the arena is reserved to an appropriate size
     * using .reserve_arena()
     *
     * @see alloc_arena() */
    template<class T>
    typename std::enable_if<!std::is_floating_point<T>::value, csubstr>::type
    to_arena(T const& C4_RESTRICT a)
    {
        substr rem(m_arena.sub(m_arena_pos));
        size_t num = to_chars(rem, a);
        if(num > rem.len)
        {
            rem = _grow_arena(num);
            num = to_chars(rem, a);
            _RYML_CB_ASSERT(m_callbacks, num <= rem.len);
        }
        rem = _request_span(num);
        return rem;
    }

    /** serialize the given csubstr to the tree's arena, growing the
     * arena as needed to accomodate the serialization.
     *
     * @note Growing the arena may cause relocation of the entire
     * existing arena, and thus change the contents of individual
     * nodes, and thus cost O(numnodes)+O(arenasize). To avoid this
     * cost, ensure that the arena is reserved to an appropriate size
     * using .reserve_arena()
     *
     * @see alloc_arena() */
    csubstr to_arena(csubstr a)
    {
        if(a.len > 0)
        {
            substr rem(m_arena.sub(m_arena_pos));
            size_t num = to_chars(rem, a);
            if(num > rem.len)
            {
                rem = _grow_arena(num);
                num = to_chars(rem, a);
                _RYML_CB_ASSERT(m_callbacks, num <= rem.len);
            }
            return _request_span(num);
        }
        else
        {
            if(a.str == nullptr)
            {
                return csubstr{};
            }
            else if(m_arena.str == nullptr)
            {
                // Arena is empty and we want to store a non-null
                // zero-length string.
                // Even though the string has zero length, we need
                // some "memory" to store a non-nullptr string
                _grow_arena(1);
            }
            return _request_span(0);
        }
    }
    C4_ALWAYS_INLINE csubstr to_arena(const char *s)
    {
        return to_arena(to_csubstr(s));
    }
    C4_ALWAYS_INLINE csubstr to_arena(std::nullptr_t)
    {
        return csubstr{};
    }

    /** copy the given substr to the tree's arena, growing it by the
     * required size
     *
     * @note Growing the arena may cause relocation of the entire
     * existing arena, and thus change the contents of individual
     * nodes, and thus cost O(numnodes)+O(arenasize). To avoid this
     * cost, ensure that the arena is reserved to an appropriate size
     * using .reserve_arena()
     *
     * @see alloc_arena() */
    substr copy_to_arena(csubstr s)
    {
        substr cp = alloc_arena(s.len);
        _RYML_CB_ASSERT(m_callbacks, cp.len == s.len);
        _RYML_CB_ASSERT(m_callbacks, !s.overlaps(cp));
        #if (!defined(__clang__)) && (defined(__GNUC__) && __GNUC__ >= 10)
        C4_SUPPRESS_WARNING_GCC_PUSH
        C4_SUPPRESS_WARNING_GCC("-Wstringop-overflow=") // no need for terminating \0
        C4_SUPPRESS_WARNING_GCC( "-Wrestrict") // there's an assert to ensure no violation of restrict behavior
        #endif
        if(s.len)
            memcpy(cp.str, s.str, s.len);
        #if (!defined(__clang__)) && (defined(__GNUC__) && __GNUC__ >= 10)
        C4_SUPPRESS_WARNING_GCC_POP
        #endif
        return cp;
    }

    /** grow the tree's string arena by the given size and return a substr
     * of the added portion
     *
     * @note Growing the arena may cause relocation of the entire
     * existing arena, and thus change the contents of individual
     * nodes, and thus cost O(numnodes)+O(arenasize). To avoid this
     * cost, ensure that the arena is reserved to an appropriate size
     * using .reserve_arena().
     *
     * @see reserve_arena() */
    substr alloc_arena(size_t sz)
    {
        if(sz > arena_slack())
            _grow_arena(sz - arena_slack());
        substr s = _request_span(sz);
        return s;
    }

    /** ensure the tree's internal string arena is at least the given capacity
     * @warning This operation may be expensive, with a potential complexity of O(numNodes)+O(arenasize).
     * @warning Growing the arena may cause relocation of the entire
     * existing arena, and thus change the contents of individual nodes. */
    void reserve_arena(size_t arena_cap)
    {
        if(arena_cap > m_arena.len)
        {
            substr buf;
            buf.str = (char*) m_callbacks.m_allocate(arena_cap, m_arena.str, m_callbacks.m_user_data);
            buf.len = arena_cap;
            if(m_arena.str)
            {
                _RYML_CB_ASSERT(m_callbacks, m_arena.len >= 0);
                _relocate(buf); // does a memcpy and changes nodes using the arena
                m_callbacks.m_free(m_arena.str, m_arena.len, m_callbacks.m_user_data);
            }
            m_arena = buf;
        }
    }

    /** @} */

private:

    substr _grow_arena(size_t more)
    {
        size_t cap = m_arena.len + more;
        cap = cap < 2 * m_arena.len ? 2 * m_arena.len : cap;
        cap = cap < 64 ? 64 : cap;
        reserve_arena(cap);
        return m_arena.sub(m_arena_pos);
    }

    substr _request_span(size_t sz)
    {
        _RYML_CB_ASSERT(m_callbacks, m_arena_pos + sz <= m_arena.len);
        substr s;
        s = m_arena.sub(m_arena_pos, sz);
        m_arena_pos += sz;
        return s;
    }

    substr _relocated(csubstr s, substr next_arena) const
    {
        _RYML_CB_ASSERT(m_callbacks, m_arena.is_super(s));
        _RYML_CB_ASSERT(m_callbacks, m_arena.sub(0, m_arena_pos).is_super(s));
        auto pos = (s.str - m_arena.str); // this is larger than 0 based on the assertions above
        substr r(next_arena.str + pos, s.len);
        _RYML_CB_ASSERT(m_callbacks, r.str - next_arena.str == pos);
        _RYML_CB_ASSERT(m_callbacks, next_arena.sub(0, m_arena_pos).is_super(r));
        return r;
    }

public:

    /** @name lookup */
    /** @{ */

    struct lookup_result
    {
        id_type  target;
        id_type  closest;
        size_t  path_pos;
        csubstr path;

        inline operator bool() const { return target != NONE; }

        lookup_result() : target(NONE), closest(NONE), path_pos(0), path() {}
        lookup_result(csubstr path_, id_type start) : target(NONE), closest(start), path_pos(0), path(path_) {}

        /** get the part ot the input path that was resolved */
        csubstr resolved() const;
        /** get the part ot the input path that was unresolved */
        csubstr unresolved() const;
    };

    /** for example foo.bar[0].baz */
    lookup_result lookup_path(csubstr path, id_type start=NONE) const;

    /** defaulted lookup: lookup @p path; if the lookup fails, recursively modify
     * the tree so that the corresponding lookup_path() would return the
     * default value.
     * @see lookup_path() */
    id_type lookup_path_or_modify(csubstr default_value, csubstr path, id_type start=NONE);

    /** defaulted lookup: lookup @p path; if the lookup fails, recursively modify
     * the tree so that the corresponding lookup_path() would return the
     * branch @p src_node (from the tree @p src).
     * @see lookup_path() */
    id_type lookup_path_or_modify(Tree const *src, id_type src_node, csubstr path, id_type start=NONE);

    /** @} */

private:

    struct _lookup_path_token
    {
        csubstr value;
        NodeType type;
        _lookup_path_token() : value(), type() {}
        _lookup_path_token(csubstr v, NodeType t) : value(v), type(t) {}
        inline operator bool() const { return type != NOTYPE; }
        bool is_index() const { return value.begins_with('[') && value.ends_with(']'); }
    };

    id_type _lookup_path_or_create(csubstr path, id_type start);

    void   _lookup_path       (lookup_result *r) const;
    void   _lookup_path_modify(lookup_result *r);

    id_type _next_node       (lookup_result *r, _lookup_path_token *parent) const;
    id_type _next_node_modify(lookup_result *r, _lookup_path_token *parent);

    void   _advance(lookup_result *r, size_t more) const;

    _lookup_path_token _next_token(lookup_result *r, _lookup_path_token const& parent) const;

private:

    void _clear();
    void _free();
    void _copy(Tree const& that);
    void _move(Tree      & that) noexcept;

    void _relocate(substr next_arena);

public:

    /** @cond dev*/

    #if ! RYML_USE_ASSERT
    C4_ALWAYS_INLINE void _check_next_flags(id_type, type_bits) {}
    #else
    void _check_next_flags(id_type node, type_bits f)
    {
        auto n = _p(node);
        type_bits o = n->m_type; // old
        C4_UNUSED(o);
        if(f & MAP)
        {
            RYML_ASSERT_MSG((f & SEQ) == 0, "cannot mark simultaneously as map and seq");
            RYML_ASSERT_MSG((f & VAL) == 0, "cannot mark simultaneously as map and val");
            RYML_ASSERT_MSG((o & SEQ) == 0, "cannot turn a seq into a map; clear first");
            RYML_ASSERT_MSG((o & VAL) == 0, "cannot turn a val into a map; clear first");
        }
        else if(f & SEQ)
        {
            RYML_ASSERT_MSG((f & MAP) == 0, "cannot mark simultaneously as seq and map");
            RYML_ASSERT_MSG((f & VAL) == 0, "cannot mark simultaneously as seq and val");
            RYML_ASSERT_MSG((o & MAP) == 0, "cannot turn a map into a seq; clear first");
            RYML_ASSERT_MSG((o & VAL) == 0, "cannot turn a val into a seq; clear first");
        }
        if(f & KEY)
        {
            _RYML_CB_ASSERT(m_callbacks, !is_root(node));
            auto pid = parent(node); C4_UNUSED(pid);
            _RYML_CB_ASSERT(m_callbacks, is_map(pid));
        }
        if((f & VAL) && !is_root(node))
        {
            auto pid = parent(node); C4_UNUSED(pid);
            _RYML_CB_ASSERT(m_callbacks, is_map(pid) || is_seq(pid));
        }
    }
    #endif

    inline void _set_flags(id_type node, NodeType_e f) { _check_next_flags(node, f); _p(node)->m_type = f; }
    inline void _set_flags(id_type node, type_bits  f) { _check_next_flags(node, f); _p(node)->m_type = f; }

    inline void _add_flags(id_type node, NodeType_e f) { NodeData *d = _p(node); type_bits fb = f |  d->m_type; _check_next_flags(node, fb); d->m_type = (NodeType_e) fb; }
    inline void _add_flags(id_type node, type_bits  f) { NodeData *d = _p(node);                f |= d->m_type; _check_next_flags(node,  f); d->m_type = f; }

    inline void _rem_flags(id_type node, NodeType_e f) { NodeData *d = _p(node); type_bits fb = d->m_type & ~f; _check_next_flags(node, fb); d->m_type = (NodeType_e) fb; }
    inline void _rem_flags(id_type node, type_bits  f) { NodeData *d = _p(node);            f = d->m_type & ~f; _check_next_flags(node,  f); d->m_type = f; }

    void _set_key(id_type node, csubstr key, type_bits more_flags=0)
    {
        _p(node)->m_key.scalar = key;
        _add_flags(node, KEY|more_flags);
    }
    void _set_key(id_type node, NodeScalar const& key, type_bits more_flags=0)
    {
        _p(node)->m_key = key;
        _add_flags(node, KEY|more_flags);
    }

    void _set_val(id_type node, csubstr val, type_bits more_flags=0)
    {
        _RYML_CB_ASSERT(m_callbacks, num_children(node) == 0);
        _RYML_CB_ASSERT(m_callbacks, !is_seq(node) && !is_map(node));
        _p(node)->m_val.scalar = val;
        _add_flags(node, VAL|more_flags);
    }
    void _set_val(id_type node, NodeScalar const& val, type_bits more_flags=0)
    {
        _RYML_CB_ASSERT(m_callbacks, num_children(node) == 0);
        _RYML_CB_ASSERT(m_callbacks,  ! is_container(node));
        _p(node)->m_val = val;
        _add_flags(node, VAL|more_flags);
    }

    void _set(id_type node, NodeInit const& i)
    {
        _RYML_CB_ASSERT(m_callbacks, i._check());
        NodeData *n = _p(node);
        _RYML_CB_ASSERT(m_callbacks, n->m_key.scalar.empty() || i.key.scalar.empty() || i.key.scalar == n->m_key.scalar);
        _add_flags(node, i.type);
        if(n->m_key.scalar.empty())
        {
            if( ! i.key.scalar.empty())
            {
                _set_key(node, i.key.scalar);
            }
        }
        n->m_key.tag = i.key.tag;
        n->m_val = i.val;
    }

    void _set_parent_as_container_if_needed(id_type in)
    {
        NodeData const* n = _p(in);
        id_type ip = parent(in);
        if(ip != NONE)
        {
            if( ! (is_seq(ip) || is_map(ip)))
            {
                if((in == first_child(ip)) && (in == last_child(ip)))
                {
                    if( ! n->m_key.empty() || has_key(in))
                    {
                        _add_flags(ip, MAP);
                    }
                    else
                    {
                        _add_flags(ip, SEQ);
                    }
                }
            }
        }
    }

    void _seq2map(id_type node)
    {
        _RYML_CB_ASSERT(m_callbacks, is_seq(node));
        for(id_type i = first_child(node); i != NONE; i = next_sibling(i))
        {
            NodeData *C4_RESTRICT ch = _p(i);
            if(ch->m_type.is_keyval())
                continue;
            ch->m_type.add(KEY);
            ch->m_key = ch->m_val;
        }
        auto *C4_RESTRICT n = _p(node);
        n->m_type.rem(SEQ);
        n->m_type.add(MAP);
    }

    id_type _do_reorder(id_type *node, id_type count);

    void _swap(id_type n_, id_type m_);
    void _swap_props(id_type n_, id_type m_);
    void _swap_hierarchy(id_type n_, id_type m_);
    void _copy_hierarchy(id_type dst_, id_type src_);

    inline void _copy_props(id_type dst_, id_type src_)
    {
        _copy_props(dst_, this, src_);
    }

    inline void _copy_props_wo_key(id_type dst_, id_type src_)
    {
        _copy_props_wo_key(dst_, this, src_);
    }

    void _copy_props(id_type dst_, Tree const* that_tree, id_type src_)
    {
        auto      & C4_RESTRICT dst = *_p(dst_);
        auto const& C4_RESTRICT src = *that_tree->_p(src_);
        dst.m_type = src.m_type;
        dst.m_key  = src.m_key;
        dst.m_val  = src.m_val;
    }

    void _copy_props(id_type dst_, Tree const* that_tree, id_type src_, type_bits src_mask)
    {
        auto      & C4_RESTRICT dst = *_p(dst_);
        auto const& C4_RESTRICT src = *that_tree->_p(src_);
        dst.m_type = (src.m_type & src_mask) | (dst.m_type & ~src_mask);
        dst.m_key  = src.m_key;
        dst.m_val  = src.m_val;
    }

    void _copy_props_wo_key(id_type dst_, Tree const* that_tree, id_type src_)
    {
        auto      & C4_RESTRICT dst = *_p(dst_);
        auto const& C4_RESTRICT src = *that_tree->_p(src_);
        dst.m_type = (src.m_type & ~_KEYMASK) | (dst.m_type & _KEYMASK);
        dst.m_val  = src.m_val;
    }

    void _copy_props_wo_key(id_type dst_, Tree const* that_tree, id_type src_, type_bits src_mask)
    {
        auto      & C4_RESTRICT dst = *_p(dst_);
        auto const& C4_RESTRICT src = *that_tree->_p(src_);
        dst.m_type = (src.m_type & ((~_KEYMASK)|src_mask)) | (dst.m_type & (_KEYMASK|~src_mask));
        dst.m_val  = src.m_val;
    }

    inline void _clear_type(id_type node)
    {
        _p(node)->m_type = NOTYPE;
    }

    inline void _clear(id_type node)
    {
        auto *C4_RESTRICT n = _p(node);
        n->m_type = NOTYPE;
        n->m_key.clear();
        n->m_val.clear();
        n->m_parent = NONE;
        n->m_first_child = NONE;
        n->m_last_child = NONE;
    }

    inline void _clear_key(id_type node)
    {
        _p(node)->m_key.clear();
        _rem_flags(node, KEY);
    }

    inline void _clear_val(id_type node)
    {
        _p(node)->m_val.clear();
        _rem_flags(node, VAL);
    }

    /** @endcond */

private:

    void _clear_range(id_type first, id_type num);

public:
    id_type _claim();
private:
    void   _claim_root();
    void   _release(id_type node);
    void   _free_list_add(id_type node);
    void   _free_list_rem(id_type node);

    void _set_hierarchy(id_type node, id_type parent, id_type after_sibling);
    void _rem_hierarchy(id_type node);

public:

    // members are exposed, but you should NOT access them directly

    NodeData *m_buf;
    id_type   m_cap;

    id_type m_size;

    id_type m_free_head;
    id_type m_free_tail;

    substr m_arena;
    size_t m_arena_pos;

    Callbacks m_callbacks;

    TagDirective m_tag_directives[RYML_MAX_TAG_DIRECTIVES];

};

/** @} */

} // namespace yml
} // namespace c4


C4_SUPPRESS_WARNING_MSVC_POP
C4_SUPPRESS_WARNING_GCC_CLANG_POP


#endif /* _C4_YML_TREE_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/tree.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/node.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/node.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_NODE_HPP_
#define _C4_YML_NODE_HPP_

/** @file node.hpp Node classes */

//included above:
//#include <cstddef>

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/tree.hpp
//#include "c4/yml/tree.hpp"
#if !defined(C4_YML_TREE_HPP_) && !defined(_C4_YML_TREE_HPP_)
#error "amalgamate: file c4/yml/tree.hpp must have been included at this point"
#endif /* C4_YML_TREE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/base64.hpp
//#include "c4/base64.hpp"
#if !defined(C4_BASE64_HPP_) && !defined(_C4_BASE64_HPP_)
#error "amalgamate: file c4/base64.hpp must have been included at this point"
#endif /* C4_BASE64_HPP_ */


#ifdef __clang__
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wtype-limits"
#   pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wtype-limits"
#   pragma GCC diagnostic ignored "-Wold-style-cast"
#   pragma GCC diagnostic ignored "-Wuseless-cast"
#elif defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable: 4251/*needs to have dll-interface to be used by clients of struct*/)
#   pragma warning(disable: 4296/*expression is always 'boolean_value'*/)
#endif

namespace c4 {
namespace yml {

/** @addtogroup doc_node_classes
 *
 * @{
 */


/** @defgroup doc_serialization_helpers Serialization helpers
 *
 * @{
 */
template<class K> struct Key { K & k; };
template<> struct Key<fmt::const_base64_wrapper> { fmt::const_base64_wrapper wrapper; };
template<> struct Key<fmt::base64_wrapper> { fmt::base64_wrapper wrapper; };

template<class K> C4_ALWAYS_INLINE Key<K> key(K & k) { return Key<K>{k}; }
C4_ALWAYS_INLINE Key<fmt::const_base64_wrapper> key(fmt::const_base64_wrapper w) { return {w}; }
C4_ALWAYS_INLINE Key<fmt::base64_wrapper> key(fmt::base64_wrapper w) { return {w}; }

template<class T> void write(NodeRef *n, T const& v);

template<class T>
typename std::enable_if< ! std::is_floating_point<T>::value, bool>::type
read(NodeRef const& n, T *v);

template<class T>
typename std::enable_if<   std::is_floating_point<T>::value, bool>::type
read(NodeRef const& n, T *v);

/** @} */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

// forward decls
class NodeRef;
class ConstNodeRef;


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @cond dev */
namespace detail {

template<class NodeRefType>
struct child_iterator
{
    using value_type = NodeRefType;
    using tree_type = typename NodeRefType::tree_type;

    tree_type * C4_RESTRICT m_tree;
    id_type m_child_id;

    child_iterator(tree_type * t, id_type id) : m_tree(t), m_child_id(id) {}

    child_iterator& operator++ () { RYML_ASSERT(m_child_id != NONE); m_child_id = m_tree->next_sibling(m_child_id); return *this; }
    child_iterator& operator-- () { RYML_ASSERT(m_child_id != NONE); m_child_id = m_tree->prev_sibling(m_child_id); return *this; }

    NodeRefType operator*  () const { return NodeRefType(m_tree, m_child_id); }
    NodeRefType operator-> () const { return NodeRefType(m_tree, m_child_id); }

    bool operator!= (child_iterator that) const { RYML_ASSERT(m_tree == that.m_tree); return m_child_id != that.m_child_id; }
    bool operator== (child_iterator that) const { RYML_ASSERT(m_tree == that.m_tree); return m_child_id == that.m_child_id; }
};

template<class NodeRefType>
struct children_view_
{
    using n_iterator = child_iterator<NodeRefType>;

    n_iterator b, e;

    inline children_view_(n_iterator const& C4_RESTRICT b_,
                          n_iterator const& C4_RESTRICT e_) : b(b_), e(e_) {}

    inline n_iterator begin() const { return b; }
    inline n_iterator end  () const { return e; }
};

template<class NodeRefType, class Visitor>
bool _visit(NodeRefType &node, Visitor fn, id_type indentation_level, bool skip_root=false)
{
    id_type increment = 0;
    if( ! (node.is_root() && skip_root))
    {
        if(fn(node, indentation_level))
            return true;
        ++increment;
    }
    if(node.has_children())
    {
        for(auto ch : node.children())
        {
            if(_visit(ch, fn, indentation_level + increment, false)) // no need to forward skip_root as it won't be root
            {
                return true;
            }
        }
    }
    return false;
}

template<class NodeRefType, class Visitor>
bool _visit_stacked(NodeRefType &node, Visitor fn, id_type indentation_level, bool skip_root=false)
{
    id_type increment = 0;
    if( ! (node.is_root() && skip_root))
    {
        if(fn(node, indentation_level))
        {
            return true;
        }
        ++increment;
    }
    if(node.has_children())
    {
        fn.push(node, indentation_level);
        for(auto ch : node.children())
        {
            if(_visit_stacked(ch, fn, indentation_level + increment, false)) // no need to forward skip_root as it won't be root
            {
                fn.pop(node, indentation_level);
                return true;
            }
        }
        fn.pop(node, indentation_level);
    }
    return false;
}

template<class Impl, class ConstImpl>
struct RoNodeMethods;
} // detail
/** @endcond */

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


/** a CRTP base providing read-only methods for @ref ConstNodeRef and @ref NodeRef */
namespace detail {
template<class Impl, class ConstImpl>
struct RoNodeMethods
{
    C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wcast-align")
    /** @cond dev */
    // helper CRTP macros, undefined at the end
    #define tree_ ((ConstImpl const* C4_RESTRICT)this)->m_tree
    #define id_ ((ConstImpl const* C4_RESTRICT)this)->m_id
    #define tree__ ((Impl const* C4_RESTRICT)this)->m_tree
    #define id__ ((Impl const* C4_RESTRICT)this)->m_id
    // require readable: this is a precondition for reading from the
    // tree using this object.
    #define _C4RR()                                       \
        RYML_ASSERT(tree_ != nullptr);                    \
        _RYML_CB_ASSERT(tree_->m_callbacks, id_ != NONE); \
        _RYML_CB_ASSERT(tree_->m_callbacks, (((Impl const* C4_RESTRICT)this)->readable()))
    // a SFINAE beautifier to enable a function only if the
    // implementation is mutable
    #define _C4_IF_MUTABLE(ty) typename std::enable_if<!std::is_same<U, ConstImpl>::value, ty>::type
    /** @endcond */

public:

    /** @name node property getters */
    /** @{ */

    /** returns the data or null when the id is NONE */
    C4_ALWAYS_INLINE NodeData const* get() const RYML_NOEXCEPT { return ((Impl const*)this)->readable() ? tree_->get(id_) : nullptr; }
    /** returns the data or null when the id is NONE */
    template<class U=Impl>
    C4_ALWAYS_INLINE auto get() RYML_NOEXCEPT -> _C4_IF_MUTABLE(NodeData*) { return ((Impl const*)this)->readable() ? tree__->get(id__) : nullptr; }

    C4_ALWAYS_INLINE NodeType    type()     const RYML_NOEXCEPT { _C4RR(); return tree_->type(id_); }     /**< Forward to @ref Tree::type_str(). Node must be readable. */
    C4_ALWAYS_INLINE const char* type_str() const RYML_NOEXCEPT { _C4RR(); return tree_->type_str(id_); } /**< Forward to @ref Tree::type_str(). Node must be readable. */

    C4_ALWAYS_INLINE csubstr key()        const RYML_NOEXCEPT { _C4RR(); return tree_->key(id_); }        /**< Forward to @ref Tree::key(). Node must be readable. */
    C4_ALWAYS_INLINE csubstr key_tag()    const RYML_NOEXCEPT { _C4RR(); return tree_->key_tag(id_); }    /**< Forward to @ref Tree::key_tag(). Node must be readable. */
    C4_ALWAYS_INLINE csubstr key_ref()    const RYML_NOEXCEPT { _C4RR(); return tree_->key_ref(id_); }    /**< Forward to @ref Tree::key_ref(). Node must be readable. */
    C4_ALWAYS_INLINE csubstr key_anchor() const RYML_NOEXCEPT { _C4RR(); return tree_->key_anchor(id_); } /**< Forward to @ref Tree::key_anchor(). Node must be readable. */

    C4_ALWAYS_INLINE csubstr val()        const RYML_NOEXCEPT { _C4RR(); return tree_->val(id_); }        /**< Forward to @ref Tree::val(). Node must be readable. */
    C4_ALWAYS_INLINE csubstr val_tag()    const RYML_NOEXCEPT { _C4RR(); return tree_->val_tag(id_); }    /**< Forward to @ref Tree::val_tag(). Node must be readable. */
    C4_ALWAYS_INLINE csubstr val_ref()    const RYML_NOEXCEPT { _C4RR(); return tree_->val_ref(id_); }    /**< Forward to @ref Tree::val_ref(). Node must be readable. */
    C4_ALWAYS_INLINE csubstr val_anchor() const RYML_NOEXCEPT { _C4RR(); return tree_->val_anchor(id_); } /**< Forward to @ref Tree::val_anchor(). Node must be readable. */

    C4_ALWAYS_INLINE NodeScalar const& keysc() const RYML_NOEXCEPT { _C4RR(); return tree_->keysc(id_); } /**< Forward to @ref Tree::keysc(). Node must be readable. */
    C4_ALWAYS_INLINE NodeScalar const& valsc() const RYML_NOEXCEPT { _C4RR(); return tree_->valsc(id_); } /**< Forward to @ref Tree::valsc(). Node must be readable. */

    C4_ALWAYS_INLINE bool key_is_null() const RYML_NOEXCEPT { _C4RR(); return tree_->key_is_null(id_); } /**< Forward to @ref Tree::key_is_null(). Node must be readable. */
    C4_ALWAYS_INLINE bool val_is_null() const RYML_NOEXCEPT { _C4RR(); return tree_->val_is_null(id_); } /**< Forward to @ref Tree::val_is_null(). Node must be readable. */

    C4_ALWAYS_INLINE bool is_key_unfiltered() const noexcept { _C4RR(); return tree_->is_key_unfiltered(id_); } /**< Forward to @ref Tree::is_key_unfiltered(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_val_unfiltered() const noexcept { _C4RR(); return tree_->is_val_unfiltered(id_); } /**< Forward to @ref Tree::is_val_unfiltered(). Node must be readable. */

    /** @} */

public:

    /** @name node type predicates */
    /** @{ */

    C4_ALWAYS_INLINE bool empty()            const RYML_NOEXCEPT { _C4RR(); return tree_->empty(id_); } /**< Forward to @ref Tree::empty(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_stream()        const RYML_NOEXCEPT { _C4RR(); return tree_->is_stream(id_); } /**< Forward to @ref Tree::is_stream(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_doc()           const RYML_NOEXCEPT { _C4RR(); return tree_->is_doc(id_); } /**< Forward to @ref Tree::is_doc(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_container()     const RYML_NOEXCEPT { _C4RR(); return tree_->is_container(id_); } /**< Forward to @ref Tree::is_container(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_map()           const RYML_NOEXCEPT { _C4RR(); return tree_->is_map(id_); } /**< Forward to @ref Tree::is_map(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_seq()           const RYML_NOEXCEPT { _C4RR(); return tree_->is_seq(id_); } /**< Forward to @ref Tree::is_seq(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_val()          const RYML_NOEXCEPT { _C4RR(); return tree_->has_val(id_); } /**< Forward to @ref Tree::has_val(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_key()          const RYML_NOEXCEPT { _C4RR(); return tree_->has_key(id_); } /**< Forward to @ref Tree::has_key(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_val()           const RYML_NOEXCEPT { _C4RR(); return tree_->is_val(id_); } /**< Forward to @ref Tree::is_val(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_keyval()        const RYML_NOEXCEPT { _C4RR(); return tree_->is_keyval(id_); } /**< Forward to @ref Tree::is_keyval(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_key_tag()      const RYML_NOEXCEPT { _C4RR(); return tree_->has_key_tag(id_); } /**< Forward to @ref Tree::has_key_tag(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_val_tag()      const RYML_NOEXCEPT { _C4RR(); return tree_->has_val_tag(id_); } /**< Forward to @ref Tree::has_val_tag(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_key_anchor()   const RYML_NOEXCEPT { _C4RR(); return tree_->has_key_anchor(id_); } /**< Forward to @ref Tree::has_key_anchor(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_val_anchor()   const RYML_NOEXCEPT { _C4RR(); return tree_->has_val_anchor(id_); } /**< Forward to @ref Tree::has_val_anchor(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_anchor()       const RYML_NOEXCEPT { _C4RR(); return tree_->has_anchor(id_); } /**< Forward to @ref Tree::has_anchor(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_key_ref()       const RYML_NOEXCEPT { _C4RR(); return tree_->is_key_ref(id_); } /**< Forward to @ref Tree::is_key_ref(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_val_ref()       const RYML_NOEXCEPT { _C4RR(); return tree_->is_val_ref(id_); } /**< Forward to @ref Tree::is_val_ref(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_ref()           const RYML_NOEXCEPT { _C4RR(); return tree_->is_ref(id_); } /**< Forward to @ref Tree::is_ref(). Node must be readable. */
    C4_ALWAYS_INLINE bool parent_is_seq()    const RYML_NOEXCEPT { _C4RR(); return tree_->parent_is_seq(id_); } /**< Forward to @ref Tree::parent_is_seq(). Node must be readable. */
    C4_ALWAYS_INLINE bool parent_is_map()    const RYML_NOEXCEPT { _C4RR(); return tree_->parent_is_map(id_); } /**< Forward to @ref Tree::parent_is_map(). Node must be readable. */

    RYML_DEPRECATED("use has_key_anchor()")  bool is_key_anchor() const noexcept { _C4RR(); return tree_->has_key_anchor(id_); }
    RYML_DEPRECATED("use has_val_anchor()")  bool is_val_hanchor() const noexcept { _C4RR(); return tree_->has_val_anchor(id_); }
    RYML_DEPRECATED("use has_anchor()")      bool is_anchor()     const noexcept { _C4RR(); return tree_->has_anchor(id_); }
    RYML_DEPRECATED("use has_anchor() || is_ref()") bool is_anchor_or_ref() const noexcept { _C4RR(); return tree_->is_anchor_or_ref(id_); }

    /** @} */

public:

    /** @name node container+scalar style predicates */
    /** @{ */

    // documentation to the right -->

    C4_ALWAYS_INLINE bool type_has_any(NodeType_e bits)  const RYML_NOEXCEPT { _C4RR(); return tree_->type_has_any(id_, bits); }  /**< Forward to @ref Tree::type_has_any(). Node must be readable. */
    C4_ALWAYS_INLINE bool type_has_all(NodeType_e bits)  const RYML_NOEXCEPT { _C4RR(); return tree_->type_has_all(id_, bits); }  /**< Forward to @ref Tree::type_has_all(). Node must be readable. */
    C4_ALWAYS_INLINE bool type_has_none(NodeType_e bits) const RYML_NOEXCEPT { _C4RR(); return tree_->type_has_none(id_, bits); } /**< Forward to @ref Tree::type_has_none(). Node must be readable. */

    C4_ALWAYS_INLINE bool is_container_styled() const RYML_NOEXCEPT { _C4RR(); return tree_->is_container_styled(id_); } /**< Forward to @ref Tree::is_container_styled(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_block()            const RYML_NOEXCEPT { _C4RR(); return tree_->is_block(id_); }   /**< Forward to @ref Tree::is_block(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_flow_sl()          const RYML_NOEXCEPT { _C4RR(); return tree_->is_flow_sl(id_); } /**< Forward to @ref Tree::is_flow_sl(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_flow_ml()          const RYML_NOEXCEPT { _C4RR(); return tree_->is_flow_ml(id_); } /**< Forward to @ref Tree::is_flow_ml(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_flow()             const RYML_NOEXCEPT { _C4RR(); return tree_->is_flow(id_); }    /**< Forward to @ref Tree::is_flow(). Node must be readable. */

    C4_ALWAYS_INLINE bool is_key_styled()       const RYML_NOEXCEPT { _C4RR(); return tree_->is_key_styled(id_); }  /**< Forward to @ref Tree::is_key_styled(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_val_styled()       const RYML_NOEXCEPT { _C4RR(); return tree_->is_val_styled(id_); }  /**< Forward to @ref Tree::is_val_styled(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_key_literal()      const RYML_NOEXCEPT { _C4RR(); return tree_->is_key_literal(id_); } /**< Forward to @ref Tree::is_key_literal(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_val_literal()      const RYML_NOEXCEPT { _C4RR(); return tree_->is_val_literal(id_); } /**< Forward to @ref Tree::is_val_literal(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_key_folded()       const RYML_NOEXCEPT { _C4RR(); return tree_->is_key_folded(id_); }  /**< Forward to @ref Tree::is_key_folded(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_val_folded()       const RYML_NOEXCEPT { _C4RR(); return tree_->is_val_folded(id_); }  /**< Forward to @ref Tree::is_val_folded(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_key_squo()         const RYML_NOEXCEPT { _C4RR(); return tree_->is_key_squo(id_); }    /**< Forward to @ref Tree::is_key_squo(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_val_squo()         const RYML_NOEXCEPT { _C4RR(); return tree_->is_val_squo(id_); }    /**< Forward to @ref Tree::is_val_squo(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_key_dquo()         const RYML_NOEXCEPT { _C4RR(); return tree_->is_key_dquo(id_); }    /**< Forward to @ref Tree::is_key_dquo(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_val_dquo()         const RYML_NOEXCEPT { _C4RR(); return tree_->is_val_dquo(id_); }    /**< Forward to @ref Tree::is_val_dquo(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_key_plain()        const RYML_NOEXCEPT { _C4RR(); return tree_->is_key_plain(id_); }   /**< Forward to @ref Tree::is_key_plain(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_val_plain()        const RYML_NOEXCEPT { _C4RR(); return tree_->is_val_plain(id_); }   /**< Forward to @ref Tree::is_val_plain(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_key_quoted()       const RYML_NOEXCEPT { _C4RR(); return tree_->is_key_quoted(id_); }  /**< Forward to @ref Tree::is_key_quoted(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_val_quoted()       const RYML_NOEXCEPT { _C4RR(); return tree_->is_val_quoted(id_); }  /**< Forward to @ref Tree::is_val_quoted(). Node must be readable. */
    C4_ALWAYS_INLINE bool is_quoted()           const RYML_NOEXCEPT { _C4RR(); return tree_->is_quoted(id_); }      /**< Forward to @ref Tree::is_quoted(). Node must be readable. */

    /** @} */

public:

    /** @name hierarchy predicates */
    /** @{ */

    // documentation to the right -->

    C4_ALWAYS_INLINE bool is_root()    const RYML_NOEXCEPT { _C4RR(); return tree_->is_root(id_); } /**< Forward to @ref Tree::is_root(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_parent() const RYML_NOEXCEPT { _C4RR(); return tree_->has_parent(id_); } /**< Forward to @ref Tree::has_parent()  Node must be readable. */

    C4_ALWAYS_INLINE bool has_child(ConstImpl const& n) const RYML_NOEXCEPT { _C4RR(); return n.readable() ? tree_->has_child(id_, n.m_id) : false; } /**< Forward to @ref Tree::has_child(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_child(id_type node) const RYML_NOEXCEPT { _C4RR(); return tree_->has_child(id_, node); } /**< Forward to @ref Tree::has_child(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_child(csubstr name) const RYML_NOEXCEPT { _C4RR(); return tree_->has_child(id_, name); } /**< Forward to @ref Tree::has_child(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_children() const RYML_NOEXCEPT { _C4RR(); return tree_->has_children(id_); } /**< Forward to @ref Tree::has_child(). Node must be readable. */

    C4_ALWAYS_INLINE bool has_sibling(ConstImpl const& n) const RYML_NOEXCEPT { _C4RR(); return n.readable() ? tree_->has_sibling(id_, n.m_id) : false; } /**< Forward to @ref Tree::has_sibling(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_sibling(id_type node) const RYML_NOEXCEPT { _C4RR(); return tree_->has_sibling(id_, node); } /**< Forward to @ref Tree::has_sibling(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_sibling(csubstr name) const RYML_NOEXCEPT { _C4RR(); return tree_->has_sibling(id_, name); } /**< Forward to @ref Tree::has_sibling(). Node must be readable. */
    C4_ALWAYS_INLINE bool has_other_siblings() const RYML_NOEXCEPT { _C4RR(); return tree_->has_other_siblings(id_); }  /**< Forward to @ref Tree::has_sibling(). Node must be readable. */

    RYML_DEPRECATED("use has_other_siblings()") bool has_siblings() const RYML_NOEXCEPT { _C4RR(); return tree_->has_siblings(id_); }

    /** @} */

public:

    /** @name hierarchy getters */
    /** @{ */

    // documentation to the right -->

    template<class U=Impl>
    C4_ALWAYS_INLINE auto doc(id_type i) RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { RYML_ASSERT(tree_); return {tree__, tree__->doc(i)}; } /**< Forward to @ref Tree::doc(). Node must be readable. */
    /** succeeds even when the node may have invalid or seed id */
    C4_ALWAYS_INLINE ConstImpl doc(id_type i) const RYML_NOEXCEPT { RYML_ASSERT(tree_); return {tree_, tree_->doc(i)}; }                /**< Forward to @ref Tree::doc(). Node must be readable. */

    template<class U=Impl>
    C4_ALWAYS_INLINE auto parent() RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { _C4RR(); return {tree__, tree__->parent(id__)}; } /**< Forward to @ref Tree::parent(). Node must be readable. */
    C4_ALWAYS_INLINE ConstImpl parent() const RYML_NOEXCEPT { _C4RR(); return {tree_, tree_->parent(id_)}; }                 /**< Forward to @ref Tree::parent(). Node must be readable. */

    template<class U=Impl>
    C4_ALWAYS_INLINE auto first_child() RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { _C4RR(); return {tree__, tree__->first_child(id__)}; }  /**< Forward to @ref Tree::first_child(). Node must be readable. */
    C4_ALWAYS_INLINE ConstImpl first_child() const RYML_NOEXCEPT { _C4RR(); return {tree_, tree_->first_child(id_)}; }                  /**< Forward to @ref Tree::first_child(). Node must be readable. */

    template<class U=Impl>
    C4_ALWAYS_INLINE auto last_child() RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { _C4RR(); return {tree__, tree__->last_child(id__)}; }  /**< Forward to @ref Tree::last_child(). Node must be readable. */
    C4_ALWAYS_INLINE ConstImpl last_child () const RYML_NOEXCEPT { _C4RR(); return {tree_, tree_->last_child (id_)}; }                /**< Forward to @ref Tree::last_child(). Node must be readable. */

    template<class U=Impl>
    C4_ALWAYS_INLINE auto child(id_type pos) RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { _C4RR(); return {tree__, tree__->child(id__, pos)}; }  /**< Forward to @ref Tree::child(). Node must be readable. */
    C4_ALWAYS_INLINE ConstImpl child(id_type pos) const RYML_NOEXCEPT { _C4RR(); return {tree_, tree_->child(id_, pos)}; }                  /**< Forward to @ref Tree::child(). Node must be readable. */

    template<class U=Impl>
    C4_ALWAYS_INLINE auto find_child(csubstr name)  RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { _C4RR(); return {tree__, tree__->find_child(id__, name)}; }  /**< Forward to @ref Tree::first_child(). Node must be readable. */
    C4_ALWAYS_INLINE ConstImpl find_child(csubstr name) const RYML_NOEXCEPT { _C4RR(); return {tree_, tree_->find_child(id_, name)}; }                   /**< Forward to @ref Tree::first_child(). Node must be readable. */

    template<class U=Impl>
    C4_ALWAYS_INLINE auto prev_sibling() RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { _C4RR(); return {tree__, tree__->prev_sibling(id__)}; }  /**< Forward to @ref Tree::prev_sibling(). Node must be readable. */
    C4_ALWAYS_INLINE ConstImpl prev_sibling() const RYML_NOEXCEPT { _C4RR(); return {tree_, tree_->prev_sibling(id_)}; }                  /**< Forward to @ref Tree::prev_sibling(). Node must be readable. */

    template<class U=Impl>
    C4_ALWAYS_INLINE auto next_sibling() RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { _C4RR(); return {tree__, tree__->next_sibling(id__)}; }  /**< Forward to @ref Tree::next_sibling(). Node must be readable. */
    C4_ALWAYS_INLINE ConstImpl next_sibling() const RYML_NOEXCEPT { _C4RR(); return {tree_, tree_->next_sibling(id_)}; }                  /**< Forward to @ref Tree::next_sibling(). Node must be readable. */

    template<class U=Impl>
    C4_ALWAYS_INLINE auto first_sibling() RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { _C4RR(); return {tree__, tree__->first_sibling(id__)}; }  /**< Forward to @ref Tree::first_sibling(). Node must be readable. */
    C4_ALWAYS_INLINE ConstImpl first_sibling() const RYML_NOEXCEPT { _C4RR(); return {tree_, tree_->first_sibling(id_)}; }                  /**< Forward to @ref Tree::first_sibling(). Node must be readable. */

    template<class U=Impl>
    C4_ALWAYS_INLINE auto last_sibling() RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { _C4RR(); return {tree__, tree__->last_sibling(id__)}; }  /**< Forward to @ref Tree::last_sibling(). Node must be readable. */
    C4_ALWAYS_INLINE ConstImpl last_sibling () const RYML_NOEXCEPT { _C4RR(); return {tree_, tree_->last_sibling(id_)}; }                 /**< Forward to @ref Tree::last_sibling(). Node must be readable. */

    template<class U=Impl>
    C4_ALWAYS_INLINE auto sibling(id_type pos) RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { _C4RR(); return {tree__, tree__->sibling(id__, pos)}; }  /**< Forward to @ref Tree::sibling(). Node must be readable. */
    C4_ALWAYS_INLINE ConstImpl sibling(id_type pos) const RYML_NOEXCEPT { _C4RR(); return {tree_, tree_->sibling(id_, pos)}; }                  /**< Forward to @ref Tree::sibling(). Node must be readable. */

    template<class U=Impl>
    C4_ALWAYS_INLINE auto find_sibling(csubstr name) RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl) { _C4RR(); return {tree__, tree__->find_sibling(id__, name)}; }  /**< Forward to @ref Tree::find_sibling(). Node must be readable. */
    C4_ALWAYS_INLINE ConstImpl find_sibling(csubstr name) const RYML_NOEXCEPT { _C4RR(); return {tree_, tree_->find_sibling(id_, name)}; }                  /**< Forward to @ref Tree::find_sibling(). Node must be readable. */

    C4_ALWAYS_INLINE id_type num_children() const RYML_NOEXCEPT { _C4RR(); return tree_->num_children(id_); } /**< O(num_children). Forward to @ref Tree::num_children(). */
    C4_ALWAYS_INLINE id_type num_siblings() const RYML_NOEXCEPT { _C4RR(); return tree_->num_siblings(id_); } /**< O(num_children). Forward to @ref Tree::num_siblings(). */
    C4_ALWAYS_INLINE id_type num_other_siblings() const RYML_NOEXCEPT { _C4RR(); return tree_->num_other_siblings(id_); } /**< O(num_siblings). Forward to @ref Tree::num_other_siblings(). */
    C4_ALWAYS_INLINE id_type child_pos(ConstImpl const& n) const RYML_NOEXCEPT { _C4RR(); _RYML_CB_ASSERT(tree_->m_callbacks, n.readable()); return tree_->child_pos(id_, n.m_id); } /**< O(num_children). Forward to @ref Tree::child_pos(). */
    C4_ALWAYS_INLINE id_type sibling_pos(ConstImpl const& n) const RYML_NOEXCEPT { _C4RR(); _RYML_CB_ASSERT(tree_->callbacks(), n.readable()); return tree_->child_pos(tree_->parent(id_), n.m_id); } /**< O(num_siblings). Forward to @ref Tree::sibling_pos(). */

    C4_ALWAYS_INLINE id_type depth_asc() const RYML_NOEXCEPT { _C4RR(); return tree_->depth_asc(id_); } /** O(log(num_nodes)). Forward to Tree::depth_asc(). Node must be readable. */
    C4_ALWAYS_INLINE id_type depth_desc() const RYML_NOEXCEPT { _C4RR(); return tree_->depth_desc(id_); } /** O(num_nodes). Forward to Tree::depth_desc(). Node must be readable. */

    /** @} */

public:

    /** @name square_brackets
     * operator[] */
    /** @{ */

    /** Find child by key; complexity is O(num_children).
     *
     * Returns the requested node, or an object in seed state if no
     * such child is found (see @ref NodeRef for an explanation of
     * what is seed state). When the object is in seed state, using it
     * to read from the tree is UB. The seed node can be used to write
     * to the tree provided that its create() method is called prior
     * to writing, which happens in most modifying methods in
     * NodeRef. It is the caller's responsibility to verify that the
     * returned node is readable before subsequently using it to read
     * from the tree.
     *
     * @warning the calling object must be readable. This precondition
     * is asserted. The assertion is performed only if @ref
     * RYML_USE_ASSERT is set to true. As with the non-const overload,
     * it is UB to call this method if the node is not readable.
     *
     * @see https://github.com/biojppm/rapidyaml/issues/389 */
    template<class U=Impl>
    C4_ALWAYS_INLINE auto operator[] (csubstr key) RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl)
    {
        _C4RR();
        id_type ch = tree__->find_child(id__, key);
        return ch != NONE ? Impl(tree__, ch) : Impl(tree__, id__, key);
    }

    /** Find child by position; complexity is O(pos).
     *
     * Returns the requested node, or an object in seed state if no
     * such child is found (see @ref NodeRef for an explanation of
     * what is seed state). When the object is in seed state, using it
     * to read from the tree is UB. The seed node can be used to write
     * to the tree provided that its create() method is called prior
     * to writing, which happens in most modifying methods in
     * NodeRef. It is the caller's responsibility to verify that the
     * returned node is readable before subsequently using it to read
     * from the tree.
     *
     * @warning the calling object must be readable. This precondition
     * is asserted. The assertion is performed only if @ref
     * RYML_USE_ASSERT is set to true. As with the non-const overload,
     * it is UB to call this method if the node is not readable.
     *
     * @see https://github.com/biojppm/rapidyaml/issues/389 */
    template<class U=Impl>
    C4_ALWAYS_INLINE auto operator[] (id_type pos) RYML_NOEXCEPT -> _C4_IF_MUTABLE(Impl)
    {
        _C4RR();
        id_type ch = tree__->child(id__, pos);
        return ch != NONE ? Impl(tree__, ch) : Impl(tree__, id__, pos);
    }

    /** Find a child by key; complexity is O(num_children).
     *
     * Behaves similar to the non-const overload, but further asserts
     * that the returned node is readable (because it can never be in
     * a seed state). The assertion is performed only if @ref
     * RYML_USE_ASSERT is set to true. As with the non-const overload,
     * it is UB to use the return value if it is not valid.
     *
     * @see https://github.com/biojppm/rapidyaml/issues/389  */
    C4_ALWAYS_INLINE ConstImpl operator[] (csubstr key) const RYML_NOEXCEPT
    {
        _C4RR();
        id_type ch = tree_->find_child(id_, key);
        _RYML_CB_ASSERT(tree_->m_callbacks, ch != NONE);
        return {tree_, ch};
    }

    /** Find a child by position; complexity is O(pos).
     *
     * Behaves similar to the non-const overload, but further asserts
     * that the returned node is readable (because it can never be in
     * a seed state). This assertion is performed only if @ref
     * RYML_USE_ASSERT is set to true. As with the non-const overload,
     * it is UB to use the return value if it is not valid.
     *
     * @see https://github.com/biojppm/rapidyaml/issues/389  */
    C4_ALWAYS_INLINE ConstImpl operator[] (id_type pos) const RYML_NOEXCEPT
    {
        _C4RR();
        id_type ch = tree_->child(id_, pos);
        _RYML_CB_ASSERT(tree_->m_callbacks, ch != NONE);
        return {tree_, ch};
    }

    /** @} */

public:

    /** @name at
     *
     * These functions are the analogue to operator[], with the
     * difference that they emit an error instead of an
     * assertion. That is, if any of the pre or post conditions is
     * violated, an error is always emitted (resulting in a call to
     * the error callback).
     *
     * @{ */

    /** Find child by key; complexity is O(num_children).
     *
     * Returns the requested node, or an object in seed state if no
     * such child is found (see @ref NodeRef for an explanation of
     * what is seed state). When the object is in seed state, using it
     * to read from the tree is UB. The seed node can be subsequently
     * used to write to the tree provided that its create() method is
     * called prior to writing, which happens inside most mutating
     * methods in NodeRef. It is the caller's responsibility to verify
     * that the returned node is readable before subsequently using it
     * to read from the tree.
     *
     * @warning This method will call the error callback (regardless
     * of build type or of the value of RYML_USE_ASSERT) whenever any
     * of the following preconditions is violated: a) the object is
     * valid (points at a tree and a node), b) the calling object must
     * be readable (must not be in seed state), c) the calling object
     * must be pointing at a MAP node. The preconditions are similar
     * to the non-const operator[](csubstr), but instead of using
     * assertions, this function directly checks those conditions and
     * calls the error callback if any of the checks fail.
     *
     * @note since it is valid behavior for the returned node to be in
     * seed state, the error callback is not invoked when this
     * happens. */
    template<class U=Impl>
    C4_ALWAYS_INLINE auto at(csubstr key) -> _C4_IF_MUTABLE(Impl)
    {
        RYML_CHECK(tree_ != nullptr);
        _RYML_CB_CHECK(tree_->m_callbacks, (id_ >= 0 && id_ < tree_->capacity()));
        _RYML_CB_CHECK(tree_->m_callbacks, ((Impl const*)this)->readable());
        _RYML_CB_CHECK(tree_->m_callbacks, tree_->is_map(id_));
        id_type ch = tree__->find_child(id__, key);
        return ch != NONE ? Impl(tree__, ch) : Impl(tree__, id__, key);
    }

    /** Find child by position; complexity is O(pos).
     *
     * Returns the requested node, or an object in seed state if no
     * such child is found (see @ref NodeRef for an explanation of
     * what is seed state). When the object is in seed state, using it
     * to read from the tree is UB. The seed node can be used to write
     * to the tree provided that its create() method is called prior
     * to writing, which happens in most modifying methods in
     * NodeRef. It is the caller's responsibility to verify that the
     * returned node is readable before subsequently using it to read
     * from the tree.
     *
     * @warning This method will call the error callback (regardless
     * of build type or of the value of RYML_USE_ASSERT) whenever any
     * of the following preconditions is violated: a) the object is
     * valid (points at a tree and a node), b) the calling object must
     * be readable (must not be in seed state), c) the calling object
     * must be pointing at a MAP node. The preconditions are similar
     * to the non-const operator[](id_type), but instead of using
     * assertions, this function directly checks those conditions and
     * calls the error callback if any of the checks fail.
     *
     * @note since it is valid behavior for the returned node to be in
     * seed state, the error callback is not invoked when this
     * happens. */
    template<class U=Impl>
    C4_ALWAYS_INLINE auto at(id_type pos) -> _C4_IF_MUTABLE(Impl)
    {
        RYML_CHECK(tree_ != nullptr);
        const id_type cap = tree_->capacity();
        _RYML_CB_CHECK(tree_->m_callbacks, (id_ >= 0 && id_ < cap));
        _RYML_CB_CHECK(tree_->m_callbacks, (pos >= 0 && pos < cap));
        _RYML_CB_CHECK(tree_->m_callbacks, ((Impl const*)this)->readable());
        _RYML_CB_CHECK(tree_->m_callbacks, tree_->is_container(id_));
        id_type ch = tree__->child(id__, pos);
        return ch != NONE ? Impl(tree__, ch) : Impl(tree__, id__, pos);
    }

    /** Get a child by name, with error checking; complexity is
     * O(num_children).
     *
     * Behaves as operator[](csubstr) const, but always raises an
     * error (even when RYML_USE_ASSERT is set to false) when the
     * returned node does not exist, or when this node is not
     * readable, or when it is not a map. This behaviour is similar to
     * std::vector::at(), but the error consists in calling the error
     * callback instead of directly raising an exception. */
    ConstImpl at(csubstr key) const
    {
        RYML_CHECK(tree_ != nullptr);
        _RYML_CB_CHECK(tree_->m_callbacks, (id_ >= 0 && id_ < tree_->capacity()));
        _RYML_CB_CHECK(tree_->m_callbacks, ((Impl const*)this)->readable());
        _RYML_CB_CHECK(tree_->m_callbacks, tree_->is_map(id_));
        id_type ch = tree_->find_child(id_, key);
        _RYML_CB_CHECK(tree_->m_callbacks, ch != NONE);
        return {tree_, ch};
    }

    /** Get a child by position, with error checking; complexity is
     * O(pos).
     *
     * Behaves as operator[](id_type) const, but always raises an error
     * (even when RYML_USE_ASSERT is set to false) when the returned
     * node does not exist, or when this node is not readable, or when
     * it is not a container. This behaviour is similar to
     * std::vector::at(), but the error consists in calling the error
     * callback instead of directly raising an exception. */
    ConstImpl at(id_type pos) const
    {
        RYML_CHECK(tree_ != nullptr);
        const id_type cap = tree_->capacity();
        _RYML_CB_CHECK(tree_->m_callbacks, (id_ >= 0 && id_ < cap));
        _RYML_CB_CHECK(tree_->m_callbacks, (pos >= 0 && pos < cap));
        _RYML_CB_CHECK(tree_->m_callbacks, ((Impl const*)this)->readable());
        _RYML_CB_CHECK(tree_->m_callbacks, tree_->is_container(id_));
        const id_type ch = tree_->child(id_, pos);
        _RYML_CB_CHECK(tree_->m_callbacks, ch != NONE);
        return {tree_, ch};
    }

    /** @} */

public:

    /** @name deserialization */
    /** @{ */

    /** deserialize the node's val to the given variable, forwarding
     * to the user-overrideable @ref read() function. */
    template<class T>
    ConstImpl const& operator>> (T &v) const
    {
        _C4RR();
        if( ! read((ConstImpl const&)*this, &v))
            _RYML_CB_ERR(tree_->m_callbacks, "could not deserialize value");
        return *((ConstImpl const*)this);
    }

    /** deserialize the node's key to the given variable, forwarding
     * to the user-overrideable @ref read() function; use @ref key()
     * to disambiguate; for example: `node >> ryml::key(var)` */
    template<class T>
    ConstImpl const& operator>> (Key<T> v) const
    {
        _C4RR();
        if(key().empty() || ! from_chars(key(), &v.k))
            _RYML_CB_ERR(tree_->m_callbacks, "could not deserialize key");
        return *((ConstImpl const*)this);
    }

    /** deserialize the node's key as base64. lightweight wrapper over @ref deserialize_key() */
    ConstImpl const& operator>> (Key<fmt::base64_wrapper> w) const
    {
        deserialize_key(w.wrapper);
        return *((ConstImpl const*)this);
    }

    /** deserialize the node's val as base64. lightweight wrapper over @ref deserialize_val() */
    ConstImpl const& operator>> (fmt::base64_wrapper w) const
    {
        deserialize_val(w);
        return *((ConstImpl const*)this);
    }

    /** decode the base64-encoded key and assign the
     * decoded blob to the given buffer/
     * @return the size of base64-decoded blob */
    size_t deserialize_key(fmt::base64_wrapper v) const
    {
        _C4RR();
        return from_chars(key(), &v);
    }
    /** decode the base64-encoded key and assign the
     * decoded blob to the given buffer/
     * @return the size of base64-decoded blob */
    size_t deserialize_val(fmt::base64_wrapper v) const
    {
        _C4RR();
        return from_chars(val(), &v);
    };

    /** look for a child by name, if it exists assign to var. return
     * true if the child existed. */
    template<class T>
    bool get_if(csubstr name, T *var) const
    {
        _C4RR();
        ConstImpl ch = find_child(name);
        if(!ch.readable())
            return false;
        ch >> *var;
        return true;
    }

    /** look for a child by name, if it exists assign to var,
     * otherwise default to fallback. return true if the child
     * existed. */
    template<class T>
    bool get_if(csubstr name, T *var, T const& fallback) const
    {
        _C4RR();
        ConstImpl ch = find_child(name);
        if(ch.readable())
        {
            ch >> *var;
            return true;
        }
        else
        {
            *var = fallback;
            return false;
        }
    }

    /** @} */

public:

    #if defined(__clang__)
    #   pragma clang diagnostic push
    #   pragma clang diagnostic ignored "-Wnull-dereference"
    #elif defined(__GNUC__)
    #   pragma GCC diagnostic push
    #   if __GNUC__ >= 6
    #       pragma GCC diagnostic ignored "-Wnull-dereference"
    #   endif
    #endif

    /** @name iteration */
    /** @{ */

    using iterator = detail::child_iterator<Impl>;
    using const_iterator = detail::child_iterator<ConstImpl>;
    using children_view = detail::children_view_<Impl>;
    using const_children_view = detail::children_view_<ConstImpl>;

    /** get an iterator to the first child */
    template<class U=Impl>
    C4_ALWAYS_INLINE auto begin() RYML_NOEXCEPT -> _C4_IF_MUTABLE(iterator) { _C4RR(); return iterator(tree__, tree__->first_child(id__)); }
    /** get an iterator to the first child */
    C4_ALWAYS_INLINE const_iterator begin() const RYML_NOEXCEPT { _C4RR(); return const_iterator(tree_, tree_->first_child(id_)); }
    /** get an iterator to the first child */
    C4_ALWAYS_INLINE const_iterator cbegin() const RYML_NOEXCEPT { _C4RR(); return const_iterator(tree_, tree_->first_child(id_)); }

    /** get an iterator to after the last child */
    template<class U=Impl>
    C4_ALWAYS_INLINE auto end() RYML_NOEXCEPT -> _C4_IF_MUTABLE(iterator) { _C4RR(); return iterator(tree__, NONE); }
    /** get an iterator to after the last child */
    C4_ALWAYS_INLINE const_iterator end() const RYML_NOEXCEPT { _C4RR(); return const_iterator(tree_, NONE); }
    /** get an iterator to after the last child */
    C4_ALWAYS_INLINE const_iterator cend() const RYML_NOEXCEPT { _C4RR(); return const_iterator(tree_, tree_->first_child(id_)); }

    /** get an iterable view over children */
    template<class U=Impl>
    C4_ALWAYS_INLINE auto children() RYML_NOEXCEPT -> _C4_IF_MUTABLE(children_view) { _C4RR(); return children_view(begin(), end()); }
    /** get an iterable view over children */
    C4_ALWAYS_INLINE const_children_view children() const RYML_NOEXCEPT { _C4RR(); return const_children_view(begin(), end()); }
    /** get an iterable view over children */
    C4_ALWAYS_INLINE const_children_view cchildren() const RYML_NOEXCEPT { _C4RR(); return const_children_view(begin(), end()); }

    /** get an iterable view over all siblings (including the calling node) */
    template<class U=Impl>
    C4_ALWAYS_INLINE auto siblings() RYML_NOEXCEPT -> _C4_IF_MUTABLE(children_view)
    {
        _C4RR();
        NodeData const *nd = tree__->get(id__);
        return (nd->m_parent != NONE) ? // does it have a parent?
            children_view(iterator(tree__, tree_->get(nd->m_parent)->m_first_child), iterator(tree__, NONE))
            :
            children_view(end(), end());
    }
    /** get an iterable view over all siblings (including the calling node) */
    C4_ALWAYS_INLINE const_children_view siblings() const RYML_NOEXCEPT
    {
        _C4RR();
        NodeData const *nd = tree_->get(id_);
        return (nd->m_parent != NONE) ? // does it have a parent?
            const_children_view(const_iterator(tree_, tree_->get(nd->m_parent)->m_first_child), const_iterator(tree_, NONE))
            :
            const_children_view(end(), end());
    }
    /** get an iterable view over all siblings (including the calling node) */
    C4_ALWAYS_INLINE const_children_view csiblings() const RYML_NOEXCEPT { return siblings(); }

    /** visit every child node calling fn(node) */
    template<class Visitor>
    bool visit(Visitor fn, id_type indentation_level=0, bool skip_root=true) const RYML_NOEXCEPT
    {
        _C4RR();
        return detail::_visit(*(ConstImpl const*)this, fn, indentation_level, skip_root);
    }
    /** visit every child node calling fn(node) */
    template<class Visitor, class U=Impl>
    auto visit(Visitor fn, id_type indentation_level=0, bool skip_root=true) RYML_NOEXCEPT
        -> _C4_IF_MUTABLE(bool)
    {
        _C4RR();
        return detail::_visit(*(Impl*)this, fn, indentation_level, skip_root);
    }

    /** visit every child node calling fn(node, level) */
    template<class Visitor>
    bool visit_stacked(Visitor fn, id_type indentation_level=0, bool skip_root=true) const RYML_NOEXCEPT
    {
        _C4RR();
        return detail::_visit_stacked(*(ConstImpl const*)this, fn, indentation_level, skip_root);
    }
    /** visit every child node calling fn(node, level) */
    template<class Visitor, class U=Impl>
    auto visit_stacked(Visitor fn, id_type indentation_level=0, bool skip_root=true) RYML_NOEXCEPT
        -> _C4_IF_MUTABLE(bool)
    {
        _C4RR();
        return detail::_visit_stacked(*(Impl*)this, fn, indentation_level, skip_root);
    }

    /** @} */

    #if defined(__clang__)
    #   pragma clang diagnostic pop
    #elif defined(__GNUC__)
    #   pragma GCC diagnostic pop
    #endif

    #undef _C4_IF_MUTABLE
    #undef _C4RR
    #undef tree_
    #undef tree__
    #undef id_
    #undef id__

    C4_SUPPRESS_WARNING_GCC_CLANG_POP
};
} // detail


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** Holds a pointer to an existing tree, and a node id. It can be used
 * only to read from the tree.
 *
 * @warning The lifetime of the tree must be larger than that of this
 * object. It is up to the user to ensure that this happens. */
class RYML_EXPORT ConstNodeRef : public detail::RoNodeMethods<ConstNodeRef, ConstNodeRef>
{
public:

    using tree_type = Tree const;

public:

    Tree const* C4_RESTRICT m_tree;
    id_type m_id;

    friend NodeRef;
    friend struct detail::RoNodeMethods<ConstNodeRef, ConstNodeRef>;

public:

    /** @name construction */
    /** @{ */

    ConstNodeRef() noexcept : m_tree(nullptr), m_id(NONE) {}
    ConstNodeRef(Tree const &t) noexcept : m_tree(&t), m_id(t .root_id()) {}
    ConstNodeRef(Tree const *t) noexcept : m_tree(t ), m_id(t->root_id()) {}
    ConstNodeRef(Tree const *t, id_type id) noexcept : m_tree(t), m_id(id) {}
    ConstNodeRef(std::nullptr_t) noexcept : m_tree(nullptr), m_id(NONE) {}

    ConstNodeRef(ConstNodeRef const&) noexcept = default;
    ConstNodeRef(ConstNodeRef     &&) noexcept = default;

    ConstNodeRef(NodeRef const&) noexcept;
    ConstNodeRef(NodeRef     &&) noexcept;

    /** @} */

public:

    /** @name assignment */
    /** @{ */

    ConstNodeRef& operator= (std::nullptr_t) noexcept { m_tree = nullptr; m_id = NONE; return *this; }

    ConstNodeRef& operator= (ConstNodeRef const&) noexcept = default;
    ConstNodeRef& operator= (ConstNodeRef     &&) noexcept = default;

    ConstNodeRef& operator= (NodeRef const&) noexcept;
    ConstNodeRef& operator= (NodeRef     &&) noexcept;


    /** @} */

public:

    /** @name state queries
     *
     * see @ref NodeRef for an explanation on what these states mean */
    /** @{ */

    C4_ALWAYS_INLINE bool invalid() const noexcept { return (!m_tree) || (m_id == NONE); }
    /** because a ConstNodeRef cannot be used to write to the tree,
     * readable() has the same meaning as !invalid() */
    C4_ALWAYS_INLINE bool readable() const noexcept { return m_tree != nullptr && m_id != NONE; }
    /** because a ConstNodeRef cannot be used to write to the tree, it can never be a seed.
     * This method is provided for API equivalence between ConstNodeRef and NodeRef. */
    constexpr static C4_ALWAYS_INLINE bool is_seed() noexcept { return false; }

    RYML_DEPRECATED("use one of readable(), is_seed() or !invalid()") bool valid() const noexcept { return m_tree != nullptr && m_id != NONE; }

    /** @} */

public:

    /** @name member getters */
    /** @{ */

    C4_ALWAYS_INLINE Tree const* tree() const noexcept { return m_tree; }
    C4_ALWAYS_INLINE id_type id() const noexcept { return m_id; }

    /** @} */

public:

    /** @name comparisons */
    /** @{ */

    C4_ALWAYS_INLINE bool operator== (ConstNodeRef const& that) const RYML_NOEXCEPT { return that.m_tree == m_tree && m_id == that.m_id; }
    C4_ALWAYS_INLINE bool operator!= (ConstNodeRef const& that) const RYML_NOEXCEPT { return ! this->operator== (that); }

    /** @cond dev */
    RYML_DEPRECATED("use invalid()")  bool operator== (std::nullptr_t) const noexcept { return m_tree == nullptr || m_id == NONE; }
    RYML_DEPRECATED("use !invalid()") bool operator!= (std::nullptr_t) const noexcept { return !(m_tree == nullptr || m_id == NONE); }

    RYML_DEPRECATED("use (this->val() == s)") bool operator== (csubstr s) const RYML_NOEXCEPT { RYML_ASSERT(m_tree); _RYML_CB_ASSERT(m_tree->m_callbacks, m_id != NONE); return m_tree->val(m_id) == s; }
    RYML_DEPRECATED("use (this->val() != s)") bool operator!= (csubstr s) const RYML_NOEXCEPT { RYML_ASSERT(m_tree); _RYML_CB_ASSERT(m_tree->m_callbacks, m_id != NONE); return m_tree->val(m_id) != s; }
    /** @endcond */

    /** @} */

};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** A reference to a node in an existing yaml tree, offering a more
 * convenient API than the index-based API used in the tree.
 *
 * Unlike its imutable ConstNodeRef peer, a NodeRef can be used to
 * mutate the tree, both by writing to existing nodes and by creating
 * new nodes to subsequently write to. Semantically, a NodeRef
 * object can be in one of three states:
 *
 * ```text
 * invalid  := not pointing at anything
 * readable := points at an existing tree/node
 * seed     := points at an existing tree, and the node
 *             may come to exist, if we write to it.
 * ```
 *
 * So both `readable` and `seed` are states where the node is also `valid`.
 *
 * ```cpp
 * Tree t = parse_in_arena("{a: b}");
 * NodeRef invalid; // not pointing at anything.
 * NodeRef readable = t["a"]; // also valid, because "a" exists
 * NodeRef seed = t["none"]; // also valid, but is seed because "none" is not in the map
 * ```
 *
 * When the object is in seed state, using it to read from the tree is
 * UB. The seed node can be used to write to the tree, provided that
 * its create() method is called prior to writing, which happens in
 * most modifying methods in NodeRef.
 *
 * It is the owners's responsibility to verify that an existing
 * node is readable before subsequently using it to read from the
 * tree.
 *
 * @warning The lifetime of the tree must be larger than that of this
 * object. It is up to the user to ensure that this happens.
 */
class RYML_EXPORT NodeRef : public detail::RoNodeMethods<NodeRef, ConstNodeRef>
{
public:

    using tree_type = Tree;
    using base_type = detail::RoNodeMethods<NodeRef, ConstNodeRef>;

private:

    Tree *C4_RESTRICT m_tree;
    id_type m_id;

    /** This member is used to enable lazy operator[] writing. When a child
     * with a key or index is not found, m_id is set to the id of the parent
     * and the asked-for key or index are stored in this member until a write
     * does happen. Then it is given as key or index for creating the child.
     * When a key is used, the csubstr stores it (so the csubstr's string is
     * non-null and the csubstr's size is different from NONE). When an index is
     * used instead, the csubstr's string is set to null, and only the csubstr's
     * size is set to a value different from NONE. Otherwise, when operator[]
     * does find the child then this member is empty: the string is null and
     * the size is NONE. */
    csubstr m_seed;

    friend ConstNodeRef;
    friend struct detail::RoNodeMethods<NodeRef, ConstNodeRef>;

    // require valid: a helper macro, undefined at the end
    #define _C4RR()                                                         \
        RYML_ASSERT(m_tree != nullptr);                                     \
        _RYML_CB_ASSERT(m_tree->m_callbacks, m_id != NONE && !is_seed())
    // require id: a helper macro, undefined at the end
    #define _C4RID()                                                        \
        RYML_ASSERT(m_tree != nullptr);                                     \
        _RYML_CB_ASSERT(m_tree->m_callbacks, m_id != NONE)

public:

    /** @name construction */
    /** @{ */

    NodeRef() noexcept : m_tree(nullptr), m_id(NONE), m_seed() { _clear_seed(); }
    NodeRef(Tree &t) noexcept : m_tree(&t), m_id(t .root_id()), m_seed() { _clear_seed(); }
    NodeRef(Tree *t) noexcept : m_tree(t ), m_id(t->root_id()), m_seed() { _clear_seed(); }
    NodeRef(Tree *t, id_type id) noexcept : m_tree(t), m_id(id), m_seed() { _clear_seed(); }
    NodeRef(Tree *t, id_type id, id_type seed_pos) noexcept : m_tree(t), m_id(id), m_seed() { m_seed.str = nullptr; m_seed.len = (size_t)seed_pos; }
    NodeRef(Tree *t, id_type id, csubstr  seed_key) noexcept : m_tree(t), m_id(id), m_seed(seed_key) {}
    NodeRef(std::nullptr_t) noexcept : m_tree(nullptr), m_id(NONE), m_seed() {}

    inline void _clear_seed() noexcept { /*do the following manually or an assert is triggered: */ m_seed.str = nullptr; m_seed.len = npos; }

    /** @} */

public:

    /** @name assignment */
    /** @{ */

    NodeRef(NodeRef const&) noexcept = default;
    NodeRef(NodeRef     &&) noexcept = default;

    NodeRef& operator= (NodeRef const&) noexcept = default;
    NodeRef& operator= (NodeRef     &&) noexcept = default;

    /** @} */

public:

    /** @name state_queries
     * @{ */

    /** true if the object is not referring to any existing or seed node. @see the doc for @ref NodeRef */
    inline bool invalid() const noexcept { return m_tree == nullptr || m_id == NONE; }
    /** true if the object is not invalid and in seed state. @see the doc for @ref NodeRef */
    inline bool is_seed() const noexcept { return (m_tree != NULL && m_id != NONE) && (m_seed.str != nullptr || m_seed.len != (size_t)NONE); }
    /** true if the object is not invalid and not in seed state. @see the doc for @ref NodeRef */
    inline bool readable() const noexcept { return (m_tree != NULL && m_id != NONE) && (m_seed.str == nullptr && m_seed.len == (size_t)NONE); }

    RYML_DEPRECATED("use one of readable(), is_seed() or !invalid()") inline bool valid() const { return m_tree != nullptr && m_id != NONE; }

    /** @} */

public:

    /** @name comparisons */
    /** @{ */

    bool operator== (NodeRef const& that) const
    {
        if(m_tree == that.m_tree && m_id == that.m_id)
        {
            bool seed = is_seed();
            if(seed == that.is_seed())
            {
                if(seed)
                {
                    return (m_seed.len == that.m_seed.len)
                        && (m_seed.str == that.m_seed.str
                            || m_seed == that.m_seed); // do strcmp only in the last resort
                }
                return true;
            }
        }
        return false;
    }
    inline bool operator!= (NodeRef const& that) const { return ! this->operator==(that); }

    inline bool operator== (ConstNodeRef const& that) const { return m_tree == that.m_tree && m_id == that.m_id && !is_seed(); }
    inline bool operator!= (ConstNodeRef const& that) const { return ! this->operator==(that); }

    /** @cond dev */
    RYML_DEPRECATED("use !readable()") bool operator== (std::nullptr_t) const { return m_tree == nullptr || m_id == NONE || is_seed(); }
    RYML_DEPRECATED("use readable()")  bool operator!= (std::nullptr_t) const { return !(m_tree == nullptr || m_id == NONE || is_seed()); }

    RYML_DEPRECATED("use `this->val() == s`") bool operator== (csubstr s) const { _C4RR(); _RYML_CB_ASSERT(m_tree->m_callbacks, has_val()); return m_tree->val(m_id) == s; }
    RYML_DEPRECATED("use `this->val() != s`") bool operator!= (csubstr s) const { _C4RR(); _RYML_CB_ASSERT(m_tree->m_callbacks, has_val()); return m_tree->val(m_id) != s; }
    /** @endcond */

public:

    /** @name node_property_getters
     * @{ */

    C4_ALWAYS_INLINE Tree * tree() noexcept { return m_tree; }
    C4_ALWAYS_INLINE Tree const* tree() const noexcept { return m_tree; }

    C4_ALWAYS_INLINE id_type id() const noexcept { return m_id; }

    /** @} */

public:

    /** @name node_modifiers */
    /** @{ */

    void create() { _apply_seed(); }

    void change_type(NodeType t) { _C4RR(); m_tree->change_type(m_id, t); }

    void set_type(NodeType t) { _apply_seed(); m_tree->_set_flags(m_id, t); }
    void set_key(csubstr key) { _apply_seed(); m_tree->_set_key(m_id, key); }
    void set_val(csubstr val) { _apply_seed(); m_tree->_set_val(m_id, val); }
    void set_key_tag(csubstr key_tag) { _apply_seed(); m_tree->set_key_tag(m_id, key_tag); }
    void set_val_tag(csubstr val_tag) { _apply_seed(); m_tree->set_val_tag(m_id, val_tag); }
    void set_key_anchor(csubstr key_anchor) { _apply_seed(); m_tree->set_key_anchor(m_id, key_anchor); }
    void set_val_anchor(csubstr val_anchor) { _apply_seed(); m_tree->set_val_anchor(m_id, val_anchor); }
    void set_key_ref(csubstr key_ref) { _apply_seed(); m_tree->set_key_ref(m_id, key_ref); }
    void set_val_ref(csubstr val_ref) { _apply_seed(); m_tree->set_val_ref(m_id, val_ref); }

    void set_container_style(NodeType_e style) { _C4RR(); m_tree->set_container_style(m_id, style); }
    void set_key_style(NodeType_e style) { _C4RR(); m_tree->set_key_style(m_id, style); }
    void set_val_style(NodeType_e style) { _C4RR(); m_tree->set_val_style(m_id, style); }

public:

    inline void clear()
    {
        if(is_seed())
            return;
        m_tree->remove_children(m_id);
        m_tree->_clear(m_id);
    }

    inline void clear_key()
    {
        if(is_seed())
            return;
        m_tree->_clear_key(m_id);
    }

    inline void clear_val()
    {
        if(is_seed())
            return;
        m_tree->_clear_val(m_id);
    }

    inline void clear_children()
    {
        if(is_seed())
            return;
        m_tree->remove_children(m_id);
    }

    inline void operator= (NodeType_e t)
    {
        _apply_seed();
        m_tree->_add_flags(m_id, t);
    }

    inline void operator|= (NodeType_e t)
    {
        _apply_seed();
        m_tree->_add_flags(m_id, t);
    }

    inline void operator= (NodeInit const& v)
    {
        _apply_seed();
        _apply(v);
    }

    inline void operator= (NodeScalar const& v)
    {
        _apply_seed();
        _apply(v);
    }

    inline void operator= (std::nullptr_t)
    {
        _apply_seed();
        _apply(csubstr{});
    }

    inline void operator= (csubstr v)
    {
        _apply_seed();
        _apply(v);
    }

    template<size_t N>
    inline void operator= (const char (&v)[N])
    {
        _apply_seed();
        csubstr sv;
        sv.assign<N>(v);
        _apply(sv);
    }

    /** @} */

public:

    /** @name serialization */
    /** @{ */

    /** serialize a variable to the arena */
    template<class T>
    inline csubstr to_arena(T const& C4_RESTRICT s)
    {
        RYML_ASSERT(m_tree); // no need for valid or readable
        return m_tree->to_arena(s);
    }

    template<class T>
    size_t set_key_serialized(T const& C4_RESTRICT k)
    {
        _apply_seed();
        csubstr s = m_tree->to_arena(k);
        m_tree->_set_key(m_id, s);
        return s.len;
    }
    size_t set_key_serialized(std::nullptr_t)
    {
        _apply_seed();
        m_tree->_set_key(m_id, csubstr{});
        return 0;
    }

    template<class T>
    size_t set_val_serialized(T const& C4_RESTRICT v)
    {
        _apply_seed();
        csubstr s = m_tree->to_arena(v);
        m_tree->_set_val(m_id, s);
        return s.len;
    }
    size_t set_val_serialized(std::nullptr_t)
    {
        _apply_seed();
        m_tree->_set_val(m_id, csubstr{});
        return 0;
    }

    /** encode a blob as base64 into the tree's arena, then assign the
     * result to the node's key
     * @return the size of base64-encoded blob */
    size_t set_key_serialized(fmt::const_base64_wrapper w);
    /** encode a blob as base64 into the tree's arena, then assign the
     * result to the node's val
     * @return the size of base64-encoded blob */
    size_t set_val_serialized(fmt::const_base64_wrapper w);

    /** serialize a variable, then assign the result to the node's val */
    inline NodeRef& operator<< (csubstr s)
    {
        // this overload is needed to prevent ambiguity (there's also
        // operator<< for writing a substr to a stream)
        _apply_seed();
        write(this, s);
        _RYML_CB_ASSERT(m_tree->m_callbacks, val() == s);
        return *this;
    }

    template<class T>
    inline NodeRef& operator<< (T const& C4_RESTRICT v)
    {
        _apply_seed();
        write(this, v);
        return *this;
    }

    /** serialize a variable, then assign the result to the node's key */
    template<class T>
    inline NodeRef& operator<< (Key<const T> const& C4_RESTRICT v)
    {
        _apply_seed();
        set_key_serialized(v.k);
        return *this;
    }

    /** serialize a variable, then assign the result to the node's key */
    template<class T>
    inline NodeRef& operator<< (Key<T> const& C4_RESTRICT v)
    {
        _apply_seed();
        set_key_serialized(v.k);
        return *this;
    }

    NodeRef& operator<< (Key<fmt::const_base64_wrapper> w)
    {
        set_key_serialized(w.wrapper);
        return *this;
    }

    NodeRef& operator<< (fmt::const_base64_wrapper w)
    {
        set_val_serialized(w);
        return *this;
    }

    /** @} */

private:

    void _apply_seed()
    {
        _C4RID();
        if(m_seed.str) // we have a seed key: use it to create the new child
        {
            m_id = m_tree->append_child(m_id);
            m_tree->_set_key(m_id, m_seed);
            m_seed.str = nullptr;
            m_seed.len = (size_t)NONE;
        }
        else if(m_seed.len != (size_t)NONE) // we have a seed index: create a child at that position
        {
            _RYML_CB_ASSERT(m_tree->m_callbacks, (size_t)m_tree->num_children(m_id) == m_seed.len);
            m_id = m_tree->append_child(m_id);
            m_seed.str = nullptr;
            m_seed.len = (size_t)NONE;
        }
        else
        {
            _RYML_CB_ASSERT(m_tree->m_callbacks, readable());
        }
    }

    inline void _apply(csubstr v)
    {
        m_tree->_set_val(m_id, v);
    }

    inline void _apply(NodeScalar const& v)
    {
        m_tree->_set_val(m_id, v);
    }

    inline void _apply(NodeInit const& i)
    {
        m_tree->_set(m_id, i);
    }

public:

    /** @name modification of hierarchy */
    /** @{ */

    inline NodeRef insert_child(NodeRef after)
    {
        _C4RR();
        _RYML_CB_ASSERT(m_tree->m_callbacks, after.m_tree == m_tree);
        NodeRef r(m_tree, m_tree->insert_child(m_id, after.m_id));
        return r;
    }

    inline NodeRef insert_child(NodeInit const& i, NodeRef after)
    {
        _C4RR();
        _RYML_CB_ASSERT(m_tree->m_callbacks, after.m_tree == m_tree);
        NodeRef r(m_tree, m_tree->insert_child(m_id, after.m_id));
        r._apply(i);
        return r;
    }

    inline NodeRef prepend_child()
    {
        _C4RR();
        NodeRef r(m_tree, m_tree->insert_child(m_id, NONE));
        return r;
    }

    inline NodeRef prepend_child(NodeInit const& i)
    {
        _C4RR();
        NodeRef r(m_tree, m_tree->insert_child(m_id, NONE));
        r._apply(i);
        return r;
    }

    inline NodeRef append_child()
    {
        _C4RR();
        NodeRef r(m_tree, m_tree->append_child(m_id));
        return r;
    }

    inline NodeRef append_child(NodeInit const& i)
    {
        _C4RR();
        NodeRef r(m_tree, m_tree->append_child(m_id));
        r._apply(i);
        return r;
    }

    inline NodeRef insert_sibling(ConstNodeRef const& after)
    {
        _C4RR();
        _RYML_CB_ASSERT(m_tree->m_callbacks, after.m_tree == m_tree);
        NodeRef r(m_tree, m_tree->insert_sibling(m_id, after.m_id));
        return r;
    }

    inline NodeRef insert_sibling(NodeInit const& i, ConstNodeRef const& after)
    {
        _C4RR();
        _RYML_CB_ASSERT(m_tree->m_callbacks, after.m_tree == m_tree);
        NodeRef r(m_tree, m_tree->insert_sibling(m_id, after.m_id));
        r._apply(i);
        return r;
    }

    inline NodeRef prepend_sibling()
    {
        _C4RR();
        NodeRef r(m_tree, m_tree->prepend_sibling(m_id));
        return r;
    }

    inline NodeRef prepend_sibling(NodeInit const& i)
    {
        _C4RR();
        NodeRef r(m_tree, m_tree->prepend_sibling(m_id));
        r._apply(i);
        return r;
    }

    inline NodeRef append_sibling()
    {
        _C4RR();
        NodeRef r(m_tree, m_tree->append_sibling(m_id));
        return r;
    }

    inline NodeRef append_sibling(NodeInit const& i)
    {
        _C4RR();
        NodeRef r(m_tree, m_tree->append_sibling(m_id));
        r._apply(i);
        return r;
    }

public:

    inline void remove_child(NodeRef & child)
    {
        _C4RR();
        _RYML_CB_ASSERT(m_tree->m_callbacks, has_child(child));
        _RYML_CB_ASSERT(m_tree->m_callbacks, child.parent().id() == id());
        m_tree->remove(child.id());
        child.clear();
    }

    //! remove the nth child of this node
    inline void remove_child(id_type pos)
    {
        _C4RR();
        _RYML_CB_ASSERT(m_tree->m_callbacks, pos >= 0 && pos < num_children());
        id_type child = m_tree->child(m_id, pos);
        _RYML_CB_ASSERT(m_tree->m_callbacks, child != NONE);
        m_tree->remove(child);
    }

    //! remove a child by name
    inline void remove_child(csubstr key)
    {
        _C4RR();
        id_type child = m_tree->find_child(m_id, key);
        _RYML_CB_ASSERT(m_tree->m_callbacks, child != NONE);
        m_tree->remove(child);
    }

public:

    /** change the node's position within its parent, placing it after
     * @p after. To move to the first position in the parent, simply
     * pass an empty or default-constructed reference like this:
     * `n.move({})`. */
    inline void move(ConstNodeRef const& after)
    {
        _C4RR();
        m_tree->move(m_id, after.m_id);
    }

    /** move the node to a different @p parent (which may belong to a
     * different tree), placing it after @p after. When the
     * destination parent is in a new tree, then this node's tree
     * pointer is reset to the tree of the parent node. */
    inline void move(NodeRef const& parent, ConstNodeRef const& after)
    {
        _C4RR();
        if(parent.m_tree == m_tree)
        {
            m_tree->move(m_id, parent.m_id, after.m_id);
        }
        else
        {
            parent.m_tree->move(m_tree, m_id, parent.m_id, after.m_id);
            m_tree = parent.m_tree;
        }
    }

    /** duplicate the current node somewhere within its parent, and
     * place it after the node @p after. To place into the first
     * position of the parent, simply pass an empty or
     * default-constructed reference like this: `n.move({})`. */
    inline NodeRef duplicate(ConstNodeRef const& after) const
    {
        _C4RR();
        _RYML_CB_ASSERT(m_tree->m_callbacks, m_tree == after.m_tree || after.m_id == NONE);
        id_type dup = m_tree->duplicate(m_id, m_tree->parent(m_id), after.m_id);
        NodeRef r(m_tree, dup);
        return r;
    }

    /** duplicate the current node somewhere into a different @p parent
     * (possibly from a different tree), and place it after the node
     * @p after. To place into the first position of the parent,
     * simply pass an empty or default-constructed reference like
     * this: `n.move({})`. */
    inline NodeRef duplicate(NodeRef const& parent, ConstNodeRef const& after) const
    {
        _C4RR();
        _RYML_CB_ASSERT(m_tree->m_callbacks, parent.m_tree == after.m_tree || after.m_id == NONE);
        if(parent.m_tree == m_tree)
        {
            id_type dup = m_tree->duplicate(m_id, parent.m_id, after.m_id);
            NodeRef r(m_tree, dup);
            return r;
        }
        else
        {
            id_type dup = parent.m_tree->duplicate(m_tree, m_id, parent.m_id, after.m_id);
            NodeRef r(parent.m_tree, dup);
            return r;
        }
    }

    inline void duplicate_children(NodeRef const& parent, ConstNodeRef const& after) const
    {
        _C4RR();
        _RYML_CB_ASSERT(m_tree->m_callbacks, parent.m_tree == after.m_tree);
        if(parent.m_tree == m_tree)
        {
            m_tree->duplicate_children(m_id, parent.m_id, after.m_id);
        }
        else
        {
            parent.m_tree->duplicate_children(m_tree, m_id, parent.m_id, after.m_id);
        }
    }

    /** @} */

#undef _C4RR
#undef _C4RID
};


//-----------------------------------------------------------------------------

inline ConstNodeRef::ConstNodeRef(NodeRef const& that) noexcept
    : m_tree(that.m_tree)
    , m_id(!that.is_seed() ? that.id() : (id_type)NONE)
{
}

inline ConstNodeRef::ConstNodeRef(NodeRef && that) noexcept
    : m_tree(that.m_tree)
    , m_id(!that.is_seed() ? that.id() : (id_type)NONE)
{
}


inline ConstNodeRef& ConstNodeRef::operator= (NodeRef const& that) noexcept
{
    m_tree = (that.m_tree);
    m_id = (!that.is_seed() ? that.id() : (id_type)NONE);
    return *this;
}

inline ConstNodeRef& ConstNodeRef::operator= (NodeRef && that) noexcept
{
    m_tree = (that.m_tree);
    m_id = (!that.is_seed() ? that.id() : (id_type)NONE);
    return *this;
}


//-----------------------------------------------------------------------------

/** @addtogroup doc_serialization_helpers
 *
 * @{
 */

template<class T>
inline void write(NodeRef *n, T const& v)
{
    n->set_val_serialized(v);
}

namespace detail {
// SFINAE overloads for skipping leading + which cannot be read by the charconv functions
template<class T>
C4_ALWAYS_INLINE auto read_skip_plus(csubstr val, T *v)
    -> typename std::enable_if<std::is_arithmetic<T>::value, bool>::type
{
    if(val.begins_with('+'))
        val = val.sub(1);
    return from_chars(val, v);
}
template<class T>
C4_ALWAYS_INLINE auto read_skip_plus(csubstr val, T *v)
    -> typename std::enable_if< ! std::is_arithmetic<T>::value, bool>::type
{
    return from_chars(val, v);
}
} // namespace detail

/** convert the val of a scalar node to a particular type, by
 * forwarding its val to @ref from_chars<T>(). The full string is
 * used.
 * @return false if the conversion failed */
template<class T>
inline auto read(NodeRef const& n, T *v)
    -> typename std::enable_if< ! std::is_floating_point<T>::value, bool>::type
{
    csubstr val = n.val();
    if(val.empty())
        return false;
    return detail::read_skip_plus(val, v);
}
/** convert the val of a scalar node to a particular type, by
 * forwarding its val to @ref from_chars<T>(). The full string is
 * used.
 * @return false if the conversion failed */
template<class T>
inline auto read(ConstNodeRef const& n, T *v)
    -> typename std::enable_if< ! std::is_floating_point<T>::value, bool>::type
{
    csubstr val = n.val();
    if(val.empty())
        return false;
    return detail::read_skip_plus(val, v);
}

/** convert the val of a scalar node to a floating point type, by
 * forwarding its val to @ref from_chars_float<T>().
 *
 * @return false if the conversion failed
 *
 * @warning Unlike non-floating types, only the leading part of the
 * string that may constitute a number is processed. This happens
 * because the float parsing is delegated to fast_float, which is
 * implemented that way. Consequently, for example, all of `"34"`,
 * `"34 "` `"34hg"` `"34 gh"` will be read as 34. If you are not sure
 * about the contents of the data, you can use
 * csubstr::first_real_span() to check before calling `>>`, for
 * example like this:
 *
 * ```cpp
 * csubstr val = node.val();
 * if(val.first_real_span() == val)
 *     node >> v;
 * else
 *     ERROR("not a real")
 * ```
 */
template<class T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
inline read(NodeRef const& n, T *v)
{
    csubstr val = n.val();
    if(val.empty())
        return false;
    return from_chars_float(val, v);
}
/** convert the val of a scalar node to a floating point type, by
 * forwarding its val to @ref from_chars_float<T>().
 *
 * @return false if the conversion failed
 *
 * @warning Unlike non-floating types, only the leading part of the
 * string that may constitute a number is processed. This happens
 * because the float parsing is delegated to fast_float, which is
 * implemented that way. Consequently, for example, all of `"34"`,
 * `"34 "` `"34hg"` `"34 gh"` will be read as 34. If you are not sure
 * about the contents of the data, you can use
 * csubstr::first_real_span() to check before calling `>>`, for
 * example like this:
 *
 * ```cpp
 * csubstr val = node.val();
 * if(val.first_real_span() == val)
 *     node >> v;
 * else
 *     ERROR("not a real")
 * ```
 */
template<class T>
typename std::enable_if<std::is_floating_point<T>::value, bool>::type
inline read(ConstNodeRef const& n, T *v)
{
    csubstr val = n.val();
    if(val.empty())
        return false;
    return from_chars_float(val, v);
}

/** @} */

/** @} */


} // namespace yml
} // namespace c4



#ifdef __clang__
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#elif defined(_MSC_VER)
#   pragma warning(pop)
#endif

#endif /* _C4_YML_NODE_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/node.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/writer.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/writer.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_WRITER_HPP_
#define _C4_YML_WRITER_HPP_

#ifndef _C4_YML_COMMON_HPP_
#include "./common.hpp"
#endif

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/substr.hpp
//#include <c4/substr.hpp>
#if !defined(C4_SUBSTR_HPP_) && !defined(_C4_SUBSTR_HPP_)
#error "amalgamate: file c4/substr.hpp must have been included at this point"
#endif /* C4_SUBSTR_HPP_ */

#include <stdio.h>  // fwrite(), fputc()
#include <string.h> // memcpy()


namespace c4 {
namespace yml {

/** @addtogroup doc_emit
 * @{
 */

/** @defgroup doc_writers Writer objects to use with an Emitter
 * @see Emitter
 * @{
 */


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** A writer that outputs to a file. Defaults to stdout. */
struct WriterFile
{
    FILE * m_file;
    size_t m_pos;

    WriterFile(FILE *f = nullptr) : m_file(f ? f : stdout), m_pos(0) {}

    inline substr _get(bool /*error_on_excess*/)
    {
        substr sp;
        sp.str = nullptr;
        sp.len = m_pos;
        return sp;
    }

    template<size_t N>
    inline void _do_write(const char (&a)[N])
    {
        fwrite(a, sizeof(char), N - 1, m_file);
        m_pos += N - 1;
    }

    inline void _do_write(csubstr sp)
    {
        #if defined(__clang__)
        #   pragma clang diagnostic push
        #   pragma GCC diagnostic ignored "-Wsign-conversion"
        #elif defined(__GNUC__)
        #   pragma GCC diagnostic push
        #   pragma GCC diagnostic ignored "-Wsign-conversion"
        #endif
        if(sp.empty()) return;
        fwrite(sp.str, sizeof(csubstr::char_type), sp.len, m_file);
        m_pos += sp.len;
        #if defined(__clang__)
        #   pragma clang diagnostic pop
        #elif defined(__GNUC__)
        #   pragma GCC diagnostic pop
        #endif
    }

    inline void _do_write(const char c)
    {
        fputc(c, m_file);
        ++m_pos;
    }

    inline void _do_write(const char c, size_t num_times)
    {
        for(size_t i = 0; i < num_times; ++i)
            fputc(c, m_file);
        m_pos += num_times;
    }
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** A writer that outputs to an STL-like ostream. */
template<class OStream>
struct WriterOStream
{
    OStream& m_stream;
    size_t   m_pos;

    WriterOStream(OStream &s) : m_stream(s), m_pos(0) {}

    inline substr _get(bool /*error_on_excess*/)
    {
        substr sp;
        sp.str = nullptr;
        sp.len = m_pos;
        return sp;
    }

    template<size_t N>
    inline void _do_write(const char (&a)[N])
    {
        m_stream.write(a, N - 1);
        m_pos += N - 1;
    }

    inline void _do_write(csubstr sp)
    {
        #if defined(__clang__)
        #   pragma clang diagnostic push
        #   pragma GCC diagnostic ignored "-Wsign-conversion"
        #elif defined(__GNUC__)
        #   pragma GCC diagnostic push
        #   pragma GCC diagnostic ignored "-Wsign-conversion"
        #endif
        if(sp.empty()) return;
        m_stream.write(sp.str, sp.len);
        m_pos += sp.len;
        #if defined(__clang__)
        #   pragma clang diagnostic pop
        #elif defined(__GNUC__)
        #   pragma GCC diagnostic pop
        #endif
    }

    inline void _do_write(const char c)
    {
        m_stream.put(c);
        ++m_pos;
    }

    inline void _do_write(const char c, size_t num_times)
    {
        for(size_t i = 0; i < num_times; ++i)
            m_stream.put(c);
        m_pos += num_times;
    }
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/** a writer to a substr */
struct WriterBuf
{
    substr m_buf;
    size_t m_pos;

    WriterBuf(substr sp) : m_buf(sp), m_pos(0) {}

    inline substr _get(bool error_on_excess)
    {
        if(m_pos <= m_buf.len)
        {
            return m_buf.first(m_pos);
        }
        if(error_on_excess)
        {
            c4::yml::error("not enough space in the given buffer");
        }
        substr sp;
        sp.str = nullptr;
        sp.len = m_pos;
        return sp;
    }

    template<size_t N>
    inline void _do_write(const char (&a)[N])
    {
        RYML_ASSERT( ! m_buf.overlaps(a));
        if(m_pos + N-1 <= m_buf.len)
        {
            memcpy(&(m_buf[m_pos]), a, N-1);
        }
        m_pos += N-1;
    }

    inline void _do_write(csubstr sp)
    {
        if(sp.empty()) return;
        RYML_ASSERT( ! sp.overlaps(m_buf));
        if(m_pos + sp.len <= m_buf.len)
        {
            memcpy(&(m_buf[m_pos]), sp.str, sp.len);
        }
        m_pos += sp.len;
    }

    inline void _do_write(const char c)
    {
        if(m_pos + 1 <= m_buf.len)
            m_buf[m_pos] = c;
        ++m_pos;
    }

    inline void _do_write(const char c, size_t num_times)
    {
        if(m_pos + num_times <= m_buf.len)
            for(size_t i = 0; i < num_times; ++i)
                m_buf[m_pos + i] = c;
        m_pos += num_times;
    }
};

/** @ } */

/** @ } */


} // namespace yml
} // namespace c4

#endif /* _C4_YML_WRITER_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/writer.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/detail/parser_dbg.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/parser_dbg.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_DETAIL_PARSER_DBG_HPP_
#define _C4_YML_DETAIL_PARSER_DBG_HPP_

#ifndef _C4_YML_COMMON_HPP_
#include "../common.hpp"
#endif

#ifdef RYML_DBG
//included above:
//#include <cstdio>
#endif


//-----------------------------------------------------------------------------
// some debugging scaffolds

#if defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable: 4068/*unknown pragma*/)
#endif

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
//#pragma GCC diagnostic ignored "-Wpragma-system-header-outside-header"
#pragma GCC system_header

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Werror"
#pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"


#ifndef RYML_DBG
#   define _c4err(fmt, ...)   \
    this->_err("ERROR: " fmt, ## __VA_ARGS__)
#   define _c4dbgt(fmt, ...)
#   define _c4dbgpf(fmt, ...)
#   define _c4dbgpf_(fmt, ...)
#   define _c4dbgp(msg)
#   define _c4dbgp_(msg)
#   define _c4dbgq(msg)
#   define _c4presc(...)
#   define _c4prscalar(msg, scalar, keep_newlines)
#else
#   define _c4err(fmt, ...)   \
    do { RYML_DEBUG_BREAK(); this->_err("ERROR:\n" "{}:{}: " fmt, __FILE__, __LINE__, ## __VA_ARGS__); } while(0)
#   define _c4dbgt(fmt, ...)   do { if(_dbg_enabled()) {                \
                               this->_dbg ("{}:{}: "   fmt     , __FILE__, __LINE__, ## __VA_ARGS__); } } while(0)
#   define _c4dbgpf(fmt, ...)  _dbg_printf("{}:{}: "   fmt "\n", __FILE__, __LINE__, ## __VA_ARGS__)
#   define _c4dbgpf_(fmt, ...) _dbg_printf("{}:{}: "   fmt     , __FILE__, __LINE__, ## __VA_ARGS__)
#   define _c4dbgp(msg)        _dbg_printf("{}:{}: "   msg "\n", __FILE__, __LINE__                )
#   define _c4dbgp_(msg)       _dbg_printf("{}:{}: "   msg     , __FILE__, __LINE__                )
#   define _c4dbgq(msg)        _dbg_printf(msg "\n")
#   define _c4presc(...)       do { if(_dbg_enabled()) __c4presc(__VA_ARGS__); } while(0)
#   define _c4prscalar(msg, scalar, keep_newlines)                  \
    do {                                                            \
        _c4dbgpf_("{}: [{}]~~~", msg, scalar.len);                  \
        if(_dbg_enabled()) {                                        \
            __c4presc((scalar).str, (scalar).len, (keep_newlines)); \
        }                                                           \
        _c4dbgq("~~~");                                             \
    } while(0)
#endif // RYML_DBG


//-----------------------------------------------------------------------------

#ifdef RYML_DBG

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/dump.hpp
//#include <c4/dump.hpp>
#if !defined(C4_DUMP_HPP_) && !defined(_C4_DUMP_HPP_)
#error "amalgamate: file c4/dump.hpp must have been included at this point"
#endif /* C4_DUMP_HPP_ */

namespace c4 {
inline bool& _dbg_enabled() { static bool enabled = true; return enabled; }
inline void _dbg_set_enabled(bool yes) { _dbg_enabled() = yes; }
inline void _dbg_dumper(csubstr s)
{
    if(s.str)
        fwrite(s.str, 1, s.len, stdout);
}
inline substr _dbg_buf() noexcept
{
    static char writebuf[2048];
    return writebuf;
}
template<class ...Args>
C4_NO_INLINE void _dbg_printf(c4::csubstr fmt, Args const& ...args)
{
    if(_dbg_enabled())
    {
        substr buf = _dbg_buf();
        const size_t needed_size = c4::format_dump(&_dbg_dumper, buf, fmt, args...);
        C4_CHECK(needed_size <= buf.len);
    }
}
inline void __c4presc(const char *s, size_t len, bool keep_newlines=false)
{
    RYML_ASSERT(s || !len);
    size_t prev = 0;
    for(size_t i = 0; i < len; ++i)
    {
        switch(s[i])
        {
        case '\n'  : _dbg_printf("{}{}{}", csubstr(s+prev, i-prev), csubstr("\\n"), csubstr(keep_newlines ? "\n":"")); prev = i+1; break;
        case '\t'  : _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\t")); prev = i+1; break;
        case '\0'  : _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\0")); prev = i+1; break;
        case '\r'  : _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\r")); prev = i+1; break;
        case '\f'  : _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\f")); prev = i+1; break;
        case '\b'  : _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\b")); prev = i+1; break;
        case '\v'  : _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\v")); prev = i+1; break;
        case '\a'  : _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\a")); prev = i+1; break;
        case '\x1b': _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\x1b")); prev = i+1; break;
        case -0x3e/*0xc2u*/:
            if(i+1 < len)
            {
                if(s[i+1] == -0x60/*0xa0u*/)
                {
                    _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\_")); prev = i+1;
                }
                else if(s[i+1] == -0x7b/*0x85u*/)
                {
                    _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\N")); prev = i+1;
                }
            }
            break;
        case -0x1e/*0xe2u*/:
            if(i+2 < len && s[i+1] == -0x80/*0x80u*/)
            {
                if(s[i+2] == -0x58/*0xa8u*/)
                {
                    _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\L")); prev = i+1;
                }
                else if(s[i+2] == -0x57/*0xa9u*/)
                {
                    _dbg_printf("{}{}", csubstr(s+prev, i-prev), csubstr("\\P")); prev = i+1;
                }
            }
            break;
        }
    }
    if(len > prev)
        _dbg_printf("{}", csubstr(s+prev, len-prev));
}
inline void __c4presc(csubstr s, bool keep_newlines=false)
{
    __c4presc(s.str, s.len, keep_newlines);
}
} // namespace c4

#endif // RYML_DBG

#pragma clang diagnostic pop
#pragma GCC diagnostic pop

#if defined(_MSC_VER)
#   pragma warning(pop)
#endif

#endif /* _C4_YML_DETAIL_PARSER_DBG_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/detail/parser_dbg.hpp)

#define C4_YML_EMIT_DEF_HPP_



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/emit.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/emit.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_EMIT_HPP_
#define _C4_YML_EMIT_HPP_

/** @file emit.hpp Utilities to emit YAML and JSON. */

#ifndef _C4_YML_WRITER_HPP_
#include "./writer.hpp"
#endif

#ifndef _C4_YML_TREE_HPP_
#include "./tree.hpp"
#endif

#ifndef _C4_YML_NODE_HPP_
#include "./node.hpp"
#endif

#define RYML_DEPRECATE_EMIT                                             \
    RYML_DEPRECATED("use emit_yaml() instead. "                         \
                    "See https://github.com/biojppm/rapidyaml/issues/120")
#define RYML_DEPRECATE_EMITRS                                           \
    RYML_DEPRECATED("use emitrs_yaml() instead. "                       \
                    "See https://github.com/biojppm/rapidyaml/issues/120")

#ifdef emit
#error "emit is defined, likely from a Qt include. "                    \
    "This will cause a compilation error. "                             \
    "See https://github.com/biojppm/rapidyaml/issues/120"
#endif


C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

namespace c4 {
namespace yml {

/** @addtogroup doc_emit
 *
 * @{
 */

// fwd declarations
template<class Writer> class Emitter;
template<class OStream>
using EmitterOStream = Emitter<WriterOStream<OStream>>;
using EmitterFile = Emitter<WriterFile>;
using EmitterBuf  = Emitter<WriterBuf>;

namespace detail {
inline bool is_set_(ConstNodeRef n) { return n.tree() && (n.id() != NONE); }
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** Specifies the type of content to emit */
typedef enum {
    EMIT_YAML = 0, ///< emit YAML
    EMIT_JSON = 1  ///< emit JSON
} EmitType_e;


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** A lightweight object containing options to be used when emitting. */
struct EmitOptions
{
    typedef enum : uint32_t {
        DEFAULT_FLAGS = 0,
        JSON_ERR_ON_TAG = 1 << 0,
        JSON_ERR_ON_ANCHOR = 1 << 1,
        _JSON_ERR_MASK = JSON_ERR_ON_TAG|JSON_ERR_ON_ANCHOR,
    } EmitOptionFlags_e;

public:

    /** @name option flags
     *
     * @{ */
    C4_ALWAYS_INLINE EmitOptionFlags_e json_error_flags() const noexcept { return m_option_flags; }
    EmitOptions& json_error_flags(EmitOptionFlags_e d) noexcept { m_option_flags = (EmitOptionFlags_e)(d & _JSON_ERR_MASK); return *this; }
    /** @} */

public:

    /** @name max depth for the emitted tree
     *
     * This makes the emitter fail when emitting trees exceeding the
     * max_depth.
     *
     * @{ */
    C4_ALWAYS_INLINE id_type max_depth() const noexcept { return m_max_depth; }
    EmitOptions& max_depth(id_type d) noexcept { m_max_depth = d; return *this; }
    static constexpr const id_type max_depth_default = 64;
    /** @} */

public:

    bool operator== (const EmitOptions& that) const noexcept
    {
        return m_max_depth == that.m_max_depth &&
            m_option_flags == that.m_option_flags;
    }

private:

    /** @cond dev */
    id_type m_max_depth{max_depth_default};
    EmitOptionFlags_e m_option_flags{DEFAULT_FLAGS};
    /** @endcond */
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** A stateful emitter, for use with a writer such as @ref WriterBuf,
 * @ref WriterFile, or @ref WriterOStream */
template<class Writer>
class Emitter : public Writer
{
public:

    /** Construct the emitter and its internal Writer state, using default emit options.
     * @param args arguments to be forwarded to the constructor of the writer.
     * */
    template<class ...Args>
    Emitter(Args &&...args) : Writer(std::forward<Args>(args)...), m_tree(), m_opts(), m_flow(false) {}

    /** Construct the emitter and its internal Writer state.
     *
     * @param opts EmitOptions
     * @param args arguments to be forwarded to the constructor of the writer.
     * */
    template<class ...Args>
    Emitter(EmitOptions const& opts, Args &&...args) : Writer(std::forward<Args>(args)...), m_tree(), m_opts(opts), m_flow(false) {}

    /** emit!
     *
     * When writing to a buffer, returns a substr of the emitted YAML.
     * If the given buffer has insufficient space, the returned substr
     * will be null and its size will be the needed space. Whatever
     * the size of the buffer, it is guaranteed that no writes are
     * done past its end.
     *
     * When writing to a file, the returned substr will be null, but its
     * length will be set to the number of bytes written.
     *
     * @param type specify what to emit
     * @param t the tree to emit
     * @param id the id of the node to emit
     * @param error_on_excess when true, an error is raised when the
     *        output buffer is too small for the emitted YAML/JSON
     * */
    substr emit_as(EmitType_e type, Tree const& t, id_type id, bool error_on_excess);
    /** emit starting at the root node */
    substr emit_as(EmitType_e type, Tree const& t, bool error_on_excess=true)
    {
        if(t.empty())
            return {};
        return this->emit_as(type, t, t.root_id(), error_on_excess);
    }
    /** emit starting at the given node */
    substr emit_as(EmitType_e type, ConstNodeRef const& n, bool error_on_excess=true)
    {
        if(!detail::is_set_(n))
            return {};
        _RYML_CB_CHECK(n.tree()->callbacks(), n.readable());
        return this->emit_as(type, *n.tree(), n.id(), error_on_excess);
    }

public:

    /** get the emit options for this object */
    EmitOptions const& options() const noexcept { return m_opts; }

    /** set the max depth for emitted trees (to prevent a stack overflow) */
    void max_depth(id_type max_depth) noexcept { m_opts.max_depth(max_depth); }
    /** get the max depth for emitted trees (to prevent a stack overflow) */
    id_type max_depth() const noexcept { return m_opts.max_depth(); }

private:

    Tree const* C4_RESTRICT m_tree;
    EmitOptions m_opts;
    bool m_flow;

private:

    void _emit_yaml(id_type id);
    void _do_visit_flow_sl(id_type id, id_type depth, id_type ilevel=0);
    void _do_visit_flow_ml(id_type id, id_type depth, id_type ilevel=0, id_type do_indent=1);
    void _do_visit_block(id_type id, id_type depth, id_type ilevel=0, id_type do_indent=1);
    void _do_visit_block_container(id_type id, id_type depth, id_type next_level, bool do_indent);
    void _do_visit_json(id_type id, id_type depth);

private:

    void _write(NodeScalar const& C4_RESTRICT sc, NodeType flags, id_type level);
    void _write_json(NodeScalar const& C4_RESTRICT sc, NodeType flags);

    void _write_doc(id_type id);
    void _write_scalar_json_dquo(csubstr s);
    void _write_scalar_literal(csubstr s, id_type level, bool as_key);
    void _write_scalar_folded(csubstr s, id_type level, bool as_key);
    void _write_scalar_squo(csubstr s, id_type level);
    void _write_scalar_dquo(csubstr s, id_type level);
    void _write_scalar_plain(csubstr s, id_type level);

    size_t _write_escaped_newlines(csubstr s, size_t i);
    size_t _write_indented_block(csubstr s, size_t i, id_type level);

    void _write_tag(csubstr tag)
    {
        if(!tag.begins_with('!'))
            this->Writer::_do_write('!');
        this->Writer::_do_write(tag);
    }

    enum : type_bits {
        _keysc =  (KEY|KEYREF|KEYANCH|KEYQUO|KEY_STYLE) | ~(VAL|VALREF|VALANCH|VALQUO|VAL_STYLE) | CONTAINER_STYLE,
        _valsc = ~(KEY|KEYREF|KEYANCH|KEYQUO|KEY_STYLE) |  (VAL|VALREF|VALANCH|VALQUO|VAL_STYLE) | CONTAINER_STYLE,
        _keysc_json =  (KEY)  | ~(VAL),
        _valsc_json = ~(KEY)  |  (VAL),
    };

    C4_ALWAYS_INLINE void _writek(id_type id, id_type level) { _write(m_tree->keysc(id), (m_tree->_p(id)->m_type.type & ~_valsc), level); }
    C4_ALWAYS_INLINE void _writev(id_type id, id_type level) { _write(m_tree->valsc(id), (m_tree->_p(id)->m_type.type & ~_keysc), level); }

    C4_ALWAYS_INLINE void _writek_json(id_type id) { _write_json(m_tree->keysc(id), m_tree->_p(id)->m_type.type & ~(VAL)); }
    C4_ALWAYS_INLINE void _writev_json(id_type id) { _write_json(m_tree->valsc(id), m_tree->_p(id)->m_type.type & ~(KEY)); }

    void _indent(id_type level, bool enabled)
    {
        if(enabled)
            this->Writer::_do_write(' ', 2u * (size_t)level);
    }
    void _indent(id_type level)
    {
        if(!m_flow)
            this->Writer::_do_write(' ', 2u * (size_t)level);
    }
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** @defgroup doc_emit_to_file Emit to file
 *
 * @{
 */


// emit from tree and node id -----------------------

/** (1) emit YAML to the given file, starting at the given node. A null
 * file defaults to stdout. Return the number of bytes written. */
inline size_t emit_yaml(Tree const& t, id_type id, EmitOptions const& opts, FILE *f)
{
    EmitterFile em(opts, f);
    return em.emit_as(EMIT_YAML, t, id, /*error_on_excess*/true).len;
}
/** (2) like (1), but use default emit options */
inline size_t emit_yaml(Tree const& t, id_type id, FILE *f)
{
    EmitterFile em(f);
    return em.emit_as(EMIT_YAML, t, id, /*error_on_excess*/true).len;
}
/** (1) emit JSON to the given file, starting at the given node. A null
 * file defaults to stdout.  Return the number of bytes written. */
inline size_t emit_json(Tree const& t, id_type id, EmitOptions const& opts, FILE *f)
{
    EmitterFile em(opts, f);
    return em.emit_as(EMIT_JSON, t, id, /*error_on_excess*/true).len;
}
/** (2) like (1), but use default emit options */
inline size_t emit_json(Tree const& t, id_type id, FILE *f)
{
    EmitterFile em(f);
    return em.emit_as(EMIT_JSON, t, id, /*error_on_excess*/true).len;
}


// emit from root -------------------------

/** (1) emit YAML to the given file, starting at the root node. A null file defaults to stdout.
 * Return the number of bytes written. */
inline size_t emit_yaml(Tree const& t, EmitOptions const& opts, FILE *f=nullptr)
{
    EmitterFile em(opts, f);
    return em.emit_as(EMIT_YAML, t, /*error_on_excess*/true).len;
}
/** (2) like (1), but use default emit options */
inline size_t emit_yaml(Tree const& t, FILE *f=nullptr)
{
    EmitterFile em(f);
    return em.emit_as(EMIT_YAML, t, /*error_on_excess*/true).len;
}
/** (1) emit JSON to the given file. A null file defaults to stdout.
 * Return the number of bytes written. */
inline size_t emit_json(Tree const& t, EmitOptions const& opts, FILE *f=nullptr)
{
    EmitterFile em(opts, f);
    return em.emit_as(EMIT_JSON, t, /*error_on_excess*/true).len;
}
/** (2) like (1), but use default emit options */
inline size_t emit_json(Tree const& t, FILE *f=nullptr)
{
    EmitterFile em(f);
    return em.emit_as(EMIT_JSON, t, /*error_on_excess*/true).len;
}


// emit from ConstNodeRef ------------------------

/** (1) emit YAML to the given file. A null file defaults to stdout.
 * Return the number of bytes written. */
inline size_t emit_yaml(ConstNodeRef const& r, EmitOptions const& opts, FILE *f=nullptr)
{
    if(!detail::is_set_(r))
        return {};
    EmitterFile em(opts, f);
    return em.emit_as(EMIT_YAML, r, /*error_on_excess*/true).len;
}
/** (2) like (1), but use default emit options */
inline size_t emit_yaml(ConstNodeRef const& r, FILE *f=nullptr)
{
    if(!detail::is_set_(r))
        return {};
    EmitterFile em(f);
    return em.emit_as(EMIT_YAML, r, /*error_on_excess*/true).len;
}
/** (1) emit JSON to the given file. A null file defaults to stdout.
 * Return the number of bytes written. */
inline size_t emit_json(ConstNodeRef const& r, EmitOptions const& opts, FILE *f=nullptr)
{
    if(!detail::is_set_(r))
        return {};
    EmitterFile em(opts, f);
    return em.emit_as(EMIT_JSON, r, /*error_on_excess*/true).len;
}
/** (2) like (1), but use default emit options */
inline size_t emit_json(ConstNodeRef const& r, FILE *f=nullptr)
{
    if(!detail::is_set_(r))
        return {};
    EmitterFile em(f);
    return em.emit_as(EMIT_JSON, r, /*error_on_excess*/true).len;
}

/** @} */


//-----------------------------------------------------------------------------

/** @defgroup doc_emit_to_ostream Emit to an STL-like ostream
 *
 * @{
 */

/** emit YAML to an STL-like ostream */
template<class OStream>
inline OStream& operator<< (OStream& s, Tree const& t)
{
    EmitterOStream<OStream> em(s);
    em.emit_as(EMIT_YAML, t);
    return s;
}

/** emit YAML to an STL-like ostream
 * @overload */
template<class OStream>
inline OStream& operator<< (OStream& s, ConstNodeRef const& n)
{
    if(!detail::is_set_(n))
        return s;
    EmitterOStream<OStream> em(s);
    em.emit_as(EMIT_YAML, n);
    return s;
}

/** mark a tree or node to be emitted as yaml when using @ref
 * operator<<, with options. For example:
 *
 * ```cpp
 * Tree t = parse_in_arena("{foo: bar}");
 * std::cout << t; // emits YAML
 * std::cout << as_yaml(t); // emits YAML, same as above
 * std::cout << as_yaml(t, EmitOptions().max_depth(10)); // emits JSON with a max tree depth
 * ```
 *
 * @see @ref operator<< */
struct as_json
{
    Tree const* tree;
    size_t node;
    EmitOptions options;
    as_json(Tree const& t, EmitOptions const& opts={}) : tree(&t), node(t.empty() ? NONE : t.root_id()), options(opts)  {}
    as_json(Tree const& t, size_t id, EmitOptions const& opts={}) : tree(&t), node(id), options(opts)  {}
    as_json(ConstNodeRef const& n, EmitOptions const& opts={}) : tree(n.tree()), node(n.id()), options(opts) {}
};

/** mark a tree or node to be emitted as yaml when using @ref
 * operator<< . For example:
 *
 * ```cpp
 * Tree t = parse_in_arena("{foo: bar}");
 * std::cout << t; // emits YAML
 * std::cout << as_json(t); // emits JSON
 * std::cout << as_json(t, EmitOptions().max_depth(10)); // emits JSON with a max tree depth
 * ```
 *
 * @see @ref operator<< */
struct as_yaml
{
    Tree const* tree;
    size_t node;
    EmitOptions options;
    as_yaml(Tree const& t, EmitOptions const& opts={}) : tree(&t), node(t.empty() ? NONE : t.root_id()), options(opts)  {}
    as_yaml(Tree const& t, size_t id, EmitOptions const& opts={}) : tree(&t), node(id), options(opts)  {}
    as_yaml(ConstNodeRef const& n, EmitOptions const& opts={}) : tree(n.tree()), node(n.id()), options(opts) {}
};

/** emit json to an STL-like stream */
template<class OStream>
inline OStream& operator<< (OStream& s, as_json const& j)
{
    if(!j.tree || j.node == NONE)
        return s;
    EmitterOStream<OStream> em(j.options, s);
    em.emit_as(EMIT_JSON, *j.tree, j.node, true);
    return s;
}

/** emit yaml to an STL-like stream */
template<class OStream>
inline OStream& operator<< (OStream& s, as_yaml const& y)
{
    if(!y.tree || y.node == NONE)
        return s;
    EmitterOStream<OStream> em(y.options, s);
    em.emit_as(EMIT_YAML, *y.tree, y.node, true);
    return s;
}

/** @} */


//-----------------------------------------------------------------------------

/** @defgroup doc_emit_to_buffer Emit to memory buffer
 *
 * @{
 */

// emit from tree and node id -----------------------

/** (1) emit YAML to the given buffer. Return a substr trimmed to the emitted YAML.
 * @param t the tree to emit.
 * @param id the node where to start emitting.
 * @param opts emit options.
 * @param buf the output buffer.
 * @param opts emit options.
 * @param error_on_excess Raise an error if the space in the buffer is insufficient.
 * @return a substr trimmed to the result in the output buffer. If the buffer is
 * insufficient (when error_on_excess is false), the string pointer of the
 * result will be set to null, and the length will report the required buffer size. */
inline substr emit_yaml(Tree const& t, id_type id, EmitOptions const& opts, substr buf, bool error_on_excess=true)
{
    EmitterBuf em(opts, buf);
    return em.emit_as(EMIT_YAML, t, id, error_on_excess);
}
/** (2) like (1), but use default emit options */
inline substr emit_yaml(Tree const& t, id_type id, substr buf, bool error_on_excess=true)
{
    EmitterBuf em(buf);
    return em.emit_as(EMIT_YAML, t, id, error_on_excess);
}
/** (1) emit JSON to the given buffer. Return a substr trimmed to the emitted JSON.
 * @param t the tree to emit.
 * @param id the node where to start emitting.
 * @param opts emit options.
 * @param buf the output buffer.
 * @param opts emit options.
 * @param error_on_excess Raise an error if the space in the buffer is insufficient.
 * @return a substr trimmed to the result in the output buffer. If the buffer is
 * insufficient (when error_on_excess is false), the string pointer of the
 * result will be set to null, and the length will report the required buffer size. */
inline substr emit_json(Tree const& t, id_type id, EmitOptions const& opts, substr buf, bool error_on_excess=true)
{
    EmitterBuf em(opts, buf);
    return em.emit_as(EMIT_JSON, t, id, error_on_excess);
}
/** (2) like (1), but use default emit options */
inline substr emit_json(Tree const& t, id_type id, substr buf, bool error_on_excess=true)
{
    EmitterBuf em(buf);
    return em.emit_as(EMIT_JSON, t, id, error_on_excess);
}


// emit from root -------------------------

/** (1) emit YAML to the given buffer. Return a substr trimmed to the emitted YAML.
 * @param t the tree; will be emitted from the root node.
 * @param buf the output buffer.
 * @param error_on_excess Raise an error if the space in the buffer is insufficient.
 * @return a substr trimmed to the result in the output buffer. If the buffer is
 * insufficient (when error_on_excess is false), the string pointer of the
 * result will be set to null, and the length will report the required buffer size. */
inline substr emit_yaml(Tree const& t, EmitOptions const& opts, substr buf, bool error_on_excess=true)
{
    EmitterBuf em(opts, buf);
    return em.emit_as(EMIT_YAML, t, error_on_excess);
}
/** (2) like (1), but use default emit options */
inline substr emit_yaml(Tree const& t, substr buf, bool error_on_excess=true)
{
    EmitterBuf em(buf);
    return em.emit_as(EMIT_YAML, t, error_on_excess);
}
/** (1) emit JSON to the given buffer. Return a substr trimmed to the emitted JSON.
 * @param t the tree; will be emitted from the root node.
 * @param buf the output buffer.
 * @param error_on_excess Raise an error if the space in the buffer is insufficient.
 * @return a substr trimmed to the result in the output buffer. If the buffer is
 * insufficient (when error_on_excess is false), the string pointer of the
 * result will be set to null, and the length will report the required buffer size. */
inline substr emit_json(Tree const& t, EmitOptions const& opts, substr buf, bool error_on_excess=true)
{
    EmitterBuf em(opts, buf);
    return em.emit_as(EMIT_JSON, t, error_on_excess);
}
/** (2) like (1), but use default emit options */
inline substr emit_json(Tree const& t, substr buf, bool error_on_excess=true)
{
    EmitterBuf em(buf);
    return em.emit_as(EMIT_JSON, t, error_on_excess);
}


// emit from ConstNodeRef ------------------------

/** (1) emit YAML to the given buffer. Return a substr trimmed to the emitted YAML.
 * @param r the starting node.
 * @param buf the output buffer.
 * @param opts emit options.
 * @param error_on_excess Raise an error if the space in the buffer is insufficient.
 * @return a substr trimmed to the result in the output buffer. If the buffer is
 * insufficient (when error_on_excess is false), the string pointer of the
 * result will be set to null, and the length will report the required buffer size. */
inline substr emit_yaml(ConstNodeRef const& r, EmitOptions const& opts, substr buf, bool error_on_excess=true)
{
    if(!detail::is_set_(r))
        return {};
    EmitterBuf em(opts, buf);
    return em.emit_as(EMIT_YAML, r, error_on_excess);
}
/** (2) like (1), but use default emit options */
inline substr emit_yaml(ConstNodeRef const& r, substr buf, bool error_on_excess=true)
{
    if(!detail::is_set_(r))
        return {};
    EmitterBuf em(buf);
    return em.emit_as(EMIT_YAML, r, error_on_excess);
}
/** (1) emit JSON to the given buffer. Return a substr trimmed to the emitted JSON.
 * @param r the starting node.
 * @param buf the output buffer.
 * @param opts emit options.
 * @param error_on_excess Raise an error if the space in the buffer is insufficient.
 * @return a substr trimmed to the result in the output buffer. If the buffer is
 * insufficient (when error_on_excess is false), the string pointer of the
 * result will be set to null, and the length will report the required buffer size. */
inline substr emit_json(ConstNodeRef const& r, EmitOptions const& opts, substr buf, bool error_on_excess=true)
{
    if(!detail::is_set_(r))
        return {};
    EmitterBuf em(opts, buf);
    return em.emit_as(EMIT_JSON, r, error_on_excess);
}
/** (2) like (1), but use default emit options */
inline substr emit_json(ConstNodeRef const& r, substr buf, bool error_on_excess=true)
{
    if(!detail::is_set_(r))
        return {};
    EmitterBuf em(buf);
    return em.emit_as(EMIT_JSON, r, error_on_excess);
}


//-----------------------------------------------------------------------------

/** @defgroup doc_emit_to_container Emit to resizeable container
 *
 * @{
 */

// emit from tree and node id ---------------------------

/** (1) emit+resize: emit YAML to the given `std::string`/`std::vector`-like
 * container, resizing it as needed to fit the emitted YAML. If @p append is
 * set to true, the emitted YAML is appended at the end of the container.
 *
 * @return a substr trimmed to the emitted YAML (excluding the initial contents, when appending) */
template<class CharOwningContainer>
substr emitrs_yaml(Tree const& t, id_type id, EmitOptions const& opts, CharOwningContainer * cont, bool append=false)
{
    size_t startpos = append ? cont->size() : 0u;
    cont->resize(cont->capacity()); // otherwise the first emit would be certain to fail
    substr buf = to_substr(*cont).sub(startpos);
    substr ret = emit_yaml(t, id, opts, buf, /*error_on_excess*/false);
    if(ret.str == nullptr && ret.len > 0)
    {
        cont->resize(startpos + ret.len);
        buf = to_substr(*cont).sub(startpos);
        ret = emit_yaml(t, id, opts, buf, /*error_on_excess*/true);
    }
    else
    {
        cont->resize(startpos + ret.len);
    }
    return ret;
}
/** (2) like (1), but use default emit options */
template<class CharOwningContainer>
substr emitrs_yaml(Tree const& t, id_type id, CharOwningContainer * cont, bool append=false)
{
    return emitrs_yaml(t, id, EmitOptions{}, cont, append);
}
/** (1) emit+resize: emit JSON to the given `std::string`/`std::vector`-like
 * container, resizing it as needed to fit the emitted JSON. If @p append is
 * set to true, the emitted YAML is appended at the end of the container.
 *
 * @return a substr trimmed to the emitted JSON (excluding the initial contents, when appending) */
template<class CharOwningContainer>
substr emitrs_json(Tree const& t, id_type id, EmitOptions const& opts, CharOwningContainer * cont, bool append=false)
{
    const size_t startpos = append ? cont->size() : 0u;
    cont->resize(cont->capacity()); // otherwise the first emit would be certain to fail
    substr buf = to_substr(*cont).sub(startpos);
    EmitterBuf em(opts, buf);
    substr ret = emit_json(t, id, opts, buf, /*error_on_excess*/false);
    if(ret.str == nullptr && ret.len > 0)
    {
        cont->resize(startpos + ret.len);
        buf = to_substr(*cont).sub(startpos);
        ret = emit_json(t, id, opts, buf, /*error_on_excess*/true);
    }
    else
    {
        cont->resize(startpos + ret.len);
    }
    return ret;
}
/** (2) like (1), but use default emit options */
template<class CharOwningContainer>
substr emitrs_json(Tree const& t, id_type id, CharOwningContainer * cont, bool append=false)
{
    return emitrs_json(t, id, EmitOptions{}, cont, append);
}


/** (3) emit+resize: YAML to a newly-created `std::string`/`std::vector`-like container. */
template<class CharOwningContainer>
CharOwningContainer emitrs_yaml(Tree const& t, id_type id, EmitOptions const& opts={})
{
    CharOwningContainer c;
    emitrs_yaml(t, id, opts, &c);
    return c;
}
/** (3) emit+resize: JSON to a newly-created `std::string`/`std::vector`-like container. */
template<class CharOwningContainer>
CharOwningContainer emitrs_json(Tree const& t, id_type id, EmitOptions const& opts={})
{
    CharOwningContainer c;
    emitrs_json(t, id, opts, &c);
    return c;
}


// emit from root -------------------------

/** (1) emit+resize: YAML to the given `std::string`/`std::vector`-like
 * container, resizing it as needed to fit the emitted YAML.
 * @return a substr trimmed to the new emitted contents. */
template<class CharOwningContainer>
substr emitrs_yaml(Tree const& t, EmitOptions const& opts, CharOwningContainer * cont, bool append=false)
{
    if(t.empty())
        return {};
    return emitrs_yaml(t, t.root_id(), opts, cont, append);
}
/** (2) like (1), but use default emit options */
template<class CharOwningContainer>
substr emitrs_yaml(Tree const& t, CharOwningContainer * cont, bool append=false)
{
    if(t.empty())
        return {};
    return emitrs_yaml(t, t.root_id(), EmitOptions{}, cont, append);
}
/** (1) emit+resize: JSON to the given `std::string`/`std::vector`-like
 * container, resizing it as needed to fit the emitted JSON.
 * @return a substr trimmed to the new emitted contents. */
template<class CharOwningContainer>
substr emitrs_json(Tree const& t, EmitOptions const& opts, CharOwningContainer * cont, bool append=false)
{
    if(t.empty())
        return {};
    return emitrs_json(t, t.root_id(), opts, cont, append);
}
/** (2) like (1), but use default emit options */
template<class CharOwningContainer>
substr emitrs_json(Tree const& t, CharOwningContainer * cont, bool append=false)
{
    if(t.empty())
        return {};
    return emitrs_json(t, t.root_id(), EmitOptions{}, cont, append);
}


/** (3) emit+resize: YAML to a newly-created `std::string`/`std::vector`-like container. */
template<class CharOwningContainer>
CharOwningContainer emitrs_yaml(Tree const& t, EmitOptions const& opts={})
{
    CharOwningContainer c;
    if(t.empty())
        return c;
    emitrs_yaml(t, t.root_id(), opts, &c);
    return c;
}
/** (3) emit+resize: JSON to a newly-created `std::string`/`std::vector`-like container. */
template<class CharOwningContainer>
CharOwningContainer emitrs_json(Tree const& t, EmitOptions const& opts={})
{
    CharOwningContainer c;
    if(t.empty())
        return c;
    emitrs_json(t, t.root_id(), opts, &c);
    return c;
}


// emit from ConstNodeRef ------------------------


/** (1) emit+resize: YAML to the given `std::string`/`std::vector`-like container,
 * resizing it as needed to fit the emitted YAML.
 * @return a substr trimmed to the new emitted contents */
template<class CharOwningContainer>
substr emitrs_yaml(ConstNodeRef const& n, EmitOptions const& opts, CharOwningContainer * cont, bool append=false)
{
    if(!detail::is_set_(n))
        return {};
    _RYML_CB_CHECK(n.tree()->callbacks(), n.readable());
    return emitrs_yaml(*n.tree(), n.id(), opts, cont, append);
}
/** (2) like (1), but use default emit options */
template<class CharOwningContainer>
substr emitrs_yaml(ConstNodeRef const& n, CharOwningContainer * cont, bool append=false)
{
    if(!detail::is_set_(n))
        return {};
    _RYML_CB_CHECK(n.tree()->callbacks(), n.readable());
    return emitrs_yaml(*n.tree(), n.id(), EmitOptions{}, cont, append);
}
/** (1) emit+resize: JSON to the given `std::string`/`std::vector`-like container,
 * resizing it as needed to fit the emitted JSON.
 * @return a substr trimmed to the new emitted contents */
template<class CharOwningContainer>
substr emitrs_json(ConstNodeRef const& n, EmitOptions const& opts, CharOwningContainer * cont, bool append=false)
{
    if(!detail::is_set_(n))
        return {};
    _RYML_CB_CHECK(n.tree()->callbacks(), n.readable());
    return emitrs_json(*n.tree(), n.id(), opts, cont, append);
}
/** (2) like (1), but use default emit options */
template<class CharOwningContainer>
substr emitrs_json(ConstNodeRef const& n, CharOwningContainer * cont, bool append=false)
{
    if(!detail::is_set_(n))
        return {};
    _RYML_CB_CHECK(n.tree()->callbacks(), n.readable());
    return emitrs_json(*n.tree(), n.id(), EmitOptions{}, cont, append);
}


/** (3) emit+resize: YAML to a newly-created `std::string`/`std::vector`-like container. */
template<class CharOwningContainer>
CharOwningContainer emitrs_yaml(ConstNodeRef const& n, EmitOptions const& opts={})
{
    if(!detail::is_set_(n))
        return {};
    _RYML_CB_CHECK(n.tree()->callbacks(), n.readable());
    CharOwningContainer c;
    emitrs_yaml(*n.tree(), n.id(), opts, &c);
    return c;
}
/** (3) emit+resize: JSON to a newly-created `std::string`/`std::vector`-like container. */
template<class CharOwningContainer>
CharOwningContainer emitrs_json(ConstNodeRef const& n, EmitOptions const& opts={})
{
    if(!detail::is_set_(n))
        return {};
    _RYML_CB_CHECK(n.tree()->callbacks(), n.readable());
    CharOwningContainer c;
    emitrs_json(*n.tree(), n.id(), opts, &c);
    return c;
}


/** @} */


//-----------------------------------------------------------------------------

/** @cond dev */

RYML_DEPRECATE_EMIT inline size_t emit(Tree const& t, id_type id, FILE *f)
{
    return emit_yaml(t, id, f);
}
RYML_DEPRECATE_EMIT inline size_t emit(Tree const& t, FILE *f=nullptr)
{
    return emit_yaml(t, f);
}
RYML_DEPRECATE_EMIT inline size_t emit(ConstNodeRef const& r, FILE *f=nullptr)
{
    return emit_yaml(r, f);
}

RYML_DEPRECATE_EMIT inline substr emit(Tree const& t, id_type id, substr buf, bool error_on_excess=true)
{
    return emit_yaml(t, id, buf, error_on_excess);
}
RYML_DEPRECATE_EMIT inline substr emit(Tree const& t, substr buf, bool error_on_excess=true)
{
    return emit_yaml(t, buf, error_on_excess);
}
RYML_DEPRECATE_EMIT inline substr emit(ConstNodeRef const& r, substr buf, bool error_on_excess=true)
{
    return emit_yaml(r, buf, error_on_excess);
}

template<class CharOwningContainer>
RYML_DEPRECATE_EMITRS substr emitrs(Tree const& t, id_type id, CharOwningContainer * cont)
{
    return emitrs_yaml(t, id, cont);
}
template<class CharOwningContainer>
RYML_DEPRECATE_EMITRS CharOwningContainer emitrs(Tree const& t, id_type id)
{
    return emitrs_yaml<CharOwningContainer>(t, id);
}
template<class CharOwningContainer>
RYML_DEPRECATE_EMITRS substr emitrs(Tree const& t, CharOwningContainer * cont)
{
    return emitrs_yaml(t, cont);
}
template<class CharOwningContainer>
RYML_DEPRECATE_EMITRS CharOwningContainer emitrs(Tree const& t)
{
    return emitrs_yaml<CharOwningContainer>(t);
}
template<class CharOwningContainer>
RYML_DEPRECATE_EMITRS substr emitrs(ConstNodeRef const& n, CharOwningContainer * cont)
{
    return emitrs_yaml(n, cont);
}
template<class CharOwningContainer>
RYML_DEPRECATE_EMITRS CharOwningContainer emitrs(ConstNodeRef const& n)
{
    return emitrs_yaml<CharOwningContainer>(n);
}
/** @endcond */


} // namespace yml
} // namespace c4

C4_SUPPRESS_WARNING_GCC_CLANG_POP

#undef RYML_DEPRECATE_EMIT
#undef RYML_DEPRECATE_EMITRS

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/emit.def.hpp
//#include "c4/yml/emit.def.hpp"
#if !defined(C4_YML_EMIT_DEF_HPP_) && !defined(_C4_YML_EMIT_DEF_HPP_)
#error "amalgamate: file c4/yml/emit.def.hpp must have been included at this point"
#endif /* C4_YML_EMIT_DEF_HPP_ */


#endif /* _C4_YML_EMIT_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/emit.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/emit.def.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/emit.def.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_EMIT_DEF_HPP_
#define _C4_YML_EMIT_DEF_HPP_

#ifndef _C4_YML_EMIT_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/emit.hpp
//#include "c4/yml/emit.hpp"
#if !defined(C4_YML_EMIT_HPP_) && !defined(_C4_YML_EMIT_HPP_)
#error "amalgamate: file c4/yml/emit.hpp must have been included at this point"
#endif /* C4_YML_EMIT_HPP_ */

#endif

/** @file emit.def.hpp Definitions for emit functions. */
#ifndef _C4_YML_DETAIL_PARSER_DBG_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/parser_dbg.hpp
//#include "c4/yml/detail/parser_dbg.hpp"
#if !defined(C4_YML_DETAIL_PARSER_DBG_HPP_) && !defined(_C4_YML_DETAIL_PARSER_DBG_HPP_)
#error "amalgamate: file c4/yml/detail/parser_dbg.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PARSER_DBG_HPP_ */

#endif

namespace c4 {
namespace yml {

template<class Writer>
substr Emitter<Writer>::emit_as(EmitType_e type, Tree const& t, id_type id, bool error_on_excess)
{
    if(t.empty())
    {
        _RYML_CB_ASSERT(t.callbacks(), id == NONE);
        return {};
    }
    if(id == NONE)
        id = t.root_id();
    _RYML_CB_CHECK(t.callbacks(), id < t.capacity());
    m_tree = &t;
    m_flow = false;
    if(type == EMIT_YAML)
        _emit_yaml(id);
    else if(type == EMIT_JSON)
        _do_visit_json(id, 0);
    else
        _RYML_CB_ERR(m_tree->callbacks(), "unknown emit type");
    m_tree = nullptr;
    return this->Writer::_get(error_on_excess);
}


//-----------------------------------------------------------------------------

template<class Writer>
void Emitter<Writer>::_emit_yaml(id_type id)
{
    // save branches in the visitor by doing the initial stream/doc
    // logic here, sparing the need to check stream/val/keyval inside
    // the visitor functions
    auto dispatch = [this](id_type node){
        NodeType ty = m_tree->type(node);
        if(ty.is_flow_sl())
            _do_visit_flow_sl(node, 0);
        else if(ty.is_flow_ml())
            _do_visit_flow_ml(node, 0);
        else
        {
            _do_visit_block(node, 0);
        }
    };
    if(!m_tree->is_root(id))
    {
        if(m_tree->is_container(id) && !m_tree->type(id).is_flow())
        {
            id_type ilevel = 0;
            if(m_tree->has_key(id))
            {
                this->Writer::_do_write(m_tree->key(id));
                this->Writer::_do_write(":\n");
                ++ilevel;
            }
            _do_visit_block_container(id, 0, ilevel, ilevel);
            return;
        }
    }

    TagDirectiveRange tagds = m_tree->tag_directives();
    auto write_tag_directives = [&tagds, this](const id_type next_node){
        TagDirective const* C4_RESTRICT end = tagds.b;
        while(end < tagds.e)
        {
            if(end->next_node_id > next_node)
                break;
            ++end;
        }
        const id_type parent = m_tree->parent(next_node);
        for( ; tagds.b != end; ++tagds.b)
        {
            if(next_node != m_tree->first_child(parent))
                this->Writer::_do_write("...\n");
            this->Writer::_do_write("%TAG ");
            this->Writer::_do_write(tagds.b->handle);
            this->Writer::_do_write(' ');
            this->Writer::_do_write(tagds.b->prefix);
            this->Writer::_do_write('\n');
        }
    };
    if(m_tree->is_stream(id))
    {
        const id_type first_child = m_tree->first_child(id);
        if(first_child != NONE)
            write_tag_directives(first_child);
        for(id_type child = first_child; child != NONE; child = m_tree->next_sibling(child))
        {
            dispatch(child);
            if(m_tree->is_doc(child) && m_tree->type(child).is_flow_sl())
                this->Writer::_do_write('\n');
            if(m_tree->next_sibling(child) != NONE)
                write_tag_directives(m_tree->next_sibling(child));
        }
    }
    else if(m_tree->is_container(id))
    {
        dispatch(id);
    }
    else if(m_tree->is_doc(id))
    {
        _RYML_CB_ASSERT(m_tree->callbacks(), !m_tree->is_container(id)); // checked above
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_val(id)); // so it must be a val
        _write_doc(id);
    }
    else if(m_tree->is_keyval(id))
    {
        _writek(id, 0);
        this->Writer::_do_write(": ");
        _writev(id, 0);
        if(!m_tree->type(id).is_flow())
            this->Writer::_do_write('\n');
    }
    else if(m_tree->is_val(id))
    {
        //this->Writer::_do_write("- ");
        _writev(id, 0);
        if(!m_tree->type(id).is_flow())
            this->Writer::_do_write('\n');
    }
    else if(m_tree->type(id) == NOTYPE)
    {
        ;
    }
    else
    {
        _RYML_CB_ERR(m_tree->callbacks(), "unknown type");
    }
}

#define _rymlindent_nextline() this->_indent(ilevel + 1);

template<class Writer>
void Emitter<Writer>::_write_doc(id_type id)
{
    RYML_ASSERT(m_tree->is_doc(id));
    RYML_ASSERT(!m_tree->has_key(id));
    if(!m_tree->is_root(id))
    {
        RYML_ASSERT(m_tree->is_stream(m_tree->parent(id)));
        this->Writer::_do_write("---");
    }
    //
    if(!m_tree->has_val(id)) // this is more frequent
    {
        const bool tag = m_tree->has_val_tag(id);
        const bool anchor = m_tree->has_val_anchor(id);
        if(!tag && !anchor)
        {
            ;
        }
        else if(!tag && anchor)
        {
            if(!m_tree->is_root(id))
                this->Writer::_do_write(' ');
            this->Writer::_do_write('&');
            this->Writer::_do_write(m_tree->val_anchor(id));
            #ifdef RYML_NO_COVERAGE__TO_BE_DELETED
            if(m_tree->has_children(id) && m_tree->is_root(id))
                this->Writer::_do_write('\n');
            #endif
        }
        else if(tag && !anchor)
        {
            if(!m_tree->is_root(id))
                this->Writer::_do_write(' ');
            _write_tag(m_tree->val_tag(id));
            #ifdef RYML_NO_COVERAGE__TO_BE_DELETED
            if(m_tree->has_children(id) && m_tree->is_root(id))
                this->Writer::_do_write('\n');
            #endif
        }
        else // tag && anchor
        {
            if(!m_tree->is_root(id))
                this->Writer::_do_write(' ');
            _write_tag(m_tree->val_tag(id));
            this->Writer::_do_write(" &");
            this->Writer::_do_write(m_tree->val_anchor(id));
            #ifdef RYML_NO_COVERAGE__TO_BE_DELETED
            if(m_tree->has_children(id) && m_tree->is_root(id))
                this->Writer::_do_write('\n');
            #endif
        }
    }
    else // docval
    {
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->has_val(id));
        // some plain scalars such as '...' and '---' must not
        // appear at 0-indentation
        const csubstr val = m_tree->val(id);
        const bool preceded_by_3_dashes = !m_tree->is_root(id);
        const type_bits style_marks = m_tree->type(id) & (KEY_STYLE|VAL_STYLE);
        const bool is_plain = m_tree->type(id).is_val_plain();
        const bool is_ambiguous = (is_plain || !style_marks)
            && ((val.begins_with("...") || val.begins_with("---"))
                ||
                (val.find('\n') != npos));
        if(preceded_by_3_dashes)
        {
            if(val.len == 0 && !m_tree->has_val_anchor(id) && !m_tree->has_val_tag(id))
            {
                this->Writer::_do_write('\n');
                return;
            }
            else if(val.len && is_ambiguous)
            {
                this->Writer::_do_write('\n');
            }
            else
            {
                this->Writer::_do_write(' ');
            }
        }
        id_type ilevel = 0u;
        if(is_ambiguous)
        {
            _rymlindent_nextline();
            ++ilevel;
        }
        _writev(id, ilevel);
        if(val.len && m_tree->is_root(id))
            this->Writer::_do_write('\n');
    }
    if(!m_tree->is_root(id))
        this->Writer::_do_write('\n');
}

template<class Writer>
void Emitter<Writer>::_do_visit_flow_sl(id_type node, id_type depth, id_type ilevel)
{
    const bool prev_flow = m_flow;
    m_flow = true;
    _RYML_CB_ASSERT(m_tree->callbacks(), !m_tree->is_stream(node));
    _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_container(node) || m_tree->is_doc(node));
    _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_root(node) || (m_tree->parent_is_map(node) || m_tree->parent_is_seq(node)));
    if(C4_UNLIKELY(depth > m_opts.max_depth()))
        _RYML_CB_ERR(m_tree->callbacks(), "max depth exceeded");

    if(m_tree->is_doc(node))
    {
        _write_doc(node);
        #ifdef RYML_NO_COVERAGE__TO_BE_DELETED
        if(!m_tree->has_children(node))
            return;
        else
        #endif
        {
            if(m_tree->is_map(node))
            {
                this->Writer::_do_write('{');
            }
            else
            {
                _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_seq(node));
                this->Writer::_do_write('[');
            }
        }
    }
    else if(m_tree->is_container(node))
    {
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_map(node) || m_tree->is_seq(node));

        bool spc = false; // write a space

        if(m_tree->has_key(node))
        {
            _writek(node, ilevel);
            this->Writer::_do_write(':');
            spc = true;
        }

        if(m_tree->has_val_tag(node))
        {
            if(spc)
                this->Writer::_do_write(' ');
            _write_tag(m_tree->val_tag(node));
            spc = true;
        }

        if(m_tree->has_val_anchor(node))
        {
            if(spc)
                this->Writer::_do_write(' ');
            this->Writer::_do_write('&');
            this->Writer::_do_write(m_tree->val_anchor(node));
            spc = true;
        }

        if(spc)
            this->Writer::_do_write(' ');

        if(m_tree->is_map(node))
        {
            this->Writer::_do_write('{');
        }
        else
        {
            _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_seq(node));
            this->Writer::_do_write('[');
        }
    } // container

    for(id_type child = m_tree->first_child(node), count = 0; child != NONE; child = m_tree->next_sibling(child))
    {
        if(count++)
            this->Writer::_do_write(',');
        if(m_tree->is_keyval(child))
        {
            _writek(child, ilevel);
            this->Writer::_do_write(": ");
            _writev(child, ilevel);
        }
        else if(m_tree->is_val(child))
        {
            _writev(child, ilevel);
        }
        else
        {
            // with single-line flow, we can never go back to block
            _do_visit_flow_sl(child, depth + 1, ilevel + 1);
        }
    }

    if(m_tree->is_map(node))
    {
        this->Writer::_do_write('}');
    }
    else if(m_tree->is_seq(node))
    {
        this->Writer::_do_write(']');
    }
    m_flow = prev_flow;
}

C4_SUPPRESS_WARNING_MSVC_WITH_PUSH(4702) // unreachable error, triggered by flow_ml not implemented

template<class Writer>
void Emitter<Writer>::_do_visit_flow_ml(id_type id, id_type depth, id_type ilevel, id_type do_indent)
{
    C4_UNUSED(id);
    C4_UNUSED(depth);
    C4_UNUSED(ilevel);
    C4_UNUSED(do_indent);
    c4::yml::error("not implemented");
    #ifdef THIS_IS_A_WORK_IN_PROGRESS
    if(C4_UNLIKELY(depth > m_opts.max_depth()))
        _RYML_CB_ERR(m_tree->callbacks(), "max depth exceeded");
    const bool prev_flow = m_flow;
    m_flow = true;
    // do it...
    m_flow = prev_flow;
    #endif
}

template<class Writer>
void Emitter<Writer>::_do_visit_block_container(id_type node, id_type depth, id_type level, bool do_indent)
{
    if(m_tree->is_seq(node))
    {
        for(id_type child = m_tree->first_child(node); child != NONE; child = m_tree->next_sibling(child))
        {
            _RYML_CB_ASSERT(m_tree->callbacks(), !m_tree->has_key(child));
            if(m_tree->is_val(child))
            {
                _indent(level, do_indent);
                this->Writer::_do_write("- ");
                _writev(child, level);
                this->Writer::_do_write('\n');
            }
            else
            {
                _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_container(child));
                NodeType ty = m_tree->type(child);
                if(ty.is_flow_sl())
                {
                    _indent(level, do_indent);
                    this->Writer::_do_write("- ");
                    _do_visit_flow_sl(child, depth+1, 0u);
                    this->Writer::_do_write('\n');
                }
                else if(ty.is_flow_ml())
                {
                    _indent(level, do_indent);
                    this->Writer::_do_write("- ");
                    _do_visit_flow_ml(child, depth+1, 0u, do_indent);
                    this->Writer::_do_write('\n');
                }
                else
                {
                    _do_visit_block(child, depth+1, level, do_indent); // same indentation level
                }
            }
            do_indent = true;
        }
    }
    else // map
    {
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_map(node));
        for(id_type ich = m_tree->first_child(node); ich != NONE; ich = m_tree->next_sibling(ich))
        {
            _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->has_key(ich));
            if(m_tree->is_keyval(ich))
            {
                _indent(level, do_indent);
                _writek(ich, level);
                this->Writer::_do_write(": ");
                _writev(ich, level);
                this->Writer::_do_write('\n');
            }
            else
            {
                _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_container(ich));
                NodeType ty = m_tree->type(ich);
                if(ty.is_flow_sl())
                {
                    _indent(level, do_indent);
                    _do_visit_flow_sl(ich, depth+1, 0u);
                    this->Writer::_do_write('\n');
                }
                else if(ty.is_flow_ml())
                {
                    _indent(level, do_indent);
                    _do_visit_flow_ml(ich, depth+1, 0u);
                    this->Writer::_do_write('\n');
                }
                else
                {
                    _do_visit_block(ich, depth+1, level, do_indent); // same level!
                }
            } // keyval vs container
            do_indent = true;
        } // for children
    } // seq vs map
}

template<class Writer>
void Emitter<Writer>::_do_visit_block(id_type node, id_type depth, id_type ilevel, id_type do_indent)
{
    _RYML_CB_ASSERT(m_tree->callbacks(), !m_tree->is_stream(node));
    _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_container(node) || m_tree->is_doc(node));
    _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_root(node) || (m_tree->parent_is_map(node) || m_tree->parent_is_seq(node)));
    if(C4_UNLIKELY(depth > m_opts.max_depth()))
        _RYML_CB_ERR(m_tree->callbacks(), "max depth exceeded");
    if(m_tree->is_doc(node))
    {
        _write_doc(node);
        if(!m_tree->has_children(node))
            return;
    }
    else if(m_tree->is_container(node))
    {
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_map(node) || m_tree->is_seq(node));
        bool spc = false; // write a space
        bool nl = false;  // write a newline
        if(m_tree->has_key(node))
        {
            _indent(ilevel, do_indent);
            _writek(node, ilevel);
            this->Writer::_do_write(':');
            spc = true;
        }
        else if(!m_tree->is_root(node))
        {
            _indent(ilevel, do_indent);
            this->Writer::_do_write('-');
            spc = true;
        }

        if(m_tree->has_val_tag(node))
        {
            if(spc)
                this->Writer::_do_write(' ');
            _write_tag(m_tree->val_tag(node));
            spc = true;
            nl = true;
        }

        if(m_tree->has_val_anchor(node))
        {
            if(spc)
                this->Writer::_do_write(' ');
            this->Writer::_do_write('&');
            this->Writer::_do_write(m_tree->val_anchor(node));
            spc = true;
            nl = true;
        }

        if(m_tree->has_children(node))
        {
            if(m_tree->has_key(node))
                nl = true;
            else
                if(!m_tree->is_root(node) && !nl)
                    spc = true;
        }
        else
        {
            if(m_tree->is_seq(node))
                this->Writer::_do_write(" []\n");
            else if(m_tree->is_map(node))
                this->Writer::_do_write(" {}\n");
            return;
        }

        if(spc && !nl)
            this->Writer::_do_write(' ');

        do_indent = 0;
        if(nl)
        {
            this->Writer::_do_write('\n');
            do_indent = 1;
        }
    } // container

    id_type next_level = ilevel + 1;
    if(m_tree->is_root(node) || m_tree->is_doc(node))
        next_level = ilevel; // do not indent at top level

    _do_visit_block_container(node, depth, next_level, do_indent);
}

C4_SUPPRESS_WARNING_MSVC_POP


template<class Writer>
void Emitter<Writer>::_do_visit_json(id_type id, id_type depth)
{
    _RYML_CB_CHECK(m_tree->callbacks(), !m_tree->is_stream(id)); // JSON does not have streams
    if(C4_UNLIKELY(depth > m_opts.max_depth()))
        _RYML_CB_ERR(m_tree->callbacks(), "max depth exceeded");
    if(m_tree->is_keyval(id))
    {
        _writek_json(id);
        this->Writer::_do_write(": ");
        _writev_json(id);
    }
    else if(m_tree->is_val(id))
    {
        _writev_json(id);
    }
    else if(m_tree->is_container(id))
    {
        if(m_tree->has_key(id))
        {
            _writek_json(id);
            this->Writer::_do_write(": ");
        }
        if(m_tree->is_seq(id))
            this->Writer::_do_write('[');
        else if(m_tree->is_map(id))
            this->Writer::_do_write('{');
    }  // container

    for(id_type ich = m_tree->first_child(id); ich != NONE; ich = m_tree->next_sibling(ich))
    {
        if(ich != m_tree->first_child(id))
            this->Writer::_do_write(',');
        _do_visit_json(ich, depth+1);
    }

    if(m_tree->is_seq(id))
        this->Writer::_do_write(']');
    else if(m_tree->is_map(id))
        this->Writer::_do_write('}');
}

template<class Writer>
void Emitter<Writer>::_write(NodeScalar const& C4_RESTRICT sc, NodeType flags, id_type ilevel)
{
    if( ! sc.tag.empty())
    {
        _write_tag(sc.tag);
        this->Writer::_do_write(' ');
    }
    if(flags.has_anchor())
    {
        RYML_ASSERT(flags.is_ref() != flags.has_anchor());
        RYML_ASSERT( ! sc.anchor.empty());
        this->Writer::_do_write('&');
        this->Writer::_do_write(sc.anchor);
        this->Writer::_do_write(' ');
    }
    else if(flags.is_ref())
    {
        if(sc.anchor != "<<")
            this->Writer::_do_write('*');
        this->Writer::_do_write(sc.anchor);
        if(flags.is_key_ref())
            this->Writer::_do_write(' ');
        return;
    }

    // ensure the style flags only have one of KEY or VAL
    _RYML_CB_ASSERT(m_tree->callbacks(), ((flags & SCALAR_STYLE) == 0) || (((flags&KEY_STYLE) == 0) != ((flags&VAL_STYLE) == 0)));
    type_bits style_marks = flags & SCALAR_STYLE;
    if(!style_marks)
        style_marks = scalar_style_choose(sc.scalar);
    if(style_marks & (KEY_LITERAL|VAL_LITERAL))
    {
        _write_scalar_literal(sc.scalar, ilevel, flags.has_key());
    }
    else if(style_marks & (KEY_FOLDED|VAL_FOLDED))
    {
        _write_scalar_folded(sc.scalar, ilevel, flags.has_key());
    }
    else if(style_marks & (KEY_SQUO|VAL_SQUO))
    {
        _write_scalar_squo(sc.scalar, ilevel);
    }
    else if(style_marks & (KEY_DQUO|VAL_DQUO))
    {
        _write_scalar_dquo(sc.scalar, ilevel);
    }
    else if(style_marks & (KEY_PLAIN|VAL_PLAIN))
    {
        if(C4_LIKELY(!(sc.scalar.begins_with(": ") || sc.scalar.begins_with(":\t"))))
            _write_scalar_plain(sc.scalar, ilevel);
        else
            _write_scalar_squo(sc.scalar, ilevel);
    }
    else
    {
        _RYML_CB_ERR(m_tree->callbacks(), "not implemented");
    }
}

template<class Writer>
void Emitter<Writer>::_write_json(NodeScalar const& C4_RESTRICT sc, NodeType flags)
{
    if(flags & (KEYTAG|VALTAG))
        if(m_opts.json_error_flags() & EmitOptions::JSON_ERR_ON_TAG)
            _RYML_CB_ERR(m_tree->callbacks(), "JSON does not have tags");
    if(C4_UNLIKELY(flags.has_anchor()))
        if(m_opts.json_error_flags() & EmitOptions::JSON_ERR_ON_ANCHOR)
            _RYML_CB_ERR(m_tree->callbacks(), "JSON does not have anchors");
    if(sc.scalar.len)
    {
        // use double quoted style...
        // if it is a key (mandatory in JSON)
        // if the style is marked quoted
        bool dquoted = ((flags & (KEY|VALQUO))
                        || (scalar_style_json_choose(sc.scalar) & SCALAR_DQUO)); // choose the style
        if(dquoted)
            _write_scalar_json_dquo(sc.scalar);
        else
            this->Writer::_do_write(sc.scalar);
    }
    else
    {
        if(sc.scalar.str || (flags & (KEY|VALQUO|KEYTAG|VALTAG)))
            this->Writer::_do_write("\"\"");
        else
            this->Writer::_do_write("null");
    }
}

template<class Writer>
size_t Emitter<Writer>::_write_escaped_newlines(csubstr s, size_t i)
{
    RYML_ASSERT(s.len > i);
    RYML_ASSERT(s.str[i] == '\n');
    //_c4dbgpf("nl@i={} rem=[{}]~~~{}~~~", i, s.sub(i).len, s.sub(i));
    // add an extra newline for each sequence of consecutive
    // newline/whitespace
    this->Writer::_do_write('\n');
    do
    {
        this->Writer::_do_write('\n'); // write the newline again
        ++i; // increase the outer loop counter!
    } while(i < s.len && s.str[i] == '\n');
    _RYML_CB_ASSERT(m_tree->callbacks(), i > 0);
    --i;
    _RYML_CB_ASSERT(m_tree->callbacks(), s.str[i] == '\n');
    return i;
}

inline bool _is_indented_block(csubstr s, size_t prev, size_t i) noexcept
{
    if(prev == 0 && s.begins_with_any(" \t"))
        return true;
    const size_t pos = s.first_not_of('\n', i);
    return (pos != npos) && (s.str[pos] == ' ' || s.str[pos] == '\t');
}

template<class Writer>
size_t Emitter<Writer>::_write_indented_block(csubstr s, size_t i, id_type ilevel)
{
    //_c4dbgpf("indblock@i={} rem=[{}]~~~\n{}~~~", i, s.sub(i).len, s.sub(i));
    _RYML_CB_ASSERT(m_tree->callbacks(), i > 0);
    _RYML_CB_ASSERT(m_tree->callbacks(), s.str[i-1] == '\n');
    _RYML_CB_ASSERT(m_tree->callbacks(), i < s.len);
    _RYML_CB_ASSERT(m_tree->callbacks(), s.str[i] == ' ' || s.str[i] == '\t' || s.str[i] == '\n');
again:
    size_t pos = s.find("\n ", i);
    if(pos == npos)
        pos = s.find("\n\t", i);
    if(pos != npos)
    {
        ++pos;
        //_c4dbgpf("indblock line@i={} rem=[{}]~~~\n{}~~~", i, s.range(i, pos).len, s.range(i, pos));
        _rymlindent_nextline();
        this->Writer::_do_write(s.range(i, pos));
        i = pos;
        goto again;
    }
    // consume the newlines after the indented block
    // to prevent them from being escaped
    pos = s.find('\n', i);
    if(pos != npos)
    {
        const size_t pos2 = s.first_not_of('\n', pos);
        pos = (pos2 != npos) ? pos2 : pos;
        //_c4dbgpf("indblock line@i={} rem=[{}]~~~\n{}~~~", i, s.range(i, pos).len, s.range(i, pos));
        _rymlindent_nextline();
        this->Writer::_do_write(s.range(i, pos));
        i = pos;
    }
    return i;
}

template<class Writer>
void Emitter<Writer>::_write_scalar_literal(csubstr s, id_type ilevel, bool explicit_key)
{
    _RYML_CB_ASSERT(m_tree->callbacks(), s.find("\r") == csubstr::npos);
    if(explicit_key)
        this->Writer::_do_write("? ");
    csubstr trimmed = s.trimr('\n');
    const size_t numnewlines_at_end = s.len - trimmed.len;
    const bool is_newline_only = (trimmed.len == 0 && (s.len > 0));
    const bool explicit_indentation = s.triml("\n\r").begins_with_any(" \t");
    //
    this->Writer::_do_write('|');
    if(explicit_indentation)
        this->Writer::_do_write('2');
    //
    if(numnewlines_at_end > 1 || is_newline_only)
        this->Writer::_do_write('+');
    else if(numnewlines_at_end == 0)
        this->Writer::_do_write('-');
    //
    if(trimmed.len)
    {
        this->Writer::_do_write('\n');
        size_t pos = 0; // tracks the last character that was already written
        for(size_t i = 0; i < trimmed.len; ++i)
        {
            if(trimmed[i] != '\n')
                continue;
            // write everything up to this point
            csubstr since_pos = trimmed.range(pos, i+1); // include the newline
            _rymlindent_nextline()
            this->Writer::_do_write(since_pos);
            pos = i+1; // already written
        }
        if(pos < trimmed.len)
        {
            _rymlindent_nextline()
            this->Writer::_do_write(trimmed.sub(pos));
        }
    }
    for(size_t i = !is_newline_only; i < numnewlines_at_end; ++i)
        this->Writer::_do_write('\n');
    if(explicit_key)
        this->Writer::_do_write('\n');
}

template<class Writer>
void Emitter<Writer>::_write_scalar_folded(csubstr s, id_type ilevel, bool explicit_key)
{
    if(explicit_key)
        this->Writer::_do_write("? ");
    _RYML_CB_ASSERT(m_tree->callbacks(), s.find("\r") == csubstr::npos);
    csubstr trimmed = s.trimr('\n');
    const size_t numnewlines_at_end = s.len - trimmed.len;
    const bool is_newline_only = (trimmed.len == 0 && (s.len > 0));
    const bool explicit_indentation = s.triml("\n\r").begins_with_any(" \t");
    //
    this->Writer::_do_write('>');
    if(explicit_indentation)
        this->Writer::_do_write('2');
    //
    if(numnewlines_at_end == 0)
        this->Writer::_do_write('-');
    else if(numnewlines_at_end > 1 || is_newline_only)
        this->Writer::_do_write('+');
    //
    if(trimmed.len)
    {
        this->Writer::_do_write('\n');
        size_t pos = 0; // tracks the last character that was already written
        for(size_t i = 0; i < trimmed.len; ++i)
        {
            if(trimmed[i] != '\n')
                continue;
            // escape newline sequences
            if( ! _is_indented_block(s, pos, i))
            {
                if(pos < i)
                {
                    _rymlindent_nextline()
                    this->Writer::_do_write(s.range(pos, i));
                    i = _write_escaped_newlines(s, i);
                    pos = i+1;
                }
                else
                {
                    if(i+1 < s.len)
                    {
                        if(s.str[i+1] == '\n')
                        {
                            ++i;
                            i = _write_escaped_newlines(s, i);
                            pos = i+1;
                        }
                        else
                        {
                            this->Writer::_do_write('\n');
                            pos = i+1;
                        }
                    }
                }
            }
            else // do not escape newlines in indented blocks
            {
                ++i;
                _rymlindent_nextline()
                this->Writer::_do_write(s.range(pos, i));
                if(pos > 0 || !s.begins_with_any(" \t"))
                    i = _write_indented_block(s, i, ilevel);
                pos = i;
            }
        }
        if(pos < trimmed.len)
        {
            _rymlindent_nextline()
            this->Writer::_do_write(trimmed.sub(pos));
        }
    }
    for(size_t i = !is_newline_only; i < numnewlines_at_end; ++i)
        this->Writer::_do_write('\n');
    if(explicit_key)
        this->Writer::_do_write('\n');
}

template<class Writer>
void Emitter<Writer>::_write_scalar_squo(csubstr s, id_type ilevel)
{
    size_t pos = 0; // tracks the last character that was already written
    this->Writer::_do_write('\'');
    for(size_t i = 0; i < s.len; ++i)
    {
        if(s[i] == '\n')
        {
            this->Writer::_do_write(s.range(pos, i));  // write everything up to (excluding) this char
            //_c4dbgpf("newline at {}. writing ~~~{}~~~", i, s.range(pos, i));
            i = _write_escaped_newlines(s, i);
            //_c4dbgpf("newline --> {}", i);
            if(i < s.len)
                _rymlindent_nextline()
            pos = i+1;
        }
        else if(s[i] == '\'')
        {
            csubstr sub = s.range(pos, i+1);
            //_c4dbgpf("squote at {}. writing ~~~{}~~~", i, sub);
            this->Writer::_do_write(sub); // write everything up to (including) this squote
            this->Writer::_do_write('\''); // write the squote again
            pos = i+1;
        }
    }
    // write missing characters at the end of the string
    if(pos < s.len)
        this->Writer::_do_write(s.sub(pos));
    this->Writer::_do_write('\'');
}

template<class Writer>
void Emitter<Writer>::_write_scalar_dquo(csubstr s, id_type ilevel)
{
    size_t pos = 0; // tracks the last character that was already written
    this->Writer::_do_write('"');
    for(size_t i = 0; i < s.len; ++i)
    {
        const char curr = s.str[i];
        switch(curr)
        {
        case '"':
        case '\\':
        {
            csubstr sub = s.range(pos, i);
            this->Writer::_do_write(sub);  // write everything up to (excluding) this char
            this->Writer::_do_write('\\'); // write the escape
            this->Writer::_do_write(curr); // write the char
            pos = i+1;
            break;
        }
#ifndef prefer_writing_newlines_as_double_newlines
        case '\n':
        {
            csubstr sub = s.range(pos, i);
            this->Writer::_do_write(sub);   // write everything up to (excluding) this char
            this->Writer::_do_write("\\n"); // write the escape
            pos = i+1;
            (void)ilevel;
            break;
        }
#else
        case '\n':
        {
            // write everything up to (excluding) this newline
            //_c4dbgpf("nl@i={} rem=[{}]~~~{}~~~", i, s.sub(i).len, s.sub(i));
            this->Writer::_do_write(s.range(pos, i));
            i = _write_escaped_newlines(s, i);
            ++i;
            pos = i;
            // as for the next line...
            if(i < s.len)
            {
                _rymlindent_nextline() // indent the next line
                // escape leading whitespace, and flush it
                size_t first = s.first_not_of(" \t", i);
                _c4dbgpf("@i={} first={} rem=[{}]~~~{}~~~", i, first, s.sub(i).len, s.sub(i));
                if(first > i)
                {
                    if(first == npos)
                        first = s.len;
                    this->Writer::_do_write('\\');
                    this->Writer::_do_write(s.range(i, first));
                    this->Writer::_do_write('\\');
                    i = first-1;
                    pos = first;
                }
            }
            break;
        }
        // escape trailing whitespace before a newline
        case ' ':
        case '\t':
        {
            const size_t next = s.first_not_of(" \t\r", i);
            if(next != npos && s.str[next] == '\n')
            {
                csubstr sub = s.range(pos, i);
                this->Writer::_do_write(sub);  // write everything up to (excluding) this char
                this->Writer::_do_write('\\'); // escape the whitespace
                pos = i;
            }
            break;
        }
#endif
        case '\r':
        {
            csubstr sub = s.range(pos, i);
            this->Writer::_do_write(sub);  // write everything up to (excluding) this char
            this->Writer::_do_write("\\r"); // write the escaped char
            pos = i+1;
            break;
        }
        case '\b':
        {
            csubstr sub = s.range(pos, i);
            this->Writer::_do_write(sub);  // write everything up to (excluding) this char
            this->Writer::_do_write("\\b"); // write the escaped char
            pos = i+1;
            break;
        }
        }
    }
    // write missing characters at the end of the string
    if(pos < s.len)
        this->Writer::_do_write(s.sub(pos));
    this->Writer::_do_write('"');
}

template<class Writer>
void Emitter<Writer>::_write_scalar_plain(csubstr s, id_type ilevel)
{
    if(C4_UNLIKELY(ilevel == 0 && (s.begins_with("...") || s.begins_with("---"))))
    {
        _rymlindent_nextline()     // indent the next line
        ++ilevel;
    }
    size_t pos = 0; // tracks the last character that was already written
    for(size_t i = 0; i < s.len; ++i)
    {
        const char curr = s.str[i];
        if(curr == '\n')
        {
            csubstr sub = s.range(pos, i);
            this->Writer::_do_write(sub);  // write everything up to (including) this newline
            i = _write_escaped_newlines(s, i);
            pos = i+1;
            if(pos < s.len)
                _rymlindent_nextline()     // indent the next line
        }
    }
    // write missing characters at the end of the string
    if(pos < s.len)
        this->Writer::_do_write(s.sub(pos));
}

#undef _rymlindent_nextline

template<class Writer>
void Emitter<Writer>::_write_scalar_json_dquo(csubstr s)
{
    size_t pos = 0;
    this->Writer::_do_write('"');
    for(size_t i = 0; i < s.len; ++i)
    {
        switch(s.str[i])
        {
        case '"':
            this->Writer ::_do_write(s.range(pos, i));
            this->Writer ::_do_write("\\\"");
            pos = i + 1;
            break;
        case '\n':
            this->Writer ::_do_write(s.range(pos, i));
            this->Writer ::_do_write("\\n");
            pos = i + 1;
            break;
        case '\t':
            this->Writer ::_do_write(s.range(pos, i));
            this->Writer ::_do_write("\\t");
            pos = i + 1;
            break;
        case '\\':
            this->Writer ::_do_write(s.range(pos, i));
            this->Writer ::_do_write("\\\\");
            pos = i + 1;
            break;
        case '\r':
            this->Writer ::_do_write(s.range(pos, i));
            this->Writer ::_do_write("\\r");
            pos = i + 1;
            break;
        case '\b':
            this->Writer ::_do_write(s.range(pos, i));
            this->Writer ::_do_write("\\b");
            pos = i + 1;
            break;
        case '\f':
            this->Writer ::_do_write(s.range(pos, i));
            this->Writer ::_do_write("\\f");
            pos = i + 1;
            break;
        }
    }
    if(pos < s.len)
    {
        csubstr sub = s.sub(pos);
        this->Writer::_do_write(sub);
    }
    this->Writer::_do_write('"');
}

} // namespace yml
} // namespace c4

#endif /* _C4_YML_EMIT_DEF_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/emit.def.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/detail/stack.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/stack.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_DETAIL_STACK_HPP_
#define _C4_YML_DETAIL_STACK_HPP_

#ifndef _C4_YML_COMMON_HPP_
//included above:
//#include "../common.hpp"
#endif

#ifdef RYML_DBG
#   include <type_traits>
#endif

//included above:
//#include <string.h>

namespace c4 {
namespace yml {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")

namespace detail {

/** A lightweight contiguous stack with Small Storage
 * Optimization. This is required because std::vector can throw
 * exceptions, and we don't want to enforce any particular error
 * mechanism. */
template<class T, id_type N=16>
class stack
{
    static_assert(std::is_trivially_copyable<T>::value, "T must be trivially copyable");
    static_assert(std::is_trivially_destructible<T>::value, "T must be trivially destructible");

public:

    enum : id_type { sso_size = N };

public:

    T              m_buf[size_t(N)];
    T *C4_RESTRICT m_stack;
    id_type        m_size;
    id_type        m_capacity;
    Callbacks      m_callbacks;

public:

    constexpr static bool is_contiguous() { return true; }

    stack(Callbacks const& cb)
        : m_buf()
        , m_stack(m_buf)
        , m_size(0)
        , m_capacity(N)
        , m_callbacks(cb) {}
    stack() : stack(get_callbacks()) {}
    ~stack()
    {
        _free();
    }

    stack(stack const& that) RYML_NOEXCEPT : stack(that.m_callbacks)
    {
        resize(that.m_size);
        _cp(&that);
    }

    stack(stack &&that) noexcept : stack(that.m_callbacks)
    {
        _mv(&that);
    }

    stack& operator= (stack const& that) RYML_NOEXCEPT
    {
        _cb(that.m_callbacks);
        resize(that.m_size);
        _cp(&that);
        return *this;
    }

    stack& operator= (stack &&that) noexcept
    {
        _cb(that.m_callbacks);
        _mv(&that);
        return *this;
    }

public:

    id_type size() const { return m_size; }
    id_type empty() const { return m_size == 0; }
    id_type capacity() const { return m_capacity; }

    void clear()
    {
        m_size = 0;
    }

    void resize(id_type sz)
    {
        reserve(sz);
        m_size = sz;
    }

    void reserve(id_type sz);

    void push(T const& C4_RESTRICT n)
    {
        _RYML_CB_ASSERT(m_callbacks, (const char*)&n + sizeof(T) < (const char*)m_stack || &n > m_stack + m_capacity);
        if(m_size == m_capacity)
        {
            id_type cap = m_capacity == 0 ? N : 2 * m_capacity;
            reserve(cap);
        }
        m_stack[m_size] = n;
        ++m_size;
    }

    void push_top()
    {
        _RYML_CB_ASSERT(m_callbacks, m_size > 0);
        if(m_size == m_capacity)
        {
            id_type cap = m_capacity == 0 ? N : 2 * m_capacity;
            reserve(cap);
        }
        m_stack[m_size] = m_stack[m_size - 1];
        ++m_size;
    }

    T const& C4_RESTRICT pop()
    {
        _RYML_CB_ASSERT(m_callbacks, m_size > 0);
        --m_size;
        return m_stack[m_size];
    }

    C4_ALWAYS_INLINE T const& C4_RESTRICT top() const { _RYML_CB_ASSERT(m_callbacks, m_size > 0); return m_stack[m_size - 1]; }
    C4_ALWAYS_INLINE T      & C4_RESTRICT top()       { _RYML_CB_ASSERT(m_callbacks, m_size > 0); return m_stack[m_size - 1]; }

    C4_ALWAYS_INLINE T const& C4_RESTRICT bottom() const { _RYML_CB_ASSERT(m_callbacks, m_size > 0); return m_stack[0]; }
    C4_ALWAYS_INLINE T      & C4_RESTRICT bottom()       { _RYML_CB_ASSERT(m_callbacks, m_size > 0); return m_stack[0]; }

    C4_ALWAYS_INLINE T const& C4_RESTRICT top(id_type i) const { _RYML_CB_ASSERT(m_callbacks, i < m_size); return m_stack[m_size - 1 - i]; }
    C4_ALWAYS_INLINE T      & C4_RESTRICT top(id_type i)       { _RYML_CB_ASSERT(m_callbacks, i < m_size); return m_stack[m_size - 1 - i]; }

    C4_ALWAYS_INLINE T const& C4_RESTRICT bottom(id_type i) const { _RYML_CB_ASSERT(m_callbacks, i < m_size); return m_stack[i]; }
    C4_ALWAYS_INLINE T      & C4_RESTRICT bottom(id_type i)       { _RYML_CB_ASSERT(m_callbacks, i < m_size); return m_stack[i]; }

    C4_ALWAYS_INLINE T const& C4_RESTRICT operator[](id_type i) const { _RYML_CB_ASSERT(m_callbacks, i < m_size); return m_stack[i]; }
    C4_ALWAYS_INLINE T      & C4_RESTRICT operator[](id_type i)       { _RYML_CB_ASSERT(m_callbacks, i < m_size); return m_stack[i]; }

public:

    using       iterator = T       *;
    using const_iterator = T const *;

    iterator begin() { return m_stack; }
    iterator end  () { return m_stack + m_size; }

    const_iterator begin() const { return (const_iterator)m_stack; }
    const_iterator end  () const { return (const_iterator)m_stack + m_size; }

public:

    void _free();
    void _cp(stack const* C4_RESTRICT that);
    void _mv(stack * that);
    void _cb(Callbacks const& cb);

};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<class T, id_type N>
void stack<T, N>::reserve(id_type sz)
{
    if(sz <= m_size)
        return;
    if(sz <= N)
    {
        m_stack = m_buf;
        m_capacity = N;
        return;
    }
    T *buf = (T*) m_callbacks.m_allocate((size_t)sz * sizeof(T), m_stack, m_callbacks.m_user_data);
    _RYML_CB_ASSERT(m_callbacks, ((uintptr_t)buf % alignof(T)) == 0u);
    memcpy(buf, m_stack, (size_t)m_size * sizeof(T));
    if(m_stack != m_buf)
    {
        m_callbacks.m_free(m_stack, (size_t)m_capacity * sizeof(T), m_callbacks.m_user_data);
    }
    m_stack = buf;
    m_capacity = sz;
}


//-----------------------------------------------------------------------------

template<class T, id_type N>
void stack<T, N>::_free()
{
    _RYML_CB_ASSERT(m_callbacks, m_stack != nullptr); // this structure cannot be memset() to zero
    if(m_stack != m_buf)
    {
        m_callbacks.m_free(m_stack, (size_t)m_capacity * sizeof(T), m_callbacks.m_user_data);
        m_stack = m_buf;
        m_size = N;
        m_capacity = N;
    }
    else
    {
        _RYML_CB_ASSERT(m_callbacks, m_capacity == N);
    }
}


//-----------------------------------------------------------------------------

template<class T, id_type N>
void stack<T, N>::_cp(stack const* C4_RESTRICT that)
{
    if(that->m_stack != that->m_buf)
    {
        _RYML_CB_ASSERT(m_callbacks, that->m_capacity > N);
        _RYML_CB_ASSERT(m_callbacks, that->m_size <= that->m_capacity);
    }
    else
    {
        _RYML_CB_ASSERT(m_callbacks, that->m_capacity <= N);
        _RYML_CB_ASSERT(m_callbacks, that->m_size <= that->m_capacity);
    }
    memcpy(m_stack, that->m_stack, that->m_size * sizeof(T));
    m_size = that->m_size;
    m_capacity = that->m_size < N ? N : that->m_size;
    m_callbacks = that->m_callbacks;
}


//-----------------------------------------------------------------------------

template<class T, id_type N>
void stack<T, N>::_mv(stack * that)
{
    if(that->m_stack != that->m_buf)
    {
        _RYML_CB_ASSERT(m_callbacks, that->m_capacity > N);
        _RYML_CB_ASSERT(m_callbacks, that->m_size <= that->m_capacity);
        m_stack = that->m_stack;
    }
    else
    {
        _RYML_CB_ASSERT(m_callbacks, that->m_capacity <= N);
        _RYML_CB_ASSERT(m_callbacks, that->m_size <= that->m_capacity);
        memcpy(m_buf, that->m_buf, that->m_size * sizeof(T));
        m_stack = m_buf;
    }
    m_size = that->m_size;
    m_capacity = that->m_capacity;
    m_callbacks = that->m_callbacks;
    // make sure no deallocation happens on destruction
    _RYML_CB_ASSERT(m_callbacks, that->m_stack != m_buf);
    that->m_stack = that->m_buf;
    that->m_capacity = N;
    that->m_size = 0;
}


//-----------------------------------------------------------------------------

template<class T, id_type N>
void stack<T, N>::_cb(Callbacks const& cb)
{
    if(cb != m_callbacks)
    {
        _free();
        m_callbacks = cb;
    }
}

} // namespace detail

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace yml
} // namespace c4

#endif /* _C4_YML_DETAIL_STACK_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/detail/stack.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/filter_processor.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/filter_processor.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_FILTER_PROCESSOR_HPP_
#define _C4_YML_FILTER_PROCESSOR_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/common.hpp
//#include "c4/yml/common.hpp"
#if !defined(C4_YML_COMMON_HPP_) && !defined(_C4_YML_COMMON_HPP_)
#error "amalgamate: file c4/yml/common.hpp must have been included at this point"
#endif /* C4_YML_COMMON_HPP_ */


#ifdef RYML_DBG
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/charconv.hpp
//#include "c4/charconv.hpp"
#if !defined(C4_CHARCONV_HPP_) && !defined(_C4_CHARCONV_HPP_)
#error "amalgamate: file c4/charconv.hpp must have been included at this point"
#endif /* C4_CHARCONV_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/parser_dbg.hpp
//#include "c4/yml/detail/parser_dbg.hpp"
#if !defined(C4_YML_DETAIL_PARSER_DBG_HPP_) && !defined(_C4_YML_DETAIL_PARSER_DBG_HPP_)
#error "amalgamate: file c4/yml/detail/parser_dbg.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PARSER_DBG_HPP_ */

#endif

namespace c4 {
namespace yml {

/** @defgroup doc_filter_processors Scalar filter processors
 *
 * These are internal classes used by @ref ParseEngine to parse the
 * scalars; normally there is no reason for a user to be manually
 * using these classes.
 *
 * @ingroup doc_parse */
/** @{ */

//-----------------------------------------------------------------------------

/** Filters an input string into a different output string */
struct FilterProcessorSrcDst
{
    csubstr src;
    substr dst;
    size_t rpos; ///< read position
    size_t wpos; ///< write position

    C4_ALWAYS_INLINE FilterProcessorSrcDst(csubstr src_, substr dst_) noexcept
        : src(src_)
        , dst(dst_)
        , rpos(0)
        , wpos(0)
    {
        RYML_ASSERT(!dst.overlaps(src));
    }

    C4_ALWAYS_INLINE void setwpos(size_t wpos_) noexcept { wpos = wpos_; }
    C4_ALWAYS_INLINE void setpos(size_t rpos_, size_t wpos_) noexcept { rpos = rpos_; wpos = wpos_; }
    C4_ALWAYS_INLINE void set_at_end() noexcept { skip(src.len - rpos); }

    C4_ALWAYS_INLINE bool has_more_chars() const noexcept { return rpos < src.len; }
    C4_ALWAYS_INLINE bool has_more_chars(size_t maxpos) const noexcept { RYML_ASSERT(maxpos <= src.len); return rpos < maxpos; }

    C4_ALWAYS_INLINE csubstr rem() const noexcept { return src.sub(rpos); }
    C4_ALWAYS_INLINE csubstr sofar() const noexcept { return csubstr(dst.str, wpos <= dst.len ? wpos : dst.len); }
    C4_ALWAYS_INLINE FilterResult result() const noexcept
    {
        FilterResult ret;
        ret.str.str = wpos <= dst.len ? dst.str : nullptr;
        ret.str.len = wpos;
        return ret;
    }

    C4_ALWAYS_INLINE char curr() const noexcept { RYML_ASSERT(rpos < src.len); return src[rpos]; }
    C4_ALWAYS_INLINE char next() const noexcept { return rpos+1 < src.len ? src[rpos+1] : '\0'; }
    C4_ALWAYS_INLINE bool skipped_chars() const noexcept { return wpos != rpos; }

    C4_ALWAYS_INLINE void skip() noexcept { ++rpos; }
    C4_ALWAYS_INLINE void skip(size_t num) noexcept { rpos += num; }

    C4_ALWAYS_INLINE void set_at(size_t pos, char c) noexcept
    {
        RYML_ASSERT(pos < wpos);
        dst.str[pos] = c;
    }
    C4_ALWAYS_INLINE void set(char c) noexcept
    {
        if(wpos < dst.len)
            dst.str[wpos] = c;
        ++wpos;
    }
    C4_ALWAYS_INLINE void set(char c, size_t num) noexcept
    {
        RYML_ASSERT(num > 0);
        if(wpos + num <= dst.len)
            memset(dst.str + wpos, c, num);
        wpos += num;
    }

    C4_ALWAYS_INLINE void copy() noexcept
    {
        RYML_ASSERT(rpos < src.len);
        if(wpos < dst.len)
            dst.str[wpos] = src.str[rpos];
        ++wpos;
        ++rpos;
    }
    C4_ALWAYS_INLINE void copy(size_t num) noexcept
    {
        RYML_ASSERT(num);
        RYML_ASSERT(rpos+num <= src.len);
        if(wpos + num <= dst.len)
            memcpy(dst.str + wpos, src.str + rpos, num);
        wpos += num;
        rpos += num;
    }

    C4_ALWAYS_INLINE void translate_esc(char c) noexcept
    {
        if(wpos < dst.len)
            dst.str[wpos] = c;
        ++wpos;
        rpos += 2;
    }
    C4_ALWAYS_INLINE void translate_esc_bulk(const char *C4_RESTRICT s, size_t nw, size_t nr) noexcept
    {
        RYML_ASSERT(nw > 0);
        RYML_ASSERT(nr > 0);
        RYML_ASSERT(rpos+nr <= src.len);
        if(wpos+nw <= dst.len)
            memcpy(dst.str + wpos, s, nw);
        wpos += nw;
        rpos += 1 + nr;
    }
    C4_ALWAYS_INLINE void translate_esc_extending(const char *C4_RESTRICT s, size_t nw, size_t nr) noexcept
    {
        translate_esc_bulk(s, nw, nr);
    }
};


//-----------------------------------------------------------------------------
// filter in place

// debugging scaffold
/** @cond dev */
#if defined(RYML_DBG) && 0
#define _c4dbgip(...) _c4dbgpf(__VA_ARGS__)
#else
#define _c4dbgip(...)
#endif
/** @endcond */

/** Filters in place. While the result may be larger than the source,
 * any extending happens only at the end of the string. Consequently,
 * it's impossible for characters to be left unfiltered.
 *
 * @see FilterProcessorInplaceMidExtending */
struct FilterProcessorInplaceEndExtending
{
    substr src;  ///< the subject string
    size_t wcap; ///< write capacity - the capacity of the subject string's buffer
    size_t rpos; ///< read position
    size_t wpos; ///< write position

    C4_ALWAYS_INLINE FilterProcessorInplaceEndExtending(substr src_, size_t wcap_) noexcept
        : src(src_)
        , wcap(wcap_)
        , rpos(0)
        , wpos(0)
    {
        RYML_ASSERT(wcap >= src.len);
    }

    C4_ALWAYS_INLINE void setwpos(size_t wpos_) noexcept { wpos = wpos_; }
    C4_ALWAYS_INLINE void setpos(size_t rpos_, size_t wpos_) noexcept { rpos = rpos_; wpos = wpos_; }
    C4_ALWAYS_INLINE void set_at_end() noexcept { skip(src.len - rpos); }

    C4_ALWAYS_INLINE bool has_more_chars() const noexcept { return rpos < src.len; }
    C4_ALWAYS_INLINE bool has_more_chars(size_t maxpos) const noexcept { RYML_ASSERT(maxpos <= src.len); return rpos < maxpos; }

    C4_ALWAYS_INLINE FilterResult result() const noexcept
    {
        _c4dbgip("inplace: wpos={} wcap={} small={}", wpos, wcap, wpos > rpos);
        FilterResult ret;
        ret.str.str = (wpos <= wcap) ? src.str : nullptr;
        ret.str.len = wpos;
        return ret;
    }
    C4_ALWAYS_INLINE csubstr sofar() const noexcept { return csubstr(src.str, wpos <= wcap ? wpos : wcap); }
    C4_ALWAYS_INLINE csubstr rem() const noexcept { return src.sub(rpos); }

    C4_ALWAYS_INLINE char curr() const noexcept { RYML_ASSERT(rpos < src.len); return src[rpos]; }
    C4_ALWAYS_INLINE char next() const noexcept { return rpos+1 < src.len ? src[rpos+1] : '\0'; }

    C4_ALWAYS_INLINE void skip() noexcept { ++rpos; }
    C4_ALWAYS_INLINE void skip(size_t num) noexcept { rpos += num; }

    void set_at(size_t pos, char c) noexcept
    {
        RYML_ASSERT(pos < wpos);
        const size_t save = wpos;
        wpos = pos;
        set(c);
        wpos = save;
    }
    void set(char c) noexcept
    {
        if(wpos < wcap)  // respect write-capacity
            src.str[wpos] = c;
        ++wpos;
    }
    void set(char c, size_t num) noexcept
    {
        RYML_ASSERT(num);
        if(wpos + num <= wcap)  // respect write-capacity
            memset(src.str + wpos, c, num);
        wpos += num;
    }

    void copy() noexcept
    {
        RYML_ASSERT(wpos <= rpos);
        RYML_ASSERT(rpos < src.len);
        if(wpos < wcap)  // respect write-capacity
            src.str[wpos] = src.str[rpos];
        ++rpos;
        ++wpos;
    }
    void copy(size_t num) noexcept
    {
        RYML_ASSERT(num);
        RYML_ASSERT(rpos+num <= src.len);
        RYML_ASSERT(wpos <= rpos);
        if(wpos + num <= wcap)  // respect write-capacity
        {
            if(wpos + num <= rpos) // there is no overlap
                memcpy(src.str + wpos, src.str + rpos, num);
            else                   // there is overlap
                memmove(src.str + wpos, src.str + rpos, num);
        }
        rpos += num;
        wpos += num;
    }

    void translate_esc(char c) noexcept
    {
        RYML_ASSERT(rpos + 2 <= src.len);
        RYML_ASSERT(wpos <= rpos);
        if(wpos < wcap) // respect write-capacity
            src.str[wpos] = c;
        rpos += 2; // add 1u to account for the escape character
        ++wpos;
    }

    void translate_esc_bulk(const char *C4_RESTRICT s, size_t nw, size_t nr) noexcept
    {
        RYML_ASSERT(nw > 0);
        RYML_ASSERT(nr > 0);
        RYML_ASSERT(nw <= nr + 1u);
        RYML_ASSERT(rpos+nr <= src.len);
        RYML_ASSERT(wpos <= rpos);
        const size_t wpos_next = wpos + nw;
        const size_t rpos_next = rpos + nr + 1u; // add 1u to account for the escape character
        RYML_ASSERT(wpos_next <= rpos_next);
        if(wpos_next <= wcap)
            memcpy(src.str + wpos, s, nw);
        rpos = rpos_next;
        wpos = wpos_next;
    }

    C4_ALWAYS_INLINE void translate_esc_extending(const char *C4_RESTRICT s, size_t nw, size_t nr) noexcept
    {
        translate_esc_bulk(s, nw, nr);
    }
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** Filters in place. The result may be larger than the source, and
 * extending may happen anywhere. As a result some characters may be
 * left unfiltered when there is no slack in the buffer and the
 * write-position would overlap the read-position. Consequently, it's
 * possible for characters to be left unfiltered. In YAML, this
 * happens only with double-quoted strings, and only with a small
 * number of escape sequences such as `\L` which is substituted by three
 * bytes. These escape sequences cause a call to translate_esc_extending()
 * which is the only entry point to this unfiltered situation.
 *
 * @see FilterProcessorInplaceMidExtending */
struct FilterProcessorInplaceMidExtending
{
    substr src;  ///< the subject string
    size_t wcap; ///< write capacity - the capacity of the subject string's buffer
    size_t rpos; ///< read position
    size_t wpos; ///< write position
    size_t maxcap; ///< the max capacity needed for filtering the string. This may be larger than the final string size.
    bool unfiltered_chars; ///< number of characters that were not added to wpos from lack of capacity

    C4_ALWAYS_INLINE FilterProcessorInplaceMidExtending(substr src_, size_t wcap_) noexcept
        : src(src_)
        , wcap(wcap_)
        , rpos(0)
        , wpos(0)
        , maxcap(src.len)
        , unfiltered_chars(false)
    {
        RYML_ASSERT(wcap >= src.len);
    }

    C4_ALWAYS_INLINE void setwpos(size_t wpos_) noexcept { wpos = wpos_; }
    C4_ALWAYS_INLINE void setpos(size_t rpos_, size_t wpos_) noexcept { rpos = rpos_; wpos = wpos_; }
    C4_ALWAYS_INLINE void set_at_end() noexcept { skip(src.len - rpos); }

    C4_ALWAYS_INLINE bool has_more_chars() const noexcept { return rpos < src.len; }
    C4_ALWAYS_INLINE bool has_more_chars(size_t maxpos) const noexcept { RYML_ASSERT(maxpos <= src.len); return rpos < maxpos; }

    C4_ALWAYS_INLINE FilterResultExtending result() const noexcept
    {
        _c4dbgip("inplace: wpos={} wcap={} unfiltered={} maxcap={}", this->wpos, this->wcap, this->unfiltered_chars, this->maxcap);
        FilterResultExtending ret;
        ret.str.str = (wpos <= wcap && !unfiltered_chars) ? src.str : nullptr;
        ret.str.len = wpos;
        ret.reqlen = maxcap;
        return ret;
    }
    C4_ALWAYS_INLINE csubstr sofar() const noexcept { return csubstr(src.str, wpos <= wcap ? wpos : wcap); }
    C4_ALWAYS_INLINE csubstr rem() const noexcept { return src.sub(rpos); }

    C4_ALWAYS_INLINE char curr() const noexcept { RYML_ASSERT(rpos < src.len); return src[rpos]; }
    C4_ALWAYS_INLINE char next() const noexcept { return rpos+1 < src.len ? src[rpos+1] : '\0'; }

    C4_ALWAYS_INLINE void skip() noexcept { ++rpos; }
    C4_ALWAYS_INLINE void skip(size_t num) noexcept { rpos += num; }

    void set_at(size_t pos, char c) noexcept
    {
        RYML_ASSERT(pos < wpos);
        const size_t save = wpos;
        wpos = pos;
        set(c);
        wpos = save;
    }
    void set(char c) noexcept
    {
        if(wpos < wcap)  // respect write-capacity
        {
            if((wpos <= rpos) && !unfiltered_chars)
                src.str[wpos] = c;
        }
        else
        {
            _c4dbgip("inplace: add unwritten {}->{}   maxcap={}->{}!", unfiltered_chars, true, maxcap, (wpos+1u > maxcap ? wpos+1u : maxcap));
            unfiltered_chars = true;
        }
        ++wpos;
        maxcap = wpos > maxcap ? wpos : maxcap;
    }
    void set(char c, size_t num) noexcept
    {
        RYML_ASSERT(num);
        if(wpos + num <= wcap)  // respect write-capacity
        {
            if((wpos <= rpos) && !unfiltered_chars)
                memset(src.str + wpos, c, num);
        }
        else
        {
            _c4dbgip("inplace: add unwritten {}->{}   maxcap={}->{}!", unfiltered_chars, true, maxcap, (wpos+num > maxcap ? wpos+num : maxcap));
            unfiltered_chars = true;
        }
        wpos += num;
        maxcap = wpos > maxcap ? wpos : maxcap;
    }

    void copy() noexcept
    {
        RYML_ASSERT(rpos < src.len);
        if(wpos < wcap)  // respect write-capacity
        {
            if((wpos < rpos) && !unfiltered_chars)  // write only if wpos is behind rpos
                src.str[wpos] = src.str[rpos];
        }
        else
        {
            _c4dbgip("inplace: add unwritten {}->{} (wpos={}!=rpos={})={}  (wpos={}<wcap={})   maxcap={}->{}!", unfiltered_chars, true, wpos, rpos, wpos!=rpos, wpos, wcap, wpos<wcap, maxcap, (wpos+1u > maxcap ? wpos+1u : maxcap));
            unfiltered_chars = true;
        }
        ++rpos;
        ++wpos;
        maxcap = wpos > maxcap ? wpos : maxcap;
    }
    void copy(size_t num) noexcept
    {
        RYML_ASSERT(num);
        RYML_ASSERT(rpos+num <= src.len);
        if(wpos + num <= wcap)  // respect write-capacity
        {
            if((wpos < rpos) && !unfiltered_chars)  // write only if wpos is behind rpos
            {
                if(wpos + num <= rpos) // there is no overlap
                    memcpy(src.str + wpos, src.str + rpos, num);
                else                   // there is overlap
                    memmove(src.str + wpos, src.str + rpos, num);
            }
        }
        else
        {
            _c4dbgip("inplace: add unwritten {}->{} (wpos={}!=rpos={})={}  (wpos={}<wcap={})  maxcap={}->{}!", unfiltered_chars, true, wpos, rpos, wpos!=rpos, wpos, wcap, wpos<wcap);
            unfiltered_chars = true;
        }
        rpos += num;
        wpos += num;
        maxcap = wpos > maxcap ? wpos : maxcap;
    }

    void translate_esc(char c) noexcept
    {
        RYML_ASSERT(rpos + 2 <= src.len);
        if(wpos < wcap) // respect write-capacity
        {
            if((wpos <= rpos) && !unfiltered_chars)
                src.str[wpos] = c;
        }
        else
        {
            _c4dbgip("inplace: add unfiltered {}->{}  maxcap={}->{}!", unfiltered_chars, true, maxcap, (wpos+1u > maxcap ? wpos+1u : maxcap));
            unfiltered_chars = true;
        }
        rpos += 2;
        ++wpos;
        maxcap = wpos > maxcap ? wpos : maxcap;
    }

    C4_NO_INLINE void translate_esc_bulk(const char *C4_RESTRICT s, size_t nw, size_t nr) noexcept
    {
        RYML_ASSERT(nw > 0);
        RYML_ASSERT(nr > 0);
        RYML_ASSERT(nr+1u >= nw);
        const size_t wpos_next = wpos + nw;
        const size_t rpos_next = rpos + nr + 1u; // add 1u to account for the escape character
        if(wpos_next <= wcap)  // respect write-capacity
        {
            if((wpos <= rpos) && !unfiltered_chars)  // write only if wpos is behind rpos
                memcpy(src.str + wpos, s, nw);
        }
        else
        {
            _c4dbgip("inplace: add unwritten {}->{} (wpos={}!=rpos={})={}  (wpos={}<wcap={})  maxcap={}->{}!", unfiltered_chars, true, wpos, rpos, wpos!=rpos, wpos, wcap, wpos<wcap);
            unfiltered_chars = true;
        }
        rpos = rpos_next;
        wpos = wpos_next;
        maxcap = wpos > maxcap ? wpos : maxcap;
    }

    C4_NO_INLINE void translate_esc_extending(const char *C4_RESTRICT s, size_t nw, size_t nr) noexcept
    {
        RYML_ASSERT(nw > 0);
        RYML_ASSERT(nr > 0);
        RYML_ASSERT(rpos+nr <= src.len);
        const size_t wpos_next = wpos + nw;
        const size_t rpos_next = rpos + nr + 1u; // add 1u to account for the escape character
        if(wpos_next <= rpos_next) // read and write do not overlap. just do a vanilla copy.
        {
            if((wpos_next <= wcap) && !unfiltered_chars)
                memcpy(src.str + wpos, s, nw);
            rpos = rpos_next;
            wpos = wpos_next;
            maxcap = wpos > maxcap ? wpos : maxcap;
        }
        else // there is overlap. move the (to-be-read) string to the right.
        {
            const size_t excess = wpos_next - rpos_next;
            RYML_ASSERT(wpos_next > rpos_next);
            if(src.len + excess <= wcap) // ensure we do not go past the end
            {
                RYML_ASSERT(rpos+nr+excess <= src.len);
                if(wpos_next <= wcap)
                {
                    if(!unfiltered_chars)
                    {
                        memmove(src.str + wpos_next, src.str + rpos_next, src.len - rpos_next);
                        memcpy(src.str + wpos, s, nw);
                    }
                    rpos = wpos_next; // wpos, not rpos
                }
                else
                {
                    rpos = rpos_next;
                    //const size_t unw = nw > (nr + 1u) ? nw - (nr + 1u) : 0;
                    _c4dbgip("inplace: add unfiltered {}->{}   maxcap={}->{}!", unfiltered_chars, true);
                    unfiltered_chars = true;
                }
                wpos = wpos_next;
                // extend the string up to capacity
                src.len += excess;
                maxcap = wpos > maxcap ? wpos : maxcap;
            }
            else
            {
                //const size_t unw = nw > (nr + 1u) ? nw - (nr + 1u) : 0;
                RYML_ASSERT(rpos_next <= src.len);
                const size_t required_size = wpos_next + (src.len - rpos_next);
                _c4dbgip("inplace: add unfiltered {}->{}   maxcap={}->{}!", unfiltered_chars, true, maxcap, required_size > maxcap ? required_size : maxcap);
                RYML_ASSERT(required_size > wcap);
                unfiltered_chars = true;
                maxcap = required_size > maxcap ? required_size : maxcap;
                wpos = wpos_next;
                rpos = rpos_next;
            }
        }
    }
};

#undef _c4dbgip


/** @} */

} // namespace yml
} // namespace c4

#endif /* _C4_YML_FILTER_PROCESSOR_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/filter_processor.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/parser_state.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/parser_state.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_PARSER_STATE_HPP_
#define _C4_YML_PARSER_STATE_HPP_

#ifndef _C4_YML_COMMON_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/common.hpp
//#include "c4/yml/common.hpp"
#if !defined(C4_YML_COMMON_HPP_) && !defined(_C4_YML_COMMON_HPP_)
#error "amalgamate: file c4/yml/common.hpp must have been included at this point"
#endif /* C4_YML_COMMON_HPP_ */

#endif

namespace c4 {
namespace yml {

/** data type for @ref ParserState_e */
using ParserFlag_t = int;

/** Enumeration of the state flags for the parser */
typedef enum : ParserFlag_t {
    RTOP = 0x01 <<  0,   ///< reading at top level
    RUNK = 0x01 <<  1,   ///< reading unknown state (when starting): must determine whether scalar, map or seq
    RMAP = 0x01 <<  2,   ///< reading a map
    RSEQ = 0x01 <<  3,   ///< reading a seq
    FLOW = 0x01 <<  4,   ///< reading is inside explicit flow chars: [] or {}
    BLCK = 0x01 <<  5,   ///< reading in block mode
    QMRK = 0x01 <<  6,   ///< reading an explicit key (`? key`)
    RKEY = 0x01 <<  7,   ///< reading a scalar as key
    RVAL = 0x01 <<  9,   ///< reading a scalar as val
    RKCL = 0x01 <<  8,   ///< reading the key colon (ie the : after the key in the map)
    RNXT = 0x01 << 10,   ///< read next val or keyval
    SSCL = 0x01 << 11,   ///< there's a stored scalar
    QSCL = 0x01 << 12,   ///< stored scalar was quoted
    RSET = 0x01 << 13,   ///< the (implicit) map being read is a !!set. @see https://yaml.org/type/set.html
    RDOC = 0x01 << 14,   ///< reading a document
    NDOC = 0x01 << 15,   ///< no document mode. a document has ended and another has not started yet.
    USTY = 0x01 << 16,   ///< reading in unknown style mode - must determine FLOW or BLCK
    //! reading an implicit map nested in an explicit seq.
    //! eg, {key: [key2: value2, key3: value3]}
    //! is parsed as {key: [{key2: value2}, {key3: value3}]}
    RSEQIMAP = 0x01 << 17,
} ParserState_e;

#ifdef RYML_DBG
/** @cond dev */
namespace detail {
csubstr _parser_flags_to_str(substr buf, ParserFlag_t flags);
} // namespace
/** @endcond */
#endif


/** Helper to control the line contents while parsing a buffer */
struct LineContents
{
    substr  rem;         ///< the stripped line remainder; initially starts at the first non-space character
    size_t  indentation; ///< the number of spaces on the beginning of the line
    substr  full;        ///< the full line, including newlines on the right
    substr  stripped;    ///< the stripped line, excluding newlines on the right

    LineContents() = default;

    void reset_with_next_line(substr buf, size_t offset)
    {
        RYML_ASSERT(offset <= buf.len);
        size_t e = offset;
        // get the current line stripped of newline chars
        while(e < buf.len && (buf.str[e] != '\n' && buf.str[e] != '\r'))
            ++e;
        RYML_ASSERT(e >= offset);
        const substr stripped_ = buf.range(offset, e);
        // advance pos to include the first line ending
        if(e < buf.len && buf.str[e] == '\r')
            ++e;
        if(e < buf.len && buf.str[e] == '\n')
            ++e;
        const substr full_ = buf.range(offset, e);
        reset(full_, stripped_);
    }

    void reset(substr full_, substr stripped_)
    {
        rem = stripped_;
        indentation = stripped_.first_not_of(' ');  // find the first column where the character is not a space
        full = full_;
        stripped = stripped_;
    }

    C4_ALWAYS_INLINE size_t current_col() const RYML_NOEXCEPT
    {
        // WARNING: gcc x86 release builds were wrong (eg returning 0
        // when the result should be 4 ) when this function was like
        // this:
        //
        //return current_col(rem);
        //
        // (see below for the full definition of the called overload
        // of current_col())
        //
        // ... so we explicitly inline the code in here:
        RYML_ASSERT(rem.str >= full.str);
        size_t col = static_cast<size_t>(rem.str - full.str);
        return col;
        //
        // this was happening only on builds specifically with (gcc
        // AND x86 AND release); no other builds were having the
        // problem: not in debug, not in x64, not in other
        // architectures, not in clang, not in visual studio. WTF!?
        //
        // Enabling debug prints with RYML_DBG made the problem go
        // away, so these could not be used to debug the
        // problem. Adding prints inside the called current_col() also
        // made the problem go away! WTF!???
        //
        // a prize will be offered to anybody able to explain why this
        // was happening.
    }

    C4_ALWAYS_INLINE size_t current_col(csubstr s) const RYML_NOEXCEPT
    {
        RYML_ASSERT(s.str >= full.str);
        RYML_ASSERT(full.is_super(s));
        size_t col = static_cast<size_t>(s.str - full.str);
        return col;
    }
};
static_assert(std::is_standard_layout<LineContents>::value, "LineContents not standard");


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

struct ParserState
{
    LineContents line_contents;
    Location     pos;
    ParserFlag_t flags;
    size_t       indref;  ///< the reference indentation in the current block scope
    id_type      level;
    id_type      node_id; ///< don't hold a pointer to the node as it will be relocated during tree resizes
    size_t       scalar_col; // the column where the scalar (or its quotes) begin
    bool         more_indented;
    bool         has_children;

    ParserState() = default;

    void start_parse(const char *file, id_type node_id_)
    {
        level = 0;
        pos.name = to_csubstr(file);
        pos.offset = 0;
        pos.line = 1;
        pos.col = 1;
        node_id = node_id_;
        more_indented = false;
        scalar_col = 0;
        indref = 0;
        has_children = false;
    }

    void reset_after_push()
    {
        node_id = NONE;
        indref = npos;
        more_indented = false;
        ++level;
        has_children = false;
    }

    C4_ALWAYS_INLINE void reset_before_pop(ParserState const& to_pop)
    {
        pos = to_pop.pos;
        line_contents = to_pop.line_contents;
    }

public:

    C4_ALWAYS_INLINE bool at_line_beginning() const noexcept
    {
        return line_contents.rem.str == line_contents.full.str;
    }
    C4_ALWAYS_INLINE bool indentation_eq() const noexcept
    {
        RYML_ASSERT(indref != npos);
        return line_contents.indentation != npos && line_contents.indentation == indref;
    }
    C4_ALWAYS_INLINE bool indentation_ge() const noexcept
    {
        RYML_ASSERT(indref != npos);
        return line_contents.indentation != npos && line_contents.indentation >= indref;
    }
    C4_ALWAYS_INLINE bool indentation_gt() const noexcept
    {
        RYML_ASSERT(indref != npos);
        return line_contents.indentation != npos && line_contents.indentation > indref;
    }
    C4_ALWAYS_INLINE bool indentation_lt() const noexcept
    {
        RYML_ASSERT(indref != npos);
        return line_contents.indentation != npos && line_contents.indentation < indref;
    }
};
static_assert(std::is_standard_layout<ParserState>::value, "ParserState not standard");


} // namespace yml
} // namespace c4

#endif /* _C4_YML_PARSER_STATE_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/parser_state.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/event_handler_stack.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/event_handler_stack.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_EVENT_HANDLER_STACK_HPP_
#define _C4_YML_EVENT_HANDLER_STACK_HPP_

#ifndef _C4_YML_DETAIL_STACK_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/stack.hpp
//#include "c4/yml/detail/stack.hpp"
#if !defined(C4_YML_DETAIL_STACK_HPP_) && !defined(_C4_YML_DETAIL_STACK_HPP_)
#error "amalgamate: file c4/yml/detail/stack.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_STACK_HPP_ */

#endif

#ifndef _C4_YML_DETAIL_PARSER_DBG_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/parser_dbg.hpp
//#include "c4/yml/detail/parser_dbg.hpp"
#if !defined(C4_YML_DETAIL_PARSER_DBG_HPP_) && !defined(_C4_YML_DETAIL_PARSER_DBG_HPP_)
#error "amalgamate: file c4/yml/detail/parser_dbg.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PARSER_DBG_HPP_ */

#endif

#ifndef _C4_YML_PARSER_STATE_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/parser_state.hpp
//#include "c4/yml/parser_state.hpp"
#if !defined(C4_YML_PARSER_STATE_HPP_) && !defined(_C4_YML_PARSER_STATE_HPP_)
#error "amalgamate: file c4/yml/parser_state.hpp must have been included at this point"
#endif /* C4_YML_PARSER_STATE_HPP_ */

#endif

#ifdef RYML_DBG
#ifndef _C4_YML_DETAIL_PRINT_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/print.hpp
//#include "c4/yml/detail/print.hpp"
#if !defined(C4_YML_DETAIL_PRINT_HPP_) && !defined(_C4_YML_DETAIL_PRINT_HPP_)
#error "amalgamate: file c4/yml/detail/print.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PRINT_HPP_ */

#endif
#endif

namespace c4 {
namespace yml {

/** @addtogroup doc_event_handlers
 * @{ */

namespace detail {
using pfn_relocate_arena = void (*)(void*, csubstr prev_arena, substr next_arena);
} // detail

/** Use this class a base of implementations of event handler to
 * simplify the stack logic. */
template<class HandlerImpl, class HandlerState>
struct EventHandlerStack
{
    static_assert(std::is_base_of<ParserState, HandlerState>::value,
                  "ParserState must be a base of HandlerState");

    using state = HandlerState;
    using pfn_relocate_arena = detail::pfn_relocate_arena;

public:

    detail::stack<state> m_stack;
    state *C4_RESTRICT   m_curr;    ///< current stack level: top of the stack. cached here for easier access.
    state *C4_RESTRICT   m_parent;  ///< parent of the current stack level.
    pfn_relocate_arena   m_relocate_arena; ///< callback when the arena gets relocated
    void *               m_relocate_arena_data;

protected:

    EventHandlerStack() : m_stack(), m_curr(), m_parent(), m_relocate_arena(), m_relocate_arena_data() {}
    EventHandlerStack(Callbacks const& cb) : m_stack(cb), m_curr(), m_parent(), m_relocate_arena(), m_relocate_arena_data() {}

protected:

    void _stack_start_parse(const char *filename, pfn_relocate_arena relocate_arena, void *relocate_arena_data)
    {
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_curr != nullptr);
        _RYML_CB_ASSERT(m_stack.m_callbacks, relocate_arena != nullptr);
        _RYML_CB_ASSERT(m_stack.m_callbacks, relocate_arena_data != nullptr);
        m_curr->start_parse(filename, m_curr->node_id);
        m_relocate_arena = relocate_arena;
        m_relocate_arena_data = relocate_arena_data;
    }

    void _stack_finish_parse()
    {
    }

protected:

    void _stack_reset_root()
    {
        m_stack.clear();
        m_stack.push({});
        m_parent = nullptr;
        m_curr = &m_stack.top();
    }

    void _stack_reset_non_root()
    {
        m_stack.clear();
        m_stack.push({}); // parent
        m_stack.push({}); // node
        m_parent = &m_stack.top(1);
        m_curr = &m_stack.top();
    }

    void _stack_push()
    {
        m_stack.push_top();
        m_parent = &m_stack.top(1); // don't use m_curr. watch out for relocations inside the prev push
        m_curr = &m_stack.top();
        m_curr->reset_after_push();
    }

    void _stack_pop()
    {
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_parent);
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_stack.size() > 1);
        m_parent->reset_before_pop(*m_curr);
        m_stack.pop();
        m_parent = m_stack.size() > 1 ? &m_stack.top(1) : nullptr;
        m_curr = &m_stack.top();
        #ifdef RYML_DBG
        if(m_parent)
            _c4dbgpf("popped! top is now node={} (parent={})", m_curr->node_id, m_parent->node_id);
        else
            _c4dbgpf("popped! top is now node={} @ ROOT", m_curr->node_id);
        #endif
    }

protected:

    // undefined at the end
    #define _has_any_(bits) (static_cast<HandlerImpl const* C4_RESTRICT>(this)->template _has_any__<bits>())

    bool _stack_should_push_on_begin_doc() const
    {
        const bool is_root = (m_stack.size() == 1u);
        return is_root && (_has_any_(DOC|VAL|MAP|SEQ) || m_curr->has_children);
    }

    bool _stack_should_pop_on_end_doc() const
    {
        const bool is_root = (m_stack.size() == 1u);
        return !is_root && _has_any_(DOC);
    }

protected:

    void _stack_relocate_to_new_arena(csubstr prev, substr curr)
    {
        for(state &st : m_stack)
        {
            if(st.line_contents.rem.is_sub(prev))
                st.line_contents.rem = _stack_relocate_to_new_arena(st.line_contents.rem, prev, curr);
            if(st.line_contents.full.is_sub(prev))
                st.line_contents.full = _stack_relocate_to_new_arena(st.line_contents.full, prev, curr);
            if(st.line_contents.stripped.is_sub(prev))
                st.line_contents.stripped = _stack_relocate_to_new_arena(st.line_contents.stripped, prev, curr);
        }
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_relocate_arena != nullptr);
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_relocate_arena_data != nullptr);
        m_relocate_arena(m_relocate_arena_data, prev, curr);
    }

    substr _stack_relocate_to_new_arena(csubstr s, csubstr prev, substr curr)
    {
        _RYML_CB_ASSERT(m_stack.m_callbacks, prev.is_super(s));
        auto pos = s.str - prev.str;
        substr out = {curr.str + pos, s.len};
        _RYML_CB_ASSERT(m_stack.m_callbacks, curr.is_super(out));
        return out;
    }

public:

    /** Check whether the current parse tokens are trailing on the
     * previous doc, and raise an error if they are. This function is
     * called by the parse engine (not the event handler) before a doc
     * is started. */
    void check_trailing_doc_token() const
    {
        const bool is_root = (m_stack.size() == 1u);
        const bool isndoc = (m_curr->flags & NDOC) != 0;
        const bool suspicious = _has_any_(MAP|SEQ|VAL);
        _c4dbgpf("target={} isroot={} suspicious={} ndoc={}", m_curr->node_id, is_root, suspicious, isndoc);
        if((is_root || _has_any_(DOC)) && suspicious && !isndoc)
            _RYML_CB_ERR_(m_stack.m_callbacks, "parse error", m_curr->pos);
    }

protected:

    #undef _has_any_

};

/** @} */

} // namespace yml
} // namespace c4

#endif /* _C4_YML_EVENT_HANDLER_STACK_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/event_handler_stack.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/event_handler_tree.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/event_handler_tree.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_EVENT_HANDLER_TREE_HPP_
#define _C4_YML_EVENT_HANDLER_TREE_HPP_

#ifndef _C4_YML_TREE_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/tree.hpp
//#include "c4/yml/tree.hpp"
#if !defined(C4_YML_TREE_HPP_) && !defined(_C4_YML_TREE_HPP_)
#error "amalgamate: file c4/yml/tree.hpp must have been included at this point"
#endif /* C4_YML_TREE_HPP_ */

#endif

#ifndef _C4_YML_EVENT_HANDLER_STACK_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/event_handler_stack.hpp
//#include "c4/yml/event_handler_stack.hpp"
#if !defined(C4_YML_EVENT_HANDLER_STACK_HPP_) && !defined(_C4_YML_EVENT_HANDLER_STACK_HPP_)
#error "amalgamate: file c4/yml/event_handler_stack.hpp must have been included at this point"
#endif /* C4_YML_EVENT_HANDLER_STACK_HPP_ */

#endif

C4_SUPPRESS_WARNING_MSVC_WITH_PUSH(4702) // unreachable code

namespace c4 {
namespace yml {

/** @addtogroup doc_event_handlers
 * @{ */


/** The stack state needed specifically by @ref EventHandlerTree */
struct EventHandlerTreeState : public ParserState
{
    NodeData *tr_data;
};


/** The event handler to create a ryml @ref Tree. See the
 * documentation for @ref doc_event_handlers, which has important
 * notes about the event model used by rapidyaml. */
struct EventHandlerTree : public EventHandlerStack<EventHandlerTree, EventHandlerTreeState>
{

    /** @name types
     * @{ */

    using state = EventHandlerTreeState;

    /** @} */

public:

    /** @cond dev */
    Tree *C4_RESTRICT m_tree;
    id_type m_id;
    size_t m_num_directives;
    bool m_yaml_directive;

    #if RYML_DBG
    #define _enable_(bits) _enable__<bits>(); _c4dbgpf("node[{}]: enable {}", m_curr->node_id, #bits)
    #define _disable_(bits) _disable__<bits>(); _c4dbgpf("node[{}]: disable {}", m_curr->node_id, #bits)
    #else
    #define _enable_(bits) _enable__<bits>()
    #define _disable_(bits) _disable__<bits>()
    #endif
    #define _has_any_(bits) _has_any__<bits>()
    /** @endcond */

public:

    /** @name construction and resetting
     * @{ */

    EventHandlerTree() : EventHandlerStack(), m_tree(), m_id(NONE), m_num_directives(), m_yaml_directive() {}
    EventHandlerTree(Callbacks const& cb) : EventHandlerStack(cb), m_tree(), m_id(NONE), m_num_directives(), m_yaml_directive() {}
    EventHandlerTree(Tree *tree, id_type id) : EventHandlerStack(tree->callbacks()), m_tree(tree), m_id(id), m_num_directives(), m_yaml_directive()
    {
        reset(tree, id);
    }

    void reset(Tree *tree, id_type id)
    {
        if(C4_UNLIKELY(!tree))
            _RYML_CB_ERR(m_stack.m_callbacks, "null tree");
        if(C4_UNLIKELY(id >= tree->capacity()))
            _RYML_CB_ERR(tree->callbacks(), "invalid node");
        if(C4_UNLIKELY(!tree->is_root(id)))
            if(C4_UNLIKELY(tree->is_map(tree->parent(id))))
                if(C4_UNLIKELY(!tree->has_key(id)))
                    _RYML_CB_ERR(tree->callbacks(), "destination node belongs to a map and has no key");
        m_tree = tree;
        m_id = id;
        if(m_tree->is_root(id))
        {
            _stack_reset_root();
            _reset_parser_state(m_curr, id, m_tree->root_id());
        }
        else
        {
            _stack_reset_non_root();
            _reset_parser_state(m_parent, id, m_tree->parent(id));
            _reset_parser_state(m_curr, id, id);
        }
        m_num_directives = 0;
        m_yaml_directive = false;
    }

    /** @} */

public:

    /** @name parse events
     * @{ */

    void start_parse(const char* filename, detail::pfn_relocate_arena relocate_arena, void *relocate_arena_data)
    {
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree != nullptr);
        this->_stack_start_parse(filename, relocate_arena, relocate_arena_data);
    }

    void finish_parse()
    {
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree != nullptr);
        if(m_num_directives && !m_tree->is_stream(m_tree->root_id()))
            _RYML_CB_ERR_(m_stack.m_callbacks, "directives cannot be used without a document", {});
        this->_stack_finish_parse();
        /* This pointer is temporary. Remember that:
         *
         * - this handler object may be held by the user
         * - it may be used with a temporary tree inside the parse function
         * - when the parse function returns the temporary tree, its address
         *   will change
         *
         * As a result, the user could try to read the tree from m_tree, and
         * end up reading the stale temporary object.
         *
         * So it is better to clear it here; then the user will get an obvious
         * segfault if reading from m_tree. */
        m_tree = nullptr;
    }

    void cancel_parse()
    {
        m_tree = nullptr;
    }

    /** @} */

public:

    /** @name YAML stream events */
    /** @{ */

    C4_ALWAYS_INLINE void begin_stream() const noexcept { /*nothing to do*/ }

    C4_ALWAYS_INLINE void end_stream() const noexcept { /*nothing to do*/ }

    /** @} */

public:

    /** @name YAML document events */
    /** @{ */

    /** implicit doc start (without ---) */
    void begin_doc()
    {
        _c4dbgp("begin_doc");
        if(_stack_should_push_on_begin_doc())
        {
            _c4dbgp("push!");
            _set_root_as_stream();
            _push();
            _enable_(DOC);
        }
    }
    /** implicit doc end (without ...) */
    void end_doc()
    {
        _c4dbgp("end_doc");
        if(_stack_should_pop_on_end_doc())
        {
            _remove_speculative();
            _c4dbgp("pop!");
            _pop();
        }
    }

    /** explicit doc start, with --- */
    void begin_doc_expl()
    {
        _c4dbgp("begin_doc_expl");
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree->root_id() == m_curr->node_id);
        if(!m_tree->is_stream(m_tree->root_id())) //if(_should_push_on_begin_doc())
        {
            _c4dbgp("ensure stream");
            _set_root_as_stream();
            id_type first = m_tree->first_child(m_tree->root_id());
            _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree->is_stream(m_tree->root_id()));
            _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree->num_children(m_tree->root_id()) == 1u);
            if(m_tree->has_children(first) || m_tree->is_val(first))
            {
                _c4dbgp("push!");
                _push();
            }
            else
            {
                _c4dbgp("tweak");
                _push();
                _remove_speculative();
                m_curr->node_id = m_tree->last_child(m_tree->root_id());
                m_curr->tr_data = m_tree->_p(m_curr->node_id);
            }
        }
        else
        {
            _c4dbgp("push!");
            _push();
        }
        _enable_(DOC);
    }
    /** explicit doc end, with ... */
    void end_doc_expl()
    {
        _c4dbgp("end_doc_expl");
        _remove_speculative();
        if(_stack_should_pop_on_end_doc())
        {
            _c4dbgp("pop!");
            _pop();
        }
        m_yaml_directive = false;
    }

    /** @} */

public:

    /** @name YAML map events */
    /** @{ */

    void begin_map_key_flow()
    {
        _RYML_CB_ERR_(m_stack.m_callbacks, "ryml trees cannot handle containers as keys", m_curr->pos);
    }
    void begin_map_key_block()
    {
        _RYML_CB_ERR_(m_stack.m_callbacks, "ryml trees cannot handle containers as keys", m_curr->pos);
    }

    void begin_map_val_flow()
    {
        _c4dbgpf("node[{}]: begin_map_val_flow", m_curr->node_id);
        _RYML_CB_CHECK(m_stack.m_callbacks, !_has_any_(VAL));
        _enable_(MAP|FLOW_SL);
        _save_loc();
        _push();
    }
    void begin_map_val_block()
    {
        _c4dbgpf("node[{}]: begin_map_val_block", m_curr->node_id);
        _RYML_CB_CHECK(m_stack.m_callbacks, !_has_any_(VAL));
        _enable_(MAP|BLOCK);
        _save_loc();
        _push();
    }

    void end_map()
    {
        _pop();
        _c4dbgpf("node[{}]: end_map_val", m_curr->node_id);
    }

    /** @} */

public:

    /** @name YAML seq events */
    /** @{ */

    void begin_seq_key_flow()
    {
        _RYML_CB_ERR_(m_stack.m_callbacks, "ryml trees cannot handle containers as keys", m_curr->pos);
    }
    void begin_seq_key_block()
    {
        _RYML_CB_ERR_(m_stack.m_callbacks, "ryml trees cannot handle containers as keys", m_curr->pos);
    }

    void begin_seq_val_flow()
    {
        _c4dbgpf("node[{}]: begin_seq_val_flow", m_curr->node_id);
        _RYML_CB_CHECK(m_stack.m_callbacks, !_has_any_(VAL));
        _enable_(SEQ|FLOW_SL);
        _save_loc();
        _push();
    }
    void begin_seq_val_block()
    {
        _c4dbgpf("node[{}]: begin_seq_val_block", m_curr->node_id);
        _RYML_CB_CHECK(m_stack.m_callbacks, !_has_any_(VAL));
        _enable_(SEQ|BLOCK);
        _save_loc();
        _push();
    }

    void end_seq()
    {
        _pop();
        _c4dbgpf("node[{}]: end_seq_val", m_curr->node_id);
    }

    /** @} */

public:

    /** @name YAML structure events */
    /** @{ */

    void add_sibling()
    {
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree);
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_parent);
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree->has_children(m_parent->node_id));
        NodeData const* prev = m_tree->m_buf; // watchout against relocation of the tree nodes
        _set_state_(m_curr, m_tree->_append_child__unprotected(m_parent->node_id));
        if(prev != m_tree->m_buf)
            _refresh_after_relocation();
        _c4dbgpf("node[{}]: added sibling={} prev={}", m_parent->node_id, m_curr->node_id, m_tree->prev_sibling(m_curr->node_id));
    }

    /** set the previous val as the first key of a new map, with flow style.
     *
     * See the documentation for @ref doc_event_handlers, which has
     * important notes about this event.
     */
    void actually_val_is_first_key_of_new_map_flow()
    {
        if(C4_UNLIKELY(m_tree->is_container(m_curr->node_id)))
            _RYML_CB_ERR_(m_stack.m_callbacks, "ryml trees cannot handle containers as keys", m_curr->pos);
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_parent);
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree->is_seq(m_parent->node_id));
        _RYML_CB_ASSERT(m_stack.m_callbacks, !m_tree->is_container(m_curr->node_id));
        _RYML_CB_ASSERT(m_stack.m_callbacks, !m_tree->has_key(m_curr->node_id));
        const NodeData tmp = _val2key_(*m_curr->tr_data);
        _disable_(_VALMASK|VAL_STYLE);
        m_curr->tr_data->m_val = {};
        begin_map_val_flow();
        m_curr->tr_data->m_type = tmp.m_type;
        m_curr->tr_data->m_key = tmp.m_key;
    }

    /** like its flow counterpart, but this function can only be
     * called after the end of a flow-val at root or doc level.
     *
     * See the documentation for @ref doc_event_handlers, which has
     * important notes about this event.
     */
    void actually_val_is_first_key_of_new_map_block()
    {
        _RYML_CB_ERR_(m_stack.m_callbacks, "ryml trees cannot handle containers as keys", m_curr->pos);
    }

    /** @} */

public:

    /** @name YAML scalar events */
    /** @{ */


    C4_ALWAYS_INLINE void set_key_scalar_plain(csubstr scalar) noexcept
    {
        _c4dbgpf("node[{}]: set key scalar plain: [{}]~~~{}~~~ ({})", m_curr->node_id, scalar.len, scalar, reinterpret_cast<void const*>(scalar.str));
        m_curr->tr_data->m_key.scalar = scalar;
        _enable_(KEY|KEY_PLAIN);
    }
    C4_ALWAYS_INLINE void set_val_scalar_plain(csubstr scalar) noexcept
    {
        _c4dbgpf("node[{}]: set val scalar plain: [{}]~~~{}~~~ ({})", m_curr->node_id, scalar.len, scalar, reinterpret_cast<void const*>(scalar.str));
        m_curr->tr_data->m_val.scalar = scalar;
        _enable_(VAL|VAL_PLAIN);
    }


    C4_ALWAYS_INLINE void set_key_scalar_dquoted(csubstr scalar) noexcept
    {
        _c4dbgpf("node[{}]: set key scalar dquot: [{}]~~~{}~~~ ({})", m_curr->node_id, scalar.len, scalar, reinterpret_cast<void const*>(scalar.str));
        m_curr->tr_data->m_key.scalar = scalar;
        _enable_(KEY|KEY_DQUO);
    }
    C4_ALWAYS_INLINE void set_val_scalar_dquoted(csubstr scalar) noexcept
    {
        _c4dbgpf("node[{}]: set val scalar dquot: [{}]~~~{}~~~ ({})", m_curr->node_id, scalar.len, scalar, reinterpret_cast<void const*>(scalar.str));
        m_curr->tr_data->m_val.scalar = scalar;
        _enable_(VAL|VAL_DQUO);
    }


    C4_ALWAYS_INLINE void set_key_scalar_squoted(csubstr scalar) noexcept
    {
        _c4dbgpf("node[{}]: set key scalar squot: [{}]~~~{}~~~ ({})", m_curr->node_id, scalar.len, scalar, reinterpret_cast<void const*>(scalar.str));
        m_curr->tr_data->m_key.scalar = scalar;
        _enable_(KEY|KEY_SQUO);
    }
    C4_ALWAYS_INLINE void set_val_scalar_squoted(csubstr scalar) noexcept
    {
        _c4dbgpf("node[{}]: set val scalar squot: [{}]~~~{}~~~ ({})", m_curr->node_id, scalar.len, scalar, reinterpret_cast<void const*>(scalar.str));
        m_curr->tr_data->m_val.scalar = scalar;
        _enable_(VAL|VAL_SQUO);
    }


    C4_ALWAYS_INLINE void set_key_scalar_literal(csubstr scalar) noexcept
    {
        _c4dbgpf("node[{}]: set key scalar literal: [{}]~~~{}~~~ ({})", m_curr->node_id, scalar.len, scalar, reinterpret_cast<void const*>(scalar.str));
        m_curr->tr_data->m_key.scalar = scalar;
        _enable_(KEY|KEY_LITERAL);
    }
    C4_ALWAYS_INLINE void set_val_scalar_literal(csubstr scalar) noexcept
    {
        _c4dbgpf("node[{}]: set val scalar literal: [{}]~~~{}~~~ ({})", m_curr->node_id, scalar.len, scalar, reinterpret_cast<void const*>(scalar.str));
        m_curr->tr_data->m_val.scalar = scalar;
        _enable_(VAL|VAL_LITERAL);
    }


    C4_ALWAYS_INLINE void set_key_scalar_folded(csubstr scalar) noexcept
    {
        _c4dbgpf("node[{}]: set key scalar folded: [{}]~~~{}~~~ ({})", m_curr->node_id, scalar.len, scalar, reinterpret_cast<void const*>(scalar.str));
        m_curr->tr_data->m_key.scalar = scalar;
        _enable_(KEY|KEY_FOLDED);
    }
    C4_ALWAYS_INLINE void set_val_scalar_folded(csubstr scalar) noexcept
    {
        _c4dbgpf("node[{}]: set val scalar folded: [{}]~~~{}~~~ ({})", m_curr->node_id, scalar.len, scalar, reinterpret_cast<void const*>(scalar.str));
        m_curr->tr_data->m_val.scalar = scalar;
        _enable_(VAL|VAL_FOLDED);
    }


    C4_ALWAYS_INLINE void mark_key_scalar_unfiltered() noexcept
    {
        _enable_(KEY_UNFILT);
    }
    C4_ALWAYS_INLINE void mark_val_scalar_unfiltered() noexcept
    {
        _enable_(VAL_UNFILT);
    }

    /** @} */

public:

    /** @name YAML anchor/reference events */
    /** @{ */

    void set_key_anchor(csubstr anchor)
    {
        _c4dbgpf("node[{}]: set key anchor: [{}]~~~{}~~~", m_curr->node_id, anchor.len, anchor);
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree);
        if(C4_UNLIKELY(_has_any_(KEYREF)))
            _RYML_CB_ERR_(m_tree->callbacks(), "key cannot have both anchor and ref", m_curr->pos);
        _RYML_CB_ASSERT(m_tree->callbacks(), !anchor.begins_with('&'));
        _enable_(KEYANCH);
        m_curr->tr_data->m_key.anchor = anchor;
    }
    void set_val_anchor(csubstr anchor)
    {
        _c4dbgpf("node[{}]: set val anchor: [{}]~~~{}~~~", m_curr->node_id, anchor.len, anchor);
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree);
        if(C4_UNLIKELY(_has_any_(VALREF)))
            _RYML_CB_ERR_(m_tree->callbacks(), "val cannot have both anchor and ref", m_curr->pos);
        _RYML_CB_ASSERT(m_tree->callbacks(), !anchor.begins_with('&'));
        _enable_(VALANCH);
        m_curr->tr_data->m_val.anchor = anchor;
    }

    void set_key_ref(csubstr ref)
    {
        _c4dbgpf("node[{}]: set key ref: [{}]~~~{}~~~", m_curr->node_id, ref.len, ref);
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree);
        if(C4_UNLIKELY(_has_any_(KEYANCH)))
            _RYML_CB_ERR_(m_tree->callbacks(), "key cannot have both anchor and ref", m_curr->pos);
        _RYML_CB_ASSERT(m_tree->callbacks(), ref.begins_with('*'));
        _enable_(KEY|KEYREF);
        m_curr->tr_data->m_key.anchor = ref.sub(1);
        m_curr->tr_data->m_key.scalar = ref;
    }
    void set_val_ref(csubstr ref)
    {
        _c4dbgpf("node[{}]: set val ref: [{}]~~~{}~~~", m_curr->node_id, ref.len, ref);
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree);
        if(C4_UNLIKELY(_has_any_(VALANCH)))
            _RYML_CB_ERR_(m_tree->callbacks(), "val cannot have both anchor and ref", m_curr->pos);
        _RYML_CB_ASSERT(m_tree->callbacks(), ref.begins_with('*'));
        _enable_(VAL|VALREF);
        m_curr->tr_data->m_val.anchor = ref.sub(1);
        m_curr->tr_data->m_val.scalar = ref;
    }

    /** @} */

public:

    /** @name YAML tag events */
    /** @{ */

    void set_key_tag(csubstr tag) noexcept
    {
        _c4dbgpf("node[{}]: set key tag: [{}]~~~{}~~~", m_curr->node_id, tag.len, tag);
        _enable_(KEYTAG);
        m_curr->tr_data->m_key.tag = tag;
    }
    void set_val_tag(csubstr tag) noexcept
    {
        _c4dbgpf("node[{}]: set val tag: [{}]~~~{}~~~", m_curr->node_id, tag.len, tag);
        _enable_(VALTAG);
        m_curr->tr_data->m_val.tag = tag;
    }

    /** @} */

public:

    /** @name YAML directive events */
    /** @{ */

    C4_NO_INLINE void add_directive(csubstr directive)
    {
        _c4dbgpf("% directive! {}", directive);
        _RYML_CB_ASSERT(m_tree->callbacks(), directive.begins_with('%'));
        if(directive.begins_with("%TAG"))
        {
            if(C4_UNLIKELY(!m_tree->add_tag_directive(directive)))
                _RYML_CB_ERR_(m_stack.m_callbacks, "failed to add directive", m_curr->pos);
        }
        else if(directive.begins_with("%YAML"))
        {
            _c4dbgpf("%YAML directive! ignoring...: {}", directive);
            if(C4_UNLIKELY(m_yaml_directive))
                _RYML_CB_ERR_(m_stack.m_callbacks, "multiple yaml directives", m_curr->pos);
            m_yaml_directive = true;
        }
        else
        {
            _c4dbgpf("unknown directive! ignoring... {}", directive);
        }
        ++m_num_directives;
    }

    /** @} */

public:

    /** @name arena functions */
    /** @{ */

    substr alloc_arena(size_t len)
    {
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree);
        csubstr prev = m_tree->arena();
        substr out = m_tree->alloc_arena(len);
        substr curr = m_tree->arena();
        if(curr.str != prev.str)
            _stack_relocate_to_new_arena(prev, curr);
        return out;
    }

    substr alloc_arena(size_t len, substr *relocated)
    {
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree);
        csubstr prev = m_tree->arena();
        if(!prev.is_super(*relocated))
            return alloc_arena(len);
        substr out = alloc_arena(len);
        substr curr = m_tree->arena();
        if(curr.str != prev.str)
            *relocated = _stack_relocate_to_new_arena(*relocated, prev, curr);
        return out;
    }

    /** @} */

public:

    /** @cond dev */
    void _reset_parser_state(state* st, id_type parse_root, id_type node)
    {
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree);
        _set_state_(st, node);
        const NodeType type = m_tree->type(node);
        #ifdef RYML_DBG
        char flagbuf[80];
        _c4dbgpf("resetting state: initial flags={}", detail::_parser_flags_to_str(flagbuf, st->flags));
        #endif
        if(type == NOTYPE)
        {
            _c4dbgpf("node[{}] is notype", node);
            if(m_tree->is_root(parse_root))
            {
                _c4dbgpf("node[{}] is root", node);
                st->flags |= RUNK|RTOP;
            }
            else
            {
                _c4dbgpf("node[{}] is not root. setting USTY", node);
                st->flags |= USTY;
            }
        }
        else if(type.is_map())
        {
            _c4dbgpf("node[{}] is map", node);
            st->flags |= RMAP|USTY;
        }
        else if(type.is_seq())
        {
            _c4dbgpf("node[{}] is map", node);
            st->flags |= RSEQ|USTY;
        }
        else if(type.has_key())
        {
            _c4dbgpf("node[{}] has key. setting USTY", node);
            st->flags |= USTY;
        }
        else
        {
            _RYML_CB_ERR(m_tree->callbacks(), "cannot append to node");
        }
        if(type.is_doc())
        {
            _c4dbgpf("node[{}] is doc", node);
            st->flags |= RDOC;
        }
        #ifdef RYML_DBG
        _c4dbgpf("resetting state: final flags={}", detail::_parser_flags_to_str(flagbuf, st->flags));
        #endif
    }

    /** push a new parent, add a child to the new parent, and set the
     * child as the current node */
    void _push()
    {
        _stack_push();
        NodeData const* prev = m_tree->m_buf; // watch out against relocation of the tree nodes
        m_curr->node_id = m_tree->_append_child__unprotected(m_parent->node_id);
        m_curr->tr_data = m_tree->_p(m_curr->node_id);
        if(prev != m_tree->m_buf)
            _refresh_after_relocation();
        _c4dbgpf("pushed! level={}. top is now node={} (parent={})", m_curr->level, m_curr->node_id, m_parent ? m_parent->node_id : NONE);
    }
    /** end the current scope */
    void _pop()
    {
        _remove_speculative_with_parent();
        _stack_pop();
    }

public:

    template<type_bits bits> C4_HOT C4_ALWAYS_INLINE void _enable__() noexcept
    {
        m_curr->tr_data->m_type.type = static_cast<NodeType_e>(m_curr->tr_data->m_type.type | bits);
    }
    template<type_bits bits> C4_HOT C4_ALWAYS_INLINE void _disable__() noexcept
    {
        m_curr->tr_data->m_type.type = static_cast<NodeType_e>(m_curr->tr_data->m_type.type & (~bits));
    }
    template<type_bits bits> C4_HOT C4_ALWAYS_INLINE bool _has_any__() const noexcept
    {
        return (m_curr->tr_data->m_type.type & bits) != 0;
    }

public:

    C4_ALWAYS_INLINE void _set_state_(state *C4_RESTRICT s, id_type id) noexcept
    {
        s->node_id = id;
        s->tr_data = m_tree->_p(id);
    }
    void _refresh_after_relocation()
    {
        _c4dbgp("tree: refreshing stack data after tree data relocation");
        for(auto &st : m_stack)
            st.tr_data = m_tree->_p(st.node_id);
    }

    void _set_root_as_stream()
    {
        _c4dbgp("set root as stream");
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->root_id() == 0u);
        _RYML_CB_ASSERT(m_tree->callbacks(), m_curr->node_id == 0u);
        const bool hack = !m_tree->has_children(m_curr->node_id) && !m_tree->is_val(m_curr->node_id);
        if(hack)
            m_tree->_p(m_tree->root_id())->m_type.add(VAL);
        m_tree->set_root_as_stream();
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_stream(m_tree->root_id()));
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->has_children(m_tree->root_id()));
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->is_doc(m_tree->first_child(m_tree->root_id())));
        if(hack)
            m_tree->_p(m_tree->first_child(m_tree->root_id()))->m_type.rem(VAL);
        _set_state_(m_curr, m_tree->root_id());
    }

    static NodeData _val2key_(NodeData const& C4_RESTRICT d) noexcept
    {
        NodeData r = d;
        r.m_key = d.m_val;
        r.m_val = {};
        r.m_type = d.m_type;
        static_assert((_VALMASK >> 1u) == _KEYMASK, "required for this function to work");
        static_assert((VAL_STYLE >> 1u) == KEY_STYLE, "required for this function to work");
        r.m_type.type = ((d.m_type.type & (_VALMASK|VAL_STYLE)) >> 1u);
        r.m_type.type = (r.m_type.type & ~(_VALMASK|VAL_STYLE));
        r.m_type.type = (r.m_type.type | KEY);
        return r;
    }

    void _remove_speculative()
    {
        _c4dbgp("remove speculative node");
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree);
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->size() > 0);
        const id_type last_added = m_tree->size() - 1;
        if(m_tree->has_parent(last_added))
            if(m_tree->_p(last_added)->m_type == NOTYPE)
                m_tree->remove(last_added);
    }

    void _remove_speculative_with_parent()
    {
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree);
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->size() > 0);
        const id_type last_added = m_tree->size() - 1;
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->has_parent(last_added));
        if(m_tree->_p(last_added)->m_type == NOTYPE)
        {
            _c4dbgpf("remove speculative node with parent. parent={} node={} parent(node)={}", m_parent->node_id, last_added, m_tree->parent(last_added));
            m_tree->remove(last_added);
        }
    }

    C4_ALWAYS_INLINE void _save_loc()
    {
        _RYML_CB_ASSERT(m_stack.m_callbacks, m_tree);
        _RYML_CB_ASSERT(m_tree->callbacks(), m_tree->_p(m_curr->node_id)->m_val.scalar.len == 0);
        m_tree->_p(m_curr->node_id)->m_val.scalar.str = m_curr->line_contents.rem.str;
    }

#undef _enable_
#undef _disable_
#undef _has_any_

    /** @endcond */
};

/** @} */

} // namespace yml
} // namespace c4

C4_SUPPRESS_WARNING_MSVC_POP

#endif /* _C4_YML_EVENT_HANDLER_TREE_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/event_handler_tree.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/parse_engine.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/parse_engine.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_PARSE_ENGINE_HPP_
#define _C4_YML_PARSE_ENGINE_HPP_

#ifndef _C4_YML_DETAIL_PARSER_DBG_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/parser_dbg.hpp
//#include "c4/yml/detail/parser_dbg.hpp"
#if !defined(C4_YML_DETAIL_PARSER_DBG_HPP_) && !defined(_C4_YML_DETAIL_PARSER_DBG_HPP_)
#error "amalgamate: file c4/yml/detail/parser_dbg.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PARSER_DBG_HPP_ */

#endif

#ifndef _C4_YML_PARSER_STATE_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/parser_state.hpp
//#include "c4/yml/parser_state.hpp"
#if !defined(C4_YML_PARSER_STATE_HPP_) && !defined(_C4_YML_PARSER_STATE_HPP_)
#error "amalgamate: file c4/yml/parser_state.hpp must have been included at this point"
#endif /* C4_YML_PARSER_STATE_HPP_ */

#endif


#if defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable: 4251/*needs to have dll-interface to be used by clients of struct*/)
#endif


namespace c4 {
namespace yml {

/** @addtogroup doc_parse
 * @{ */

/** @defgroup doc_event_handlers Event Handlers
 *
 * @brief rapidyaml implements its parsing logic with a two-level
 * model, where a @ref ParseEngine object reads through the YAML
 * source, and dispatches events to an EventHandler bound to the @ref
 * ParseEngine. Because @ref ParseEngine is templated on the event
 * handler, the binding uses static polymorphism, without any virtual
 * functions. The actual handler object can be changed at run time,
 * (but of course needs to be the type of the template parameter).
 * This is thus a very efficient architecture, and further enables the
 * user to provide his own custom handler if he wishes to bypass the
 * rapidyaml @ref Tree.
 *
 * There are two handlers implemented in this project:
 *
 * - @ref EventHandlerTree is the handler responsible for creating the
 *   ryml @ref Tree
 *
 * - @ref EventHandlerYamlStd is the handler responsible for emitting
 *   standardized [YAML test suite
 *   events](https://github.com/yaml/yaml-test-suite), used (only) in
 *   the CI of this project.
 *
 *
 * ### Event model
 *
 * The event model used by the parse engine and event handlers follows
 * very closely the event model in the [YAML test
 * suite](https://github.com/yaml/yaml-test-suite).
 *
 * Consider for example this YAML,
 * ```yaml
 * {foo: bar,foo2: bar2}
 * ```
 * which would produce these events in the test-suite parlance:
 * ```
 * +STR
 * +DOC
 * +MAP {}
 * =VAL :foo
 * =VAL :bar
 * =VAL :foo2
 * =VAL :bar2
 * -MAP
 * -DOC
 * -STR
 * ```
 *
 * For reference, the @ref ParseEngine object will produce this
 * sequence of calls to its bound EventHandler:
 * ```cpp
 * handler.begin_stream();
 * handler.begin_doc();
 * handler.begin_map_val_flow();
 * handler.set_key_scalar_plain("foo");
 * handler.set_val_scalar_plain("bar");
 * handler.add_sibling();
 * handler.set_key_scalar_plain("foo2");
 * handler.set_val_scalar_plain("bar2");
 * handler.end_map();
 * handler.end_doc();
 * handler.end_stream();
 * ```
 *
 * For many other examples of all areas of YAML and how ryml's parse
 * model corresponds to the YAML standard model, refer to the [unit
 * tests for the parse
 * engine](https://github.com/biojppm/rapidyaml/tree/master/test/test_parse_engine.cpp).
 *
 *
 * ### Special events
 *
 * Most of the parsing events adopted by rapidyaml in its event model
 * are fairly obvious, but there are two less-obvious events requiring
 * some explanation.
 *
 * These events exist to make it easier to parse some special YAML
 * cases. They are called by the parser when a just-handled
 * value/container is actually the first key of a new map:
 *
 *   - `actually_val_is_first_key_of_new_map_flow()` (@ref EventHandlerTree::actually_val_is_first_key_of_new_map_flow() "see implementation in EventHandlerTree" / @ref EventHandlerYamlStd::actually_val_is_first_key_of_new_map_flow() "see implementation in EventHandlerYamlStd")
 *   - `actually_val_is_first_key_of_new_map_block()` (@ref EventHandlerTree::actually_val_is_first_key_of_new_map_block() "see implementation in EventHandlerTree" / @ref EventHandlerYamlStd::actually_val_is_first_key_of_new_map_block() "see implementation in EventHandlerYamlStd")
 *
 * For example, consider an implicit map inside a seq: `[a: b, c:
 * d]` which is parsed as `[{a: b}, {c: d}]`. The standard event
 * sequence for this YAML would be the following:
 * ```cpp
 * handler.begin_seq_val_flow();
 * handler.begin_map_val_flow();
 * handler.set_key_scalar_plain("a");
 * handler.set_val_scalar_plain("b");
 * handler.end_map();
 * handler.add_sibling();
 * handler.begin_map_val_flow();
 * handler.set_key_scalar_plain("c");
 * handler.set_val_scalar_plain("d");
 * handler.end_map();
 * handler.end_seq();
 * ```
 * The problem with this event sequence is that it forces the
 * parser to delay setting the val scalar (in this case "a" and
 * "c") until it knows whether the scalar is a key or a val. This
 * would require the parser to store the scalar until this
 * time. For instance, in the example above, the parser should
 * delay setting "a" and "c", because they are in fact keys and
 * not vals. Until then, the parser would have to store "a" and
 * "c" in its internal state. The downside is that this complexity
 * cost would apply even if there is no implicit map -- every val
 * in a seq would have to be delayed until one of the
 * disambiguating subsequent tokens `,-]:` is found.
 * By calling this function, the parser can avoid this complexity,
 * by preemptively setting the scalar as a val. Then a call to
 * this function will create the map and rearrange the scalar as
 * key. Now the cost applies only once: when a seqimap starts. So
 * the following (easier and cheaper) event sequence below has the
 * same effect as the event sequence above:
 * ```cpp
 * handler.begin_seq_val_flow();
 * handler.set_val_scalar_plain("notmap");
 * handler.set_val_scalar_plain("a"); // preemptively set "a" as val!
 * handler.actually_as_new_map_key(); // create a map, move the "a" val as the key of the first child of the new map
 * handler.set_val_scalar_plain("b"); // now "a" is a key and "b" the val
 * handler.end_map();
 * handler.set_val_scalar_plain("c"); // "c" also as val!
 * handler.actually_as_block_flow();  // likewise
 * handler.set_val_scalar_plain("d"); // now "c" is a key and "b" the val
 * handler.end_map();
 * handler.end_seq();
 * ```
 * This also applies to container keys (although ryml's tree
 * cannot accomodate these): the parser can preemptively set a
 * container as a val, and call this event to turn that container
 * into a key. For example, consider this yaml:
 * ```yaml
 *   [aa, bb]: [cc, dd]
 * # ^       ^ ^
 * # |       | |
 * # (2)   (1) (3)     <- event sequence
 * ```
 * The standard event sequence for this YAML would be the
 * following:
 * ```cpp
 * handler.begin_map_val_block();       // (1)
 * handler.begin_seq_key_flow();        // (2)
 * handler.set_val_scalar_plain("aa");
 * handler.add_sibling();
 * handler.set_val_scalar_plain("bb");
 * handler.end_seq();
 * handler.begin_seq_val_flow();        // (3)
 * handler.set_val_scalar_plain("cc");
 * handler.add_sibling();
 * handler.set_val_scalar_plain("dd");
 * handler.end_seq();
 * handler.end_map();
 * ```
 * The problem with the sequence above is that, reading from
 * left-to-right, the parser can only detect the proper calls at
 * (1) and (2) once it reaches (1) in the YAML source. So, the
 * parser would have to buffer the entire event sequence starting
 * from the beginning until it reaches (1). Using this function,
 * the parser can do instead:
 * ```cpp
 * handler.begin_seq_val_flow();        // (2) -- preemptively as val!
 * handler.set_val_scalar_plain("aa");
 * handler.add_sibling();
 * handler.set_val_scalar_plain("bb");
 * handler.end_seq();
 * handler.actually_as_new_map_key();   // (1) -- adjust when finding that the prev val was actually a key.
 * handler.begin_seq_val_flow();        // (3) -- go on as before
 * handler.set_val_scalar_plain("cc");
 * handler.add_sibling();
 * handler.set_val_scalar_plain("dd");
 * handler.end_seq();
 * handler.end_map();
 * ```
 */

class Tree;
class NodeRef;
class ConstNodeRef;


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** Options to give to the parser to control its behavior. */
struct RYML_EXPORT ParserOptions
{
private:

    typedef enum : uint32_t {
        SCALAR_FILTERING = (1u << 0),
        LOCATIONS = (1u << 1),
        DEFAULTS = SCALAR_FILTERING,
    } Flags_e;

    uint32_t flags = DEFAULTS;

public:

    ParserOptions() = default;

public:

    /** @name source location tracking */
    /** @{ */

    /** enable/disable source location tracking */
    ParserOptions& locations(bool enabled) noexcept
    {
        if(enabled)
            flags |= LOCATIONS;
        else
            flags &= ~LOCATIONS;
        return *this;
    }
    /** query source location tracking status */
    C4_ALWAYS_INLINE bool locations() const noexcept { return (flags & LOCATIONS); }

    /** @} */

public:

    /** @name scalar filtering status (experimental; disable at your discretion) */
    /** @{ */

    /** enable/disable scalar filtering while parsing */
    ParserOptions& scalar_filtering(bool enabled) noexcept
    {
        if(enabled)
            flags |= SCALAR_FILTERING;
        else
            flags &= ~SCALAR_FILTERING;
        return *this;
    }
    /** query scalar filtering status */
    C4_ALWAYS_INLINE bool scalar_filtering() const noexcept { return (flags & SCALAR_FILTERING); }

    /** @} */
};


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

/** This is the main driver of parsing logic: it scans the YAML or
 * JSON source for tokens, and emits the appropriate sequence of
 * parsing events to its event handler. The parse engine itself has no
 * special limitations, and *can* accomodate containers as keys; it is the
 * event handler may introduce additional constraints.
 *
 * There are two implemented handlers (see @ref doc_event_handlers,
 * which has important notes about the event model):
 *
 * - @ref EventHandlerTree is the handler responsible for creating the
 *   ryml @ref Tree
 *
 * - @ref EventHandlerYamlStd is the handler responsible for emitting
 *   standardized [YAML test suite
 *   events](https://github.com/yaml/yaml-test-suite), used (only) in
 *   the CI of this project. This is not part of the library and is
 *   not installed.
 */
template<class EventHandler>
class ParseEngine
{
public:

    using handler_type = EventHandler;

public:

    /** @name construction and assignment */
    /** @{ */

    ParseEngine(EventHandler *evt_handler, ParserOptions opts={});
    ~ParseEngine();

    ParseEngine(ParseEngine &&);
    ParseEngine(ParseEngine const&);
    ParseEngine& operator=(ParseEngine &&);
    ParseEngine& operator=(ParseEngine const&);

    /** @} */

public:

    /** @name modifiers */
    /** @{ */

    /** Reserve a certain capacity for the parsing stack.
     * This should be larger than the expected depth of the parsed
     * YAML tree.
     *
     * The parsing stack is the only (potential) heap memory used
     * directly by the parser.
     *
     * If the requested capacity is below the default
     * stack size of 16, the memory is used directly in the parser
     * object; otherwise it will be allocated from the heap.
     *
     * @note this reserves memory only for the parser itself; all the
     * allocations for the parsed tree will go through the tree's
     * allocator (when different).
     *
     * @note for maximum efficiency, the tree and the arena can (and
     * should) also be reserved. */
    void reserve_stack(id_type capacity)
    {
        m_evt_handler->m_stack.reserve(capacity);
    }

    /** Reserve a certain capacity for the array used to track node
     * locations in the source buffer. */
    void reserve_locations(size_t num_source_lines)
    {
        _resize_locations(num_source_lines);
    }

    RYML_DEPRECATED("filter arena no longer needed")
    void reserve_filter_arena(size_t) {}

    /** @} */

public:

    /** @name getters */
    /** @{ */

    /** Get the options used to build this parser object. */
    ParserOptions const& options() const { return m_options; }

    /** Get the current callbacks in the parser. */
    Callbacks const& callbacks() const { RYML_ASSERT(m_evt_handler); return m_evt_handler->m_stack.m_callbacks; }

    /** Get the name of the latest file parsed by this object. */
    csubstr filename() const { return m_file; }

    /** Get the latest YAML buffer parsed by this object. */
    csubstr source() const { return m_buf; }

    id_type stack_capacity() const { RYML_ASSERT(m_evt_handler); return m_evt_handler->m_stack.capacity(); }
    size_t locations_capacity() const { return m_newline_offsets_capacity; }

    RYML_DEPRECATED("filter arena no longer needed")
    size_t filter_arena_capacity() const { return 0u; }

    /** @} */

public:

    /** @name parse methods */
    /** @{ */

    /** parse YAML in place, emitting events to the current handler */
    void parse_in_place_ev(csubstr filename, substr src);

    /** parse JSON in place, emitting events to the current handler */
    void parse_json_in_place_ev(csubstr filename, substr src);

    /** @} */

public:

    /** @name deprecated parse methods
     * @{ */

    /** @cond dev */
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_place(csubstr filename, substr yaml, Tree *t, size_t node_id);
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_place(                  substr yaml, Tree *t, size_t node_id);
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_place(csubstr filename, substr yaml, Tree *t                );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_place(                  substr yaml, Tree *t                );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_place(csubstr filename, substr yaml, NodeRef node           );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_place(                  substr yaml, NodeRef node           );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, Tree>::type parse_in_place(csubstr filename, substr yaml                         );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, Tree>::type parse_in_place(                  substr yaml                         );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(csubstr filename, csubstr yaml, Tree *t, size_t node_id);
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(                  csubstr yaml, Tree *t, size_t node_id);
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(csubstr filename, csubstr yaml, Tree *t                );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(                  csubstr yaml, Tree *t                );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(csubstr filename, csubstr yaml, NodeRef node           );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(                  csubstr yaml, NodeRef node           );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, Tree>::type parse_in_arena(csubstr filename, csubstr yaml                         );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding function in parse.hpp.") typename std::enable_if<U::is_wtree, Tree>::type parse_in_arena(                  csubstr yaml                         );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding csubstr version in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(csubstr filename, substr yaml, Tree *t, size_t node_id);
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding csubstr version in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(                  substr yaml, Tree *t, size_t node_id);
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding csubstr version in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(csubstr filename, substr yaml, Tree *t                );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding csubstr version in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(                  substr yaml, Tree *t                );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding csubstr version in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(csubstr filename, substr yaml, NodeRef node           );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding csubstr version in parse.hpp.") typename std::enable_if<U::is_wtree, void>::type parse_in_arena(                  substr yaml, NodeRef node           );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding csubstr version in parse.hpp.") typename std::enable_if<U::is_wtree, Tree>::type parse_in_arena(csubstr filename, substr yaml                         );
    template<class U=EventHandler> RYML_DEPRECATED("removed, deliberately undefined. use the freestanding csubstr version in parse.hpp.") typename std::enable_if<U::is_wtree, Tree>::type parse_in_arena(                  substr yaml                         );
    /** @endcond */

    /** @} */

public:

    /** @name locations */
    /** @{ */

    /** Get the location of a node of the last tree to be parsed by this parser. */
    Location location(Tree const& tree, id_type node_id) const;
    /** Get the location of a node of the last tree to be parsed by this parser. */
    Location location(ConstNodeRef node) const;
    /** Get the string starting at a particular location, to the end
     * of the parsed source buffer. */
    csubstr location_contents(Location const& loc) const;
    /** Given a pointer to a buffer position, get the location.
     * @param[in] val must be pointing to somewhere in the source
     * buffer that was last parsed by this object. */
    Location val_location(const char *val) const;

    /** @} */

public:

    /** @name scalar filtering */
    /** @{*/

    /** filter a plain scalar */
    FilterResult filter_scalar_plain(csubstr scalar, substr dst, size_t indentation);
    /** filter a plain scalar in place */
    FilterResult filter_scalar_plain_in_place(substr scalar, size_t cap, size_t indentation);

    /** filter a single-quoted scalar */
    FilterResult filter_scalar_squoted(csubstr scalar, substr dst);
    /** filter a single-quoted scalar in place */
    FilterResult filter_scalar_squoted_in_place(substr scalar, size_t cap);

    /** filter a double-quoted scalar */
    FilterResult filter_scalar_dquoted(csubstr scalar, substr dst);
    /** filter a double-quoted scalar in place */
    FilterResultExtending filter_scalar_dquoted_in_place(substr scalar, size_t cap);

    /** filter a block-literal scalar */
    FilterResult filter_scalar_block_literal(csubstr scalar, substr dst, size_t indentation, BlockChomp_e chomp);
    /** filter a block-literal scalar in place */
    FilterResult filter_scalar_block_literal_in_place(substr scalar, size_t cap, size_t indentation, BlockChomp_e chomp);

    /** filter a block-folded scalar */
    FilterResult filter_scalar_block_folded(csubstr scalar, substr dst, size_t indentation, BlockChomp_e chomp);
    /** filter a block-folded scalar in place */
    FilterResult filter_scalar_block_folded_in_place(substr scalar, size_t cap, size_t indentation, BlockChomp_e chomp);

    /** @} */

private:

    struct ScannedScalar
    {
        substr scalar;
        bool needs_filter;
    };

    struct ScannedBlock
    {
        substr scalar;
        size_t indentation;
        BlockChomp_e chomp;
    };

    bool    _is_doc_begin(csubstr s);
    bool    _is_doc_end(csubstr s);

    bool    _scan_scalar_plain_blck(ScannedScalar *C4_RESTRICT sc, size_t indentation);
    bool    _scan_scalar_plain_seq_flow(ScannedScalar *C4_RESTRICT sc);
    bool    _scan_scalar_plain_seq_blck(ScannedScalar *C4_RESTRICT sc);
    bool    _scan_scalar_plain_map_flow(ScannedScalar *C4_RESTRICT sc);
    bool    _scan_scalar_plain_map_blck(ScannedScalar *C4_RESTRICT sc);
    bool    _scan_scalar_map_json(ScannedScalar *C4_RESTRICT sc);
    bool    _scan_scalar_seq_json(ScannedScalar *C4_RESTRICT sc);
    bool    _scan_scalar_plain_unk(ScannedScalar *C4_RESTRICT sc);
    bool    _is_valid_start_scalar_plain_flow(csubstr s);

    ScannedScalar _scan_scalar_squot();
    ScannedScalar _scan_scalar_dquot();

    void    _scan_block(ScannedBlock *C4_RESTRICT sb, size_t indref);

    csubstr _scan_anchor();
    csubstr _scan_ref_seq();
    csubstr _scan_ref_map();
    csubstr _scan_tag();

public: // exposed for testing

    /** @cond dev */
    csubstr _filter_scalar_plain(substr s, size_t indentation);
    csubstr _filter_scalar_squot(substr s);
    csubstr _filter_scalar_dquot(substr s);
    csubstr _filter_scalar_literal(substr s, size_t indentation, BlockChomp_e chomp);
    csubstr _filter_scalar_folded(substr s, size_t indentation, BlockChomp_e chomp);

    csubstr _maybe_filter_key_scalar_plain(ScannedScalar const& sc, size_t indendation);
    csubstr _maybe_filter_val_scalar_plain(ScannedScalar const& sc, size_t indendation);
    csubstr _maybe_filter_key_scalar_squot(ScannedScalar const& sc);
    csubstr _maybe_filter_val_scalar_squot(ScannedScalar const& sc);
    csubstr _maybe_filter_key_scalar_dquot(ScannedScalar const& sc);
    csubstr _maybe_filter_val_scalar_dquot(ScannedScalar const& sc);
    csubstr _maybe_filter_key_scalar_literal(ScannedBlock const& sb);
    csubstr _maybe_filter_val_scalar_literal(ScannedBlock const& sb);
    csubstr _maybe_filter_key_scalar_folded(ScannedBlock const& sb);
    csubstr _maybe_filter_val_scalar_folded(ScannedBlock const& sb);
    /** @endcond */

private:

    void  _handle_map_block();
    void  _handle_seq_block();
    void  _handle_map_flow();
    void  _handle_seq_flow();
    void  _handle_seq_imap();
    void  _handle_map_json();
    void  _handle_seq_json();

    void  _handle_unk();
    void  _handle_unk_json();
    void  _handle_usty();

    void  _handle_flow_skip_whitespace();

    void  _end_map_blck();
    void  _end_seq_blck();
    void  _end2_map();
    void  _end2_seq();

    void  _begin2_doc();
    void  _begin2_doc_expl();
    void  _end2_doc();
    void  _end2_doc_expl();

    void  _maybe_begin_doc();
    void  _maybe_end_doc();

    void  _start_doc_suddenly();
    void  _end_doc_suddenly();
    void  _end_doc_suddenly__pop();
    void  _end_stream();

    void  _set_indentation(size_t indentation);
    void  _save_indentation();
    void  _handle_indentation_pop_from_block_seq();
    void  _handle_indentation_pop_from_block_map();
    void  _handle_indentation_pop(ParserState const* dst);

    void _maybe_skip_comment();
    void _skip_comment();
    void _maybe_skip_whitespace_tokens();
    void _maybe_skipchars(char c);
    #ifdef RYML_NO_COVERAGE__TO_BE_DELETED
    void _maybe_skipchars_up_to(char c, size_t max_to_skip);
    #endif
    template<size_t N>
    void _skipchars(const char (&chars)[N]);
    bool _maybe_scan_following_colon() noexcept;
    bool _maybe_scan_following_comma() noexcept;

public:

    /** @cond dev */
    template<class FilterProcessor> auto _filter_plain(FilterProcessor &C4_RESTRICT proc, size_t indentation) -> decltype(proc.result());
    template<class FilterProcessor> auto _filter_squoted(FilterProcessor &C4_RESTRICT proc) -> decltype(proc.result());
    template<class FilterProcessor> auto _filter_dquoted(FilterProcessor &C4_RESTRICT proc) -> decltype(proc.result());
    template<class FilterProcessor> auto _filter_block_literal(FilterProcessor &C4_RESTRICT proc, size_t indentation, BlockChomp_e chomp) -> decltype(proc.result());
    template<class FilterProcessor> auto _filter_block_folded(FilterProcessor &C4_RESTRICT proc, size_t indentation, BlockChomp_e chomp) -> decltype(proc.result());
    /** @endcond */

public:

    /** @cond dev */
    template<class FilterProcessor> void   _filter_nl_plain(FilterProcessor &C4_RESTRICT proc, size_t indentation);
    template<class FilterProcessor> void   _filter_nl_squoted(FilterProcessor &C4_RESTRICT proc);
    template<class FilterProcessor> void   _filter_nl_dquoted(FilterProcessor &C4_RESTRICT proc);

    template<class FilterProcessor> bool   _filter_ws_handle_to_first_non_space(FilterProcessor &C4_RESTRICT proc);
    template<class FilterProcessor> void   _filter_ws_copy_trailing(FilterProcessor &C4_RESTRICT proc);
    template<class FilterProcessor> void   _filter_ws_skip_trailing(FilterProcessor &C4_RESTRICT proc);

    template<class FilterProcessor> void   _filter_dquoted_backslash(FilterProcessor &C4_RESTRICT proc);

    template<class FilterProcessor> void   _filter_chomp(FilterProcessor &C4_RESTRICT proc, BlockChomp_e chomp, size_t indentation);
    template<class FilterProcessor> size_t _handle_all_whitespace(FilterProcessor &C4_RESTRICT proc, BlockChomp_e chomp);
    template<class FilterProcessor> size_t _extend_to_chomp(FilterProcessor &C4_RESTRICT proc, size_t contents_len);
    template<class FilterProcessor> void   _filter_block_indentation(FilterProcessor &C4_RESTRICT proc, size_t indentation);
    template<class FilterProcessor> void   _filter_block_folded_newlines(FilterProcessor &C4_RESTRICT proc, size_t indentation, size_t len);
    template<class FilterProcessor> size_t _filter_block_folded_newlines_compress(FilterProcessor &C4_RESTRICT proc, size_t num_newl, size_t wpos_at_first_newl);
    template<class FilterProcessor> void   _filter_block_folded_newlines_leading(FilterProcessor &C4_RESTRICT proc, size_t indentation, size_t len);
    template<class FilterProcessor> void   _filter_block_folded_indented_block(FilterProcessor &C4_RESTRICT proc, size_t indentation, size_t len, size_t curr_indentation) noexcept;

    /** @endcond */

private:

    void _line_progressed(size_t ahead);
    void _line_ended();
    void _line_ended_undo();

    bool  _finished_file() const;
    bool  _finished_line() const;

    void   _scan_line();
    substr _peek_next_line(size_t pos=npos) const;

    inline bool _at_line_begin() const
    {
        return m_evt_handler->m_curr->line_contents.rem.begin() == m_evt_handler->m_curr->line_contents.full.begin();
    }

    void _relocate_arena(csubstr prev_arena, substr next_arena);
    static void _s_relocate_arena(void*, csubstr prev_arena, substr next_arena);

private:

    C4_ALWAYS_INLINE bool has_all(ParserFlag_t f) const noexcept { return (m_evt_handler->m_curr->flags & f) == f; }
    C4_ALWAYS_INLINE bool has_any(ParserFlag_t f) const noexcept { return (m_evt_handler->m_curr->flags & f) != 0; }
    C4_ALWAYS_INLINE bool has_none(ParserFlag_t f) const noexcept { return (m_evt_handler->m_curr->flags & f) == 0; }
    static C4_ALWAYS_INLINE bool has_all(ParserFlag_t f, ParserState const* C4_RESTRICT s) noexcept { return (s->flags & f) == f; }
    static C4_ALWAYS_INLINE bool has_any(ParserFlag_t f, ParserState const* C4_RESTRICT s) noexcept { return (s->flags & f) != 0; }
    static C4_ALWAYS_INLINE bool has_none(ParserFlag_t f, ParserState const* C4_RESTRICT s) noexcept { return (s->flags & f) == 0; }

    #ifndef RYML_DBG
    C4_ALWAYS_INLINE static void add_flags(ParserFlag_t on, ParserState *C4_RESTRICT s) noexcept { s->flags |= on; }
    C4_ALWAYS_INLINE static void addrem_flags(ParserFlag_t on, ParserFlag_t off, ParserState *C4_RESTRICT s) noexcept { s->flags &= ~off; s->flags |= on; }
    C4_ALWAYS_INLINE static void rem_flags(ParserFlag_t off, ParserState *C4_RESTRICT s) noexcept { s->flags &= ~off; }
    C4_ALWAYS_INLINE void add_flags(ParserFlag_t on) noexcept { m_evt_handler->m_curr->flags |= on; }
    C4_ALWAYS_INLINE void addrem_flags(ParserFlag_t on, ParserFlag_t off) noexcept { m_evt_handler->m_curr->flags &= ~off; m_evt_handler->m_curr->flags |= on; }
    C4_ALWAYS_INLINE void rem_flags(ParserFlag_t off) noexcept { m_evt_handler->m_curr->flags &= ~off; }
    #else
    static void add_flags(ParserFlag_t on, ParserState *C4_RESTRICT s);
    static void addrem_flags(ParserFlag_t on, ParserFlag_t off, ParserState *C4_RESTRICT s);
    static void rem_flags(ParserFlag_t off, ParserState *C4_RESTRICT s);
    C4_ALWAYS_INLINE void add_flags(ParserFlag_t on) noexcept { add_flags(on, m_evt_handler->m_curr); }
    C4_ALWAYS_INLINE void addrem_flags(ParserFlag_t on, ParserFlag_t off) noexcept { addrem_flags(on, off, m_evt_handler->m_curr); }
    C4_ALWAYS_INLINE void rem_flags(ParserFlag_t off) noexcept { rem_flags(off, m_evt_handler->m_curr); }
    #endif

private:

    void _prepare_locations();
    void _resize_locations(size_t sz);
    bool _locations_dirty() const;

    bool _location_from_cont(Tree const& tree, id_type node, Location *C4_RESTRICT loc) const;
    bool _location_from_node(Tree const& tree, id_type node, Location *C4_RESTRICT loc, id_type level) const;

private:

    void _reset();
    void _free();
    void _clr();

    #ifdef RYML_DBG
    template<class ...Args> void _dbg(csubstr fmt, Args const& C4_RESTRICT ...args) const;
    #endif
    template<class ...Args> void _err(csubstr fmt, Args const& C4_RESTRICT ...args) const;
    template<class ...Args> void _errloc(csubstr fmt, Location const& loc, Args const& C4_RESTRICT ...args) const;

    template<class DumpFn>  void _fmt_msg(DumpFn &&dumpfn) const;

private:

    /** store pending tag or anchor/ref annotations */
    struct Annotation
    {
        struct Entry
        {
            csubstr str;
            size_t indentation;
            size_t line;
        };
        Entry annotations[2];
        size_t num_entries;
    };

    void _add_annotation(Annotation *C4_RESTRICT dst, csubstr str, size_t indentation, size_t line);
    void _clear_annotations(Annotation *C4_RESTRICT dst);
    bool _has_pending_annotations() const { return m_pending_tags.num_entries || m_pending_anchors.num_entries; }
    #ifdef RYML_NO_COVERAGE__TO_BE_DELETED
    bool _handle_indentation_from_annotations();
    #endif
    bool _annotations_require_key_container() const;
    void _handle_annotations_before_blck_key_scalar();
    void _handle_annotations_before_blck_val_scalar();
    void _handle_annotations_before_start_mapblck(size_t current_line);
    void _handle_annotations_before_start_mapblck_as_key();
    void _handle_annotations_and_indentation_after_start_mapblck(size_t key_indentation, size_t key_line);
    size_t _select_indentation_from_annotations(size_t val_indentation, size_t val_line);
    void _handle_directive(csubstr rem);

    void _check_tag(csubstr tag);

private:

    ParserOptions m_options;

    csubstr m_file;
    substr  m_buf;

public:

    /** @cond dev */
    EventHandler *C4_RESTRICT m_evt_handler;
    /** @endcond */

private:

    Annotation m_pending_anchors;
    Annotation m_pending_tags;

    bool m_was_inside_qmrk;
    bool m_doc_empty = true;

private:

    size_t *m_newline_offsets;
    size_t  m_newline_offsets_size;
    size_t  m_newline_offsets_capacity;
    csubstr m_newline_offsets_buf;

};

/** @cond dev */
RYML_EXPORT C4_NO_INLINE size_t _find_last_newline_and_larger_indentation(csubstr s, size_t indentation) noexcept;
/** @endcond */


/** Quickly inspect the source to estimate the number of nodes the
 * resulting tree is likely have. If a tree is empty before
 * parsing, considerable time will be spent growing it, so calling
 * this to reserve the tree size prior to parsing is likely to
 * result in a time gain. We encourage using this method before
 * parsing, but as always measure its impact in performance to
 * obtain a good trade-off.
 *
 * @note since this method is meant for optimizing performance, it
 * is approximate. The result may be actually smaller than the
 * resulting number of nodes, notably if the YAML uses implicit
 * maps as flow seq members as in `[these: are, individual:
 * maps]`. */
RYML_EXPORT id_type estimate_tree_capacity(csubstr src);

/** @} */

} // namespace yml
} // namespace c4

#if defined(_MSC_VER)
#   pragma warning(pop)
#endif

#endif /* _C4_YML_PARSE_ENGINE_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/parse_engine.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/preprocess.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/preprocess.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_PREPROCESS_HPP_
#define _C4_YML_PREPROCESS_HPP_

/** @file preprocess.hpp Functions for preprocessing YAML prior to parsing. */

#ifndef _C4_YML_COMMON_HPP_
//included above:
//#include "./common.hpp"
#endif
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/substr.hpp
//#include <c4/substr.hpp>
#if !defined(C4_SUBSTR_HPP_) && !defined(_C4_SUBSTR_HPP_)
#error "amalgamate: file c4/substr.hpp must have been included at this point"
#endif /* C4_SUBSTR_HPP_ */



namespace c4 {
namespace yml {

/** @addtogroup doc_preprocessors
 * @{
 */

/** @cond dev */
namespace detail {
using Preprocessor = size_t(csubstr, substr);
template<Preprocessor PP, class CharContainer>
substr preprocess_into_container(csubstr input, CharContainer *out)
{
    // try to write once. the preprocessor will stop writing at the end of
    // the container, but will process all the input to determine the
    // required container size.
    size_t sz = PP(input, to_substr(*out));
    // if the container size is not enough, resize, and run again in the
    // resized container
    if(sz > out->size())
    {
        out->resize(sz);
        sz = PP(input, to_substr(*out));
    }
    return to_substr(*out).first(sz);
}
} // namespace detail
/** @endcond */


//-----------------------------------------------------------------------------

/** @defgroup doc_preprocess_rxmap preprocess_rxmap
 *
 * @brief Convert flow-type relaxed maps (with implicit bools) into strict YAML
 * flow map:
 *
 * @code{.yaml}
 * {a, b, c, d: [e, f], g: {a, b}}
 * # is converted into this:
 * {a: 1, b: 1, c: 1, d: [e, f], g: {a, b}}
 * @endcode

 * @note this is NOT recursive - conversion happens only in the top-level map
 * @param rxmap A relaxed map
 * @param buf output buffer
 * @param out output container
 *
 * @{
 */

/** Write into a given output buffer. This function is safe to call with
 * empty or small buffers; it won't write beyond the end of the buffer.
 *
 * @return the number of characters required for output
 */
RYML_EXPORT size_t preprocess_rxmap(csubstr rxmap, substr buf);


/** Write into an existing container. It is resized to contained the output.
 * @return a substr of the container
 * @overload preprocess_rxmap */
template<class CharContainer>
substr preprocess_rxmap(csubstr rxmap, CharContainer *out)
{
    return detail::preprocess_into_container<preprocess_rxmap>(rxmap, out);
}


/** Create a container with the result.
 * @overload preprocess_rxmap */
template<class CharContainer>
CharContainer preprocess_rxmap(csubstr rxmap)
{
    CharContainer out;
    preprocess_rxmap(rxmap, &out);
    return out;
}

/** @} */ // preprocess_rxmap
/** @} */ // group

} // namespace yml
} // namespace c4

#endif /* _C4_YML_PREPROCESS_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/preprocess.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/reference_resolver.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/reference_resolver.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_REFERENCE_RESOLVER_HPP_
#define _C4_YML_REFERENCE_RESOLVER_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/tree.hpp
//#include "c4/yml/tree.hpp"
#if !defined(C4_YML_TREE_HPP_) && !defined(_C4_YML_TREE_HPP_)
#error "amalgamate: file c4/yml/tree.hpp must have been included at this point"
#endif /* C4_YML_TREE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/stack.hpp
//#include "c4/yml/detail/stack.hpp"
#if !defined(C4_YML_DETAIL_STACK_HPP_) && !defined(_C4_YML_DETAIL_STACK_HPP_)
#error "amalgamate: file c4/yml/detail/stack.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_STACK_HPP_ */



namespace c4 {
namespace yml {

/** @addtogroup doc_ref_utils
 * @{
 */

/** Reusable object to resolve references/aliases in the tree. */
struct RYML_EXPORT ReferenceResolver
{
    ReferenceResolver() = default;

    /** Resolve references: for each reference, look for a matching
     * anchor, and copy its contents to the ref node.
     *
     * This method first does a full traversal of the tree to gather
     * all anchors and references in a separate collection, then it
     * goes through that collection to locate the names, which it does
     * by obeying the YAML standard diktat that "an alias node refers
     * to the most recent node in the serialization having the
     * specified anchor"
     *
     * So, depending on the number of anchor/alias nodes, this is a
     * potentially expensive operation, with a best-case linear
     * complexity (from the initial traversal).
     *
     * @todo verify sanity against anchor-ref attacks (https://en.wikipedia.org/wiki/Billion_laughs_attack )
     */
    void resolve(Tree *t_);

public:

    /** @cond dev */

    struct RefData
    {
        NodeType type;
        id_type node;
        id_type prev_anchor;
        id_type target;
        id_type parent_ref;
        id_type parent_ref_sibling;
    };

    void reset_(Tree *t_);
    void gather_anchors_and_refs_();
    void gather_anchors_and_refs__(id_type n);
    id_type count_anchors_and_refs_(id_type n);

    id_type lookup_(RefData *C4_RESTRICT ra);

public:

    Tree *C4_RESTRICT m_tree;
    /** We're using this stack purely as an array. */
    detail::stack<RefData> m_refs;

    /** @endcond */
};

/** @} */

} // namespace ryml
} // namespace c4


#endif // _C4_YML_REFERENCE_RESOLVER_HPP_


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/reference_resolver.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/parse.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/parse.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_PARSE_HPP_
#define _C4_YML_PARSE_HPP_

#ifndef _C4_YML_COMMON_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/common.hpp
//#include "c4/yml/common.hpp"
#if !defined(C4_YML_COMMON_HPP_) && !defined(_C4_YML_COMMON_HPP_)
#error "amalgamate: file c4/yml/common.hpp must have been included at this point"
#endif /* C4_YML_COMMON_HPP_ */

#endif

namespace c4 {
namespace yml {

class Tree;
class NodeRef;
template<class EventHandler> class ParseEngine;
struct EventHandlerTree;
RYML_EXPORT id_type estimate_tree_capacity(csubstr src);


/** @addtogroup doc_parse
 * @{ */

/** This is the main ryml parser, where the parser events are handled
 * to create a ryml tree.
 *
 * @warning Because the ryml @ref Tree does not accept containers as
 * keys, this class cannot successfully parse YAML source with this
 * feature. See @ref ParseEngine for more details.
 *
 * @see ParserOptions
 * @see ParseEngine
 * @see EventHandlerTree
 * */
using Parser = RYML_EXPORT ParseEngine<EventHandlerTree>;


//-----------------------------------------------------------------------------

/** @defgroup doc_parse_in_place__with_existing_parser Parse in place with existing parser
 *
 * @brief parse a mutable YAML source buffer. Scalars requiring
 * filtering are mutated in place (except in the rare cases where the
 * filtered scalar is longer than the original scalar, or where
 * filtering was disabled before the call). These overloads accept an
 * existing parser object, and provide the opportunity to use special
 * parser options.
 *
 * @see ParserOptions
 *
 * @{
 */

// this is vertically aligned to highlight the parameter differences.

RYML_EXPORT void parse_in_place(Parser *parser, csubstr filename, substr yaml, Tree *t, id_type node_id); /**< (1) parse YAML into an existing tree node.
                                                                                                          *
                                                                                                          * The filename will be used in any error messages
                                                                                                          * arising during the parse. The callbacks in the
                                                                                                          * tree are kept, and used to allocate
                                                                                                          * the tree members, if any allocation is required. */
RYML_EXPORT void parse_in_place(Parser *parser,                   substr yaml, Tree *t, id_type node_id); /**< (2) like (1) but no filename will be reported */
RYML_EXPORT void parse_in_place(Parser *parser, csubstr filename, substr yaml, Tree *t                 ); /**< (3) parse YAML into an existing tree, into its root node.
                                                                                                          *
                                                                                                          * The filename will be used in any error messages
                                                                                                          * arising during the parse. The callbacks in the
                                                                                                          * tree are kept, and used to allocate
                                                                                                          * the tree members, if any allocation is required. */
RYML_EXPORT void parse_in_place(Parser *parser,                   substr yaml, Tree *t                 ); /**< (4) like (3) but no filename will be reported */
RYML_EXPORT void parse_in_place(Parser *parser, csubstr filename, substr yaml, NodeRef node            ); /**< (5) like (1) but the node is given as a NodeRef */
RYML_EXPORT void parse_in_place(Parser *parser,                   substr yaml, NodeRef node            ); /**< (6) like (5) but no filename will be reported */
RYML_EXPORT Tree parse_in_place(Parser *parser, csubstr filename, substr yaml                          ); /**< (7) create a new tree, and parse YAML into its root node.
                                                                                                          *
                                                                                                          * The filename will be used in any error messages
                                                                                                          * arising during the parse. The tree is created with
                                                                                                          * the callbacks currently in the parser.
                                                                                                          */
RYML_EXPORT Tree parse_in_place(Parser *parser,                   substr yaml                          ); /**< (8) like (7) but no filename will be reported */


// this is vertically aligned to highlight the parameter differences.
RYML_EXPORT void parse_json_in_place(Parser *parser, csubstr filename, substr json, Tree *t, id_type node_id); ///< (1) parse JSON into an existing tree node. The filename will be used in any error messages arising during the parse.
RYML_EXPORT void parse_json_in_place(Parser *parser,                   substr json, Tree *t, id_type node_id); ///< (2) like (1) but no filename will be reported
RYML_EXPORT void parse_json_in_place(Parser *parser, csubstr filename, substr json, Tree *t                 ); ///< (3) parse JSON into an existing tree, into its root node.
RYML_EXPORT void parse_json_in_place(Parser *parser,                   substr json, Tree *t                 ); ///< (4) like (3) but no filename will be reported
RYML_EXPORT void parse_json_in_place(Parser *parser, csubstr filename, substr json, NodeRef node            ); ///< (5) like (1) but the node is given as a NodeRef
RYML_EXPORT void parse_json_in_place(Parser *parser,                   substr json, NodeRef node            ); ///< (6) like (5) but no filename will be reported
RYML_EXPORT Tree parse_json_in_place(Parser *parser, csubstr filename, substr json                          ); ///< (7) create a new tree, and parse JSON into its root node.
RYML_EXPORT Tree parse_json_in_place(Parser *parser,                   substr json                          ); ///< (8) like (7) but no filename will be reported

/** @} */


//-----------------------------------------------------------------------------

/** @defgroup doc_parse_in_place___with_temporary_parser Parse in place with temporary parser
 *
 * @brief parse a mutable YAML source buffer. Scalars requiring
 * filtering are mutated in place (except in the rare cases where the
 * filtered scalar is longer than the original scalar).
 *
 * @note These freestanding functions use a temporary parser object,
 * and are convenience functions to enable the user to easily parse
 * YAML without the need to explicitly instantiate a parser and event
 * handler. Note that some properties (notably node locations in the
 * original source code) are only available through the parser
 * class. If you need access to any of these properties, use
 * the appropriate overload from @ref doc_parse_in_place__with_existing_parser
 *
 * @{
 */

// this is vertically aligned to highlight the parameter differences.
RYML_EXPORT void parse_in_place(csubstr filename, substr yaml, Tree *t, id_type node_id); ///< (1) parse YAML into an existing tree node. The filename will be used in any error messages arising during the parse.
RYML_EXPORT void parse_in_place(                  substr yaml, Tree *t, id_type node_id); ///< (2) like (1) but no filename will be reported
RYML_EXPORT void parse_in_place(csubstr filename, substr yaml, Tree *t                 ); ///< (3) parse YAML into an existing tree, into its root node.
RYML_EXPORT void parse_in_place(                  substr yaml, Tree *t                 ); ///< (4) like (3) but no filename will be reported
RYML_EXPORT void parse_in_place(csubstr filename, substr yaml, NodeRef node            ); ///< (5) like (1) but the node is given as a NodeRef
RYML_EXPORT void parse_in_place(                  substr yaml, NodeRef node            ); ///< (6) like (5) but no filename will be reported
RYML_EXPORT Tree parse_in_place(csubstr filename, substr yaml                          ); ///< (7) create a new tree, and parse YAML into its root node.
RYML_EXPORT Tree parse_in_place(                  substr yaml                          ); ///< (8) like (7) but no filename will be reported

// this is vertically aligned to highlight the parameter differences.
RYML_EXPORT void parse_json_in_place(csubstr filename, substr json, Tree *t, id_type node_id); ///< (1) parse JSON into an existing tree node. The filename will be used in any error messages arising during the parse.
RYML_EXPORT void parse_json_in_place(                  substr json, Tree *t, id_type node_id); ///< (2) like (1) but no filename will be reported
RYML_EXPORT void parse_json_in_place(csubstr filename, substr json, Tree *t                 ); ///< (3) parse JSON into an existing tree, into its root node.
RYML_EXPORT void parse_json_in_place(                  substr json, Tree *t                 ); ///< (4) like (3) but no filename will be reported
RYML_EXPORT void parse_json_in_place(csubstr filename, substr json, NodeRef node            ); ///< (5) like (1) but the node is given as a NodeRef
RYML_EXPORT void parse_json_in_place(                  substr json, NodeRef node            ); ///< (6) like (5) but no filename will be reported
RYML_EXPORT Tree parse_json_in_place(csubstr filename, substr json                          ); ///< (7) create a new tree, and parse JSON into its root node.
RYML_EXPORT Tree parse_json_in_place(                  substr json                          ); ///< (8) like (7) but no filename will be reported

/** @} */


//-----------------------------------------------------------------------------


/** @defgroup doc_parse_in_arena__with_existing_parser Parse in arena with existing parser
 *
 * @brief parse a read-only (immutable) YAML source buffer. This is
 * achieved by first copying the contents of the buffer to the tree's
 * arena, and then calling @ref parse_in_arena() . All the resulting
 * scalars will be filtered in the arena. These overloads accept an
 * existing parser object, and provide the opportunity to use special
 * parser options.
 *
 * @see ParserOptions
 *
 *
 * @note These freestanding functions use a temporary parser object,
 * and are convenience functions to easily parse YAML without the need
 * to instantiate a separate parser. Note that some properties
 * (notably node locations in the original source code) are only
 * available through the parser class. If you need access to any of
 * these properties, use the appropriate overload from @ref
 * doc_parse_in_arena__with_existing_parser
 *
 * @warning overloads receiving a substr YAML buffer are intentionally
 * left undefined, such that calling parse_in_arena() with a substr
 * will cause a linker error. This is to prevent an accidental copy of
 * the source buffer to the tree's arena, because substr (which is
 * mutable) is implicitly convertible to csubstr (which is
 * immutable). If you really intend to parse a mutable buffer in the
 * tree's arena, convert it first to immutable by assigning the substr
 * to a csubstr prior to calling parse_in_arena(). This is not needed
 * for parse_in_place() because csubstr is not implicitly convertible
 * to substr. To be clear:
 * ```c++
 * substr mutable_buffer = ...;
 * parser.parse_in_arena(mutable_buffer); // linker error
 *
 * csubstr immutable_buffer = ...;
 * parser.parse_in_arena(immutable_buffer); // ok
 * ```
 *
 * @{
 */

#define RYML_DONT_PARSE_SUBSTR_IN_ARENA ""                      \
    "Do not pass a (mutable) substr to parse_in_arena(); "      \
    "if you have a substr, it should be parsed in place. "      \
    "Consider using parse_in_place() instead, or convert "      \
    "the buffer to csubstr prior to calling. This function "    \
    " is deliberately left undefined, so that calling it "      \
    "will cause a linker error."

// this is vertically aligned to highlight the parameter differences.
RYML_EXPORT void parse_in_arena(Parser *parser, csubstr filename, csubstr yaml, Tree *t, id_type node_id); ///< (1) parse YAML into an existing tree node. The filename will be used in any error messages arising during the parse.
RYML_EXPORT void parse_in_arena(Parser *parser,                   csubstr yaml, Tree *t, id_type node_id); ///< (2) like (1) but no filename will be reported
RYML_EXPORT void parse_in_arena(Parser *parser, csubstr filename, csubstr yaml, Tree *t                 ); ///< (3) parse YAML into an existing tree, into its root node.
RYML_EXPORT void parse_in_arena(Parser *parser,                   csubstr yaml, Tree *t                 ); ///< (4) like (3) but no filename will be reported
RYML_EXPORT void parse_in_arena(Parser *parser, csubstr filename, csubstr yaml, NodeRef node            ); ///< (5) like (1) but the node is given as a NodeRef
RYML_EXPORT void parse_in_arena(Parser *parser,                   csubstr yaml, NodeRef node            ); ///< (6) like (5) but no filename will be reported
RYML_EXPORT Tree parse_in_arena(Parser *parser, csubstr filename, csubstr yaml                          ); ///< (7) create a new tree, and parse YAML into its root node.
RYML_EXPORT Tree parse_in_arena(Parser *parser,                   csubstr yaml                          ); ///< (8) like (7) but no filename will be reported

// this is vertically aligned to highlight the parameter differences.
RYML_EXPORT void parse_json_in_arena(Parser *parser, csubstr filename, csubstr json, Tree *t, id_type node_id); ///< (1) parse JSON into an existing tree node. The filename will be used in any error messages arising during the parse.
RYML_EXPORT void parse_json_in_arena(Parser *parser,                   csubstr json, Tree *t, id_type node_id); ///< (2) like (1) but no filename will be reported
RYML_EXPORT void parse_json_in_arena(Parser *parser, csubstr filename, csubstr json, Tree *t                 ); ///< (3) parse JSON into an existing tree, into its root node.
RYML_EXPORT void parse_json_in_arena(Parser *parser,                   csubstr json, Tree *t                 ); ///< (4) like (3) but no filename will be reported
RYML_EXPORT void parse_json_in_arena(Parser *parser, csubstr filename, csubstr json, NodeRef node            ); ///< (5) like (1) but the node is given as a NodeRef
RYML_EXPORT void parse_json_in_arena(Parser *parser,                   csubstr json, NodeRef node            ); ///< (6) like (5) but no filename will be reported
RYML_EXPORT Tree parse_json_in_arena(Parser *parser, csubstr filename, csubstr json                          ); ///< (7) create a new tree, and parse JSON into its root node.
RYML_EXPORT Tree parse_json_in_arena(Parser *parser,                   csubstr json                          ); ///< (8) like (7) but no filename will be reported

/* READ THE DEPRECATION NOTE!
 *
 * All of the functions below are intentionally left undefined, to
 * prevent them being used.
 *
 */
/** @cond dev */
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(Parser *parser,                   substr yaml, Tree *t, id_type node_id);
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(Parser *parser, csubstr filename, substr yaml, Tree *t, id_type node_id);
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(Parser *parser,                   substr yaml, Tree *t                 );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(Parser *parser, csubstr filename, substr yaml, Tree *t                 );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(Parser *parser,                   substr yaml, NodeRef node            );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(Parser *parser, csubstr filename, substr yaml, NodeRef node            );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) Tree parse_in_arena(Parser *parser,                   substr yaml                          );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) Tree parse_in_arena(Parser *parser, csubstr filename, substr yaml                          );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(Parser *parser,                   substr json, Tree *t, id_type node_id);
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(Parser *parser, csubstr filename, substr json, Tree *t, id_type node_id);
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(Parser *parser,                   substr json, Tree *t                 );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(Parser *parser, csubstr filename, substr json, Tree *t                 );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(Parser *parser,                   substr json, NodeRef node            );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(Parser *parser, csubstr filename, substr json, NodeRef node            );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) Tree parse_json_in_arena(Parser *parser,                   substr json                          );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) Tree parse_json_in_arena(Parser *parser, csubstr filename, substr json                          );
/** @endcond */

/** @} */


//-----------------------------------------------------------------------------


/** @defgroup doc_parse_in_arena__with_temporary_parser Parse in arena with temporary parser
 *
 * @brief parse a read-only (immutable) YAML source buffer. This is
 * achieved by first copying the contents of the buffer to the tree's
 * arena, and then calling @ref parse_in_arena() .
 *
 * @note These freestanding functions use a temporary parser object,
 * and are convenience functions to easily one-off parse YAML without
 * the need to instantiate a separate parser. Note that some
 * properties (notably node locations in the original source code) are
 * only available through the parser class. If you need access to any
 * of these properties, use the appropriate overload from @ref
 * doc_parse_in_arena__with_existing_parser
 *
 * @warning overloads receiving a substr YAML buffer are intentionally
 * left undefined, such that calling parse_in_arena() with a substr
 * will cause a linker error. This is to prevent an accidental copy of
 * the source buffer to the tree's arena, because substr (which is
 * mutable) is implicitly convertible to csubstr (which is
 * immutable). If you really intend to parse a mutable buffer in the
 * tree's arena, convert it first to immutable by assigning the substr
 * to a csubstr prior to calling parse_in_arena(). This is not needed
 * for parse_in_place() because csubstr is not implicitly convertible
 * to substr. To be clear:
 * ```c++
 * substr mutable_buffer = ...;
 * parser.parse_in_arena(mutable_buffer); // linker error
 *
 * csubstr immutable_buffer = ...;
 * parser.parse_in_arena(immutable_buffer); // ok
 * ```
 *
 * @{
 */

// this is vertically aligned to highlight the parameter differences.
RYML_EXPORT void parse_in_arena(csubstr filename, csubstr yaml, Tree *t, id_type node_id); ///< (1) parse YAML into an existing tree node. The filename will be used in any error messages arising during the parse.
RYML_EXPORT void parse_in_arena(                  csubstr yaml, Tree *t, id_type node_id); ///< (2) like (1) but no filename will be reported
RYML_EXPORT void parse_in_arena(csubstr filename, csubstr yaml, Tree *t                 ); ///< (3) parse YAML into an existing tree, into its root node.
RYML_EXPORT void parse_in_arena(                  csubstr yaml, Tree *t                 ); ///< (4) like (3) but no filename will be reported
RYML_EXPORT void parse_in_arena(csubstr filename, csubstr yaml, NodeRef node            ); ///< (5) like (1) but the node is given as a NodeRef
RYML_EXPORT void parse_in_arena(                  csubstr yaml, NodeRef node            ); ///< (6) like (5) but no filename will be reported
RYML_EXPORT Tree parse_in_arena(csubstr filename, csubstr yaml                          ); ///< (7) create a new tree, and parse YAML into its root node.
RYML_EXPORT Tree parse_in_arena(                  csubstr yaml                          ); ///< (8) like (7) but no filename will be reported

// this is vertically aligned to highlight the parameter differences.
RYML_EXPORT void parse_json_in_arena(csubstr filename, csubstr json, Tree *t, id_type node_id); ///< (1) parse JSON into an existing tree node. The filename will be used in any error messages arising during the parse.
RYML_EXPORT void parse_json_in_arena(                  csubstr json, Tree *t, id_type node_id); ///< (2) like (1) but no filename will be reported
RYML_EXPORT void parse_json_in_arena(csubstr filename, csubstr json, Tree *t                 ); ///< (3) parse JSON into an existing tree, into its root node.
RYML_EXPORT void parse_json_in_arena(                  csubstr json, Tree *t                 ); ///< (4) like (3) but no filename will be reported
RYML_EXPORT void parse_json_in_arena(csubstr filename, csubstr json, NodeRef node            ); ///< (5) like (1) but the node is given as a NodeRef
RYML_EXPORT void parse_json_in_arena(                  csubstr json, NodeRef node            ); ///< (6) like (5) but no filename will be reported
RYML_EXPORT Tree parse_json_in_arena(csubstr filename, csubstr json                          ); ///< (7) create a new tree, and parse JSON into its root node.
RYML_EXPORT Tree parse_json_in_arena(                  csubstr json                          ); ///< (8) like (7) but no filename will be reported

/* READ THE DEPRECATION NOTE!
 *
 * All of the functions below are intentionally left undefined, to
 * prevent them being used.
 */
/** @cond dev */
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(                  substr yaml, Tree *t, id_type node_id);
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(csubstr filename, substr yaml, Tree *t, id_type node_id);
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(                  substr yaml, Tree *t                 );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(csubstr filename, substr yaml, Tree *t                 );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(                  substr yaml, NodeRef node            );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_in_arena(csubstr filename, substr yaml, NodeRef node            );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) Tree parse_in_arena(                  substr yaml                          );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) Tree parse_in_arena(csubstr filename, substr yaml                          );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(                  substr json, Tree *t, id_type node_id);
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(csubstr filename, substr json, Tree *t, id_type node_id);
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(                  substr json, Tree *t                 );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(csubstr filename, substr json, Tree *t                 );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(                  substr json, NodeRef node            );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) void parse_json_in_arena(csubstr filename, substr json, NodeRef node            );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) Tree parse_json_in_arena(                  substr json                          );
RYML_DEPRECATED(RYML_DONT_PARSE_SUBSTR_IN_ARENA) Tree parse_json_in_arena(csubstr filename, substr json                          );
/** @endcond */

/** @} */
/** @} */

} // namespace yml
} // namespace c4

#endif /* _C4_YML_PARSE_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/parse.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/std/map.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/std/map.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_STD_MAP_HPP_
#define _C4_YML_STD_MAP_HPP_

/** @file map.hpp write/read std::map to/from a YAML tree. */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/node.hpp
//#include "c4/yml/node.hpp"
#if !defined(C4_YML_NODE_HPP_) && !defined(_C4_YML_NODE_HPP_)
#error "amalgamate: file c4/yml/node.hpp must have been included at this point"
#endif /* C4_YML_NODE_HPP_ */

#include <map>

namespace c4 {
namespace yml {

// std::map requires child nodes in the data
// tree hierarchy (a MAP node in ryml parlance).
// So it should be serialized via write()/read().

template<class K, class V, class Less, class Alloc>
void write(c4::yml::NodeRef *n, std::map<K, V, Less, Alloc> const& m)
{
    *n |= c4::yml::MAP;
    for(auto const& C4_RESTRICT p : m)
    {
        auto ch = n->append_child();
        ch << c4::yml::key(p.first);
        ch << p.second;
    }
}

template<class K, class V, class Less, class Alloc>
bool read(c4::yml::ConstNodeRef const& n, std::map<K, V, Less, Alloc> * m)
{
    K k{};
    V v{};
    for(auto const& C4_RESTRICT ch : n)
    {
        ch >> c4::yml::key(k);
        ch >> v;
        m->emplace(std::make_pair(std::move(k), std::move(v)));
    }
    return true;
}

} // namespace yml
} // namespace c4

#endif // _C4_YML_STD_MAP_HPP_


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/std/map.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/std/string.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/std/string.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef C4_YML_STD_STRING_HPP_
#define C4_YML_STD_STRING_HPP_

/** @file string.hpp substring conversions for/from std::string */

// everything we need is implemented here:
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/std/string.hpp
//#include <c4/std/string.hpp>
#if !defined(C4_STD_STRING_HPP_) && !defined(_C4_STD_STRING_HPP_)
#error "amalgamate: file c4/std/string.hpp must have been included at this point"
#endif /* C4_STD_STRING_HPP_ */


#endif // C4_YML_STD_STRING_HPP_


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/std/string.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/std/vector.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/std/vector.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_STD_VECTOR_HPP_
#define _C4_YML_STD_VECTOR_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/node.hpp
//#include "c4/yml/node.hpp"
#if !defined(C4_YML_NODE_HPP_) && !defined(_C4_YML_NODE_HPP_)
#error "amalgamate: file c4/yml/node.hpp must have been included at this point"
#endif /* C4_YML_NODE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/std/vector.hpp
//#include <c4/std/vector.hpp>
#if !defined(C4_STD_VECTOR_HPP_) && !defined(_C4_STD_VECTOR_HPP_)
#error "amalgamate: file c4/std/vector.hpp must have been included at this point"
#endif /* C4_STD_VECTOR_HPP_ */

#include <vector>

namespace c4 {
namespace yml {

// vector is a sequence-like type, and it requires child nodes
// in the data tree hierarchy (a SEQ node in ryml parlance).
// So it should be serialized via write()/read().


template<class V, class Alloc>
void write(c4::yml::NodeRef *n, std::vector<V, Alloc> const& vec)
{
    *n |= c4::yml::SEQ;
    for(V const& v : vec)
        n->append_child() << v;
}

template<class V, class Alloc>
bool read(c4::yml::ConstNodeRef const& n, std::vector<V, Alloc> *vec)
{
    C4_SUPPRESS_WARNING_GCC_WITH_PUSH("-Wuseless-cast")
    vec->resize(static_cast<size_t>(n.num_children()));
    C4_SUPPRESS_WARNING_GCC_POP
    size_t pos = 0;
    for(ConstNodeRef const child : n)
        child >> (*vec)[pos++];
    return true;
}

/** specialization: std::vector<bool> uses std::vector<bool>::reference as
 * the return value of its operator[]. */
template<class Alloc>
bool read(c4::yml::ConstNodeRef const& n, std::vector<bool, Alloc> *vec)
{
    C4_SUPPRESS_WARNING_GCC_WITH_PUSH("-Wuseless-cast")
    vec->resize(static_cast<size_t>(n.num_children()));
    C4_SUPPRESS_WARNING_GCC_POP
    size_t pos = 0;
    bool tmp = {};
    for(ConstNodeRef const child : n)
    {
        child >> tmp;
        (*vec)[pos++] = tmp;
    }
    return true;
}

} // namespace yml
} // namespace c4

#endif // _C4_YML_STD_VECTOR_HPP_


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/std/vector.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/std/std.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/std/std.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_STD_STD_HPP_
#define _C4_YML_STD_STD_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/std/string.hpp
//#include "c4/yml/std/string.hpp"
#if !defined(C4_YML_STD_STRING_HPP_) && !defined(_C4_YML_STD_STRING_HPP_)
#error "amalgamate: file c4/yml/std/string.hpp must have been included at this point"
#endif /* C4_YML_STD_STRING_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/std/vector.hpp
//#include "c4/yml/std/vector.hpp"
#if !defined(C4_YML_STD_VECTOR_HPP_) && !defined(_C4_YML_STD_VECTOR_HPP_)
#error "amalgamate: file c4/yml/std/vector.hpp must have been included at this point"
#endif /* C4_YML_STD_VECTOR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/std/map.hpp
//#include "c4/yml/std/map.hpp"
#if !defined(C4_YML_STD_MAP_HPP_) && !defined(_C4_YML_STD_MAP_HPP_)
#error "amalgamate: file c4/yml/std/map.hpp must have been included at this point"
#endif /* C4_YML_STD_MAP_HPP_ */


#endif // _C4_YML_STD_STD_HPP_


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/std/std.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/version.cpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/version.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef RYML_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/version.hpp
//#include "c4/yml/version.hpp"
#if !defined(C4_YML_VERSION_HPP_) && !defined(_C4_YML_VERSION_HPP_)
#error "amalgamate: file c4/yml/version.hpp must have been included at this point"
#endif /* C4_YML_VERSION_HPP_ */


namespace c4 {
namespace yml {

csubstr version()
{
  return RYML_VERSION;
}

int version_major()
{
  return RYML_VERSION_MAJOR;
}

int version_minor()
{
  return RYML_VERSION_MINOR;
}

int version_patch()
{
  return RYML_VERSION_PATCH;
}

} // namespace yml
} // namespace c4

#endif /* RYML_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/version.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/common.cpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/common.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef RYML_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/common.hpp
//#include "c4/yml/common.hpp"
#if !defined(C4_YML_COMMON_HPP_) && !defined(_C4_YML_COMMON_HPP_)
#error "amalgamate: file c4/yml/common.hpp must have been included at this point"
#endif /* C4_YML_COMMON_HPP_ */


#ifndef RYML_NO_DEFAULT_CALLBACKS
#   include <stdlib.h>
//included above:
//#   include <stdio.h>
#   ifdef RYML_DEFAULT_CALLBACK_USES_EXCEPTIONS
#       include <stdexcept>
#   endif
#endif // RYML_NO_DEFAULT_CALLBACKS


namespace c4 {
namespace yml {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")
C4_SUPPRESS_WARNING_MSVC_WITH_PUSH(4702/*unreachable code*/) // on the call to the unreachable macro

namespace {
Callbacks s_default_callbacks;
} // anon namespace

#ifndef RYML_NO_DEFAULT_CALLBACKS
void report_error_impl(const char* msg, size_t length, Location loc, FILE *f)
{
    if(!f)
        f = stderr;
    if(loc)
    {
        if(!loc.name.empty())
        {
            // this is more portable than using fprintf("%.*s:") which
            // is not available in some embedded platforms
            fwrite(loc.name.str, 1, loc.name.len, f);
            fputc(':', f);
        }
        fprintf(f, "%zu:", loc.line);
        if(loc.col)
            fprintf(f, "%zu:", loc.col);
        if(loc.offset)
            fprintf(f, " (%zuB):", loc.offset);
        fputc(' ', f);
    }
    RYML_ASSERT(!csubstr(msg, length).ends_with('\0'));
    fwrite(msg, 1, length, f);
    fputc('\n', f);
    fflush(f);
}

[[noreturn]] void error_impl(const char* msg, size_t length, Location loc, void * /*user_data*/)
{
    RYML_ASSERT(!csubstr(msg, length).ends_with('\0'));
    report_error_impl(msg, length, loc, nullptr);
#ifdef RYML_DEFAULT_CALLBACK_USES_EXCEPTIONS
    throw std::runtime_error(std::string(msg, length));
#else
    ::abort();
#endif
}

void* allocate_impl(size_t length, void * /*hint*/, void * /*user_data*/)
{
    void *mem = ::malloc(length);
    if(mem == nullptr)
    {
        const char msg[] = "could not allocate memory";
        error_impl(msg, sizeof(msg)-1, {}, nullptr);
    }
    return mem;
}

void free_impl(void *mem, size_t /*length*/, void * /*user_data*/)
{
    ::free(mem);
}
#endif // RYML_NO_DEFAULT_CALLBACKS



Callbacks::Callbacks()
    :
    m_user_data(nullptr),
    #ifndef RYML_NO_DEFAULT_CALLBACKS
    m_allocate(allocate_impl),
    m_free(free_impl),
    m_error(error_impl)
    #else
    m_allocate(nullptr),
    m_free(nullptr),
    m_error(nullptr)
    #endif
{
}

Callbacks::Callbacks(void *user_data, pfn_allocate alloc_, pfn_free free_, pfn_error error_)
    :
    m_user_data(user_data),
    #ifndef RYML_NO_DEFAULT_CALLBACKS
    m_allocate(alloc_ ? alloc_ : allocate_impl),
    m_free(free_ ? free_ : free_impl),
    m_error((error_ ? error_ : error_impl))
    #else
    m_allocate(alloc_),
    m_free(free_),
    m_error(error_)
    #endif
{
    RYML_CHECK(m_allocate);
    RYML_CHECK(m_free);
    RYML_CHECK(m_error);
}


void set_callbacks(Callbacks const& c)
{
    s_default_callbacks = c;
}

Callbacks const& get_callbacks()
{
    return s_default_callbacks;
}

void reset_callbacks()
{
    set_callbacks(Callbacks());
}

// the [[noreturn]] attribute needs to be here as well (UB otherwise)
// https://en.cppreference.com/w/cpp/language/attributes/noreturn
[[noreturn]] void error(Callbacks const& cb, const char *msg, size_t msg_len, Location loc)
{
    cb.m_error(msg, msg_len, loc, cb.m_user_data);
    abort(); // call abort in case the error callback didn't interrupt execution
    C4_UNREACHABLE();
}

// the [[noreturn]] attribute needs to be here as well (UB otherwise)
// see https://en.cppreference.com/w/cpp/language/attributes/noreturn
[[noreturn]] void error(const char *msg, size_t msg_len, Location loc)
{
    error(s_default_callbacks, msg, msg_len, loc);
    C4_UNREACHABLE();
}

C4_SUPPRESS_WARNING_MSVC_POP
C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace yml
} // namespace c4

#endif /* RYML_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/common.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/node_type.cpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/node_type.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef RYML_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/node_type.hpp
//#include "c4/yml/node_type.hpp"
#if !defined(C4_YML_NODE_TYPE_HPP_) && !defined(_C4_YML_NODE_TYPE_HPP_)
#error "amalgamate: file c4/yml/node_type.hpp must have been included at this point"
#endif /* C4_YML_NODE_TYPE_HPP_ */


namespace c4 {
namespace yml {

const char* NodeType::type_str(NodeType_e ty) noexcept
{
    switch(ty & _TYMASK)
    {
    case KEYVAL:
        return "KEYVAL";
    case KEY:
        return "KEY";
    case VAL:
        return "VAL";
    case MAP:
        return "MAP";
    case SEQ:
        return "SEQ";
    case KEYMAP:
        return "KEYMAP";
    case KEYSEQ:
        return "KEYSEQ";
    case DOCSEQ:
        return "DOCSEQ";
    case DOCMAP:
        return "DOCMAP";
    case DOCVAL:
        return "DOCVAL";
    case DOC:
        return "DOC";
    case STREAM:
        return "STREAM";
    case NOTYPE:
        return "NOTYPE";
    default:
        if((ty & KEYVAL) == KEYVAL)
            return "KEYVAL***";
        if((ty & KEYMAP) == KEYMAP)
            return "KEYMAP***";
        if((ty & KEYSEQ) == KEYSEQ)
            return "KEYSEQ***";
        if((ty & DOCSEQ) == DOCSEQ)
            return "DOCSEQ***";
        if((ty & DOCMAP) == DOCMAP)
            return "DOCMAP***";
        if((ty & DOCVAL) == DOCVAL)
            return "DOCVAL***";
        if(ty & KEY)
            return "KEY***";
        if(ty & VAL)
            return "VAL***";
        if(ty & MAP)
            return "MAP***";
        if(ty & SEQ)
            return "SEQ***";
        if(ty & DOC)
            return "DOC***";
        return "(unk)";
    }
}

csubstr NodeType::type_str(substr buf, NodeType_e flags) noexcept
{
    size_t pos = 0;
    bool gotone = false;

    #define _prflag(fl, txt)                                    \
    do {                                                        \
        if((flags & fl) == (fl))                                \
        {                                                       \
            if(gotone)                                          \
            {                                                   \
                if(pos + 1 < buf.len)                           \
                    buf[pos] = '|';                             \
                ++pos;                                          \
            }                                                   \
            csubstr fltxt = txt;                                \
            if(pos + fltxt.len <= buf.len)                      \
                memcpy(buf.str + pos, fltxt.str, fltxt.len);    \
            pos += fltxt.len;                                   \
            gotone = true;                                      \
            flags = (flags & ~fl); /*remove the flag*/          \
        }                                                       \
    } while(0)

    _prflag(STREAM, "STREAM");
    _prflag(DOC, "DOC");
    // key properties
    _prflag(KEY, "KEY");
    _prflag(KEYTAG, "KTAG");
    _prflag(KEYANCH, "KANCH");
    _prflag(KEYREF, "KREF");
    _prflag(KEY_LITERAL, "KLITERAL");
    _prflag(KEY_FOLDED, "KFOLDED");
    _prflag(KEY_SQUO, "KSQUO");
    _prflag(KEY_DQUO, "KDQUO");
    _prflag(KEY_PLAIN, "KPLAIN");
    _prflag(KEY_UNFILT, "KUNFILT");
    // val properties
    _prflag(VAL, "VAL");
    _prflag(VALTAG, "VTAG");
    _prflag(VALANCH, "VANCH");
    _prflag(VALREF, "VREF");
    _prflag(VAL_UNFILT, "VUNFILT");
    _prflag(VAL_LITERAL, "VLITERAL");
    _prflag(VAL_FOLDED, "VFOLDED");
    _prflag(VAL_SQUO, "VSQUO");
    _prflag(VAL_DQUO, "VDQUO");
    _prflag(VAL_PLAIN, "VPLAIN");
    _prflag(VAL_UNFILT, "VUNFILT");
    // container properties
    _prflag(MAP, "MAP");
    _prflag(SEQ, "SEQ");
    _prflag(FLOW_SL, "FLOWSL");
    _prflag(FLOW_ML, "FLOWML");
    _prflag(BLOCK, "BLCK");
    if(pos == 0)
        _prflag(NOTYPE, "NOTYPE");

    #undef _prflag

    if(pos < buf.len)
    {
        buf[pos] = '\0';
        return buf.first(pos);
    }
    else
    {
        csubstr failed;
        failed.len = pos + 1;
        failed.str = nullptr;
        return failed;
    }
}


//-----------------------------------------------------------------------------

// see https://www.yaml.info/learn/quote.html#noplain
bool scalar_style_query_squo(csubstr s) noexcept
{
    return ! s.first_of_any("\n ", "\n\t");
}

// see https://www.yaml.info/learn/quote.html#noplain
bool scalar_style_query_plain(csubstr s) noexcept
{
    if(s.begins_with("-."))
    {
        if(s == "-.inf" || s == "-.INF")
            return true;
        else if(s.sub(2).is_number())
            return true;
    }
    else if(s.begins_with_any("0123456789.-+") && s.is_number())
    {
        return true;
    }
    return s != ':'
        && ( ! s.begins_with_any("-:?*&,'\"{}[]|>%#@`\r")) // @ and ` are reserved characters
        && ( ! s.ends_with_any(":#"))
             // make this check in the last place, as it has linear
             // complexity, while the previous ones are
             // constant-time
        && (s.first_of("\n#:[]{},") == npos);
}

NodeType_e scalar_style_choose(csubstr s) noexcept
{
    if(s.len)
    {
        if(s.begins_with_any(" \n\t")
           ||
           s.ends_with_any(" \n\t"))
        {
            return SCALAR_DQUO;
        }
        else if( ! scalar_style_query_plain(s))
        {
            return scalar_style_query_squo(s) ? SCALAR_SQUO : SCALAR_DQUO;
        }
        // nothing remarkable - use plain
        return SCALAR_PLAIN;
    }
    return s.str ? SCALAR_SQUO : SCALAR_PLAIN;
}

NodeType_e scalar_style_json_choose(csubstr s) noexcept
{
    // do not quote special cases
    bool plain = (
        (s == "true" || s == "false" || s == "null")
        ||
        (
            // do not quote numbers
            s.is_number()
            &&
            (
                // quote integral numbers if they have a leading 0
                // https://github.com/biojppm/rapidyaml/issues/291
                (!(s.len > 1 && s.begins_with('0')))
                // do not quote reals with leading 0
                // https://github.com/biojppm/rapidyaml/issues/313
                || (s.find('.') != csubstr::npos)
            )
        )
    );
    return plain ? SCALAR_PLAIN : SCALAR_DQUO;
}

} // namespace yml
} // namespace c4

#endif /* RYML_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/node_type.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/tag.cpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/tag.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef RYML_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/tag.hpp
//#include "c4/yml/tag.hpp"
#if !defined(C4_YML_TAG_HPP_) && !defined(_C4_YML_TAG_HPP_)
#error "amalgamate: file c4/yml/tag.hpp must have been included at this point"
#endif /* C4_YML_TAG_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/tree.hpp
//#include "c4/yml/tree.hpp"
#if !defined(C4_YML_TREE_HPP_) && !defined(_C4_YML_TREE_HPP_)
#error "amalgamate: file c4/yml/tree.hpp must have been included at this point"
#endif /* C4_YML_TREE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/parser_dbg.hpp
//#include "c4/yml/detail/parser_dbg.hpp"
#if !defined(C4_YML_DETAIL_PARSER_DBG_HPP_) && !defined(_C4_YML_DETAIL_PARSER_DBG_HPP_)
#error "amalgamate: file c4/yml/detail/parser_dbg.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PARSER_DBG_HPP_ */



namespace c4 {
namespace yml {

bool is_custom_tag(csubstr tag)
{
    if((tag.len > 2) && (tag.str[0] == '!'))
    {
        size_t pos = tag.find('!', 1);
        return pos != npos && pos > 1 && tag.str[1] != '<';
    }
    return false;
}

csubstr normalize_tag(csubstr tag)
{
    YamlTag_e t = to_tag(tag);
    if(t != TAG_NONE)
        return from_tag(t);
    if(tag.begins_with("!<"))
        tag = tag.sub(1);
    if(tag.begins_with("<!"))
        return tag;
    return tag;
}

csubstr normalize_tag_long(csubstr tag)
{
    YamlTag_e t = to_tag(tag);
    if(t != TAG_NONE)
        return from_tag_long(t);
    if(tag.begins_with("!<"))
        tag = tag.sub(1);
    if(tag.begins_with("<!"))
        return tag;
    return tag;
}

csubstr normalize_tag_long(csubstr tag, substr output)
{
    csubstr result = normalize_tag_long(tag);
    if(result.begins_with("!!"))
    {
        tag = tag.sub(2);
        const csubstr pfx = "<tag:yaml.org,2002:";
        const size_t len = pfx.len + tag.len + 1;
        if(len <= output.len)
        {
            memcpy(output.str          , pfx.str, pfx.len);
            memcpy(output.str + pfx.len, tag.str, tag.len);
            output[pfx.len + tag.len] = '>';
            result = output.first(len);
        }
        else
        {
            result.str = nullptr;
            result.len = len;
        }
    }
    return result;
}

YamlTag_e to_tag(csubstr tag)
{
    if(tag.begins_with("!<"))
        tag = tag.sub(1);
    if(tag.begins_with("!!"))
        tag = tag.sub(2);
    else if(tag.begins_with('!'))
        return TAG_NONE;
    else if(tag.begins_with("tag:yaml.org,2002:"))
    {
        RYML_ASSERT(csubstr("tag:yaml.org,2002:").len == 18);
        tag = tag.sub(18);
    }
    else if(tag.begins_with("<tag:yaml.org,2002:"))
    {
        RYML_ASSERT(csubstr("<tag:yaml.org,2002:").len == 19);
        tag = tag.sub(19);
        if(!tag.len)
            return TAG_NONE;
        tag = tag.offs(0, 1);
    }

    if(tag == "map")
        return TAG_MAP;
    else if(tag == "omap")
        return TAG_OMAP;
    else if(tag == "pairs")
        return TAG_PAIRS;
    else if(tag == "set")
        return TAG_SET;
    else if(tag == "seq")
        return TAG_SEQ;
    else if(tag == "binary")
        return TAG_BINARY;
    else if(tag == "bool")
        return TAG_BOOL;
    else if(tag == "float")
        return TAG_FLOAT;
    else if(tag == "int")
        return TAG_INT;
    else if(tag == "merge")
        return TAG_MERGE;
    else if(tag == "null")
        return TAG_NULL;
    else if(tag == "str")
        return TAG_STR;
    else if(tag == "timestamp")
        return TAG_TIMESTAMP;
    else if(tag == "value")
        return TAG_VALUE;
    else if(tag == "yaml")
        return TAG_YAML;

    return TAG_NONE;
}

csubstr from_tag_long(YamlTag_e tag)
{
    switch(tag)
    {
    case TAG_MAP:
        return {"<tag:yaml.org,2002:map>"};
    case TAG_OMAP:
        return {"<tag:yaml.org,2002:omap>"};
    case TAG_PAIRS:
        return {"<tag:yaml.org,2002:pairs>"};
    case TAG_SET:
        return {"<tag:yaml.org,2002:set>"};
    case TAG_SEQ:
        return {"<tag:yaml.org,2002:seq>"};
    case TAG_BINARY:
        return {"<tag:yaml.org,2002:binary>"};
    case TAG_BOOL:
        return {"<tag:yaml.org,2002:bool>"};
    case TAG_FLOAT:
        return {"<tag:yaml.org,2002:float>"};
    case TAG_INT:
        return {"<tag:yaml.org,2002:int>"};
    case TAG_MERGE:
        return {"<tag:yaml.org,2002:merge>"};
    case TAG_NULL:
        return {"<tag:yaml.org,2002:null>"};
    case TAG_STR:
        return {"<tag:yaml.org,2002:str>"};
    case TAG_TIMESTAMP:
        return {"<tag:yaml.org,2002:timestamp>"};
    case TAG_VALUE:
        return {"<tag:yaml.org,2002:value>"};
    case TAG_YAML:
        return {"<tag:yaml.org,2002:yaml>"};
    case TAG_NONE:
    default:
        return {""};
    }
}

csubstr from_tag(YamlTag_e tag)
{
    switch(tag)
    {
    case TAG_MAP:
        return {"!!map"};
    case TAG_OMAP:
        return {"!!omap"};
    case TAG_PAIRS:
        return {"!!pairs"};
    case TAG_SET:
        return {"!!set"};
    case TAG_SEQ:
        return {"!!seq"};
    case TAG_BINARY:
        return {"!!binary"};
    case TAG_BOOL:
        return {"!!bool"};
    case TAG_FLOAT:
        return {"!!float"};
    case TAG_INT:
        return {"!!int"};
    case TAG_MERGE:
        return {"!!merge"};
    case TAG_NULL:
        return {"!!null"};
    case TAG_STR:
        return {"!!str"};
    case TAG_TIMESTAMP:
        return {"!!timestamp"};
    case TAG_VALUE:
        return {"!!value"};
    case TAG_YAML:
        return {"!!yaml"};
    case TAG_NONE:
    default:
        return {""};
    }
}


bool TagDirective::create_from_str(csubstr directive_)
{
    csubstr directive = directive_;
    directive = directive.sub(4);
    if(!directive.begins_with(' '))
        return false;
    directive = directive.triml(' ');
    size_t pos = directive.find(' ');
    if(pos == npos)
        return false;
    handle = directive.first(pos);
    directive = directive.sub(handle.len).triml(' ');
    pos = directive.find(' ');
    if(pos != npos)
        directive = directive.first(pos);
    prefix = directive;
    next_node_id = NONE;
    _c4dbgpf("%TAG: handle={} prefix={}", handle, prefix);
    return true;
}

bool TagDirective::create_from_str(csubstr directive_, Tree *tree)
{
    _RYML_CB_CHECK(tree->callbacks(), directive_.begins_with("%TAG "));
    if(!create_from_str(directive_))
    {
        _RYML_CB_ERR(tree->callbacks(), "invalid tag directive");
    }
    next_node_id = tree->size();
    if(tree->size() > 0)
    {
        const id_type prev = tree->size() - 1;
        if(tree->is_root(prev) && tree->type(prev) != NOTYPE && !tree->is_stream(prev))
            ++next_node_id;
    }
    _c4dbgpf("%TAG: handle={} prefix={} next_node={}", handle, prefix, next_node_id);
    return true;
}

size_t TagDirective::transform(csubstr tag, substr output, Callbacks const& callbacks) const
{
    _c4dbgpf("%TAG: handle={} prefix={} next_node={}. tag={}", handle, prefix, next_node_id, tag);
    _RYML_CB_ASSERT(callbacks, tag.len >= handle.len);
    csubstr rest = tag.sub(handle.len);
    _c4dbgpf("%TAG: rest={}", rest);
    if(rest.begins_with('<'))
    {
        _c4dbgpf("%TAG: begins with <. rest={}", rest);
        if(C4_UNLIKELY(!rest.ends_with('>')))
            _RYML_CB_ERR(callbacks, "malformed tag");
        rest = rest.offs(1, 1);
        if(rest.begins_with(prefix))
        {
            _c4dbgpf("%TAG: already transformed! actual={}", rest.sub(prefix.len));
            return 0; // return 0 to signal that the tag is local and cannot be resolved
        }
    }
    size_t len = 1u + prefix.len + rest.len + 1u;
    size_t numpc = rest.count('%');
    if(numpc == 0)
    {
        if(len <= output.len)
        {
            output.str[0] = '<';
            memcpy(1u + output.str, prefix.str, prefix.len);
            memcpy(1u + output.str + prefix.len, rest.str, rest.len);
            output.str[1u + prefix.len + rest.len] = '>';
        }
    }
    else
    {
        // need to decode URI % sequences
        size_t pos = rest.find('%');
        _RYML_CB_ASSERT(callbacks, pos != npos);
        do {
            size_t next = rest.first_not_of("0123456789abcdefABCDEF", pos+1);
            if(next == npos)
                next = rest.len;
            _RYML_CB_CHECK(callbacks, pos+1 < next);
            _RYML_CB_CHECK(callbacks, pos+1 + 2 <= next);
            size_t delta = next - (pos+1);
            len -= delta;
            pos = rest.find('%', pos+1);
        } while(pos != npos);
        if(len <= output.len)
        {
            size_t prev = 0, wpos = 0;
            auto appendstr = [&](csubstr s) { memcpy(output.str + wpos, s.str, s.len); wpos += s.len; };
            auto appendchar = [&](char c) { output.str[wpos++] = c; };
            appendchar('<');
            appendstr(prefix);
            pos = rest.find('%');
            _RYML_CB_ASSERT(callbacks, pos != npos);
            do {
                size_t next = rest.first_not_of("0123456789abcdefABCDEF", pos+1);
                if(next == npos)
                    next = rest.len;
                _RYML_CB_CHECK(callbacks, pos+1 < next);
                _RYML_CB_CHECK(callbacks, pos+1 + 2 <= next);
                uint8_t val;
                if(C4_UNLIKELY(!read_hex(rest.range(pos+1, next), &val) || val > 127))
                    _RYML_CB_ERR(callbacks, "invalid URI character");
                appendstr(rest.range(prev, pos));
                appendchar(static_cast<char>(val));
                prev = next;
                pos = rest.find('%', pos+1);
            } while(pos != npos);
            _RYML_CB_ASSERT(callbacks, pos == npos);
            _RYML_CB_ASSERT(callbacks, prev > 0);
            _RYML_CB_ASSERT(callbacks, rest.len >= prev);
            appendstr(rest.sub(prev));
            appendchar('>');
            _RYML_CB_ASSERT(callbacks, wpos == len);
        }
    }
    return len;
}

} // namespace yml
} // namespace c4

#endif /* RYML_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/tag.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/tree.cpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/tree.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef RYML_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/tree.hpp
//#include "c4/yml/tree.hpp"
#if !defined(C4_YML_TREE_HPP_) && !defined(_C4_YML_TREE_HPP_)
#error "amalgamate: file c4/yml/tree.hpp must have been included at this point"
#endif /* C4_YML_TREE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/parser_dbg.hpp
//#include "c4/yml/detail/parser_dbg.hpp"
#if !defined(C4_YML_DETAIL_PARSER_DBG_HPP_) && !defined(_C4_YML_DETAIL_PARSER_DBG_HPP_)
#error "amalgamate: file c4/yml/detail/parser_dbg.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PARSER_DBG_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/node.hpp
//#include "c4/yml/node.hpp"
#if !defined(C4_YML_NODE_HPP_) && !defined(_C4_YML_NODE_HPP_)
#error "amalgamate: file c4/yml/node.hpp must have been included at this point"
#endif /* C4_YML_NODE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/reference_resolver.hpp
//#include "c4/yml/reference_resolver.hpp"
#if !defined(C4_YML_REFERENCE_RESOLVER_HPP_) && !defined(_C4_YML_REFERENCE_RESOLVER_HPP_)
#error "amalgamate: file c4/yml/reference_resolver.hpp must have been included at this point"
#endif /* C4_YML_REFERENCE_RESOLVER_HPP_ */



C4_SUPPRESS_WARNING_MSVC_WITH_PUSH(4296/*expression is always 'boolean_value'*/)
C4_SUPPRESS_WARNING_MSVC(4702/*unreachable code*/)
C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")
C4_SUPPRESS_WARNING_GCC("-Wtype-limits")
C4_SUPPRESS_WARNING_GCC("-Wuseless-cast")

namespace c4 {
namespace yml {


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

NodeRef Tree::rootref()
{
    return NodeRef(this, root_id());
}
ConstNodeRef Tree::rootref() const
{
    return ConstNodeRef(this, root_id());
}

ConstNodeRef Tree::crootref() const
{
    return ConstNodeRef(this, root_id());
}

NodeRef Tree::ref(id_type id)
{
    _RYML_CB_ASSERT(m_callbacks, id != NONE && id >= 0 && id < m_cap);
    return NodeRef(this, id);
}
ConstNodeRef Tree::ref(id_type id) const
{
    _RYML_CB_ASSERT(m_callbacks, id != NONE && id >= 0 && id < m_cap);
    return ConstNodeRef(this, id);
}
ConstNodeRef Tree::cref(id_type id) const
{
    _RYML_CB_ASSERT(m_callbacks, id != NONE && id >= 0 && id < m_cap);
    return ConstNodeRef(this, id);
}

NodeRef Tree::operator[] (csubstr key)
{
    return rootref()[key];
}
ConstNodeRef Tree::operator[] (csubstr key) const
{
    return rootref()[key];
}

NodeRef Tree::operator[] (id_type i)
{
    return rootref()[i];
}
ConstNodeRef Tree::operator[] (id_type i) const
{
    return rootref()[i];
}

NodeRef Tree::docref(id_type i)
{
    return ref(doc(i));
}
ConstNodeRef Tree::docref(id_type i) const
{
    return cref(doc(i));
}
ConstNodeRef Tree::cdocref(id_type i) const
{
    return cref(doc(i));
}


//-----------------------------------------------------------------------------
Tree::Tree(Callbacks const& cb)
    : m_buf(nullptr)
    , m_cap(0)
    , m_size(0)
    , m_free_head(NONE)
    , m_free_tail(NONE)
    , m_arena()
    , m_arena_pos(0)
    , m_callbacks(cb)
    , m_tag_directives()
{
}

Tree::Tree(id_type node_capacity, size_t arena_capacity, Callbacks const& cb)
    : Tree(cb)
{
    reserve(node_capacity);
    reserve_arena(arena_capacity);
}

Tree::~Tree()
{
    _free();
}


Tree::Tree(Tree const& that) : Tree(that.m_callbacks)
{
    _copy(that);
}

Tree& Tree::operator= (Tree const& that)
{
    _free();
    m_callbacks = that.m_callbacks;
    _copy(that);
    return *this;
}

Tree::Tree(Tree && that) noexcept : Tree(that.m_callbacks)
{
    _move(that);
}

Tree& Tree::operator= (Tree && that) RYML_NOEXCEPT
{
    _free();
    m_callbacks = that.m_callbacks;
    _move(that);
    return *this;
}

void Tree::_free()
{
    if(m_buf)
    {
        _RYML_CB_ASSERT(m_callbacks, m_cap > 0);
        _RYML_CB_FREE(m_callbacks, m_buf, NodeData, (size_t)m_cap);
    }
    if(m_arena.str)
    {
        _RYML_CB_ASSERT(m_callbacks, m_arena.len > 0);
        _RYML_CB_FREE(m_callbacks, m_arena.str, char, m_arena.len);
    }
    _clear();
}


C4_SUPPRESS_WARNING_GCC_PUSH
#if defined(__GNUC__) && __GNUC__>= 8
    C4_SUPPRESS_WARNING_GCC_WITH_PUSH("-Wclass-memaccess") // error: ‘void* memset(void*, int, size_t)’ clearing an object of type ‘class c4::yml::Tree’ with no trivial copy-assignment; use assignment or value-initialization instead
#endif

void Tree::_clear()
{
    m_buf = nullptr;
    m_cap = 0;
    m_size = 0;
    m_free_head = 0;
    m_free_tail = 0;
    m_arena = {};
    m_arena_pos = 0;
    for(id_type i = 0; i < RYML_MAX_TAG_DIRECTIVES; ++i)
        m_tag_directives[i] = {};
}

void Tree::_copy(Tree const& that)
{
    _RYML_CB_ASSERT(m_callbacks, m_buf == nullptr);
    _RYML_CB_ASSERT(m_callbacks, m_arena.str == nullptr);
    _RYML_CB_ASSERT(m_callbacks, m_arena.len == 0);
    if(that.m_cap)
    {
        m_buf = _RYML_CB_ALLOC_HINT(m_callbacks, NodeData, (size_t)that.m_cap, that.m_buf);
        memcpy(m_buf, that.m_buf, (size_t)that.m_cap * sizeof(NodeData));
    }
    m_cap = that.m_cap;
    m_size = that.m_size;
    m_free_head = that.m_free_head;
    m_free_tail = that.m_free_tail;
    m_arena_pos = that.m_arena_pos;
    m_arena = that.m_arena;
    if(that.m_arena.str)
    {
        _RYML_CB_ASSERT(m_callbacks, that.m_arena.len > 0);
        substr arena;
        arena.str = _RYML_CB_ALLOC_HINT(m_callbacks, char, that.m_arena.len, that.m_arena.str);
        arena.len = that.m_arena.len;
        _relocate(arena); // does a memcpy of the arena and updates nodes using the old arena
        m_arena = arena;
    }
    for(id_type i = 0; i < RYML_MAX_TAG_DIRECTIVES; ++i)
        m_tag_directives[i] = that.m_tag_directives[i];
}

void Tree::_move(Tree & that) noexcept
{
    _RYML_CB_ASSERT(m_callbacks, m_buf == nullptr);
    _RYML_CB_ASSERT(m_callbacks, m_arena.str == nullptr);
    _RYML_CB_ASSERT(m_callbacks, m_arena.len == 0);
    m_buf = that.m_buf;
    m_cap = that.m_cap;
    m_size = that.m_size;
    m_free_head = that.m_free_head;
    m_free_tail = that.m_free_tail;
    m_arena = that.m_arena;
    m_arena_pos = that.m_arena_pos;
    for(id_type i = 0; i < RYML_MAX_TAG_DIRECTIVES; ++i)
        m_tag_directives[i] = that.m_tag_directives[i];
    that._clear();
}

void Tree::_relocate(substr next_arena)
{
    _RYML_CB_ASSERT(m_callbacks, next_arena.not_empty());
    _RYML_CB_ASSERT(m_callbacks, next_arena.len >= m_arena.len);
    if(m_arena_pos)
        memcpy(next_arena.str, m_arena.str, m_arena_pos);
    for(NodeData *C4_RESTRICT n = m_buf, *e = m_buf + m_cap; n != e; ++n)
    {
        if(in_arena(n->m_key.scalar))
            n->m_key.scalar = _relocated(n->m_key.scalar, next_arena);
        if(in_arena(n->m_key.tag))
            n->m_key.tag = _relocated(n->m_key.tag, next_arena);
        if(in_arena(n->m_key.anchor))
            n->m_key.anchor = _relocated(n->m_key.anchor, next_arena);
        if(in_arena(n->m_val.scalar))
            n->m_val.scalar = _relocated(n->m_val.scalar, next_arena);
        if(in_arena(n->m_val.tag))
            n->m_val.tag = _relocated(n->m_val.tag, next_arena);
        if(in_arena(n->m_val.anchor))
            n->m_val.anchor = _relocated(n->m_val.anchor, next_arena);
    }
    for(TagDirective &C4_RESTRICT td : m_tag_directives)
    {
        if(in_arena(td.prefix))
            td.prefix = _relocated(td.prefix, next_arena);
        if(in_arena(td.handle))
            td.handle = _relocated(td.handle, next_arena);
    }
}


//-----------------------------------------------------------------------------
void Tree::reserve(id_type cap)
{
    if(cap > m_cap)
    {
        NodeData *buf = _RYML_CB_ALLOC_HINT(m_callbacks, NodeData, (size_t)cap, m_buf);
        if(m_buf)
        {
            memcpy(buf, m_buf, (size_t)m_cap * sizeof(NodeData));
            _RYML_CB_FREE(m_callbacks, m_buf, NodeData, (size_t)m_cap);
        }
        id_type first = m_cap, del = cap - m_cap;
        m_cap = cap;
        m_buf = buf;
        _clear_range(first, del);
        if(m_free_head != NONE)
        {
            _RYML_CB_ASSERT(m_callbacks, m_buf != nullptr);
            _RYML_CB_ASSERT(m_callbacks, m_free_tail != NONE);
            m_buf[m_free_tail].m_next_sibling = first;
            m_buf[first].m_prev_sibling = m_free_tail;
            m_free_tail = cap-1;
        }
        else
        {
            _RYML_CB_ASSERT(m_callbacks, m_free_tail == NONE);
            m_free_head = first;
            m_free_tail = cap-1;
        }
        _RYML_CB_ASSERT(m_callbacks, m_free_head == NONE || (m_free_head >= 0 && m_free_head < cap));
        _RYML_CB_ASSERT(m_callbacks, m_free_tail == NONE || (m_free_tail >= 0 && m_free_tail < cap));

        if( ! m_size)
            _claim_root();
    }
}


//-----------------------------------------------------------------------------
void Tree::clear()
{
    _clear_range(0, m_cap);
    m_size = 0;
    if(m_buf)
    {
        _RYML_CB_ASSERT(m_callbacks, m_cap >= 0);
        m_free_head = 0;
        m_free_tail = m_cap-1;
        _claim_root();
    }
    else
    {
        m_free_head = NONE;
        m_free_tail = NONE;
    }
    for(id_type i = 0; i < RYML_MAX_TAG_DIRECTIVES; ++i)
        m_tag_directives[i] = {};
}

void Tree::_claim_root()
{
    id_type r = _claim();
    _RYML_CB_ASSERT(m_callbacks, r == 0);
    _set_hierarchy(r, NONE, NONE);
}


//-----------------------------------------------------------------------------
void Tree::_clear_range(id_type first, id_type num)
{
    if(num == 0)
        return; // prevent overflow when subtracting
    _RYML_CB_ASSERT(m_callbacks, first >= 0 && first + num <= m_cap);
    memset(m_buf + first, 0, (size_t)num * sizeof(NodeData)); // TODO we should not need this
    for(id_type i = first, e = first + num; i < e; ++i)
    {
        _clear(i);
        NodeData *n = m_buf + i;
        n->m_prev_sibling = i - 1;
        n->m_next_sibling = i + 1;
    }
    m_buf[first + num - 1].m_next_sibling = NONE;
}

C4_SUPPRESS_WARNING_GCC_POP


//-----------------------------------------------------------------------------
void Tree::_release(id_type i)
{
    _RYML_CB_ASSERT(m_callbacks, i >= 0 && i < m_cap);

    _rem_hierarchy(i);
    _free_list_add(i);
    _clear(i);

    --m_size;
}

//-----------------------------------------------------------------------------
// add to the front of the free list
void Tree::_free_list_add(id_type i)
{
    _RYML_CB_ASSERT(m_callbacks, i >= 0 && i < m_cap);
    NodeData &C4_RESTRICT w = m_buf[i];

    w.m_parent = NONE;
    w.m_next_sibling = m_free_head;
    w.m_prev_sibling = NONE;
    if(m_free_head != NONE)
        m_buf[m_free_head].m_prev_sibling = i;
    m_free_head = i;
    if(m_free_tail == NONE)
        m_free_tail = m_free_head;
}

void Tree::_free_list_rem(id_type i)
{
    if(m_free_head == i)
        m_free_head = _p(i)->m_next_sibling;
    _rem_hierarchy(i);
}

//-----------------------------------------------------------------------------
id_type Tree::_claim()
{
    if(m_free_head == NONE || m_buf == nullptr)
    {
        id_type sz = 2 * m_cap;
        sz = sz ? sz : 16;
        reserve(sz);
        _RYML_CB_ASSERT(m_callbacks, m_free_head != NONE);
    }

    _RYML_CB_ASSERT(m_callbacks, m_size < m_cap);
    _RYML_CB_ASSERT(m_callbacks, m_free_head >= 0 && m_free_head < m_cap);

    id_type ichild = m_free_head;
    NodeData *child = m_buf + ichild;

    ++m_size;
    m_free_head = child->m_next_sibling;
    if(m_free_head == NONE)
    {
        m_free_tail = NONE;
        _RYML_CB_ASSERT(m_callbacks, m_size == m_cap);
    }

    _clear(ichild);

    return ichild;
}

//-----------------------------------------------------------------------------

C4_SUPPRESS_WARNING_GCC_PUSH
C4_SUPPRESS_WARNING_CLANG_PUSH
C4_SUPPRESS_WARNING_CLANG("-Wnull-dereference")
#if defined(__GNUC__)
#if (__GNUC__ >= 6)
C4_SUPPRESS_WARNING_GCC("-Wnull-dereference")
#endif
#if (__GNUC__ > 9)
C4_SUPPRESS_WARNING_GCC("-Wanalyzer-fd-leak")
#endif
#endif

void Tree::_set_hierarchy(id_type ichild, id_type iparent, id_type iprev_sibling)
{
    _RYML_CB_ASSERT(m_callbacks, ichild >= 0 && ichild < m_cap);
    _RYML_CB_ASSERT(m_callbacks, iparent == NONE || (iparent >= 0 && iparent < m_cap));
    _RYML_CB_ASSERT(m_callbacks, iprev_sibling == NONE || (iprev_sibling >= 0 && iprev_sibling < m_cap));

    NodeData *C4_RESTRICT child = _p(ichild);

    child->m_parent = iparent;
    child->m_prev_sibling = NONE;
    child->m_next_sibling = NONE;

    if(iparent == NONE)
    {
        _RYML_CB_ASSERT(m_callbacks, ichild == 0);
        _RYML_CB_ASSERT(m_callbacks, iprev_sibling == NONE);
    }

    if(iparent == NONE)
        return;

    id_type inext_sibling = iprev_sibling != NONE ? next_sibling(iprev_sibling) : first_child(iparent);
    NodeData *C4_RESTRICT parent = get(iparent);
    NodeData *C4_RESTRICT psib   = get(iprev_sibling);
    NodeData *C4_RESTRICT nsib   = get(inext_sibling);

    if(psib)
    {
        _RYML_CB_ASSERT(m_callbacks, next_sibling(iprev_sibling) == id(nsib));
        child->m_prev_sibling = id(psib);
        psib->m_next_sibling = id(child);
        _RYML_CB_ASSERT(m_callbacks, psib->m_prev_sibling != psib->m_next_sibling || psib->m_prev_sibling == NONE);
    }

    if(nsib)
    {
        _RYML_CB_ASSERT(m_callbacks, prev_sibling(inext_sibling) == id(psib));
        child->m_next_sibling = id(nsib);
        nsib->m_prev_sibling = id(child);
        _RYML_CB_ASSERT(m_callbacks, nsib->m_prev_sibling != nsib->m_next_sibling || nsib->m_prev_sibling == NONE);
    }

    if(parent->m_first_child == NONE)
    {
        _RYML_CB_ASSERT(m_callbacks, parent->m_last_child == NONE);
        parent->m_first_child = id(child);
        parent->m_last_child = id(child);
    }
    else
    {
        if(child->m_next_sibling == parent->m_first_child)
            parent->m_first_child = id(child);

        if(child->m_prev_sibling == parent->m_last_child)
            parent->m_last_child = id(child);
    }
}

C4_SUPPRESS_WARNING_GCC_POP
C4_SUPPRESS_WARNING_CLANG_POP


//-----------------------------------------------------------------------------
void Tree::_rem_hierarchy(id_type i)
{
    _RYML_CB_ASSERT(m_callbacks, i >= 0 && i < m_cap);

    NodeData &C4_RESTRICT w = m_buf[i];

    // remove from the parent
    if(w.m_parent != NONE)
    {
        NodeData &C4_RESTRICT p = m_buf[w.m_parent];
        if(p.m_first_child == i)
        {
            p.m_first_child = w.m_next_sibling;
        }
        if(p.m_last_child == i)
        {
            p.m_last_child = w.m_prev_sibling;
        }
    }

    // remove from the used list
    if(w.m_prev_sibling != NONE)
    {
        NodeData *C4_RESTRICT prev = get(w.m_prev_sibling);
        prev->m_next_sibling = w.m_next_sibling;
    }
    if(w.m_next_sibling != NONE)
    {
        NodeData *C4_RESTRICT next = get(w.m_next_sibling);
        next->m_prev_sibling = w.m_prev_sibling;
    }
}

//-----------------------------------------------------------------------------
id_type Tree::_do_reorder(id_type *node, id_type count)
{
    // swap this node if it's not in place
    if(*node != count)
    {
        _swap(*node, count);
        *node = count;
    }
    ++count; // bump the count from this node

    // now descend in the hierarchy
    for(id_type i = first_child(*node); i != NONE; i = next_sibling(i))
    {
        // this child may have been relocated to a different index,
        // so get an updated version
        count = _do_reorder(&i, count);
    }
    return count;
}

void Tree::reorder()
{
    id_type r = root_id();
    _do_reorder(&r, 0);
}


//-----------------------------------------------------------------------------
void Tree::_swap(id_type n_, id_type m_)
{
    _RYML_CB_ASSERT(m_callbacks, (parent(n_) != NONE) || type(n_) == NOTYPE);
    _RYML_CB_ASSERT(m_callbacks, (parent(m_) != NONE) || type(m_) == NOTYPE);
    NodeType tn = type(n_);
    NodeType tm = type(m_);
    if(tn != NOTYPE && tm != NOTYPE)
    {
        _swap_props(n_, m_);
        _swap_hierarchy(n_, m_);
    }
    else if(tn == NOTYPE && tm != NOTYPE)
    {
        _copy_props(n_, m_);
        _free_list_rem(n_);
        _copy_hierarchy(n_, m_);
        _clear(m_);
        _free_list_add(m_);
    }
    else if(tn != NOTYPE && tm == NOTYPE)
    {
        _copy_props(m_, n_);
        _free_list_rem(m_);
        _copy_hierarchy(m_, n_);
        _clear(n_);
        _free_list_add(n_);
    }
    else
    {
        C4_NEVER_REACH();
    }
}

//-----------------------------------------------------------------------------
void Tree::_swap_hierarchy(id_type ia, id_type ib)
{
    if(ia == ib) return;

    for(id_type i = first_child(ia); i != NONE; i = next_sibling(i))
    {
        if(i == ib || i == ia)
            continue;
        _p(i)->m_parent = ib;
    }

    for(id_type i = first_child(ib); i != NONE; i = next_sibling(i))
    {
        if(i == ib || i == ia)
            continue;
        _p(i)->m_parent = ia;
    }

    auto & C4_RESTRICT a  = *_p(ia);
    auto & C4_RESTRICT b  = *_p(ib);
    auto & C4_RESTRICT pa = *_p(a.m_parent);
    auto & C4_RESTRICT pb = *_p(b.m_parent);

    if(&pa == &pb)
    {
        if((pa.m_first_child == ib && pa.m_last_child == ia)
            ||
           (pa.m_first_child == ia && pa.m_last_child == ib))
        {
            std::swap(pa.m_first_child, pa.m_last_child);
        }
        else
        {
            bool changed = false;
            if(pa.m_first_child == ia)
            {
                pa.m_first_child = ib;
                changed = true;
            }
            if(pa.m_last_child  == ia)
            {
                pa.m_last_child = ib;
                changed = true;
            }
            if(pb.m_first_child == ib && !changed)
            {
                pb.m_first_child = ia;
            }
            if(pb.m_last_child  == ib && !changed)
            {
                pb.m_last_child  = ia;
            }
        }
    }
    else
    {
        if(pa.m_first_child == ia)
            pa.m_first_child = ib;
        if(pa.m_last_child  == ia)
            pa.m_last_child  = ib;
        if(pb.m_first_child == ib)
            pb.m_first_child = ia;
        if(pb.m_last_child  == ib)
            pb.m_last_child  = ia;
    }
    std::swap(a.m_first_child , b.m_first_child);
    std::swap(a.m_last_child  , b.m_last_child);

    if(a.m_prev_sibling != ib && b.m_prev_sibling != ia &&
       a.m_next_sibling != ib && b.m_next_sibling != ia)
    {
        if(a.m_prev_sibling != NONE && a.m_prev_sibling != ib)
            _p(a.m_prev_sibling)->m_next_sibling = ib;
        if(a.m_next_sibling != NONE && a.m_next_sibling != ib)
            _p(a.m_next_sibling)->m_prev_sibling = ib;
        if(b.m_prev_sibling != NONE && b.m_prev_sibling != ia)
            _p(b.m_prev_sibling)->m_next_sibling = ia;
        if(b.m_next_sibling != NONE && b.m_next_sibling != ia)
            _p(b.m_next_sibling)->m_prev_sibling = ia;
        std::swap(a.m_prev_sibling, b.m_prev_sibling);
        std::swap(a.m_next_sibling, b.m_next_sibling);
    }
    else
    {
        if(a.m_next_sibling == ib) // n will go after m
        {
            _RYML_CB_ASSERT(m_callbacks, b.m_prev_sibling == ia);
            if(a.m_prev_sibling != NONE)
            {
                _RYML_CB_ASSERT(m_callbacks, a.m_prev_sibling != ib);
                _p(a.m_prev_sibling)->m_next_sibling = ib;
            }
            if(b.m_next_sibling != NONE)
            {
                _RYML_CB_ASSERT(m_callbacks, b.m_next_sibling != ia);
                _p(b.m_next_sibling)->m_prev_sibling = ia;
            }
            id_type ns = b.m_next_sibling;
            b.m_prev_sibling = a.m_prev_sibling;
            b.m_next_sibling = ia;
            a.m_prev_sibling = ib;
            a.m_next_sibling = ns;
        }
        else if(a.m_prev_sibling == ib) // m will go after n
        {
            _RYML_CB_ASSERT(m_callbacks, b.m_next_sibling == ia);
            if(b.m_prev_sibling != NONE)
            {
                _RYML_CB_ASSERT(m_callbacks, b.m_prev_sibling != ia);
                _p(b.m_prev_sibling)->m_next_sibling = ia;
            }
            if(a.m_next_sibling != NONE)
            {
                _RYML_CB_ASSERT(m_callbacks, a.m_next_sibling != ib);
                _p(a.m_next_sibling)->m_prev_sibling = ib;
            }
            id_type ns = b.m_prev_sibling;
            a.m_prev_sibling = b.m_prev_sibling;
            a.m_next_sibling = ib;
            b.m_prev_sibling = ia;
            b.m_next_sibling = ns;
        }
        else
        {
            C4_NEVER_REACH();
        }
    }
    _RYML_CB_ASSERT(m_callbacks, a.m_next_sibling != ia);
    _RYML_CB_ASSERT(m_callbacks, a.m_prev_sibling != ia);
    _RYML_CB_ASSERT(m_callbacks, b.m_next_sibling != ib);
    _RYML_CB_ASSERT(m_callbacks, b.m_prev_sibling != ib);

    if(a.m_parent != ib && b.m_parent != ia)
    {
        std::swap(a.m_parent, b.m_parent);
    }
    else
    {
        if(a.m_parent == ib && b.m_parent != ia)
        {
            a.m_parent = b.m_parent;
            b.m_parent = ia;
        }
        else if(a.m_parent != ib && b.m_parent == ia)
        {
            b.m_parent = a.m_parent;
            a.m_parent = ib;
        }
        else
        {
            C4_NEVER_REACH();
        }
    }
}

//-----------------------------------------------------------------------------
void Tree::_copy_hierarchy(id_type dst_, id_type src_)
{
    auto const& C4_RESTRICT src = *_p(src_);
    auto      & C4_RESTRICT dst = *_p(dst_);
    auto      & C4_RESTRICT prt = *_p(src.m_parent);
    for(id_type i = src.m_first_child; i != NONE; i = next_sibling(i))
    {
        _p(i)->m_parent = dst_;
    }
    if(src.m_prev_sibling != NONE)
    {
        _p(src.m_prev_sibling)->m_next_sibling = dst_;
    }
    if(src.m_next_sibling != NONE)
    {
        _p(src.m_next_sibling)->m_prev_sibling = dst_;
    }
    if(prt.m_first_child == src_)
    {
        prt.m_first_child = dst_;
    }
    if(prt.m_last_child  == src_)
    {
        prt.m_last_child  = dst_;
    }
    dst.m_parent       = src.m_parent;
    dst.m_first_child  = src.m_first_child;
    dst.m_last_child   = src.m_last_child;
    dst.m_prev_sibling = src.m_prev_sibling;
    dst.m_next_sibling = src.m_next_sibling;
}

//-----------------------------------------------------------------------------
void Tree::_swap_props(id_type n_, id_type m_)
{
    NodeData &C4_RESTRICT n = *_p(n_);
    NodeData &C4_RESTRICT m = *_p(m_);
    std::swap(n.m_type, m.m_type);
    std::swap(n.m_key, m.m_key);
    std::swap(n.m_val, m.m_val);
}

//-----------------------------------------------------------------------------
void Tree::move(id_type node, id_type after)
{
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    _RYML_CB_ASSERT(m_callbacks, node != after);
    _RYML_CB_ASSERT(m_callbacks,  ! is_root(node));
    _RYML_CB_ASSERT(m_callbacks, (after == NONE) || (has_sibling(node, after) && has_sibling(after, node)));

    _rem_hierarchy(node);
    _set_hierarchy(node, parent(node), after);
}

//-----------------------------------------------------------------------------

void Tree::move(id_type node, id_type new_parent, id_type after)
{
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    _RYML_CB_ASSERT(m_callbacks, node != after);
    _RYML_CB_ASSERT(m_callbacks, new_parent != NONE);
    _RYML_CB_ASSERT(m_callbacks, new_parent != node);
    _RYML_CB_ASSERT(m_callbacks, new_parent != after);
    _RYML_CB_ASSERT(m_callbacks,  ! is_root(node));

    _rem_hierarchy(node);
    _set_hierarchy(node, new_parent, after);
}

id_type Tree::move(Tree *src, id_type node, id_type new_parent, id_type after)
{
    _RYML_CB_ASSERT(m_callbacks, src != nullptr);
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    _RYML_CB_ASSERT(m_callbacks, new_parent != NONE);
    _RYML_CB_ASSERT(m_callbacks, new_parent != after);

    id_type dup = duplicate(src, node, new_parent, after);
    src->remove(node);
    return dup;
}

void Tree::set_root_as_stream()
{
    id_type root = root_id();
    if(is_stream(root))
        return;
    // don't use _add_flags() because it's checked and will fail
    if(!has_children(root))
    {
        if(is_val(root))
        {
            _p(root)->m_type.add(SEQ);
            id_type next_doc = append_child(root);
            _copy_props_wo_key(next_doc, root);
            _p(next_doc)->m_type.add(DOC);
            _p(next_doc)->m_type.rem(SEQ);
        }
        _p(root)->m_type = STREAM;
        return;
    }
    _RYML_CB_ASSERT(m_callbacks, !has_key(root));
    id_type next_doc = append_child(root);
    _copy_props_wo_key(next_doc, root);
    _add_flags(next_doc, DOC);
    for(id_type prev = NONE, ch = first_child(root), next = next_sibling(ch); ch != NONE; )
    {
        if(ch == next_doc)
            break;
        move(ch, next_doc, prev);
        prev = ch;
        ch = next;
        next = next_sibling(next);
    }
    _p(root)->m_type = STREAM;
}


//-----------------------------------------------------------------------------
void Tree::remove_children(id_type node)
{
    _RYML_CB_ASSERT(m_callbacks, get(node) != nullptr);
    id_type ich = get(node)->m_first_child;
    while(ich != NONE)
    {
        remove_children(ich);
        _RYML_CB_ASSERT(m_callbacks, get(ich) != nullptr);
        id_type next = get(ich)->m_next_sibling;
        _release(ich);
        if(ich == get(node)->m_last_child)
            break;
        ich = next;
    }
}

bool Tree::change_type(id_type node, NodeType type)
{
    _RYML_CB_ASSERT(m_callbacks, type.is_val() || type.is_map() || type.is_seq());
    _RYML_CB_ASSERT(m_callbacks, type.is_val() + type.is_map() + type.is_seq() == 1);
    _RYML_CB_ASSERT(m_callbacks, type.has_key() == has_key(node) || (has_key(node) && !type.has_key()));
    NodeData *d = _p(node);
    if(type.is_map() && is_map(node))
        return false;
    else if(type.is_seq() && is_seq(node))
        return false;
    else if(type.is_val() && is_val(node))
        return false;
    d->m_type = (d->m_type & (~(MAP|SEQ|VAL))) | type;
    remove_children(node);
    return true;
}


//-----------------------------------------------------------------------------
id_type Tree::duplicate(id_type node, id_type parent, id_type after)
{
    return duplicate(this, node, parent, after);
}

id_type Tree::duplicate(Tree const* src, id_type node, id_type parent, id_type after)
{
    _RYML_CB_ASSERT(m_callbacks, src != nullptr);
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    _RYML_CB_ASSERT(m_callbacks, parent != NONE);
    _RYML_CB_ASSERT(m_callbacks,  ! src->is_root(node));

    id_type copy = _claim();

    _copy_props(copy, src, node);
    _set_hierarchy(copy, parent, after);
    duplicate_children(src, node, copy, NONE);

    return copy;
}

//-----------------------------------------------------------------------------
id_type Tree::duplicate_children(id_type node, id_type parent, id_type after)
{
    return duplicate_children(this, node, parent, after);
}

id_type Tree::duplicate_children(Tree const* src, id_type node, id_type parent, id_type after)
{
    _RYML_CB_ASSERT(m_callbacks, src != nullptr);
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    _RYML_CB_ASSERT(m_callbacks, parent != NONE);
    _RYML_CB_ASSERT(m_callbacks, after == NONE || has_child(parent, after));

    id_type prev = after;
    for(id_type i = src->first_child(node); i != NONE; i = src->next_sibling(i))
    {
        prev = duplicate(src, i, parent, prev);
    }

    return prev;
}

//-----------------------------------------------------------------------------
void Tree::duplicate_contents(id_type node, id_type where)
{
    duplicate_contents(this, node, where);
}

void Tree::duplicate_contents(Tree const *src, id_type node, id_type where)
{
    _RYML_CB_ASSERT(m_callbacks, src != nullptr);
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    _RYML_CB_ASSERT(m_callbacks, where != NONE);
    _copy_props_wo_key(where, src, node);
    duplicate_children(src, node, where, last_child(where));
}

//-----------------------------------------------------------------------------
id_type Tree::duplicate_children_no_rep(id_type node, id_type parent, id_type after)
{
    return duplicate_children_no_rep(this, node, parent, after);
}

id_type Tree::duplicate_children_no_rep(Tree const *src, id_type node, id_type parent, id_type after)
{
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    _RYML_CB_ASSERT(m_callbacks, parent != NONE);
    _RYML_CB_ASSERT(m_callbacks, after == NONE || has_child(parent, after));

    // don't loop using pointers as there may be a relocation

    // find the position where "after" is
    id_type after_pos = NONE;
    if(after != NONE)
    {
        for(id_type i = first_child(parent), icount = 0; i != NONE; ++icount, i = next_sibling(i))
        {
            if(i == after)
            {
                after_pos = icount;
                break;
            }
        }
        _RYML_CB_ASSERT(m_callbacks, after_pos != NONE);
    }

    // for each child to be duplicated...
    id_type prev = after;
    for(id_type i = src->first_child(node); i != NONE; i = src->next_sibling(i))
    {
        if(is_seq(parent))
        {
            prev = duplicate(i, parent, prev);
        }
        else
        {
            _RYML_CB_ASSERT(m_callbacks, is_map(parent));
            // does the parent already have a node with key equal to that of the current duplicate?
            id_type rep = NONE, rep_pos = NONE;
            for(id_type j = first_child(parent), jcount = 0; j != NONE; ++jcount, j = next_sibling(j))
            {
                if(key(j) == key(i))
                {
                    rep = j;
                    rep_pos = jcount;
                    break;
                }
            }
            if(rep == NONE) // there is no repetition; just duplicate
            {
                prev = duplicate(src, i, parent, prev);
            }
            else  // yes, there is a repetition
            {
                if(after_pos != NONE && rep_pos < after_pos)
                {
                    // rep is located before the node which will be inserted,
                    // and will be overridden by the duplicate. So replace it.
                    remove(rep);
                    prev = duplicate(src, i, parent, prev);
                }
                else if(prev == NONE)
                {
                    // first iteration with prev = after = NONE and repetition
                    prev = rep;
                }
                else if(rep != prev)
                {
                    // rep is located after the node which will be inserted
                    // and overrides it. So move the rep into this node's place.
                    move(rep, prev);
                    prev = rep;
                }
            } // there's a repetition
        }
    }

    return prev;
}


//-----------------------------------------------------------------------------

void Tree::merge_with(Tree const *src, id_type src_node, id_type dst_node)
{
    _RYML_CB_ASSERT(m_callbacks, src != nullptr);
    if(src_node == NONE)
        src_node = src->root_id();
    if(dst_node == NONE)
        dst_node = root_id();
    _RYML_CB_ASSERT(m_callbacks, src->has_val(src_node) || src->is_seq(src_node) || src->is_map(src_node));
    if(src->has_val(src_node))
    {
        type_bits mask_src = ~STYLE; // keep the existing style if it is already a val
        if( ! has_val(dst_node))
        {
            if(has_children(dst_node))
                remove_children(dst_node);
            mask_src |= VAL_STYLE; // copy the src style
        }
        if(src->is_keyval(src_node))
        {
            _copy_props(dst_node, src, src_node, mask_src);
        }
        else
        {
            _RYML_CB_ASSERT(m_callbacks, src->is_val(src_node));
            _copy_props_wo_key(dst_node, src, src_node, mask_src);
        }
    }
    else if(src->is_seq(src_node))
    {
        if( ! is_seq(dst_node))
        {
            if(has_children(dst_node))
                remove_children(dst_node);
            _clear_type(dst_node);
            if(src->has_key(src_node))
                to_seq(dst_node, src->key(src_node));
            else
                to_seq(dst_node);
            _p(dst_node)->m_type = src->_p(src_node)->m_type;
        }
        for(id_type sch = src->first_child(src_node); sch != NONE; sch = src->next_sibling(sch))
        {
            id_type dch = append_child(dst_node);
            _copy_props_wo_key(dch, src, sch);
            merge_with(src, sch, dch);
        }
    }
    else
    {
        _RYML_CB_ASSERT(m_callbacks, src->is_map(src_node));
        if( ! is_map(dst_node))
        {
            if(has_children(dst_node))
                remove_children(dst_node);
            _clear_type(dst_node);
            if(src->has_key(src_node))
                to_map(dst_node, src->key(src_node));
            else
                to_map(dst_node);
            _p(dst_node)->m_type = src->_p(src_node)->m_type;
        }
        for(id_type sch = src->first_child(src_node); sch != NONE; sch = src->next_sibling(sch))
        {
            id_type dch = find_child(dst_node, src->key(sch));
            if(dch == NONE)
            {
                dch = append_child(dst_node);
                _copy_props(dch, src, sch);
            }
            merge_with(src, sch, dch);
        }
    }
}


//-----------------------------------------------------------------------------

void Tree::resolve()
{
    if(m_size == 0)
        return;
    ReferenceResolver rr;
    resolve(&rr);
}

void Tree::resolve(ReferenceResolver *C4_RESTRICT rr)
{
    if(m_size == 0)
        return;
    rr->resolve(this);
}


//-----------------------------------------------------------------------------

id_type Tree::num_children(id_type node) const
{
    id_type count = 0;
    for(id_type i = first_child(node); i != NONE; i = next_sibling(i))
        ++count;
    return count;
}

id_type Tree::child(id_type node, id_type pos) const
{
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    id_type count = 0;
    for(id_type i = first_child(node); i != NONE; i = next_sibling(i))
    {
        if(count++ == pos)
            return i;
    }
    return NONE;
}

id_type Tree::child_pos(id_type node, id_type ch) const
{
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    id_type count = 0;
    for(id_type i = first_child(node); i != NONE; i = next_sibling(i))
    {
        if(i == ch)
            return count;
        ++count;
    }
    return NONE;
}

#if defined(__clang__)
#   pragma clang diagnostic push
#   pragma GCC diagnostic ignored "-Wnull-dereference"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   if __GNUC__ >= 6
#       pragma GCC diagnostic ignored "-Wnull-dereference"
#   endif
#   if __GNUC__ > 9
#       pragma GCC diagnostic ignored "-Wanalyzer-null-dereference"
#   endif
#endif

id_type Tree::find_child(id_type node, csubstr const& name) const
{
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    _RYML_CB_ASSERT(m_callbacks, is_map(node));
    if(get(node)->m_first_child == NONE)
    {
        _RYML_CB_ASSERT(m_callbacks, _p(node)->m_last_child == NONE);
        return NONE;
    }
    else
    {
        _RYML_CB_ASSERT(m_callbacks, _p(node)->m_last_child != NONE);
    }
    for(id_type i = first_child(node); i != NONE; i = next_sibling(i))
    {
        if(_p(i)->m_key.scalar == name)
        {
            return i;
        }
    }
    return NONE;
}

#if defined(__clang__)
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif

namespace {
id_type depth_desc_(Tree const& C4_RESTRICT t, id_type id, id_type currdepth=0, id_type maxdepth=0)
{
    maxdepth = currdepth > maxdepth ? currdepth : maxdepth;
    for(id_type child = t.first_child(id); child != NONE; child = t.next_sibling(child))
    {
        const id_type d = depth_desc_(t, child, currdepth+1, maxdepth);
        maxdepth = d > maxdepth ? d : maxdepth;
    }
    return maxdepth;
}
}

id_type Tree::depth_desc(id_type node) const
{
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    return depth_desc_(*this, node);
}

id_type Tree::depth_asc(id_type node) const
{
    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    id_type depth = 0;
    while(!is_root(node))
    {
        ++depth;
        node = parent(node);
    }
    return depth;
}


//-----------------------------------------------------------------------------

void Tree::to_val(id_type node, csubstr val, type_bits more_flags)
{
    _RYML_CB_ASSERT(m_callbacks,  ! has_children(node));
    _RYML_CB_ASSERT(m_callbacks, parent(node) == NONE || ! parent_is_map(node));
    _set_flags(node, VAL|more_flags);
    _p(node)->m_key.clear();
    _p(node)->m_val = val;
}

void Tree::to_keyval(id_type node, csubstr key, csubstr val, type_bits more_flags)
{
    _RYML_CB_ASSERT(m_callbacks,  ! has_children(node));
    _RYML_CB_ASSERT(m_callbacks, parent(node) == NONE || parent_is_map(node));
    _set_flags(node, KEYVAL|more_flags);
    _p(node)->m_key = key;
    _p(node)->m_val = val;
}

void Tree::to_map(id_type node, type_bits more_flags)
{
    _RYML_CB_ASSERT(m_callbacks,  ! has_children(node));
    _RYML_CB_ASSERT(m_callbacks, parent(node) == NONE || ! parent_is_map(node)); // parent must not have children with keys
    _set_flags(node, MAP|more_flags);
    _p(node)->m_key.clear();
    _p(node)->m_val.clear();
}

void Tree::to_map(id_type node, csubstr key, type_bits more_flags)
{
    _RYML_CB_ASSERT(m_callbacks,  ! has_children(node));
    _RYML_CB_ASSERT(m_callbacks, parent(node) == NONE || parent_is_map(node));
    _set_flags(node, KEY|MAP|more_flags);
    _p(node)->m_key = key;
    _p(node)->m_val.clear();
}

void Tree::to_seq(id_type node, type_bits more_flags)
{
    _RYML_CB_ASSERT(m_callbacks,  ! has_children(node));
    _RYML_CB_ASSERT(m_callbacks, parent(node) == NONE || parent_is_seq(node));
    _set_flags(node, SEQ|more_flags);
    _p(node)->m_key.clear();
    _p(node)->m_val.clear();
}

void Tree::to_seq(id_type node, csubstr key, type_bits more_flags)
{
    _RYML_CB_ASSERT(m_callbacks,  ! has_children(node));
    _RYML_CB_ASSERT(m_callbacks, parent(node) == NONE || parent_is_map(node));
    _set_flags(node, KEY|SEQ|more_flags);
    _p(node)->m_key = key;
    _p(node)->m_val.clear();
}

void Tree::to_doc(id_type node, type_bits more_flags)
{
    _RYML_CB_ASSERT(m_callbacks,  ! has_children(node));
    _set_flags(node, DOC|more_flags);
    _p(node)->m_key.clear();
    _p(node)->m_val.clear();
}

void Tree::to_stream(id_type node, type_bits more_flags)
{
    _RYML_CB_ASSERT(m_callbacks,  ! has_children(node));
    _set_flags(node, STREAM|more_flags);
    _p(node)->m_key.clear();
    _p(node)->m_val.clear();
}


//-----------------------------------------------------------------------------
id_type Tree::num_tag_directives() const
{
    // this assumes we have a very small number of tag directives
    for(id_type i = 0; i < RYML_MAX_TAG_DIRECTIVES; ++i)
        if(m_tag_directives[i].handle.empty())
            return i;
    return RYML_MAX_TAG_DIRECTIVES;
}

void Tree::clear_tag_directives()
{
    for(TagDirective &td : m_tag_directives)
        td = {};
}

id_type Tree::add_tag_directive(TagDirective const& td)
{
    _RYML_CB_CHECK(m_callbacks, !td.handle.empty());
    _RYML_CB_CHECK(m_callbacks, !td.prefix.empty());
    _RYML_CB_CHECK(m_callbacks, td.handle.begins_with('!'));
    _RYML_CB_CHECK(m_callbacks, td.handle.ends_with('!'));
    // https://yaml.org/spec/1.2.2/#rule-ns-word-char
    _RYML_CB_CHECK(m_callbacks, td.handle == '!' || td.handle == "!!" || td.handle.trim('!').first_not_of("01234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-") == npos);
    id_type pos = num_tag_directives();
    _RYML_CB_CHECK(m_callbacks, pos < RYML_MAX_TAG_DIRECTIVES);
    m_tag_directives[pos] = td;
    return pos;
}

bool Tree::add_tag_directive(csubstr directive_)
{
    TagDirective td;
    if(td.create_from_str(directive_, this))
    {
        add_tag_directive(td);
        return true;
    }
    return false;
}

size_t Tree::resolve_tag(substr output, csubstr tag, id_type node_id) const
{
    // lookup from the end. We want to find the first directive that
    // matches the tag and has a target node id leq than the given
    // node_id.
    for(id_type i = RYML_MAX_TAG_DIRECTIVES-1; i != (id_type)-1; --i)
    {
        auto const& td = m_tag_directives[i];
        if(td.handle.empty())
            continue;
        if(tag.begins_with(td.handle) && td.next_node_id <= node_id)
            return td.transform(tag, output, m_callbacks);
    }
    if(tag.begins_with('!'))
    {
        if(is_custom_tag(tag))
        {
            _RYML_CB_ERR(m_callbacks, "tag directive not found");
        }
    }
    return 0; // return 0 to signal that the tag is local and cannot be resolved
}

namespace {
csubstr _transform_tag(Tree *t, csubstr tag, id_type node)
{
    _c4dbgpf("[{}] resolving tag ~~~{}~~~", node, tag);
    size_t required_size = t->resolve_tag(substr{}, tag, node);
    if(!required_size)
    {
        if(tag.begins_with("!<"))
            tag = tag.sub(1);
        _c4dbgpf("[{}] resolved tag: ~~~{}~~~", node, tag);
        return tag;
    }
    const char *prev_arena = t->arena().str;(void)prev_arena;
    substr buf = t->alloc_arena(required_size);
    _RYML_CB_ASSERT(t->m_callbacks, t->arena().str == prev_arena);
    size_t actual_size = t->resolve_tag(buf, tag, node);
    _RYML_CB_ASSERT(t->m_callbacks, actual_size <= required_size);
    _c4dbgpf("[{}] resolved tag: ~~~{}~~~", node, buf.first(actual_size));
    return buf.first(actual_size);
}
void _resolve_tags(Tree *t, id_type node)
{
    NodeData *C4_RESTRICT d = t->_p(node);
    if(d->m_type & KEYTAG)
        d->m_key.tag = _transform_tag(t, d->m_key.tag, node);
    if(d->m_type & VALTAG)
        d->m_val.tag = _transform_tag(t, d->m_val.tag, node);
    for(id_type child = t->first_child(node); child != NONE; child = t->next_sibling(child))
        _resolve_tags(t, child);
}
size_t _count_resolved_tags_size(Tree const* t, id_type node)
{
    size_t sz = 0;
    NodeData const* C4_RESTRICT d = t->_p(node);
    if(d->m_type & KEYTAG)
        sz += t->resolve_tag(substr{}, d->m_key.tag, node);
    if(d->m_type & VALTAG)
        sz += t->resolve_tag(substr{}, d->m_val.tag, node);
    for(id_type child = t->first_child(node); child != NONE; child = t->next_sibling(child))
        sz += _count_resolved_tags_size(t, child);
    return sz;
}
void _normalize_tags(Tree *t, id_type node)
{
    NodeData *C4_RESTRICT d = t->_p(node);
    if(d->m_type & KEYTAG)
        d->m_key.tag = normalize_tag(d->m_key.tag);
    if(d->m_type & VALTAG)
        d->m_val.tag = normalize_tag(d->m_val.tag);
    for(id_type child = t->first_child(node); child != NONE; child = t->next_sibling(child))
        _normalize_tags(t, child);
}
void _normalize_tags_long(Tree *t, id_type node)
{
    NodeData *C4_RESTRICT d = t->_p(node);
    if(d->m_type & KEYTAG)
        d->m_key.tag = normalize_tag_long(d->m_key.tag);
    if(d->m_type & VALTAG)
        d->m_val.tag = normalize_tag_long(d->m_val.tag);
    for(id_type child = t->first_child(node); child != NONE; child = t->next_sibling(child))
        _normalize_tags_long(t, child);
}
} // namespace

void Tree::resolve_tags()
{
    if(empty())
        return;
    size_t needed_size = _count_resolved_tags_size(this, root_id());
    if(needed_size)
        reserve_arena(arena_size() + needed_size);
    _resolve_tags(this, root_id());
}

void Tree::normalize_tags()
{
    if(empty())
        return;
    _normalize_tags(this, root_id());
}

void Tree::normalize_tags_long()
{
    if(empty())
        return;
    _normalize_tags_long(this, root_id());
}


//-----------------------------------------------------------------------------

csubstr Tree::lookup_result::resolved() const
{
    csubstr p = path.first(path_pos);
    if(p.ends_with('.'))
        p = p.first(p.len-1);
    return p;
}

csubstr Tree::lookup_result::unresolved() const
{
    return path.sub(path_pos);
}

void Tree::_advance(lookup_result *r, size_t more) const
{
    r->path_pos += more;
    if(r->path.sub(r->path_pos).begins_with('.'))
        ++r->path_pos;
}

Tree::lookup_result Tree::lookup_path(csubstr path, id_type start) const
{
    if(start == NONE)
        start = root_id();
    lookup_result r(path, start);
    if(path.empty())
        return r;
    _lookup_path(&r);
    if(r.target == NONE && r.closest == start)
        r.closest = NONE;
    return r;
}

id_type Tree::lookup_path_or_modify(csubstr default_value, csubstr path, id_type start)
{
    id_type target = _lookup_path_or_create(path, start);
    if(parent_is_map(target))
        to_keyval(target, key(target), default_value);
    else
        to_val(target, default_value);
    return target;
}

id_type Tree::lookup_path_or_modify(Tree const *src, id_type src_node, csubstr path, id_type start)
{
    id_type target = _lookup_path_or_create(path, start);
    merge_with(src, src_node, target);
    return target;
}

id_type Tree::_lookup_path_or_create(csubstr path, id_type start)
{
    if(start == NONE)
        start = root_id();
    lookup_result r(path, start);
    _lookup_path(&r);
    if(r.target != NONE)
    {
        C4_ASSERT(r.unresolved().empty());
        return r.target;
    }
    _lookup_path_modify(&r);
    return r.target;
}

void Tree::_lookup_path(lookup_result *r) const
{
    C4_ASSERT( ! r->unresolved().empty());
    _lookup_path_token parent{"", type(r->closest)};
    id_type node;
    do
    {
        node = _next_node(r, &parent);
        if(node != NONE)
            r->closest = node;
        if(r->unresolved().empty())
        {
            r->target = node;
            return;
        }
    } while(node != NONE);
}

void Tree::_lookup_path_modify(lookup_result *r)
{
    C4_ASSERT( ! r->unresolved().empty());
    _lookup_path_token parent{"", type(r->closest)};
    id_type node;
    do
    {
        node = _next_node_modify(r, &parent);
        if(node != NONE)
            r->closest = node;
        if(r->unresolved().empty())
        {
            r->target = node;
            return;
        }
    } while(node != NONE);
}

id_type Tree::_next_node(lookup_result * r, _lookup_path_token *parent) const
{
    _lookup_path_token token = _next_token(r, *parent);
    if( ! token)
        return NONE;

    id_type node = NONE;
    csubstr prev = token.value;
    if(token.type == MAP || token.type == SEQ)
    {
        _RYML_CB_ASSERT(m_callbacks, !token.value.begins_with('['));
        //_RYML_CB_ASSERT(m_callbacks, is_container(r->closest) || r->closest == NONE);
        _RYML_CB_ASSERT(m_callbacks, is_map(r->closest));
        node = find_child(r->closest, token.value);
    }
    else if(token.type == KEYVAL)
    {
        _RYML_CB_ASSERT(m_callbacks, r->unresolved().empty());
        if(is_map(r->closest))
            node = find_child(r->closest, token.value);
    }
    else if(token.type == KEY)
    {
        _RYML_CB_ASSERT(m_callbacks, token.value.begins_with('[') && token.value.ends_with(']'));
        token.value = token.value.offs(1, 1).trim(' ');
        id_type idx = 0;
        _RYML_CB_CHECK(m_callbacks, from_chars(token.value, &idx));
        node = child(r->closest, idx);
    }
    else
    {
        C4_NEVER_REACH();
    }

    if(node != NONE)
    {
        *parent = token;
    }
    else
    {
        csubstr p = r->path.sub(r->path_pos > 0 ? r->path_pos - 1 : r->path_pos);
        r->path_pos -= prev.len;
        if(p.begins_with('.'))
            r->path_pos -= 1u;
    }

    return node;
}

id_type Tree::_next_node_modify(lookup_result * r, _lookup_path_token *parent)
{
    _lookup_path_token token = _next_token(r, *parent);
    if( ! token)
        return NONE;

    id_type node = NONE;
    if(token.type == MAP || token.type == SEQ)
    {
        _RYML_CB_ASSERT(m_callbacks, !token.value.begins_with('['));
        //_RYML_CB_ASSERT(m_callbacks, is_container(r->closest) || r->closest == NONE);
        if( ! is_container(r->closest))
        {
            if(has_key(r->closest))
                to_map(r->closest, key(r->closest));
            else
                to_map(r->closest);
        }
        else
        {
            if(is_map(r->closest))
                node = find_child(r->closest, token.value);
            else
            {
                id_type pos = NONE;
                _RYML_CB_CHECK(m_callbacks, c4::atox(token.value, &pos));
                _RYML_CB_ASSERT(m_callbacks, pos != NONE);
                node = child(r->closest, pos);
            }
        }
        if(node == NONE)
        {
            _RYML_CB_ASSERT(m_callbacks, is_map(r->closest));
            node = append_child(r->closest);
            NodeData *n = _p(node);
            n->m_key.scalar = token.value;
            n->m_type.add(KEY);
        }
    }
    else if(token.type == KEYVAL)
    {
        _RYML_CB_ASSERT(m_callbacks, r->unresolved().empty());
        if(is_map(r->closest))
        {
            node = find_child(r->closest, token.value);
            if(node == NONE)
                node = append_child(r->closest);
        }
        else
        {
            _RYML_CB_ASSERT(m_callbacks, !is_seq(r->closest));
            _add_flags(r->closest, MAP);
            node = append_child(r->closest);
        }
        NodeData *n = _p(node);
        n->m_key.scalar = token.value;
        n->m_val.scalar = "";
        n->m_type.add(KEYVAL);
    }
    else if(token.type == KEY)
    {
        _RYML_CB_ASSERT(m_callbacks, token.value.begins_with('[') && token.value.ends_with(']'));
        token.value = token.value.offs(1, 1).trim(' ');
        id_type idx;
        if( ! from_chars(token.value, &idx))
             return NONE;
        if( ! is_container(r->closest))
        {
            if(has_key(r->closest))
            {
                csubstr k = key(r->closest);
                _clear_type(r->closest);
                to_seq(r->closest, k);
            }
            else
            {
                _clear_type(r->closest);
                to_seq(r->closest);
            }
        }
        _RYML_CB_ASSERT(m_callbacks, is_container(r->closest));
        node = child(r->closest, idx);
        if(node == NONE)
        {
            _RYML_CB_ASSERT(m_callbacks, num_children(r->closest) <= idx);
            for(id_type i = num_children(r->closest); i <= idx; ++i)
            {
                node = append_child(r->closest);
                if(i < idx)
                {
                    if(is_map(r->closest))
                        to_keyval(node, /*"~"*/{}, /*"~"*/{});
                    else if(is_seq(r->closest))
                        to_val(node, /*"~"*/{});
                }
            }
        }
    }
    else
    {
        C4_NEVER_REACH();
    }

    _RYML_CB_ASSERT(m_callbacks, node != NONE);
    *parent = token;
    return node;
}

/* types of tokens:
 * - seeing "map."  ---> "map"/MAP
 * - finishing "scalar" ---> "scalar"/KEYVAL
 * - seeing "seq[n]" ---> "seq"/SEQ (--> "[n]"/KEY)
 * - seeing "[n]" ---> "[n]"/KEY
 */
Tree::_lookup_path_token Tree::_next_token(lookup_result *r, _lookup_path_token const& parent) const
{
    csubstr unres = r->unresolved();
    if(unres.empty())
        return {};

    // is it an indexation like [0], [1], etc?
    if(unres.begins_with('['))
    {
        size_t pos = unres.find(']');
        if(pos == csubstr::npos)
            return {};
        csubstr idx = unres.first(pos + 1);
        _advance(r, pos + 1);
        return {idx, KEY};
    }

    // no. so it must be a name
    size_t pos = unres.first_of(".[");
    if(pos == csubstr::npos)
    {
        _advance(r, unres.len);
        NodeType t;
        if(( ! parent) || parent.type.is_seq())
            return {unres, VAL};
        return {unres, KEYVAL};
    }

    // it's either a map or a seq
    _RYML_CB_ASSERT(m_callbacks, unres[pos] == '.' || unres[pos] == '[');
    if(unres[pos] == '.')
    {
        _RYML_CB_ASSERT(m_callbacks, pos != 0);
        _advance(r, pos + 1);
        return {unres.first(pos), MAP};
    }

    _RYML_CB_ASSERT(m_callbacks, unres[pos] == '[');
    _advance(r, pos);
    return {unres.first(pos), SEQ};
}


} // namespace ryml
} // namespace c4


C4_SUPPRESS_WARNING_GCC_CLANG_POP
C4_SUPPRESS_WARNING_MSVC_POP

#endif /* RYML_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/tree.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/parse_engine.def.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/parse_engine.def.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_PARSE_ENGINE_DEF_HPP_
#define _C4_YML_PARSE_ENGINE_DEF_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/parse_engine.hpp
//#include "c4/yml/parse_engine.hpp"
#if !defined(C4_YML_PARSE_ENGINE_HPP_) && !defined(_C4_YML_PARSE_ENGINE_HPP_)
#error "amalgamate: file c4/yml/parse_engine.hpp must have been included at this point"
#endif /* C4_YML_PARSE_ENGINE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/error.hpp
//#include "c4/error.hpp"
#if !defined(C4_ERROR_HPP_) && !defined(_C4_ERROR_HPP_)
#error "amalgamate: file c4/error.hpp must have been included at this point"
#endif /* C4_ERROR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/charconv.hpp
//#include "c4/charconv.hpp"
#if !defined(C4_CHARCONV_HPP_) && !defined(_C4_CHARCONV_HPP_)
#error "amalgamate: file c4/charconv.hpp must have been included at this point"
#endif /* C4_CHARCONV_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/utf.hpp
//#include "c4/utf.hpp"
#if !defined(C4_UTF_HPP_) && !defined(_C4_UTF_HPP_)
#error "amalgamate: file c4/utf.hpp must have been included at this point"
#endif /* C4_UTF_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/dump.hpp
//#include <c4/dump.hpp>
#if !defined(C4_DUMP_HPP_) && !defined(_C4_DUMP_HPP_)
#error "amalgamate: file c4/dump.hpp must have been included at this point"
#endif /* C4_DUMP_HPP_ */


#include <ctype.h>

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/parser_dbg.hpp
//#include "c4/yml/detail/parser_dbg.hpp"
#if !defined(C4_YML_DETAIL_PARSER_DBG_HPP_) && !defined(_C4_YML_DETAIL_PARSER_DBG_HPP_)
#error "amalgamate: file c4/yml/detail/parser_dbg.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PARSER_DBG_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/filter_processor.hpp
//#include "c4/yml/filter_processor.hpp"
#if !defined(C4_YML_FILTER_PROCESSOR_HPP_) && !defined(_C4_YML_FILTER_PROCESSOR_HPP_)
#error "amalgamate: file c4/yml/filter_processor.hpp must have been included at this point"
#endif /* C4_YML_FILTER_PROCESSOR_HPP_ */

#ifdef RYML_DBG
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/print.hpp
//#include "c4/yml/detail/print.hpp"
#if !defined(C4_YML_DETAIL_PRINT_HPP_) && !defined(_C4_YML_DETAIL_PRINT_HPP_)
#error "amalgamate: file c4/yml/detail/print.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PRINT_HPP_ */

#endif


#if defined(RYML_WITH_TAB_TOKENS)
#define _RYML_WITH_TAB_TOKENS(...) __VA_ARGS__
#define _RYML_WITHOUT_TAB_TOKENS(...)
#define _RYML_WITH_OR_WITHOUT_TAB_TOKENS(with, without) with
#else
#define _RYML_WITH_TAB_TOKENS(...)
#define _RYML_WITHOUT_TAB_TOKENS(...) __VA_ARGS__
#define _RYML_WITH_OR_WITHOUT_TAB_TOKENS(with, without) without
#endif


// scaffold:
#define _c4dbgnextline()                           \
    do {                                           \
       _c4dbgq("\n-----------");                   \
       _c4dbgt("handling line={}, offset={}B",     \
               m_evt_handler->m_curr->pos.line,    \
               m_evt_handler->m_curr->pos.offset); \
    } while(0)


#if defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable: 4296/*expression is always 'boolean_value'*/)
#   pragma warning(disable: 4702/*unreachable code*/)
#elif defined(__clang__)
#   pragma clang diagnostic push
#   pragma clang diagnostic ignored "-Wtype-limits" // to remove a warning on an assertion that a size_t >= 0. Later on, this size_t will turn into a template argument, and then it can become < 0.
#   pragma clang diagnostic ignored "-Wformat-nonliteral"
#   pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wtype-limits" // to remove a warning on an assertion that a size_t >= 0. Later on, this size_t will turn into a template argument, and then it can become < 0.
#   pragma GCC diagnostic ignored "-Wformat-nonliteral"
#   pragma GCC diagnostic ignored "-Wold-style-cast"
#   if __GNUC__ >= 7
#       pragma GCC diagnostic ignored "-Wduplicated-branches"
#   endif
#endif

namespace c4 {
namespace yml {

namespace {

C4_HOT C4_ALWAYS_INLINE bool _is_blck_token(csubstr s) noexcept
{
    RYML_ASSERT(s.len > 0);
    RYML_ASSERT(s.str[0] == '-' || s.str[0] == ':' || s.str[0] == '?');
    return ((s.len == 1) || ((s.str[1] == ' ') _RYML_WITH_TAB_TOKENS( || (s.str[1] == '\t'))));
}

inline bool _is_doc_begin_token(csubstr s)
{
    RYML_ASSERT(s.begins_with('-'));
    RYML_ASSERT(!s.ends_with("\n"));
    RYML_ASSERT(!s.ends_with("\r"));
    return (s.len >= 3 && s.str[1] == '-' && s.str[2] == '-')
        && (s.len == 3 || (s.str[3] == ' ' _RYML_WITH_TAB_TOKENS(|| s.str[3] == '\t')));
}

inline bool _is_doc_end_token(csubstr s)
{
    RYML_ASSERT(s.begins_with('.'));
    RYML_ASSERT(!s.ends_with("\n"));
    RYML_ASSERT(!s.ends_with("\r"));
    return (s.len >= 3 && s.str[1] == '.' && s.str[2] == '.')
        && (s.len == 3 || (s.str[3] == ' ' _RYML_WITH_TAB_TOKENS(|| s.str[3] == '\t')));
}

inline bool _is_doc_token(csubstr s) noexcept
{
    //
    // NOTE: this function was failing under some scenarios when
    // compiled with gcc -O2 (but not -O3 or -O1 or -O0), likely
    // related to optimizer assumptions on the input string and
    // possibly caused from UB around assignment to that string (the
    // call site was in _scan_block()). For more details see:
    //
    // https://github.com/biojppm/rapidyaml/issues/440
    //
    // The current version does not suffer this problem, but it may
    // appear again.
    //
    if(s.len >= 3)
    {
        switch(s.str[0])
        {
        case '-':
            //return _is_doc_begin_token(s); // this was failing with gcc -O2
            return (s.str[1] == '-' && s.str[2] == '-')
                && (s.len == 3 || (s.str[3] == ' ' _RYML_WITH_TAB_TOKENS(|| s.str[3] == '\t')));
        case '.':
            //return _is_doc_end_token(s); // this was failing with gcc -O2
            return (s.str[1] == '.' && s.str[2] == '.')
                && (s.len == 3 || (s.str[3] == ' ' _RYML_WITH_TAB_TOKENS(|| s.str[3] == '\t')));
        }
    }
    return false;
}

inline size_t _is_special_json_scalar(csubstr s)
{
    RYML_ASSERT(s.len);
    switch(s.str[0])
    {
    case 'f':
        if(s.len >= 5 && s.begins_with("false"))
            return 5u;
        break;
    case 't':
        if(s.len >= 4 && s.begins_with("true"))
            return 4u;
        break;
    case 'n':
        if(s.len >= 4 && s.begins_with("null"))
            return 4u;
        break;
    }
    return 0u;
}


//-----------------------------------------------------------------------------

C4_ALWAYS_INLINE size_t _extend_from_combined_newline(char nl, char following)
{
    return (nl == '\n' && following == '\r') || (nl == '\r' && following == '\n');
}

//! look for the next newline chars, and jump to the right of those
inline substr from_next_line(substr rem)
{
    size_t nlpos = rem.first_of("\r\n");
    if(nlpos == csubstr::npos)
        return {};
    const char nl = rem[nlpos];
    rem = rem.right_of(nlpos);
    if(rem.empty())
        return {};
    if(_extend_from_combined_newline(nl, rem.front()))
        rem = rem.sub(1);
    return rem;
}


//-----------------------------------------------------------------------------

inline size_t _count_following_newlines(csubstr r, size_t *C4_RESTRICT i)
{
    RYML_ASSERT(r[*i] == '\n');
    size_t numnl_following = 0;
    ++(*i);
    for( ; *i < r.len; ++(*i))
    {
        if(r.str[*i] == '\n')
            ++numnl_following;
        // skip leading whitespace
        else if(r.str[*i] == ' ' || r.str[*i] == '\t' || r.str[*i] == '\r')
            ;
        else
            break;
    }
    return numnl_following;
}

/** @p i is set to the first non whitespace character after the line
 * @return the number of empty lines after the initial position */
inline size_t _count_following_newlines(csubstr r, size_t *C4_RESTRICT i, size_t indentation)
{
    RYML_ASSERT(r[*i] == '\n');
    size_t numnl_following = 0;
    ++(*i);
    if(indentation == 0)
    {
        for( ; *i < r.len; ++(*i))
        {
            if(r.str[*i] == '\n')
                ++numnl_following;
            // skip leading whitespace
            else if(r.str[*i] == ' ' || r.str[*i] == '\t' || r.str[*i] == '\r')
                ;
            else
                break;
        }
    }
    else
    {
        for( ; *i < r.len; ++(*i))
        {
            if(r.str[*i] == '\n')
            {
                ++numnl_following;
                // skip the indentation after the newline
                size_t stop = *i + indentation;
                for( ; *i < r.len; ++(*i))
                {
                    if(r.str[*i] != ' ' && r.str[*i] != '\r')
                        break;
                    RYML_ASSERT(*i < stop);
                }
                C4_UNUSED(stop);
            }
            // skip leading whitespace
            else if(r.str[*i] == ' ' || r.str[*i] == '\t' || r.str[*i] == '\r')
                ;
            else
                break;
        }
    }
    return numnl_following;
}

} // anon namespace


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<class EventHandler>
ParseEngine<EventHandler>::~ParseEngine()
{
    _free();
    _clr();
}

template<class EventHandler>
ParseEngine<EventHandler>::ParseEngine(EventHandler *evt_handler, ParserOptions opts)
    : m_options(opts)
    , m_file()
    , m_buf()
    , m_evt_handler(evt_handler)
    , m_pending_anchors()
    , m_pending_tags()
    , m_newline_offsets()
    , m_newline_offsets_size(0)
    , m_newline_offsets_capacity(0)
    , m_newline_offsets_buf()
{
    RYML_CHECK(evt_handler);
}

template<class EventHandler>
ParseEngine<EventHandler>::ParseEngine(ParseEngine &&that)
    : m_options(that.m_options)
    , m_file(that.m_file)
    , m_buf(that.m_buf)
    , m_evt_handler(that.m_evt_handler)
    , m_pending_anchors(that.m_pending_anchors)
    , m_pending_tags(that.m_pending_tags)
    , m_newline_offsets(that.m_newline_offsets)
    , m_newline_offsets_size(that.m_newline_offsets_size)
    , m_newline_offsets_capacity(that.m_newline_offsets_capacity)
    , m_newline_offsets_buf(that.m_newline_offsets_buf)
{
    that._clr();
}

template<class EventHandler>
ParseEngine<EventHandler>::ParseEngine(ParseEngine const& that)
    : m_options(that.m_options)
    , m_file(that.m_file)
    , m_buf(that.m_buf)
    , m_evt_handler(that.m_evt_handler)
    , m_pending_anchors(that.m_pending_anchors)
    , m_pending_tags(that.m_pending_tags)
    , m_newline_offsets()
    , m_newline_offsets_size()
    , m_newline_offsets_capacity()
    , m_newline_offsets_buf()
{
    if(that.m_newline_offsets_capacity)
    {
        _resize_locations(that.m_newline_offsets_capacity);
        _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, m_newline_offsets_capacity == that.m_newline_offsets_capacity);
        memcpy(m_newline_offsets, that.m_newline_offsets, that.m_newline_offsets_size * sizeof(size_t));
        m_newline_offsets_size = that.m_newline_offsets_size;
    }
}

template<class EventHandler>
ParseEngine<EventHandler>& ParseEngine<EventHandler>::operator=(ParseEngine &&that)
{
    _free();
    m_options = (that.m_options);
    m_file = (that.m_file);
    m_buf = (that.m_buf);
    m_evt_handler = that.m_evt_handler;
    m_pending_anchors = that.m_pending_anchors;
    m_pending_tags = that.m_pending_tags;
    m_newline_offsets = (that.m_newline_offsets);
    m_newline_offsets_size = (that.m_newline_offsets_size);
    m_newline_offsets_capacity = (that.m_newline_offsets_capacity);
    m_newline_offsets_buf = (that.m_newline_offsets_buf);
    that._clr();
    return *this;
}

template<class EventHandler>
ParseEngine<EventHandler>& ParseEngine<EventHandler>::operator=(ParseEngine const& that)
{
    _free();
    m_options = (that.m_options);
    m_file = (that.m_file);
    m_buf = (that.m_buf);
    m_evt_handler = that.m_evt_handler;
    m_pending_anchors = that.m_pending_anchors;
    m_pending_tags = that.m_pending_tags;
    if(that.m_newline_offsets_capacity > m_newline_offsets_capacity)
        _resize_locations(that.m_newline_offsets_capacity);
    _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, m_newline_offsets_capacity >= that.m_newline_offsets_capacity);
    _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, m_newline_offsets_capacity >= that.m_newline_offsets_size);
    memcpy(m_newline_offsets, that.m_newline_offsets, that.m_newline_offsets_size * sizeof(size_t));
    m_newline_offsets_size = that.m_newline_offsets_size;
    m_newline_offsets_buf = that.m_newline_offsets_buf;
    return *this;
}

template<class EventHandler>
void ParseEngine<EventHandler>::_clr()
{
    m_options = {};
    m_file = {};
    m_buf = {};
    m_evt_handler = {};
    m_pending_anchors = {};
    m_pending_tags = {};
    m_newline_offsets = {};
    m_newline_offsets_size = {};
    m_newline_offsets_capacity = {};
    m_newline_offsets_buf = {};
}

template<class EventHandler>
void ParseEngine<EventHandler>::_free()
{
    if(m_newline_offsets)
    {
        _RYML_CB_FREE(m_evt_handler->m_stack.m_callbacks, m_newline_offsets, size_t, m_newline_offsets_capacity);
        m_newline_offsets = nullptr;
        m_newline_offsets_size = 0u;
        m_newline_offsets_capacity = 0u;
        m_newline_offsets_buf = 0u;
    }
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_reset()
{
    m_pending_anchors = {};
    m_pending_tags = {};
    if(m_options.locations())
    {
        _prepare_locations();
    }
    m_was_inside_qmrk = false;
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_relocate_arena(csubstr prev_arena, substr next_arena)
{
    #define _ryml_relocate(s)                                   \
    if(s.is_sub(prev_arena))                                    \
    {                                                           \
        s.str = next_arena.str + (s.str - prev_arena.str);      \
    }
    _ryml_relocate(m_buf);
    _ryml_relocate(m_newline_offsets_buf);
    for(size_t i = 0; i < m_pending_tags.num_entries; ++i)
        _ryml_relocate(m_pending_tags.annotations[i].str);
    for(size_t i = 0; i < m_pending_anchors.num_entries; ++i)
        _ryml_relocate(m_pending_anchors.annotations[i].str);
    #undef _ryml_relocate
}

template<class EventHandler>
void ParseEngine<EventHandler>::_s_relocate_arena(void* data, csubstr prev_arena, substr next_arena)
{
    ((ParseEngine*)data)->_relocate_arena(prev_arena, next_arena);
}


//-----------------------------------------------------------------------------

template<class EventHandler>
template<class DumpFn>
void ParseEngine<EventHandler>::_fmt_msg(DumpFn &&dumpfn) const
{
    auto const *const C4_RESTRICT st = m_evt_handler->m_curr;
    auto const& lc = st->line_contents;
    csubstr contents = lc.stripped;
    if(contents.len)
    {
        // print the yaml src line
        size_t offs = 3u + to_chars(substr{}, st->pos.line) + to_chars(substr{}, st->pos.col);
        if(m_file.len)
        {
            detail::_dump(dumpfn, "{}:", m_file);
            offs += m_file.len + 1;
        }
        detail::_dump(dumpfn, "{}:{}: ", st->pos.line, st->pos.col);
        csubstr maybe_full_content = (contents.len < 80u ? contents : contents.first(80u));
        csubstr maybe_ellipsis = (contents.len < 80u ? csubstr{} : csubstr("..."));
        detail::_dump(dumpfn, "{}{}  (size={})\n", maybe_full_content, maybe_ellipsis, contents.len);
        // highlight the remaining portion of the previous line
        size_t firstcol = (size_t)(lc.rem.begin() - lc.full.begin());
        size_t lastcol = firstcol + lc.rem.len;
        for(size_t i = 0; i < offs + firstcol; ++i)
            dumpfn(" ");
        dumpfn("^");
        for(size_t i = 1, e = (lc.rem.len < 80u ? lc.rem.len : 80u); i < e; ++i)
            dumpfn("~");
        detail::_dump(dumpfn, "{}  (cols {}-{})\n", maybe_ellipsis, firstcol+1, lastcol+1);
    }
    else
    {
        dumpfn("\n");
    }

#ifdef RYML_DBG
    // next line: print the state flags
    {
        char flagbuf_[128];
        detail::_dump(dumpfn, "top state: {}\n", detail::_parser_flags_to_str(flagbuf_, m_evt_handler->m_curr->flags));
    }
#endif
}


//-----------------------------------------------------------------------------

template<class EventHandler>
template<class ...Args>
void ParseEngine<EventHandler>::_err(csubstr fmt, Args const& C4_RESTRICT ...args) const
{
    char errmsg[RYML_ERRMSG_SIZE];
    detail::_SubstrWriter writer(errmsg);
    auto dumpfn = [&writer](csubstr s){ writer.append(s); };
    detail::_dump(dumpfn, fmt, args...);
    writer.append('\n');
    _fmt_msg(dumpfn);
    size_t len = writer.pos < RYML_ERRMSG_SIZE ? writer.pos : RYML_ERRMSG_SIZE;
    m_evt_handler->cancel_parse();
    m_evt_handler->m_stack.m_callbacks.m_error(errmsg, len, m_evt_handler->m_curr->pos, m_evt_handler->m_stack.m_callbacks.m_user_data);
}


//-----------------------------------------------------------------------------
#ifdef RYML_DBG
template<class EventHandler>
template<class ...Args>
void ParseEngine<EventHandler>::_dbg(csubstr fmt, Args const& C4_RESTRICT ...args) const
{
    if(_dbg_enabled())
    {
        auto dumpfn = [](csubstr s){ if(s.str) fwrite(s.str, 1, s.len, stdout); };
        detail::_dump(dumpfn, fmt, args...);
        dumpfn("\n");
        _fmt_msg(dumpfn);
    }
}
#endif


//-----------------------------------------------------------------------------
template<class EventHandler>
bool ParseEngine<EventHandler>::_finished_file() const
{
    bool ret = m_evt_handler->m_curr->pos.offset >= m_buf.len;
    if(ret)
    {
        _c4dbgp("finished file!!!");
    }
    return ret;
}

template<class EventHandler>
C4_HOT C4_ALWAYS_INLINE bool ParseEngine<EventHandler>::_finished_line() const
{
    return m_evt_handler->m_curr->line_contents.rem.empty();
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_maybe_skip_whitespace_tokens()
{
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(rem.len && (rem.str[0] == ' ' _RYML_WITH_TAB_TOKENS(|| rem.str[0] == '\t')))
    {
        size_t pos = rem.first_not_of(_RYML_WITH_OR_WITHOUT_TAB_TOKENS(" \t", ' '));
        if(pos == npos)
            pos = rem.len; // maybe the line is just all whitespace
        _c4dbgpf("skip {} whitespace characters", pos);
        _line_progressed(pos);
    }
}

template<class EventHandler>
void ParseEngine<EventHandler>::_maybe_skipchars(char c)
{
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(rem.len && rem.str[0] == c)
    {
        size_t pos = rem.first_not_of(c);
        if(pos == npos)
            pos = rem.len; // maybe the line is just all c
        _c4dbgpf("skip {}x'{}'", pos, c);
        _line_progressed(pos);
    }
}

#ifdef RYML_NO_COVERAGE__TO_BE_DELETED
template<class EventHandler>
void ParseEngine<EventHandler>::_maybe_skipchars_up_to(char c, size_t max_to_skip)
{
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(rem.len && rem.str[0] == c)
    {
        size_t pos = rem.first_not_of(c);
        if(pos == npos)
            pos = rem.len; // maybe the line is just all c
        if(pos > max_to_skip)
            pos = max_to_skip;
        _c4dbgpf("skip {}x'{}'", pos, c);
        _line_progressed(pos);
    }
}
#endif

template<class EventHandler>
template<size_t N>
void ParseEngine<EventHandler>::_skipchars(const char (&chars)[N])
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->line_contents.rem.begins_with_any(chars));
    size_t pos = m_evt_handler->m_curr->line_contents.rem.first_not_of(chars);
    if(pos == npos)
        pos = m_evt_handler->m_curr->line_contents.rem.len; // maybe the line is just whitespace
    _c4dbgpf("skip {} characters", pos);
    _line_progressed(pos);
}

template<class EventHandler>
void ParseEngine<EventHandler>::_skip_comment()
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->line_contents.rem.begins_with('#'));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->line_contents.rem.is_sub(m_evt_handler->m_curr->line_contents.full));
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    csubstr full = m_evt_handler->m_curr->line_contents.full;
    // raise an error if the comment is not preceded by whitespace
    if(!full.begins_with('#'))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, rem.str > full.str);
        const char c = full[(size_t)(rem.str - full.str - 1)];
        if(C4_UNLIKELY(c != ' ' && c != '\t'))
            _RYML_CB_ERR(m_evt_handler->m_stack.m_callbacks, "comment not preceded by whitespace");
    }
    else
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, rem.str == full.str);
    }
    _c4dbgpf("comment was '{}'", rem);
    _line_progressed(rem.len);
}

template<class EventHandler>
void ParseEngine<EventHandler>::_maybe_skip_comment()
{
    csubstr s = m_evt_handler->m_curr->line_contents.rem.triml(' ');
    if(s.begins_with('#'))
    {
        _line_progressed((size_t)(s.str - m_evt_handler->m_curr->line_contents.rem.str));
        _skip_comment();
    }
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_maybe_scan_following_colon() noexcept
{
    if(m_evt_handler->m_curr->line_contents.rem.len)
    {
        if(m_evt_handler->m_curr->line_contents.rem.str[0] == ' ' || m_evt_handler->m_curr->line_contents.rem.str[0] == '\t')
        {
            size_t pos = m_evt_handler->m_curr->line_contents.rem.first_not_of(" \t");
            if(pos == npos)
                pos = m_evt_handler->m_curr->line_contents.rem.len; // maybe the line has only spaces
            _c4dbgpf("skip {}x'{}'", pos, ' ');
            _line_progressed(pos);
        }
        if(m_evt_handler->m_curr->line_contents.rem.len && (m_evt_handler->m_curr->line_contents.rem.str[0] == ':'))
        {
            _c4dbgp("found ':' colon next");
            _line_progressed(1);
            return true;
        }
    }
    return false;
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_maybe_scan_following_comma() noexcept
{
    if(m_evt_handler->m_curr->line_contents.rem.len)
    {
        if(m_evt_handler->m_curr->line_contents.rem.str[0] == ' ' || m_evt_handler->m_curr->line_contents.rem.str[0] == '\t')
        {
            size_t pos = m_evt_handler->m_curr->line_contents.rem.first_not_of(" \t");
            if(pos == npos)
                pos = m_evt_handler->m_curr->line_contents.rem.len; // maybe the line has only spaces
            _c4dbgpf("skip {}x'{}'", pos, ' ');
            _line_progressed(pos);
        }
        if(m_evt_handler->m_curr->line_contents.rem.len && (m_evt_handler->m_curr->line_contents.rem.str[0] == ','))
        {
            _c4dbgp("found ',' comma next");
            _line_progressed(1);
            return true;
        }
    }
    return false;
}


//-----------------------------------------------------------------------------

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_scan_anchor()
{
    csubstr s = m_evt_handler->m_curr->line_contents.rem;
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.begins_with('&'));
    csubstr anchor = s.range(1, s.first_of(' '));
    _line_progressed(1u + anchor.len);
    _maybe_skipchars(' ');
    return anchor;
}

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_scan_ref_seq()
{
    csubstr s = m_evt_handler->m_curr->line_contents.rem;
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.begins_with('*'));
    csubstr ref = s.first(s.first_of(",] :"));
    _line_progressed(ref.len);
    return ref;
}

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_scan_ref_map()
{
    csubstr s = m_evt_handler->m_curr->line_contents.rem;
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.begins_with('*'));
    csubstr ref = s.first(s.first_of(",} "));
    _line_progressed(ref.len);
    return ref;
}

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_scan_tag()
{
    csubstr rem = m_evt_handler->m_curr->line_contents.rem.triml(' ');
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, rem.begins_with('!'));
    csubstr t;
    if(rem.begins_with("!!"))
    {
        _c4dbgp("begins with '!!'");
        if(has_any(FLOW))
            t = rem.left_of(rem.first_of(" ,"));
        else
            t = rem.left_of(rem.first_of(' '));
    }
    else if(rem.begins_with("!<"))
    {
        _c4dbgp("begins with '!<'");
        t = rem.left_of(rem.first_of('>'), true);
    }
    #ifdef RYML_NO_COVERAGE__TO_BE_DELETED
    else if(rem.begins_with("!h!"))
    {
        _c4dbgp("begins with '!h!'");
        t = rem.left_of(rem.first_of(' '));
    }
    #endif
    else
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, rem.begins_with('!'));
        _c4dbgp("begins with '!'");
        if(has_any(FLOW))
            t = rem.left_of(rem.first_of(" ,"));
        else
            t = rem.left_of(rem.first_of(' '));
    }
    _line_progressed(t.len);
    _maybe_skip_whitespace_tokens();
    return t;
}


//-----------------------------------------------------------------------------

template<class EventHandler>
bool ParseEngine<EventHandler>::_is_valid_start_scalar_plain_flow(csubstr s)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, !s.empty());

    // it's not a scalar if it starts with any of these characters:
    switch(s.str[0])
    {
    // these are all legal tokens which mean no scalar is starting:
    case '[':
    case ']':
    case '{':
    case '}':
    case '!':
    case '&':
    case '*':
    case '|':
    case '>':
    case '#':
        _c4dbgpf("not a scalar: found non-scalar token '{}'", _c4prc(s.str[0]));
        return false;
    // '-' and ':' are illegal at the beginning if not followed by a scalar character
    case '-':
    case ':':
        if(s.len > 1)
        {
            switch(s.str[1])
            {
            case '\n':
            case '\r':
            case '{':
            case '[':
            //_RYML_WITHOUT_TAB_TOKENS(case '\t'):
                _c4err("invalid token \":{}\"", _c4prc(s.str[1]));
                break;
            case ' ':
            case '}':
            case ']':
                if(s.str[0] == ':')
                {
                    _c4dbgpf("not a scalar: found non-scalar token '{}{}'", s.str[0], s.str[1]);
                    return false;
                }
                break;
            default:
                break;
            }
        }
        else
        {
            return false;
        }
        break;
    case '?':
        if(s.len > 1)
        {
            switch(s.str[1])
            {
            case ' ':
            case '\n':
            case '\r':
            _RYML_WITHOUT_TAB_TOKENS(case '\t':)
                _c4dbgpf("not a scalar: found non-scalar token '?{}'", _c4prc(s.str[1]));
                return false;
            case '{':
            case '}':
            case '[':
            case ']':
                _c4err("invalid token \"?{}\"", _c4prc(s.str[1]));
                break;
            default:
                break;
            }
        }
        else
        {
            return false;
        }
        break;
    // everything else is a legal starting character
    default:
        break;
    }

    return true;
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_scan_scalar_plain_seq_flow(ScannedScalar *C4_RESTRICT sc)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(BLCK));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RSEQ|RSEQIMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(FLOW));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RVAL));

    substr s = m_evt_handler->m_curr->line_contents.rem;
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, !s.begins_with(' '));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, !s.begins_with('\n'));

    if(!s.len)
        return false;

    if(!_is_valid_start_scalar_plain_flow(s))
        return false;

    _c4dbgp("scanning seqflow scalar...");

    const size_t start_offset = m_evt_handler->m_curr->pos.offset;
    bool needs_filter = false;
    while(true)
    {
        _c4dbgpf("scanning scalar: curr line=[{}]~~~{}~~~", s.len, s);
        for(size_t i = 0; i < s.len; ++i)
        {
            const char c = s.str[i];
            switch(c)
            {
            case ',':
                _c4dbgpf("found terminating character at {}: '{}'", i, c);
                _line_progressed(i);
                if(m_evt_handler->m_curr->pos.offset + i > start_offset)
                {
                    goto ended_scalar;
                }
                else
                {
                    _c4dbgp("at the beginning. no scalar here.");
                    return false;
                }
                break;
            case ']':
                _c4dbgpf("found terminating character at {}: '{}'", i, c);
                _line_progressed(i);
                goto ended_scalar;
                break;
            case '#':
                _c4dbgp("found suspicious '#'");
                if(!i || (s.str[i-1] == ' ' _RYML_WITH_TAB_TOKENS(|| s.str[i-1] == '\t')))
                {
                    _c4dbgpf("found terminating character at {}: '{}'", i, c);
                    _line_progressed(i);
                    goto ended_scalar;
                }
                break;
            case ':':
                _c4dbgp("found suspicious ':'");
                if(s.len > i+1)
                {
                    const char next = s.str[i+1];
                    _c4dbgpf("next char is '{}'", _c4prc(next));
                    if(next == ' ' || next == ',' _RYML_WITH_TAB_TOKENS(|| next == '\t'))
                    {
                        _c4dbgp("map starting!");
                        if(m_evt_handler->m_curr->pos.offset + i > start_offset)
                        {
                            _c4dbgp("scalar finished!");
                            _line_progressed(i);
                            goto ended_scalar;
                        }
                        else
                        {
                            _c4dbgp("at the beginning. no scalar here.");
                            return false;
                        }
                    }
                    else
                    {
                        _c4dbgp("it's a scalar indeed.");
                        ++i; // skip the next char
                    }
                }
                else if(s.len == i+1)
                {
                    _c4dbgp("':' at line end. map starting!");
                    return false;
                }
                break;
            case '[':
            case '{':
            case '}':
                _line_progressed(i);
                _c4err("invalid character: '{}'", c); // noreturn
            default:
                ;
            }
        }
        _line_progressed(s.len);
        if(!_finished_file())
        {
            _c4dbgp("next line!");
            _line_ended();
            _scan_line();
        }
        else
        {
            _c4dbgp("file finished!");
            goto ended_scalar;
        }
        s = m_evt_handler->m_curr->line_contents.rem;
        needs_filter = true;
    }

ended_scalar:

    sc->scalar = m_buf.range(start_offset, m_evt_handler->m_curr->pos.offset).trimr(_RYML_WITH_OR_WITHOUT_TAB_TOKENS(" \t", ' '));
    sc->needs_filter = needs_filter;

    _c4prscalar("scanned plain scalar", sc->scalar, /*keep_newlines*/true);

    return true;
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_scan_scalar_plain_map_flow(ScannedScalar *C4_RESTRICT sc)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RSEQ) || has_any(RSEQIMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(BLCK));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RMAP|RSEQIMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(FLOW));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RKEY|RVAL|QMRK));

    substr s = m_evt_handler->m_curr->line_contents.rem;
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, !s.begins_with(' '));

    if(!s.len)
        return false;

    if(!_is_valid_start_scalar_plain_flow(s))
        return false;

    _c4dbgp("scanning scalar...");

    const size_t start_offset = m_evt_handler->m_curr->pos.offset;
    bool needs_filter = false;
    while(true)
    {
        for(size_t i = 0; i < s.len; ++i)
        {
            const char c = s.str[i];
            switch(c)
            {
            case ',':
            case '}':
                _line_progressed(i);
                _c4dbgpf("found terminating character: '{}'", c);
                goto ended_scalar;
            case ':':
                if(s.len == i+1 || s.str[i+1] == ' ' || s.str[i+1] == ',' || s.str[i+1] == '}' _RYML_WITH_TAB_TOKENS(|| s.str[i+1] == '\t'))
                {
                    _line_progressed(i);
                    _c4dbgpf("found terminating character: '{}'", c);
                    goto ended_scalar;
                }
                break;
            case '{':
            case '[':
                _line_progressed(i);
                _c4err("invalid character: '{}'", c); // noreturn
                break;
            case ']':
                _line_progressed(i);
                if(has_any(RSEQIMAP))
                    goto ended_scalar;
                else
                    _c4err("invalid character: '{}'", c); // noreturn
                break;
            case '#':
                if(!i || s.str[i-1] == ' ' _RYML_WITH_TAB_TOKENS(|| s.str[i-1] == '\t'))
                {
                    _line_progressed(i);
                    _c4dbgpf("found terminating character: '{}'", c);
                    goto ended_scalar;
                }
                break;
            default:
                ;
            }
        }
        _c4dbgp("next line!");
        _line_progressed(s.len);
        if(!_finished_file())
        {
            _c4dbgp("next line!");
            _line_ended();
            _scan_line();
        }
        else
        {
            _c4dbgp("file finished!");
            goto ended_scalar;
        }
        s = m_evt_handler->m_curr->line_contents.rem;
        needs_filter = true;
    }

ended_scalar:

    sc->scalar = m_buf.range(start_offset, m_evt_handler->m_curr->pos.offset).trimr(_RYML_WITH_OR_WITHOUT_TAB_TOKENS(" \n\t\r", " \n\r"));
    sc->needs_filter = needs_filter;

    _c4dbgpf("scalar was [{}]~~~{}~~~", sc->scalar.len, sc->scalar);

    return true;
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_scan_scalar_seq_json(ScannedScalar *C4_RESTRICT sc)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(BLCK));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RSEQ));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(FLOW));

    substr s = m_evt_handler->m_curr->line_contents.rem;
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, !s.begins_with(' '));

    if(!s.len)
        return false;

    _c4dbgp("scanning scalar...");

    switch(s.str[0])
    {
    case ']':
    case '{':
    case ',':
        _c4dbgp("not a scalar.");
        return false;
    }

    {
        const size_t len = _is_special_json_scalar(s);
        if(len)
        {
            sc->scalar = s.first(len);
            sc->needs_filter = false;
            _c4dbgpf("special json scalar: '{}'", sc->scalar);
            _line_progressed(len);
            return true;
        }
    }

    // must be a number
    size_t i = 0;
    for( ; i < s.len; ++i)
    {
        const char c = s.str[i];
        switch(c)
        {
        case ',':
        case ']':
        case ' ':
        case '\t':
            _c4dbgpf("found terminating character: '{}'", c);
            goto ended_scalar;
        case '#':
            if(!i || s.str[i-1] == ' ')
            {
                _c4dbgpf("found terminating character: '{}'", c);
                goto ended_scalar;
            }
            break;
        default:
            ;
        }
    }

ended_scalar:

    if(C4_LIKELY(i > 0))
    {
        _line_progressed(i);
        sc->scalar = s.first(i);
        sc->needs_filter = false;
        _c4dbgpf("scalar was [{}]~~~{}~~~", sc->scalar.len, sc->scalar);
        return true;
    }

    return false;
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_scan_scalar_map_json(ScannedScalar *C4_RESTRICT sc)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RSEQ));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(BLCK));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(FLOW));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RKEY|RVAL));

    substr s = m_evt_handler->m_curr->line_contents.rem;
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, !s.begins_with(' '));

    if(!s.len)
        return false;

    _c4dbgp("scanning scalar...");

    {
        const size_t len = _is_special_json_scalar(s);
        if(len)
        {
            sc->scalar = s.first(len);
            sc->needs_filter = false;
            _c4dbgpf("special json scalar: '{}'", sc->scalar);
            _line_progressed(len);
            return true;
        }
    }

    // must be a number
    size_t i = 0;
    for( ; i < s.len; ++i)
    {
        const char c = s.str[i];
        switch(c)
        {
        case ',':
        case '}':
        case ' ':
        case '\t':
            _c4dbgpf("found terminating character: '{}'", c);
            goto ended_scalar;
        case '#':
            if(!i || s.str[i-1] == ' ')
            {
                _c4dbgpf("found terminating character: '{}'", c);
                goto ended_scalar;
            }
            break;
        default:
            ;
        }
    }

ended_scalar:

    if(C4_LIKELY(i > 0))
    {
        _line_progressed(i);
        sc->scalar = s.first(i);
        sc->needs_filter = false;
        _c4dbgpf("scalar was [{}]~~~{}~~~", sc->scalar.len, sc->scalar);
        return true;
    }

    return false;
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_is_doc_begin(csubstr s)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s[0] == '-');
    return (m_evt_handler->m_curr->line_contents.indentation == 0u && _at_line_begin() && _is_doc_begin_token(s));
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_is_doc_end(csubstr s)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s[0] == '.');
    return (m_evt_handler->m_curr->line_contents.indentation == 0u && _at_line_begin() && _is_doc_end_token(s));
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_scan_scalar_plain_blck(ScannedScalar *C4_RESTRICT sc, size_t indentation)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(FLOW));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RSEQIMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(BLCK|RUNK|USTY));

    substr s = m_evt_handler->m_curr->line_contents.rem;
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, !s.begins_with(' '));

    if(!s.len)
        return false;

    switch(s.str[0])
    {
    case '-':
        if(_is_blck_token(s))
        {
            return false;
        }
        else if(_is_doc_begin(s))
        {
            _c4dbgp("token is doc start");
            return false;
        }
        break;
    case ':':
    case '?':
        if(_is_blck_token(s))
            return false;
        break;
    case '[':
    case '{':
    case '&':
    case '*':
    case '!':
    _RYML_WITH_TAB_TOKENS(case '\t':)
        return false;
    case '.':
        if(_is_doc_end(s))
        {
            _c4dbgp("token is doc end");
            return false;
        }
        break;
    }

    _c4dbgpf("plain scalar! indentation={}", indentation);

    const size_t start_offset = m_evt_handler->m_curr->pos.offset;
    const size_t start_line = m_evt_handler->m_curr->pos.line;

    bool needs_filter = false;
    while(true)
    {
        _c4dbgpf("plain scalar line: [{}]~~~{}~~~", s.len, s);
        for(size_t i = 0; i < s.len; ++i)
        {
            const char curr = s.str[i];
            //_c4dbgpf("[{}]='{}'", i, _c4prc(curr));
            switch(curr)
            {
            case ':':
                _c4dbgpf("[{}]: got suspicious ':'", i);
                // are there more characters?
                if((i + 1 == s.len) || ((s.str[i+1] == ' ') _RYML_WITH_TAB_TOKENS( || (s.str[i+1] == '\t'))))
                {
                    _c4dbgpf("followed by '{}'", i+1 == s.len ? csubstr("\\n") : _c4prc(s.str[i+1]));
                    _line_progressed(i);
                    // ': ' is accepted only on the first line
                    if(C4_LIKELY(m_evt_handler->m_curr->pos.line == start_line))
                    {
                        _c4dbgp("start line. scalar ends here");
                        goto ended_scalar;
                    }
                    else
                    {
                        _c4err("parse error");
                    }
                }
                else
                {
                    size_t j = i;
                    while(j + 1 < s.len && s.str[j+1] == ':')
                    {
                        _c4dbgp("skip colon");
                        ++j;
                    }
                    i = j > i ? j-1 : i;
                    _c4dbgp("nothing to see here");
                }
                break;
            case '#':
                _c4dbgp("got suspicious '#'");
                if(!i || (s.str[i-1] == ' ' || s.str[i-1] == '\t'))
                {
                    _c4dbgp("comment! scalar ends here");
                    _line_progressed(i);
                    goto ended_scalar;
                }
                else
                {
                    _c4dbgp("nothing to see here");
                }
                break;
            }
        }
        _line_progressed(s.len);
        csubstr next_peeked = _peek_next_line(m_evt_handler->m_curr->pos.offset);
        next_peeked = next_peeked.trimr("\n\r");
        const size_t next_indentation = next_peeked.first_not_of(' ');
        _c4dbgpf("indentation curr={} next={}", indentation, next_indentation);
        if(next_indentation < indentation)
        {
            _c4dbgp("smaller indentation! scalar ended");
            goto ended_scalar;
        }
        else if(next_indentation == 0 && next_peeked.len > 0)
        {
            const char first = next_peeked.str[0];
            switch(first)
            {
            case '-':
                next_peeked = next_peeked.trimr("\n\r");
                _c4dbgpf("doc begin? peeked=[{}]~~~{}{}~~~", next_peeked.len, next_peeked.len >= 3 ? next_peeked.first(3) : next_peeked, next_peeked.len > 3 ? "..." : "");
                if(_is_doc_begin_token(next_peeked))
                {
                    _c4dbgp("doc begin! scalar ended");
                    goto ended_scalar;
                }
                break;
            case '.':
                next_peeked = next_peeked.trimr("\n\r");
                _c4dbgpf("doc end? peeked=[{}]~~~{}{}~~~", next_peeked.len, next_peeked.len >= 3 ? next_peeked.first(3) : next_peeked, next_peeked.len > 3 ? "..." : "");
                if(_is_doc_end_token(next_peeked))
                {
                    _c4dbgp("doc end! scalar ended");
                    goto ended_scalar;
                }
                break;
            }
        }
        // load with next line
        _c4dbgp("next line!");
        if(!_finished_file())
        {
            _c4dbgp("next line!");
            _line_ended();
            _scan_line();
        }
        else
        {
            _c4dbgp("file finished!");
            goto ended_scalar;
        }
        s = m_evt_handler->m_curr->line_contents.rem;
        needs_filter = true;
    }

ended_scalar:

    sc->scalar = m_buf.range(start_offset, m_evt_handler->m_curr->pos.offset).trimr(" \n\r\t");
    sc->needs_filter = needs_filter;

    _c4dbgpf("scalar was [{}]~~~{}~~~", sc->scalar.len, sc->scalar);

    return true;
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_scan_scalar_plain_seq_blck(ScannedScalar *C4_RESTRICT sc)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(FLOW));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RSEQIMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RSEQ));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(BLCK));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RVAL));
    return _scan_scalar_plain_blck(sc, m_evt_handler->m_curr->indref + 1u);
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_scan_scalar_plain_map_blck(ScannedScalar *C4_RESTRICT sc)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RSEQ));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(FLOW));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(BLCK));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RKEY|RVAL|QMRK));
    return _scan_scalar_plain_blck(sc, m_evt_handler->m_curr->indref + 1u);
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_scan_scalar_plain_unk(ScannedScalar *C4_RESTRICT sc)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks,  has_any(RUNK|USTY));
    return _scan_scalar_plain_blck(sc, m_evt_handler->m_curr->indref);
}


//-----------------------------------------------------------------------------

template<class EventHandler>
substr ParseEngine<EventHandler>::_peek_next_line(size_t pos) const
{
    substr rem{}; // declare here because of the goto
    size_t nlpos{}; // declare here because of the goto
    pos = pos == npos ? m_evt_handler->m_curr->pos.offset : pos;
    if(pos >= m_buf.len)
        goto next_is_empty;

    // look for the next newline chars, and jump to the right of those
    rem = from_next_line(m_buf.sub(pos));
    if(rem.empty())
        goto next_is_empty;

    // now get everything up to and including the following newline chars
    nlpos = rem.first_of("\r\n");
    if((nlpos != csubstr::npos) && (nlpos + 1 < rem.len))
        nlpos += _extend_from_combined_newline(rem[nlpos], rem[nlpos+1]);
    rem = rem.left_of(nlpos, /*include_pos*/true);

    _c4dbgpf("peek next line @ {}: (len={})'{}'", pos, rem.len, rem.trimr("\r\n"));
    return rem;

next_is_empty:
    _c4dbgpf("peek next line @ {}: (len=0)''", pos);
    return {};
}

//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_scan_line()
{
    if(C4_LIKELY(m_evt_handler->m_curr->pos.offset < m_buf.len))
        m_evt_handler->m_curr->line_contents.reset_with_next_line(m_buf, m_evt_handler->m_curr->pos.offset);
    else
        m_evt_handler->m_curr->line_contents.reset(m_buf.last(0), m_buf.last(0));
}

template<class EventHandler>
void ParseEngine<EventHandler>::_line_progressed(size_t ahead)
{
    _c4dbgpf("line[{}] ({} cols) progressed by {}:  col {}-->{}   offset {}-->{}", m_evt_handler->m_curr->pos.line, m_evt_handler->m_curr->line_contents.full.len, ahead, m_evt_handler->m_curr->pos.col, m_evt_handler->m_curr->pos.col+ahead, m_evt_handler->m_curr->pos.offset, m_evt_handler->m_curr->pos.offset+ahead);
    m_evt_handler->m_curr->pos.offset += ahead;
    m_evt_handler->m_curr->pos.col += ahead;
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->pos.col <= m_evt_handler->m_curr->line_contents.stripped.len+1);
    m_evt_handler->m_curr->line_contents.rem = m_evt_handler->m_curr->line_contents.rem.sub(ahead);
}

template<class EventHandler>
void ParseEngine<EventHandler>::_line_ended()
{
    _c4dbgpf("line[{}] ({} cols) ended! offset {}-->{} / col {}-->{}",
             m_evt_handler->m_curr->pos.line,
             m_evt_handler->m_curr->line_contents.full.len,
             m_evt_handler->m_curr->pos.offset, m_evt_handler->m_curr->pos.offset + m_evt_handler->m_curr->line_contents.full.len - m_evt_handler->m_curr->line_contents.stripped.len,
             m_evt_handler->m_curr->pos.col, 1);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->pos.col == m_evt_handler->m_curr->line_contents.stripped.len + 1);
    m_evt_handler->m_curr->pos.offset += m_evt_handler->m_curr->line_contents.full.len - m_evt_handler->m_curr->line_contents.stripped.len;
    ++m_evt_handler->m_curr->pos.line;
    m_evt_handler->m_curr->pos.col = 1;
}

template<class EventHandler>
void ParseEngine<EventHandler>::_line_ended_undo()
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->pos.col == 1u);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->pos.line > 0u);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->pos.offset >= m_evt_handler->m_curr->line_contents.full.len - m_evt_handler->m_curr->line_contents.stripped.len);
    const size_t delta = m_evt_handler->m_curr->line_contents.full.len - m_evt_handler->m_curr->line_contents.stripped.len;
    _c4dbgpf("line[{}] undo ended! line {}-->{}, offset {}-->{}", m_evt_handler->m_curr->pos.line, m_evt_handler->m_curr->pos.line, m_evt_handler->m_curr->pos.line - 1, m_evt_handler->m_curr->pos.offset, m_evt_handler->m_curr->pos.offset - delta);
    m_evt_handler->m_curr->pos.offset -= delta;
    --m_evt_handler->m_curr->pos.line;
    m_evt_handler->m_curr->pos.col = m_evt_handler->m_curr->line_contents.stripped.len + 1u;
    // don't forget to undo also the changes to the remainder of the line
    //_RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->pos.offset >= m_buf.len || m_buf[m_evt_handler->m_curr->pos.offset] == '\n' || m_buf[m_evt_handler->m_curr->pos.offset] == '\r');
    m_evt_handler->m_curr->line_contents.rem = m_buf.sub(m_evt_handler->m_curr->pos.offset, 0);
}


//-----------------------------------------------------------------------------
template<class EventHandler>
void ParseEngine<EventHandler>::_set_indentation(size_t indentation)
{
    m_evt_handler->m_curr->indref = indentation;
    _c4dbgpf("state[{}]: saving indentation: {}", m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref);
}

template<class EventHandler>
void ParseEngine<EventHandler>::_save_indentation()
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->line_contents.rem.begin() >= m_evt_handler->m_curr->line_contents.full.begin());
    m_evt_handler->m_curr->indref = m_evt_handler->m_curr->line_contents.current_col();
    _c4dbgpf("state[{}]: saving indentation: {}", m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref);
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_end_map_blck()
{
    _c4dbgp("mapblck: end");
    if(has_any(RKCL|RVAL))
    {
        _c4dbgp("mapblck: set missing val");
        _handle_annotations_before_blck_val_scalar();
        m_evt_handler->set_val_scalar_plain({});
    }
    else if(has_any(QMRK))
    {
        _c4dbgp("mapblck: set missing keyval");
        _handle_annotations_before_blck_key_scalar();
        m_evt_handler->set_key_scalar_plain({});
        _handle_annotations_before_blck_val_scalar();
        m_evt_handler->set_val_scalar_plain({});
    }
    m_evt_handler->end_map();
}

template<class EventHandler>
void ParseEngine<EventHandler>::_end_seq_blck()
{
    if(has_any(RVAL))
    {
        _c4dbgp("seqblck: set missing val");
        _handle_annotations_before_blck_val_scalar();
        m_evt_handler->set_val_scalar_plain({});
    }
    m_evt_handler->end_seq();
}

template<class EventHandler>
void ParseEngine<EventHandler>::_end2_map()
{
    _c4dbgp("map: end");
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RMAP));
    if(has_any(BLCK))
    {
        _end_map_blck();
    }
    else
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(FLOW));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(USTY));
        m_evt_handler->_pop();
    }
}

template<class EventHandler>
void ParseEngine<EventHandler>::_end2_seq()
{
    _c4dbgp("seq: end");
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RSEQ));
    if(has_any(BLCK))
    {
        _end_seq_blck();
    }
    else
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(FLOW));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(USTY));
        m_evt_handler->_pop();
    }
}

template<class EventHandler>
void ParseEngine<EventHandler>::_begin2_doc()
{
    m_doc_empty = true;
    add_flags(RDOC);
    m_evt_handler->begin_doc();
    m_evt_handler->m_curr->indref = 0; // ?
}

template<class EventHandler>
void ParseEngine<EventHandler>::_begin2_doc_expl()
{
    m_doc_empty = true;
    add_flags(RDOC);
    m_evt_handler->begin_doc_expl();
    m_evt_handler->m_curr->indref = 0; // ?
}

template<class EventHandler>
void ParseEngine<EventHandler>::_end2_doc()
{
    _c4dbgp("doc: end");
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RDOC));
    if(m_doc_empty)
    {
        _c4dbgp("doc was empty; add empty val");
        m_evt_handler->set_val_scalar_plain({});
    }
    m_evt_handler->end_doc();
}

template<class EventHandler>
void ParseEngine<EventHandler>::_end2_doc_expl()
{
    _c4dbgp("doc: end");
    if(m_doc_empty)
    {
        _c4dbgp("doc: no children; add empty val");
        m_evt_handler->set_val_scalar_plain({});
    }
    m_evt_handler->end_doc_expl();
}

template<class EventHandler>
void ParseEngine<EventHandler>::_maybe_begin_doc()
{
    if(has_none(RDOC))
    {
        _c4dbgp("doc must be started");
        _begin2_doc();
    }
}
template<class EventHandler>
void ParseEngine<EventHandler>::_maybe_end_doc()
{
    if(has_any(RDOC))
    {
        _c4dbgp("doc must be finished");
        _end2_doc();
    }
}

template<class EventHandler>
void ParseEngine<EventHandler>::_end_doc_suddenly__pop()
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_stack.size() >= 1);
    if(m_evt_handler->m_stack[0].flags & RDOC)
    {
        _c4dbgp("root is RDOC");
        if(m_evt_handler->m_curr->level != 0)
            _handle_indentation_pop(&m_evt_handler->m_stack[0]);
    }
    else if((m_evt_handler->m_stack.size() > 1) && (m_evt_handler->m_stack[1].flags & RDOC))
    {
        _c4dbgp("root is STREAM");
        if(m_evt_handler->m_curr->level != 1)
            _handle_indentation_pop(&m_evt_handler->m_stack[1]);
    }
    else
    {
        _c4err("internal error");
    }
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RDOC));
}

template<class EventHandler>
void ParseEngine<EventHandler>::_end_doc_suddenly()
{
    _c4dbgp("end doc suddenly");
    _end_doc_suddenly__pop();
    _end2_doc_expl();
    addrem_flags(RUNK|RTOP|NDOC, RMAP|RSEQ|RDOC);
}

template<class EventHandler>
void ParseEngine<EventHandler>::_start_doc_suddenly()
{
    _c4dbgp("start doc suddenly");
    _end_doc_suddenly__pop();
    _end2_doc();
    _begin2_doc_expl();
}

template<class EventHandler>
void ParseEngine<EventHandler>::_end_stream()
{
    _c4dbgpf("end_stream, level={} node_id={}", m_evt_handler->m_curr->level, m_evt_handler->m_curr->node_id);
    if(has_all(RSEQ|FLOW))
        _c4err("missing terminating ]");
    else if(has_all(RMAP|FLOW))
        _c4err("missing terminating }");
    if(m_evt_handler->m_stack.size() > 1)
        _handle_indentation_pop(m_evt_handler->m_stack.begin());
    if(has_all(RDOC))
    {
        _end2_doc();
    }
    else if(has_all(RTOP|RUNK))
    {
        if(m_pending_anchors.num_entries || m_pending_tags.num_entries)
        {
            if(m_doc_empty)
            {
                m_evt_handler->begin_doc();
                _handle_annotations_before_blck_val_scalar();
                m_evt_handler->set_val_scalar_plain({});
                m_evt_handler->end_doc();
            }
        }
    }
    m_evt_handler->end_stream();
}


template<class EventHandler>
void ParseEngine<EventHandler>::_handle_indentation_pop(ParserState const* popto)
{
    _c4dbgpf("popping {} level{}: from level {}(@ind={}) to level {}(@ind={})", m_evt_handler->m_curr->level - popto->level, (((m_evt_handler->m_curr->level - popto->level) > 1) ? "s" : ""), m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref, popto->level, popto->indref);
    while(m_evt_handler->m_curr != popto)
    {
        if(has_any(RSEQ))
        {
            _c4dbgpf("popping seq at level {} (indentation={},addr={})", m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref, m_evt_handler->m_curr);
            _end2_seq();
        }
        else if(has_any(RMAP))
        {
            _c4dbgpf("popping map at level {} (indentation={},addr={})", m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref, m_evt_handler->m_curr);
            _end2_map();
        }
        else
        {
            break;
        }
    }
    _c4dbgpf("current level is {} (indentation={})", m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref);
}

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_indentation_pop_from_block_seq()
{
    // search the stack frame to jump to based on its indentation
    using state_type = typename EventHandler::state;
    state_type const* popto = nullptr;
    auto &stack = m_evt_handler->m_stack;
    _RYML_CB_ASSERT(stack.m_callbacks, stack.is_contiguous()); // this search relies on the stack being contiguous
    _RYML_CB_ASSERT(stack.m_callbacks, m_evt_handler->m_curr >= stack.begin() && m_evt_handler->m_curr < stack.end());
    const size_t ind = m_evt_handler->m_curr->line_contents.indentation;
    #ifdef RYML_DBG
    if(_dbg_enabled())
    {
        char flagbuf_[128];
        for(state_type const& s : stack)
            _dbg_printf("state[{}]: ind={} node={} flags={}\n", s.level, s.indref, s.node_id, detail::_parser_flags_to_str(flagbuf_, s.flags));
    }
    #endif
    for(state_type const* s = m_evt_handler->m_curr-1; s >= stack.begin(); --s)
    {
        _c4dbgpf("searching for state with indentation {}. curr={} (level={},node={})", ind, s->indref, s->level, s->node_id);
        if(s->indref == ind)
        {
            _c4dbgpf("gotit!!! level={} node={}", s->level, s->node_id);
            popto = s;
            break;
        }
    }
    if(!popto || popto >= m_evt_handler->m_curr || popto->level >= m_evt_handler->m_curr->level)
    {
        _c4err("parse error: incorrect indentation?");
    }
    _handle_indentation_pop(popto);
}

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_indentation_pop_from_block_map()
{
    // search the stack frame to jump to based on its indentation
    using state_type = typename EventHandler::state;
    auto &stack = m_evt_handler->m_stack;
    _RYML_CB_ASSERT(stack.m_callbacks, stack.is_contiguous()); // this search relies on the stack being contiguous
    _RYML_CB_ASSERT(stack.m_callbacks, m_evt_handler->m_curr >= stack.begin() && m_evt_handler->m_curr < stack.end());
    const size_t ind = m_evt_handler->m_curr->line_contents.indentation;
    state_type const* popto = nullptr;
    #ifdef RYML_DBG
    char flagbuf_[128];
    if(_dbg_enabled())
    {
        for(state_type const& s : stack)
            _dbg_printf("state[{}]: ind={} node={} flags={}\n", s.level, s.indref, s.node_id, detail::_parser_flags_to_str(flagbuf_, s.flags));
    }
    #endif
    for(state_type const* s = m_evt_handler->m_curr-1; s > stack.begin(); --s) // never go to the stack bottom. that's the root
    {
        _c4dbgpf("searching for state with indentation {}. current: ind={},level={},node={},flags={}", ind, s->indref, s->level, s->node_id, detail::_parser_flags_to_str(flagbuf_, s->flags));
        if(s->indref < ind)
        {
            break;
        }
        else if(s->indref == ind)
        {
            _c4dbgpf("same indentation!!! level={} node={}", s->level, s->node_id);
            if(popto && has_any(RTOP, s) && has_none(RMAP|RSEQ, s))
            {
                break;
            }
            popto = s;
            if(has_all(RSEQ|BLCK, s))
            {
                csubstr rem = m_evt_handler->m_curr->line_contents.rem;
                const size_t first = rem.first_not_of(' ');
                _RYML_CB_ASSERT(stack.m_callbacks, first == ind || first == npos);
                rem = rem.right_of(first, true);
                _c4dbgpf("indentless? rem='{}' first={}", rem, first);
                if(rem.begins_with('-') && _is_blck_token(rem))
                {
                    _c4dbgp("parent was indentless seq");
                    break;
                }
            }
        }
    }
    if(!popto || popto >= m_evt_handler->m_curr || popto->level >= m_evt_handler->m_curr->level)
    {
        _c4err("parse error: incorrect indentation?");
    }
    _handle_indentation_pop(popto);
}


//-----------------------------------------------------------------------------
template<class EventHandler>
typename ParseEngine<EventHandler>::ScannedScalar ParseEngine<EventHandler>::_scan_scalar_squot()
{
    // quoted scalars can spread over multiple lines!
    // nice explanation here: http://yaml-multiline.info/

    // a span to the end of the file
    size_t b = m_evt_handler->m_curr->pos.offset;
    substr s = m_buf.sub(b);
    if(s.begins_with(' '))
    {
        s = s.triml(' ');
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_buf.sub(b).is_super(s));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.begin() >= m_buf.sub(b).begin());
        _line_progressed((size_t)(s.begin() - m_buf.sub(b).begin()));
    }
    b = m_evt_handler->m_curr->pos.offset; // take this into account
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.begins_with('\''));

    // skip the opening quote
    _line_progressed(1);
    s = s.sub(1);

    bool needs_filter = false;

    size_t numlines = 1; // we already have one line
    size_t pos = npos; // find the pos of the matching quote
    while( ! _finished_file())
    {
        const csubstr line = m_evt_handler->m_curr->line_contents.rem;
        bool line_is_blank = true;
        _c4dbgpf("scanning single quoted scalar @ line[{}]: ~~~{}~~~", m_evt_handler->m_curr->pos.line, line);
        for(size_t i = 0; i < line.len; ++i)
        {
            const char curr = line.str[i];
            if(curr == '\'') // single quotes are escaped with two single quotes
            {
                const char next = i+1 < line.len ? line.str[i+1] : '~';
                if(next != '\'') // so just look for the first quote
                {                // without another after it
                    pos = i;
                    break;
                }
                else
                {
                    needs_filter = true; // needs filter to remove escaped quotes
                    ++i; // skip the escaped quote
                }
            }
            else if(curr != ' ')
            {
                line_is_blank = false;
            }
        }

        // leading whitespace also needs filtering
        needs_filter = needs_filter
            || (numlines > 1)
            || line_is_blank
            || (_at_line_begin() && line.begins_with(' '));

        if(pos == npos)
        {
            _line_progressed(line.len);
            ++numlines;
        }
        else
        {
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, pos >= 0 && pos < m_buf.len);
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_buf[m_evt_handler->m_curr->pos.offset + pos] == '\'');
            _line_progressed(pos + 1); // progress beyond the quote
            pos = m_evt_handler->m_curr->pos.offset - b - 1; // but we stop before it
            break;
        }

        _line_ended();
        _scan_line();
    }

    if(pos == npos)
    {
        _c4err("reached end of file while looking for closing quote");
    }
    else
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, pos > 0);
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.end() >= m_buf.begin() && s.end() <= m_buf.end());
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.end() == m_buf.end() || *s.end() == '\'');
        s = s.sub(0, pos-1);
    }

    _c4prscalar("scanned squoted scalar", s, /*keep_newlines*/true);

    return ScannedScalar { s, needs_filter };
}


//-----------------------------------------------------------------------------
template<class EventHandler>
typename ParseEngine<EventHandler>::ScannedScalar ParseEngine<EventHandler>::_scan_scalar_dquot()
{
    // quoted scalars can spread over multiple lines!
    // nice explanation here: http://yaml-multiline.info/

    // a span to the end of the file
    size_t b = m_evt_handler->m_curr->pos.offset;
    substr s = m_buf.sub(b);
    if(s.begins_with(' '))
    {
        s = s.triml(' ');
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_buf.sub(b).is_super(s));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.begin() >= m_buf.sub(b).begin());
        _line_progressed((size_t)(s.begin() - m_buf.sub(b).begin()));
    }
    b = m_evt_handler->m_curr->pos.offset; // take this into account
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.begins_with('"'));

    // skip the opening quote
    _line_progressed(1);
    s = s.sub(1);

    bool needs_filter = false;

    size_t numlines = 1; // we already have one line
    size_t pos = npos; // find the pos of the matching quote
    while( ! _finished_file())
    {
        const csubstr line = m_evt_handler->m_curr->line_contents.rem;
        bool line_is_blank = true;
        _c4dbgpf("scanning double quoted scalar @ line[{}]:  line='{}'", m_evt_handler->m_curr->pos.line, line);
        for(size_t i = 0; i < line.len; ++i)
        {
            const char curr = line.str[i];
            if(curr != ' ')
                line_is_blank = false;
            // every \ is an escape
            if(curr == '\\')
            {
                const char next = i+1 < line.len ? line.str[i+1] : '~';
                needs_filter = true;
                if(next == '"' || next == '\\')
                    ++i;
            }
            else if(curr == '"')
            {
                pos = i;
                break;
            }
        }

        // leading whitespace also needs filtering
        needs_filter = needs_filter
            || (numlines > 1)
            || line_is_blank
            || (_at_line_begin() && line.begins_with(' '));

        if(pos == npos)
        {
            _line_progressed(line.len);
            ++numlines;
        }
        else
        {
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, pos >= 0 && pos < m_buf.len);
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_buf[m_evt_handler->m_curr->pos.offset + pos] == '"');
            _line_progressed(pos + 1); // progress beyond the quote
            pos = m_evt_handler->m_curr->pos.offset - b - 1; // but we stop before it
            break;
        }

        _line_ended();
        _scan_line();
    }

    if(pos == npos)
    {
        _c4err("reached end of file looking for closing quote");
    }
    else
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, pos > 0);
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.end() == m_buf.end() || *s.end() == '"');
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.end() >= m_buf.begin() && s.end() <= m_buf.end());
        s = s.sub(0, pos-1);
    }

    _c4prscalar("scanned dquoted scalar", s, /*keep_newlines*/true);

    return ScannedScalar { s, needs_filter };
}


//-----------------------------------------------------------------------------
template<class EventHandler>
void ParseEngine<EventHandler>::_scan_block(ScannedBlock *C4_RESTRICT sb, size_t indref)
{
    _c4dbgpf("blck: indref={}", indref);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, indref != npos);

    // nice explanation here: http://yaml-multiline.info/
    csubstr s = m_evt_handler->m_curr->line_contents.rem;
    csubstr trimmed = s.triml(' ');
    if(trimmed.str > s.str)
    {
        _c4dbgp("skipping whitespace");
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, trimmed.str >= s.str);
        _line_progressed(static_cast<size_t>(trimmed.str - s.str));
        s = trimmed;
    }
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.begins_with('|') || s.begins_with('>'));

    _c4dbgpf("blck: specs=[{}]~~~{}~~~", s.len, s);

    // parse the spec
    BlockChomp_e chomp = CHOMP_CLIP; // default to clip unless + or - are used
    size_t indentation = npos; // have to find out if no spec is given
    csubstr digits;
    if(s.len > 1)
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, s.begins_with_any("|>"));
        csubstr t = s.sub(1);
        _c4dbgpf("blck: spec is multichar: '{}'", t);
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, t.len >= 1);
        size_t pos = t.first_of("-+");
        _c4dbgpf("blck: spec chomp char at {}", pos);
        if(pos != npos)
        {
            if(t[pos] == '-')
                chomp = CHOMP_STRIP;
            else if(t[pos] == '+')
                chomp = CHOMP_KEEP;
            if(pos == 0)
                t = t.sub(1);
            else
                t = t.first(pos);
        }
        // from here to the end, only digits are considered
        digits = t.left_of(t.first_not_of("0123456789"));
        if( ! digits.empty())
        {
            if(C4_UNLIKELY(digits.len > 1))
                _c4err("parse error: invalid indentation");
            _c4dbgpf("blck: parse indentation digits: [{}]~~~{}~~~", digits.len, digits);
            if(C4_UNLIKELY( ! c4::atou(digits, &indentation)))
                _c4err("parse error: could not read indentation as decimal");
            if(C4_UNLIKELY( ! indentation))
                _c4err("parse error: null indentation");
            _c4dbgpf("blck: indentation specified: {}. add {} from curr state -> {}", indentation, m_evt_handler->m_curr->indref, indentation+indref);
            indentation += m_evt_handler->m_curr->indref;
        }
    }

    _c4dbgpf("blck: style={}  chomp={}  indentation={}", s.begins_with('>') ? "fold" : "literal", chomp==CHOMP_CLIP ? "clip" : (chomp==CHOMP_STRIP ? "strip" : "keep"), indentation);

    // finish the current line
    _line_progressed(s.len);
    _line_ended();
    _scan_line();

    // start with a zero-length block, already pointing at the right place
    substr raw_block(m_buf.data() + m_evt_handler->m_curr->pos.offset, size_t(0));// m_evt_handler->m_curr->line_contents.full.sub(0, 0);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, raw_block.begin() == m_evt_handler->m_curr->line_contents.full.begin());

    // read every full line into a raw block,
    // from which newlines are to be stripped as needed.
    //
    // If no explicit indentation was given, pick it from the first
    // non-empty line. See
    // https://yaml.org/spec/1.2.2/#8111-block-indentation-indicator
    size_t num_lines = 0;
    size_t first = m_evt_handler->m_curr->pos.line;
    size_t provisional_indentation = npos;
    LineContents lc;
    while(( ! _finished_file()))
    {
        // peek next line, but do not advance immediately
        lc.reset_with_next_line(m_buf, m_evt_handler->m_curr->pos.offset);
        _c4dbgpf("blck: peeking at [{}]~~~{}~~~", lc.stripped.len, lc.stripped);
        // evaluate termination conditions
        if(indentation != npos)
        {
            _c4dbgpf("blck: indentation={}", indentation);
            // stop when the line is deindented and not empty
            if(lc.indentation < indentation && ( ! lc.rem.trim(" \t").empty()))
            {
                if(raw_block.len)
                {
                    _c4dbgpf("blck: indentation decreased ref={} thisline={}", indentation, lc.indentation);
                }
                else
                {
                    _c4err("indentation decreased without any scalar");
                }
                break;
            }
            else if(indentation == 0)
            {
                _c4dbgpf("blck: noindent. lc.rem=[{}]~~~{}~~~", lc.rem.len, lc.rem);
                if(_is_doc_token(lc.rem))
                {
                    _c4dbgp("blck: stop. indentation=0 and doc ended");
                    break;
                }
            }
        }
        else
        {
            const size_t fns = lc.stripped.first_not_of(' ');
            _c4dbgpf("blck: indentation ref not set. firstnonws={}", fns);
            if(fns != npos) // non-empty line
            {
                _RYML_WITH_TAB_TOKENS(
                    if(C4_UNLIKELY(lc.stripped.begins_with('\t')))
                        _c4err("parse error");
                )
                _c4dbgpf("blck: line not empty. indref={} indprov={} indentation={}", indref, provisional_indentation, lc.indentation);
                if(provisional_indentation == npos)
                {
                    if(lc.indentation < indref)
                    {
                        _c4dbgpf("blck: block terminated indentation={} < indref={}", lc.indentation, indref);
                        if(raw_block.len == 0)
                        {
                            _c4dbgp("blck: was empty, undo next line");
                            _line_ended_undo();
                        }
                        break;
                    }
                    else if(lc.indentation == m_evt_handler->m_curr->indref)
                    {
                        if(has_any(RSEQ|RMAP))
                        {
                            _c4dbgpf("blck: block terminated. reading container and indentation={}==indref={}", lc.indentation, m_evt_handler->m_curr->indref);
                            break;
                        }
                    }
                    _c4dbgpf("blck: set indentation ref from this line: ref={}", lc.indentation);
                    indentation = lc.indentation;
                }
                else
                {
                    if(lc.indentation >= provisional_indentation)
                    {
                        _c4dbgpf("blck: set indentation ref from provisional indentation: provisional_ref={}, thisline={}", provisional_indentation, lc.indentation);
                        //indentation = provisional_indentation ? provisional_indentation : lc.indentation;
                        indentation = lc.indentation;
                    }
                    else
                    {
                        break;
                        //_c4err("parse error: first non-empty block line should have at least the original indentation");
                    }
                }
            }
            else // empty line
            {
                _c4dbgpf("blck: line empty or {} spaces. line_indentation={} prov_indentation={}", lc.stripped.len, lc.indentation, provisional_indentation);
                if(provisional_indentation != npos)
                {
                    if(lc.stripped.len >= provisional_indentation)
                    {
                        _c4dbgpf("blck: increase provisional_ref {} -> {}", provisional_indentation, lc.stripped.len);
                        provisional_indentation = lc.stripped.len;
                    }
                    #ifdef RYML_NO_COVERAGE__TO_BE_DELETED
                    else if(lc.indentation >= provisional_indentation && lc.indentation != npos)
                    {
                        _c4dbgpf("blck: increase provisional_ref {} -> {}", provisional_indentation, lc.indentation);
                        provisional_indentation = lc.indentation;
                    }
                    #endif
                }
                else
                {
                    provisional_indentation = lc.indentation ? lc.indentation : has_any(RSEQ|RVAL);
                    _c4dbgpf("blck: initialize provisional_ref={}", provisional_indentation);
                    if(provisional_indentation == npos)
                    {
                        provisional_indentation = lc.stripped.len ? lc.stripped.len : has_any(RSEQ|RVAL);
                        _c4dbgpf("blck: initialize provisional_ref={}", provisional_indentation);
                    }
                    if(provisional_indentation < indref)
                    {
                        provisional_indentation = indref;
                        _c4dbgpf("blck: initialize provisional_ref={}", provisional_indentation);
                    }
                }
            }
        }
        // advance now that we know the folded scalar continues
        m_evt_handler->m_curr->line_contents = lc;
        _c4dbgpf("blck: append '{}'", m_evt_handler->m_curr->line_contents.rem);
        raw_block.len += m_evt_handler->m_curr->line_contents.full.len;
        _line_progressed(m_evt_handler->m_curr->line_contents.rem.len);
        _line_ended();
        ++num_lines;
    }
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->pos.line == (first + num_lines) || (raw_block.len == 0));
    C4_UNUSED(num_lines);
    C4_UNUSED(first);

    if(indentation == npos)
    {
        _c4dbgpf("blck: set indentation from provisional: {}", provisional_indentation);
        indentation = provisional_indentation;
    }

    if(num_lines)
        _line_ended_undo();

    _c4prscalar("scanned block", raw_block, /*keep_newlines*/true);

    sb->scalar = raw_block;
    sb->indentation = indentation;
    sb->chomp = chomp;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

// a debugging scaffold:
#if 0
#define _c4dbgfws(fmt, ...) _c4dbgpf("filt_ws[{}->{}]: " fmt, proc.rpos, proc.wpos, __VA_ARGS__)
#else
#define _c4dbgfws(...)
#endif

template<class EventHandler>
template<class FilterProcessor>
bool ParseEngine<EventHandler>::_filter_ws_handle_to_first_non_space(FilterProcessor &proc)
{
    _c4dbgfws("found whitespace '{}'", _c4prc(proc.curr()));
    _RYML_CB_ASSERT(this->callbacks(), proc.curr() == ' ' || proc.curr() == '\t');

    const size_t first_pos = proc.rpos > 0 ? proc.src.first_not_of(" \t", proc.rpos) : proc.src.first_not_of(' ', proc.rpos);
    if(first_pos != npos)
    {
        const char first_char = proc.src[first_pos];
        _c4dbgfws("firstnonws='{}'@{}", _c4prc(first_char), first_pos);
        if(first_char == '\n' || first_char == '\r') // skip trailing whitespace
        {
            _c4dbgfws("whitespace is trailing on line", "");
            proc.skip(first_pos - proc.rpos);
        }
        else // a legit whitespace
        {
            proc.copy();
            _c4dbgfws("legit whitespace. sofar=[{}]~~~{}~~~", proc.wpos, proc.sofar());
        }
        return true;
    }
    _c4dbgfws("whitespace is trailing on line", "");
    return false;
}

template<class EventHandler>
template<class FilterProcessor>
void ParseEngine<EventHandler>::_filter_ws_copy_trailing(FilterProcessor &proc)
{
    if(!_filter_ws_handle_to_first_non_space(proc))
    {
        _c4dbgfws("... everything else is trailing whitespace - copy {} chars", proc.src.len - proc.rpos);
        proc.copy(proc.src.len - proc.rpos);
    }
}

template<class EventHandler>
template<class FilterProcessor>
void ParseEngine<EventHandler>::_filter_ws_skip_trailing(FilterProcessor &proc)
{
    if(!_filter_ws_handle_to_first_non_space(proc))
    {
        _c4dbgfws("... everything else is trailing whitespace - skip {} chars", proc.src.len - proc.rpos);
        proc.skip(proc.src.len - proc.rpos);
    }
}

#undef _c4dbgfws


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/* plain scalars */

// a debugging scaffold:
#if 0
#define _c4dbgfps(fmt, ...) _c4dbgpf("filt_plain[{}->{}]: " fmt, proc.rpos, proc.wpos, __VA_ARGS__)
#else
#define _c4dbgfps(fmt, ...)
#endif

template<class EventHandler>
template<class FilterProcessor>
void ParseEngine<EventHandler>::_filter_nl_plain(FilterProcessor &C4_RESTRICT proc, size_t indentation)
{
    _RYML_CB_ASSERT(this->callbacks(), proc.curr() == '\n');

    _c4dbgfps("found newline. sofar=[{}]~~~{}~~~", proc.wpos, proc.sofar());
    size_t ii = proc.rpos;
    const size_t numnl_following = _count_following_newlines(proc.src, &ii, indentation);
    if(numnl_following)
    {
        proc.set('\n', numnl_following);
        _c4dbgfps("{} consecutive (empty) lines {}. totalws={}", 1+numnl_following, ii < proc.src.len ? "in the middle" : "at the end", proc.rpos-ii);
    }
    else
    {
        const size_t ret = proc.src.first_not_of(" \t", proc.rpos+1);
        if(ret != npos)
        {
            proc.set(' ');
             _c4dbgfps("single newline. convert to space. ret={}/{}. sofar=[{}]~~~{}~~~", ii, proc.src.len, proc.wpos, proc.sofar());
        }
        else
        {
            _c4dbgfps("last newline, everything else is whitespace. ii={}/{}", ii, proc.src.len);
            ii = proc.src.len;
        }
    }
    proc.rpos = ii;
}

template<class EventHandler>
template<class FilterProcessor>
auto ParseEngine<EventHandler>::_filter_plain(FilterProcessor &C4_RESTRICT proc, size_t indentation) -> decltype(proc.result())
{
    _RYML_CB_ASSERT(this->callbacks(), indentation != npos);
    _c4dbgfps("before=[{}]~~~{}~~~", proc.src.len, proc.src);

    while(proc.has_more_chars())
    {
        const char curr = proc.curr();
        _c4dbgfps("'{}', sofar=[{}]~~~{}~~~", _c4prc(curr), proc.wpos, proc.sofar());
        switch(curr)
        {
        case ' ':
        _RYML_WITH_TAB_TOKENS(case '\t':)
            _c4dbgfps("whitespace", curr);
            _filter_ws_skip_trailing(proc);
            break;
        case '\n':
            _c4dbgfps("newline", curr);
            _filter_nl_plain(proc, /*indentation*/indentation);
            break;
        case '\r':  // skip \r --- https://stackoverflow.com/questions/1885900
            _c4dbgfps("carriage return, ignore", curr);
            proc.skip();
            break;
        default:
            proc.copy();
            break;
        }
    }

    _c4dbgfps("after[{}]=~~~{}~~~", proc.wpos, proc.sofar());

    return proc.result();
}

#undef _c4dbgfps


template<class EventHandler>
FilterResult ParseEngine<EventHandler>::filter_scalar_plain(csubstr scalar, substr dst, size_t indentation)
{
    FilterProcessorSrcDst proc(scalar, dst);
    return _filter_plain(proc, indentation);
}

template<class EventHandler>
FilterResult ParseEngine<EventHandler>::filter_scalar_plain_in_place(substr dst, size_t cap, size_t indentation)
{
    FilterProcessorInplaceEndExtending proc(dst, cap);
    return _filter_plain(proc, indentation);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/* single quoted */

// a debugging scaffold:
#if 0
#define _c4dbgfsq(fmt, ...) _c4dbgpf("filt_squo[{}->{}]: " fmt, proc.rpos, proc.wpos, __VA_ARGS__)
#else
#define _c4dbgfsq(fmt, ...)
#endif

template<class EventHandler>
template<class FilterProcessor>
void ParseEngine<EventHandler>::_filter_nl_squoted(FilterProcessor &C4_RESTRICT proc)
{
    _RYML_CB_ASSERT(this->callbacks(), proc.curr() == '\n');

    _c4dbgfsq("found newline. sofar=[{}]~~~{}~~~", proc.wpos, proc.sofar());
    size_t ii = proc.rpos;
    const size_t numnl_following = _count_following_newlines(proc.src, &ii);
    if(numnl_following)
    {
        proc.set('\n', numnl_following);
        _c4dbgfsq("{} consecutive (empty) lines {}. totalws={}", 1+numnl_following, ii < proc.src.len ? "in the middle" : "at the end", proc.rpos-ii);
    }
    else
    {
        const size_t ret = proc.src.first_not_of(" \t", proc.rpos+1);
        if(ret != npos)
        {
            proc.set(' ');
            _c4dbgfsq("single newline. convert to space. ret={}/{}. sofar=[{}]~~~{}~~~", ii, proc.src.len, proc.wpos, proc.sofar());
        }
        else
        {
            proc.set(' ');
            _c4dbgfsq("single newline. convert to space. ii={}/{}. sofar=[{}]~~~{}~~~", ii, proc.src.len, proc.wpos, proc.sofar());
        }
    }
    proc.rpos = ii;
}

template<class EventHandler>
template<class FilterProcessor>
auto ParseEngine<EventHandler>::_filter_squoted(FilterProcessor &C4_RESTRICT proc) -> decltype(proc.result())
{
    _c4dbgfsq("before=[{}]~~~{}~~~", proc.src.len, proc.src);

    // from the YAML spec for double-quoted scalars:
    // https://yaml.org/spec/1.2-old/spec.html#style/flow/single-quoted
    while(proc.has_more_chars())
    {
        const char curr = proc.curr();
        _c4dbgfsq("'{}', sofar=[{}]~~~{}~~~", _c4prc(curr), proc.wpos, proc.sofar());
        switch(curr)
        {
        case ' ':
        case '\t':
            _c4dbgfsq("whitespace", curr);
            _filter_ws_copy_trailing(proc);
            break;
        case '\n':
            _c4dbgfsq("newline", curr);
            _filter_nl_squoted(proc);
            break;
        case '\r':  // skip \r --- https://stackoverflow.com/questions/1885900
            _c4dbgfsq("skip cr", curr);
            proc.skip();
            break;
        case '\'':
            _c4dbgfsq("squote", curr);
            if(proc.next() == '\'')
            {
                _c4dbgfsq("two consecutive squotes", curr);
                proc.skip();
                proc.copy();
            }
            else
            {
                _c4err("filter error");
            }
            break;
        default:
            proc.copy();
            break;
        }
    }

    _c4dbgfsq(": #filteredchars={} after=~~~[{}]{}~~~", proc.src.len-proc.sofar().len, proc.sofar().len, proc.sofar());

    return proc.result();
}

#undef _c4dbgfsq

template<class EventHandler>
FilterResult ParseEngine<EventHandler>::filter_scalar_squoted(csubstr scalar, substr dst)
{
    FilterProcessorSrcDst proc(scalar, dst);
    return _filter_squoted(proc);
}

template<class EventHandler>
FilterResult ParseEngine<EventHandler>::filter_scalar_squoted_in_place(substr dst, size_t cap)
{
    FilterProcessorInplaceEndExtending proc(dst, cap);
    return _filter_squoted(proc);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
/* double quoted */

// a debugging scaffold:
#if 0
#define _c4dbgfdq(fmt, ...) _c4dbgpf("filt_dquo[{}->{}]: " fmt, proc.rpos, proc.wpos, __VA_ARGS__)
#else
#define _c4dbgfdq(...)
#endif

template<class EventHandler>
template<class FilterProcessor>
void ParseEngine<EventHandler>::_filter_nl_dquoted(FilterProcessor &C4_RESTRICT proc)
{
    _RYML_CB_ASSERT(this->callbacks(), proc.curr() == '\n');

    _c4dbgfdq("found newline. sofar=[{}]~~~{}~~~", proc.wpos, proc.sofar());
    size_t ii = proc.rpos;
    const size_t numnl_following = _count_following_newlines(proc.src, &ii);
    if(numnl_following)
    {
        proc.set('\n', numnl_following);
        _c4dbgfdq("{} consecutive (empty) lines {}. totalws={}", 1+numnl_following, ii < proc.src.len ? "in the middle" : "at the end", proc.rpos-ii);
    }
    else
    {
        const size_t ret = proc.src.first_not_of(" \t", proc.rpos+1);
        if(ret != npos)
        {
            proc.set(' ');
            _c4dbgfdq("single newline. convert to space. ret={}/{}. sofar=[{}]~~~{}~~~", ii, proc.src.len, proc.wpos, proc.sofar());
        }
        else
        {
            proc.set(' ');
            _c4dbgfdq("single newline. convert to space. ii={}/{}. sofar=[{}]~~~{}~~~", ii, proc.src.len, proc.wpos, proc.sofar());
        }
        if(ii < proc.src.len && proc.src.str[ii] == '\\')
        {
            _c4dbgfdq("backslash at [{}]", ii);
            const char next = ii+1 < proc.src.len ? proc.src.str[ii+1] : '\0';
            if(next == ' ' || next == '\t')
            {
                _c4dbgfdq("extend skip to backslash", "");
                ++ii;
            }
        }
    }
    proc.rpos = ii;
}

template<class EventHandler>
template<class FilterProcessor>
void ParseEngine<EventHandler>::_filter_dquoted_backslash(FilterProcessor &C4_RESTRICT proc)
{
    char next = proc.next();
    _c4dbgfdq("backslash, next='{}'", _c4prc(next));
    if(next == '\r')
    {
        if(proc.rpos+2 < proc.src.len && proc.src.str[proc.rpos+2] == '\n')
        {
            proc.skip(); // newline escaped with \ -- skip both (add only one as i is loop-incremented)
            next = '\n';
            _c4dbgfdq("[{}]: was \\r\\n, now next='\\n'", proc.rpos);
        }
    }

    if(next == '\n')
    {
        size_t ii = proc.rpos + 2;
        for( ; ii < proc.src.len; ++ii)
        {
            // skip leading whitespace
            if(proc.src.str[ii] == ' ' || proc.src.str[ii] == '\t')
                ;
            else
                break;
        }
        proc.skip(ii - proc.rpos);
    }
    else if(next == '"' || next == '/' || next == ' ' || next == '\t')
    {
        // escapes for json compatibility
        proc.translate_esc(next);
        _c4dbgfdq("here, used '{}'", _c4prc(next));
    }
    else if(next == '\r')
    {
        proc.skip();
    }
    else if(next == 'n')
    {
        proc.translate_esc('\n');
    }
    else if(next == 'r')
    {
        proc.translate_esc('\r');
    }
    else if(next == 't')
    {
        proc.translate_esc('\t');
    }
    else if(next == '\\')
    {
        proc.translate_esc('\\');
    }
    else if(next == 'x') // UTF8
    {
        if(C4_UNLIKELY(proc.rpos + 1u + 2u >= proc.src.len))
            _c4err("\\x requires 2 hex digits. scalar pos={}", proc.rpos);
        csubstr codepoint = proc.src.sub(proc.rpos + 2u, 2u);
        _c4dbgfdq("utf8 ~~~{}~~~ rpos={} rem=~~~{}~~~", codepoint, proc.rpos, proc.src.sub(proc.rpos));
        uint8_t byteval = {};
        if(C4_UNLIKELY(!read_hex(codepoint, &byteval)))
            _c4err("failed to read \\x codepoint. scalar pos={}", proc.rpos);
        proc.translate_esc_bulk((const char*)&byteval, 1u, /*nread*/3u);
        _c4dbgfdq("utf8 after rpos={} rem=~~~{}~~~", proc.rpos, proc.src.sub(proc.rpos));
    }
    else if(next == 'u') // UTF16
    {
        if(C4_UNLIKELY(proc.rpos + 1u + 4u >= proc.src.len))
            _c4err("\\u requires 4 hex digits. scalar pos={}", proc.rpos);
        char readbuf[8];
        csubstr codepoint = proc.src.sub(proc.rpos + 2u, 4u);
        uint32_t codepoint_val = {};
        if(C4_UNLIKELY(!read_hex(codepoint, &codepoint_val)))
            _c4err("failed to parse \\u codepoint. scalar pos={}", proc.rpos);
        const size_t numbytes = decode_code_point((uint8_t*)readbuf, sizeof(readbuf), codepoint_val);
        if(C4_UNLIKELY(numbytes == 0))
            _c4err("failed to decode code point={}", proc.rpos);
        _RYML_CB_ASSERT(callbacks(), numbytes <= 4);
        proc.translate_esc_bulk(readbuf, numbytes, /*nread*/5u);
    }
    else if(next == 'U') // UTF32
    {
        if(C4_UNLIKELY(proc.rpos + 1u + 8u >= proc.src.len))
            _c4err("\\U requires 8 hex digits. scalar pos={}", proc.rpos);
        char readbuf[8];
        csubstr codepoint = proc.src.sub(proc.rpos + 2u, 8u);
        uint32_t codepoint_val = {};
        if(C4_UNLIKELY(!read_hex(codepoint, &codepoint_val)))
            _c4err("failed to parse \\U codepoint. scalar pos={}", proc.rpos);
        const size_t numbytes = decode_code_point((uint8_t*)readbuf, sizeof(readbuf), codepoint_val);
        if(C4_UNLIKELY(numbytes == 0))
            _c4err("failed to decode code point={}", proc.rpos);
        _RYML_CB_ASSERT(callbacks(), numbytes <= 4);
        proc.translate_esc_bulk(readbuf, numbytes, /*nread*/9u);
    }
    // https://yaml.org/spec/1.2.2/#rule-c-ns-esc-char
    else if(next == '0')
    {
        proc.translate_esc('\0');
    }
    else if(next == 'b') // backspace
    {
        proc.translate_esc('\b');
    }
    else if(next == 'f') // form feed
    {
        proc.translate_esc('\f');
    }
    else if(next == 'a') // bell character
    {
        proc.translate_esc('\a');
    }
    else if(next == 'v') // vertical tab
    {
        proc.translate_esc('\v');
    }
    else if(next == 'e') // escape character
    {
        proc.translate_esc('\x1b');
    }
    else if(next == '_') // unicode non breaking space \u00a0
    {
        // https://www.compart.com/en/unicode/U+00a0
        const char payload[] = {
            _RYML_CHCONST(-0x3e, 0xc2),
            _RYML_CHCONST(-0x60, 0xa0),
        };
        proc.translate_esc_bulk(payload, /*nwrite*/2, /*nread*/1);
    }
    else if(next == 'N') // unicode next line \u0085
    {
        // https://www.compart.com/en/unicode/U+0085
        const char payload[] = {
            _RYML_CHCONST(-0x3e, 0xc2),
            _RYML_CHCONST(-0x7b, 0x85),
        };
        proc.translate_esc_bulk(payload, /*nwrite*/2, /*nread*/1);
    }
    else if(next == 'L') // unicode line separator \u2028
    {
        // https://www.utf8-chartable.de/unicode-utf8-table.pl?start=8192&number=1024&names=-&utf8=0x&unicodeinhtml=hex
        const char payload[] = {
            _RYML_CHCONST(-0x1e, 0xe2),
            _RYML_CHCONST(-0x80, 0x80),
            _RYML_CHCONST(-0x58, 0xa8),
        };
        proc.translate_esc_extending(payload, /*nwrite*/3, /*nread*/1);
    }
    else if(next == 'P') // unicode paragraph separator \u2029
    {
        // https://www.utf8-chartable.de/unicode-utf8-table.pl?start=8192&number=1024&names=-&utf8=0x&unicodeinhtml=hex
        const char payload[] = {
            _RYML_CHCONST(-0x1e, 0xe2),
            _RYML_CHCONST(-0x80, 0x80),
            _RYML_CHCONST(-0x57, 0xa9),
        };
        proc.translate_esc_extending(payload, /*nwrite*/3, /*nread*/1);
    }
    else if(next == '\0')
    {
        proc.skip();
    }
    else
    {
        _c4err("unknown character '{}' after '\\' pos={}", _c4prc(next), proc.rpos);
    }
    _c4dbgfdq("backslash...sofar=[{}]~~~{}~~~", proc.wpos, proc.sofar());
}


template<class EventHandler>
template<class FilterProcessor>
auto ParseEngine<EventHandler>::_filter_dquoted(FilterProcessor &C4_RESTRICT proc) -> decltype(proc.result())
{
    _c4dbgfdq("before=[{}]~~~{}~~~", proc.src.len, proc.src);
    // from the YAML spec for double-quoted scalars:
    // https://yaml.org/spec/1.2-old/spec.html#style/flow/double-quoted
    while(proc.has_more_chars())
    {
        const char curr = proc.curr();
        _c4dbgfdq("'{}' sofar=[{}]~~~{}~~~", _c4prc(curr), proc.wpos, proc.sofar());
        switch(curr)
        {
        case ' ':
        case '\t':
        {
            _c4dbgfdq("whitespace", curr);
            _filter_ws_copy_trailing(proc);
            break;
        }
        case '\n':
        {
            _c4dbgfdq("newline", curr);
            _filter_nl_dquoted(proc);
            break;
        }
        case '\r':  // skip \r --- https://stackoverflow.com/questions/1885900
        {
            _c4dbgfdq("carriage return, ignore", curr);
            proc.skip();
            break;
        }
        case '\\':
        {
            _filter_dquoted_backslash(proc);
            break;
        }
        default:
        {
            proc.copy();
            break;
        }
        }
    }
    _c4dbgfdq("after[{}]=~~~{}~~~", proc.wpos, proc.sofar());
    return proc.result();
}

#undef _c4dbgfdq


template<class EventHandler>
FilterResult ParseEngine<EventHandler>::filter_scalar_dquoted(csubstr scalar, substr dst)
{
    FilterProcessorSrcDst proc(scalar, dst);
    return _filter_dquoted(proc);
}

template<class EventHandler>
FilterResultExtending ParseEngine<EventHandler>::filter_scalar_dquoted_in_place(substr dst, size_t cap)
{
    FilterProcessorInplaceMidExtending proc(dst, cap);
    return _filter_dquoted(proc);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// block filtering helpers

template<class EventHandler>
template<class FilterProcessor>
void ParseEngine<EventHandler>::_filter_chomp(FilterProcessor &C4_RESTRICT proc, BlockChomp_e chomp, size_t indentation)
{
    _RYML_CB_ASSERT(this->callbacks(), chomp == CHOMP_CLIP || chomp == CHOMP_KEEP || chomp == CHOMP_STRIP);
    _RYML_CB_ASSERT(this->callbacks(), proc.rem().first_not_of(" \n\r") == npos);

    // a debugging scaffold:
    #if 0
    #define _c4dbgchomp(fmt, ...) _c4dbgpf("chomp[{}->{}]: " fmt, proc.rpos, proc.wpos, __VA_ARGS__)
    #else
    #define _c4dbgchomp(...)
    #endif

    // advance to the last line having spaces beyond the indentation
    {
        size_t last = _find_last_newline_and_larger_indentation(proc.rem(), indentation);
        if(last != npos)
        {
            _c4dbgchomp("found newline and larger indentation. last={}", last);
            last = proc.rpos + last + size_t(1) + indentation;  // last started at to-be-read.
            _RYML_CB_ASSERT(this->callbacks(), last <= proc.src.len);
            // remove indentation spaces, copy the rest
            while((proc.rpos < last) && proc.has_more_chars())
            {
                const char curr = proc.curr();
                _c4dbgchomp("curr='{}'", _c4prc(curr));
                switch(curr)
                {
                case '\n':
                    {
                        _c4dbgchomp("newline! remlen={}", proc.rem().len);
                        proc.copy();
                        // are there spaces after the newline?
                        csubstr at_next_line = proc.rem();
                        if(at_next_line.begins_with(' '))
                        {
                            _c4dbgchomp("next line begins with spaces. indentation={}", indentation);
                            // there are spaces.
                            size_t first_non_space = at_next_line.first_not_of(' ');
                            _c4dbgchomp("first_non_space={}", first_non_space);
                            if(first_non_space == npos)
                            {
                                _c4dbgchomp("{} spaces, to the end", at_next_line.len);
                                first_non_space = at_next_line.len;
                            }
                            if(first_non_space <= indentation)
                            {
                                _c4dbgchomp("skip spaces={}<=indentation={}", first_non_space, indentation);
                                proc.skip(first_non_space);
                            }
                            else
                            {
                                _c4dbgchomp("skip indentation={}<spaces={}", indentation, first_non_space);
                                proc.skip(indentation);
                                // copy the spaces after the indentation
                                _c4dbgchomp("copy {}={}-{} spaces", first_non_space - indentation, first_non_space, indentation);
                                proc.copy(first_non_space - indentation);
                            }
                        }
                        break;
                    }
                case '\r':
                    proc.skip();
                    break;
                default:
                    _c4err("parse error");
                    break;
                }
            }
        }
    }

    // from now on, we only have line ends (or indentation spaces)
    switch(chomp)
    {
    case CHOMP_CLIP:
    {
        bool had_one = false;
        while(proc.has_more_chars())
        {
            const char curr = proc.curr();
            _c4dbgchomp("CLIP: '{}'", _c4prc(curr));
            switch(curr)
            {
            case '\n':
            {
                _c4dbgchomp("copy newline!", curr);
                proc.copy();
                proc.set_at_end();
                had_one = true;
                break;
            }
            case ' ':
            case '\r':
                _c4dbgchomp("skip!", curr);
                proc.skip();
                break;
            }
        }
        if(!had_one) // there were no newline characters. add one.
        {
            _c4dbgchomp("chomp=CLIP: add missing newline @{}", proc.wpos);
            proc.set('\n');
        }
        break;
    }
    case CHOMP_KEEP:
    {
        _c4dbgchomp("chomp=KEEP: copy all remaining new lines of {} characters", proc.rem().len);
        while(proc.has_more_chars())
        {
            const char curr = proc.curr();
            _c4dbgchomp("KEEP: '{}'", _c4prc(curr));
            switch(curr)
            {
            case '\n':
                _c4dbgchomp("copy newline!", curr);
                proc.copy();
                break;
            case ' ':
            case '\r':
                _c4dbgchomp("skip!", curr);
                proc.skip();
                break;
            }
        }
        break;
    }
    case CHOMP_STRIP:
    {
        _c4dbgchomp("chomp=STRIP: strip {} characters", proc.rem().len);
        // nothing to do!
        break;
    }
    }

    #undef _c4dbgchomp
}


// a debugging scaffold:
#if 0
#define _c4dbgfb(fmt, ...) _c4dbgpf("filt_block[{}->{}]: " fmt, proc.rpos, proc.wpos, __VA_ARGS__)
#else
#define _c4dbgfb(...)
#endif

template<class EventHandler>
template<class FilterProcessor>
void ParseEngine<EventHandler>::_filter_block_indentation(FilterProcessor &C4_RESTRICT proc, size_t indentation)
{
    csubstr rem = proc.rem(); // remaining
    if(rem.len)
    {
        size_t first = rem.first_not_of(' ');
        if(first != npos)
        {
            _c4dbgfb("{} spaces follow before next nonws character", first);
            if(first < indentation)
            {
                _c4dbgfb("skip {}<{} spaces from indentation", first, indentation);
                proc.skip(first);
            }
            else
            {
                _c4dbgfb("skip {} spaces from indentation", indentation);
                proc.skip(indentation);
            }
        }
        #ifdef RYML_NO_COVERAGE__TO_BE_DELETED
        else
        {
            _c4dbgfb("all spaces to the end: {} spaces", first);
            first = rem.len;
            if(first)
            {
                if(first < indentation)
                {
                    _c4dbgfb("skip everything", first);
                    proc.skip(proc.src.len - proc.rpos);
                }
                else
                {
                    _c4dbgfb("skip {} spaces from indentation", indentation);
                    proc.skip(indentation);
                }
            }
        }
        #endif
    }
}

template<class EventHandler>
template<class FilterProcessor>
size_t ParseEngine<EventHandler>::_handle_all_whitespace(FilterProcessor &C4_RESTRICT proc, BlockChomp_e chomp)
{
    csubstr contents = proc.src.trimr(" \n\r");
    _c4dbgfb("ws: contents_len={} wslen={}", contents.len, proc.src.len-contents.len);
    if(!contents.len)
    {
        _c4dbgfb("ws: all whitespace: len={}", proc.src.len);
        if(chomp == CHOMP_KEEP && proc.src.len)
        {
            _c4dbgfb("ws: chomp=KEEP all {} newlines", proc.src.count('\n'));
            while(proc.has_more_chars())
            {
                const char curr = proc.curr();
                if(curr == '\n')
                    proc.copy();
                else
                    proc.skip();
            }
            if(!proc.wpos)
            {
                proc.set('\n');
            }
        }
    }
    return contents.len;
}

template<class EventHandler>
template<class FilterProcessor>
size_t ParseEngine<EventHandler>::_extend_to_chomp(FilterProcessor &C4_RESTRICT proc, size_t contents_len)
{
    _c4dbgfb("contents_len={}", contents_len);

    _RYML_CB_ASSERT(this->callbacks(), contents_len > 0u);

    // extend contents to just before the first newline at the end,
    // in case it is preceded by spaces
    size_t firstnewl = proc.src.first_of('\n', contents_len);
    if(firstnewl != npos)
    {
        contents_len = firstnewl;
        _c4dbgfb("contents_len={}  <--- firstnewl={}", contents_len, firstnewl);
    }
    else
    {
        contents_len = proc.src.len;
        _c4dbgfb("contents_len={}  <--- src.len={}", contents_len, proc.src.len);
    }

    return contents_len;
}

#undef _c4dbgfb


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

// a debugging scaffold:
#if 0
#define _c4dbgfbl(fmt, ...) _c4dbgpf("filt_block_lit[{}->{}]: " fmt, proc.rpos, proc.wpos, __VA_ARGS__)
#else
#define _c4dbgfbl(...)
#endif

template<class EventHandler>
template<class FilterProcessor>
auto ParseEngine<EventHandler>::_filter_block_literal(FilterProcessor &C4_RESTRICT proc, size_t indentation, BlockChomp_e chomp) -> decltype(proc.result())
{
    _c4dbgfbl("indentation={} before=[{}]~~~{}~~~", indentation, proc.src.len, proc.src);

    size_t contents_len = _handle_all_whitespace(proc, chomp);
    if(!contents_len)
        return proc.result();

    contents_len = _extend_to_chomp(proc, contents_len);

    _c4dbgfbl("to filter=[{}]~~~{}~~~", contents_len, proc.src.first(contents_len));

    _filter_block_indentation(proc, indentation);

    // now filter the bulk
    while(proc.has_more_chars(/*maxpos*/contents_len))
    {
        const char curr = proc.curr();
        _c4dbgfbl("'{}' sofar=[{}]~~~{}~~~",  _c4prc(curr), proc.wpos, proc.sofar());
        switch(curr)
        {
        case '\n':
        {
            _c4dbgfbl("found newline. skip indentation on the next line", curr);
            proc.copy();  // copy the newline
            _filter_block_indentation(proc, indentation);
            break;
        }
        case '\r':
            proc.skip();
            break;
        default:
            proc.copy();
            break;
        }
    }

    _c4dbgfbl("before chomp: #tochomp={}   sofar=[{}]~~~{}~~~", proc.rem().len, proc.sofar().len, proc.sofar());

    _filter_chomp(proc, chomp, indentation);

    _c4dbgfbl("final=[{}]~~~{}~~~", proc.sofar().len, proc.sofar());

    return proc.result();
}

#undef _c4dbgfbl

template<class EventHandler>
FilterResult ParseEngine<EventHandler>::filter_scalar_block_literal(csubstr scalar, substr dst, size_t indentation, BlockChomp_e chomp)
{
    FilterProcessorSrcDst proc(scalar, dst);
    return _filter_block_literal(proc, indentation, chomp);
}

template<class EventHandler>
FilterResult ParseEngine<EventHandler>::filter_scalar_block_literal_in_place(substr scalar, size_t cap, size_t indentation, BlockChomp_e chomp)
{
    FilterProcessorInplaceEndExtending proc(scalar, cap);
    return _filter_block_literal(proc, indentation, chomp);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

// a debugging scaffold:
#if 0
#define _c4dbgfbf(fmt, ...) _c4dbgpf("filt_block_folded[{}->{}]: " fmt, proc.rpos, proc.wpos, __VA_ARGS__)
#else
#define _c4dbgfbf(...)
#endif


template<class EventHandler>
template<class FilterProcessor>
void ParseEngine<EventHandler>::_filter_block_folded_newlines_leading(FilterProcessor &C4_RESTRICT proc, size_t indentation, size_t len)
{
    _filter_block_indentation(proc, indentation);
    while(proc.has_more_chars(len))
    {
        const char curr = proc.curr();
        _c4dbgfbf("'{}' sofar=[{}]~~~{}~~~",  _c4prc(curr), proc.wpos, proc.sofar());
        switch(curr)
        {
        case '\n':
            _c4dbgfbf("newline.", curr);
            proc.copy();
            _filter_block_indentation(proc, indentation);
            break;
        case '\r':
            proc.skip();
            break;
        case ' ':
        case '\t':
        {
            size_t first = proc.rem().first_not_of(" \t");
            _c4dbgfbf("space. first={}", first);
            if(first == npos)
                first = proc.rem().len;
            _c4dbgfbf("... indentation increased to {}",  first);
            _filter_block_folded_indented_block(proc, indentation, len, first);
            break;
        }
        default:
            _c4dbgfbf("newl leading: not space, not newline. stop.", 0);
            return;
        }
    }
}

template<class EventHandler>
template<class FilterProcessor>
size_t ParseEngine<EventHandler>::_filter_block_folded_newlines_compress(FilterProcessor &C4_RESTRICT proc, size_t num_newl, size_t wpos_at_first_newl)
{
    switch(num_newl)
    {
    case 1u:
        _c4dbgfbf("... this is the first newline. turn into space. wpos={}", proc.wpos);
        wpos_at_first_newl = proc.wpos;
        proc.skip();
        proc.set(' ');
        break;
    case 2u:
        _c4dbgfbf("... this is the second newline. prev space (at wpos={}) must be newline", wpos_at_first_newl);
        _RYML_CB_ASSERT(this->callbacks(), wpos_at_first_newl != npos);
        _RYML_CB_ASSERT(this->callbacks(), proc.sofar()[wpos_at_first_newl] == ' ');
        _RYML_CB_ASSERT(this->callbacks(), wpos_at_first_newl + 1u == proc.wpos);
        proc.skip();
        proc.set_at(wpos_at_first_newl, '\n');
        _RYML_CB_ASSERT(this->callbacks(), proc.sofar()[wpos_at_first_newl] == '\n');
        break;
    default:
        _c4dbgfbf("... subsequent newline (num_newl={}). copy", num_newl);
        proc.copy();
        break;
    }
    return wpos_at_first_newl;
}

template<class EventHandler>
template<class FilterProcessor>
void ParseEngine<EventHandler>::_filter_block_folded_newlines(FilterProcessor &C4_RESTRICT proc, size_t indentation, size_t len)
{
    _RYML_CB_ASSERT(this->callbacks(), proc.curr() == '\n');
    size_t num_newl = 0;
    size_t wpos_at_first_newl = npos;
    while(proc.has_more_chars(len))
    {
        const char curr = proc.curr();
        _c4dbgfbf("'{}' sofar=[{}]~~~{}~~~",  _c4prc(curr), proc.wpos, proc.sofar());
        switch(curr)
        {
        case '\n':
        {
            _c4dbgfbf("newline. sofar={}", num_newl);
            // NOTE: vs2022-32bit-release builds were giving wrong
            // results in this block, if it was written as either
            // as a  switch(num_newl) or its equivalent if-form.
            //
            // For this reason, we're using a dedicated function
            // (**_compress), which seems to work around the issue.
            //
            // The manifested problem was that somewhere between the
            // assignment to curr and this point, proc.wpos (the
            // write-position of the processor) jumped to npos, which
            // made the write wrap-around! To make things worse,
            // enabling prints via _c4dbgpf() and _c4dbgfbf() made the
            // problem go away!
            //
            // The only way to make the problem appear with prints
            // enabled was by disabling all prints in this function
            // (including in the block which was moved to the compress
            // function) and then selectively enabling only some of
            // those prints.
            //
            // This may be due to some bug in the cl-x86 optimizer; or
            // it may be triggered by some UB which may be
            // inadvertedly present in this function or in the filter
            // processor. This is despite our best efforts to weed out
            // any such UB problem: neither clang-tidy nor none of the
            // sanitizers, or gcc's -fanalyzer pointed to any problems
            // in this code.
            //
            // In the end, moving this block to a separate function
            // was the only way to bury the problem. But it may
            // resurface again, as The Undead, rising to from the
            // grave to haunt us with his terrible presence.
            //
            // We may have to revisit this. With a stake, and lots of
            // garlic.
            wpos_at_first_newl = _filter_block_folded_newlines_compress(proc, ++num_newl, wpos_at_first_newl);
            _filter_block_indentation(proc, indentation);
            break;
        }
        case ' ':
        case '\t':
            {
                size_t first = proc.rem().first_not_of(" \t");
                _c4dbgfbf("space. first={}", first);
                if(first == npos)
                    first = proc.rem().len;
                _c4dbgfbf("... indentation increased to {}",  first);
                if(num_newl)
                {
                    _c4dbgfbf("... prev space (at wpos={}) must be newline", wpos_at_first_newl);
                    proc.set_at(wpos_at_first_newl, '\n');
                }
                if(num_newl > 1u)
                {
                    _c4dbgfbf("... add missing newline", wpos_at_first_newl);
                    proc.set('\n');
                }
                _filter_block_folded_indented_block(proc, indentation, len, first);
                num_newl = 0;
                wpos_at_first_newl = npos;
                break;
            }
        case '\r':
            proc.skip();
            break;
        default:
            _c4dbgfbf("not space, not newline. stop.", 0);
            return;
        }
    }
}


template<class EventHandler>
template<class FilterProcessor>
void ParseEngine<EventHandler>::_filter_block_folded_indented_block(FilterProcessor &C4_RESTRICT proc, size_t indentation, size_t len, size_t curr_indentation) noexcept
{
    _RYML_CB_ASSERT(this->callbacks(), (proc.rem().first_not_of(" \t") == curr_indentation) || (proc.rem().first_not_of(" \t") == npos));
    if(curr_indentation)
        proc.copy(curr_indentation);
    while(proc.has_more_chars(len))
    {
        const char curr = proc.curr();
        _c4dbgfbf("'{}' sofar=[{}]~~~{}~~~",  _c4prc(curr), proc.wpos, proc.sofar());
        switch(curr)
        {
        case '\n':
            {
                proc.copy();
                _filter_block_indentation(proc, indentation);
                csubstr rem = proc.rem();
                const size_t first = rem.first_not_of(' ');
                _c4dbgfbf("newline. firstns={}",  first);
                if(first == 0)
                {
                    const char c = rem[first];
                    _c4dbgfbf("firstns={}='{}'", first, _c4prc(c));
                    if(c == '\n' || c == '\r')
                    {
                        ;
                    }
                    else
                    {
                        _c4dbgfbf("done with indented block",  first);
                        goto endloop;
                    }
                }
                else if(first != npos)
                {
                    proc.copy(first);
                    _c4dbgfbf("copy all {} spaces",  first);
                }
                break;
            }
            break;
        case '\r':
            proc.skip();
            break;
        default:
            proc.copy();
            break;
        }
    }
 endloop:
    return;
}


template<class EventHandler>
template<class FilterProcessor>
auto ParseEngine<EventHandler>::_filter_block_folded(FilterProcessor &C4_RESTRICT proc, size_t indentation, BlockChomp_e chomp) -> decltype(proc.result())
{
    _c4dbgfbf("indentation={} before=[{}]~~~{}~~~", indentation, proc.src.len, proc.src);

    size_t contents_len = _handle_all_whitespace(proc, chomp);
    if(!contents_len)
        return proc.result();

    contents_len = _extend_to_chomp(proc, contents_len);

    _c4dbgfbf("to filter=[{}]~~~{}~~~", contents_len, proc.src.first(contents_len));

    _filter_block_folded_newlines_leading(proc, indentation, contents_len);

    // now filter the bulk
    while(proc.has_more_chars(/*maxpos*/contents_len))
    {
        const char curr = proc.curr();
        _c4dbgfbf("'{}' sofar=[{}]~~~{}~~~",  _c4prc(curr), proc.wpos, proc.sofar());
        switch(curr)
        {
        case '\n':
        {
            _c4dbgfbf("found newline", curr);
            _filter_block_folded_newlines(proc, indentation, contents_len);
            break;
        }
        case '\r':
            proc.skip();
            break;
        default:
            proc.copy();
            break;
        }
    }

    _c4dbgfbf("before chomp: #tochomp={}   sofar=[{}]~~~{}~~~", proc.rem().len, proc.sofar().len, proc.sofar());

    _filter_chomp(proc, chomp, indentation);

    _c4dbgfbf("final=[{}]~~~{}~~~", proc.sofar().len, proc.sofar());

    return proc.result();
}

#undef _c4dbgfbf

template<class EventHandler>
FilterResult ParseEngine<EventHandler>::filter_scalar_block_folded(csubstr scalar, substr dst, size_t indentation, BlockChomp_e chomp)
{
    FilterProcessorSrcDst proc(scalar, dst);
    return _filter_block_folded(proc, indentation, chomp);
}

template<class EventHandler>
FilterResult ParseEngine<EventHandler>::filter_scalar_block_folded_in_place(substr scalar, size_t cap, size_t indentation, BlockChomp_e chomp)
{
    FilterProcessorInplaceEndExtending proc(scalar, cap);
    return _filter_block_folded(proc, indentation, chomp);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_filter_scalar_plain(substr s, size_t indentation)
{
    _c4dbgpf("filtering plain scalar: s=[{}]~~~{}~~~", s.len, s);
    FilterResult r = this->filter_scalar_plain_in_place(s, s.len, indentation);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, r.valid());
    _c4dbgpf("filtering plain scalar: success! s=[{}]~~~{}~~~", r.get().len, r.get());
    return r.get();
}

//-----------------------------------------------------------------------------

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_filter_scalar_squot(substr s)
{
    _c4dbgpf("filtering squo scalar: s=[{}]~~~{}~~~", s.len, s);
    FilterResult r = this->filter_scalar_squoted_in_place(s, s.len);
    _RYML_CB_ASSERT(this->callbacks(), r.valid());
    _c4dbgpf("filtering squo scalar: success! s=[{}]~~~{}~~~", r.get().len, r.get());
    return r.get();
}


//-----------------------------------------------------------------------------

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_filter_scalar_dquot(substr s)
{
    _c4dbgpf("filtering dquo scalar: s=[{}]~~~{}~~~", s.len, s);
    FilterResultExtending r = this->filter_scalar_dquoted_in_place(s, s.len);
    if(C4_LIKELY(r.valid()))
    {
        _c4dbgpf("filtering dquo scalar: success! s=[{}]~~~{}~~~", r.get().len, r.get());
        return r.get();
    }
    else
    {
        const size_t len = r.required_len();
        _c4dbgpf("filtering dquo scalar: not enough space: needs {}, have {}", len, s.len);
        substr dst = m_evt_handler->alloc_arena(len, &s);
        _c4dbgpf("filtering dquo scalar: dst.len={}", dst.len);
        _RYML_CB_ASSERT(this->callbacks(), dst.len == len);
        FilterResult rsd = this->filter_scalar_dquoted(s, dst);
        _c4dbgpf("filtering dquo scalar: ... result now needs {} was {}", rsd.required_len(), len);
        _RYML_CB_ASSERT(this->callbacks(), rsd.required_len() <= len); // may be smaller!
        _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, rsd.valid());
        _c4dbgpf("filtering dquo scalar: success! s=[{}]~~~{}~~~", rsd.get().len, rsd.get());
        return rsd.get();
    }
}


//-----------------------------------------------------------------------------
template<class EventHandler>
csubstr ParseEngine<EventHandler>::_filter_scalar_literal(substr s, size_t indentation, BlockChomp_e chomp)
{
    _c4dbgpf("filtering block literal scalar: s=[{}]~~~{}~~~", s.len, s);
    FilterResult r = this->filter_scalar_block_literal_in_place(s, s.len, indentation, chomp);
    if(C4_LIKELY(r.valid()))
    {
        _c4dbgpf("filtering block literal scalar: success! s=[{}]~~~{}~~~", r.get().len, r.get());
        return r.get();
    }
    else
    {
        _c4dbgpf("filtering block literal scalar: not enough space: needs {}, have {}", r.required_len(), s.len);
        substr dst = m_evt_handler->alloc_arena(r.required_len(), &s);
        FilterResult rsd = this->filter_scalar_block_literal(s, dst, indentation, chomp);
        _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, rsd.valid());
        _c4dbgpf("filtering block literal scalar: success! s=[{}]~~~{}~~~", rsd.get().len, rsd.get());
        return rsd.get();
    }
}


//-----------------------------------------------------------------------------
template<class EventHandler>
csubstr ParseEngine<EventHandler>::_filter_scalar_folded(substr s, size_t indentation, BlockChomp_e chomp)
{
    _c4dbgpf("filtering block folded scalar: s=[{}]~~~{}~~~", s.len, s);
    FilterResult r = this->filter_scalar_block_folded_in_place(s, s.len, indentation, chomp);
    if(C4_LIKELY(r.valid()))
    {
        _c4dbgpf("filtering block folded scalar: success! s=[{}]~~~{}~~~", r.get().len, r.get());
        return r.get();
    }
    else
    {
        _c4dbgpf("filtering block folded scalar: not enough space: needs {}, have {}", r.required_len(), s.len);
        substr dst = m_evt_handler->alloc_arena(r.required_len(), &s);
        FilterResult rsd = this->filter_scalar_block_folded(s, dst, indentation, chomp);
        _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, rsd.valid());
        _c4dbgpf("filtering block folded scalar: success! s=[{}]~~~{}~~~", rsd.get().len, rsd.get());
        return rsd.get();
    }
}


//-----------------------------------------------------------------------------

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_maybe_filter_key_scalar_plain(ScannedScalar const& C4_RESTRICT sc, size_t indentation)
{
    if(sc.needs_filter)
    {
        if(m_options.scalar_filtering())
        {
            return _filter_scalar_plain(sc.scalar, indentation);
        }
        else
        {
            _c4dbgp("plain scalar left unfiltered");
            m_evt_handler->mark_key_scalar_unfiltered();
        }
    }
    else
    {
        _c4dbgp("plain scalar doesn't need filtering");
    }
    return sc.scalar;
}

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_maybe_filter_val_scalar_plain(ScannedScalar const& C4_RESTRICT sc, size_t indentation)
{
    if(sc.needs_filter)
    {
        if(m_options.scalar_filtering())
        {
            return _filter_scalar_plain(sc.scalar, indentation);
        }
        else
        {
            _c4dbgp("plain scalar left unfiltered");
            m_evt_handler->mark_val_scalar_unfiltered();
        }
    }
    else
    {
        _c4dbgp("plain scalar doesn't need filtering");
    }
    return sc.scalar;
}


//-----------------------------------------------------------------------------

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_maybe_filter_key_scalar_squot(ScannedScalar const& C4_RESTRICT sc)
{
    if(sc.needs_filter)
    {
        if(m_options.scalar_filtering())
        {
            return _filter_scalar_squot(sc.scalar);
        }
        else
        {
            _c4dbgp("squo key scalar left unfiltered");
            m_evt_handler->mark_key_scalar_unfiltered();
        }
    }
    else
    {
        _c4dbgp("squo key scalar doesn't need filtering");
    }
    return sc.scalar;
}

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_maybe_filter_val_scalar_squot(ScannedScalar const& C4_RESTRICT sc)
{
    if(sc.needs_filter)
    {
        if(m_options.scalar_filtering())
        {
            return _filter_scalar_squot(sc.scalar);
        }
        else
        {
            _c4dbgp("squo val scalar left unfiltered");
            m_evt_handler->mark_val_scalar_unfiltered();
        }
    }
    else
    {
        _c4dbgp("squo val scalar doesn't need filtering");
    }
    return sc.scalar;
}


//-----------------------------------------------------------------------------

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_maybe_filter_key_scalar_dquot(ScannedScalar const& C4_RESTRICT sc)
{
    if(sc.needs_filter)
    {
        if(m_options.scalar_filtering())
        {
            return _filter_scalar_dquot(sc.scalar);
        }
        else
        {
            _c4dbgp("dquo scalar left unfiltered");
            m_evt_handler->mark_key_scalar_unfiltered();
        }
    }
    else
    {
        _c4dbgp("dquo scalar doesn't need filtering");
    }
    return sc.scalar;
}

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_maybe_filter_val_scalar_dquot(ScannedScalar const& C4_RESTRICT sc)
{
    if(sc.needs_filter)
    {
        if(m_options.scalar_filtering())
        {
            return _filter_scalar_dquot(sc.scalar);
        }
        else
        {
            _c4dbgp("dquo scalar left unfiltered");
            m_evt_handler->mark_val_scalar_unfiltered();
        }
    }
    else
    {
        _c4dbgp("dquo scalar doesn't need filtering");
    }
    return sc.scalar;
}


//-----------------------------------------------------------------------------

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_maybe_filter_key_scalar_literal(ScannedBlock const& C4_RESTRICT sb)
{
    if(m_options.scalar_filtering())
    {
        return _filter_scalar_literal(sb.scalar, sb.indentation, sb.chomp);
    }
    else
    {
        _c4dbgp("literal scalar left unfiltered");
        m_evt_handler->mark_key_scalar_unfiltered();
    }
    return sb.scalar;
}

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_maybe_filter_val_scalar_literal(ScannedBlock const& C4_RESTRICT sb)
{
    if(m_options.scalar_filtering())
    {
        return _filter_scalar_literal(sb.scalar, sb.indentation, sb.chomp);
    }
    else
    {
        _c4dbgp("literal scalar left unfiltered");
        m_evt_handler->mark_val_scalar_unfiltered();
    }
    return sb.scalar;
}


//-----------------------------------------------------------------------------

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_maybe_filter_key_scalar_folded(ScannedBlock const& C4_RESTRICT sb)
{
    if(m_options.scalar_filtering())
    {
        return _filter_scalar_folded(sb.scalar, sb.indentation, sb.chomp);
    }
    else
    {
        _c4dbgp("folded scalar left unfiltered");
        m_evt_handler->mark_key_scalar_unfiltered();
    }
    return sb.scalar;
}

template<class EventHandler>
csubstr ParseEngine<EventHandler>::_maybe_filter_val_scalar_folded(ScannedBlock const& C4_RESTRICT sb)
{
    if(m_options.scalar_filtering())
    {
        return _filter_scalar_folded(sb.scalar, sb.indentation, sb.chomp);
    }
    else
    {
        _c4dbgp("folded scalar left unfiltered");
        m_evt_handler->mark_val_scalar_unfiltered();
    }
    return sb.scalar;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

#ifdef RYML_DBG  //   !!! <----------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::add_flags(ParserFlag_t on, ParserState * s)
{
    char buf1_[64], buf2_[64], buf3_[64];
    csubstr buf1 = detail::_parser_flags_to_str(buf1_, on);
    csubstr buf2 = detail::_parser_flags_to_str(buf2_, s->flags);
    csubstr buf3 = detail::_parser_flags_to_str(buf3_, s->flags|on);
    _c4dbgpf("state[{}]: add {}: before={} after={}", s->level, buf1, buf2, buf3);
    s->flags |= on;
}

template<class EventHandler>
void ParseEngine<EventHandler>::addrem_flags(ParserFlag_t on, ParserFlag_t off, ParserState * s)
{
    char buf1_[64], buf2_[64], buf3_[64], buf4_[64];
    csubstr buf1 = detail::_parser_flags_to_str(buf1_, on);
    csubstr buf2 = detail::_parser_flags_to_str(buf2_, off);
    csubstr buf3 = detail::_parser_flags_to_str(buf3_, s->flags);
    csubstr buf4 = detail::_parser_flags_to_str(buf4_, ((s->flags|on)&(~off)));
    _c4dbgpf("state[{}]: add {} / rem {}: before={} after={}", s->level, buf1, buf2, buf3, buf4);
    s->flags |= on;
    s->flags &= ~off;
}

template<class EventHandler>
void ParseEngine<EventHandler>::rem_flags(ParserFlag_t off, ParserState * s)
{
    char buf1_[64], buf2_[64], buf3_[64];
    csubstr buf1 = detail::_parser_flags_to_str(buf1_, off);
    csubstr buf2 = detail::_parser_flags_to_str(buf2_, s->flags);
    csubstr buf3 = detail::_parser_flags_to_str(buf3_, s->flags&(~off));
    _c4dbgpf("state[{}]: rem {}: before={} after={}", s->level, buf1, buf2, buf3);
    s->flags &= ~off;
}

inline C4_NO_INLINE csubstr detail::_parser_flags_to_str(substr buf, ParserFlag_t flags)
{
    size_t pos = 0;
    bool gotone = false;

    #define _prflag(fl)                                     \
    if((flags & fl) == (fl))                                \
    {                                                       \
        if(gotone)                                          \
        {                                                   \
            if(pos + 1 < buf.len)                           \
                buf[pos] = '|';                             \
            ++pos;                                          \
        }                                                   \
        csubstr fltxt = #fl;                                \
        if(pos + fltxt.len <= buf.len)                      \
            memcpy(buf.str + pos, fltxt.str, fltxt.len);    \
        pos += fltxt.len;                                   \
        gotone = true;                                      \
    }

    _prflag(RTOP);
    _prflag(RUNK);
    _prflag(RMAP);
    _prflag(RSEQ);
    _prflag(FLOW);
    _prflag(BLCK);
    _prflag(QMRK);
    _prflag(RKEY);
    _prflag(RVAL);
    _prflag(RKCL);
    _prflag(RNXT);
    _prflag(SSCL);
    _prflag(QSCL);
    _prflag(RSET);
    _prflag(RDOC);
    _prflag(NDOC);
    _prflag(USTY);
    _prflag(RSEQIMAP);

    #undef _prflag

    if(pos == 0)
        if(buf.len > 0)
            buf[pos++] = '0';

    RYML_CHECK(pos <= buf.len);

    return buf.first(pos);
}

#endif // RYML_DBG   !!! <----------------------------------


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<class EventHandler>
csubstr ParseEngine<EventHandler>::location_contents(Location const& loc) const
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, loc.offset < m_buf.len);
    return m_buf.sub(loc.offset);
}

template<class EventHandler>
Location ParseEngine<EventHandler>::location(ConstNodeRef node) const
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, node.readable());
    return location(*node.tree(), node.id());
}

template<class EventHandler>
Location ParseEngine<EventHandler>::location(Tree const& tree, id_type node) const
{
    // try hard to avoid getting the location from a null string.
    Location loc;
    if(_location_from_node(tree, node, &loc, 0))
        return loc;
    return val_location(m_buf.str);
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_location_from_node(Tree const& tree, id_type node, Location *C4_RESTRICT loc, id_type level) const
{
    if(tree.has_key(node))
    {
        csubstr k = tree.key(node);
        if(C4_LIKELY(k.str != nullptr))
        {
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, k.is_sub(m_buf));
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_buf.is_super(k));
            *loc = val_location(k.str);
            return true;
        }
    }

    if(tree.has_val(node))
    {
        csubstr v = tree.val(node);
        if(C4_LIKELY(v.str != nullptr))
        {
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, v.is_sub(m_buf));
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_buf.is_super(v));
            *loc = val_location(v.str);
            return true;
        }
    }

    if(tree.is_container(node))
    {
        if(_location_from_cont(tree, node, loc))
            return true;
    }

    if(tree.type(node) != NOTYPE && level == 0)
    {
        // try the prev sibling
        {
            const id_type prev = tree.prev_sibling(node);
            if(prev != NONE)
            {
                if(_location_from_node(tree, prev, loc, level+1))
                    return true;
            }
        }
        // try the next sibling
        {
            const id_type next = tree.next_sibling(node);
            if(next != NONE)
            {
                if(_location_from_node(tree, next, loc, level+1))
                    return true;
            }
        }
        // try the parent
        {
            const id_type parent = tree.parent(node);
            if(parent != NONE)
            {
                if(_location_from_node(tree, parent, loc, level+1))
                    return true;
            }
        }
    }

    return false;
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_location_from_cont(Tree const& tree, id_type node, Location *C4_RESTRICT loc) const
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, tree.is_container(node));
    if(!tree.is_stream(node))
    {
        const char *node_start = tree._p(node)->m_val.scalar.str;  // this was stored in the container
        if(tree.has_children(node))
        {
            id_type child = tree.first_child(node);
            if(tree.has_key(child))
            {
                // when a map starts, the container was set after the key
                csubstr k = tree.key(child);
                if(k.str && node_start > k.str)
                    node_start = k.str;
            }
        }
        *loc = val_location(node_start);
        return true;
    }
    else // it's a stream
    {
        *loc = val_location(m_buf.str); // just return the front of the buffer
    }
    return true;
}


template<class EventHandler>
Location ParseEngine<EventHandler>::val_location(const char *val) const
{
    if(C4_UNLIKELY(val == nullptr))
        return {m_file, 0, 0, 0};
    _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, m_options.locations());
    // NOTE: if any of these checks fails, the parser needs to be
    // instantiated with locations enabled.
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_buf.str == m_newline_offsets_buf.str);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_buf.len == m_newline_offsets_buf.len);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_options.locations());
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, !_locations_dirty());
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_newline_offsets != nullptr);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_newline_offsets_size > 0);
    // NOTE: the pointer needs to belong to the buffer that was used to parse.
    csubstr src = m_buf;
    _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, val != nullptr || src.str == nullptr);
    _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, (val >= src.begin() && val <= src.end()) || (src.str == nullptr && val == nullptr));
    // ok. search the first stored newline after the given ptr
    using lineptr_type = size_t const* C4_RESTRICT;
    lineptr_type lineptr = nullptr;
    size_t offset = (size_t)(val - src.begin());
    if(m_newline_offsets_size < RYML_LOCATIONS_SMALL_THRESHOLD)
    {
        // just do a linear search if the size is small.
        for(lineptr_type curr = m_newline_offsets, last = m_newline_offsets + m_newline_offsets_size; curr < last; ++curr)
        {
            if(*curr > offset)
            {
                lineptr = curr;
                break;
            }
        }
    }
    else
    {
        // do a bisection search if the size is not small.
        //
        // We could use std::lower_bound but this is simple enough and
        // spares the costly include of <algorithm>.
        size_t count = m_newline_offsets_size;
        size_t step;
        lineptr_type it;
        lineptr = m_newline_offsets;
        while(count)
        {
            step = count >> 1;
            it = lineptr + step;
            if(*it < offset)
            {
                lineptr = ++it;
                count -= step + 1;
            }
            else
            {
                count = step;
            }
        }
    }
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, lineptr >= m_newline_offsets);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, lineptr <= m_newline_offsets + m_newline_offsets_size);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, *lineptr > offset);
    Location loc;
    loc.name = m_file;
    loc.offset = offset;
    loc.line = (size_t)(lineptr - m_newline_offsets);
    if(lineptr > m_newline_offsets)
        loc.col = (offset - *(lineptr-1) - 1u);
    else
        loc.col = offset;
    return loc;
}

template<class EventHandler>
void ParseEngine<EventHandler>::_prepare_locations()
{
    m_newline_offsets_buf = m_buf;
    size_t numnewlines = 1u + m_buf.count('\n');
    _resize_locations(numnewlines);
    m_newline_offsets_size = 0;
    for(size_t i = 0; i < m_buf.len; i++)
        if(m_buf[i] == '\n')
            m_newline_offsets[m_newline_offsets_size++] = i;
    m_newline_offsets[m_newline_offsets_size++] = m_buf.len;
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_newline_offsets_size == numnewlines);
}

template<class EventHandler>
void ParseEngine<EventHandler>::_resize_locations(size_t numnewlines)
{
    if(numnewlines > m_newline_offsets_capacity)
    {
        if(m_newline_offsets)
            _RYML_CB_FREE(m_evt_handler->m_stack.m_callbacks, m_newline_offsets, size_t, m_newline_offsets_capacity);
        m_newline_offsets = _RYML_CB_ALLOC_HINT(m_evt_handler->m_stack.m_callbacks, size_t, numnewlines, m_newline_offsets);
        m_newline_offsets_capacity = numnewlines;
    }
}

template<class EventHandler>
bool ParseEngine<EventHandler>::_locations_dirty() const
{
    return !m_newline_offsets_size;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_flow_skip_whitespace()
{
    if(m_evt_handler->m_curr->line_contents.rem.len > 0)
    {
        csubstr rem = m_evt_handler->m_curr->line_contents.rem;
        if(rem.str[0] == ' ' || rem.str[0] == '\t')
        {
            _c4dbgpf("starts with whitespace: '{}'", _c4prc(rem.str[0]));
            _skipchars(" \t");
            rem = m_evt_handler->m_curr->line_contents.rem;
        }
        // comments
        if(rem.begins_with('#'))
        {
            _c4dbgpf("it's a comment: {}", m_evt_handler->m_curr->line_contents.rem);
            _line_progressed(m_evt_handler->m_curr->line_contents.rem.len);
        }
    }
}


//-----------------------------------------------------------------------------


template<class EventHandler>
void ParseEngine<EventHandler>::_add_annotation(Annotation *C4_RESTRICT dst, csubstr str, size_t indentation, size_t line)
{
    _c4dbgpf("store annotation[{}]: '{}' indentation={} line={}", dst->num_entries, str, indentation, line);
    if(C4_UNLIKELY(dst->num_entries >= C4_COUNTOF(dst->annotations)))
        _c4err("too many annotations");
    dst->annotations[dst->num_entries].str = str;
    dst->annotations[dst->num_entries].indentation = indentation;
    dst->annotations[dst->num_entries].line = line;
    ++dst->num_entries;
}

template<class EventHandler>
void ParseEngine<EventHandler>::_clear_annotations(Annotation *C4_RESTRICT dst)
{
    dst->num_entries = 0;
}

#ifdef RYML_NO_COVERAGE__TO_BE_DELETED
template<class EventHandler>
bool ParseEngine<EventHandler>::_handle_indentation_from_annotations()
{
    if(m_pending_anchors.num_entries == 1u || m_pending_tags.num_entries == 1u)
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_pending_anchors.num_entries < 2u && m_pending_tags.num_entries < 2u);
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_pending_anchors.annotations[0].line < m_evt_handler->m_curr->pos.line);
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_pending_tags.annotations[1].line < m_evt_handler->m_curr->pos.line);
        size_t to_skip = m_evt_handler->m_curr->indref;
        if(m_pending_anchors.num_entries)
            to_skip = m_pending_anchors.annotations[0].indentation > to_skip ? m_pending_anchors.annotations[0].indentation : to_skip;
        if(m_pending_tags.num_entries)
            to_skip = m_pending_tags.annotations[0].indentation > to_skip ? m_pending_tags.annotations[0].indentation : to_skip;
        _c4dbgpf("annotations pending, skip indentation up to {}!", to_skip);
        _maybe_skipchars_up_to(' ', to_skip);
        return true;
    }
    return false;
}
#endif

template<class EventHandler>
bool ParseEngine<EventHandler>::_annotations_require_key_container() const
{
    return m_pending_tags.num_entries > 1 || m_pending_anchors.num_entries > 1;
}

template<class EventHandler>
void ParseEngine<EventHandler>::_check_tag(csubstr tag)
{
    if(!tag.begins_with("!<"))
    {
        if(C4_UNLIKELY(tag.first_of("[]{},") != npos))
            _RYML_CB_ERR_(m_evt_handler->m_stack.m_callbacks, "tags must not contain any of '[]{},'", m_evt_handler->m_curr->pos);
    }
    else
    {
        if(C4_UNLIKELY(!tag.ends_with('>')))
            _RYML_CB_ERR_(m_evt_handler->m_stack.m_callbacks, "malformed tag", m_evt_handler->m_curr->pos);
    }
}

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_annotations_before_blck_key_scalar()
{
    _c4dbgpf("annotations_before_blck_key_scalar, node={}", m_evt_handler->m_curr->node_id);
    if(m_pending_tags.num_entries)
    {
        _c4dbgpf("annotations_before_blck_key_scalar, #tags={}", m_pending_tags.num_entries);
        if(C4_LIKELY(m_pending_tags.num_entries == 1))
        {
            _check_tag(m_pending_tags.annotations[0].str);
            m_evt_handler->set_key_tag(m_pending_tags.annotations[0].str);
            _clear_annotations(&m_pending_tags);
        }
        else
        {
            _c4err("too many tags");
        }
    }
    if(m_pending_anchors.num_entries)
    {
        _c4dbgpf("annotations_before_blck_key_scalar, #anchors={}", m_pending_anchors.num_entries);
        if(C4_LIKELY(m_pending_anchors.num_entries == 1))
        {
            m_evt_handler->set_key_anchor(m_pending_anchors.annotations[0].str);
            _clear_annotations(&m_pending_anchors);
        }
        else
        {
            _c4err("too many anchors");
        }
    }
}

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_annotations_before_blck_val_scalar()
{
    _c4dbgpf("annotations_before_blck_val_scalar, node={}", m_evt_handler->m_curr->node_id);
    if(m_pending_tags.num_entries)
    {
        _c4dbgpf("annotations_before_blck_val_scalar, #tags={}", m_pending_tags.num_entries);
        if(C4_LIKELY(m_pending_tags.num_entries == 1))
        {
            _check_tag(m_pending_tags.annotations[0].str);
            m_evt_handler->set_val_tag(m_pending_tags.annotations[0].str);
            _clear_annotations(&m_pending_tags);
        }
        else
        {
            _c4err("too many tags");
        }
    }
    if(m_pending_anchors.num_entries)
    {
        _c4dbgpf("annotations_before_blck_val_scalar, #anchors={}", m_pending_anchors.num_entries);
        if(C4_LIKELY(m_pending_anchors.num_entries == 1))
        {
            m_evt_handler->set_val_anchor(m_pending_anchors.annotations[0].str);
            _clear_annotations(&m_pending_anchors);
        }
        else
        {
            _c4err("too many anchors");
        }
    }
}

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_annotations_before_start_mapblck(size_t current_line)
{
    _c4dbgpf("annotations_before_start_mapblck, current_line={}", current_line);
    if(m_pending_tags.num_entries == 2)
    {
        _c4dbgp("2 tags, setting entry 0");
        _check_tag(m_pending_tags.annotations[0].str);
        m_evt_handler->set_val_tag(m_pending_tags.annotations[0].str);
    }
    else if(m_pending_tags.num_entries == 1)
    {
        _c4dbgpf("1 tag. line={}, curr={}", m_pending_tags.annotations[0].line);
        if(m_pending_tags.annotations[0].line < current_line)
        {
            _c4dbgp("...tag is for the map. setting it.");
            _check_tag(m_pending_tags.annotations[0].str);
            m_evt_handler->set_val_tag(m_pending_tags.annotations[0].str);
            _clear_annotations(&m_pending_tags);
        }
    }
    //
    if(m_pending_anchors.num_entries == 2)
    {
        _c4dbgp("2 anchors, setting entry 0");
        m_evt_handler->set_val_anchor(m_pending_anchors.annotations[0].str);
    }
    else if(m_pending_anchors.num_entries == 1)
    {
        _c4dbgpf("1 anchor. line={}, curr={}", m_pending_anchors.annotations[0].line);
        if(m_pending_anchors.annotations[0].line < current_line)
        {
            _c4dbgp("...anchor is for the map. setting it.");
            m_evt_handler->set_val_anchor(m_pending_anchors.annotations[0].str);
            _clear_annotations(&m_pending_anchors);
        }
    }
}

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_annotations_before_start_mapblck_as_key()
{
    _c4dbgp("annotations_before_start_mapblck_as_key");
    if(m_pending_tags.num_entries == 2)
    {
        _check_tag(m_pending_tags.annotations[0].str);
        m_evt_handler->set_key_tag(m_pending_tags.annotations[0].str);
    }
    if(m_pending_anchors.num_entries == 2)
    {
        m_evt_handler->set_key_anchor(m_pending_anchors.annotations[0].str);
    }
}

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_annotations_and_indentation_after_start_mapblck(size_t key_indentation, size_t key_line)
{
    _c4dbgp("annotations_after_start_mapblck");
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_pending_tags.num_entries <= 2);
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_pending_anchors.num_entries <= 2);
    if(m_pending_anchors.num_entries || m_pending_tags.num_entries)
    {
        key_indentation = _select_indentation_from_annotations(key_indentation, key_line);
        switch(m_pending_tags.num_entries)
        {
        case 1u:
            _check_tag(m_pending_tags.annotations[0].str);
            m_evt_handler->set_key_tag(m_pending_tags.annotations[0].str);
            _clear_annotations(&m_pending_tags);
            break;
        case 2u:
            _check_tag(m_pending_tags.annotations[1].str);
            m_evt_handler->set_key_tag(m_pending_tags.annotations[1].str);
            _clear_annotations(&m_pending_tags);
            break;
        }
        switch(m_pending_anchors.num_entries)
        {
        case 1u:
            m_evt_handler->set_key_anchor(m_pending_anchors.annotations[0].str);
            _clear_annotations(&m_pending_anchors);
            break;
        case 2u:
            m_evt_handler->set_key_anchor(m_pending_anchors.annotations[1].str);
            _clear_annotations(&m_pending_anchors);
            break;
        }
    }
    _set_indentation(key_indentation);
}

template<class EventHandler>
size_t ParseEngine<EventHandler>::_select_indentation_from_annotations(size_t val_indentation, size_t val_line)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_pending_tags.num_entries || m_pending_anchors.num_entries);
    // select the left-most annotation on the max line
    auto const *C4_RESTRICT curr = m_pending_anchors.num_entries ? &m_pending_anchors.annotations[0] : &m_pending_tags.annotations[0];
    for(size_t i = 0; i < m_pending_anchors.num_entries; ++i)
    {
        auto const& C4_RESTRICT ann = m_pending_anchors.annotations[i];
        if(ann.line > curr->line)
            curr = &ann;
        else if(ann.indentation < curr->indentation)
            curr = &ann;
    }
    for(size_t j = 0; j < m_pending_tags.num_entries; ++j)
    {
        auto const& C4_RESTRICT ann = m_pending_tags.annotations[j];
        if(ann.line > curr->line)
            curr = &ann;
        else if(ann.indentation < curr->indentation)
            curr = &ann;
    }
    return curr->line < val_line ? val_indentation : curr->indentation;
}

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_directive(csubstr rem)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, rem.is_sub(m_evt_handler->m_curr->line_contents.rem));
    const size_t pos = rem.find('#');
    _c4dbgpf("handle_directive: pos={} rem={}", pos, rem);
    if(pos == npos) // no comments
    {
        m_evt_handler->add_directive(rem);
        _line_progressed(rem.len);
    }
    else
    {
        csubstr to_comment = rem.first(pos);
        csubstr trimmed = to_comment.trimr(" \t");
        m_evt_handler->add_directive(trimmed);
        _line_progressed(pos);
        _skip_comment();
    }
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_seq_json()
{
seqjson_start:
    _c4dbgpf("handle2_seq_json: node_id={} level={} indentation={}", m_evt_handler->m_curr->node_id, m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref);

    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RSEQ));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(FLOW));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RVAL|RNXT));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RVAL) != has_all(RNXT));

    _handle_flow_skip_whitespace();
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(!rem.len)
        goto seqjson_again;

    if(has_any(RVAL))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        const char first = rem.str[0];
        _c4dbgpf("mapjson[RVAL]: '{}'", first);
        switch(first)
        {
        case '"':
        {
            _c4dbgp("seqjson[RVAL]: scanning double-quoted scalar");
            ScannedScalar sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_val_scalar_dquot(sc);
            m_evt_handler->set_val_scalar_dquoted(maybe_filtered);
            addrem_flags(RNXT, RVAL);
            break;
        }
        case '[':
        {
            _c4dbgp("seqjson[RVAL]: start child seqjson");
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_seq_val_flow();
            addrem_flags(RVAL, RNXT);
            _line_progressed(1);
            break;
        }
        case '{':
        {
            _c4dbgp("seqjson[RVAL]: start child mapjson");
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_map_val_flow();
            addrem_flags(RMAP|RKEY, RSEQ|RVAL|RNXT);
            _line_progressed(1);
            goto seqjson_finish;
        }
        case ']': // this happens on a trailing comma like ", ]"
        {
            _c4dbgp("seqjson[RVAL]: end!");
            rem_flags(RSEQ);
            m_evt_handler->end_seq();
            _line_progressed(1);
            if(!has_all(RSEQ|FLOW))
                goto seqjson_finish;
            break;
        }
        default:
        {
            ScannedScalar sc;
            if(_scan_scalar_seq_json(&sc))
            {
                _c4dbgp("seqjson[RVAL]: it's a plain scalar.");
                csubstr maybe_filtered = _maybe_filter_val_scalar_plain(sc, m_evt_handler->m_curr->indref);
                m_evt_handler->set_val_scalar_plain(maybe_filtered);
                addrem_flags(RNXT, RVAL);
            }
            else
            {
                _c4err("parse error");
            }
        }
        }
    }
    else // RNXT
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        const char first = rem.str[0];
        _c4dbgpf("mapjson[RNXT]: '{}'", first);
        switch(first)
        {
        case ',':
        {
            _c4dbgp("seqjson[RNXT]: expect next val");
            addrem_flags(RVAL, RNXT);
            m_evt_handler->add_sibling();
            _line_progressed(1);
            break;
        }
        case ']':
        {
            _c4dbgp("seqjson[RNXT]: end!");
            m_evt_handler->end_seq();
            _line_progressed(1);
            goto seqjson_finish;
        }
        default:
            _c4err("parse error");
        }
    }

 seqjson_again:
    _c4dbgt("seqjson: go again", 0);
    if(_finished_line())
    {
        if(C4_LIKELY(!_finished_file()))
        {
            _line_ended();
            _scan_line();
            _c4dbgnextline();
        }
        else
        {
            _c4err("missing terminating ]");
        }
    }
    goto seqjson_start;

 seqjson_finish:
    _c4dbgp("seqjson: finish");
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_map_json()
{
mapjson_start:
    _c4dbgpf("handle2_map_json: node_id={} level={} indentation={}", m_evt_handler->m_curr->node_id, m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref);

    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(FLOW));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RKEY|RKCL|RVAL|RNXT));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, 1 == (has_any(RKEY) + has_any(RKCL) + has_any(RVAL) + has_any(RNXT)));

    _handle_flow_skip_whitespace();
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(!rem.len)
        goto mapjson_again;

    if(has_any(RKEY))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        const char first = rem.str[0];
        _c4dbgpf("mapjson[RKEY]: '{}'", first);
        switch(first)
        {
        case '"':
        {
            _c4dbgp("mapjson[RKEY]: scanning double-quoted scalar");
            ScannedScalar sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_key_scalar_dquot(sc);
            m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
            addrem_flags(RKCL, RKEY);
            break;
        }
        case '}': // this happens on a trailing comma like ", }"
        {
            _c4dbgp("mapjson[RKEY]: end!");
            m_evt_handler->end_map();
            _line_progressed(1);
            goto mapjson_finish;
        }
        default:
            _c4err("parse error");
        }
    }
    else if(has_any(RVAL))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        const char first = rem.str[0];
        _c4dbgpf("mapjson[RVAL]: '{}'", first);
        switch(first)
        {
        case '"':
        {
            _c4dbgp("mapjson[RVAL]: scanning double-quoted scalar");
            ScannedScalar sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_val_scalar_dquot(sc);
            m_evt_handler->set_val_scalar_dquoted(maybe_filtered);
            addrem_flags(RNXT, RVAL);
            break;
        }
        case '[':
        {
            _c4dbgp("mapjson[RVAL]: start val seqjson");
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_seq_val_flow();
            _set_indentation(m_evt_handler->m_parent->indref);
            addrem_flags(RSEQ|RVAL, RMAP|RNXT);
            _line_progressed(1);
            goto mapjson_finish;
        }
        case '{':
        {
            _c4dbgp("mapjson[RVAL]: start val mapjson");
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_map_val_flow();
            _set_indentation(m_evt_handler->m_parent->indref);
            addrem_flags(RKEY, RNXT);
            _line_progressed(1);
            // keep going in this function
            break;
        }
        default:
        {
            ScannedScalar sc;
            if(_scan_scalar_map_json(&sc))
            {
                _c4dbgp("mapjson[RVAL]: plain scalar.");
                csubstr maybe_filtered = _maybe_filter_val_scalar_plain(sc, m_evt_handler->m_curr->indref);
                m_evt_handler->set_val_scalar_plain(maybe_filtered);
                addrem_flags(RNXT, RVAL);
            }
            else
            {
                _c4err("parse error");
            }
            break;
        }
        }
    }
    else if(has_any(RKCL)) // read the key colon
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        const char first = rem.str[0];
        _c4dbgpf("mapjson[RKCL]: '{}'", first);
        if(first == ':')
        {
            _c4dbgp("mapjson[RKCL]: found the colon");
            addrem_flags(RVAL, RKCL);
            _line_progressed(1);
        }
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(RNXT))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        _c4dbgpf("mapjson[RNXT]: '{}'", rem.str[0]);
        if(rem.begins_with(','))
        {
            _c4dbgp("mapjson[RNXT]: expect next keyval");
            m_evt_handler->add_sibling();
            addrem_flags(RKEY, RNXT);
            _line_progressed(1);
        }
        else if(rem.begins_with('}'))
        {
            _c4dbgp("mapjson[RNXT]: end!");
            m_evt_handler->end_map();
            _line_progressed(1);
            goto mapjson_finish;
        }
        else
        {
            _c4err("parse error");
        }
    }

 mapjson_again:
    _c4dbgt("mapjson: go again", 0);
    if(_finished_line())
    {
        if(C4_LIKELY(!_finished_file()))
        {
            _line_ended();
            _scan_line();
            _c4dbgnextline();
        }
        else
        {
            _c4err("missing terminating }");
        }
    }
    goto mapjson_start;

 mapjson_finish:
    _c4dbgp("mapjson: finish");
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_seq_imap()
{
seqimap_start:
    _c4dbgpf("handle2_seq_imap: node_id={} level={} indref={}", m_evt_handler->m_curr->node_id, m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref);

    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RSEQIMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RVAL|RNXT|QMRK|RKCL));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, 1 == has_all(RVAL) + has_all(RNXT) + has_all(QMRK) + has_all(RKCL));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_stack.size() >= 3);

    _handle_flow_skip_whitespace();
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(!rem.len)
        goto seqimap_again;

    if(has_any(RVAL))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        const char first = rem.str[0];
        _c4dbgpf("seqimap[RVAL]: '{}'", _c4prc(first));
        ScannedScalar sc;
        if(first == '\'')
        {
            _c4dbgp("seqimap[RVAL]: scanning single-quoted scalar");
            sc = _scan_scalar_squot();
            csubstr maybe_filtered = _maybe_filter_val_scalar_squot(sc);
            m_evt_handler->set_val_scalar_squoted(maybe_filtered);
            m_evt_handler->end_map();
            goto seqimap_finish;
        }
        else if(first == '"')
        {
            _c4dbgp("seqimap[RVAL]: scanning double-quoted scalar");
            sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_val_scalar_dquot(sc);
            m_evt_handler->set_val_scalar_dquoted(maybe_filtered);
            m_evt_handler->end_map();
            goto seqimap_finish;
        }
        // block scalars (ie | and >) cannot appear in flow containers
        else if(_scan_scalar_plain_map_flow(&sc))
        {
            _c4dbgp("seqimap[RVAL]: it's a scalar.");
            csubstr maybe_filtered = _maybe_filter_val_scalar_plain(sc, m_evt_handler->m_curr->indref);
            m_evt_handler->set_val_scalar_plain(maybe_filtered);
            m_evt_handler->end_map();
            goto seqimap_finish;
        }
        else if(first == '[')
        {
            _c4dbgp("seqimap[RVAL]: start child seqflow");
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_seq_val_flow();
            addrem_flags(RVAL, RNXT|RSEQIMAP);
            _set_indentation(m_evt_handler->m_parent->indref);
            _line_progressed(1);
            goto seqimap_finish;
        }
        else if(first == '{')
        {
            _c4dbgp("seqimap[RVAL]: start child mapflow");
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_map_val_flow();
            addrem_flags(RMAP|RKEY, RSEQ|RVAL|RSEQIMAP|RNXT);
            _set_indentation(m_evt_handler->m_parent->indref);
            _line_progressed(1);
            goto seqimap_finish;
        }
        else if(first == ',' || first == ']')
        {
            _c4dbgp("seqimap[RVAL]: finish without val.");
            m_evt_handler->set_val_scalar_plain({});
            m_evt_handler->end_map();
            goto seqimap_finish;
        }
        else if(first == '&')
        {
            csubstr anchor = _scan_anchor();
            _c4dbgp("seqimap[RVAL]: anchor!");
            m_evt_handler->set_val_anchor(anchor);
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_seq();
            _c4dbgp("seqimap[RVAL]: ref!");
            m_evt_handler->set_val_ref(ref);
            addrem_flags(RNXT, RVAL);
        }
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(RNXT))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        const char first = rem.str[0];
        _c4dbgpf("seqimap[RNXT]: '{}'", _c4prc(first));
        if(first == ',' || first == ']')
        {
            // we may get here because a map or a seq started and we
            // return later
            _c4dbgp("seqimap: done");
            m_evt_handler->end_map();
            goto seqimap_finish;
        }
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(QMRK))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(QMRK));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        const char first = rem.str[0];
        _c4dbgpf("seqimap[QMRK]: '{}'", _c4prc(first));
        ScannedScalar sc;
        if(first == '\'')
        {
            _c4dbgp("seqimap[QMRK]: scanning single-quoted scalar");
            sc = _scan_scalar_squot();
            csubstr maybe_filtered = _maybe_filter_key_scalar_squot(sc);
            m_evt_handler->set_key_scalar_squoted(maybe_filtered);
            addrem_flags(RKCL, QMRK);
            goto seqimap_again;
        }
        else if(first == '"')
        {
            _c4dbgp("seqimap[QMRK]: scanning double-quoted scalar");
            sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_key_scalar_dquot(sc);
            m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
            addrem_flags(RKCL, QMRK);
            goto seqimap_again;
        }
        // block scalars (ie | and >) cannot appear in flow containers
        else if(_scan_scalar_plain_map_flow(&sc))
        {
            _c4dbgp("seqimap[QMRK]: it's a scalar.");
            csubstr maybe_filtered = _maybe_filter_key_scalar_plain(sc, m_evt_handler->m_curr->indref);
            m_evt_handler->set_key_scalar_plain(maybe_filtered);
            addrem_flags(RKCL, QMRK);
            goto seqimap_again;
        }
        else if(first == '[')
        {
            _c4dbgp("seqimap[QMRK]: start child seqflow");
            addrem_flags(RKCL, QMRK);
            m_evt_handler->begin_seq_key_flow();
            addrem_flags(RSEQ|RVAL, RKCL|RSEQIMAP);
            _set_indentation(m_evt_handler->m_parent->indref);
            _line_progressed(1);
            goto seqimap_finish;
        }
        else if(first == '{')
        {
            _c4dbgp("seqimap[QMRK]: start child mapflow");
            addrem_flags(RKCL, QMRK);
            m_evt_handler->begin_map_key_flow();
            addrem_flags(RMAP|RKEY, RSEQ|RKCL|RSEQIMAP);
            _set_indentation(m_evt_handler->m_parent->indref);
            _line_progressed(1);
            goto seqimap_finish;
        }
        else if(first == ',' || first == ']')
        {
            _c4dbgp("seqimap[QMRK]: finish without key.");
            m_evt_handler->set_key_scalar_plain({});
            m_evt_handler->set_val_scalar_plain({});
            m_evt_handler->end_map();
            goto seqimap_finish;
        }
        else if(first == '&')
        {
            csubstr anchor = _scan_anchor();
            _c4dbgp("seqimap[QMRK]: anchor!");
            m_evt_handler->set_key_anchor(anchor);
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_seq();
            _c4dbgp("seqimap[QMRK]: ref!");
            m_evt_handler->set_key_ref(ref);
            addrem_flags(RKCL, QMRK);
        }
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(RKCL))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RKCL));
        const char first = rem.str[0];
        _c4dbgpf("seqimap[RKCL]: '{}'", _c4prc(first));
        if(first == ':')
        {
            _c4dbgp("seqimap[RKCL]: found ':'");
            addrem_flags(RVAL, RKCL);
            _line_progressed(1);
            goto seqimap_again;
        }
        else if(first == ',' || first == ']')
        {
            _c4dbgp("seqimap[RKCL]: found ','. finish without val");
            m_evt_handler->set_val_scalar_plain({});
            m_evt_handler->end_map();
            goto seqimap_finish;
        }
        else
        {
            _c4err("parse error");
        }
    }

 seqimap_again:
    _c4dbgt("seqimap: go again", 0);
    if(_finished_line())
    {
        if(C4_LIKELY(!_finished_file()))
        {
            _line_ended();
            _scan_line();
            _c4dbgnextline();
        }
        else
        {
            _c4err("parse error");
        }
    }
    goto seqimap_start;

 seqimap_finish:
    _c4dbgp("seqimap: finish");
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_seq_flow()
{
seqflow_start:
    _c4dbgpf("handle2_seq_flow: node_id={} level={} indentation={}", m_evt_handler->m_curr->node_id, m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref);

    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RSEQ));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(FLOW));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RVAL|RNXT));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RVAL) != has_all(RNXT));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->indref != npos);

    _handle_flow_skip_whitespace();
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(!rem.len)
        goto seqflow_again;

    if(has_any(RVAL))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        const char first = rem.str[0];
        ScannedScalar sc;
        if(first == '\'')
        {
            _c4dbgp("seqflow[RVAL]: scanning single-quoted scalar");
            sc = _scan_scalar_squot();
            csubstr maybe_filtered = _maybe_filter_val_scalar_squot(sc);
            m_evt_handler->set_val_scalar_squoted(maybe_filtered);
            addrem_flags(RNXT, RVAL);
        }
        else if(first == '"')
        {
            _c4dbgp("seqflow[RVAL]: scanning double-quoted scalar");
            sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_val_scalar_dquot(sc);
            m_evt_handler->set_val_scalar_dquoted(maybe_filtered);
            addrem_flags(RNXT, RVAL);
        }
        // block scalars (ie | and >) cannot appear in flow containers
        else if(_scan_scalar_plain_seq_flow(&sc))
        {
            _c4dbgp("seqflow[RVAL]: it's a scalar.");
            csubstr maybe_filtered = _maybe_filter_val_scalar_plain(sc, m_evt_handler->m_curr->indref);
            m_evt_handler->set_val_scalar_plain(maybe_filtered);
            addrem_flags(RNXT, RVAL);
        }
        else if(first == '[')
        {
            _c4dbgp("seqflow[RVAL]: start child seqflow");
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_seq_val_flow();
            _set_indentation(m_evt_handler->m_parent->indref);
            addrem_flags(RVAL, RNXT);
            _line_progressed(1);
        }
        else if(first == '{')
        {
            _c4dbgp("seqflow[RVAL]: start child mapflow");
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_map_val_flow();
            _set_indentation(m_evt_handler->m_parent->indref);
            addrem_flags(RMAP|RKEY, RSEQ|RVAL|RNXT);
            _line_progressed(1);
            goto seqflow_finish;
        }
        else if(first == ']') // this happens on a trailing comma like ", ]"
        {
            _c4dbgp("seqflow[RVAL]: end!");
            _line_progressed(1);
            m_evt_handler->end_seq();
            goto seqflow_finish;
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_seq();
            _c4dbgpf("seqflow[RVAL]: ref! [{}]~~~{}~~~", ref.len, ref);
            m_evt_handler->set_val_ref(ref);
            addrem_flags(RNXT, RVAL);
        }
        else if(first == '&')
        {
            csubstr anchor = _scan_anchor();
            _c4dbgpf("seqflow[RVAL]: anchor! [{}]~~~{}~~~", anchor.len, anchor);
            m_evt_handler->set_val_anchor(anchor);
            if(_maybe_scan_following_comma())
            {
                _c4dbgp("seqflow[RVAL]: empty scalar!");
                m_evt_handler->set_val_scalar_plain({});
                m_evt_handler->add_sibling();
            }
        }
        else if(first == '!')
        {
            csubstr tag = _scan_tag();
            _c4dbgpf("seqflow[RVAL]: tag! [{}]~~~{}~~~", tag.len, tag);
            _check_tag(tag);
            m_evt_handler->set_val_tag(tag);
            if(_maybe_scan_following_comma())
            {
                _c4dbgp("seqflow[RVAL]: empty scalar!");
                m_evt_handler->set_val_scalar_plain({});
                m_evt_handler->add_sibling();
            }
        }
        else if(first == ':')
        {
            _c4dbgpf("seqflow[RVAL]: actually seqimap at node[{}], with empty key", m_evt_handler->m_curr->node_id);
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_map_val_flow();
            _set_indentation(m_evt_handler->m_parent->indref);
            m_evt_handler->set_key_scalar_plain({});
            addrem_flags(RSEQIMAP|RVAL, RSEQ|RNXT);
            _line_progressed(1);
            goto seqflow_finish;
        }
        else if(first == '?')
        {
            _c4dbgp("seqflow[RVAL]: start child mapflow, explicit key");
            addrem_flags(RNXT, RVAL);
            m_was_inside_qmrk = true;
            m_evt_handler->begin_map_val_flow();
            _set_indentation(m_evt_handler->m_parent->indref);
            addrem_flags(RSEQIMAP|QMRK, RSEQ|RNXT);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
            goto seqflow_finish;
        }
        else
        {
            _c4err("parse error");
        }
    }
    else // RNXT
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        const char first = rem.str[0];
        if(first == ',')
        {
            _c4dbgp("seqflow[RNXT]: expect next val");
            addrem_flags(RVAL, RNXT);
            m_evt_handler->add_sibling();
            _line_progressed(1);
        }
        else if(first == ']')
        {
            _c4dbgp("seqflow[RNXT]: end!");
            m_evt_handler->end_seq();
            _line_progressed(1);
            goto seqflow_finish;
        }
        else if(first == ':')
        {
            _c4dbgpf("seqflow[RNXT]: actually seqimap at node[{}]", m_evt_handler->m_curr->node_id);
            m_evt_handler->actually_val_is_first_key_of_new_map_flow();
            _set_indentation(m_evt_handler->m_parent->indref);
            _line_progressed(1);
            addrem_flags(RSEQIMAP|RVAL, RNXT);
            goto seqflow_finish;
        }
        else
        {
            _c4err("parse error");
        }
    }

 seqflow_again:
    _c4dbgt("seqflow: go again", 0);
    if(_finished_line())
    {
        if(C4_LIKELY(!_finished_file()))
        {
            _line_ended();
            _scan_line();
            _c4dbgnextline();
        }
        else
        {
            _c4err("missing terminating ]");
        }
    }
    goto seqflow_start;

 seqflow_finish:
    _c4dbgp("seqflow: finish");
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_map_flow()
{
mapflow_start:
    _c4dbgpf("handle2_map_flow: node_id={} level={} indentation={}", m_evt_handler->m_curr->node_id, m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref);

    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(FLOW));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RKEY|RKCL|RVAL|RNXT|QMRK));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, 1 == (has_any(RKEY) + has_any(RKCL) + has_any(RVAL) + has_any(RNXT) + has_any(QMRK)));

    _handle_flow_skip_whitespace();
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(!rem.len)
        goto mapflow_again;

    if(has_any(RKEY))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        const char first = rem.str[0];
        _c4dbgpf("mapflow[RKEY]: '{}'", first);
        ScannedScalar sc;
        if(first == '\'')
        {
            _c4dbgp("mapflow[RKEY]: scanning single-quoted scalar");
            sc = _scan_scalar_squot();
            csubstr maybe_filtered = _maybe_filter_key_scalar_squot(sc);
            m_evt_handler->set_key_scalar_squoted(maybe_filtered);
            addrem_flags(RKCL, RKEY|QMRK);
        }
        else if(first == '"')
        {
            _c4dbgp("mapflow[RKEY]: scanning double-quoted scalar");
            sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_key_scalar_dquot(sc);
            m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
            addrem_flags(RKCL, RKEY|QMRK);
        }
        // block scalars (ie | and >) cannot appear in flow containers
        else if(_scan_scalar_plain_map_flow(&sc))
        {
            _c4dbgp("mapflow[RKEY]: plain scalar");
            csubstr maybe_filtered = _maybe_filter_key_scalar_plain(sc, m_evt_handler->m_curr->indref);
            m_evt_handler->set_key_scalar_plain(maybe_filtered);
            addrem_flags(RKCL, RKEY|QMRK);
        }
        else if(first == '?')
        {
            _c4dbgp("mapflow[RKEY]: explicit key");
            _line_progressed(1);
            addrem_flags(QMRK, RKEY);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == ':')
        {
            _c4dbgp("mapflow[RKEY]: setting empty key");
            m_evt_handler->set_key_scalar_plain({});
            addrem_flags(RVAL, RKEY|QMRK);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '}') // this happens on a trailing comma like ", }"
        {
            _c4dbgp("mapflow[RKEY]: end!");
            m_evt_handler->end_map();
            _line_progressed(1);
            goto mapflow_finish;
        }
        else if(first == '&')
        {
            csubstr anchor = _scan_anchor();
            _c4dbgpf("mapflow[RKEY]: key anchor! [{}]~~~{}~~~", anchor.len, anchor);
            m_evt_handler->set_key_anchor(anchor);
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_map();
            _c4dbgpf("mapflow[RKEY]: key ref! [{}]~~~{}~~~", ref.len, ref);
            m_evt_handler->set_key_ref(ref);
            addrem_flags(RKCL, RKEY);
        }
        else if(first == '[')
        {
            // RYML's tree cannot store container keys, but that's
            // handled inside the tree sink. Other sink types may be
            // able to handle it.
            _c4dbgp("mapflow[RKEY]: start child seqflow (!)");
            addrem_flags(RKCL, RKEY);
            m_evt_handler->begin_seq_key_flow();
            addrem_flags(RSEQ|RVAL, RMAP|RKCL);
            _set_indentation(m_evt_handler->m_parent->indref);
            _line_progressed(1);
            goto mapflow_finish;
        }
        else if(first == '{')
        {
            // RYML's tree cannot store container keys, but that's
            // handled inside the tree sink. Other sink types may be
            // able to handle it.
            _c4dbgp("mapflow[RKEY]: start child mapflow (!)");
            addrem_flags(RKCL, RKEY);
            m_evt_handler->begin_map_key_flow();
            addrem_flags(RKEY, RVAL|RKCL);
            _set_indentation(m_evt_handler->m_parent->indref);
            _line_progressed(1);
            // keep going in this function
        }
        else if(first == '!')
        {
            csubstr tag = _scan_tag();
            _c4dbgpf("mapflow[RKEY]: tag! [{}]~~~{}~~~", tag.len, tag);
            _check_tag(tag);
            m_evt_handler->set_key_tag(tag);
        }
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(RKCL)) // read the key colon
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        const char first = rem.str[0];
        _c4dbgpf("mapflow[RKCL]: '{}'", first);
        if(first == ':')
        {
            _c4dbgp("mapflow[RKCL]: found the colon");
            addrem_flags(RVAL, RKCL);
            _line_progressed(1);
        }
        else if(first == '}')
        {
            _c4dbgp("mapflow[RKCL]: end with missing val!");
            addrem_flags(RVAL, RKCL);
            m_evt_handler->set_val_scalar_plain({});
            m_evt_handler->end_map();
            _line_progressed(1);
            goto mapflow_finish;
        }
        else if(first == ',')
        {
            _c4dbgp("mapflow[RKCL]: got comma. val is missing");
            m_evt_handler->set_val_scalar_plain({});
            m_evt_handler->add_sibling();
            addrem_flags(RKEY, RKCL);
            _line_progressed(1);
        }
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(RVAL))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        const char first = rem.str[0];
        _c4dbgpf("mapflow[RVAL]: '{}'", first);
        ScannedScalar sc;
        if(first == '\'')
        {
            _c4dbgp("mapflow[RVAL]: scanning single-quoted scalar");
            sc = _scan_scalar_squot();
            csubstr maybe_filtered = _maybe_filter_val_scalar_squot(sc);
            m_evt_handler->set_val_scalar_squoted(maybe_filtered);
            addrem_flags(RNXT, RVAL);
        }
        else if(first == '"')
        {
            _c4dbgp("mapflow[RVAL]: scanning double-quoted scalar");
            sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_val_scalar_dquot(sc);
            m_evt_handler->set_val_scalar_dquoted(maybe_filtered);
            addrem_flags(RNXT, RVAL);
        }
        // block scalars (ie | and >) cannot appear in flow containers
        else if(_scan_scalar_plain_map_flow(&sc))
        {
            _c4dbgp("mapflow[RVAL]: plain scalar.");
            csubstr maybe_filtered = _maybe_filter_val_scalar_plain(sc, m_evt_handler->m_curr->indref);
            m_evt_handler->set_val_scalar_plain(maybe_filtered);
            addrem_flags(RNXT, RVAL);
        }
        else if(first == '[')
        {
            _c4dbgp("mapflow[RVAL]: start val seqflow");
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_seq_val_flow();
            _set_indentation(m_evt_handler->m_parent->indref);
            addrem_flags(RSEQ|RVAL, RMAP|RNXT);
            _line_progressed(1);
            goto mapflow_finish;
        }
        else if(first == '{')
        {
            _c4dbgp("mapflow[RVAL]: start val mapflow");
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_map_val_flow();
            _set_indentation(m_evt_handler->m_parent->indref);
            addrem_flags(RKEY, RNXT);
            _line_progressed(1);
            // keep going in this function
        }
        else if(first == '}')
        {
            _c4dbgp("mapflow[RVAL]: end!");
            m_evt_handler->set_val_scalar_plain({});
            m_evt_handler->end_map();
            _line_progressed(1);
            goto mapflow_finish;
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_map();
            _c4dbgpf("mapflow[RVAL]: key ref! [{}]~~~{}~~~", ref.len, ref);
            m_evt_handler->set_val_ref(ref);
            addrem_flags(RNXT, RVAL);
        }
        else if(first == '&')
        {
            csubstr anchor = _scan_anchor();
            _c4dbgpf("mapflow[RVAL]: key anchor! [{}]~~~{}~~~", anchor.len, anchor);
            m_evt_handler->set_val_anchor(anchor);
        }
        else if(first == '!')
        {
            csubstr tag = _scan_tag();
            _c4dbgpf("mapflow[RVAL]: tag! [{}]~~~{}~~~", tag.len, tag);
            _check_tag(tag);
            m_evt_handler->set_val_tag(tag);
        }
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(RNXT))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        _c4dbgpf("mapflow[RNXT]: '{}'", rem.str[0]);
        if(rem.begins_with(','))
        {
            _c4dbgp("mapflow[RNXT]: expect next keyval");
            m_evt_handler->add_sibling();
            addrem_flags(RKEY, RNXT);
            _line_progressed(1);
        }
        else if(rem.begins_with('}'))
        {
            _c4dbgp("mapflow[RNXT]: end!");
            m_evt_handler->end_map();
            _line_progressed(1);
            goto mapflow_finish;
        }
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(QMRK))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        const char first = rem.str[0];
        _c4dbgpf("mapflow[QMRK]: '{}'", first);
        ScannedScalar sc;
        if(first == '\'')
        {
            _c4dbgp("mapflow[QMRK]: scanning single-quoted scalar");
            sc = _scan_scalar_squot();
            csubstr maybe_filtered = _maybe_filter_key_scalar_squot(sc);
            m_evt_handler->set_key_scalar_squoted(maybe_filtered);
            addrem_flags(RKCL, QMRK);
        }
        else if(first == '"')
        {
            _c4dbgp("mapflow[QMRK]: scanning double-quoted scalar");
            sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_key_scalar_dquot(sc);
            m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
            addrem_flags(RKCL, QMRK);
        }
        // block scalars (ie | and >) cannot appear in flow containers
        else if(_scan_scalar_plain_map_flow(&sc))
        {
            _c4dbgp("mapflow[QMRK]: plain scalar");
            csubstr maybe_filtered = _maybe_filter_key_scalar_plain(sc, m_evt_handler->m_curr->indref);
            m_evt_handler->set_key_scalar_plain(maybe_filtered);
            addrem_flags(RKCL, QMRK);
        }
        else if(first == ':')
        {
            _c4dbgp("mapflow[QMRK]: setting empty key");
            m_evt_handler->set_key_scalar_plain({});
            addrem_flags(RVAL, QMRK);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '}') // this happens on a trailing comma like ", }"
        {
            _c4dbgp("mapflow[QMRK]: end!");
            m_evt_handler->set_key_scalar_plain({});
            m_evt_handler->set_val_scalar_plain({});
            m_evt_handler->end_map();
            _line_progressed(1);
            goto mapflow_finish;
        }
        else if(first == '&')
        {
            csubstr anchor = _scan_anchor();
            _c4dbgpf("mapflow[QMRK]: key anchor! [{}]~~~{}~~~", anchor.len, anchor);
            m_evt_handler->set_key_anchor(anchor);
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_map();
            _c4dbgpf("mapflow[QMRK]: key ref! [{}]~~~{}~~~", ref.len, ref);
            m_evt_handler->set_key_ref(ref);
            addrem_flags(RKCL, QMRK);
        }
        else if(first == '[')
        {
            // RYML's tree cannot store container keys, but that's
            // handled inside the tree sink. Other sink types may be
            // able to handle it.
            _c4dbgp("mapflow[QMRK]: start child seqflow (!)");
            addrem_flags(RKCL, QMRK);
            m_evt_handler->begin_seq_key_flow();
            addrem_flags(RSEQ|RVAL, RMAP|RKCL);
            _set_indentation(m_evt_handler->m_parent->indref);
            _line_progressed(1);
            goto mapflow_finish;
        }
        else if(first == '{')
        {
            // RYML's tree cannot store container keys, but that's
            // handled inside the tree sink. Other sink types may be
            // able to handle it.
            _c4dbgp("mapflow[QMRK]: start child mapflow (!)");
            addrem_flags(RKCL, QMRK);
            m_evt_handler->begin_map_key_flow();
            _set_indentation(m_evt_handler->m_parent->indref);
            addrem_flags(RKEY, RKCL);
            _line_progressed(1);
            // keep going in this function
        }
        else if(first == '!')
        {
            csubstr tag = _scan_tag();
            _c4dbgpf("mapflow[QMRK]: tag! [{}]~~~{}~~~", tag.len, tag);
            _check_tag(tag);
            m_evt_handler->set_key_tag(tag);
        }
        else
        {
            _c4err("parse error");
        }
    }

 mapflow_again:
    _c4dbgt("mapflow: go again", 0);
    if(_finished_line())
    {
        if(C4_LIKELY(!_finished_file()))
        {
            _line_ended();
            _scan_line();
            _c4dbgnextline();
        }
        else
        {
            _c4err("missing terminating }");
        }
    }
    goto mapflow_start;

 mapflow_finish:
    _c4dbgp("mapflow: finish");
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_seq_block()
{
seqblck_start:
    _c4dbgpf("handle2_seq_block: seq_id={} node_id={} level={} indent={}", m_evt_handler->m_parent->node_id, m_evt_handler->m_curr->node_id, m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref);

    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RSEQ));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(BLCK));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RVAL|RNXT));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, 1 == (has_any(RVAL) + has_any(RNXT)));

    _maybe_skip_comment();
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(!rem.len)
        goto seqblck_again;

    if(has_any(RVAL))
    {
        _c4dbgpf("seqblck[RVAL]: col={}", m_evt_handler->m_curr->pos.col);
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        if(m_evt_handler->m_curr->at_line_beginning())
        {
            _c4dbgpf("seqblck[RVAL]: indref={} indentation={}", m_evt_handler->m_curr->indref, m_evt_handler->m_curr->line_contents.indentation);
            if(m_evt_handler->m_curr->indentation_ge())
            {
                _c4dbgpf("seqblck[RVAL]: skip {} from indentation", m_evt_handler->m_curr->line_contents.indentation);
                _line_progressed(m_evt_handler->m_curr->line_contents.indentation);
                rem = m_evt_handler->m_curr->line_contents.rem;
                if(!rem.len)
                    goto seqblck_again;
            }
            else if(m_evt_handler->m_curr->indentation_lt())
            {
                _c4dbgp("seqblck[RVAL]: smaller indentation!");
                _handle_indentation_pop_from_block_seq();
                goto seqblck_finish;
            }
            else if(m_evt_handler->m_curr->line_contents.indentation == npos)
            {
                _c4dbgp("seqblck[RVAL]: empty line!");
                _line_progressed(m_evt_handler->m_curr->line_contents.rem.len);
                goto seqblck_again;
            }
        }
        #ifdef RYML_NO_COVERAGE__TO_BE_DELETED
        else
        {
            // accomodate annotation on the previous line. eg:
            // - &elm
            //   foo            # <-- on this line
            // - &elm
            //   &foo foo: bar  # <-- on this line
            if(rem.str[0] == ' ')
            {
                if(_handle_indentation_from_annotations())
                {
                    _c4dbgp("seqblck[RVAL]: annotations!");
                    rem = m_evt_handler->m_curr->line_contents.rem;
                    if(!rem.len)
                        goto seqblck_again;
                }
            }
        }
        #endif
        _RYML_CB_ASSERT(callbacks(), rem.len);
        _c4dbgpf("seqblck[RVAL]: '{}' node_id={}", rem.str[0], m_evt_handler->m_curr->node_id);
        const char first = rem.str[0];
        const size_t startline = m_evt_handler->m_curr->pos.line;
        // warning: the gcc optimizer on x86 builds is brittle with
        // this function:
        const size_t startindent = m_evt_handler->m_curr->line_contents.current_col();
        ScannedScalar sc;
        if(first == '\'')
        {
            _c4dbgp("seqblck[RVAL]: single-quoted scalar");
            sc = _scan_scalar_squot();
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("seqblck[RVAL]: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_squot(sc); // VAL!
                m_evt_handler->set_val_scalar_squoted(maybe_filtered);
                addrem_flags(RNXT, RVAL);
            }
            else
            {
                _c4dbgp("seqblck[RVAL]: start mapblck, set scalar as key");
                addrem_flags(RNXT, RVAL);
                _handle_annotations_before_start_mapblck(startline);
                m_evt_handler->begin_map_val_block();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                csubstr maybe_filtered = _maybe_filter_key_scalar_squot(sc); // KEY!
                m_evt_handler->set_key_scalar_squoted(maybe_filtered);
                addrem_flags(RMAP|RVAL, RSEQ|RNXT);
                _maybe_skip_whitespace_tokens();
                goto seqblck_finish;
            }
        }
        else if(first == '"')
        {
            _c4dbgp("seqblck[RVAL]: double-quoted scalar");
            sc = _scan_scalar_dquot();
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("seqblck[RVAL]: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_dquot(sc); // VAL!
                m_evt_handler->set_val_scalar_dquoted(maybe_filtered);
                addrem_flags(RNXT, RVAL);
            }
            else
            {
                _c4dbgp("seqblck[RVAL]: start mapblck, set scalar as key");
                addrem_flags(RNXT, RVAL);
                _handle_annotations_before_start_mapblck(startline);
                m_evt_handler->begin_map_val_block();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                csubstr maybe_filtered = _maybe_filter_key_scalar_dquot(sc); // KEY!
                m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
                addrem_flags(RMAP|RVAL, RSEQ|RNXT);
                _maybe_skip_whitespace_tokens();
                goto seqblck_finish;
            }
        }
        // block scalars can only appear as keys when in QMRK scope
        // (ie, after ? tokens), so no need to scan following colon in
        // here.
        else if(first == '|')
        {
            _c4dbgp("seqblck[RVAL]: block-literal scalar");
            ScannedBlock sb;
            _scan_block(&sb, m_evt_handler->m_curr->indref + 1);
            _handle_annotations_before_blck_val_scalar();
            csubstr maybe_filtered = _maybe_filter_val_scalar_literal(sb);
            m_evt_handler->set_val_scalar_literal(maybe_filtered);
            addrem_flags(RNXT, RVAL);
        }
        else if(first == '>')
        {
            _c4dbgp("seqblck[RVAL]: block-folded scalar");
            ScannedBlock sb;
            _scan_block(&sb, m_evt_handler->m_curr->indref + 1);
            _handle_annotations_before_blck_val_scalar();
            csubstr maybe_filtered = _maybe_filter_val_scalar_folded(sb);
            m_evt_handler->set_val_scalar_folded(maybe_filtered);
            addrem_flags(RNXT, RVAL);
        }
        else if(_scan_scalar_plain_seq_blck(&sc))
        {
            _c4dbgp("seqblck[RVAL]: plain scalar.");
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("seqblck[RVAL]: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_plain(sc, m_evt_handler->m_curr->indref);  // VAL!
                m_evt_handler->set_val_scalar_plain(maybe_filtered);
                addrem_flags(RNXT, RVAL);
            }
            else
            {
                if(startindent > m_evt_handler->m_curr->indref)
                {
                    _c4dbgp("seqblck[RVAL]: start mapblck, set scalar as key");
                    addrem_flags(RNXT, RVAL);
                    _handle_annotations_before_start_mapblck(startline);
                    m_evt_handler->begin_map_val_block();
                    _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                    csubstr maybe_filtered = _maybe_filter_key_scalar_plain(sc, m_evt_handler->m_curr->indref);  // KEY!
                    m_evt_handler->set_key_scalar_plain(maybe_filtered);
                    addrem_flags(RMAP|RVAL, RSEQ|RNXT);
                    _maybe_skip_whitespace_tokens();
                    goto seqblck_finish;
                }
                else if(m_evt_handler->m_parent && m_evt_handler->m_parent->indref == startindent && has_any(RMAP|BLCK, m_evt_handler->m_parent))
                {
                    _c4dbgp("seqblck[RVAL]: empty val + end indentless seq + set key");
                    m_evt_handler->set_val_scalar_plain({});
                    m_evt_handler->end_seq();
                    m_evt_handler->add_sibling();
                    csubstr maybe_filtered = _maybe_filter_key_scalar_plain(sc, m_evt_handler->m_curr->indref);  // KEY!
                    m_evt_handler->set_key_scalar_plain(maybe_filtered);
                    addrem_flags(RVAL, RNXT|RKEY);
                    _maybe_skip_whitespace_tokens();
                    goto seqblck_finish;
                }
                else
                {
                    _c4err("parse error");
                }
            }
        }
        else if(first == '[')
        {
            _c4dbgp("seqblck[RVAL]: start child seqflow");
            addrem_flags(RNXT, RVAL);
            m_evt_handler->begin_seq_val_flow();
            addrem_flags(FLOW|RVAL, BLCK|RNXT);
            _line_progressed(1);
            _set_indentation(m_evt_handler->m_parent->indref + 1u);
            goto seqblck_finish;
        }
        else if(first == '{')
        {
            _c4dbgp("seqblck[RVAL]: start child mapflow");
            addrem_flags(RNXT, RVAL);
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->begin_map_val_flow();
            addrem_flags(RMAP|RKEY|FLOW, BLCK|RSEQ|RVAL|RNXT);
            _line_progressed(1);
            _set_indentation(m_evt_handler->m_parent->indref + 1u);
            goto seqblck_finish;
        }
        else if(first == '-')
        {
            if(startindent == m_evt_handler->m_curr->indref)
            {
                _c4dbgp("seqblck[RVAL]: prev val was empty");
                _handle_annotations_before_blck_val_scalar();
                m_evt_handler->set_val_scalar_plain({});
                // keep in RVAL, but for the next sibling
                m_evt_handler->add_sibling();
            }
            else
            {
                _c4dbgp("seqblck[RVAL]: start child seqblck");
                _RYML_CB_ASSERT(this->callbacks(), startindent > m_evt_handler->m_curr->indref);
                addrem_flags(RNXT, RVAL);
                _handle_annotations_before_blck_val_scalar();
                m_evt_handler->begin_seq_val_block();
                addrem_flags(RVAL, RNXT);
                _save_indentation();
                // keep going on inside this function
            }
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == ':')
        {
            _c4dbgp("seqblck[RVAL]: start child mapblck with empty key");
            addrem_flags(RNXT, RVAL);
            _handle_annotations_before_start_mapblck(startline);
            m_evt_handler->begin_map_val_block();
            _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
            m_evt_handler->set_key_scalar_plain({});
            addrem_flags(RMAP|RVAL, RSEQ|RNXT);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
            goto seqblck_finish;
        }
        else if(first == '&')
        {
            const csubstr anchor = _scan_anchor();
            _c4dbgpf("seqblck[RVAL]: anchor! [{}]~~~{}~~~", anchor.len, anchor);
            // we need to buffer the anchors, as there may be two
            // consecutive anchors in here
            _add_annotation(&m_pending_anchors, anchor, startindent, startline);
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_seq();
            _c4dbgpf("seqblck[RVAL]: ref! [{}]~~~{}~~~", ref.len, ref);
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("seqblck[RVAL]: set ref as val!");
                _handle_annotations_before_blck_val_scalar();
                m_evt_handler->set_val_ref(ref);
                addrem_flags(RNXT, RVAL);
            }
            else
            {
                _c4dbgp("seqblck[RVAL]: ref is key of map");
                addrem_flags(RNXT, RVAL);
                _handle_annotations_before_start_mapblck(startline);
                m_evt_handler->begin_map_val_block();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                m_evt_handler->set_key_ref(ref);
                addrem_flags(RMAP|RVAL, RSEQ|RNXT);
                _set_indentation(startindent);
                _maybe_skip_whitespace_tokens();
                goto seqblck_finish;
            }
        }
        else if(first == '!')
        {
            csubstr tag = _scan_tag();
            _c4dbgpf("seqblck[RVAL]: val tag! [{}]~~~{}~~~", tag.len, tag);
            // we need to buffer the tags, as there may be two
            // consecutive tags in here
            _add_annotation(&m_pending_tags, tag, startindent, startline);
        }
        else if(first == '?')
        {
            _c4dbgp("seqblck[RVAL]: start child mapblck, explicit key");
            addrem_flags(RNXT, RVAL);
            m_was_inside_qmrk = true;
            m_evt_handler->begin_map_val_block();
            addrem_flags(RMAP|QMRK, RSEQ|RNXT);
            _save_indentation();
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
            goto seqblck_finish;
        }
        else
        {
            _c4err("parse error");
        }
    }
    else // RNXT
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        //
        // handle indentation
        //
        _c4dbgpf("seqblck[RNXT]: indref={} indentation={}", m_evt_handler->m_curr->indref, m_evt_handler->m_curr->line_contents.indentation);
        if(C4_UNLIKELY(!_at_line_begin()))
            _c4err("parse error");
        if(m_evt_handler->m_curr->indentation_ge())
        {
            _c4dbgpf("seqblck[RNXT]: skip {} from indref", m_evt_handler->m_curr->indref);
            _line_progressed(m_evt_handler->m_curr->indref);
            _maybe_skip_whitespace_tokens();
            rem = m_evt_handler->m_curr->line_contents.rem;
            if(!rem.len)
                goto seqblck_again;
        }
        else if(m_evt_handler->m_curr->indentation_lt())
        {
            _c4dbgp("seqblck[RNXT]: smaller indentation!");
            _handle_indentation_pop_from_block_seq();
            if(has_all(RSEQ|BLCK))
            {
                _c4dbgp("seqblck[RNXT]: still seqblck!");
                _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RNXT));
                _line_progressed(m_evt_handler->m_curr->line_contents.indentation);
                rem = m_evt_handler->m_curr->line_contents.rem;
                if(!rem.len)
                    goto seqblck_again;
            }
            else
            {
                _c4dbgp("seqblck[RNXT]: no longer seqblck!");
                goto seqblck_finish;
            }
        }
        else if(m_evt_handler->m_curr->line_contents.indentation == npos)
        {
            _c4dbgpf("seqblck[RNXT]: blank line, len={}", m_evt_handler->m_curr->line_contents.rem);
            _line_progressed(m_evt_handler->m_curr->line_contents.rem.len);
            rem = m_evt_handler->m_curr->line_contents.rem;
            if(!rem.len)
                goto seqblck_again;
        }
        //
        // now handle the tokens
        //
        const char first = rem.str[0];
        _c4dbgpf("seqblck[RNXT]: '{}' node_id={}", first, m_evt_handler->m_curr->node_id);
        if(first == '-')
        {
            if(m_evt_handler->m_curr->indref > 0 || m_evt_handler->m_curr->line_contents.indentation > 0 || !_is_doc_begin_token(rem))
            {
                _c4dbgp("seqblck[RNXT]: expect next val");
                addrem_flags(RVAL, RNXT);
                m_evt_handler->add_sibling();
                _line_progressed(1);
                _maybe_skip_whitespace_tokens();
            }
            else
            {
                _c4dbgp("seqblck[RNXT]: start doc");
                _start_doc_suddenly();
                _line_progressed(3);
                _maybe_skip_whitespace_tokens();
                goto seqblck_finish;
            }
        }
        else if(first == ':')
        {
            // This happens for example in `- [a: b]: c` (after
            // terminating the seq, ie, after `]`). All other cases
            // (ie colon after scalars) are caught elsewhere (ie, in
            // RVAL state).
            auto const *C4_RESTRICT prev_state = m_evt_handler->m_parent;
            if(C4_LIKELY(prev_state && (prev_state->flags & RMAP)))
            {
                _c4dbgp("seqblck[RNXT]: actually this seq was '?' key of parent map");
                m_evt_handler->end_seq();
                goto seqblck_finish;
            }
            else
            {
                _c4err("parse error");
            }
        }
        else if(first == '.')
        {
            _c4dbgp("seqblck[RNXT]: maybe doc?");
            csubstr rs = rem.sub(1);
            if(rs == ".." || rs.begins_with(".. "))
            {
                _c4dbgp("seqblck[RNXT]: end+start doc");
                _end_doc_suddenly();
                _line_progressed(3);
                _maybe_skip_whitespace_tokens();
                goto seqblck_finish;
            }
            else
            {
                _c4err("parse error");
            }
        }
        else
        {
            // may be an indentless sequence nested in a map...
            //if(m_evt_handler->m_stack.size() >= 2)
            #ifdef RYML_DBG
            char flagbuf_[128];
            for(auto const& s : m_evt_handler->m_stack)
            {
                _dbg_printf("state[{}]: ind={} node={} flags={}\n", s.level, s.indref, s.node_id, detail::_parser_flags_to_str(flagbuf_, s.flags));
            }
            #endif
            if(m_evt_handler->m_parent && has_all(RMAP|BLCK, m_evt_handler->m_parent) && m_evt_handler->m_curr->indref == m_evt_handler->m_parent->indref)
            {
                _c4dbgpf("seqblck[RNXT]: end indentless seq, go to parent={}. node={}", m_evt_handler->m_parent->node_id, m_evt_handler->m_curr->node_id);
                _RYML_CB_ASSERT(this->callbacks(), m_evt_handler->m_curr != m_evt_handler->m_parent);
                _handle_indentation_pop(m_evt_handler->m_parent);
                _RYML_CB_ASSERT(this->callbacks(), has_all(RMAP|BLCK));
                m_evt_handler->add_sibling();
                addrem_flags(RKEY, RNXT);
                goto seqblck_finish;
            }
            else //if(first != '*')
            {
                _c4err("parse error");
            }
        }
    }

 seqblck_again:
    _c4dbgt("seqblck: go again", 0);
    if(_finished_line())
    {
        _line_ended();
        _scan_line();
        if(_finished_file())
        {
            _c4dbgp("seqblck: finish!");
            _end_seq_blck();
            goto seqblck_finish;
        }
        _c4dbgnextline();
    }
    goto seqblck_start;

 seqblck_finish:
    _c4dbgp("seqblck: finish");
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_map_block()
{
mapblck_start:
    _c4dbgpf("handle2_map_block: map_id={} node_id={} level={} indref={}", m_evt_handler->m_parent->node_id, m_evt_handler->m_curr->node_id, m_evt_handler->m_curr->level, m_evt_handler->m_curr->indref);

    // states: RKEY|QMRK -> RKCL -> RVAL -> RNXT
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(BLCK));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RKEY|RKCL|RVAL|RNXT|QMRK));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, 1 == (has_any(RKEY) + has_any(RKCL) + has_any(RVAL) + has_any(RNXT) + has_any(QMRK)));

    _maybe_skip_comment();
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(!rem.len)
        goto mapblck_again;

    if(has_any(RKEY))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        //
        // handle indentation
        //
        if(m_evt_handler->m_curr->at_line_beginning())
        {
            if(m_evt_handler->m_curr->indentation_eq())
            {
                _c4dbgpf("mapblck[RKEY]: skip {} from indref", m_evt_handler->m_curr->indref);
                _line_progressed(m_evt_handler->m_curr->indref);
                rem = m_evt_handler->m_curr->line_contents.rem;
                if(!rem.len)
                    goto mapblck_again;
            }
            else if(m_evt_handler->m_curr->indentation_lt())
            {
                _c4dbgp("mapblck[RKEY]: smaller indentation!");
                _handle_indentation_pop_from_block_map();
                _line_progressed(m_evt_handler->m_curr->line_contents.indentation);
                if(has_all(RMAP|BLCK))
                {
                    _c4dbgp("mapblck[RKEY]: still mapblck!");
                    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(RKEY));
                    rem = m_evt_handler->m_curr->line_contents.rem;
                    if(!rem.len)
                        goto mapblck_again;
                }
                else
                {
                    _c4dbgp("mapblck[RKEY]: no longer mapblck!");
                    goto mapblck_finish;
                }
            }
            else
            {
                _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->indentation_gt());
                _c4err("invalid indentation");
            }
        }
        //
        // now handle the tokens
        //
        const char first = rem.str[0];
        const size_t startline = m_evt_handler->m_curr->pos.line;
        const size_t startindent = m_evt_handler->m_curr->line_contents.current_col();
        _c4dbgpf("mapblck[RKEY]: '{}'", first);
        ScannedScalar sc;
        if(first == '\'')
        {
            _c4dbgp("mapblck[RKEY]: scanning single-quoted scalar");
            sc = _scan_scalar_squot();
            csubstr maybe_filtered = _maybe_filter_val_scalar_squot(sc);
            _handle_annotations_before_blck_key_scalar();
            m_evt_handler->set_key_scalar_squoted(maybe_filtered);
            addrem_flags(RVAL, RKEY);
            if(!_maybe_scan_following_colon())
                _c4err("could not find ':' colon after key");
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '"')
        {
            _c4dbgp("mapblck[RKEY]: scanning double-quoted scalar");
            sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_val_scalar_dquot(sc);
            _handle_annotations_before_blck_key_scalar();
            m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
            addrem_flags(RVAL, RKEY);
            if(!_maybe_scan_following_colon())
                _c4err("could not find ':' colon after key");
            _maybe_skip_whitespace_tokens();
        }
        // block scalars (| and >) can not be used as keys unless they
        // appear in an explicit QMRK scope (ie, after the ? token),
        else if(C4_UNLIKELY(first == '|'))
        {
            _c4err("block literal keys must be enclosed in '?'");
        }
        else if(C4_UNLIKELY(first == '>'))
        {
            _c4err("block literal keys must be enclosed in '?'");
        }
        else if(_scan_scalar_plain_map_blck(&sc))
        {
            _c4dbgp("mapblck[RKEY]: plain scalar");
            csubstr maybe_filtered = _maybe_filter_val_scalar_plain(sc, m_evt_handler->m_curr->indref);
            _handle_annotations_before_blck_key_scalar();
            m_evt_handler->set_key_scalar_plain(maybe_filtered);
            addrem_flags(RVAL, RKEY);
            if(!_maybe_scan_following_colon())
                _c4err("could not find ':' colon after key");
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '?')
        {
            _c4dbgp("mapblck[RKEY]: key token!");
            addrem_flags(QMRK, RKEY);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
            m_was_inside_qmrk = true;
            goto mapblck_again;
        }
        else if(first == ':')
        {
            _c4dbgp("mapblck[RKEY]: setting empty key");
            _handle_annotations_before_blck_key_scalar();
            m_evt_handler->set_key_scalar_plain({});
            addrem_flags(RVAL, RKEY);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_map();
            _c4dbgpf("mapblck[RKEY]: key ref! [{}]~~~{}~~~", ref.len, ref);
            _handle_annotations_before_blck_key_scalar();
            m_evt_handler->set_key_ref(ref);
            addrem_flags(RVAL, RKEY);
            if(!_maybe_scan_following_colon())
                _c4err("could not find ':' colon after key");
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '&')
        {
            csubstr anchor = _scan_anchor();
            _c4dbgpf("mapblck[RKEY]: key anchor! [{}]~~~{}~~~", anchor.len, anchor);
            _add_annotation(&m_pending_anchors, anchor, startindent, startline);
        }
        else if(first == '!')
        {
            csubstr tag = _scan_tag();
            _c4dbgpf("mapblck[RKEY]: key tag! [{}]~~~{}~~~", tag.len, tag);
            _add_annotation(&m_pending_tags, tag, startindent, startline);
        }
        else if(first == '[')
        {
            // RYML's tree cannot store container keys, but that's
            // handled inside the tree handler. Other handlers may be
            // able to handle it.
            _c4dbgp("mapblck[RKEY]: start child seqflow (!)");
            addrem_flags(RKCL, RKEY);
            _handle_annotations_before_blck_key_scalar();
            m_evt_handler->begin_seq_key_flow();
            addrem_flags(RSEQ|FLOW|RVAL, RMAP|BLCK|RKCL);
            _line_progressed(1);
            _set_indentation(startindent);
            goto mapblck_finish;
        }
        else if(first == '{')
        {
            // RYML's tree cannot store container keys, but that's
            // handled inside the tree handler. Other handlers may be
            // able to handle it.
            _c4dbgp("mapblck[RKEY]: start child mapflow (!)");
            addrem_flags(RKCL, RKEY);
            _handle_annotations_before_blck_key_scalar();
            m_evt_handler->begin_map_key_flow();
            addrem_flags(FLOW|RKEY, BLCK|RKCL);
            _line_progressed(1);
            _set_indentation(startindent);
            goto mapblck_finish;
        }
        else if(first == '-')
        {
            _c4dbgp("mapblck[RKEY]: maybe doc?");
            if(m_evt_handler->m_curr->line_contents.indentation == 0 && _is_doc_begin_token(rem))
            {
                _c4dbgp("mapblck[RKEY]: end+start doc");
                _start_doc_suddenly();
                _line_progressed(3);
                _maybe_skip_whitespace_tokens();
                goto mapblck_finish;
            }
            else
            {
                _c4err("parse error");
            }
        }
        else if(first == '.')
        {
            _c4dbgp("mapblck[RKEY]: maybe end doc?");
            if(m_evt_handler->m_curr->line_contents.indentation == 0 && _is_doc_end_token(rem))
            {
                _c4dbgp("mapblck[RKEY]: end doc");
                _end_doc_suddenly();
                _line_progressed(3);
                _maybe_skip_whitespace_tokens();
                goto mapblck_finish;
            }
            else
            {
                _c4err("parse error");
            }
        }
       _RYML_WITH_TAB_TOKENS(
        else if(first == '\t')
        {
            _c4dbgp("mapblck[RKEY]: skip tabs");
            _maybe_skipchars('\t');
        })
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(RKCL)) // read the key colon
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        //
        // handle indentation
        //
        if(m_evt_handler->m_curr->at_line_beginning())
        {
            if(m_evt_handler->m_curr->indentation_eq())
            {
                _c4dbgpf("mapblck[RKCL]: skip {} from indref", m_evt_handler->m_curr->indref);
                _line_progressed(m_evt_handler->m_curr->indref);
                rem = m_evt_handler->m_curr->line_contents.rem;
                if(!rem.len)
                    goto mapblck_again;
            }
            else if(C4_UNLIKELY(m_evt_handler->m_curr->indentation_lt()))
            {
                _c4err("invalid indentation");
            }
        }
        const char first = rem.str[0];
        _c4dbgpf("mapblck[RKCL]: '{}'", first);
        if(first == ':')
        {
            _c4dbgp("mapblck[RKCL]: found the colon");
            addrem_flags(RVAL, RKCL);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '?')
        {
            _c4dbgp("mapblck[RKCL]: got '?'. val was empty");
            _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, m_was_inside_qmrk);
            m_evt_handler->set_val_scalar_plain({});
            m_evt_handler->add_sibling();
            addrem_flags(QMRK, RKCL);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '-')
        {
            if(m_evt_handler->m_curr->indref == 0 || m_evt_handler->m_curr->line_contents.indentation == 0 || _is_doc_begin_token(rem))
            {
                _c4dbgp("mapblck[RKCL]: end+start doc");
                _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, _is_doc_begin_token(rem));
                _start_doc_suddenly();
                _line_progressed(3);
                _maybe_skip_whitespace_tokens();
                goto mapblck_finish;
            }
            else
            {
                _c4err("parse error");
            }
        }
        else if(first == '.')
        {
            _c4dbgp("mapblck[RKCL]: maybe end doc?");
            csubstr rs = rem.sub(1);
            if(rs == ".." || rs.begins_with(".. "))
            {
                _c4dbgp("mapblck[RKCL]: end+start doc");
                _end_doc_suddenly();
                _line_progressed(3);
                goto mapblck_finish;
            }
            else
            {
                _c4err("parse error");
            }
        }
        else if(m_was_inside_qmrk)
        {
            _RYML_CB_CHECK(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->indentation_eq());
            _c4dbgp("mapblck[RKCL]: missing :");
            m_evt_handler->set_val_scalar_plain({});
            m_evt_handler->add_sibling();
            m_was_inside_qmrk = false;
            addrem_flags(RKEY, RKCL);
        }
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(RVAL))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        //
        // handle indentation
        //
        if(m_evt_handler->m_curr->at_line_beginning())
        {
            _c4dbgpf("mapblck[RVAL]: indref={} indentation={}", m_evt_handler->m_curr->indref, m_evt_handler->m_curr->line_contents.indentation);
            m_evt_handler->m_curr->more_indented = false;
            if(m_evt_handler->m_curr->indref == npos)
            {
                _c4dbgpf("mapblck[RVAL]: setting indentation={}", m_evt_handler->m_parent->indref);
                _set_indentation(m_evt_handler->m_curr->line_contents.indentation);
                _line_progressed(m_evt_handler->m_curr->indref);
                rem = m_evt_handler->m_curr->line_contents.rem;
                if(!rem.len)
                    goto mapblck_again;
            }
            else if(m_evt_handler->m_curr->indentation_eq())
            {
                _c4dbgp("mapblck[RVAL]: skip indentation!");
                _line_progressed(m_evt_handler->m_curr->indref);
                rem = m_evt_handler->m_curr->line_contents.rem;
                if(!rem.len)
                    goto mapblck_again;
                // TODO: this is valid:
                //
                // ```yaml
                // a:
                // b:
                // ---
                // a:
                //  b
                // ---
                // a:
                //  b: c
                // ```
                //
                // ... but this is not:
                //
                // ```yaml
                // a:
                // v
                // ---
                // a: b: c
                // ```
                //
                // here, we probably need to set a boolean on the state
                // to disambiguate between these cases.
            }
            else if(m_evt_handler->m_curr->indentation_gt())
            {
                _c4dbgp("mapblck[RVAL]: more indented!");
                m_evt_handler->m_curr->more_indented = true;
                _line_progressed(m_evt_handler->m_curr->line_contents.indentation);
                rem = m_evt_handler->m_curr->line_contents.rem;
                if(!rem.len)
                    goto mapblck_again;
            }
            else if(m_evt_handler->m_curr->indentation_lt())
            {
                _c4dbgp("mapblck[RVAL]: smaller indentation!");
                _handle_indentation_pop_from_block_map();
                if(has_all(RMAP|BLCK))
                {
                    _c4dbgp("mapblck[RVAL]: still mapblck!");
                    _line_progressed(m_evt_handler->m_curr->line_contents.indentation);
                    if(has_any(RNXT))
                    {
                        _c4dbgp("mapblck[RVAL]: speculatively expect next keyval");
                        m_evt_handler->add_sibling();
                        addrem_flags(RKEY, RNXT);
                    }
                    goto mapblck_again;
                }
                else
                {
                    _c4dbgp("mapblck[RVAL]: no longer mapblck!");
                    goto mapblck_finish;
                }
            }
            else if(m_evt_handler->m_curr->line_contents.indentation == npos)
            {
                _c4dbgp("mapblck[RVAL]: empty line!");
                _line_progressed(m_evt_handler->m_curr->line_contents.rem.len);
                goto mapblck_again;
            }
        }
        //
        // now handle the tokens
        //
        const char first = rem.str[0];
        const size_t startline = m_evt_handler->m_curr->pos.line;
        const size_t startindent = m_evt_handler->m_curr->line_contents.current_col();
        _c4dbgpf("mapblck[RVAL]: '{}'", first);
        ScannedScalar sc;
        if(first == '\'')
        {
            _c4dbgp("mapblck[RVAL]: scanning single-quoted scalar");
            sc = _scan_scalar_squot();
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("mapblck[RVAL]: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_squot(sc); // VAL!
                m_evt_handler->set_val_scalar_squoted(maybe_filtered);
                addrem_flags(RNXT, RVAL);
            }
            else
            {
                if(startindent != m_evt_handler->m_curr->indref)
                {
                    _c4dbgp("mapblck[RVAL]: start new block map, set scalar as key");
                    _handle_annotations_before_start_mapblck(startline);
                    addrem_flags(RNXT, RVAL);
                    m_evt_handler->begin_map_val_block();
                    _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                    csubstr maybe_filtered = _maybe_filter_key_scalar_squot(sc); // KEY!
                    m_evt_handler->set_key_scalar_squoted(maybe_filtered);
                    _maybe_skip_whitespace_tokens();
                    _set_indentation(m_evt_handler->m_curr->line_contents.indentation);
                    // keep the child state on RVAL
                    addrem_flags(RVAL, RNXT);
                }
                else
                {
                    _c4dbgp("mapblck[RVAL]: prev val empty+this is a key");
                    m_evt_handler->set_val_scalar_plain({});
                    m_evt_handler->add_sibling();
                    csubstr maybe_filtered = _maybe_filter_key_scalar_squot(sc); // KEY!
                    m_evt_handler->set_key_scalar_squoted(maybe_filtered);
                    // keep going on RVAL
                    _maybe_skip_whitespace_tokens();
                }
            }
        }
        else if(first == '"')
        {
            _c4dbgp("mapblck[RVAL]: scanning double-quoted scalar");
            sc = _scan_scalar_dquot();
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("mapblck[RVAL]: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_dquot(sc); // VAL!
                m_evt_handler->set_val_scalar_dquoted(maybe_filtered);
                addrem_flags(RNXT, RVAL);
            }
            else
            {
                if(startindent != m_evt_handler->m_curr->indref)
                {
                    _c4dbgp("mapblck[RVAL]: start new block map, set scalar as key");
                    _handle_annotations_before_start_mapblck(startline);
                    addrem_flags(RNXT, RVAL);
                    m_evt_handler->begin_map_val_block();
                    _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                    csubstr maybe_filtered = _maybe_filter_key_scalar_dquot(sc); // KEY!
                    m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
                    _maybe_skip_whitespace_tokens();
                    _set_indentation(m_evt_handler->m_curr->line_contents.indentation);
                    // keep the child state on RVAL
                    addrem_flags(RVAL, RNXT);
                }
                else
                {
                    _c4dbgp("mapblck[RVAL]: prev val empty+this is a key");
                    m_evt_handler->set_val_scalar_plain({});
                    m_evt_handler->add_sibling();
                    csubstr maybe_filtered = _maybe_filter_key_scalar_dquot(sc); // KEY!
                    m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
                    // keep going on RVAL
                    _maybe_skip_whitespace_tokens();
                }
            }
        }
        // block scalars can only appear as keys when in QMRK scope
        // (ie, after ? tokens), so no need to scan following colon
        else if(first == '|')
        {
            _c4dbgp("mapblck[RVAL]: scanning block-literal scalar");
            ScannedBlock sb;
            _scan_block(&sb, m_evt_handler->m_curr->indref + 1);
            _handle_annotations_before_blck_val_scalar();
            csubstr maybe_filtered = _maybe_filter_val_scalar_literal(sb);
            m_evt_handler->set_val_scalar_literal(maybe_filtered);
            addrem_flags(RNXT, RVAL);
        }
        else if(first == '>')
        {
            _c4dbgp("mapblck[RVAL]: scanning block-folded scalar");
            ScannedBlock sb;
            _scan_block(&sb, m_evt_handler->m_curr->indref + 1);
            _handle_annotations_before_blck_val_scalar();
            csubstr maybe_filtered = _maybe_filter_val_scalar_folded(sb);
            m_evt_handler->set_val_scalar_folded(maybe_filtered);
            addrem_flags(RNXT, RVAL);
        }
        else if(_scan_scalar_plain_map_blck(&sc))
        {
            _c4dbgp("mapblck[RVAL]: plain scalar.");
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("mapblck[RVAL]: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_plain(sc, m_evt_handler->m_curr->indref); // VAL!
                m_evt_handler->set_val_scalar_plain(maybe_filtered);
                addrem_flags(RNXT, RVAL);
            }
            else
            {
                if(startindent != m_evt_handler->m_curr->indref)
                {
                    _c4dbgpf("mapblck[RVAL]: start new block map, set scalar as key {}", m_evt_handler->m_curr->indref);
                    addrem_flags(RNXT, RVAL);
                    _handle_annotations_before_start_mapblck(startline);
                    m_evt_handler->begin_map_val_block();
                    _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                    csubstr maybe_filtered = _maybe_filter_key_scalar_plain(sc, m_evt_handler->m_curr->indref); // KEY!
                    m_evt_handler->set_key_scalar_plain(maybe_filtered);
                    _maybe_skip_whitespace_tokens();
                    _set_indentation(m_evt_handler->m_curr->line_contents.indentation);
                    // keep the child state on RVAL
                    addrem_flags(RVAL, RNXT);
                }
                else
                {
                    _c4dbgp("mapblck[RVAL]: prev val empty+this is a key");
                    _handle_annotations_before_blck_val_scalar();
                    m_evt_handler->set_val_scalar_plain({});
                    m_evt_handler->add_sibling();
                    csubstr maybe_filtered = _maybe_filter_key_scalar_plain(sc, m_evt_handler->m_curr->indref); // KEY!
                    m_evt_handler->set_key_scalar_plain(maybe_filtered);
                    // keep going on RVAL
                    _maybe_skip_whitespace_tokens();
                }
            }
        }
        else if(first == '-')
        {
            if(rem.len == 1 || rem.str[1] == ' ' _RYML_WITH_TAB_TOKENS(|| rem.str[1] == '\t'))
            {
                _c4dbgp("mapblck[RVAL]: start val seqblck");
                addrem_flags(RNXT, RVAL);
                _handle_annotations_before_blck_val_scalar();
                m_evt_handler->begin_seq_val_block();
                addrem_flags(RSEQ|RVAL, RMAP|RNXT);
                _set_indentation(startindent);
                _line_progressed(1);
                _maybe_skip_whitespace_tokens();
                goto mapblck_finish;
            }
            else if(m_evt_handler->m_curr->indref == 0 || m_evt_handler->m_curr->line_contents.indentation == 0 || _is_doc_begin_token(rem))
            {
                _c4dbgp("mapblck[RVAL]: end+start doc");
                _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, _is_doc_begin_token(rem));
                _start_doc_suddenly();
                _line_progressed(3);
                _maybe_skip_whitespace_tokens();
                goto mapblck_finish;
            }
            else
            {
                _c4err("parse error");
            }
        }
        else if(first == '[')
        {
            _c4dbgp("mapblck[RVAL]: start val seqflow");
            addrem_flags(RNXT, RVAL);
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->begin_seq_val_flow();
            addrem_flags(RSEQ|FLOW|RVAL, RMAP|BLCK|RNXT|BLCK);
            _set_indentation(m_evt_handler->m_curr->indref + 1u);
            _line_progressed(1);
            goto mapblck_finish;
        }
        else if(first == '{')
        {
            _c4dbgp("mapblck[RVAL]: start val mapflow");
            addrem_flags(RNXT, RVAL);
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->begin_map_val_flow();
            addrem_flags(RKEY|FLOW, BLCK|RVAL|RNXT);
            m_evt_handler->m_curr->scalar_col = m_evt_handler->m_curr->line_contents.indentation;
            _set_indentation(m_evt_handler->m_curr->indref + 1u);
            _line_progressed(1);
            goto mapblck_finish;
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_map();
            _c4dbgpf("mapblck[RVAL]: ref! [{}]~~~{}~~~", ref.len, ref);
            if(startindent == m_evt_handler->m_curr->indref)
            {
                _c4dbgpf("mapblck[RVAL]: same indentation {}", startindent);
                m_evt_handler->set_val_ref(ref);
                addrem_flags(RNXT, RVAL);
            }
            else
            {
                _c4dbgpf("mapblck[RVAL]: larger indentation {}>{}", startindent, m_evt_handler->m_curr->indref);
                _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, startindent > m_evt_handler->m_curr->indref);
                if(_maybe_scan_following_colon())
                {
                    _c4dbgp("mapblck[RVAL]: start child map, block");
                    addrem_flags(RNXT, RVAL);
                    _handle_annotations_before_blck_val_scalar();
                    m_evt_handler->begin_map_val_block();
                    m_evt_handler->set_key_ref(ref);
                    _set_indentation(startindent);
                    // keep going in RVAL
                    addrem_flags(RVAL, RNXT);
                }
                else
                {
                    _c4dbgp("mapblck[RVAL]: was val ref");
                    _handle_annotations_before_blck_val_scalar();
                    m_evt_handler->set_val_ref(ref);
                    addrem_flags(RNXT, RVAL);
                }
            }
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '&')
        {
            csubstr anchor = _scan_anchor();
            _c4dbgpf("mapblck[RVAL]: anchor! [{}]~~~{}~~~", anchor.len, anchor);
            if(startindent == m_evt_handler->m_curr->indref)
            {
                _c4dbgp("mapblck[RVAL]: anchor for next key. val is missing!");
                m_evt_handler->set_val_scalar_plain({});
                m_evt_handler->add_sibling();
                addrem_flags(RKEY, RVAL);
            }
            // we need to buffer the anchors, as there may be two
            // consecutive anchors in here
            _add_annotation(&m_pending_anchors, anchor, startindent, startline);
        }
        else if(first == '!')
        {
            csubstr tag = _scan_tag();
            _c4dbgpf("mapblck[RVAL]: tag! [{}]~~~{}~~~", tag.len, tag);
            if(startindent == m_evt_handler->m_curr->indref)
            {
                _c4dbgp("mapblck[RVAL]: tag for next key. val is missing!");
                _handle_annotations_before_blck_val_scalar();
                m_evt_handler->set_val_scalar_plain({});
                m_evt_handler->add_sibling();
                addrem_flags(RKEY, RVAL);
            }
            // we need to buffer the tags, as there may be two
            // consecutive tags in here
            _add_annotation(&m_pending_tags, tag, startindent, startline);
        }
        else if(first == '?')
        {
            if(startindent == m_evt_handler->m_curr->indref)
            {
                _c4dbgp("mapblck[RVAL]: got '?'. val was empty");
                _handle_annotations_before_blck_val_scalar();
                m_evt_handler->set_val_scalar_plain({});
                m_evt_handler->add_sibling();
                addrem_flags(QMRK, RVAL);
            }
            else if(startindent > m_evt_handler->m_curr->indref)
            {
                _c4dbgp("mapblck[RVAL]: start val mapblck");
                addrem_flags(RNXT, RVAL);
                _handle_annotations_before_blck_val_scalar();
                m_evt_handler->begin_map_val_block();
                addrem_flags(QMRK|BLCK, RNXT);
                _set_indentation(startindent);
            }
            else
            {
                _c4err("parse error");
            }
            m_was_inside_qmrk = true;
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
            goto mapblck_again;
        }
        else if(first == ':')
        {
            if(startindent == m_evt_handler->m_curr->indref)
            {
                _c4dbgp("mapblck[RVAL]: got ':'. val was empty, next key as well");
                m_evt_handler->set_val_scalar_plain({});
                m_evt_handler->add_sibling();
                m_evt_handler->set_key_scalar_plain({});
                _line_progressed(1);
                _maybe_skip_whitespace_tokens();
                goto mapblck_again;
            }
            else
            {
                _c4err("parse error");
            }
        }
        else if(first == '.')
        {
            _c4dbgp("mapblck[RVAL]: maybe doc?");
            csubstr rs = rem.sub(1);
            if(rs == ".." || rs.begins_with(".. "))
            {
                _c4dbgp("seqblck[RVAL]: end doc expl");
                _end_doc_suddenly();
                _line_progressed(3);
                _maybe_skip_whitespace_tokens();
                goto mapblck_finish;
            }
            else
            {
                _c4err("parse error");
            }
        }
       _RYML_WITH_TAB_TOKENS(
        else if(first == '\t')
        {
            _c4dbgp("mapblck[RVAL]: skip tabs");
            _maybe_skipchars('\t');
        })
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(RNXT))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(QMRK));
        //
        // handle indentation
        //
        if(m_evt_handler->m_curr->at_line_beginning())
        {
            _c4dbgpf("mapblck[RNXT]: indref={} indentation={}", m_evt_handler->m_curr->indref, m_evt_handler->m_curr->line_contents.indentation);
            if(m_evt_handler->m_curr->indentation_eq())
            {
                _c4dbgpf("mapblck[RNXT]: skip {} from indref", m_evt_handler->m_curr->indref);
                _line_progressed(m_evt_handler->m_curr->indref);
                _c4dbgp("mapblck[RNXT]: speculatively expect next keyval");
                m_evt_handler->add_sibling();
                addrem_flags(RKEY, RNXT);
                goto mapblck_again;
            }
            else if(m_evt_handler->m_curr->indentation_lt())
            {
                _c4dbgp("mapblck[RNXT]: smaller indentation!");
                _handle_indentation_pop_from_block_map();
                if(has_all(RMAP|BLCK))
                {
                    _line_progressed(m_evt_handler->m_curr->line_contents.indentation);
                    if(!has_any(RKCL))
                    {
                        _c4dbgp("mapblck[RNXT]: speculatively expect next keyval");
                        m_evt_handler->add_sibling();
                        addrem_flags(RKEY, RNXT);
                    }
                    goto mapblck_again;
                }
                else
                {
                    goto mapblck_finish;
                }
            }
        }
        //
        // handle tokens
        //
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, rem.len > 0);
        const char first = rem.str[0];
        _c4dbgpf("mapblck[RNXT]: '{}'", _c4prc(first));
        if(first == ':')
        {
            if(m_evt_handler->m_curr->more_indented)
            {
                _c4dbgp("mapblck[RNXT]: start child block map");
                C4_NOT_IMPLEMENTED();
                //m_evt_handler->actually_as_block_map();
                _line_progressed(1);
                _set_indentation(m_evt_handler->m_curr->scalar_col);
                m_evt_handler->m_curr->more_indented = false;
                goto mapblck_again;
            }
            else
            {
                _c4err("parse error");
            }
        }
        else if(first == ' ')
        {
            _c4dbgp("mapblck[RNXT]: skip spaces");
            _maybe_skip_whitespace_tokens();
        }
        else
        {
            _c4err("parse error");
        }
    }
    else if(has_any(QMRK))
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKEY));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RKCL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RVAL));
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT));
        //
        // handle indentation
        //
        if(m_evt_handler->m_curr->at_line_beginning())
        {
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_curr->line_contents.indentation != npos);
            if(m_evt_handler->m_curr->indentation_eq())
            {
                _c4dbgpf("mapblck[QMRK]: skip {} from indref", m_evt_handler->m_curr->indref);
                _line_progressed(m_evt_handler->m_curr->indref);
                rem = m_evt_handler->m_curr->line_contents.rem;
                if(!rem.len)
                    goto mapblck_again;
            }
            else if(m_evt_handler->m_curr->indentation_lt())
            {
                _c4dbgp("mapblck[QMRK]: smaller indentation!");
                _handle_indentation_pop_from_block_map();
                _line_progressed(m_evt_handler->m_curr->line_contents.indentation);
                if(has_all(RMAP|BLCK))
                {
                    _c4dbgp("mapblck[QMRK]: still mapblck!");
                    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_any(QMRK));
                    rem = m_evt_handler->m_curr->line_contents.rem;
                    if(!rem.len)
                        goto mapblck_again;
                }
                else
                {
                    _c4dbgp("mapblck[QMRK]: no longer mapblck!");
                    goto mapblck_finish;
                }
            }
            // indentation can be larger in QMRK state
            else
            {
                _c4dbgp("mapblck[QMRK]: larger indentation !");
                _line_progressed(m_evt_handler->m_curr->line_contents.indentation);
                rem = m_evt_handler->m_curr->line_contents.rem;
                if(!rem.len)
                    goto mapblck_again;
            }
        }
        //
        // now handle the tokens
        //
        const char first = rem.str[0];
        const size_t startline = m_evt_handler->m_curr->pos.line;
        const size_t startindent = m_evt_handler->m_curr->line_contents.current_col();
        _c4dbgpf("mapblck[QMRK]: '{}'", first);
        ScannedScalar sc;
        if(first == '\'')
        {
            _c4dbgp("mapblck[QMRK]: scanning single-quoted scalar");
            sc = _scan_scalar_squot();
            csubstr maybe_filtered = _maybe_filter_key_scalar_squot(sc); // KEY!
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("mapblck[QMRK]: set as key");
                _handle_annotations_before_blck_key_scalar();
                m_evt_handler->set_key_scalar_squoted(maybe_filtered);
                addrem_flags(RKCL, QMRK);
            }
            else
            {
                _c4dbgp("mapblck[QMRK]: start new block map as key (!), set scalar as key");
                addrem_flags(RKCL, QMRK);
                _handle_annotations_before_start_mapblck_as_key();
                m_evt_handler->begin_map_key_block();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                m_evt_handler->set_key_scalar_squoted(maybe_filtered);
                _maybe_skip_whitespace_tokens();
                _set_indentation(startindent);
                // keep the child state on RVAL
                addrem_flags(RVAL, RKCL|QMRK);
            }
        }
        else if(first == '"')
        {
            _c4dbgp("mapblck[QMRK]: scanning double-quoted scalar");
            sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_key_scalar_dquot(sc); // KEY!
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("mapblck[QMRK]: set as key");
                _handle_annotations_before_blck_key_scalar();
                m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
                addrem_flags(RKCL, QMRK);
            }
            else
            {
                _c4dbgp("mapblck[QMRK]: start new block map as key (!), set scalar as key");
                addrem_flags(RKCL, QMRK);
                _handle_annotations_before_start_mapblck_as_key();
                m_evt_handler->begin_map_key_block();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
                _maybe_skip_whitespace_tokens();
                _set_indentation(startindent);
                // keep the child state on RVAL
                addrem_flags(RVAL, RKCL|QMRK);
            }
        }
        else if(first == '|')
        {
            _c4dbgp("mapblck[QMRK]: scanning block-literal scalar");
            ScannedBlock sb;
            _scan_block(&sb, m_evt_handler->m_curr->indref + 1);
            csubstr maybe_filtered = _maybe_filter_key_scalar_literal(sb); // KEY!
            _handle_annotations_before_blck_key_scalar();
            m_evt_handler->set_key_scalar_literal(maybe_filtered);
            addrem_flags(RKCL, QMRK);
        }
        else if(first == '>')
        {
            _c4dbgp("mapblck[QMRK]: scanning block-literal scalar");
            ScannedBlock sb;
            _scan_block(&sb, m_evt_handler->m_curr->indref + 1);
            csubstr maybe_filtered = _maybe_filter_key_scalar_folded(sb); // KEY!
            _handle_annotations_before_blck_key_scalar();
            m_evt_handler->set_key_scalar_folded(maybe_filtered);
            addrem_flags(RKCL, QMRK);
        }
        else if(_scan_scalar_plain_map_blck(&sc))
        {
            _c4dbgp("mapblck[QMRK]: plain scalar");
            csubstr maybe_filtered = _maybe_filter_key_scalar_plain(sc, m_evt_handler->m_curr->indref); // KEY!
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("mapblck[QMRK]: set as key");
                _handle_annotations_before_blck_key_scalar();
                m_evt_handler->set_key_scalar_plain(maybe_filtered);
                addrem_flags(RKCL, QMRK);
            }
            else
            {
                _c4dbgp("mapblck[QMRK]: start new block map as key (!), set scalar as key");
                addrem_flags(RKCL, QMRK);
                _handle_annotations_before_start_mapblck_as_key();
                m_evt_handler->begin_map_key_block();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                m_evt_handler->set_key_scalar_plain(maybe_filtered);
                _maybe_skip_whitespace_tokens();
                _set_indentation(startindent);
                // keep the child state on RVAL
                addrem_flags(RVAL, RKCL|QMRK);
            }
        }
        else if(first == ':')
        {
            if(startindent == m_evt_handler->m_curr->indref)
            {
                _c4dbgp("mapblck[QMRK]: empty key");
                addrem_flags(RVAL, QMRK);
                _handle_annotations_before_blck_key_scalar();
                m_evt_handler->set_key_scalar_plain({});
                _line_progressed(1);
                _maybe_skip_whitespace_tokens();
            }
            else
            {
                _c4dbgp("mapblck[QMRK]: start new block map as key (!), empty key");
                addrem_flags(RKCL, QMRK);
                _handle_annotations_before_start_mapblck_as_key();
                m_evt_handler->begin_map_key_block();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                m_evt_handler->set_key_scalar_plain({});
                _line_progressed(1);
                _maybe_skip_whitespace_tokens();
                _set_indentation(startindent);
                // keep the child state on RVAL
                addrem_flags(RVAL, RKCL|QMRK);
            }
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_map();
            _c4dbgpf("mapblck[QMRK]: key ref! [{}]~~~{}~~~", ref.len, ref);
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("mapblck[QMRK]: set ref as key");
                _handle_annotations_before_blck_key_scalar();
                m_evt_handler->set_key_ref(ref);
                addrem_flags(RKCL, QMRK);
            }
            else
            {
                _c4dbgp("mapblck[QMRK]: start new block map as key (!), set ref as key");
                addrem_flags(RKCL, QMRK);
                _handle_annotations_before_blck_key_scalar();
                m_evt_handler->begin_map_key_block();
                m_evt_handler->set_key_ref(ref);
                _set_indentation(startindent);
                // keep the child state on RVAL
                addrem_flags(RVAL, RKCL|QMRK);
            }
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '&')
        {
            csubstr anchor = _scan_anchor();
            _c4dbgpf("mapblck[QMRK]: key anchor! [{}]~~~{}~~~", anchor.len, anchor);
            _add_annotation(&m_pending_anchors, anchor, startindent, startline);
        }
        else if(first == '!')
        {
            csubstr tag = _scan_tag();
            _c4dbgpf("mapblck[QMRK]: key tag! [{}]~~~{}~~~", tag.len, tag);
            _add_annotation(&m_pending_tags, tag, startindent, startline);
        }
        else if(first == '-')
        {
            _c4dbgp("mapblck[QMRK]: maybe doc?");
            csubstr rs = rem.sub(1);
            if(rs == "--" || rs.begins_with("-- "))
            {
                _c4dbgp("mapblck[QMRK]: end+start doc");
                _start_doc_suddenly();
                _line_progressed(3);
            }
            else
            {
                _c4dbgp("mapblck[QMRK]: start child seqblck (!)");
                addrem_flags(RKCL, RKEY|QMRK);
                m_evt_handler->begin_seq_key_block();
                addrem_flags(RVAL|RSEQ, RMAP|RKCL|QMRK);
                _set_indentation(startindent);
                _line_progressed(1);
            }
            _maybe_skip_whitespace_tokens();
            goto mapblck_finish;
        }
        else if(first == '[')
        {
            _c4dbgp("mapblck[QMRK]: start child seqflow (!)");
            addrem_flags(RKCL, RKEY|QMRK);
            m_evt_handler->begin_seq_key_flow();
            addrem_flags(RVAL|RSEQ|FLOW, RMAP|RKCL|QMRK|BLCK);
            _set_indentation(m_evt_handler->m_parent->indref);
            _line_progressed(1);
            goto mapblck_finish;
        }
        else if(first == '{')
        {
            _c4dbgp("mapblck[QMRK]: start child mapblck (!)");
            addrem_flags(RKCL, RKEY|QMRK);
            m_evt_handler->begin_map_key_flow();
            addrem_flags(RKEY|FLOW, RVAL|RKCL|QMRK|BLCK);
            _set_indentation(m_evt_handler->m_parent->indref);
            _line_progressed(1);
            goto mapblck_finish;
        }
        else if(first == '?')
        {
            _c4dbgp("mapblck[QMRK]: another QMRK '?'");
            m_evt_handler->set_key_scalar_plain({});
            m_evt_handler->set_val_scalar_plain({});
            m_evt_handler->add_sibling();
            _line_progressed(1);
        }
        else if(first == '.')
        {
            _c4dbgp("mapblck[QMRK]: maybe end doc?");
            csubstr rs = rem.sub(1);
            if(rs == ".." || rs.begins_with(".. "))
            {
                _c4dbgp("mapblck[QMRK]: end+start doc");
                _end_doc_suddenly();
                _line_progressed(3);
                goto mapblck_finish;
            }
            else
            {
                _c4err("parse error");
            }
        }
        else
        {
            _c4err("parse error");
        }
    }

 mapblck_again:
    _c4dbgt("mapblck: again", 0);
    if(_finished_line())
    {
        _line_ended();
        _scan_line();
        if(_finished_file())
        {
            _c4dbgp("mapblck: file finished!");
            _end_map_blck();
            goto mapblck_finish;
        }
        _c4dbgnextline();
    }
    goto mapblck_start;

 mapblck_finish:
    _c4dbgp("mapblck: finish");
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_unk_json()
{
    _c4dbgpf("handle_unk_json indref={} target={}", m_evt_handler->m_curr->indref, m_evt_handler->m_curr->node_id);

    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT|RSEQ|RMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RTOP));

    _maybe_skip_comment();
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(!rem.len)
        return;

    size_t pos = rem.first_not_of(" \t");
    if(pos)
    {
        pos = pos != npos ? pos : rem.len;
        _c4dbgpf("skipping indentation of {}", pos);
        _line_progressed(pos);
        rem = m_evt_handler->m_curr->line_contents.rem;
        if(!rem.len)
            return;
        _c4dbgpf("rem is now [{}]~~~{}~~~", rem.len, rem);
    }

    if(rem.begins_with('['))
    {
        _c4dbgp("it's a seq");
        m_evt_handler->check_trailing_doc_token();
        _maybe_begin_doc();
        m_evt_handler->begin_seq_val_flow();
        addrem_flags(RSEQ|FLOW|RVAL, RUNK|RTOP|RDOC);
        _set_indentation(m_evt_handler->m_curr->line_contents.current_col(rem));
        m_doc_empty = false;
        _line_progressed(1);
    }
    else if(rem.begins_with('{'))
    {
        _c4dbgp("it's a map");
        m_evt_handler->check_trailing_doc_token();
        _maybe_begin_doc();
        m_evt_handler->begin_map_val_flow();
        addrem_flags(RMAP|FLOW|RKEY, RVAL|RTOP|RUNK|RDOC);
        m_doc_empty = false;
        _set_indentation(m_evt_handler->m_curr->line_contents.current_col(rem));
        _line_progressed(1);
    }
    else
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks,  ! has_any(SSCL));
        _maybe_skip_whitespace_tokens();
        csubstr s = m_evt_handler->m_curr->line_contents.rem;
        if(!s.len)
            return;
        const size_t startindent = m_evt_handler->m_curr->line_contents.indentation; // save
        const char first = s.str[0];
        ScannedScalar sc;
        if(first == '"')
        {
            _c4dbgp("runk_json: scanning double-quoted scalar");
            m_evt_handler->check_trailing_doc_token();
            _maybe_begin_doc();
            add_flags(RDOC);
            m_doc_empty = false;
            sc = _scan_scalar_dquot();
            csubstr maybe_filtered = _maybe_filter_val_scalar_dquot(sc);
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("runk_json: set as val");
                _handle_annotations_before_blck_val_scalar();
                m_evt_handler->set_val_scalar_dquoted(maybe_filtered);
            }
            else
            {
                _c4err("parse error");
            }
        }
        else if(_scan_scalar_plain_unk(&sc))
        {
            _c4dbgp("runk_json: got a plain scalar");
            m_evt_handler->check_trailing_doc_token();
            _maybe_begin_doc();
            add_flags(RDOC);
            m_doc_empty = false;
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("runk_json: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_plain(sc, startindent);
                m_evt_handler->set_val_scalar_plain(maybe_filtered);
            }
            else
            {
                _c4err("parse error");
            }
        }
        else
        {
            _c4err("parse error");
        }
    }
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::_handle_unk()
{
    _c4dbgpf("handle_unk indref={} target={}", m_evt_handler->m_curr->indref, m_evt_handler->m_curr->node_id);

    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(RNXT|RSEQ|RMAP));
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RTOP));

    _maybe_skip_comment();
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(!rem.len)
        return;

    size_t pos = rem.first_not_of(" \t");
    if(pos)
    {
        pos = pos != npos ? pos : rem.len;
        _c4dbgpf("skipping {} whitespace characters", pos);
        _line_progressed(pos);
        rem = m_evt_handler->m_curr->line_contents.rem;
        if(!rem.len)
            return;
        _c4dbgpf("rem is now [{}]~~~{}~~~", rem.len, rem);
    }

    if(m_evt_handler->m_curr->line_contents.indentation == 0u && _at_line_begin())
    {
        const char first = rem.str[0];
        _c4dbgp("rtop: zero indent + at line begin");
        if(first == '-')
        {
            _c4dbgp("rtop: suspecting doc");
            if(_is_doc_begin_token(rem))
            {
                _c4dbgp("rtop: begin doc");
                _maybe_end_doc();
                _begin2_doc_expl();
                _set_indentation(0);
                addrem_flags(RDOC|RUNK, NDOC);
                _line_progressed(3u);
                _maybe_skip_whitespace_tokens();
                return;
            }
        }
        else if(first == '.')
        {
            _c4dbgp("rtop: suspecting doc end");
            if(_is_doc_end_token(rem))
            {
                _c4dbgp("rtop: end doc");
                if(has_any(RDOC))
                {
                    _end2_doc_expl();
                }
                else
                {
                    _c4dbgp("rtop: ignore end doc");
                }
                addrem_flags(NDOC|RUNK, RDOC);
                _line_progressed(3u);
                _maybe_skip_whitespace_tokens();
                return;
            }
        }
        else if(first == '%')
        {
            _c4dbgpf("directive: {}", rem);
            if(C4_UNLIKELY(!m_doc_empty && has_none(NDOC)))
                _RYML_CB_ERR(m_evt_handler->m_stack.m_callbacks, "need document footer before directives");
            _handle_directive(rem);
            return;
        }
    }

    /* no else-if! */
    char first = rem.str[0];

    if(first == '[')
    {
        m_evt_handler->check_trailing_doc_token();
        _maybe_begin_doc();
        m_doc_empty = false;
        const size_t startindent = m_evt_handler->m_curr->line_contents.current_col(rem);
        if(C4_LIKELY( ! _annotations_require_key_container()))
        {
            _c4dbgp("it's a seq, flow");
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->begin_seq_val_flow();
            addrem_flags(RSEQ|FLOW|RVAL, RUNK|RTOP|RDOC);
            _set_indentation(startindent);
        }
        else
        {
            _c4dbgp("start new block map, set flow seq as key (!)");
            _handle_annotations_before_start_mapblck(m_evt_handler->m_curr->pos.line);
            m_evt_handler->begin_map_val_block();
            addrem_flags(RMAP|BLCK|RKCL, RUNK|RTOP|RDOC);
            _handle_annotations_and_indentation_after_start_mapblck(startindent, m_evt_handler->m_curr->pos.line);
            m_evt_handler->begin_seq_key_flow();
            addrem_flags(RSEQ|FLOW|RVAL, RMAP|BLCK|RKCL);
            _set_indentation(startindent);
        }
        _line_progressed(1);
    }
    else if(first == '{')
    {
        m_evt_handler->check_trailing_doc_token();
        _maybe_begin_doc();
        m_doc_empty = false;
        const size_t startindent = m_evt_handler->m_curr->line_contents.current_col(rem);
        if(C4_LIKELY( ! _annotations_require_key_container()))
        {
            _c4dbgp("it's a map, flow");
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->begin_map_val_flow();
            addrem_flags(RMAP|FLOW|RKEY, RVAL|RTOP|RUNK|RDOC);
            _set_indentation(startindent);
        }
        else
        {
            _c4dbgp("start new block map, set flow map as key (!)");
            _handle_annotations_before_start_mapblck(m_evt_handler->m_curr->pos.line);
            m_evt_handler->begin_map_val_block();
            addrem_flags(RMAP|BLCK|RKCL, RUNK|RTOP|RDOC);
            _handle_annotations_and_indentation_after_start_mapblck(startindent, m_evt_handler->m_curr->pos.line);
            m_evt_handler->begin_map_key_flow();
            addrem_flags(RMAP|FLOW|RKEY, BLCK|RKCL);
            _set_indentation(startindent);
        }
        _line_progressed(1);
    }
    else if(first == '-' && _is_blck_token(rem))
    {
        _c4dbgp("it's a seq, block");
        m_evt_handler->check_trailing_doc_token();
        _maybe_begin_doc();
        _handle_annotations_before_blck_val_scalar();
        m_evt_handler->begin_seq_val_block();
        addrem_flags(RSEQ|BLCK|RVAL, RNXT|RTOP|RUNK|RDOC);
        m_doc_empty = false;
        _set_indentation(m_evt_handler->m_curr->line_contents.current_col(rem));
        _line_progressed(1);
        _maybe_skip_whitespace_tokens();
    }
    else if(first == '?' && _is_blck_token(rem))
    {
        _c4dbgp("it's a map + this key is complex");
        m_evt_handler->check_trailing_doc_token();
        _maybe_begin_doc();
        _handle_annotations_before_blck_val_scalar();
        m_evt_handler->begin_map_val_block();
        addrem_flags(RMAP|BLCK|QMRK, RKEY|RVAL|RTOP|RUNK);
        m_doc_empty = false;
        m_was_inside_qmrk = true;
        _save_indentation();
        _line_progressed(1);
        _maybe_skip_whitespace_tokens();
    }
    else if(first == ':' && _is_blck_token(rem))
    {
        if(m_doc_empty)
        {
            _c4dbgp("it's a map with an empty key");
            m_evt_handler->check_trailing_doc_token();
            _maybe_begin_doc();
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->begin_map_val_block();
            m_evt_handler->set_key_scalar_plain({});
            m_doc_empty = false;
            _save_indentation();
        }
        else
        {
            _c4dbgp("actually prev val is a key!");
            size_t prev_indentation = m_evt_handler->m_curr->indref;
            m_evt_handler->actually_val_is_first_key_of_new_map_block();
            _set_indentation(prev_indentation);
        }
        addrem_flags(RMAP|BLCK|RVAL, RTOP|RUNK|RDOC);
        _line_progressed(1);
        _maybe_skip_whitespace_tokens();
    }
    else if(first == '&')
    {
        csubstr anchor = _scan_anchor();
        _c4dbgpf("anchor! [{}]~~~{}~~~", anchor.len, anchor);
        m_evt_handler->check_trailing_doc_token();
        _maybe_begin_doc();
        const size_t indentation = m_evt_handler->m_curr->line_contents.current_col(rem);
        const size_t line = m_evt_handler->m_curr->pos.line;
        _add_annotation(&m_pending_anchors, anchor, indentation, line);
        _set_indentation(m_evt_handler->m_curr->line_contents.current_col(rem));
        m_doc_empty = false;
    }
    else if(first == '*')
    {
        csubstr ref = _scan_ref_map();
        _c4dbgpf("ref! [{}]~~~{}~~~", ref.len, ref);
        m_evt_handler->check_trailing_doc_token();
        _maybe_begin_doc();
        m_doc_empty = false;
        if(!_maybe_scan_following_colon())
        {
            _c4dbgp("runk: set val ref");
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->set_val_ref(ref);
        }
        else
        {
            _c4dbgp("runk: start new block map, set ref as key");
            const size_t startindent = m_evt_handler->m_curr->line_contents.indentation; // save
            const size_t startline = m_evt_handler->m_curr->pos.line; // save
            _handle_annotations_before_start_mapblck(startline);
            m_evt_handler->begin_map_val_block();
            _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
            m_evt_handler->set_key_ref(ref);
            _maybe_skip_whitespace_tokens();
            _set_indentation(startindent);
            addrem_flags(RMAP|BLCK|RVAL, RTOP|RUNK|RDOC);
        }
    }
    else if(first == '!')
    {
        csubstr tag = _scan_tag();
        _c4dbgpf("unk: val tag! [{}]~~~{}~~~", tag.len, tag);
        // we need to buffer the tags, as there may be two
        // consecutive tags in here
        const size_t indentation = m_evt_handler->m_curr->line_contents.current_col(rem);
        const size_t line = m_evt_handler->m_curr->pos.line;
        _add_annotation(&m_pending_tags, tag, indentation, line);
    }
    else
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks,  ! has_any(SSCL));
        _maybe_skip_whitespace_tokens();
        csubstr s = m_evt_handler->m_curr->line_contents.rem;
        if(!s.len)
            return;
        const size_t startindent = m_evt_handler->m_curr->line_contents.indentation; // save
        const size_t startline = m_evt_handler->m_curr->pos.line; // save
        first = s.str[0];
        ScannedScalar sc;
        if(first == '\'')
        {
            _c4dbgp("runk: scanning single-quoted scalar");
            m_evt_handler->check_trailing_doc_token();
            _maybe_begin_doc();
            add_flags(RDOC);
            m_doc_empty = false;
            sc = _scan_scalar_squot();
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("runk: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_squot(sc);
                m_evt_handler->set_val_scalar_squoted(maybe_filtered);
            }
            else
            {
                _c4dbgp("runk: start new block map, set scalar as key");
                _handle_annotations_before_start_mapblck(startline);
                m_evt_handler->begin_map_val_block();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                csubstr maybe_filtered = _maybe_filter_key_scalar_squot(sc);
                m_evt_handler->set_key_scalar_squoted(maybe_filtered);
                _maybe_skip_whitespace_tokens();
                _set_indentation(startindent);
                addrem_flags(RMAP|BLCK|RVAL, RTOP|RUNK|RDOC);
            }
        }
        else if(first == '"')
        {
            _c4dbgp("runk: scanning double-quoted scalar");
            m_evt_handler->check_trailing_doc_token();
            _maybe_begin_doc();
            add_flags(RDOC);
            m_doc_empty = false;
            sc = _scan_scalar_dquot();
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("runk: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_dquot(sc);
                m_evt_handler->set_val_scalar_dquoted(maybe_filtered);
            }
            else
            {
                _c4dbgp("runk: start new block map, set double-quoted scalar as key");
                _handle_annotations_before_start_mapblck(startline);
                m_evt_handler->begin_map_val_block();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                csubstr maybe_filtered = _maybe_filter_key_scalar_dquot(sc);
                m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
                _maybe_skip_whitespace_tokens();
                _set_indentation(startindent);
                addrem_flags(RMAP|BLCK|RVAL, RTOP|RUNK|RDOC);
            }
        }
        else if(first == '|')
        {
            _c4dbgp("runk: scanning block-literal scalar");
            m_evt_handler->check_trailing_doc_token();
            _maybe_begin_doc();
            add_flags(RDOC);
            m_doc_empty = false;
            ScannedBlock sb;
            _scan_block(&sb, startindent);
            if(C4_LIKELY(!_maybe_scan_following_colon()))
            {
                _c4dbgp("runk: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_literal(sb);
                m_evt_handler->set_val_scalar_literal(maybe_filtered);
            }
            else
            {
                _c4err("block literal keys must be enclosed in '?'");
            }
        }
        else if(first == '>')
        {
            _c4dbgp("runk: scanning block-folded scalar");
            m_evt_handler->check_trailing_doc_token();
            _maybe_begin_doc();
            add_flags(RDOC);
            m_doc_empty = false;
            ScannedBlock sb;
            _scan_block(&sb, startindent);
            if(C4_LIKELY(!_maybe_scan_following_colon()))
            {
                _c4dbgp("runk: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_folded(sb);
                m_evt_handler->set_val_scalar_folded(maybe_filtered);
            }
            else
            {
                _c4err("block folded keys must be enclosed in '?'");
            }
        }
        else if(_scan_scalar_plain_unk(&sc))
        {
            _c4dbgp("runk: got a plain scalar");
            m_evt_handler->check_trailing_doc_token();
            _maybe_begin_doc();
            add_flags(RDOC);
            m_doc_empty = false;
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("runk: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_plain(sc, startindent);
                m_evt_handler->set_val_scalar_plain(maybe_filtered);
            }
            else
            {
                _c4dbgp("runk: start new block map, set scalar as key");
                _handle_annotations_before_start_mapblck(startline);
                m_evt_handler->begin_map_val_block();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                csubstr maybe_filtered = _maybe_filter_key_scalar_plain(sc, startindent);
                m_evt_handler->set_key_scalar_plain(maybe_filtered);
                _maybe_skip_whitespace_tokens();
                _set_indentation(startindent);
                addrem_flags(RMAP|BLCK|RVAL, RTOP|RUNK|RDOC);
            }
        }
    }
}


//-----------------------------------------------------------------------------

template<class EventHandler>
C4_COLD void ParseEngine<EventHandler>::_handle_usty()
{
    _c4dbgpf("handle_usty target={}", m_evt_handler->m_curr->indref, m_evt_handler->m_curr->node_id);

    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_none(BLCK|FLOW));

    #ifdef RYML_NO_COVERAGE__TO_BE_DELETED
    if(has_any(RNXT))
    {
        _c4dbgp("usty[RNXT]: finishing!");
        _end_stream();
    }
    #endif

    _maybe_skip_comment();
    csubstr rem = m_evt_handler->m_curr->line_contents.rem;
    if(!rem.len)
        return;

    size_t pos = rem.first_not_of(" \t");
    if(pos)
    {
        pos = pos != npos ? pos : rem.len;
        _c4dbgpf("skipping indentation of {}", pos);
        _line_progressed(pos);
        rem = m_evt_handler->m_curr->line_contents.rem;
        if(!rem.len)
            return;
        _c4dbgpf("rem is now [{}]~~~{}~~~", rem.len, rem);
    }

    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, rem.len > 0);
    size_t startindent = m_evt_handler->m_curr->line_contents.indentation; // save
    char first = rem.str[0];
    if(has_any(RSEQ)) // destination is a sequence
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks,  ! has_any(RMAP));
        _c4dbgpf("usty[RSEQ]: first='{}'", _c4prc(first));
        if(first == '[')
        {
            _c4dbgp("usty[RSEQ]: it's a flow seq. merging it");
            add_flags(RNXT);
            m_evt_handler->_push();
            addrem_flags(FLOW|RVAL, RNXT|USTY);
            _set_indentation(startindent);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '-' && _is_blck_token(rem))
        {
            _c4dbgp("usty[RSEQ]: it's a block seq. merging it");
            add_flags(RNXT);
            m_evt_handler->_push();
            addrem_flags(BLCK|RVAL, RNXT|USTY);
            _set_indentation(startindent);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else
        {
            _c4err("can only parse a seq into an existing seq");
        }
    }
    else if(has_any(RMAP)) // destination is a map
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks,  ! has_any(RSEQ));
        _c4dbgpf("usty[RMAP]: first='{}'", _c4prc(first));
        if(first == '{')
        {
            _c4dbgp("usty[RMAP]: it's a flow map. merging it");
            add_flags(RNXT);
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->_push();
            addrem_flags(RMAP|FLOW|RKEY, RNXT|USTY);
            _set_indentation(startindent);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '?' && _is_blck_token(rem))
        {
            _c4dbgp("usty[RMAP]: it's a block map + this key is complex");
            add_flags(RNXT);
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->_push();
            addrem_flags(RMAP|BLCK|QMRK, RNXT|USTY);
            m_was_inside_qmrk = true;
            _save_indentation();
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == ':' && _is_blck_token(rem))
        {
            _c4dbgp("usty[RMAP]: it's a map with an empty key");
            add_flags(RNXT);
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->_push();
            m_evt_handler->set_key_scalar_plain({});
            addrem_flags(RMAP|BLCK|RVAL, RNXT|USTY);
            _save_indentation();
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(rem.begins_with('&'))
        {
            csubstr anchor = _scan_anchor();
            _c4dbgpf("usty[RMAP]: anchor! [{}]~~~{}~~~", anchor.len, anchor);
            const size_t indentation = m_evt_handler->m_curr->line_contents.current_col(rem);
            const size_t line = m_evt_handler->m_curr->pos.line;
            _add_annotation(&m_pending_anchors, anchor, indentation, line);
            _set_indentation(m_evt_handler->m_curr->line_contents.current_col(rem));
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_map();
            _c4dbgpf("usty[RMAP]: ref! [{}]~~~{}~~~", ref.len, ref);
            if(!_maybe_scan_following_colon())
            {
                _c4err("cannot read a VAL to a map");
            }
            else
            {
                _c4dbgp("usty[RMAP]: start new block map, set ref as key");
                const size_t startline = m_evt_handler->m_curr->pos.line; // save
                add_flags(RNXT);
                _handle_annotations_before_start_mapblck(startline);
                m_evt_handler->_push();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                m_evt_handler->set_key_ref(ref);
                _maybe_skip_whitespace_tokens();
                _set_indentation(startindent);
                addrem_flags(RMAP|BLCK|RVAL, RNXT|USTY);
            }
        }
        else if(first == '!')
        {
            csubstr tag = _scan_tag();
            _c4dbgpf("usty[RMAP]: val tag! [{}]~~~{}~~~", tag.len, tag);
            // we need to buffer the tags, as there may be two
            // consecutive tags in here
            const size_t indentation = m_evt_handler->m_curr->line_contents.current_col(rem);
            const size_t line = m_evt_handler->m_curr->pos.line;
            _add_annotation(&m_pending_tags, tag, indentation, line);
        }
        else if(first == '[' || (first == '-' && _is_blck_token(rem)))
        {
            _c4err("cannot parse a seq into an existing map");
        }
        else
        {
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks,  ! has_any(SSCL));
            startindent = m_evt_handler->m_curr->line_contents.indentation; // save
            const size_t startline = m_evt_handler->m_curr->pos.line; // save
            ScannedScalar sc;
            _c4dbgpf("usty[RMAP]: maybe scalar. first='{}'", _c4prc(first));
            if(first == '\'')
            {
                _c4dbgp("usty[RMAP]: scanning single-quoted scalar");
                sc = _scan_scalar_squot();
                if(!_maybe_scan_following_colon())
                {
                    _c4err("cannot read a VAL to a map");
                }
                else
                {
                    _c4dbgp("usty[RMAP]: start new block map, set scalar as key");
                    add_flags(RNXT);
                    _handle_annotations_before_start_mapblck(startline);
                    m_evt_handler->_push();
                    _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                    csubstr maybe_filtered = _maybe_filter_key_scalar_squot(sc);
                    m_evt_handler->set_key_scalar_squoted(maybe_filtered);
                    _set_indentation(startindent);
                    addrem_flags(RMAP|BLCK|RVAL, RNXT|USTY);
                    _maybe_skip_whitespace_tokens();
                }
            }
            else if(first == '"')
            {
                _c4dbgp("usty[RMAP]: scanning double-quoted scalar");
                sc = _scan_scalar_dquot();
                if(!_maybe_scan_following_colon())
                {
                    _c4err("cannot read a VAL to a map");
                }
                else
                {
                    _c4dbgp("usty[RMAP]: start new block map, set double-quoted scalar as key");
                    add_flags(RNXT);
                    _handle_annotations_before_start_mapblck(startline);
                    m_evt_handler->_push();
                    _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                    csubstr maybe_filtered = _maybe_filter_key_scalar_dquot(sc);
                    m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
                    _set_indentation(startindent);
                    addrem_flags(RMAP|BLCK|RVAL, RNXT|USTY);
                    _maybe_skip_whitespace_tokens();
                }
            }
            else if(first == '|')
            {
                _c4err("block literal keys must be enclosed in '?'");
            }
            else if(first == '>')
            {
                _c4err("block literal keys must be enclosed in '?'");
            }
            else if(_scan_scalar_plain_unk(&sc))
            {
                _c4dbgp("usty[RMAP]: got a plain scalar");
                if(!_maybe_scan_following_colon())
                {
                    _c4err("cannot read a VAL to a map");
                }
                else
                {
                    _c4dbgp("usty[RMAP]: start new block map, set scalar as key");
                    add_flags(RNXT);
                    _handle_annotations_before_start_mapblck(startline);
                    m_evt_handler->_push();
                    _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                    csubstr maybe_filtered = _maybe_filter_key_scalar_plain(sc, startindent);
                    m_evt_handler->set_key_scalar_plain(maybe_filtered);
                    _set_indentation(startindent);
                    addrem_flags(RMAP|BLCK|RVAL, RNXT|USTY);
                    _maybe_skip_whitespace_tokens();
                }
            }
            else
            {
                _c4err("parse error");
            }
        }
    }
    else // destination is unknown
    {
        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks,  ! has_any(RSEQ));
        _c4dbgpf("usty[UNK]: first='{}'", _c4prc(first));
        if(first == '[')
        {
            _c4dbgp("usty[UNK]: it's a flow seq");
            add_flags(RNXT);
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->begin_seq_val_flow();
            addrem_flags(RSEQ|FLOW|RVAL, RNXT|USTY);
            _set_indentation(startindent);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '-' && _is_blck_token(rem))
        {
            _c4dbgp("usty[UNK]: it's a block seq");
            add_flags(RNXT);
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->begin_seq_val_block();
            addrem_flags(RSEQ|BLCK|RVAL, RNXT|USTY);
            _set_indentation(startindent);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '{')
        {
            _c4dbgp("usty[UNK]: it's a flow map");
            add_flags(RNXT);
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->begin_map_val_flow();
            addrem_flags(RMAP|FLOW|RKEY, RNXT|USTY);
            _set_indentation(startindent);
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '?' && _is_blck_token(rem))
        {
            _c4dbgp("usty[UNK]: it's a map + this key is complex");
            add_flags(RNXT);
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->begin_map_val_block();
            addrem_flags(RMAP|BLCK|QMRK, RNXT|USTY);
            m_was_inside_qmrk = true;
            _save_indentation();
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == ':' && _is_blck_token(rem))
        {
            _c4dbgp("usty[UNK]: it's a map with an empty key");
            add_flags(RNXT);
            _handle_annotations_before_blck_val_scalar();
            m_evt_handler->begin_map_val_block();
            m_evt_handler->set_key_scalar_plain({});
            addrem_flags(RMAP|BLCK|RVAL, RNXT|USTY);
            _save_indentation();
            _line_progressed(1);
            _maybe_skip_whitespace_tokens();
        }
        else if(first == '&')
        {
            csubstr anchor = _scan_anchor();
            _c4dbgpf("usty[UNK]: anchor! [{}]~~~{}~~~", anchor.len, anchor);
            const size_t indentation = m_evt_handler->m_curr->line_contents.current_col(rem);
            const size_t line = m_evt_handler->m_curr->pos.line;
            _add_annotation(&m_pending_anchors, anchor, indentation, line);
            _set_indentation(m_evt_handler->m_curr->line_contents.current_col(rem));
        }
        else if(first == '*')
        {
            csubstr ref = _scan_ref_map();
            _c4dbgpf("usty[UNK]: ref! [{}]~~~{}~~~", ref.len, ref);
            if(!_maybe_scan_following_colon())
            {
                _c4dbgp("usty[UNK]: set val ref");
                _handle_annotations_before_blck_val_scalar();
                m_evt_handler->set_val_ref(ref);
            }
            else
            {
                _c4dbgp("usty[UNK]: start new block map, set ref as key");
                const size_t startline = m_evt_handler->m_curr->pos.line; // save
                add_flags(RNXT);
                _handle_annotations_before_start_mapblck(startline);
                m_evt_handler->begin_map_val_block();
                _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                m_evt_handler->set_key_ref(ref);
                _maybe_skip_whitespace_tokens();
                _set_indentation(startindent);
                addrem_flags(RMAP|BLCK|RVAL, RNXT|USTY);
            }
        }
        else if(first == '!')
        {
            csubstr tag = _scan_tag();
            _c4dbgpf("usty[UNK]: val tag! [{}]~~~{}~~~", tag.len, tag);
            // we need to buffer the tags, as there may be two
            // consecutive tags in here
            const size_t indentation = m_evt_handler->m_curr->line_contents.current_col(rem);
            const size_t line = m_evt_handler->m_curr->pos.line;
            _add_annotation(&m_pending_tags, tag, indentation, line);
        }
        else
        {
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks,  ! has_any(SSCL));
            startindent = m_evt_handler->m_curr->line_contents.indentation; // save
            const size_t startline = m_evt_handler->m_curr->pos.line; // save
            first = rem.str[0];
            ScannedScalar sc;
            _c4dbgpf("usty[UNK]: maybe scalar. first='{}'", _c4prc(first));
            if(first == '\'')
            {
                _c4dbgp("usty[UNK]: scanning single-quoted scalar");
                sc = _scan_scalar_squot();
                if(!_maybe_scan_following_colon())
                {
                    _c4dbgp("usty[UNK]: set as val");
                    _handle_annotations_before_blck_val_scalar();
                    csubstr maybe_filtered = _maybe_filter_val_scalar_squot(sc);
                    m_evt_handler->set_val_scalar_squoted(maybe_filtered);
                    _end_stream();
                }
                else
                {
                    _c4dbgp("usty[UNK]: start new block map, set scalar as key");
                    add_flags(RNXT);
                    _handle_annotations_before_start_mapblck(startline);
                    m_evt_handler->begin_map_val_block();
                    _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                    csubstr maybe_filtered = _maybe_filter_key_scalar_squot(sc);
                    m_evt_handler->set_key_scalar_squoted(maybe_filtered);
                    _set_indentation(startindent);
                    addrem_flags(RMAP|BLCK|RVAL, RNXT|USTY);
                    _maybe_skip_whitespace_tokens();
                }
            }
            else if(first == '"')
            {
                _c4dbgp("usty[UNK]: scanning double-quoted scalar");
                sc = _scan_scalar_dquot();
                if(!_maybe_scan_following_colon())
                {
                    _c4dbgp("usty[UNK]: set as val");
                    _handle_annotations_before_blck_val_scalar();
                    csubstr maybe_filtered = _maybe_filter_val_scalar_dquot(sc);
                    m_evt_handler->set_val_scalar_dquoted(maybe_filtered);
                    _end_stream();
                }
                else
                {
                    _c4dbgp("usty[UNK]: start new block map, set double-quoted scalar as key");
                    add_flags(RNXT);
                    _handle_annotations_before_start_mapblck(startline);
                    m_evt_handler->begin_map_val_block();
                    _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                    csubstr maybe_filtered = _maybe_filter_key_scalar_dquot(sc);
                    m_evt_handler->set_key_scalar_dquoted(maybe_filtered);
                    _set_indentation(startindent);
                    addrem_flags(RMAP|BLCK|RVAL, RNXT|USTY);
                    _maybe_skip_whitespace_tokens();
                }
            }
            else if(first == '|')
            {
                _c4dbgp("usty[UNK]: scanning block-literal scalar");
                ScannedBlock sb;
                _scan_block(&sb, startindent);
                _c4dbgp("usty[UNK]: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_literal(sb);
                m_evt_handler->set_val_scalar_literal(maybe_filtered);
                _end_stream();
            }
            else if(first == '>')
            {
                _c4dbgp("usty[UNK]: scanning block-folded scalar");
                ScannedBlock sb;
                _scan_block(&sb, startindent);
                _c4dbgp("usty[UNK]: set as val");
                _handle_annotations_before_blck_val_scalar();
                csubstr maybe_filtered = _maybe_filter_val_scalar_folded(sb);
                m_evt_handler->set_val_scalar_folded(maybe_filtered);
                _end_stream();
            }
            else if(_scan_scalar_plain_unk(&sc))
            {
                _c4dbgp("usty[UNK]: got a plain scalar");
                if(!_maybe_scan_following_colon())
                {
                    _c4dbgp("usty[UNK]: set as val");
                    _handle_annotations_before_blck_val_scalar();
                    csubstr maybe_filtered = _maybe_filter_val_scalar_plain(sc, startindent);
                    m_evt_handler->set_val_scalar_plain(maybe_filtered);
                    _end_stream();
                }
                else
                {
                    _c4dbgp("usty[UNK]: start new block map, set scalar as key");
                    add_flags(RNXT);
                    _handle_annotations_before_start_mapblck(startline);
                    m_evt_handler->begin_map_val_block();
                    _handle_annotations_and_indentation_after_start_mapblck(startindent, startline);
                    csubstr maybe_filtered = _maybe_filter_key_scalar_plain(sc, startindent);
                    m_evt_handler->set_key_scalar_plain(maybe_filtered);
                    _set_indentation(startindent);
                    addrem_flags(RMAP|BLCK|RVAL, RNXT|USTY);
                    _maybe_skip_whitespace_tokens();
                }
            }
            else
            {
                _c4err("parse error");
            }
        }
    }
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::parse_json_in_place_ev(csubstr filename, substr src)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_stack.size() >= 1);
    m_file = filename;
    m_buf = src;
    _reset();
    m_evt_handler->start_parse(filename.str, &_s_relocate_arena, this);
    m_evt_handler->begin_stream();
    while( ! _finished_file())
    {
        _scan_line();
        while( ! _finished_line())
        {
            _c4dbgnextline();
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks,  ! m_evt_handler->m_curr->line_contents.rem.empty());
            if(has_any(RSEQ))
            {
                _handle_seq_json();
            }
            else if(has_any(RMAP))
            {
                _handle_map_json();
            }
            else if(has_any(RUNK))
            {
                _handle_unk_json();
            }
            else
            {
                _c4err("internal error");
            }
        }
        if(_finished_file())
            break; // it may have finished because of multiline blocks
        _line_ended();
    }
    _end_stream();
    m_evt_handler->finish_parse();
}


//-----------------------------------------------------------------------------

template<class EventHandler>
void ParseEngine<EventHandler>::parse_in_place_ev(csubstr filename, substr src)
{
    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, m_evt_handler->m_stack.size() >= 1);
    m_file = filename;
    m_buf = src;
    _reset();
    m_evt_handler->start_parse(filename.str, &_s_relocate_arena, this);
    m_evt_handler->begin_stream();
    while( ! _finished_file())
    {
        _scan_line();
        while( ! _finished_line())
        {
            _c4dbgnextline();
            _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks,  ! m_evt_handler->m_curr->line_contents.rem.empty());
            if(has_any(FLOW))
            {
                if(has_none(RSEQIMAP))
                {
                    if(has_any(RSEQ))
                    {
                        _handle_seq_flow();
                    }
                    else
                    {
                        _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RMAP));
                        _handle_map_flow();
                    }
                }
                else
                {
                    _handle_seq_imap();
                }
            }
            else if(has_any(BLCK))
            {
                if(has_any(RSEQ))
                {
                    _handle_seq_block();
                }
                else
                {
                    _RYML_CB_ASSERT(m_evt_handler->m_stack.m_callbacks, has_all(RMAP));
                    _handle_map_block();
                }
            }
            else if(has_any(RUNK))
            {
                _handle_unk();
            }
            else if(has_any(USTY))
            {
                _handle_usty();
            }
            else
            {
                _c4err("internal error");
            }
        }
        if(_finished_file())
            break; // it may have finished because of multiline blocks
        _line_ended();
    }
    _end_stream();
    m_evt_handler->finish_parse();
}

} // namespace yml
} // namespace c4

#undef _c4dbgnextline

#if defined(_MSC_VER)
#   pragma warning(pop)
#elif defined(__clang__)
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif

#endif // _C4_YML_PARSE_ENGINE_DEF_HPP_


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/parse_engine.def.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/reference_resolver.cpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/reference_resolver.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef RYML_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/reference_resolver.hpp
//#include "c4/yml/reference_resolver.hpp"
#if !defined(C4_YML_REFERENCE_RESOLVER_HPP_) && !defined(_C4_YML_REFERENCE_RESOLVER_HPP_)
#error "amalgamate: file c4/yml/reference_resolver.hpp must have been included at this point"
#endif /* C4_YML_REFERENCE_RESOLVER_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/dump.hpp
//#include "c4/dump.hpp" // this is needed to resolve a function in the next header
#if !defined(C4_DUMP_HPP_) && !defined(_C4_DUMP_HPP_)
#error "amalgamate: file c4/dump.hpp must have been included at this point"
#endif /* C4_DUMP_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/common.hpp
//#include "c4/yml/common.hpp"
#if !defined(C4_YML_COMMON_HPP_) && !defined(_C4_YML_COMMON_HPP_)
#error "amalgamate: file c4/yml/common.hpp must have been included at this point"
#endif /* C4_YML_COMMON_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/parser_dbg.hpp
//#include "c4/yml/detail/parser_dbg.hpp"
#if !defined(C4_YML_DETAIL_PARSER_DBG_HPP_) && !defined(_C4_YML_DETAIL_PARSER_DBG_HPP_)
#error "amalgamate: file c4/yml/detail/parser_dbg.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PARSER_DBG_HPP_ */

#ifdef RYML_DBG
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/print.hpp
//#include "c4/yml/detail/print.hpp"
#if !defined(C4_YML_DETAIL_PRINT_HPP_) && !defined(_C4_YML_DETAIL_PRINT_HPP_)
#error "amalgamate: file c4/yml/detail/print.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PRINT_HPP_ */

#else
#define _c4dbg_tree(...)
#define _c4dbg_node(...)
#endif

namespace c4 {
namespace yml {

id_type ReferenceResolver::count_anchors_and_refs_(id_type n)
{
    id_type c = 0;
    c += m_tree->has_key_anchor(n);
    c += m_tree->has_val_anchor(n);
    c += m_tree->is_key_ref(n);
    c += m_tree->is_val_ref(n);
    c += m_tree->has_key(n) && m_tree->key(n) == "<<";
    for(id_type ch = m_tree->first_child(n); ch != NONE; ch = m_tree->next_sibling(ch))
        c += count_anchors_and_refs_(ch);
    return c;
}

void ReferenceResolver::gather_anchors_and_refs__(id_type n)
{
    // insert key refs BEFORE inserting val refs
    if(m_tree->has_key(n))
    {
        if(m_tree->key(n) == "<<")
        {
            _c4dbgpf("node[{}]: key is <<", n);
            if(m_tree->has_val(n))
            {
                if(m_tree->is_val_ref(n))
                {
                    _c4dbgpf("node[{}]: val ref, inheriting!", n);
                    m_refs.push({VALREF, n, NONE, NONE, NONE, NONE});
                    //m_refs.push({KEYREF, n, NONE, NONE, NONE, NONE});
                }
                else
                {
                    _c4dbgpf("node[{}]: not ref!", n);
                }
            }
            else if(m_tree->is_seq(n))
            {
                // for merging multiple inheritance targets
                //   <<: [ *CENTER, *BIG ]
                _c4dbgpf("node[{}]: is seq!", n);
                for(id_type ich = m_tree->first_child(n); ich != NONE; ich = m_tree->next_sibling(ich))
                {
                    _c4dbgpf("node[{}]: val ref, inheriting multiple: {}", n, ich);
                    if(m_tree->is_container(ich))
                    {
                        detail::_report_err(m_tree->m_callbacks, "ERROR: node {} child {}: refs for << cannot be containers.'", n, ich);
                        C4_UNREACHABLE_AFTER_ERR();
                    }
                    m_refs.push({VALREF, ich, NONE, NONE, n, m_tree->next_sibling(n)});
                }
                return; // don't descend into the seq
            }
            else
            {
                detail::_report_err(m_tree->m_callbacks, "ERROR: node {}: refs for << must be either val or seq", n);
                C4_UNREACHABLE_AFTER_ERR();
            }
        }
        else if(m_tree->is_key_ref(n))
        {
            _c4dbgpf("node[{}]: key ref: '{}'", n, m_tree->key_ref(n));
            _RYML_CB_ASSERT(m_tree->m_callbacks, m_tree->key(n) != "<<");
            _RYML_CB_CHECK(m_tree->m_callbacks, (!m_tree->has_key(n)) || m_tree->key(n).ends_with(m_tree->key_ref(n)));
            m_refs.push({KEYREF, n, NONE, NONE, NONE, NONE});
        }
    }
    // val ref
    if(m_tree->is_val_ref(n) && (!m_tree->has_key(n) || m_tree->key(n) != "<<"))
    {
        _c4dbgpf("node[{}]: val ref: '{}'", n, m_tree->val_ref(n));
        RYML_CHECK((!m_tree->has_val(n)) || m_tree->val(n).ends_with(m_tree->val_ref(n)));
        m_refs.push({VALREF, n, NONE, NONE, NONE, NONE});
    }
    // anchors
    if(m_tree->has_key_anchor(n))
    {
        _c4dbgpf("node[{}]: key anchor: '{}'", n, m_tree->key_anchor(n));
        RYML_CHECK(m_tree->has_key(n));
        m_refs.push({KEYANCH, n, NONE, NONE, NONE, NONE});
    }
    if(m_tree->has_val_anchor(n))
    {
        _c4dbgpf("node[{}]: val anchor: '{}'", n, m_tree->val_anchor(n));
        RYML_CHECK(m_tree->has_val(n) || m_tree->is_container(n));
        m_refs.push({VALANCH, n, NONE, NONE, NONE, NONE});
    }
    // recurse
    for(id_type ch = m_tree->first_child(n); ch != NONE; ch = m_tree->next_sibling(ch))
        gather_anchors_and_refs__(ch);
}

void ReferenceResolver::gather_anchors_and_refs_()
{
    _c4dbgp("gathering anchors and refs...");

    // minimize (re-)allocations by counting first
    id_type num_anchors_and_refs = count_anchors_and_refs_(m_tree->root_id());
    if(!num_anchors_and_refs)
        return;
    m_refs.reserve(num_anchors_and_refs);
    m_refs.clear();

    // now descend through the hierarchy
    gather_anchors_and_refs__(m_tree->root_id());

    _c4dbgpf("found {} anchors/refs", m_refs.size());

    // finally connect the reference list
    id_type prev_anchor = NONE;
    id_type count = 0;
    for(auto &rd : m_refs)
    {
        rd.prev_anchor = prev_anchor;
        if(rd.type.has_anchor())
            prev_anchor = count;
        ++count;
    }
    _c4dbgp("gathering anchors and refs: finished");
}

id_type ReferenceResolver::lookup_(RefData *C4_RESTRICT ra)
{
    RYML_ASSERT(ra->type.is_key_ref() || ra->type.is_val_ref());
    RYML_ASSERT(ra->type.is_key_ref() != ra->type.is_val_ref());
    csubstr refname;
    if(ra->type.is_val_ref())
    {
        refname = m_tree->val_ref(ra->node);
    }
    else
    {
        RYML_ASSERT(ra->type.is_key_ref());
        refname = m_tree->key_ref(ra->node);
    }
    while(ra->prev_anchor != NONE)
    {
        ra = &m_refs[ra->prev_anchor];
        if(m_tree->has_anchor(ra->node, refname))
            return ra->node;
    }
    detail::_report_err(m_tree->m_callbacks, "ERROR: anchor not found: '{}'", refname);
    C4_UNREACHABLE_AFTER_ERR();
}

void ReferenceResolver::reset_(Tree *t_)
{
    if(t_->callbacks() != m_refs.m_callbacks)
    {
        m_refs.m_callbacks = t_->callbacks();
    }
    m_refs.clear();
    m_tree = t_;
}

void ReferenceResolver::resolve(Tree *t_)
{
    _c4dbgp("resolving references...");

    reset_(t_);

    _c4dbg_tree("unresolved tree", *m_tree);

    gather_anchors_and_refs_();
    if(m_refs.empty())
        return;

    /* from the specs: "an alias node refers to the most recent
     * node in the serialization having the specified anchor". So
     * we need to start looking upward from ref nodes.
     *
     * @see http://yaml.org/spec/1.2/spec.html#id2765878 */
    _c4dbgp("matching anchors/refs...");
    for(id_type i = 0, e = m_refs.size(); i < e; ++i)
    {
        RefData &C4_RESTRICT refdata = m_refs.top(i);
        if( ! refdata.type.is_ref())
            continue;
        refdata.target = lookup_(&refdata);
    }
    _c4dbgp("matching anchors/refs: finished");

    // insert the resolved references
    _c4dbgp("modifying tree...");
    id_type prev_parent_ref = NONE;
    id_type prev_parent_ref_after = NONE;
    for(id_type i = 0, e = m_refs.size(); i < e; ++i)
    {
        RefData const& C4_RESTRICT refdata = m_refs[i];
        _c4dbgpf("instance {}/{}...", i, e);
        if( ! refdata.type.is_ref())
            continue;
        _c4dbgpf("instance {} is reference!", i);
        if(refdata.parent_ref != NONE)
        {
            _c4dbgpf("ref {} has parent: {}", i, refdata.parent_ref);
            _RYML_CB_ASSERT(m_tree->m_callbacks, m_tree->is_seq(refdata.parent_ref));
            const id_type p = m_tree->parent(refdata.parent_ref);
            const id_type after = (prev_parent_ref != refdata.parent_ref) ?
                refdata.parent_ref//prev_sibling(rd.parent_ref_sibling)
                :
                prev_parent_ref_after;
            prev_parent_ref = refdata.parent_ref;
            prev_parent_ref_after = m_tree->duplicate_children_no_rep(refdata.target, p, after);
            m_tree->remove(refdata.node);
        }
        else
        {
            _c4dbgpf("ref {} has no parent", i, refdata.parent_ref);
            if(m_tree->has_key(refdata.node) && m_tree->key(refdata.node) == "<<")
            {
                _c4dbgpf("ref {} is inheriting", i);
                _RYML_CB_ASSERT(m_tree->m_callbacks, m_tree->is_keyval(refdata.node));
                const id_type p = m_tree->parent(refdata.node);
                const id_type after = m_tree->prev_sibling(refdata.node);
                m_tree->duplicate_children_no_rep(refdata.target, p, after);
                m_tree->remove(refdata.node);
            }
            else if(refdata.type.is_key_ref())
            {
                _c4dbgpf("ref {} is key ref", i);
                _RYML_CB_ASSERT(m_tree->m_callbacks, m_tree->is_key_ref(refdata.node));
                _RYML_CB_ASSERT(m_tree->m_callbacks, m_tree->has_key_anchor(refdata.target) || m_tree->has_val_anchor(refdata.target));
                if(m_tree->has_val_anchor(refdata.target) && m_tree->val_anchor(refdata.target) == m_tree->key_ref(refdata.node))
                {
                    _RYML_CB_CHECK(m_tree->m_callbacks, !m_tree->is_container(refdata.target));
                    _RYML_CB_CHECK(m_tree->m_callbacks, m_tree->has_val(refdata.target));
                    const type_bits existing_style_flags = VAL_STYLE & m_tree->_p(refdata.target)->m_type.type;
                    static_assert((VAL_STYLE >> 1u) == (KEY_STYLE), "bad flags");
                    m_tree->_p(refdata.node)->m_key.scalar = m_tree->val(refdata.target);
                    m_tree->_add_flags(refdata.node, KEY | (existing_style_flags >> 1u));
                }
                else
                {
                    _RYML_CB_CHECK(m_tree->m_callbacks, m_tree->key_anchor(refdata.target) == m_tree->key_ref(refdata.node));
                    m_tree->_p(refdata.node)->m_key.scalar = m_tree->key(refdata.target);
                    // keys cannot be containers, so don't inherit container flags
                    const type_bits existing_style_flags = KEY_STYLE & m_tree->_p(refdata.target)->m_type.type;
                    m_tree->_add_flags(refdata.node, KEY | existing_style_flags);
                }
            }
            else // val ref
            {
                _c4dbgpf("ref {} is val ref", i);
                _RYML_CB_ASSERT(m_tree->m_callbacks, refdata.type.is_val_ref());
                if(m_tree->has_key_anchor(refdata.target) && m_tree->key_anchor(refdata.target) == m_tree->val_ref(refdata.node))
                {
                    _RYML_CB_CHECK(m_tree->m_callbacks, !m_tree->is_container(refdata.target));
                    _RYML_CB_CHECK(m_tree->m_callbacks, m_tree->has_val(refdata.target));
                    // keys cannot be containers, so don't inherit container flags
                    const type_bits existing_style_flags = (KEY_STYLE) & m_tree->_p(refdata.target)->m_type.type;
                    static_assert((KEY_STYLE << 1u) == (VAL_STYLE), "bad flags");
                    m_tree->_p(refdata.node)->m_val.scalar = m_tree->key(refdata.target);
                    m_tree->_add_flags(refdata.node, VAL | (existing_style_flags << 1u));
                }
                else
                {
                    m_tree->duplicate_contents(refdata.target, refdata.node);
                }
            }
        }
    }
    _c4dbgp("modifying tree: finished");

    // clear anchors and refs
    _c4dbgp("clearing anchors/refs");
    for(auto const& C4_RESTRICT ar : m_refs)
    {
        m_tree->rem_anchor_ref(ar.node);
        if(ar.parent_ref != NONE)
            if(m_tree->type(ar.parent_ref) != NOTYPE)
                m_tree->remove(ar.parent_ref);
    }
    _c4dbgp("clearing anchors/refs: finished");

    _c4dbg_tree("resolved tree", *m_tree);

    m_tree = nullptr;
    _c4dbgp("resolving references: finished");
}


} // namespace ryml
} // namespace c4

#endif /* RYML_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/reference_resolver.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/parse.cpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/parse.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef RYML_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/parse.hpp
//#include "c4/yml/parse.hpp"
#if !defined(C4_YML_PARSE_HPP_) && !defined(_C4_YML_PARSE_HPP_)
#error "amalgamate: file c4/yml/parse.hpp must have been included at this point"
#endif /* C4_YML_PARSE_HPP_ */


#ifndef _C4_YML_NODE_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/node.hpp
//#include "c4/yml/node.hpp"
#if !defined(C4_YML_NODE_HPP_) && !defined(_C4_YML_NODE_HPP_)
#error "amalgamate: file c4/yml/node.hpp must have been included at this point"
#endif /* C4_YML_NODE_HPP_ */

#endif
#ifndef _C4_YML_PARSE_ENGINE_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/parse_engine.hpp
//#include "c4/yml/parse_engine.hpp"
#if !defined(C4_YML_PARSE_ENGINE_HPP_) && !defined(_C4_YML_PARSE_ENGINE_HPP_)
#error "amalgamate: file c4/yml/parse_engine.hpp must have been included at this point"
#endif /* C4_YML_PARSE_ENGINE_HPP_ */

#endif
#ifndef _C4_YML_PARSE_ENGINE_DEF_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/parse_engine.def.hpp
//#include "c4/yml/parse_engine.def.hpp"
#if !defined(C4_YML_PARSE_ENGINE_DEF_HPP_) && !defined(_C4_YML_PARSE_ENGINE_DEF_HPP_)
#error "amalgamate: file c4/yml/parse_engine.def.hpp must have been included at this point"
#endif /* C4_YML_PARSE_ENGINE_DEF_HPP_ */

#endif
#ifndef _C4_YML_EVENT_HANDLER_TREE_HPP_
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/event_handler_tree.hpp
//#include "c4/yml/event_handler_tree.hpp"
#if !defined(C4_YML_EVENT_HANDLER_TREE_HPP_) && !defined(_C4_YML_EVENT_HANDLER_TREE_HPP_)
#error "amalgamate: file c4/yml/event_handler_tree.hpp must have been included at this point"
#endif /* C4_YML_EVENT_HANDLER_TREE_HPP_ */

#endif


//-----------------------------------------------------------------------------

namespace c4 {
namespace yml {

// instantiate the parser class
template class ParseEngine<EventHandlerTree>;

namespace {
inline void _reset_tree_handler(Parser *parser, Tree *t, id_type node_id)
{
    RYML_ASSERT(parser);
    RYML_ASSERT(t);
    if(!parser->m_evt_handler)
        _RYML_CB_ERR(t->m_callbacks, "event handler is not set");
    parser->m_evt_handler->reset(t, node_id);
    RYML_ASSERT(parser->m_evt_handler->m_tree == t);
}
} // namespace

void parse_in_place(Parser *parser, csubstr filename, substr yaml, Tree *t, id_type node_id)
{
    _reset_tree_handler(parser, t, node_id);
    parser->parse_in_place_ev(filename, yaml);
}

void parse_json_in_place(Parser *parser, csubstr filename, substr json, Tree *t, id_type node_id)
{
    _reset_tree_handler(parser, t, node_id);
    parser->parse_json_in_place_ev(filename, json);
}


// this is vertically aligned to highlight the parameter differences.
void parse_in_place(Parser *parser,                   substr yaml, Tree *t, id_type node_id) { parse_in_place(parser, {}, yaml, t, node_id); }
void parse_in_place(Parser *parser, csubstr filename, substr yaml, Tree *t                ) { RYML_CHECK(t); parse_in_place(parser, filename, yaml, t, t->root_id()); }
void parse_in_place(Parser *parser,                   substr yaml, Tree *t                ) { RYML_CHECK(t); parse_in_place(parser, {}      , yaml, t, t->root_id()); }
void parse_in_place(Parser *parser, csubstr filename, substr yaml, NodeRef node           ) { RYML_CHECK(!node.invalid()); parse_in_place(parser, filename, yaml, node.tree(), node.id()); }
void parse_in_place(Parser *parser,                   substr yaml, NodeRef node           ) { RYML_CHECK(!node.invalid()); parse_in_place(parser, {}      , yaml, node.tree(), node.id()); }
Tree parse_in_place(Parser *parser, csubstr filename, substr yaml                         ) { RYML_CHECK(parser); RYML_CHECK(parser->m_evt_handler); Tree tree(parser->callbacks()); parse_in_place(parser, filename, yaml, &tree, tree.root_id()); return tree; }
Tree parse_in_place(Parser *parser,                   substr yaml                         ) { RYML_CHECK(parser); RYML_CHECK(parser->m_evt_handler); Tree tree(parser->callbacks()); parse_in_place(parser, {}      , yaml, &tree, tree.root_id()); return tree; }

// this is vertically aligned to highlight the parameter differences.
void parse_in_place(csubstr filename, substr yaml, Tree *t, id_type node_id) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); parse_in_place(&parser, filename, yaml, t, node_id); }
void parse_in_place(                  substr yaml, Tree *t, id_type node_id) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); parse_in_place(&parser, {}      , yaml, t, node_id); }
void parse_in_place(csubstr filename, substr yaml, Tree *t                ) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); parse_in_place(&parser, filename, yaml, t, t->root_id()); }
void parse_in_place(                  substr yaml, Tree *t                ) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); parse_in_place(&parser, {}      , yaml, t, t->root_id()); }
void parse_in_place(csubstr filename, substr yaml, NodeRef node           ) { RYML_CHECK(!node.invalid()); Parser::handler_type event_handler(node.tree()->callbacks()); Parser parser(&event_handler); parse_in_place(&parser, filename, yaml, node.tree(), node.id()); }
void parse_in_place(                  substr yaml, NodeRef node           ) { RYML_CHECK(!node.invalid()); Parser::handler_type event_handler(node.tree()->callbacks()); Parser parser(&event_handler); parse_in_place(&parser, {}      , yaml, node.tree(), node.id()); }
Tree parse_in_place(csubstr filename, substr yaml                         ) { Parser::handler_type event_handler; Parser parser(&event_handler); Tree tree(parser.callbacks()); parse_in_place(&parser, filename, yaml, &tree, tree.root_id()); return tree; }
Tree parse_in_place(                  substr yaml                         ) { Parser::handler_type event_handler; Parser parser(&event_handler); Tree tree(parser.callbacks()); parse_in_place(&parser, {}      , yaml, &tree, tree.root_id()); return tree; }


// this is vertically aligned to highlight the parameter differences.
void parse_json_in_place(Parser *parser,                   substr json, Tree *t, id_type node_id) { parse_json_in_place(parser, {}, json, t, node_id); }
void parse_json_in_place(Parser *parser, csubstr filename, substr json, Tree *t                ) { RYML_CHECK(t); parse_json_in_place(parser, filename, json, t, t->root_id()); }
void parse_json_in_place(Parser *parser,                   substr json, Tree *t                ) { RYML_CHECK(t); parse_json_in_place(parser, {}      , json, t, t->root_id()); }
void parse_json_in_place(Parser *parser, csubstr filename, substr json, NodeRef node           ) { RYML_CHECK(!node.invalid()); parse_json_in_place(parser, filename, json, node.tree(), node.id()); }
void parse_json_in_place(Parser *parser,                   substr json, NodeRef node           ) { RYML_CHECK(!node.invalid()); parse_json_in_place(parser, {}      , json, node.tree(), node.id()); }
Tree parse_json_in_place(Parser *parser, csubstr filename, substr json                         ) { RYML_CHECK(parser); RYML_CHECK(parser->m_evt_handler); Tree tree(parser->callbacks()); parse_json_in_place(parser, filename, json, &tree, tree.root_id()); return tree; }
Tree parse_json_in_place(Parser *parser,                   substr json                         ) { RYML_CHECK(parser); RYML_CHECK(parser->m_evt_handler); Tree tree(parser->callbacks()); parse_json_in_place(parser, {}      , json, &tree, tree.root_id()); return tree; }

// this is vertically aligned to highlight the parameter differences.
void parse_json_in_place(csubstr filename, substr json, Tree *t, id_type node_id) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); parse_json_in_place(&parser, filename, json, t, node_id); }
void parse_json_in_place(                  substr json, Tree *t, id_type node_id) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); parse_json_in_place(&parser, {}      , json, t, node_id); }
void parse_json_in_place(csubstr filename, substr json, Tree *t                ) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); parse_json_in_place(&parser, filename, json, t, t->root_id()); }
void parse_json_in_place(                  substr json, Tree *t                ) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); parse_json_in_place(&parser, {}      , json, t, t->root_id()); }
void parse_json_in_place(csubstr filename, substr json, NodeRef node           ) { RYML_CHECK(!node.invalid()); Parser::handler_type event_handler(node.tree()->callbacks()); Parser parser(&event_handler); parse_json_in_place(&parser, filename, json, node.tree(), node.id()); }
void parse_json_in_place(                  substr json, NodeRef node           ) { RYML_CHECK(!node.invalid()); Parser::handler_type event_handler(node.tree()->callbacks()); Parser parser(&event_handler); parse_json_in_place(&parser, {}      , json, node.tree(), node.id()); }
Tree parse_json_in_place(csubstr filename, substr json                         ) { Parser::handler_type event_handler; Parser parser(&event_handler); Tree tree(parser.callbacks()); parse_json_in_place(&parser, filename, json, &tree, tree.root_id()); return tree; }
Tree parse_json_in_place(                  substr json                         ) { Parser::handler_type event_handler; Parser parser(&event_handler); Tree tree(parser.callbacks()); parse_json_in_place(&parser, {}      , json, &tree, tree.root_id()); return tree; }


// this is vertically aligned to highlight the parameter differences.
void parse_in_arena(Parser *parser, csubstr filename, csubstr yaml, Tree *t, id_type node_id) { RYML_CHECK(t); substr src = t->copy_to_arena(yaml); parse_in_place(parser, filename, src, t, node_id); }
void parse_in_arena(Parser *parser,                   csubstr yaml, Tree *t, id_type node_id) { RYML_CHECK(t); substr src = t->copy_to_arena(yaml); parse_in_place(parser, {}      , src, t, node_id); }
void parse_in_arena(Parser *parser, csubstr filename, csubstr yaml, Tree *t                ) { RYML_CHECK(t); substr src = t->copy_to_arena(yaml); parse_in_place(parser, filename, src, t, t->root_id()); }
void parse_in_arena(Parser *parser,                   csubstr yaml, Tree *t                ) { RYML_CHECK(t); substr src = t->copy_to_arena(yaml); parse_in_place(parser, {}      , src, t, t->root_id()); }
void parse_in_arena(Parser *parser, csubstr filename, csubstr yaml, NodeRef node           ) { RYML_CHECK(!node.invalid()); substr src = node.tree()->copy_to_arena(yaml); parse_in_place(parser, filename, src, node.tree(), node.id()); }
void parse_in_arena(Parser *parser,                   csubstr yaml, NodeRef node           ) { RYML_CHECK(!node.invalid()); substr src = node.tree()->copy_to_arena(yaml); parse_in_place(parser, {}      , src, node.tree(), node.id()); }
Tree parse_in_arena(Parser *parser, csubstr filename, csubstr yaml                         ) { RYML_CHECK(parser); RYML_CHECK(parser->m_evt_handler); Tree tree(parser->callbacks()); substr src = tree.copy_to_arena(yaml); parse_in_place(parser, filename, src, &tree, tree.root_id()); return tree; }
Tree parse_in_arena(Parser *parser,                   csubstr yaml                         ) { RYML_CHECK(parser); RYML_CHECK(parser->m_evt_handler); Tree tree(parser->callbacks()); substr src = tree.copy_to_arena(yaml); parse_in_place(parser, {}      , src, &tree, tree.root_id()); return tree; }

// this is vertically aligned to highlight the parameter differences.
void parse_in_arena(csubstr filename, csubstr yaml, Tree *t, id_type node_id) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); substr src = t->copy_to_arena(yaml); parse_in_place(&parser, filename, src, t, node_id); }
void parse_in_arena(                  csubstr yaml, Tree *t, id_type node_id) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); substr src = t->copy_to_arena(yaml); parse_in_place(&parser, {}      , src, t, node_id); }
void parse_in_arena(csubstr filename, csubstr yaml, Tree *t                ) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); substr src = t->copy_to_arena(yaml); parse_in_place(&parser, filename, src, t, t->root_id()); }
void parse_in_arena(                  csubstr yaml, Tree *t                ) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); substr src = t->copy_to_arena(yaml); parse_in_place(&parser, {}      , src, t, t->root_id()); }
void parse_in_arena(csubstr filename, csubstr yaml, NodeRef node           ) { RYML_CHECK(!node.invalid()); Parser::handler_type event_handler(node.tree()->callbacks()); Parser parser(&event_handler); substr src = node.tree()->copy_to_arena(yaml); parse_in_place(&parser, filename, src, node.tree(), node.id()); }
void parse_in_arena(                  csubstr yaml, NodeRef node           ) { RYML_CHECK(!node.invalid()); Parser::handler_type event_handler(node.tree()->callbacks()); Parser parser(&event_handler); substr src = node.tree()->copy_to_arena(yaml); parse_in_place(&parser, {}      , src, node.tree(), node.id()); }
Tree parse_in_arena(csubstr filename, csubstr yaml                         ) { Parser::handler_type event_handler; Parser parser(&event_handler); Tree tree(parser.callbacks()); substr src = tree.copy_to_arena(yaml); parse_in_place(&parser, filename, src, &tree, tree.root_id()); return tree; }
Tree parse_in_arena(                  csubstr yaml                         ) { Parser::handler_type event_handler; Parser parser(&event_handler); Tree tree(parser.callbacks()); substr src = tree.copy_to_arena(yaml); parse_in_place(&parser, {}      , src, &tree, tree.root_id()); return tree; }


// this is vertically aligned to highlight the parameter differences.
void parse_json_in_arena(Parser *parser, csubstr filename, csubstr json, Tree *t, id_type node_id) { RYML_CHECK(t); substr src = t->copy_to_arena(json); parse_json_in_place(parser, filename, src, t, node_id); }
void parse_json_in_arena(Parser *parser,                   csubstr json, Tree *t, id_type node_id) { RYML_CHECK(t); substr src = t->copy_to_arena(json); parse_json_in_place(parser, {}      , src, t, node_id); }
void parse_json_in_arena(Parser *parser, csubstr filename, csubstr json, Tree *t                ) { RYML_CHECK(t); substr src = t->copy_to_arena(json); parse_json_in_place(parser, filename, src, t, t->root_id()); }
void parse_json_in_arena(Parser *parser,                   csubstr json, Tree *t                ) { RYML_CHECK(t); substr src = t->copy_to_arena(json); parse_json_in_place(parser, {}      , src, t, t->root_id()); }
void parse_json_in_arena(Parser *parser, csubstr filename, csubstr json, NodeRef node           ) { RYML_CHECK(!node.invalid()); substr src = node.tree()->copy_to_arena(json); parse_json_in_place(parser, filename, src, node.tree(), node.id()); }
void parse_json_in_arena(Parser *parser,                   csubstr json, NodeRef node           ) { RYML_CHECK(!node.invalid()); substr src = node.tree()->copy_to_arena(json); parse_json_in_place(parser, {}      , src, node.tree(), node.id()); }
Tree parse_json_in_arena(Parser *parser, csubstr filename, csubstr json                         ) { RYML_CHECK(parser); RYML_CHECK(parser->m_evt_handler); Tree tree(parser->callbacks()); substr src = tree.copy_to_arena(json); parse_json_in_place(parser, filename, src, &tree, tree.root_id()); return tree; }
Tree parse_json_in_arena(Parser *parser,                   csubstr json                         ) { RYML_CHECK(parser); RYML_CHECK(parser->m_evt_handler); Tree tree(parser->callbacks()); substr src = tree.copy_to_arena(json); parse_json_in_place(parser, {}      , src, &tree, tree.root_id()); return tree; }

// this is vertically aligned to highlight the parameter differences.
void parse_json_in_arena(csubstr filename, csubstr json, Tree *t, id_type node_id) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); substr src = t->copy_to_arena(json); parse_json_in_place(&parser, filename, src, t, node_id); }
void parse_json_in_arena(                  csubstr json, Tree *t, id_type node_id) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); substr src = t->copy_to_arena(json); parse_json_in_place(&parser, {}      , src, t, node_id); }
void parse_json_in_arena(csubstr filename, csubstr json, Tree *t                ) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); substr src = t->copy_to_arena(json); parse_json_in_place(&parser, filename, src, t, t->root_id()); }
void parse_json_in_arena(                  csubstr json, Tree *t                ) { RYML_CHECK(t); Parser::handler_type event_handler(t->callbacks()); Parser parser(&event_handler); substr src = t->copy_to_arena(json); parse_json_in_place(&parser, {}      , src, t, t->root_id()); }
void parse_json_in_arena(csubstr filename, csubstr json, NodeRef node           ) { RYML_CHECK(!node.invalid()); Parser::handler_type event_handler(node.tree()->callbacks()); Parser parser(&event_handler); substr src = node.tree()->copy_to_arena(json); parse_json_in_place(&parser, filename, src, node.tree(), node.id()); }
void parse_json_in_arena(                  csubstr json, NodeRef node           ) { RYML_CHECK(!node.invalid()); Parser::handler_type event_handler(node.tree()->callbacks()); Parser parser(&event_handler); substr src = node.tree()->copy_to_arena(json); parse_json_in_place(&parser, {}      , src, node.tree(), node.id()); }
Tree parse_json_in_arena(csubstr filename, csubstr json                         ) { Parser::handler_type event_handler; Parser parser(&event_handler); Tree tree(parser.callbacks()); substr src = tree.copy_to_arena(json); parse_json_in_place(&parser, filename, src, &tree, tree.root_id()); return tree; }
Tree parse_json_in_arena(                  csubstr json                         ) { Parser::handler_type event_handler; Parser parser(&event_handler); Tree tree(parser.callbacks()); substr src = tree.copy_to_arena(json); parse_json_in_place(&parser, {}      , src, &tree, tree.root_id()); return tree; }


RYML_EXPORT C4_NO_INLINE size_t _find_last_newline_and_larger_indentation(csubstr s, size_t indentation) noexcept
{
    if(indentation + 1 > s.len)
        return npos;
    for(size_t i = s.len-indentation-1; i != size_t(-1); --i)
    {
        if(s.str[i] == '\n')
        {
            csubstr rem = s.sub(i + 1);
            size_t first = rem.first_not_of(' ');
            first = (first != npos) ? first : rem.len;
            if(first > indentation)
                return i;
        }
    }
    return npos;
}

//-----------------------------------------------------------------------------

RYML_EXPORT id_type estimate_tree_capacity(csubstr src)
{
    id_type num_nodes = 1; // root
    for(size_t i = 0; i < src.len; ++i)
    {
        const char c = src.str[i];
        num_nodes += (c == '\n') || (c == ',') || (c == '[') || (c == '{');
    }
    return num_nodes;
}

} // namespace yml
} // namespace c4

#endif /* RYML_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/parse.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/node.cpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/node.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef RYML_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/node.hpp
//#include "c4/yml/node.hpp"
#if !defined(C4_YML_NODE_HPP_) && !defined(_C4_YML_NODE_HPP_)
#error "amalgamate: file c4/yml/node.hpp must have been included at this point"
#endif /* C4_YML_NODE_HPP_ */


namespace c4 {
namespace yml {




//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

size_t NodeRef::set_key_serialized(c4::fmt::const_base64_wrapper w)
{
    _apply_seed();
    csubstr encoded = this->to_arena(w);
    this->set_key(encoded);
    return encoded.len;
}

size_t NodeRef::set_val_serialized(c4::fmt::const_base64_wrapper w)
{
    _apply_seed();
    csubstr encoded = this->to_arena(w);
    this->set_val(encoded);
    return encoded.len;
}

} // namespace yml
} // namespace c4

#endif /* RYML_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/node.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/preprocess.cpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/preprocess.cpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifdef RYML_SINGLE_HDR_DEFINE_NOW
// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/preprocess.hpp
//#include "c4/yml/preprocess.hpp"
#if !defined(C4_YML_PREPROCESS_HPP_) && !defined(_C4_YML_PREPROCESS_HPP_)
#error "amalgamate: file c4/yml/preprocess.hpp must have been included at this point"
#endif /* C4_YML_PREPROCESS_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/parser_dbg.hpp
//#include "c4/yml/detail/parser_dbg.hpp"
#if !defined(C4_YML_DETAIL_PARSER_DBG_HPP_) && !defined(_C4_YML_DETAIL_PARSER_DBG_HPP_)
#error "amalgamate: file c4/yml/detail/parser_dbg.hpp must have been included at this point"
#endif /* C4_YML_DETAIL_PARSER_DBG_HPP_ */


/** @file preprocess.hpp Functions for preprocessing YAML prior to parsing. */

namespace c4 {
namespace yml {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

namespace {
C4_ALWAYS_INLINE bool _is_idchar(char c)
{
    return (c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
        || (c >= '0' && c <= '9')
        || (c == '_' || c == '-' || c == '~' || c == '$');
}

typedef enum { kReadPending = 0, kKeyPending = 1, kValPending = 2 } _ppstate;
C4_ALWAYS_INLINE _ppstate _next(_ppstate s)
{
    int n = (int)s + 1;
    return (_ppstate)(n <= (int)kValPending ? n : 0);
}
} // empty namespace


//-----------------------------------------------------------------------------

size_t preprocess_rxmap(csubstr s, substr buf)
{
    detail::_SubstrWriter writer(buf);
    _ppstate state = kReadPending;
    size_t last = 0;

    if(s.begins_with('{'))
    {
        RYML_CHECK(s.ends_with('}'));
        s = s.offs(1, 1);
    }

    writer.append('{');

    for(size_t i = 0; i < s.len; ++i)
    {
        const char curr = s[i];
        const char next = i+1 < s.len ? s[i+1] : '\0';

        if(curr == '\'' || curr == '"')
        {
            csubstr ss = s.sub(i).pair_range_esc(curr, '\\');
            i += static_cast<size_t>(ss.end() - (s.str + i));
            state = _next(state);
        }
        else if(state == kReadPending && _is_idchar(curr))
        {
            state = _next(state);
        }

        switch(state)
        {
        case kKeyPending:
        {
            if(curr == ':' && next == ' ')
            {
                state = _next(state);
            }
            else if(curr == ',' && next == ' ')
            {
                writer.append(s.range(last, i));
                writer.append(": 1, ");
                last = i + 2;
            }
            break;
        }
        case kValPending:
        {
            if(curr == '[' || curr == '{' || curr == '(')
            {
                csubstr ss = s.sub(i).pair_range_nested(curr, '\\');
                i += static_cast<size_t>(ss.end() - (s.str + i));
                state = _next(state);
            }
            else if(curr == ',' && next == ' ')
            {
                state = _next(state);
            }
            break;
        }
        default:
            // nothing to do
            break;
        }
    }

    writer.append(s.sub(last));
    if(state == kKeyPending)
        writer.append(": 1");
    writer.append('}');

    return writer.pos;
}

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} // namespace yml
} // namespace c4

#endif /* RYML_SINGLE_HDR_DEFINE_NOW */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/preprocess.cpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/detail/checks.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/checks.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef C4_YML_DETAIL_CHECKS_HPP_
#define C4_YML_DETAIL_CHECKS_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/tree.hpp
//#include "c4/yml/tree.hpp"
#if !defined(C4_YML_TREE_HPP_) && !defined(_C4_YML_TREE_HPP_)
#error "amalgamate: file c4/yml/tree.hpp must have been included at this point"
#endif /* C4_YML_TREE_HPP_ */


#ifdef __clang__
#   pragma clang diagnostic push
#elif defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wtype-limits" // error: comparison of unsigned expression >= 0 is always true
#elif defined(_MSC_VER)
#   pragma warning(push)
#   pragma warning(disable: 4296/*expression is always 'boolean_value'*/)
#endif

namespace c4 {
namespace yml {


void check_invariants(Tree const& t, id_type node=NONE);
void check_free_list(Tree const& t);
void check_arena(Tree const& t);


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

inline void check_invariants(Tree const& t, id_type node)
{
    if(node == NONE)
    {
        if(t.size() == 0) return;
        node = t.root_id();
    }

    NodeData const& n = *t._p(node);
#if defined(RYML_DBG) && 0
    if(n.m_first_child != NONE || n.m_last_child != NONE)
    {
        printf("check(%zu): fc=%zu lc=%zu\n", node, n.m_first_child, n.m_last_child);
    }
    else
    {
        printf("check(%zu)\n", node);
    }
#endif

    C4_CHECK(n.m_parent != node);
    if(n.m_parent == NONE)
    {
        C4_CHECK(t.is_root(node));
    }
    else //if(n.m_parent != NONE)
    {
        C4_CHECK(t.has_child(n.m_parent, node));

        auto const& p = *t._p(n.m_parent);
        if(n.m_prev_sibling == NONE)
        {
            C4_CHECK(p.m_first_child == node);
            C4_CHECK(t.first_sibling(node) == node);
        }
        else
        {
            C4_CHECK(p.m_first_child != node);
            C4_CHECK(t.first_sibling(node) != node);
        }

        if(n.m_next_sibling == NONE)
        {
            C4_CHECK(p.m_last_child == node);
            C4_CHECK(t.last_sibling(node) == node);
        }
        else
        {
            C4_CHECK(p.m_last_child != node);
            C4_CHECK(t.last_sibling(node) != node);
        }
    }

    C4_CHECK(n.m_first_child != node);
    C4_CHECK(n.m_last_child != node);
    if(n.m_first_child != NONE || n.m_last_child != NONE)
    {
        C4_CHECK(n.m_first_child != NONE);
        C4_CHECK(n.m_last_child != NONE);
    }

    C4_CHECK(n.m_prev_sibling != node);
    C4_CHECK(n.m_next_sibling != node);
    if(n.m_prev_sibling != NONE)
    {
        C4_CHECK(t._p(n.m_prev_sibling)->m_next_sibling == node);
        C4_CHECK(t._p(n.m_prev_sibling)->m_prev_sibling != node);
    }
    if(n.m_next_sibling != NONE)
    {
        C4_CHECK(t._p(n.m_next_sibling)->m_prev_sibling == node);
        C4_CHECK(t._p(n.m_next_sibling)->m_next_sibling != node);
    }

    id_type count = 0;
    for(id_type i = n.m_first_child; i != NONE; i = t.next_sibling(i))
    {
#if defined(RYML_DBG) && 0
        printf("check(%zu):               descend to child[%zu]=%zu\n", node, count, i);
#endif
        auto const& ch = *t._p(i);
        C4_CHECK(ch.m_parent == node);
        C4_CHECK(ch.m_next_sibling != i);
        ++count;
    }
    C4_CHECK(count == t.num_children(node));

    if(n.m_prev_sibling == NONE && n.m_next_sibling == NONE)
    {
        if(n.m_parent != NONE)
        {
            C4_CHECK(t.num_children(n.m_parent) == 1);
            C4_CHECK(t.num_siblings(node) == 1);
        }
    }

    if(node == t.root_id())
    {
        C4_CHECK(t.size() == t.m_size);
        C4_CHECK(t.capacity() == t.m_cap);
        C4_CHECK(t.m_cap == t.m_size + t.slack());
        check_free_list(t);
        check_arena(t);
    }

    for(id_type i = t.first_child(node); i != NONE; i = t.next_sibling(i))
    {
        check_invariants(t, i);
    }
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

inline void check_free_list(Tree const& t)
{
    if(t.m_free_head == NONE)
    {
        C4_CHECK(t.m_free_tail == t.m_free_head);
        return;
    }

    C4_CHECK(t.m_free_head >= 0 && t.m_free_head < t.m_cap);
    C4_CHECK(t.m_free_tail >= 0 && t.m_free_tail < t.m_cap);

    auto const& head = *t._p(t.m_free_head);
    //auto const& tail = *t._p(t.m_free_tail);

    //C4_CHECK(head.m_prev_sibling == NONE);
    //C4_CHECK(tail.m_next_sibling == NONE);

    id_type count = 0;
    for(id_type i = t.m_free_head, prev = NONE; i != NONE; i = t._p(i)->m_next_sibling)
    {
        auto const& elm = *t._p(i);
        if(&elm != &head)
        {
            C4_CHECK(elm.m_prev_sibling == prev);
        }
        prev = i;
        ++count;
    }
    C4_CHECK(count == t.slack());
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

inline void check_arena(Tree const& t)
{
    C4_CHECK(t.m_arena.len == 0 || (t.m_arena_pos >= 0 && t.m_arena_pos <= t.m_arena.len));
    C4_CHECK(t.arena_size() == t.m_arena_pos);
    C4_CHECK(t.arena_slack() + t.m_arena_pos == t.m_arena.len);
}


} /* namespace yml */
} /* namespace c4 */

#ifdef __clang__
#   pragma clang diagnostic pop
#elif defined(__GNUC__)
#   pragma GCC diagnostic pop
#elif defined(_MSC_VER)
#   pragma warning(pop)
#endif

#endif /* C4_YML_DETAIL_CHECKS_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/detail/checks.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/detail/print.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/detail/print.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef C4_YML_DETAIL_PRINT_HPP_
#define C4_YML_DETAIL_PRINT_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/tree.hpp
//#include "c4/yml/tree.hpp"
#if !defined(C4_YML_TREE_HPP_) && !defined(_C4_YML_TREE_HPP_)
#error "amalgamate: file c4/yml/tree.hpp must have been included at this point"
#endif /* C4_YML_TREE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/node.hpp
//#include "c4/yml/node.hpp"
#if !defined(C4_YML_NODE_HPP_) && !defined(_C4_YML_NODE_HPP_)
#error "amalgamate: file c4/yml/node.hpp must have been included at this point"
#endif /* C4_YML_NODE_HPP_ */


#ifdef RYML_DBG
#define _c4dbg_tree(...) print_tree(__VA_ARGS__)
#define _c4dbg_node(...) print_tree(__VA_ARGS__)
#else
#define _c4dbg_tree(...)
#define _c4dbg_node(...)
#endif

namespace c4 {
namespace yml {

C4_SUPPRESS_WARNING_GCC_CLANG_WITH_PUSH("-Wold-style-cast")
C4_SUPPRESS_WARNING_GCC("-Wuseless-cast")

inline const char* _container_style_code(Tree const& p, id_type node)
{
    if(p.is_container(node))
    {
        if(p._p(node)->m_type & (FLOW_SL|FLOW_ML))
        {
            return "[FLOW]";
        }
        if(p._p(node)->m_type & (BLOCK))
        {
            return "[BLCK]";
        }
    }
    return "";
}
inline char _scalar_code(NodeType masked)
{
    if(masked & (KEY_LITERAL|VAL_LITERAL))
        return '|';
    if(masked & (KEY_FOLDED|VAL_FOLDED))
        return '>';
    if(masked & (KEY_SQUO|VAL_SQUO))
        return '\'';
    if(masked & (KEY_DQUO|VAL_DQUO))
        return '"';
    if(masked & (KEY_PLAIN|VAL_PLAIN))
        return '~';
    return '@';
}
inline char _scalar_code_key(NodeType t)
{
    return _scalar_code(t & KEY_STYLE);
}
inline char _scalar_code_val(NodeType t)
{
    return _scalar_code(t & VAL_STYLE);
}
inline char _scalar_code_key(Tree const& p, id_type node)
{
    return _scalar_code_key(p._p(node)->m_type);
}
inline char _scalar_code_val(Tree const& p, id_type node)
{
    return _scalar_code_key(p._p(node)->m_type);
}
inline id_type print_node(Tree const& p, id_type node, int level, id_type count, bool print_children)
{
    printf("[%zu]%*s[%zu] %p", (size_t)count, (2*level), "", (size_t)node, (void const*)p.get(node));
    if(p.is_root(node))
    {
        printf(" [ROOT]");
    }
    char typebuf[128];
    csubstr typestr = p.type(node).type_str(typebuf);
    RYML_CHECK(typestr.str);
    printf(" %.*s", (int)typestr.len, typestr.str);
    if(p.has_key(node))
    {
        if(p.has_key_anchor(node))
        {
            csubstr ka = p.key_anchor(node);
            printf(" &%.*s", (int)ka.len, ka.str);
        }
        if(p.has_key_tag(node))
        {
            csubstr kt = p.key_tag(node);
            printf(" <%.*s>", (int)kt.len, kt.str);
        }
        const char code = _scalar_code_key(p, node);
        csubstr k  = p.key(node);
        printf(" %c%.*s%c :", code, (int)k.len, k.str, code);
    }
    if(p.has_val_anchor(node))
    {
        csubstr a = p.val_anchor(node);
        printf(" &%.*s'", (int)a.len, a.str);
    }
    if(p.has_val_tag(node))
    {
        csubstr vt = p.val_tag(node);
        printf(" <%.*s>", (int)vt.len, vt.str);
    }
    if(p.has_val(node))
    {
        const char code = _scalar_code_val(p, node);
        csubstr v  = p.val(node);
        printf(" %c%.*s%c", code, (int)v.len, v.str, code);
    }
    printf("  (%zu sibs)", (size_t)p.num_siblings(node));

    ++count;

    if(!p.is_container(node))
    {
        printf("\n");
    }
    else
    {
        printf(" (%zu children)\n", (size_t)p.num_children(node));
        if(print_children)
        {
            for(id_type i = p.first_child(node); i != NONE; i = p.next_sibling(i))
            {
                count = print_node(p, i, level+1, count, print_children);
            }
        }
    }

    return count;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

inline void print_node(ConstNodeRef const& p, int level=0)
{
    print_node(*p.tree(), p.id(), level, 0, true);
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

inline id_type print_tree(const char *message, Tree const& p, id_type node=NONE)
{
    printf("--------------------------------------\n");
    if(message != nullptr)
        printf("%s:\n", message);
    id_type ret = 0;
    if(!p.empty())
    {
        if(node == NONE)
            node = p.root_id();
        ret = print_node(p, node, 0, 0, true);
    }
    printf("#nodes=%zu vs #printed=%zu\n", (size_t)p.size(), (size_t)ret);
    printf("--------------------------------------\n");
    return ret;
}

inline id_type print_tree(Tree const& p, id_type node=NONE)
{
    return print_tree(nullptr, p, node);
}

inline void print_tree(ConstNodeRef const& p, int level)
{
    print_node(p, level);
    for(ConstNodeRef ch : p.children())
    {
        print_tree(ch, level+1);
    }
}

C4_SUPPRESS_WARNING_GCC_CLANG_POP

} /* namespace yml */
} /* namespace c4 */


#endif /* C4_YML_DETAIL_PRINT_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/detail/print.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/c4/yml/yml.hpp
// https://github.com/biojppm/rapidyaml/src/c4/yml/yml.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _C4_YML_YML_HPP_
#define _C4_YML_YML_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/version.hpp
//#include "c4/yml/version.hpp"
#if !defined(C4_YML_VERSION_HPP_) && !defined(_C4_YML_VERSION_HPP_)
#error "amalgamate: file c4/yml/version.hpp must have been included at this point"
#endif /* C4_YML_VERSION_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/tree.hpp
//#include "c4/yml/tree.hpp"
#if !defined(C4_YML_TREE_HPP_) && !defined(_C4_YML_TREE_HPP_)
#error "amalgamate: file c4/yml/tree.hpp must have been included at this point"
#endif /* C4_YML_TREE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/node.hpp
//#include "c4/yml/node.hpp"
#if !defined(C4_YML_NODE_HPP_) && !defined(_C4_YML_NODE_HPP_)
#error "amalgamate: file c4/yml/node.hpp must have been included at this point"
#endif /* C4_YML_NODE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/emit.hpp
//#include "c4/yml/emit.hpp"
#if !defined(C4_YML_EMIT_HPP_) && !defined(_C4_YML_EMIT_HPP_)
#error "amalgamate: file c4/yml/emit.hpp must have been included at this point"
#endif /* C4_YML_EMIT_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/event_handler_tree.hpp
//#include "c4/yml/event_handler_tree.hpp"
#if !defined(C4_YML_EVENT_HANDLER_TREE_HPP_) && !defined(_C4_YML_EVENT_HANDLER_TREE_HPP_)
#error "amalgamate: file c4/yml/event_handler_tree.hpp must have been included at this point"
#endif /* C4_YML_EVENT_HANDLER_TREE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/parse_engine.hpp
//#include "c4/yml/parse_engine.hpp"
#if !defined(C4_YML_PARSE_ENGINE_HPP_) && !defined(_C4_YML_PARSE_ENGINE_HPP_)
#error "amalgamate: file c4/yml/parse_engine.hpp must have been included at this point"
#endif /* C4_YML_PARSE_ENGINE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/filter_processor.hpp
//#include "c4/yml/filter_processor.hpp"
#if !defined(C4_YML_FILTER_PROCESSOR_HPP_) && !defined(_C4_YML_FILTER_PROCESSOR_HPP_)
#error "amalgamate: file c4/yml/filter_processor.hpp must have been included at this point"
#endif /* C4_YML_FILTER_PROCESSOR_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/parse.hpp
//#include "c4/yml/parse.hpp"
#if !defined(C4_YML_PARSE_HPP_) && !defined(_C4_YML_PARSE_HPP_)
#error "amalgamate: file c4/yml/parse.hpp must have been included at this point"
#endif /* C4_YML_PARSE_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/preprocess.hpp
//#include "c4/yml/preprocess.hpp"
#if !defined(C4_YML_PREPROCESS_HPP_) && !defined(_C4_YML_PREPROCESS_HPP_)
#error "amalgamate: file c4/yml/preprocess.hpp must have been included at this point"
#endif /* C4_YML_PREPROCESS_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/reference_resolver.hpp
//#include "c4/yml/reference_resolver.hpp"
#if !defined(C4_YML_REFERENCE_RESOLVER_HPP_) && !defined(_C4_YML_REFERENCE_RESOLVER_HPP_)
#error "amalgamate: file c4/yml/reference_resolver.hpp must have been included at this point"
#endif /* C4_YML_REFERENCE_RESOLVER_HPP_ */

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/tag.hpp
//#include "c4/yml/tag.hpp"
#if !defined(C4_YML_TAG_HPP_) && !defined(_C4_YML_TAG_HPP_)
#error "amalgamate: file c4/yml/tag.hpp must have been included at this point"
#endif /* C4_YML_TAG_HPP_ */


#endif // _C4_YML_YML_HPP_


// (end https://github.com/biojppm/rapidyaml/src/c4/yml/yml.hpp)



//********************************************************************************
//--------------------------------------------------------------------------------
// src/ryml.hpp
// https://github.com/biojppm/rapidyaml/src/ryml.hpp
//--------------------------------------------------------------------------------
//********************************************************************************

#ifndef _RYML_HPP_
#define _RYML_HPP_

// amalgamate: removed include of
// https://github.com/biojppm/rapidyaml/src/c4/yml/yml.hpp
//#include "c4/yml/yml.hpp"
#if !defined(C4_YML_YML_HPP_) && !defined(_C4_YML_YML_HPP_)
#error "amalgamate: file c4/yml/yml.hpp must have been included at this point"
#endif /* C4_YML_YML_HPP_ */


namespace ryml {
using namespace c4::yml;
using namespace c4;
}

#endif /* _RYML_HPP_ */


// (end https://github.com/biojppm/rapidyaml/src/ryml.hpp)

#endif /* _RYML_SINGLE_HEADER_AMALGAMATED_HPP_ */

