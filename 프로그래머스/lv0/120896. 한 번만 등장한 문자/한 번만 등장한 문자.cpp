#include <string>
#include <vector>

using namespace std;
int cnt[50];

string solution(string s) {
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        cnt[s[i] - 'a']++;
    }
    for(int i = 0; i < 50; i++){
        if(cnt[i] == 1)
            answer += char('a' + i);
    }
    
    return answer;
}