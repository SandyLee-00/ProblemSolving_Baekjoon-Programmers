// 15663번 N과 M (9)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/
int num[10];
int n, m;
int prt[10];
bool vis[10];

void rec(int idx, int cnt){
	if(cnt == m){
		for(int i = 1; i <= m; i++)
			cout << prt[i] << " ";
		cout << "\n";
		return;
	}
	int last = -1;
	
	for(int i = 0; i < n; i++){
		if(last != num[i] && vis[i] == false){
			cnt += 1;
			prt[cnt] = num[i];
			last = num[i];
			vis[i] = 1;
			
			rec(i, cnt);
			vis[i] = 0;
			cnt -= 1;
		}
	}
}


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	sort(num, num + n);
	rec(0, 0);
	
	return 0;
}