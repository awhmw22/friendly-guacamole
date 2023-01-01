#include<iostream>
using namespace std;
void Tomplays();
int main()
{
  Tomplays();
  return 0;
}
void Tomplays()
{ 
  int holidays;
  cout<<"Enter the number of holidays per year : "<<endl;
  cin>>holidays;
  int time1=30000;
  int workingdays=365-holidays;
  cout<<"The working days per year ="<<workingdays<<endl;
  int time2=(workingdays*63)+(holidays*127);
  cout<<"The time for playing games in minutes is :"<<time2<<endl;
  int difference=time1-time2;
  cout<<"The difference from the norm in minutes is :"<<difference<<endl;
  if(holidays==20){
    cout<<"Tom sleeps well i.e 5,725 minutes less for play"<<endl;
    }
  if(holidays>20){
    cout<<"Tom will run away"<<endl;
    }
   }                 