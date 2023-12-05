// 3190번 뱀
/*
맵에 사과 놓기
while에서 초 카운트 하기

머리 방향에 따라 위치
사과 / 벽 / 몸
사과: 맵에서 체크해서 없애기, isApple = true
벽: 맵에서 체크해서 게임오버 하기
몸: 몸 모든 큐 빼서 돌면서 겹치는지 체크 게임오버하기

몸큐 돌면서 위치 옮겨주기
isApple이면 size 1일 때 마지막에 추가하기

방향전환
di 0 dj 1
L -1 +1 D -1 -1

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <sstream>
using namespace std;
using ll = long long;

int N;
bool map[105][105];
int diri[] = { 0, 1, 0, -1 };
int dirj[] = { 1, 0, -1, 0 };

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int appleNum;
	cin >> appleNum;

	for (int k = 0; k < appleNum; k++) {
		int i, j;
		cin >> i >> j;
		map[i - 1][j - 1] = true;
	}

	int L;
	cin >> L;
	queue<pair<int, int>> commandq;
	for (int i = 0; i < L; i++) {
		int a;
		cin >> a;
		char command;
		cin >> command;
		commandq.push({ a, command });
	}

	int res = 0;
	pair<int, int> nextDir = { 0, 1 };
	pair<int, int> nextPos = { 0, 0 };
	queue<pair<int, int>> body;
	body.push({ 0, 0 });
	int dirV = 0;

	while (1) {
		// 초 더하기
		res++;

		// 앞칸 가기
		nextPos.first += nextDir.first;
		nextPos.second += nextDir.second;

		// 사과 / 벽 / 몸

		// 벽 체크
		if (nextPos.first < 0 || nextPos.first >= N ||
			nextPos.second < 0 || nextPos.second >= N) {
			body;
			// cout << "WALL : ";
			// cout << nextPos.first << " " << nextPos.second << " \n";
			cout << res;
			return 0;
		}

		// 몸 체크
		queue<pair<int, int>> tq;
		while (!body.empty()) {
			int bi = body.front().first;
			int bj = body.front().second;
			tq.push({ bi, bj });
			body.pop();

			if (bi == nextPos.first && bj == nextPos.second) {
				// cout << "BODY : ";
				// cout << nextPos.first << " " << nextPos.second << " \n";

				cout << res;

				return 0;
			}
		}
		while (!tq.empty()) {
			body.push(tq.front());
			tq.pop();
		}

		// 머리 추가
		body.push({ nextPos.first, nextPos.second });

		// 다 구현했는데 뒤에 원소 빼야해서 덱 써야하는지 고민이 들어버렸다!
		// 큐 맨 뒤에꺼 빼려고 다 돌리고 있다
		int ti, tj;
		// 꼬리 빼기
		ti = body.front().first;
		tj = body.front().second;
		body.pop();

		while (!body.empty()) {
			tq.push(body.front());
			body.pop();
		}

		// 사과 체크
		if (map[nextPos.first][nextPos.second] == true) {
			// 꼬리 추가
			body.push({ ti, tj });
			map[nextPos.first][nextPos.second] = false;
		}
		
		while (!tq.empty()) {
			body.push(tq.front());
			tq.pop();
		}

		

		// 방향전환이면 앞칸 바꾸기
		while (!commandq.empty()) {
			if (commandq.front().first != res) {
				break;
			}
			if (commandq.front().second == 'D') {
				dirV += 1;
			}
			else if (commandq.front().second == 'L') {
				dirV += 3;
			}
			commandq.pop();
		}
		// 다음 방향 넣기
		dirV = dirV % 4;
		nextDir.first = diri[dirV];
		nextDir.second = dirj[dirV];

	}
	cout << res;

	return 0;
}
