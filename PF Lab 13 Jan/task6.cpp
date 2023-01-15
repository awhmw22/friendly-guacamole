#include<iostream>
#include<string>
using namespace std;
float CheckStudio(string month, int stays);
float CheckApartment(string month, int stays);
int main()
{
    int Stays;
    cout << "Enter the number of days of your stay : " << endl;
    cin >> Stays;
    int amount, result1, result2;
    char sign = '$';
    string Month;
    cout << "Enter month of your stay :" << endl;
    cin >> Month;
    int rent;
    result1= CheckStudio( Month,  Stays);
     result2=CheckApartment( Month, Stays);
    cout << "Your bill for studio is : " << result1 << sign << endl;
    cout << "Your bill for apartment is : " << result2 << sign << endl;
}
    float CheckStudio(string month, int stays)
    {
        float rentStudio;
        int price;
        if (month == "May" || month == "October")
        {
            if (stays > 7 && stays <= 14)
            {
                price = 50 * stays;
                rentStudio = price - (price * 0.05);
            }
            else if (stays > 14)
            {
                price = 50 * stays;
                rentStudio = price - (price * 0.3);
            }
            else
            {
                rentStudio = 50 * stays;
            }

        }
        else if (month == "June" || month == "September")
        {
            if (stays > 14)
            {
                price = 75.20 * stays;
                rentStudio = price - (price * 0.2);
            }

            else if (stays <= 14)
            {
                rentStudio = 75.20 * stays;
            }

        }
        else if (month == "July" || month == "August")
        {

            rentStudio = 76 * stays;
        }
        return rentStudio;
    }
    float CheckApartment(string month, int stays)
    {
        float apartmentStudio;
        int money;
        if (month == "May" || month == "October")
        {

            if (stays > 14)
            {
                money = 65 * stays;
                apartmentStudio = money - (money * 0.1);
            }

            else if (stays <= 14)
            {
                apartmentStudio = 65 * stays;
            }
        }
        else if (month == "June" || month == "September")
        {

            if (stays > 14)
            {
                money = 68.70 * stays;
                apartmentStudio = money - (money * 0.1);
            }

            else if (stays <= 14)
            {
                apartmentStudio = 68.70 * stays;
            }

        }


        else if (month == "July" || month == "August")
        {
            if (stays > 14)
            {
                money = 77.00 * stays;
                apartmentStudio = money - (money * 0.1);
            }
            else if (stays <= 14)
            {

                apartmentStudio = 77.00 * stays;

            }
        }
 
    }
