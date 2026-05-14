#include <iostream>
#include <bits/stdc++.h>

// Note :- Every bit operation works in O(1) time & they are very superfast.
// bit operators :- & | ^ << >> ~ 

// IMP XOR (^) properties :- N^N = 0
//                         - N^0 = N
//                         - bit ^ 1 = ~(bit) toggle

using namespace std;


int checkIthBit(int n, int i)
{
    int mask = 1 << i;

    return (n&mask) == 0 ? 0 : 1;
}

void unsetIthBit(int &n, int i)
{
    // using ~mask
    int mask = ~(1<<i);
    n = n&mask;
}

void swap2Numbers(int a, int b)
{
    cout << "Before, A:" << a << " , B: " << b << endl;

    //iv) approach-4 :- Using ^ xor 
    a = a^b;
    b = a^b;
    a = a^b;

    // iii) approach-3 :- Using the +,- operators
    // a = a+b;   
    // b = a-b;
    // a = a-b;

    //ii) approach-2 :- Using temp variable
    // int temp = a;
    // a = b;
    // b = temp;

    // i) approach 1:- using inbuilt-swap function
    // swap(a,b);

    cout << "After, A:" << a << " , B: " << b << endl;
}

// 4] Count no of set bits 
void countSetBits(int n)
{
    int count = 0;

    // iii) Optimal approach :- using bramhastra (N&(N-1)) formula
    //                        - if N is non- zero means it have at least one set bit if (N) -> count++;
    //                        - and unset rightmost set bit , N = N&(N-1) & check this again
    //                         - TC - Better Than Normal Bit Traversal , Worst - logN
    while(n)
    {
        count++;
        n = n&(n-1);
    }

    // ii) Simple approach :- Using rightShift >> and & operator to check lsb bit is 1 or 0
    //                      - TC - O(logN) same as above
    /*
    while(n)
    {
        if((n&1) == 1){
            count++;
        }
        n >>= 1;
    }
        */

    // i) First Principle approach:- using loop int range like from 30-0
    // /                           - checking for each bit
    /*
    int k = 32;         // K=32 for int, k=64 for long long
    for(int i=k-1; i>=0; i--)
    {
        if(checkIthBit(n,i) == 1){
            count++;
        }
    }
        */


    cout << count << endl;
}

// 3] Given a number N, check if even or odd
void checkIfEvenOrOdd(int n)
{
    // ii) Best/Fast  :- using & operator -> fast
    if(n&1 == 1){
        cout << "Odd" << endl;
    }
    else{
        cout << "Even" << endl;
    }

    // i) Basic approach :- using %, % is heacy operator
    /*
    if(n%2 == 0){
        cout << "Even" << endl;
    }
    else{
        cout << "Odd" << endl;
    }
    */
}

//2] Given a number N, check if it is power of 2 or not
 void checkPowerOf2(int n)
 {

    // iii) Optimal approach :- using bramhastra & => using N&(N-1)
    if((n & (n-1)) == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    // ii) another similar approach :- using loop & checking for power <= n
    /*
    int power = 1;
    while(power <= n){
        power = power << 1;
    }
    power = power >> 1;     // power becomes out of loop , need to get the power <= n
    if(power == n){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
        */

    // i) first approach :- counting no of set bits -> if no of set bits == 1 -> YES, else -> NO
    //                  - TC - LogN
    /*
    int count = 0;
    while(n){
        if(n&1 == 1){
            count++;
        }
        n = n >> 1;
    }

    if(count == 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
        */
 }

// 1] Give a number N, unset the rightmost set bit
void unsetRightMostSetBit(int n)
{
    if(n == 0){
        cout << 0 << endl;
        return;
    }

    // iii) Optimal approach :- Bramhastra => N*N-1, TC-O(1)
    n = n & (n-1);

    // both approaches are correct

    //ii) class approach:- using loop from 0 to 30, and use checkIthBit logic & once we got set bit then use unsetIthBitLogic
    //                  - TC - not O(1), but its O(logN) -> 10^9 -> 31 , 10^18 -> 63 
    // /*
    for(int i=0; i<31; i++){    // 0-31 for 4 bit, 0-63 for 8 bit
        if(checkIthBit(n,i) == 1){
             unsetIthBit(n,i);
             break;
        }
    }
        // */

    //i) approach (my approach):- Simply checking each rightmost bit using mask, intially mask is 1
    //             TC-  O(logN) -> 10^9 -> 31 , 10^18 -> 63
    //          - ex. N=100100, mask=1 ,  
    /*
    int mask = 1;
    
    while((n&mask) == 0){ //  if n&mask == 0 (rightmost bit is 0) -> so check next 
        mask = mask << 1;          // -> mask << 1
    }
                        // mask = 100, ~mask = 011
    mask = ~mask;       // here rightmost bit = 1 , need make it 0 using & with 0, mask = 100 -> ~mask = 011
    n = n&mask;
    */

    cout << n << endl;
}

int main()
{
    
    int n;
    // cin >> n;

    // 5] Swap two numbers
    swap2Numbers(10,20);

    // 4] Count the no of set bit of N
    // countSetBits(n);

    //3] Given a number N, check Even or Odd
    // checkIfEvenOrOdd(n);

    //2] Given a number N, check if it is power of 2 or not
    // checkPowerOf2(n);

    // 1] Give a number N, unset the rightmost set bit
    // unsetRightMostSetBit(n);


    return 0;
}