#include <iostream>
using namespace std; 


int main(){
    int Num;

    cout << "Request Number: "; 
    cin >> Num;

    if (Num >= -50 && Num <= 150) {
        cout << "The Number is valid";
    }
    
    return 0;
}