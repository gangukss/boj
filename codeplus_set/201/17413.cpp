#include <iostream>
using namespace std;

bool is_alnum(char c) {
	return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
}

int main() {
	string input, output;
	getline(cin, input);

	for (size_t i = 0; i < input.size(); ++i) {
		if (input[i] == '<') {
			while (input[i] != '>') {
				output += input[i];
				++i;
			}
			output += input[i];
		} else if (input[i] == ' ') {
			output += input[i];
		} else if (is_alnum(input[i])) {
			int start = (int)i;
			while (is_alnum(input[i + 1]))
				++i;
			for (int end = (int)i; end >= start; --end)
				output += input[end];
		}
	}

	cout << output;
}
