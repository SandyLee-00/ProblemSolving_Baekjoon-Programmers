#include <string>
#include <vector>

using namespace std;
/*
카펫 조각 합 구하기, 가로세로 가능한 조합 찾기
세로가 3이상인 것
두께 1 ~ 갈색 카운트하기
*/

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    for(int i = 3; i < sum; i++){
        if(sum % i == 0){
            int w = sum / i;
            int h = i;
            for(int range = 1; range <= i / 2; range++){
                int bCnt = range * (2 * w + 2 * (h - 2));
                if(bCnt == brown){
                    answer.push_back(w);
                    answer.push_back(h);
                    return answer;
                }
            }
        }
    }
    
    
    return answer;
}