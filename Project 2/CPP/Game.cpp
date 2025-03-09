/*
 * CSCI 1300 Spring 2024 
 * Author: Mohammed Abdulrahman 
 * TA: Anush Venkatesh 
 * Date: 2024-04-25
 * Description: Implemntion Headers
 */


#include "../Headers/Game.h"
// #include "../Headers/loaders.h"

Game::Game(){
    //cout << "[DEBUG] No Problem Here Mate" << endl;
    for (int i = 0; i < 2; i++){
    _players[i].setName("");
    _enemies[i].setName("");
    }
}

Game::Game(vector<Entity> Players,  vector <Entity> Enemies){

    for(int i = 0; i < (int) Players.size(); i++){
        _players[i] = Players[i];
    }

    for (int i = 0; i < (int) Enemies.size(); i++){
        _enemies[i] = Enemies[i];
    }
}

int Game::getNumPlayers(){
    return _players.size();
}

int Game::getNumEnemies(){
    return _enemies.size();
}

bool Game::setPlayer(int index, Entity new_player){
    bool flag;
    if ((index == 0) || (index == 1)){
        cout << "[DEBUG] The player Name Before: " <<  _players[index].getName() << endl;
        _players[index] = new_player;
        cout << "[DEBUG] The player Name After: " <<  _players[index].getName() << endl;
        flag = true;
    } else {
        flag = false;
    }
    return flag;
}

void Game::setPlayersList(Entity Player[], int numObj){
    if(numObj > 2){
        for (int i = 0; i < 2; i++){
            _players[i] = Player[i];
        }
    } else {
        for (int i = 0; i < numObj; i++){
            _players[i] = Player[i];
        }
    }
}

// Remmber Here numObj is abstrcut fix that
void Game::setEnemiesList(Entity Enemies[], int numObj){
    if(numObj > 2){
        for (int i = 0; i < 2; i++){
            _enemies[i] = Enemies[i];
        }
    } else {
        for (int i = 0; i < numObj; i++){
            _enemies[i] = Enemies[i];
        }
    }
}

bool Game::setEnemy(int index, Entity new_enemy){
    bool flag;
    if ((index == 0) || (index == 1)){
        _enemies[index] = new_enemy;
        flag = true;
    } else {
        flag = false;
    }

    return flag;
}

int Game::findPlayer(string name){
    int index = -1;
    cout << "[DEBUG] Num Players: " << getNumPlayers() << endl;
    for(int i = 0; i < getNumPlayers(); i++){
        cout << "[DEBUG] The Player name is: " << _players[i].getName() << endl;
        if (_players[i].getName() == name){
            index = i;
        }
    }
    cout << "[DEBUG] index is: " << index << endl;
    return index;
}

int Game::findEnemy(string name){
    int index = -1;
    for(int i = 0; i < getNumPlayers(); i++){
        if (_enemies[i].getName() == name){
            index = i;
        }
    }
    cout << "[DEBUG] " << index << endl;
    return index;
}

Entity Game::getPlayer(string playernName){
    Entity Player;
    for (int i = 0; i < getNumPlayers(); i++){
        if(_players[i].getName() == playernName){
            Player = _players[i];
        }
    }

    return Player;
}

Entity Game::getEnemy(string EnemyName){
    Entity Enemy;
    for (int i = 0; i < getNumEnemies(); i++){
        cout << _enemies[i].getName() << endl;
        if(_enemies[i].getName() == EnemyName){
            Enemy = _enemies[i];
        }
    }
    return Enemy;
}


void Game::printAllStats() {
    for (int i = 0; i < getNumPlayers(); i++){
        _players[i].printStats();
        cout << "-------------------------------" << endl;
    }

    for (int i = 0; i < getNumEnemies(); i++){
        _enemies[i].printStats();
        cout << "-------------------------------" << endl;
    }
}


// The Game Function that do the action the actula game not just info

void Game::playGame() {
    // // Beging of the game
    // const int CHARACTERS_MAX_SIZE = 13;
    // Entity Characters[CHARACTERS_MAX_SIZE];

    // const int EQU_MAX_SIZE = 16;
    // Equipment Equ[EQU_MAX_SIZE];

    // const int POT_MAX_SIZE = 9;
    // Potions Pot[POT_MAX_SIZE];

    // cout << "Loading..." << endl;
    // if (loadChracters(Characters, CHARACTERS_MAX_SIZE) && (loadEqu(Equ,EQU_MAX_SIZE)) && (loadPotions(Pot, POT_MAX_SIZE))) {
    //     cout << "Welcome to Odyseey!" << endl;
    //     int players = 0;
    //     for (int i = 0; i < CHARACTERS_MAX_SIZE; i++){
    //         if (!Characters[i].getIsEnemy()) {
    //             players++;
    //             cout << "(" << players << ")" << Characters[i].getName() << " "; 
    //         }
    //     }
    // } else {
    //     cout << "[DEBUG] Faild to load Chracters" << endl;
    // }
    // cout << "Please Select your Player: " << endl;
    // while (true){
    //     continue;
    // }

}

