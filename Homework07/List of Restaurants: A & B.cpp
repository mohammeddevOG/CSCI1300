/*
 * CSCI 1300 Spring 2024 
 * Author: Mohammed Abdulrahman 
 * TA: Anush Venkatesh 
 * Date: 2024-03-22
 * Description: Homework Headers
 * Question 06
 */

#include <iostream>
#include <fstream>

using namespace std;

struct Restaurant {
    string name;
    int food_quality;
    int cleanliness;
    int wait_time;
    double overall;

};
int readRestaruntDetails(string filename, Restaurant restaurant[], const int MAX_RESTAURANT);
int getBest(Restaurant restaurant[], int arr_size, string metric);

int main(){
    const int MAX_SIZE = 30;
    Restaurant r[MAX_SIZE];
    int size_of_res = readRestaruntDetails("res.txt",r, MAX_SIZE);
    cout << size_of_res << endl;
    for (int i = 0; i < size_of_res; i++){
        cout << "The name of The Resturant: " << r[i].name << endl;
        cout << "The Food Quality of The Resturant: " << r[i].food_quality << endl;
        cout << "The Cleainness of The Resturant: " <<  r[i].cleanliness << endl;
        cout << "The Wait time Resturant: " << r[i].wait_time <<  endl;
    }
    return 0;
}

int readRestaruntDetails(string filename, Restaurant restaurant[], const int MAX_RESTAURANT){
    ifstream file_in(filename);
    int cols = 0;
    int rows = 0;
    string line;
    if (file_in.fail()){
        return -1;
    } else {
        while(getline(file_in, line)){
            for (int i = 0; i < (int) line.length(); i++){
                if (line[i] == '~') {
                    cout << "Done" << endl;
                    rows++;
                }
            }
            cout << rows << endl;
            if (rows == 3){
                int pos = 0;
                pos = line.find("~");
                restaurant[cols].name = line.substr(0,pos);

                int prev_pos = pos + 1;
                pos = line.find('~', prev_pos);
                cout << "[DEBUG] Value of teh substr " <<line.substr(prev_pos,pos - prev_pos) << endl; 
                restaurant[cols].food_quality = stoi(line.substr(prev_pos,pos - prev_pos));

                prev_pos = pos + 1;
                pos = line.find('~', prev_pos);
                cout << "[DEBUG] Value of teh substr " <<line.substr(prev_pos,pos - prev_pos) << endl;
                restaurant[cols].cleanliness = stoi(line.substr(prev_pos,pos - prev_pos));

                prev_pos = pos + 1;
                pos = line.find('~', prev_pos);
                cout << "[DEBUG] Value of teh substr " <<line.substr(prev_pos,pos - prev_pos) << endl;
                //restaurant[lines].wait_time = stoi(line.substr(prev_pos,pos - prev_pos));
                cols++;
            } 
        }
    }
    return cols;
}
