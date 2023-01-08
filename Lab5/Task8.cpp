#include<iostream>
using namespace std;

main()
{
	float capacity, p1, p2, time;
	float calc1, calc2;
	int calc3, calc4;
	cout << "Enter capacity : ";
	cin >> capacity;
	cout << "Enter pipe 1 capacity : ";
	cin >> p1;
	cout << "Enter pipe 2 capacity : ";
	cin >> p2;
	cout << "Enter Time : ";
	cin >> time;
	calc1 = ((((p1 * time) + (p2 * time)) * 100) / capacity);
	calc2 = ((p1 * time) + (p2 * time));
	if (calc1 > 100) {
		cout << "For " << time << "hours the pool overflows with " << calc2 << "liters";
	}
	cout << "The Pool is " << calc1 << " % full !!";

	calc3 = ((p1 * time) / calc2) * 100;
	cout << "  The contribution of Pipe 1 is : " << calc3 << "%";
	calc4 = ((p2 * time) / calc2) * 100;
	cout << "  The contribution of Pipe 2 is : " << calc4 << "%";
}