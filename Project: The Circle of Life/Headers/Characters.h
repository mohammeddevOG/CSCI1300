// Chracters.h
#ifndef CHARACTERS_H  // Header guard to prevent double inclusion
#define CHARACTERS_H
/*
 * File: /home/jovyan/CSCI1300/Projects/Project02_2025/Header/Characters.h
 * Project: /home/jovyan/CSCI1300/Projects/Project02_2025/Header
 * Created Date: Monday April 7th 2025
 * Author: Mohammed Abdulrahman
 * -----
 * Last Modified:
 * Modified By:
 * -----
 * CSCI 2270 Class
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std; // not waht you think 

class Character {
    private:
        string _playerName;
        int _age;
        int _strength; // magical energy that the character has
        int _stamina;
        int _wisdom;
        int _pridePoint;
        bool _isCreature;


    public:
        // For constructers & setter/getter
        Character();
        Character(string, int, int, int, int, int, bool);

        // getter
        string getPlayerName();
        int getAge();
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPridePoint();
        bool getIsCreature();


        // setters
        void setPlayerName(string);
        void setAge(int);
        void setStrenth(int);
        void setStamina(int);
        void setWisdom(int);
        void setPridePoint(int);
        void setIsCreature(bool);


        // helpful functions
        void printStats();

};

#endif
