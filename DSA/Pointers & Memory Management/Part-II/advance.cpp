#include <bits/stdc++.h>

// #define int long long
#define endl '\n'
using namespace std;

class Vector{
public:
    int *arr;
    int size;

    Vector(int n){
        arr = new int[n];
    }

    // size vs capacity : size - It is actual no of elements present in array
    //                  Capacity - It is assigned limit of size, when it exceeds then -> new array get's create of double size
    // Ex.  at push_back,   Size =      1   2   3   4   5
    //                      Capacity =  1   2   4   4   8  (here size exceeds capacity, new array will get created by double capacity)

    // when push_back gets called, internally ->If capacity exceeds  then -> It creates new array of size n+1, and copy existing ele into newArr & also add new value. And delete prev arr
    //                                      - If capacity is not exceeded then -> it will just add value to current arr
    void push_back(int val)
    {
        int *newArr = new int[size+1];      // - creates new Array
        for(int i=0; i<size; i++){
            newArr[i] = arr[i];             // - Copy prev array ele's into newArr
        }
        newArr[size] = val;                 // add new value to newArr
        size++;                             // increase siz e
        delete arr;                         // delete prev arr
        arr = newArr;                       // assign newArr to arr (address will get assigned)
    }
};

signed main()
{
    // ******* Vectors Internal ******



    // Ex. Data can not be delete autmatically on Heap -> With great power, come great responsibility
    /*
    int *a = new int[10];
    a[2] = 10;
    a[4] = 12;
    // a is not needed anymore
    a = new int[5];     // problem : here we have reassigned new array to a, but previous array is still on Heap
                        //         - Need to delete it manually from Heap
    */

    /*
    int *num = new int[5];
    num[1] = 10;
    num[3] = 15;
    // delete []num;
    cout << num[1] << endl;     // random value - num is deleted 
    */

    int A[5] = {1,2,3,4,5};
    // some logic after- no longer needd array, need to remove/delete array, can we do this? - NO, it will automatically get deleted once its scope is over
    // delete A;               // can't delete
    // cout << A[3] << endl;   // still accessible 

    //*** */ Stack vs Heap Memory 
    // - TO create anything on heap need to use 'new' keyword which return a pointer
    // ex. ptr -> stack, new int -> heap
    int *ptr = new int;     // ptr stores the address returned by new int (on heap)
    int *a= new int[10];    // a pointer- gets store in stack, which points to actual aaray on Heap
                            // Stack (a-pointer)   ----->  [1,2,3,4,5,6,7,8,9,0] Heap
    a[2] = 7;               // will it work ? - YES , a[2] = *(a + 2)
    cout << a[2] << endl;

    // Stack - Whatever we create, gets created in stack memory and get's removed when function/scope is over
    int x = 10;     // stored in stack memory
    int arr[10];    // in stack 


    // int A[5];   // {, , , , , }
    //Q.] You want to insert one ele at last (x), is it possible to insert/remove any element from the array
    //    -> No, with normal arrays you can't insert/remove elements. Can do in vectors
    /*
    int B[6];
    for(int i=0; i<5; i++){
        B[i] = A[i];
    }
    B[6] = 12;
    A = B;          // error -> can't reassign aaray A with size 6
    A = &B[0];      // error
    */

    return 0;
}

// ** Heap :
//    - Bigger than Stack Memory.
//    - Through address we can access data
//    - Data Can not be deleted automatically, need to manually delete

/* *** Array
    - Drwabacks -> i) We can't insert/remove any element, can just update existing elements.
                  ii) You can't reassign the array. 

    *** Vector :- dynamic array , internally performs DYnamic memory allocation
                - We can do above things in vector

*/