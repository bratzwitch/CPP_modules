#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file");
    
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, priceStr;
        if (std::getline(ss, date, ',') && std::getline(ss, priceStr)) {
            char* endptr;
            float price = static_cast<float>(std::strtod(priceStr.c_str(), &endptr));
            if (*endptr == '\0' && endptr != priceStr.c_str()) {
                exchangeRates[date] = price;
            }
        }
    }
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    if (exchangeRates.empty()) {
        return 0;
    }
    std::map<std::string, float>::const_iterator it = exchangeRates.find(date);
    if (it != exchangeRates.end()) {
        return it->second;
    }
    it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.begin()) {
        return -1;
    }
    --it;
    return it->second;
}

bool BitcoinExchange::isValidDate(std::string& date){
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    std::stringstream ss(date);
    std::string yearStr, monthStr, dayStr;
    if (!std::getline(ss, yearStr, '-') || 
        !std::getline(ss, monthStr, '-') || 
        !std::getline(ss, dayStr))
        return false;

    char* endptr;
    std::strtol(yearStr.c_str(), &endptr, 10);
    if (*endptr != '\0' || endptr == yearStr.c_str()) 
        return false;
    
    long month = std::strtol(monthStr.c_str(), &endptr, 10);
    if (*endptr != '\0' || endptr == monthStr.c_str())
        return false;
    
    long day = std::strtol(dayStr.c_str(), &endptr, 10);
    if (*endptr != '\0' || endptr == dayStr.c_str())
        return false;
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

bool BitcoinExchange::isValidValue(float value) const {
    return value >= 0 && value <= 1000;
}