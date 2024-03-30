// 2467번 용액
/*
lowerbound로 하나 용액에서 다른 용액 일치 찾기
start ++하면서 lowerbound 찾기
값 용1 용2로 저장하기

- 안나누고 하나에서 처리하기
- 그냥 투포인터 문제였다 투포인터 + bs로 풀려고 했는데 아니었다
- 1퍼에서 틀렸다고 한다 왜일까 
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

	int start = 0, end = v.size()-1;
	int sum = v[start] + v[end];

	ll minSum = LONG_LONG_MAX;
	ii res = {v[start], v[end]};

	while(1){
		if(start == end){
			break;
		}
		
		sum = v[start] + v[end];
		// cout << v[start] << " " << v[end] << "\n";
		if(minSum > abs(sum)){
			minSum = abs(sum);
			res = {v[start], v[end]};
		}
		
		if(sum > 0){
			end -= 1;
		}
		else if(sum < 0){
			start += 1;
		}
		else{
			break;
		}
	}
	cout << res.first << " " << res.second;
	
	return 0;
}