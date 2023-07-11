// 11725번 트리의 부모 찾기

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
using ll = long long;

/*
N+1개 Vertex만들기
fir, sec 중에 그래프에 값 0 아니면 상대방을 벡터에 넣기
@ 나중에 위로 연결되면 어떤게 level 높은지 모른다

N+1개 Vertex만들기
all 에 각 vertex에서 edge 추가되면 push_back 하기


*/

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> all(N + 1, vector<int>(0));

	for(int i = 1; i < N; i++){
		int a, b;
		cin >> a >> b;
		
		all[a].push_back(b);
		all[b].push_back(a);
	}

	// for(int i = 0; i <= N; i++){
	// 	for(int j = 0; j < all[i].size(); j++){
	// 		cout << all[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	vector<int> res(N + 1, 0);
	res[0] = -1;
	res[1] = -1;

	queue<pair<int, int>> q;

	for(int i = 0; i < all[1].size(); i++){
		q.push(make_pair(all[1][i], 1));
	}

	while(!q.empty()){
		int child = q.front().first;
		int parent = q.front().second;
		q.pop();

		if(res[child] != 0){
			continue;
		}

		res[child] = parent;
		for(int i = 0; i < all[child].size(); i++){
		q.push(make_pair(all[child][i], child));
		}
	}

	for(int i = 2; i <= N; i++){
		cout << res[i] << "\n";
	}
		
	return 0;
}