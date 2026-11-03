#include <iostream>
using namespace std;

int main() {
    string exp = "hello ";
    int fort = 25;

    cout << "UW Tacoma — TCES/TCSS C++ Starter\n";
    cout << "\n" << endl;
    cout << exp << "char in quotes " << fort << endl;
    cout << endl;
    // TODO: Add a single cout statement using << chaining
    // Print two lines: one ending with \n, one ending with endl
    // Include a string, a char in quotes, and an int literal
    // End with return 0;


    // === Activity 2 ===
    int width_px = 40;          // decimal literal
    int height_px = 0x28;       // hex literal; 0x28 == 40 in base 10
    int area = width_px * height_px;
    bool isLandscape = (width_px >= height_px);
    char initial = 'D';
    string label = "Drone";
    string note = label + " area=" + to_string(area);
    int truncated = 13.9;
    double precise = 13.9;

    cout << "Label: " << label << " '" << initial << "'\n";
    cout << "Data: width=" << width_px
         << " height=" << height_px
         << " area=" << area
         << " isLandscape=" << isLandscape << "\n";
    cout << "Summary: " << note << endl;
    cout << "Truncation demo → int: " << truncated
         << "  vs double: " << precise << endl;

    // === Activity 3 ===
    cout << "Division (integer) 13/5 = " << (13 / 5) << endl;
    cout << "Division (floating) 13/5.0 = " << (13 / 5.0) << endl;

    cout << "sizeof(int)    = " << sizeof(int)    << " bytes\n";
    cout << "sizeof(double) = " << sizeof(double) << " bytes\n";
    cout << "sizeof(char)   = " << sizeof(char)   << " bytes\n";
    cout << "sizeof(bool)   = " << sizeof(bool)   << " bytes\n";
    cout << "sizeof(string) = " << sizeof(string) << " bytes\n";

    cout << "Outer area (before block) = " << area << endl;
    {
        // Inner variable hides (shadows) the outer one only inside this block
        int area = area + 7;
        cout << "Inner area (shadowed)   = " << area << endl;
    }
    cout << "Outer area (after block)  = " << area << endl;
}

