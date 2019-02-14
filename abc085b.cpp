#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    int N,ans;
    cin >> N;
    vector<int> v;
    for(int i=0;i<N;i++) cin >> v[i];
    //sort(v.begin(),v.end());
    //v.erase(unique(v.begin(),v.end()),v.end());
    set<int> s(v.begin(),v.end());
    vector<int> v2(v.begin(),v.end());
    ans =v2.size();
    cout << ans << endl;
    return 0;
}