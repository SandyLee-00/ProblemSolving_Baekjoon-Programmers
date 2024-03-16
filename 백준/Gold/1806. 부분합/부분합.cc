// 1806번 부분합
/*
-투포인터?


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

	int N, S;
	cin >> N >> S;

	vector<int> v;

	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}
	
	ll sum = v[0];
	int start = 0, end = 0;
	int count = 1;
	int minCount = INT_MAX;

	while(1){
		if(end == N){
			break;
		}
		
		if(sum >= S){
			sum -= v[start];
			start += 1;
			minCount = min(minCount, count);
			count -= 1;

		}

		else if(sum < S){
			end += 1;
			sum += v[end];
			count += 1;
		}

		// cout << sum << " ";
	}

	if(minCount != INT_MAX){
		cout << minCount;
	}
	else{
		cout << 0;
	}

	return 0;
}