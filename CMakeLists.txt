cmake_minimum_required(VERSION 3.10)
project(WeatherApp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(${CMAKE_SOURCE_DIR})

add_executable(weather_app src/main.cpp)

find_package(CURL REQUIRED)
target_link_libraries(weather_app CURL::libcurl)
