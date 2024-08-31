#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    unordered_map<string, int> names;
    for(int i = 0; i < name.size(); i++)
    {
        names[name[i]] = yearning[i];
    }
    
    for(int i = 0; i < photo.size(); i++)
    {
        answer.push_back(0);
        
        for(int j = 0; j < photo[i].size(); j++)
        {
            string namej = photo[i][j];
            
            if(names[namej] != 0)
            {
                answer[i] += names[namej];
            }
        }
    }
    
    
    return answer;
}