#include<iostream>
using namespace std;
int fact(int n){
    if(n==0) return 1;
    return n * fact(n-1);
}
int main(){
    long long ans;
    ans = fact(10);
    cout << ans << endl;
    return 0;
}