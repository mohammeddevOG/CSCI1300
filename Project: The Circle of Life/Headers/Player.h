#ifndef PLAYER_H  // Header guard to prevent double inclusion
#define PLAYER_H
/*
 * File: /home/jovyan/CSCI1300/Projects/Project02_2025/Headers/Players.h
 * Project: /home/jovyan/CSCI1300/Projects/Project02_2025/Headers
 * Created Date: Sunday April 13th 2025
 * Author: Mohammed Abdulrahman
 * -----
 * Last Modified:
 * Modified By:
 * -----
 * For Love
 */
#

#include "Game.h"

class Player{
    private:
        Character _player;
        int _pathChoice;
        int _advisor;
        int _postion;

    public:
        Player();
        Player(Character, int, int);

        // Getters
        Character getPlayer();
        int getPathChoice();
        int getAdvisor();
        int getPostion();

        // Setters
        void setCharacter(Character);
        void setPath(int);
        void setAdvisor(int);
        void setPostion(int);

        // print player stats
        void printPlayer();

        // Logic for Game Play
        void takeTurn();
        int throwDice(); 





};

#endif
