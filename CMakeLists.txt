cmake_minimum_required(VERSION 3.14)
project(ListaSpesaObserver)
set(CMAKE_CXX_STANDARD 11)

# App principale
add_executable(lista main.cpp ShoppingList.cpp User.cpp)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Test
enable_testing()
add_executable(lista_tests tests/test_main.cpp ShoppingList.cpp User.cpp)
target_link_libraries(lista_tests gtest gtest_main)
target_include_directories(lista_tests PRIVATE .)
gtest_discover_tests(lista_tests)
