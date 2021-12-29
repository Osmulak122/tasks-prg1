#include "../include/projekt/Headers.h"
#include "../include/projekt/Hero.h"
#include "Hero.cpp"
#include "Mob.cpp"


void HUD(), Combat(), inCombatHUD(), Move(), NextLevel(), Rest(), Roll(),
PreviousLevel(), mobHUD(), GameOver(), Attack(), Wait(), Run(), mobAttack(), mobDefeated();


auto main() -> int {
    hero.createHero();
    HUD();
    Move();
    return 0;
}

void HUD() {
    std::cout << "\033[1;32mName: " << hero.name << "      Class: " << hero.h_class << "       Sex: " << hero.sex <<
    "\33[0m\n\033[1;34mLevel: " << hero.lvl << "          XP: " << hero.xp << "             To Lvl Up: " << hero.toLvlUp <<
    "\33[0m\n\033[1;31mHP: " << hero.hp << "           Attack: " << hero.attack << "\33[0m\n";
}
void mobHUD() {
    std::cout << "\033[1;32mMob: " << mob.mob_type << "      Level: " << mob.lvl << "\33[0m\n\033[1;34mXp to get: " <<
    mob.xp << "\33[0m\n\033[1;31mHp: " << mob.hp << "          Attack: " << mob.attack << "\33[0m\n";

}
void Move() {
    int pick;

    std::cout << "\nTime to move (Type a number below)\n";
    std::cout << "1. Move\n";
    std::cout << "2. Rest\n";
    std::cout << "3. Try your luck\n\n";

    std::cin >> pick;

    if (pick == 1) {
        Combat();
    }   else if (pick == 2) {
        Rest();
    }   else if (pick == 3) {
        Roll();
    } else {
        std::cout << "You have probably messed up\n";
        sleep(1);
        Clear();
        HUD();
        Move();
    }
}

void CombatMove() {
    int pick;

    std::cout << "\nTime to move (Type a number below)\n";
    std::cout << "1. Attack\n";
    std::cout << "2. Wait\n";
    std::cout << "3. Run\n";

    std::cin >> pick;

    if (pick == 1) {
        Attack();
    }   else if (pick == 2) {
        Wait();
    }   else if (pick == 3) {
        Run();
    } else {
        std::cout << "You have probably messed up\n";
        sleep(1);
        Clear();
        sleep(1);
        inCombatHUD();
        CombatMove();
    }
}

void Rest() {
    srand((unsigned) time(0));
    int randomNumber;
    for (int index = 0; index < 5; index++) {
        randomNumber = (rand() % 10) + 1;
    }
    int toHeal = randomNumber * 3 + hero.lvl * 2;
    std::string ifFull = " ";
    if (hero.totalhp == hero.hp) {
        toHeal = 0;
        ifFull = " as you are already at full hp.\n";
    } else if (hero.hp + toHeal > hero.totalhp) {
        toHeal = hero.totalhp - hero.hp;
    }
    std::cout << "Are you really that tired?!\n\n";
    sleep(1);
    std::cout << "You have slept for " << randomNumber << " hours.\n";
    std::cout << "The rest you took has healed you for " << std::to_string(toHeal) << ifFull << std::endl;
    hero.hp = hero.hp + toHeal;
    sleep(4);

    Clear();
    HUD();
    Move();
}

