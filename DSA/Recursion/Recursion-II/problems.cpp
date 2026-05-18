#include <bits/stdc++.h>

using namespace std;

// 3] Tower Of Hanoi :- 
void towerOfHanoi(int n, char src, char aux, char dest)
{
    // source- A tower, auxillary- B tower, destination- C tower

    if(n == 0){     // base/stop condition
        return;
    }

    // step 1: move top(n-1) disks from src(A)
    towerOfHanoi(n-1, src, dest, aux);

    // step 2: move the largest disk from src(A) to dest(C)
    cout << "Move from " << src << " to " << dest << endl;
    
    // step 3: move all (n-1) disks from aux(B) to dest(C)
    towerOfHanoi(n-1, aux, src, dest);
}


// 2] Check if arrays is sorted or not
bool isSorted(int *arr, int n)
{
    // using recursion :- task - check if array is sorted or not
    //                  breakdown - if(f(arr, n-1) == false) return false; - check left array is sorted or not if not then return false
    //                            - if left array is sorted -> then check currEle >= prevEle
    //                  base case - if n == 1, return true if array have only one ele , then its sorted

    if(n == 1){
        return true;
    }

    bool ans = isSorted(arr, n-1);      // check leftArray , if leftArray is not sorted then return false
    if(ans == false){
        return false;
    }
    
    return arr[n-1] >= arr[n-2];        // check currELe with previosEle
}


// 1] Find first/last/all occurences if X
vector<int> occurences;
void findAllOccurence(int *arr, int n, int x)
{
    // using recursion :- task - find first occ of x in array
    //                  breackdown - if( f(arr, n-1, x) != -2) print(f(arr, n-1, x)) first print occurence from left
    //                             - if(arr[n-1] == x) return n-1 - then check for curr ele == x, return n-1;
    //                             - smallAns = f(arr, n-1), if(smallAns != -1) return smallAns,  
 

    if(n == 0){
        return;      // base case - if array does not have ele, return -1
    }
    findAllOccurence(arr, n-1, x); // first print all occurences from left then check currEle
    if(arr[n-1] == x){
        occurences.push_back(n-1);        //then check curr ele if currEle == x, return n-1
    }
}


int findLastOccurence(int *arr, int n, int x)
{
    // using recursion :- task - find first occ of x in array
    //                  breackdown - first check currEle == x , if yes then return it, if not then check recursion ans & return it, if rec ans == -1, then return -1
    //                             -  if(arr[n-1] == x) return n-1: firstc check currElc then if currEle not ans -> then check recursion ans
    //                             - smallAns = f(arr, n-1), if(smallAns != -1) return smallAns,  
 

    if(n == 0){
        return -1;      // base case - if array does not have ele, return -1
    }
    if(arr[n-1] == x){
        return n-1;         //first check curr ele if currEle == x, return n-1
    }

    int smallAns = findLastOccurence(arr, n-1, x);
    return smallAns;    // if rec gave ans from left then return it

}

int findFirstOccurence(int *arr, int n, int x)
{
    // using recursion :- task - find first occ of x in array
    //                  breackdown - recursion will return ans/index from left array till currEle, i just need to check if recursion gave ans -> return it otherwise check curr ele
    //                             - smallAns = f(arr, n-1), if(smallAns != -1) return smallAns,  
    //                             - if(arr[n-1] == x) return n-1, else return -1 : if recursion gave -1, then need to check curr ele 

    if(n == 0){
        return -1;      // base case - if array does not have ele, return -1
    }
    int smallAns = findFirstOccurence(arr, n-1, x);
    if(smallAns != -1){
        return smallAns;    // if rec gave ans from left then return it
    }

    if(arr[n-1] == x){
        return n-1;         // check curr ele if currEle == x, return n-1
    }
    else{
        return -1;          // if not then return -1
    }

}

signed main()
{
    cout << "***** Recursion-II Problems *********" << endl;

    int n,x;
    cin >> n;

    // int arr[n];
    // for(int i=0; i<n; i++)
    // {
    //     cin >> arr[i];
    // }

    // 3] Tower of Hanoi :- shifts all disks from Src(A-tower) to Destination(C-tower) with the help of Auxillary(B-tower)
    towerOfHanoi(n, 'A', 'B', 'C');
    

    // 2] Check if array is sorted or not
    /*
    bool ans = isSorted(arr, n);
    if(ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
        */

    // 1] Find first/last/all occurences if X
    /*
    // cin >> x;
    findAllOccurence(arr, n, x);
    if(occurences.size() != 0){
        for(auto ele: occurences){
            cout << ele << " ";
        }
    }
    else{
        cout << -1 << endl;
    }
        */
    // int ans = findLastOccurence(arr, n,x);
    // int ans = findFirstOccurence(arr, n,x);
    // cout << ans << endl;

}