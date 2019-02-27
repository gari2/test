#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <climits>
#include <set>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
typedef pair<ll, ll> pll;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
#define MOD 1000000007
#define ARRAY_MAX 200005
const int INF = 1e9 + 7;
int main()
{
    int A,B,a,b,c;
    cin >> A >> B;
    a = A+B;
    b = A*B;
    c = A-B;
while(1){
if(a >=b && b >=c) cout << a <<endl;break;
if(a >=b && b <=c && a >= c) cout << a <<endl;break;
if(b >=a && a>=c) cout << b <<endl;break;
if(b >=a && a<=c && b >= c) cout << b <<endl;break;
if(c >=a && a>=b) cout << c <<endl;break;
if(c >=a && a<=b && b >= c) cout << c <<endl;break;
}
    return 0;
}