#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
	int n, k, ans, sum, t;
	scanf("%d%d", &n, &k);
	int arr[n];
	unordered_map <int, vector<pair<int, int>>> m;
	sum = 0;
	t = 0;
	m[0].push_back({0, 0});
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
		t += arr[i] % 2 ? 1 : -1;
		if (sum <= k)
		{
			m[t].push_back({i, sum});
		}
	}
	ans = m[0].size() > 0 ? m[0].back().second : 0;
	sum = 0;
	t = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		sum += arr[i];
		t += arr[i] % 2 ? 1 : -1;
		if (sum > k)
		{
			break;
		}
		for(int j = m[0 - t].size() - 1; j >= 0; j--)
		{
			if (sum + m[0 - t][j].second <= k && i > m[0 - t][j].first)
			{
				ans = max(ans, sum + m[0 - t][j].second);
				break;
			}
		}
	}
	printf("%d", ans);
}