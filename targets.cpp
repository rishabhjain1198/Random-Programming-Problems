#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class rectangle
{
    public:
    int x1, y1, x2, y2;
};

class circle
{
    public:
    int x,y,r;
};

int main()
{
    vector<rectangle> rectangles;
    vector<circle> circles;

    int m; cin>>m;
    while(m--)
    {
        string s; cin>>s; 
        if(s=="rectangle")
        {
            rectangle temp;
            cin>>temp.x1; cin>>temp.y1; cin>>temp.x2; cin>>temp.y2;
            rectangles.push_back(temp);
        }
        else
        {
            circle temp;
            cin>>temp.x; cin>>temp.y; cin>>temp.r;
            circles.push_back(temp);
        }
    }

    int n; cin>>n;
    while(n--)
    {
        int x, y; cin>>x; cin>>y;
        //RECTANGLE CHECKER
        int counter = 0;
        for(int i = 0; i < rectangles.size(); i++)
        {
            if(x>=rectangles[i].x1 && x<=rectangles[i].x2 && y>=rectangles[i].y1 && y<=rectangles[i].y2)
            {
                counter++;
                cout<<"rectangles: x1: "<<rectangles[i].x1<<" y1: "<<rectangles[i].y1<<"   x2: "<<rectangles[i].x2<<" y2: "<<rectangles[i].y2<<endl;
            }
       }

        //CIRCLE CHECKER

        for(int i = 0; i < circles.size(); i++)
        {
            if( (pow(double(x-circles[i].x),double(2)) + pow(double(y-circles[i].y),double(2)) )< pow(double(circles[i].r), double(2)))
            {
                counter++;
                cout<<endl<<"circles:  x: "<<circles[i].x<<" y: "<<circles[i].y<<" R: "<<circles[i].r;
            }
        }

        cout<<endl<<counter<<endl;

    }
    return 0;
}
