# 🌦️ Weather App in C++

A simple terminal-based weather application written in **C++**. It fetches real-time weather data from the **OpenWeatherMap API**, using:

- [`libcurl`](https://curl.se/libcurl/) for handling HTTP requests
- [`nlohmann::json`](https://github.com/nlohmann/json) for JSON parsing

This app allows the user to enter any **city name** at runtime and shows the current temperature, humidity, and weather description in that location.

---

## ✅ Features

- Command-line interface for city input
- Real-time weather data using public API
- Uses modern C++ (C++17)
- Cleanly structured with separate config and build system

---

## 📦 Requirements

Make sure your system has the following installed:

- **g++** (C++ compiler)
- **CMake** (build tool)
- **libcurl** (HTTP client library)

On Ubuntu/Debian-based systems:

```bash
xargs -a requirements.txt sudo apt install -y
```

## 🔑 Get Your Free Weather API Key

This app uses the **OpenWeatherMap API**, which requires an API key. Follow these steps to get yours:

1. Visit: [https://openweathermap.org/api](https://openweathermap.org/api)
2. Click on **"Sign Up"** (top-right corner) and create a free account
3. Go to your **Dashboard** after signing in
4. Under **"API keys"**, you will find a default key (or create a new one)
5. Copy that API key for use in the project

---

## 🛠️ Setup Instructions

### 1. Clone the project

If you're downloading this project from GitHub:

```bash
git clone https://github.com/yourusername/weather_app_cpp.git
cd weather_app_cpp
```

### 🚀 Run the App

From the `build/` folder:

```bash
./weather_app
```

Then enter a city name, for example:

```yaml
Enter city name: Paris

Weather in Paris:
Temperature: 21.56 °C
Humidity: 65 %
Description: clear sky
```

## 🧱 File Structure
```text
weather_app/
│
├── include/
│   └── config.h              # API key stored here
│
├── src/
│   └── main.cpp              # Main program
│
├── json.hpp                  # Header-only JSON library
├── requirements.txt          # System package dependencies
├── CMakeLists.txt            # CMake build instructions
└── README.md                 # You're reading this!
```
## 📚 Dependencies
- nlohmann::json – included as json.hpp
- libcurl – installed via your system package manager







