#pragma once

namespace cpp_traits::detail {

template <class T, bool B>
struct function_traits_deduction_impl {};

template <class T>
struct function_traits_deduction_impl<T, true> {
  using type = T;
};

template <class T>
struct function_traits_deduction_impl<T, false> {
  using type = decltype(&T::operator());
};

} // namespace cpp_traits::detail