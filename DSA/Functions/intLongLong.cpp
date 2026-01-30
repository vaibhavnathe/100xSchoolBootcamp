#include <iostream>
using namespace std;

#define int long long     // hack -> int will get replaced by long long in whole code
                        // every int will get replaced , also main functions int

// not good practise for interviews but good for contests
signed main(){
    
    // int(4 bytes) vs long long(8 bytes)

    // int -> 4 bytes = 32 bits -> 2^32 to 2^31 -1(~2x10^9)
    int x = 1000000000;  // 10^9 -> will work
    // int y = 10000000000; // 10^10 -> error:verflow in implicit constant conversion [-Woverflow]
    cout << x << endl;

    // long long -> 8 bytes= 64 bits -> 2^64 => ~9x10^18
    long long num = 1000000000000;
    cout << num << endl;


    // use long long when :-
    //      1. Multiplying large numbers
    //      2. Constraints mention 10^9, 10^12, 10^18
    //      3. Competetive programming problems

    // #define int long long
    int num1 = 1000000;
    int num2 = 1000000;
    cout << num1*num2 << endl;

    return 0;       // for signed main -> return 0 is optional
}