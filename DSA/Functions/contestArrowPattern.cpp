#include <iostream>
using namespace std;

void arrow(int n){

    for(int i=1; i<=n; i++){
        // spaces
        for(int j=1; j<i; j++){
            cout << " ";
        }
        // > arrows
        for(int j=1; j<=i; j++){
           if(i==1 || j==1 || j==i){
             cout << ">";
             if(j!=i){
                cout << " ";
             }
           }
           else{
            cout << "  ";
           }
        }
        cout << endl;
    }

    // 2nd half -> just reverse it
    for(int i=n-1; i>=1; i--){
        // spaces
        for(int j=1; j<i; j++){
            cout << " ";
        }
        // > arrows
        for(int j=1; j<=i; j++){
           if(i==1 || j==1 || j==i){
             cout << ">";
             if(j!=i){
                cout << " ";
             }
           }
           else{
            cout << "  ";
           }
        }
        cout << endl;
    }
}

void hourGlass(int n)
{
    for(int i=n; i>=2; i--){
        // spaces
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        // stars
        for(int j=1; j<=i; j++){
            cout << ". ";
        }
        cout << endl;
    }

    for(int i=1; i<=n; i++){
        // spaces
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        // stars
        for(int j=1; j<=i; j++){
            cout << ". ";
        }
        cout << endl;
    }
}

void shiftedPyramid(int n){

    for(int i=1; i<=n; i++){
        // spaces
        for(int j=1; j<i; j++){
            cout << " ";
        }
        // stars
        for(int j=1; j<=i; j++){
            cout << "x";
        }
        cout << endl;
    }
}

int main(){

    int n;
    cin >> n;

    // shiftedPyramid(n);
    // hourGlass(n);
    arrow(n);

    return 0;
}