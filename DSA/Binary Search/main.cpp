#include <iostream>
#include <bits/stdc++.h>

#define int long long

using namespace std;


// 2.] Find last occurence of target in an sorted array
int findLastOccurence(int *arr, int n, int target)
{
    int l = 0;
    int r = n-1;
    int ans = -1;

    while(l <= r)
    {
        int mid = l - ((l-r)/2);

        if(target == arr[mid]){ // found ans -> store curr ans & search/move to right to find last occurence
            ans = mid;
           l = mid+1;
        }
        else if(target < arr[mid]){ // target is in left side
            r = mid-1;
        }
        else{  // target > arr[mid] -> target is in right side
            l = mid+1;
        }
    }

    return ans;
}

// 1.] Find first occurence of target in an sorted array
int findFirstOccurence(int *arr, int n, int target)
{
    int l = 0;
    int r = n-1;
    int ans = -1;

    while(l <= r)
    {
        int mid = l - ((l-r)/2);

        if(target == arr[mid]){ // found ans -> store curr ans & search/move in left to fid first occurence
            ans = mid;
            r = mid-1;
        }
        else if(target < arr[mid]){ // target is in left side
            r = mid-1;
        }
        else{  // target > arr[mid] -> target is in right side
            l = mid+1;
        }
    }

    return ans;
}

// 3.] Find first & last occurence of target in an sorted array
void findFirstAndLastOccurence(int*arr , int n, int target)
{
    // two binary searches :- i) binary search for first occurence -> findFirstOccurence() fn
    //                        ii) binary search for last occurence -> findLastOccurence() fn

    int firstOcc = findFirstOccurence(arr, n, target);
    int lastOcc = findLastOccurence(arr, n, target);

    cout << firstOcc << " " << lastOcc << endl;
}

// 4.] Count number of occurences of target in an array
int findNoOfOccurences(int*arr , int n, int target)
{
    int ans = 0;
    int firstOcc = findFirstOccurence(arr, n, target);
    int lastOccu = findLastOccurence(arr, n, target);

    // edge cases :- i) what if target is not present
    if(firstOcc == -1){
        return 0;
    }
    ans = lastOccu - firstOcc + 1;
    return ans;
}

// Binary Search :- TC- O(logn), SC- O(1)
int binarySearch(int *arr, int n, int target)
{
    int l=0;
    int r=n-1;

    while(l <= r)
    {
        int mid = l - ((l-r)/2);

        if(target == arr[mid])
        {
            // return true;     // for just present or not
            return mid;         // if we need an index
        }
        else if(target < arr[mid]){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    return -1;
}

signed main()
{
    int n,target;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cin >> target;

    // 4.] Count number of occurences of target in an array
    int ans = findNoOfOccurences(arr, n, target);
    cout << ans << endl;

    // 3.] Find first & last occurence of target in an sorted array
    // findFirstAndLastOccurence(arr, n, target);

    // 2.] Find last occurence of target in an sorted array
    // int ans = findLastOccurence(arr, n, target);
    // cout << ans << endl;

    // 1.] Find first occurence of target in an sorted array
    // int ans = findFirstOccurence(arr, n, target);
    // cout << ans << endl;

    // int ans = binarySearch(arr, n, target);
    // cout << ans << endl;

    return 0;
}