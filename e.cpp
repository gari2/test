#include<queue>
#include<cstdio>

using namespace std;
int main(){
    queue<int> que; //int型をデータ型とするキューを用意する FIFO First in first out
    que.push(1); //{}→{1}
    que.push(2); //{1}→{1,2}
    que.push(3); //{1,2}→{1,2,3}
    printf("%d\n",que.front()); //1
    que.pop(); //一番下から取り除く {1,2,3}→{2,3}
    printf("%d\n", que.front());// 2
    que.pop();//{2,3}→{3}
    printf("%d\n", que.front());//3
    que.pop(); //{3}→{}
    return 0;
}