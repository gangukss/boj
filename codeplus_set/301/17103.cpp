#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int M = 1e6 + 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool PrimeArray[M];

	PrimeArray[0] = false;
	PrimeArray[1] = false;
	for (int i = 2; i <= M; i++)
	    PrimeArray[i] = true;
	for (int i = 2; i * i <= M; i++) {
		if (PrimeArray[i])
			for (int j = i * i; j <= M; j += i)
			    PrimeArray[j] = false;
	}

	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 2; i <= n / 2; ++i)
			if (PrimeArray[i] && PrimeArray[n - i])
				++ans;
		cout << ans << "\n";
	}
}
