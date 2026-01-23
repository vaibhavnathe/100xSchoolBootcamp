#include<iostream>  // header file which allow to use 'cout'

using namespace std;

int main(){

    // Conditional statements

    

    int num;
    // cin >> num;

    if(num%2 == 0){
        cout << "Even" << endl;
    }
    else{
        cout << "Odd" << endl;
    }

    // bool isRain = true;
    
    // if(isRain){
    //     cout << "Buy Umbrella" << endl;
    // }
    // else{
    //     cout << "Don't Buy Umbrella" << endl;
    // }


    // Relational Operators: >,<,>=,<=,== ,!=
    /*
    bool ans = (5==5);
    bool ans2 = (5==3);
    bool ans3 = (5!=4);
    bool ans4 = (6>2);
    bool ans5= (6<2);

    cout << ans <<endl;     // true -> 1
    cout << ans2 <<endl;    // false -> 0
    cout << ans3 <<endl;
    cout << ans4 <<endl;
    cout << ans5 <<endl;

    bool res = 121562362;   // true -> 1 , only 0 -> false, others -> true
    cout << res << endl;
    */


    // Taking input from user
    /*
    int num1, num2;
    double num3;
    cin >> num1 >> num2 >> num3;
    cout << "Sum : " << num1 + num2 + num3 << endl;
    */

    // Variables -> to store value
    /*
    string name = "HKirat";
    int age = 20;
    float marks = 90.78;
    float Marks = 95.56;
    char grade = 'A';
    bool canVote = true;

    cout << "Name : " << name << endl; 
    cout << "Age : " << age << endl; 
    cout << "Marks : " << marks << endl; 
    cout << "Marks : " << Marks << endl; 
    cout << "Grade : " << grade << endl; 
    cout << "Can Vote : " << canVote << endl; 
    */

    // Arithmetic Operators
    /*
    cout << 10+3 << endl;  // 13
    cout << 10-3 << endl;  // 7
    cout << 10*3 << endl;  // 30 

    cout << 10/3 << endl;  // quetiont : 3
    cout << 10/3.0 << endl;  // quetiont : 3.33333
    cout << 10.0/3 << endl;  // quetiont : 3.33333

    cout << 10%3 << endl;  // reminder : 1
    */

 
    /*
    // Print star pattern
    // std::cout << "*" ; 
    cout << "*" << endl;
    cout << "**" << endl;  
    cout << "***" << endl;  
    cout << "****" << endl;  
    cout << "*****" << endl;  
    */

    /*
    cout << "Hello World";
    
    cout << endl;
    cout << "100xDevs School" << endl;

    cout << "1kDevs School" << endl;

    cout << "10kDevs School" << endl;

    cout << "********************" << endl;
    cout << "Hello World" << endl << "100xDevs School" << endl << "1kDevs School" << endl << "10kDevs School" << endl;

    */

    return 0;

}