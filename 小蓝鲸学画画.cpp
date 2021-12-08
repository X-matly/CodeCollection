#include <iostream>
#include <cmath>
using namespace std;

struct edge
{
    int m, n;
    int length;
} edge[10000];

int d[101][2];
int n;

void qsort(int l, int m)
{
    int mid = edge[(l + m) / 2].length;
    int i = l;
    int j = m;
    do
    {
        while (edge[i].length < mid)
            i++;
        while (edge[j].length > mid)
            j--;
        if (i <= j)
        {
            int temp1, temp2, temp3;
            temp1 = edge[i].length;
            temp2 = edge[i].m;
            temp3 = edge[i].n;
            edge[i].length = edge[j].length;
            edge[i].m = edge[j].m;
            edge[i].n = edge[j].n;
            edge[j].length = temp1;
            edge[j].m = temp2;
            edge[j].n = temp3;
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j)
        qsort(l, j);
    if (i < m)
        qsort(i, m);
}

const int N = 105; // 节点数量
int f[N];

void init()
{
    // 初始化
    for (int i = 0; i < N; i++)
        f[i] = i;
}

int find(int x)
{
    // 查询所在团伙代表人
    return f[x] == x ? x : find(f[x]);
}

void merge(int a, int b)
{
    // 合并操作
    f[find(a)] = find(b);
}

int main()
{
    init();
    int n = 0;
    int num = 0;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i][0] >> d[i][1];
        for (int j = 0; j < i; j++)
        {
            edge[num].m = i;
            edge[num].n = j;
            edge[num].length = abs(d[i][0] - d[j][0]) + abs(d[i][1] - d[j][1]);
            num++;
        }
    }
    qsort(0, num - 1);
    for (int i = 0; i < num; i++)
    {
        if (find(edge[i].m) != find(edge[i].n))
        {
            merge(edge[i].m, edge[i].n);
            ans += edge[i].length;
            //cout << edge[i].m << "  " << edge[i].n << " " << edge[i].length << endl;
        }
    }
    cout << ans;
    return 0;
}