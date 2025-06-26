cmake_minimum_required(VERSION 3.15)
project(BoostAsioMicroservice VERSION 1.0.0 LANGUAGES CXX)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Поиск необходимых пакетов
find_package(Boost 1.66 REQUIRED COMPONENTS system)

# Настройка include директорий
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
)

# Создание исполняемого файла
add_executable(BoostAsioMicroservice
    src/main.cpp
    src/microservice.cpp
    src/echo_handler.cpp
    src/calculator_handler.cpp
)

# Подключение зависимостей
target_link_libraries(BoostAsioMicroservice
    PRIVATE Boost::system
)

# Опционально: установка
install(TARGETS microservice DESTINATION bin)

# Включение тестов
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
