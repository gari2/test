#include <iostream>
using namespace std;

int calc(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += x % 10; //10の位も100の位も、何回か割れば10で割った余りになる。14%10 = 4 4%10 = 4など
        x /= 10;
    }
    return ret;
}
int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum = calc(i);
        if (sum >= a && sum <= b)
            ans += i;
    }
    cout << ans << endl;
}