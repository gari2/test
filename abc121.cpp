#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int W, H, w, h, x;
    cin >> W >> H;
    cin >> w >> h;

    x = (W-w)*(H-h);

    cout << x << endl;
    
    return 0;
}