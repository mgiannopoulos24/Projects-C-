#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
    void start();
private:
    void chooseMode();
    std::string getUserChoice(const std::string& player);
    std::string getComputerChoice();
    void determineWinner(const std::string& player1Choice, const std::string& player2Choice);
    std::string getChoiceName(int choice);

    bool playWithComputer;
};

#endif // GAME_H