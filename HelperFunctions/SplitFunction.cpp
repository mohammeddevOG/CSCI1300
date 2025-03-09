/*
 * CSCI 1300 Spring 2024 
 * Author: Mohammed Abdulrahman 
 * TA: Anush Venkatesh 
 * Date: 2024-03-22
 * Description: Homework Headers
 * Question SPLIT FUNCTION
 */

#include <iostream>
#include <string>

using namespace std;

int split (string input_string, char sep, string arr[], const int MAX_SIZE);

int main() {
    string line = "Thsis is just a test to see my function "     
                   "dos'nt\n add any lines";
    const int MAX_SIZE = 100;
    string arr[MAX_SIZE];
    char sep = ' ';
    int words = split(line, sep, arr, MAX_SIZE);
    cout << words << endl;

    for (int i =0; i < words; i++){
        cout << arr[i] << endl;
    }

    return 0;

}

int split (string input_string, char sep, string arr[], const int MAX_SIZE) {
    int words_size = 0;

    for (int i =0; i < (int) input_string.length(); i++){
        if (isalpha(input_string[i])){
            arr[words_size] += input_string[i];
        } else if (input_string[i] == sep){
            if (input_string[i+1] == sep){
                continue;
            } else {
                words_size++;
            }
        }
    }

    return words_size;
}
