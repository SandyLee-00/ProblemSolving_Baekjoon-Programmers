#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

/*
bfs로 바깥 공기 5로 만들기
안에는 0
1중에서 2개 이상 5 닿으면 2로 바꾸기
2 지우기 

*/

int N, M;
const int MAXV = 101;
int bd[MAXV][MAXV];
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};
int answer = 0;

void bfs(int pi, int pj)
{
    queue<pair<int, int>> q;
    q.push({pi, pj});
    bd[pi][pj] = 5;

    int vis[MAXV][MAXV];
    vis[pi][pj] = 1;
    for(int i = 0; i < MAXV; i++)
    {
        for(int j = 0; j < MAXV; j++)
        {
            vis[i][j] = 0;
        }
    }

    while (!q.empty())
    {
        int posi = q.front().first;
        int posj = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ni = posi + di[i];
            int nj = posj + dj[i];

            if (ni < 0 || nj < 0 || ni >= N || nj >= M)
            {
                continue;
            }

            if(vis[ni][nj] == 1)
            {
                continue;
            }

            if (bd[ni][nj] == 0 || bd[ni][nj] == 5)
            {
                bd[ni][nj] = 5;
                vis[ni][nj] = 1;
                q.push({ni, nj});
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> bd[i][j];
        }
    }

    while (1)
    {
        bfs(0, 0);

        int flag = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (bd[i][j] == 1)
                {
                    flag = 1;
                    int sum = 0;
                    for (int d = 0; d < 4; d++)
                    {
                        if (bd[i + di[d]][j + dj[d]] == 5)
                        {
                            sum += 1;
                        }
                    }
                    if (sum >= 2)
                    {
                        bd[i][j] = 2;
                    }
                }
            }
        }

        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //     {
        //         cout << bd[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        if (flag == 0)
        {
            break;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (bd[i][j] == 2)
                {
                    bd[i][j] = 5;
                }
            }
        }

        answer += 1;
    }

    cout << answer;

    return 0;
}