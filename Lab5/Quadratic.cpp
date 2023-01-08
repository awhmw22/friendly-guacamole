#include<iostream>
#include<cmath>
using namespace std;
float quadraticPlus(int num1,int num2,int num3);
float quadraticminus(int number1,int number2,int number3);
main()
{
 int a,b,c;
 cout<<"Enter first number: "<<endl;
 cin>>a;
 cout<<"Enter second number :"<<endl;
 cin>>b;
 cout<<"Enter third number :"<<endl;
 cin>>c;
 float x=quadraticPlus(a,b,c); 
 cout<<"positive value of x is :"<<x<<endl;
 float X=quadraticminus(a,b,c);
 cout<<"negative value of x is :"<<X<<endl;
}
float quadraticPlus(int num1,int num2,int num3)
{
	int v1 = pow(num2, 2);
 int v2=4*num1*num3;
 int v3=2*num1;
 int v4 = -num2;
 float b2=v1-v2;
 float squareroot=sqrt(b2);
 float plus = v4 + squareroot;
 float x1 = plus / v3;
 return x1;
}
float quadraticminus(int number1,int number2,int number3)
{
 int a1=pow(number2,2);
 int a2=4*number1*number3;
 int a3=2*number1;
 int a4 = -number2;
 float b1=a1-a2;
 float squaroot=sqrt(b1);
 float minus = a4 - squaroot;
 float x2=minus/a3;
 return x2;
}