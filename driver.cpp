#include <iostream>
#include "hash.hpp"
#include "PriorityQueue.hpp"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void displayMenu() // do not modify
{
    cout << "------------------" << endl;
    cout << "1: Build the data structure (execute this option one time)" << endl;
    cout << "2: Add a review" << endl;
    cout << "3: Retrieve most recent review for a restaurant" << endl;
    cout << "4: Pop most recent review for a restaurant" << endl;
    cout << "5: Print reviews for a restaurant" << endl;
    cout << "6: Display number of collisions" << endl;
    cout << "7: Display table results" << endl;
    cout << "8: Exit" << endl;
    cout << "------------------" << endl;
}

int main(int argc, char* argv[])
{
    if (argc <3)
    {
        cout<<"need correct number of arguments"<<endl;
    }
	
    string fname = argv[1];
    int tableSize = stoi(argv[2]);
    int ch = 0;
    string chs;
    HashTable ht(tableSize);
    cout<<tableSize;
    int time;
    string num;
    ReviewInfo rest;
    bool start = false;
    string restaurant;
         node* choice;
    //     cout<<ht.hashFunction("the sink")%56;
    while(ch!=8)
    {
        displayMenu();
        cout << "Enter your choice >>";
        getline(cin, chs);
        ch = stoi(chs);
        cin.clear();
        switch (ch)
        {
            case 1:
			if(start){

                cout<<"data structure has been made"<<endl;
                
            }else{

                ht.setup(fname);
                start = true;
				//}
				
            }
            break;
            case 2:
			{
                 cout << "Enter name of restaurant: ";
            getline(cin, rest.restaurantName);
            cout<<endl;
             cin.clear();
            cout << "Enter your name: ";
            getline(cin, rest.customer);
            cout<<endl;
             cin.clear();
            cout << "Enter review: ";
            getline(cin, rest.review);
            cout<<endl;
             cin.clear();
            cout << "Enter time: ";
               getline(cin,num);
                cout<<endl;
            
            rest.time=stoi(num);
             
            ht.insertItem(rest);
                
                //
				break;
            }
            case 3:
			{
             cout<<"Restaurant name: ";
                    getline(cin,restaurant);
                    cout<<endl;
                      cin.clear();


                choice = ht.searchItem(restaurant);
                if(choice==nullptr){
                    cout<<"No record found"<<endl;
                    
                }else{
              cout<<" Retrieved Result"<<endl;

                    choice->pq.peek();
                }
           
                //
				break;
            }
            case 4:
			{
                 cout<<"Enter restaurant name: ";
                getline(cin,restaurant);
                cout<<endl;
  cin.clear();
                choice = ht.searchItem(restaurant);
                  if(choice==nullptr){
                    cout<<"No record found"<<endl;
                    
                }else{
              cout<<" Retrieved Result"<<endl;

                    choice->pq.pop();
                }
                //
				break;
            }
            case 5:
			{
                cout<<"Restaurant name: ";
                    getline(cin,restaurant);
                    cout<<endl;
                      cin.clear();
                       choice = ht.searchItem(restaurant);
                  if(choice==nullptr){
                    cout<<"No record found"<<endl;
                    
                }else{
              cout<<"Restaurant:  "<<choice->restaurantName<<endl;

                    choice->pq.print();
                }
				//
				break;
			}
            case 6:
            cout<<"Number of collisions: "<<ht.getNumCollision()<<endl;
                //
                break;
            case 7:
            ht.displayTable();
                //
                break;
            case 8:
            
            cout<<"Quitting goodbye"<<endl;
    // HashTable tempHashTable(5);
   
				break;
            default:
                cout << "Enter a valid option." << endl;
                break;
        }
    }
}
