#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    vector<int> tmp;
    tmp = arr;
    sort(tmp.begin(), tmp.end());
    int minV = tmp[0];
    for(int i = 0; i < arr.size(); i++){
        if(minV != arr[i]){
            answer.push_back(arr[i]);
        }
    }
    if(answer.empty())
        answer.push_back(-1);
    return answer;
}