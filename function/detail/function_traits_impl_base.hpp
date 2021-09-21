#pragma once

#include <tuple>

namespace cpp_traits::detail {

template <class ReturnType, class... Args>
struct function_traits_impl_base {
  using result_type = ReturnType;

  static constexpr auto args_count = sizeof...(Args);

  template <std::size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};

} // namespace cpp_traits::detail