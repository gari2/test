#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int n, q, t;
    string name;

    //標準ライブラリからqueueを使用する
    queue<pair<string, int>> Q;//プロセスのキュー
    cin >> n >> q;

    //全てのプロセスにキューを順番に追加する
    for(int i=0; i< n; i++){
        cin >> name >> t;
        Q.push(make_pair(name, t));
    }

    pair<string, int> u;
    int elaps = 0, a;

    //シュミレーションをする
    while(!Q.empty()){
        u = Q.front(); Q.pop();  // qまたは必要なじかんu.tだけ処理を行う。
        u.second -= a; //残りの必要時間を計算する
        elaps += a; //経過時間を加算する
        if (u.second > 0){
            Q.push(u); //処理が済んでいなければキューに追加する

        } else {
            cout << u.first << " " << elaps << endl;
        }
    }
    return 0; 
}