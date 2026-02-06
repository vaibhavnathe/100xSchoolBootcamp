#include <iostream>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    // Find the duplicate ele in array
    // /*
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count == 2){
            cout << arr[i] << endl;
            break;
        }
    }
        // */


    // Unique element in the array

    // Approach 2:- Using XOR (^) operator. 1^0, 0^1 = 1, 1^1, 0^0=0
    /*
    int ans = 0;
    for(int i=0; i<n; i++){
        ans ^= arr[i];
    }
    cout << ans << endl;
    */
    
    // Approach 1:- using count by nested loops
    /*
    for(int i=0; i<n; i++){
        int count = 1;
        for(int j=0; j<n; j++){
            if(arr[i] == arr[j] and i!=j){
                count++;
            }
        }
        if(count == 1){
            cout << arr[i] << endl;
            break;
        }
    }
        */


    // Reverse in the same array
    /*
    int i=0;
    int j=n-1;

    while(i <= j){
        swap(arr[i++], arr[j--]);
    }
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    */


    // Swap alternate ele in an array
    /*
    for(int i=1; i<n; i+=2){
        swap(arr[i], arr[i-1]);
    }
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    */


    // Sort 0's and 1's in an array
    // aproach 2 - using pointer approach
    /*
    int i=0;
    int j=0;
    while(j < n){
        if(arr[j] == 0){
            // int temp = arr[j];
            // arr[j] = arr[i];
            // arr[i] = temp;
            swap(arr[i], arr[j]);   // in-built function
            i++;
        }
        j++;
    }
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    */

    // aproach 1 - using count 0's and 1's
    /*
    int c0 = 0;
    int c1 = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            c0++;
        }
        else{
            c1++;
        }
    }
    while(c0--){
        cout << 0 << " ";
    }
    while(c1--){
        cout << 1 << " ";
    }
    */


    // Check if array is sorted or not in asceding order
    /*
    bool isSorted = true;
    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            isSorted = false;
            break;
        }
    }
    if(isSorted){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    */



    // COunt occurences of an ele in the array 
    /*
    int target;
    cout << "Enter target ele : ";
    cin >> target;
    int count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            count++;
        }
    }
    cout << "Count : " << count << endl;
    */


    // Search in the array 
    /*
    int target;
    cout << "Enter target ele to search : ";
    cin >> target;
    bool isFound = false;
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            isFound = true;
            break;
        }
    }
    if(isFound){
        cout << "Found" << endl;
    }
    else{
        cout << "Not Found" << endl;
    }
    */


    // Find Min element with location(1 to n) in an array 
    /*
    long long min = arr[0];
    int pos = 1;
    for(int i=1; i<n; i++){
        if(arr[i] < min){
            min = arr[i];
            pos = i+1;
        }
    }
    cout << "Min : "<< min << endl;
    cout << "Location : "<< pos << endl;
    */



    // Find Max element with location(1 to n) in an array 
    /*
    long long max = arr[0];
    int pos = 1;
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
            pos = i+1;
        }
    }
    cout << "Max : "<< max << endl;
    cout << "Location : "<< pos << endl;
    */


    // Find sum of an array
    /*
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    cout << "Sum : "<< sum << endl;
    */



    // Print Array in Reverse
    /*
    // n-1 to 0
    for(int i=n-1; i>=0; i--){
        cout << arr[i] << " ";
    }
    cout << endl;
    */


    // Array size , input, output
    /*
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<=n-1; i++){
        cin >> arr[i];
    }

    cout << "Array : ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    */


    // creatint an array of diff data types;
    /*
    int a[20];      // initially it contains garbage value
    float b[30];
    long long c[20];

    // all contains garbage value
    cout << a[5] << endl;
    cout << b[10] << endl;
    cout << c[19] << endl;
    cout << a[100] << endl;
    */



    // Storing Marks of 5 Students -> hard to manage
    // int m1, m2, m3, m4, m5;
    // cin >> m1 >> m2 >> m3 >> m4 >> m5;

    // Storing Marks of 10 Students  -> Hard to manage
    // int m1, m2, m3, m4, m5, m6, m7, m8, m9, m10;

    // Storgin marks of 100 students
    // cin >> m1,m2m3....m100  - to hard to manage

    // Using array -> collection of same type of element
    int marks[10];         // declare with 100 of size
    // marks[1] = 17;
    // marks[4] = 25;
    // marks[9] = 65;

    // input
    // cin >> marks[0] >> marks[1] >> marks[2] >> marks[3];
    /*
    for(int i=0; i<10; i++){
        cin >> marks[i];
    }

    // priting array
    cout << "Marks : ";
    for(int i=0; i<10; i++){
        cout << marks[i] << " ";
    }
    cout << endl;
    */

    return 0;
}