#include <bits/stdc++.h>

#define int long long

using namespace std;

// note:- prefer writing recursive/backtracking code in this structure/format like f(idx/curr, arr, n, path)
//      - It will help in DP


// 5] Print all subsequences of an array whose sum = k
void subSequncesOfSumK(int idx, int sum, vector<int> arr, vector<int>path, int k)
{
    // stop/base case -> if idx out of range
    if(idx == arr.size()){
        if(sum == k){   // check if sum == k -> then only print
            // print path
            for(auto ele: path){
                cout << ele << " ";
            }
            cout << endl;
        }
        return;
    }

     // for each ele - 2 option -> take(include) & not take(exclude)
    // 1. take(include) curr ele and also add to sum
    path.push_back(arr[idx]);
    subSequncesOfSumK(idx+1, sum + arr[idx], arr, path, k);
    path.pop_back();

    // 2. not take(exclude) curr ele - don't add in path & in sum, just call
    subSequncesOfSumK(idx+1, sum, arr, path, k);

}

// 5] Print all subsequences of all ele in an array
void printAllSubSequences(int idx, int *arr, int n, vector<int>&path)
{
    // stop/base case -> if idx out of range
    if(idx == n){
        // print path & return
        for(auto ele: path){
            cout << ele << " ";
        }
        cout << endl;
        return;
    }
    
    // for each ele - 2 option -> take(include) & not take(exclude)
    // 1. take(include) curr ele
    path.push_back(arr[idx]);
    printAllSubSequences(idx+1, arr, n, path);      // f(idx+1, arr, n, path)
    path.pop_back();

    // 2. not take(exclude) curr ele - don't add in path , just call
    printAllSubSequences(idx+1, arr, n, path);      // f(idx+1, arr, n, path)
}


// 4] Rat in Maze-II -> same as below, just one condition - cell can be blocked(can't go trhough it/can't consider as path)
void ratInMazeII(int i, int j, int n, int m, int arr[][4], vector<char> path)
{
    // out of grid/matrix - Invalid - always prefer writing this first
    if(i >= n or j >= m){
        return;
    }
    // check blocked cell or not
    if(arr[i][j] == -1){    //-1 -> blocked cell
        return;
    }
    // print path once rat reach to target cell
    if(i == n-1 and j == m-1){
        for(auto ch: path){
            cout << ch << " ";
        }
        cout << endl;
        return;
    }

    // now either go right or down
    path.push_back('R');
    ratInMazeII(i, j+1, n,m, arr, path);
    path.pop_back();

    // Down
    path.push_back('D');
    ratInMazeII(i+1, j, n, m, arr, path);
    path.pop_back();
}

// 3] Rat in a Maze :- Given a grid/matrix n x m - rat is at (0,0) ,target(n-1, m-1) -> how many ways rat can reach to target , print paths(R-rigth D-down)
void ratInMaze(int i, int j, int n, int m, vector<char> path)
{
    // out of matrix case - Invalid -> prefer writing this case first
    if(i >= n or j >= m){
        return;
    }

    // base/stop case - if rat reached to target -> print path & returhn
    if(i == n-1 and j == m-1){
        for(auto ch: path)
        {
            cout << ch << " ";
        }
        cout << endl;
        return;
    }
    
    // rat can go either right(i,j+1) or down(i+1,j)
    // right
    path.push_back('R');
    ratInMaze(i, j+1, n, m, path);
    path.pop_back();

    // Down
    path.push_back('D');
    ratInMaze(i+1, j, n, m, path);
    path.pop_back();
}


// 2] Climb Stairs-II :- Given n(no of stairs) & k (max jumps) , print all possible paths
void climbStairsII(int curr, int k, int n, vector<int> path) 
{
    // if reached to the target stair -> valid path - print it & return
    if(curr == n){
        for(auto ele : path){
            cout << ele << " ";
        }
        cout << endl;
        return;
    }

    if(curr > k){   // not valid path
        return;
    }

    // k-jumps
    for(int i=1; i<=k; i++)
    {
        path.push_back(i);
        climbStairsII(curr + i, k, n, path);
        path.pop_back();
    }
}


// 1] Climb Stairs :- Print tha path / no of possible ways to reach to top of n stairs
void climbStairsPath(int curr, int n, vector<int>&path){

    // i) Using recursion approach 2
    if(curr == n){  // reached n -> print path & return
        for(auto ele : path){
            cout << ele << " ";
        }
        cout << endl;
        return; 
    }
    if(curr > n){   // exceeds path -> not valid path
        return;
    }

    // jump of 1
    path.push_back(1);      // add jump of 1 to current path
    climbStairsPath(curr+1, n, path);
    path.pop_back();    // remove 1 after coming from fun call
    // jump of 2
    path.push_back(2);        // add jump of 2 to current path
    climbStairsPath(curr+2, n, path);
    path.pop_back();           // remove 2 after coming from fun call
}

int climbStairs(int n){


    // i) Using recursion approach 1
    // /*
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    int curr = climbStairs(n-1) + climbStairs(n-2);
    return curr;
    // */
}

signed main()
{
    // int n,m;
    // cin >> n >> m;
    vector<int> path;

    // 6] Print all subsequences of array whose sum = k
    vector<int> arr = {1,-1,2,0,-2};
    int k = 0;
    subSequncesOfSumK(0, 0, arr, path, k);  // f(idx,sum, arr, path, k)

    // 5] Print all subsequences of all ele in an array
    /*
    int arr[] = {10,3,6};
    printAllSubSequences(0, arr, 3, path);  // f(idx, arr, n, path)
    */

    // 4] Rat in Maze-II -> same as below, just one condition - cell can be blocked(can't go trhough it/can't consider as path)
    /*
    int arr[][4] = {    
        {0,0,-1,0},     // -1 -> blocked cell
        {0,0,0,-1},
        {0,-1,0,0},
        {0,0,0,0}
    };
    ratInMazeII(0,0,4,4,arr,path);
    */


    // 3] Rat in a Maze :- Given a grid/matrix n x m - rat is at (0,0) ,target(n-1, m-1) -> how many ways rat can reach to target , print paths(R-rigth D-down)
    // ratInMaze(0,0,n,m,path);

    // 2] Climb Stairs-II :- Given n(no of stairs) & k (max jumps) , print all possible paths
    /*
    int k;
    cin >> k;
    climbStairsII(0, k, n, path);
    */

    // 1] Climb Stairs :- no of possible ways to reach to top of n stairs
    // climbStairsPath(0,n,path);
    // int ans = climbStairs(n);
    // cout << ans << endl;

    return 0;
}