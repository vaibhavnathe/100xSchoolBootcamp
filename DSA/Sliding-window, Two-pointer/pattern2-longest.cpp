// Pattern #2 :- LONGEST SUBARRAY WITH <CONDITION>

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void longest_subarray_having_sum_lessthan_X(int *arr, int n, int x)
{
    int maxLen = 0;

    // 3. Optimal -  -> O(n)
    int sum = 0;
    int l=0;
    for(int r=0; r<n; r++){
        sum += arr[r];

        while(sum >= x){        //invalid sum => minus from l until sum >= x
            sum -= arr[l];  
            l++;
        }
        // valid sum , < x -> calculate its length
        maxLen = max(maxLen, r-l+1);
    }

    // 2. (My-thinking approach) :- Using sliding window  -> O(n^2)
    /*
    int i=0;
    int j=0;
    int sum = 0;
    while(i <= j and j < n)
    {
        sum += arr[j];
        if(sum < x){
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        else{
            sum = 0;
            i++;
            j=i;
        }
    }
        */


    //1. Brute force :- Using nested loops for each ele's subarray's
    // O(n^2)
    /*
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum < x){
                maxLen = max(maxLen, j-i+1);
            }
            else{
                break;
            }
        }
    }
    */


    cout << maxLen << endl;
}

int main()
{
    int n,x;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> x;
    longest_subarray_having_sum_lessthan_X(arr, n, x);
    
    return 0;
}