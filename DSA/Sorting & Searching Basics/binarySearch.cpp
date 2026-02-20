#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void binarySeach(int *arr, int n, int target)
{
    int flag = false;

    int l = 0;
    int r = n-1;

    while(l <= r)
    {
        int mid = l-((l-r)/2);
    
        if(target == arr[mid]){
            flag = true;
            break;
        }
        else if(target < arr[mid]){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    if(flag){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

}

int main(){

    int n, target;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> target;

    binarySeach(arr, n, target); 

    return 0;
}