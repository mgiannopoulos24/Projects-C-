#ifndef TERRAIN_H
#define TERRAIN_H

#include <string>
#include <iostream>

class Terrain {
public:
    std::string name;
    char content;

    Terrain(std::string name);
    friend std::ostream& operator<<(std::ostream& os, const Terrain& t);
};

#endif
