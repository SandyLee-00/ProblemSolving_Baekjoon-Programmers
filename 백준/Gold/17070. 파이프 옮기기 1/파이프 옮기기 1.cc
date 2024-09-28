#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

/*
BFS 가능한 것 돌리기
*/

int bd[20][20];
int N;
int answer = 0;

struct Bar
{
	int fi;
	int fj;
	int si;
	int sj;
	int type;
};

void bfs()
{
	Bar a;
	a.fi = 0;
	a.fj = 0;
	a.si = 0;
	a.sj = 1;
	a.type = 0;
	
	queue<Bar> q;
	
	q.push({a});

	while (!q.empty())
	{
		Bar bar = q.front();
		q.pop();

		if (bar.si == N - 1 && bar.sj == N - 1)
		{
			answer += 1;
		}

		if (bar.type == 0)
		{
			Bar temp1 = bar;
			if (bar.sj + 1 < N && bd[bar.si][bar.sj+1] == 0)
			{
				temp1.fj += 1;
				temp1.sj += 1;
				temp1.type = 0;
				q.push({ temp1 });
			}
			Bar temp2 = bar;
			if (bar.sj + 1 < N && bar.si + 1 < N && 
				bd[bar.si][bar.sj + 1] == 0 &&
				bd[bar.si + 1][bar.sj] == 0 &&
				bd[bar.si + 1][bar.sj + 1] == 0)
			{
				temp2.fj += 1;
				temp2.si += 1;
				temp2.sj += 1;
				temp2.type = 2;
				q.push({ temp2 });
			}
		}
		else if (bar.type == 1)
		{
			Bar temp3 = bar;
			if (bar.si + 1 < N && bd[bar.si + 1][bar.sj] == 0)
			{
				temp3.fi += 1;
				temp3.si += 1;
				temp3.type = 1;
				q.push({ temp3 });
			}
			Bar temp4 = bar;
			if (bar.sj + 1 < N && bar.si + 1 < N &&
				bd[bar.si][bar.sj + 1] == 0 &&
				bd[bar.si + 1][bar.sj] == 0 &&
				bd[bar.si + 1][bar.sj + 1] == 0)
			{
				temp4.fi += 1;
				temp4.si += 1;
				temp4.sj += 1;
				temp4.type = 2;
				q.push({ temp4 });
			}
		}
		else if (bar.type == 2)
		{
			Bar temp5 = bar;
			if (bar.sj + 1 < N && bd[bar.si][bar.sj + 1] == 0)
			{
				temp5.fi += 1;
				temp5.fj += 1;
				temp5.sj += 1;
				temp5.type = 0;
				q.push({ temp5 });
			}
			Bar temp6 = bar;
			if (bar.si + 1 < N && bd[bar.si + 1][bar.sj] == 0)
			{
				temp6.fi += 1;
				temp6.fj += 1;
				temp6.si += 1;
				temp6.type = 1;
				q.push({ temp6 });
			}
			Bar temp7 = bar;
			if (bar.sj + 1 < N && bar.si + 1 < N &&
				bd[bar.si][bar.sj + 1] == 0 &&
				bd[bar.si + 1][bar.sj] == 0 &&
				bd[bar.si + 1][bar.sj + 1] == 0)
			{
				temp7.fi += 1;
				temp7.fj += 1;
				temp7.si += 1;
				temp7.sj += 1;
				temp7.type = 2;
				q.push({ temp7 });
			}
		}
	}
}


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			bd[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> bd[i][j];
		}
	}

	bfs();

	cout << answer;

	return 0;
}