#include <iostream>
using namespace std;

// Best Practises :- 1. Prefer local variables over global
//                   2. Keep variable scope as small as possible
//                   3. Avoid reusing variable names
//                   4. Use meaningful names
//                   5. Avoid unnecessary globals

int z = 100;     // global scope :- not recommended
int y = 10;

void fun(){
    int y = 20;
    cout << y << endl;
}

void func(){
    // cout << x << endl;      //can't access a varible of another function

    int i = 10;         // functional scope -> can't acces outside this function
    cout << i << endl;      
}

int main()
{
    cout << y << endl;  // 10 - global
    fun();              // 20 - functional
    cout << y << endl;  // 10 - global

    // cout << x << endl;      // can't access before declaration
    // int x = 10;

    /*
    int z = 99;
    cout << z << endl;
    if(true){
        int z = 98;
        cout << z << endl;  // 98 -> closest variable will get printed
    }
    */

    // to access global variable among same name
    cout << ::z << endl;    //100 - global value

    // cout << z << endl;      // global variable can be accessible everywhere

    // int n;
    // cin >> n;

    // for(int i=1; i<=n; i++){
    //     cout << i << endl;      // i is only accessible inside for loop
    // }
    // cout << i << endl;          // error: 'i' was not declared in this scope

    /*
    // int x = 10;     // can't access outside of main function

    if(true){
        int x = 10;     // only access inside the if
        cout << x << endl;
    }

    // cout << x << endl;      // can't access 

    if(true){
        int x = 20;
        cout << x << endl;
    }
        */

    
    return 0;
}