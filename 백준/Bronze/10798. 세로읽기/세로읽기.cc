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
#include <stack>
#include <climits>
#include <set>
#include <sstream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<string> v;
	int maxSize = 0;
	
	for(int i = 0; i < 5; i++){
		string str;
		cin >> str;
		maxSize = max(int(str.size()), maxSize);
		v.push_back(str);
	}

	for(int i = 0; i < 5; i++){
		while(v[i].size() < maxSize){
			v[i] += ' ';
		}
	}

	for(int j = 0; j < maxSize; j++){
		for(int i = 0; i < 5; i++){
			if(v[i][j] != ' '){
				cout << v[i][j];

			}
		}
	}
	
	return 0;
}