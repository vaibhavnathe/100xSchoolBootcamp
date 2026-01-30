#include <iostream>
using namespace std;

bool isPrime(int num)
{
    // prime -> prime have exactly 2 factors thats why 1 is not prime.
    if(num <= 1){
        return false;
    }

    for(int i=2; i<num; i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

// function to print factors
bool isPrime2(int n){
    int count  = 0;
    for(int i=1; i<=n; i++){
        if(n%i == 0){
            // cout << i << " ";
            count++;
        }
    }
    
    return count==2;
}

void printPrime1toN(int n){
    
    for(int i=1; i<=n; i++){
        if(isPrime2(i)){
            cout << i << " ";
        }
    }
    cout << endl;
}


// function to print factors
void printFactors(int n){
    int count  = 0;
    for(int i=1; i<=n; i++){
        if(n%i == 0){
            cout << i << " ";
            count++;
        }
    }
    cout << endl;
    cout << count << endl;
}

// function to print sqaure pattern
void printPattern(int n, char ch){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << ch;
        }
        cout << endl;
    }
}

// write a function that prints from 1 to n
void print1ton(int n){
    for(int i=1; i<=n; i++){
        cout << i << endl;
    }
}

//set of statements / a block of code that can be reused whenever we want
int factorial(int num){
    int ans = 1;
    for(int i=1; i<=num; i++){
        ans *= i;
    }

    return ans;
}

int sum2(int num1, int num2){
    return num1+num2;
}

int sum3(int num1, int num2, int num3){
    return num1+ num2+num3;
}


int main(){

    int n;
    cin >> n;

    printPrime1toN(n);

    // cout << isPrime(n) << endl;
    // cout << isPrime2(n) << endl;

    // printFactors(n);

    // int n;
    // char ch;
    // cin >> n >> ch;
    // printPattern(n,ch);

    // print1ton(n);

    // int a,b,c;
    // cin >> a >> b >> c;
    // cout << sum2(a,b) << endl;
    // cout << sum3(a,b,c) << endl;

    /*
    int n, r;
    cin >> n >> r;

    // To avoid repetition, we use functions
    int nFact = factorial(n);
    int rFact = factorial(r);
    int nrFact = factorial(n-r);
    */

    // Calculate nCr = n!/r!(n-r)!
    // repeation
    /*

    int nFact = 1;
    for(int i=1; i<=n; i++){
        nFact *= i;
    }

    int rFact = 1;
    for(int i=1; i<=r; i++){
        rFact *= i;
    }

    int nrFact = 1;
    for(int i=1; i<=(n-r); i++){
        nrFact *= i;
    }
    */

    // cout << nFact/(rFact*nrFact) << endl;
    


    return 0;
}