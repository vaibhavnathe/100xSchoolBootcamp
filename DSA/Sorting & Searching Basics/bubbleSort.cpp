#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int *arr, int n)
{
    for(int i=n-1; i>=1; i--){
        // placing max ele from unsorted array to the last place of unsorted
        for(int j=0; j<i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleSortOptimized(int *arr, int n)
{
    for(int i=n-1; i>=1; i--){
        // placing max ele from unsorted array to the last place of unsorted
        // [0,i] -> unsorted, swap there
        bool swapped = false;
        for(int j=0; j<i; j++){
            // if no swap happen means -> array is already sorted then break
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        // cout << isSwap << endl;

        if(swapped == false){
            break;
        }
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
    // bubbleSort(arr, n);
    bubbleSortOptimized(arr, n);
    print(arr, n);
    
    return 0;
}