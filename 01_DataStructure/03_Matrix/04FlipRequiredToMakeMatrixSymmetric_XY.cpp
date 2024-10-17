/*
To make a grid symmetric, you can consider either horizontal symmetry, vertical symmetry, or both. 
We'll assume you want to make the grid symmetric along both axes (a full reflectional symmetry) unless specified otherwise.

Given an n x n grid, each cell should match its corresponding cell in the opposite quadrant after flipping along the horizontal and vertical axes.

To make the grid symmetric, the idea is to iterate over each cell and compare it with its mirrored counterparts in terms of both axes. 
If they don't match, you will need to flip some of them, and we count how many moves (flips) are required.
*/


#include <iostream>
#include <vector>

using namespace std;

// Function to return the minimum moves to make the grid symmetric
int minMovesToSymmetry(vector<vector<char>>& grid, int n) {
    int moves = 0;
    if(n<2)
        return moves;

    // Iterate through the top-left quadrant (including center for odd n)
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            // Get the four symmetric positions
            char topLeft = grid[i][j];
            char topRight = grid[i][n - j - 1];
            char bottomLeft = grid[n - i - 1][j];
            char bottomRight = grid[n - i - 1][n - j - 1];

            // Count the number of black cells in the four positions
            int blackCells = (topLeft == 'B') + (topRight == 'B') + (bottomLeft == 'B') + (bottomRight == 'B');

            // We need to make all four cells the same, so we flip to either 'B' or 'W'
            // The best option is to flip the fewest number of cells to get all four matching.
            // If 2 or more are black, we make all black; otherwise, make all white.
            moves += min(blackCells, 4 - blackCells);
        }
    }

    //horizontal & vertical center row & column
    if(n%2!=0){
        // Get the four symmetric positions
        char top = grid[0][n/2];
        char bottom = grid[n-1][n/2];
        char left = grid[n/2][0];
        char right = grid[n/2][n-1];

        // Count the number of black cells in the four positions
        int blackCells = (top != bottom) + (left != right );
        moves += blackCells;

    }
    return moves;
}

int main() {
    int n;
    cout << "Enter the size of the grid (n x n): ";
    cin >> n;
    
    vector<vector<char>> grid(n, vector<char>(n));

    cout << "Enter the grid (B for Black, W for White):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = minMovesToSymmetry(grid, n);
    cout << "Minimum moves to make the grid symmetric: " << result << endl;

    return 0;
}
