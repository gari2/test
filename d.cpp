#include<stack>
#include<cstdio>

using namespace std;

int main(){
    stack<int> s; //int型をデータ構造とするスタックを用意する LIFO(Last in Last out)
    s.push(1);//{} →{1}
    s.push(2);//{1}→{1,2}
    s.push(3);//{1,2} →{1,2,3}
    printf("%d\n", s.top());//3
    s.pop(); //{1,2}→{1}
    printf("%d\n", s.top());// 1
    s.pop();//{1}→{}
    return 0;
}