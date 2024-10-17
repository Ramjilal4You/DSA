/*
Given  a grid of n*m consisting of O's and X's. The task is to find the number of 'X' total shapes.
Note: 'X' shape consists of one or more adjacent X's (diagonals not included).

Input: grid = {{X,O,X},{O,X,O},{X,X,X}}
Output: 3
Explanation: 
The grid is-
X O X
O X O
X X X
So, X with same colour are adjacent to each other vertically for horizontally (diagonals not included). 
So, there are 3 different groups in the given grid.

*/

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

void UpdateConnectedXShapeToO(vector<vector<char>>& grid, int i, int j)
{
    int n = grid.size();
    int m = grid[0].size();
    
    if(i<0||i>=n||j<0||j>=m||grid[i][j]=='O')
        return;
        
    grid[i][j]='O';
    UpdateConnectedXShapeToO(grid, i+0, j+1);
    UpdateConnectedXShapeToO(grid, i+1, j+0);
    UpdateConnectedXShapeToO(grid, i-0, j-1);
    UpdateConnectedXShapeToO(grid, i-1, j-0);
}

//Function to find the number of 'X' total shapes.
int xShapeRecursive(vector<vector<char>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    
    int res=0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='X'){
                res++;
                UpdateConnectedXShapeToO(grid, i, j);
            }
        }
    }
    
    return res;
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

		int ans = xShapeRecursive(grid);
		cout <<"Shape Count : "<< ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends