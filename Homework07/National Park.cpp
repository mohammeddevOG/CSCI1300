/*
 * CSCI 1300 Spring 2024 
 * Author: Mohammed Abdulrahman 
 * TA: Anush Venkatesh 
 * Date: 2024-03-18
 * Description: Homework Headers
 * Question 01
 */

#include <iostream>
#include <fstream>

using namespace std;

void listNationalParks(string filename);


int main(){
    string filename;

    cout << "Enter national parks filename" << endl;
    cin >> filename;
    listNationalParks(filename);
    return 0;
}

void listNationalParks(string filename){

    ifstream myFile(filename);

    if (myFile.fail()){
        cout << "Faild to open file." << endl;
        return;
    }

    const int MAX_SIZE = 63;
    string parks[MAX_SIZE];

    string park;

    int idx = 0;
    while(getline(myFile, park)){
        parks[idx] = park;
        idx += 1;

        if (idx == MAX_SIZE) {
            break;
        }
    }

    for(int i = 0; i < idx; ++i){
        cout << i << ": " << parks[i] << endl;
    }

    myFile.close();
}
