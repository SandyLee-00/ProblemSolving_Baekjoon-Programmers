#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string tmpS = "";
    int tmp = 0;
    bool flag = 1;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            tmpS += s[i];
        }
        else if(s[i] == '-'){
            flag = 0;
        }
        else if(s[i] == ' '){
            if(tmpS.size() > 0){
                tmp = stoi(tmpS);
                tmpS = "";
            if(!flag)
                tmp = -tmp;
            answer += tmp;
            flag = 1;
            }
            
        }
        else if(s[i] == 'Z'){
            answer -= tmp;
        }
    }
     if(tmpS.size() > 0){
                tmp = stoi(tmpS);
                tmpS = "";
            if(!flag)
                tmp = -tmp;
            answer += tmp;
     }
    
    return answer;
}