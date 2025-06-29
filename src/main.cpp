#include <iostream>
#include <string>
#include <curl/curl.h>
#include "../include/config.h"
#include "../include/json.hpp"

using json = nlohmann::json;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    try {
        s->append((char*)contents, newLength);
    } catch (std::bad_alloc &e) {
        return 0;
    }
    return newLength;
}

int main() {
    std::string city;
    std::cout << "Enter city name: ";
    std::getline(std::cin, city);

    for (auto& c : city) {
        if (c == ' ') c = '+';
    }

    std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city +
                      "&appid=" + WEATHER_API_KEY + "&units=metric";

    CURL* curl = curl_easy_init();
    std::string readBuffer;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Failed to initialize curl" << std::endl;
        return 1;
    }

    try {
        auto j = json::parse(readBuffer);

        if (j.contains("cod") && j["cod"] != 200) {
            std::cerr << "Error: " << j["message"] << std::endl;
            return 1;
        }

        double temp = j["main"]["temp"];
        int humidity = j["main"]["humidity"];
        std::string weather = j["weather"][0]["description"];

        std::cout << "\nWeather in " << city << ":\n";
        std::cout << "Temperature: " << temp << " °C\n";
        std::cout << "Humidity: " << humidity << " %\n";
        std::cout << "Description: " << weather << "\n";
    } catch (std::exception& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
