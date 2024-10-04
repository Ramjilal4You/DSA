
//https://www.geeksforgeeks.org/min-cost-path-dp-6/

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* The data structure to store the coordinates
   of the unit square and the cost of path from the top left. */
struct Cell {
    int x;
    int y;
    int cost;
};

/* The compare class to be used by a Min Heap.
 * The greater than condition is used as this
   is for a Min Heap based on priority_queue. */
class mycomparison {
public:
    bool operator()(const Cell& lhs, const Cell& rhs) const {
        return (lhs.cost > rhs.cost);
    }
};

/* To verify whether a move is within the boundary. */
bool isSafe(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

/* This solution is based on Dijkstra’s shortest
   path algorithm */
int minCost(vector<vector<int>>& cost, int m, int n) {
    int rows = cost.size();
    int cols = cost[0].size();

    /* the array to store the accumulated cost of path
       from top left corner */
    vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));

    /* the array to record whether a unit square has been visited */
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    /* Define a reverse priority queue. Priority queue is a Max heap based implementation.
     * The default behavior of a priority queue is
        to have the maximum element at the top.
     * The compare class is used in the definition of the
     Min Heap.  */
    priority_queue<Cell, vector<Cell>, mycomparison> pq;

    /* 4 possible moves */
    int dx[4] = { -1, 1,  0, 0 };
    int dy[4] = {  0, 0, -1, 1 };

    /* initialize the starting top left unit with the cost 
       and add it to the queue as the first move. */
    dp[0][0] = cost[0][0];
    pq.push({ 0, 0, cost[0][0] });

    while (!pq.empty()) {

        /* pop a move from the queue, ignore the
           units already visited */
        Cell cell = pq.top();
        pq.pop();
        int x = cell.x;
        int y = cell.y;
        if (visited[x][y])
            continue;

        visited[x][y] = true;   /* mark the current unit as visited */

        /* examine all non-visited adjacent units in 4 directions */
        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (isSafe(next_x, next_y, rows, cols) && 
                !visited[next_x][next_y]) 
            {
                dp[next_x][next_y] = cost[next_x][next_y] + 
                                     min(dp[next_x][next_y], dp[x][y]);
                pq.push({next_x, next_y, dp[next_x][next_y]});
            }
        }
    }

    /* return the minimum cost path at the lower 
      right corner */
    return dp[m][n];
}

/* Driver code */
int main() {
    vector<vector<int>> cost = {
        { 9, 4, 9, 9 },
        { 6, 7, 6, 4 },
        { 8, 3, 3, 7 },
        { 7, 4, 9, 10 }
    };

    printf(" %d ", minCost(cost, 3, 3));
    return 0;
}
