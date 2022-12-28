#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for(int i = 0; i < quiz.size(); i++){
        string q = quiz[i];
        string tmp;
        int flag = 1;
        int lNum = 0;
        for(int j = 0; j < q.size(); j++){
            if(q[j] >= '0' && q[j] <= '9')
                tmp += q[j];
            
            if(q[j] == '-')
                flag = 0;
            
            if(q[j] == ' ' && tmp.size() > 0 && j != q.size()-1){
                int num = stoi(tmp);
                tmp = "";
                if(!flag) 
                    num = -num;
                flag = 1;
                lNum += num;
            }
            if(j == q.size()-1){
                int num = stoi(tmp);
                tmp = "";
                if(!flag) 
                    num = -num;
                flag = 1;
                
                if(lNum == num)
                    answer.push_back("O");
                else
                    answer.push_back("X");
            }
        }
    }
    
    
    return answer;
}