#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int DP[1001][1001];
int mat[1001][1001];

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%1d", &mat[i][j]);
        }
    }

    for (int i = 1; i <= N; i++)
    {
        DP[i][1] = mat[i][1];
    }

    for (int i = 1; i <= M; i++)
    {
        DP[1][i] = mat[1][i];
    }

    int answer = DP[1][1];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (mat[i][j] == 0) 
                DP[i][j] = 0;
            else
            {
                DP[i][j] = 1 + min({ DP[i][j - 1], DP[i - 1][j], DP[i - 1][j - 1] });

                answer = max(answer, DP[i][j]);
            }
        }
    }

    printf("%d", answer * answer);

    return 0;
}
