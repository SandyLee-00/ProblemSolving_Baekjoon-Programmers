// 1138번 한 줄로 서기
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <deque>
using namespace std;

void prt_res(vector<int> res){
	for(int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}
	cout << "\n";
	cout << "\n";
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<int> v;
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		v.push_back(a);
	}
	vector<int>res(N);
	const int MAX = N + 1;
	for(int i = 0; i < N; i++){
		res[i] = MAX;
	}
	for(int vi = 0; vi < N; vi++){
		
		int x_cnt = v[vi];
		// cout << "vi x_cnt : " << x_cnt << "\n";
		// prt_res(res);
		
		for(int respos = 0; respos < N; respos++){
			// cout << "x_cnt : " << x_cnt << "\n";
			if(x_cnt == 0 && res[respos] == MAX){
				res[respos] = vi + 1;
				break;
			}
			if(res[respos] == MAX){
				x_cnt -= 1;
			}
			
		}
		
	}

	for(int i = 0; i < N; i++){
		cout << res[i] << " ";
	}
	
	return 0;
}