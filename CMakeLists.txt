cmake_minimum_required(VERSION 3.15.0)
project(CppTraits)

add_executable(function_traits_example)

set_target_properties(function_traits_example PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)

target_sources(function_traits_example PRIVATE examples/function_traits.cpp)