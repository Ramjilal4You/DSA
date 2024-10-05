/*
Given a sorted array arr[] of positive integers, find the smallest positive integer such that it cannot be 
represented as the sum of elements of any subset of the given array set.

Input: arr[] = [1, 2, 3]
Output: 7
Explanation: 7 is the smallest positive number for which no subset is there with sum 7.
*/
#include <iostream>
#include <vector>

using namespace std;

long long findSmallest(vector<int> &arr) 
{
    int res = 1;    //store the result
    
    //Find minimum not possible number
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > res)      // check for the next min not possible number
            return res;
        else
            res += arr[i];    //update the next min not possible number
    }
    
    return res;
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


        auto ans = findSmallest(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends














// https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1


