#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N, M;
	int sum = 0;
	vector<int> numbers;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		numbers.push_back(tmp);
	}

	vector<bool> temp(numbers.size(), false);

	for (int i = 0; i < 3; i++)
		temp[i] = true;

	do
	{
		int sum_tmp = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (temp[i])
				sum_tmp += numbers[i];
		}

		if (sum_tmp > sum && sum_tmp <= M)
			sum = sum_tmp;

	} while (prev_permutation(temp.begin(), temp.end()));

	cout << sum;

	return 0;
}