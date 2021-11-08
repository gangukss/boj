#include <iostream>
using namespace std;

int input[100];

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, t;
	cin >> t;
	while (t--) {
		long long ans = 0;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> input[i];
		for (int i = 0; i < n - 1; ++i)
			for (int j = i + 1; j < n; ++j)
				ans += gcd(input[i], input[j]);
		cout << ans << "\n";
	}
}
