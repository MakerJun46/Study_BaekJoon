#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	vector<int> numbers;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;

		numbers.push_back(tmp);
	}

	sort(numbers.begin(), numbers.end());
	
	for (int i : numbers)
	{
		cout << i << endl;
	}

	return 0;
}