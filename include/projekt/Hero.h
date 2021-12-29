#pragma once

#include "Headers.h"

class Hero {
public:
    Hero();

    std::string name, sex, h_class;
    std::vector<std::string> playerClass;
    int lvl, xp, hp, totalhp, maxhp, toLvlUp, heal, attack;

    void createHero();
};

#ifndef TASKS_PRG1_HERO_H
#define TASKS_PRG1_HERO_H

#endif //TASKS_PRG1_HERO_H
