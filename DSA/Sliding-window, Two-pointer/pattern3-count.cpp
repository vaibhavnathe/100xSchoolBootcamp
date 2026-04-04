// Pattern #2 :- LONGEST SUBARRAY WITH <CONDITION> 
//             -This pattern is almost same as pattern 2(LONGEST), just need to update step 3 for valid window

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void count_subarray_with_no_duplicates(int *arr, int n)
{
    int count = 0;

    // 3. Optimal -  -> O(n)
    map<int, int>mp;
    int l=0;
    for(int r=0; r<n; r++){
        mp[arr[r]]++;

        while(mp[arr[r]] > 1){        //invalid window => remove ele until get valid window of distinct ele's
            mp[arr[l]]--;
            if(mp[arr[l]] == 0){
                mp.erase(mp.find(arr[l]));
            }
            l++;
        }
        // valid window of distinct ele
        count += r-l+1;
    }


    //1. Brute force :- Using nested loops for each ele's subarray's
    // O(n^2)
    /*
    for(int i=0; i<n; i++)
    {

    }
    */


    cout << count << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    count_subarray_with_no_duplicates(arr, n);
    
    return 0;
}