#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int P;

    cin >> P;

    while (P--) 
    {
        int num, m;
        cin >> num >> m;

        // 피보나치 만들기
        vector<int> fibonaci;
        fibonaci.push_back(0);    
        fibonaci.push_back(1);    
        fibonaci.push_back(1);

        // 새로 피보나치를 계속 갱신하면서 나머지를 확인한다
        int n = 3;

        while (1) 
        {
            fibonaci.push_back((fibonaci.at(n - 2) + fibonaci.at(n - 1)) % m);

            if (fibonaci.at(n - 1) % m == 0 && fibonaci.at(n) % m == 1)
                break;

            n++;
        }

        cout << num << " " << n - 1 << "\n";
    }


    return 0;
}