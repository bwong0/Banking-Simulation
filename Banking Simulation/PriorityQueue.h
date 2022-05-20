/* 
 * PriorityQueue.h
 *
 * Description: Link-based implementation of data collection Priority Queue ADT.
 * 
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 * 
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 *
 * Date: June 2016
 *
 */   
#pragma once

//#include <iostream>
#include "Node.h"
#include "EmptyDataCollectionException.h"


template <class T>
class PriorityQueue {

private:
   Node<T>* head;     // Pointer to first node in the chain
   int elementCount;     // Current count of list items
   
   // Utility method - Locates the node that is before the node that should or does
   //                  contain the anElement.
   Node<T>* getNodeBefore(const T& anElement) const;

   // Utility method - Destroy the whole linked list - same as dequeueAll()
   void clear();

   // Utility method - Copy a linked list
   Node<T>* copyLinkedList(const Node<T>* originalHead);

   
public:
   // Default Constructor
   PriorityQueue();
   // Copy Constructor
   PriorityQueue(const PriorityQueue& rhsPriorityQueue);
   // Destructor
   ~PriorityQueue();   

      // Description: Returns the number of elements in the Priority Queue.
   int getElementCount() const;
   
   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
   
   // Description: Inserts newElement in sort order.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is sorted.   
   // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.    
   // Time Efficiency: O(n)        
   bool enqueue(const T& newElement);
      
   // Description: Removes the element with the "highest" priority.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is not empty.
   // Time Efficiency: O(1) 
   bool dequeue();
   
   // Description: Returns (a copy of) the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1) 
   T peek() const throw(EmptyDataCollectionException);  

   // For Testing Purposes - See Labs 3 and 4.
   // Description: Prints the content of "this". 
   void printPriorityQueue( ) const;
   // friend ostream & operator<<(ostream & os, const PriorityQueue& rhs);
   
}; // end PriorityQueue

#include "PriorityQueue.cpp"