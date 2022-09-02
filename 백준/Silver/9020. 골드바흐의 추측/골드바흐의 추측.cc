// 9020번 골드바흐의 추측
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

// 소수 에라 체로 벡터에 만들기 10,000

vector<int> primes;
int nums[10001];
void is_prime(){
	for(int i = 0; i < 10001; i++){
		nums[i] = i;
	}
	for(int i = 2; i * i < 10001; i++){
		for(int j = i + i; j < 10001; j += i){
			if(nums[j] == 0) continue;
			else{
				nums[j] = 0;
			}
		}
	}
	for(int i = 2; i < 10001; i++){
		if(nums[i] != 0) primes.push_back(nums[i]);
	}
}

void goldbahu(int n){
	int h_n = n / 2;
	int first, second;
	first = n / 2;
	second = n / 2;
	while(1){
		if(n == nums[first] + nums[second]){
			cout << nums[first] << " " << nums[second] << "\n";
			return;
		}
		first--;
		second++;
	}
	
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	is_prime();
	
	while(T--){
		int n; cin >> n;
		goldbahu(n);
	}
	
	return 0;
}