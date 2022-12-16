#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    char kC = k + '0';
    for(; i <= j; i++){
        string num = to_string(i);
        for(int l = 0; l < num.size(); l++){
            if(num[l] == kC)
                answer++;
        }
    }
    return answer;
}