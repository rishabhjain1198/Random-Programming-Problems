//Solution for Leetcode Problem: Generate Parenthesis
//To view more of my competitive programming solutions, visit http://github.com/rishabhjain1198
//
//Input single positive integer to output all possible valid parenthesis strings of that number of pairs

#include<iostream>
#include<vector>

using namespace std;

void makeNewParens(int leftPair, int rightPair, vector<string> &finalResult, int left, string tempString)
{
    if(!leftPair && !rightPair)
    {
        finalResult.push_back(tempString);
        cout<<tempString<<endl;
        return ;
    }
    
    
    if(left)
   {
       if(rightPair)
       {
            tempString += ')';
            makeNewParens(leftPair, rightPair-1, finalResult, left-1, tempString);
            tempString.pop_back();
        }
   }
   if(leftPair)
   {
        tempString += '(';
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

    //Uncomment this block to display and confirm contents of finalResult vector
    /*
    for(int i=0; i<finalResult.size(); i++)
    {
		cout << finalResult[i] << endl;
    }
    */
    
    return 0;
}
