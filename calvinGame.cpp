#include<iostream>

using namespace std;

void printit(int array [], int size)
{
	for(long long int i =0; i<size; i++)
	{
		cout<<array[i]<<" ";
	}
}

void reverseTraverseSquares(int Squares [], int sizeSquares, int bmaxy [], int pos, int currentValue, int prevValue)
{
    if(pos>=sizeSquares)
        return ;
    if(currentValue + prevValue <= bmaxy[pos])
        return ;

    currentValue += prevValue;
    bmaxy[pos] = currentValue;
    reverseTraverseSquares(Squares, sizeSquares, bmaxy, pos+1, currentValue, Squares[pos]);
    reverseTraverseSquares(Squares, sizeSquares, bmaxy, pos+2, currentValue, Squares[pos]);

}

void newTraverseSquares(int Squares[], int sizeSquares, int bmaxy [], int pos, int k)
{
    if(pos>=sizeSquares)
        return ;

    bmaxy[pos] += Squares[pos] + bmaxy[pos] - bmaxy[k] - Squares[k];
    newTraverseSquares(Squares, sizeSquares, bmaxy, pos+1, k);
}

int main()
{
    int sizeSquares, k;
    cin>>sizeSquares; cin>>k; k--;
    if(sizeSquares<=0 || k<0)
    {cout<<"0"; return 0;}
    int Squares [sizeSquares], bmaxy[sizeSquares];
    for(int i = 0; i<sizeSquares; i++)
    {
        bmaxy[i] = -99999999;
        cin>>Squares[i];
    }
    
    reverseTraverseSquares(Squares, sizeSquares, bmaxy, 0, 0, 0);
    printit(bmaxy, sizeSquares);
    cout<<endl;

    newTraverseSquares(Squares, sizeSquares, bmaxy, k+1, k);
    printit(bmaxy, sizeSquares);
    
    int maxx = -99999999;
    for(int i = k; i<sizeSquares; i++)
    {
        maxx = max(maxx, bmaxy[i]);
    }

    cout<<maxx;
    return 0;
}
