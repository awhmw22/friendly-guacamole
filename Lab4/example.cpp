#include <iostream>
using namespace std;

void printName(string name);

main(){
 string name = "Huzaifa";
 printName(name);
 printName("Wattoo");
 string secondName;
 cout << "Enter name: ";
 cin >> secondName;
 printName (secondName);
}
void printName(string name){
 cout << "My name is: " <<name <<endl;


}