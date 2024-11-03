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

ll fibs[2][2] = {{1, 1}, {1, 0}};
ll ans[2][2] = {{1, 0}, {0, 1}};

const ll MOD = 1000000007;

void Mul(ll v1[2][2], ll v2[2][2])
{
    ll tmp[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            tmp[i][j] = 0;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ll modNum = (v1[i][k] * v2[k][j]) % MOD;

                tmp[i][j] = (tmp[i][j] + modNum) % MOD;
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            v1[i][j] = tmp[i][j];
            // cout << v1[i][j] << " ";
        }

       // cout << "\n";
    }

    // cout << "\n";
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    while (1)
    {
        if (n % 2 == 1)
        {
            Mul(ans, fibs);
        }

        Mul(fibs, fibs);

        n /= 2;
        if (n == 0)
        {
            break;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
           //  cout << ans[i][j] << " ";
        }
       //  cout << "\n";
    }

    cout << ans[0][1];

    return 0;
}