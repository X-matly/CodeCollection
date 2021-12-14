#include <iostream>
using namespace std;
#define MAX 10001

int parent[MAX];
int relation[MAX];

int find(int x)
{
    if (x != parent[x])
    {
        int t = parent[x];
        parent[x] = find(parent[x]);
        relation[x] = (relation[x] + relation[t]) % 2;
    }
    return parent[x];
}

inline void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
}

int main()
{
    int n;
    int state = 1;
    cin >> n;
    init(n);
    int x, y;
    while (cin >> x >> y)
    {
        int a = find(x);
        int b = find(y);
        if (a == b && (relation[x] - relation[y] + 2) % 2 != 1)
            state = 0;
        else
        {
            parent[a] = b;
            relation[a] = (-relation[x] + 1 + relation[y]) % 2;
        }
    }
    cout << state;
    return 0;
}