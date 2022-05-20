/*
 * Event.h
 * 
 * Description: Models arrival or departure event.
 * 
 * Class Invariant: Arrival events have type 'A'
 * 					Departure event have type 'D'
 * 
 * Author: Billy Wong
 * Date: march 27 2022
 */

#pragma once
#include <iostream>

using namespace std;

class Event {

private:
	char type;
	int time;
	int length; 
	
public:
	static const char ARRIVAL = 'A';
	static const char DEPARTURE = 'D';
	
	// Constructor
	Event();
	Event(char type, int time);
	Event(char type, int time, int length);
	
    // Getters
    char getType() const;
    int getTime() const;
    int getLength() const;
    
    
	
	// Description: Return true if this event is an arrival event, false otherwise.
	bool isArrival();

	// Overloaded Operators
	// Description: Returns "true" if "this" < "rhs", "false" otherwise.
	bool operator<(const Event& rhs);


	// Description: Prints the content
	// void printEvent( ) const ;
	
	friend ostream& operator<<(ostream & os, const Event& rhs);

}; 
