#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    vector<int> str;
    for(int i = 0; i < my_string.size(); i++){
        int letter = my_string[i];
        if(my_string[i] < 'a'){
            letter += - 'A' + 'a';
        }
        str.push_back(letter);
    }
    sort(str.begin(), str.end());
    for(int i = 0; i < str.size(); i++){
        answer += char(str[i]);
    }
    
    return answer;
}