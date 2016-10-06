#include<iostream>

using namespace std;

int main()
{
    long long int x; cin>>x; long long int permaX = x;

    long long int counter  = 0;
    for(long long int i = 2; i < (x/2)+1; i++)
    {
        if(permaX%i == 0)
        {
            counter++;
            permaX = permaX/i;
        }
    }

    cout<<counter;

    return 0;
}
