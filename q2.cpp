#include <iostream>
#include <string>
using namespace std;

void binary_type(int x){
    if (x > 1){
        binary_type(x / 2);
        binary_type(x % 2);
        binary_type(x / 2);
        return;
    }
    else if (x <= 1){
        cout << x;
    }
}

int main (){
    int input;
    cin >> input;
    binary_type(input);
}