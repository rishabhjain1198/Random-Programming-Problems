#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include<vector>

using namespace std;

void showit(vector<string> dict)
{
    for(int i = 0; i < dict.size(); i++)
    {
        cout<<endl;
        cout<<dict[i];
    }
}

int main() {
    int n;  cin>>n; vector<string> dict;
    for(int i = 0; i < n; i++)
    {
            string tempp, temp = "";
                cin>> tempp;
                for(int j = 0; j < tempp.length(); j++)
                {
                    temp += tolower(tempp[j]);
                }
                sort(temp.begin(), temp.end());
                        dict.push_back(temp);
    }

    int counter = 0;
    vector<int> used;
    for(int i = 0; i<n; i++)
    {
        used.push_back(0);
    }

    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
        used[i] = 1; bool haan = 1;
        for(int j = i+1; j < n; j++)
        {
            if(dict[i] == dict[j])
            {
                if(haan)
                {
                    counter++;
                    haan = 0;
                }
                used[j] = 1;
                counter++;
            }
        }
        }
    }

    cout<<counter;
    return 0;
}
