#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string answer = "";
	string A, B;
	cin >> A >> B;
	
	if (A.length() < B.length())
	{
		string tmp = A;
		A = B;
		B = tmp;
	}

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int tmp = 0;
	for (int i = 0; i < B.length(); i++)
	{
		int a_n = A[i] - '0';
		int b_n = B[i] - '0';

		int sum = a_n + b_n + tmp;
		
		tmp = sum / 10;
		answer += to_string(sum % 10);
	}

	for (int i = B.length(); i < A.length(); i++)
	{
		int a_n = A[i] - '0' + tmp;

		tmp = a_n / 10;
		answer += to_string(a_n % 10);
	}

	if (tmp > 0)
		answer += to_string(tmp);

	reverse(answer.begin(), answer.end());

	cout << answer;

	return 0;
}