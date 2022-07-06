#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N;
int answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<int> v(N);
	priority_queue<int> min_pq; // top�� �߰����� ���� �͵� �߿� ���� ū �� 
	priority_queue<int, vector<int>, greater<int>> max_pq; // top �� �߰����� ū �͵��߿� ���� ���� ��

	int input;
	int mid;

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	mid = v[0];

	cout << mid << "\n";

	for (int i = 1; i < N; i++)
	{
		if (v[i] <= mid)
			min_pq.push(v[i]);
		else
			max_pq.push(v[i]);

		int size = min_pq.size() - max_pq.size();

		if (abs(size) >= 2)
		{
			if (size < 0) // max�� �� ���� ���
			{
				min_pq.push(mid); // max�� �� �����ϱ� �߰����� �Ƿ��� �ݵ�� min�� �־����
				mid = max_pq.top(); max_pq.pop();
			}
			else
			{
				max_pq.push(mid);
				mid = min_pq.top(); min_pq.pop();
			}
		}

		if (i % 2 == 1) // ���ڰ� ¦�� ���ϋ�
		{
			if (size > 0 && !max_pq.empty() && mid > max_pq.top()) // min.top�̶� �� => mid�� max���� ����� ��
			{
				min_pq.push(mid);

				mid = max_pq.top(); max_pq.pop();
			}
			else if (size > 0 && !min_pq.empty() && mid > min_pq.top())
			{
				max_pq.push(mid);

				mid = min_pq.top(); min_pq.pop();
			}
		}

		cout << mid << "\n";
	}

	return 0;
}