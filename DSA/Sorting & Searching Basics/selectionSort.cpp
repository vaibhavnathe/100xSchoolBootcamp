#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void selectionSort(int *arr, int n)
{
    for(int i=0; i<n; i++){
        // find min in the unsorted region/array :- [i,n-1]
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        // swap min with i
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void print(int *arr, int n)
{
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    print(arr, n);
    selectionSort(arr, n);
    print(arr, n);
    
    return 0;
}