// 1654번 랜선 자르기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

vector<long long> line;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int K;
	long long N, res = 0;
	cin >> K >> N;
	for(auto i = 0; i < K; i++){
		long long l;
		cin >> l;
		line.push_back(l);
	}
	long long start = 1, end = *max_element(line.begin(), line.end());
	
	while(start <= end){
		long long mid = (start + end) / 2;
		int cnt = 0;

		for(auto i = 0; i < line.size(); i++){
			if(mid <= line[i]){
				int line_num = line[i] / mid;
				cnt += line_num;
			}
		}
		if(cnt >= N){
			start = mid + 1;
			res = mid;
		}
		else{
			end = mid - 1;
		}
	}
	cout << res;

	return 0;
}