#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> inputs;

	int data;

	for (int i = 0; i < 9; i++)
	{
		cin >> data;

		inputs.push_back(data);
	}

	sort(inputs.begin(), inputs.end());

	do
	{
		vector<int>answer(inputs.begin(), inputs.begin() + 7);

		if(accumulate(answer.begin(), answer.end(), 0) == 100)
		{
			sort(answer.begin(), answer.end());

			for (int i : answer)
				cout << i << endl;

			break;
		}
	} while (next_permutation(inputs.begin(), inputs.end()));
	

	return 0;
}