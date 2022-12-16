#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {
    int answer = 1;
    
    int chars[100];
    for(int i = 0; i < 100; i++){
        chars[i] = 0;
    }
    
    for(int i = 0; i < before.size(); i++){
        chars[before[i] - 'a']++;
    }
    for(int i = 0; i < after.size(); i++){
        chars[after[i] - 'a']--;
    }
    for(int i = 0; i < 100; i++){
        if(chars[i] != 0)
            answer = 0;
    }
    
    return answer;
}