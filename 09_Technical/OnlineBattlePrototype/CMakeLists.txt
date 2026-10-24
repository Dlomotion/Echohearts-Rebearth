cmake_minimum_required(VERSION 3.16)
project(EchoheartsOnlineBattlePrototype LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(online_battle_verification OnlineBattleVerification.cpp)
target_include_directories(online_battle_verification PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if (MSVC)
    target_compile_options(online_battle_verification PRIVATE /W4 /permissive-)
else()
    target_compile_options(online_battle_verification PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
