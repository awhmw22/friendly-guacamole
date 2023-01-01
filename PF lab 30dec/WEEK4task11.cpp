#include<iostream>
using namespace std;
void Speed();
int main(){
           Speed(); 
           return 0;
}
void Speed(){
     int speed;
     cout<<"Enter the speed of car in km/h :"<<endl;
     cin>>speed;
     if(speed>100){
       cout<<"Warning!!!YOU WILL BE CHALLENGED!!!";
}
     if(speed<100){
       cout<<"Perfect! You are going good";
}
}