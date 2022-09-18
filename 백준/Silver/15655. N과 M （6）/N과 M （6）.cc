// 15655번 N과 M (6)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

const int MAX = 9;
int N, M;
int pos[MAX];
//int vis[MAX];
vector<int> v;
int vsize;

void dfs(int n, int cnt){

	if(cnt == M){
		for(int i = 1; i <= cnt; i++){
			cout << pos[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int i = n + 1; i < vsize; i++){
		//if(vis[i] == 0){
		cnt += 1;
		pos[cnt] = v[i];
		//vis[i] = 1;
		dfs(i, cnt);
		cnt -= 1;
		//vis[i] = 0;
			//}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	vsize = v.size();
	
	dfs(-1,0);
	
	
	return 0;
}