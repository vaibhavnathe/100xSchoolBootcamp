#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define int long long // Using int as long long in whole code

//✅ Actual version — by assigning 
void insertionSort(int *arr, int n)
{
    for(int i=1; i<n; i++){
        
        int key = arr[i];
        int j = i-1;
        while(j >= 0 and arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

//✅ My version — swap-based insertion sort
void insertionSortActual(int *arr, int n)
{
    for(int i=1; i<n; i++){
        int j = i;

        while(j>0 && arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
        
    }
}

void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

signed main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    printArray(arr, n);
    // insertionSort(arr, n);
    insertionSortActual(arr, n);
    printArray(arr, n);

    return 0;
}