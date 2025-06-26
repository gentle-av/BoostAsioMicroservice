cmake_minimum_required(VERSION 3.15)
project(boost_asio_microservice VERSION 2.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Поиск Boost (только для реализации)
find_package(Boost 1.75 REQUIRED COMPONENTS system)

# Основная библиотека
add_library(microservice_core STATIC
    src/microservice.cpp
    src/echo_handler.cpp
    src/calculator_handler.cpp
)

target_include_directories(microservice_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${Boost_INCLUDE_DIRS}
)

target_link_libraries(microservice_core PRIVATE Boost::system)

# Основной исполняемый файл
add_executable(microservice src/main.cpp)
target_link_libraries(microservice PRIVATE microservice_core)

# Тесты
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
