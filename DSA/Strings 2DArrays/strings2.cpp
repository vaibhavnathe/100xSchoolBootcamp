#include <iostream>
using namespace std;

string invertCase(string str)
{
    for(int i=0; i<str.size(); i++){
        if(str[i] >= 'a' and str[i] <= 'z'){
            str[i] -= 32;
        }
        else if(str[i] >= 'A' and str[i] <= 'Z'){
            str[i] += 32;
        }
    }
    return str;
}


string isStrongPassword(string password)
{
    if(password.size() != 10){
        return "Not Strong";
    }

    int lowercase = 0;
    int uppercase = 0;
    int digit = 0;
    int specialChar = 0;
    for(int i=0; i<password.size(); i++){
        if(password[i] >= 'a' and password[i] <= 'z'){
            lowercase++;
        }
        else if(password[i] >= 'A' and password[i] <= 'Z'){
            uppercase++;
        }
        else if(password[i] >= '0' and password[i] <= '9'){
            digit++;
        }
        else{
            specialChar++;
        }
    }

    if(lowercase and uppercase and digit and specialChar){
        return "Strong";
    }
    return "Not Strong";
}


int countWords(string str)
{
    int count = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i] == ' '){
            count++;
        }
    }
    
    return count+1;     // spaces+1 -> no of words
}


string replaceCharacters(string str, char ch1, char ch2)
{
    for(int i=0; i<str.size(); i++){
        if(str[i] == ch1){
            str[i] = ch2;
        }
    }

    return str;
}


string checkLexicographical(string word1 , string word2)
{
    // we can directly compare using <, >  : follows dictionary order
    if(word1 == word2){
        return "Equal";
    }
    else if(word1 < word2){
        return word1;
    }
    else{
        return word2;
    }
}

string checkBrothers(string firstName, string lastName, string firstName2,string lastName2)
{
    if(lastName == lastName2){
        return "Yes";
    }
    return "No";
}

int main(){

    // 6. Invert case: lowercase -> uppercase , uppercase -> lowercase
    string str;
    getline(cin, str);
    string ans = invertCase(str);
    cout << ans << endl;


    // 5. Strong Password -> check strong password or not : includes at least one lowercase, one uppercase, one digit, one special character
    /*
    string password = "HdOpnd$5#l";
    string ans = isStrongPassword (password);
    cout << ans << endl;
    */


    // 4. Count words -> count no of words in sentence which is seprate by exaclty one space
    /*
    string str;
    getline(cin, str);
    int ans = countWords(str);
    cout << ans << endl;
    */


    // 3. Replace characters -> replace char c1 -> c2 , eg. replace 'a' by 'b' in string
    /*
    string str;
    cin >> str;
    char ch1, ch2;
    cin >> ch1 >> ch2;
    string ans = replaceCharacters(str, ch1, ch2);
    cout << ans << endl;
    */


    // 2. Lexicographical order -> dictionary order, which word come first eg, apple orange -> it is lexographical order
    //                          -> check which word came first apple(A), approval(B) => A
    /*
    string word1, word2;
    cin >> word1 >> word2;
    string ans = checkLexicographical(word1, word2);    
    cout << ans << endl;
    */


    //1. Brothers -> given two names of 2 people, they are borther if there last name is same, check 
    /*
    string firstName, lastName, firstName2, lastName2;
    cin >> firstName >> lastName >> firstName2 >> lastName2;
    string ans = checkBrothers(firstName, lastName, firstName2, lastName2);
    cout << ans << endl;
    */


    // strings => COllection/Sequence of characters stored at continout locations.
    // autoamtic memory management, less error-prone, more inbuilt functions available

    /*
    string name;
    cin >> name;                // input just a singl word
    // getline(cin, name);      // input for multiple words / sentence
    cout << name << endl;
    */

    // int n = name.size();
    // for(int i=0; i<n; i++){
    //     cout << name[i];
    // } 

    // Char array -> C style , Manual memory handling, More error-prone
    char ch[5] = {'D', 'h', 'r', 'u', 'v'};  
    // cout << ch[0] << endl;

    return 0;
}