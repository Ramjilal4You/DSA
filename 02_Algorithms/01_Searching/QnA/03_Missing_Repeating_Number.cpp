//Find the missing and repeating number
/*
** Given an unsorted array of size n. Array elements are in the range of 1 to n. One number from set {1, 2, …n} 
   is missing and one number occurs twice in the array. Find these two numbers.

Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 2 is missing and 3 occurs twice 
*/

#include <iostream>
#include <vector>

using namespace std;

void FindMissingRepeatingNumberUsingArray(int arr[], const int n){
    vector<int> temp;

    //set all values to 0
    for(int i=0;i<=n;i++){
        temp.push_back(0);
    }

    int repeating = -1, missing=-1;
    //fill the count of element in array;
    for(int i=0;i<n;i++){
        temp[arr[i]]++;
    }

    //fill the count of element in array;
    for(int i=1;i<=n;i++){
        if(temp[i] > 1)
            repeating=i;
        else if(temp[i] == 0)
            missing=i;     
    }

    cout<<"repeating : "<<repeating<<"\nmissing : "<<missing<<"\n\n\n";

}

//mark the visited places as negative
void FindMissingRepeatingNumberUsingSameArray(int arr[], int size)
{
    cout << "The repeating element is ";

    for (int i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];   //marking number negative
        else
            cout << abs(arr[i]) << "\n";
    }

    cout << "and the missing element is ";
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0)
            cout << (i + 1);
    }
}

int main(){
    int arr[] = {3, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    FindMissingRepeatingNumberUsingArray(arr, n);

return 0;
}