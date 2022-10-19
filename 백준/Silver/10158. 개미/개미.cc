// 10158번 개미
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int w, h, p, q; cin >> w >> h >> p >> q;
	int t; cin >> t;

	int tx = t % (w * 2);
	int ty = t % (h * 2);
	
	int dirx = 1;
	int diry = 1;
	
	while(tx--){
		if(p == w || p == 0){
			dirx *= -1;
		}
		p += dirx;
	}
	
	while(ty--){
		if(q == h || q == 0){
			diry *= -1;
		}
		q += diry;
	}
	
	cout << p << " " << q;
	
	return 0;
}