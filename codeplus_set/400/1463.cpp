#include <iostream>
using namespace std;

const int M = 1e6 + 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, i = 0;
	int ans[M];
	for (int j = 0; j < M; ++j)
		ans[j] = M;
	cin >> n;
	ans[1] = 0;
	while (++i < n) {
		int tmp = ans[i] + 1;
		if (i * 3 < M && ans[i * 3] > tmp)
			ans[i * 3] = tmp;
		if (i * 2 < M && ans[i * 2] > tmp)
			ans[i * 2] = tmp;
		if (i + 1 < M && ans[i + 1] > tmp)
			ans[i + 1] = tmp;
	}
	cout << ans[n];
}
