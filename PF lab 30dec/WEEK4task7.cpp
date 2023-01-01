#include <iostream>
#include <windows.h>
using namespace std;
void printMaze()
{
 cout<<"   #####################################################################  "<<endl;

 cout<<"   #                                                                   #  "<<endl;

 cout<<"   #                                                                   #  "<<endl;

 cout<<"   #                                                                   #  "<<endl;

 cout<<"   #                                                                   #  "<<endl;

 cout<<"   #                                                                   #  "<<endl;

 cout<<"   #                                                                   #  "<<endl;

 cout<<"   #                                                                   #  "<<endl;

 cout<<"   #                                                                   #  "<<endl;

 cout<<"   #                                                                   #  "<<endl;

cout<<"    #                                                                   #  "<<endl;

cout<<"    #                                                                   #  "<<endl;

 cout<<"   #####################################################################  "<<endl;
}
void gotoxy(int x,int y)  
{
 COORD coordinates;
 coordinates .X=x;
 coordinates .Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
void Pacman(int x,int y)
{
 gotoxy(x,y-1);
 cout<<" ";
 gotoxy(x,y-1);
 cout<<" P ";
 Sleep(200);
 }
int main()
{
 system("Cls");
 printMaze();
int x=3;
int y=3;
 while(true){
            Pacman(x,y);
       if(y<20){
       y=y+1;
  }
       if(y==20){
       gotoxy(x,y-1);       
      cout<<"";
      y=3;
} 
       if (y > 20) {
           y = y - 1;
       }
}
 return 0;
}