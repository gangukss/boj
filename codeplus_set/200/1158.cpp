#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	queue<int> q;
	vector<int> ans;
	int n, k;

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		q.emplace(i);
	while (!q.empty()) {
		for (int i = 1; i < k; ++i) {
			q.emplace(q.front());
			q.pop();
		}
		ans.emplace_back(q.front());
		q.pop();
	}
	cout << "<";
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i];
		if (i != ans.size() - 1)
			cout << ", ";
	}
	cout << ">";
}