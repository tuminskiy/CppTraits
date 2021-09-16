#include <type_traits>

#include "function_traits_deduction_impl.hpp"

namespace cpp_traits::detail {

template <class T>
struct function_traits_deduction
  : public detail::function_traits_deduction_impl<T, std::is_function_v<T>>
{};

template <class T>
using function_traits_deduction_t = typename function_traits_deduction<T>::type;

} // namespace cpp_traits::detail


