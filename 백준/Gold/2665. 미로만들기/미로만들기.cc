#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
각 위치에 가기 위해서 필요한 검정 바꾸는 수 최소로 업데이트하기
만약 더 비싸면 그냥 없애기
큐 빌때까지 돌리기
*/

int oriRoom[55][55];
int cntRoom[55][55];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		string a; cin >> a;
		for(int j = 0; j < n; j++){
			oriRoom[i][j] = (a[j] - '0' + 1 ) %2;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cntRoom[i][j] = 9999999;
		}
	}
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0,0,0));
	cntRoom[0][0] = 0;
	
	while(!q.empty()){
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int px = x + dx[i];
			int py = y + dy[i];
			int pcnt = cnt + oriRoom[px][py];
			
			if(px < 0 || px >= n || py < 0 || py >= n)
				continue;
			if(pcnt < cntRoom[px][py]){
				// cout << px << " " << py << " " << pcnt << "\n";
				cntRoom[px][py] = pcnt;
				q.push(make_tuple(px, py, pcnt));
			}
		}
	}
	cout << cntRoom[n-1][n-1];
	
	
	return 0;
}