#include <iostream>
using namespace std;

 void greaterNumber(int number1 , int number2);

 int main(){
 
    int number1 , number2 ; 
   while(true){
      cout << "Enter first number: " ;
      cin >> number1;
     cout << "Enter second number: " ;
     cin >> number2;
     greaterNumber(number1 , number2);
   }
   return 0;
 }

 void greaterNumber(int number1 , int number2){

   if (number1 > number2){
   cout << "First number is greater" <<endl;
   }

   if (number2 > number1){
   cout << "Second number is greater" <<endl;
   }
 }