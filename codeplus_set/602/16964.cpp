#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int n;
const int M = 1e5 + 1;
vector<vector<int>> input(M);
vector<bool> check(M);
queue<int> inputOrder;

void dfs(int x) {
    if (check[x] == true)
        return;
    check[x] = true;
	set<int> s;
    for (int y : input[x])
		if (!check[y])
			s.insert(y);
	for (size_t i = 0; i < s.size(); ++i) {
		int tmp = inputOrder.front();
		if (s.find(tmp) != s.end()) {
			inputOrder.pop();
			dfs(tmp);
		} else {
			cout << 0;
			exit(0);
		}
	}
}

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
	if (inputOrder.front() != 1) {
		cout << 0;
		return 0;
	}
	inputOrder.pop();
	dfs(1);
	cout << 1;
}
