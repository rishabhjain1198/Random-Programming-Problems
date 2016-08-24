#include<iostream>

using namespace std;

void traverseSquares(int Squares [], int sizeSquares, int maxy [], int pos, int currentValue)
{
    if(pos>=sizeSquares)
        return ;

    if(currentValue+Squares[pos] <= maxy[pos])
        return ;

    currentValue += Squares[pos];
    maxy[pos] = currentValue;
    traverseSquares(Squares, sizeSquares, maxy, pos+1, currentValue);
    traverseSquares(Squares, sizeSquares, maxy, pos+2, currentValue);
}

int findMax(int maxy [], int sizeSquares, int &j)
{
   int maxx = -9999;
   for(int i = 0; i<sizeSquares; i++)
   {
        if(maxy[i] > maxx)
        {maxx = maxy[i];
            j = i;}
   }
   return maxx;
}

void reverseTraverseSquares(int Squares [], int sizeSquares, int maxy [], int pos, int currentValue)
{
    if(pos<0)
        return ;

    if(currentValue+Squares[pos] <= maxy[pos])
        return ;

    currentValue += Squares[pos];
    maxy[pos] = currentValue;
    reverseTraverseSquares(Squares, sizeSquares, maxy, pos-1, currentValue);
    reverseTraverseSquares(Squares, sizeSquares, maxy, pos-2, currentValue);
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
        maxy[i] = -9999;
        bmaxy[i] = -9999;
        cin>>Squares[i];
    }
    //Input taken successfully and every element of maxy set to -9999

    //Updating maxy by traversing squares and implementing dp using maxy itself
    traverseSquares(Squares, sizeSquares,  maxy, k+1, 0);
    traverseSquares(Squares, sizeSquares, maxy, k+2, 0);

    int j;
    int maxx1 = findMax(maxy, sizeSquares, j);
    //start reverse traversal of update of maxy
    reverseTraverseSquares(Squares, sizeSquares, bmaxy, j-1, 0);
    reverseTraverseSquares(Squares, sizeSquares, bmaxy, j-2, 0);


    cout<<maxx1+bmaxy[0];
    return 0;
}
