#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

/*
a - b + c -> a b - c +
a / b * c -> a b / c *

*/

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    stack<char> s;

    for (int i = 0; i < str.size(); i++)
    {
        char a = str[i];

        if (a == '*')
        {
            while (!s.empty() && (s.top() == '/' || s.top() == '*'))
            {
                cout << s.top();
                s.pop();
            }
            s.push(a);
        }
        else if (a == '/')
        {
            while (!s.empty() && (s.top() == '/' || s.top() == '*'))
            {
                cout << s.top();
                s.pop();
            }
            s.push(a);
        }
        else if (a == '+')
        {
            while (!s.empty() && (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/'))
            {
                cout << s.top();
                s.pop();
            }
            s.push(a);
        }
        else if (a == '-')
        {
            while (!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-'))
            {
                cout << s.top();
                s.pop();
            }
            s.push(a);
        }
        else if (a == '(')
        {
            s.push(a);
        }
        else if (a == ')')
        {
            while (!s.empty())
            {
                if (s.top() != '(')
                {
                    cout << s.top();
                    s.pop();
                }
                else
                {
                    s.pop();
                    break;
                }
            }
        }
        else
        {
            cout << a;
        }
    }

    while (!s.empty())
    {
        if (s.top() != '(')
        {
            cout << s.top();
        }
        s.pop();
    }

    return 0;
}