// 5430번 AC
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <deque>
using namespace std;

// R 배열 뒤집
// D 첫번째 수 버림

// string 입력 -> 덱에 하나씩 저장


deque<int> str_to_dq(string arr_nums, deque<int> dq){
	int strSize = arr_nums.size();
	string oneNum = "";
	for(int i = 0; i < strSize; i++){
		if(arr_nums[i] - '0' >= 0 && arr_nums[i] - '0' <= 9){
			oneNum += arr_nums[i];
		}
		else{
			if(oneNum != "")dq.push_back(stoi(oneNum));
			oneNum = "";
		}
	}
	
	return dq;
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T; cin >> T;
	while(T--){
		string p; cin >> p;
		int n; cin >> n;
		string str_nums; cin >> str_nums;
		deque<int> dq;
		dq = str_to_dq(str_nums, dq);

		// for(int i = 0; i < dq.size(); i++){
		// 	cout << dq.front() << " ";
		// 	dq.push_back(dq.front());
		// 	dq.pop_front();
		// }
		int lr = 0; // l:0 r:1
		int error = 0;

		for(int i = 0; i < p.size(); i++){
			if(p[i] == 'R'){
				lr = (lr + 1) % 2;
			}
			else if(p[i] == 'D'){
				if(dq.empty()){
					error = 1;
					break;
				}
				else{
					if(lr == 0) dq.pop_front();
					else if(lr == 1) dq.pop_back();
				}
				
			}
		}
		if(error) cout << "error";
		else{
			cout << "[";
			if (lr == 0){
				while(!dq.empty()){
					cout << dq.front();
					dq.pop_front();
					if(!dq.empty()) cout << ",";
					}
				}
			
			else{
				while(!dq.empty()){
					cout << dq.back();
					dq.pop_back();
					if(!dq.empty()) cout << ",";
					}
				}

			cout << "]";
		}

		cout << "\n";
	}
	
	return 0;
}