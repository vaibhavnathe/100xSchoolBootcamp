// Sorting -II
// comparator.cpp

#include <bits/stdc++.h> 
#define int long long
using namespace std;
  
// Q.2] Sort Scholars :- given name of student with their marks, sort them based on marks (top marks) , if marks same -> take according lexiographical order of name
// struct/class :- custom data types
struct Student{
  public:
    string name;
    int marks;
};

bool sortScholarCmp(Student s1, Student s2)
{
    if(s1.marks == s2.marks){   // same marks - lexiographical order of names asce order
        return s1.name < s2.name;
    }
    return s1.marks > s2.marks; // desc order (first student mark > second student mark)
}
 
//Q.1] String Sort :- arr of strings, sort them based on length, if length same take in ascending/lexicographical order
bool stringComparator(string str1, string str2)
{
    if(str1.length() == str2.length())		// if length are same :- take it as in lexicographical/asceding order
    {
        return str1 < str2;
    }
    return str1.length() < str2.length();	// sort based on lengths
}

void stringSort(vector<string> &arr)
{
    sort(arr.begin(), arr.end(), stringComparator);
    for(auto str: arr){
        cout << str << endl;
    }
}
 

// a should come first -> true
// b should come first -> false
 
//Ex. 1. sort based on last digit , if same sort based on actual valur
//    2. Sort based on last digit, if same sort based on actual value
//    3. sort base on magnitude , if lastDigit same - take bigger actaul value first
 
bool comparator(int a, int b)
{
    // 3. sort by magnitude, if same, bigger value should come first (desc)
    int modA = abs(a);
    int modB = abs(b);
    if(modA != modB){
        return modA < modB;
    }
    return b < a;
    // 2. Sort by last digit: if lastDigit same - then take in asceding order
    //  int modA = abs(a%10);
    // int modB = abs(b%10);
    // if(modA == modB){
    //     return a < b;
    // }
    // return modA < modB;
    //1. sort by values => a-first -> true, b-first -> false
    // return a < b;       // a-first (ascending)
    // or return b > a;     // b-first (descending)
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
   // Q.2] Sort Scholars :- given name of student with their marks, sort them based on marks (top marks) , if marks same -> take according lexiographical order of name
    vector<Student> arr(n);  // Student cust data-type -> to store student names with marks
    for(int i=0; i<n; i++){
       cin >> arr[i].name >> arr[i].marks;
    }
    sort(arr.begin(), arr.end(), sortScholarCmp);
    for(int i=0; i<n; i++){
        cout << arr[i].name << " " << arr[i].marks << '\n';
    }
 
 
   // Q.1] String Sort :- arr of strings, sort them based on length, if length same take in ascending/lexicographical order
/*
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    stringSort(arr);
*/

 
    /* Comparator :- function which compares 2 values & return true/false based on it. Generally used while sorting elements */
   /*
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), comparator);
    for(auto ele: arr){
        cout << ele << " ";
    }
    cout << endl;
    */

    return 0;
}


// Comparagtor in diff languages :-

// i)  cpp :-  bool cmp(int a, int b){
//                  return true (a<b);     // a should come first          
//                  return false (b<a);     // b should come first
    //         }

// ii) Java, Py, JS :-  int cmp(int a, int b){
//                          a should come first -> return -ve no;
//                          b should come first -> return =ve no;
//                          both same           -> return 0
//                      }

//        or just write -> return a-b;      for ascending order
//                      -> return b-a;      for descending order