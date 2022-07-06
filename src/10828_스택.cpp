#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;

int N;

int main()
{
    cin >> N;

    int inputNum;

    stack<int> s;
    string input;

    for (int i = 0; i < N; i++)
    {
        cin >> input;

        if (input == "push")
        {
            cin >> inputNum;

            s.push(inputNum);
        }
        else if (input == "pop")
        {
            if (s.empty())
                cout << -1 << endl;
            else
            {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (input == "size")
        {
            cout << s.size() << endl;
        }
        else if (input == "empty")
        {
            cout << (s.empty() ? 1 : 0) << endl;
        }
        else if (input == "top")
        {
            if (s.empty())
                cout << -1 << endl;
            else
                cout << s.top() << endl;
        }   
    }

    return 0;
}
