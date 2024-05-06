#include <iostream>
#include <bits/stdc++.h>
using namespace std;
  void f(int withdraw,map<int,int>&mp,vector<int>&availaibedeno,int totamount){  // To find the denomination When customer Will Withdraw.
         map<int,int>requireddeno;                             // This function will help you to find the denomination for the withdrawal Ammount
         int withdrawamount = withdraw;

         int i = availaibedeno.size() - 1;

         while(i>=0 && withdrawamount>0){
             int denomination = availaibedeno[i];
             while(mp[denomination]>0 && withdrawamount>=denomination && withdrawamount>0){
                 withdrawamount = withdrawamount - denomination;
                 mp[denomination]--;
                 requireddeno[denomination]++;
             }
             i--;
         }

         for(auto it:requireddeno){
             cout<<it.second<<" "<<it.first<<endl;
         }

         cout<<"remaining Balance"<<" "<<totamount-withdraw<<endl;
    }

class ATM{
    vector<int>arr;
    public:
    ATM(){}
    int totalamountofatm=0;
    string error = "Insufficent Balance";

    void totalamountofatmm(map<int,int>&mp){
        for(auto it:mp){
            int amount = it.first*it.second;
            totalamountofatm = totalamountofatm + amount;
        }
        cout<<"Before Totalamount"<<" "<<totalamountofatm<<endl;
    }


    void topuptheatm(map<int,int>& mp,vector<int>&arr){
          cout<<"Enter the top up amount"<<endl;
          int topamount;
          cin>>topamount;

          totalamountofatm = totalamountofatm + topamount;

          for(int i=arr.size()-1;i>=0;i--){ 
              int sh = arr[i];
             
              while(topamount>0 && topamount>sh){
                  topamount = topamount - sh;
                  mp[arr[i]]++;
              }
          }
          cout<<"Total Balance after Topup"<<" "<<totalamountofatm<<endl;
    }

    void withdrawamount(map<int,int>&mp,vector<int>&denocurrency){
         cout<<"Enter the withdrawal Amount"<<endl;
         int amountotbewithdrawn;
         cin>>amountotbewithdrawn;

        map<int,int>gh = mp;

         if(amountotbewithdrawn>totalamountofatm){
             cout<<error<<endl;
         }
         
         else{
             int amountotbewithdraw = amountotbewithdrawn; 
             bool flag = false;
            
             for(int i=0;i<denocurrency.size();i++){
                 int temp = denocurrency[i];
                 while(amountotbewithdraw>=temp){
                     amountotbewithdraw = amountotbewithdraw - temp;
                 }
             }

             if(amountotbewithdraw == 0){
                 vector<int>r = denocurrency;
                 cout<<"The Denomination is  availaible"<<endl;
                 f(amountotbewithdrawn,gh,r,totalamountofatm);
             }

             else{
                 cout<<"Denomination is not availaibe"<<endl; 
             }
         }
    }
};
int main() {
    ATM a;
    map<int,int>mp;
    vector<int>arr;

    arr.push_back(2000);
    arr.push_back(500);
    arr.push_back(200);
    arr.push_back(100);

    mp[2000] = 1;
    mp[500] = 2;
    mp[200] = 5;
    mp[100] = 6;

    sort(arr.begin(),arr.end());
    
    a.totalamountofatmm(mp);
    a.topuptheatm(mp,arr);
    a.withdrawamount(mp,arr);
    return 0;
}
