//  2473번 세 용액
/*
두 개 고르고 하나 bs로 찾기 X
1개 고정, 투 포인터 사용하기

- 넘길 때 기존 선택한 것 말고 골라야 한다 X
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
using pll = pair<ll, ll>;
using pii = pair<int, int>;


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<pll> v;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back({ a, 0 });
	}

	sort(v.begin(), v.end());

	ll sum;
	ll minSum = LLONG_MAX;
	vector<int> res(3);

	for (int i = 0; i < N; i++) {
		int a = v[i].first;
		v[i].second = 1;

		int sidx = 0;
		int eidx = v.size() - 1;
		if (v[eidx].second == 1) {
			eidx -= 1;
		}
		if (v[sidx].second == 1) {
			sidx += 1;
		}

		while (1) {
			if (sidx >= eidx) {
				break;
			}
			sum = a + v[sidx].first + v[eidx].first;

			if (abs(sum) < minSum) {
				minSum = abs(sum);
				res[0] = a;
				res[1] = v[sidx].first;
				res[2] = v[eidx].first;
			}

			else if (sum >= 0) {
				eidx -= 1;
				if (v[eidx].second == 1) {
					eidx -= 1;
				}
			}
			else if (sum < 0) {
				sidx += 1;
				if (v[sidx].second == 1) {
					sidx += 1;
				}
			}
		}
		v[i].second = 0;
	}
	sort(res.begin(), res.end());

	cout << res[0] << " " << res[1] << " " << res[2];

	return 0;
}