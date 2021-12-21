#include <iostream>
#include <stdlib.h>
using namespace std;

#define Elemtype int
#define MAXDATA 100000000 /* 该值应根据具体情况定义为大于堆中所有可能元素的值 */
#define MINDATA -1
typedef struct HNode
{
    Elemtype *Data; /* 存储元素的数组 */
    int Size;       /* 堆中当前元素个数 */
    int Capacity;   /* 堆的最大容量 */
} * Heap;

typedef Heap MaxHeap; /* 最大堆 */
typedef Heap MinHeap; /* 最小堆 */

MaxHeap CreateHeap_MAX(int MaxSize)
{ /* 创建容量为MaxSize的空的最大堆 */

    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->Data = (Elemtype *)malloc((MaxSize + 1) * sizeof(Elemtype));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Data[0] = MAXDATA; /* 定义"哨兵"为大于堆中所有可能元素的值*/
    return H;
}

MinHeap CreateHeap_MIN(int MaxSize)
{ /* 创建容量为MaxSize的空的最小堆 */

    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->Data = (Elemtype *)malloc((MaxSize + 1) * sizeof(Elemtype));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Data[0] = MINDATA; /* 定义"哨兵"为小于堆中所有可能元素的值*/
    return H;
}

bool Insert_MAX(MaxHeap H, Elemtype X)
{ /* 将元素X插入最大堆H，其中H->Data[0]已经定义为哨兵 */
    int i;
    i = ++H->Size; /* i指向插入后堆中的最后一个元素的位置 */
    for (; H->Data[i / 2] < X; i /= 2)
        H->Data[i] = H->Data[i / 2]; /* 上滤X */
    H->Data[i] = X;                  /* 将X插入 */
    return true;
}

bool Insert_MIN(MinHeap H, Elemtype X)
{ /* 将元素X插入最小堆H，其中H->Data[0]已经定义为哨兵 */
    int i;
    i = ++H->Size; /* i指向插入后堆中的最后一个元素的位置 */
    for (; H->Data[i / 2] > X; i /= 2)
        H->Data[i] = H->Data[i / 2]; /* 上滤X */
    H->Data[i] = X;                  /* 将X插入 */
    return true;
}

#define ERROR -1 /* 错误标识应根据具体情况定义为堆中不可能出现的元素值 */

Elemtype DeleteMax(MaxHeap H)
{ /* 从最大堆H中取出键值为最大的元素，并删除一个结点 */
    int Parent, Child;
    Elemtype MaxItem, X;
    MaxItem = H->Data[1]; /* 取出根结点存放的最大值 */
    /* 用最大堆中最后一个元素从根结点开始向上过滤下层结点 */
    X = H->Data[H->Size--]; /* 注意当前堆的规模要减小 */
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Data[Child] < H->Data[Child + 1]))
            Child++; /* Child指向左右子结点的较大者 */
        if (X >= H->Data[Child])
            break; /* 找到了合适位置 */
        else       /* 下滤X */
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
    return MaxItem;
}

Elemtype DeleteMin(MinHeap H)
{ /* 从最小堆H中取出键值为最小的元素，并删除一个结点 */
    int Parent, Child;
    Elemtype MinItem, X;
    MinItem = H->Data[1]; /* 取出根结点存放的最小值 */
    /* 用最小堆中最后一个元素从根结点开始向上过滤下层结点 */
    X = H->Data[H->Size--]; /* 注意当前堆的规模要减小 */
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if ((Child != H->Size) && (H->Data[Child] > H->Data[Child + 1]))
            Child++; /* Child指向左右子结点的较小者 */
        if (X <= H->Data[Child])
            break; /* 找到了合适位置 */
        else       /* 下滤X */
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
    return MinItem;
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    MaxHeap MAX = CreateHeap_MAX(n); //建立最大堆
    MinHeap MIN = CreateHeap_MIN(n); //建立最小堆
    for (int i = 1; i <= n; i++)
    {
        int population = 0;
        scanf("%d", &population);
        if (population > MIN->Data[1])
            Insert_MIN(MIN, population);
        else
            Insert_MAX(MAX, population);              //根据人口数量与最小堆根节点的比较判断其进入最大堆或是最小堆
        int k = (i % m == 0) ? (i / m) : (i / m + 1); //更新k值
        while (MIN->Size > k)                         //维护大小为k的最小堆
        {
            Insert_MAX(MAX, DeleteMin(MIN));
        }
        while (MIN->Size < k)
        {
            Insert_MIN(MIN, DeleteMax(MAX));
        }
        printf("%d ", MIN->Data[1]); //最小堆根节点即为答案
    }
    return 0;
}
