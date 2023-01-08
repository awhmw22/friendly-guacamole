#include<iostream>
using namespace std;
int multiply(int number);

main()
{
 int num1;
 cout<<"Enter a number :"<<endl;
 cin>>num1;
 int conclusion=multiply(num1);
 cout<<"Result is:"<<conclusion<<endl;
}
int multiply(int number)
{
 int result=number*5;
 return result;
}