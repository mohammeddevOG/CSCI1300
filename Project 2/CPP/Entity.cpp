/*
 * CSCI 1300 Spring 2024 
 * Author: Mohammed Abdulrahman 
 * TA: Anush Venkatesh 
 * Date: 2024-03-30
 * Description: Header Implmetntion
 */

#include "../Headers/Entity.h"

// this construct just create an empty entity
Entity::Entity(){
    //cout << "[DEBUG] The constrctor worked" << endl;
    _gold = 0;
    _hp = 0.00;
    _name = "";
    _condetion = 'H';
    _isEnemy = false;
    _defense = 0;
    _stamina = 0;
    _advantage = false;
    _clamity = 0.0;

}
// this one is from the homework we should include the stamina and defense and other stuff.
Entity::Entity(string name, double hp, int gold, char condition, bool enemy){
    _name = name;
    if (hp > 0){
        _hp = hp;
    } else {
        _hp = 0.00;
    }

    if ((condition == 'H')|| (condition == 'D') || (condition == 'P')){
        _condetion = condition;
    } else {
        _condetion = 'H';
    }
    if (gold > 0){
        _gold = gold;
    } else {
        _gold = 0;
    }
    
    _isEnemy = enemy;

}

string Entity::getName(){
    return _name;
}

double Entity::getHP(){
    return _hp;
}

char Entity::getCondition(){
    return _condetion;
}

int Entity::getGold(){
    return _gold;
}

double Entity::getStamina() {
    return _stamina;
}

double Entity::getDefense() {
    return _defense;
}

bool Entity::getAdvantage() {
    if (_advantage == "True"){
        return true;
    } else {
        return false;
    }
}
bool Entity::getIsEnemy(){
    return _isEnemy;
}

char Entity::getElementWeekness(){
    return _elementWeakness;
}

void Entity::setName (string name){
    _name = name;
    //cout << "Name Has Been Set to " << _name << endl;
}

void Entity::setHP(double HP){
    if (HP > 0){
        _hp = HP;
    }
}

void Entity::setStamina(double stamina){
    _stamina = stamina;
}

void Entity::setDefense(double defense){
    _defense = defense;
}

void Entity::setAdvantage(string adv){
    _advantage = adv;
}

void Entity::setCondition(char condition){
    if ((condition == 'H')|| (condition == 'D') || (condition == 'P')){
        _condetion = condition;
    }
}

void Entity::setGold(int gold){
    if (gold > 0){
        _gold = gold;
    }
}

void Entity::setIsEnemy(bool is_enemey){
    _isEnemy = is_enemey;
}
void Entity::setNItems(string nItems){
    _nItems = nItems;
}
void Entity::setElementWeakness(char elmentWeek){
    _elementWeakness = elmentWeek;
}
void Entity::setItemes(string item){
    _items.push_back(item);
}
void Entity::printStats(){
    cout << getName() << "'s " << "stats:" << endl;
    cout << fixed << "HP: " << setprecision(2) << getHP() << endl;
    cout << "Condition: " << getCondition() << endl;
    cout << "Gold: " << getGold() << endl;
    cout << "Stamina: " << getStamina() << endl;
    cout << "Defense: " << getDefense() << endl;
    cout << "Advanatage: " << getAdvantage() << endl;
    cout << "Elemnetal Weakness: " << getElementWeekness() << endl;
    if (getIsEnemy()){
        cout << "Is Enemy: Yes" << endl;
    } else {
        cout << "Is Enemy: No" << endl;
    }

}

// here the action/motion functions

void Entity::swap(int userChoice){
    if (userChoice == 1){ // ---> 1 Equibment change
        // Do the swapping for weaopns;
    } else { // ---> 2 potions change
        // Do the the Swapping for potions
    }
}

void Entity::drop(int userChoice){
    if (userChoice == 1){
        Equipment empty;
        _equipped[0] = empty;
    } else {
        Potions empty;
        _potions[0] = empty;
    }
}

void Entity::usePotion(int userChoice){
    //_potions[userChoice];
}

void Entity::updateEquipment(int equipIndex, Equipment weapon) {
    _equipped[equipIndex] = weapon;
}
