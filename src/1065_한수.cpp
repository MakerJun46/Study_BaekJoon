#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int answer = 0;
	int data;

	cin >> data;

	for (int i = 1; i <= data; i++)
	{
		vector<int> nums;
		int d = i;

		while (d > 0)
		{
			nums.push_back(d % 10);
			d /= 10;
		}

		if (nums.size() <= 2)
			answer++;
		else
		{
			int tmp = nums[0] - nums[1];
			bool isHanNum = true;

			for (int j = 1; j < nums.size(); j++)
			{
				if (tmp != nums[j - 1] - nums[j])
				{
					isHanNum = false;
					break;
				}
			}

			if (isHanNum)
				answer++;
		}
	}

	cout << answer;

	return 0;
}