#include <iostream>
using namespace std;

int main()
{
    int marks;
    cout << "Enter marks: ";
    cin >> marks;

    if(marks >= 35){
        cout << "Pass" << endl;
    }
    else{
        cout << "Fail" << endl;
    }
    
    return 0;
}