#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
using namespace std;

/*
bfs 크기 작거나 같은 가장 가까운 물고기 찾기
결과 +=
같은 사이즈 몇개 먹었는지 저장하기
2-> 6 배열에 각 개수대로 저장 -= 1 해서 0이면 레벨업

*/

int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

int main()
{
	ios_base ::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> m(n, vector<int>(n, 0));

	pair<int, int> sharkPosition;
	int sharkSize = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			m[i][j] = a;

			if (a == 9)
			{
				sharkPosition = {i, j};
				m[i][j] = 0;
			}
		}
	}

	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << m[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	int answer = 0;
	vector<int> sharkExps;
	for (int i = 0; i <= 1000; i++)
	{
		sharkExps.push_back(i);
	}

	while (1)
	{
		// 상어 물고기 찾기 bfs
		queue<pair<pair<int, int>, int>> q;
		q.push({sharkPosition, 0});

		vector<vector<int>> vis(n, vector<int>(n, 0));
		vis[sharkPosition.first][sharkPosition.second] = 1;
		bool flag = false;

		priority_queue<pair<pair<int, int>, int>> pq;
		while (!q.empty())
		{
			pair<int, int> pos = q.front().first;
			int cost = q.front().second;
			q.pop();

			if (!pq.empty() && cost + 1 > pq.top().second)
			{
				continue;
			}

			for (int d = 0; d < 4; d++)
			{
				int pi = pos.first + dy[d];
				int pj = pos.second + dx[d];

				if (pi < 0 || pj < 0 || pi >= n || pj >= n)
					continue;

				if (vis[pi][pj] == 1)
					continue;

				// 못 먹는 물고기
				if (m[pi][pj] > sharkSize)
					continue;

				// 먹을 수 있는 가장 가까운 물고기 발견
				if (m[pi][pj] < sharkSize && m[pi][pj] != 0)
				{
					flag = true;
					pq.push({{-pi, -pj}, cost + 1});
				}

				vis[pi][pj] = 1;
				q.push({{pi, pj}, cost + 1});
			}
		}

		if (!pq.empty())
		{
			int pqCost = pq.top().second;
			int pqi = -pq.top().first.first;
			int pqj = -pq.top().first.second;

			// cout << m[pqi][pqj] << " " << pqi << " " << pqj << " " << pqCost << " \n";

			answer += pqCost;
			sharkPosition = {pqi, pqj};

			sharkExps[sharkSize] -= 1;
			if (sharkExps[sharkSize] == 0)
			{
				sharkSize += 1;
			}
			m[pqi][pqj] = 0;
		}

		if (flag == false)
		{
			break;
		}
	}

	cout << answer;

	return 0;
}