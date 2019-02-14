#include <iostream>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 100;
int N, M;
char field[MAX_N][MAX_M + 1]; //庭

//現在位置(x,y)
void dfs(int x, int y)
{
    //今いるところを、.に置き換える
    field[x][y] = '.';

    //移動する8方向について,ループする
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            //x方向にdx, y方向にdy 移動した場所を(nx,ny)とする
            int nx = x + dx, ny = y + dy;

            //nxとnyが水たまりかどうか、またfield[nx][ny]が水たまりかどうかを特定する
            if (0 <= nx && nx < N && 0 <= nx && ny < M && field[nx][ny] == 'W')
                dfs(nx, ny);
        }
    }
    return;
}
void solve()
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (field[i][j] == 'W')
            {

            
                //Wが残っているなら、そこからdfsを始める
                dfs(i, j);
                res++;
                //cout << res << endl;
            }
        }
    }
    //cout << res << endl;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> field[i][j];
        }
    }
    solve();
    return 0;
}