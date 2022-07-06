#include <iostream>
#include <queue>

using namespace std;

int N;

int main()
{
    cin >> N;

    int inputNum;

    queue<int> q;
    string input;

    for (int i = 0; i < N; i++)
    {
        cin >> input;

        if (input == "push")
        {
            cin >> inputNum;

            q.push(inputNum);
        }
        else if (input == "pop")
        {
            if (q.empty())
                cout << -1 << endl;
            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (input == "size")
        {
            cout << q.size() << endl;
        }
        else if (input == "empty")
        {
            cout << (q.empty() ? 1 : 0) << endl;
        }
        else if (input == "front")
        {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.front() << endl;
        }   
        else if (input == "back")
        {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.back() << endl;
        }
    }

    return 0;
}
