#include <bits/stdc++.h>

using namespace std;

// 4] find sum of the array
int sumOfArray(int *arr, int n)
{
    // using recursion : task -> find sum in array, need to return it
    //                 breackdown -> recursion will return sum from left array till curr ele, i just need compare it with curr ele & return it
    //                              int sum = f(arr, n-1) + arr[n-1],    f(arr, n-1)-> will return sum from left remaining array, 
    //                              return sum
    //                base/stop - 2 ways -> i) if(n == 1) return arr[0];   - array contain only one ele, so return it
    //                                     ii) if(n == 0) return 0;  -  if no ele -> sum=0

    if(n == 1){
        return arr[0];     // base/stop case - array contain only one ele, so return it
    }
    int sum = sumOfArray(arr, n-1) + arr[n-1];   // recursion will return sum from from left array till curr ele,
    return sum;          
}

// 4] find max ele in array
int maxEleInArray(int *arr, int n)
{
    // using recursion : task -> find min ele in array, need to return it
    //                 breackdown -> recursion will return minEle from till curr ele, i just need compare it with curr ele & return it
    //                              int minELe = min(f(arr, n-1), arr[n-1]),    f(arr, n-1)-> will return minEle from previous, 
    //                              return minEle
    //                base/stop - 2 ways -> i) if(n == 1) return arr[0];   - array contain only one ele, so return it
    //                                     ii) if(n == 0) return INT_MIN;  - eventually will compare with min ele, minEle = min(x, INT_MAX) => x

    if(n == 0){
        return INT_MIN;     // can alos use-> if(n == 1) return arr[0];   - array contain only one ele, so return it
    }
    int maxEle = maxEleInArray(arr, n-1);   // recursion will return minEle from till curr ele,
    return max(maxEle, arr[n-1]);           // I just need compare it with curr ele & return it
}

// 3] find min ele in array
int minEleInArray(int *arr, int n)
{
    // using recursion : task -> find min ele in array, need to return it
    //                 breackdown -> recursion will return minEle from till curr ele, i just need compare it with curr ele & return it
    //                              int minELe = min(f(arr, n-1), arr[n-1]),    f(arr, n-1)-> will return minEle from previous, 
    //                              return minEle
    //                base/stop - 2 ways -> i) if(n == 1) return arr[0];   - array contain only one ele, so return it
    //                                     ii) if(n == 0) return INT_MAX;  - eventually will compare with min ele, minEle = min(x, INT_MAX) => x

    if(n == 0){
        return INT_MAX;     // can alos use-> if(n == 1) return arr[0];   - array contain only one ele, so return it
    }
    int minEle = minEleInArray(arr, n-1);   // recursion will return minEle from till curr ele,
    return min(minEle, arr[n-1]);           // I just need compare it with curr ele & return it
}

// 2] Print array in same order
void printArray(int *arr, int n)
{
    // ii) using recursion :- task - print in reverse like arr[n-1], arr[n-2] ... arr[0]
    //                      breakdown - fn(arr, n-1), then print(arr[n-1]),
    //                      base case - if(n == 0) return
    if(n == 0){
        return;
    }
    printArray(arr, n-1);
    cout << arr[n-1] << " ";

    // i) basic approach :- using loop from n-1 to 0

}


 // 1] Print array in reverse order
void printArrayReverse(int *arr, int n)
{
    // ii) using recursion :- task - print in reverse like arr[n-1], arr[n-2] ... arr[0]
    //                      breakdown - print(arr[n-1]), then fn(arr, n-1)
    //                      base case - if(n == 0) return
    if(n == 0){
        return;
    }
    cout << arr[n-1] << " ";
    printArrayReverse(arr, n-1);

    // i) basic approach :- using loop from n-1 to 0

}

signed main()
{
    cout << "***** Recursion-II *********" << endl;

    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    //3] Find sum of array
    int ans = sumOfArray(arr, n);
    cout << ans << endl;

    //4] Find max ele in array
    // int ans = maxEleInArray(arr, n);
    // cout << ans << endl;

    //3] Find min ele in array
    // int ans = minEleInArray(arr, n);
    // cout << ans << endl;

    // 2] Print array in same order
    // printArray(arr, n);

    // 1] Print array in reverse order
    // printArrayReverse(arr, n);
 
    return 0;
}