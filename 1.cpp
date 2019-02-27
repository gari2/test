//入力
int N,M;
char field[MAX_N][MAN_M+1]; //庭

//現在位置(x,y)
void dfs(int x, int y){
    //今いるところを.に置き換える
    field[x][y] = '.';

    //移動する8方向をループする
    for(int dx = -1; dx <= 1; dx++){
        //x軸方向に-1 ~ 1
        for(int dy = -1; dy <= 1; dy++){
            // y軸方向に-1 ~ 1
            //x方向にdx y方向にdy移動した場所を(nx,ny)とする
            int nx = x + dx, ny = y + dy;

            //nxとnyが庭の範囲内であるか、field[nx][ny]が水溜りであるかどうか判定
            if(0<=nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W')dfs(nx,ny);
        }
    }
    return 0;
}
void solve(){
    int res = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(field[i][j] == 'W'){
                //Wが残っているなら、そこからdfsを始める
                dfs(i,j);
                res++
            }
        }
    }
    printf("%d\n", res);
}