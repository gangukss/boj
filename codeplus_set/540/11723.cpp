#include <iostream>
#include <string>
using namespace std;

bool visit[21];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string cmd;
		int num;
		cin >> cmd;
		if (cmd == "add") {
			cin >> num;
			visit[num] = 1;
		} else if (cmd == "remove") {
			cin >> num;
			visit[num] = 0;
		} else if (cmd == "check") {
			cin >> num;
			if (visit[num])
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		} else if (cmd == "toggle") {
			cin >> num;
			if (visit[num])
				visit[num] = 0;
			else
				visit[num] = 1;
		} else if (cmd == "all") {
			for (int j = 1; j <= 20; ++j)
				visit[j] = 1;
		} else if (cmd == "empty") {
			for (int j = 1; j <= 20; ++j)
				visit[j] = 0;
		}
	}
}
