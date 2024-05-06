#include <iostream>
using namespace std;

class Person{  // Base Class
   public:
   string name;
   int age;

   Person(string name,int age):name(name),age(age){}

   string getPersonName(){
        return name;
   }

   int getage(){
       return age;
   }
};

class Driver:public Person{    // We have used Inheritance over here as Driver is also a Person Here//
    
    public:
    Driver(string name,int age):Person(name,age){};
};

class Mp:Person{  // Because Mp is also a Person//
    public:
    string constituency;
    string DriverAssigned;
    int spendlimit;
    int expenses;

    Mp(string name,int age,string DriverAssigned,int spendlimit,int expenses):
    Person(name,age),constituency(constituency),DriverAssigned(DriverAssigned),spendlimit(spendlimit),expenses(expenses){}

    string getdrivername(){
         return DriverAssigned;
    }

    string getConstituency(){
        return constituency;
    }

    bool exceedspendinglimit(){
        return expenses>spendlimit;
    }


};

class Minister:public Mp{  
    public:
    Minister(string name,int age,string DriverAssigned,int spendlimit,int expenses):
    Mp(name,age,DriverAssigned,spendlimit,expenses){}
};


class PrimeMinister:public Minister{
    public:
    bool haveairplane=true;
    bool havePermission;
   
    PrimeMinister(string name,int age,string DriverAssigned,int spendlimit,int expenses,bool havePermission)
    :Minister(name,age,DriverAssigned,spendlimit,expenses),havePermission(havePermission){}
};

class Commisioner:public Person{
    public:
    Commisioner(string name,int age):Person(name,age){}

    void CanArrest(Mp& p){
          if(p.expenses > p.spendlimit){
              cout<<"Can Be Arrested"<<endl;
          }

          else{
              cout<<"Can't Be Arrested"<<endl;
          }
    }

    void CanArrest(PrimeMinister& p){
        cout<<"Pm Can't Be Arrested"<<endl;
    }

    void CanArrest(Minister& m,PrimeMinister& p){
        if(m.expenses > m.spendlimit){
            if(p.havePermission == true){
                cout<<"Can Be arrested"<<endl;
            }
            else{
                cout<<"Can't be Arrested"<<endl;
            }
        }
        else{
            cout<<"Can't Be Arrested"<<endl;
        }
    }
};

int main() {
    Driver p("Ankit",20);
    string name = p.getPersonName();
    int age = p.getage();

    PrimeMinister pp("Narendar Modi",50,"MohanLal",10000,200,true);

    string drivername = pp.getdrivername();
    cout<<drivername<<endl;

    Commisioner c("Ankit",20);
    cout<<"Prime Minister"<<" "<<endl;
    c.CanArrest(pp);

    Minister M("NarendarModi",60,"Pankhu",10000,200000);
    cout<<"Minister"<<" "<<endl;
    c.CanArrest(M,pp);



    return 0;
}
