#include <iostream>
using namespace std;

// int -> 10^9
// long long -> 10^18

/*7. Spiral Martix -> Print the matrix in spiral manner*/
void spiralMatrix(int arr[][100], int n, int m)
{
    int startRow = 0;
    int endRow  = n-1;
    int startCol  = 0;
    int endCol  = m-1;

    while(startRow <= endRow and startCol <= endCol)
    {
        // 1st row :- i=startRow,  j=startCol to endCol 
        for(int j=startCol; j<=endCol; j++){
            cout << arr[startRow][j] << " ";
        }
        startRow++;

        // last col :- i=startRow to endRow row, j=endCol
        for(int i=startRow; i<=endRow; i++){
            cout << arr[i][endCol] << " ";
        }
        endCol--;

        // last row :- i=endRow, j=endCol to startCol
        if(startRow <= endRow and startCol <= endCol){
            for(int j=endCol; j>=startCol; j--){
                cout << arr[endRow][j] << " ";
            }
            endRow--;
        }

        // first col :- i=endRow to startRow , j=startCol
        if(startRow <= endRow and startCol <= endCol){
            for(int i=endRow; i>=startRow; i--){
                cout << arr[i][startCol] << " ";
            }
        }
        

        // Moving into inner layer after doing boundary traversal for outer layer
        startCol++;
    }
    
}


/*6. Rotate Image*/
/**
void rotateImage(int arr[][100], int n)
{
    // approach 2: printing each column in reverse order
    for(int j=0; j<n; j++){
        for(int i=n-1; i>=0; i--){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }


    // approch 1: transpose & then reverse rows
 
    // step 1: transpose the array
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<=i; j++){
    //         swap(arr[i][j], arr[j][i]);
    //     }
    // }
    // step 2: reverse the rows
    // for(int i=0; i<n; i++){
    //     int j=0;
    //     int k=n-1;
    //     while(j<=k){
    //         swap(arr[i][j++], arr[i][k--]);
    //     }
    // }
}
*/


/*5. Diagonal Sum :- from right side*/
int diagonalSumFromRight(int arr[][100], int n)
{
    int sum = 0;

    int i=0;
    int j=n-1;

    while(i < n and j >=0){
        sum += arr[i][j];
        i++;
        j--;
    }

    return sum;
    
   
}


/*4. Diagonal Sum*/
int diagonalSum(int arr[][100], int n)
{
    int sum = 0;

    /* approach 2: using only one loop and use same pointer as arr[i][i]*/
    for(int i=0; i<n; i++){
        sum += arr[i][i];
    }

    // approach 1: process each ele & check i==j
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                sum += arr[i][j];
            }
        }
    }
    */

    return sum;
    
   
}


/*3. Longest Word length */
int lengestWord(string str)
{
    int maxLen = 0;

    /*Appraoch 1:*/
    // /** 
    string word = "";

    for(int i=0; i<str.size(); i++)
    {
        if(str[i] != ' '){
            word += str[i];
        }
        else if(str[i] == ' ' and word.size() > 0){
            if(word.size() > maxLen){
                maxLen = word.size();
            }
            word = "";
        }
    }
    if(word.size() > maxLen){
        maxLen = word.size();
    }

    return maxLen;
    //  */


    /*Approach 2: using same i,j pointer -> o(n^2)*/
    /*
    int i=0;
    while(i<str.size()){
        if(str[i] == ' '){
            i++;
            continue;
        }

        int j=i;
        int len = 0;
        while(j<str.size() and str[j] != ' '){
            len++;
            j++;
        }

        if(len >= maxLen){
            maxLen = len;
        }
        i=j;
    }
    return maxLen;
    */
    
}


/*2. Compress String */
void compressString(string str)
{
    /* Approch 2*/
    // /** 
    char currChar = str[0];
    int count = 1; 

    for(int i=1; i<str.size(); i++){
        if(str[i] == currChar){
            count++;
        }
        else{
            cout << currChar;
            if(count > 1){
                cout << count;
            }
            currChar = str[i];
            count = 1;
        }
    }
    cout << currChar;
    if(count > 1){
        cout << count << endl;
    }
    // */


    // Apprach 1: using i,j pointer
    /*
    int i=0;

    while(i<str.size()){
        int j=i;
        int count = 0;

        while(str[i] == str[j] and j<str.size()){
            count++;
            j++;
        }
        cout << str[i];
        if(count > 1){
            cout << count;
        }

        i=j;
    }
        */

}


/*1. Sum of Digits*/
int sumOfDigits(string str)
{
    int n = str.size();
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += str[i] - 48; 
        // sum += str[i] - '0'; 
    }
   
    return sum;

    /*  only for int & long long range
    int sum = 0;
    while(n){
        int rem = n%10;
        sum += rem;
        n /= 10;
    }
    return sum;
    */
}


void print2DArray(int arr[][100], int n)
{
    cout << "2D Array : " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    /*6. Spiral Matric :- Give a 2D array , print in spiral manner*/
    int n, m;
    cin >> n >> m;
    int arr[n][100];      // max size for just to pass in function, originally we use n as size
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    spiralMatrix(arr, n, m);


    /*5. Rotate Image :- Given a new 2D array of n*n size, rotate it by 90 degree clockwise*/
    /*
    int n;
    cin >> n;
    int arr[100][100];      // max size for just to pass in function, originally we use n as size
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    rotateImage(arr, n);
    // print2DArray(arr, n);
    */


    /*4. Diagonal Sum :- Given N*N matrix, find the sum of diagonal elements*/
    /*
    int n;
    cin >> n;
    int arr[100][100];      // max size for just to pass in function, originally we use n as size
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    // int sum = diagonalSum(arr, n);
    int sum = diagonalSumFromRight(arr, n);
    cout << sum << endl;
    */


    /*3. Longest Word length :-  i/p = "  I  am   Learning   DSA" , o/p = 8*/
    // string str;
    // getline(cin, str);
    // int ans = lengestWord(str);
    // cout << ans << endl;

    

    /*2. Compress string : ex. i/p = aaabbddccc , o/p = a3b2d2c3 */
    // string str;
    // cin >> str;
    // compressString(str);

    


    /*1. Sum of Digits*/
    // int -> 10^9 , long long -> 10^18 , what if input num is to large than long long also
    // string n;   // we can use string for storing large nums
    // cin >> n;
    // int ans = sumOfDigits(n);
    // cout << ans << endl;
    

    return 0;
}