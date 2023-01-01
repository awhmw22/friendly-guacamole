#include<iostream>
using namespace std;
void isEqual(int x,int y);
int main(){
          int a=7;
          int b=9; 
           isEqual(a,b);
 return 0;
}
void isEqual(int x,int y)
{
  int a;
  cout<<"Enter first number : "<<endl;
  cin>>a;
  int b;
  cout<<"Enter second number : "<<endl;
  cin>>b;
  if(a>b){
    cout<<"True";
}
  if(a<b){
    cout<<"False";
}
}