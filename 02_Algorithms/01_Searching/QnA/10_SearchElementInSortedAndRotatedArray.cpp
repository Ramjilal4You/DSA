// Search an element in a sorted and rotated Array
/*
** Given a sorted and rotated array arr[] of n distinct elements, the task is to find the index of given 
   target element in the array. If target is not present in the array, return -1.

Example:  
    Input  : arr[] = {4, 5, 6, 7, 0, 1, 2}, target = 0
    Output : 4

    Input  : arr[] = { 4, 5, 6, 7, 0, 1, 2 }, target = 3
    Output : -1

    Input : arr[] = {30, 40, 50, 10, 20}, target = 10   
    Output : 3
*/
/*
** O(n) - search in linear way
** O(logn) - binary search with twick
*/

#include <iostream>
using namespace std;

void findElement(int arr[], int n, int target){
    int l=0, r=n-1;

    while(l<=r){
        int mid = (l+r)/2;
        
        if(arr[mid]==target){
            cout<<"\nElement Found at "<<mid<<" index\n\n\n";
            return;
        }

        if(arr[mid]>target){
            if(arr[l]>target)
                l=mid+1;
            else    
                r=mid-1;
        }
        else{
            if(arr[l]<target)
                l=mid+1;
            else    
                r=mid-1;
        }
    }
    cout<<"\nElement not Found !\n\n\n";
}
int main(){
    //int arr[] = {4, 5, 6, 7, 0, 1, 2}, target = 0;
    //int arr[] = { 4, 5, 6, 7, 0, 1, 2 }, target = 3;
    int arr[] = {30, 40, 50, 10, 20}, target = 20;
    int n = sizeof(arr)/sizeof(arr[0]);

    findElement(arr, n, target);
return 0;
}