#include <iostream>
using namespace std;

// Calculate Area and Perimeter of Rectangle

int main()
{
    int lenght, bredth;
    cin >> lenght >> bredth;

    // Area = len * wid;
    int area = lenght * bredth;

    // Perimeter = 2 * (len + wid)
    int perimeter = 2 * (lenght + bredth);

    cout << "Area : " << area << endl;
    cout << "Perimeter : " << perimeter << endl;

    

    return 0;
}