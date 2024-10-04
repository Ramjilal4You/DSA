//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        long long int multi=1, zeroCount=0;
        
        //1. multiply all non zero elements 
        for(int x:nums){
            if(x==0)
                zeroCount++;
            else
               multi*=x; 
        }
        
        //2. create multiply array
        int n = nums.size();
        vector<long long int> multiplyArray(n, 0);
        
        //3. Having more than one zero 
        if(zeroCount>1)
            return multiplyArray;

        //4. Having one zero or non-zero elements 
        for(int i=0; i<n; i++){
            if(nums[i] != 0 && zeroCount != 0)
                multiplyArray[i]=0;
            else if(nums[i] != 0)
                multiplyArray[i] = multi/nums[i];
            else
                multiplyArray[i] = multi;
        }
        
        //5. return the resulted array
        return multiplyArray;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cout<<"Please enter Use case count : ";
    cin >> t;
    while (t--) {
        int n; // size of the array
        cout<<"Please enter Array Size : ";
        cin >> n;
        vector<long long int> arr(n), vec(n);

        cout<<"Please enter Array Elements : ";
        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends