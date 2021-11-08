#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, s, tmp;
	int ans = 0;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		if (s - tmp > 0)
			tmp = s - tmp;
		else
			tmp = tmp - s;
		ans = gcd(tmp, ans);
	}
	cout << ans;
}
