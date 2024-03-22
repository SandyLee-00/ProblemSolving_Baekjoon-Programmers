// 1202번 보석 도둑 
/*
가방 무게 작은 순부터 나열
가방 들어갈 수 있는 것 pq에 넣기
결과 더하기
시간초과 이유: 보석 가방에 넣을 때 전부 체크
- 보석 무게별로 정렬하기, 넣어야 할 범위만 목록에 넣기
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

	int N, K;
	cin >> N >> K;
	vector<ii> jewels;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		jewels.push_back({ a, b });
	}

	vector<int> Cs;
	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		Cs.push_back(a);
	}

	sort(Cs.begin(), Cs.end());
	sort(jewels.begin(), jewels.end());

	for (int i = 0; i < jewels.size(); i++) {
		// cout << jewels[i].first << " " << jewels[i].second << "\n";
	}

	long long res = 0;
	priority_queue<int> pq;

	int nowWeight = 0;
	int idx = 0;

	// 이전-현재 무게 사이 전부 pq에 넣기
	for (int i = 0; i < Cs.size(); i++) {
		nowWeight = Cs[i];

		while(1){
			if(nowWeight < jewels[idx].first){
				break;
			}
			if(idx >= N){
				break;
			}
			pq.push(jewels[idx].second);
			idx += 1;
		}

		if (!pq.empty()) {
			res += pq.top();
			// cout << pq.top() << "\n";
			pq.pop();
		}

	}

	cout << res;

	return 0;
}