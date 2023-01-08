#include<iostream>

using namespace std;

main()
{
	int x, y, z;
	cout << "Enter hours : ";
	cin >> x;
	cout << "Enter minutes : ";
	cin >> y;
	if (x <= 23)
	{
		if (y <= 44) {
			y = y + 15;
			cout << x << ":" << y;
		}
		if (y == 45) {
			y = 0;x = x + 1;
			cout << x << ":" << y;
		}
		if (y > 45) {
			y = (y + 15) - 60;
			if (x == 23)
			{
				x = 0;
			}
			if (x <= 22)
			{
				x = x + 1;
			}
			cout << x << ":" << y;
		}

	}
	else if (x == 24)
	{
		if (y <= 44)
		{
			y = y + 15;
			cout << x << ":" << y;
		}
		if (y == 45)
		{
			y = 0;x = 0;
			cout << x << ":" << y;
		}
		if (y > 45)
		{
			y = (y + 15) - 60;
			x = 0;
			cout << x << ":" << y;
		}

	}
	if (x > 24)
	{
		cout << "Invalid Input !!!";
	}

}