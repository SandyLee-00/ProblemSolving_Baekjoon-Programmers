// 14003번 가장 긴 증가하는 부분 수열 5
/*
증가수열 만들기
각 dp에 저장한 idx 저장하기
뒤에서부터 출력하기

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
	vector<int> dp(N);
	vector<int> nums;
	int maxV = 0;
	
	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		v.push_back(a);
	}

	nums.push_back(v[0]);
	int cnt = 0;

	for(int i = 0; i < N; i++){
		// 맨 뒤 원소보다 크면 뒤에 원소 추가하기
		if(v[i] > nums[cnt]){
			nums.push_back(v[i]);
			cnt += 1;
			dp[i] = cnt;
		}

		// 작거나 같으면 idx 찾아서 바꾸기
		else{
			int idx = lower_bound(nums.begin(), nums.end(), v[i]) - nums.begin();
			nums[idx] = v[i];
			dp[i] = idx;
			
		}
	}
	int max = cnt;
	vector<int> res;

	for(int i = N-1; i >= 0; i--){
		if(dp[i] == max){
			res.push_back(v[i]);
			max -= 1;
		}
	}

	cout << cnt + 1 << "\n";
	for(int i = res.size()-1; i >= 0; i--){
		cout << res[i] << " ";
	}

	return 0;
}