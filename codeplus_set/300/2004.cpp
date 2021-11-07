#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, m;
	long long fiveCount = 0;
	long long twoCount = 0;
	cin >> n >> m;
	for (long long i = 2; i <= n; i *= 2) {
		twoCount += n / i;
		if (i <= n - m)
			twoCount -= (n - m) / i;
		if (i <= m)
			twoCount -= m / i;
	}
	for (long long i = 5; i <= n; i *= 5) {
		fiveCount += n / i;
		if (i <= n - m)
			fiveCount -= (n - m) / i;
		if (i <= m)
			fiveCount -= m / i;
	}
	cout << min(fiveCount, twoCount);
}
