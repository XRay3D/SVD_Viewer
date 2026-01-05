cmake_minimum_required(VERSION 3.10)
project(Generated)

set(CMAKE_CXX_STANDARD 20)

# Находим tinyxml2
find_package(tinyxml2 REQUIRED)

# Создаем библиотеку
add_library(xsd_generated
    Enums.cpp
)

target_include_directories(xsd_generated
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(xsd_generated
    PUBLIC
        tinyxml2::tinyxml2
)
