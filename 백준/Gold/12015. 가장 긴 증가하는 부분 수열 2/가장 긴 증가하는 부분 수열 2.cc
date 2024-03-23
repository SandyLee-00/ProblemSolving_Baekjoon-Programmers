// 12015번 가장 긴 증가하는 부분 수열 2
/*
길이만 유지한 채로 더 붙힐 수 있는 가능성 높히기
마지막 원소보다 크면 뒤에 붙히기
아니면 있는 원소 중에서 큰 것중에서 가장 작은 것과 바꾸기
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

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> v;
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}

	vector<int> ls;
	ls.push_back(v[0]);
	for(int i = 1; i < N; i++){
		if(ls[ls.size()-1] < v[i]){
			ls.push_back(v[i]);
		}
		else{
			int idx = lower_bound(ls.begin(), ls.end(), v[i]) - ls.begin();
			ls[idx] = v[i];
		}
	}
	cout << ls.size();

	return 0;
}