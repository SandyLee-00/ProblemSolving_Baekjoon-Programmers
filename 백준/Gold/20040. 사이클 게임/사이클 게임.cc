// 20040번 사이클 게임
/*
unionfind
false인 것 리턴하기
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int parents[500005];

int find(int a){
	if(a == parents[a]){
		return a;
	}
	else{
		return parents[a] = find(parents[a]);
	}
}

bool unionF(int a, int b){
	int pa = find(a);
	int pb = find(b);
	if(pa != pb){
		parents[pa] = pb;
		return true;
	}
	else{
		return false;
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int count = 0;
	int res = 0;

	for(int i = 0; i < 500005; i++){
		parents[i] = i;
	}
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		count += 1;

		if(unionF(a, b) == false && res == 0){
			// cout << a << " " << b << " ";
			res = count; 
		}
	}

	cout << res;
	
	return 0;
}