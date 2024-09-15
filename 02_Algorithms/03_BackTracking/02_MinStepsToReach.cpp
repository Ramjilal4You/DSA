/*
find minimum steps to reach from source point(a, b) to destination point(c, d) 
using specific movement rules: (x, y) can move to (x + y, y) or (x, x + y). 

    - reachable
        int a = 2, b = 3;
        int c = 12, d = 5;
    
    - Can not reach
        int a = 2, b = 3;
        int c = 12, d = 13;

This is a classic problem that can be approached using a breadth-first search (BFS) algorithm to explore 
all possible positions the robot can reach.
*/
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

// Define a structure for holding the state of the robot (x, y)
struct State {
    int x, y;
    int steps;
    
    State(int x, int y, int steps) : x(x), y(y), steps(steps) {}
};

int minStepsToReach(int a, int b, int c, int d) {
    if (a == c && b == d) {
        return 0;
    }

    queue<State> q;
    q.push(State(a, b, 0));

    while (!q.empty()) {
        State current = q.front();
        q.pop();
        
        int x = current.x;
        int y = current.y;
        int steps = current.steps;

        // Move to (x + y, y)
        if (x + y <= c && y<=d) {
            if (x + y == c && y == d) {
                return steps + 1;
            }
            q.push(State(x + y, y, steps + 1));
        }

        // Move to (x, x + y)
        if (x <= c && x + y <= d) {
            if (x == c && x + y == d) {
                return steps + 1;
            }
            q.push(State(x, x + y, steps + 1));
        }
    }

    return -1; // No valid path found
}

int main() {
    int a = 2, b = 3, c = 12, d = 5;
    //int a = 2, b = 3, c = 12, d = 13;
    int result = minStepsToReach(a, b, c, d);
    if (result == -1) {
        cout << "\nNo valid path found.\n" << endl;
    } else {
        cout << "\nMinimum steps required: " << result << "\n\n";
    }

    return 0;
}