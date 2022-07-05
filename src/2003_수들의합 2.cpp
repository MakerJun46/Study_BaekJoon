#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N;
long long M;
long long nums[10001];
int answer = 0;

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	int pA = 0;
	int pB = 1;

	long long sum = nums[0];

	while (pA <= pB && pB <= N)
	{
		if (sum == M) 
		{
			answer++;
		}

		if (sum <= M)
		{
			sum += nums[pB];
			pB++;
		}
		else if(sum > M)
		{
			sum -= nums[pA];
			pA++;
		}
	}

	printf("%d", answer);

	return 0;
}