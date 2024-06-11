#include "beings.h"
#include <cstdlib>

Beings::Beings(std::string name, int x, int y) : name(name), x(x), y(y) {}

Monsters::Monsters(std::string name, int x, int y, int health, int attack, int defense, int medicine)
    : Beings(name, x, y), health(health), attack(attack), defense(defense), medicine(medicine) {}

void Monsters::move(std::vector<std::vector<Terrain>>& grid, int n, int m) {
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    int new_x = (x + dx + n) % n;
    int new_y = (y + dy + m) % m;
    if (grid[new_x][new_y].content == '.') {
        grid[x][y].content = '.';
        x = new_x;
        y = new_y;
        grid[x][y].content = name[0];
    }
}

Vampires::Vampires(int x, int y)
    : Monsters("V", x, y, rand() % 51 + 100, rand() % 26 + 25, rand() % 26 + 25, rand() % 5 + 1) {}

Werewolves::Werewolves(int x, int y)
    : Monsters("W", x, y, rand() % 51 + 100, rand() % 26 + 25, rand() % 26 + 25, rand() % 5 + 1) {}

Avatar::Avatar(int x, int y) : Beings("A", x, y) {}

XPotion::XPotion(int x, int y) : Beings("P", x, y) {}
