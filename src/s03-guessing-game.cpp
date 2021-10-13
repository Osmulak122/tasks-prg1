#include <iostream>
#include <string>
#include <cstdlib>

auto ask_user_for_number(std::string prompt) -> int {
    std::cout << prompt << " int:";
    auto n = std::string{};
    std::getline(std::cin, n);
    return std::stoi(n);
}

auto main() -> int {
    int randomNumber = rand() % 100 + 1;
    int input;
    std::cout << "The number is : " + std::to_string(randomNumber)  << std::endl;
    do {
        input = ask_user_for_number("guess ");
    } while (input != randomNumber);
    {
        std::cout << "You won";
    }
    return 0;
}