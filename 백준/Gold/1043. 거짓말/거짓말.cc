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
유니온 파인드로 그룹 만들기
하나라도 1있으면 전체 1
다시 돌리면서 확인
*/
const int MAXV = 55;

int knows[MAXV];
int parent[MAXV];

int find(int node)
{
    if (node == parent[node])
    {
        return node;
    }

    if(knows[parent[node]] == 1)
    {
        knows[node] = 1;
    }

    return parent[node] = find(parent[node]);
}

void merge(int node1, int node2)
{
    int p1 = find(node1);
    int p2 = find(node2);
    if (p1 == p2)
    {
        return;
    }

    parent[p1] = p2;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int answer = 0;

    for (int i = 0; i < MAXV; i++)
    {
        parent[i] = i;
    }

    int A;
    cin >> A;
    for (int i = 0; i < A; i++)
    {
        int b;
        cin >> b;
        knows[b] = 1;
    }

    vector<vector<int>> v(M);
    for (int i = 0; i < M; i++)
    {
        int c;
        cin >> c;
        for (int k = 0; k < c; k++)
        {
            int d;
            cin >> d;
            v[i].push_back(d);
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 1; j < v[i].size(); j++)
        {
            merge(v[i][j - 1], v[i][j]);
        }
    }

    for(int i = 0; i < MAXV; i++)
    {
        find(i);
    }

    for(int i = 0; i < MAXV; i++)
    {
        if(knows[i] == 1)
        {
            int parentNode = parent[i];

            for(int j = 0; j < MAXV; j++)
            {
                if(parent[j] == parentNode)
                {
                    knows[j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        int flag = 1;
        for (int j = 0; j < v[i].size(); j++)
        {
            if (knows[v[i][j]] == 1)
            {
                flag = 0;
                // cout << v[i][j] << " ";
            }
        }
        // cout << "\n";

        answer += flag;
    }

    cout << answer;

    return 0;
}