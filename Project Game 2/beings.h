#ifndef BEINGS_H
#define BEINGS_H

#include <string>
#include <vector>
#include "terrain.h"

class Beings {
public:
    std::string name;
    int x, y;

    Beings(std::string name, int x, int y);
};

class Monsters : public Beings {
public:
    int health, attack, defense, medicine;

    Monsters(std::string name, int x, int y, int health, int attack, int defense, int medicine);
    void move(std::vector<std::vector<Terrain>>& grid, int n, int m);
};

class Vampires : public Monsters {
public:
    Vampires(int x, int y);
};

class Werewolves : public Monsters {
public:
    Werewolves(int x, int y);
};

class Avatar : public Beings {
public:
    Avatar(int x, int y);
};

class XPotion : public Beings {
public:
    XPotion(int x, int y);
};

#endif
