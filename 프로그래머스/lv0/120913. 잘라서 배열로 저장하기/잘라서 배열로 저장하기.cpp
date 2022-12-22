#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string str = "";
    
    for(int i = 0; i < my_str.size(); i++){
        str += my_str[i];
        if(str.size() % n == 0){
            answer.push_back(str);
            str = "";
        }
        
    }
    if(str.size() > 0){
        answer.push_back(str);
        
    }
    
    return answer;
}