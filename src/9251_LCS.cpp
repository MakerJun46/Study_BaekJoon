#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string a, b;
string ans = "";
int DP[1001][1001];

int main()
{
    getline(cin, a);
    getline(cin, b);

    a = " " + a;
    b = " " + b;

    int maxLength = 0;

    for (int i = 1; i < a.length(); i++)
    {
        for (int j = 1; j < b.length(); j++)
        {
            if (a[i] == b[j])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    printf("%d", DP[a.length() - 1][b.length() - 1]);

    return 0;
}
