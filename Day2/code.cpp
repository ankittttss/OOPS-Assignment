#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Ticket{
    public:
    int ticketid;
    string issuedate;
    string expiringdate;

    Ticket(int ticketid,string issuedate,string expiringdate):ticketid(ticketid),issuedate(issuedate),expiringdate(expiringdate){}


};


class Person{
    public:
    string name;
    Address ad;
    int phone;

    Person(string name,int phone):name(name),phone(phone){}
};

class Customer:class Person{
    public:
    Customer(string name,int phone):Person(name,phone){}
};

class Admin:public Person{
    public:
    Admin(string name,int phone):Person(name,phone){}
};


class Parkingattendant:public Person{
    public:
    Parkingattendant(string name,int phone):Person(name,phone){}
};


class Vehicle{
     public:
     string company;
     int licenseno;

     Vehicle(string company,int licenseno):company(company),licenseno(licenseno){}
};

class Car:public Vehicle{
    public:
    string type;
    Car(string company,int licenseno,string type):Vehicle(company,licenseno),type(type){}
};

class Truck:public Vehicle{
    public:
    string type;
    Truck(string company,int licenseno,string type):Vehicle(company,licenseno),type(type){}
};

class Electric:public Vehicle{
    public:
    string type;
    Electric(string company,int licenseno,string type):Vehicle(company,licenseno),type(type){}
};

class Motor:public Vehicle{
    public:
    string type;
    Motor(string company,int licenseno,string type):Vehicle(company,licenseno),type(type){}
};



class spot{
    public:
    bool free;
    string type;
    Vehicle v;

    spot(bool free,string type):type(type){}

    bool assignavehicle(){
         return true;
    }

    bool removeavehicle(){
         return false;
    }

};

class DisplayBoard{
    public:
    
    // set<pair<Parkingfloor,pair<string,vector<int>>>>st;

    void floordetails(){
        
    }
};


class Parkingfloor{
    public:
    DisplayBoard d;
    int floorid;
    int handicapped;
    int large;
    int compact;
    int motor;

    Parkingfloor(int floorid,int handicapped,int large,int compact,int motor):
    floorid(floorid),handicapped(handicapped),large(large),compact(compact),motor(motor){}

    void gh(){
        d.floordetails();
    }


    
};


class EntrancePanel{
       public:

       void getticket(){
          
       }  
};

class ExitPanel{
      public:
};




class ParkingLot{
    public:
    set<pair<Parkingfloor,pair<string,vector<int>>>>mp;
    vector<EntrancePanel>entry;
    vector<ExitPanel>exit;
    vector<Parkingfloor>vt;

    // Have all the details//
    
};



class System{
    public:
     vector<Parkingfloor>gh;
     map<Parkingfloor,vector<spot>>mp;



     void addfloor(Account a,Parkingfloor f){
           if(a.isadmin == true){
              cout<<"Yes the floor has been added"<<endl;
           }
           else{
               cout<<"The user is not admin"<<endl;
           }
     }

     void removefloor(Parkingfloor f){
            
     }

     void addspot(Account a,spot h){
           
     }

     void removespot(){
        
     }
};

class UsermanagementSystem{
     public:
      System s;

     void adduser(A){
         s.adduser()
     }
};


int main() {
    Address d("88","panipat","Panipat",132103);
    Person p("Ankit",d,798891);
    Account g("Ankit","ankit",true,false);
    System s;
    s.adduser(g);
    Parkingfloor f(1,4,3,3,3);
    s.addfloor(g,f);
    f.gh();
    
}
