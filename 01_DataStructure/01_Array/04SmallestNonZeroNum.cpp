/*
You are given an array arr[]. Your task is to find the smallest number x such that when x is processed 
sequentially with each element of the array (from index 0 to n-1), it never becomes negative, under the 
following conditions:
- If x is greater than the current array element, x is increased by the difference between x and the array element.
- If x is less than or equal to the current array element, x is decreased by the difference between the array element and x.

Input: arr[] = [3, 4, 3, 2, 4]
Output: 4
Explanation: Start with `x = 4`:
- For arr[0] = 3, x becomes 5.
- For arr[1] = 4, x becomes 6.
- For arr[2] = 3, x becomes 9.
- For arr[3] = 2, x becomes 16.
- For arr[4] = 4, x becomes 28.
x remains positive throughout the process.
If x < 4, it would become negative at some point.

*/

#include <iostream>
#include <vector>

using namespace std;

// } Driver Code Ends
class Solution {
    //brute force O(k*n)
    int find1(vector<int>& arr) {
        int n = arr.size();
        int k=1;
        while(1){
            int x=k;
            int i=0;
            while(i<n){
                int diff = x-arr[i];
                x+=diff;
                if(x<0)
                    break;
                i++;
            }
            if(i==n)
                return k;
            k++;
        }
        return k;
    }
    
    //Efficient Approach: Backward Calculation O(n) 
    //Use the fact that when you reach the last array element, the value with which we started can be at least 0, 
    //Which means suppose last array element is a[n-1] then the value at a[n-2] must be greater than or equal to a[n-1]/2.
    int find2(vector<int>& arr) {
        
        int x=0;
        int n = arr.size();
        for(int i=n-1; i>=0; i--){
            if((x+arr[i])%2!=0)
                x++;    //add 1 to make ((x+arr[i])/2) result to upper bound value
            x = ((x+arr[i])/2);
        }
        return x;
    }
    
public:
    int SmallestNonZeroNum(vector<int>& arr) {
        
        //brute force O(k*n)
        //return find1(arr);
        
        //Backward Calculation O(n) 
        return find2(arr);
    }
};

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

        Solution obj;
        auto ans = obj.SmallestNonZeroNum(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends