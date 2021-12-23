#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<char, int>& a, pair<char, int>& b)
{
	return a.second > b.second;
}

int main()
{
	string s;

	cin >> s;

	map<char, int> countAlpha;

	for (int i = 0; i < s.length(); i++)
	{
		s[i] = toupper(s[i]);
		countAlpha[s[i]]++;
	}

	vector<pair<char, int>> tmp(countAlpha.begin(), countAlpha.end());

	sort(tmp.begin(), tmp.end(), cmp);

	if (tmp[0].second == tmp[1].second)
		cout << '?';
	else
		cout << tmp[0].first;

	return 0;
}