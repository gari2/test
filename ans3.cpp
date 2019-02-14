#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef pair<int, int> P;
typedef long long LL;

const LL INF = 1 << 31;

int main()
{
    string a[4] = {"dream", "erase", "dreamer", "eraser"};
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < 4; ++i)
    {
        reverse(a[i].begin(), a[i].end());
    }
    bool ans = false;
    LL j = 0;
    bool aaa = true;
    while (aaa)
    {
        bool ans2 = false;
        for (int i = 0; i < 4; ++i)
        {

            if (i < 2)
            {
                string d = s.substr(j, 5);
                if (d == a[i])
                {
                    j += 5;
                    ans2 = true;
                }
                continue;
            }
            else if (i == 3)
            {
                string d = s.substr(j, 6);
                if (d == a[i])
                {
                    j += 6;
                    ans2 = true;
                }
                continue;
            }
            else
            {
                string d = s.substr(j, 7);
                if (d == a[i])
                {
                    j += 7;
                    ans2 = true;
                }
                continue;
            }
        }
        LL uuu = s.size();

        if (!ans2)
        {
            aaa = false;
            break;
        }
        else if (j >= uuu - 1)
        {
            ans = true;
            break;
        }
    }
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
