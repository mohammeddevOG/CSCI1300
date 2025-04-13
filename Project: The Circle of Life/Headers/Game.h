// Game.h
#ifndef GAME_H
#define GAME_H
/*
 * File: /home/jovyan/CSCI1300/Projects/Project02_2025/Headers/Game.h
 * Project: /home/jovyan/CSCI1300/Projects/Project02_2025/Headers
 * Created Date: Monday April 7th 2025
 * Author: Mohammed Abdulrahman
 * -----
 * Last Modified:
 * Modified By:
 * -----
 * For Love
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Riddles.h"
#include "Events.h"
#include "Board.h"
#include "Characters.h"
#include "Player.h"


class Game{
    private:
        vector<Player> _players;
        vector<Character> _creatures;
        vector<Riddles> _riddlesData;
        vector<Events> _eventsData;
        int _currentTurnIndex;
        int _riddleSize;
        int _eventsSize;
        int _num_players;
        int _num_creatures;

    public:
        Game();
        Game(vector<Player>, vector<Character>, vector<Riddles>, vector<Events>);

        // Getters
        int getNumPlayers();
        int getNumCreatures();
        int getRiddleSize();
        int getEventsSize();
        int getCurrentTurnIndex();
        vector<Riddles> getRiddlesData();
        vector<Events> getEventsData();
        Character getPlayer(string);
       

        //setter function
        void setPlayerList(vector<Character>, int);
        void setCreatureList(vector<Character>, int);
        void setCurrentTurnIndex(int index);
        bool setPlayer(int, Character);
        bool setCreature(int, Character);

        // helpful funcitons
        int findPlayer(string);
        int findCreature(string);
        void printAllStats();

        // Logic Functions for Game Play
        vector<Riddles> getRandomRiddle();
        vector<Events> getEvent(bool isBad);
        void advanceTurn();
        bool hasPlayerWon(Player);
        int dice();

        // Main Logic
        void playGame();
};

#endif
