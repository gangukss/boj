#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
const int M = 1e5 + 1;
vector<vector<int>> input(M);
vector<bool> visit(M);
queue<int> inputOrder;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0 ; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		input[a].emplace_back(b);
		input[b].emplace_back(a);
	}
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		inputOrder.push(tmp);
	}
	q.push(1);
	visit[1] = 1;
	if (inputOrder.front() != 1) {
		cout << 0;
		return 0;
	}
	inputOrder.pop();
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int cnt = 0;
		for (auto next : input[x])
			if (!visit[next])
				++cnt;
		while (cnt) {
			auto nextIt = find(input[x].begin(), input[x].end(), inputOrder.front());
			if (nextIt != input[x].end()) {
				q.push(*nextIt);
				visit[*nextIt] = 1;
				inputOrder.pop();
				--cnt;
			} else {
				cout << 0;
				return 0;
			}
		}
	}
	cout << 1;
}
