#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy) {
    *this = cpy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy) {
    if (this != &copy) {
        this->_data = copy._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {};

bool BitcoinExchange::loadDatabase(const std::string& path) {
    std::ifstream dbFile(path.c_str());
    if (!dbFile.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return false;
    }

    std::string line;
    std::getline(dbFile, line);

    while (std::getline(dbFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string date = line.substr(0, commaPos);
            float rate = static_cast<float>(atof(line.substr(commaPos + 1).c_str()));
            _data[date] = rate;
        }
    }
    dbFile.close();
    return true;
}

void BitcoinExchange::processInput(const std::string& path) {
    std::ifstream inputFile(path.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipePos - 1);
        std::string valStr = line.substr(pipePos + 1);
        float value = static_cast<float>(atof(valStr.c_str()));

        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _data.find(date);
        if (it == _data.end()) {
            it = _data.upper_bound(date);
            if (it != _data.begin()) {
                --it;
            } else {
                std::cerr << "Error: no earlier date found for " << date << std::endl;
                continue;
            }
        }
        
        std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
    }
}