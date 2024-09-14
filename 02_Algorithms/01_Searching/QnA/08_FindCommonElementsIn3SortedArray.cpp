// Find common elements in three sorted arrays
/*
** Given three sorted arrays in non-decreasing order, print all common elements in these arrays.
** Note: In case of duplicate common elements, print only once.

Examples: 
    Input: A[] = {1, 5, 10, 20, 30} , B[] = {5, 13, 15, 20}, C[] = {5, 20} 
    Output: 5 20
    Explanation: 5 and 20 are common in all the arrays.
*/
/*
** 1. O(n1+n2+n3) - use hashing - take array of max element (in all 3array) size
** 2. O(max(n1,n2,n3)) - using loop
*/

#include <iostream>

using namespace std;

void PrintCommonElements(int A[], int B[], int C[], int n1, int n2, int n3){
    int i=0, j=0, k=0;
    while(i<n1 && j<n2 && k<n3){
        if(A[i]==B[j] && B[j]==C[k]){
            cout<<A[i]<<" ";
            i++, j++, k++;
        }

        if(A[i]>B[j])
            j++;
        else if(A[i]<B[j])
            i++;
        
        if(B[j]>C[k])
            k++;
        else if(B[j]<C[k])
            j++;
    }
}

int main(){
    int A[] = {1, 5, 10, 20, 30} , B[] = {5, 13, 15, 20}, C[] = {5, 15, 20, 30};
    int n1 = sizeof(A)/sizeof(A[0]), n2 = sizeof(B)/sizeof(B[0]), n3 = sizeof(C)/sizeof(C[0]); 

    PrintCommonElements(A, B, C, n1, n2, n3);

return 0;
}