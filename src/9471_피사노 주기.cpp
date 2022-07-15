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

        // �Ǻ���ġ �����
        vector<int> fibonaci;
        fibonaci.push_back(0);    
        fibonaci.push_back(1);    
        fibonaci.push_back(1);

        // ���� �Ǻ���ġ�� ��� �����ϸ鼭 �������� Ȯ���Ѵ�
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