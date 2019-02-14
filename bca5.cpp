#include<iostream>
using namespace std;
int main(int argc, char const *argv[]) //main関数の仮引数が、こうなっている理由がよくわからない
{
    int N,A[200],ans = 0; //N,A :問題文通りの定義 / ans : 答え
    cin >> N; //Nを格納

    for(int i = 0; i < N; ++i){
        cin >> A[i]; //A_i~A_Nの入力をA[0]からA[N-1]に代入する
    }
    ans = 0; //操作可能回数は0回からスタート
    while(1){  //while(1)のテクニックの意味を知りたい → 意図的な無限ループ文。breakやreturn文で、whileを抜け出すコードを書くことがほとんど。
        bool allEven = true; //全て偶数かどうかのフラグ

        for(int i=0;i<N;++i) //黒板の数字全てについて
        {
            if(A[i]%2==1){ //A[i]が奇数ならば終了
            allEven = false;
            break;             
            }else{ //A[i]が偶数ならば2で割って再代入
            A[i] /=2;
            }
        }
        if(!allEven){ //奇数が含まれていた場合→操作可能回数を増やす
            break;
        }else{
            ans++; //全て偶数だった場合→操作可能回数を+1する
        }
    }
    cout << ans << endl; //答えを出力する
    return 0;
}
