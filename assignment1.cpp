#include <iostream>
using namespace std;

class Mp{ 
    public:
  string constituency;
  int expenses;
  string vehicle;
  string driver;
  string designation;
  int limit;

  Mp(string constt,int exp,string veh,string dri,string des,int limitt):constituency(constt),expenses(exp),vehicle(veh),driver(dri),designation(des),limit(limitt){}

  virtual void getconstituency(){
      cout<<constituency<<endl;
  }

  virtual void getdriver(){
       cout<<driver<<endl;
  }

  virtual bool exceedingLimit(){
      return expenses>limit;
  }
};

class PM:public Mp{
  public:
   bool isPermission;
    PM(string constt,int exp,string veh,string dri,string des,int limitt,bool permission):Mp(constt,exp,veh,dri,des,limitt),isPermission(permission){}

  virtual void getconstituency(){
      cout<<constituency<<endl;
  }

  virtual void getdriver(){
       cout<<driver<<endl;
  }

  virtual bool exceedingLimit(){
      return expenses>limit;
  }

};

class Minister:public Mp{
    public:
     bool permi;
     Minister(string constt,int exp,string veh,string driver,string des,int limitt,bool permission):Mp(constt,exp,veh,driver,des,limitt),permi(permission){}

   virtual void getconstituency(){
      cout<<constituency<<endl;
   }

  virtual void getdriver(){
       cout<<driver<<endl;
  }

  virtual bool exceedingLimit(){
      return expenses>limit;
  }

};


class Commisioner{
    public:
   bool arrest(PM p){
       if(p.designation != "PM"){
           if(p.expenses > p.limit){
               return true;
               cout<<"YES CAN BE ARRESTED"<<endl;
           }
           else{
               return false;
               cout<<"CAN'T BE ARRESTED"<<endl;
           }
       }

       else if(p.designation == "MIN"){
           if(p.expenses > p.limit){
               cout<<"YES CAN BE ARRESTED"<<endl;
               return true;
           }
           else{
               cout<<"CAN'T BE ARRESTED"<<endl;
               return false;
           }
       }

       else{
           if(p.expenses > p.limit){
               cout<<"YES CAN BE ARRESTED"<<endl;
               return true;
           }
           else{
               cout<<"NO CAN'T BE ARRESTED"<<endl;
               return false;
           }
       }
   }
};


int main() {
    PM p("Panipat",20000,"Ambassador","Motilal","PM",10000000,true);
    p.getconstituency();
    p.getdriver();
    Commisioner c;
    c.arrest(p);
    return 0;
}
