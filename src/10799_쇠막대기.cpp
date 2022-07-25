#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N;

string L;
stack<char> s;

int main() {

    cin >> L;

    int answer = 0;

    for (int i = 0; i < L.length(); i++)
    {
        if (i < L.length() - 1 && L[i] == '(' && L[i + 1] == ')')
        {
            answer += s.size();

            i++;

            continue;
        }

        if (L[i] == ')')
        {
            answer++;
            s.pop();
        }
        else
        {
            s.push(L[i]);
        }
    }

    printf("%d", answer);

    return 0;
}