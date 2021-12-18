#include <iostream>
using namespace std;
int a[10000005];
void qsort(int l, int m)
{
    int mid = a[(l + m) / 2];
    int i = l;
    int j = m;
    do
    {
        while (a[i] > mid)
            i++;
        while (a[j] < mid)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j)
        qsort(l, j);
    if (i < m)
        qsort(i, m);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    qsort(0, m - 1);
    cout << a[n - 1];
    return 0;
}