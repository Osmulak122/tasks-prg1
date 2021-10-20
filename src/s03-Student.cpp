#include "sstream"
#include "../include/Student.h"
#include "iostream"

s24259::Student::Student(std::string imie, std::string nazwisko, std::string nrindex, int semestr, double srednia)
        : imie{imie}, nazwisko{nazwisko}, nrindex{nrindex}, semestr{semestr}, srednia{srednia} {}

auto s24259::Student::to_string() const -> std::string {
    auto output = std::ostringstream{};
    output << "Imię: " << imie << std::endl << "Nazwisko: " << nazwisko << std::endl << "Numer indeksu: " << nrindex
           << std::endl
           << "Semestr: " << semestr << std::endl << "Średnia: " << srednia;

    return output.str();
}

auto main() -> int {
    auto student = s24259::Student{"Adam", "Nowak", "s12345", 1, 4.53};
    std::cout << student.to_string() << "\n";
    return 0;
}
