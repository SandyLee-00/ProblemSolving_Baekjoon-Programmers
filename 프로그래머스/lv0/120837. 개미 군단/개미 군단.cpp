#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int GenCnt = 0;
    int solCnt = 0;
    int workCnt = 0;
    
    GenCnt = hp / 5;
    hp -= GenCnt * 5;
    solCnt = hp / 3;
    hp -= solCnt * 3;
    workCnt = hp;
    answer = GenCnt + solCnt + workCnt;
    
    return answer;
}