void Roll() {
    srand((unsigned) time(0));
    int healChange;
    int randomNumber;
    for (int index = 0; index < 5; index++) {
        randomNumber = (rand() % 75) + 1;
        // damage Hero or heal
    }
        if (randomNumber < 25) {
            if (randomNumber % 2 == 0) {
                if (hero.totalhp == hero.hp) {
                    std::cout << "\nYou rolled a heal but you are full hp :(\n";
            }   else if (hero.hp + 10 + hero.lvl * 2 > hero.totalhp) {
                    healChange = hero.totalhp - hero.hp;
                    std::cout << "\nHealed you for " << healChange << " hp.\n";
                    hero.hp = hero.hp + healChange;
                } else {
                    healChange = 10 + hero.lvl * 2;
                    std::cout << "\nYou have been healed for " << healChange << " hp.\n";
                    hero.hp = hero.hp + healChange;
                }
            }   else {
                healChange = -10 - hero.lvl * 2;
                std::cout << "\nYou have taken " << healChange << " damage. Bad luck...\n";
                hero.hp = hero.hp + healChange;
            }
        }   else if (randomNumber >= 25 && randomNumber < 50) {
            if (randomNumber % 3 == 0) {
                std::cout << "\nYou have been given a free lvl.\n";
                NextLevel();
            }   else {
                if (hero.lvl == 1) {
                    std::cout << "\nYou would have lost a level, but you're a lvl 1.\n";
                }   else {
                    std::cout << "\nYou have lost one level.\n";
                    PreviousLevel();
                }
            }
        } else if (randomNumber >= 50 && randomNumber < 75) {
            if (randomNumber % 2 == 0) {
                int xpToAdd = 0;
                int xpChange = (int)(randomNumber / 4);
                if(xpChange + hero.xp > hero.toLvlUp) {
                    int remainingXp = hero.toLvlUp - hero.xp;
                    xpToAdd = xpChange - remainingXp;
                    NextLevel();
                } else {
                    xpToAdd = xpChange;
                }
                hero.xp += xpToAdd;
                std::cout << "\nYou have been given " << xpChange << " xp!\n";
            }   else {
                hero.xp = 1;
                std::cout << "\nBad luck! Your XP has been set to 1.\n";
            }
        }
    sleep(3);
        Clear();
        if (hero.hp > 0) {
            HUD();
            Move();
        } else {
            GameOver();
        }
    }
void NextLevel() {
    hero.lvl += 1;
    hero.totalhp += hero.lvl * 3;
    hero.attack += hero.lvl * 2;
    hero.maxhp += hero.lvl * 3;
    hero.hp = hero.maxhp;
    hero.xp = 0;
}

void PreviousLevel() {
    hero.totalhp -= hero.lvl * 3;
    hero.maxhp -= hero.lvl * 3;
    hero.attack -= hero.lvl * 2;
    hero.hp = hero.maxhp;
    hero.xp = 0;
    hero.lvl -= 1;
}
void Combat() {
    srand((unsigned) time(0));
    int randomNumber;
    for (int index = 0; index < 5; index++) {
        randomNumber = (rand() % 100) + 1;
    }
    if(randomNumber < 60) {
        mob.createMob();

        std::cout << "You went a step too far...\n";
        sleep(2);
        std::cout << "Time to face: \033[1;31m" << mob.mob_type << "\33[0m\n";
        sleep(1);
        std::cout << mob.mob_says << "\n";
        sleep(1);
        std::cout << "Moving to combat..\n";
        sleep(1);
        Clear();
        inCombatHUD();
    }   else {
        std::cout << "\nYou moved, but nothing was there.\n\nTry again.\n";
        sleep(2);
        Clear();
        HUD();
        Move();
    }
}

void inCombatHUD() {
    HUD();
    std::cout << "=================================================\n";
    mobHUD();
    std::cout << "=================================================\n";
    CombatMove();
}

void Attack() {
    mob.hp -= hero.attack;
    std::cout << "\nDealt " << hero.attack << " damage to " << mob.mob_type <<"\n\n";
    sleep(2);
    if (hero.hp > 0) {
        if (mob.hp > 0) {
            mobAttack();
            Clear();
            inCombatHUD();
        } else {
          mobDefeated();
        }
    } else {
        GameOver();
    }
}

void Wait() {
    std::cout << "You have just waited a bit, you skipped a round, but why?\n";
    sleep(2);
    Clear();
    inCombatHUD();
}

void Run() {
    std::cout << "Running away from " << mob.mob_type << "?" << " ...Really??\n";
    sleep(2);
    Clear();
    HUD();
}
void mobAttack() {
    hero.hp -= mob.attack;
    std::cout << "You have been damaged for " << mob.attack << ".\n";
    sleep(2);
}

void GameOver() {
    Clear();
    std::cout << "\nGame Over!";
}

void mobDefeated() {
    int xpToAdd = 0;
    if(mob.xp + hero.xp > hero.toLvlUp) {
        int remainingXp = hero.toLvlUp - hero.xp;
        xpToAdd = mob.xp - remainingXp;
        NextLevel();
    } else {
        xpToAdd = mob.xp;
    }
    hero.xp += xpToAdd;
    std::cout << "\nYou have defeated " << mob.mob_type << ".\n\n";
    sleep(2);
    Clear();
    HUD();
    Move();
}