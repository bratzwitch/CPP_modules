#include "Array.hpp"
#include <iostream>

int main() {
    Array<int> empty;
    std::cout << empty.size() << std::endl;

    Array<int> nums(2);
    nums[0] = 5;
    nums[1] = 10;
    std::cout << nums[0] << std::endl;
    std::cout << nums[1] << std::endl;

    Array<int> copy = nums;
    copy[0] = 99;
    std::cout << nums[0] << std::endl;
    std::cout << copy[0] << std::endl;

    Array<int> temp(1);
    temp = nums;
    temp[0] = 88;
    std::cout << nums[0] << std::endl;
    std::cout << temp[0] << std::endl;

    try {
        nums[2] = 0;
        std::cout << "good" << std::endl;
    } catch (const std::exception&) {
        std::cout << "no good" << std::endl;
    }
    return 0;
}