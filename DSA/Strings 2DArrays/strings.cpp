#include <iostream>
using namespace std;

void checkCharacter(char ch)
{
    if(ch >= 'a' and ch <= 'z'){
        cout << "Lowercase" << endl;
    }
    else if(ch >= 'A' and ch <= 'Z'){
        cout << "Uppercase" << endl;
    }
    else if(ch >= '0' and ch <= '9'){
        cout << "Digit" << endl;
    }
    else{
        cout << "Special" << endl;
    }
}


char toLowerCase(char ch)
{
    if(ch >= 'A' and ch <='Z'){
        return ch+32;
    }

    return ch;
}

bool isLowerCase(char ch)
{
    if(ch >= 'a' && ch <= 'z'){
        return true;
    }
    return false;
}

int main(){

    char ch;
    cin >> ch;

    // Check Charcter -> check whether a given character is lowercase, uppercase, digit or a special character
    checkCharacter(ch);

    
    // COnvert to Lowercase
    /*
    char ans = toLowerCase(ch);
    cout << ans << endl;
    */


    // check lowercase or not
    /*
    bool ans = isLowerCase(ch);
    cout << ans << endl;
    */


    // assci to char
    /*
    int num = 65;
    char ch = num;
    // cout << char(num) << endl;
    cout << ch << endl;

    int num2 = 97;
    cout << char(num2) << endl;

    int num3 = 48;
    cout << char(num3) << endl;
    */

    // char to ascii
    /*
    char ch = 'a';
    cout <<ch << " : " << int(ch) << endl;

    char ch2 = 'A';
    cout << ch2 << " : " << int(ch2) << endl;

    char ch3 = '0';
    cout << ch3 << " : " << int(ch3) << endl;
    */

    return 0;
}