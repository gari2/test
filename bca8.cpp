#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N,A,b=0,ans=0; //b :ビット和
    cin >> N;

    for(int i=0;i<N;++i){
        cin >> A; //A[i]を格納する
        b = (A | b); //bはA_1~A_Nのビット和
    }
    while((b&1)==0){ //ビット和の最下位ビットが0である限り
    b = b >> 1; //ビット和を右に１ビットシフトして
    ans++; //操作回数を１回増やす
    }
    cout << ans << endl;
    return 0;
}