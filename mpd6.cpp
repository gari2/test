#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

int a, b;
int d[5];

int main()
{
    for (int i = 1; i <= 3; i++)
        cin >> a >> b, d[a]++, d[b]++;
    sort(d + 1, d + 4 + 1);
    if (d[1] == 1 && d[2] == 1 && d[3] == 2 && d[4] == 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}