// 4307번 개미
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T; 
	while(T--){
		int length; cin >> length;
		int n; cin >> n;
		vector<int> pos(n);
		for(int i = 0; i < n; i++){
			cin >> pos[i];
		}
		int res_min, res_max, tmp_max, tmp_min;
		res_min = 0;
		res_max = 0;
		for(int i = 0; i < n; i++){
			int to_left = pos[i];
			int to_right = length - pos[i];
			tmp_max = max(to_left, to_right);
			tmp_min = min(to_left, to_right);

			res_max = max(tmp_max, res_max);
			res_min = max(res_min, tmp_min);
		}

		cout << res_min << " " << res_max << "\n";
		
	}
	return 0;
}