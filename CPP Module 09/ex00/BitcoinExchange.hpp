#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, float> _data;
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& cpy);
    BitcoinExchange& operator=(const BitcoinExchange& copy);
    ~BitcoinExchange();
    bool    loadDatabase(const std::string& path);
    void    processInput(const std::string& path);
};

#endif