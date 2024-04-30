#include <iostream>
using namespace std;

class inverter{
      public:
      int current;
      int voltage;
      int powerrating = 0;
      string type;

     inverter(string t,int c,int v) : type(t),current(c),voltage(v){}

     virtual bool issolar(){ // Used the Virtual Function to achieve the Polymorphism//
         return false;
     }

     virtual bool havepanel(){
         return false;
     }

     virtual bool battery(){
         return true;
     }
 
     virtual bool hasGridd(){
         return false;
     }

     virtual void print(){
         cout<<type<<endl;
         cout<<powerrating<<" "<<current*voltage<<endl;
     }  
};

class Solarinverter:public inverter{ // Inherit the Class //
      public:
      string type;
      int current;
      int voltage;
      bool hasSolarPanels;
      bool hasGrid;
      bool hasBattery;

      Solarinverter(string type,int current,int voltage,bool solarpanels,bool grid,bool battery) : inverter(type,current,voltage),hasSolarPanels(solarpanels),
      hasBattery(battery),hasGrid(grid){}

     virtual bool havepanel(){
          return hasSolarPanels;
      }

      virtual bool hasGridd(){
          return hasGrid;
      }

      virtual bool battery(){
          return hasBattery;
      }

      virtual void print(){
          cout<<type<<endl;
          cout<<powerrating<<" "<<current*voltage<<endl;

          if(hasSolarPanels == true){
              cout<<"With Solar Panles"<<endl;
          }
          else{
              cout<<"Without Solar Panels"<<endl;
          }

          if(hasBattery == true){
              cout<<"With Battery"<<endl;
          }

          else{
              cout<<"Without Battery"<<endl;
          }

          if(hasGrid == true){
              cout<<"Has Grid"<<endl;
          }

          else{
              cout<<"No Grid"<<endl;
          }

      }
};


int main() {
     inverter* PCU = new inverter("Inverter",220,5);
     inverter* GTI = new Solarinverter("Inverter",220,5,true,false,true);

     PCU->print();
     GTI->print();

     return 0;
}
