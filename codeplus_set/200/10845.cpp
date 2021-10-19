#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int n;
	size_t idx = 0;

	v.reserve(10000);
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int data;
			cin >> data;
			v.emplace_back(data);
		} else if (cmd == "pop") {
			if (idx >= v.size()) {
				cout << "-1\n";
				continue ;
			}
			cout << v[idx] << "\n";
			++idx;
		} else if (cmd == "size") {
			cout << v.size() - idx << "\n";
		} else if (cmd == "empty") {
			if (v.size() == idx)
				cout << "1\n";
			else
				cout << "0\n";
		} else if (cmd == "front") {
			if (idx >= v.size()) {
				cout << "-1\n";
				continue ;
			}
			cout << v[idx] << "\n";
		} else if (cmd == "back") {
			if (idx >= v.size()) {
				cout << "-1\n";
				continue ;
			}
			cout << v[v.size() - 1] << "\n";
		}
	}
}