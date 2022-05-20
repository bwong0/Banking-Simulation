/*
 * List.cpp
 * 
 *Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (For you to fill: Add the other invariant(s) of this List class.)
 *
 * Author: Billy Wong
 * Date CreatedL Jan 30 2022
 */

#include <iostream>
#include <string>
#include "List.h"
#include "Patient.h"

// Default constructor
List::List(): elementCount(0), capacity(List::INITIAL_CAPACITY) {
    cout << "Inializing Patient database" << endl; //for testing delete later


}


// Destructor
	// Description: Destruct a List object, releasing heap-allocated memory.

List::~List() {
    cout << "Deleting list" << endl; // delete later
    delete [] elements;
}


// Description: Returns the total element count currently stored in List.
int  List::getElementCount() const{
    return elementCount;
}


// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.   
bool List::insert(const Patient& newElement){
    bool ableToInsert=elementCount<capacity;
    if (search(newElement)==NULL){
        if (ableToInsert==true&&elementCount!=0){
        int pos,flag=0  ;
        for (pos=elementCount;flag==0;pos--)
        {
            if (elements[pos-1]>newElement){
            elements[pos]=elements[pos-1];
            }
            else{
            flag=1;
            }
        }
        elements[pos+1]=newElement;
        elementCount++;
        }
        else if (ableToInsert==true&&elementCount==0){
        elements[0]=newElement;
        elementCount++;
        }
    }
    else{
        ableToInsert=false;
    }
    return ableToInsert;
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove( const Patient& toBeRemoved ){
  int pos,flag=0;
  for (pos=0,flag=0;flag==0;pos++){
    if (elements[pos]==toBeRemoved){
      flag=1;
    }
  }
  bool ableToRemove=(pos-1<elementCount)&&(flag==1);
  if (ableToRemove){
    for (int index=pos-1;index<elementCount;index++){
      elements[index]=elements[index+1];
    }
    elementCount--;
  }
  return ableToRemove;
}

// Description: Removes all elements from the List.
// Postconditions: List contains no elements and the element count is 0.
void List::removeAll() {

    for (int i = 0; i < elementCount; i++){
        remove(elements[i]);
    }
    elementCount = 0;
    return;
} 

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target){
  int flag=0;
  Patient* result=NULL;
  for (int pos=0;pos<elementCount&&flag!=1;pos++){
    if (elements[pos]==target){
      flag=1;
      result=&elements[pos];
    }
  }
  return result;
}

void swap(Patient *src, Patient *dest){
    Patient temp = *src;
    *src = *dest;
    *dest = temp;
}

void List::sortList(){
    int count = List::getElementCount();
    for (int i = 0 ; i < count ; i++ ){
        for (int j = 1; j < count-i;j++){
            if (elements[j] < elements[j+1]){
                swap(&elements[j],&elements[j+1]);
            }
        }
    }

}
void List::printList(){
    for (int pos=0;pos<elementCount;pos++){
    cout<<elements[pos].getCareCard()<<", Patient: "<<elements[pos].getName()<<", ";
    cout<<elements[pos].getAddress()<<", "<<elements[pos].getPhone()<<", "<<elements[pos].getEmail()<<endl;
  }
}


