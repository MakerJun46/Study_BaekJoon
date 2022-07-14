#include <cstdio>

using namespace std;

int N, M;

int mat[1025][1025];
int DP[1025][1025];

int main()
{
    scanf("%d %d", &N, &M);

    int d;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &d);

            mat[i][j] = d;
            
            // 2���� �迭 dp ����
            // DP[i][j] => i x j ¥�� �簢���� �������ϴ� ���� ���� ��
            // ���� i - 1(����) + j - 1(����)���� ��ġ�� �� (i - 1)(j - 1)�� ���ְ� �Է°� ���ϸ� �ȴ�!
            
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1] + d;
        }
    }

    int x1, y1, x2, y2, ans = 0;

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        printf("%d\n", DP[x2][y2] - DP[x2][y1 - 1] - DP[x1 - 1][y2] + DP[x1 - 1][y1 - 1]);
    }


    return 0;
}
