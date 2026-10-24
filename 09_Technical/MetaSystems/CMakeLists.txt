cmake_minimum_required(VERSION 3.16)
project(EchoheartsMetaSystemsVerification LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(meta_systems_verify MetaSystemsVerification.cpp)
if(MSVC)
    target_compile_options(meta_systems_verify PRIVATE /W4 /WX)
else()
    target_compile_options(meta_systems_verify PRIVATE -Wall -Wextra -Werror)
endif()

enable_testing()
add_test(NAME EchoheartsMetaSystemsVerification COMMAND meta_systems_verify)

# Prove a failed expectation exits nonzero even when NDEBUG is enabled.
add_test(NAME EchoheartsMetaSystemsFailurePath COMMAND meta_systems_verify --self-test-failure)
set_tests_properties(EchoheartsMetaSystemsFailurePath PROPERTIES WILL_FAIL TRUE)
