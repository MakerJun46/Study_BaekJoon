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

    // [k][v] 에 현재 정점v의 2^k 번째 부모 저장, 문제 조건에 최대 100000만개니까
    // 2^17 = 131072 이므로 최대 17번째 부모까지만 있어도 됨
    vector<vector<int>> Parent(18, vector<int>(N + 1));

    for (int i = 0; i < N - 1; i++)
    {

        cin >> a >> b;

        Nodes[a].push_back(b);
        Nodes[b].push_back(a);
    }

    // Depth 구하기 시작 : root node(0) <= 1번 노드
    // bfs를 이용해 구하기
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

    // 점핑 테이블(희소 테이블) 만들기
    for (int r = 1; r < 18; r++)
    {
        for (int i = 1; i <= N; i++)
        {
            Parent[r][i] = Parent[r - 1][Parent[r - 1][i]]; // Parent[r][i] => Parent[r - 1][i]의 2^(r-1)번째 부모
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        
        // Depth 맞추기
        // 항상 a가 크도록 조정

        if (Depth[a] < Depth[b])
            swap(a, b);

        int diff = Depth[a] - Depth[b];

        for (int r = 0; diff > 0; r++)
        {
            if (diff & 1)
            {
                a = Parent[r][a];
            }

            diff >>= 1; // 이진수 기준 한칸 오른쪽으로(2의 거듭제곱으로 줄어듬)
        }

        // diff가 10이면 10 => 2^3 + 2^1 , 그런데 10을 2진수로 표현하면 1010 이니까
        // diff & 1일때 (마지막 자리수가 1일때는 2의 거듭제곱이 되니까)만 점프
        // 그러면 2의 거듭제곱으로 최소한의 움직임으로 최대한 움직일 수 있게 됨
        
        
        // LCA 찾기

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