#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    map<double, int> m;
    for(int i = 0; i < 4; i++){
        for(int j = i+1; j < 4; j++){
            double dx = dots[i][0] - dots[j][0];
            double dy = dots[i][1] - dots[j][1];
            if(dx != 0)
                m[dy/dx] += 1;
        }
    }
    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second >= 2)
            answer = 1;
    }
    return answer;
}