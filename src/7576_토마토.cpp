#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> table(1001, vector<int>(1001));
bool Visited[1001][1001];
queue<pair<int, int>> q;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int BFS()
{
    int cnt = 0;

    while (!q.empty())
    {
        bool isChanged = false;
        queue<pair<int, int>> q2 = q;
        
        while (!q.empty())
            q.pop();

        while (!q2.empty())
        {
            int x = q2.front().first;
            int y = q2.front().second;

            q2.pop();

            table[x][y] = 1;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx > 0 && nx <= M && ny > 0 && ny <= N)
                {
                    if (table[nx][ny] == 0 && !Visited[nx][ny])
                    {
                        Visited[nx][ny] = true;
                        isChanged = true;
                        q.push(make_pair(nx, ny));
                    }  
                }
            }
        }

        if (isChanged)
            cnt++;
    }

    return cnt;
}

int main()
{
    scanf("%d %d", &N, &M);

    int d;

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &d);

            table[i][j] = d;
        }
    }

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (table[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }


    int cnt = BFS();

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (table[i][j] == 0)
            {
                printf("%d", -1);
                return 0;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}
