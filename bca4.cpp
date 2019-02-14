#include <iostream>
using namespace std;
  int N;
    cin >> N;
    int A[N];int cnt=0;
void solve{
    for (int i = 0; i < N; i++)
    {
        if (A[i % 2 == 1])
            continue;
        if (A[i % 2 == 0])
            A[i] = A[i] / 2;
            cnt++;

    }
}
int main()
{
    return 0;
}