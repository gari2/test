#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b;
    c =a*b;
    if(c%2==0)cout << "Even";
    else cout << "Odd";
    return 0;
}