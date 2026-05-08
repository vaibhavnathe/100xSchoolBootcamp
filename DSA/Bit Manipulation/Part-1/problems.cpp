#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int checkIthBit(int n, int i)
{
    int mask = 1 << i;
    return (n & mask) == 0 ? 0 : 1;
}


// 2] Count no of set bits in N
int countSetBits(int n)
{
    int count = 0;

    // i) First approach :- checking for each bit from left , whether bit is set or unset
    //                  - Int 32 bit 0-31 , 31 is reserved for sign, check from 30-0
    for(int i=30; i>=0; i--)
    {
        if(checkIthBit(n, i)){
            count++;
        }
    }

    return count;
}

// 3] Check if N is 2's power no or not
bool checkNoIf2sPowerOrNot(int n)
{
    // approach :- if n have only one set(1 bit) -> 2's power no
    //          - ex 2^0 = 1, 2^1 = 10, 2^2 = 100, 2^3 = 1000, 2^4 = 10000
    if(countSetBits(n) == 1){
        return true;
    }

    return false;
}

// 1] Decimal to Binary
void decimalToBinary(int n)
{
    // i) First approach :- checking for each bit from left , whether bit is set or unset
    //                  - Int 32 bit 0-31 , 31 is reserved for sign, check from 30-0
    for(int i=30; i>=0; i--)
    {
        if(checkIthBit(n, i)){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    
}

signed main()
{
    int n;
    cin >> n;

    // 3] Check if N is 2's power no or not
    int res = checkNoIf2sPowerOrNot(n);
    cout << res << endl;

    // 2] Count no of set bits in N
    // int count = countSetBits(n);
    // cout << count << endl;

    // 1] Decimal to Binary
    // decimalToBinary(n);

    return 0;
}