#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main(){
    int cnt[4]{};
    REP(i,3){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        cnt[a]++;
        cnt[b]++;
    }
    bool ok = true;
   REP(i,n) if(cnt[i]>2) ok=false;
    cout <<(ok?"YES":"NO");
}