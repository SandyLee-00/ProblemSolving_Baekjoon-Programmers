// 1766번 문제집
/*
위상정렬 순서대로 출력하기 
- 가능한 쉬운 순서대로 count 0이면 먼저 -> pq 사용하기
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

	int N, M;
	cin >> N >> M;

	vector<vector<int>> con(N + 1);
	vector<int> counts(N+1);
	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		counts[b] += 1;
		con[a].push_back(b);
	}

	for(int i = 1; i <= N; i++){
		if(counts[i] == 0){
			pq.push(i);
		}
	}

	while(!pq.empty()){
		int n = pq.top();
		cout << n << " ";
		
		pq.pop();
		
		for(int i = 0; i < con[n].size(); i++){
			int next = con[n][i];
			counts[next] -= 1;
			
			if(counts[next] == 0){
				pq.push(next);
			}
		}
	}
		

	return 0;
}