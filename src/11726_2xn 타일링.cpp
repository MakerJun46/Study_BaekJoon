#include <cstdio>

int N;

int DP[1001];

int main()
{
    scanf("%d", &N); 

    DP[0] = 1;
    DP[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
    }

    printf("%d", DP[N]);

    return 0;
}
