// 1021번 회전하는 큐
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
덱에 개수만큼 숫자 넣기
*/

int getCnt2(int num, deque<int> dq){
	int cnt = 0;
	while(1){
			if(num == dq.front())
				break;
			cnt++;
			int tmp = dq.front();
			dq.pop_front();
			dq.push_back(tmp);
		}
	return cnt;
}
int getCnt3(int num, deque<int> dq){
	int cnt = 0;
	while(1){
			if(num == dq.front())
				break;
			cnt++;
			int tmp = dq.back();
			dq.pop_back();
			dq.push_front(tmp);
		}
	return cnt;
}


int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	int M; cin >> M;
	int resCnt = 0;
	deque<int> dq;
	for(int i = 1; i <= N; i++){
		dq.push_back(i);
	}
	for(int i = 0; i < M; i++){
		int num; cin >> num;
		int sec = getCnt2(num, dq);
		int thir = getCnt3(num, dq);
		int cnt = 0;
		if(sec < thir){
			while(1){
			if(num == dq.front())
				break;
			cnt++;
			int tmp = dq.front();
			dq.pop_front();
			dq.push_back(tmp);
			}
			resCnt += cnt;
		}
		else{
			while(1){
			if(num == dq.front())
				break;
			cnt++;
			int tmp = dq.back();
			dq.pop_back();
			dq.push_front(tmp);
			}
			resCnt += cnt;
		}
		dq.pop_front();
	}
	cout << resCnt;
	
	return 0;
}