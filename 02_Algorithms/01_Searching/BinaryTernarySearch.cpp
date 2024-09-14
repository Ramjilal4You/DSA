//binary search
#include <iostream>
#include <algorithm>
using namespace std;

#define LIMIT 10;

void binarySearch(int* arr,int n, int iKey){
    cout<<"\nbinarySearch()\n";
    int l=0,r=n-1,mid;
    while(l<=r){
        mid = l + (r-l)/2;

        if(arr[mid]==iKey){
            cout<<"Key found at "<<mid<<" index.\n\n\n";
            return;
        }
        
        if(arr[mid]<iKey)
            l=mid+1;    //move left forward
        else
            r=mid-1;    //move right backward 
    }
    cout<<"Key not found!\n\n\n";
}

void binarySearchRec(int* arr, int l, int r, int iKey){
    cout<<"\nbinarySearchRec()\n";
    if(l>r){
        cout<<"Key not found!\n\n\n";
        return;
    }

    int mid = l+(r-l)/2;

    if(arr[mid]==iKey){
        cout<<"Key found at "<<mid<<" index.\n\n\n";
        return;
    }

    if(arr[mid]>iKey)
        r=mid-1;
    else
        l=mid+1;

    binarySearchRec(arr, l, r, iKey);
}

void ternarySearchRec(int* arr, int l, int r, int iKey){
    cout<<"\nternarySearchRec()\n";
    if(l>r){
        cout<<"Key not found!\n\n\n";
        return;
    }

    int mid1 = l+(r-l)/3;
    int mid2 = r-(r-l)/3;

    if(arr[mid1]==iKey){
        cout<<"Key found at "<<mid1<<" index.\n\n\n";
        return;
    }
    if(arr[mid2]==iKey){
        cout<<"Key found at "<<mid2<<" index.\n\n\n";
        return;
    }

    if(iKey<arr[mid1])
        return ternarySearchRec(arr, l, mid1-1, iKey);  //1st block
    else if(iKey>arr[mid2])
        return ternarySearchRec(arr,mid2+1, r, iKey);   //3rd block
    else
        return ternarySearchRec(arr,mid1+1, mid2-1, iKey);  //middle block

}

void ternarySearch(int* arr, int l, int r, int iKey){
    cout<<"\nternarySearch()\n";
    while(l<=r){
        int mid1 = l+(r-l)/3;
        int mid2 = r-(r-l)/3;

        if(arr[mid1]==iKey){
            cout<<"Key found at "<<mid1<<" index.\n\n\n";
            return;
        }
        if(arr[mid2]==iKey){
            cout<<"Key found at "<<mid2<<" index.\n\n\n";
            return;
        }

        if(iKey<arr[mid1])
            r = mid1-1;  //1st block
        else if(iKey>arr[mid2])
            l = mid2+1;   //3rd block
        else    //middle block
        {
            l = mid1+1;
            r = mid2-1;  
        }
    }
    cout<<"Key not found!\n\n\n";
}

int main(){
    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int key = 11;

    // print array 
    cout<<"Original Array : ";
    for_each(arr, arr+10, [](int x){cout<<x<<" ";});

    binarySearch(arr,10, key);

    binarySearchRec(arr, 0, 9, key);

    ternarySearchRec(arr, 0, 9, key);
    ternarySearch(arr, 0, 9, key);

return 0;
}