
#include <iostream>
#include <algorithm>
#include <climits> 
#include<string>

using namespace std;

string reverseIt(string si)
{
    for(int i = 0; i < si.length()/2; i++)
    {
        char temp = si[i];
        si[i] = si[si.length() - i - 1];
        si[si.length() - i - 1] = temp;
    }
    return si;
}

int main() {
    string s; getline(cin, s); int n; cin>>n;
    string fin; 
    if(s[s.length()-1] == ' ')
    {
        s[s.length() - 1] = '\0';
    }
    if(s[s.length()-2] == ' ')
    {
        s[s.length() - 2] = '\0';
    }
    if(n > s.length())
    {
        n = s.length();
    }

for(int i = 0; i < s.length(); i ++)
{
    string temp = "";
   for(int j = i; j < i+n; j++)
   {
        temp += s[j]; 
   }
   i += n;
    temp = reverseIt(temp);
   fin.append(temp);
   temp = "";
   for(int j = i; j < i+n; j++)
   {
       temp += s[j];
   }
   fin.append(temp);
   i += n - 1;
   
}

cout<<fin;
    return 0;
}
