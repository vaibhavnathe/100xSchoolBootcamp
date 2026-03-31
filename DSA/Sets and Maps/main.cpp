#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define int long long

void unionOfTwoArraysDuplicates(int *arr1, int n, int *arr2, int m)
{
    //2] optimal using maps:- creating map for both arr, then finding max freq from both and printing accordingly
    map<int, int>mapA; 
    map<int, int>mapB;
    for(int i=0; i<n; i++)
    {
        if(mapA[arr1[i]]){
            mapA[arr1[i]]++;
        }
        else{
            mapA[arr1[i]] = 1;
        }
    } 

    for(int i=0; i<m; i++)
    {
        if(mapB[arr2[i]]){
            mapB[arr2[i]]++;
        }
        else{
            mapB[arr2[i]] = 1;
        }
    } 

    // finding max freq from both and updating in mapA 
    for(auto ele : mapB)
    {
        if(mapA[ele.first]){
            mapA[ele.first] = max(mapA[ele.first], ele.second); 
        }
        else{
            mapA[ele.first] = ele.second;
        }
    }
    // printing accordingly
    for(auto ele : mapA){
        while(ele.second){
            cout << ele.first << " ";
            ele.second--;
        }
    }

    //1] brute force :- using loops
}

void unionOfTwoArrays(int *arr1, int n, int *arr2, int m)
{
    //Brute Force :- Using nested loop, for each ele in arr1 check if that ele is present in arr2, then mark it as -1 (to already considered for next time). And push curr ele of arr1 in res

    //optimal approach :- using set- put all ele of arr1 & arr2 into the set
    set<int>st;
    for(int i=0; i<n; i++){
        st.insert(arr1[i]);
    }
    for(int i=0; i<m; i++){
        st.insert(arr2[i]);
    }

    // traverse over set & print ele
    for(auto ele : st){
        cout << ele << " ";
    }
}


void countDistinct(int *arr, int n){

    int count = 0;

    //2] Optimal APproach :- Using set - just need to insert & return its size as distinct count
    set<int>st;
    for(int i=0; i<n; i++)
    {
        st.insert(arr[i]);
    } 
    count = st.size();

    //1] Brute Force :- using nested loops to count distincy & mark duplicates
    /*
    for(int i=0; i<n; i++)
    {   
        if(arr[i] == -1){
            continue;
        }

        count++;
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] == arr[j]){
                arr[j] = -1;        // marking duplicate ele as -1, if array contains -1 then user INT_MAX for marking
            }
        }
    }*/
    
    cout << count << endl;

}


bool checkDuplicates(int *arr, int n)
{
    //2) Optimal approach :- Using set : check set already contains ele or not
    set<int> st;
    for(int i=0; i<n; i++)
    {
        if(st.count(arr[i])){       // or use -> st.find(arr[i]) != st.end()
            return true;
        }
        else{
            st.insert(arr[i]);
        }
    }

    return false;


    // 1) Brute force :- using loops/nested iteration
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    */

    return false;
}

void countFrequency(int *arr, int n)
{
    // 2) Optimal approach :- Using map - ele already present then increse count , if not then map ele -> 1 count
    map<int, int> mp;
    for(int i=0; i<n; i++)
    {
        if(mp.count(arr[i])){       // or we can use :- mp.find(arr[i]) != mp.end()
            // found ele -> increase its count
            mp[arr[i]]++;
        }
        else{
            // ele not found -> map ele to count 1
            mp[arr[i]] = 1;
        }
    }

    // iteration over map
    for(auto ele: mp){
        cout << ele.first << "->" << ele.second << endl;
    }


    // 1) Brute force :- using loops/nested iteration
    /*
    for (int i = 0; i < n; i++){
        if (arr[i] == -1){
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j]){
                count++;
                arr[j] = -1; // marking as done -> already done counting
            }
        }
        cout << arr[i] << "->" << count << endl;
    }
        */
}

signed main()
{
    int n,m;
    cin >> n;

    int arr1[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cin>>m;
    int arr2[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    // 5] Union of two arrays wth duplicates
    unionOfTwoArraysDuplicates(arr1, n, arr2, m);

    // 4] Union of two arrays
    // unionOfTwoArrays(arr1, n, arr2, m);

    
    //3] Count distinct ele in an array
    // countDistinct(arr, n);


    // 2] Count the freq of each ele in array
    // countFrequency(arr, n);

    // 1] Check if array contains duplicate ele or not
    // cout << checkDuplicates(arr, n) << endl;

    return 0;
}