#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int vis[10];
int N;
vector<vector<int>> dungeons;

void dfs(int k, int count)
{
    answer = max(count, answer);
    
    // cout << k << " " << count << " \n";
    
    for(int i = 0; i < N; i++)
    {
        if(vis[i] == 1 || k < dungeons[i][0]) continue;
        
        vis[i] = 1;
        dfs(k - dungeons[i][1], count + 1);
        vis[i] = 0;
        
        // cout << i << " ";
    }
}


int solution(int k, vector<vector<int>> _dungeons) {
    
    N = _dungeons.size();
    dungeons = _dungeons;
    
    dfs(k, 0);
        
    return answer;
}