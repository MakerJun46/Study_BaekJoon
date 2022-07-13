#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct e_t
{
    int v;
    int cost;

    e_t(int _v, int _cost) : v(_v), cost(_cost) {}

    bool operator<(const e_t& ref) const
    {
        return this->cost > ref.cost;
    }
};

vector<e_t> Nodes[20001];
int Visited[20001];

int V, E, K;

// 다익스트라

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin >> V >> E >> K;

    for (int i = 1; i <= V; i++)
    {
        Visited[i] = INT_MAX;
    }

    int a, b, c;

    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;

        Nodes[a].push_back(e_t(b, c));
    }

    priority_queue<e_t> pq;

    pq.push(e_t(K, 0));

    Visited[K] = 0;

    while (!pq.empty())
    {
        e_t item = pq.top(); pq.pop();

        for (e_t next_node : Nodes[item.v])
        {
            int next_cost = item.cost + next_node.cost;

            if (next_cost < Visited[next_node.v])
            {
                Visited[next_node.v] = next_cost;
                pq.push(e_t(next_node.v, next_cost));
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (Visited[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << Visited[i] << "\n";
    }

    return 0;
}
