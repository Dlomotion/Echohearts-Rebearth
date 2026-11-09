cmake_minimum_required(VERSION 3.20)
project(EchoHeartsRebirth3D LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# raylib is fetched automatically — no manual install needed.
# In Visual Studio 2022: File > Open > Folder, select this folder, then Build.
# In VS Code: install the CMake Tools extension, then Configure + Build.
include(FetchContent)
FetchContent_Declare(raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

add_executable(EchoHeartsRebirth3D src/main.cpp)
target_include_directories(EchoHeartsRebirth3D PRIVATE src)
target_link_libraries(EchoHeartsRebirth3D PRIVATE raylib)

# Logic tests build and run without raylib / a window.
add_executable(echohearts_logic_test tests/logic_test.cpp)
target_include_directories(echohearts_logic_test PRIVATE src)
enable_testing()
add_test(NAME logic COMMAND echohearts_logic_test)
