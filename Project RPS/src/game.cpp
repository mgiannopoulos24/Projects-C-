#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Game::start() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed for random number generation
    chooseMode();

    std::string player1Choice = getUserChoice("Player 1");
    std::string player2Choice = playWithComputer ? getComputerChoice() : getUserChoice("Player 2");

    determineWinner(player1Choice, player2Choice);
}

void Game::chooseMode() {
    int mode;
    std::cout << "Choose game mode (1 = Play with Computer, 2 = Play with Another Player): ";
    std::cin >> mode;

    while (mode < 1 || mode > 2) {
        std::cout << "Invalid choice. Please enter 1 or 2: ";
        std::cin >> mode;
    }

    playWithComputer = (mode == 1);
}

std::string Game::getUserChoice(const std::string& player) {
    int choice;
    std::cout << player << ", enter your choice (0 = Rock, 1 = Paper, 2 = Scissors): ";
    std::cin >> choice;

    while (choice < 0 || choice > 2) {
        std::cout << "Invalid choice. Please enter 0, 1, or 2: ";
        std::cin >> choice;
    }

    return getChoiceName(choice);
}

std::string Game::getComputerChoice() {
    int choice = std::rand() % 3; // Random number between 0 and 2
    return getChoiceName(choice);
}

void Game::determineWinner(const std::string& player1Choice, const std::string& player2Choice) {
    std::cout << "Player 1 chose: " << player1Choice << std::endl;
    std::cout << "Player 2 chose: " << player2Choice << std::endl;

    if (player1Choice == player2Choice) {
        std::cout << "It's a tie!" << std::endl;
    } else if ((player1Choice == "Rock" && player2Choice == "Scissors") ||
               (player1Choice == "Paper" && player2Choice == "Rock") ||
               (player1Choice == "Scissors" && player2Choice == "Paper")) {
        std::cout << "Player 1 wins!" << std::endl;
    } else {
        std::cout << "Player 2 wins!" << std::endl;
    }
}

std::string Game::getChoiceName(int choice) {
    switch (choice) {
        case 0: return "Rock";
        case 1: return "Paper";
        case 2: return "Scissors";
        default: return "";
    }
}