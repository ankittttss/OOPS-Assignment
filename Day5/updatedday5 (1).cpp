#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Media{  // We can send different types of Media in a chat Box that can in form of Video, Image and Location
    public:
    Media(){}
};

class Photo:public Media{  
  public:
  int size;  // size of the photo
  string format; // format of the photo -: jpg,png
  string comment; // We can add a comment on a photo before sending it
  Photo(int size,string format,string comment):Media(),size(size),format(format),comment(comment){}
};

class Video:public Media{  // We can send the Media in the form of Video Also//
    public:
    int size;             // The size of the Video//
    int format;           // The format such as -: mkv,mp4// 
    string comment;       // We can add some additional information // 
    Video(int size,int format,string comment):Media(),size(size),format(format),comment(comment){}
};

class Location:public Media{ // We can send our Live Location to the people// 
    public:
    string latitude;     // These are the coordinates of our location//
    string longitude;
    Location(string latitude,string longitude):Media(),latitude(latitude),longitude(longitude){}
};



class Contact{  // Class define about our Contacts and their information such as Name,email,phoneNo and address//
  public:
  string name;  // Name of our Contact//
  string phoneno; // Phone Number//
  string email;  // Email //
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
   string password;
   int id;

   User(string name,Contact c,string password,int id):name(name),c(c),password(password),id(id){}

};

class Status{  // This class define some attributes about our status whether it's a text based Status or A Videobased Status//
 public:
 string type; // To idenify whether we have a status that is text based or a video based//
 string message;
 int id;
 Status(string type,string message,int id):type(type),message(message),id(id){}

   string getstatustype(){
       return type;
   }

   int getid(){
       return id;
   }
};


class chat{
  public:
  string type;
  string message;
  time_t recent;
  bool sendstatus;
  chat(string type,string message,time_t recent,bool sendstatus):type(type),message(message),recent(recent),sendstatus(sendstatus){}

  
};

class chatManager{
    public:
   
    map<string,vector<chat>>chatstored;
    void receiveavideocall(string& name){  // The receiver will receive the video call by this//
       cout<<"Video Call Accepted by"<<" "<<name<<endl;
   }
   
   void receivedatextmessage(string& name){ // A function that showcase that the message has been received by the user//
       cout<<"received a textmessage"<<" "<<"by"<<" "<<name<<endl;
   }

   void sendatextmessage(chat& chat,User& user,Contact& contact){
          cout<<chat.message<<endl;
          cout<<"Message delievered by "<<user.name<<" "<<"to"<<" "<<contact.name<<endl;
          chatstored[contact.name].push_back(chat);
          receivedatextmessage(user.name);

   }

   void doavideocall(User& user,Contact& contact){ // A simple Function to initiated a Video Call//
         cout<<user.name<<" "<<"has Initiated a videocall to "<<" "<<contact.name<<endl;
         receiveavideocall(contact.name);
   } 

   void deleteallchat(){

   }

   void sendatextmessagewithattachment(chat& chat,Photo& p,Contact& c){
      
   }

   void sendatextmessagewithattachment(chat& chat,Video& p,Contact& c){

   }

   void sendalocation(chat& chat,Location& l,Contact& c){
       
   }

};

class UserManager{
    public:

       map<string,string>UserDetails; 
       vector<Contact>AllContacts;


     void createnewuser(){  // We are Creating a new User//
          cout<<"Enter the username"<<endl;

          string username;
          cin>>username;

          cout<<"Enter the Password"<<endl;

          string password;
          cin>>password;

          UserDetails[username] = password;
          cout<<"User Created SuccessFully"<<endl;
     }

     void login(){ // User Will Login then it will access//
         cout<<"Enter the username"<<endl;
         string username;
         cin>>username;

         cout<<"Enter the Password"<<endl;
         string password;
         cin>>password;

         if(UserDetails.find(username)==UserDetails.end()){
             cout<<"User Do not Exist"<<endl;
         }
         else if(UserDetails[username]==password){
             cout<<"Authenticated"<<endl;
         }
         else{
             cout<<"Inavlid Credentials"<<endl;
         }
     }

     void addContact(Contact& c,User& u){ // To add Contact in our List//
         AllContacts.push_back(c);
         cout<<"Contact Added Successfully"<<endl;
   }

   void deletecontact(Contact& c){ // To delete a contact in our List//
  
   } 

   void updateContact(){
          
   }

   vector<Contact>getallContact(){
       return AllContacts;
   }

};

class StatusManager{
    public:
    map<string,vector<Status>>Totalstatusbyuser;
    void postststatus(Status& s,User& u){ // Post a status //
        cout<<"Status Posted"<<" "<<"by"<<" "<<u.name<<endl;
        Totalstatusbyuser[u.name].push_back(s);
   }

   void seestatus(User& u,Status& s){ // To see the status of any user//
         if(Totalstatusbyuser.find(u.name)==Totalstatusbyuser.end()){
             cout<<"No status Availaible"<<endl;
         }
         else{
             vector<Status>statusavail = Totalstatusbyuser[u.name];
             cout<<"Watched the status"<<endl;
         }
   }

   void deletestatus(User& u,Status& s){
        
   }

};



int main() {
    Contact c("Saini","12345678","ankit","ankit");
    Contact f("Ankit","12345678","Ankit","Saini");
    User u("Ankit",c,"a",5);
    Status ss("Video","Hi There",2);
    chat y("text","Hey there",time(0),false);

    StatusManager sm;
    UserManager um;
    chatManager cm;

    cm.sendatextmessage(y,u,c);
    cm.doavideocall(u,c);
    um.addContact(c,u);
    um.addContact(f,u);
    sm.postststatus(ss,u);

    um.createnewuser();
    um.login();

    vector<Contact>AllContact = um.getallContact();

    for(int i=0;i<AllContact.size();i++){
          cout<<AllContact[i].name<<endl;
    }

    return 0;
}
