#include <iostream>

using namespace std;

int main()
{
	int n;
	int count = 0;
	string s;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		bool isGroupWord = true;
		bool isCounted[26]{ false, };
		char startC = s[0];
		isCounted[s[0] - 'a'] = true;

		for (char c : s)
		{
			if (startC != c && isCounted[c - 'a'])
			{
				isGroupWord = false;
				break;
			}
			else if (startC != c && !isCounted[c - 'a'])
			{
				isCounted[c - 'a'] = true;
				startC = c;
			}
		}

		isGroupWord ? count++ : count;
	}

	cout << count;

	return 0;
}

