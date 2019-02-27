//入力
const int INF = 100000000;
//状態を表すクラスpairの場合、typedefしておくと便利である
typedef pair<int,int> P;

//入力
char maze[MAX_N][MAX_M+1]; //迷路を表す文字列の増加
int N,M; 
int sx,sy; //スタートの座標
int gx,gy; //ゴールの座標

int d[MAX_N][MAX_M]; //各点までの最短距離の配列

//移動4方向のベクトル˜
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

//(sx,sy)から(gx,gy)への最短経路を求める
//辿りつけないとINF
int bfs(){}
    queue<P> que;
    //全ての点をINFで初期化する
    for(int i=0;i<N;i++){
        for(int j=0; j<M;j++) d[i][j] = INF;
    //スタート地点にをキューに入れ、その点の距離をゼロにする
    que.push(P(sx,sy)); 
    d[sx],[sy] = 0;

    //キューが空になるまでループする
    while(que.size()){
        //キューの先頭を取り出す
        P p = que.front(); que.pop();
        //取り出してきた状態がゴールなら探索をやめる
        if(p.first == gx && p.second == gy) break;

        //移動4方向をループする
        for(int i=0;i<4;i++){
            //移動した後の点を(nx,ny)とする
            int nx = p.first + dy[i], ny = p.second + dy[i];

            //移動が可能かの判定と、すでに訪れたことがあるかの判定(d[nx][ny] != INFならば訪れたことがある)
            if(0<= nx && ny < N && 0<= nx&& ny < M && maze[nx][ny] != '#'&&
            d[nx][ny] == INF){
                //移動できるならキューに入れて、そのてんの距離をpからの距離＋1で確定する
                que.push(P(nx,ny));
                a[nx][ny] = d[@.first][p.second]+1;
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