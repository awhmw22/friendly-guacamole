#include<iostream>
using namespace std;
int main()
{
	          /*During each summer, Ahmad and Fatima grow vegetables in their backyard and buy
seeds and fertilizer from a local nursery. The nursery carries different types of vegetable
fertilizers in various bag sizes. When buying a particular fertilizer, they want to know the
price of the fertilizer per pound and the cost of fertilizing per square foot. Write a c++
program that inputs
1. the size of the fertilizer bag in pounds.
2. the cost of the bag.
3. and the area in square feet that can be covered by the bag.*/
	int size;
	int cost;
	int area;
	cout << "Enter the size of fertilizer bag in pounds : " << endl;
	cin >> size;
	cout << "Enter the cost per bag in PKR : " << endl;
	cin >> cost;
	cout << "Enter the area in square feet that can be covered by the bag : " << endl;
	cin >> area;
	int cost_price = cost / size;
	cout << "The cost of fertilizer per pound in PKR is : " << cost_price << endl;
	int cost_per_square_foot = cost / area;
	cout << "The cost of fertilizing per square foot in PKR is : " << cost_per_square_foot << endl;
	return 0;



}