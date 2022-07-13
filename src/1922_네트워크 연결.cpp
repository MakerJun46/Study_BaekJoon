#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct e_t
{
    int node;
    int cost;

    e_t(int _node, int _cost) : node(_node), cost(_cost) {}

    bool operator<(const e_t& ref) const
    {
        return this->cost > ref.cost;
    }
};

int N, M;

vector<e_t> Nodes[1001];
int Visited[1001];

// MST (Prim Algorithm)

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
        Visited[i] = -1;

    int a, b, c;

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        Nodes[a].push_back(e_t(b, c));
        Nodes[b].push_back(e_t(a, c));
    }

    priority_queue<e_t> pq;

    pq.push(e_t(1, 0));

    while (!pq.empty())
    {
        e_t item = pq.top(); pq.pop();

        if (Visited[item.node] != -1)
            continue;

        Visited[item.node] = item.cost;

        for (e_t next : Nodes[item.node])
        {
            pq.push(next);
        }
    }

    int costSum = 0;

    for (int i = 1; i <= N; i++)
    {
        costSum += Visited[i];
    }
    
    printf("%d", costSum);

    return 0;
}
