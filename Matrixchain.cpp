//2019044711_김찬웅_11802
#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX 987654321

int n;
int arr[101][101];
int s[101][101];
int p[101];
/*
30 x 35
35 x 15
15 x 5
5 x 10
10 x 20
20 x 25
*/
void init()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
}

void MatrixChain()
{
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            arr[i][j] = MAX;
            int q;
            for (int k = i; k <= j - 1; k++)
            {
                q = arr[i][k] + arr[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < arr[i][j])
                {
                    arr[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print(int i, int j)
{
    if (i == j)
    {
        printf("%d ", i);
    }
    else
    {
        printf("( ");
        print(i, s[i][j]);
        print(s[i][j] + 1, j);
        printf(") ");
    }
}

int main()
{
    init();
    MatrixChain();
    printf("%d\n", arr[1][n]);
    print(1, n);
    return 0;
}