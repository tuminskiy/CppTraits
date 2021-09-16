#include <type_traits>

namespace cpp_traits::detail {

template <class T>
struct function_traits_impl{};


template <class ReturnType, class... Args>
struct function_traits_impl<ReturnType(Args...)> {

  using result_type = ReturnType;

  static constexpr auto args_count = sizeof...(Args);

  template <std::size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};


template <class ClassType, class ReturnType, class... Args>
struct function_traits_impl<ReturnType(ClassType::*)(Args...) const>
{
  using result_type = ReturnType;

  static constexpr auto args_count = sizeof...(Args);

  template <std::size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};

} // namespace cpp_traits::detail