#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
const int M = 3001;
vector<vector<int>> v(M);
int isCycle[M];
queue<int> q;
#define VISITED -1
#define ISCYCLE -2
#define ENDCYCLE -3
#define GONEXT -4

int checkCycle(int cur, const int &prev) {
	if (isCycle[cur] == VISITED)
		return cur;
	isCycle[cur] = VISITED;
	for (auto next : v[cur]) {
		if (next == prev)
			continue ;
		int ret = checkCycle(next, cur);
		if (ret == ENDCYCLE)
			return ENDCYCLE;
		if (ret >= 1) {
			isCycle[cur] = ISCYCLE;
			if (ret == cur)
				return ENDCYCLE;
			return ret;
		}
	}
	return GONEXT;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	checkCycle(1, -1);
	for (int i = 1; i <= n; ++i) {
		if (isCycle[i] == ISCYCLE) {
			q.push(i);
			isCycle[i] = 0;
		} else {
			isCycle[i] = -1;
		}
	}
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (auto next : v[tmp]) {
			if (isCycle[next] == -1) {
				q.push(next);
				isCycle[next] = isCycle[tmp] + 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		cout << isCycle[i] << " ";
}
