// 5464번 주차장
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int N, M; 
vector<int> costs;
vector<int> cars;

vector<int> isin;
queue<int> waiting;

int res = 0;

void goin(int state){
	for(int i = 1; i <= N; i++){
		if(isin[i] == 0){
			isin[i] = state;
			return;
		}
	}
	waiting.push(state);
}

void goout(int state){
	for(int i = 1; i <= N; i++){
		if(isin[i] == -state){
			isin[i] = 0;
			res += cars[-state] * costs[i];
		}
	}
	// 큐 있으면 가장 앞 넣기
	if(!waiting.empty()){
		int newincar = waiting.front();
		waiting.pop();

		goin(newincar);
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	// N N개의 주차 공간
	// M M대의 차량
	
	costs.push_back(0);
	cars.push_back(0);
	isin.push_back(0);
	
	for(int i = 0; i < N; i++){
		int a; cin >> a;
		costs.push_back(a);
	}

	for(int i = 0; i < M; i++){
		int a; cin >> a;
		cars.push_back(a);
		isin.push_back(0);
	}
	int inout = M * 2;
	
	while(inout--){
		int state; cin >> state;
		if(state > 0){
			goin(state);
		}
		else if(state < 0){
			goout(state);
		}
	}
	cout << res;
	
	return 0;
}