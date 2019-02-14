#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, A, ans; // N,A : 問題文通りの定義 / ans : 答え
    cin >> N;      // Nを格納
    ans = 1000;    // 最終的な答えは最小値なので、まずはどんな答えよりも大きい数字を代入

    for (int i = 0; i < N; ++i)
    {
        cin >> A;       // A_iをAに格納
        int tmpAns = 0; // A_iに対する「最大で何回 2 で割れるか」の値。最初は0

        while (A % 2 == 0)
        {              // Aを2で割れるかぎり
            tmpAns++;  // 割れる回数を+1して
            A = A / 2; // Aには2で割った数値を再代入
        }

        if (tmpAns < ans)
        { // tmpAnsがansより小さければansに代入 →ansはtmpAnsの最小値となる
            ans = tmpAns;
        }
    }

    cout << ans << endl; // 答えを出力
    return 0;
}