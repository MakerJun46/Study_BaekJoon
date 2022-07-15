#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct e_t
{
    int node;
    int cost;

    bool operator< (const e_t& ref) const
    {
        return this->cost > ref.cost;
    }
};

int N, M, K;
vector<e_t> AL[1001];
priority_queue<int> Visited[1001];
priority_queue<e_t> pq;

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    int a, b, c;

    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        AL[a].push_back({ b, c });
    }
    
    Visited[1].push(0);
    pq.push({ 1, 0 });

    while (!pq.empty())
    {
        e_t curr = pq.top(); pq.pop();

        for (e_t next : AL[curr.node])
        {
            int next_cost = curr.cost + next.cost; // ���ͽ�Ʈ��

            if (Visited[next.node].size() == K && next_cost < Visited[next.node].top())
            {
                Visited[next.node].pop();
            }
                                                   
            // ���� ������ K��°���� �湮�ϴ� ��� ����� ����, Visited�� pq�� K�� ���� ������
            if (Visited[next.node].size() < K)
            {
                Visited[next.node].push(next_cost);
                pq.push({ next.node, next_cost });
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (Visited[i].size() < K)
            printf("-1\n");
        else
            printf("%d\n", Visited[i].top());
    }

    return 0;
}