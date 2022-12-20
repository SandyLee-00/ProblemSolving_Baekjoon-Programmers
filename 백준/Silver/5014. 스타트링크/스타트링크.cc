// 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/
int vis[1000005];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	queue<pair<int, int>> q;
	int res = -1;
	
	q.push({S, 0});
	while(!q.empty()){
		int floor = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(floor == G){
			res = cnt;
			break;
		}
		if(floor + U <= F){
			if(vis[floor + U] == 0){
				vis[floor + U] = 1;
				q.push({floor + U, cnt + 1});
			}
		}
		if(floor - D > 0){
			if(vis[floor - D] == 0){
				vis[floor - D] = 1;
				q.push({floor - D, cnt + 1});
				
			}
		}
	}
	if(res == -1)
		cout << "use the stairs";
	else{
		cout << res;
	}
	
	
	return 0;
}