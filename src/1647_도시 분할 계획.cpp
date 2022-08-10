#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int Node[100001];
vector<pair<int, pair<int, int>>> Edges;

int GetParent(int x)
{
	if (Node[x] == x)
		return x;
	else
		return Node[x] = GetParent(Node[x]);
}

void Union(int a, int b)
{
	int Pa = GetParent(a);
	int Pb = GetParent(b);

	if (Pa != Pb)
		Node[Pa] = Pb;
}

bool Find(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	int a, b, c;
	int sum = 0;
	int maxCost = 0;

	for (int i = 1; i <= N; i++)
	{
		Node[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &a, &b, &c);

		Edges.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(Edges.begin(), Edges.end());

	for (int i = 0; i < M; i++)
	{
		if (!Find(Edges[i].second.first, Edges[i].second.second))
		{
			Union(Edges[i].second.first, Edges[i].second.second);

			sum += Edges[i].first;

			if (maxCost < Edges[i].first)
				maxCost = Edges[i].first;
		}
	}

	printf("%d", sum - maxCost);

	return 0;
}