/*
finding a way for a robot to move from point (a, b) to (c, d) 
using specific movement rules: (x, y) can move to (x + y, y) or (x, x + y). 

    int a = 1, b = 2;
    int c = 5, d = 8;

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

// Hash function for pair<int, int> to use in unordered_set
struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2; // XOR to combine the two hash values
    }
};

int minStepsToReach(int a, int b, int c, int d) {
    if (a == c && b == d) {
        return 0;
    }

    queue<State> q;
    unordered_set<pair<int, int>, PairHash> visited;

    q.push(State(a, b, 0));
    visited.insert({a, b});

    while (!q.empty()) {
        State current = q.front();
        q.pop();
        
        int x = current.x;
        int y = current.y;
        int steps = current.steps;

        // Move to (x + y, y)
        if (x + y <= c && !visited.count({x + y, y})) {
            if (x + y == c && y == d) {
                return steps + 1;
            }
            q.push(State(x + y, y, steps + 1));
            visited.insert({x + y, y});
        }

        // Move to (x, x + y)
        if (x <= c && x + y <= d && !visited.count({x, x + y})) {
            if (x == c && x + y == d) {
                return steps + 1;
            }
            q.push(State(x, x + y, steps + 1));
            visited.insert({x, x + y});
        }
    }

    return -1; // No valid path found
}

int main() {
    int a = 1, b = 2;
    int c = 5, d = 8;

    int result = minStepsToReach(a, b, c, d);
    if (result == -1) {
        cout << "No valid path found." << endl;
    } else {
        cout << "Minimum steps required: " << result << endl;
    }

    return 0;
}