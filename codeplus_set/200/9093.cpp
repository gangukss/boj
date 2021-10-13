#include <iostream>
#include <vector>
using namespace std;

int t;
string line;
vector<char> word;

void printReverse(vector<char> &word)
{
	for (int j = word.size() - 1; j >= 0; --j)
		cout << word[j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		getline(cin, line);
		if (line == "")
			getline(cin, line);
		for (size_t i = 0; i < line.size(); ++i)
		{
			if (line[i] == ' ')
			{
				printReverse(word);
				cout << " ";
				word.clear();
				continue ;
			}
			word.emplace_back(line[i]);
		}
		printReverse(word);
		cout << "\n";
		word.clear();
	}
}