#include <cstdio>
#include <stack>

using namespace std;

int N;

stack<pair<int, int>> s;

int intercept[500001];

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int d;

		scanf("%d", &d);
		
		if (s.empty())
			s.push(make_pair(i, d));
		else if (s.top().second < d) // 새로 입력값이 top보다 크면
		{
			while(!s.empty() && s.top().second < d)
				s.pop();

			intercept[i] = s.empty() ? 0 : s.top().first;
			s.push(make_pair(i, d));
		}
		else // 새로 입력값이 top 보다 작으면 
		{
			intercept[i] = s.top().first;
			s.push(make_pair(i, d));
		}
	}

	for (int i = 1; i <= N; i++)
	{
		printf("%d ", intercept[i]);
	}

	return 0;
}