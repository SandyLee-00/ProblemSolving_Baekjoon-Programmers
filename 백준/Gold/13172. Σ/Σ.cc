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
v2에 들어있는 수들의 최소공배수 구하기
v1에 대해서 최소공배수로 더할 값 구하기
각 값 더해서 a / b 만들기

a / b gcd로 기약분수 만들기


*/

const ll MOD = 1000000007;

ll GetGCD(ll fir, ll sec)
{
	ll num;

	while (1)
	{
		num = fir % sec;

		fir = sec;
		sec = num;

		if (num == 0)
		{
			// cout << fir;
			return fir;
		}
	}
}

ll Mul(ll fir, ll sec)
{
	ll res = (fir % MOD * sec % MOD) % MOD;
	return res;
}

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll M;
	cin >> M;
	ll ans = 0;

	for (ll i = 0; i < M; i++)
	{
		ll a, b;
		cin >> a >> b;

		ll val = 1;
		ll z = 1000000005;
		ll muls = a;

		while (1)
		{
			if (z % 2 == 1)
			{
				val = Mul(val, muls);
			}

			muls = Mul(muls, muls);

			z /= 2;
			if (z == 0)
			{
				break;
			}
		}

		ans += ((b * val) % MOD);
		ans %= MOD;
	}

	cout << ans;

	return 0;
}