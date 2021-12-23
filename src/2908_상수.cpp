#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s1, s2;

	cin >> s1 >> s2;

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	cout << (stoi(s1) > stoi(s2) ? s1 : s2);

	return 0;
}