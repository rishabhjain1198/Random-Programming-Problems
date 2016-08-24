#include<iostream>

using namespace std;

void printit(int array [], int size)
{
	for(int i =0; i<size; i++)
	{
		cout<<array[i]<<" ";
	}
}

void reverseTraverseSquares(int Squares [], int sizeSquares, int bmaxy [], int pos, int currentValue, int prevValue)
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


void traverseSquares(int Squares [], int sizeSquares, int maxy [], int pos, int currentValue)
{
    if(pos>=sizeSquares)
        return ;
    if(currentValue+Squares[pos] < maxy[pos])
        return ;

    maxy[pos] = currentValue + Squares[pos];
    traverseSquares(Squares, sizeSquares, maxy, pos+1, currentValue + Squares[pos]);
    traverseSquares(Squares, sizeSquares, maxy, pos+2, currentValue + Squares[pos]);
}



int main()
{
    int sizeSquares, k;
    cin>>sizeSquares; cin>>k; k--;
    if(!sizeSquares)
    {cout<<"0"; return 0;}
    int Squares [sizeSquares], maxy [sizeSquares], bmaxy[sizeSquares];
    for(int i = 0; i<sizeSquares; i++)
    {
        maxy[i] = -999999999 ? i>k : maxy[i] = 0;
        bmaxy[i] = -999999999;
        cin>>Squares[i];
    }
    //Input taken successfully and every element of maxy set to -9999
    bmaxy[0] = 0;

    //Updating maxy by traversing squares and implementing dp using maxy itself
    traverseSquares(Squares, sizeSquares,  maxy, k+1, 0);
    traverseSquares(Squares, sizeSquares,  maxy, k+2, 0);

    reverseTraverseSquares(Squares, sizeSquares, bmaxy, 0, 0, 0);
    
    int maxx = 0;
    for(int i = 0; i<sizeSquares; i++)
    {
        maxx = max(maxx, maxy[i] + bmaxy[i]);
    }

    cout<<maxx;
    return 0;
}
