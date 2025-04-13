#ifndef EVENTS_H
#define EVENTS_H


struct Events{
    string advisors[6] = {"none", "Rafiki", "Nala", "Sarabi", "Zazu", "Sarafina"};
    string description;
    int pathType;
    int advisor; //  Advisor (0 = none; 1 = Rafiki; 2 = Nala; 3 = Sarabi; 4 = Zazu; 5 = Sarafina)
    int PP; // lose or gain depands on the advisor
};

#endif
