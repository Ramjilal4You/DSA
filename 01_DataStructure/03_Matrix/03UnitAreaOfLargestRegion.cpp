/*
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
 

Example 1:

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1
The largest region of 1's is colored in orange.
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void UpdateAllConnectedOneToZero(vector<vector<int>>& grid, int i, int j, int& oneCount)
{
    int n = grid.size();
    int m = grid[0].size();
    
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
        return;
        
    oneCount++;
    grid[i][j]=0;
    
    UpdateAllConnectedOneToZero(grid, i+0, j+1, oneCount);
    UpdateAllConnectedOneToZero(grid, i+1, j+1, oneCount);
    UpdateAllConnectedOneToZero(grid, i+1, j+0, oneCount);
    UpdateAllConnectedOneToZero(grid, i+1, j-1, oneCount);
    UpdateAllConnectedOneToZero(grid, i+0, j-1, oneCount);
    UpdateAllConnectedOneToZero(grid, i-1, j-1, oneCount);
    UpdateAllConnectedOneToZero(grid, i-1, j+0, oneCount);
    UpdateAllConnectedOneToZero(grid, i-1, j+1, oneCount);
}

//Function to find unit area of the largest region of 1s.
int findMaxAreaRecursive(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    
    int res=0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==1){
                int oneCount=0;
                UpdateAllConnectedOneToZero(grid, i, j, oneCount);
                if(res<oneCount)
                    res=oneCount;
            }
        }
    }
    
    return res;
}

void printGrid(const vector<vector<int>>& grid){
    cout<<"Grid Elements : \n";
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<endl;
}

//{ Driver Code Starts.
int main(){
	int tc; // number of test cases
    cout<<"Please enter Use case count : ";
	cin >> tc;
	while(tc--){
		int n, m;   // size of the matrix
        cout<<"Please enter matrix Size (n*m) : ";
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
        cout<<"Please enter matrix Elements :";
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}

        printGrid(grid);

		int ans = findMaxAreaRecursive(grid);
		cout << "Unit Area : "<< ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends