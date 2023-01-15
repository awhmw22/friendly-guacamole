#include <iostream>
#include <cmath>
using namespace std;

float PlayVolleyball(int holidays ,int weekends );

main()
{
     int holidays , weekends; 
     string year;
     cout << "Is Year leap or not? " << endl;
    cin >> year;
    cout << "Enter his number of hoidays: " << endl;
    cin >> holidays;
    cout << "Enter number of weekends in which he travels to his hometown: " << endl;
    cin >> weekends;
    float result = PlayVolleyball(holidays , weekends );
     if (year == "leap")
     {
        float Normalplay = result * 0.15;
          float End = Normalplay + result;
              int Approx = floor(End);
              cout << Approx;
    
     }
    else
    {
       int Approx = floor(result);
       cout << Approx;
    }
}
float PlayVolleyball(int holidays ,int weekends )
{
    float play =   (holidays * 0.67);
    float days = 36 + play ;
    return days;
}