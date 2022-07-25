#include <cstdio>

int T, N;

int DP[11];

int main()
{
    scanf("%d", &T); 

    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    for (int i = 4; i <= 10; i++)
        DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1];
    
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);

        printf("%d\n", DP[N]);
    }

    return 0;
}
