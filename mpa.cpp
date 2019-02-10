#include<iostream>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    if(n>=(2*k-1)) cout << "YES" << endl;
    else cout << "NO"<< endl;
    return 0;
}