#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

/*
전체 말 map에 저장, 동일한지 체크
i / n 말 i % n 사람
*/
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m;
    char last = words[0][words[0].size()-1];
    for(int i = 0; i < words.size(); i++){
        m[words[i]] ++;
        
        if(m[words[i]] > 1){
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            return answer;
        }
        
        if(i == 0) continue;
        
        last = words[i-1][words[i-1].size()-1];
        if(words[i][0] != last){
            answer.push_back(i % n + 1);
            answer.push_back((i / n) + 1);
            return answer;
        }
        
        
    }
    answer.push_back(0);
    answer.push_back(0);

    return answer;
}