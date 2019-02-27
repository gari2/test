//入力
int L, P, N;
int A[MAX_N + 1], B[MAX_N + 1];

void solve()
{
    // 簡単のため、ゴールをガゾリンスタンドに設定する
    A[N] = L;
    B[N] = 0;
    N++;

    //ガソリンスタンドを管理する順位キュー
    priority_queue<int> que;

    //ans: 補給回数、pos：今いる場所、tank:タンクのガソリン量
    int ans = 0;
    pos = 0;
    tank = P;

    for (int i = 0; i < N; i++)
    {
        //次に進む距離について
        int d = A[i] - pos;
        //十分な量になるまで、ガソリンを補給する
        while (tank - d < 0)
        {
            if (que.empty())
            {
                puts("-1");
                return;
            }
            tank += que.top();
            que.pop;
            ans++;
        }
        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }
    printf("%d\n", ans);
}
