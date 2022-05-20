#include <iostream>
#include <sstream>
#include <iomanip>
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"


using namespace std;


void printResult(PriorityQueue<Event>* aPQ, Queue<Event>* aQ) {

    cout << "The Customer Queue\n" << endl; 
    cout << "There are " << aQ->getElementCount() << " elements in the Customer Queue." << endl;
    aQ->printQueue();

    cout << "The Event Priority Queue\n" << endl; 
    cout << "There are " << aPQ->getElementCount() << " elements in the Event Priority Queue." << endl;
    aPQ->printPriorityQueue();

    return;
}

void printStats( int peopleCount, int waitingTime ) {
  float avg = (float)waitingTime/(float)peopleCount;

  cout << "\nFinal Statistics:  \n" << endl;  
  cout << "\tTotal number of people processed:  " << peopleCount << endl;
  cout << "\tAverage amount of time spent waiting: " 
       << setprecision(3) << avg;
  cout << "\n";
}


int main() {
    string aLine = "";
    int time = 0;
    int length = 0;
    bool tellerAvailable = true;
    Event currentEvent;
    Event customer;
    Event newDepartureEvent;
    int currentTime = 0;
    int departureTime = 0;
    int peopleCount = 0;
    int waitingTime = 0;

    
    Queue<Event>* waitQueue = new Queue<Event>();

   
    PriorityQueue<Event>* eventPQueue = new PriorityQueue<Event>();
            
    
    while(getline(cin, aLine)) {   // while (data)
        stringstream ss(aLine);
        ss >> time >> length;      // Get next arrival time and transaction time 
        Event newArrivalEvent(Event::ARRIVAL, time, length);
        eventPQueue->enqueue(newArrivalEvent);
    }

   

    cout << "Simulation Begins" << endl;

    // Event L
    while ( !eventPQueue->isEmpty() ) {
      try {
            // current event
            currentEvent = eventPQueue->peek();
      }
      catch ( EmptyDataCollectionException& anException ) {
            cout << "main:eventPQueue->peek(): " << anException.what() << endl;
      }
 
        
        currentTime = currentEvent.getTime();

    
        if ( currentEvent.isArrival() ) {        
           cout << "Processing an arrival event at time:";
           cout.width(5); cout << right << currentTime << endl;
           peopleCount++;

         
          if ( eventPQueue->dequeue() ) {
           
            if ( waitQueue->isEmpty() && tellerAvailable ) {
              
              departureTime = currentTime + currentEvent.getLength();
              newDepartureEvent = Event(Event::DEPARTURE, departureTime);
              eventPQueue->enqueue(newDepartureEvent);
              tellerAvailable = false;
            }
            else
              
              waitQueue->enqueue(currentEvent);
          }
        }
        else {  
           
            cout << "Processing a departure event at time:";
            cout.width(4); cout << right << currentTime << endl;

           
            if ( eventPQueue->dequeue() ) {
                if ( !waitQueue->isEmpty() ) {   
                   
                    try { 
                        customer = waitQueue->peek();
                    }
                        catch ( EmptyDataCollectionException& anException ) {
                        cout << "main:eventListPQueue->peek(): " << anException.what() << endl;
                    }
                if ( waitQueue->dequeue() ) {
                    
                    departureTime = currentTime + customer.getLength();
                    newDepartureEvent = Event(Event::DEPARTURE, departureTime);
                    eventPQueue->enqueue(newDepartureEvent);
                    waitingTime += ( currentTime - customer.getTime() );
                }
            }
            else
                tellerAvailable = true;
            } 
        }
    
    

    }

    cout << "Simulation Ends" << endl;
    printStats( peopleCount, waitingTime );


    delete waitQueue;
    waitQueue = NULL;

    delete eventPQueue;
    eventPQueue = NULL; 

   
	return 0;
}