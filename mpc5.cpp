#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define INF 1LL<<60
#define fs first
#define sc second
#define pb push_back
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b-1);i>=a;i--) //なんだこれは　デクリメントか
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define RITR(itr,mp) for(auto itr = (mp).begin();itr != (mp).end(); ++itr)//なんだこれは
#define range(i,a,b) (a)<=(i) &&(i)<=(b)
#define debug(x) cout << #x << " = " << (x) << endl; //具体的な使い方がわからん
#define SP << " " << 
typedef pair<int, int> P; //具体的な使い方がわからん
typedef vector<vector<P> > Graph;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> x(n);
    REP(i,n) cin >> x[i];
    vector<int> c(n);
    REP(i,n) cin >> c[i];
    vector<int> v(n);
    REP(i,n)cin >> v[i];

    //bitがたっている商品を購入可能な時、その値段と価値のsum ←bitが立つってなんだ
    vector<int> cc(1<<n), vv(1<<n), cnt(1<<n, 0); //<<の意味がわからん ビットシフトか?

}



