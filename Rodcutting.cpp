//2019044711_김찬웅_11802
#include <stdio.h>

#define INF -98654321

int n;
int p[101];
int r[101];
int s[101];

void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
}

void Rodcutting()
{
    for (int i = 1; i <= n; i++)
    {
        int q = INF;
        for (int j = 1; j <= i; j++)
        {
            if (q < p[j] + r[i - j])
            {
                q = p[j] + r[i - j];
                s[i] = j;
            }
        }
        r[i] = q;
    }
}

void print_rod_sol()
{
    int temp_n = n;
    printf("%d\n", r[temp_n]);
    while (temp_n > 0)
    {
        printf("%d ", s[temp_n]);
        temp_n = temp_n - s[temp_n];
    }
}

int main(void)
{
    init();
    Rodcutting();
    print_rod_sol();
    return 0;
}