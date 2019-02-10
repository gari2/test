#include <iostream>
using namespace std;
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
const long long INF = 1LL << 60;

const int MAX_N = 110;
const int MAX_V = 100100;
//入力
int N;
long long W, weight[MAX_N], value[MAX_N]; //品物の品質は100個なので少し余裕を持たせてサイズ110

//DPテーブル
long long dp[MAX_N][MAX_V];

int main()
{
    cin >> N >> W;
    for (int i = 0; i < N; ++i)
        cin >> weight[i] >> value[i];

    //初期化
    for (int i = 0; i < MAX_N; ++i)
        for (int j = 0; j < MAX_V; ++j)
            dp[i][j] = INF;

    //初期条件
    dp[0][0] = 0;

    //DPループ
    for (int i = 0; i < N; ++i)
    {
        for (int sum_v = 0; sum_v < MAX_V; ++sum_v)
        {
            //i番目の品物を選ぶ場合
            if (sum_v - value[i] >= 0)
            {
                chmin(dp[i + 1][sum_v], dp[i][sum_v - value[i]] + weight[i]);
            }

            //i番目の品物を選ばない場合
            chmin(dp[i + 1][sum_v], dp[i][sum_v]);
        }
    }
    long long res = 0;
    for (int sum_v = 0; sum_v < MAX_V; ++sum_v)
    {
        if (dp[N][sum_v] <= W)
            res = sum_v;
    }
    cout << res << endl;
}
