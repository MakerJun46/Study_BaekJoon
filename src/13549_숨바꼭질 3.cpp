#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N, K;
bool Visited[200001];

struct e_t
{
    int node;
    int cost;
    int cnt;

    bool operator<(const e_t& ref) const
    {
        if (this->cost == ref.cost)
            return this->cnt > ref.cnt;
        else
            return this->cost > ref.cost;
    }
};

priority_queue<e_t> pq;

int time;

void BFS()
{
    while (!pq.empty())
    {
        e_t now = pq.top();
        pq.pop();

        Visited[now.node] = true;

        if (now.node == K)
        {
            time = now.cnt;
            break;
        }

        if (now.node < 100000 && !Visited[now.node + 1])
            pq.push({ now.node + 1, 1, now.cnt + 1 });

        if (now.node > 0 && !Visited[now.node - 1])
            pq.push({ now.node - 1, 1, now.cnt + 1 });

        if (now.node < 100000 && !Visited[now.node * 2])
            pq.push({ now.node * 2, 0, now.cnt });
    }
}

int main() {

    scanf("%d %d", &N, &K);

    pq.push({ N, 0, 0 });

    BFS();

    printf("%d", time);

    return 0;
}