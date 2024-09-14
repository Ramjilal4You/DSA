//Sum of two elements whose sum is closest to zero
/*
** Given an integer array of N elements. You need to find the maximum sum of two elements such that sum is closest to zero.
** Note: In Case if we have two of more ways to form sum of two elements closest to zero return the maximum sum.

Example:
    Input: N = 3, arr[] = {-8 -66 -60}
    Output: -68
    Explanation: Sum of two elements closest to zero is -68 using numbers -60 and -8.
*/

#include <iostream>
#include <limits>   //INT_MAX
#include <algorithm>    //sort

using namespace std;

//O(n2) //brute force approach
void TwoNumberSumClosestToZeroUsingNestedLoop(int arr[], int n){
    int sum = INT_MAX, idx1=0, idx2=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(abs(sum) > abs(arr[i]+arr[j])){
                sum = arr[i]+arr[j];
                idx1 = i;
                idx2 = j;
            }
            //Note: In Case if we have two of more ways to form sum of two elements closest to zero return the maximum sum.
            else if(abs(sum) == abs(arr[i]+arr[j])){
                sum = max(sum,arr[i]+arr[j]);
                idx1 = i;
                idx2 = j;
            }
        }
    }

    cout<<"Sum closest to zero : "<<sum<<" ( "<<arr[idx1]<<", "<<arr[idx2]<<" )\n\n\n";
}

//O(nlogn) //sorting approach
void TwoNumberSumClosestToZeroUsingSorting(int arr[], int n){
    sort(arr, arr+n);
    int l=0, r=n-1, sum=INT_MAX, idx1=0, idx2=0;
    while(l<r){
        if(abs(sum)>abs(arr[l]+arr[r])){
            sum = arr[l]+arr[r];
            idx1 = l;
            idx2 = r;
        }
        //Note: In Case if we have two of more ways to form sum of two elements closest to zero return the maximum sum.
        else if(abs(sum) == abs(arr[l]+arr[r])){
            sum = max(sum,arr[l]+arr[r]);
            idx1 = l;
            idx2 = r;
        }
        
        if(arr[l]+arr[r] > 0)
            r--;
        else    
            l++;
    }

    cout<<"Sum closest to zero : "<<sum<<" ( "<<arr[idx1]<<", "<<arr[idx2]<<" )\n\n\n";
}


int main(){

    int arr[] = {-8, -66, -60, 134};
    int n = sizeof(arr)/sizeof(arr[0]);

    TwoNumberSumClosestToZeroUsingNestedLoop(arr, n);

    TwoNumberSumClosestToZeroUsingSorting(arr, n);

return 0;
}