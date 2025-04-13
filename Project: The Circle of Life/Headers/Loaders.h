// Loaders.h
//#ifndef LOADERS_H  // Header guard to prevent double inclusion
#define LOADERS_H
/*
 * File: /home/jovyan/CSCI1300/Projects/Project02_2025/Header/Loaders.h
 * Project: /home/jovyan/CSCI1300/Projects/Project02_2025/Header
 * Created Date: Monday April 7th 2025
 * Author: Mohammed Abdulrahman
 * -----
 * Last Modified:
 * Modified By:
 * -----
 * For Love
 */

//Loader File For loading any data I want

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include "Characters.h"
#include "Riddles.h"
#include "Events.h"

using namespace std; // is not what you think it's


//Function for laoding and extracting data

vector<Character> extrtactCharacters(ifstream &dataFile, bool isCreature);
vector<Riddles> extractRiddles();
bool loadeAdvisors(ifstream &dataFile, Events eventsList[]);

// Function for extracting chracters/Creatures from files
vector<Character> extrtactCharacters(bool isCreature){
    cout << "Loading Charactes/Creatures..." << endl;

    // Files Names
    const string characterFileN = "Data/character.txt";
    const string creatureFileN = "Data/creatures.txt";


    // Files Object based on the passed boolean - default is the characters file
    ifstream dataFile;
    if (isCreature){
        dataFile.open(creatureFileN);
    } else {
        dataFile.open(characterFileN);
    }

    // Checing
    if (!(dataFile.is_open()) ){
        cout << "[DEBUG] Faild to open one of the files: " << endl;
        cout << "\t -" << characterFileN << endl;
        cout << "\t -" << creatureFileN << endl;
        cout << "[DEBUG] End of message" << endl;
    }

    // Beging the extracting
    string line;
    vector <Character> characters;

    while (getline(dataFile, line)){
        int length = line.length();
        if (length == 0) continue;

        size_t pos = line.find('|');
        
        // ignoring the first line;
        if (pos != string::npos && line.substr(0, pos) == "PlayerName") {continue;}

        // Creating a vector for the info
        vector <string> data;
        
        while (pos != string::npos){
            data.push_back(line.substr(0, pos));
            line = line.substr(pos + 1);
            pos = line.find('|');
        }

        if (!line.empty()){
            data.push_back(line);
        }

        // This is for setting the class variables
        // cout << "[DEBUG] Size of Data: " << data.size() << endl;

        Character ch;
        ch.setPlayerName(data[0]);
        ch.setAge(stoi(data[1]));
        ch.setStrenth(stoi(data[2]));
        ch.setStamina(stoi(data[3]));
        ch.setWisdom(stoi(data[4]));
        ch.setPridePoint(stoi(data[5]));
        ch.setIsCreature(isCreature);
        // End of it

        characters.push_back(ch);
    }

    return characters;
}

// Riddles
vector<Riddles> extractRiddles(){
    cout << "Loading Riddles..." << endl;


    const string riddleFileN = "Data/riddles.txt";
    ifstream dataFile(riddleFileN);

    if (!(dataFile.is_open())){
        cout << "[DEBUG] Failed to open Riddle File: " << endl;
        cout << "\t - " << riddleFileN << endl;
        cout << "[DEBUG] End of message" << endl;
    }

    // Beging the extracting
    vector <Riddles> riddlesData;
    string line;

    while (getline(dataFile, line)){
        int length = line.length();
        if (length == 0) continue;
        size_t pos = line.find('|');
        
        // ignoring the first line;
        if (pos != string::npos && line.substr(0, pos) == "Question(answer specifications)") {continue;}

        // Creating a vector for the info
        vector <string> data;
        
        while (pos != string::npos){
            data.push_back(line.substr(0, pos));
            line = line.substr(pos + 1);
            pos = line.find('|');
        }

        if (!line.empty()){
            data.push_back(line);
        }
        Riddles riddle;
        riddle.question = data[0];
        riddle.answer = data[1];

        riddlesData.push_back(riddle);
    }

    return riddlesData;
}


// Advisors 
vector<Events> extractEvents(){
    cout << "Loading Events..." << endl;
    const string riddleFileN = "Data/random_events.txt";
    ifstream dataFile(riddleFileN);

    if (!(dataFile.is_open())){
        cout << "[DEBUG] Failed to open Events File: " << endl;
        cout << "\t - " << riddleFileN << endl;
        cout << "[DEBUG] End of message" << endl;
    }

    string line;
    vector<Events> eventsData;

    while (getline(dataFile, line)){
        int length = line.length();
        if (length == 0) continue;

        size_t pos = line.find('|');
        
        // ignoring the first line;
        if (pos != string::npos && line.substr(0, pos) == "Description") {continue;}

        //cout << "[DEBUG] Line: " << line << endl; 
        // Creating a vector for the info
        vector <string> data;
        
        while (pos != string::npos){
            data.push_back(line.substr(0, pos));
            line = line.substr(pos + 1);
            pos = line.find('|');
        }

        if (!line.empty()){
            data.push_back(line);
        }
        Events event;
        event.description = data[0];
        event.pathType = stoi(data[1]);
        event.advisor = stoi(data[2]);
        event.PP = stoi(data[3]);

        eventsData.push_back(event);
    }

    return eventsData;
}
