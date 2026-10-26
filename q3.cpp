#include <iostream>
#include <string>
#include <vector>
using namespace std;




vector<int> read_list(int n) {
    if (n <= 0) return {};
    int x;
    cin >> x;
    vector<int> v = read_list(n - 1);
    v.insert(v.begin(), x);     
    return v;
}

void reverse_it(vector <int>& v, int i){
    if (i >= v.size()){
        return;
    }
    cout << v[v.size() - i - 1];

    return reverse_it(v, i + 1);
}

void print_no_rev(vector <int> &v, int i){
    if (v.size() <= i){
        return;
    }
    cout << v[i];
    print_no_rev(v, i +1);

}

void train_func(vector <int>& v, int k, int n){
    // cin >> n >> k ;
    
    if (v.size() >= k){
        vector<int> sub(v.begin() , v.begin() + k);
        reverse_it(sub, 0);

        vector<int> new_v(v.begin() + k , v.end() );
        train_func(new_v, k, n);

    }
    else{
        print_no_rev(v, 0);
        return;
    }

}

int main (){
    int n,k;
    cin >> n >> k;
    vector <int> v = read_list(n);
    train_func(v, k, n);
     cout << endl;
    //  << n<< k;
}

