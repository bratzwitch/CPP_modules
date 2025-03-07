#include "Replace.hpp"

void Replace::processFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    if (s1.empty()) {
        std::cerr << "no empty." << std::endl;
        return;
    }
    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "no open" << filename << std::endl;
        return;
    }
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str()); 
    if (!outputFile) {
        std::cerr << "no output file " << outputFilename << std::endl;
        return;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outputFile << line << std::endl;
    }
    std::cout << "Cool! Something changed(or not)" << std::endl;
}
