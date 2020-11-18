//2019044711_김찬웅_11802
#include <stdio.h>

#define MAX 100000

int N, arr[MAX], sorted[MAX];

void Merge(int p, int q, int r)
{
    int a, b, c, i;
    a = p;
    b = q + 1;
    c = p;

    while (a <= q && b <= r)
    {
        if (arr[a] >= arr[b])
            sorted[c++] = arr[a++];
        else
            sorted[c++] = arr[b++];
    }

    if (a <= q)
    {
        for (i = a; i <= q; i++)
        {
            sorted[c++] = arr[a++];
        }
    }
    else
    {
        for (i = b; i <= r; i++)
        {
            sorted[c++] = arr[b++];
        }
    }

    for (i = p; i <= r; i++)
    {
        arr[i] = sorted[i];
    }
}

void Merge_Sort(int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        Merge_Sort(p, q);
        Merge_Sort(q + 1, r);
        Merge(p, q, r);
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    Merge_Sort(0, N - 1);

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}