#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    for(int i = 0; i < my_string.size(); i++){
        char l = letter[0];
        if(my_string[i] != l){
            answer += my_string[i];
        }
    }
    return answer;
}