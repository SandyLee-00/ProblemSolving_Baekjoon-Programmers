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
pq에 노드 하나씩 넣고 남은 거리 관리하기
각 노드 방문처리, 노드 아이템 보관 X

한 노드에서 다른 곳까지 전부 체크 필요
max 값 구하기
전체 그래프에서 최단거리 다 구하기
각 노드마다 아이템 얻기
*/

const int MAXV = 105;

int bd[MAXV][MAXV];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> items;
    items.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        items.push_back(a);
    }

    for(int i = 0; i < MAXV; i++)
    {
        for(int j = 0; j < MAXV; j++)
        {
            bd[i][j] = INT_MAX / 2 - 1;
        }
    }

    for (int i = 0; i < r; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        bd[a][b] = c;
        bd[b][a] = c;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int k = 1; k <= n; k++)
            {
                if(bd[i][j] > bd[i][k] + bd[k][j] || bd[j][i] > bd[i][k] + bd[k][j])
                {
                    bd[i][j] = bd[i][k] + bd[k][j];
                    bd[j][i] = bd[i][k] + bd[k][j];
                } 
            }
        }
    }

    int answer = 0;

    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                sum += items[i];
            }

            if(bd[i][j] <= m && i != j)
            {
                sum += items[j];
            }
        }

        answer = max(sum, answer);
    }

    cout << answer;

    // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
    // for(int i = 0; i < r; i++)
    // {
    //     int a, b, c;
    //     cin >> a >> b >> c;

    //     pq.push({c, {a, b}});
    // }

    // while(!pq.empty())
    // {
    //     int a, b, c;

    //     c = pq.front().first;
    //     a = pq.front().second.first;
    //     b = pq.front().second.second;
    // }

    return 0;
}