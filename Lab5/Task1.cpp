#include<iostream>
#include<cmath>
using namespace std;
float calculateHeight(float distance,float degrees);
main()
{
 float base;
 float angle;
 float height;
 cout<<"Enter base value :";
 cin>>base;
 cout<<"Enter the angle of elevation :";
 cin>>angle;

 height=calculateHeight(base,angle);
cout<<"Height of the tree is:"<<height<<endl;
}
float calculateHeight(float distance,float degrees)
{
 float radian=57.2958;
 float radians;
 float angle;
 float height;
 radians=degrees/radian;
 angle=tan(radians);
 height=angle*distance;
 return height;
}
 
 
  
