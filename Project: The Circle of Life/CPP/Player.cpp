/*
 * File: /home/jovyan/CSCI1300/Projects/Project02_2025/CPP/Player.cpp
 * Project: /home/jovyan/CSCI1300/Projects/Project02_2025/CPP
 * Created Date: Sunday April 13th 2025
 * Author: Mohammed Abdulrahman
 * -----
 * Last Modified:
 * Modified By:
 * -----
 * For Love
 */
#include "../Headers/Game.h"
#include "../Headers/Player.h"

Player::Player(){
    Character ch;
    _player = ch;
    _pathChoice = 0;
    _advisor = 0;
    _postion = 0;
}

Player::Player(Character NewPlayer, int path, int advisor){
    _player = NewPlayer;
    _pathChoice = path;
    _advisor = advisor;
    _postion = 0;
}

Character Player::getPlayer(){
    return _player;
}

int Player::getPathChoice(){
    return _pathChoice;
}

int Player::getAdvisor(){
    return _advisor;
}

int Player::getPostion(){
    return _postion;
}

void Player::setCharacter(Character newPlayer){
    _player = newPlayer;
}

void Player::setPath(int path){
    _pathChoice = path;
}

void Player::setAdvisor(int advisor){
    _advisor = advisor;
}

void Player::setPostion(int pos){
    _postion += pos;
}
int Player::throwDice(){
    srand(time(0));
    return (rand() % 6) + 1;
}

void Player::takeTurn(){
    cout << "it's " << getPlayer().getPlayerName() << "'s Turn" << endl;
    cout << "Main Menu: Select an option to continue" << endl;
    cout << "1. Check Player Progress (1)" << endl;
    cout << "2. Review Character (2)" << endl;
    cout << "3. Check Postion (3)" << endl;
    cout << "4. Review your Advisor (4)" << endl;
    cout << "5. Move Forward (5)" << endl;
    cout << endl;
    cout << "Please choose an option using the correspoidning number: \n#";

    string choice; // The reason why I choose string is to minimise erros
    cin >> choice;
    int move = 0;
    string ans1;

    switch(choice[0]){
        case '1':
            cout << "---------------------------------------------------------------------" << endl;
            cout << "The Player: " << getPlayer().getPlayerName() << "'s Stats:  " << endl;
            cout << "Pride Points: " << getPlayer().getPridePoint() << endl;
            cout << "Wisdom: " << getPlayer().getWisdom() << endl;
            cout << "Stamina: " << getPlayer().getStamina() << endl;
            cout << "Strength: " << getPlayer().getStrength() << endl;
            cout << "--------------------------------------------------------------------" << endl;
            cout << "Would you Like to convert you Leadership Poitns to Pride points?(y/n)" << endl;

            cin >> ans1;
            (ans1[0] == 'y' || ans1[0] == 'Y') ? cout << "Converted!!\n" : cout << "Moving On\n";
            takeTurn();
            break;
        case '2':
            cout << "---------------------------------------------------------------------" << endl;
            cout << "The Player: " << getPlayer().getPlayerName() << "'s Stats:  " << endl;
            cout << "Age: " << getPlayer().getAge() << endl;
            cout << "--------------------------------------------------------------------" << endl;
            takeTurn();
            break;
        case '3':
            cout << "The Player: " << getPlayer().getPlayerName() << "'s is in  " << getPostion() << endl;
            takeTurn();
            break;
        case '4':
            getAdvisor();
            cout << "Would Like to use the Advisor Ability?" << endl;
            takeTurn();
            break;
        case '5':
            move = throwDice();
            _postion += move;
            //setPostion(move);
            cout << "You've Moved " << move << endl;
            break;
        default:
            cout << "Please Choose a Vaild option!\n# ";
            takeTurn();
            break;
    }
}
