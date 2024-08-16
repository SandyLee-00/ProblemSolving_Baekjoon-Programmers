/*
시작지점부터 각 지점까지 거리 구하기

각 지점에서 a목적지, 각 지점에서 b목적지 구하기

전체 테이블 만들기

*/
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int cost[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cost[i][j] = 99999999;
        }
    }
    
    
    for(int i = 0; i < fares.size(); i++)
    {
        cost[fares[i][0]][fares[i][1]] = fares[i][2];
        cost[fares[i][1]][fares[i][0]] = fares[i][2];
        
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // cout << cost[i][j] << " ";
        }
    }
    
    
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(cost[i][k] + cost[k][j] < cost[i][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                    // cout << cost[i][j] << " ";
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // cout << cost[i][j] << " ";
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        cost[i][i] = 0;
    }
    
    
    int sum = 9999999;
    for(int i = 1; i <= n; i++)
    {
        int costab = cost[s][i];
        
        int costa = cost[i][a];
        int costb = cost[i][b];
        
        sum = min(sum, costab + costa + costb);
        
    }
    
    
    
    return sum;
}