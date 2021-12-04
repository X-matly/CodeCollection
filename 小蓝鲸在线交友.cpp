#include<iostream>
using namespace std;

const int N = 205; // 节点数量
int f[N];

void init() {
    // 初始化
    for (int i = 0; i < N; i++)
        f[i] = i;
}

int find(int x) {
    // 查询所在团伙代表人
    return f[x] == x ? x : find(f[x]);
}

void merge(int a, int b) {
    // 合并操作
    f[find(a)] = find(b);
}

int main()
{
    int a=0;
    int b=0;
    cin>>a;
    init();
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a;j++)
        {
            cin>>b;
            if(b)
            {
                if(find(i)!=find(j))
                {
                    merge(i,j);
                }
            }
        }
    }
    int ans[a];
    int num=0;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(find(i)==ans[j])
            {
                goto loop;
            }
        }
        ans[num++]=find(i);
        loop:;
    }
    cout<<num;
    return 0;
}