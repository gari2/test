#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> a(2);
    vector<int> b(2);
    vector<int> c(2);

    vector<int> d(6);
    vector<int> e(3);

    for (int i = 0; i < 2; i++)
        cin >> a[i];
    for (int i = 0; i < 2; i++)
        cin >> b[i];
    for (int i = 0; i < 2; i++)
        cin >> c[i];

    //for(int i=0;i<2;i++) cout << b[i];
    d.insert(d.begin(), a.begin(), a.end());
    d.insert(d.begin(), b.begin(), b.end());
    d.insert(d.begin(), c.begin(), c.end());
    for (int i = 0; i < 6; i++)
        cout << d[i] << endl;
    int c1, c2, c3,c4;
    c1 = count(d.begin(), d.end(), 1);
    c2 = count(d.begin(), d.end(), 2);
    c3 = count(d.begin(), d.end(), 3);
    c4 = count(d.begin(), d.end(), 4);
    e.push_back(c1);
    e.push_back(c2);
    e.push_back(c3);
    sort(e.begin(),e.end());
    if(e[0]==1&&e[1]==1&&e[2]==2&&e[3]==2&&e[4]==2){

    }


    //sort(a.begin(),a.end());
    //sort(b.begin(),b.end());
    //sort(c.begin(),c.end());

    //if((a[1]==b[0]||a[1]==c[0])) cout << "閉路であるかも。";

    return 0;
}