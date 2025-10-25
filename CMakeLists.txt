cmake_minimum_required(VERSION 3.14)
project(Lab_OOP CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Основные исходники
file(GLOB SRC "src/*.cpp")

# Создание исполняемого файла
add_executable(Lab_OOP ${SRC})

# ---------------- Google Test ----------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
   DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Собираем тесты
file(GLOB TEST_SRC "tests/*.cpp")
add_executable(tests ${TEST_SRC} ${SRC})
target_link_libraries(tests gtest_main gtest)

add_test(NAME AllTests COMMAND tests)
