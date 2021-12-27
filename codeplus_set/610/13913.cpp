#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct info {
	int pos;
	int time;
};
const int M = 1e5 + 1;
int n, k;
queue<info> q;
int visit[M];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	q.push({n, 0});
	memset(visit, -1, sizeof(visit));
	visit[n] = n;
	while (!q.empty()) {
		info tmp = q.front();
		q.pop();
		if (tmp.pos == k) {
			cout << tmp.time << "\n";
			vector<int> history;
			while (k != n) {
				history.emplace_back(k);
				k = visit[k];
			}
			history.emplace_back(n);
			for (int i = (int)history.size() - 1; i >= 0; --i)
				cout << history[i] << " ";
			break ;
		}
		if (tmp.pos - 1 >= 0 && visit[tmp.pos - 1] == -1) {
			visit[tmp.pos - 1] = tmp.pos;
			q.push({tmp.pos - 1, tmp.time + 1});
		}
		if (tmp.pos + 1 <= M && visit[tmp.pos + 1] == -1) {
			visit[tmp.pos + 1] = tmp.pos;
			q.push({tmp.pos + 1, tmp.time + 1});
		}
		if (tmp.pos * 2 <= M && visit[tmp.pos * 2] == -1) {
			visit[tmp.pos * 2] = tmp.pos;
			q.push({tmp.pos * 2, tmp.time + 1});
		}
	}
}
