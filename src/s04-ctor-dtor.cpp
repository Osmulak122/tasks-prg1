#include "iostream"

struct to_destruct {
    std::string example;
    to_destruct(std::string example1) {
        example = example1;
    }
    ~to_destruct() {
        std::cout << "DESTRUCTION!" << std::endl;
        std::cout << example << std::endl;
    }
};

auto main() -> int {
    auto example_input = to_destruct("Text input");
}