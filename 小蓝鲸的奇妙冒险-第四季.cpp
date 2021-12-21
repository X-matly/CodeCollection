#include <iostream>
using namespace std;

const int maxnum = 505;
const int maxint = 999999999;

// 各数组都从下标1开始
int dist[maxnum];      // 表示当前点到源点的最短路径长度
int preva[maxnum];     // 记录当前点的前一个结点
int c[maxnum][maxnum]; // 记录图的两点间路径长度
int n, line;           // 图的结点数和路径数
int in[maxnum];        //换线时间
int sum[maxnum];       //各线路站点数量
int pq[maxnum];        //各站点数量
int timee[maxnum];     //各线路站点间距时间

void Dijkstra(int n, int v, int *dist, int *preva, int c[maxnum][maxnum]) //迪杰特斯拉算法
{
    bool s[maxnum]; // 判断是否已存入该点到S集合中
    for (int i = 1; i <= n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0; // 初始都未用过该点
        if (dist[i] == maxint)
            preva[i] = 0;
        else
            preva[i] = v;
    }
    dist[v] = 0;
    s[v] = 1;

    // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
    // 注意是从第二个节点开始，第一个为源点
    for (int i = 2; i <= n; ++i)
    {
        int tmp = maxint;
        int u = v;
        // 找出当前未使用的点j的dist[j]最小值
        for (int j = 1; j <= n; ++j)
            if ((!s[j]) && dist[j] < tmp)
            {
                u = j; // u保存当前邻接点中距离最小的点的号码
                tmp = dist[j];
            }
        s[u] = 1; // 表示u点已存入S集合中

        // 更新dist
        for (int j = 1; j <= n; ++j)
            if ((!s[j]) && c[u][j] < maxint)
            {
                int newdist = dist[u] + c[u][j];
                if (newdist < dist[j])
                {
                    dist[j] = newdist;
                    preva[j] = u;
                }
            }
    }
}

int main()
{
    int a, b;
    cin >> n;
    // 输入路径数
    cin >> line;
    cin >> a >> b;
    for (int i = 1; i <= line; i++) //各线路站点
    {
        cin >> sum[i];
    }
    for (int i = 1; i <= line; i++) //各线路换乘时间
    {
        cin >> in[i];
    }
    // 初始化c[][]为maxint
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            c[i][j] = maxint;
    //输入图的各项信息
    for (int i = 1; i <= line; ++i)
    {
        for (int j = 1; j <= sum[i]; j++)
        {
            cin >> pq[j];
        }
        for (int j = 1; j < sum[i]; j++)
        {
            cin >> timee[j];
        }
        for (int j = 1; j <= sum[i]; j++)
        {
            for (int l = j + 1; l <= sum[i]; l++)
            {
                int temp = in[i];
                for (int k = j; k < l; k++)
                {
                    temp += timee[k];
                }
                if (temp < c[pq[j]][pq[l]]) // 有重边
                {
                    c[pq[j]][pq[l]] = temp; // p指向q
                }
            }
        }
    }
    //初始化dist数组
    for (int i = 1; i <= n; ++i)
        dist[i] = maxint;

    Dijkstra(n, a, dist, preva, c);

    // 最短路径长度
    cout << dist[b];
}