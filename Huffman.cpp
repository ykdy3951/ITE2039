//2019044711_김찬웅_11802
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int S;
priority_queue<int> pq;
vector<int> v;

int huffman()
{
    int ans = 0;
    while (!pq.empty())
    {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();

        int sum = a + b;
        ans += sum;

        if (!pq.empty())
        {
            pq.push(-sum);
        }
    }
    return ans;
}

int fixed(int n)
{
    int ans = 0;
    while (n >= 2)
    {
        ans++;
        n /= 2;
    }
    ans += n;
    return ans;
}

void init()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char str[4];
        int num;
        scanf("%4s %d", str, &num);
        pq.push(-num);
        // s *temp = new s(num, true);
        // pq.push({-num, temp});
    }
    scanf("%d", &S);
}

int main(void)
{
    init();

    printf("%d\n", S * fixed(n));
    printf("%d\n", huffman());
    return 0;
}