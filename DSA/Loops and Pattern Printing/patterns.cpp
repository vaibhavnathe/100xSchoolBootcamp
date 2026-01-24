#include <iostream>
using namespace std;

int main()
{
    
    int n;
    cin >> n;

    // Pyramid Alphabets
    char ch = 'A';
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << ch;
        }
        ch++;
        cout << endl;
    }


    //Number Rectangle - IV (Alphabets)
    /*
    int m;
    cin >> m;

    char ch = 'A';
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << ch;
        }
        ch++;
        cout << endl;
    }
    */

    // Numbered Rectangle - III (Aplhabets)
    /*
    int m;
    cin >> m;

    for(int i=1; i<=n; i++){
        char ch = 'A';
        for(int j=1; j<=m; j++){
            cout << ch;
            ch++;
        }
        cout << endl;
    }
    */

    // Numbered Rectangle - II
    /*
    int m;
    cin >> m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << i;
        }
        cout << endl;
    }
        */

    // Hollow Inverted Pyramid
    /*
    for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++){
            if(i==1 or i==n or j==1 or j==i){
                cout << " *";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    */

    // Hollow Pyramid
    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(i==1 or i==n or j==1 or j==i){
                cout << " *";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    */

    // Hollow Rectangle
    /*
    int m;
    cin >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 or i==n or j==1 or j==m){
                cout << " *";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
        */


    // Hollow Square
    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
        {
            if(i == 1 or i == n or j == 1 or j == n){
                cout << " *";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    */


    // Inverted Pyramid
    /*
     for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout << "*";
        }
        cout << endl;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i+1; j++){
            cout << "*";
        }
        cout << endl;
    }
    */

    // Pyramid
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout << "*";
        }
        cout << endl;
    }
    */

    /*
    int n,m;
    cin >> n >> m;

    // M stars in N rows
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << "*";
        }
        cout << endl;
    }
    */

    // N stars(Rectangle)
    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << "*";
        }
        cout << endl;
    }
    */

     //4 stars -> print 4*'s for N rows
     /*
    for(int i=0; i<n; i++){
        cout << "****" << endl;
    }
    */

    //2 stars -> print 2*'s for N rows
    /*
    for(int i=0; i<n; i++){
        cout << "**" << endl;
    }
        */


    // Print 1 to N
    /*
    for(int i=1; i<=n; i++){
        cout << i << endl;
    }
        */
    
    return 0;
}