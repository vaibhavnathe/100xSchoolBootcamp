#include <iostream>
using namespace std;

int main()
{

    // for 3 numbers
    int num1, num2, num3;
    cout << "Enters numbers : ";
    cin >> num1 >> num2 >> num3;

    // and == &&
    if(num1 >= num2 and num1 >= num3){
        cout << "Max : " << num1 << endl;
    }
    else if(num2 >= num1 && num2 >= num3){
        cout << "Max : " << num2 << endl;
    }
    else{
        cout << "Max : " << num3 << endl;
    }

    // For 2 numbers
    /*
    int num1,num2;
    cout << "Enter numbers : ";
    cin >> num1 >> num2;

    if(num1 > num2){
        cout << "Max : " << num1 << endl;
        cout << "Min : " << num2 << endl;
    }
    else{
        cout << "Max : " << num2 << endl;
        cout << "Min : " << num1 << endl;
    }
        */
    
    return 0;
}