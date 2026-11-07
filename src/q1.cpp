#include <iostream>
#include <string>
using namespace std;

string type_machine(string str, int index) {
    
    if (index >= str.length() - 1) {
        return str;
    }
    if (str[index] == str[index + 1]) {
        str.erase(index + 1, 1);  
        return type_machine(str, index);  
    }
    
    return type_machine(str, index + 1);
}

int main (){
    string str;
    while (cin >> str){
        type_machine(str, 0);
    }
}