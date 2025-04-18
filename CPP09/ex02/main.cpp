#include "PmergeMe.hpp"


template <typename Container>
void processInput(const std::string& input, Container& result, double& time, int& res_steps)
{
    Container vec;
    std::stringstream ss(input);
    std::string token;
    while (ss >> token) {
        char* endptr;
        long num = std::strtol(token.c_str(), &endptr, 10);
        if (*endptr != '\0' || num < 0 || num > 2147483647) {
            throw std::runtime_error("Invalid input: only positive integers allowed");
        }
        vec.push_back(static_cast<typename Container::value_type>(num));
    }
    
    PmergeMe<Container> sorter;
    int steps = 0;
    clock_t start = clock();
    sorter.sort(vec,steps);
    clock_t end = clock();
    time = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;
    result = vec;
    res_steps = steps;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::ostringstream oss;
    for (int i = 1; i < argc; ++i) {
        if (i > 1) oss << " ";
        oss << argv[i];
    }
    std::string input = oss.str();
    std::cout << "Before: " << input << std::endl;

    try {
        std::vector<int> vecResult;
        std::deque<int> deqResult;
        double vecTime = 0.0, deqTime = 0.0;
        int vecSteps = 0;
        int deqSteps = 0;
        processInput(input, vecResult, vecTime,vecSteps);
        processInput(input, deqResult, deqTime,deqSteps);
        for (size_t i = 0; i < vecResult.size(); ++i) {
            for(size_t j = i; j < vecResult.size(); j++) {
                if(j != i) { 
                    if(vecResult[i] == vecResult[j])
                    {
                        std::cerr << "no duplicates" << std::endl;
                        return 1;
                    }
                }
            }
        }
        std::cout << "After: ";

        for (size_t i = 0; i < vecResult.size(); ++i) {
            std::cout << vecResult[i];
            if (i < vecResult.size() - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
        std::cout << "time to process a range of " << vecResult.size() << " elements with std::vector : " << vecTime << " ms" << std::endl;
        std::cout << "time to process a range of " << deqResult.size() << " elements with std::deque : " << deqTime << " ms" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}