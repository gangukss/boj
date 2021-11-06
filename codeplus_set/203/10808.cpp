#include <iostream>
#include <string>
using namespace std;

string input;
int ans[26];

int main() {
	cin >> input;
	for (size_t i = 0; i < input.size(); ++i)
		++ans[input[i] - 'a'];
	for (int i = 0; i < 26; ++i)
		cout << ans[i] << " ";
}
