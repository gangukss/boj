#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	int res = 0, layer = 0;

	cin >> input;
	for (size_t i = 0; i < input.size(); ++i) {
		if (input[i] == '(') {
			if (input[i + 1] == ')') {
				++i;
				res += layer;
			} else
				++layer;
		} else {
			--layer;
			++res;
		}
	}
	cout << res;
}
