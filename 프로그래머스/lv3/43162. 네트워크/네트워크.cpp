#include <string>
#include <vector>

using namespace std;

const int MAX = 205;
bool isVisitCom[MAX];

void DFS(int node, int n, vector<vector<int>> computers)
{
    isVisitCom[node] = true;
    
    for(int i = 0; i < n; i++)
    {
        if(computers[node][i] == true && isVisitCom[i] == false)
        {
            DFS(i, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(isVisitCom[i] == false)
        {
            answer++;
            DFS(i, n, computers);
        }
    }
    
    return answer;
}