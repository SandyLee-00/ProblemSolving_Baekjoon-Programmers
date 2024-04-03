// 27172번 수 나누기 게임
/*
N^2으로 접근하면 안된다
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int MAXV2 = 1000005;

int num[MAXV2];
int v[MAXV2];
int res[MAXV2];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < MAXV2; i++) {
		v[i] = -1;
		num[i] = -1;
		res[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v[i] = a;
		num[a] = i;
	}

	for (int i = 0; i < N; i++) {
		int first = v[i];
		int firIdx = i;

		for (int j = first * 2; j < MAXV2; j += first) {

			if (num[j] != -1) {
				int second = j;
				int secIdx = num[j];

				res[secIdx] += -1;
				res[firIdx] += 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << res[i] << " ";
	}

	return 0;
}