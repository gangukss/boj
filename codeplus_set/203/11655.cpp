#include <iostream>
#include <string>
using namespace std;

string input;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin, input);
	for (size_t i = 0; i < input.size(); ++i) {
		if (input[i] >= 'a' && input[i] <= 'm')
			input[i] += 13;
		else if (input[i] >= 'A' && input[i] <= 'M')
			input[i] += 13;
		else if (input[i] >= 'n' && input[i] <= 'z')
			input[i] -= 13;
		else if (input[i] >= 'N' && input[i] <= 'Z')
			input[i] -= 13;
	}
	cout << input;
}
