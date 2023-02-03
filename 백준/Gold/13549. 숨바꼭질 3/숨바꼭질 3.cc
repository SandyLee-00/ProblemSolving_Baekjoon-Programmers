// 13549번 숨바꼭질 3
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
bfs로 매 초마다 이동하기
*2 할 때는 시간 추가 안하고 큐에 넣기

큐에 넣을 때 모든 *2에다가 큐 넣기
*/
const int MAX = 100005;
bool vis[MAX];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int K; cin >> K;
	deque<pair<int, int>> q;
	q.push_front({N, 0});
	int res = MAX;
	vis[N] = 1;
	
	while(!q.empty()){
		int pos = q.front().first;
		int cnt = q.front().second;
		// cout << pos << " ";
		q.pop_front();
		if(pos == K){
			res = cnt;
			break;
		}
		
		
		// for(int i = pos * 2; i < MAX; i = i * 2){
		// 	if(vis[i] == 0){
		// 		vis[i] = 1;
		// 		q.push({i, cnt});
		// 	}
		// }
		if(pos * 2 < MAX){
			if(vis[pos * 2] == 0){
				vis[pos * 2] = 1;
				q.push_front({pos*2, cnt});
			}
		}
		
		if(pos-1 >= 0){
		if(vis[pos-1] == 0){
			vis[pos-1] = 1;
			q.push_back({pos-1, cnt + 1});
		}
		}
		if(pos + 1 < MAX){
		if(vis[pos+1] == 0){
			vis[pos+1] = 1;
			q.push_back({pos+1, cnt + 1});
		}
		}
	}
	cout << res;
	
	return 0;
}