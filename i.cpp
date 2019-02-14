const int INF = 100000000;
co
//状態を表すクラスpaitの場合、typedefしておくと便利である。
char maze[MAX_N][MAX_M+1]; //迷路を表す文字列の配列
int N,M;
int sx,sy; //スタート地点の座礁
int gx,gy; //ゴール地点の座標

int d[MAX_N][MAX_M]; //各店までの最短距離の配列

//移動4方向のベクトル
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};

//(sx,sy)から(gx,gy)への最短距離を求める
//たどり着けないとINF
int bfs(){
    queue<P> que;
    //全ての点をINFで初期化
    for(int i=0;i<N;i++)
      for(int j=0;j<M;j++) d[i][j] = INF;
      //スタート地点にキューを入れて、その点の距離をゼロにする
      que.push(P(sx,sy));
      d[sx][sy];

      //キューが空になるまでループ
      while(que.size()){
          //キューの先頭を取り出す
          P p = que.front(); que.pop();
          //取り出してきた状態がゴールならば、探索をやめる
          if(p.first == gx && p.second == qy)break;

    //移動4方向をループする
    for(int i=0;i<4;i++){
        //移動した後の点を(nx,ny)とする
        int nx = p.first + dx[i], ny = p.second + dy[i];

        //
    }
      }
}