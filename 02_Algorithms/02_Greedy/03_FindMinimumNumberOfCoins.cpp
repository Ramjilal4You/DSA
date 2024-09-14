// Greedy Algorithm to find Minimum number of Coins
/*
    Given a value of V Rs and an infinite supply of each of the denominations {1, 2, 5, 10, 20, 50, 100, 500, 1000} 
    valued coins/notes, The task is to find the minimum number of coins and/or notes needed to make the change?

Examples:  
    Input: V = 70
    Output: 2
    Explanation: We need a 50 Rs note and a 20 Rs note.

    Input: V = 121
    Output: 3
    Explanation: We need a 100 Rs note, a 20 Rs note, and a 1 Rs coin.
*/
/*
    O(nlogn) - Greedy approach - sort array of coins in reverse order
    O(n) - using DP Approach - check in DP section below
*/

// C++ program to find minimum number of denominations
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// All denominations of Indian Currency
int denomination[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
int n = sizeof(denomination) / sizeof(denomination[0]);

void findMin(int V)
{
	sort(denomination, denomination + n);

	// Initialize result
	vector<int> ans;

	// Traverse through all denomination
	for (int i = n - 1; i >= 0; i--) {

		// Find denominations
		while (V >= denomination[i]) {
			V -= denomination[i];
			ans.push_back(denomination[i]);
		}
	}

	// Print result
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}

// A Dynamic Programming based C++ program to find minimum of coins to make a given change sum
// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int sum)
{
    // table[i] will be storing the minimum number of coins
    // required for i value.  So table[sum] will have result
    int* dp = new int[sum + 1];

    // Base case (If given value sum is 0)
    dp[0] = 0;

    // Initialize all table values as Infinite
    for (int i = 1; i <= sum; i++)
        dp[i] = INT_MAX;

    // Compute minimum coins required for all
    // values from 1 to sum
    for (int i = 1; i <= sum; i++) {
        // Go through all coins smaller than i
        for (int j = 0; j < m; j++)
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                    dp[i] = sub_res + 1;
            }
    }

    return (dp[sum] == INT_MAX) ? -1 : dp[sum];
}

// Driver Code
int main()
{
	int sum = 93;
	cout << "Minimal number of change for " << sum << ": ";

	// Function Call
	//findMin(n);

	//dp approach
	minCoins(denomination, ::n, sum);
	return 0;
}

