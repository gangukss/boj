#include <iostream>
#include <queue>
using namespace std;

struct info {
	int cnt;
	int clipboard;
};
int s;
const int M = 1001;
int visit[M][M];
queue<info> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	q.push({1, 0});
	while (!q.empty()) {
		info tmp = q.front();
		q.pop();
		if (tmp.cnt == s) {
			cout << visit[tmp.cnt][tmp.clipboard];
			break ;
		}
		if (!visit[tmp.cnt][tmp.cnt]) {
			visit[tmp.cnt][tmp.cnt] = visit[tmp.cnt][tmp.clipboard] + 1;
			q.push({tmp.cnt, tmp.cnt});
		}
		if (tmp.cnt + tmp.clipboard <= 1000 && !visit[tmp.cnt + tmp.clipboard][tmp.clipboard]) {
			visit[tmp.cnt + tmp.clipboard][tmp.clipboard] = visit[tmp.cnt][tmp.clipboard] + 1;
			q.push({tmp.cnt + tmp.clipboard, tmp.clipboard});
		}
		if (tmp.cnt - 1 >= 2 && !visit[tmp.cnt - 1][tmp.clipboard]) {
			visit[tmp.cnt - 1][tmp.clipboard] = visit[tmp.cnt][tmp.clipboard] + 1;
			q.push({tmp.cnt - 1, tmp.clipboard});
		}
	}
}
