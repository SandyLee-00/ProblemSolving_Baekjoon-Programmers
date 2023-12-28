// 2110번 공유기 설치
/* 
간격을 최대로 할 수 있는 범위 이분탐색으로 정하기
정한 간격 이상으로 해당 공유기 전부 놓을 수 있는지 찾기
통과되면 간격 넓히기 안되면 간격 줄이기 

해당 거리로 놓는 것이 유효한지 체크 못했다
1번째 집 꼭 놓는다

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
using ii = pair<int, int>;

vector<int> xs;
int N, C;


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> C;

	for(int i = 0; i < N; i++){
		int a;
		cin >> a;
		xs.push_back(a);
	}

	sort(xs.begin(), xs.end());
	
	// 간격을 최대로 할 수 있는 범위 이분탐색으로 정하기
	int minDis = 1;
	int maxDis = *(xs.end()-1) - *xs.begin();
	int mid;
	int res = 0;

	

	while(1){
		mid = (maxDis + minDis) / 2;
		// cout << mid << "\n";

		if(minDis > maxDis){
			break;
		}
		
		// 집 돌면서 거리 멀면 배치 가능
		int curPos = *xs.begin();
		int cnt = 1;
		
		for(int i = 1; i < xs.size(); i++){
			if(xs[i] - curPos >= mid){
				cnt += 1;
				curPos = xs[i];
			}
		}

		// 배치한 개수 더 크다 -> 최소 간격값 
		if(cnt >= C){
			// cout << mid << " " << cnt << "\n";

			minDis = mid + 1;
			res = max(res, mid);			
		}
		// 거리 반으로 줄여서 다시 체크하기
		else{
			maxDis = mid - 1;
		}
	}

	cout << res;
	
	
	return 0;
}