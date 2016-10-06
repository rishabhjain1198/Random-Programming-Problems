#include<iostream>

using namespace std;

int main()
{
    long long int w, h, n; cin>>w; cin>>h; cin>>n;
    long long int height = 0, width = 0;

    for(int i = 1; i <= n; i++)
    {
        if(height+h>width+w)
        {
            width += w;
        }

        else
        {
            height += h;
        }

        if(i != (height*width)/(h*w))
        {
            i = (height*width)/(h*w);
        }
    }

    if(width>height)
	    cout<<width;
    else
	    cout<<height;
    
    return 0;
}
