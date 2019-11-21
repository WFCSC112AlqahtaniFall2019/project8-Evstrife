#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include "data.h"

using namespace std;
int main(){
//create objects for container
data other;
stack <data> Stack;
queue <data> Queue;
priority_queue <data> priorityQueue;
//declare fstream variables
ifstream datafile;
ofstream outStack;
ofstream outQueue;
ofstream outPriority;
//
datafile.open ("../Pokemon.csv");
outStack.open("Stack.txt");
outQueue.open("Queue.txt");
outPriority.open("PriorityQueue.txt");

if(!datafile.is_open()){
cout<<"Input file did not open"<<endl;
return 1;
}
if(!outStack.is_open()){
cout<<"Stack output file did not open"<<endl;
return 2;
}
if(!outQueue.is_open()){
cout<<"Queue output file did not open"<<endl;
return 3;
}
if(!outPriority.is_open()){
cout<<"Sorted output file did not open"<<endl;
return 4;
}

cout<<"All files open"<<endl<< "../Pokemon.csv is being read"<<endl;

outQueue<<"Number, Name, HP, Attack, Defence, SpecialAttack, SpecialDefence, Speed"<<endl;
outStack<<"Number, Name, HP, Attack, Defence, SpecialAttack, SpecialDefence, Speed"<<endl;
outPriority<<"This list is sorted by HP"<<endl;
outPriority<<"Number, Name, HP, Attack, Defence, SpecialAttack, SpecialDefence, Speed"<<endl;


while (!datafile.eof()) {
//getline until the the comma
string num, name, hp, att, def, spatt, spdef, speed;
getline(datafile, num, ',');
getline(datafile, name, ',');
getline(datafile, hp, ',');
getline(datafile, att, ',');
getline(datafile, def, ',');
getline(datafile, spatt, ',');
getline(datafile, spdef, ',');
getline(datafile, speed,'\n');


//changes from string to double
double Num = stod (num);
double HP = stod(hp);
double Att = stod(att);
double Def = stod(def);
double Spatt = stod(spatt);
double Spdef = stod(spdef);
double Speed = stod(speed);

data info = data (Num, name, HP, Att, Def, Spatt, Spdef, Speed);
//creates an object to put the data
Stack.push(info);
//push into the stack
Queue.push(info);
//push into the queue
priorityQueue.push(info);
//put data in to the sorted list
other=info;
}

cout<<"Writing data in stack inserted at head into Stack.txt"<<endl;
cout<<"Writing data in queue inserted at tail into Queue.txt"<<endl;
cout<<"Writing data in sorted linked list sorted by attribute into Sorted.txt"<<endl;

//prints then removes the element from stack
    cout << "Writing data in stack into Stack.txt" << endl;
    while (!Stack.empty()){
        outStack << Stack.top() << endl;
        Stack.pop();
    }
    //prints then removes the element from queue
    cout << "Writing data in queue into Queue.txt" << endl;
    while (!Queue.empty()){
        outQueue << Queue.front() << endl;
        Queue.pop();
    }
    //prints then removes the element from the priority queue
    cout << "Writing data in priority queue into Sorted.txt" << endl;
    while (!priorityQueue.empty()){
        outPriority << priorityQueue.top() << endl;
        priorityQueue.pop();
    }
//close file
datafile.close();
outQueue.close();
outPriority.close();
outStack.close();
cout<<"All files closed"<<endl;


return 0;
}