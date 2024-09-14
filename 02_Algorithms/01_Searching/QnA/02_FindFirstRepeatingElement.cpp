//Q. Find the first repeating element in an array of integers - 4 Approaches
/*
Input: arr[] = {10, 5, 3, 4, 3, 5, 6}
Output: 5 
Explanation: 5 is the first element that repeats
*/

#include <iostream>
#include <algorithm>    //std::sort
#include <unordered_set>
#include "01_CountNumberOfOccurrences.hxx" //CountNumberOfOccurrencesUsingBinarySearch()

using namespace std;

//O(n*n)
void FindFirstRepeatingElementLoop(int* arr, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                cout<<"First Repeating Element : "<<arr[i]<<"\n\n\n\n";
                return;
            }
        }
    }
}


//O(nlogn) -- using sorting 
void FindFirstRepeatingElementUsingSorting(int* arr, int n){
    int *temp = new int[n];
    copy_n(arr, n, temp);   //copy to temp array

    sort(temp, temp+n); //sort temp array

    for(int i=0; i<n; i++){
        int OccCount;
        //OccCount = CountNumberOfOccurrencesUsingBinarySearch(temp, n, arr[i]);
        
        if(OccCount>1){
            cout<<"\nFirst Repeating Element : "<<arr[i]<<"\n\n\n\n";
            return;
        }
    }

    cout<<"Repeating Element not found\n\n\n\n";
}

//O(n) -- using hashing(array)
void FindFirstRepeatingElementUsingHashArray(int* arr, int n){
    int max=-1;
    for_each(arr, arr+n, [&](int x){if(max<x){max=x;};});   //find max element;

    int *temp = new int[max+1];   //memory allocation to temp array;

    for(int i=0; i<max+1; i++)  //reset all value to 0;
    {
        temp[i]=0;
    }

    for_each(arr, arr+n, [&](int x){temp[x]++;});   //update hash array with occurenes

    for(int i=0;i<max+1; i++){ 
        if(temp[arr[i]]>1){
            cout<<"\nFirst Repeating Element : "<<arr[i]<<"\n\n\n\n";
            return;
        }
    }  
}

//O(n) -- using hashing(unordered_set)
void FindFirstRepeatingElementUsingHashSet(int* arr, int n){
    unordered_set<int>st;
    int minIndex=INT_MAX;
    for(int i=n-1;i>=0; i--){ 

        if(st.find(arr[i])!=st.end())   //element already there
        {
            minIndex=i;
        }
        else{
            st.insert(arr[i]);
        }
    }

    if(minIndex != INT_MAX){
        cout<<"\nFirst Repeating Element : "<<arr[minIndex]<<"\n\n\n\n";
    }
    else{
        cout<<"Repeating Element not found\n\n\n\n";
    }
}
int main(){
    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    //FindFirstRepeatingElementLoop(arr, n);

    //FindFirstRepeatingElementUsingSorting(arr, n);

    //FindFirstRepeatingElementUsingHashArray(arr,n);

    FindFirstRepeatingElementUsingHashSet(arr,n);
    
    
return 0;
}