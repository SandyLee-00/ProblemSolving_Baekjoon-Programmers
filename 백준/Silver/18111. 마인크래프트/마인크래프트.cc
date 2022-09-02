// 18111번 마인크래프트
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;

// 채우기 범위 어디까지 판 - 블록 가방? 시간?
// 비우기 범위 어디까지 블록 가방? 시간?
int blocks[256 + 1];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	int bag_or;

	cin >> N >> M >> bag_or;

	int land[M][N];
	int timeCnt = 0;
	int Mintime = 99999999;
	int Maxheight = 0;
	
	// 각 층의 블록 개수
	
	int level;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> level;

			for(int k = 1; k <= level; k++){
				blocks[k] += 1;
			}
		}
	}
	for(int i = 0; i <= 256; i++){
		// cout << blocks[i] << '\n';
	}
	for(int target = 0; target <= 256; target++){
		timeCnt = 0;
		int bag = bag_or;
		// 채우기
		for(int i = 1; i <= target; i++){
			bag -= (N * M) - blocks[i];
			timeCnt += (N * M) - blocks[i];
		}
		// 빼기
		for(int j = 256; j >= target + 1; j--){
			bag += blocks[j];
			timeCnt += (2 * blocks[j]);
		}
		if(bag < 0) break;
		if(Mintime >= timeCnt){
			Mintime = timeCnt;
			Maxheight = target;
		} 
	}
	
	cout << Mintime << ' ' << Maxheight;

	
	return 0;
}