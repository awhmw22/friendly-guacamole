#include<iostream>
using namespace std;
void AirlineCompany();
int main(){
            while(true){       
            AirlineCompany();
}
            return 0;     
}
void AirlineCompany(){
string country;
cout<<"Enter the country you want to travel to :"<<endl;
cin>>country;
int cost;
cout<<"Enter the ticket price in dollars"<<endl;
cin>>cost;
if(country=="Pakistan"){
   int finalprice=(cost-(cost*5)/100);
   cout<<"The final price after discount is :"<<finalprice<<endl;
}
if(country=="India"){
   int finalprice=(cost-(cost*20)/100);
   cout<<"The final price after discount is :"<<finalprice<<endl;
}
if(country=="England"){
   int finalprice=(cost-(cost*30)/100);
   cout<<"The final price after discount is :"<<finalprice<<endl;
}
if(country=="Ireland"){
   int finalprice=(cost-(cost*10)/100);
   cout<<"The final price after discount is :"<<finalprice<<endl;
}
if(country=="Canada"){
   int finalprice=(cost-(cost*45)/100);
   cout<<"The final price after discount is :"<<finalprice<<endl;
}
}