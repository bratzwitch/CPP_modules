#include "ScalarConverter.hpp"

#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        std::cerr << "./convert <literal>" << std::endl;
        return 1;
    }
    std::string str(argv[1]);
    size_t start = str.find_first_not_of(" \t");
    if (start == std::string::npos) {
        std::cout << "no good" << std::endl;
        return 1;
    }
    size_t end = str.find_last_not_of(" \t");
    str = str.substr(start, end - start + 1);
    if (str == "nan" || str == "nanf" || str == "-inf" || str == "-inff" || str == "+inf" || str == "+inff") {
        ScalarConverter::convert(str);
        return 0;
    }
    if (str.length() > 0 && str[str.length() - 1] == 'f' && 
        str != "nanf" && str != "-inff" && str != "+inff") {
        str.erase(str.length() - 1);
    }
    bool isd = false;
    bool hasDigit = false;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            if (isd) {
                std::cout << "no good" << std::endl;
                return 1;
            }
            isd = true;
        } else if (!std::isdigit(str[i]) && (i != 0 || (str[i] != '+' && str[i] != '-'))) {
            std::cout << "no good" << std::endl;
            return 1;
        } else if (std::isdigit(str[i])) {
            hasDigit = true;
        }
    }
    if (!hasDigit) { 
        std::cout << "no good" << std::endl; 
        return 1; 
    }

    ScalarConverter::convert(str);
    return 0;
}

