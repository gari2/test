const int INF = 10000000;

//状態を表すクラスpairの場合、typedefしておくと便利である
typedef pair<int,int> P;

char maze[MAX_N][MAX_M+1]; //迷路を表す文字列の生成
int N,M; 
int sx,sy; //スタートの座標
int gx,gy; //ゴールの座標

int d[MAX_N][MAX_M];//各点までの最短距離の配列

//移動4方向のベクトル
int dx[4] = {1, 0, -1, 0}, dy[4] = {0,1,0,-1};

//(sx,sy)から(gx,gy)への最短距離を考える
//たどり着けないとINF
int bfs(){
    queue<P> que;
    //全ての点をINFで初期化する
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++); d[i][j] = INF;
        //スタート地点をキューに入れて、その点の距離を0にする
        que.push(P(sx,sy));
        d[sx][sy] = 0;

//キューが空になるまでループする
while(que.size()){
    //キューの先頭を取り出す
    P p = que.front();que.pop();
    //取り出してきた状態がゴールなら、探索をやめる。
    if(p.first == gx && p.second == gy) break;

    //移動4方向をループする
    for(int i=0; i<4;i++){
        //移動した後の点を(nx.ny)とする
        int nx = p.first + dx[i], ny = p.second + dy[i];

        //移動が可能かの判定とすでに訪れたことがあるかの判定(d[nx][ny] != INFなら訪れたことがある)
        if(0<= nx && nx<SN && 0<= ny && ny < M && maze[nx][ny] != '#'&&
        d[nx][ny] = INF){
            //移動できるならキューに入れて、その点の距離をpからの距離＋１で確定する
            que.push(P(nx,ny));
            d[nx][ny] = d[p.first][p.second] + 1;
        Ａ
        }
    }
}
return d[gx][gy];
    }
    void solve(){
        int res = bfs();
        printf("%d\n", res);
    }
}