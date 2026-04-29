#include <iostream>
#include <bits/stdc++.h>

#define int long long

using namespace std;

// Q] Prime Factorization :- find only prime factors of a nin the range 1 to n

void primeFactorization(int n)
{
    // ii) Optimal approach :- Using Sieve style approach - first precompute spf array from 2 to n -> initially from 2 to n all are spf itself, then for only primes , updating the spf for multuiple of primes
    //                                                    - then for each query get the spf

    // i) Brute Force :- Using nested loop
    //                 - TC - O(Q*N^2), Sc- O(1)
    /*
    for(int i=2; i<=n; i++){

        if(n%i == 0){
            while(n%i == 0){
                cout << i << " ";
                n /= i;
            }
        }
    }
        */
    cout << endl;
}

signed main()
{
    int n,q;
    cin >> n >> q;

    int spf[n+1];
    // calculating spf - initially from 2 to n all are spf itself, then for each prime no -> updating spf for multiples of prime
    for(int i=2; i<=n; i++) {
        spf[i] = i; // initially marking all are spf itslef
    }

    for(int i=2; i<=n; i++) {
        if(spf[i] == i){ // checking prime
            for(int j = i*i; j<=n; j+=i){
                spf[j] = min(i, spf[j]);
            }
        } 
    }

    for(int i=0; i<q; i++){
        int x;
        cin >> x;
        if(x > n){
            return 0;       // out of range
        }

        while(x != 1){
            cout << spf[x] << " ";        
            x /= spf[x];
        }
        cout << endl;

        // primeFactorization(x);
    }
    
    return 0;
}