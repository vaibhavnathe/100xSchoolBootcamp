// Pattern #1 :  FIXED SIZE = K

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void countDistinctEleInEachWindow(int *arr, int n, int k)
{
    map<int, int> mp;

    // first window
    for(int i=0; i<k; i++){
        mp[arr[i]]++;
    }
    cout << mp.size() << " ";

    // remaining windows
    for(int i=k; i<n; i++){
        mp[arr[i]]++;
        mp[arr[i-k]]--;

        if(mp[arr[i-k]] == 0){
            mp.erase(mp.find(arr[i-k]));
        }
        cout << mp.size() << " ";
    }
}

// 2.] Count vowel in each subarray of size k
bool isVowel(char ch){
    if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U')
    {
        return true;
    }
    return false;
}

void countVowelsInEachSubarraySizeK(string str, int k)
{
    int count = 0;

    // first window
    for(int i=0; i<k; i++){
        if(isVowel(str[i])){
            count++;
        }
    }
    cout << count << " ";

    //remaining windows
    for(int i=k; i<str.size(); i++)
    {   
        if(isVowel(str[i])){
            count++;
        }
        if(isVowel(str[i-k])){
            count--;
        }
        cout << count << " ";
    }
}

// 1.] Max sum of Subarray of size k
int maxSubarraySumOfSizeK(int *arr, int n, int k)
{
    // optimal approach :- using sliding window 
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i=0; i<k; i++){     // first window sum
        sum += arr[i];
    }
    maxSum = max(sum, maxSum);

    //traversing other remaining windows 
    for(int i=k; i<n; i++)
    {
        sum += arr[i];      // added the next ele
        sum -= arr[i-k];    // substract the previous window first ele
        maxSum = max(sum, maxSum);
    }

    // brute force :- using nested loops -> O(n^2)
    /*
    for(int i=0; i<n-k; i++)
    {
        int sum = 0;
        for(int j=i; j<i+k; j++){
            sum += arr[j];
            maxSum = max(sum, maxSum);
        }
    }
    */
    return maxSum;
    
}

int main()
{
    // // Patterns -> diff types of problems , i)   FIXED SIZE = K

    int n,k;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> k;

    // 3] Count distinct elements in every window of size k
    countDistinctEleInEachWindow(arr, n, k);


    // 2.] Count vowels in each subaaray of size k
    // string str;
    // cin >> str;
    // int k;
    // cin >> k;
    // countVowelsInEachSubarraySizeK(str, k);


    /* 1] Max sum of subarray of size k
    int ans = maxSubarraySumOfSizeK(arr, n, k);
    cout << ans << endl;
    */
    
    return 0;
}