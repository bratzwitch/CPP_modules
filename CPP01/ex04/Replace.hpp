#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace {
public:
    static void processFile(const std::string& filename, const std::string& s1, const std::string& s2);
};

#endif