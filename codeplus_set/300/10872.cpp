#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int ans = 1;
	cin >> n;
	for (int i = 2; i <= n; ++i)
		ans *= i;
	cout << ans;
}
