vector<int> a{1, 2, 3, 4};
vector<int> b{9, 8};
b = a; //aの内容をbに代入する 同じ型のvecotor同士なら可能である

vector<int> a{1, 2, 3, 4}; 
vector<int> b, c;
c = b = a; //aの内容をb, cに代入する

int ar[] = {1, 2, 3, 4, 5, 6, 7};
vector<int> v{9, 8};
v.assign(&ar[0], &ar[3]); //vの内容は{1, 2, 3}になる

vector<int> v{9,8};
v.assign(3, 1); //vの内容は{1, 1, 1}になる

std::vector<int> data{3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
for(int i=0;i<10;i++){
    std::cout << data[i]; //dataのi番目の値を表示する
}

const int SZ = 10; //要素数
std::vector<int>v(SZ); //指定要素数でvectorを生成
for(int i=0;i<SZ;i++)
c[i] = i; //要素数を0,1,2, ...に変更

std::vector<int>data{3, 1, 4, 1, 6, 9, 2, 6, 5, 3}; 
for(int i=0;i<10; i++)
std::cout << data.at(i); //dataのi番目の要素を表示する

//イテレータ（抽象化されたポインタ）について
std::vector



