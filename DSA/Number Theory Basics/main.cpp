#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 4] Print Prime no's from 1 to N ->  
// TC - O(N*N) -> O(N*rootN) -> O(N*logN) -> O(N*log(logN))
void printPrimesFrom1ToN(int n)
{
    // iv) Optimal approach 2:- Using Sieve of eratosthenus, most optimised
    //                      - Initially arr considering all prime(true) then starting from 2 to n & marking all multiples of current (i) as false
    //                      - TC - O(N*log(logN)) , Sc- O(N)
    vector<bool> isPrime(n+1, true);
    isPrime[0] == false;
    isPrime[1] == false;
    for(int i=2; i*i<=n; i++)   // optimization -> i*i <=n  , because of j=i*i 
    {
        if(isPrime[i]){   // optimization-  considering only true (prime) & ignoring not prime already marked(false), marking their multiples as false not prime
            for(int j=i*i; j<=n; j+=i){     // i*i -> otpimization because (i+i / 2*i already marked as false)
                
                isPrime[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++)
    {
        if(isPrime[i]){   //printing only prime no's, considering only true
            cout << i << " ";
        }
    }

    // note: Sieve style loop(used in variou problems) Same as previos problem, just need to count factors of each no from 1 to n, if factors[i] == 2 => prime
    // iii) Optimal Approach (Sieve Style loop) :- using extra space but less time, for each no, storing its factors in vector
    //                     - TC - O(N*logN), SC - O(N)
    /*
    vector<int> factors(n+1);
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i){
            
            factors[j]++;
            
        }
    }
    for(int i=1; i<=n; i++)
    {
         if(factors[i] == 2){
            cout << i << " ";
        }
    }
    */


    // ii) Better approach :- using nested loop but, inner loop will run from 1 to root n only
    //                     - TC - O(N*rootN), SC - O(1) or O(n) if we use extra space to store factors 
    /*
    for(int i=1; i<=n; i++)
    {
        int count = 0;
        int j = 1;
        while(j*j <= i){
            if(i%j == 0){
                count++;
                if(j != i/j){
                    count++;
                }
            }
            j++;
        }
        if(count == 2){
            cout << i << " ";
        }
        cout << endl;
       
    }
        */

    // i) Brite Force :- using nested loops, calculating factor of each no from 1 to no
    //                - TC - O(N^2), SC- O(1)
    /*
    for(int i=1; i<=n; i++)
    {
        int count = 0;
        // factors of i
        for(int j=1; j<=i; j++){
            if(i % j == 0){
                count++;
            }
        }
        
        if(count == 2){
            cout << i << " ";
        }
        cout << endl;
    }
    */
}

// 3] Count Factors of each no from 1 to N
void countFactorOfEachNoFrom1ToN(int n)
{
    // iv) Optimal Approach 2:- using extra space but less time, for each no, storing its factors in vector
    //                     - TC - O(N*logN), SC - O(N)
    vector<int> factors(n+1);
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i){
            
            factors[j]++;
            
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout << "Factors Count of " << i << " : " << factors[i]<< endl;
    }

    // iii) Optimal Approach 1:- using extra space but less time, for each no, storing its factors in vector
    //                     - TC - O(N*logN), SC - O(N*logN)
    /*
    vector<vector<int>> factors(n+1);
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i){
            
            factors[j].push_back(i);
            
        }
    }
    for(int i=1; i<factors.size(); i++)
    {
        cout << "Factors Count of " << i << " : " << factors[i].size() << endl;
    }
    */

    // ii) Better approach :- using nested loop but, inner loop will run from 1 to root n only
    //                     - TC - O(N*rootN), SC - O(1) or O(n) if we use extra space to store factors 
    /*
    for(int i=1; i<=n; i++)
    {
        int count = 0;
        int j = 1;
        while(j*j <= i){
            if(i%j == 0){
                count++;
                if(j != i/j){
                    count++;
                }
            }
            j++;
        }
        cout << "Factors Count of " << i << " : " << count << endl;
       
    }
        */

    // i) Brite Force :- using nested loops, calculating factor of each no from 1 to no
    //                - TC - O(N^2), SC- O(1)
    /*
    for(int i=1; i<=n; i++)
    {
        int count = 0;
        // factors of i
        for(int j=1; j<=i; j++){
            if(i % j == 0){
                count++;
            }
        }
        cout << "Factors Count of " << i << " : " << count << endl;
    }
    */
}


// 2] Factors of each no from 1 to N
void factorOfEachNoFrom1ToN(int n)
{
    // iii Optimal Approach:- using extra space but less time, for each no, storing its factors in vector
    //                     - TC - O(N*logN), SC - O(N*logN)
    vector<vector<int>> factors(n+1);
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i){
            
            factors[j].push_back(i);
            
        }
    }
    for(int i=1; i<factors.size(); i++)
    {
        cout << "Factors of " << i << " : ";
        for(int j=0; j<factors[i].size(); j++){
            cout << factors[i][j] << " ";
        }
        cout << endl;
    }

    // ii) Better approach :- using nested loop but, inner loop will run from 1 to root n only
    //                     - TC - O(N*rootN), SC - O(1) or O(n) if we use extra space to store factors 
    /*
    for(int i=1; i<=n; i++)
    {
        cout << "Factors of " << i << " : ";
        int j = 1;
        while(j*j <= i){
            if(i%j == 0){
                cout << j << " ";
            }
            j++;
        }
        j--;
        while(j >= 1){
            if(i%j == 0){
                if(j != i/j){
                    cout << i/j << " ";
                }
            }
            j--;
        }
        cout << endl;
    }
        */

    // i) Brite Force :- using nested loops, calculating factor of each no from 1 to no
    //                - TC - O(N^2), SC- O(1)
    /*
    for(int i=1; i<=n; i++)
    {
        // factors of i
        cout << "Factors of " << i << ": ";
        for(int j=1; j<=i; j++){
            if(i % j == 0){
                cout << j << " ";
            }
        }
        cout << endl;
    }
    */
}

// 1] Factors of n - print fcators in ascending order
void factorsOfN(int n)
{
    // iii) Optimal approach :- looping from 1 to root n for first haalf, sec half looping from root n to 1
    //                      - TC- O(root n), SC- O(1)
    int i=1;
    while(i*i <= n){
        if(n%i == 0){
            cout << i << " ";
        }
        i++;
    }
    i--; // -> now is out of range, need to make i-- for sec half (root n to 1)
    while(i >= 1){
        if(n%i == 0){
            if(i != n/i){
                cout << n/i << " ";
            }
        }
        i--;
    }
    

    // ii) Better approach :- looping from 1 to root n -> TC - O(root n), SC - O(n)
    /*
    vector<int>secHalf;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            cout << i << " ";
            if(i != n/i){
                secHalf.push_back(n/i);
            }
        }
    }
    // printing sec half 
    for(int i=secHalf.size()-1; i>=0; i--){
        cout << i << " ";
    }
    */

    // i) Brute Force :- looping from 1 to n -> TC - O(n)
    /*
    for(int i=1; i<=n; i++)
    {
        if(n%i == 0){
            cout << i << " ";
        }
    }
    */
}

int main()
{
    int n;
    cin >> n;

    // 4] Print Prime no's from 1 to N
    printPrimesFrom1ToN(n);

    // 3] Count Factors of each no from 1 to n
    // countFactorOfEachNoFrom1ToN(n);

    // 2] Factors of each no from 1 to n
    // factorOfEachNoFrom1ToN(n);

    // 1] Factors of n - ascending order
    // factorsOfN(n);
    
    return 0;
}