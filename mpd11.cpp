#include<iostream>
using namespace std;
int main(){
    int a1,b1;
    cin >> a1 >> b1;
    int a2,b2;
    cin >> a2 >> b2;
    int a3,b3;
    cin >> a3 >> b3;

    if(a1==a2||a1==b2){
        if(a1==a3||a1==b3){
            cout<< "NO"<<endl;
            return 0;
        }
    }
    if(b1==a2||b1==b2){
        if(b1==a3||b1==b3){
            cout<< "NO"<<endl;
            return 0;
        }
    }
}