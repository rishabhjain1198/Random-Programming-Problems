#include<iostream>
#include<vector>

using namespace std;

void mergeIt(vector<pair<int, int> > &envelopes, int low, int mid, int high, vector<pair<int, int> > &dpit)
{
    int part1, part2, i;
    for(part1 = low, part2 = mid+1, i = 0; part1 <= mid && part2 <= high && i <= high; i++)
    {
        if(envelopes[part1].first > envelopes[part2].first)
        {
                dpit.push_back(envelopes[part1++]);
        }
        else if(envelopes[part1].first <= envelopes[part2].first)
        {
                dpit.push_back(envelopes[part2++]);
        }
    }
    while(part1<=mid)
    {
        dpit.push_back(envelopes[part1++]);
    }
    while(part2<=high)
    {
        dpit.push_back(envelopes[part2++]);
    }

    while(low<=high)
    {
        envelopes[low] = dpit[low];
        low++;
    }
}

void mergeSort(vector<pair<int, int> > &envelopes, int low, int high, vector<pair<int, int> > &dpit)
{
   if(low<high)
   {
        int mid = (low + high) / 2;
        mergeSort(envelopes, low, mid, dpit);
        mergeSort(envelopes, mid+1, high, dpit);
        mergeIt(envelopes, low, mid, high, dpit);
   }
    
}

void secondSort(vector<pair<int, int> > &envelopes, int start)
{
    if(start!=(envelopes.size())-1)
    {
        int endi = start;
        for(int i = start; i<envelopes.size(); i++)
        {
           if(envelopes[i].first == envelopes[start].first)
           {
                endi = i;
           }
        }
        
        for(int i = start; i<=endi; i++)
        {
            for(int j = start; j<=i; j++)
            {
                if(envelopes[j].second > envelopes[i].second)
                {
                    pair<int, int> temp  = envelopes[j];
                    envelopes[j]= envelopes[i];
                    envelopes[i]= temp;
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
    if(!searchit(envelopes, dpit, pos))
    {
        dpit.push_back(envelopes[pos]);
        for(int i = pos+1; i<envelopes.size(); i++)
        {
            if(envelopes[pos].first > envelopes[i].first && envelopes[pos].second > envelopes[i].second)
            {
               traverseit(envelopes, i, dpit, finalAnswer, tempCount+1);
               break;
            }
        }
    }}
    else
    {
       if(tempCount>finalAnswer)
            finalAnswer = tempCount;
    }
}

int maxEnvelopes(vector<pair<int, int> > &envelopes)
{
    int finalAnswer;
    vector<pair<int, int> > dpit;     
    mergeSort(envelopes, 0, envelopes.size(), dpit);
    dpit.clear();
    secondSort(envelopes, 0);
    for(int i = 0; i<envelopes.size(); i++)
    {
        traverseit(envelopes, i, dpit, finalAnswer, 0);
    }
    return finalAnswer; 
}

int main()
{
    vector<pair<int, int> > envelopes = [[5,4],[6,4],[6,7],[2,3]];
    

    maxEnvelopes(envelopes);

    return 0;
}
