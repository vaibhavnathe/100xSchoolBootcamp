#include <iostream>
#include <bits/stdc++.h>

#define int long long

using namespace std;

//*** Recursion :- function calling itself */
// * 3 Golden rules to solve any recursive problem :- i) Define a clear cut responsibility for the recursive function
//                                                   ii) Break it down recursively and Believe/Trust/Have a leap of faith that this function will work for small inputs automatically
//                                                   iii) Figure out the base case

// 9] Fibonacii Number :- given n number, return nth fibonacci number
int fibo(int n)
{
    if(n <= 0){
        return -1;      // invalid
    }

    // ii) using recursion :- task - f(n) nth fibonacci number
    //                      breakdown - f(n) = f(n-1) + f(n-2)
    //                      base case - f(1) = 0, f(2) = 1
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }

    int ans = fibo(n-1) + fibo(n-2);
    return ans;

    // i) simple approach :- using loop & variable fibFirst=0, fibSecond=1 & currFib = fibFirst + fibSecond
}

// 8] Sum of digits- given number n, find the sum of its digitd
int sumOfDigits(int n)
{
    // ii) using recursion :- task - sum of digits of n = n%10 + n%100 +..
    //                      breakdown - f(n) = n%10 + fn(n/10)
    // /                    base case - n==0 -> return 0
    if(n == 0){
        return 0;
    }
    int ans = n%10 + sumOfDigits(n/10);
    return ans;

    // i) simple approach :- simple using loop & % operator
}

// 7] Power - x^n
int power(int x, int n)
{
    // iii) using recursion :- task->   f(x,n) = x*x*x*....*x (n times)
    //                        breakdown ->  f(x,n) = x*f(x,n-1) 
    //                        base case ->  if(n==0) => return 1, x^0=1
    if(n == 0){
        return 1;
    }
    int ans = x*power(x,n-1);
    return ans;

    // ii) optimal approach :- using bit manipulation 

    // i) basic approach :- using loop n time, and multiply x n-times
}

// 6] Sum from 1 to N
int sum(int n)
{
    // iii) another approach :- using reursion
    if(n == 1){
        return 1;
    }
    int ans = n + sum(n-1);
    return ans;

    // ii) optimal approach :- using formala of sum of first N natuaral no => (n * (n+1))/2
    // i) simple approach:- using loop
}

// 5] Factorial of N
int fact(int n)
{
    // ii) using recursion :- // use 3 golden rules -> i) what is responsibility/task - n! 
    //                                                ii) breakdown-  n * fact(n-1)
    //                                               iii)stop condition - 0! = 1
    if(n == 0){
        return 1;   // base case-> 0! = 1
    }
    int ans = n * fact(n-1);    
    return ans;


    // i) simple approach :- using loops
    /*
    int ans = 1;
    for(int i=n; i>=1; i--){
        ans *= i;
    }
    return ans;
    */
}

// 4] Given a number n, print n in reverse order
void reverse(int n)
{
    // ii) Using Recursion :- % to get lastDigit, then recursive call for n/10, and base condition n=0-> return
    if(n == 0){
        return;
    }
    cout << n%10;
    reverse(n/10);

    // i) Simple approach :- using loop & % operator to get last digit
    /*
    while(n){
        int lastDigit = n%10;
        cout << lastDigit;
        n /= 10;
    }
        */
}


// 3] Given an integer n, print zig zag sequence. (n to 1 & back 1 to n)
// - 1st way : we can call 2 functions -> printDecreasing & printIncreasing
// - 2nd way : we can use only one function and print before & after the recursive call
void zigzag(int n)
{
    if(n == 1){
        cout << n << endl;      // need to print like - 5 4 3 2 1 2 3 4 5
        return;
    }
    cout << n << endl;  // will print n to 1
    zigzag(n-1);    
    cout << n << endl;  // after call execution , for printing 1 to n

}

// 2] Given an integer n, print 1 to n without usig any loop
// 2nd way :- 
void printIncreasing2(int n)
{
    if(n == 0){
        return;
    }
    printIncreasing2(n-1);      // Head recursion
    cout << n << endl;
}

// 1st way
void printIncreasing(int n, int i)
{
    if(i > n){
        return;
    }

    cout << i << endl;
    printIncreasing(n, i+1);
}

// 1] Given an integer n, print n to 1 without usig any loop
void printDecreasing(int n)
{
    if(n == 0){
        return;
    }

    cout << n << endl;
    printDecreasing(n-1);
}

void fun(int n){
    // base/stop condition :- to stop at some point , avoid from infinite loop
    if(n == 0){
        return;
    }
    
    cout << "Hello " << endl;
    fun(n-1);
}

void A(){
    cout << "Function A" << endl;
    // C();    // infinite loop :- C - B - A - C -> Stack overflow
}

void B(){
    cout << "Function B" << endl;
    A();
}

void C(){
    cout << "Function C" << endl;
    B();
} 

signed main()
{
    int n;
    cin >> n;

    // some basic problems

    // 9] Fibanacci number
    int ans = fibo(n);
    cout << ans << endl;

    // 8] Sum of all digits of n
    // int ans = sumOfDigits(n);
    // cout << ans << endl;

    // 7] Power -> fing power x^n
    // int x;
    // cin >> x >> n;
    // cout << power(x,n) << endl;

    // 6] Find sum from  1 to N
    // int ans = sum(n);
    // cout << ans << endl;

    // 5] Given a number n, find its factorial
    // int ans = fact(n);
    // cout << ans << endl;

    // 4] Given a number n, print n in reverse order
    /*
    if(n == 0){     // to handle 0's case, make changes outside the recursive function
        cout << 0 << endl;
    }
    else{
        reverse(n);
    }
    */
    

    // 3] Given an integer n, print zig zag sequence. (n to 1 & back 1 to n)
    // zigzag(n);

    // 2] Given an integer n, print 1 to n without usig any loop
    // printIncreasing(n, 1);  // using i=1 to print from 1 to n
    // printIncreasing2(n);        // witohout using any extra parameter, just using recursive

    // 1] Given an integer n, print n to 1 without usig any loop
    // printDecreasing(n);

    //call stack : main -> C -> B -> A
    // C();

    // A();
    // B(); 
    // C();

    // fun(10);
    

    return 0;
}