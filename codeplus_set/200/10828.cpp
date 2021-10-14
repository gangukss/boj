#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, pushData;
vector<int> v;
string cmd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> pushData;
			v.emplace_back(pushData);
		} else if (cmd == "pop") {
			if (v.empty())
				cout << "-1\n";
			else {
				cout << v.back() << "\n";
				v.pop_back();
			}
		} else if (cmd == "size") {
			cout << v.size() << "\n";
		} else if (cmd == "empty") {
			cout << v.empty() << "\n";
		} else if (cmd == "top") {
			if (v.empty())
				cout << "-1\n";
			else
				cout << v.back() << "\n";
		}
	}
}