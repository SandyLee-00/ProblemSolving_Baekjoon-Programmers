#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

/*
dp
for문 N개째에서 값 구하기 
메모리 초과 난다

*/

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	const int MOD = 4;

	vector<vector<int>> minv(MOD, vector<int>(3, INT_MAX));
	vector<vector<int>> maxv(MOD, vector<int>(3));

	int a, b, c;
	cin >> a >> b >> c;

	minv[0][0] = a;
	minv[0][1] = b;
	minv[0][2] = c;

	maxv[0][0] = a;
	maxv[0][1] = b;
	maxv[0][2] = c;

	for (int i = 1; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		int idx = i % MOD;
		int idxm1 = (i + MOD-1) % MOD;

		minv[idx][0] = a + min(minv[idxm1][0], minv[idxm1][1]);
		minv[idx][1] = b + min(min(minv[idxm1][0], minv[idxm1][1]), minv[idxm1][2]);
		minv[idx][2] = c + min(minv[idxm1][1], minv[idxm1][2]);

		maxv[idx][0] = a + max(maxv[idxm1][0], maxv[idxm1][1]);
		maxv[idx][1] = b + max(max(maxv[idxm1][0], maxv[idxm1][1]), maxv[idxm1][2]);
		maxv[idx][2] = c + max(maxv[idxm1][1], maxv[idxm1][2]);
	}

	int Nm1idx = (N - 1) % MOD;

	cout << max(max(maxv[Nm1idx][0], maxv[Nm1idx][1]), maxv[Nm1idx][2]) << " ";
	cout << min(min(minv[Nm1idx][0], minv[Nm1idx][1]), minv[Nm1idx][2]);
	

	return 0;
}