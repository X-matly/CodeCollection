#include <iostream>
using namespace std;

const int N = 100005; // 节点数量
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

struct node
{
    int ID;
    node *next;
};
node *branch[100005];

bool check(int m, int n)
{
    if (find(m) == find(n))
    {
        return false;
    }
    else
        merge(m, n);
    if (branch[n] == NULL)
        return true;
    else
    {
        for (node *p = branch[n]; p != NULL; p = p->next)
        {
            if (p->ID == m)
            {
                return false;
            }
            else if (!check(n, p->ID))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
    {
        init();
        int m, n;
        cin >> m >> n;
        if (branch[m] == NULL)
        {
            if (check(m, n))
            {
                branch[m] = (node *)malloc(sizeof(node));
                branch[m]->ID = n;
                branch[m]->next = NULL;
            }
            else
            {
                cout << "False";
                return 0;
            }
        }
        else
        {
            if (check(m, n))
            {
                node *p = branch[m];
                for (; p->next != NULL; p = p->next)
                    ;
                p->next = (node *)malloc(sizeof(node));
                p = p->next;
                p->ID = n;
                p->next = NULL;
            }
            else
            {
                cout << "False";
                return 0;
            }
        }
    }
    cout << "True";
    return 0;
}

#include <iostream>
using namespace std;

const int N = 100005; // 节点数量
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

struct node
{
    int ID;
    node *next;
};
node *branch[100005];

bool check(int m, int n)
{
    if (find(m) == find(n))
    {
        return false;
    }
    else
        merge(m, n);
    if (branch[n] == NULL)
        return true;
    else
    {
        for (node *p = branch[n]; p != NULL; p = p->next)
        {
            if (!check(n, p->ID))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < b; i++)
    {
        init();
        int m, n;
        cin >> m >> n;
        if (branch[m] == NULL)
        {
            if (check(m, n))
            {
                branch[m] = (node *)malloc(sizeof(node));
                branch[m]->ID = n;
                branch[m]->next = NULL;
            }
            else
            {
                cout << "False";
                return 0;
            }
        }
        else
        {
            if (check(m, n))
            {
                node *p = branch[m];
                for (; p->next != NULL; p = p->next)
                    ;
                p->next = (node *)malloc(sizeof(node));
                p = p->next;
                p->ID = n;
                p->next = NULL;
            }
            else
            {
                cout << "False";
                return 0;
            }
        }
    }
    cout << "True";
    return 0;
}
