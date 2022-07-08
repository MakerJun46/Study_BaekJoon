#include <iostream>

using namespace std;

int N, K;
bool arr[1001];
int _count = 0;
int K_answer;

void findPrimeNum(int max)
{
    bool isFindK = false;

    for (int i = 2; i <= max; i++)
    {
        if (isFindK)
            break;

        for (int j = i; j <= max; j += i)
        {
            if (!arr[j])
            {
                arr[j] = true;
                _count++;

                if (_count == K)
                {
                    K_answer = j;
                    isFindK = true;
                    break;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    findPrimeNum(N);

    cout << K_answer;

    return 0;
}