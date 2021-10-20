#ifndef TASKS_PRG1_STUDENT_H
#define TASKS_PRG1_STUDENT_H
#include "string"
namespace s24259 {
    class Student {
    public:
        std::string const imie;
        std::string const nazwisko;
        std::string const nrindex;
        int semestr;
        double srednia;

        Student(std::string, std::string, std::string, int, double);
        auto to_string() const -> std::string;
    };
} //namespace s24259
#endif //TASKS_PRG1_STUDENT_H
