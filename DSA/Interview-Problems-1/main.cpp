#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// LeetCode Hard (blinkit SDE)
// 6.] First Missing Positive ele in array.  1 <= N <= 10^6  , 10^-9 <= A[i] <= 10^9
void firstMissingPositive(int *arr, int n)
{
    // observation/hint :- 1 <= ans <= n+1  -> ans lie only between the 1 to n+1

    // Optimal :- Using cyclic sort approach = place all ele at their resp index , if ele <= 0 or ele > n -> ignore
    for(int i=1; i<=n; i++)
    {
        int ele = arr[i-1];
        if(ele < 0 || ele > n){
            continue;   // ignore 
        }

        // place ele at their resp index
        if(ele != arr[ele-1]){
            swap(arr[i-1], arr[ele-1]);     // or swap(arr[i], arr[arr[i]])
            i--;    // to again check the swapped ele
        }
    }

    // check for each ele , if ele != index -> ans = index
    for(int i=0; i<n; i++)
    {
        // cout << arr[i] << " ";
        if(arr[i] != i+1){
            cout << i+1 << endl;
            return;
        }
    }

    // Brute Force :- Using Set - Put all arr ele's in set then check from i=1 to n , if i not exist -> ans
}


// 5.] Find repeating elements in an array / also Find missing ele in an array
//      0 <= arr[i] <= n-1
void findRepeatingMissingEle(int *arr, int n)
{
    // Optimal/Best :- Using Cyclic Sort - replacing/swapping ele's with their same resp index
    for(int i=0; i<n; i++)
    {
        if(arr[i] != arr[arr[i]]){
            swap(arr[i], arr[arr[i]]);
            i--;
        }

        // or
        // int ele = arr[i];
        // if(ele != arr[ele]){
        //     swap(arr[i], arr[ele]);
        //     i--;
        // }
    }

    // printing repeative & missing ele
    cout << "Repeating ele's : ";
    for(int i=0; i<n; i++)
    {
        if(i != arr[i]){
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    cout << "Missing ele : ";
    for(int i=0; i<n; i++)
    {
        if(i != arr[i]){
            cout << i << " ";
        }
    }

    // Better approach :- Using map to store freq of ele's => TC: O(n), SC: o(n)

    // Brute force :- Using nested loops for each ele, we are checking => TC-O(n^2)
}


//4.] print/find subarray with max sum / advanced version of kadane's
void printSubarrayOfMaxSum(int *arr, int n)
{
    int ans = INT_MIN;

    // Optimal Approach :- Using pointer
    int sum = 0;
    int i=0;    // to track the start index of subarray
    int ansL = -1;
    int ansR = -1;
    for(int j=0; j<n; j++)
    {
        if(sum < 0){
            sum = 0;
            i = j;
        }  

        sum += arr[j];
        if(sum > ans){
            ans = sum;
            ansL = i;
            ansR = j;
        }
         
    }

    // printing subarray of max sum
    for(int i=ansL; i<=ansR; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    //Brute Force :- Using nessted loops - Carry-forward technique => O(n^2) , TLE for 1<=N<=10^5

}


//3.] Maximum Subarray Sum/ Kadane's algorithm
void maxSubarraySum(int *arr, int n)
{
    int ans = INT_MIN;

    // Optimal Approach :- Using pointer
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        if(sum < 0){
            sum = 0;
        }
        sum += arr[i];
        ans = max(ans, sum);
    }


    //Brute Force :- Using nessted loops - Carry-forward technique => O(n^2) , TLE for 1<=N<=10^5
    /*
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];
            ans = max(ans, sum);
        }
    }
    */

    cout << ans << endl;
}


//2.] Sort 0's , 1's & 2's
void dutchNationalFlag(int *arr, int n)
{
    // best approach :- three-pointer approach (single-pass solution)
    int i=0;    // for 0's
    int j=0;    // for iteration over array
    int k=n-1;  // for 1's

    while(j <= k)
    {
        if(arr[j] == 0){
            swap(arr[i++], arr[j++]);   // swapping at start    
        }
        else if(arr[j] == 2){
            swap(arr[k--], arr[j]);     // swapping with end, but also need to check the swapped ele whether it is 0,1 or 2
        }
        else{
            j++;   // 1 came -> ignore so that it will come in middle
        }
    }

    // Normal approach :- using in-built sort , or, counting method , or, can use extra array etc.
}

//1.] Sort 0's & 1's
void sortZeroOnes(int *arr, int n)
{
    // Optimal/Better approach :- Using two-pointer approach (one-pass solution)
    int i=0;    // 0's iterator
    int j=0;    // iterator
    while(j < n){
        if(arr[j] == 0){
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }

    // Brute Force: Using counting 0's & 1's , or in-built sort , or using extra array
    /* Two Passes Solution
    int count0 = 0;
    int count1 = 0;

    for(int i=0; i<n; i++){
        if(arr[i] == 0){
            count0++;
        }
        else{
            count1++;
        }
    }
    int i=0;
    while(count0--){
        arr[i++] = 0;
    }
    while(count1--){
        arr[i++] = 1;
    }
    */
}

void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    // LeetCode Hard (blinkit SDE)
    // 6.] First Missing Positive ele in array. 
    firstMissingPositive(arr, n);


    // 5.] Find repeating elements in an array / also Find missing ele in an array
    // findRepeatingMissingEle(arr, n);

    // //4.] print/find subarray with max sum / advanced version of kadane's
    // printSubarrayOfMaxSum(arr, n);

    //Q.3] Max Subarray Sum / Kadane's Algorithm
    // maxSubarraySum(arr, n);

    //Q.2] Dutch-national-flag problem/ sort 0's 1's & 2's
    // dutchNationalFlag(arr, n);

    //Q.1] Sort 0's & 1's
    // sortZeroOnes(arr, n);


    // printArray(arr, n);
    
    return 0;
}