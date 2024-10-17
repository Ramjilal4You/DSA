/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). 
Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands in all 8 directions.
i.e. horizontally or vertically or diagonally. 

Examples:

Input: grid = [[0,1],[1,0],[1,1],[1,0]]
Output: 1

Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
*/


//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int X[8]={1, 1, 0, -1, -1, -1, 0, 1};
int Y[8]={0, -1, -1, -1, 0, 1, 1, 1};
void MarkAllConnectedIslandsVisited(vector<vector<char>>& grid, int r, int c, int n, int m, vector<vector<bool>>& dp) 
{
    for(int i=0; i<8; i++){
        int rd = r+Y[i];
        int cd = c+X[i];
        if(rd>=0 && rd<n && cd<m && cd>=0)  //check grid boundary
        { 
            if(grid[rd][cd]=='1' && dp[rd][cd]==false){
                dp[rd][cd]=true;
                MarkAllConnectedIslandsVisited(grid, rd, cd, n, m, dp);
            }
        }
    }
}

void printDP(vector<vector<bool>>dp, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<dp[i][j]<<" ";
        }
    cout<<endl;
    }
}
int numIslandsUsingDP(vector<vector<char>>& grid) 
{
    int n = grid.size();    //column
    int m = grid[0].size(); //rows
    vector<vector<bool>>dp (n, vector<bool>(m, false)); //visited
    int res=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='1'){
                if(dp[i][j]==false){
                    res++;
                    dp[i][j]=true;
                    MarkAllConnectedIslandsVisited(grid, i, j, n, m, dp);
                    //printDP(dp, n, m);
                    //cout<<"res = "<<res<<endl;
                    //cout<<"\n-----------\n";
                }
            }
        }
    }
    return res;
}
//-----------------------------------

void UpdateAllConnectedIslandsToZero(vector<vector<char>>& grid, int r, int c, int n, int m) 
{
    if(r<0 || r>=n || c>=m || c<0 || grid[r][c]=='0')
        return;
    
    grid[r][c]='0';
    UpdateAllConnectedIslandsToZero(grid, r+0, c+1, n, m);
    UpdateAllConnectedIslandsToZero(grid, r+1, c+1, n, m);
    UpdateAllConnectedIslandsToZero(grid, r+1, c+0, n, m);
    UpdateAllConnectedIslandsToZero(grid, r+1, c-1, n, m);
    UpdateAllConnectedIslandsToZero(grid, r+0, c-1, n, m);
    UpdateAllConnectedIslandsToZero(grid, r-1, c-1, n, m);
    UpdateAllConnectedIslandsToZero(grid, r-1, c+0, n, m);
    UpdateAllConnectedIslandsToZero(grid, r-1, c+1, n, m);
}

// Function to find the number of islands.
int numIslandsUsingRecursive(vector<vector<char>>& grid) 
{
    int n = grid.size();    //column
    int m = grid[0].size(); //rows
    int res=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='1'){
                res++;
                UpdateAllConnectedIslandsToZero(grid, i, j, n, m);
                //printDP(grid, n, m);
                //cout<<"res = "<<res<<endl;
                //cout<<"\n-----------\n";
            }
        }
    }
    return res;
}

// Function to find the number of islands.
int numIslands(vector<vector<char>>& grid) {
    //return numIslandsUsingDP(grid);
    
    return numIslandsUsingRecursive(grid);
}

void printGrid(const vector<vector<char>>& grid){
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
		vector<vector<char>>grid(n, vector<char>(m, '#'));
        cout<<"Please enter matrix Elements :";
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}

        printGrid(grid);

		int ans = numIslands(grid);
		cout << "Islands Count : "<< ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends