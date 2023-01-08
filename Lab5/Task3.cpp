#include<iostream>
#include<cmath>
using namespace std;
bool isSymmetric(int num);
main()
{
 system("cls");
 bool z;
 int number;
while(1)
        {
 cout<<"Enter a three digit number:"<<endl;
 cin>>number;
 z= isSymmetric(number);
      if(z==true){
          cout<<"true"<<endl;
          }
      if(z!=true){
          cout<<"false"<<endl;
          } 
         }
}
bool isSymmetric(int num)
{
 int digit1=num%10;
 int d1=num/10;
 int digit2=d1%10;
 int d2=d1/10;
 int digit3=d2%10;
 int d3=d2/10;
 
 if(digit1==digit3){
    return true;
   }
 else{
      return false;
   }
} 
 