#include <cstdio>
#include <string>
#include <algorithm>

int N, K;

int Weight[101];
int Value[101];

int DP[101][100001];

int main()
{
    scanf("%d %d", &N, &K);

    int w, v;

    for (int i = 1; i <= N; i++)
    {
        scanf("%d %d", &w, &v);

        Weight[i] = w;
        Value[i] = v;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j - Weight[i] >= 0)
                DP[i][j] = std::max(DP[i - 1][j], DP[i - 1][j - Weight[i]] + Value[i]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    }

    printf("%d", DP[N][K]);

    return 0;
}
