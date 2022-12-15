#include <string>
#include <vector>

using namespace std;

int numCnt[1005];

int solution(vector<int> array) {
    int answer = 0;
    
    for(int i = 0; i < array.size(); i++){
        numCnt[array[i]]++;
    }
    int res = 0;
    int resCnt = 0;
    for(int i = 0; i < 1005; i++){
        if(resCnt < numCnt[i]){
            resCnt = numCnt[i];
            res = i;
        }
    }
    for(int i = 0; i < 1005; i++){
        if(numCnt[res] == numCnt[i] && res != i)
            res = -1;
    }
    
    answer = res;
    
    return answer;
}