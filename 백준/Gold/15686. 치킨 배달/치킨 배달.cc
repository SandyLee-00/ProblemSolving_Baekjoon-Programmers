// 15686번 치킨 배달
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
M개 고르기 순서 x, 중복 x
고르면 최단거리 계산 함수 호출

각 집에서 고른 치킨 거리 중 짧은 것 찾아서 합하기
최단거리 갱신
*/

const int MAX = 999999999;
int bd[55][55];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int res = 999999999;
int N, M;
int selectedChicken[20];

void getMinDis(){
	int sum = 0;
	for(int i = 0; i < house.size(); i++){
		int dis = 999999999;
		for(int j = 0; j < 20; j++){
			if(selectedChicken[j] == 1){
				int pi = house[i].first - chicken[j].first;
				int pj = house[i].second - chicken[j].second;
				if(pi < 0)
					pi = -pi;
				if(pj < 0)
					pj = -pj;
				dis = min(dis, pi+pj);
			}
		}
		sum += dis;
	}
	res = min(sum, res);
}

void selectM(int idx, int cnt){
	//cout << cnt << " ";
	if(cnt == M){
		getMinDis();
		return;
	}
	for(int i = idx + 1; i < chicken.size(); i++){
		cnt++;
		selectedChicken[i] = 1;
		selectM(i, cnt);
		cnt--;
		selectedChicken[i] = 0;
	}
}

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int a; cin >> a;
			bd[i][j] = a;
			if(a == 1)
				house.push_back({i,j});
			if(a == 2)
				chicken.push_back({i,j});
		}
	}
	selectM(-1, 0);

	cout << res;
	
	return 0;
}