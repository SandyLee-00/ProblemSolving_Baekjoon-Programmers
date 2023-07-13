#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool isDifOnlyOne(string a, string b)
{
    if(a.size() != b.size()) return false;
    
    int diffCnt = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i]) diffCnt += -1;
    }
    
    if(diffCnt != -1) return false;
    
    return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    words.push_back(begin);
    vector<bool> isVis(words.size(), false);
    
    queue<pair<int, int>> q;
    q.push(make_pair(words.size() -1, 0));
    isVis[words.size() -1] = true;
    
    while(!q.empty())
    {
        int strI = q.front().first;
        string str = words[strI];
        int cnt = q.front().second;
        
        q.pop();
        
        if(str == target)
        {
            return cnt;
        }
        
        for(int i = 0; i < words.size(); i++)
        {
            if(isVis[i] == true) continue;
            
            if(isDifOnlyOne(str, words[i]) == true)
            {
                isVis[i] = true;
                cnt++;
                q.push(make_pair(i, cnt));
                cout << words[i] << "/" << cnt << "\n";
                cnt--;
            }
        }
    }
    return answer;
}