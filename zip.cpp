#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include<vector>

int conty;
int n;
using namespace std;

void traversal(vector<int> hills, int pos, int counter)
{
    counter++;
    if(counter>conty)
        conty = counter;
    if(hills[pos - 1] < hills[pos] && pos-1 >= 0)
    {
       traversal(hills, pos-1, counter);
    }
    if(hills[pos - 2] < hills[pos] && pos-2 >= 0)
    {
        traversal(hills, pos-2, counter);
    }
    if(hills[pos + 1] < hills[pos] && pos+1 <n)
    {
        traversal(hills, pos+1, counter);
    }
    if(hills[pos + 2] < hills[pos] && pos+2 < n)
    {
        traversal(hills, pos+2, counter);
    }
}

int main() {
     cin>>n;
    vector<int> hills;
    for(int i = 0; i< n; i++)
    {
        int temp; cin>>temp; hills.push_back(temp);
    }
    //input done

   conty = 0; 

   for(int i = 0; i < n; i++)
   {
       traversal(hills, i, 0);
   }

   cout<<conty-1;

    return 0;
}
