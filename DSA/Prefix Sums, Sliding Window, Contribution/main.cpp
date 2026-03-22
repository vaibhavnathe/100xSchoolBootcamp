#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define int long long

void countVowelsInRange(string str, int l, int r, int *prefix)
{
    int count = 0;
    //2. optimal approach :- using prefix array - storing total vowels count until the current character
    //                      count in l to r :- total count till r - count till l-1
    if(l == 0){
        count = prefix[r];  // count from 0 to r
    }
    else{
        count = prefix[r] - prefix[l-1];    // count from l to r => count from 0 to r - count from 0 to l-1
    }
    

    //1. brute force :- using loop from l to r -> TC = O(Q*N), SC = O(10)
    /*
    for(int i=l; i<=r; i++){
        if(str[i] == 'a' or str[i] == 'e' or str[i] == 'i' or str[i] == 'o' or str[i] == 'u'){
            count++;
        }
    }
        */

    cout << count << endl;

}


void rangeSum(int *arr, int n, int l, int r, int *prefix)
{
    int sum = 0;
    if(r >= n){
        return;
    }

    //1. basic approach :- using loop from l to r -> but it takes huge time like for each query: O(Q*N)
    // for(int i=l; i<=r; i++){
    //     sum += arr[i];
    // }

    //2. optimal approach :- using prefix sum -> P array which stores sum till current ele
    if(l == 0){
        sum = prefix[r];    //sum => l=0 to r , its prefix[r]
    }
    else{
        sum = prefix[r] - prefix[l-1];  // l!=0 , l to r , sum => total(0 to r)/prefix[r] - first half (0 to l-1)/prefix[l-1]
    }

    cout << sum << endl;
}


signed main()
{

    //2. Count vowels in string between l to r index
    string str;
    cin >> str;

    int q;
    cin >> q;

    int prefix[str.size()];
    int count = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == 'a' or str[i] == 'e' or str[i] == 'i' or str[i] == 'o' or str[i] == 'u'){
            count++;
        }
        prefix[i] = count;
    }

    for(int i=0; i<q; i++){
        int l,r;
        cin >> l >> r;
        countVowelsInRange(str, l, r, prefix);
    }



    //1. Sum in Range from L to R
    /*
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // optimal approach :- using prefix sum -> P array which stores sum till current ele
    int prefix[n];
    prefix[0] = arr[0];
    for(int i=1; i<n; i++){
        prefix[i] = arr[i] + prefix[i-1];
    }

    int q;
    cin >> q;

    for(int i=0; i<q; i++){
        int l, r;
        cin >> l >> r;

        rangeSum(arr, n, l , r, prefix);
    }
    */

    return 0;
}