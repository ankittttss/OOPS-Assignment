#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Room Class That Includes basic Attributes such as -: Number of Bed, Type of Room, Price of the Room// 

class Room{
    public:
    string roomtype;             
    int noofbed;              
    bool housekeepingfacilty;   
    int price;                  
    bool acavial;               
    bool hotshoweravail;        
    bool roomavail;            
    string status;

  Room(string roomtype,int noofbed,bool housekeepingfacilty,int price,bool acavial,bool hotshoweravail,bool roomavail,string status):
  roomtype(roomtype),noofbed(noofbed),housekeepingfacilty(housekeepingfacilty),price(price),acavial(acavial),hotshoweravail(hotshoweravail),
  roomavail(roomavail),status(status){}

     // Our Getter Functions//

    bool getstatusofavailabilty(){
         return roomavail;
    }

    bool setstatusofavail(bool status){
          roomavail = status;
          return true;
    }

    void setstatus(string& name){
         status = name;
    }

    int getprice(){
        return price;
    }

    void displaystatus(){
       cout<<status<<endl;
    }
};

//----------------------------------------------------------------------------------------------------------------------------------------

// Hotel Class will inlcude the details such as Address and many other Things as a Unique ID, Rating of the Room, and Address//

class Hotel{
    public:
    int id;               // Every Hotel will have a Unique ID//
    string HotelName;     // A hotel will have it's own Name//
    string state;         // Location of the Hotel//
    int stars;            //Hotel on the basis of Stars such as -: 3 star,......so on//
    int customerating;    // We will see the Rating of that Room//
    vector<Room>Totalroom; // Total Room in a Hotel//

    Hotel(int id,string HotelName,string state,int stars,int customerating,vector<Room>Totalroom):id(id),
    HotelName(HotelName),state(state),stars(stars),customerating(customerating),Totalroom(Totalroom){}
};

//---------------------------------------------------------------------------------------------------------------------------------------

class Person{   // Base Class that will include details such as Username and Email//  
    public:
    string username;
    string email;
    string password;


    Person(string username,string email,string password):username(username),email(email),password(password){}
};

class User:public Person{   // User will also inherits the Person Class as there is a (IS -> A ) Relationship//
    public:
    User(string username,string email,string password):Person(username,email,password){}

    // Getter Function//

    string getemail(){
        return email;
    }

    string getusername(){
        return username;
    }
 
};

class HotelAgent:public Person{   // Inherit the Base Class ie Person because there is a (IS->A) Relationship//
    public:
    HotelAgent(string username,string email,string password):Person(username,email,password){}
};

//-------------------------------------------------------------------------------------------------------------------------------------

class Adminstrator{   // A different Class that will handle it's own functions//
   public:
   string name;
   Adminstrator(string name):name(name){}
};

//---------------------------------------------------------------------------------------------------------------------------------------

class UserManagement{     // All of the user related Services will be handled here such. Every Service that will include User is Handled Here// 
    public:

    vector<User>TotalUser;              // A simple Container that will store our all User//
    map<string,string>LoginPurpose;     // Map<Username,Password> We are Using this for Login Purpose//
    

    void registerauserforsite(){              // A simple Method that is handling the register Functionality//   
         cout<<"Enter the username"<<endl;
         string username;
         cin>>username;

         cout<<"Enter the Password"<<endl;
         string password;
         cin>>password;

         cout<<"Enter the Email"<<endl;
         string email;
         cin>>email;

         User u(username,email,password);  // Creating a objet as User has registered and we will be storing it in our Container//
         TotalUser.push_back(u);
         LoginPurpose[username] = password; // Just Map the Username with Password//

         cout<<"User Has Been Created"<<endl;
    }
  

    void updateyourdetails(){
            // We can update our Details//
    }

    void login(){   // Login Method that will help you to Enter the Account//
        cout<<"Enter the username"<<endl;
        string username;
        cin>>username;

        cout<<"Enter the Password"<<endl;
        string password;
        cin>>password;

        if(LoginPurpose[username] == password){
            cout<<"Logged In"<<endl;
        }

        else{
            cout<<"Invalid Credntials"<<endl;
        }
    }


    vector<User>getalluser(){  // Simple Function that will return All Users//
        return TotalUser;
    }  
};

//-----------------------------------------------------------------------------------------------------------------------------------

class HotelAgentManagement{           // Class Will Include Registration and Other Functionality Related to HotelAgent//
    public:
    vector<HotelAgent>TotalHotelAgent;      // It will store how many Hotel Agent We have//
    map<string,string>ForLogin;

    void Register(){                 // A simple Register Function that helps you to register//
         cout<<"Enter the Details"<<endl;
         string username;
         cin>>username;

         cout<<"Enter the Password"<<endl;
         string password;
         cin>>password;

         cout<<"Enter the Email"<<endl;
         string email;
         cin>>email;

         HotelAgent u(username,email,password);   // Making a hotelagent Password//
         TotalHotelAgent.push_back(u);
         ForLogin[username] = password;          // Map the username with password//
    }



