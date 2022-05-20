/*
 * walkIn.cpp
 * 

 *
 * Author: Billy Wong
 * Date: Jan 30 2022
 */

#include <iostream>
#include <string>
#include "Patient.h"
#include "List.h"

using namespace std;

void newPatient( List* thePatients){
  char inputModify=0;
  int flag=0;
  cout<<"Please enter the what information you have:"<<endl; 
  cout<<"Carecard only                                enter: 1"<<endl;
  cout<<"Carecard and Name Only                       enter: 2"<<endl;
  cout<<"Carecard, Name and Address Only              enter: 3"<<endl;
  cout<<"Carecard, Name, Address and Phone            enter: 4"<<endl;
  cout<<"Carecard, Name, Address, Phone and Email     enter: 5"<<endl;
  cin>>inputModify;
    inputModify=tolower(inputModify);
    if (inputModify=='1'||'2'||'3'||'4'||'5'){
      flag=1;
    }
    else{
      cout<<"Not a valid input, please try again."<<endl;
    }

    //Paramterized constructor #1 with carecard only
    if (inputModify=='1'){
      string cc="";
      unsigned int flag=0, i=0;
      cout << "Please enter the careCard number: "<<endl;
      cin>>cc;
      while (i<cc.length()){
        if (isalpha(cc[i])){
          flag=1;
        }
        i++;
      }
      if (flag==0){
        if (cc.length()!=10){
          cout<<"CareCard did not have 10 digits."<<endl;
          cc="0000000000";
        }
        Patient thePatient(cc);
        if (thePatients->insert(thePatient)){
          cout <<thePatient.getCareCard()<<" has successfully been entered into the system"<<endl;
        }
        else{
          cout<<cc<<" is unable to be entered into the system."<<endl;
        }
      }
      else{
        cout<<cc<<" is unable to be entered into the system. Incorrect CareCard format"<<endl;
      }
    }

    // Parameterized Constructor 2 with carecard and name
    else if (inputModify=='2'){
      string cc="";
      string name ="";
      unsigned int flag=0, i=0;
      cout << "Please enter the careCard number: "<<endl;
      cin>>cc;
      while (i<cc.length()){
        if (isalpha(cc[i])){
          flag=1;
        }
        i++;
      }
      cout << "Please enter the patient name: "<<endl;
      getline(cin >> ws, name);
      if (flag==0){
        if (cc.length()!=10){
          cout<<"CareCard did not have 10 digits."<<endl;
          cc="0000000000";
        }


        Patient thePatient(cc,name);
        if (thePatients->insert(thePatient)){
          cout <<thePatient.getCareCard()<<" has successfully been entered into the system"<<endl;
        }
        else{
          cout<<cc<<" is unable to be entered into the system."<<endl;
        }
      }
      else{
        cout<<cc<<" is unable to be entered into the system. Incorrect CareCard format"<<endl;
      }
    }

    //paramaterized constructor 3 with carecard name and address
    else if (inputModify=='3'){
      string cc="";
      string name ="";
      string address = "";
      unsigned int flag=0, i=0;
      cout << "Please enter the careCard number: "<<endl;
      cin>>cc;
      while (i<cc.length()){
        if (isalpha(cc[i])){
          flag=1;
        }
        i++;
      }
      cout << "Please enter the patient name: "<<endl;
      getline(cin >> ws, name);
      cout << "Please enter the patient address: "<<endl;
      getline(cin >> ws,address);
      if (flag==0){
        if (cc.length()!=10){
          cout<<"CareCard did not have 10 digits."<<endl;
          cc="0000000000";
        }


        Patient thePatient(cc,name,address);
        if (thePatients->insert(thePatient)){
          cout <<thePatient.getCareCard()<<" has successfully been entered into the system"<<endl;
        }
        else{
          cout<<cc<<" is unable to be entered into the system."<<endl;
        }
      }
      else{
        cout<<cc<<" is unable to be entered into the system. Incorrect CareCard format"<<endl;
      }
    }

    //paramaterized constructor 4 carecard, name, address, phone
    else if (inputModify=='4'){
      string cc="";
      string name ="";
      string address = "";
      string phone = "";
      unsigned int flag=0, i=0,p=0,phlag=0;
      cout << "Please enter the careCard number: "<<endl;
      cin>>cc;
      while (i<cc.length()){
        if (isalpha(cc[i])){
          flag=1;
        }
        i++;
      }


      cout << "Please enter the patient name: "<<endl;
      getline(cin >> ws, name);
      cout << "Please enter the patient address: "<<endl;
      getline(cin >> ws,address);
      cout << "Please enter the patient phone number xxx-xxx-xxxx: "<<endl;
      getline(cin >> ws,phone);
      if (phone.length()!=12){
        phlag =1;
      }
      while (p<phone.length()){
        if (isalpha(phone[p])){
          phlag =1;
        }
        p++;
      }

      if (flag==0){
        if (cc.length()!=10){
          cout<<"CareCard did not have 10 digits."<<endl;
          cc="0000000000";
        
      
        }

        if (phlag==1){
          
          cout<<"Phone did not have proper format. Please modify phone in this patient's profile"<<endl;
          phone="To be entered";
        
        }

        Patient thePatient(cc,name,address,phone);
        if (thePatients->insert(thePatient)){
          cout <<thePatient.getCareCard()<<" has successfully been entered into the system"<<endl;
        }
        else{
          cout<<cc<<" is unable to be entered into the system."<<endl;
        }
      }
      else{
        cout<<cc<<" is unable to be entered into the system. Incorrect CareCard format"<<endl;
      }
    }
    
    // paramaterized construtor 5 all fields
    else if (inputModify=='5'){
      string cc="";
      string name ="";
      string address = "";
      string phone = "";
      string email = "";
      unsigned int flag=0, i=0,phlag=0, p=0, eflag=0;
      cout << "Please enter the careCard number: "<<endl;
      cin>>cc;
      while (i<cc.length()){
        if (isalpha(cc[i])){
          flag=1;
        }
        i++;
      }
      cout << "Please enter the patient name: "<<endl;
      getline(cin >> ws, name);
      cout << "Please enter the patient address: "<<endl;
      getline(cin >> ws,address);
      cout << "Please enter the patient phone number xxx-xxx-xxxx: "<<endl;
      getline(cin >> ws,phone);
      cout << "Please enter the patient email: "<<endl;
      getline(cin >> ws,email);

      if (phone.length()!=12 ){
        phlag =1;
      }
      while (p<phone.length()){
        if (isalpha(phone[p])){
          phlag =1;
        }
        p++;
      }

      if(email != "*@*"){
        eflag =1;
      }

      if (flag==0){
        if (cc.length()!=10){
          cout<<"CareCard did not have 10 digits."<<endl;
          cc="0000000000";
        
      
        }

        if (phlag==1){
          
          cout<<"Phone did not have proper format. Please modify phone in this patient's profile"<<endl;
          phone="To be entered";
        
        }

        if (eflag==1){
          
          cout<<"Email did not have proper format. Please modify email in this patient's profile"<<endl;
          email="To be entered";
        
        }



        Patient thePatient(cc,name,address,phone,email);
        if (thePatients->insert(thePatient)){
          cout <<thePatient.getCareCard()<<" has successfully been entered into the system"<<endl;
        }
        else{
          cout<<cc<<" is unable to be entered into the system."<<endl;
        }
      }
      else{
        cout<<cc<<" is unable to be entered into the system. Incorrect CareCare Format"<<endl;
      }
    }

  

  return;
}



