#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
void showClothes(vector<int> clothes)
{
    cout<<endl;
    for(int i = 0; i < n; i++)
    {
        cout<<clothes[i];
    }
}

bool compar(int i, int j)
{
    return (i>j);
}

void decrementClothes(vector<int> &clothes, int position)
{
    for(int i = position+1; i<n; i++)
    {
        clothes[i]--;
    }
}

int main()
{
    cin >> n; int k;
    vector<int> clothes;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        clothes.push_back(temp);
    }
    cin>>k;
    //INPUT TAKEN SUCCESSFULLY
    sort(clothes.begin(), clothes.begin()+n, compar);
    int totalTime = 0; int position = 0;

    while(clothes[position] > 0)
    {
         decrementClothes(clothes, position);
        clothes[position] -= k;
            sort(clothes.begin(), clothes.begin()+n, compar);
            totalTime++;
    }
    cout<<totalTime;
    return 0;
}

