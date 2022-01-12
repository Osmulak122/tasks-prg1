#include "../include/projekt/Hero.h"
#include "../include/projekt/Headers.h"

Hero::Hero() {
    name = " ";
    h_class = " ";
    sex = " ";

    playerClass = {"Mage", "Paladin", "Warrior", "Druid", "Warlock", "Rogue", "Hunter", "DeathKnight"};
    lvl = 0, xp = 0, hp = 0, totalhp = 0, maxhp = 0, toLvlUp = 0, heal = 0, attack = 0;
}

Hero hero;

void Clear() {
    system("clear"); //for macos and linux
    //system("cls"); //for windows
}

void Hero::createHero() {
    int selection;
    lvl = 1;
    xp = 1;
    toLvlUp = 50;

    std::cout << "Welcome to the game!\n\n" <<
              "What is your name?" << "\n...\n..\n.\n\n";
    std::cin >> name;
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    std::cout << "Hello \033[1;32m" << name << "\033[0m\n";
    sleep(1);
    std::cout << "It is a time to pick a class\n";
    sleep(1);
    std::cout << "I hope you're ready!" << "\n\n";
    sleep(2);
    Clear();

    for (int i = 0; i < 8; ++i) {
        std::cout << i + 1 << " " << playerClass[i] << std::endl;
    }
    std::cout << "\nWhich class do you pick? (Number 1-8) :" << "\n";
    std::cin >> selection;

    if (std::cin.fail() || selection > 8 || selection < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        sleep(1);
        std::cout << "Your input was wrong.\nThe class will be picked randomly\n" << std::endl;
        srand((unsigned) time(0));
        int randomNumber;
        for (int index = 0; index < 5; index++) {
            randomNumber = (rand() % 8) + 1;
        }
        h_class = playerClass[randomNumber - 1];
    } else {
        h_class = playerClass[selection - 1];
    }
    sleep(2);
    Clear();
    std::cout << "You have picked : " << h_class << "\n\n";

    if (h_class == "Mage") {
        hp = 60;
        attack = 15;
    } else if (h_class == "Paladin") {
        hp = 100;
        attack = 10;
    } else if (h_class == "Warrior") {
        hp = 120;
        attack = 9;
    } else if (h_class == "Druid") {
        hp = 160;
        attack = 7;
    } else if (h_class == "Warlock") {
        hp = 90;
        attack = 11;
    } else if (h_class == "Rogue") {
        hp = 70;
        attack = 12;
    } else if (h_class == "Hunter") {
        hp = 60;
        attack = 13;
    } else {
        h_class = "DeathKnight";
        hp = 130;
        attack = 9;
    }
    sleep(1);
    std::string sex_selection;
    std::cout << "Pick your hero's sex (Type Male/Female)" << "\n\n";
    std::cin >> sex_selection;
    std::for_each(sex_selection.begin(), sex_selection.end(), [](char &c) {
        c = ::tolower(c);
    });
    if (sex_selection == "male") {
        sex = "Male";
    } else if (sex_selection == "female") {
        sex = "Female";
    } else {
        sex = "Unisex";
    }

    std::cout << "You have selected : " << sex << "\n\n";
    sleep(1);
    for (int j = 0; j < 3; ++j) {
        Clear();
        sleep(1);
        std::cout << "Creating your hero..." << std::endl;
        sleep(1);
    }
    Clear();

    name[0] = toupper(name[0]);

    totalhp = hp;
    maxhp = totalhp;
}


