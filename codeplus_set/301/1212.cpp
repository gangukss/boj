#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input, ans;
	cin >> input;

	if (input == "0") {
		cout << "0";
		return 0;
	}

	for (size_t i = 0; i < input.size(); ++i) {
		int tmp = input[i] - '0';
		string tmpAns;

		if (tmp / 4) {
			tmpAns += '1';
			tmp %= 4;
		} else {
			tmpAns += '0';
		}

		if (tmp / 2) {
			tmpAns += '1';
			tmp %= 2;
		} else {
			tmpAns += '0';
		}

		if (tmp) {
			tmpAns += '1';
		} else {
			tmpAns += '0';
		}

		ans += tmpAns;
	}

	int i = 0;
	while (ans[i] == '0')
		++i;

	cout << ans.substr(i);
}
