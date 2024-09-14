// Fractional Knapsack Problem
/*
** Given the weights and profits of N items, in the form of {profit, weight} put these items in a 
    knapsack of capacity W to get the maximum total profit in the knapsack. In Fractional Knapsack, 
    we can break items for maximizing the total value of the knapsack.

    Input: arr[] = {{60, 10}, {100, 20}, {120, 30}}, W = 50
    Output: 240 
    Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. 
    Hence total price will be 60+100+(2/3)(120) = 240

    Input:  arr[] = {{500, 30}}, W = 10
    Output: 166.667
*/

// C++ program to solve fractional Knapsack Problem

#include <iostream>
#include <algorithm>
using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
struct Item {
	int profit, weight;
};

// Comparison function to sort Item according to profit/weight ratio (reverse order)
static bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
	sort(arr, arr + N, cmp); // Sorting Item on basis of ratio in decreasing order

	double finalProfit = 0.0;

	// Looping through all items
	for (int i = 0; i < N; i++) {
		// If adding Item won't overflow, add it completely
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalProfit += arr[i].profit;
		}
		else {  // If we can't add current Item, add fractional part of it
			finalProfit += arr[i].profit	* ((double)W / (double)arr[i].weight);
			break;
		}
	}

	// Returning final value
	return finalProfit;
}

int main()
{
	int W = 50;
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << fractionalKnapsack(W, arr, N);
	return 0;
}
