#pragma once

#include "Headers.h"

class Mob {
public:
    Mob();

    std::string mob_type;
    std::string mob_says;
    std::vector<std::string> mobType;
    int hp, totalHp, attack, lvl, xp;

    void createMob();
};

#ifndef TASKS_PRG1_MOB_H
#define TASKS_PRG1_MOB_H

#endif //TASKS_PRG1_MOB_H
