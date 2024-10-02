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
bfs x+1 / x-1 / x*2 돌리기
방문처리
최소값보다 크면 더이상 안 넣기
*/

const int MAXV = 200005;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int answer1 = INT_MAX, answer2 = 0;

    queue<pair<int, int>> q;
    q.push({N, 0});

    int vis[MAXV];
    for (int i = 0; i < MAXV; i++)
    {
        vis[i] = INT_MAX;
    }

    vis[N] = INT_MAX;

    int flag = 0;
    while (!q.empty())
    {
        int pos = q.front().first;
        int count = q.front().second;

        // cout << pos << " " << count << "\n";
        vis[pos] = 1;

        q.pop();

        if (pos == K && flag == 1 && count == answer1)
        {
            answer2 += 1;
        }
        if (pos == K && flag == 0)
        {
            // cout << "pos" << pos << "\n";
            flag = 1;
            answer1 = count;
            answer2 += 1;
        }

        if (pos + 1 < MAXV && vis[pos + 1] == INT_MAX && flag == 0)
        {
            q.push({pos + 1, count + 1});
        }
        if (pos - 1 >= 0 && vis[pos - 1] == INT_MAX && flag == 0)
        {
            q.push({pos - 1, count + 1});
        }
        if (pos * 2 < MAXV && vis[pos * 2] == INT_MAX && flag == 0)
        {
            q.push({pos * 2, count + 1});
        }
    }

    cout << answer1 << "\n"
         << answer2;

    return 0;
}