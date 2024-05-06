#include <iostream>
using namespace std;

class Inverter{  // Base Class//
    public:
    string type; // Type of inverter whether it's Solar or Non Solar//
    int current;
    int operatingVoltage;

    Inverter(string type,int current,int operatingVoltage):
    type(type),current(current),operatingVoltage(operatingVoltage){}

    int powerating(){ // To calculate the power rating //
        return current*operatingVoltage;
    }

};

class Battery{   // Inverter has a Battery// 
   public:
   string companyname;  // Attributes//
   int capacity;

   Battery(string companyname,int capacity):companyname(companyname),capacity(capacity){}
};

class SolarPanel{  // Solar Inverter have Solar Panel also//
    public:
    string companyname;
    int size;

    SolarPanel(string companyname,int size):companyname(companyname),size(size){}
};

class Solar:public Inverter{
    public:
    bool havesolarpanels = true;
    bool havebattery;
    bool isgridon;
    Solar(string type,int current,int operatingVoltage,bool isgridon,bool havebattery):
    Inverter(type,current,operatingVoltage),havebattery(havebattery),isgridon(isgridon){}

    bool checkwhetherbatteryavail(){
         if(havebattery == true){
             cout<<"Yes the Inverter Have Battery"<<endl;
             return true;
         }
         else{
             cout<<"No the Inverter did not Have a Battery"<<endl;
             return false;
         }
    }

    void gridonavail(){
         if(isgridon == true){
             cout<<"Yes The Grid on is Availaible"<<endl;
         }
         else{
             cout<<"No the Grid on is Not Availaible"<<endl;
         }
    }

};

class PCU:public Solar{  // PCU,GTI,Regalia are Solar Inverter//
    PCU(string type,int current,int operatingVoltage,bool isgridon,bool havebattery):
    Solar(type,current,operatingVoltage,isgridon,havebattery){}

};

class GTI:public Solar{
    GTI(string type,int current,int operatingVoltage,bool isgridon,bool havebattery):
    Solar(type,current,operatingVoltage,isgridon,havebattery){}
};

class Regalia:public Solar{
    Regalia(string type,int current,int operatingVoltage,bool isgridon,bool havebattery):
    Solar(type,current,operatingVoltage,isgridon,havebattery){}
};


class NonSolar:public Inverter{
     public:
     bool havebattery = true;
     NonSolar(string type,int current,int operatingVoltage):Inverter(type,current,operatingVoltage){}

     bool isgridavail(){
         return havebattery;
     }
};

class Zelio:public NonSolar{
   public:
   bool havebattery = true;
   Zelio(string type,int current,int operatingVoltage):NonSolar(type,current,operatingVoltage){}
};

class iCruze:public NonSolar{
   public:
   bool havebattery = true;
   iCruze(string type,int current,int operatingVoltage):NonSolar(type,current,operatingVoltage){}
};


int main() {
    iCruze c("Non Solar",24,5);
    bool f = c.havebattery;
    int x = c.powerating();
    cout<<x<<endl;
    if(f == true){
        cout<<"YES"<<endl;
    }

    else{
        cout<<"NO"<<endl;
    }
}
