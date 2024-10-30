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
한 점 잡고 거기서 dfs로 가장 긴 노드 찾기 
그 노드에서 다시 dfs로 가장 긴 노드 거리 찾기 

*/

const int MAXV = 100005;
vector<pair<int, int>> v[MAXV];
int vis[MAXV];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int V;
    cin >> V;

    for(int i = 0; i < V; i++)
    {
        int a;
        cin >> a;
        
        while(1)
        {
            int b;
            cin >> b;
            if(b == -1) break;
            int c;
            cin >> c;

            v[a].push_back({-c, b});
        }
    }

    int maxNode = 0;
    int maxLength = 0;

    stack<pair<int, int>> s;
    s.push({1, 0});
    vis[1] = 1;

    while(!s.empty())
    {
        int snode = s.top().first;
        int length = s.top().second;
        s.pop();

        for(int i = 0; i < v[snode].size(); i++)
        {
            int nnode = v[snode][i].second;
            int nlength = - v[snode][i].first;

            if(vis[nnode] == 1) continue;

            if(length + nlength > maxLength)
            {
                //cout << maxLength << " " << nnode << "\n";
                maxNode = nnode;
                maxLength = length + nlength;
            }
            vis[nnode] = 1;
            s.push({nnode, nlength + length});
        }
    }

    for(int i = 0; i < MAXV; i++)
    {
        vis[i] = 0;
    }

    // cout << maxNode << " ";

    stack<pair<int, int>> s2;
    s2.push({maxNode, 0});
    vis[maxNode] = 1;
    
    maxNode = 0;
    maxLength = 0;

    while(!s2.empty())
    {
        int snode = s2.top().first;
        int length = s2.top().second;
        s2.pop();

        for(int i = 0; i < v[snode].size(); i++)
        {
            int nnode = v[snode][i].second;
            int nlength = - v[snode][i].first;

            if(vis[nnode] == 1) continue;

            if(length + nlength > maxLength)
            {
                // cout << maxLength << " " << nnode << "\n";
                maxNode = nnode;
                maxLength = length + nlength;
            }
            vis[nnode] = 1;
            s2.push({nnode, nlength + length});
        }
    }
	
    cout << maxLength;
	
	return 0;
}