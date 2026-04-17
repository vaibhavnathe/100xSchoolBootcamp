#include <iostream>
#include <bits/stdc++.h>

#define int long long

using namespace std;


// 1.] Given an array & Q queries, for each query given x. Find how many ele's <= x in array.
int findNoOfElesLessThanEqualToX(int *arr, int n, int x)
{
    // Optimal :-First Sort & Using binary search - if(mid ele <= x)-> store ans & moving right, else move left
    //             TC - O(Q * logN), SC - O(1)
    int l = 0;
    int r = n-1;
    int ans = -1;

    while(l <= r)
    {
        int mid = l - ((l - r)/2);

        if(arr[mid] <= x) {
            ans = mid;        //storing ans=mid if mid ele <= x, -> until mid ele all left ele are <= x
            l = mid+1;          // moving right to for better ans
        }
        else{   // other move left
            r = mid-1;
        }
    }

    // i) Brute Force :- Using loop - Iterating for each query & counting ele's <= x
    //                  TC - O(Q*N) , TLE -> 1 <= Q,N <= 10^5

    // count = index+1
    return ans + 1;     // even if no ele <= x found -> -1+1 = 0 no of ele
}


signed main()
{
    int n,q;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cin >> q;
    sort(arr, arr+n);

    // 1.] Given an array & Q queries, for each query given x. Find how many ele's <= x in array.
    for(int i=0; i<q; i++)
    {
        int x;
        cin >> x;
        int ans = findNoOfElesLessThanEqualToX(arr, n, x);
        cout << ans << endl;
    }
    


    return 0;
}