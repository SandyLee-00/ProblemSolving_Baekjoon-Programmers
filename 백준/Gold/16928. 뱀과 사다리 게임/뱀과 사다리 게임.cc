// 16928번 뱀과 사다리 게임
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int N, M; 
vector<int>x;
vector<int>y;
vector<int>u;
vector<int>v;
queue<int> q;
queue<int>cnt;
int vis[120];

int res;

int check_p(int pos){
	for(int i = 0; i < N; i++){
		if(pos == x[i]){
			return y[i];
		}
	}
	for(int i = 0; i < M; i++){
		if(pos == u[i]){
			return v[i];
		}
	}
	return pos;
}

void bfs(int pos){
	
	for(int i = 1; i <= 6; i++){
		q.push(pos + i);
		cnt.push(1);
	}
	while(!q.empty()){
		int p = q.front();
		int qcnt = cnt.front();

		if(p == 100){
			res = qcnt;
			return;
		}
		
		q.pop();
		cnt.pop();
		
		int np = check_p(p);

		for(int i = 1; i <= 6; i++){
			if(vis[np+i] == 0){
				q.push(np + i);
				cnt.push(qcnt + 1);
				vis[np+i] = 1;
			}
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		int a, b; cin >> a >> b;
		x.push_back(a);
		y.push_back(b);
	}

	for(int i = 0; i < M; i++){
		int a, b; cin >> a >> b;
		u.push_back(a);
		v.push_back(b);
	}
	bfs(1);

	cout << res;
	
	return 0;
}