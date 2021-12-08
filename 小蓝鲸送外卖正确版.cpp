#include <iostream>
using namespace std;

int state[50001];
long int number[50001];

int main()
{
    int n = 0;
    cin >> n;
    long int sum = 0, maxx = 0;
    int u, v, w;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        if (v == 1 || state[v])
        {
            int temp = v;
            v = u;
            u = temp;
        }
        state[v]++;
        state[u]++;
        number[v] = number[u] + w;
        sum += w;
        maxx = (maxx > number[v] ? maxx : number[v]);
    }
    sum -= maxx;
    sum *= 2;
    sum += maxx;
    cout << sum;
    return 0;
}