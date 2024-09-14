// Find the element before which all the elements are smaller than it, and after which all are greater
/*
** Given an array, find an element before which all elements are smaller than it, and after which all are greater than it. 
   Return the index of the element if there is such an element, otherwise, return -1.

Examples:
    Input: arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9}; 
    Output: 4 
    Explanation: All elements on left of arr[4] are smaller than it 
    and all elements on right are greater.

    Input: arr[] = {5, 1, 4, 4}; 
    Output: -1 
    Explanation : No such index exits.
*/
/*
** O(n*n) - using loop, check for each element
** O(n) - using leftMin array & traverse from right for each elemtn - extra space O(n)
*/

#include <iostream>
#include <stdio.h>

using namespace std;

// Function to return the index of the element which is greater than
// all left elements and smaller than all right elements.
void findElementUsingArray(int arr[], int n)
{
    // leftMax[i] stores maximum of arr[0..i-1]
    int *leftMax = new int[n];
    leftMax[0] = INT_MIN;
 
    // Fill leftMax[1..n-1]
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i-1], arr[i-1]);
 
    // Initialize minimum from right
    int rightMin = INT_MAX;
 
    // Traverse array from right
    for (int i=n-1; i>=0; i--)
    {
        // Check if we found a required element
        if (leftMax[i] < arr[i] && rightMin > arr[i]){
            printf("Element Found : %d\n\n",arr[i]);
            return;
        }
 
        // Update right minimum
        rightMin = min(rightMin, arr[i]);
    }
 
    // If there was no element matching criteria
    cout<<"Element Not Found\n\n";
}

int main(){
    //int arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9}; //output 6
    int arr[] = {4,5,8,7};   //output : not found
    int n = sizeof(arr)/sizeof(arr[0]);

    findElementUsingArray(arr, n);

return 0;
}