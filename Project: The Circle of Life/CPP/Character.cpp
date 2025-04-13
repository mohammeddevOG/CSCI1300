/*
 * File: /home/jovyan/CSCI1300/Projects/Project02_2025/CPP/Character.cpp
 * Project: /home/jovyan/CSCI1300/Projects/Project02_2025/CPP
 * Created Date: Monday April 7th 2025
 * Author: Mohammed Abdulrahman
 * -----
 * Last Modified:
 * Modified By:
 * -----
 * For Love
 */

#include "../Headers/Characters.h"

Character::Character() {
    _playerName = "";
    _age = 0;
    _strength = 0;
    _stamina = 0;
    _wisdom = 0;
    _pridePoint = 0;
    _isCreature = false;
}

Character::Character(string playerName, int age, int strength, int stamina, int wisdom, int PP, bool isCreature){
    _playerName = playerName;
    _isCreature = isCreature;

    // Checking Varibles
    age > 0 ? _age=age : _age = 0;
    strength > 0 ? _strength = strength : _strength = 0;
    stamina > 0 ? _stamina = stamina : _stamina = 0;
    wisdom > 0 ? _stamina = stamina : _stamina = 0;
    PP > 0 ? _pridePoint = PP : _pridePoint = 0;

}

// Getters Denfined here
string Character::getPlayerName(){
    return _playerName;
}

int Character::getAge(){
    return _age;
}

int Character::getStrength(){
    return _strength;
}

int Character::getStamina(){
    return _stamina;
}

int Character::getWisdom(){
    return _wisdom;
}

int Character::getPridePoint(){
    return _pridePoint;
}

bool Character::getIsCreature(){
    return _isCreature;
}

// Setters Defnied here

void Character::setPlayerName(string playerName){
    _playerName = playerName;
}

void Character::setAge(int age){
    age > 0 ? _age=age : _age = 0; 
}

void Character::setStrenth(int strength){
    strength > 0 ? _strength = strength : _strength = 0;
}

void Character::setStamina(int stamina){
    stamina > 0 ? _stamina = stamina : _stamina = 0;
}

void Character::setWisdom(int wisdom){
    wisdom > 0 ? _wisdom = wisdom : _wisdom = 0;
}

void Character::setPridePoint(int PP){
    PP > 0 ? _pridePoint = PP : _pridePoint = 0;
}


void Character::setIsCreature(bool isCreature){
    _isCreature = isCreature;
}


void Character::printStats(){
    cout << "--------------------------------------------------" << endl;;
    cout << getPlayerName() << "'s" << " Stats: " << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Stamina: " << getStamina() << endl;
    cout << "Strength: " << getStrength() << endl;
    cout << "Wisdom: " << getWisdom() << endl;
    cout << "Pride Point: " << getPridePoint() << endl;
    cout << "isCreature: ";
    (getIsCreature() == true) ? cout << "Yes" << endl : cout << "No" << endl;
    cout << endl;
}
