#include<iostream>
#include<windows.h>
using namespace std;
void printName(){

cout<<"    ##     ##    ##     ##    #########      ##      #####    #######     ##    "<<endl;
cout<<"    ##     ##    ##     ##           #     ##   ##     #      #         ##   ## "<<endl;
cout<<"    ## ### ##    ##     ##         #       ## # ##     #      ######    ## # ## "<<endl;
cout<<"    ##     ##    ##     ##       #         ##   ##     #      #         ##   ## "<<endl;
cout<<"    ##     ##     ## ## #       #######    ##   ##   #####    #         ##   ## "<<endl;
}
void gotoxy(int x,int y)
{
COORD coordinates;
coordinates .X=x;
coordinates .Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}
int main(){
        system("Cls");
        printName();
        gotoxy(20,20);
        return 0;
}