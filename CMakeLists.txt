cmake_minimum_required(VERSION 3.20)
project(boost_asio_microservice VERSION 2.0.0 LANGUAGES CXX)

# Настройка стандарта C++20 с модулями
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Поддержка модулей
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.20)
    set(CMAKE_CXX_SCAN_FOR_MODULES ON)
endif()

# Поиск Boost (только для реализации)
find_package(Boost 1.75 REQUIRED COMPONENTS system)

# Настройка модулей
add_library(microservice_core)
target_sources(microservice_core
    PUBLIC
    FILE_SET all_headers TYPE HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
    FILES
        include/request_handler.ixx
        include/microservice.ixx
        include/echo_handler.ixx
        include/calculator_handler.ixx
    PRIVATE
        src/microservice.cpp
        src/microservice_private.cpp
        src/echo_handler.cpp
        src/calculator_handler.cpp
)

target_link_libraries(microservice_core
    PRIVATE 
    Boost::system
)

# Основной исполняемый файл
add_executable(microservice src/main.cpp)
target_link_libraries(microservice PRIVATE microservice_core)

# Тесты
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
