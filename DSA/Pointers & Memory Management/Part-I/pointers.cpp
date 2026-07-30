#include <bits/stdc++.h>

#define int long long

#define endl '\n'       // '\n' is faster than endl

using namespace std;

void Swap1(int a, int b)       // pass by value
{
    int temp = a;
    a = b;
    b = temp;
}

void Swap2(int &a, int &b)      // pass by reference
{
    int temp = a;
    a = b;
    b = temp;
}

// int *a -> pointer creation
// *a = *b -> dereference operator
void Swap3(int *a, int *b)      // pass by address - need pointers to store address
{                               // size -> 8 + 8 = 16 bytes
    int temp = *a;          // * -> dereference operator
    *a = *b;
    *b = temp;
}


signed main()
{
    // Ex. WHy not work
    int x = 10;
    // int &y = &x;    // won't work - if we are storing address then use pointer , if creating reference variable just assign int to int
    int *y = &x;    // pointer
    // int &y = x;     // reference variable

    // Ex. Swap function
    int a = 10;
    int b = 20;
    
    // Swap1(a, b);        // pass by value -> will not swap
    // Swap2(a, b);        // pass by reference   -> will get swap
    Swap3(&a, &b);        // pass by address (use extra space for pointers)   -> will get swap
    cout << "AFter swap : " << a << " " << b << endl;
    
    
    // ****** POinters 
    /*
    int x = 10;                 // 4-bytes
    char ch = 'a';              // 1-byte
    long long num = 8723873638;     // 8-bytes
    cout << x << endl;      // value
    cout << &x << endl;     // address

    //to store address of variable -> pointer
    // int ptr = &x;       // error - can't store address into normal type
    int* ptr = &x;          //int-pointer - Int type pointer stores address of x
    char *ptr2 = &ch;       // type - char pointer
    long long *ptr3 = &num;

    auto ptr4 = &x;         // also can store like this 

    cout << x << " : " << ptr << endl;
    cout << ch << " : " << ptr2 << endl;
    cout << num << " : " << ptr3 << endl;
    
    // size of Pointer: Why size of all are 8 - coz all stores address(hexadecimal) not specific type value
    cout << sizeof(ptr) << endl;        // 8
    cout << sizeof(ptr2) << endl;       // 8
    cout << sizeof(ptr3) << endl;       // 8
    */


    return 0;
}

// Pointer Syntax :
//  T var_name = ___;       normal variable - (T-type)
//  T *ptr = &var_name;     Pointer variable 

// Size of Pointer :- 8 or 4 dependeing on machine (cpu architecture of machine) & compiler

// pass by value, pass by reference & pass by address 
//  pass by reference & address -> not same - diff]


/*  #diff uses of (*) dereference operator

    i) POinters :- 
        ex. int a = 10;
            int *ptr = &a;

    ii) De-reference :-
            cout << ptr << endl;    -> ptr - addres
            cout << *ptr << endl;   -> *ptr - value at ptr address

    iii) Multiplication :- 
            ex. int a = 10;
                int b = 20;
                cout << a*b << endl;
*/