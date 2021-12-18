/*#include <stdio.h>
#include <stack>
int q[100005];
int ans[100005];
int main()
{
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        ans[i] = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
        for (int j = 0; j < i; j++)
        {
            if (q[j] > q[i])
                ans[j]++;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    return 0;
}*/

#include <iostream>
#include <stack>
using namespace std;
int a[100005];
int ans[100005];
int main()
{
    int n = 0;
    cin >> n;
    stack<int> q;
    for (int i = n - 1; i >= 0; i--)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && a[q.top()] > a[i])
        {
            int temp = q.top();
            q.pop();
            ans[temp] = q.size();
        }
        q.push(i);
    }
    while (!q.empty())
    {
        int temp = q.top();
        q.pop();
        ans[temp] = q.size();
    }
    for (int i = n - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}