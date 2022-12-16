#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    vector<int> alph(500, 0);
    for(int i = 0; i < my_string.size(); i++){
        if(alph[my_string[i]] == 0){
            answer += my_string[i];
        }
        alph[my_string[i]] = 1;
    }
    
    return answer;
}