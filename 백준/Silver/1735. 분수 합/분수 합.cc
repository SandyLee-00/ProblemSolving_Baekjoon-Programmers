// 1735번 분수 합
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int gcd(int a, int b){
	if(a == 0) return b;
	else{
		return gcd(b % a, a);
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int A, B, C, D; cin >> A >> B >> C >> D;
	A *= D;
	C *= B;

	int res_u = A + C;
	int res_d = B * D;
	int r = gcd(res_u, res_d);
	// cout << res_u << res_d;
	// cout << r;
	cout << res_u / r << " " << res_d / r;
	
	
	return 0;
}