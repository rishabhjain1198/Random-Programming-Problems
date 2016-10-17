#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include<vector>
int n,m, conty;
bool ya;
using namespace std;

class pos
{
    public:
    int x,y;
};

void traversal(vector<string> grid, pos c, int counter)
{
  
    if(grid[c.x][c.y] == 'S')
    {
        ya = 1;
        counter++;
        if(counter>conty)
            conty = counter;
        return;
    }
    if(c.x+1<n)
    {
    if(grid[c.x+1][c.y] == '.' && c.x+1<n)
    {
        pos temp; temp.x = c.x+1; temp.y = c.y;
        counter++;
        traversal(grid, temp, counter);
    }
    }
    if(c.y+1<m)
    {
           if(grid[c.x][c.y+1] == '.' && c.y+1<m)
    {
        pos temp; temp.x = c.x; temp.y = c.y+1;
        counter++;
        traversal(grid, temp, counter);
    }
    }
    if(c.y-1>=0)
    {
    if(grid[c.x][c.y-1] == '.' && c.y-1>=0)
    {
        pos temp; temp.x = c.x; temp.y = c.y-1;
        counter++;
        traversal(grid, temp, counter);
    }
    }
    if(c.x-1>=0)
    {
       if(grid[c.x-1][c.y] == '.')
    {
        pos temp; temp.x = c.x-1; temp.y = c.y;
        counter++;
        traversal(grid, temp, counter);
    }
    }




}


int main() {

    cin>>n; cin>>m; vector<string> grid; pos fen;
    for(int i = 0; i < n; i++)
    {
        string temp = "";
        cin>>temp;
        for(int j = 0; j < m; j++)
        {
            if(temp[j] == '*')
            {
                fen.x = i; fen.y = j;
            }
        }
        grid.push_back(temp);
        temp = "";
    }
    //INPUT DONE
    conty = 0;
    
    /////////TRAVERSAL////////
    traversal(grid, fen, 0);
    
    if(ya != 1)
    {
    cout<<"-1";
    }
    else
        cout<<conty;
    
 

    return 0;
}
