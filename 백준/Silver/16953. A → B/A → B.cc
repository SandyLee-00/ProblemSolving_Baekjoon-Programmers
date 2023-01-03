//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*

*/
ll const MAX = 1000000009;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll A, B; cin >> A >> B;
	queue<pair<ll, int>> q;
	int res = -1;
	q.push({A, 0});
	
	while(!q.empty()){
		ll num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		// cout << num << " ";
		
		if(num == B){
			res = cnt + 1;
			break;
		}
		
		ll fir = num * 2;
		if(fir <= B){
			q.push({fir, cnt+1});
		}
		
		ll sec = stol(to_string(num) + "1");
		if(sec <= B){
			q.push({sec, cnt+1});
		}
		
	}
	cout << res;
	
	return 0;
}