#include <iostream>
#include <string>

auto main(int, char *argv[]) -> int {
    auto const console_param = std::string{argv[1]};
    auto password = std::string{};
    std::cout << "password ";
    std::getline(std::cin, password);

    while (password != "Student") {
        std::cout << "The password is wrong. Please try again:";
        std::getline(std::cin, password);
    }
    if (password == "Student") {
        std::cout << "The password is correct \n";
    }
    return 0;
}