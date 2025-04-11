#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void processInput(const std::string& filename, BitcoinExchange& btc) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    bool firstline = true;
    while (std::getline(file, line)) {
        
        if(firstline){
            if(line == "date | value"){
                firstline = false;
                continue;
            }
            else{
                std::cout << "wrong header line" << std::endl;
                return;
            }
        }
        std::stringstream ss(line);
        
        std::string date, separator, valueStr;
        if (!(std::getline(ss, date, ' ')) || 
            !std::getline(ss, separator, ' ') || 
            !std::getline(ss, valueStr) || 
            separator != "|") {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!btc.isValidDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        char* endptr;
        float value = static_cast<float>(std::strtod(valueStr.c_str(), &endptr));
        if (*endptr != '\0' || endptr == valueStr.c_str()) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (!btc.isValidValue(value)) {
            if (value < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else
                std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = btc.getExchangeRate(date);
        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}

std::string findCsvFile() {
    DIR* dir = opendir(".");
    if (!dir) {
        return "";
    }
    struct dirent* entry;
    while ((entry = readdir(dir))) {
        std::string filename = entry->d_name;
        if (filename.length() >= 4 && 
            filename.substr(filename.length() - 4) == ".csv") {
            closedir(dir);
            return filename;
        }
    }
    closedir(dir);
    return "";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string outputFilename = findCsvFile();
    try {
        BitcoinExchange btc;
        btc.loadDatabase(outputFilename);
        processInput(argv[1], btc);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}