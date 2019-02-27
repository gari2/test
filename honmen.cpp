#include <iostream>
using namespace std;
int s; //score
const int MAX_S = 100;
int skn(int x)
{
    if (s >= 90)
    {
        cout << "合格" << endl;
        return 0;
    }
    else skn(x+1);
}
int main()
{
    cin >> s;
    skn(1);
    return 0;
}