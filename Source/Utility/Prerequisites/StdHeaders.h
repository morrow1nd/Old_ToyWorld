#pragma once

#ifdef __BORLANDC__
#define __STD_ALGORITHM
#endif

//#include <cassert>
//#include <cstdio>
//#include <cstdlib>
//#include <ctime>
//#include <cstring>
//#include <cstdarg>
//#include <cmath>

//#include <memory>

// STL containers
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <array>
#include <unordered_map>
#include <unordered_set>

// STL algorithms & functions
#include <algorithm>
#include <functional>
#include <limits>

// C++ Stream stuff
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <sstream>

extern "C" {
#   include <sys/types.h>
#   include <sys/stat.h>
}

//#if TOY_WORLD_PLATFORM == TOY_WORLD_PLATFORM_WIN
#  undef min
#  undef max
#	if !defined(NOMINMAX) && defined(_MSC_VER)
#		define NOMINMAX // required to stop windows.h messing up std::min
#	endif
#  if defined( __MINGW32__ )
#    include <unistd.h>
#  endif
//#endif

//#if TOY_WORLD_PLATFORM == TOY_WORLD_PLATFORM_LINUX
//extern "C" {
//#   include <unistd.h>
//#   include <dlfcn.h>
//}
//#endif
//
//#if TOY_WORLD_PLATFORM == TOY_WORLD_PLATFORM_OSX
//extern "C" {
//#   include <unistd.h>
//#   include <sys/param.h>
//#   include <CoreFoundation/CoreFoundation.h>
//}
//#endif


