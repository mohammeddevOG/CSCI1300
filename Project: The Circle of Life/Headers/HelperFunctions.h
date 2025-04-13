// Function that will help me build the game
/*
 * File: /home/jovyan/CSCI1300/Projects/Project02_2025/Headers/HelperFunctions.h
 * Project: /home/jovyan/CSCI1300/Projects/Project02_2025/Headers
 * Created Date: Tuesday April 8th 2025
 * Author: Mohammed Abdulrahman
 * -----
 * Last Modified:
 * Modified By:
 * -----
 * CSCI 2270 Class
 */


#include "Game.h"
string convertToLower(string);

// Function for getting the playerChoice
int getNumberInput(string prompt) {
    int number;
    bool valid = false;

    while (!valid) {
        cout << prompt;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter a valid number.\n";
        } else {
            valid = true;
            cin.ignore(1000, '\n');
        }
    }

    return number;
}


int getPlayerChoice(int playerNumber){
    int playerChoice;
    char choice;

    cout << "Player " << playerNumber << " Chooese you Character:# ";
    cin >> choice;

    bool flag = true;
    while (flag){
        if (!isdigit(choice)){
            cout << "Please onlly type a digits! ";
            cout << "Player " << playerNumber << "Chooese you Character: " << endl;
        } else if (((choice - '0') > 5) || ((choice - '0') < 1)){
            cout << "Please only choose betwwen the limits: " << endl;
            cout << "Player " << playerNumber << "Chooese you Character: " << endl;
        } else {
            playerChoice = choice - '0';
            flag = false;
        }   
    }

    return playerChoice - 1; 
}


// Function for priting the Selection Menu
void printChracterSlectionMenu(vector<Character> charactersData){
    for (int i = 0; i < charactersData.size(); i++){
        charactersData[i].printStats();
    }
}

/*
    All of this For Riddles handling
*/

bool checkRiddlAnswer(string correctAnswer, string userAnswer){
    // First thing is to change the letters to either upper
    // or lower case
    correctAnswer = convertToLower(correctAnswer);
    userAnswer = convertToLower(correctAnswer);

    if (correctAnswer == userAnswer){
        return true;
    }

    return false;
}

string convertToLower(string word){
    const int length = word.length();
    string lowerWord;
    for (int i =0; i < length; i++){
        lowerWord += word[i] + 32;
    }
    return lowerWord;    
}

/*
    End of Riddle Handling
*/

/*
    Events Handling
*/

