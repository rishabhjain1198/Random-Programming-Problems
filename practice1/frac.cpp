#include<iostream>
#include<vector>

using namespace std;

class fraction
{
    public:
    int num; int den; double value;
};

//WRITING QUICKSORT FUNCTION
void quickIt(vector<fraction> fractions, int left, int right)
{ 
	int i = left; int j = right; fraction tmp; 
	int pivot = fractions[(left+right)/2].value;

	while(i <= j)
	{ 
		while(fractions[i].value < pivot)
		{ 
			i++;
		}
		while(fractions[j].value>pivot)
		{ 
			j--;
		}
		if(i <= j)
		{ 
			tmp = fractions[i];
			fractions[i] = fractions[j];
			fractions[j] = tmp;
			i++; j--;
		}
	}	

	if(left < j)
		quickIt(fractions, left, j);
	if(i<right)
		quickIt(fractions, right, i);
}

//SHOWCASE CONTENTS OF VECTOR
void showFrac(vector<fraction> fractions)
{
    for(int i = 0; i < fractions.size(); i++)
    {
        cout<<"Num: "<<fractions[i].num<<"  Den: "<<fractions[i].den<<"  Value: "<<fractions[i].value<<endl;
    }
}

void showFrac(vector<fraction> fractions, string useless)
{
    for(int i = 0; i < fractions.size(); i++)
    {
        cout<<fractions[i].num<<"/"<<fractions[i].den<<endl;
    }
}

int main()
{
    int n; cin>>n; vector<fraction> fractions;
    while(n--)
    {
        int a; cin>>a; int b; cin.ignore(); cin>>b; double temp = double(a)/double(b); 
        fraction tempp; tempp.num = a; tempp.den = b; tempp.value = temp;
        fractions.push_back(tempp);
    }
    //INPUT RECIEVED SUCCESSFULLY
/*
    for(int i = 0; i < fractions.size(); i++)
    {
        for(int j = 0; j < fractions.size() - i - 1; j++)
        {
            if(fractions[j].value > fractions [j+1].value)
            {
                fraction temp = fractions[j]; fractions[j] = fractions[j+1]; fractions[j+1] = temp;
            }
            else if(fractions[j].value == fractions[j+1].value)
            {
                if(fractions[j].num > fractions[j+1].num)
                {
                    fraction temp = fractions[j]; fractions[j] = fractions[j+1]; fractions[j+1] = temp;
                }
            }
        }
    }
*/
    quickIt(fractions, 0, fractions.size()-1);
    showFrac(fractions, "proper");
    return 0;
}
