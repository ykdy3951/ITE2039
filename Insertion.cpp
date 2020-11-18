//2019044711_김찬웅_11802
#include <stdio.h>

#define MAX 30000

int N, arr[MAX];

void insertion_sort()
{
    int i, j, key;
    for (i = 1; i < N; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] < key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
    }

    insertion_sort();

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}