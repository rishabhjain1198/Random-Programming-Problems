#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

void traverseit(int right, int left, int pair, string &stackit, vector<string> &finalResult, int pos, string s)
{
	cout<<" YOYO FUNC EXE"<<endl<<s.length()<<" "<<pos<<endl;
	cout<<"LEFT: "<<left<<" RIGHT: "<<right<<" PAIR: "<<pair<<" POS: "<<pos<<endl;
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
				{finalResult.push_back(stackit); cout<<"donezo"<<endl;}
		}
	}
	//time to define the recursion
	else
	{
		if(s[pos] == '(')
		{
			if(left)
				{traverseit(right, --left, pair, stackit, finalResult, ++pos, s);}
			stackit += '(';
			cout<<" ADDED TOT EH FKIN STACK M8"<<endl;
			traverseit(right, left, ++pair, stackit, finalResult, ++pos, s);
		}
		
		else if(s[pos] == ')')
		{
			if(right)
				{traverseit(--right, left, pair, stackit, finalResult, ++pos, s);}
			stackit += ')';
			if(pair)
				{traverseit(right, left, --pair, stackit, finalResult, ++pos, s);}
		}
		else
		{
			stackit += s[pos];
			traverseit(right, left, pair, stackit, finalResult, ++pos, s);
		}
	}
}

vector<string> removeInvalidParenthesis(string s)
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
			cout<<"LEFT INCREMENETED"<<endl;
		}
		
		else if(s[i] == ')')
		{
			if(left)
			{
				left--;
				cout<<"LEFT DECRE"<<endl;
			}
			else
			{
				right++;
				cout<<"RIGHT INCRE"<<endl;
			}
		}
	}
	//Scan of string complete, now to call traversal of the string for DFS
	
	traverseit(right, left,  pair, stackit, finalResult, pos, s);	
	
	cout<<endl;
	for(int i = 0; i<finalResult.size(); i++)
	{
		cout<<finalResult[i]<<endl;
	}	
	return finalResult;

}


int main()
{
	removeInvalidParenthesis("()())()");
	return 0;
}
