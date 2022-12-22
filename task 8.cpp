
#include <iostream>
using namespace std;
int main()
{
	float matric_marks, inter_marks, ecat_marks;
	float aggregate;
	cout << "Enter the matric marks of student : " << endl;
	cin >> matric_marks;
	cout << "Enter the intermediate marks of student : " << endl;
	cin >> inter_marks;
	cout << "Enter the ecat marks of student : " << endl;
	cin >> ecat_marks;
	matric_marks = matric_marks / 1100 * (0.1 * 100);
	ecat_marks = ecat_marks / 400 * (0.5 * 100);
	inter_marks = inter_marks / 550 * (0.4 * 100);
	
	aggregate = (matric_marks + ecat_marks + inter_marks);

	cout << "The aggregate of student is : " << aggregate << endl;
	return 0;
}
