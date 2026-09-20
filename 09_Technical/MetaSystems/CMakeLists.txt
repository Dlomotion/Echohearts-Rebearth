cmake_minimum_required(VERSION 3.16)
project(EchoheartsMetaSystemsVerification LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(meta_systems_verify MetaSystemsVerification.cpp)
target_compile_options(meta_systems_verify PRIVATE -Wall -Wextra -Werror)

enable_testing()
add_test(NAME EchoheartsMetaSystemsVerification COMMAND meta_systems_verify)
