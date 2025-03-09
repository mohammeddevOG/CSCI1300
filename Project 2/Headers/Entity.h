//Entity.h
#ifndef ENTITY_H
#define ENTITY_H
/*
 * CSCI 1300 Spring 2024 
 * Author: Mohammed Abdulrahman 
 * TA: Anush Venkatesh 
 * Date: 2024-04-25
 * Description: Header Headers
 * Header file  
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Struct.h"

using namespace std;
// The struct needed
// Good idead to sperate the struct to a file
// But I'm not gonna do that
// struct Potions {
//     string name;
//     char type;
//     double effect_value;
//     int quantity;
// };

// struct Equipment {
//     string name;
//     char type;
//     char element;
//     double damege;
//     double defense;
//     double price;
// };


class Entity {
    private:
        // Varibles
        string _name;
        string _nItems;
        string _advantage;
        double _hp;
        double _stamina;
        double _defense;
        int _gold;
        char _condetion;
        char _elementWeakness;
        bool _isEnemy;
        float _clamity;
        const static int MAX_EQUIPPED = 2;

        // list / array-vectors
        vector<Potions>  _potions;
        Equipment _equipped[MAX_EQUIPPED]; // I though array better here since the size is allocated
        vector<Equipment> _inventory;
        vector<string> _items; // just for refrense I wanted to intilize the vector here I spend half an hour to solve it!
        
    
    public:
        // Intilizing and setter/getters

        // consteructrs
        Entity();
        Entity(string, double, int, char, bool);

        // getters
        bool getIsEnemy();
        bool getAdvantage();
        char getCondition();
        double getHP();
        double getStamina();
        double getDefense();
        int getGold();
        int getNItems();
        string getName();
        string getItems();
        char getElementWeekness();



        // setters
        void setName(string);
        void setHP(double);
        void setCondition(char);
        void setGold(int);
        void setStamina(double stamina);
        void setDefense(double defense);
        void setAdvantage(string adv);
        void setIsEnemy(bool);
        void setNItems(string item);
        void setItemes(string item);
        void setElementWeakness(char eWeek);
        void printStats();

        // Actions function that deals with the motion of the game
        void swap(int userChoice);
        void drop(int userChoice);
        void usePotion(int userChoice);
        void updateEquipment(int equipIndex, Equipment weapon);
};

#endif
