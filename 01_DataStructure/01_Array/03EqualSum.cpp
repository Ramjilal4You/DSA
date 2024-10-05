/*
Given an array arr. Determine if there exists an element in the array such that the sum of the elements on 
its left is equal to the sum of the elements on its right. If there are no elements to the left/right, 
then the sum is considered to be zero. 

Input: arr[] = [1, 2, 3, 3]
Output: true
Explanation: Consider 1-based indexing i = 3, for [1, 2] sum is 3 and for [3] sum is also 3.

*/
#include <iostream>
#include <vector>

using namespace std;

string equilibrium(vector<int> &arr) {
    //calculate the sum
    int sum=0;
    for(int x:arr){
        sum+=x;
    }
    
    int n = arr.size();
    int left=0, right=sum;
    for(int i=0; i<n; i++){
        right = sum-arr[i]-left;
        if(left==right)
            return "true";
        left += arr[i];
    }
    return "false";
}


//{ Driver Code Starts.

int main() {
    while (1) {
        cout<<"Please input array size :";
        int len=0;
        cin>>len;

        if(len==-1)
            break;

        cout<<"Please enter Array values : ";
        vector<int> arr;
        int num;

        while (len > 0) {
            cin>>num;
            arr.push_back(num);
            len--;
        }


        auto ans = equilibrium(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends










//https://www.geeksforgeeks.org/problems/equal-sum0810/1