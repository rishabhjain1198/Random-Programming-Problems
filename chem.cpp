#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>

using namespace std;

class chems
{
    public:
        string name;
        vector<string> lias;
};
int main()
{
    int n; cin>>n;
    vector<chems> chemicals;
    for(int i = 0; i<n; i++)
    {
        string temp; cin>>temp; int num; cin>>num; 
        vector<string> temps;
        for(int j = 0; j <num; j++)
        {
            string tempy; cin>>tempy;
            temps.push_back(tempy);
        }
        chems hola; hola.name = temp; hola.lias = temps;
        chemicals.push_back(hola);
    }
    //INPUT DONE

    vector<string> seq;
    for(int i = 0; i<n ; i++)
    {
        string temp; cin>>temp; seq.push_back(temp);
    }

    bool phata = 0;

    for(int i = 0; i < n; i++)
    {
        int pos;
        for(int j = 0; j < n; j++)
        {
            if(seq[i] == chemicals[j].name)
            {
                pos = j;
            }
        }
        
        




    }

    return 0;
}
