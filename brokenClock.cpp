#include<iostream>

using namespace std;

int result;

void showTime(int hrs[2], int mins[2])
{
    cout<<endl<<"Hours: "<<hrs[0]<<" "<<hrs[1]<<endl;
    cout<<"Minutes: "<<mins[0]<<" "<<mins[1]<<endl;
}
void showString(string s)
{
    cout<<endl;
    for(int i = 0; i<s.length(); i++)
    {
        cout<<s[i];
    }
    cout<<endl;
}

void twelve(int hrs[2])
{
    if(hrs[0] == 1)
    {
        if(hrs[1] > 2)
        {
            hrs[1] = 1;
        }
    }
    else if(hrs[0] == 0)
    {
        if(hrs[1] > 9 || hrs[1] == 0)
        {
            hrs[1] = 8;
        }
    }
    else
    {
        hrs[0] = 0;
    }
}

void minutes(int mins[2])
{
    if(mins[0]>5)
    {
        mins[0] = 1;
    }
}

void twentyfour(int hrs[2])
{
    if(hrs[0] == 2)
    {
        if(hrs[1] > 4)
        {
            hrs[1] = 1;
        }
    }
    else if(hrs[0] > 2)
    {
        hrs[0] = 0;
    }
}

int main()
{
    int timeFormat; cin>>timeFormat; 
    string times; cin>>times;
    result = 0;
    
    //input done, time to parse the information
    
    int hrs[2] = {times[0]-'0', times[1]-'0'};
    int mins[2] = {times[3]-'0', times[4]-'0'};
    if(times[3] == '0')
    {
        mins[0] = 0;
    }

    if(times[4] == '0')
    {
        mins[1] = 0;
    }

    if(timeFormat == 12)
        twelve(hrs);
    else
        twentyfour(hrs);

    minutes(mins);

    cout<<hrs[0]<<hrs[1]<<":"<<mins[0]<<mins[1];


    return 0;
}
