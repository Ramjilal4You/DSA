//Count number of occurrences (or frequency) in a sorted array
/*
Input: N = 7, X = 2, Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the given array.
*/

#include <iostream>

using namespace std;

//O(n) - using loop
void CountNumberOfOccurrencesUsingLoop(int* arr, int n, int x){
    
    int f=-1,l=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            if(f==-1){
                f=i;
                l=i;
            }
            else
                l=i;
        }
    }
    if(f==-1){
        cout<<"element not found in array.\n\n";
        return;
    }
    cout<<"Count of "<<x<<" : "<<l-f+1<<"\n\n\n";
}

#include "01_CountNumberOfOccurrences.hxx" 
//FirstOccurrencesUsingBinarySearch() & LastOccurrencesUsingBinarySearch();

//O(logn) - using binary search
int CountNumberOfOccurrencesUsingBinarySearch(int* arr, int n, int x){
    int f = FirstOccurrencesUsingBinarySearch(arr, n, x);
    if( f == -1){
        cout<<"element not found in array.\n\n";
        return -1;
    }

    int l = LastOccurrencesUsingBinarySearch(arr, n, x); 
    //cout<<"Count of "<<x<<" : "<<l-f+1<<"\n\n\n";
    return l-f+1;   //return count of element in array
}

int FirstOccurrencesUsingBinarySearch(int* arr, int n, int x){
    int l=0, r=n-1, mid;
    while(l<=r){
        mid = l+(r-l)/2;

        if(mid==0||arr[mid]==x && arr[mid-1]<x){
            return mid;
        }

        if(arr[mid]<x){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}

int LastOccurrencesUsingBinarySearch(int* arr, int n, int x){
    int l=0, r=n-1, mid;
    while(l<=r){
        mid = l+(r-l)/2;

        if(mid==n-1||arr[mid]==x && arr[mid+1]>x){
            return mid;
        }

        if(arr[mid]>x){
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}


// int main(){
//     int arr[] = {1, 1, 2, 2, 2, 2, 3};
//     int X = 3, N = sizeof(arr)/sizeof(arr[0]);

//     //CountNumberOfOccurrencesUsingLoop(arr, N, X);

//     CountNumberOfOccurrencesUsingBinarySearch(arr, N, X);

// return 0;
// }