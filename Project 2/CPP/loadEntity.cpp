#include <iostream>
#include <string>
#include <fstream>
#include "CPP/Headers/Entity.h"

using namespace std;

bool loadEntity(Entity Chracters[], const int ChractersSize) {
    bool functionFlag = false;
    string filename = "Data/Characters.txt";
    fstream in_file (filename);
    string line;
    bool flag = false;
    int index = 0;
    while (getline(in_file, line)){
        int length = line.length();
        for (int i = 0; i < length; i++){
            length = line.length();
            size_t pos = line.find('|');

            // #0 Name 
            if (pos != string::npos){ 
                string name = line.substr(0, pos);
                // check if the first line or not;
                if (name == "name"){
                    break;
                } else {
                    if ((name.length() > 1) && isalpha(name[0])){
                        //cout << "[DEUG] Name is : " << name << endl;
                        Chracters[index].setName(name);
                        flag = true;
                    }
                }
                line = line.substr(pos+1);
                pos = line.find('|');
            
            // #1 Enemy or Player
            if (pos != string::npos){ 
                string type = line.substr(0, pos);
                //cout << "[DEBUG] Type is: " << type << endl;
                if(type[0] == 'P') {Chracters[index].setIsEnemy(false);}
                else {Chracters[index].setIsEnemy(true);}
                line = line.substr(pos+1);
                pos = line.find('|');
            }

            //#2 HP
            if (pos != string::npos){
                //cout << "[DEBUG] Problems is: " << line.substr(0, pos) << endl;
                double hp = stoi(line.substr(0, pos));
                Chracters[index].setHP(hp);
                // doing teh magic of substring
                line = line.substr(pos+1);
                pos = line.find('|');
            }

            // #3 Stamina
            if (pos != string::npos){
                //cout << "[DEBUG] Or Here: " <<line.substr(0,pos) << endl;
                double stamina = stod(line.substr(0, pos));
                Chracters[index].setStamina(stamina);
                line = line.substr(pos+1);
                pos = line.find('|');

            }
            // #4 Defense
            if (pos != string::npos){
                //cout << "[DEBUG] Or Here: " <<line.substr(0,pos) << endl;
                double stamina = stod(line.substr(0, pos));
                Chracters[index].setStamina(stamina);
                line = line.substr(pos+1);
                pos = line.find('|');

            }
            // #5 condetion
            if (pos != string::npos){
                string condetion = line.substr(0,pos);
                //cout << "[DEBUG] Condetion is: " << condetion << endl;
                Chracters[index].setCondition(condetion[0]);
                line = line.substr(pos+1);
                pos = line.find('|');

            }
            // #6 advantage
            if (pos != string::npos){
                //cout << "[DEBUG] Advantage: " <<line.substr(0,pos) << endl;
                string adv = line.substr(0, pos);
                Chracters[index].setAdvantage(adv);
                line = line.substr(pos+1);
                pos = line.find('|');

            }
            // #7 Element of Weakness --- Forget For now
            if (pos != string::npos){
                //cout << "[DEBUG] Or Here: " <<line.substr(0,pos) << endl;
                string ElmentWeakness = line.substr(0, pos);
                Chracters[index].setElementWeakness(ElmentWeakness[0]);
                line = line.substr(pos+1);
                pos = line.find('|');

            }
            // #8 Gold
            if (pos != string::npos){
                double gold = stod(line.substr(0, pos));
                Chracters[index].setGold(gold);
                line = line.substr(pos+1);
                pos = line.find('|');

            }

            // #9 Starting items
            if (pos != string::npos){
                string sItems[2];
                int index = 0;
                string items = line.substr(0,pos);
                for (int i = 0; i < items.length(); i++){
                    if (items[i] != ','){
                        sItems[index] += items[i];
                    } else {
                        index++;
                    }
                }
                line = line.substr(pos+1);
                pos = line.find('|');

            }

            // #10 nItems
            if (line.length() > 0){
                string nItems = line.substr(0, pos);
                Chracters[index].setNItems(nItems);
            }
        }
    }
            // increment the lines count 
        if (flag){
            index++;
        }

        if (index == 13){
            functionFlag = true;
            break;
        }
    }

    return functionFlag;
}

bool loadEqu()
int main(){
    const int MAX_SIZE = 13;
    Entity Chracters[MAX_SIZE];

    if (loadEntity(Chracters, MAX_SIZE)) {
        cout << "Loaded Files Succfuly" << endl;
    }
    for (int i = 0; i < MAX_SIZE; i++){
        Chracters[i].printStats();
        cout << "---------------------------------" << endl;
    }
}