

#include <iostream>
#include <string>

auto main(int, char *argv[]) -> int
{
    const int a = std::stoi(argv[1]);
    const int b = std::stoi(argv[2]);
    std::cout << (a - b) << "\n";

    return 0;
}