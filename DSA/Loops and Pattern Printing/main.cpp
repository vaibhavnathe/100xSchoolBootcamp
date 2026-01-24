#include <iostream>
using namespace std;

int main()
{
    cout << " ********** Loops ************" << endl;

    // problem
    // cout << 1 << endl;
    // cout << 2 << endl;
    // cout << 3 << endl;
    // cout << 4 << endl;
    // cout << 5 << endl;
    // cout << 6 << endl;
    // cout << 7 << endl;
    // cout << 8 << endl;
    // cout << 9 << endl;
    // cout << 10 << endl;

    // Types of Loops -> While , For , Do-While 

    // While Loop
    // int i=1;
    // while(i <= 100){
    //     cout << i << endl;
    //     i++;
    // }

    // Print 1 to N
    /*
    int num;
    int i=1;
    cin >> num;
    while(i <= num){
        cout << i << endl;
        i++;
    }
    */

    // Print 1 to N
    /*
    int num;
    int i=1;
    cin >> num;
    while(i <= num){
        cout << i << endl;
        i++;
    }
    */
    // Print N to 1
    /*
    int num;
    cin >> num;
    while(num >= 1){
        cout << num << endl;
        num--;
    }
    */

    
    // Print from L to R
    /*
    int L,R;
    cin >> L >> R;

    while(L <= R){
        cout << L << endl;
        L++;
    }
    */

    // Print even numbers from 1 to N
    // int i,n;
    // i=2;
    // cin >> n;

    // while(i <= n){
    //     if(i%2 == 0){
    //         cout << i << endl;
    //     }
    //     i++;
    // }

    // while(i <= n){
    //     cout << i << endl;
    //     i += 2;
    // }


    //Print All Uppercase Alphabets (A-Z)
    /*
    char ch = 'A';

    while (ch <= 'Z'){
        cout << ch << endl;
        ch++;
    }
    */
    

    /*
    char ch = 'a';

    while (ch <= 'z'){
        cout << ch << endl;
        ch++;
    }
    */

    // Print Multiplication table of N
    /*
    int N;
    cin >> N;

    int i = 1;
    while(i <= 10){
        cout << N << " * "  << i << " = " << N*i << endl;
        i++;
    }
        */

    // Print Number in reverse
    /*
    int num;
    cin >> num;

    while(num){
         cout << num%10;
         num /= 10;
    }
         */

    // Digit Sum
    /*
    int num;
    cin >> num;

    int sum = 0;
    while(num){
        sum += num%10;
        num /= 10;
    }
    cout << sum << endl;
    */


    // Reverse and Store in a variable
    /*
    int num;
    cin >> num;

    int rev = 0;

    while(num){
         int mod = num%10;
         rev = rev*10 + mod;
         num /= 10;
    }
    cout << rev << endl;
    */


    // Palindrome 
    int num;
    cin >> num;

    int rev = 0;
    int temp = num;

    while(temp){
         int mod = temp%10;
         rev = rev*10 + mod;
         temp /= 10;
    }
    if(rev == num){
        cout << "Palidrome" << endl;
    }else{
        cout << "Not Palindrome" << endl;
    }

    // For Loop
    for(int i=0; i<10; i++){
        cout << i << endl;
    }

    
    
    return 0;
}