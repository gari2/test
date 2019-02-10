#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)

    {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1LL << 60;
//入力
int N;
long long h[100010];

//メモ用のDPテーブル
long long dp[100010];

long long rec(int i)
{
    //DPの値が更新されていたら、そのままリターンする
    if (dp[i] < INF)
        return dp[i];

    //足場0のコストは0
    if (i == 0)
        return 0;

    //i-1, i-2を、それぞれ試す
    long long res = INF;
    chmin(res, rec(i-1)+abs(h[i]-h[i-1])); //足場i-1からきた場合
    if(i > 1)
    chmin(res,rec(i-2)+abs(h[i]-h[i-2]));//足場i-2からきた場合

    //結果をメモしながら、残す
    return dp[i] = res;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> h[i];

    //初期化する(最小化問題であるから、INFに最小化する)
    for (int i = 0; i < 100010; ++i)
        dp[i] = INF;

    //答え
    cout << rec(N - 1) << endl;
}