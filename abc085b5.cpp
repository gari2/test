#include<iostream>
#include<set>
using namespace std;
int main(){
    int n;
    int a;
    set<int> s;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        s.insert(a);
    }
    cout << s.size()<< endl;
    return 0;
}