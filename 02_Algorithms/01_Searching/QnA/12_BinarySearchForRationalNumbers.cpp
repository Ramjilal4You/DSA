// Binary Search for Rational Numbers without using floating point arithmetic
/*
** A rational is represented as p/qb, for example 2/3. Given a sorted array of rational numbers, 
   how to search an element using Binary Search. Use of floating-point arithmetic is not allowed.

Example:  
    Input:  arr[] = {1/5, 2/3, 3/2, 13/2}
            x = 3/2
    Output: Found at index 2
*/

// C++ program for Binary Search for 
// Rational Numbers without using
// floating point arithmetic
#include <iostream>
using namespace std;

struct Rational
{
	int p;
	int q;
};

// Utility function to compare two Rational numbers 'a' and 'b'.
// It returns
//  0 --> When 'a' and 'b' are same
//  1 --> When 'a' is greater
//  -1 --> When 'b' is greater
int compare(struct Rational a, struct Rational b){
	// If a/b == c/d then a*d = b*c: method to ignore division
	if (a.p * b.q == a.q * b.p)
		return 0;
	if (a.p * b.q > a.q * b.p)
		return 1;
		
	return -1;
}

// Returns index of x in arr[l..r] if it is present, else returns -1. It mainly uses Binary Search.
int binarySearch(struct Rational arr[], int l, int r, struct Rational x){
	if (l<=r)
	{
		int mid = l + (r - l) / 2;
		
		// If the element is present at the middle itself
		if (compare(arr[mid], x) == 0) 
			return mid;
		
		// If element is smaller than mid, then it can only be present in left subarray
		if (compare(arr[mid], x) > 0)
			return binarySearch(arr, l, mid - 1, x);
		
		// Else the element can only be present in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}

int main()
{
	Rational arr[] = { { 1, 5 }, { 2, 3 }, { 3, 2 }, { 13, 2 } };
	Rational x = { 3, 2 };
	
	int n = sizeof(arr) / sizeof(arr[0]);
	
	cout << "Element found at index " << binarySearch(arr, 0, n - 1, x);
}
