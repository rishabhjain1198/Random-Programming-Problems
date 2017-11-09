#include<iostream>

using namespace std;

int main()
{
    int n; cin>>n; int result = 0;

    for(int i = 0; i<100; i++)
    {
        for(int j = 0; j<100; j++)
        {
            if(i+j == n)
                result++;
        }
    }

    cout<<result;
    return 0;
}
