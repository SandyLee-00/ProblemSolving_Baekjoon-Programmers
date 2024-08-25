/*
연결된 엣지를 n1 n2로 갖고있기
전부 끊어보기 
dfs로 연결된 망 카운트

*/

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> wires;
int N;
int maxRes = 0;
int grp[105][105];
int vis[105];
int answer = INT_MAX;

void dfs(int index)
{
    maxRes += 1;
    
    
    for(int i = 1; i <= N; i++)
    {
        if(vis[i] == 1 || grp[index][i] == -1) continue;
        
        vis[i] = 1;
        cout << i << " - ";
        
        dfs(i);
    }
}

void getCount()
{
    maxRes = 0;
    
    for(int i = 0; i < 105; i++)
    {
        vis[i] = -1;
    }
    
    vis[1] = 1;
    dfs(1);
    
    int a = N - maxRes;
    cout << " "<< a << " \n";
    
    int res = maxRes - a;
    if(res < 0) res = -res;
    
    answer = min(answer, res);
}

int solution(int n, vector<vector<int>> _wires) {
    
    wires = _wires;
    N = n;
    
    for(int i = 0; i < 105; i++)
    {
        for(int j = 0; j < 105; j++)
        {
            grp[i][j] = -1;
        }
    }
    
    for(int i = 0; i < _wires.size(); i++)
    {
        int fir = _wires[i][0];
        int sec = _wires[i][1];
        
        grp[fir][sec] = 1;
        grp[sec][fir] = 1;
        
    }
    
    
    for(int i = 0; i < _wires.size(); i++)
    {
        
        int fir = _wires[i][0];
        int sec = _wires[i][1];
        
        cout << fir << sec << " ";
        
        grp[fir][sec] = -1;
        grp[sec][fir] = -1;
        
        getCount();
        
        grp[fir][sec] = 1;
        grp[sec][fir] = 1;
        
    }
    
    
    return answer;
}