#include <bits/stdc++.h>

#define int long long

using namespace std;

// merge fn :- first counting logic then merge logic
int merge(vector<int>&A, int l, int r)
{
    int mid = l - ((l-r)/2);
    
    int i=l; 
    int j=mid+1;
    
    // counting logic 
    int count = 0;
    while(i<=mid and j <= r){
        if(A[i] > 2*A[j]){
            count += mid-i+1;
            j++;
        }
        else{
            i++;
        }
    }
    
    i = l;
    j = mid+1;
    // Merge logic
    vector<int> temp;
    while(i <= mid and j <= r){
        if(A[i] <= A[j]){
            temp.push_back(A[i++]);
        }
        else{
            temp.push_back(A[j++]);
        }
    }
    
    while(i <= mid ){
            temp.push_back(A[i++]);
    }
    
    while(j <= r){
            temp.push_back(A[j++]);
    }
    
    int index = 0;
    for(int i=l; i<=r; i++){
        A[i] = temp[index++];
    }
    
    return count;
}

int f(vector<int>&A, int l, int r)
{
    if(l == r){
        return 0;
    }
    
    int mid = l - ((l-r)/2);
    
    int ans1 = f(A, l, mid);
    int ans2 = f(A, mid+1, r);
    int ans3 = merge(A, l, r);
    
    return ans1 + ans2 + ans3;
}

signed main()
{
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    
    int ans = f(A, 0, A.size()-1);
    cout << ans << endl;
    for(auto ele: A){
        cout << ele << " ";
    }
    
    return 0;
}