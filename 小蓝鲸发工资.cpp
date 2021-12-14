#include <iostream>
using namespace std;

int num[10000000];
int maxx = 1000000000;
int find(long long int temp, int n, int m)
{
    if (temp <= 1)
        return 0;
    long long int nadd = 0;
    for (int j = 0; j < n; j++)
    {
        if (num[j] % temp == 0)
            nadd += num[j] / temp;
        else
            nadd += (num[j] / temp) + 1;
    }
    if (nadd <= m)
    {
        return temp;
    }
    else
    {
        return 0;
    }
}

void bina(long long temp, int n, int m)
{
    int left = temp, right = temp + 100000000, mid = 0;
    mid = (right + left) / 2;
    while (left < right)
    {
        int a = find(mid, n, m);
        if (!a)
        {
            left = mid + 1;
        }
        else
        {
            maxx = maxx > mid ? mid : maxx;
            right = mid - 1;
        }
        mid = (left + right) / 2;
        if (left == right - 1)
            mid = right;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    long long int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        sum += num[i];
    }
    long long int temp = sum / m;
    bina(temp, n, m);
    cout << maxx;
    return 0;
}