    void Login(){                                // Login function that helps you to authenticated//
          cout<<"Enter the username"<<endl;
          string username;
          cin>>username;

          cout<<"Enter the Password"<<endl;
          string password;
          cin>>password;

          if(ForLogin[username] == password){
              cout<<"Authenticated"<<endl;
          }
          else{
              cout<<"Inavlid Credntials"<<endl;
          }
    }

};
//-----------------------------------------------------------------------------------------------------------------------------------------------

class HotelManagement{                 // A simple class that will deal with all of the functions that include hotel and room in it//
     public:
     vector<Hotel>TotalHotel;
     void DeleteHotel(Hotel& hotel,Adminstrator& adminstrator,HotelAgent& hotelagent){
            // We will delete the required// 
            
     } 

     void addHotel(Hotel& hotel,Adminstrator& adminstrator,HotelAgent& a){
         cout<<"approved from admin"<<endl;
         TotalHotel.push_back(hotel);
     }

     void modifyHotel(Hotel& hotel,Adminstrator& adminstrator,HotelAgent& hotelagent){
         // Here We can change any attribute of the Hotel Class//
         // We Can change the Name and other Attributes here//
     }
     

     void bookaroom(User& user){                      // We are booking a room here as A hotel have multiple Room so we will be storing//
                                                   // Room as in Vector in Hotel Object//

         for(int i=0;i<TotalHotel.size();i++){                    // If there is no room availaible then show error//
             vector<Room>TotalRoom = TotalHotel[i].Totalroom;
             if(TotalRoom.size() == 0){
                 cout<<"Roooms arent availaible"<<endl;
             }
             else{
                 for(Room r:TotalRoom){
                     if(r.roomavail == true){
                         r.roomavail = false;
                         cout<<"Room has been reserved"<<endl;     // else reserve and book the room
                         break;
                     }
                 }
             }   
         }

     }

     // User can filter and find the Hotel on the basis of Certain Keyword and Critieria -: Location,Price,Stars,Rating and Many More

     vector<Hotel>showHotelsonthebasisofstars(int amount,User& user){
            vector<Hotel>Resultant;
            for(int i=0;i<TotalHotel.size();i++){
                if(TotalHotel[i].stars >=amount){
                    Resultant.push_back(TotalHotel[i]);
                }
            }
            return Resultant;
     }

     vector<Hotel>showHotelonthebasisofrating(int amount,User& user){
            vector<Hotel>Resultant;
            for(int i=0;i<TotalHotel.size();i++){
                if(TotalHotel[i].customerating >=amount){
                    Resultant.push_back(TotalHotel[i]);
                }
            }
            return Resultant;
     }

     vector<Hotel>showhotelonthebasisofprice(int amount,User& user){
          vector<Hotel>Resultant;
          for(int i=0;i<TotalHotel.size();i++){
              vector<Room>TotalRoom = TotalHotel[i].Totalroom;
              for(Room r:TotalRoom){
                  if(r.price<=amount){
                      Resultant.push_back(TotalHotel[i]);
                  }
              }
          }
          return Resultant;
     }
};


//-------------------------------------------------------------------------------------------------------------------------------------------

int main() {
    HotelAgent hotelagent("ankit","ankit","ankit");
    Room R1("Deluxe",2,true,240,true,true,true,"availaile");
    Room R2("Standard",2,true,240,true,true,true,"availaile");
    Room R3("Simple",2,true,240,true,true,true,"availaile");

    vector<Room>Totalroom;  // Storing Room of a Hotel//

    Totalroom.push_back(R1);
    Totalroom.push_back(R2);
    Totalroom.push_back(R3);

    User i("ankit","ankit","ankit");
    UserManagement u;
    u.registerauserforsite();
    u.login();
    vector<User>vt = u.getalluser();

    Adminstrator a("Ankit");

    Hotel y(2,"Arihant","88 purewal Colony",3,3,Totalroom);

    HotelManagement h;
    h.addHotel(y,a,hotelagent);
    h.bookaroom(i);

    Hotel oi(2,"naxiya","88 purewal Colony",3,3,Totalroom);
    Hotel oo(2,"Arihant","88 purewal Colony",3,3,Totalroom);

    h.addHotel(oi,a,hotelagent);
    h.addHotel(oo,a,hotelagent);

   vector<Hotel>hotelonthebasisofstar = h.showHotelsonthebasisofstars(3,i);

   cout<<"Hotel on the Basis of Star"<<endl;

   for(Hotel h:hotelonthebasisofstar){
       cout<<h.HotelName<<endl;
   }
   cout<<"Hotel on the Basis of Rating"<<endl;

   vector<Hotel>hotelonthebasisofrating = h.showHotelonthebasisofrating(3,i);

   for(Hotel h:hotelonthebasisofrating){
       cout<<h.HotelName<<endl;
   }
   
   cout<<"Hotel on the basis of Price"<<endl;

   vector<Hotel>hotelonthebasisofprice = h.showhotelonthebasisofprice(300,i);

   for(Hotel h:hotelonthebasisofprice){
       cout<<h.HotelName<<endl;
   }

    return 0;
}
