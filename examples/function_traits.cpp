#include <iostream>
#include <typeinfo>
#include <iomanip>

#include "../function/function_traits.hpp"

class MyClass {};

template <class Traits>
void print_traits_info();

void my_function(MyClass, char) {}


int main() {
  using namespace cpp_traits;

  auto my_lambda1 = [](char, MyClass) { return 42; };
  auto my_lambda2 = [i = 1]() mutable { return ++i; };


  using lambda1_traits = function_traits<decltype(my_lambda1)>;

  std::cout << "--- Lambda1 traits info ---\n";
  print_traits_info<lambda1_traits>();


  using lambda2_traits = function_traits<decltype(my_lambda2)>;

  std::cout << "\n--- Lambda2 traits info ---\n";
  print_traits_info<lambda2_traits>();


  using func_traits = function_traits<decltype(my_function)>;

  std::cout << "\n--- Func traits info ---\n";
  print_traits_info<func_traits>();

  return 0;
}

// Output:
// --- Lambda1 traits info ---
// Return type: i
// Args count: 2
// Args types: "c" "7MyClass"
//
// --- Lambda2 traits info ---
// Return type: i
// Args count: 0
// Args types:
// 
// --- Func traits info ---
// Return type: v
// Args count: 2
// Args types: "7MyClass" "c"

template <class Traits>
void print_traits_info() {
  auto arg_printer = [](auto arg) {
    using T = typename decltype(arg)::type;

    std::cout << ' ' << std::quoted(typeid(T).name());
  };

  std::cout << "Return type: " << typeid(typename Traits::result_type).name() << '\n'
            << "Args count: " << Traits::args_count << '\n'
            << "Args types:";
  
  Traits::visit_args(arg_printer);

  std::cout << '\n';
}