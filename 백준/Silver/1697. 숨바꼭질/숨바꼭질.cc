// 1697번 숨바꼭질
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

bool visited[100001];

void bfs(int start, int end){
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(start, cnt));
	visited[start] = true;

	while(!q.empty()){
		int cur_num = q.front().first;
		int cur_cnt = q.front().second;
		q.pop();

		if(cur_num == end){
			//cout << "cur_num @" << cur_num << "\n";
			cout << cur_cnt;
			return;
		}
		int walk_b, walk_f, teleport;
		
		walk_b = cur_num - 1;
		if(walk_b >= 0){
		if(!visited[walk_b]){
			visited[walk_b] = true;
			q.push(make_pair(walk_b, cur_cnt + 1));
			//cout << "walk_b @" << walk_b << "\n";
		}}

		walk_f = cur_num + 1;
		if(!visited[walk_f]){
			visited[walk_f] = true;
			q.push(make_pair(walk_f, cur_cnt + 1));
			//cout << "walk_f @" << walk_f << "\n";
		}

		teleport = cur_num * 2;
		if(teleport <= 100000){
		if(!visited[teleport] ){
			visited[teleport] = true;
			q.push(make_pair(teleport, cur_cnt + 1));
			//cout << "teleport @" << teleport << "\n";
		}}
		
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K; cin >> N >> K;
	bfs(N, K);
	
	return 0;
}