#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k = 2;
	cin >> n;
	while (n != 1) {
		while (n % k == 0) {
			cout << k << "\n";
			n /= k;
		}
		++k;
	}
}
