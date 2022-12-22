#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            answer.push_back(i);
        }
        while(1){
            if(n % i == 0){
                n /= i;
            }
            else 
                break;
        }
        
    }    
    
    return answer;
}