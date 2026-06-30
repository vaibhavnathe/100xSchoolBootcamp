#include <bits/stdc++.h>
#define int long long
using namespace std;

// Backtracking - III 

// Problems - i) Rat in a Maze (4 directions)
//          - ii) Permutations
//          - ii) N Queens
//          - iv) Sudoku Solver


// iv)  Sudoku Solver
bool canPlace(int r, int c, vector<vector<char>> board, int n, char val){

    // need to check same row, col & box(3*3)
    // same row
    for(int j = 0; j<n; j++){
        if(board[r][j] == val){
            return false;
        }
    }
    // same col
    for(int i=0; i<n; i++){
        if(board[i][c] == val){
            return false;
        }
    }
    // same box: for any cell (i,j) -> get start box(sr, sc) - all starting boxes[(0,0), (0,3), (0,6), (3,0), (3,3), (3,6), (6,0), (6,3), (6,6) ]
    //                                                      - all are multiples of 3, to get starting box(sr, sc)
    int sr = (r/3) * 3;     // ex. for cell (4,5) -> start row = (4/3)*3 = 3
    int sc = (c/3) * 3;     //                    -> start col = (5/3)*3 = 3

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[sr+i][sc+j] == val){
                return false;
            }
        }
    }

    // here - means val is not found in same row,col & box
    return true;

}
 
// this fun will give all possible solutions -> no one asks for all soln & will lead to TLE & MLE
void sudokuAllSol(int i, int j, vector<vector<char>> &board, int n){
    // 1 to 9 numbers - exactly once in row, col & curr 3x3 grid

    // base case/stop case - all rows completed 
    if(i == n){
        // print board & return
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << board[i][j];
            }
            cout << endl;
        }
        return;
    }

    // if col/j went out of scope/board in curr row -> go to nexxt row
    if(j == n){
        sudokuAllSol(i+1, 0, board,n);
        return;
    }

    // check if curr cell already have an ele -> go to next cell
    if(board[i][j] != '.'){
        sudokuAllSol(i, j+1, board,n);
    }
    else{   // if not -> place digits from 1 to 9
        for(int val=1; val <=9; val++){
            // can we place curr digit in curr cell -> yes- place & then go to next cell
            if(canPlace(i,j,board,n, val)){
                board[i][j] = val;
                sudokuAllSol(i, j+1, board,n);
                board[i][j] = '.';
            }
        }
    }
}
 
// Only one possible solution -> once get correct board soln then return true & in main print board
bool sudoku(int i, int j, vector<vector<char>> &board, int n){
    // 1 to 9 numbers - exactly once in row, col & curr 3x3 grid

    // base case/stop case - all rows completed 
    if(i == n){
        // return true - we got correct board return true
        return true;
    }

    // if col/j went out of scope/board in curr row -> go to nexxt row
    if(j == n){
        return sudoku(i+1, 0, board,n);
    }

    // check if curr cell already have an ele -> go to next cell
    if(board[i][j] != '.'){
        return sudoku(i, j+1, board, n);
    }

    // if not -> try to place digits from 1 to 9
    for(char val='1'; val <='9'; val++){
        // can we place curr digit in curr cell -> yes- place & then go to next cell
        if(canPlace(i,j,board,n, val)){
            board[i][j] = val;
            bool ans = sudoku(i, j+1, board,n);
            if(ans == true){
                return true;        // once we get our ans true, then return from there 
            }
            board[i][j] = '.';      // if not - then backtrack & check for other no's
        }
    }
    return false;
}
 

// iii) N-QUeens
bool canPlaceQueen(int row, int col, vector<vector<char>> &board, int n)
{
    // for each cell - need to check
    
    // same col
    int i=row;
    int j = col;
    while(i >=0 ){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--;
    }
    
    // diagonal 1 - left upper diag
    i = row;
    j = col;
    while(i >= 0 and j >= 0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--;
        j--;
    }
    
    // diagonal 2 - right upper diag
    i = row;
    j = col;
    while(i >= 0 and j < n){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--;
        j++;
    }
    
    // if all above clears means -> no Q in same col, diag1, & diag2
    return true;
}

