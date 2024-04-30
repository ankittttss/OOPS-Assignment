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
   virtual void arrest(Mp p){
      
           if(p.expenses > p.limit){
               cout<<"YES CAN BE ARRESTED"<<endl;
           }
           else{
               cout<<"CAN'T BE ARRESTED"<<endl;
           }
   }
};


class pm:public Commisioner{
    public:
    virtual void arrest(PM p){
          if(p.expenses > p.limit){
              cout<<"CAN BE ARRESTED"<<endl;
          }
          else{
              cout<<"CAN'T BE ARRESTED"<<endl;
          }
    }
};

class minn:public Commisioner{
    public:
    virtual void arrest(Minister p){
        if(p.expenses > p.limit && p.permi == true){
            cout<<"CAN BE ARRESTED"<<endl;
        }
        else{
            cout<<"CAN'T BE ARRESTED"<<endl;      
        }
    }
};


int main() {
    PM p("Panipat",20000,"Ambassador","Motilal","PM",10000000,true);
    Mp h("Panipat",200000000,"Bolero","Neha","MP",234);
    Minister j("Panipat",2456,"Bolero","Neha","MIN",2222222222,true);


    minn l;
    l.arrest(j);
    return 0;
}
