#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string n;
	int a, b, m, dec = 0;
	stack<int> ans;
	cin >> a >> b >> m;
	for (int i = 0; i < m; ++i) {
		int tmp;
		cin >> tmp;
		dec += tmp * pow(a, m - i - 1);
	}
	while (dec) {
		ans.push(dec % b);
		dec /= b;
	}
	while (!ans.empty()) {
		cout << ans.top() << " ";
		ans.pop();
	}
}
