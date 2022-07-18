#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> Nodes[25];
vector<int> Village;
queue<pair<int, int>> q;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void BFS()
{
    int cnt = 0;

    while (!q.empty())
    {
        auto i = q.front(); 
        q.pop();

        if (Nodes[i.first][i.second] == 0)
            continue;

        Nodes[i.first][i.second] = 0;

        cnt++;

        for (int j = 0; j < 4; j++)
        {
            int x = i.first + dx[j];
            int y = i.second + dy[j];

            if (x >= 0  && y >= 0 && x < N && y < N)
                q.push(make_pair(x, y));
        }
    }

    Village.push_back(cnt);
}

int main() {

    scanf("%d", &N);

    int d;

    for (int i = 0; i < N; i++)
    {
        vector<int> tmp(N);

        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &d);

            tmp[j] = d;
        }

        Nodes[i] = tmp;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            auto it = find(Nodes[i].begin(), Nodes[i].end(), 1);

            if (it == Nodes[i].end())
                break;
            else
            {
                q.push(make_pair(i, it - Nodes[i].begin()));
                BFS();
            }                
        }
    }

    sort(Village.begin(), Village.end());

    printf("%d\n", (int)Village.size());

    for (int i : Village)
    {
        printf("%d\n", i);
    }

    return 0;
}