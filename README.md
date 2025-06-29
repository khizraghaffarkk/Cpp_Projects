# Weather App in C++

A simple terminal-based weather app written in C++ using libcurl and nlohmann JSON.

## Requirements

- CMake
- g++
- libcurl

## Setup

1. Install dependencies:
    ```bash
    xargs -a requirements.txt sudo apt install -y
    ```

2. Insert your API key in `include/config.h`.

3. Build:
    ```bash
    mkdir build && cd build
    cmake ..
    make
    ./weather_app
    ```

## Author
Khizra Ghaffar