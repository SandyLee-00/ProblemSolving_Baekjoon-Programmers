#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
*/

bool nums[55];

void dfs(vector<int> v, int cnt, int pos){
	if(cnt == 6){
		for(int i = 0; i < 55; i++){
			if(nums[i] == true)
				cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = pos+1; i < v.size(); i++){
		nums[v[i]] = true;
		dfs(v, cnt+1, i);
		nums[v[i]] = false;
		
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while(1){
		int k; cin >> k;
		if(k == 0) break;
		vector<int> v;
		for(int i = 0; i < k; i++){
			int a; cin >> a;
			v.push_back(a);
		}
		dfs(v, 0, -1);
		cout << "\n";
	}
	
	return 0;
}