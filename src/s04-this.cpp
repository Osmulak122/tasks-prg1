#include "iostream"

struct name_struct {
    std::string name;
    name_struct(std::string user_name) {
        name = user_name;
    }
    void function() const{
        std::cout<<"this value: "<< this -> name <<"\n";
    }
};

auto main() -> int {
    name_struct name("Tomek");
    name.function();

    std::cout<<"manual this value: "<< &name.name <<"\n";
}