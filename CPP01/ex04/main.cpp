#include "Replace.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Do this my guy " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    Replace::processFile(argv[1], argv[2], argv[3]);
    return 0;
}
