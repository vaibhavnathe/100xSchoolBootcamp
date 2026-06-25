#include <bits/stdc++.h>

using namespace std;

// 4] Combination Sum  
void combinationSum(int idx, int *arr, int n, int target, vector<int> &path, int sum)
{
    // base case & sum exceeds target
    if(sum > target or idx == n){
        return;
    }
    // if sum == target -> print path & return
    if(sum == target){
        for(auto ele: path){
            cout << ele << " ";
        }
        cout << endl;
        return;
    }
    // choices (take or not take) :- {2,3,4,5,7} , either take current ele multiple time, or take next ele
    //take- curr ele multiple times 
    path.push_back(arr[idx]);
    combinationSum(idx, arr, n,target, path, sum + arr[idx]);
    path.pop_back();

    //not take curr ele, go to next ele
    combinationSum(idx+1, arr, n,target, path, sum);
}
 


// 3] Encoding Problem :- ex. s = "1234" , o/p - "ABCD", "AWD",  "LCD"
// without using map
void encoding(int idx, string &s, string &path)
{
    // base case
    if(idx == s.size()){
        cout << path << endl;
        return;
    }
    // choices we have -> single digit or double digit
    // take 1 digit
    int num1 = stoi(s.substr(idx, 1));     // using substr & converting to int
    if(num1 > 0){                          // dead case - str[idx] = '0'
        char ch = (num1 + 'A' - 1);
        path += ch;
        encoding(idx+1, s, path);
        path.pop_back();
    }
    // take 2 digit
    int num2 = stoi(s.substr(idx,2));
    if(num2 >= 10 and num2 <= 26)  // to maintain between 'A' to 'Z', not any extra character
    {
        char ch = (num2 + 'A' - 1);
        path += ch;
        encoding(idx+2, s, path);
        path.pop_back();
    }
}
 
// using map for encoding 1-A, 2-B ..
void encoding2(int idx, string &str, map<int, char> &encoding, string &path)
{
    // base/stop case
    if(idx == str.size()){
        // print path & return
        cout << path << endl;
        return;
    }
    // str[idx] = '0' - dead state - return 
    if(str[idx] == '0'){
        return;
    }
    // options -> single digit or double digit
    //include single digit
    // int digit = str[idx] - '0';     // using ascii
    int digit = stoi(str.substr(idx,1));      // using substrings - substr(start_idx, len) & stoi - convert string to int
    path += encoding[digit];
    encoding2(idx+1, str, encoding, path);
    path.pop_back();
    //include double digit
    if(idx+1 < str.size()){
        // int twoDigit = digit*10 + (str[idx+1]-'0'); //  using ascii
        int twoDigit = stoi(str.substr(idx, 2));  // using substrings - substr(start_idx, len) & stoi - convert string to int
        if(encoding[twoDigit]){
            path += encoding[twoDigit];
            encoding2(idx+2, str, encoding, path);
            path.pop_back();
        }
    }
}


// 2] Keypad Combinations
void keypadCombinations(int idx, string s, map<char, string> & mp, string &path, vector<string>&res)
{
    // base/stoop case - when idx reached beyound s string - we have combination path, print it & return
    if(idx == s.size()){
        res.push_back(path);
        return;
    }
    
    // current digit of s string -
    char digit = s[idx];
    string choices = mp[digit];
    
    // choice for current digit :- mapped chars for that digit - need to get combinations for mapped chars 
    for(auto ch : choices){
        path += ch;
        keypadCombinations(idx+1, s, mp, path, res);
        path.pop_back();
    }
}


// 1] Generate Parantheses : n=1 -> () , n=2 -> (()), ()()
void generateParantheses(int open, int close, int n, string path)
{
    // base/stop case :- when open & close brackets count == n
    if(open == n and close == n){
        // print path & return 
        cout << path << endl;
        return;
    }

    // logic - we have two choices -> either include '(' opening or ')' closing bracket

    // open '(' bracket : need to include only when count of open < n
    if(open < n){
        path += '(';
        generateParantheses(open+1, close, n, path);
        path.pop_back();            // after coming back - need to pop the previos/last bracket
    }

    // closing ')' : need to include closing ')' bracket only when there is already opening '(' bracket is there/include
                //    - how can check : if(open > close)
    if(open > close){   // if there is already paired '(' bracket is there
        path += ')';
        generateParantheses(open, close+1, n, path);
        path.pop_back();
    }
}

signed main()
{

    // 4] Combination Sum
    int arr[] = {2,3,4,5,7};
    int target = 8;
    vector<int>path;
    combinationSum(0, arr, 5, target, path, 0);

    // 3] Encoding
    /*
    string str;
    cin >> str;
    // map<int, char> encoding;
    // for(int i=0; i<26; i++)
    // {
    //     encoding[i+1] = 'A'+i;
    // }
    string path = "";
    // using encoding map
    // encoding2(0, str, encoding, path);      // f(idx, s,encoding_map, path);
    
    encoding(0,str, path);          // without using map - using ascii
    */

    // 2] Keypad Combiantions
    /*
    string str;
    cin >> str;
    
    map<char, string> mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    
    string path;
    vector<string> res;
    keypadCombinations(0, str, mp, path, res);
    
    cout << res.size() << endl;
    for(auto str : res){
        cout << str << endl;
    }
    */
    

    // 1] Generate Parantheses
    /*
    int n;
    cin >> n;
    string path = "";
    generateParantheses(0,0,n, path);
    */

    return 0;
}


