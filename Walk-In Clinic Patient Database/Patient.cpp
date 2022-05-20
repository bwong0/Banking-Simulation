/*
 * Patient.cpp
 * 
 * Class Description: Models a walk-in clinic patient.
 * Class Invariant: Each patient has a unique care card number.
 *                  This care card number must have 10 digits.
 *                  This care card number cannot be modified. 
 *
 * Author: Billy Wong
 * Date: Jan 30 2022
 */

// You can add #include statements if you wish.
#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;

// Default Constructor
// Description: Create a patient with a care card number of "0000000000". 
// Postcondition: All data members set to "To be entered", 
//                except the care card number which is set to "0000000000".       
Patient::Patient(): 
name("To be entered"), address("To be entered"), phone("To be entered"),email("To be entered"),careCard("0000000000") {


}

// Parameterized Constructor
// Description: Create a patient with the given care card number.
// Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard) {
    name = "To be entered";
    address = "To be entered";
    phone = "To be entered";
    email = "To be entered";

    int i=0,flag=0,len=aCareCard.length();
    while (i<len&&flag==0){
        if (isalpha(aCareCard[i])){
          flag=1;
        }
        i++;
    }
    if (len!=10&&flag==0){
        careCard="0000000000";
    }
    else if (len==10&&flag==0){
        careCard=aCareCard;
    }

}

// Parameterized Constructor
// Description: Create a patient with the given name and carecard
// Postcondition: Name set to aName
//               If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
Patient::Patient(string aCareCard, string aName) {
    name = aName;
    address = "To be entered";
    phone = "To be entered";
    email = "To be entered";

    int i=0,flag=0,len=aCareCard.length();
    while (i<len&&flag==0){
        if (isalpha(aCareCard[i])){
          flag=1;
        }
        i++;
    }
    if (len!=10&&flag==0){
        careCard="0000000000";
    }
    else if (len==10&&flag==0){
        careCard=aCareCard;
    }

}

// Parameterized Constructor
// Description: Create a patient with the given name, address and carecard
// Postcondition: Name set to aName
//                Address set to anadress
//                If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
//              
Patient::Patient(string aCareCard, string aName, string anAddress) {
    name = aName;
    address = anAddress;
    phone = "To be entered";
    email = "To be entered";

    int i=0,flag=0,len=aCareCard.length();
    while (i<len&&flag==0){
        if (isalpha(aCareCard[i])){
          flag=1;
        }
        i++;
    }
    if (len!=10&&flag==0){
        careCard="0000000000";
    }
    else if (len==10&&flag==0){
        careCard=aCareCard;
    }

}

// Parameterized Constructor
// Description: Create a patient with the given name, address, carecard and phone
// Postcondition: Name set to aName
//                Address set to anadress
//                Phone set to aPhone
//                If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
//              
Patient::Patient(string aCareCard, string aName, string anAddress, string aPhone) {
    name = aName;
    address = anAddress;
    phone = aPhone;
    email = "To be entered";

    int i=0,flag=0,len=aCareCard.length();
    while (i<len&&flag==0){
        if (isalpha(aCareCard[i])){
          flag=1;
        }
        i++;
    }
    if (len!=10&&flag==0){
        careCard="0000000000";
    }
    else if (len==10&&flag==0){
        careCard=aCareCard;
    }

}

// Parameterized Constructor
// Description: Create a patient with the given name, address, carecard and phone
// Postcondition: Name set to aName
//                Address set to anadress
//                Phone set to aPhone
//                email set to anEmail                
//                If aCareCard does not have 10 digits, then care card is set to "0000000000".
//                All other data members set to "To be entered".
//              
Patient::Patient(string aCareCard, string aName, string anAddress, string aPhone, string anEmail) {
    name = aName;
    address = anAddress;
    phone = aPhone;
    email = anEmail;

    int i=0,flag=0,len=aCareCard.length();
    while (i<len&&flag==0){
        if (isalpha(aCareCard[i])){
          flag=1;
        }
        i++;
    }
    if (len!=10&&flag==0){
        careCard="0000000000";
    }
    else if (len==10&&flag==0){
        careCard=aCareCard;
    }

}
// All other parameterized constructors -> You need to implement these methods.

// Getters and setters -> You need to implement these methods.

// Getters and setters
// Description: Returns patient's name.
string Patient::getName() const{
    return name;
}

// Description: Returns patient's address.
string Patient::getAddress() const{
    return address;
}

// Description: Returns patient's phone.
string Patient::getPhone() const{
    return phone;
}

// Description: Returns patient's email.
string Patient::getEmail() const{
    return email;
}

// Description: Returns patient's care card.
string Patient::getCareCard() const{
    return careCard;
}

// Description: Sets the patient's name.
void Patient::setName(const string aName){
    name = aName;
}

// Description: Sets the patient's address.
void Patient::setAddress(const string anAddress){
    address = anAddress;
}

// Description: Sets the patient's phone.
void Patient::setPhone(const string aPhone){
    phone = aPhone;
}

// Description: Sets the patient's email.
void Patient::setEmail(const string anEmail){
    email = anEmail;
}

void Patient::printPatient(){
  cout<<this->getCareCard()<<", Patient: "<<this->getName()<<", ";
  cout<<this->getAddress()<<", "<<this->getPhone()<<", "<<this->getEmail()<<endl;
}

// Overloaded Operators
// Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if both Patient objects have the same care card number.
bool Patient::operator == (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard == rhs.getCareCard();
	
} // end of operator ==

// Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is > the care card 
//              number of "rhs" Patient object
bool Patient::operator > (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard > rhs.getCareCard();
	
} // end of operator >

// Description: Less than operator. Compares "this" Patient object with "rhs" Patient object.
//              Returns true if the care card number of "this" Patient object is < the care card 
//              number of "rhs" Patient object.
bool Patient::operator < (const Patient & rhs) {
	
	// Compare both Patient objects
	return this->careCard < rhs.getCareCard();
	
} // end of operator <

// For testing purposes!
// Description: Prints the content of "this".
ostream & operator<<(ostream & os, const Patient & p) {
	
	os << p.careCard << " - Patient: " << p.name << ", "
	   << p.address << ", " << p.phone << ", " << p.email << endl;  
	     
	return os;

} // end of operator<<

// end of Patient.cpp