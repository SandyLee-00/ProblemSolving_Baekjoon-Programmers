// 2805번 나무 자르기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

vector<long long> tree;

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	long long M, t;
	int res = 0;

	cin >> N >> M;

	for(int i = 0; i < N; i++){
		cin >> t;
		tree.push_back(t);
	}
	
	long long start = 0, end = *max_element(tree.begin(), tree.end()), mid = 0;

	while(start <= end){
		mid = (start + end) / 2;

		long long total = 0;
		for(int i = 0; i < tree.size(); i++){
			if(mid < tree[i]){
				total += tree[i] - mid;
			}
		}
		if(total >= M){
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