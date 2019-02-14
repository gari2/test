#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int main(){
    int N;
    cin >> N;
vector<int> v;
    for(int i=0;i<N;i++)cin >> v[i];
    sort(v.begin(),v.end(),greater<int>());
    int a,b;
    for(int i=0;i<N;i++){
        if(i%2==0) a += v[i];
        if(i%2==1) b += v[i];
    }
    int ans;
    ans = abs(a-b);
    cout << ans << endl;



    return 0;
}