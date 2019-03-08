#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack <int> S;

    S.push(3);//スタックに３をつむ
    S.push(7);//スタックに７をつむ
    S.push(1);//スタックに３をつむ　スタックのサイズ＝３
    cout << S.size() << " "; //3

    cout << S.top() << " "; //1
    S.pop(); //スタックの頂点から要素を削除する

    cout << S.top() << " ";// 7
    S.pop();

    cout << S.top() << " "; //3

    S.push(5);

    cout << S.top() << " "; //5
    S.pop();

    cout << S.top() << " "; //3

    return 0;  
}