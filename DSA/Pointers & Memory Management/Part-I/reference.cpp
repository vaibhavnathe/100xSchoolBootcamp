#include <bits/stdc++.h>
using namespace std;

void f(int &x)
{
    x++;
}

// pass by reference :- avoid multiple copies of vector each time
// note :- In recursion & backtracking always pass string & vectors as pass by ref, otherwise it will leads to TLE,MLE or Runtime error.
void printArray(int idx, vector<int> &arr)
{
    if(idx == arr.size()){
        cout << endl;
        return;
    }
    
    cout << arr[idx] << " ";
    printArray(idx+1, arr);
}

// Its is Pass by address 
void fun(int A[])   // - address is being passed in this function
{
    A[0]++;     // *(A+0)++
}

int main() {
    
    // ***** Pointers & Memory Management ***********

    // imp formula : A[i] = *(A + i) = *(i + A) = i[A]   => *(base address + ith position)
    int A[5] = {1,2,3,4,5};
    cout << A[2] << " : " << &A[2] << endl;
    cout << *(A + 2) << endl;   // A[2] = *(A + 2)
    for(int i=0; i<5; i++){
        cout << A[i] << " = " << *(A+i) << " = " << *(i+A) << " = " << i[A] << endl;
    }
    fun(A);     //we pass base address -> array follows pass by address 
    cout << A[0] << endl;

    
    // Address -> Value - Can we print value using an address?
    //                  - YES -> using Dereference(*) operator
    //         - *(Address) => value
    int x = 10;
    cout << &x << endl;     // address of x
    cout << *(&x) << endl;  // value stored ad address &x


    // POinters in arrays
    /*
    int A[5] = {1,2,3,4,5};
    // cout << A[2] << " : " << &A[2] << endl;
    for(int i=0; i<5; i++){
        cout << A[i] << " : " << &A[i] << endl;
    }
    cout << A << endl;      // will get base address array
    cout << &A[0] << endl;  // will get same base address as above
    */
    
    // sizeof operator - to find the size of variable in bytes (how many bytes variable actual taking)
    /*
    int a = 10;
    char ch = 'x';
    long long num = 8776347839849374;
    cout << "Values: " << a << " " << ch << " " << num << endl;
    cout << "Address : " << &a << " " << &ch << " " << &num << endl;
    cout << "Size in bytes : " << sizeof(a) << " " << sizeof(ch) << " " << sizeof(num) << endl;     // 4(int)  1(char)  8(long long)
    */
    
    // Verify ref & normal variable have same address :- by chaking/printing the address
    /*
    int x = 10;
    int &y = x;             // 
    cout << x << endl;      // 10
    cout << &x << endl;     // 0x7ffede48f4ac : & - address of operator
    cout << &y << endl;     // 0x7ffede48f4ac
    
    int z = x;
    cout << &z << endl;     // random address & diff from address of x
    */
    
    // ***
    // int a = 10;
    // int c = 20;
    // int &b = a;     // type of b is also -> INT
    // &b = c;         // possible ? -> No - Once a reference variable is binded then we can't change its reference to other var
    // cout << a << " " << b << " " << c << endl;
    
    // int &x;          // -> error: ‘x’ declared as reference but not initialized
    
    
    // With Strings
    // string str = "dhruv";
    // string &s = str;
    // s[0] = 'a';
    // cout << str << " " << s << endl;
    
    
    // Ex.3 - Pass by value & referece with vector
    /*
    vector<int> a = {1,2,3,4,5};
    vector<int> b = a;              // a gets copied to b
    b[0]++;
    cout << a[0] << " " << b[0] << endl;
    printArray(0,b);
    */
    
    // Ex.2 
    /*
    int x = 10;
    int &y = x;
    int &z = y;
    
    x++;
    y++;
    z=0;
    cout << x << " " << y << " " << z << " " << endl;
    */
	
	// Ex.1
	/*
	int x = 10;        // normal variable
	int &y = x;         //referece variable - y is just an alias for x
	
	y++;
	x *= 10;
	cout << x << endl;
	cout << y << endl;
	*/

}


/*

** Reference Variable :- just an alias/other name for a normal variable.
                     - It helps to prevent creating multiple copies of the same thing

--- Imp Points while working with referece variables

    i) When we create a ref variable, it is compulsory to assign them to an existing variable
        // ex. int &x;      -> error : x is declared as referece variable but not initialized
        
    ii) Once a reference variable is binded/refered to a variable then we can't change its reference to other var
        // ex. int a = 10;
                int c = 20;
                int &b = a;
                &b = c;         // error
    


    use case of & -> i) Reference variable, ex. int &y = xor
                     ii) Address of operator, 
                     ex. int x=10, 
                        cout << &x << endl;
                    iii) Bitwise and operator
                        ex. a=10, b=12
                            cout << a&b << endl;
                            

    // Variable to address & Address to Variable
                     &
     Variable   ---------->   address
    
                   *
     Address  ------------> Variable

 
    -- IMP Formula A[i] = *(A + i) = *(i + A) = i[A]
*/