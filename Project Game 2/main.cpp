#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#ifdef _WIN32
#include <conio.h> // Use conio.h for _kbhit() and _getch() on Windows
#else
#include <ncurses.h> // Use ncurses for getch() on Linux
#endif
#include "terrain.h"
#include "beings.h"

void initialize_grid(int n, int m, std::vector<std::vector<Terrain>>& grid) {
    grid.resize(n, std::vector<Terrain>(m, Terrain(".")));
}

void place_beings(std::vector<std::vector<Terrain>>& grid, std::vector<Beings*>& beings) {
    for (Beings* being : beings) {
        grid[being->x][being->y].content = being->name[0];
    }
}

void display_grid(const std::vector<std::vector<Terrain>>& grid) {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

void move_avatar(std::vector<std::vector<Terrain>>& grid, Avatar& avatar, int dx, int dy, int n, int m) {
    int new_x = (avatar.x + dx + n) % n;
    int new_y = (avatar.y + dy + m) % m;

    if (grid[new_x][new_y].content == '.') {
        grid[avatar.x][avatar.y].content = '.';
        avatar.x = new_x;
        avatar.y = new_y;
        grid[avatar.x][avatar.y].content = avatar.name[0];
    }
}

#ifdef _WIN32
void clear_screen() {
    system("CLS");
}
#else
void clear_screen() {
    system("clear");
}
#endif

void game_loop(int n, int m, std::vector<Vampires>& vampires, std::vector<Werewolves>& werewolves, Avatar& avatar, XPotion& potion) {
    std::vector<std::vector<Terrain>> grid;
    initialize_grid(n, m, grid);

    std::vector<Beings*> beings;
    for (Vampires& vampire : vampires) beings.push_back(&vampire);
    for (Werewolves& werewolf : werewolves) beings.push_back(&werewolf);
    beings.push_back(&avatar);
    beings.push_back(&potion);

    place_beings(grid, beings);

    while (true) {
        display_grid(grid);

#ifdef _WIN32
        if (_kbhit()) {
            char input = _getch();
            switch (input) {
                case 'w': move_avatar(grid, avatar, -1, 0, n, m); break;
                case 's': move_avatar(grid, avatar, 1, 0, n, m); break;
                case 'a': move_avatar(grid, avatar, 0, -1, n, m); break;
                case 'd': move_avatar(grid, avatar, 0, 1, n, m); break;
                default: break;
            }
        }
#else
        char input = getch();
        switch (input) {
            case 'w': move_avatar(grid, avatar, -1, 0, n, m); break;
            case 's': move_avatar(grid, avatar, 1, 0, n, m); break;
            case 'a': move_avatar(grid, avatar, 0, -1, n, m); break;
            case 'd': move_avatar(grid, avatar, 0, 1, n, m); break;
            default: break;
        }
#endif

        for (Vampires& vampire : vampires) {
            vampire.move(grid, n, m);
        }
        for (Werewolves& werewolf : werewolves) {
            werewolf.move(grid, n, m);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        clear_screen();
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

#ifndef _WIN32
    initscr(); // Initialize ncurses
    keypad(stdscr, true); // Enable keyboard input
    noecho(); // Don't echo input characters to the screen
    curs_set(0); // Hide cursor
#endif

    int n = 10, m = 10; // or take user input
    std::vector<Vampires> vampires;
    std::vector<Werewolves> werewolves;

    for (int i = 0; i < 3; ++i) {
        vampires.emplace_back(rand() % n, rand() % m);
        werewolves.emplace_back(rand() % n, rand() % m);
    }

    Avatar avatar(rand() % n, rand() % m);
    XPotion potion(rand() % n, rand() % m);

    game_loop(n, m, vampires, werewolves, avatar, potion);

#ifndef _WIN32
    endwin(); // End ncurses
#endif

    return 0;
}
