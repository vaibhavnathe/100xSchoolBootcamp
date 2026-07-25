#include <bits/stdc++.h>

#define int long long
using namespace std;

// Instead of selecting the first ele as pivot :-  can select last ele, random index
//                                             - can use Median of medians as pivot (this will gurantee N*logN always)  => advanced

int partition(vector<int>&arr, int start, int end)
{
    // to avoid worst case complexity -> take random no as pivot instead of first
    int randomIndex = start + rand()%(end-start+1);     // rand fn - generates between 0-INT_MAX, by % (e-s+1) keep in range and by adding +s -> it get's exact range
    swap(arr[start], arr[randomIndex]);

    int pivot = arr[start];
    
    int l = start+1;
    int r = end;

    while(l <= r){
        if(arr[l] < pivot){
            l++;
        }
        else{
            swap(arr[l], arr[r--]);
        }
    }
    swap(arr[start], arr[r]);
    return r;
}


// Simple approach :- taking pivot/first ele & placing it in its correct sorted position using partition. After placing -> do same for left part & right part like merge sort
//          TC (best & avg case)     - O(N*logN)  , worst case(sorted arr) - O(N^2)
// To avoid worst case -> instead of first ele as pivot, take random no as pivot :- (in partition take random no between start & end then swap with start ele - remaining code will same) 
void quickSort(vector<int>&arr, int l, int r)
{
    if(l >= r){ // 0/1 ele is there
        return;
    }

    int pivotIndex = partition(arr, l, r);
    
    // left part
    quickSort(arr, l, pivotIndex-1);
    // right part
    quickSort(arr, pivotIndex+1, r);
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,x;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, arr.size()-1);    // need to sort from 0 to n-1

    for(auto ele: arr){
        cout << ele << " ";
    }


    return 0;
}


// Note: Any benefit of using quick sort over merge sort
        // - Quick sort is in-place(no extra array) whereas merge sort is not in-place(uses extra array/space)


//   i) In-place : (Any extra space or not)
        // In-place alogorithms :- Selection, Bubble, Insertion & Quick Sort
        // No in-place algorithms :- Merge & Count Sort

//   ii) Stability : The relative ordering of equal elements remains same as given array
//      Stable :-   Merge Sort, Bubble Sort, Insertion Sort
//      Not Stable :-   Count Sort(order of ele can change) - can be made stable with prefix sum
//                  -   Quick Sort
//                  - Selection Sort (data get shuffled)


//   iii) Comparison based :- ele's gets compared or not
//                          - Selection, Bubble, Insertion, Merge, Quick Sort are comparison-based algorithms
//                          - Count Sort is not comparison-based
