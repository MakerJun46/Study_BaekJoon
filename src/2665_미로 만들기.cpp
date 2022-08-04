#include <cstdio>
#include <queue>

#define INF 300

using namespace std;

int N;
int map[51][51];
bool Visited[51][51];

struct pos
{
    int x;
    int y;
    int cnt;

    bool operator <(const pos& ref) const
    {
        return this->cnt > ref.cnt;
    }
};

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int main() {

    int DP[51][51];
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%1d", &map[i][j]);

            DP[i][j] = INF;
        }
    }

    priority_queue<pos> pq;

    pq.push({ 1, 1, 0 });
    DP[1][1] = 0;

    while (!pq.empty())
    {
        pos i = pq.top();
        pq.pop();

        Visited[i.x][i.y] = true;

        if (map[i.x][i.y] == 0)
            DP[i.x][i.y]++;

        for (int j = 0; j < 4; j++)
        {
            int next_x = i.x + dx[j];
            int next_y = i.y + dy[j];

            if (next_x > 0 && next_x <= N && next_y > 0 && next_y <= N)
            {
                DP[next_x][next_y] = min(DP[next_x][next_y], DP[i.x][i.y]);   

                if (!Visited[next_x][next_y])
                    pq.push({ next_x, next_y, DP[next_x][next_y] });
            }
        }
    }

    printf("%d", DP[N][N]);

    return 0;
}