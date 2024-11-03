#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
#include <limits.h>
using namespace std;
using ll = long long;

/*

*/

int mat[5][5];
const int MOD = 1000;
int ans[5][5];
int N;

void Multiply(int v1[5][5], int v2[5][5])
{
    int tmp[5][5];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tmp[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                tmp[i][j] += v1[i][k] * v2[k][j];
            }
            tmp[i][j] %= MOD;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            v1[i][j] = tmp[i][j];
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll B;
    cin >> N >> B;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int a;
            cin >> a;
            mat[i][j] = a;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                ans[i][j] = 1;
            }
        }
    }

    // 10

    while (1)
    {
        if (B % 2 == 1)
        {
            Multiply(ans, mat);
        }

        Multiply(mat, mat);

        B /= 2;
        if (B == 0)
            break;
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}