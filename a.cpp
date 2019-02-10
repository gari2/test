#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ALL(A) A.begin(), A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
const LL mod = 1000000007;
const LL LINF = 1LL<<62;
const LL INF = 1<< 17;

int main(){
    vector<int>x(4,0);
    for(int i=0;i<3;i++){
        int a,b;cin >> a >> b;
        a--;b--;
        x[a]++;x[b]++;
    }
    for(int i=0;i<4;i++){
        if(x[i]>= 3){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
