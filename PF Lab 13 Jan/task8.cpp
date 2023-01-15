#include<iostream>
using namespace std;


int main()
{

	int h, x, y;
	cout << "Enter the value of h : " << endl;
	cin >> h;
	cout << "Enter the X coordinates of the figure : " << endl;
	cin >> x;
	cout << "Enter the Y coordinates of the figure : " << endl;
	cin >> y;
	int upper_right_x = 2 * h;
	int upper_right_y = 4 * h;
	if (x<0 || x>upper_right_x || y<0 || y>upper_right_y) {
		cout << "Outside" << endl;
	}
	else if (x > h && x < 2 * h && y<4 * h) {
		cout << "Outside" << endl;
	}
	else if (x > h && y > h && y < 4 * h) {
		cout << "Outside" << endl;
	}
	else if (x<h && y>h && y < 4 * h) {
		cout << "Inside" << endl;
	}
	else {
		cout << "Border" << endl;
	}
	return 0;
}