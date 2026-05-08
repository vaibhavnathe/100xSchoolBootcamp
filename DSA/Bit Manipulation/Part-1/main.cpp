#include <iostream>
#include <bits/stdc++.h>

#define int long long

using namespace std;

// 5.iv] Unset ith bit of n
void unsetIthBit(int n, int i)
{
    // approach 2:- using mask= ~(n << i)= 111101111, and performing &AND n&mask
    int mask = ~(1 << i);
    n = n&mask;

    // approach 1 (my-logic) :- using mask & AND operation , check ith bit if (n&mask == 1). If bit is 1 -> then perform xor on n^mask
    //    
    /*                                                                                     If bit is already 0 (unset) -> no need to do anything
    int mask = 1 << i;
    if(!((n&mask)==0)){  // bit is 1 -> need to unset (0)
        n = n^mask;
    }
    */

    cout << n << endl;  
}

// 5.iii] Toggle the ith bit
void toggleIthBit(int n, int i)
{
    // approach 2 - simpler :- create a mask no(1 << i) & perform xor operation of n & mask -> n ^ mask
    //           
    int mask = 1 << i;  //ex. creating mask -> 0000100000 for i=5, n=1110001111
    n = n ^ mask;       // can directly do xor =>  // 1110 1 01111 ^ 0000 1 00000 => 1110 0 01111


    // approach 1:- create a mask no(1 << i) , using mask & AND operation with , check if bit is 0 -> do OR = n | mask
    //                                                                              if bit is 1 -> do XOR = n ^ mask
    /*
    int mask = 1 << i;  //ex. creating mask -> 0000100000 for i=5, n=1110001111

    if((n&mask) == 0){  // if ith bit is unset - 0
        n = n | mask;      // 1110 0 01111 | 0000 1 00000 => 1110 1 01111
    }
    else{   // bit is set - 1
        n = n ^ mask;       // 1110 1 01111 ^ 0000 1 00000 => 1110 0 01111
    }
    */

    cout << n << endl;
}

// 5.ii] Set the ith bit
void setIthBit(int n, int i)
{
    // approach :- create a mask no(1 << i) & then perform or (|) with n
    int mask = 1 << i;  // creating mask -> 100000
    n = n | mask;       // | with n -> 1110001111 | 0000100000 = 1110101111

    cout << n << endl;  // new set'th no
}

// 5.i] Check whether ith bit is set or not for given number n.
void findBitSetOrNot(int n, int i)
{
    n = n >> i;     // ex. n= 1110001111, i=5 , n >> i -> 0000011100
    int bit = n&1;  //     bit = n&1 => 0000011100 & 0000000001 -> 0
    cout << bit << endl;
}

// 4] Given a number N, fin its binary
void intToBinary(int n)
{
    //ii) Simple/Better :- Printing its right most bit & then sifting right/dividing number by 2
    //                  - TC - O(logN), SC- O(1)
    // /*
    while(n){
        if(n&1){
            cout << 1;
        }
        else{
            cout << 0;
        }
        n /= 2;
    }
        // */

    // i) First Principle :- same as previous problem ->finding nearest power & then if power <= n -> print power & substract n-power & update power /= 2
    //                      - need to find nearest power value for ex. n=51 , power =32
    //                      -  TC - O(logN), SC- O(1)
    /*
    int powerValue = 1;
    while(powerValue <= n){
        powerValue *= 2;
    }
    // out of range -> need to divide by 2
    powerValue /= 2;

    // printing
    while(n > 0)
    {
        if(powerValue <= n){
            cout << 1;
            n -= powerValue;
        }
        else{
            cout << 0;
        }
        powerValue /= 2;
    }
    */
}

 // 3] Represent N as sum of power of 2 (no-repeatition of power), ex 52 -> 32 + 16 + 2 + 1
void nAsPowerOf2(int n)
{

    // Approach :- finding nearest power & then if power <= n -> print power & substract n-power & update power /= 2
    // - need to find nearest power value for ex. n=51 , power =32
    int powerValue = 1;
    while(powerValue <= n){
        powerValue *= 2;
    }
    powerValue /= 2;     // power = 64 out of range & loop , need to divide -> power =32
    
    // substracting n-powerValue , if powerValue <=n -> print it & update powerValue & n
    while(n > 0){
        if(powerValue <= n){
            cout << powerValue << " ";
            n -= powerValue;     
        }
        powerValue /= 2;

    }
}

// 2] Power of 2 <= N :- print power of 2 value <= n , ex. N=20 -> 1,2,4,8,16
void powerOf2LessThanEqualN(int n)
{

    // ii) Optimal approach :- ans=1, multiplying ans by 2 each time till ans <= n
    //                      :- TC- O(logN), SC-O(1)
    
    int ans = 1;
    while(ans <= n){
        cout << ans << " ";
        ans *= 2;
    }

    // i) Brute Force :- running loop until pow(2,i) <= N
    //                :- TC depends on which method use by pow(2,i)- O(logN*logN), SC-O(1)
    /*
    int i=0;
    while(pow(2,i) <= n){   // pow(2,i) -> O(N), & loop running for logN times
        cout << pow(2,i) << " ";
        i++;
    }
    */
}

// 1] find x^n
void findXpowerN(int x, int n)
{

    int ans = 1;
    for(int i=1; i<=n; i++)
    {
        ans *= x;
    }
    cout << ans << endl;
}

signed main()
{
    cout << "****** Bit Manipulation Part-1*******" << endl;

    int n;
    cin >>n;

    // 5] Operations on ith bit -> i) Check ith bit set or not - use &
    //                             ii) Set the ith bit         - use | 
    //                             iii) Toggle ith bit         - use ^
    //                             iv) Unset ith bit         - use ~mask & use &
    int i;
    cin >> i;
    unsetIthBit(n,i);             // iii) Toggle ith bit of no 
    // toggleIthBit(n,i);             // iii) Toggle ith bit of no 
    // setIthBit(n,i);             // ii) Set the ith bit
    // findBitSetOrNot(n,i);   // i) Check ith bit set or not

    // 4] Given a number N, fin its binary
    // intToBinary(n);

    // 3] Represent N as sum of power of 2 (no-repeatition of power), ex 52 -> 32 + 16 + 2 + 1
    // nAsPowerOf2(n);

    // 2] Power of 2 <= N :- print power of 2 value <= n
    // powerOf2LessThanEqualN(n);

    // 1] find x^n
    // int n,x;
    // cin >>n>> x;
    // findXpowerN(x, n);

    return 0;
}