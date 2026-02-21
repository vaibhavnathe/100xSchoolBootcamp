#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Using only array
void mergeTwoSorted2(int* arr1, int n, int *arr2, int m, int *merged)
{
    int i=0;
    int j=0;
    int k=0;

    while(i<n and j<m)
    {
        if(arr1[i] < arr2[j]){
            merged[k] = arr1[i++];
        }
        else{
            merged[k] = arr2[j++];
        }
        k++;
    }

    while(i<n){
        merged[k++] = arr1[i++];
    }

    while(j<m){
         merged[k] = arr2[j++];
    }

}


// using vectors
vector<int> mergeTwoSorted(vector<int> arr1, vector<int> arr2)
{
    int i=0;
    int j=0;
    vector<int>mergedArray;

    while(i<arr1.size() and j<arr2.size())
    {
        if(arr1[i] < arr2[j]){
            mergedArray.push_back(arr1[i++]);
        }
        else{
            mergedArray.push_back(arr2[j++]);
        }
    }

    while(i<arr1.size()){
        mergedArray.push_back(arr1[i++]);
    }

    while(j<arr2.size()){
        mergedArray.push_back(arr2[j++]);
    }

    return mergedArray;
}

void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int n,m;
    cin >> n;

    int arr1[n];
    for(int i=0; i<n; i++){
        cin >> arr1[i];
    }

    cin >> m;
    
    int arr2[m];
    for(int i=0; i<m; i++){
        cin >> arr2[i];
    }

    int merged[n+m];

    mergeTwoSorted2(arr1, n, arr2, m, merged);
    printArray(merged, n+m);


    /** 
    vector<int> arr1= {1,7,8,20,35};
    vector<int> arr2 = {2,5,6,9,25,30,40};

    vector<int> ans = mergeTwoSorted(arr1, arr2);

    for(int ele : ans){
        cout << ele << " ";
    }
    */
    
    return 0;
}