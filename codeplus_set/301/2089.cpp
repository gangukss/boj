#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int input;
	cin >> input;

	if (input == 0) {
		cout << "0";
		return 0;
	}

	string ans;
	while (input) {
		if (input % -2 == 0) {
			ans += "0";
			input /= -2;
		} else {
			ans += "1";
			input = (input - 1) / -2;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}
