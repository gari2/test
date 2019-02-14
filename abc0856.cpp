#include<iostream>
using namespace std;
int N, flag[101];//100こではなく、101こ必要であるということが、重要であるということ
int main(){
    cin >> N;
    for(int i=0;i<N;++i){
        int d;
        cin >> d;
        flag[d] = 1;
    }
    int ans = 0;
    for(int i=0;i<N;++i){
        ans += flag[i];
    }
    cout << ans << endl;
}