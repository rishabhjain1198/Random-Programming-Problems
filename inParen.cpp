#include<iostream>
#include<cstring>
#include<vector>

using namespace std;


void traverseit(int right, int left, int pair, string stackit, vector<string> &finalResult, int pos, string s)
{
	//check if the recursion is at the end of its life
	if(pos >= s.length())
	{
		if(!left && !right && !pair)
		{
			//checking for duplicates
			int j = 1;
			for(int i=0; i<finalResult.size(); i++)
			{
				if(!stackit.compare(finalResult[i]))
					j = 0;
			}
			
			if(j)
				{finalResult.push_back(stackit);}
		}
        return ;
	}
	//time to define the recursion
	else
	{
		if(s[pos] == '(')
		{
			if(left)
				{traverseit(right, left-1, pair, stackit, finalResult, pos+1, s);}
			stackit += '(';
			
			traverseit(right, left, pair+1, stackit, finalResult, pos+1, s);
		}
		
		else if(s[pos] == ')')
		{
			if(right)
				{traverseit(right-1, left, pair, stackit, finalResult, pos+1, s);}
			if(pair)
				{
                    stackit += ')';
              
                    traverseit(right, left, pair-1, stackit, finalResult, pos+1, s);}
		}
		else
		{
			stackit += s[pos];
			traverseit(right, left, pair, stackit, finalResult, pos+1, s);
		}
	}
}

vector<string> removeInvalidParentheses(string s)
{	
	//Initialize the variables
	vector<string> finalResult;
	string stackit;
	int left = 0, right = 0, pair = 0, pos = 0;

	//Scann every single character of the string
	for(int i = 0; i<s.length(); i++)
	{
		if(s[i] == '(')
		{
			left++;
			
		}
		
		else if(s[i] == ')')
		{
			if(left)
			{
				left--;
			}
			else
			{
				right++;
			}
		}
	}
	//Scan of string complete, now to call traversal of the string for DFS
	
	traverseit(right, left,  pair, stackit, finalResult, pos, s);	
	
    for(int i=0; i<finalResult.size(); i++)
    {
        cout<<finalResult[i]<<endl;
    }

	return finalResult;

}

int main()
{
    string s;
    cin>>s;

    removeInvalidParentheses(s);

    return 0;
}
