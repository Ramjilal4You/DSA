//Find three closest elements from given three sorted arrays
/*
** Given three sorted arrays A[], B[] and C[], find 3 elements i, j and k from A, B and C respectively such that 
   max(abs(A[i] – B[j]), abs(B[j] – C[k]), abs(C[k] – A[i])) is minimized. Here abs() indicates absolute value.

Example : 
    Input : A[] = {1, 4, 10}
            B[] = {2, 15, 20}
            C[] = {10, 12}

    Output: 10 15 10
    Explanation: 10 from A, 15 from B and 10 from C
*/
/*
    O(p*q*r) : 3 nested loop
        int curr=max(abs(A[i]-B[j]),abs(B[j]-C[k]));
                int temp=max(curr,abs(C[k]-A[i]));
                //If that is minimum than previous then update answer
                if(temp<ans){
                    ans=temp;
                    a=A[i];
                    b=B[j];
                    c=C[k];
                }
    O(p+q+r) : 3 pointer approach
*/

// C++ program to find 3 elements such that max(abs(A[i]-B[j]), abs(B[j]-
// C[k]), abs(C[k]-A[i])) is minimized.

#include<iostream>
#include<algorithm>
using namespace std;

void findClosest(int A[], int B[], int C[], int p, int q, int r)
{

	int diff = INT_MAX; // Initialize min diff

	int res_i =0, res_j = 0, res_k = 0; // Initialize result

	// Traverse arrays
	int i=0,j=0,k=0;
	while (i < p && j < q && k < r)
	{
		// Find minimum and maximum of current three elements
		int minimum = min(A[i], min(B[j], C[k]));
		int maximum = max(A[i], max(B[j], C[k]));

		// Update result if current diff is less than the min
		// diff so far
		if (maximum-minimum < diff)
		{
			res_i = i, res_j = j, res_k = k;
			diff = maximum - minimum;
		}

		if (diff == 0) break;   // We can't get less than 0 as values are absolute

		// Increment index of array with smallest value
		if (A[i] == minimum) i++;
		else if (B[j] == minimum) j++;
		else k++;
	}

	// Print result
	cout << A[res_i] << " " << B[res_j] << " " << C[res_k];
}

// Driver program
int main()
{
	int A[] = {1, 4, 10};
	int B[] = {2, 15, 20};
	int C[] = {10, 12};

	int p = sizeof A / sizeof A[0];
	int q = sizeof B / sizeof B[0];
	int r = sizeof C / sizeof C[0];

	findClosest(A, B, C, p, q, r);
	return 0;
}
