#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            int cnt = 1;
            int size = min(s1.size(), s2.size());
            for(int k = 0; k < size; k++){
                if(s1[i][k] != s2[j][k])
                    cnt = 0;
            }
            if(s1[i].size() != s2[j].size()) cnt = 0;
            answer += cnt;
        }
    }
    return answer;
}