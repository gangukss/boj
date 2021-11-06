#include <iostream>
#include <string>
using namespace std;

string input;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (getline(cin, input)) {
		int ans[4] = {0, 0, 0, 0};
		for (size_t i = 0; i < input.size(); ++i) {
			if (input[i] >= 'a' && input[i] <= 'z')
				++ans[0];
			else if (input[i] >= 'A' && input[i] <= 'Z')
				++ans[1];
			else if (input[i] >= '0' && input[i] <= '9')
				++ans[2];
			else if (input[i] == ' ')
				++ans[3];
		}
		for (size_t i = 0; i < 4; ++i)
			cout << ans[i] << " ";
		cout << "\n";
	}
}
