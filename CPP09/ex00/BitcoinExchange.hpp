#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <dirent.h>

class BitcoinExchange {
    private:
        std::map<std::string, float> exchangeRates;
    
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy)
        void loadDatabase(const std::string& file);
        float getExchangeRate(const std::string& date) const;
        bool isValidDate(std::string& date);
        bool isValidValue(float value) const;
};
#endif