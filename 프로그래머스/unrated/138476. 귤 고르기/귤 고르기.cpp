#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(), tangerine.end());
    
    vector<int> v;
    int tmp = tangerine[0];
    v.push_back(0);
    int idx = 0;
    
    for(int i = 0; i < tangerine.size(); i++)
    {
        if(tmp == tangerine[i])
        {
            v[idx]++;
        }
        else
        {
            idx++;
            v.push_back(1);
            tmp = tangerine[i];
        }
    }
    
    sort(v.begin(), v.end(), greater<int>());
    
    for(int i = 0; i < v.size(); i++)
    {
        k -= v[i];
        answer ++;
        if(k <= 0)
        {
            break;
        }
    }
    
    return answer;
}