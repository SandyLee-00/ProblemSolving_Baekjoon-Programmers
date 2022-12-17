#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    sort(array.begin(), array.end());
    int resIdx = 0;
    int mindif = 9999;
    for(int i = 0; i < array.size(); i++){
        int dif = n - array[i];
        if(dif < 0) dif = -dif;
        
        if(dif < mindif){
            mindif = dif;
            resIdx = i;
        }
    }
    answer = array[resIdx];
    
    return answer;
}