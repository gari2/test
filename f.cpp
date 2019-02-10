#include<stdio.h>
#include<iostream>
//DFS 深さ優先探索:Depth-First-Search
//入力
using namespace std;
const int MAX_N= 20;
int a[MAX_N];
int n,k;

//iまででsumを作って、残りi以降を調べる
bool bfs(int i, int sum){
    //n個決め終わったら、今までの和sumがkと等しいかを返す
    if(i==n) return sum == k;

    //a[i]を使わない場合
    if(bfs(i+1,sum)) return true;

    //a[i]を使う場合
    if(bfs(i+1,sum+a[i])) return true;

    //a[i]を使うか使わないかに関わらず、kが作れないのでfalseを返す
    return false;
}
void solve(){
    if (bfs(0,0)) printf("Yes\n");
    else printf("No\n");
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin >> k;
    solve();
    return 0;
}