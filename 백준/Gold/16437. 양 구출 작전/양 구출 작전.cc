// 
/*
그래프 연결 상태 만들기
각 노드 데이터 넣기
S노드에서 위로 양 올리기

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <sstream>
using namespace std;
using ll = long long;

const int MAX = 123458;
int N;
int vals[MAX];
vector<int> grp[MAX];

ll dfs(int node){

	// 리프노드 양 위로 올리기
	if(grp[node].size() == 0 && vals[node] > 0){
		return vals[node];
	}
	// 리프노드 늑대 값 0
	else if(grp[node].size() == 0 && vals[node] <= 0){
		return 0;
	}

	ll sum = 0;
	// 리프 아닌 노드에서 child 값들 모으기
	for(int i = 0; i < grp[node].size(); i++){
		sum += dfs(grp[node][i]);
	}

	// 현재 노드 늑대면 올라온 양에서 값 빼기
	// 늑대가 더 많으면 0으로 처리하기
	if(vals[node] <= 0){
		sum += vals[node];
		if(sum < 0){
			return 0;
		}
		return sum;
	}

	// 현재 노드 양이면 현재 노드 값 더해서 위로 올리기
	sum += vals[node];

	// cout << node << " " << sum << " \n";
	return sum;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	
	for(int i = 2; i <= N; i++){
		char a;
		int b, c;
		cin >> a >> b >> c;
		if(a == 'W'){
			b = -b;
		}
		vals[i] = b;
		grp[c].push_back(i);
	}

	cout << dfs(1);
	
	return 0;
}