#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define int long long

void countFactorsOfN(int n)
{
    int count = 0;

    /*optimal apparoach :- loop will run only for i <= sqrt(n) : i & n/i -> factors*/
    for(int i=1; i*i <= n; i++){
        if(n%i == 0){
            count++;
            if(i != (n/i)){
                count++;
            }
        }
    }

    /*brute force -> using loop till n : o(n) if n is 10^8 => 1sec, if n is 10^12 => 10000 sec , if n is 10^18 => 316 years lol*/
    /*
    for(int i=1; i<=n; i++){
        if(n%i == 0){
            count ++;
        }
    }
    */

    cout << count << endl;
}


void factorsOfN(int n)
{

    /*optimal apparoach :- loop will run only for i <= sqrt(n) : i & n/i -> factors*/
    for(int i=1; i*i <= n; i++){
        if(n%i == 0){
            cout << i << " ";
            if(i != (n/i)){
                cout << n/i << " ";
            }
        }
    }
    cout << endl;

    /*brute force -> using loop till n : o(n) if n is 10^8 => 1sec, if n is 10^12 => 10000 sec , if n is 10^18 => 316 years lol*/
    /*
    for(int i=1; i<=n; i++){
        if(n%i == 0){
            cout << i << " ";
        }
    }
    */
}


int sumOfRange(int start, int end)
{
    int sum = 0;

    /*Best/optimal approach :- using sum of first n formula*/
    sum = ((end * (end+1))/2) - (start*(start-1)/2);    // first calculating sum of n/end and then substarcting the first half till start


    /*Basic approach :- using loop from start to end*/
    /*
    for(int i=start; i<=end; i++)
    {
        sum += i;
    }
    */

    return sum;
}


int sumOfN(int n)
{
    int sum = 0;

    /*Best approach :- using the formula*/
    sum = (n * (n+1))/2;

    /*Basic approach :- using loop till n*/
    /*
    for(int i=1; i<=n; i++){
        sum += i;
    }
    */

    return sum; 
}

signed main()
{
    /*3. Factors of n*/
    int n;
    cin >> n;
    factorsOfN(n);
    countFactorsOfN(n);


    /*2. Sum of range from start to end*/
    /*
    int start, end;
    cin >> start >> end;
    int ans = sumOfRange(start, end);
    cout << ans << endl;
    */


    /*1. Sum of first N natural numbers*/
    /*
    int n;
    cin >> n;
    int ans = sumOfN(n);
    cout << ans << endl;
    */

    return 0;
}