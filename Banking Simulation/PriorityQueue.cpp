/* 
 * PriorityQueue.cpp
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


#include <string>  
#include <iostream>  
#include "PriorityQueue.h"  

using namespace std; 

  
// Default Constructor
template <class T>
PriorityQueue<T>::PriorityQueue() {
   head = NULL;
   elementCount = 0;
  
} 

// Copy Constructor
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& rhsPriorityQueue) {
   head = copyLinkedList(rhsPriorityQueue.head);
   elementCount = rhsPriorityQueue.elementCount;
   
}  
// Utility method - Copy a linked list
template <class T>
Node<T>* PriorityQueue<T>::copyLinkedList(const Node<T>* originalHead) {
    Node<T>* copiedHead = NULL;

	if (originalHead != NULL)
	{
		// Build new linked list from given one
		copiedHead = new Node<T>(originalHead->data);
		if ( copiedHead != NULL )
			copiedHead->next = copyLinkedList(originalHead->next);
		else
		   return NULL; 
	}  // end if
   
	return copiedHead;
}  // end copylinked list

// Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue() {
   clear();
   // cout << "PriorityQueue destructor" << endl; // For learning purposes!
}  // end destructor

// Utility method - Destroy the whole linked list - same as dequeueAll()
template <class T>
void PriorityQueue<T>::clear()
{
   while (!isEmpty())
      dequeue();
}  // end clear

// Description: Returns the number of elements in the Priority Queue.
template <class T>
int PriorityQueue<T>::getElementCount() const {
   return elementCount;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::isEmpty() const {
   return ( elementCount == 0 && head == NULL );
}  // end isEmpty


// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.   
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.  
// Time Efficiency: O(n)    
template <class T>     
bool PriorityQueue<T>::enqueue(const T& newElement) {

   // cout << "PriorityQueue::enqueue" << endl;

   bool ableToEnqueue = false;

   Node<T>* newNode = new Node<T>(newElement);

   if ( newNode != NULL ){    	
   	   Node<T>* previous = getNodeBefore(newElement);
        
	   if ( isEmpty() || previous == NULL) { // Add at beginning
	      newNode->next = head;
	      head = newNode;
	   }
	   else {  // Add after node before
      	   Node<T>* afterNode = previous->next;
      	   newNode->next = afterNode;
      	   previous->next = newNode;
       } // end if

	   elementCount++;    // Increment count of elements
	   ableToEnqueue = true; 
   }

   return ableToEnqueue;
} // end enqueue

// Utility method - Locates the node that is before the node that should or does
//                  contain the anElement.
template <class T>
Node<T>* PriorityQueue<T>::getNodeBefore(const T& anElement) const {

   Node<T>* current = head;
   Node<T>* previous = NULL;

   while ( (current != NULL) && (current->data < anElement) )
   {
      previous = current;
      current = current->next;
   } // end while
 
   return previous;
} // end getNodeBefore

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::dequeue() {
   bool ableToDequeue = false;
      
   if ( !isEmpty() ) {
      Node<T>* current = head;

      // Delete the first node in the linked list
      head = head->next;
       
      // Return deleted node to system
      current->next = NULL;
      delete current;
      current = NULL;
      
      elementCount--;  // Decrement count of elements
      ableToDequeue = true;
   }  // end if
   
   return ableToDequeue;
}  // end remove


// Description: Returns (a copy of) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class T>
T PriorityQueue<T>::peek() const throw(EmptyDataCollectionException) {
   
   // Enforce precondition
   if ( !isEmpty() )
   {
      Node<T>* node = head;
      return node->data;
   }
   else
      throw(EmptyDataCollectionException("peek() called with an empty PriorityQueue.")); 

}  // end peek


// For Testing Purposes - See Labs 3 and 4.
// Description: Prints the content of "this". 
template <class T>
void PriorityQueue<T>::printPriorityQueue( ) const {
   Node<T>* current = head;

   // Traverse the list
   while (current != NULL){
      cout << current -> data; // Print data
      current = current -> next; // Go to next Node
   }
      
}  // end printPriorityQueue

// ostream& operator<<(ostream & os, const PriorityQueue& rhs) {
//   	Node* current = rhs.head;
	
// 	// Traverse the list
// 	while (current != NULL){
// 		cout << current -> data; // Print data
// 		current = current -> next; // Go to next Node
// 	}
	
// 	return os;
// } // end of operator <<

//  End of implementation file.