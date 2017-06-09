#ifndef MYTINYSTL_UTIL_H_
#define MYTINYSTL_UTIL_H_

// 这个文件包含一些通用工具

#include "type_traits.h"

namespace mystl
{

template <class T> inline constexpr 
typename mystl::remove_reference<T>::type&& move(T&& arg) noexcept
{
  return static_cast<typename mystl::remove_reference<T>::type&&>(arg);
}

template <class T> inline constexpr 
T&& forward(typename mystl::remove_reference<T>::type& arg) noexcept
{
  return static_cast<T&&>(arg);
}

template <class T> inline constexpr 
T&& forward(typename mystl::remove_reference<T>::type&& arg) noexcept
{
  static_assert(!mystl::is_lvalue_reference<T>::value, "bad forward");
  return static_cast<T&&>(arg);
}

}

#endif // !MYTINYSTL_UTIL_H_

