#include <iostream>
using namespace std;

void totalAmount( string day , int amount);

 int main(){
 string day;
 int amount;
    while(true){
       cout << "Enter day: ";
       cin >> day;
       cout << "Enter amount: ";
       cin >> amount;
       totalAmount( day ,  amount);
    }
    return 0;
 }

void totalAmount( string day , int amount){
    int discount;
    int payAbleamount;
    discount = amount * 0.1;
    payAbleamount = amount - discount;
     if (day == "sunday"){
     cout << "Payable amount is: " << payAbleamount <<endl;
     }  
     if (day != "sunday"){
     cout << "Payable amount is: " <<amount <<endl;
     }
}