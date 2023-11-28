// 1753번 최단경로
/*
시작 노드와 연결된 노드 거리 비교해서 업데이트
시작 노드 방문 체크

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int k;
	cin >> k;

	vector<int> v;
	for(int i = 0; i < N; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), greater<int>());

	cout << v[k-1];
	
	return 0;
}