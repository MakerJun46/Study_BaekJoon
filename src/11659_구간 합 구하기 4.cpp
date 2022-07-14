#include <cstdio>

using namespace std;

int N, M;

int DP[100001];

int main()
{
    scanf("%d %d", &N, &M);

    int d;

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &d);

        DP[i] = d + DP[i - 1];
    }

    int i, j;

    for (int k = 0; k < M; k++)
    {
        scanf("%d %d", &i, &j);

        // a ~ b의 구간 합은 DP[b] - DP[a] 니까
        printf("%d\n", DP[j] - DP[i - 1]);
    }


    return 0;
}
