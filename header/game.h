#ifndef GAME_H
#define GAME_H

// #include "character.h"
#include "player.h"
#include "monster.h"

class Game {
    private:
        int playerChoice;
        bool gameStatus;
        bool characterAvailable;
        bool zoneCompleted;
        bool quit;

        void continueScreen();

    public:
        Game();
        virtual ~Game();

        void gameSequence();
        void mainMenu(Player &p1);
        void startGame(Player &p1);
        void saveCharacter(Player &p1);
        void loadCharacter(Player &p1);
        void confirmationScreen();

        void printBattleStats(Player &p1, Monster &m1);
        void monsterEncounter(Player &p1, string type);

        bool getGameStatus() const { return this->gameStatus; }
        bool getCharacterAvailable() const { return this->characterAvailable; }

        //Story Functions
        void intro(Player &p1);
        void tutorial(Player &p1);
        void Forest(Player &p1);
        void Cave(Player &p1);
        void Mountain(Player &p1);

        //Zone Regions
        void Zone1(Player &p1);
        void Zone2(Player &p1);
        void Zone3(Player &p1);
};

#endif