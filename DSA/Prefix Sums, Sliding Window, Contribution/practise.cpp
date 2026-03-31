#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Count vowels from l to r

int main()
{
    string str;
    cin >> str;

    // converting to contribution array -> like 1 0 0 1 0 1 0 1
    int arr[str.size()];
    for(int k=0; k<str.size(); k++){
        if(str[k] == 'a' or str[k] == 'i' or str[k] == 'e' or str[k] == 'o' or str[k] == 'u'){
                arr[k] = 1;
        }
        else{
            arr[k] = 0;
        }
    }

    // creating prefixSum array for it
    int prefix[str.size()];
    int sum = 0;
    for(int i=0; i<str.size(); i++)
    {
        sum += arr[i];
        prefix[i] = sum;
    }


    int q;
    cin >> q;

    for(int i=0; i<q; i++)
    {
        int l,r;
        cin >> l >> r;

        // optimal approach
        if(l == 0){
            cout << prefix[r] << endl;
        }
        else{
            cout << prefix[r] - prefix[l-1] << endl;
        }

        // brute force
        // int count = 0;
        // for(int k=l; k<=r; k++){
        //     if(str[k] == 'a' or str[k] == 'i' or str[k] == 'e' or str[k] == 'o' or str[k] == 'u'){
        //         count++;
        //     }
        // }
        // cout << count << endl;
    }
    
    return 0;
}