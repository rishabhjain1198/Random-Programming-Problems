#include<iostream>
#include<vector>

using namespace std;

bool searchit(vector<pair<int, int> > &envelopes, vector<pair<int, int> > &dpit, int pos)
{
    for(int i = 0; i < dpit.size(); i++)
    {
        if(envelopes[pos].first == dpit[i].first && envelopes[pos].second == dpit[i].second)
        {
            return 1;
        }
    }

    return 0;
}

void traverseit(vector<pair<int, int> > &envelopes, int pos, vector<pair<int, int> > &dpit, int finalAnswer, int tempCount)
{
    if(!searchit(envelopes, dpit, pos))
    {
        dpit.push_back(envelopes[pos]);
        for(int i = 0; i<envelopes.size(); i++)
        {
            if(envelopes[pos].first > envelopes[i].first && envelopes[pos].second > envelopes[i].second)
            {
               traverseit(envelopes, i, dpit, finalAnswer, tempCount+1);
            }
        }
    }
}

int maxEnvelopes(vector<pair<int, int> > &envelopes)
{
    int finalAnswer;
    vector<pair<int, int> > dpit;     
    traverseit(envelopes, 0, dpit, finalAnswer, 0);
    return finalAnswer; 
}

int main()
{
    vector<pair<int, int> > envelopes;
    envelopes.push_back(make_pair(5,6));
    envelopes.push_back(make_pair(3,4));

    maxEnvelopes(envelopes);

    return 0;
}
