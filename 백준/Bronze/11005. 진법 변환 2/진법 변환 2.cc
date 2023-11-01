// 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <climits>
using namespace std;

/*

*/

int main() 
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// 10억까지여서 long long 쓰기
	long long N;
	int B;
	cin >> N;
	cin >> B;

	// 벡터로 0-35까지 char 저장해놓기
	vector<char> nums;
	for(int i = 0; i <= 35; i++){
		if(i < 10){
			nums.push_back(char(i + '0'));
		}
		else{
			nums.push_back(char(i + 'A' - 10));
		}
	}

	long long value = N;
	string res = "";
	// N B로 계속 나누면서 몫 스트링으로 더하기
	while(1){
		if(value == 0){
			break;
		}
		// 나머지 스트링으로 더하기
		char mod = nums[value % B];
		res += mod;
		value /= B;
		
	}
	// 스트링 뒤집기
	reverse(res.begin(), res.end());
	cout << res;
	

	return 0;
}