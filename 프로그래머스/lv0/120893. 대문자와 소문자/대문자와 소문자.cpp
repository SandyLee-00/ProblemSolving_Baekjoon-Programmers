#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(int i = 0; i < my_string.size(); i++){
        if(my_string[i] >= 'a' && my_string[i] <= 'z'){
            answer.push_back(my_string[i] + 'A' - 'a');
        }
        if(my_string[i] >= 'A' && my_string[i] <= 'Z'){
            answer.push_back(my_string[i] - ('A' - 'a'));
        }
    }
    return answer;
}