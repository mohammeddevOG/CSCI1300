/*
 * CSCI 1300 Spring 2024 
 * Author: Mohammed Abdulrahman 
 * TA: Anush Venkatesh 
 * Date: 2024-03-22
 * Description: Homework Headers
 * Question 04
 */
#include <iostream>

using namespace std;


struct Restaurant {
    string name;
    int food_quality;
    int cleanliness;
    int wait_time;
    double overall;

};
double getOverallRating(Restaurant restaurant);

int main(){
    Restaurant r;

    r.name = "Aloy Thai";
    r.food_quality = 9;
    r.cleanliness = 8;
    r.wait_time = 3;

    r.overall = getOverallRating(r);

    if (r.overall == -1){
        cout << "Invalid Input" << endl;
    } else {
        cout << "Restrunt: " << r.name << " Overall: " << r.overall << endl;
    }
    return 0;
}

double getOverallRating(Restaurant restaurant){
    double overall;
    if ((restaurant.food_quality < 0) || (restaurant.food_quality > 10)){
        cout << "Here" << endl;
        return -1;
    } else if((restaurant.wait_time < 0) || (restaurant.wait_time) > 5){
        return -1;
    } else if((restaurant.cleanliness < 0) || (restaurant.cleanliness) > 10){
        return -1;
    } else {
        overall = (6.3 * restaurant.food_quality) + (4.3 * restaurant.cleanliness) + 3.4 * (5-restaurant.wait_time);
    }

    return overall; 

}
