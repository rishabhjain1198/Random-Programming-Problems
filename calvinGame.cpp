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
    if(currentValue+prevValue < bmaxy[pos])
        return ;

    currentValue += prevValue;
    bmaxy[pos] = currentValue;
    reverseTraverseSquares(Squares, sizeSquares, bmaxy, pos+1, currentValue, Squares[pos]);
    reverseTraverseSquares(Squares, sizeSquares, bmaxy, pos+2, currentValue, Squares[pos]);

}


void traverseSquares(long long int Squares [], long long int sizeSquares, long long int maxy [], long long int pos, long long int currentValue)
{
    if(pos>=sizeSquares)
        return ;
    if(currentValue+Squares[pos] < maxy[pos])
        return ;

    currentValue += Squares[pos];
    maxy[pos] = currentValue;
    traverseSquares(Squares, sizeSquares, maxy, pos+1, currentValue);
    traverseSquares(Squares, sizeSquares, maxy, pos+2, currentValue);
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
        if(i>k)
            maxy[i] = -99999999999999;
        else
            maxy[i] = 0;
        bmaxy[i] = -999999999999999;
        cin>>Squares[i];
    }
    //Input taken successfully and every element of maxy set to -9999
    //Updating maxy by traversing squares and implementing dp using maxy itself
    traverseSquares(Squares, sizeSquares,  maxy, k+1, 0);
    traverseSquares(Squares, sizeSquares,  maxy, k+2, 0);

    reverseTraverseSquares(Squares, sizeSquares, bmaxy, 0, 0, 0);
    
    long long int maxx = 0;
    for(long long int i = 0; i<sizeSquares; i++)
    {
        maxx = max(maxx, maxy[i] + bmaxy[i]);
    }

    cout<<maxx;
    return 0;
}
