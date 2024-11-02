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
1에서 안 연결 된 부분 있을 수 있다
-사이클로 N-1개의 엣지로 갈 수 있는 거리가 N으로 줄어드는지만 파악 
*/

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int N, M, W;
        cin >> N >> M >> W;

        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < M; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;

            edges.push_back({T, {S, E}});
            edges.push_back({T, {E, S}});

        }

        for (int i = 0; i < W; i++)
        {
            int S, E, T;
            cin >> S >> E >> T;

            edges.push_back({-T, {S, E}});
        }

        vector<int> dis;
        for (int i = 0; i <= N; i++)
        {
            dis.push_back({INT_MAX/ 3});
        }

        dis[1] = 0;

        for (int i = 1; i <= N - 1; i++)
        {
            for (int j = 0; j < edges.size(); j++)
            {
                int from = edges[j].second.first;
                int to = edges[j].second.second;
                int weight = edges[j].first;

                if (dis[to] > dis[from] + weight)
                {
                    dis[to] = dis[from] + weight;
                }
            }
        }
        int flag = 0;


        for (int j = 0; j < edges.size(); j++)
        {
            int from = edges[j].second.first;
            int to = edges[j].second.second;
            int weight = edges[j].first;

            if (dis[to] > dis[from] + weight)
            {
                dis[to] = dis[from] + weight;
                flag = 1;
            }
        }

        if(flag == 0)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

    return 0;
}