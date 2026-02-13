#include <iostream>
using namespace std;


int main(){

    // 2D Arrays - Collection of 1D arrays
    //           - It have rows and columns

    int n,m;    // n-rows, m-cols
    cin >> n >> m;

    int arr[n][m];

    // 2D array input 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }


     // Find the min element in each row in 2D array
    // /*
    for(int i=0; i<n; i++){
        int min = arr[i][0];
        for(int j=0; j<m; j++){
            if(arr[i][j] < min){
                min = arr[i][j];
            }
        }
        cout << min << " ";
    }
    // */


    // Find the maximum element in 2D array
    /*
    int max = arr[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] > max){
                max = arr[i][j];
            }
        }
    }
    cout << max << endl;
    */


    // Print boudary ele of 2D array -> braking into small problem
    /*
    for(int j=0; j<m; j++){     // first row
        cout << arr[0][j] << " ";
    }
    for(int i= 1; i<n; i++){     // last col
        cout << arr[i][m-1] << " ";
    }
    for(int j= m-2; j>=0; j--){     // last row
        cout << arr[n-1][j] << " ";
    }
    for(int i=n-2; i>=1; i--){     // first col
        cout << arr[i][0] << " ";
    }
    */

    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
           if(i==0 || i==n-1 || j==0 || j==m-1){
            cout << arr[i][j] << " ";
           }
        //    else{
        //     cout << "  ";
        //    }
        }
        // cout << endl;
    }
        */


    // Print 2D array in wave col wise
    /*
    for(int j=0; j<m; j++){
        // odd : bottom->top
        if(j&1){
            for(int i=n-1; i>=0; i--){
                cout << arr[i][j] << " ";
            }
        }
        // even : top->bottom
        else{
            for(int i=0; i<n; i++){
                cout << arr[i][j] << " ";
            }
        }
        // cout << endl;
    }
    */


    /* 
    //Print 2D array in wave row wise
    for(int i=0; i<n; i++){
        // odd -> right to left
        if(i&1){
            for(int j=m-1; j>=0; j--){
                cout << arr[i][j] << " ";
            }
        }// eve -> left to right
        else{
            for(int j=0; j<m; j++){
                cout << arr[i][j] << " ";
            }
        }
        // cout << endl;
    }
    */


    // Print 2D array col wise
    /*
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
        */


    // printing 2d array : default row wise
    /*
    cout << "2D Array : " << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    */
    

    return 0;
}