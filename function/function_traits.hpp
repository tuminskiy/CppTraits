#pragma once

#include <utility>

#include "detail/function_traits_impl.hpp"
#include "detail/function_traits_deduction.hpp"

namespace cpp_traits {

template <class T>
class function_traits : public detail::function_traits_impl<
  detail::function_traits_deduction_t<T>
> {

  using base_type = detail::function_traits_impl<
    detail::function_traits_deduction_t<T>
  >;

  template <class Visitor, std::size_t... Is>
  static void visit_args_impl(Visitor v, std::index_sequence<Is...>) {
    (v(typename base_type::template arg<Is>{}), ...);
  }

public:
  template <class Visitor>
  static void visit_args(Visitor v) {
    visit_args_impl(v, std::make_index_sequence<base_type::args_count>{});
  };
};

} // namespace cpp_traits