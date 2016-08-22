#include<iostream>
#include<vector>

using namespace std;

void printit(vector<pair<int, int> > &envelopes)
{
    for(int i = 0; i<envelopes.size(); i++)
    {
        cout<<envelopes[i].first<<" "<<envelopes[i].second<<endl;
    }
    cout<<endl;
}

void firstSort(vector<pair<int, int> > &envelopes)
{
    bool swapped = true;
    int j = envelopes.size();
    while(swapped)
    {
        j--;
        swapped = false;
        for(int i = 0; i < j; i++)
        {
            if(envelopes[i].first<envelopes[i+1].first)
            {
                int number1 = envelopes[i].first; int number2 = envelopes[i].second;
                envelopes[i] = envelopes[i+1];
                envelopes[i+1] = make_pair(number1, number2);
                swapped = true;
            }
        }
    }
}
void secondSort(vector<pair<int, int> > &envelopes, int start)
{
    if(start<(envelopes.size())-1)
    {
        int endi = start;
        for(int i = start; i<envelopes.size(); i++)
        {
           if(envelopes[i].first == envelopes[start].first)
           {
                endi = i;
           }
        }
        bool swapped = true;
        int j = endi+1;
       while(swapped)
        {
            j--;
            swapped = false;
        for(int i = start; i<j; i++)
        {
                if(envelopes[i].second < envelopes[i+1].second)
                {
                int number1 = envelopes[i].first; int number2 = envelopes[i].second;
                envelopes[i] = envelopes[i+1];
                envelopes[i+1] = make_pair(number1, number2);
                swapped = true;
                }
        }
        }

        secondSort(envelopes, endi+1);

    }

}

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

void traverseit(vector<pair<int, int> > &envelopes, int pos, vector<pair<int, int> > dpit, int &finalAnswer, int tempCount)
{
    if(pos!=envelopes.size()-1){
        for(int i = pos+1; i<envelopes.size(); i++)
        {
            if(envelopes[pos].first > envelopes[i].first && envelopes[pos].second > envelopes[i].second)
            {
               traverseit(envelopes, i, dpit, finalAnswer, tempCount+1);
            }
        }
    }
    if(tempCount>finalAnswer)
       finalAnswer = tempCount;
}

int maxEnvelopes(vector<pair<int, int> > &envelopes)
{
    int finalAnswer = 0;
    if(envelopes.size()!=0)
    {
        vector<pair<int, int> > dpit;     
        firstSort(envelopes);
        secondSort(envelopes, 0);
        for(int i = 0; i<envelopes.size(); i++)
        {   
            traverseit(envelopes, i, dpit, finalAnswer, 1);
        }
    }
    
    cout<<finalAnswer<<endl;
    return finalAnswer;
}

int main()
{
    vector<pair<int, int> > envelopes;
    envelopes.push_back(make_pair(46,89));
    envelopes.push_back(make_pair(50,52));
envelopes.push_back(make_pair(52,68));
envelopes.push_back(make_pair(72,45));
envelopes.push_back(make_pair(77,81));

    maxEnvelopes(envelopes);
    
    return 0;
}
