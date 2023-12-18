// 20920번 영단어 암기는 괴로워
/*
map에 key value로 key 들어올 때마다 값 ++ 하기
비교 따로 X -> cmp에서 비교한 값 리턴하기


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
#include <sstream>
using namespace std;
using ll = long long;
using si = pair<string, int>;

bool cmp(si a, si b){

	bool secondBig = a.second > b.second;
	bool firstSize = a.first.size() > b.first.size();
	bool firstBig = a.first < b.first;

	if(a.second > b.second || a.second < b.second){
		return a.second > b.second;
	}

	else if(a.first.size() > b.first.size() || a.first.size() < b.first.size()){
		return a.first.size() > b.first.size();
	}

	else if(a.first < b.first || a.first >= b.first){
		return a.first < b.first;
	}

	return false;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	int M;
	cin >> M;

	map<string, int> m;

	for(int i = 0; i < N; i++){
		string str;
		cin >> str;
		
		if(str.size() >= M){
			m[str] += 1;
		}
	}

	vector<si> v(m.begin(), m.end());

	// cout << "\n";
	for(int i = 0; i < v.size(); i++){
		// cout << v[i].first << "\n";
	}
	
	sort(v.begin(), v.end(), cmp);

	// cout << "\n";

	for(int i = 0; i < v.size(); i++){
		cout << v[i].first << "\n";
	}
	
	return 0;
}