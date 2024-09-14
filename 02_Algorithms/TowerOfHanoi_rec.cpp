/*
** Tower of hanoi - Recursive approach
*/

#include<iostream>


using namespace std;

//for 3 rods
void TowerOfHanoiRec(int n, string src, string dst, string aux){
    if(n<=0)
        return;
    
    //call recursively TowerOfHanoiRec
    TowerOfHanoiRec(n-1, src, aux, dst);    //swap the dst & aux
    cout<<"Move disk "<< n <<" from "<<src<<" to "<<dst<<endl;

    TowerOfHanoiRec(n-1, aux, dst, src); //rotate the rods clock wise (forward by 1)
}

//if we have 4 rods
void TowerOfHanoiRec4(int n, string src, string dst, string aux1, string aux2){
    if(n<=0)
        return;

    //call recursively TowerOfHanoiRec4
    TowerOfHanoiRec4(n-1, src, aux1, dst, aux2);    //swap the dst & aux
    cout<<"Move disk "<< n <<" from "<<src<<" to "<<dst<<endl;

    TowerOfHanoiRec4(n-1, aux1, dst, aux2, src);    //rotate the rods(prev. call args) forward by 1
}

//if we have 5 rods
void TowerOfHanoiRec5(int n, string src, string dst, string aux1, string aux2, string aux3){
    if(n<=0)
        return;

    //call recursively TowerOfHanoiRec5
    TowerOfHanoiRec5(n-1, src, aux1, dst, aux2, aux3);    //swap the dst & aux
    cout<<"Move disk "<< n <<" from "<<src<<" to "<<dst<<endl;

    TowerOfHanoiRec5(n-1, aux1, dst, aux2, aux3, src);    //rotate the rods(prev. call args) clock wise (forward by 1)
}

int main(){
    cout<<"\nPlease enter number of disks : ";
    int n;
    cin>>n; //taking input from console

    //src - A, dst - C, aux - B
    //TowerOfHanoiRec(n, "A", "C", "B");

    //TowerOfHanoiRec4(n, "A", "D", "B", "C");  //4rods

    TowerOfHanoiRec5(n, "A", "E", "B", "C", "D"); //5rods

return 0;
}