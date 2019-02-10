#include<vector>
int main(){
    std::vector<int> v;//ローカル変数としてvを生成
    .....
    std::vector<int> org{1, 2, 3};
    std::vecotr<int> x(org); //コピーコンストラクタ

    std::vector<std::vector<int>> vv{{1, 2, 3}, {4, 5, 6}};//二次元配列

    std::vector<char> str;

    std::vector<double> pos(3);

    std::vector<char> a(10, 'a');

    std::vector<double> d{1.1, 2.2, 3.3, 4.4};

    std::vector<int> org{1, 2, 3};
    std::vector<int> x(org);

    vector<int> v(5); //要素数5、int型の動的配列v
    vector<int> v2{5}; //「５」を値にもつ、要素数１、int型の動的配列v2
    vector<int> v3[5]; //要素数0の、vecotr*5この配列



}
