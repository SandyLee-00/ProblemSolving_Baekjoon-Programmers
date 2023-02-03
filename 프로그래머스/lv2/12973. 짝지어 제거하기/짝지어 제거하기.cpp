#include <iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> sta;
    sta.push(s[0]);
    for(int i = 1; i < s.size(); i++){
        if(!sta.empty()){
            if(sta.top() == s[i]){
                sta.pop();
            }
            else{
                sta.push(s[i]);
            }
        }
        else{
            sta.push(s[i]);
        }
    }
    
    if(sta.empty()) answer = 1;
    else answer = 0;

    return answer;
}