#include "iostream"
#include "string"

auto main(int, char *argv[]) -> int {
    int input;
    try {
        input = std::stoi(argv[1]);
    }
    catch (...) {
        std::cout << "An error occurred, make sure you are using integer";
        return 0;
    }

    std::cout << "n: " + std::to_string(input) << std::endl;
    if (input % 3 == 0) {
        std::cout << "Fizz";
    }
    if (input % 5 == 0) {
        std::cout << "Buzz";
    } else {
        std::cout << "Input is not either Fizz or Buzz :(";
    }
    return 0;
}