void nQueens(int row, vector<vector<char>> &board, int n, vector<vector<vector<char>>> &res)
{
    // base/stop condition - if row goes out of range/drid
    if(row == n){
        // print board & return
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        res.push_back(board);
        return;
    }
    
    // for each row - need to check for each cell -> can we place queen or not
    for(int col = 0; col<n; col++)
    {
        if(canPlaceQueen(row, col, board, n)){
            board[row][col] = 'Q';
            nQueens(row+1, board, n, res);
            board[row][col] = '.';
        }
    }
}

// ii) Permutations - print all possible permutations
//                  - ex. A = [1,2,3] , -> [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]

void f(int idx, vector<int> arr, vector<int> path, vector<bool> &visited, vector<vector<int>> &res)
{
    // base/stop case - 
    if(idx == arr.size()){
        res.push_back(path);
        return;
    }
    
    // check curr ele is already takem -> return
    // if(visited[idx]){
    //     return;
    // }
    
    // choices we have : at 1st place , can take 1 or 2 or 3 till n ele's
    for(int i=0; i<arr.size(); i++)
    {
            if(!visited[i])
            {
                path.push_back(arr[i]);
                visited[i] = true;
                f(idx+1, arr, path, visited, res);
                path.pop_back();
                visited[i] = false;
            }
    }
}

// i) Rat in a Maze (4 directions)
void ratInMaze(int i, int j, vector<vector<int>> &grid, int n, string &path,  vector<string> &res)
{
    // out of matrix/grid
    if(i == n or i < 0 or j == n or j < 0){
        return;
    }
    
    // blocked cell / already visited cell - return
    if(grid[i][j] == 0){
        return;
    }
    
    // already visited cell - return  (using visited arrays)
    // if(visited[i][j]){
    //     return;
    // }
    
    // reached target/last cell
    if(i == n-1 and j == n-1){
        res.push_back(path);
        return;
    }
    
    // need to marked current cell as visited
    // visited[i][j] = true;    // using visited array
    grid[i][j] = 0;         // without using visited array
   
  // choices - down, left 
   
 // Down
    path += 'D';
    ratInMaze(i+1, j, grid, n, path, res);
    path.pop_back();
    
    // Left
    path += 'L';
    ratInMaze(i, j-1, grid, n, path, res);
    path.pop_back();
    
    // Right
    path += 'R';
    ratInMaze(i, j+1, grid, n, path, res);
    path.pop_back();
    
    // Up
    path += 'U';
    ratInMaze(i-1, j, grid, n, path, res);
    path.pop_back();
    
    // After visiting one coomplete path, need to marked curr cell back as un-visited
    // visited[i][j] = false;  // using visited array
    grid[i][j] = 1;         // without using visited array
}



signed main()
{

    // iv) Sudoku Solver
    /*
    int n = 9;
    vector<vector<char>> board(n, vector<char> (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    // f(0,0,board,n);      // all possible solutions
    bool ans = f2(0,0, board, n); 
    // cout << ans << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
    */

    // iii) N-Queens
    /*
    int n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<vector<char>>> res;
    nQueens(0, board, n, res);
    
    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++){
            for(int k=0; k<res[i][j].size(); k++){
                cout << res[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
        */
    
    // ii) Permutations
    /*
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> path;
    vector<bool> visited(n, false);
    vector<vector<int>> res;
    f(0, arr, path, visited, res);
    
    cout << res.size() << endl;
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }*/


    // i) Rat in a Maze
    /*
    int n;
    cin >> n;

    vector<vector<int>> grid;
    string path;
    vector<string> res;
    ratInMaze(0,0,grid,n, path, res);

    */
    
    return 0;
}



