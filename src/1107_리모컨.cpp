#include <iostream>
#include <math.h>
#include <string>

using namespace std;

bool Nums[10];
int N, M;
int answer;

bool check(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (Nums[s[i] - '0'])
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int data;

        cin >> data;

        Nums[data] = true;
    }

    answer = abs(N - 100);

    for (int i = 0; i <= 1000000; i++)
    {
        if (check(to_string(i)))
        {
            int tmp = abs(N - i) + to_string(i).length();
                
            answer = min(answer, tmp);
        }
    }

    cout << answer;

    return 0;
}
