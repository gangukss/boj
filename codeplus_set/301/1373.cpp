#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string input, ans;
	cin >> input;
	if (input.size() % 3)
		input.insert(0, 3 - input.size() % 3, '0');

	ans.append(input.size() / 3, '0');
	for (size_t i = 0; i < input.size(); i += 3) {
		if (input[i] == '1')
			ans[i / 3] += 4;
		if (input[i + 1] == '1')
			ans[i / 3] += 2;
		if (input[i + 2] == '1')
			ans[i / 3] += 1;
	}
	cout << ans;
}
