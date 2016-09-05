#include<iostream>
#include<vector>

using namespace std;

class soldier
{
    public:
        soldier* leftNode;
        soldier* rightNode;
        int value;
};

int findDepth(soldier* depthy, char comm)
{
    int depth = 0;
    if(comm == 'l')
    {
        while(depthy->value)
        {
            depth++;
            depthy = depthy->leftNode;
        }
        return depth;
    }

    while(depthy->value)
    {
        depth++;
        depthy = depthy->rightNode;
    }
    //execute right tree depth search

    return depth;
}

void printit(soldier* asli)
{
    if(!asli->value)
        return ;
    printit(asli->leftNode);
    cout<<asli->value<<" ";
    printit(asli->rightNode);
}

void placeitt(soldier* asli, int position, int stepsy)
{
    if(!asli->value)
    {
        asli->value = position;
        asli->leftNode = new soldier;
        asli->rightNode = new soldier;
        asli->leftNode->value = 0; 
        asli->rightNode->value = 0;
        return ;
    }

    if(stepsy < findDepth(asli, 'r'))
        placeitt(asli->rightNode, position, ++stepsy);
    else
        placeitt(asli->leftNode, position, --stepsy);
}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n; cin>>n;
        soldier* asli = new soldier;
        asli->value = 0;
        asli->leftNode = new soldier;
        asli->rightNode = new soldier;
        int omfg;
        for(int i = 1; i<=n; i++)
        {
            cin>>omfg;
            placeitt(asli, i, omfg);
        }
        printit(asli);
    }
    return 0;
}

