#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
다르면 - 더 많이 준 쪽이 하나 받기
같으면 - 선물지수 큰 사람이 하나 받기


*/

int grp[55][55];

vector<string> split(string input, char del){
    vector<string> answer;
    stringstream ss(input);
    string temp;
    
    while(getline(ss, temp, del)){
        answer.push_back(temp);
    }
    
    return answer;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    map<string, int> m;
    vector<int> scores(friends.size(), 0);
    
    for(int i = 0; i < friends.size(); i++){
        m[friends[i]] = i;
    }
    
    for(int i = 0; i < gifts.size(); i++){
        vector<string> strings = split(gifts[i], ' ');
        string from = strings[0];
        string to = strings[1];
        
        grp[m[from]][m[to]] += 1;
        
        scores[m[from]] += 1;
        scores[m[to]] -= 1;
        
    }
    
    vector<int> answers(friends.size(), 0);
    for(int i = 0; i < friends.size(); i++){
        for(int j = i + 1; j < friends.size(); j++){
            if(grp[i][j] > grp[j][i]){
                answers[i] += 1;
            }
            else if(grp[i][j] < grp[j][i]){
                answers[j] += 1;
            }
            else if(scores[i] > scores[j]){
                answers[i] += 1;
            }
            else if(scores[i] < scores[j]){
                answers[j] += 1;
            }
        }
    }
    
    for(int i = 0; i < answers.size(); i++){
        answer = max(answers[i], answer);
    }
    
    return answer;
}