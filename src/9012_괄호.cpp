#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int T;

int main() {

    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        string input;
        stack<char> s;

        cin >> input;

        for (int j = 0; j < input.length(); j++)
        {
            if (s.empty())
                s.push(input.at(j));
            else if (input.at(j) == s.top())
                s.push(input.at(j));
            else if(s.top() == '(' && input.at(j) == ')')
                s.pop();
        }

        if (s.empty())
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}