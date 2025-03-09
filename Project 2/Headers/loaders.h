// Loaders.h
#ifndef LOADERS_H
#define LOADERS_H
/*

    This header File For loading files reading/writing
    Creator: Mohammed Alhazmi --  The life thats not worth living.

*/
#include <iostream>
#include <fstream>
#include "Entity.h"

using namespace std;
// vectors RULE!
bool loadChracters(Entity Chracters[], const int MAX_SIZE) {
    cout << "Loading Chracters.." << endl;
    bool functionFlag = false;
    string filename = "Data/Characters.txt";
    ifstream in_file(filename);

    if (!in_file.is_open()){
        cout << "No File, Fix you Files" << endl;
    } else {
        string line;
        bool flag = false;
        int index = 0;
        //cout << "[DEBUG] Here in the else" << endl;
        while (getline(in_file, line)){
            //cout << "[DEBUG] Line is: " << line << endl;
            int length = line.length();
            for (int i = 0; i < length; i++){
                length = line.length();
                size_t pos = line.find('|');

                // #0 Name 
                if (pos != string::npos){ 
                    string name = line.substr(0, pos);
                    // check if the first line or not;
                    if (name == "name"){
                        break; // Break from the For loop not the while,
                    } else {
                        if ((name.length() > 1) && isalpha(name[0])){
                            //cout << "[DEUG] Name is : " << name << endl;
                            Chracters[index].setName(name);
                            functionFlag = true; // this tells me that the function worked correct and extracting done 
                            flag = true; // this one for the index mangements, I think because I'm using vectors I don't need it but it made my code readable at least for me
                        }
                    }
                    line = line.substr(pos+1);
                    pos = line.find('|');
                
                // #1 Enemy or Player -- bool check
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
                    double hp = stoi(line.substr(0, pos)); // you can deduct points for me because I'm not checking the number; but I'm in controll of the text file so no need to add stress on the CPU!
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
                    for (int i = 0; i < (int) items.length(); i++){
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

            // if (index == 13){
            //     functionFlag = true;
            //     break;
            // }
        }
    }
    return functionFlag;
}

bool loadEqu(Equipment Equ[], const int MAX_SIZE) {
    cout << "Loading Equipment.." << endl;
    bool functionFlag = false;
    // parsing the file
    ifstream in_file("Data/Equipment.txt");

    if (in_file.fail()){
        functionFlag = false;
    }
    bool flag = false;
    string line;
    // they say .eof is bugy but in my case I'm in control of the flow of the program
    int index = 0;
    while (getline(in_file, line)){
        int length = line.length();
        for (int i = 0; i < length; i++){
            // int newLine = line.find('\n');
            // cout << "[DEBUG] The New Line is in line: " << newLine << endl;
            // cout << "[DEBUG] The char Before it is: " << line[newLine-1] << endl;
            length = line.length();
            size_t pos = line.find('|');
            if (pos != string::npos){ // -->> Extreact the name; #0
                string name = line.substr(0, pos);
                // check if the first line or not;
                if (name == "name"){
                    break;
                } else {
                    if (name.length() > 1){
                        Equ[index].name = name;
                        functionFlag = true;
                        flag = true;
                    }
                    
                }
                //cout << index <<  ":Name is : " << name << endl;;
                line = line.substr(pos+1);
                //cout << "[DEBUG] Line before De is: " << line << endl;
                pos = line.find('|');

                // Description Extreaction and so on #1
            if (pos != string::npos){ 
                string description = line.substr(0, pos);
                //cout << "[DEBUG] Description : " << description << endl;
                line = line.substr(pos+1);
                pos = line.find('|');
            }
            //line = line.substr(pos+1);
            //cout << "[DEBUG] Line before type is: " << line << endl;
            //pos = line.find('|');

            // type #2 -- Correct
            if (pos != string::npos){ 
                string type = line.substr(0,pos);
                //cout << "[DEBUG] Type is : " << type << endl;
                Equ[index].type = type[0];
                //cout << "HP Is: " << hp << endl;
                line = line.substr(pos+1);
                pos = line.find('|');
            }

            // effect_value #3 --> Dmg or Def -- checking
            if (pos != string::npos){
                double effect_value = stod(line.substr(0, pos)); //  we know because we are the one who created the text file that in this is an double value no checking needed 
                //cout << "[DEBUG] Effected Value is: " << effect_value << endl;
                //cout <<  "[DEBUG] INDEX at: " << index << endl;
                if (Equ[index].type == 'D'){ 
                    Equ[index].damege = effect_value; 
                    Equ[index].defense = 0;
                } else  if (Equ[index].type == 'S'){
                    Equ[index].defense = effect_value;
                    Equ[index].damege = 0; 
                }

                // doing teh magic of substring
                line = line.substr(pos+1);
                //cout << "[DEBUG] Effected Value After Cutting: " << line << endl; // Correct Line Cutting No Issue Here
                pos = line.find('|');
            }

            // Element #4 -- correct No Need Cheeking
            if (pos != string::npos){
                string element = line.substr(0, pos);
                //cout << "[DEBUG] Element is: " << element << endl; // Amazing Correct As well, Where is the Issue?
                Equ[index].element = element[0]; 

                line = line.substr(pos+1);
                pos = line.find('|');

                //cout << "[DEBUG] Element Value After Cutting: " << line << endl; // Correct Line Cutting No Issue Here

            }

            // Price #5 -- correct No Need Cheeking
            if (line.length() > 0){
                double price = stod(line.substr(0, pos));
                //cout << "[DEBUG] Price: " << price << endl;
                Equ[index].price = price;
            }
        }
    }
            // increment the lines count 
        if (flag){
            index++;
        }

        if (index == MAX_SIZE){
            flag = true;
            break;
        }
    }

    return functionFlag;
}

bool loadPotions(Potions Pot[], const int MAX_SIZE){
    cout << "Loading Potions..." << endl;
    bool functionFlag = false;
    // parsing the file
    fstream in_file("Data/Potions.txt");

    if (in_file.fail()){
        functionFlag = false;
    }
    bool flag = false;
    string line;
    // they say .eof is bugy but in my case I'm in control of the flow of the program
    int index = 0;
    while (getline(in_file, line)){
        int length = line.length();
        for (int i = 0; i < length; i++){
            // int newLine = line.find('\n');
            // cout << "[DEBUG] The New Line is in line: " << newLine << endl;
            // cout << "[DEBUG] The char Before it is: " << line[newLine-1] << endl;
            length = line.length();
            size_t pos = line.find('|');
            if (pos != string::npos){ // -->> Extreact the name; #0
                string name = line.substr(0, pos);
                // check if the first line or not;
                if (name == "name"){
                    break;
                } else {
                    if (name.length() > 1){
                        Pot[index].name = name;
                        functionFlag = true;
                        flag = true;
                    }
                }
                //cout << index <<  ":Name is : " << name << endl;;
                line = line.substr(pos+1);
                //cout << "[DEBUG] Line before De is: " << line << endl;
                pos = line.find('|');

                // Description Extreaction and so on #1
            if (pos != string::npos){ 
                string description = line.substr(0, pos);
                //cout << "[DEBUG] Description : " << description << endl;
                line = line.substr(pos+1);
                pos = line.find('|');
            }

            // type #2 -- Correct
            if (pos != string::npos){ 
                string type = line.substr(0,pos);
                //cout << "[DEBUG] Type is : " << type << endl;
                Pot[index].type = type[0];
                //cout << "HP Is: " << hp << endl;
                line = line.substr(pos+1);
                pos = line.find('|');
            }

            // effect_value #3 --> Dmg or Def -- checking
            if (pos != string::npos){
                double effect_value = stod(line.substr(0, pos)); //  we know because we are the one who created the text file that in this is an double value no checking needed 
                //cout << "[DEBUG] Effected Value is: " << effect_value << endl;
                //cout <<  "[DEBUG] INDEX at: " << index << endl;
                Pot[index].effect_value = effect_value;

                // doing teh magic of substring
                line = line.substr(pos+1);
                //cout << "[DEBUG] Effected Value After Cutting: " << line << endl; // Correct Line Cutting No Issue Here
                pos = line.find('|');
            }

            // Element #4 -- correct No Need Cheeking -- None in Potions
            if (pos != string::npos){
                string element = line.substr(0, pos);
                //cout << "[DEBUG] Element is: " << element << endl; // Amazing Correct As well, Where is the Issue?
                //Equ[index].element = element[0]; 

                line = line.substr(pos+1);
                pos = line.find('|');

                //cout << "[DEBUG] Element Value After Cutting: " << line << endl; // Correct Line Cutting No Issue Here

            }

            // Price #5 -- correct No Need Cheeking --> Qunity in Potions
            if (line.length() > 0){
                int qynt = stoi(line.substr(0, pos));
                //cout << "[DEBUG] Price: " << price << endl;
                Pot[index].quantity = qynt;
            }
        }
    }
            // increment the lines count 
        if (flag){
            index++;
        }

        if (index == MAX_SIZE){
            flag = true;
            break;
        }
    }

    return functionFlag;
}

#endif