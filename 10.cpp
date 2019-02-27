#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    char b[100];
    //cin >> a;
    cin >> b;
    int i,j,ii,jj;
    i = (b[6]-'0')*10+(b[7]-'0');
    j = b[8]-'0';
    ii = b[6]-'0';
    jj = b[7]-'0';
    

    cout << i << ","<< j<< ","<<ii <<","<<jj<< endl;
    return 0;
}