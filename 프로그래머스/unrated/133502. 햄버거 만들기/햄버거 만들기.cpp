#include <string>
#include <vector>

using namespace std;
/*
하나씩 tmp에 저장,
빵 들어오면 앞에 3개 있는지, 있으면 123체크 ++ 쌓던 위치부터 추가
다른 것들 pos에 하나씩 넣기
*/

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v(ingredient.size(), 0);
    int pos = 0;
    for(int i = 0; i < ingredient.size(); i++){
        pos++;
        if(pos > 3 && ingredient[i] == 1 && v[pos-1] == 3 && v[pos-2] == 2 && v[pos-3] == 1){
            answer++;
            pos = pos-4;
        }
        else{
            v[pos] = ingredient[i];
        }
    }
    return answer;
}