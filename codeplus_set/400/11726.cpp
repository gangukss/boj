#include <iostream>
using namespace std;

int ans[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	ans[0] = 1;
	ans[1] = 1;
	for (int i = 2; i <= n; ++i)
		ans[i] = (ans[i - 1] + ans[i - 2]) % 10007;
	cout << ans[n];
}
