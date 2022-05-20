/*
 * Event.h
 * 
 * Description: Models arrival or departure event.
 * 
 * Class Invariant: Arrival events have type 'A'
 * 					Departure event have type 'D'
 * 
 * Author: Billy Wong
 * Date: March 27 2021
 */

#include <iostream>
#include "Event.h"

using namespace std;


// Constructor
Event::Event() {
	type = ARRIVAL;
	time = 0;
	length = 0;
}

Event::Event(char aType, int aTime) {
	type = aType;
	time = aTime;
	length = 0;
}

Event::Event(char aType, int aTime, int aLength) {
	type = aType;
	time= aTime;
	length = aLength;
}
	
// Getters
char Event::getType() const {
	return type;
}

int Event::getTime() const {
	return time;
}

// Postcondition: The length makes sense only when the type is "A".
int Event::getLength() const {
	return length;
}

	
	
// Description: Return true if this event is an arrival event, false otherwise.
bool Event::isArrival(){
	return type == ARRIVAL;
}

// Overloaded Operators
// Description: Comparison (equality) operator. 
//              Returns true if both Profile objects have the same name.
bool Event::operator<(const Event& rhs) {

	// Compare both Event objects
	if (time == rhs.getTime() )
		if (type == ARRIVAL && rhs.type == DEPARTURE)
			return true;
		else
			return false;
	else
	    if (time < rhs.getTime() )  
			return true;
		else
			return false;

	return false;
} 




ostream& operator<<(ostream & os, const Event& rhs) {
   
   cout << "Type: " << rhs.type;
   cout << " Time: " << rhs.time;
   if ( rhs.type == rhs.ARRIVAL ) cout << " Length: " << rhs.length;
   cout << endl << endl;

   return os;
} 
