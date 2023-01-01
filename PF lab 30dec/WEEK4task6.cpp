#include<iostream>
#include<windows.h>
using namespace std;
void printA(){


cout<<"            ##        "<<endl; 
cout<<"         ##    ##     "<<endl;
cout<<"         ## ## ##     "<<endl;
cout<<"         ##    ##     "<<endl;
cout<<"         ##    ##     "<<endl;
}



void printW(){
cout<<"         ##      ##         "<<endl;
cout<<"         ##  ##  ##         "<<endl;
cout<<"         ##  ##  ##         "<<endl;
cout<<"         ##  ##  ##         "<<endl;
cout<<"          ## ## ##          "<<endl;
}




void printI(){
cout<<"          #######        "<<endl;
cout<<"             #            "<<endl;
cout<<"             #            "<<endl;
cout<<"             #            "<<endl;
cout<<"          #######         "<<endl;
}



void printS(){
cout<<"            ##########    "<<endl;
cout<<"             ##      #    "<<endl;
cout<<"              ##          "<<endl;
cout<<"         #     ##         "<<endl;
cout<<"         ########         "<<endl;
}
gotoxy(int x,int y)
{
 COORD coordinates;
 coordinates .X=x;
 coordinates .Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
int main()
{
system("Cls");
 printA();



 printW();



 printA();



 printI();



 printS();




 gotoxy(0,20);



 return 0;
}


