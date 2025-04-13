//Game.cpp
/*
 * File: /home/jovyan/CSCI1300/Projects/Project02_2025/CPP/Game.cpp
 * Project: /home/jovyan/CSCI1300/Projects/Project02_2025/CPP
 * Created Date: Monday April 7th 2025
 * Author: Mohammed Abdulrahman
 * -----
 * Last Modified:
 * Modified By:
 * -----
 * For Love
 */
#include "../Headers/Game.h"

// Cnstructors
Game::Game(){
    vector<Player> _players;
    vector<Character> _creatures;
    vector<Riddles> _riddlesData;
    vector<Events> _eventsData;
    _riddleSize = _riddlesData.size();
    _eventsSize = _eventsData.size();
    _num_players = _players.size();
    _num_creatures = _creatures.size();
    _currentTurnIndex = 0;
}

Game::Game(vector<Player> players, vector<Character> creatures, vector<Riddles> riddlesData, vector<Events> eventsData){
    players.size() > 0 ? _num_players = players.size(): _num_players = 0;
    creatures.size() > 0 ? _num_creatures = creatures.size(): _num_creatures = 0;
    _riddlesData = riddlesData;
    _eventsData = eventsData;
    _currentTurnIndex = 0; 

    for (int i = 0; i < players.size(); i++){
        _players.push_back(players[i]);
    }

    for (int i = 0; i < creatures.size(); i++){
        _creatures.push_back(creatures[i]);
    }
}

// Getters
int Game::getNumPlayers(){
    return _num_players;
}

int Game::getNumCreatures(){
    return _num_creatures;
}

vector<Riddles> Game::getRiddlesData() {
    return _riddlesData;
}

vector<Events> Game::getEventsData(){
    return _eventsData;
}

int Game::getCurrentTurnIndex(){
    return _currentTurnIndex;
}

//Setters
bool Game::setPlayer(int index, Character new_player){
    if (index > 1){
        return false;
    }

    _players[index].setCharacter(new_player);
    return true;
}

bool Game::setCreature(int index, Character new_creature){

    if (index >= getNumCreatures() || index < 0){
        return false;
    }

    _creatures[index] = new_creature;
    return true;
}

// Helper Functions
int Game::findCreature(string name){
    int index = -1;
    
    for (int i = 0; i < getNumCreatures(); i++){
        if (_creatures[i].getPlayerName() == name){
            index = i;
        }
    }

    return index;
}

int Game::findPlayer(string name){
    int index = -1;

    for (int i = 0; i < getNumPlayers(); i++){
        Character ch;
        ch = _players[i].getPlayer();
        (ch.getPlayerName() == name) ? index = i : index = -1;
    }

    return index;
}

void Game::printAllStats(){
    for (int i = 0; getNumPlayers(); i++){
        Character ch = _players[i].getPlayer();
        ch.printStats();
    }
}

// Logic Function for Game Play
vector<Riddles> Game::getRandomRiddle(){
    // Varibales Decleration
    vector <Riddles> tempData = getRiddlesData();
    vector <Riddles> randRiddle;
    srand(time(0));
    int randRiddleNum = rand() % 10;

    // Logic
    randRiddle.push_back(tempData.at(randRiddleNum));

    return randRiddle;
}

vector<Events> Game::getEvent(bool isBad){
    vector<Events> tempEventsData = getEventsData();
    vector<Events> returnEvents;
    if (isBad){
        for (int i = 0; i < tempEventsData.size(); i++){
            if (tempEventsData[i].PP < 0){
                cout << "This is a Bad Events" << endl;
                returnEvents.push_back(tempEventsData[i]);
                break;
            }
        }
    } else {
        for (int i = 0; i < tempEventsData.size(); i++){
            if (tempEventsData[i].PP > 0){
                cout << "This a good Events" << endl;
                returnEvents.push_back(tempEventsData[i]);
                break;
            }
        }
    }

    return returnEvents;
}

bool Game::hasPlayerWon(Player p){
    return p.getPostion() > 52; // large number until I find teh logic
}

void Game::advanceTurn() {
    _currentTurnIndex = (_currentTurnIndex + 1) % _players.size();
}

void Game::playGame() {
    bool gameRunning = true;

    while (gameRunning){
        int currentIndex = getCurrentTurnIndex();
        Player currentPlayer = _players[currentIndex];
        
        currentPlayer.takeTurn();
        _players[currentIndex] = currentPlayer;

        if (hasPlayerWon(currentPlayer)){
            cout << currentPlayer.getPlayer().getPlayerName() << " has won the game!" << endl;
            gameRunning = false;
        } else {
            advanceTurn();
        }
    }
}
