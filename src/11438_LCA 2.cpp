#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<vector<int>> Nodes(N + 1);
    vector<int> Depth(N + 1, -1);

    // [k][v] �� ���� ����v�� 2^k ��° �θ� ����, ���� ���ǿ� �ִ� 100000�����ϱ�
    // 2^17 = 131072 �̹Ƿ� �ִ� 17��° �θ������ �־ ��
    vector<vector<int>> Parent(18, vector<int>(N + 1));

    for (int i = 0; i < N - 1; i++)
    {

        cin >> a >> b;

        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    // Depth ���ϱ� ���� : root node(0) <= 1�� ���
    // bfs�� �̿��� ���ϱ�
    queue<int> q;

    q.push(1);

    Depth[1] = 0;

    while (!q.empty())
    {
        int curr = q.front(); q.pop();

        for (int next : Nodes[curr])
        {
            if (Depth[next] == -1)
            {
                q.push(next);
                Depth[next] = Depth[curr] + 1;

                Parent[0][next] = curr;
            }
        }
        
    }

    // ���� ���̺�(��� ���̺�) �����
    for (int r = 1; r < 18; r++)
    {
        for (int i = 1; i <= N; i++)
        {
            Parent[r][i] = Parent[r - 1][Parent[r - 1][i]]; // Parent[r][i] => Parent[r - 1][i]�� 2^(r-1)��° �θ�
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        
        // Depth ���߱�
        // �׻� a�� ũ���� ����

        if (Depth[a] < Depth[b])
            swap(a, b);

        int diff = Depth[a] - Depth[b];

        for (int r = 0; diff > 0; r++)
        {
            if (diff & 1)
            {
                a = Parent[r][a];
            }

            diff >>= 1; // ������ ���� ��ĭ ����������(2�� �ŵ��������� �پ��)
        }

        // diff�� 10�̸� 10 => 2^3 + 2^1 , �׷��� 10�� 2������ ǥ���ϸ� 1010 �̴ϱ�
        // diff & 1�϶� (������ �ڸ����� 1�϶��� 2�� �ŵ������� �Ǵϱ�)�� ����
        // �׷��� 2�� �ŵ��������� �ּ����� ���������� �ִ��� ������ �� �ְ� ��
        
        
        // LCA ã��

        while (a != b)
        {
            int r;

            for (r = 0; r < 18; r++)
            {
                if (Parent[r][a] == Parent[r][b])
                    break;
            }

            if (r > 0)
                r--;

            a = Parent[r][a];
            b = Parent[r][b];
        }

        cout << a << "\n";
    }

    return 0;
}