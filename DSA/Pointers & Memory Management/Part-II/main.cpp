#include <bits/stdc++.h>

// #define int long long 
#define endl '\n'

using namespace std;

// note : In fun when passing an array, only base/starting address get passed 
// Arrays :- Pass by address
void f(int *a, int n)         // here only base address get passed 
{   
    // we don't know how many ele are there in arrays that's why -> always pass size n of an arrays
    cout << sizeof(a) << endl;  // should print 20, but it prints 4 why? -> only array's base address get passed in fun
}

signed main()
{
    // Arrays vs POinters
    int a[5] = {1,2,4,3,5};
    cout << sizeof(a) << endl;          // size of whole arr in bytes -> 4 bytes * 5 = 20 bytes
    cout << sizeof(a)/sizeof(a[0]) << endl;     // size of an arrays using address => 5
    f(a,5);

    //Ex. Sort vector in range using addresses
    // vector<int> A = {5,4,3,2,1};
    // sort(A.begin()+1, A.begin()+4);      // [startIdx, endIdx) - sort vector in range from index 1 - 3
    // for(auto ele: A){
    //     cout << ele << " ";
    // }
    // cout << endl;


    // *** Iterators & pointer diff :- Iterator are like pointers which stores addresses for containers like Vectors, Sets, Maps, etc.
    //                                 arrays -> pointers to store addresses
    //                                 vector -> iterators to store addresses
    // - Iterators are used with STL like Sets, Vectors, Maps etc.
    /*
    vector<int> A = {1,2,3,4,5};
    auto itr = find(A.begin(), A.end(), 3);    // return an address - but vectors & iterator not allow to print addresses
    int idx = find(A.begin(), A.end(), 3) - A.begin();
    cout << idx << endl;
    // cout << itr << endl;             // can't print an iterator
    cout << *itr << endl;               // can print value at that address
    */


    /******* Pointers Arithmetic ***** */
    /*
    int A[5] = {1,2,3,4,5};             
    int* ptr = find(A+1, A+5, 4);     //find(startAddress, endAddress, value) -> return an address of 3, if ele is not present -> will return address of next of last ele
    cout << ptr << endl;            // 0x61fef0
    cout << &A[2] << endl;          // 0x61fef0 - to verify same as ptr

    // how can we get an index of 3 from ptr address
    int index = ptr - A;        // substract the base address (Internally ex. 112 - 100 = 12/4 = 3)
    cout << index << endl;  

    // reverse array / in range
    reverse(A, A+5);            // (startAddress, next_of_endAddress)

    // count ele in array / in range
    int cnt = count(A+1, A+4, 3);       
    cout << cnt << endl;

    */


    // Where pointer arithmatic will be useful -> arrays
    // 3 Questions :- i) Why array ele starts with 0 index, ii) Why array takes O(1) time to access any ele, iii) Why array ele are continous
    //      ans   :- formula :- A[i] = *(A+i) = *(i+A) = i[A]
    /*
    int A[5] = {1,2,3,4,5};
    cout << A << endl;      // base address
    cout << *(A+2) << endl;    // 3 - 2nd index ele
    cout << A[2] << " " << *(A+2) << " " << *(2+A) << " " << 2[A] << endl; 

    for(int i=0; i<5; i++){
        // cout << A[i] << " ";        // internally :- A[i] = *(A+i) - that's why array take O(1) time to access any ele in array
        cout << *(A+i) << " ";      // base address + i(int-> 4-bytes)  - that's why array indexing starts from 0 not 1
        cout << i[A] << " ";
    }
    cout << endl;

    for(int i=0; i<5; i++){
        cout << &A[i] << endl;
        // cout << A+i << endl;     // same as above
     }

     int *ptr1 = &A[1];     // for ex. address = 104
     int *ptr2 = &A[4];     //         address = 116
     cout << ptr2-ptr1 << endl;     // 116-104 = 12/sizeof(int) = 12/4 => 3 
     cout << ptr1-ptr2 << endl;     // 104-116 = -12/sizeof(int) = -12/4 => -3 
     */


    //  int *ptr = &A[2];
    //  cout << *ptr << endl;
    //  ptr++;
    //  cout << *ptr << endl;

    /*
    int x = 10;
    int*ptr = &x;

   cout << x << endl;
   cout <<ptr << endl;
   x++;
   ptr++;               // ptr + 1(4-bytes)
   cout << x << endl;
   cout << *ptr << endl;       // problem - lost x & will get garbage value or Runtime error (Undefine behaviour).
                              //          -undefined behaviour -> Never access unallocated memory
    */

    return 0;
}

// Note: In C++ -  all are dependent on addresses -> Exlusive [start_idx, end_idx] 
//                 functions like : find(A + startIdx, A + end_idx + 1, val), for arrays
//                                 reverse(A + startIdx, A + end_idx + 1), 
//                                 count(A + startIdx, A + end_idx + 1, val)
//                                 sort(A + startIdx, end_idx+1)
// time : find - O(1)
//        reverse - O(1)
//        count - O(1)
//        sort - O(n*logn)

// - C++ gives more control over memory, above function & pass by value or reference ore address etc.

// Arrays -> pointers to store addreses - we can print pointers
// Vectors -> iterators to store addreses - but we can't print iterators
//          - sort(A.begin(), A.end())


// for vectors replace : A -> A.begin(), A+n -> A.end()
//                     - reverse(A.begin(), A.end())

/**  *** POinter operations
 *  # Addition
 *    address + i => address + i * sizeof(type_of_variable)
 * 
 *  # Substraction
 *      address1 - address2 = how many steps are they far away in the memory
 */