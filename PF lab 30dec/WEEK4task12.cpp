#include<iostream>
using namespace std;
void Amount(int number1,int number2,int number3);
int main(){
    int num1;
    int num2;
    int num3;
           Amount(num1,num2,num3);
           return 0;
}
void Amount(int number1, int number2, int number3) {
          int num1;
         cout<<"Enter the number of red roses sold : "<<endl;
         cin>>num1;
          int num2;
         cout<<"Enter the number of white roses sold  :" <<endl;
         cin>>num2; 
           int num3;
         cout<<"Enter the number of tulips sold : " <<endl;
         cin>>num3;
         float originalprice=(num1*2.00)+(num2*4.10)+(num3*2.50);
               cout<<"The original price of flowers is :" <<originalprice<<endl;    
         if(originalprice>200){
            float discprice=(originalprice-(originalprice*20)/100);
            cout<<"Price after discount is : "<<discprice<<endl;
         }
 } 
         
         
           