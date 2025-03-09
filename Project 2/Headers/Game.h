//Game.h
#ifndef GAME_H
#define GAME_H

/*
 * CSCI 1300 Spring 2024 
 * Author: Mohammed Abdulrahman 
 * TA: Anush Venkatesh 
 * Date: 2024-03-30
 * Description: Game Headers
 * Header File
 */

#include <iostream>
#include <fstream>
#include "Entity.h"
//#include "loaders.h"


class Game {
    private:
        const int static MAX_PLAYER = 2;
        vector <Entity> _players;
        vector <Entity> _enemies;
        // const static int MAX_POTIONS = 9;
        // const static int MAX_EQUIP = 16;
        vector <Potions> _allPotions; 
        vector <Equipment> _allEqip;

    public:
        // function that just intialize and setter/getters
        Game();
        Game(vector<Entity> Players,  vector <Entity> Enemies);

        // getters
        Entity getEnemy(string);
        Entity getPlayer(string);
        int getNumPlayers();
        int getNumEnemies();

        // helpfulFunction could consider as getter
        int findPlayer(string);
        int findEnemy(string);

        // Setter function
        void setPlayersList(Entity [], int);
        void setEnemiesList(Entity[], int);
        bool setPlayer(int, Entity);
        bool setEnemy(int, Entity);

        void printAllStats();

        // int combat(Entity player, Entity enemy); // returns gold won
        // int combat(Entity player1, Entity player2); // Epic ACTION
        // void shop(Potions all_potions[], Equipment all_equip[]);
        void playGame();

};

#endif