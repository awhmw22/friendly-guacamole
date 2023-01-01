#include<iostream>
#include<windows.h>
using namespace std;
void printMenu();
void calculateAggregate(string name,float matric_marks,float inter_marks,float ecat_marks);
void CompareMarks(string std1,int ecat_marks_std1,string std2,int ecat_marks_std2);
int main()
{
 printMenu();
 string nam;
 float matricMarks;
 float interMarks;
 float ecatMarks;
 calculateAggregate( nam, matricMarks, interMarks, ecatMarks);
  string stud1;
  string stud2;
  int  ecat_marks_stud1;
  int  ecat_marks_stud2;
  CompareMarks( stud1, ecat_marks_stud1, stud2, ecat_marks_stud2);
  return 0;
}
void printMenu()
{
cout<<" ##     ##    ##       ##    #######    ###     ###   #######   ##########     #########     #######    ##########   ###     ### "<<endl;
cout<<" ##     ##    ## ##    ##       #        ###   ###    #         #        #       #     #        #           #         ###   ### "<<endl;
cout<<" ##     ##    ##  ##   ##       #         ##   ##     ######    #    #####         #            #           #           #####   "<<endl;
cout<<" ##     ##    ##    ## ##       #          ## ##      #         #     #       #      #          #           #             ##    "<<endl;
cout<<"  ## # ##     ##       ##    #######         ##       ######    #      #      ########       #######        #           ######  "<<endl;

















       cout<<" ##      ##      ##      ##       ##     ##     #########    ########   ##      ##  #######  ##      ##   ##########  " <<endl;
       cout<<" ##  ##  ##   ##    ##   ## ##    ##  ##    ##  #       #    #          ##  ##  ##  #        ## ##   ##        #      "<<endl;
       cout<<" ##  ##  ##   ##  # ##   ##  ##   ##  ## #  ##  #  #####     ########   ##  ##  ##  #######  ##  ##  ##        #      "<<endl;
       cout<<" ##  ##  ##   ##    ##   ##   ##  ##  ##    ##  #      #     #          ##  ##  ##  #        ##   ## ##        #      "<<endl;
       cout<<" ##  ##  ##   ##    ##   ##       ##  ##    ##  ########     ########   ##  ##  ##  #######  ##      ##        #      "<<endl;











                  cout<<"          #########      ####    ####     ##########     ##########    ###########     ###       ###    "<<endl;
                  cout<<"            #     #       ####  ####        #      #         #         #               ###  ###  ###    "<<endl;
                  cout<<"             #             ########          #               #         ###########     ###  ###  ###    "<<endl;
                  cout<<"        #      #              ##         #     #             #         #               ###  ###  ###    "<<endl;
                  cout<<"        #######            ########      ######              #         ###########     ###  ###  ###    "<<endl;
}
void calculateAggregate(string name,float matric_marks,float inter_marks,float ecat_marks)
{
 string nam;
 cout<<"Enter the name of student : "<<endl;
 cin>>nam;
 float matricMarks;
 cout<<"Enter the matric marks of student : "<<endl;
 cin>>matricMarks;
 float interMarks;
 cout<<"Enter the inter marks of student : "<<endl;
 cin>>interMarks;
 float ecatMarks;
 cout<<"Enter the ecat marks of student : "<<endl;
 cin>>ecatMarks;
 matricMarks=matricMarks/1100*(0.3*100);
 interMarks=interMarks/550*(0.3*100);
 ecatMarks=ecatMarks/400*(0.4*100);
 float aggregate=matricMarks+interMarks+ecatMarks;
 cout<<"The final aggregate of student is :"<<aggregate<<endl;
}
void CompareMarks(string std1,int ecat_marks_std1,string std2,int ecat_marks_std2)
{
 string stud1;
 cout<<"Enter name of student 1 : "<<endl;
 cin>>stud1;
 string stud2;
 cout<<"Enter name of student 2 : "<<endl;
 cin>>stud2;
 int  ecat_marks_stud1;
 cout<<"Enter the ecat marks of student 1 : "<<endl;
 cin>> ecat_marks_stud1;
 int  ecat_marks_stud2;
 cout<<"Enter the ecat marks of student 2 : "<<endl;
 cin>> ecat_marks_stud2;
 if(ecat_marks_stud1>ecat_marks_stud2){
   cout<<"The student 1 gets the first roll number"<<endl;
   }
 if(ecat_marks_stud2>ecat_marks_stud1){
    cout<<"The student 2 gets the first roll number"<<endl;
   } 
 }
 
 