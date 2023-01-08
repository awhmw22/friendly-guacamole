#include<iostream>
using namespace std;
float volume(float length,float width,float height,string unit);
int main()
{
	float l=0.0;
	float w=0.0;
	float h=0.0;
	string u;
	volume(l, w, h, u);
}
float volume(float length, float width, float height, string unit)
{
	cout << "Enter length in metres : " << endl;
	cin >> length;
	cout << "Enter width in metres : " << endl;
	cin >> width;
	cout << "Enter height in metres : " << endl;
	cin >> height;
	cout << "Enter the units : " << unit;
	cin >> unit;
	float volume = (length * width * height)/3;
	cout << "Volume of pyramid is : " << volume;
	if (unit == "millimetres") {
		volume = volume *1000000000 ;
		cout << volume << unit;
	}
	if (unit == "centimetres") {
		volume = volume * 1000000;
		cout << volume << unit;
	}
	if (unit == "kilometres") {
		volume = volume / 1000000000;
		cout << volume << unit;
	}
	return volume;
}