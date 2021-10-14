#include <iostream>
#include <string>
#include <vector>
using namespace std;

int t;
string line;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		vector<char> v;
		int flag = 1;
		cin >> line;
		for (size_t i = 0; i < line.size(); ++i) {
			if (line[i] == ')') {
				if (v.empty()) {
					flag = 0;
					break ;
				} else 
					v.pop_back();
			} else
				v.emplace_back('(');
		}
		if (v.empty() && flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}