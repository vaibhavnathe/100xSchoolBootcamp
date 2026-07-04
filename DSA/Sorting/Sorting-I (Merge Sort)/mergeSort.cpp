#include <bits/stdc++.h>

#define int long long

using namespace std;

// Q.2] Count Inversions -> A = [10,5,3,2,1,6,3,7,8], count -> A[i] > A[j] i.e i < j.
//                      - O/P - 16 , ex. 10 > 5,3,2,1,6,3,7,8 -> 8

int mergeCountInversions(vector<int>&A, int l, int mid, int r)
{
    int i = l;  // first half -> [l, mid]
    int j = mid+1;  // second half -> [mid+1,r]

    vector<int> temp;
    int invCount = 0;       // counting remaing inversion count comparing from 1st half with 2nd half
    while(i <= mid and j <= r)
    {
        if(A[i] <= A[j]){
            temp.push_back(A[i++]);
        }
        else{
            temp.push_back(A[j++]);     // when ele selected or added from 2nd half -> remaining ele from i to mid become inversions for A[j]
            invCount += mid-i+1;        // adding remaing invCount when A[i] > A[j](2nd half) -> (mid-i+1) those many inversions need to add
        }
    }

    while(i <= mid){
        temp.push_back(A[i++]);
    }

    while(j <= r){
        temp.push_back(A[j++]);
    }

    // copy sorted temp array into original A array
    int index = 0;
    for(int i=l; i<=r; i++){
        A[i] = temp[index++];
    }

    return invCount;
}

int countInversions(vector<int>&A, int l, int r)
{
    // basic/brute approach :- using nested loops -> TC - O(n^2)

    // optimal approach :- using merge sort -> TC - O(n*logn)
    
    // base/stop case : single ele - sorted array , no inversion
    if(l == r){
        return 0;
    }

    // divide array
    int mid = l - ((l-r)/2);

    // Sort first half of arr & bring the inversion count from first half
    int ans1 = countInversions(A, l, mid);

    // Sort the 2nd half of arr & bring the inversion count from second half
    int ans2 = countInversions(A, mid+1, r);

    // Now : Merge both sorted arraya & bring the remaining inversion count for ele in 1st half with ele's in 2nd halfd
    int ans3 = mergeCountInversions(A, l, mid, r);

    // final ans -> sum of all counts
    return ans1 + ans2 + ans3;
}

// Q.1] Merge Two SOrted Arrays
void mergeTwoSorted(vector<int> &arr1, vector<int>& arr2)
{
    // basix approach :- combined arr1 & arr2 into one array & sort using in-built sort

    // optimal approach :- Using two-pointer on arrays
    int i=0;
    int j=0;

    vector<int> res;
    while(i < arr1.size() and j < arr2.size())
    {
        if(arr1[i] <= arr2[j]){
            res.push_back(arr1[i++]);
        }
        else{
            res.push_back(arr2[j++]);
        }
    }

    // remaining ele from arrays
    while(i < arr1.size()){
        res.push_back(arr1[i++]);
    }

    while(j < arr2.size()){
        res.push_back(arr2[j++]);
    }

    // print res array
    for(auto ele : res){
        cout << ele << " ";
    }
}

// Merge two Sorted for Merge Sort
void merge(vector<int> & A, int l, int mid, int r)
{
    // first half : l - mid
    // second half : mid+1 - r
    int i=l;
    int j=mid+1;

    vector<int> res;
    while(i <= mid and j <= r)
    {
        if(A[i] <= A[j]){
            res.push_back(A[i++]);
        }
        else{
            res.push_back(A[j++]);
        }
    }

    // remaining ele from arrays
    while(i <= mid){
        res.push_back(A[i++]);
    }

    while(j <= r){
        res.push_back(A[j++]);
    }

    // copy from res array to main array at correct positions
    int index = l;
    for(auto ele : res){
        A[index++] = ele;
    }
}

void mergeSort(vector<int> &A, int l, int r)
{
    // base/stop case - single el -> already sorted - return
    if(l == r){
        return;
    }
    
    // divide & conquor - divide array into two parts using mid -> recursion will sort both parts/halfs -> merge the two srted arrays

    int mid = l - ((l-r)/2);    // divide an array using mid

    mergeSort(A, l, mid);       // sort first half(l to mid) - Reccursion will do it

    mergeSort(A, mid+1, r);     // sort second half(mid+1 to r) - Reccursion will do it

    merge(A, l, mid, r);        // then - merge the both half/parts using merge Two Sorted arrays method
}

signed main()
{

    // Q.2] Count Inversions
    vector<int> A = {10,5,3,2,1,6,3,7,8};
    int ans = countInversions(A, 0, A.size()-1);
    cout << ans << endl;

    // **** Merge Sort
    /*
    vector<int> arr = {8,6,5,9,2,7,3,4,1};
    mergeSort(arr, 0, arr.size()-1);        // f(A, start, end)
    for(auto ele : arr){
        cout << ele << " ";
    }
        */

    // Q] Merge two-sorted arrays
    /*
    vector<int> arr1 = {1,4,6,8,9};
    vector<int> arr2 = {2,3,5,7,10};
    mergeTwoSorted(arr1, arr2);
    */ 

    return 0;
}