#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class chat{
  public:
  string type;
  string message;
  chat(string type,string message):type(type),message(message){}
  
};

class Status{  // This class defines some attributes about our status whether it's a text based Status or A Videobased Status//
 public:
 string type; // To idenify whether we have a status that is text based or a video based//
 Status(string type):type(type){}

   string getstatustype(){
       return type;
   }
};

class Contact{  // Class defines about our Contacts and their information such as Name,email,phoneNo and address//
  public:
  string name;
  string phoneno;
  string email;
  string address;
  Contact(string name,string phoneno,string email,string address):name(name),phoneno(phoneno),email(email),address(address){}
 
   // This is our getter Function that helps you to return a specific Value//


  string getname(){
      return name;
  }

  string getphoneno(){
      return phoneno;
  } 

  string getemail(){
      return email;
  } 

  string getaddress(){
      return address;
  }

};

class User{  // Simple User class that stores some basic information about the user such as name and Contact//
   public:
   string name;
   Contact c;

   User(string name,Contact c):name(name),c(c){}

   vector<Contact>Allcontact; // To store all of our Contact//
   map<string,vector<Status>>statusbycontact;  // To store how many status a contact has posted so that we can see the status of the user//

   void receiveavideocall(string& name){  // The receiver will receive the video call by this//
       cout<<"Video Call Accepted by"<<" "<<name<<endl;
   }
   
   void receivedatextmessage(string& name){ // A function that showcase that the message has been received by the user//
       cout<<"received a textmessage"<<" "<<"by"<<" "<<name<<endl;
   }

   void sendatextmessage(chat& c,Contact& u){
          cout<<c.message<<endl;
          cout<<"Message delievered by "<<name<<endl;
          receivedatextmessage(u.name);

   }

   void doavideocall(Contact& c){ // A simple Function to initiated a Video Call//
         cout<<"User has Initiated a videocall to "<<" "<<c.name<<endl;
         receiveavideocall(c.name);
   } 

   void addContact(Contact& c){ // To add Contact in our List//
         Allcontact.push_back(c);
         cout<<"Contact Added Successfully"<<endl;
   }

   void deletecontact(Contact& c){ // To delete a contact in our List//
  
   } 

    void poststaus(Status& s){ // Post a status //
        cout<<"Status Posted"<<" "<<"by"<<" "<<c.name<<endl;
        statusbycontact[name].push_back(s);
   }

   void seestatus(Contact& c){ // To see the status of any user//
         if(statusbycontact.find(c.name)==statusbycontact.end()){
             cout<<"No status Availaible"<<endl;
         }
         else{
             vector<Status>statusavail = statusbycontact[c.name];
             cout<<statusavail.size()<<endl;
             cout<<"Seen the status"<<endl;
         }
   }
};

int main() {
    Contact c("Saini","12345678","ankit","ankit");
    User u("Ankit",c);
    Status ss("Video");
    chat y("text","Hey there");
    u.sendatextmessage(y,c);
    u.addContact(c);
    u.doavideocall(c);
    u.poststaus(ss);
    u.seestatus(c);
    return 0;
}
