#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int fiveCount = 0;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int tmp = i;
		while (tmp % 5 == 0) {
			++fiveCount;
			tmp /= 5;
		}
	}
	cout << fiveCount;
}
