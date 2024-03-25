// 2623번 음악프로그램
/*
위상정렬
순서 불가능할 경우 처리...?
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

	vector<int> counts(N + 1);
	vector<vector<int>> con(N + 1);

	for(int i = 0; i < M; i++){
		int n;
		cin >> n;
		vector<int> t;
		
		for(int j = 0; j < n; j++){
			int a;
			cin >> a;
			t.push_back(a);
		}

		for(int j = 0; j < t.size()-1; j++){
			int a = t[j];
			int b = t[j + 1];
			counts[b] += 1;
			con[a].push_back(b);
		}
	}

	queue<int> q;
	for(int i = 1; i < counts.size(); i++){
		if(counts[i] == 0){
			q.push(i);
		}
	}

	vector<int> resV;
	while(!q.empty()){
		int node = q.front();
		resV.push_back(node);
		// cout << node << " ";
		q.pop();

		for(int i = 0; i < con[node].size(); i++){
			int next = con[node][i];
			counts[next] -= 1;
			if(counts[next] == 0){
				q.push(next);
			}
		}
	}

	if(resV.size() == N){
		for(int i = 0; i < N; i++){
			cout << resV[i] << "\n";
		}
	}
	else{
		cout << 0;
	}
	
	return 0;
}