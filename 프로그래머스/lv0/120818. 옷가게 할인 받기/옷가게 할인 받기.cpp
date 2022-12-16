#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    double p = price;
    double answer = 0;
    answer = p;
    
    if(price >= 500000){
        answer -= p / 10 * 2;
    }
    else if(price >= 300000){
        answer -= p / 10 * 1;
    }
    else if(price >= 100000){
        answer -= p / 10 / 2;
    }
    answer = int(answer);
    return answer;
}