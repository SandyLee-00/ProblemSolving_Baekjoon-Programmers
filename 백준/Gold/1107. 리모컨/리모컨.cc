// 리모컨
/*
누르는 것이 가능한 10개 배열 만들기
0 500000 체크 하면서 숫자 가능하면 GetCount하기
체크해서 min 값 구하기

가능한 조합 아니면 안 구하기

100에서 시작하는 경우 처리 추가
숫자 입력 안하고 +-만 하는 경우 추가

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
using namespace std;

int N;

int GetCount(string numstr){
	int ret = 0;
	ret += numstr.size();
	ret += abs(N - stoi(numstr));

	// cout << ret << " ";

	int retsec = 0;
	retsec += abs(N - 100);

	// cout << retsec << "\n";

	ret = min(ret, retsec);
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int M;
	cin >> M;

	vector<bool>nums(10, true);
	
	for(int i = 0; i < M; i++){
		int temp;
		cin >> temp;
		nums[temp] = false;
	}

	int res = INT_MAX;
	for(int i = 0; i < 990005; i++){
		string tempstr = to_string(i);
		bool check = true;
		
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < tempstr.size(); k++){
				if(nums[j] == false && tempstr[k] == j + '0'){
					check = false;
					continue;
				}
			}
		}
		if(check == true){
			// cout << i << " ";

			res = min(res, GetCount(tempstr));
		}
	}

	int retsec = 0;
	retsec += abs(N - 100);

	// cout << retsec << "\n";

	res = min(res, retsec);

	cout << res;
	
	return 0;
}