//2019044711_김찬웅_11802
#include <stdio.h>

#define MAX 100001

int arr[MAX] = {
    0,
};
int k, n, size;

void heapify(int i)
{
    int right = i * 2 + 1;
    int left = i * 2;
    int large = i;
    int tmp;

    if (left <= size && arr[left] > arr[large])
    {
        large = left;
    }
    if (right <= size && arr[right] > arr[large])
    {
        large = right;
    }
    if (large != i)
    {
        tmp = arr[large];
        arr[large] = arr[i];
        arr[i] = tmp;
        heapify(large);
    }
}

void build_max_heap()
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(i);
    }
}

void heapsort()
{
    build_max_heap();
    for (int i = n; i > n - k; i--)
    {
        printf("%d ", arr[1]);
        arr[1] = arr[i];
        size--;
        heapify(1);
    }
}

int main()
{
    scanf("%d %d", &n, &k);
    size = n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", arr + i);
    }
    heapsort();
    printf("\n");
    for (int i = 1; i <= size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}