#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct info {
	int pos;
	int time;
};
const int M = 1e5 + 1;
int n, k;
queue<info> q;
bool visit[M];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	q.push({n, 0});
	visit[n] = 1;
	while (!q.empty()) {
		info tmp = q.front();
		q.pop();
		if (tmp.pos == k) {
			cout << tmp.time << "\n";
			break ;
		}
		if (tmp.pos * 2 <= M && !visit[tmp.pos * 2]) {
			visit[tmp.pos * 2] = 1;
			q.push({tmp.pos * 2, tmp.time});
		}
		if (tmp.pos - 1 >= 0 && !visit[tmp.pos - 1]) {
			visit[tmp.pos - 1] = 1;
			q.push({tmp.pos - 1, tmp.time + 1});
		}
		if (tmp.pos + 1 <= M && !visit[tmp.pos + 1]) {
			visit[tmp.pos + 1] = 1;
			q.push({tmp.pos + 1, tmp.time + 1});
		}
	}
}
