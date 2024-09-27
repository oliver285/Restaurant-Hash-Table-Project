// CPP program to implement hashing with chaining
#include <iostream>
#include "hash.hpp"
#include <sstream>
#include <cstring>
using namespace std;

node* HashTable::createNode(string restaurantName, node* next)
{
  node* newnode = new node{restaurantName,PriorityQ(50),next};


 // Assigning a pointer to a new PriorityQ object
    return newnode;

}

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
numCollision=0;
table = new node*[tableSize];
for (int i=0;i<tableSize;i++){

    table[i] = nullptr;
}
}

HashTable::~HashTable()
{
for(int i=0;i<tableSize;i++){
node* current = table[i];
while(current){

node* t = current;
current=current->next;
delete t;


}



}
delete []table;
table = nullptr;
}

void HashTable::displayTable()
{
for(int i=0;i<tableSize;i++){
node* current = table[i];
cout<<i<<"|";
while(current){

cout<<current->restaurantName<<"-->";
current=current->next;


}
cout<<"NULL"<<endl;


}
}

unsigned int HashTable::hashFunction(string restaurantName)
{
 //const char* conv = restaurantName.c_str();
int length = restaurantName.length(); 
unsigned int sum = 0;
for(int i=0;i<length;i++){

sum += int(restaurantName[i]);


}

return sum%tableSize;

}

node* HashTable::searchItem(string restaurantName)
{
   unsigned int val = hashFunction(restaurantName);
    node* section = table[val];
    while(section){

if(section->restaurantName==restaurantName){
    return section;
}
section=section->next;

    }

    return nullptr;

}

void HashTable::insertItem(ReviewInfo restaurant)
{
node* start = searchItem(restaurant.restaurantName);
if(start!=nullptr){
start->pq.insertElement(restaurant);

    }

else{

node* Newnode = createNode(restaurant.restaurantName,nullptr);
Newnode->pq.insertElement(restaurant);
unsigned int val = hashFunction(restaurant.restaurantName);

if(table[val]==nullptr){

table[val]= Newnode;


}else{
      numCollision++;
Newnode->next = table[val];
table[val]=Newnode;

}

}
}


void HashTable::setup(string fname)
{
ifstream file(fname);
    if (!file.is_open()) {
        cout << "Error opening file: " << fname << endl;
        return;
    }

    string line;
    while(getline(file,line)){


stringstream ss(line);

      ReviewInfo Rest;
  getline(ss, Rest.restaurantName, ';');
        getline(ss, Rest.review, ';');
         getline(ss, Rest.customer, ';');
        ss >> Rest.time;

        insertItem(Rest);




    }

    file.close();
}