#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 2;
    for(int i = 0; i < str1.size(); i++){
        int isIn = 1;
        for(int j = 0; j < str2.size(); j++){
            if(str1[i + j] != str2[j]) isIn = 0;
        }
        if(isIn){
            answer = 1;
            break;
        } 
    }
    return answer;
}