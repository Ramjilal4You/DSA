// Find a pair with the given difference
/*
** Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n. 
Examples: 
    Input: arr[] = {5, 20, 3, 2, 50, 80}, n = 78
    Output: Pair Found: (2, 80)

    Input: arr[] = {90, 70, 20, 80, 50}, n = 45
    Output: No Such Pair
*/

/*
Approach 1. nested loop (brute force) -- O(n*n);
Approach 2. Sorted array -- O(nlogn); Hint: Traverse from Both ends
Approach 3. Hashing using temp array of diff*2 size;
*/

#include <iostream>
#include <algorithm>

using namespace std;

void FindPairWithGivenDifferenceUsingSortedArray(int arr[], int n, int d){

    sort(arr, arr+n);
    int l=0, r=1;
    while(l<=r && (l<n && r<n)){
        int diff = arr[r]-arr[l];
        if(diff==d){
            cout<<"pair found ( "<<arr[l]<<", "<<arr[r]<<" )\n\n";
            return;
        }

        if(diff > d){
            l++;
        }
        else    
            r++;
    }

    cout<<"Pair not found \n\n\n";
}
int main(){
    int arr[] = {90, 70, 20, 80, 50}, d = 45, n=sizeof(arr)/sizeof(arr[0]);


    FindPairWithGivenDifferenceUsingSortedArray(arr, n, d);

return 0;
}