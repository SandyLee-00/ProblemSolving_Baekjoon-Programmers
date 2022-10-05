// 1182번 부분수열의 합
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int res = 0;
int v_size;
int N, S;
vector<int> v;

void bt(int pos, int sum){
	if(pos == N) return;
	
	if(sum == S && pos != -1){
		// cout << "pos : " << pos << "\n";
		res += 1;
	}
	for(int i = pos + 1; i < N; i++){
		sum += v[i];
		bt(i, sum);
		sum -= v[i];
	}
	return;
}


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;
	
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		v.push_back(a);
	}
	v_size = v.size();

	bt(-1, 0);

	cout << res;
	
	return 0;
}