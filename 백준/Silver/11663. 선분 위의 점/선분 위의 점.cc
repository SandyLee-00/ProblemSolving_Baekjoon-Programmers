// 
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
#include <sstream>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

vector<ll> points;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll N, M;
	cin >> N >> M;

	for(int i = 0; i < N; i++){
		ll a;
		cin >> a;
		points.push_back(a);
	}

	sort(points.begin(), points.end());

	for(int i = 0; i < M; i++){
		ll start, end;
		cin >> start >> end;

		auto itStart = lower_bound(points.begin(), points.end(), start);

		auto itEnd = upper_bound(points.begin(), points.end(), end);

		
		cout << itEnd - itStart << "\n";
		
	}
	
	
	return 0;
}