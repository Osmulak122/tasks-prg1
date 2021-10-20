
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>


auto pop_top(std::stack<double> &stack) -> double {
    if (stack.empty()) {
        throw std::logic_error{"empty stack"};
    }
    auto element = std::move(stack.top());
    stack.pop();
    return element;
}

// dodawanie
auto evaluate_addition(std::stack<double> &stack) -> void {
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for +"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a + b);
}

// dzielenie
auto evaluate_subtraction(std::stack<double> &stack) -> void {
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for -"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a - b);
}

auto evaluate_mul(std::stack<double> &stack) -> void {
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for *"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a * b);
}

auto evaluate_div(std::stack<double> &stack) -> void {
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for /"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(a / b);
}

auto evaluate_divint(std::stack<double> &stack) -> void {
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for //"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(round(a / b));
}

auto evaluate_rest_of_div(std::stack<double> &stack) -> void {
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for %"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    int a2 = a;
    int b2 = b;
    stack.push(a2 % b2);
}

auto evaluate_exp(std::stack<double> &stack) -> void {
    if (stack.size() < 2) {
        throw std::logic_error{"not enough operands for **"};
    }
    auto const b = pop_top(stack);
    auto const a = pop_top(stack);
    stack.push(std::pow(a, b));
}

auto evaluate_sqrt(std::stack<double> &stack) -> void {
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for sqrt"};
    }
    auto const a = pop_top(stack);
    stack.push(std::sqrt(a));
}

auto evaluate_cbrt(std::stack<double> &stack) -> void {
    if (stack.size() < 1) {
        throw std::logic_error{"not enough operands for cbrt"};
    }
    auto const a = pop_top(stack);
    stack.push(std::cbrt(a));
}

auto make_args(int argc, char *argv[]) -> std::vector<std::string> {
    auto args = std::vector<std::string>{};
    std::copy_n(argv, argc, std::back_inserter(args));
    return args;
}


auto main(int argc, char *argv[]) -> int {
    auto const args = make_args(argc - 1, argv + 1);

    auto stack = std::stack<double>{};
    for (auto const each: args) {
        try {
            if (each == "p") {
                std::cout << pop_top(stack) << "\n";
            } else if (each == "+") {
                evaluate_addition(stack);
            } else if (each == "-") {
                evaluate_subtraction(stack);
            } else if (each == "*") {
                evaluate_mul(stack);
            } else if (each == "/") {
                evaluate_div(stack);
            } else if (each == "//") {
                evaluate_divint(stack);
            } else if (each == "%") {
                evaluate_rest_of_div(stack);
            } else if (each == "**") {
                evaluate_exp(stack);
            } else if (each == "sqrt") {
                evaluate_sqrt(stack);
            } else if (each == "cbrt") {
                evaluate_cbrt(stack);
            } else {
                stack.push(std::stod(each));
            }
        } catch (std::logic_error const &e) {
            std::cerr << "error: " << each << ": " << e.what() << "\n";
        }
    }

    return 0;
}