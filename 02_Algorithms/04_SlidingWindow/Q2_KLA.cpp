/*
Q2. Calculates the maximum number of items the robot can pick in exactly k steps from a row.
The robot can move left or right in each step. Given Robot position, k steps & items position array, 
    Input: Items = items[] = {9,0,0,0,1,7,2,4,0,0,9}, startPos = 5, k = 4

assumes the row of items is represented as an array of integers, where each integer denotes the number of items at that position. 
The robot starts at a specified position and can pick items up to k steps to the left or right. 
The goal is to determine the maximum number of items the robot can pick in exactly k steps.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxItemsInKSteps(const vector<int>& row, int start, int k) {
    int n = row.size();
    int maxItems = 0;

    // Iterate over all possible distances the robot can move to the left
    for (int leftMoves = 0; leftMoves <= k; ++leftMoves) {
        int rightMoves = k - leftMoves;
        
        // Calculate the starting position
        int leftPos = max(start - leftMoves, 0);
        int rightPos = min(start + rightMoves, n - 1);
        
        // Calculate the total number of items picked if we move leftMoves steps left
        // and rightMoves steps right
        int totalItems = 0;
        for (int i = leftPos; i <= rightPos; ++i) {
            totalItems += row[i];
        }
        
        // Update the maximum number of items
        maxItems = max(maxItems, totalItems);
    }

    return maxItems;
}

int main() {
    // Example row and parameters
    //vector<int> row = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    vector<int> row = {9, 0, 0, 0, 1, 7, 2, 4, 0, 0, 9};
    int start = 5;  // Starting position of the robot
    int k = 4;      // Maximum number of steps

    int result = maxItemsInKSteps(row, start, k);
    cout << "Maximum items picked: " << result << endl;

    return 0;
}
