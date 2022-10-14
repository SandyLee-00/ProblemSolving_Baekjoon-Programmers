// 9375번 패션왕 신해빈
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

/*

*/

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		vector<pair<string, int>>v;

		for(int i = 0; i < n; i++){
			int flag = 0;
			string a; cin >> a;
			string b; cin >> b;
			for(int i = 0; i < v.size(); i++){
				if(v[i].first == b){
					v[i].second += 1;
					flag = 1;
					break;
				}
			}
			if(flag == 0){
				v.push_back({b, 1});
			}
		}
		if(v.size() == 1){
			cout << v[0].second;
		}
		else{
			int res = 1;
			for(int i = 0; i < v.size(); i++){
				res *= (v[i].second + 1);
			}
			res -= 1;
			cout << res;
		}
		cout << "\n";
	}
	

	return 0;
}