// 2812번 크게 만들기
/*
앞자리 가장 큰 수 유지 -> 앞에서부터 뺄 수 있을만큼 빼면서 크게 만들기
현재 수보다 작은 수가 앞에 있으면 지우기
끝까지 갔는데 cnt 남았으면 뒤에서 빼서 맞춰주기

결과 string 이여서 char로 넣기

시간초과 난다! 

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

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	string target;
	cin >> target;

	int popCount = 0;

	stack<char> s;

	for (int i = 0; i < target.size(); i++) {
		char num = target[i];

		while (!s.empty()) {
			if (popCount >= K || num <= s.top()) {
				break;
			}
			if (num > s.top()) {
				s.pop();
				popCount += 1;
			}
		}

		s.push(num);
	}

	while (!s.empty()) {
		if (popCount >= K) {
			break;
		}
		s.pop();
		popCount += 1;
	}

	vector<char>resV;

	while(!s.empty()){
		resV.push_back(s.top());
		s.pop();
	}

	for(int i = resV.size() - 1; i >= 0; i--){
		cout << resV[i];
	}

	// string + 연산 -> 벡터에 넣기
	string res;
	// while (!s.empty()) {
		// res = s.top() + res;
		// s.pop();
	// }

	// cout << res;


	return 0;
}