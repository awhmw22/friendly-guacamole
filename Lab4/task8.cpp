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
    int discountOther = amount * 0.05;
    int discount = amount * 0.1;
    int payAbleamount = amount - discount;
    int payAbleamountOther = amount -discountOther;
     if (day == "sunday"){
     cout << "Payable amount is: " << payAbleamount <<endl;
     }
     if (day != "sunday"){
     cout << "Payable amount is: " <<payAbleamountOther <<endl;
     }
}