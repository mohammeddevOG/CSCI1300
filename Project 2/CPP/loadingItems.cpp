#include <iostream>
#include <fstream>
#include <vector>

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
bool load_Potions(Potions Pot[]);
bool is_number(string number){
    const int length = number.length();
    bool flag = false;
    int counter = 0;
    for (int i = 0; i < length; i++){
        if ((isdigit(number[i])) || (number[i] == '.')){
            //cout << "[DEBUG] the char I'm chacking: " << number[i] << endl;
            counter++;
        }
    }

    if (counter == length){
        flag = true;
    }

    return flag;

}

bool loading_items(Equipment Equ[]);

int main(){
    

    const int MAX_SIZE = 9;
    Potions Pot[MAX_SIZE];
    


    if (load_Potions(Pot)){
        for (int i = 0; i < MAX_SIZE; i++){
            cout << Pot[i].name << "\t";
            cout << Pot[i].type << "\t";
            cout << Pot[i].effect_value << "\t";
            cout << Pot[i].quantity << endl;;
        }
    }
}

bool load_Potions(Potions Pot[]){
    bool functionFlag = false;
    bool flag  = false;
    const int MAX_ITEMS = 25;
    Equipment Equ[MAX_ITEMS];
    // parsing the file
    fstream in_file("Data/Potions.txt");

    if (in_file.fail()){
        flag = false;
    }

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

        if (index == 9){
            functionFlag = true;
            break;
        }
    }

    return functionFlag;
}

