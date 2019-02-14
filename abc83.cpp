#include<iostream>
using namespace std;
int main(){
    int N,A,B;
    cin >> N >> A >> B;
    int ans = 0;
    for(int i=0;i<=N;i++){
        if(A<= (i/10+i%10)&&(i/10+i%10) <= B) {
            cout << i << endl;
            ans += i;
    }
}
cout << ans << endl;
    return 0;
}
