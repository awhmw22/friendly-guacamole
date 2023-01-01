#include<iostream>
using namespace std;
void Reverse(string value);
int main(){
      string proposition;
    Reverse(proposition);
    return 0;
}
void Reverse(string value){
    string statement;
    cout << "Enter statement true or false : " << endl;
    cin >> statement;
 if(statement=="true"){
    cout<<"false"<<endl;
}
 if(statement=="false"){
    cout<<"true"<<endl;
}
}