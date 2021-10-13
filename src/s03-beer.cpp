#include <iostream>

auto main() -> int {
    for (int i = 99; i > 1; --i) {
        std::cout << i << " bottles of beer on the wall, " << i
                  << " bottles of beer. \n"
                  << "Take one down, pass it around. \n\n";
    }
    std::cout << "1 bottle of beer on the wall, 1 bottle of beer.\n"
              << "Take the last one down, pass it around. \n\n";
    std::cout << "No more bottles of beer on the wall, no more bottles od beer. \n"
              << "Go to the store and buy some more. \n";
    return 0;
}

