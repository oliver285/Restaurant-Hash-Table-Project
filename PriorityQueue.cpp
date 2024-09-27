#include "PriorityQueue.hpp"
#include <limits.h>

using namespace std;

void swap(ReviewInfo *a, ReviewInfo *b)
{
    ReviewInfo temp = *a;
 *a = *b;
 *b=temp;
}

/*
Constructor for our MinHeap implementation
*/
PriorityQ::PriorityQ(int cap)
{
  
    capacity = cap;
    currentSize=0;
        heapArr = new ReviewInfo[capacity];

}

/*
Destructor
*/
PriorityQ::~PriorityQ()
{
 if (heapArr != nullptr) {
        delete[] heapArr; // Deallocate the dynamically allocated memory
    }
}

/*
Finds the parent of a node, given its index.
*/
int PriorityQ::parent(int index)
{
if (index==0) return -1;

return floor((index-1)/2);
}

/*
Returns the left child of a node.
*/
int PriorityQ::leftChild(int index)
{
return 2*index+1;

}

/*
Returns the right child of a node.
*/
int PriorityQ::rightChild(int index)
{
return 2*index+2;
}

void PriorityQ::peek()
{
    if(isEmpty()){

        cout<<"Queue is empty :("<<endl;
        return;
    }

    cout<<"Restaurant"<<heapArr[0].restaurantName<<endl;
      cout<<"Customer"<<heapArr[0].customer<<endl;
        cout<<"Review"<<heapArr[0].review<<endl;
          cout<<"Time"<<heapArr[0].time<<endl;

}

void PriorityQ::heapify(int index) // max heap based on project statement


{

 int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    // Check if left child exists and if it is larger than the current node
    if (left < currentSize && heapArr[left].time > heapArr[largest].time) {
        largest = left;
    }

    // Check if right child exists and if it is larger than the largest so far
    if (right < currentSize && heapArr[right].time > heapArr[largest].time) {
        largest = right;
    }

    // If largest is not the current node, swap and recursively heapify
    if (largest != index) {
        swap(heapArr[index], heapArr[largest]);
     heapify(largest);
    
    }

 










}

void PriorityQ::insertElement(ReviewInfo restaurant)
{
if(currentSize==capacity){

cout<<"Maximum heap size reached. Cannot insert anymore"<<endl;
return;

}

heapArr[currentSize]=restaurant;

currentSize++;

int in = currentSize-1;
int par = parent(in);
while(in>0&&heapArr[in].time>heapArr[par].time){

  swap(heapArr[in],heapArr[par]);
  in = par;
  par = parent(in);
}
}

/*
Prints the elements in the heap
*/
void PriorityQ::print()
{
    for(int i=0;i<currentSize;i++){
      cout<<"\t"<<"Customer: "<<heapArr[i].customer<<endl;
        cout<<"\t"<<"Review: "<<heapArr[i].review<<endl;
          cout<<"\t"<<"Time: "<<heapArr[i].time<<endl;
          cout<<"\t"<<"====="<<endl;

    }

}

// Method to remove minimum element (or root) from min heap
void PriorityQ::pop()
{
if(isEmpty()){

    cout<<"Queue is empty"<<endl;
}
    currentSize--;
    heapArr[0] = heapArr[currentSize]; // Replace the root with the last element
    heapify(0); // Heapify from the root
    //heapify(currentSize);

    

}
