#include <iostream>
using namespace std; 


int main(){
    char doAgain = 'y';
    int sum = 0;

    cout << "This code will increment sum 1 or more times. \n";
    do{
        cout << "Sum has been incremented. Do again? (y/n) ";
        cin >> doAgain;
        sum++;
    } while ((doAgain == 'y') || (doAgain == 'Y'));
    cout << "Sum was incremented " << sum << " times.\n";
}