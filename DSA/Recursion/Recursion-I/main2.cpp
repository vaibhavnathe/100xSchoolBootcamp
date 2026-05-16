#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Recursion function calls - 

void B()
{
    cout << "B" << endl;
}

void A()
{
    cout << "A" << endl;
    B();
    cout << "A" << endl;
}

int main()
{
    // call stack : main() -> 'Calling A', A() -> "A", B() -> "B" -> back in A() ->"A" -> backi in Main -> B() , "B" -> main -> empty call stack
    cout << "Calling A" << endl;
    A();
    cout << "Back in Main" << endl;
    B();
    
    return 0;
}