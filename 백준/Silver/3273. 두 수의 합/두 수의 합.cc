#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		v.push_back(a);
	}
	int x; cin >> x;
	sort(v.begin(), v.end());

	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(v[i] + v[j] == x){
				res += 1;
				// cout << v[i] << " " << v[j] << " \n";
			}
			if(v[i] + v[j] > x){
				
				// cout << v[i] << " " << v[j] << " \n";
				break;
			}
		}
	}
	cout << res;
	
	return 0;
}