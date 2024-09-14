// Kth smallest element in a row-wise and column-wise sorted 2D array
/*
** Given an n x n matrix, where every row and column is sorted in non-decreasing order. 
** Find the kth smallest element in the given 2D array.

Example:
    Input:k = 3 and array =
    10, 20, 30, 40
    15, 25, 35, 45
    24, 29, 37, 48
    32, 33, 39, 50
    Output: 20
    Explanation: The 3rd smallest element is 20
*/
/*
    1. O((n*n)*(n*n))brute force - find max & mark it visited(INT_MIN)
    2. O(n*n log(n*n)) - take into 1D temp array & sorting
    3. O(n*n log(n*n)) - priority queue
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define N 4
int kthSmallest(int arr[N][N], int n, int k ){
    // Create a min-heap (priority queue) to store elements
    // in sorted order
    priority_queue<int, vector<int>, greater<int> > pq;

    // Add all elements of the 2D array to the min-heap
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pq.push(arr[i][j]);
        }
    }

    int c = 0;
    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();
        c++;

        if (c == k)
            return temp;
    }

    // If kth smallest element not found, return -1
    return -1;

}


int main(){
    int mat[N][N] = { { 10, 20, 30, 40 },
                   { 15, 25, 35, 45 },
                   { 25, 29, 37, 48 },
                   { 32, 33, 39, 50 } };
  int res = kthSmallest(mat, 4, 7);

  cout <<  "7th smallest element is " << res;
  return 0;
}