#include <iostream>
using namespace std;

int a, b;

int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return (gcd(y, x % y));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int g = gcd(a, b);
		cout << a * b / g << "\n";
	}
}
