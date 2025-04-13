/*
 * File: /home/jovyan/CSCI1300/Projects/Project02_2025/GameDriver.cpp
 * Project: /home/jovyan/CSCI1300/Projects/Project02_2025
 * Created Date: Monday April 7th 2025
 * Author: Mohammed Abdulrahman
 * -----
 * Last Modified:
 * Modified By:
 * -----
 * For Love
 */

// Predefined Headers
#include "Headers/Game.h"
#include "Headers/Loaders.h"
#include "Headers/HelperFunctions.h"
#include "Headers/Player.h"
#include <cstdlib>
#include <unistd.h>
#include <ctime>

// Loading Characters and showing it to the user is the first Step;
// Loading the mape is the second step - wating for yaser to give me the files

using namespace std; // not what you think!
void mainMenu(){
    cout << "Main Menu: Select an option to continue" << endl;
    cout << "1. Check Player Progress (1)" << endl;
    cout << "2. Review Character (2)" << endl;
    cout << "3. Check Postion (3)" << endl;
    cout << "4. Review your Advisor (4)" << endl;
    cout << "5. Move Forward (5)" << endl;
    cout << endl;
    cout << "Please choose an option using the correspoidning number: ";
}

int main(){
    // this is for the board randomizer
    srand(time(0));
    // For Game Class
    vector<Player> players; //  Vector because we can have more than two players 
    vector <int> pathType;// it's of size two 0 for player 1, and 1 for player 2

    // End of decleartion

    // Data Gathering    
    vector<Character> charactersData = extrtactCharacters(false);
    vector<Character> creaturesData = extrtactCharacters(true);
    vector<Riddles> riddlesData = extractRiddles();
    vector<Events> eventsData = extractEvents();
    
    // Error Handling/Checking files 
    if (!(riddlesData.empty()) && !(charactersData.empty()) && !(creaturesData.empty())){
        cout << "Welcome to The Circle of Life:" << endl;
        sleep(2);
        cout << "\t - Created By Mohammed Abdulrahman" << endl;
        sleep(2);
        cout << "\t - For Love or loneliness / you choose " << endl;
        sleep(2);
    }

    int playersInGame = getNumberInput("How many People are Playing?\n#");

    for (int i =0; i < playersInGame; i++){
        Player player;
        printChracterSlectionMenu(charactersData);
        cout << "Player #" << (i+1) << endl;
        int playerChoice = getNumberInput("Choose Your Lion:# ");
        int pathType = getNumberInput("Player 1 Choose Your Path:\n\t-1. Cub Training\n\t-2. Stright to Pride Land\n#");
        int advisor = getNumberInput("Player 1 Choose Your Advisor\n#");
        player.setCharacter(charactersData[playerChoice]);
        player.setPath(pathType);
        player.setAdvisor(advisor);
        players.push_back(player);
        charactersData.erase(charactersData.begin() + (playerChoice-1));
    }
    
    // Printing Players Names:
    cout << "============================== Players =========================" << endl;
    cout << "Players: " << endl;
    for (int i =0; i < players.size(); i++){
        Character ch = players[i].getPlayer();
        cout << "Player #" << (i+1) << "Picked: " << ch.getPlayerName() << endl;
    }
    cout << "============================== Players =========================" << endl;
    cout << endl;

    // Just For Debugging - Checking if functions works 
    Game newGame(players, creaturesData, riddlesData, eventsData);
    // vector <Riddles> riddle = newGame.getRandomRiddle();
    // cout << "======================== Randome Riddle =======================" << endl;
    // cout << "Question: " << riddle[0].question << endl;
    // cout << "Answer: " << riddle[0].answer << endl;
    // cout << "======================= Random Riddle =========================" << endl;


    // vector<Events> goodEvent = newGame.getEvent(false);
    // cout << "======================= Events ================================" << endl;
    // cout << "Advisor: " << goodEvent[0].advisor << endl;
    // cout << "Describtion: " << goodEvent[0].description << endl;
    // cout << "Path Type: " << goodEvent[0].pathType << endl;
    // cout << "Pride Points: " << goodEvent[0].PP << endl;
    // cout << "====================== Events ================================" << endl;

    // vector<Events> badEvent = newGame.getEvent(true);
    // cout << "======================= Events ================================" << endl;
    // cout << "Advisor: " << badEvent[0].advisor << endl;
    // cout << "Describtion: " << badEvent[0].description << endl;
    // cout << "Path Type: " << badEvent[0].pathType << endl;
    // cout << "Pride Points: " << badEvent[0].PP << endl;
    // cout << "====================== Events ================================" << endl;

    newGame.playGame();

}
