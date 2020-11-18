//2019044711_김찬웅_11802
#include <stdio.h>

using namespace std;

#define MAX 100001

int cnt[MAX];
int a[MAX], b[MAX];
int n, k, m;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &a[i], &b[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        cnt[num]++;
    }

    for (int i = 2; i <= m; i++)
    {
        cnt[i] += cnt[i - 1];
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d\n", cnt[b[i]] - cnt[a[i] - 1]);
    }

    return 0;
}