typedef long long ll;

//入力
int N , L[MAX_N];

void solve(){
    ll ans = 0;

    //順位キューを用意する（小さい数から出てくるようにしています）
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i=0;i<N;i++){
        que.push(L[i]);
    }
    //板が一本になるまで、適用する
    while(que.size() > 1){
        //一番短い板、次に短い板を取り出す
        int l1,l2;
        ll = que.top();
        que.pop();
        l2 = que.top();
        que.pop();

        //それらを併合する
        ans += l1+l2;
        que.push(l1+l2);
    }
    printf("%lld\n", ans);
    
}