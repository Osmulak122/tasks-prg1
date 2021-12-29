#include "../include/projekt/Headers.h"
#include "../include/projekt/Mob.h"
#include "../include/projekt/Hero.h"


Mob::Mob() {
    mob_type = " ";
    mob_says = " ";
    mobType = {"Mangy Wolf", "Kobold Geomancer", "Murloc Lurker", "Defias Bandit", "Kobold Worker", "Mine Spider",
               "Hogger"};
    lvl = 0, totalHp = 0, hp = 0, attack = 0, xp = 0;
}

Mob mob;

void Mob::createMob() {
    lvl = hero.lvl;

    srand((unsigned) time(0));
    int randomNumber;
    for (int index = 0; index < 5; index++) {
        randomNumber = (rand() % 7) + 1;
    }
    mob_type = mobType[randomNumber - 1];

    if (mob_type == mobType[0]) {
        mob_says = "*growl*";
        hp = lvl * 3 + 15;
        attack = lvl * 2 + 6;
        xp = lvl * 3 + 10;
    } else if (mob_type == mobType[1]) {
        mob_says = "Candle, candle!";
        hp = lvl * 3 + 14;
        attack = lvl * 3 + 4;
        xp = lvl * 3 + 12;
    } else if (mob_type == mobType[2]) {
        mob_says = "Mglrmglmglmgl!";
        hp = lvl * 3 + 16;
        attack = lvl * 3 + 5;
        xp = lvl * 3 + 9;
    } else if (mob_type == mobType[3]) {
        mob_says = "You lookin' at me?";
        hp = lvl * 2 + 23;
        attack = lvl * 2 + 8;
        xp = lvl * 5 + 7;
    } else if (mob_type == mobType[4]) {
        mob_says = "Candle?!";
        hp = lvl * 2 + 20,
                attack = lvl * 2 + 7;
        xp = lvl * 5 + 8;
    } else if (mob_type == mobType[5]) {
        mob_says = "*some spider noises*";
        hp = lvl * 2 + 21;
        attack = lvl * 3 + 2;
        xp = lvl * 5 + 8;
    } else if (mob_type == mobType[6]) {
        mob_says = "Bones To Chew!";
        hp = lvl * 3 + 25;
        attack = lvl * 3 + 15;
        xp = lvl * 7 + 10;
    }

}