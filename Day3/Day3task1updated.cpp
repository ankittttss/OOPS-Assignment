#include <iostream>
using namespace std;


class Person{
    public:
    string name;
    string email;

    Person(string name,string email){
        name = name;
        email = email;
    }
};


class User:public Person{   
    public:
    User(string name,string email):Person(name,email){}

    map<string,int>ownermap;  
    map<string,int>dedicated;
    map<string,Brick>dedicatedbrick;

    string getname(){
        return name;
    }

    string email(){
        return email;
    }
}; 

class Admin:public Person{
    public:
    Admin(string name,string email):Person(name,email){}
};

class Country{    
    

    public vector<City>cities;

    public void addWall(City){
         cities.push_back(City);
    }

    public int gettotalcity(){
        return cities.size();
    }
};

class City{
       public vector<vector<Wall>walls;
       public int nofwalls;

       public Wall getwallofcity(int index){
           return Wall[index];
       }

       public Setnoofwalls(int n){
           nofwalls = n;
       }
   
      public getnofowalls(){
          return walls.size();
      }

      public getnoofbricksinitiatedinawall(Wall& w){
            return w.size(); // No of bricks initiated//
      }

      public void initateawall(){
          if(walls.size() == 0){
              vector<Wall>vt;  // To add another Wall
              walls.push_back(vt);
          }
          else{
              int sh = walls.size()-1;
              if(walls[sh].size()>90){ // A we have been given that if the bricks are more than 90 then make a new Wall;
                  vector<Wall>vt;
                  walls.push_back(vt);
              }
              else{
                  cout<<"Can't Initialise the walls as bricks are left"<<endl;
              }

          }
      }


};

class Brick{
   private:
    string caption;
    string ownername;
    string dedicated;
    bool isowned;
    int flag=0;

    public Brick(string caption,string ownername,string dedicated,bool isowned){
          this.caption = caption;
          this.ownername = ownername;
          this.dedicated = dedicated;
          this.isowned = isowned;
    }


    public bool iswonedbyaperson(Brick b){
        return b.isowned;
    }

    public setInvisibilty(){
        if(flag>10){
            isinvisible = true;
        }
        else{
            isinvisible = false;
        }
    }


    void ownerinmap(Country& c,Brick& b){
         string gh = b.ownername;
         c.mp[gh]++;
    }
};

class Wall{
    public vector<Brick>brick(90);

    public void readbrick(Brick b){
       cout<<b.caption<<endl;
       cout<<b.ownername<<endl;
       cout<<dedicated<<endl;
    }

     public int nofowallsinitiated(City& c){
         cout<<c.walls.size()<<endl;
     }
   
};

class UserFunction(){
   public:
   void dedicateabrick(Brick &b,User& u){
        bool flag = false;
            for(auto it:u.mp){
                if(u.it.second == u){
                    flag = true;
                    break;
                }
            }

            if(flag == false){
                u.mp[b.ownername] = b;
            }

   }

   void paintabrick(User& u,Brick& b){
        
   }

   void edithisbrick(User &u, Brick& b){
       
   }

   void readabrick(Brick& b){

   }

   void commentonabrick(){

   }

   
    string findhottestguy(){  // We will find the hottest Guy with the help of map and find the frequency of the user//
         int freq = 0;
         string ans = "";
         for(auto it:mp){
             if(it.second > freq){
                 ans = it.first;
                 freq = it.second;
             }
         }
         return ans;
    }

    string leastdedictaed(){ // It's the complete opposite of what we did in hottest Guy
          
    }
    
};

class AdminFunction{
     public:
     void changethecontentofbrick(Admin a,Brick b){
            // change the content of the brick.
     }
};

int main() {
   
}
