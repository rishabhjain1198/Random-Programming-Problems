#include<iostream>

using namespace std;

void dayToNumber(string day, int &number)
{
    if(day == "monday")
        number = 1;
    else if(day == "tuesday")
        number = 2;
    else if(day == "wednesday")
        number = 3;
    else if(day == "thursday")
        number = 4;
    else if(day == "friday")
        number = 5;
    else if(day == "saturday")
        number = 6;
    else if(day == "sunday")
        number = 7;
}

int main()
{
    string x1; string x2; cin>>x1; cin>>x2; int day1, day2; dayToNumber(x1, day1); dayToNumber(x2, day2); int y = 0;
    if(day2 > day1)
        y = day2 - day1;
    else if(day1 > day2)
        y = 7 - day1 + day2;
    if(y == 3 || y == 2 || y == 0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
