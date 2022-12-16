#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    string sAge = to_string(age);
    for(int i = 0; i < sAge.size(); i++){
        answer += sAge[i] - '0' + 'a';
    }
    return answer;
}