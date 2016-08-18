#include<iostream>
#include<vector>

using namespace std;

vector<string> removeInvalidParenthesis(string s)
{
	vector<string> finalResult;
	finalResult.push_back(s);

	return finalResult;

}


int main()
{
	cout<<removeInvalidParenthesis("rekt")[0]<<endl;
	return 0;
}
