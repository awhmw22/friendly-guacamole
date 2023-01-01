#include <iostream>
using namespace std;

 void isEven(int number);

int main(){

    int number;
    while(true){
	 cout << "Enter number: ";
 	  cin >> number;
		isEven(number);
    }
    return 0;
}

 void isEven(int number){
    
   if( number%2==0){
    
   cout << "The number is even" <<endl;
   }

   if (number%2!=0){

   cout << "Number is odd"<<endl; 
   }
}