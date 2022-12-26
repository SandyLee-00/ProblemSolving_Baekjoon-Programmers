#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = -1;
    int size = A.size();
    for(int i = 0; i < size; i++){
        // +하는 숫자
        string S = "";
        for(int j = 0; j < size; j++){
            S += A[(i + j) % size];
        }
        if(S == B){
            answer = size - i;
            break;
        }
            
    }
    if(answer == size) answer = 0;
    return answer;
}