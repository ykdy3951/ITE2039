//2019044711_김찬웅_11802
#include <stdio.h>

#define MAX 100001

int n, m, res;
int cnt[MAX];

int main(void)
{
    scanf("%d %d", &n, &m);
    while (n--)
    {
        int num;
        scanf("%d", &num);
        cnt[num]++;
    }
    while (m--)
    {
        int num;
        scanf("%d", &num);
        if (cnt[num])
        {
            res++;
        }
    }
    printf("%d", res);
    return 0;
}