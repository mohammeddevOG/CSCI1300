/*
 * CSCI 1300 Spring 2024 
 * Author: Mohammed Abdulrahman 
 * TA: Anush Venkatesh 
 * Date: 2024-04-24
 * Description: Headers
 * Driver File: The Main Driver 
 */

/*

    This is my manging files to make my life easier,
    CPP Folder --> contains the implemtantion of the headers,
    Hedaer Folder --> For obvios reason to make life easier,
    Data Folder --> Files That are needed for the game, entity,items,riddles,etc,
    This File in the root, I will give the compilers path to make the TA life easier,
    Thank You ---> BTW This was created in two days becase:
                   1. I'm an idots who formated his laptop without doing a backup
                   2. I'm also the idiots who spend most of his days learning unreal engine to create 
                      a game that will make me a PEROSN OF INTERSET!.

*/

#include "Headers/Game.h"
#include "Headers/Map.h"
#include "Headers/loaders.h"
#include <time.h>

#define RED "\033[41m"     /* Red */
#define GREEN "\033[42m"   /* Green */
#define BLUE "\033[44m"    /* Blue */
#define MAGENTA "\033[45m" /* Magenta */
#define CYAN "\033[46m"    /* Cyan */
#define RESET "\033[0m"

void mapCheck();

using namespace std;

int main(){
    vector <Entity> PlayableCharaters;
    vector <Entity> Playrs; 
    const int CHARACTERS_MAX_SIZE = 13;
    Entity Characters[CHARACTERS_MAX_SIZE];

    const int EQU_MAX_SIZE = 16;
    Equipment Equ[EQU_MAX_SIZE];

    const int POT_MAX_SIZE = 9;
    Potions Pot[POT_MAX_SIZE];

    
    cout << "Loading..." << endl;
    if (loadChracters(Characters, CHARACTERS_MAX_SIZE) && (loadEqu(Equ,EQU_MAX_SIZE)) && (loadPotions(Pot, POT_MAX_SIZE))) {
        cout << "Welcome to Odyseey!" << endl;
        for (int i = 0; i < CHARACTERS_MAX_SIZE; i++){
            if (!Characters[i].getIsEnemy()) {
                PlayableCharaters.push_back(Characters[i]);
            }
        }
    } else {
        cout << "[DEBUG] Faild to load Chracters" << endl;
    }

    for (int i = 0; i < (int) PlayableCharaters.size(); i++){
        cout << "(" << i+1 << ")" << PlayableCharaters[i].getName() << " "; 
    }
    cout << endl;
    Entity Player1;
    Entity Player2;

    char Player1_input = 0;
    char Player2_input = 0;
    //Game StartGame;
    cout << "Player1 Choose You Characters: " << endl;
    cin >> Player1_input;
    while (Playrs.size() < 2){
        if ((Player1.getName() != "") && (Player2.getName() != "")){
            break;
        }
        if (Playrs.size() < 1){ // if no players
            switch(Player1_input) {
            case '1':
                Player1 = PlayableCharaters[0];
                Playrs.push_back(Player1);
                break;
            case '2':
                Player1 = PlayableCharaters[1];
                Playrs.push_back(Player1);
                break;
            case '3':
                Player1 = PlayableCharaters[2];
                Playrs.push_back(Player1);
                break;
            case '4':
                Player1 = PlayableCharaters[3];
                Playrs.push_back(Player1);
                break;
            default:
                cout << "Please Input A valid Choice" << endl;;
                cout << "Player1 Choose You Characters: " << endl;
                break;
            }
        } else {
            cout << "Player2 Choose You Characters: " << endl;
            cin >> Player2_input;
            if (Player2_input == Player1_input){
                cout << "Please Choose Anoter Character" << endl;
            } else {
                switch(Player2_input) {
                    case '1':
                        Player2 = PlayableCharaters[0];
                        break;
                    case '2':
                        Player2 = PlayableCharaters[1];
                        break;
                    case '3':
                        Player2 = PlayableCharaters[2];
                        break;
                    case '4':
                        Player2 = PlayableCharaters[3];
                        break;
                    default:
                        cout << "Please Input A valid Choice";
                        cout << "Player2 Choose You Characters: " << endl;
                        break;
                
                }
           }
        }
    }
    cout << "Playes Have Choosen: " << endl;
    cout << "Player1: " << Player1.getName() << endl;
    cout << "Player2: " << Player2.getName() << endl;

    mapCheck();
    return 0;
}


void mapCheck(){

    cout << "Cheking Map....." << endl;
    Map Play;
    int location = 0;

    srand(time(NULL));

    int dice = rand() % 6;
    Play.initializeMap();
    while ((location <= 50)){
        dice = (rand() % 6) + 1;
        if (Play.getMapPos(0, location) == GREEN){
            //printing the Shop menu
            cout << Play.getMapPos(0, location) << "P" << location << RESET << endl;
            cout << "1. Buy " << endl;
            cout << "2. Sell" << endl;
            cout << "3. Trade" << endl;
            char input = 0;
            cin >> input;
            char flag = true;
            while(flag){
                switch(input){
                    case '1':
                        cout << "Done Bought" << endl;
                        flag = false;
                        break;
                    case '2':
                        cout << "Done Sold" << endl;
                        flag = false;
                        break;
                    case '3':
                        cout << "Done Traded" << endl;
                        flag = false;
                        break;
                    default:
                        cout << "For God Sake Put A Vaild Number : " << endl;
                        cout << "1. Buy " << endl;
                        cout << "2. Sell" << endl;
                        cout << "3. Trade" << endl;
                        //flag = true;
                        break;
                }
            }
        } else {
            cout << Play.getMapPos(0, location) << "P" << location <<  RESET <<endl;
        }
        cout << "[DEBUG] Dice is: " << dice << endl;
        location+=dice;

        if ((location == 50) && (Play.getMapPos(0,50) == GREEN)){
            cout << "Congrats You Reached Itech !" << endl;
        }
    }
}