void removePatient( List* thePatients){
  string cc="";
  if (thePatients->getElementCount()!=0){
  thePatients->printList();
    cout<<"Please enter the careCard number that is being removed"<<endl;
    cin>>cc;
    Patient thePatient(cc);
    if (thePatients->remove(thePatient)){
      cout<<cc<<" has been removed from the system."<<endl;
    }
    else{
      cout<<cc<<" is unable to be removed from the system."<<endl;
    }
  }
  else{
    cout<<"There are no no patients in the system yet."<<endl;
  }
  return;
}

void modifyPatient(List* thePatients){
  char inputModify=0;
  string cc="";
  int flag=0;
  thePatients->printList();
  cout<<"Please enter the carecard that you want to modify:"<<endl;
  cin>>cc;
  Patient thePatient(cc);
  if (thePatients->search(thePatient)!=NULL){
    cout<<"To edit name      enter: n"<<endl;
    cout<<"To edit address   enter: a"<<endl;
    cout<<"To edit phone     enter: p"<<endl;
    cout<<"To edit email     enter: e"<<endl;
    cin>>inputModify;
    inputModify=tolower(inputModify);
    if (inputModify=='n'||'p'||'a'||'e'){
      flag=1;
    }
    else{
      cout<<"Not a valid input, please try again."<<endl;
    }
    if (inputModify=='n'){
      string name="";
      cout<<"Please enter the new name:"<<endl;
      getline(cin >> ws,name);
      thePatient.setName(name);
      cout<<"Name: "<<thePatient.getName()<<" has been set. Patient's new information is:"<<endl;
      thePatient.printPatient();
    }
    else if (inputModify=='a'){
      string address="";
      cout<<"Please enter the new address:"<<endl;
      getline(cin >> ws,address);
      thePatient.setAddress(address);
      cout<<"Address: "<<thePatient.getAddress()<<" has been set. Patient's new information is:"<<endl;
      thePatient.printPatient();
    }
    else if (inputModify=='p'){
      string phone="";
      unsigned int phlag =0, p =0;
      cout<<"Please enter the new phone: xxx-xxx-xxxx"<<endl;
      getline(cin >> ws,phone);
      if (phone.length()!=12 ){
        phlag =1;
      }
      while (p<phone.length()){
        if (isalpha(phone[p])){
          phlag =1;
        }
        p++;
      }
      if (phlag ==0){
      thePatient.setPhone(phone);
      cout<<"Phone: "<<thePatient.getPhone()<<" has been set. Patient's new information is:"<<endl;
      }

      else if (phlag == 1){
        thePatient.setPhone("To be entered");
        cout<<"Phone did not have proper format. Please modify phone in this patient's profile"<<endl;
      }
        
      thePatient.printPatient();
      phlag =0;
    }

    else if (inputModify=='e'){
      string email="";
      int eflag =0;
      cout<<"Please enter the new email:"<<endl;
      getline(cin >> ws,email);

      if(email != "*@*"){
        eflag =1;
      }

      if (eflag == 0){
        thePatient.setEmail(email);
        cout<<"Email: "<<thePatient.getEmail()<<" has been set. Patient's new information is:"<<endl;
      }
      else if (eflag==1){
        thePatient.setEmail("To be entered");
        cout<<"Email did not have proper format. Please modify email in this patient's profile"<<endl;
      }
      thePatient.printPatient();


    }
  }
  return;
}

