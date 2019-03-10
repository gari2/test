#include <iostream>
#include <cstdio>
using namespace std;
const int MAX_Bi = 100;
int main()
{
    int N, M, C;
    int cnt = 0;
    cin >> N >> M >> C;
    int B[MAX_Bi];
    int A[23][23];
    for (int i = 0; i < M; i++)
        cin >> B[i];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        int tmp = 0;
        for (int j = 0; j < M; j++)
        {
            tmp += A[i][j] * B[j];
            //printf("%d\n", tmp);
        }
            if (tmp + C > 0) cnt++;
        
    }
    //printf("%d\n", s);

    cout << cnt << endl;
    return 0;
}