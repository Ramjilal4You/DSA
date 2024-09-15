/*
Q.Find a way to reach from point (A, B) to point (C, D), 
  Robot can move from (X, Y) to (X+Y, Y) or (X, Y+X).
  - If reached than print the path 
  - else print "can not reach"

    - reachable
        int a = 2, b = 3;
        int c = 12, d = 5;
    
    - Can not reach
        int a = 2, b = 3;
        int c = 12, d = 13;
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
    int a = 2, b = 3, c = 12, d = 5;
    //int a = 2, b = 3, c = 12, d = 13;

    stack<pair<int,int>>res;
    if(Navigate(a, b, c, d, res))
    {
        cout<<"\nReached\n\n";
        
        while(!res.empty())
        {   auto itr = res.top();
            res.pop();
            cout<<itr.first<<", "<<itr.second<<endl;
        }
        cout<<endl;
    }
    else
        cout<<"\nCan not reached\n\n";

    return 0;
}