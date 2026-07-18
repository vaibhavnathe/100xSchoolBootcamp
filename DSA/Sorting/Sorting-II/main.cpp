// *** Sorting-II -  till 52 mins
 
// main.cpp - Count Sort
 
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
// Q.2] Sort a string -> Given a all small(a-z) or all Capital(A-Z) letters or both, sort a string
void sortString(string &str)
{
    // ii) optimal approach :- Using count Sort - Store all chars in map with their freq & print according to their freq
    int freq[26] = {0};        // a-z or A-Z -> (26 chars)
    // map<char, int> freq;        // for both (a-z, A-Z) 52 chars

    for(auto ch : str){
        freq[ch-'a']++;     // for either lower or uppercase chars
        // freq[ch]++;      // for both upper & lowercase chars
    }

    // print ele's in order according to their freq
    for(int i=0; i<26; i++){
        while(freq[i]--){
            char ch = i + 'a';
            cout << ch;
        }
    }
    // for both upper & lowercase chars -> use Map
    // for(auto ele: freq){
    //     while(ele.second--){
    //         cout << ele.first;
    //     }
    // }

    //i) basic approach :- using in-built sort
    // sort(str.begin(), str.end());
    // cout << str << endl;
}
 
 
// Q.1] Largest Number-I -> Given an arr of numbers (0-9). Find largest num from arr by arranging ele's
void largestNumberI(vector<int> &arr)
{
    // 2) optimal approach :- using freq array & then concat/print numbers based on freq & reverse it
    //                  TC - O(N)
    int freq[10] = {0};     // 0-9 - In count Sort -> use array always (arrays are faster than maps)
    for(auto ele: arr){
        freq[ele]++;        // O(N)
    }

    for(int i=9; i>=0; i--) // O(N) - will print ele's which occurs same as in original array
    {
        while(freq[i]--){
            cout << i;
        }
    }

    //1) Simple approach :- Sort array & concat ele from last
    //              TC - O(N * logN)
    /*
    sort(arr.begin(), arr.end());
    int res = 0;

    for(int i=arr.size()-1; i>=0; i--)
    {
        res = res*10 + arr[i];
    }
    cout << res << endl;
    */
}
 
// *** Count Sort - TC-> O(N + K), SC - O(N)
// When you should Count Sort :- K(range of values that we get i/p) is small as compared to N, prefere using count sort
// Ex. 1<=N<=10^6 , 0<=A[i]<=9  -> (YES),  1<=N<=10^6, 0<=A[i]<=10^9 -> (NO)
void countSort(vector<int> &arr)
{
    // approach of count-sort :- using freq array & then print numbers based on freq in order which is already in sorted order
    //                      TC - O(N + K)
    //                      SC - O(K)       // K- range of numbers we get in i/p, like from 0-9 or 0-K

    int freq[10] = {0}; // O(10) - K size     // 0-9 - In count Sort -> use array always (arrays are faster than maps)
    for(auto ele: arr){
        freq[ele]++;        // O(N)
    }

    for(int i=0; i<10; i++) // O(N + K) - will print ele's which occurs same as in original array
    {
        while(freq[i]--){
            cout << i << " ";
        }
    }
}
 
signed main(){

    // int n;
    // cin >> n;
    // vector<int> arr(n);

    // for(int i=0; i<n; i++){
    //     cin >> arr[i];    
    // }

    // Q.2] Sort a string :- Given all small (a-z) chars / all capital(A-Z) chars -> sort a string
    string str;
    cin >> str;
    sortString(str);

    // Q.1] Largest number-I :- make largest using given arr elements
    // largestNumberI(arr);
    // ** Count Sort
    // countSort(arr);

    return 0;
}