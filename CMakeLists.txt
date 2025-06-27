cmake_minimum_required(VERSION 3.15)
project(boost_asio_microservice VERSION 2.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost 1.75 REQUIRED COMPONENTS system)

add_library(microservice_core SHARED
  src/request_handler.cpp
  src/microservice.cpp
  src/microservice_private.cpp
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

add_executable(microservice src/main.cpp)
target_link_libraries(microservice PRIVATE microservice_core)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
