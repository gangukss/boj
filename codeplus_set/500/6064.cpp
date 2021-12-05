#include <iostream>
using namespace std;

int gcd(int i, int j) {
	int k;
	while (j != 0) {
		k = i % j;
		i = j;
		j = k;
	}
	return i;
}

int lcm(int i, int j) {
	return i * j / gcd(i, j);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, m, n, x, y;
	cin >> t;
	while (t--) {
		cin >> m >> n >> x >> y;
		int ans = x, maxYear = lcm(m, n);
		for (int tmp = x % n ? x % n: n; y != tmp && ans <= maxYear; ans += m)
			tmp = (tmp + m) % n ? (tmp + m) % n: n;
		if (ans <= maxYear)
			cout << ans << "\n";
		else
			cout << -1 << "\n";
	}
}
