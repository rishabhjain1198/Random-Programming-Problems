#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

void makeNewParens(int leftPair, int rightPair, vector<string> &finalResult, int left, string tempString)
{
    if(!leftPair && !rightPair)
    {
        finalResult.push_back(tempString);
        return ;
    }
    
    
    if(left)
   {
       if(rightPair)
       {
            tempString += ')';
            cout<<" CLOSE PAREN ADDED----"<<tempString<<endl;
            makeNewParens(leftPair, rightPair-1, finalResult, left-1, tempString);
            tempString.pop_back();
        }
   }
   if(leftPair)
   {
        tempString += '(';
        cout<<" OPEN PAREN ADDED----"<<tempString<<endl;
        makeNewParens(leftPair-1, rightPair, finalResult, left+1, tempString);
   }
}

int main()
{
    int pair;
    cin>>pair;
    cout<<endl;
    vector<string> finalResult;
    string tempString = "(";
    makeNewParens(pair-1, pair, finalResult, 1, tempString);

    
    for(int i=0; i<finalResult.size(); i++)
    {
        cout<<finalResult[i]<<endl;
    }
    
    return 0;
}
