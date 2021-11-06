#include <iostream>
#include <string>
using namespace std;

string input;
int ans[26];

int main() {
	cin >> input;
	for (size_t i = 0; i < 26; ++i)
		ans[i] = -1;
	for (size_t i = 0; i < input.size(); ++i)
		if (ans[input[i] - 'a'] == -1)
			ans[input[i] - 'a'] = i;
	for (size_t i = 0; i < 26; ++i)
		cout << ans[i] << " ";
}
