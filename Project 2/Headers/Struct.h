#include <iostream>
#include <string>

using namespace std;

struct Potions {
    string name;
    char type;
    double effect_value;
    int quantity;
};

struct Equipment {
    string name;
    char type;
    char element;
    double damege;
    double defense;
    double price;
};