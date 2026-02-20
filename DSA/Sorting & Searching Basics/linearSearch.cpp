#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void linearSearch(int *arr, int n, int target)
{
    bool flag = false;

    for(int i=0; i<n; i++){
        if(arr[i] == target){
            flag = true;
            break;
        }
    }

    if(flag){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main()
{
    int n, target;
    cin >> n;

    int num[n];
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    cin >> target;

    linearSearch(num, n, target);
    
    return 0;
}