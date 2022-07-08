#include <iostream>
#include <queue>

using namespace std;

int minHeap[1000001];
int _size = 1;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;

        cin >> x;

        if (x == 0) // pop
        {
            int index = 1;

            cout << minHeap[1] << "\n";

            minHeap[1] = minHeap[--_size];
            minHeap[_size] = 0;

            while (index < _size)
            {
                if (minHeap[index * 2] == 0)
                {
                    break;
                }
                else if (minHeap[index * 2 + 1] == 0 || minHeap[index * 2] <= minHeap[index * 2 + 1])
                {
                    if (minHeap[index * 2] < minHeap[index])
                    {
                        swap(minHeap[index], minHeap[index * 2]);
                        index *= 2;
                    }
                    else
                        break;
                }
                else
                {
                    if (minHeap[index * 2 + 1] < minHeap[index])
                    {
                        swap(minHeap[index], minHeap[index * 2 + 1]);
                        index = index * 2 + 1;
                    }
                    else
                        break;
                }
            }

            if (_size == 0)
                _size++;
        }
        else // insert
        {
            int index = _size;

            minHeap[_size] = x;

            while (index > 1)
            {
                if (minHeap[index / 2] > minHeap[index])
                {
                    swap(minHeap[index], minHeap[index / 2]);

                    index /= 2;
                }
                else
                    break;
            }

            _size++;
        }
    }

    return 0;
}