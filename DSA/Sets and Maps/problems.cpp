#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int twoSumPairCount(int *arr, int n, int target)
{
    // 2] Optimise :- we can use SET, checking for each ele if there is pair ele present in set or not, if not then inserting curr ele in set
    int count = 0;
    map<int, int> mp;
    for(int i=0; i<n; i++)
    {
        int reqEle = target - arr[i];
        if(mp[reqEle]){
            count += mp[reqEle];
        }
       
        if(mp[arr[i]]){
            mp[arr[i]]++;
        }
        else{
            mp[arr[i]] = 1;
        }
        
    }


    // 1] Brute Force :- Usine nested loops & checking pair ele for each curr ele & taking their count

    return count;
}


bool twoSum(int *arr, int n, int target)
{
    // 2] Optimise :- we can use SET, checking for each ele if there is pair ele present in set or not, if not then inserting curr ele in set
    set<int>st;
    for(int i=0; i<n; i++)
    {
        int pairEle = target - arr[i];
        if(st.count(pairEle)){
            return true;
        }
        else{
            st.insert(arr[i]);
        }
    }


    // 1] Brute Force :- Usine nested loops & checking pair ele for each curr ele
    //    if 1 <= N <= 10^5 :- TLE
    /*
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] + arr[j] == target)
            {
                return true;
            }
        }
    }
    */

    return false;
}

int main()
{
    
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    
    // 1] Two Sum
    int target;
    cin>> target;
    // bool ans = twoSum(arr, n, target);
    int ans = twoSumPairCount(arr, n, target);
    cout << ans << endl;

    return 0;
}