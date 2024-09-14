/*
Q1.Robot can move 2 way only (X+Y, Y) or (X, Y+X) & you have to reach from (A, B) to (C, D)
	- Asked for schodo code only & approach
	- I explained with backtracking

*/

#include <iostream>
#include <stack>

using namespace std;

bool Navigate(int a, int b, int c, int d, stack<pair<int,int>>&res){
    if(a==c && b==d)
    {
        res.push({a,b});
        return true;
    }
    
    if(a>c || b>d)
        return false;
    
    bool reached = Navigate(a+b, b, c, d, res);
    
    if(reached==false)
        reached = Navigate(a, b+a, c, d, res);
    
    if(reached)
        res.push({a,b});
    
    return reached;
}

int main()
{
    stack<pair<int,int>>res;
    if(Navigate(2, 3, 19, 13, res))
    {
        cout<<"reached\n";
        
        while(!res.empty())
        {   auto itr = res.top();
            res.pop();
            cout<<itr.first<<", "<<itr.second<<endl;
        }
    }
    else
        cout<<"can not reached\n";

    return 0;
}