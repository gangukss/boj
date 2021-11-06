#include <iostream>
#include <string>
#include <set>
using namespace std;

string input;
set<string> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> input;
	for (size_t i = 0; i < input.size(); ++i)
		ans.insert(input.substr(i, input.size() - i));
	for (auto x : ans)
		cout << x << "\n";
}
