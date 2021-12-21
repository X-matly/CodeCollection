#include <stdio.h>

int e[1005][1005];

int main()
{
    int k, i, j, n, m;
    int p[11];
    int a, b;
    int inf = 9999999; //用inf(infinity的缩写)存储一个我们认为的正无穷值

    scanf("%d%d%d%d", &n, &m, &a, &b); //读入n和m，n表示顶点个数，m表示边的条数
    //初始化
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i == j)
                e[i][j] = 0;
            else
                e[i][j] = inf;
    //读入边

    for (i = 1; i <= m; i++)
    {

        int num = 0;
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &p[j]);
        }
        for (int j = 0; j < num - 1; j++)
        {
            int length = 0;
            scanf("%d", &length);
            e[p[j]][p[j + 1]] = length;
            e[p[j + 1]][p[j]] = length; //由于是无向边，故记录双向数据
        }
    }

    //Floyd-Warshall算法核心语句
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (e[i][j] > e[i][k] + e[k][j])
                    e[i][j] = e[i][k] + e[k][j];
    if (e[a][b] == inf)
        printf("-1");
    else
        printf("%d", e[a][b]); //无结果输出-1，有结果输出当前值
    return 0;
}