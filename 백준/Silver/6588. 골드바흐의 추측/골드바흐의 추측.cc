// 6588번 골드바흐의 추측
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <deque>
using namespace std;

int nums[1000001];
vector<int>decimals;

void make_decimal_v(){
	
	for(int i = 2; i * i <= 1000000; i++){
		if(nums[i] == 1) continue;
		else{
			for(int j = i * 2; j <= 1000000; j = j + i){
				nums[j] = 1;
			}
		}
	}
	for(int i = 3; i <= 1000000; i++){
		if(nums[i] == 0){
			decimals.push_back(i);
		}
	}
}

// 여기서 이진탐색...?? n -> nlogn
int check_decimal(int num){
	int l = 0, r = decimals.size();
	int m = 0;
	while(l <= r){
		m = (l + r) / 2;
		//cout << decimals[m] << " ";
		if(decimals[m] == num) return 1;
		else if(num < decimals[m]) r = m - 1;
		else l = m + 1;
	}
	return 0;
}


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	make_decimal_v();
	int n; cin >> n;
	
	while(n){
		for(int fir = 0; fir < decimals.size() / 2 + 1; fir++){
			int sec = n - decimals[fir];
			if(check_decimal(sec)){
				cout << n << " = " << decimals[fir] << " + "<< sec << "\n";
				break;
			}
		}
		cin >> n;
	}
	
	return 0;
}