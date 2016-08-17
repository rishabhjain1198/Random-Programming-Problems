

#include <iostream>

using namespace std;

bool result(int x, int y, int z)
{
    int gcd = 1;
    
    //CHECKING TRIVIAL CASE OF Z = 0
    if(z==0)
    {
        return 1;
    }
    
    //CHECKING IF X Y Z ARE EQUAL
    if(x==y){
        if(x==z){
            return 1;}}
    
    //CHECKING IF X or Y = 0
    else if(min(x,y) == 0)
    {
        if(max(x,y) == z)
        {
            return 1;
        }
    }
    
    
    else
    {
        // FINDING THE GCD OF X AND Y
        for(int i = 2; i <= min(x,y); i++)
        {
            if(min(x,y)%i == 0)
            {
                if(max(x,y)%i == 0)
                {
                    gcd = i;
                }
            }
            
        }
        
        cout<<gcd;
        //GCD FOUND
        
        if(z%gcd == 0 && z<=(x+y))
            return 1;
        else if(z%gcd == max(x,y) && z<=(x+y))
            return 1;
    }
        
    return 0;
  
}


int main() {
    
    int a,b,c;
    cout<<"Please enter the volume of first jug, volume of second jug, and water to be obtained, respectively\n";
    cin>>a; cin>>b; cin>>c;
    
    cout<<result(a,b,c);
    
    return 0;
}
