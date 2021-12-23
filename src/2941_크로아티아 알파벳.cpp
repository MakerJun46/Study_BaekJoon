#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;

	vector<string> cAlpha = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	int count = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (find(cAlpha.begin(), cAlpha.end(), s.substr(i, 3)) != cAlpha.end())
			i += 2;
		else if (find(cAlpha.begin(), cAlpha.end(), s.substr(i, 2)) != cAlpha.end())
			i ++;

		count++;
	}

	cout << count;

	return 0;
}