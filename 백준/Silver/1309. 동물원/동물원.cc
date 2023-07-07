#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

ll cage[100005][3] = { 0 };

ll dp(int N, int pos)
{
	if (cage[N][pos] != -1)
	{
		return cage[N][pos];
	}

	if (N == 1)
	{
		return 1;
	}
	else if (pos == 0)
	{
		cage[N][pos] = (dp(N - 1, 0) + dp(N - 1, 1) + dp(N - 1, 2)) % 9901;
		return cage[N][pos];
	}
	else if (pos == 1)
	{
		cage[N][pos] = (dp(N - 1, 0) + dp(N - 1, 2)) % 9901;
		return cage[N][pos];
	}
	else if (pos == 2)
	{
		cage[N][pos] = (dp(N - 1, 0) + dp(N - 1, 1)) % 9901;
		return cage[N][pos];
	}

	return cage[N][pos] % 9901;
}

int main(void)
{
	int N;
	cin >> N;

	for (int i = 0; i < 100005; i++)
	{
		cage[i][0] = -1;
		cage[i][1] = -1;
		cage[i][2] = -1;
	}

	cage[0][0] = 0;
	cage[0][1] = 0;
	cage[0][2] = 0;

	cage[1][0] = 1;
	cage[1][1] = 1;
	cage[1][2] = 1;

	cout << ((dp(N, 0) + dp(N, 1)) % 9901 + dp(N, 2)) % 9901 << endl;

	return 0;
}