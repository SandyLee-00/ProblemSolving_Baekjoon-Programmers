/*
min max 가로 세로

전체에서 가로 max 세로 max
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    for(int i = 0; i < sizes.size(); i++)
    {
        if(sizes[i][0] > sizes[i][1])
        {
            swap(sizes[i][0], sizes[i][1]);
        }
    }
    
    int mi = 0;
    int mj = 0;
    for(int i = 0; i < sizes.size(); i++)
    {
        mi = max(mi, sizes[i][0]);
        mj = max(mj, sizes[i][1]);
    }
    
    answer = mi * mj;
    
    return answer;
}