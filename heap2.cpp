#include<queue>
#include<cstdio>
using namespace std;
int main(){
    //宣言
    priority_queue<int> pque;

    //要素の追加について
    pque.push(3);
    pque.push(5);
    pque.push(1);

    //からになるまでループする
    while(!pque.empty()){
        //最大値の取得及び削除
        printf("%d\n", pque.top());
        pque.pop();
    }
        return 0;
}