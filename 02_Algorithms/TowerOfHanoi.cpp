/*
** Tower of Hanoi - Iterative Approach
*/

/*  //Basic rules
*   1. find the total steps - pow(2,n)-1 : n is the number of disks
        Here i is the step number
    2. if i%3=1 Move disk between src & dst
    3. if i%3=2 Move disk between src & aux
    4. if i%3=0 Move disk between aux & dst

    Note:- if n is even then swap the dst & aux pole/stack
*/

#include <iostream>
#include<vector>
#include<stack>
#include<string>
#include<cmath>


using namespace std;

vector<string> names={"src","aux","dst"};
vector<stack<int>>stacks(3);

//print the stack data
void PopStackData(int st){
    cout<<"\n\n"<<names[st]<<" Stack data : \n";
    while(!stacks[st].empty()){
        cout<<stacks[st].top()<<" ";
        stacks[st].pop();
    }
}

//move the disk from one stack to another
void MoveDisk(int a, int b){
    if(stacks[b].empty() || (!stacks[a].empty() && stacks[a].top()<stacks[b].top())){
        int disk = stacks[a].top(); //take disk from 1st stack
        stacks[a].pop();    //from disk from 1st stack

        stacks[b].push(disk);   //push disk to 2nd stack

        cout<<"Disk "<<disk<<" Moved from "<<names[a]<<" to "<<names[b]<<endl;
    }
    else{
        MoveDisk(b, a);
    }
}

void TowerOfHanoi(int n){
    cout<<"Tower of hanoi for "<<n<<" disks\n";
    int src=0, aux=1, dst=2;

    //check if disk count is 0 or less
    if(n<=0)
        return;

    //fill the src stack
    for(int i=n;i>=1;i--){
        stacks[src].push(i);
    }

    //if number of disks is even
    if(n%2==0)
        swap(aux,dst);
    
    //number of steps
    int steps = pow(2,n)-1;

    //loop through all the steps
    for(int i=1;i<=steps;i++){
        if(i%3==1)
            MoveDisk(src, dst);
        else if(i%3==2)
            MoveDisk(src, aux);
        else
            MoveDisk(aux, dst);
    }
}

int main(){
    int n;  //number of disks
    cout<<"Please Enter number of disks : ";
    cin>>n;

    TowerOfHanoi(n);

    PopStackData(2);

return 0;
}