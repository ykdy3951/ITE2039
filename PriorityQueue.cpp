//2019044711_김찬웅_11802
#include <stdio.h>

#define MAX_SIZE 100001

int a[MAX_SIZE] = {
    987654321,
},
    index;

int parent(int i)
{
    return i / 2;
}
int left_child(int i)
{
    return 2 * i;
}
int right_child(int i)
{
    return 2 * i + 1;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printAll()
{
    int i;
    printf("\n");
    for (i = 1; i <= index; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert(int data)
{
    a[++index] = data;

    int i = index;
    while (i != 1 && a[parent(i)] < a[i])
    {
        swap(&a[parent(i)], &a[i]);
        i = parent(i);
    }
}

void max_heapify(int i)
{

    int left = left_child(i);

    int right = right_child(i);

    int largest = i;

    if (right <= index && a[right] > a[largest])
    {
        largest = right;
    }

    if (left <= index && a[left] > a[largest])
    {
        largest = left;
    }

    if (largest != i)
    {
        swap(a + i, a + largest);
        max_heapify(largest);
    }
}

void subtitute(int i, int data)
{
    a[i] = data;
    if (i != 1 && a[parent(i)] < a[i])
    {
        while (i != 1 && a[parent(i)] < a[i])
        {
            swap(&a[parent(i)], &a[i]);
            i = parent(i);
        }
    }
    else
    {
        max_heapify(i);
    }
}

int extract()
{
    int max = a[1];

    a[1] = a[index];
    a[index--] = 0;
    int i = 1;
    while (1)
    {
        int left = left_child(i), right = right_child(i);
        if (left > index)
            break;
        if (a[i] >= a[left] && a[i] >= a[right])
            break;
        if (a[left] > a[right])
        {
            swap(&a[i], &a[left]);
            i = left;
        }
        else
        {
            swap(&a[i], &a[right]);
            i = right;
        }
    }
    return max;
}

int main()
{
    int input, a, b;
    scanf("%d", &input);
    while (input)
    {
        if (input == 1)
        {
            scanf("%d", &a);
            insert(a);
        }
        else if (input == 2 && index > 0)
        {
            printf("%d ", extract());
        }
        else if (input == 3)
        {
            scanf("%d %d", &a, &b);
            subtitute(a, b);
        }
        scanf("%d", &input);
    }

    printAll();
    return 0;
}