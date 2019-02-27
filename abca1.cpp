#include<iostream>
using namespace std;
int main(){
    int A, B, ans;
    cin >> A >> B;
    if(B % A == 0) ans = A + B;
    else ans = B -A;
    cout << ans << endl;
    return 0;
}