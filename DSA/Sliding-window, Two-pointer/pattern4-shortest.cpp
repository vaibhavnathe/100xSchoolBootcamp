#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Q.] Shortest subaaray with sum > x

void solve(int *arr, int n, int x)
{
    int minLen = INT_MAX;

    // 2.] Optimal :- Using sliding window: if window invalide -> expand, valid -> update ans, shrink it
    int l=0;
    int sum = 0;
    for(int r=0; r<n; r++)
    {
        sum += arr[r];
        
        while(sum > x){
            minLen = min(minLen, r-l+1);
            sum -= arr[l];
            l++;
        }
    }

    // 1.] Brute Force :- Using nested loops for each ele
    /*
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum > x){
                minLen = min(minLen, j-i+1);
                break;
            }
        }
    }
    */

    cout << minLen << endl;
}

int main()
{

    int n,x;
    cin >>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cin >> x;

    solve(arr, n, x);
    
    return 0;
}