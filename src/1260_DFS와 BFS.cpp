#include <cstdio>
#include <vector>
#include <queue>
#include <memory>
#include <algorithm>

using namespace std;

int N, M, V;

bool Visited[1001];
vector<int> Nodes[1001];

void DFS(int v)
{
    printf("%d ", v);

    Visited[v] = true;

    for (int next : Nodes[v])
    {
        if(!Visited[next])
            DFS(next);
    }
}

void BFS(int v)
{
    queue<int> q;

    q.push(v);

    while (!q.empty())
    {
        int i = q.front(); q.pop();

        if (Visited[i])
            continue;

        printf("%d ", i);

        Visited[i] = true;

        for (int next : Nodes[i])
        {
            if (!Visited[next])
                q.push(next);
        }
    }

}

int main() {

    scanf("%d %d %d", &N, &M, &V);

    int a, b;

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);

        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(Nodes[i].begin(), Nodes[i].end());
    }

    DFS(V);

    memset(Visited, false, sizeof(Visited));

    printf("\n");

    BFS(V);


    return 0;
}