namespace ToyWorld
{
/**
* Hash for enum types, to be used instead of std::hash<T> when T is an enum.
*
* Until C++14, std::hash<T> is not defined if T is a enum (see
* http://www.open-std.org/jtc1/sc22/wg21/docs/lwg-defects.html#2148).  But
* even with C++14, as of october 2016, std::hash for enums is not widely
* implemented by compilers, so here when T is a enum, we use EnumClassHash
* instead of std::hash. (For instance, in bs::hash_combine(), or
* bs::UnorderedMap.)
*/
struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

/** @addtogroup Containers
*  @{
*/

/** Hasher that handles custom enums automatically. */
template <typename Key>
using HashType = typename std::conditional<std::is_enum<Key>::value, EnumClassHash, std::hash<Key>>::type;

/** Double ended queue. Allows for fast insertion and removal at both its beggining and end. */
template <typename T, typename A = std::allocator<T>>
using Deque = std::deque<T, A>;

/** Dynamically sized array that stores element contigously. */
template <typename T, typename A = std::allocator<T>>
using Vector = std::vector<T, A>;

/** Container that supports constant time insertion and removal, but without fast random access to elements. */
template <typename T, typename A = std::allocator<T>>
using List = std::list<T, A>;

/** First-in, last-out data structure. */
template <typename T, typename A = std::allocator<T>>
using Stack = std::stack<T, std::deque<T, A>>;

/** First-in, first-out data structure. */
template <typename T, typename A = std::allocator<T>>
using Queue = std::queue<T, std::deque<T, A>>;

/** An associative container containing an ordered set of elements. */
template <typename T, typename P = std::less<T>, typename A = std::allocator<T>>
using Set = std::set<T, P, A>;

/** An associative container containing an ordered set of key-value pairs. */
template <typename K, typename V, typename P = std::less<K>, typename A = std::allocator<std::pair<const K, V>>>
using Map = std::map<K, V, P, A>;

/** An associative container containing an ordered set of key-value pairs where multiple elements can have the same key. */
template <typename K, typename V, typename P = std::less<K>, typename A = std::allocator<std::pair<const K, V>>>
using MultiMap = std::multimap<K, V, P, A>;

/** An associative container containing an unordered set of elements. Usually faster than Set for larger data sets. */
template <typename T, typename H = HashType<T>, typename C = std::equal_to<T>, typename A = std::allocator<T>>
using UnorderedSet = std::unordered_set<T, H, C, A>;

/** An associative container containing an ordered set of key-value pairs. Usually faster than Map for larger data sets. */
template <typename K, typename V, typename H = HashType<K>, typename C = std::equal_to<K>, typename A = std::allocator<std::pair<const K, V>>>
using UnorderedMap = std::unordered_map<K, V, H, C, A>;

/**
* An associative container containing an ordered set of key-value pairs where multiple elements can have the same key.
* Usually faster than MultiMap for larger data sets.
*/
template <typename K, typename V, typename H = HashType<K>, typename C = std::equal_to<K>, typename A = std::allocator<std::pair<const K, V>>>
using UnorderedMultimap = std::unordered_multimap<K, V, H, C, A>;

/** Equivalent to Vector, except it avoids any dynamic allocations until the number of elements exceeds @p Count. */
template <typename T, int Count>
using SmallVector = std::vector<T, std::allocator<T>>; // TODO: Currently equivalent to Vector, need to implement the allocator

/** @} */


/** Basic string that uses Banshee memory allocators. */
template <typename T>
using BasicString = std::basic_string < T, std::char_traits<T>, std::allocator<T> >;

/**	Basic string stream that uses Banshee memory allocators. */
template <typename T>
using BasicStringStream = std::basic_stringstream < T, std::char_traits<T>, std::allocator<T> >;

/** Wide string used primarily for handling Unicode text (UTF-32 on Linux, UTF-16 on Windows, generally). */
typedef BasicString<wchar_t> WString;

/** Narrow string used for handling narrow encoded text (either locale specific ANSI or UTF-8). */
typedef BasicString<char> String;

/** Wide string used UTF-16 encoded strings. */
typedef BasicString<char16_t> U16String;

/** Wide string used UTF-32 encoded strings. */
typedef BasicString<char32_t> U32String;

/** Wide string stream used for primarily for constructing wide strings. */
typedef BasicStringStream<wchar_t> WStringStream;

/** Wide string stream used for primarily for constructing narrow strings. */
typedef BasicStringStream<char> StringStream;

/** Wide string stream used for primarily for constructing UTF-16 strings. */
typedef BasicStringStream<char16_t> U16StringStream;

/** Wide string stream used for primarily for constructing UTF-32 strings. */
typedef BasicStringStream<char32_t> U32StringStream;

/** Equivalent to String, except it avoids any dynamic allocations until the number of elements exceeds @p Count. */
template <int Count>
using SmallString = std::basic_string <char, std::char_traits<char>, std::allocator<char>>; // TODO: Currently equivalent to String, need to implement the allocator


/** @addtogroup Memory
*  @{
*/
//
///**
//* Smart pointer that retains shared ownership of an project through a pointer. The object is destroyed automatically
//* when the last shared pointer to the object is destroyed.
//*/
//template <typename T>
//using SPtr = std::shared_ptr<T>;
//
///**
//* Smart pointer that retains shared ownership of an project through a pointer. Reference to the object must be unique.
//* The object is destroyed automatically when the pointer to the object is destroyed.
//*/
//template <typename T, typename Alloc = GenAlloc>
//using UPtr = std::unique_ptr<T, decltype(&bs_delete<T, Alloc>)>;
//
///** Create a new shared pointer using a custom allocator category. */
//template<class Type, class AllocCategory, class... Args>
//SPtr<Type> bs_shared_ptr_new(Args &&... args)
//{
//    return std::allocate_shared<Type>(std::allocator<Type, AllocCategory>(), std::forward<Args>(args)...);
//}
//
///** Create a new shared pointer using the default allocator category. */
//template<class Type, class... Args>
//SPtr<Type> bs_shared_ptr_new(Args &&... args)
//{
//    return std::allocate_shared<Type>(std::allocator<Type, GenAlloc>(), std::forward<Args>(args)...);
//}
//
///**
//* Create a new shared pointer from a previously constructed object.
//* Pointer specific data will be allocated using the provided allocator category.
//*/
//template<class Type, class MainAlloc = GenAlloc, class PtrDataAlloc = GenAlloc>
//SPtr<Type> bs_shared_ptr(Type* data)
//{
//    return SPtr<Type>(data, &bs_delete<Type, MainAlloc>, std::allocator<Type, PtrDataAlloc>());
//}
//
///**
//* Create a new unique pointer from a previously constructed object.
//* Pointer specific data will be allocated using the provided allocator category.
//*/
//template<class Type, class Alloc = GenAlloc>
//UPtr<Type, Alloc> bs_unique_ptr(Type* data)
//{
//    return std::unique_ptr<Type, decltype(&bs_delete<Type, Alloc>)>(data, bs_delete<Type, Alloc>);
//}
//
///** Create a new unique pointer using a custom allocator category. */
//template<class Type, class Alloc, class... Args>
//UPtr<Type> bs_unique_ptr_new(Args &&... args)
//{
//    Type* rawPtr = bs_new<Type, Alloc>(std::forward<Args>(args)...);
//
//    return bs_unique_ptr<Type, Alloc>(rawPtr);
//}
//
///** Create a new unique pointer using the default allocator category. */
//template<class Type, class... Args>
//UPtr<Type> bs_unique_ptr_new(Args &&... args)
//{
//    Type* rawPtr = bs_new<Type, GenAlloc>(std::forward<Args>(args)...);
//
//    return bs_unique_ptr<Type, GenAlloc>(rawPtr);
//}
//
///** @} */


} // end of namespace ToyWorld