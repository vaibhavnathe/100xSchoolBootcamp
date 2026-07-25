#include <bits/stdc++.h>

#define int long long 

using namespace std;

// Q.3] Quick parttion :- Given an array, Take first ele as pivot/x. Find the position for pivot/x such that =>  [...<pivot/x] X [...>=pivot/x..]
//                      - do rearrangement such [...ele<x,  X  , ele>=X]
int quickPartition(vector<int>&arr)
{
    int pivot = arr[0];     // or x=arr[0]
    
    // approach :- using two-pointer apporach: l=1, r=n-1 , same logic if(arr[l] < pivot) -> l++, else -> swap(arr[l], arr[r--])
    //          - at last swap pivot/arr[0] with arr[r] its correct position which is r
    int l = 1;
    int r = arr.size()-1;
    while(l <= r){
        if(arr[l] < pivot){
            l++;
        }
        else{// arr[l] > pivot -> send it last to r
            swap(arr[l], arr[r--]);
        }
    }
    swap(arr[0], arr[r]);   // swap with its correct pos
    return r;
}

// Q.2] Pivot rank :- Given an array of size N and integer X, we need to find correct sorted position for X in array, so X will become part of arr
int pivotRank(vector<int>&arr, int x)
{
    // approach 3 :- simply count ele's < x by iterating -> count is correct sorted position for x
    int count = 0;
    for(auto ele : arr){
        if(ele < x){
            count++;
        }
    }
    cout << count << endl;      // after no. of count ele's, x will appear -> count is pos

    // approach 2 :- using two-pointer approach, l-at first & r-at end -> if arr[l] < z -> l++, if(arr[r] > x) ->r--, else ->l++ , r-- without arranging ele's
    //          TC - O(N)
    /*
    int l=0;
    int r=arr.size()-1;
    while(l <= r){
        if(arr[l] < x){
            l++;
        }
        else if(arr[r] > x){
            r--;
        }
        else{   // means: arr[l] > x and arr[r] < x  => increase l++ , decrease r--
            l++;
            r--;
        }
    }
    // now l is the position
    cout << l << endl;
    */


    // approach 1:- simply using in-built sort & then check sorted pos for X by iterationg over it
    ///      TC - O(N*logN) + O(N / logN) => O(N*logN)
}

//Q.1] Given an array and X, re-arrange ele such that, All ele's < X come before all ele's >= X
//      - If multiple ans/arrangements, print any of them
void rearrangeArray(vector<int> &arr, int x)
{
    // ii) Optimal approach :-using two-pointer approach - one pass
    //                      - TC - O(N)
    // 2nd way of two-pointer
    int l=0;
    int r=arr.size()-1;
    while(l <= r){
        if(arr[l] < x){
            l++;
        }
        else{
            swap(arr[l], arr[r]);
            r--;
        }
    }

    // 1st way of two-pointer 
    /*
    int i=0;
    int j=0;
    
    while(j < arr.size())
    {
        if(arr[j] < x){
            swap(arr[j], arr[i]);
            i++;
        }
        j++;
    }
    */
     for(auto ele: arr){
        cout << ele << " ";
    }
 
    // i)basic approach :- using extra array - first store ele's < X, then ele's >= X
    //                  - Or iterating twice - first print ele's < X & then ele's >= X
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
    // cin >> x;

    
    // Q.3] Quick partition :- Given an array, Take first ele as pivot/x. Find the position for pivot/x such that =>  [...<pivot/x] X [...>=pivot/x..]
    int pos = quickPartition(arr);
    cout << pos << endl;
    for(auto ele: arr){
        cout << ele << " ";
    }

    // Q.2] Pivot rank :- Given an array of size N and integer X, we need to find correct sorted position for X in array, so X will become part of arr
    // pivotRank(arr, x);
    
    //Q.1] Re-arrange an array :- Given an array and X, re-arrange ele such that, All ele's < X come before all ele's >= X
    /*
    rearrangeArray(arr,x);
    */
    
    return 0;
}