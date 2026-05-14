#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int checkIthBit(int n, int i)
{
    int mask = 1<<i;
    return (n&mask) == 0 ? 0 : 1;
}

int setIthBit(int n, int i)
{
    int mask = 1 << i;
    return n | mask;
}

// 5] Print all Subsets of an array
void printAllSubsets(int *arr, int n)
{
    // approach :- there will be 2^n=(1<<n) subsets, using binary -> can decide whether ele should take or not, 1-taken, 0-not taken
    for(int mask = 0; mask < (1<<n) ; mask++)   // 2^n/(1<<n) subsets -> loop to cover alll subsets
    {
        for(int i=0; i<n; i++)      // loop over an array
        {   
            if(checkIthBit(mask, i) == 1){      // checking ith bit of mask , 1-ele need to taken
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

}

// 4] Single Number 3 :- GIven an array of ele, where all ele occurs twice, only 2 ele's occurs once, find those unque ele's
void singleNumber3(int *arr, int n)
{
    //ii) optimal approach :- Using xor, & based on xor ans find position of set bit , then divide ele into 2 group based on the 0/1 at that position

    // - xor of entire array
    int xor_arr = 0;
    for(int i=0; i<n; i++)
    {
        xor_arr ^= arr[i];      // we'll always get a number because in question 2 diff unique ele present mention
    }
    //- figure out any position in which they both differ, means 1^0, 0^1 => 1 , position of any set bit in xor_Array
    int pos = -1;
    int k = 32;     // for int-32, long-64 range
    for(int i=0; i<k; i++)
    {
        if(checkIthBit(xor_arr, i) == 1){
            pos = i;
            break;
        }
    }
    // - make groups based on position -> then xor of both groups
    int group1 = 0;
    int group2 = 0;
    for(int i=0; i<n; i++)
    {
        if(checkIthBit(arr[i], pos) == 1){  // if ele's pos'th bit is 1 -> place then in group1 & xor
            group1 ^= arr[i];
        }
        else{  // ele's pos'th bit is 1 -> place then in group2 & xor
            group2 ^= arr[i];
        }
    }
    cout << group1 << endl; 
    cout << group2 << endl; 


    //i) simple approach :- Use hashmap to store frequency of ele, return ele's with freq=1
    //                  - TC - O(1) SC - O(1)
}


// 3] Single Number 2 :- Find unique number in an array, where  every other ele occurs thrice & only one ele occurs once which is ans
void singleNumber2(int *arr, int n)
{

    // ii) optimal approach :-Using bits columns & if each ele occurs thrice then sum of each bit col of all ele is %3=0 , 
    //                      - if imposter(unque ele) is added then %3 != 0, so that col bit is disturbed, so we can set the same col bit of ans
    //                      - O(K*logN), SC- O(1)
    int ans = 0;
    int k = 32;     // int range 0-32, long range - 0-64
    for(int j=0; j<k; j++){     // loop for traversing over each bit col of ele range from k=0-32/64
        int sum = 0;
        for(int i=0; i<n; i++){ // loop for traversing over an array
            if(checkIthBit(arr[i], j) == 1){
                sum++;
            }
        }
        if(sum%3 != 0){
            ans = setIthBit(ans, j);
        }
    }
    cout << ans << endl;

    // i) simple approach :- Using Hashmap to store freq of elements
    // /                   - TC - O(N) , SC - O(N)
}

// 2] Sigle number 1 :- find unique ele in sorted array
void uniqueEleSorted(int *arr, int n)
{
    // optimal appriach:- using binary search , TC - O(LogN), SC-O(1)
    int ans = -1;

    int start = 0;
    int end = n-1;

    while(start <= end)
    {
        int mid = start - ((start-end)/2);

        if(mid&1){  // mid is odd index
            if(arr[mid] == arr[mid-1] && mid >= 0)
            {
                start = mid+1;
            }
            else if(arr[mid] == arr[mid+1] && mid+1 <n)
            {
                end = mid-1;
            }
            else{
                ans = arr[mid];
                break;
            }
        }
        else{   // even index
            if(arr[mid] == arr[mid+1] && mid < n)
            {
                start = mid+2;
            }
            else if(arr[mid] == arr[mid-1] && mid >= 0)
            {
                end = mid-2;
            }
            else{
                ans = arr[mid];
                break;
            }
        }
    }

    cout << ans << endl;
}

 // 1] Single Number 1 :- Given an array of numbers(can be shuffeled ), every ele occurs twice. Find the unique ele ehich occurs once
void uniqueEle(int *arr, int n)
{
    int ans = 0;

    // iii) Optimal approach :- usin XOR (^) apporach
    for(int i=0; i<n; i++)
    {
        ans ^= arr[i];
    }

    // ii) better approach :- using map, if freq=1 -> unique ele
    //                      - TC - O(N), SC - O(N)

    // i) brute force :- using nested loop checking freq for each ele, if freq == 1 -> unque ele
    //                 - TC - O(n^2), SC - O(1)

    cout << ans << endl;
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

    // 5] Print all substes of an array
    printAllSubsets(arr, n);

    // 4] Single Number 3 :- GIven an array of ele, where all ele occurs twice, only 2 ele's occurs once, find those unque ele's
    // singleNumber3(arr, n);

    //3] Single Number 2 :-  Find unique number in an array, where  every other ele occurs thrice & one ele occurs once which is ans
    // singleNumber2(arr, n);

    // 2] Single Number 1 :- Given an sorted array of numbers, every ele occurs twice. Find the unique ele ehich occurs once
    // uniqueEleSorted(arr,n);

    // 1] Single Number 1 :- Given an array of numbers(can be shuffeled ), every ele occurs twice. Find the unique ele ehich occurs once
    // uniqueEle(arr,n);
    
    return 0;
}