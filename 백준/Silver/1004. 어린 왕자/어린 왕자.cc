// 1004번 어린 왕자
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <deque>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while(T--){
		int x1, y1; cin >> x1 >> y1;
		int x2, y2; cin >> x2 >> y2;

		int n; cin >> n;
		vector<int> vx;
		vector<int> vy;
		vector<int> vr;
		for(int i = 0; i < n; i++){
			int x, y, r; cin >> x >> y >> r;
			vx.push_back(x);
			vy.push_back(y);
			vr.push_back(r);
		}
		
		int cnt = 0;

		for(int i = 0; i < vx.size(); i++){
			int dx1 = vx[i] - x1;
			int dy1 = vy[i] - y1;
			int dr1_dr1 = dx1 * dx1 + dy1 * dy1;

			int dx2 = vx[i] - x2;
			int dy2 = vy[i] - y2;
			int dr2_dr2 = dx2 * dx2 + dy2 * dy2;

			if((dr1_dr1 < vr[i] * vr[i] && dr2_dr2 > vr[i] * vr[i]) || dr1_dr1 > vr[i] * vr[i] && dr2_dr2 < vr[i] * vr[i]){
				cnt += 1;
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}