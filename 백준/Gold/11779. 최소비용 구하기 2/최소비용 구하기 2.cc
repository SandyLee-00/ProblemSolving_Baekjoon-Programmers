#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
#include <map>
#include <queue>
#include <limits.h>
using namespace std;

/*
각 노드에서 연결 상태 만들어 놓기
출발 노드에서부터 cost로 pq넣어서 도착지까지 결과 넣기
pq에 벡터도 넣어서 목적지까지 업데이트 되면 그것도 바꿔주기
*/

const int MAXV = 1005;
vector<pair<int, int>> grp[MAXV];
int dis[MAXV];
int mid[MAXV];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        grp[a].push_back({b, c});
    }

    int start, end;
    cin >> start >> end;

    for (int i = 0; i < MAXV; i++)
    {
        dis[i] = INT_MAX / 3;
    }

    dis[start] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dis[node] < cost) continue;

        for (int i = 0; i < grp[node].size(); i++)
        {
            int nNode = grp[node][i].first;
            int edge = grp[node][i].second;

            if (dis[nNode] > dis[node] + edge)
            {
                dis[nNode] = dis[node] + edge;
                pq.push({- cost - edge, nNode});
                mid[nNode] = node; 
            }
        }
    }

    cout << dis[end] << "\n";

    stack<int> s;
    s.push(end);
    while(1)
    {
        int beforeNode = mid[s.top()];
        s.push(beforeNode);

        if(beforeNode == start) break;
    }

    cout << s.size() << "\n";

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }


    return 0;
}