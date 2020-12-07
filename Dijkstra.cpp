//2019044711_김찬웅_11802
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

typedef struct pair_t
{
    int a;
    int b;
    bool operator<(const pair_t t) const
    {
        return a > t.a;
    }
} pair_t;

priority_queue<pair_t> pq;
vector<pair_t> graph[5005];
bool chk[5005];
int ans;

int n, m;

void init()
{
    scanf("%d %d", &n, &m);
    int a, b, w;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        pair_t x;
        x.a = b;
        x.b = w;
        graph[a].push_back(x);
    }
}

void Dijkstra()
{
    pq.push({0, 1});
    while (!pq.empty())
    {
        pair_t x = pq.top();
        int w = x.a, node = x.b;
        pq.pop();
        if (chk[node])
        {
            continue;
        }
        chk[node] = 1;
        ans = w;
        for (int i = 0; i < graph[node].size(); i++)
        {
            pair_t nx = graph[node][i];
            int next = nx.a, dw = nx.b;
            pq.push({(w + dw), next});
        }
    }
}

int main(void)
{
    init();
    Dijkstra();
    printf("%d\n", ans);
    return 0;
}