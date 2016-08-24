#include<iostream>

using namespace std;

void printit(long long int array [], long long int size)
{
	for(long long int i =0; i<size; i++)
	{
		cout<<array[i]<<" ";
	}
}

void reverseTraverseSquares(long long int Squares [], long long int sizeSquares, long long int bmaxy [], long long int pos, long long int currentValue, long long int prevValue)
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

void newTraverseSquares(long long int Squares[], long long int sizeSquares, long long int maxy [], long long int bmaxy [], long long int pos, long long int k)
{
    if(pos>=sizeSquares)
        return ;

    maxy[pos] = Squares[pos] + bmaxy[pos] - bmaxy[k] - Squares[k];
    newTraverseSquares(Squares, sizeSquares, maxy, bmaxy, pos+1, k);
}

int main()
{
    long long int sizeSquares, k;
    cin>>sizeSquares; cin>>k; k--;
    if(sizeSquares<=0)
    {cout<<"0"; return 0;}
    long long int Squares [sizeSquares], maxy [sizeSquares], bmaxy[sizeSquares];
    for(long long int i = 0; i<sizeSquares; i++)
    {
        bmaxy[i] = -999999999999999;
        cin>>Squares[i];
    }
    maxy[k] = 0;

    reverseTraverseSquares(Squares, sizeSquares, bmaxy, 0, 0, 0);

    newTraverseSquares(Squares, sizeSquares, maxy, bmaxy, k+1, k);
    
    long long int maxx = -99999999999;
    for(long long int i = k; i<sizeSquares; i++)
    {
        maxx = max(maxx, maxy[i] + bmaxy[i]);
    }

    cout<<maxx;
    return 0;
}
