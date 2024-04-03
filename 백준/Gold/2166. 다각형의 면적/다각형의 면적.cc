// 2166번 다각형의 면적
/*

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


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<ii> v;

	double res = 0;

	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}

	ll x1 = v[0].first;
	ll y1 = v[0].second;

	for(int i = 1; i < N-1; i++){
		ll x2 = v[i].first;
		ll y2 = v[i].second;

		ll x3 = v[i+1].first;
		ll y3 = v[i+1].second;

		pair<ll, ll> v1 = {x2 - x1, y2 - y1};
		pair<ll, ll> v2 = {x3 - x1, y3 - y1};

		double tmp = v1.first * v2.second - v2.first * v1.second;
		
		res += tmp;
	}

	res = abs(res);
	res /= 2;

	cout << fixed;
	cout.precision(1);

	cout << res;

	return 0;
}