void searchPatient(List* thePatients){
  string cc="";
  thePatients->printList();
  cout<<"Please enter the careCard that you are searching for:"<<endl;
  cin>>cc;
  Patient thePatient(cc);
  if (thePatients->search(thePatient)!=NULL){
    cout<<cc<<" is in the system."<<endl;
  }
  return;
}
int main(){

  List* patients = new List();
  bool done = false;
  char input = 0;

// Keep doing what the user selects until the user exits
  while (not done) {
    // Print menu to user 
    cout << "\n----Walk In Clinic Patient Database\n" << endl;
    cout << "Enter a new patient into the system\t\t  enter: n" << endl;
    cout << "Remove a patient from the system\t\t  enter: r" << endl;
    cout << "To search for an existing patient\t\t  enter: s" << endl;
    cout << "To modify a patients profile\t\t\t  enter: m" << endl;
    cout << "print all patients\t\t\t\t  enter: p" << endl;
    cout << "To exit database\t\t\t\t  enter: x\n" << endl;

    cout << "Your choice: ";
    cin >> input;
    input = tolower(input);
    switch(input) {
      case 'n': newPatient(patients); break;
      case 'r': removePatient(patients); break;
      case 'm': modifyPatient(patients); break;
      case 's': searchPatient(patients); break;
      case 'p': patients->printList(); break;
      case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
      default: cout << "Not sure what you mean! Please, try again!" << endl;
    }
  }
  // Clean up code:
  // Note to self: The new operator should always be matched with the delete operator! :)
  
  return 0;
}