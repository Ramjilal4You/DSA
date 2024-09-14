// Print K largest(or smallest) elements in an array
/*
** Given an array arr[] of size N, the task is to printing K largest elements in an array.
** Note: Elements in output array can be in any order

Examples:
    Input:  [1, 23, 12, 9, 30, 2, 50], K = 3
    Output: 50, 30, 23

*/
/*
** 1. O(n*k) - nested loop - find max and mark it as visited k times
** 2. O(nlogn) - using sort - sort array and get k elements
** 3. O(nlogk) - Using priority_queue - insert element take log k time
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void kLargest(vector<int>arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int x:arr){
        pq.push(x); //take logk time

        if(pq.size()>k) //maintaine k elemens only in priority queue
        {
            pq.pop();   //take logk time
        }
    }

    //print k largest elements
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<"\n\n\n";
}

int main(){
    // Given array
    vector<int> arr = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };
    // Size of array
    int n = arr.size();
    int k = 3;
    cout << k << " largest elements are : ";
    kLargest(arr, n, k);
return 0;
}
