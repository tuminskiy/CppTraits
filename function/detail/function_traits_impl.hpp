#pragma once

#include "function_traits_impl_base.hpp"

namespace cpp_traits::detail {

template <class T>
struct function_traits_impl{};


template <class ReturnType, class... Args>
struct function_traits_impl<ReturnType(Args...)>
  : public function_traits_impl_base<ReturnType, Args...>
{};


template <class ClassType, class ReturnType, class... Args>
struct function_traits_impl<ReturnType(ClassType::*)(Args...) const>
  : public function_traits_impl_base<ReturnType, Args...>
{};

template <class ClassType, class ReturnType, class... Args>
struct function_traits_impl<ReturnType(ClassType::*)(Args...)>
  : public function_traits_impl_base<ReturnType, Args...>
{};

} // namespace cpp_traits::detail