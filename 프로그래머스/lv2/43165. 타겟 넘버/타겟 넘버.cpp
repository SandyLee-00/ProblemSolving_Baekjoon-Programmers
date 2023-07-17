#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;

void DFS(int curIdx, int sum, vector<int>& numbers, int target)
{
    if(sum == target && curIdx == numbers.size() - 1)
    {
        cout << curIdx << "/" << sum << "\n";
        cnt++;
        return;
    }
    
    int nexti = curIdx + 1;
    
    if(nexti >=  numbers.size())
    {
        return;
    }
    
    DFS(nexti, sum + numbers[nexti], numbers, target);
    DFS(nexti, sum - numbers[nexti], numbers, target);
    
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(-1, 0, numbers, target);
    
    answer = cnt;
    
    return answer;
}