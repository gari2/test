#include<iostream>
using namespace std;
int main(){
    const int N = 3;
    char h[N];int cnt = 0;
    for(int i=0;i<N;i++){
       cin >> h[i];
       if(h[i] == '1')  cnt++;
    }
    cout << cnt << endl;
    
    return 0;
}