#include<iostream>
using namespace std;
int main(){
    const int MAX_N=30,MAX_M=30;
    int a[MAX_N][MAX_M] = {{0}};
    int N,M,ans;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> a[i][j];
        }
    }
    cout << ans;
    return 0;
}