#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> q;
    string w;
    cin >> w;
    for (int i = 0; i < w.length(); i++)
    {
        if (q.empty())
        {
            q.push(i);
        }
        else
        {
            if (w[q.top()] == 'M' && w[i] == 'S')
            {
                w[q.top()] = '*';
                w[i] = '*';
                q.pop();
            }
            else
            {
                q.push(i);
            }
        }
    }
    int max = 0;
    int temp = 0;
    w += 'Q';
    for (int i = 0; i < w.length(); i++)
    {
        if (w[i] == '*')
            temp++;
        if (w[i + 1] == '*')
            continue;
        else
        {
            max = max > temp ? max : temp;
            temp = 0;
        }
    }
    cout << max;
    return 0;
}